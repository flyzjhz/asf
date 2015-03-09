/**
 * \file
 *
 * \brief XMEGA-E5 Xplained board init.
 *
 * This file contains board initialization function.
 *
 * Copyright (c) 2012-2014 Atmel Corporation. All rights reserved.
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
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */
#include <conf_board.h>
#include <board.h>
#include <ioport.h>

/**
 * \addtogroup xmega_e5_xplained_group
 * @{
 */

void board_init(void)
{
	ioport_configure_pin(LED0_GPIO, IOPORT_DIR_OUTPUT | IOPORT_INIT_HIGH);
	ioport_configure_pin(LED1_GPIO, IOPORT_DIR_OUTPUT | IOPORT_INIT_HIGH);


	ioport_configure_pin(GPIO_PUSH_BUTTON_0, IOPORT_DIR_INPUT
			| IOPORT_LEVEL | IOPORT_PULL_UP);
	ioport_configure_pin(GPIO_PUSH_BUTTON_1, IOPORT_DIR_INPUT
			| IOPORT_LEVEL | IOPORT_PULL_UP);
	ioport_configure_pin(GPIO_PUSH_BUTTON_2, IOPORT_DIR_INPUT
			| IOPORT_LEVEL | IOPORT_PULL_UP);

	// Always enable Chip Select pin of OLED
	// to unselect this component at default
	ioport_configure_pin(UG_2832HSWEG04_SS, IOPORT_DIR_OUTPUT
			| IOPORT_INIT_HIGH);

#ifdef CONF_BOARD_OLED_UG_2832HSWEG04
	PORTC.REMAP |= PORT_USART0_bm;
	ioport_configure_pin(UG_2832HSWEG04_DATA_CMD, IOPORT_DIR_OUTPUT
			| IOPORT_INIT_HIGH);
	ioport_configure_pin(UG_2832HSWEG04_RESET, IOPORT_DIR_OUTPUT
			| IOPORT_INIT_HIGH);
	ioport_configure_pin(UG_2832HSWEG04_SPI_SCK, IOPORT_DIR_OUTPUT
			| IOPORT_INIT_HIGH);
	ioport_configure_pin(UG_2832HSWEG04_SPI_MOSI, IOPORT_DIR_OUTPUT
			| IOPORT_INIT_HIGH);
#endif

#ifdef CONF_BOARD_QUADRATURE_ENCODER
	ioport_configure_pin(QUADRATURE_ENCODER_LINE_A, IOPORT_DIR_INPUT);
	ioport_configure_pin(QUADRATURE_ENCODER_LINE_B, IOPORT_DIR_INPUT);
#endif

#ifdef CONF_BOARD_LIGHT_SENSOR
	ioport_configure_pin(LIGHT_SENSOR_SIGNAL_PIN, IOPORT_DIR_INPUT);
#endif

#ifdef CONF_BOARD_ENABLE_USARTC0
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTC, 3), IOPORT_DIR_OUTPUT
			| IOPORT_INIT_HIGH);
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTC, 2), IOPORT_DIR_INPUT);
#endif

#ifdef CONF_BOARD_ENABLE_USARTC0_REMAP
	PORTC.REMAP |= PORT_USART0_bm;
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTC, 7), IOPORT_DIR_OUTPUT
			| IOPORT_INIT_HIGH);
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTC, 6), IOPORT_DIR_INPUT);
#endif

#ifdef CONF_BOARD_ENABLE_USARTD0
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTD, 3), IOPORT_DIR_OUTPUT
			| IOPORT_INIT_HIGH);
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTD, 2), IOPORT_DIR_INPUT);
#endif

#ifdef CONF_BOARD_ENABLE_USARTD0_REMAP
	PORTD.REMAP |= PORT_USART0_bm;
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTD, 7), IOPORT_DIR_OUTPUT
			| IOPORT_INIT_HIGH);
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTD, 6), IOPORT_DIR_INPUT);
#endif

#ifdef CONF_BOARD_ENABLE_USARTC0_ONEWIRE
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTC, 2), IOPORT_DIR_INPUT);
#endif

#ifdef CONF_BOARD_ENABLE_USARTC0_ONEWIRE_REMAP
	PORTC.REMAP |= PORT_USART0_bm;
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTC, 6), IOPORT_DIR_INPUT);
#endif

#ifdef CONF_BOARD_ENABLE_USARTD0_ONEWIRE
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTD, 2), IOPORT_DIR_INPUT);
#endif

#ifdef CONF_BOARD_ENABLE_USARTD0_ONEWIRE_REMAP
	PORTD.REMAP |= PORT_USART0_bm;
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTD, 6), IOPORT_DIR_INPUT);
#endif

#ifdef CONF_BOARD_CLKOUT_PC7
	PORTC.DIR |= 0x80;
	PORTCFG.CLKOUT |= PORTCFG_CLKOUT_PC7_gc;
#endif

	/* XCL OUT0 configurations */
