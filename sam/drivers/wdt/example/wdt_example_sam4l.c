/**
 * \file
 *
 * \brief Watchdog Timer (WDT) example for SAM4L.
 *
 * Copyright (c) 2012-2015 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel microcontroller product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \asf_license_stop
 *
 */

/**
 * \mainpage
 * \section intro Introduction
 * This example uses a push button event to simulate a deadlock in program so
 * as to demonstrate how watchdog timer works.
 *
 * At first, the example configures the pins of LED and Console UART, enables
 * the watchdog timer, and then prints some information via UART. Before user
 * presses the push button that the information mentions, the LED keeps blinking
 * and the counter of the watchdog timer is restarted before any fault of the
 * watchdog timer occurs (the reset in this case). The example enters a deadlock
 * status after user presses the push button and it causes that the counter
 * will not be restarted until a fault occurs (the watchdog reset).
 *
 * \section files Main Files
 * - wdt_sam4l.c: Watchdog driver for SAM4L;
 * - wdt_sam4l.h: Watchdog driver header file for SAM4L;
 * - wdt_example_sam4l.c: Watchdog example application for SAM4L.
 *
 * \section compilinfo Compilation Information
 * This software is written for GNU GCC and IAR Embedded Workbench
 * for Atmel. Other compilers may or may not work.
 *
 * \section deviceinfo Device Information
 * SAM4L device can be used.
 *
 * \section Requirements
 *
 * This example can be used on:
 *  - SAM4L evaluation kit
 *  - SAM4L Xplained Pro kit
 *  - SAM4L8 Xplained Pro kit
 *
 * \section Usage
 *
 * - Build the program and download it to the evaluation board.
 * -# On the computer, open and configure a terminal application
 *    (e.g., HyperTerminal on Microsoft Windows) with these settings:
 *   - 115200 bauds
 *   - 8 bits of data
 *   - No parity
 *   - 1 stop bit
 *   - No flow control
 * -# In the terminal window, the following text should appear (values depend
 *    on the board and chip used):
 *    \code
	-- Watchdog example --
	-- xxxxxx-xx
	-- Compiled: xxx xx xxxx xx:xx:xx --
\endcode
 * -# A LED keeps blinking and watchdog timer is cleared before
 *  watchdog timeout.
 * -# The example will enter a deadlock status if user presses the push button
 *  and it will trigger an watchdog reset in about 5 seconds.
 *
 * \section contactinfo Contact Information
 * For further information, visit
 * <A href="http://www.atmel.com">Atmel</A>.\n
 * Support and FAQ: http://www.atmel.com/design-support/
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */
#include <asf.h>
#include "conf_example.h"

/** Watchdog period in millisecond */
#define WDT_RESTART_PERIOD       2000

/** LED blink time in millisecond */
#define BLINK_PERIOD             500

/** System Tick event flag */
volatile bool g_b_systick_event = false;

/** System tick increased by 1 every millisecond */
volatile uint32_t g_ul_ms_ticks = 0;

/** Push button event */
volatile uint8_t g_b_button_event = 0;

/** WDT instance */
struct wdt_dev_inst g_wdt_inst;

/** WDT configuration */
struct wdt_config   g_wdt_cfg;

/**
 *  \brief Handler for System Tick interrupt.
 */
void SysTick_Handler(void)
{
	/* Set systick event flag (g_b_systick_event) and add 1 to systick. */
	g_b_systick_event = true;
	g_ul_ms_ticks++;
}

/**
 * \brief Interrupt handler for EIC interrupt.
 */
static void set_toggle_flag(void)
{
	/* Check if EIC push button line interrupt line is pending. */
	if (eic_line_interrupt_is_pending(EIC, EXAMPLE_BUTTON_EIC_LINE)) {
		eic_line_clear_interrupt(EIC, EXAMPLE_BUTTON_EIC_LINE);
		g_b_button_event = 1;
	}
}

/**
 *  Configure serial console.
 */
static void configure_console(void)
{
	const usart_serial_options_t uart_serial_options = {
		.baudrate = CONF_UART_BAUDRATE,
#ifdef CONF_UART_CHAR_LENGTH
		.charlength = CONF_UART_CHAR_LENGTH,
#endif
		.paritytype = CONF_UART_PARITY,
#ifdef CONF_UART_STOP_BITS
		.stopbits = CONF_UART_STOP_BITS,
#endif
	};

	/* Configure console. */
	stdio_serial_init(CONF_UART, &uart_serial_options);
}

/* \brief Main entry point
 * This is an example of how to use watchdog.
 */
int main(void)
{
	struct eic_line_config eic_line_cfg;

	/* Initialize the SAM system */
	sysclk_init();
	board_init();

	/* Initialize the console uart */
	configure_console();

	/* Output example information */
	printf("\r\n\r\n-- Watchdog example --\r\n");
	printf("-- %s\r\n", BOARD_NAME);
	printf("-- Compiled: %s %s --\r\n", __DATE__, __TIME__);

	/* Systick configuration. */
	if (SysTick_Config(sysclk_get_cpu_hz() / 1000)) {
		puts("-F- Systick configuration error\r");
	}

	/* Configure push button */
	eic_line_cfg.eic_mode = EIC_MODE_EDGE_TRIGGERED;
	eic_line_cfg.eic_edge = EIC_EDGE_FALLING_EDGE;
	eic_line_cfg.eic_level = EIC_LEVEL_LOW_LEVEL;
	eic_line_cfg.eic_filter = EIC_FILTER_DISABLED;
	eic_line_cfg.eic_async = EIC_ASYNCH_MODE;

	eic_enable(EIC);
	eic_line_set_config(EIC, EXAMPLE_BUTTON_EIC_LINE,
			&eic_line_cfg);
	eic_line_set_callback(EIC, EXAMPLE_BUTTON_EIC_LINE, set_toggle_flag,
			EXAMPLE_BUTTON_EIC_IRQN, 1);
	eic_line_enable(EIC, EXAMPLE_BUTTON_EIC_LINE);

	/*
	 * Intialize and enable the watchdog.
	 * Use default configuration but change timeout period
	 * to about 4.56s (Ttimeout = 2pow(PSEL+1) / Fclk_cnt = 524288 / 115000).
	 */
	wdt_get_config_defaults(&g_wdt_cfg);
	g_wdt_cfg.timeout_period = WDT_PERIOD_524288_CLK;
	wdt_init(&g_wdt_inst, WDT, &g_wdt_cfg);
	wdt_enable(&g_wdt_inst);

	printf("\r\nPlease press %s to simulate a deadlock.\r\n",
			EXAMPLE_BUTTON_NAME);

	while (1) {
		if (g_b_systick_event == true) {
			g_b_systick_event = false;

			/* Toggle LED at the given period. */
			if ((g_ul_ms_ticks % BLINK_PERIOD) == 0) {
				ioport_toggle_pin_level(EXAMPLE_LED_GPIO);
			}

			/* Clear watchdog at the given period. */
			if ((g_ul_ms_ticks % WDT_RESTART_PERIOD) == 0) {
				wdt_clear(&g_wdt_inst);
			}
		}

		/* Simulate deadlock when button is pressed. */
		if (g_b_button_event == true) {
			puts("The program enters an infinite loop, the WDT reset will " \
					"be triggered in about 5s.\r");
			wdt_clear(&g_wdt_inst);
			while (1) {
				if (g_b_systick_event == true) {
					g_b_systick_event = false;
					if ((g_ul_ms_ticks % BLINK_PERIOD) == 0) {
						printf(".");
					}
				}
			}
		}
	}
}