#ifdef CONF_BOARD_XCL_OUT0_PD0
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTD, 0), IOPORT_DIR_OUTPUT);
#endif
#ifdef CONF_BOARD_XCL_OUT0_PD4
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTD, 4), IOPORT_DIR_OUTPUT);
#endif
#ifdef CONF_BOARD_XCL_OUT0_PC0
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTC, 0), IOPORT_DIR_OUTPUT);
#endif
#ifdef CONF_BOARD_XCL_OUT0_PC4
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTC, 4), IOPORT_DIR_OUTPUT);
#endif
#ifdef CONF_BOARD_XCL_OUT0_PD0_INV
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTD, 0), IOPORT_DIR_OUTPUT
			| IOPORT_INV_ENABLED);
#endif
#ifdef CONF_BOARD_XCL_OUT0_PD4_INV
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTD, 4), IOPORT_DIR_OUTPUT
			| IOPORT_INV_ENABLED);
#endif
#ifdef CONF_BOARD_XCL_OUT0_PC0_INV
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTC, 0), IOPORT_DIR_OUTPUT
			| IOPORT_INV_ENABLED);
#endif
#ifdef CONF_BOARD_XCL_OUT0_PC4_INV
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTC, 4),
			IOPORT_DIR_OUTPUT | IOPORT_INV_ENABLED);
#endif

	/* XCL CC0 and CC1 configurations */
#ifdef CONF_BOARD_XCL_CC0_PC2
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTC, 2), IOPORT_DIR_OUTPUT);
#endif
#ifdef CONF_BOARD_XCL_CC0_PC3
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTC, 3), IOPORT_DIR_OUTPUT);
#endif
#ifdef CONF_BOARD_XCL_CC0_PD2
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTD, 2), IOPORT_DIR_OUTPUT);
#endif
#ifdef CONF_BOARD_XCL_CC0_PD3
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTD, 3), IOPORT_DIR_OUTPUT);
#endif
#ifdef CONF_BOARD_XCL_CC0_PC2_INV
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTC, 2), IOPORT_DIR_OUTPUT
			| IOPORT_INV_ENABLED);
#endif
#ifdef CONF_BOARD_XCL_CC0_PC3_INV
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTC, 3), IOPORT_DIR_OUTPUT
			| IOPORT_INV_ENABLED);
#endif
#ifdef CONF_BOARD_XCL_CC0_PD2_INV
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTD, 2), IOPORT_DIR_OUTPUT
			| IOPORT_INV_ENABLED);
#endif
#ifdef CONF_BOARD_XCL_CC0_PD3_INV
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTD, 3), IOPORT_DIR_OUTPUT
			| IOPORT_INV_ENABLED);
#endif

	/* XCL IN0 configurations */
#ifdef CONF_BOARD_XCL_IN0_PD2
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTD, 2), IOPORT_DIR_INPUT
			| IOPORT_FORCE_ENABLE | IOPORT_PULL_UP);
#endif
#ifdef CONF_BOARD_XCL_IN0_PD2_INV
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTD, 2), IOPORT_DIR_INPUT
			| IOPORT_FORCE_ENABLE | IOPORT_INV_ENABLED | IOPORT_PULL_UP);
#endif
#ifdef CONF_BOARD_XCL_IN0_PD6
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTD, 6), IOPORT_DIR_INPUT
			| IOPORT_FORCE_ENABLE | IOPORT_PULL_UP);
#endif
#ifdef CONF_BOARD_XCL_IN0_PD6_INV
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTD, 6), IOPORT_DIR_INPUT
			| IOPORT_FORCE_ENABLE | IOPORT_INV_ENABLED | IOPORT_PULL_UP);
#endif
#ifdef CONF_BOARD_XCL_IN0_PC2
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTC, 2), IOPORT_DIR_INPUT
			| IOPORT_FORCE_ENABLE | IOPORT_PULL_UP);
#endif
#ifdef CONF_BOARD_XCL_IN0_PC2_INV
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTC, 2), IOPORT_DIR_INPUT
			| IOPORT_FORCE_ENABLE | IOPORT_INV_ENABLED | IOPORT_PULL_UP);
#endif
#ifdef CONF_BOARD_XCL_IN0_PC6
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTC, 6), IOPORT_DIR_INPUT
			| IOPORT_FORCE_ENABLE | IOPORT_PULL_UP);
#endif
#ifdef CONF_BOARD_XCL_IN0_PC6_INV
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTC, 6), IOPORT_DIR_INPUT
			| IOPORT_FORCE_ENABLE | IOPORT_INV_ENABLED | IOPORT_PULL_UP);
#endif

	/* XCL IN1 Configurations */
#ifdef CONF_BOARD_XCL_IN1_PD0
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTD, 0),
			IOPORT_DIR_INPUT | IOPORT_FORCE_ENABLE | IOPORT_PULL_UP);
#endif
#ifdef CONF_BOARD_XCL_IN1_PD0_INV
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTD, 0), IOPORT_DIR_INPUT 
			| IOPORT_FORCE_ENABLE | IOPORT_INV_ENABLED | IOPORT_PULL_UP);
#endif
#ifdef CONF_BOARD_XCL_IN1_PD4
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTD, 4), IOPORT_DIR_INPUT
			| IOPORT_FORCE_ENABLE | IOPORT_PULL_UP);
#endif
#ifdef CONF_BOARD_XCL_IN1_PD4_INV
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTD, 4),IOPORT_DIR_INPUT
			| IOPORT_FORCE_ENABLE | IOPORT_INV_ENABLED | IOPORT_PULL_UP);
#endif
#ifdef CONF_BOARD_XCL_IN1_PC0
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTC, 0), IOPORT_DIR_INPUT
			| IOPORT_FORCE_ENABLE | IOPORT_PULL_UP);
#endif
#ifdef CONF_BOARD_XCL_IN1_PC0_INV
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTC, 0), IOPORT_DIR_INPUT
			| IOPORT_FORCE_ENABLE | IOPORT_INV_ENABLED | IOPORT_PULL_UP);
#endif
#ifdef CONF_BOARD_XCL_IN1_PC4
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTC, 4), IOPORT_DIR_INPUT
			| IOPORT_FORCE_ENABLE | IOPORT_PULL_UP);
#endif
#ifdef CONF_BOARD_XCL_IN1_PC4_INV
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTC, 4), IOPORT_DIR_INPUT 
			| IOPORT_FORCE_ENABLE | IOPORT_INV_ENABLED | IOPORT_PULL_UP);
#endif

	/* XCL IN2 Configurations */
#ifdef CONF_BOARD_XCL_IN2_PD1
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTD, 1), IOPORT_DIR_INPUT
			| IOPORT_FORCE_ENABLE | IOPORT_PULL_UP);
#endif
#ifdef CONF_BOARD_XCL_IN2_PD1_INV
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTD, 1), IOPORT_DIR_INPUT
			| IOPORT_FORCE_ENABLE | IOPORT_INV_ENABLED | IOPORT_PULL_UP);
#endif
#ifdef CONF_BOARD_XCL_IN2_PD5
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTD, 5), IOPORT_DIR_INPUT
			| IOPORT_FORCE_ENABLE | IOPORT_PULL_UP);
#endif
#ifdef CONF_BOARD_XCL_IN2_PD5_INV
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTD,5), IOPORT_DIR_INPUT
			| IOPORT_FORCE_ENABLE | IOPORT_INV_ENABLED | IOPORT_PULL_UP);
#endif
#ifdef CONF_BOARD_XCL_IN2_PC1
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTC, 1), IOPORT_DIR_INPUT
			| IOPORT_FORCE_ENABLE | IOPORT_PULL_UP);
#endif
#ifdef CONF_BOARD_XCL_IN2_PC1_INV
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTC, 1), IOPORT_DIR_INPUT
			| IOPORT_FORCE_ENABLE | IOPORT_INV_ENABLED | IOPORT_PULL_UP);
#endif
#ifdef CONF_BOARD_XCL_IN2_PC5
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTC, 5), IOPORT_DIR_INPUT
			| IOPORT_FORCE_ENABLE | IOPORT_PULL_UP);
#endif
#ifdef CONF_BOARD_XCL_IN2_PC5_INV
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTC, 5), IOPORT_DIR_INPUT
			| IOPORT_FORCE_ENABLE | IOPORT_INV_ENABLED | IOPORT_PULL_UP);
#endif

	/* XCL IN3 Configurations */
#ifdef CONF_BOARD_XCL_IN3_PD3
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTD, 3), IOPORT_DIR_INPUT
			| IOPORT_FORCE_ENABLE | IOPORT_PULL_UP);
#endif
#ifdef CONF_BOARD_XCL_IN3_PD3_INV
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTD, 3), IOPORT_DIR_INPUT
			| IOPORT_FORCE_ENABLE | IOPORT_INV_ENABLED | IOPORT_PULL_UP);
#endif
#ifdef CONF_BOARD_XCL_IN3_PD7
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTD, 7), IOPORT_DIR_INPUT
			| IOPORT_FORCE_ENABLE | IOPORT_PULL_UP);
#endif
#ifdef CONF_BOARD_XCL_IN3_PD7_INV
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTD, 7), IOPORT_DIR_INPUT
			| IOPORT_FORCE_ENABLE | IOPORT_INV_ENABLED | IOPORT_PULL_UP);
#endif
#ifdef CONF_BOARD_XCL_IN3_PC3
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTC, 3), IOPORT_DIR_INPUT
			| IOPORT_FORCE_ENABLE | IOPORT_PULL_UP);
#endif
#ifdef CONF_BOARD_XCL_IN3_PC3_INV
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTC, 3), IOPORT_DIR_INPUT
			| IOPORT_FORCE_ENABLE | IOPORT_INV_ENABLED | IOPORT_PULL_UP);
#endif
#ifdef CONF_BOARD_XCL_IN3_PC7
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTC, 7), IOPORT_DIR_INPUT
			| IOPORT_FORCE_ENABLE | IOPORT_PULL_UP);
#endif
#ifdef CONF_BOARD_XCL_IN3_PC7_INV
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTC, 7), IOPORT_DIR_INPUT
			| IOPORT_FORCE_ENABLE | IOPORT_INV_ENABLED | IOPORT_PULL_UP);
#endif
}

/**
 * @}
 */
