/**
 * \file
 *
 * \brief Unit tests for ABDAC driver.
 *
 * Copyright (c) 2014-2015 Atmel Corporation. All rights reserved.
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
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */

#include <asf.h>
#include <conf_test.h>

/**
 * \mainpage
 *
 * \section intro Introduction
 * This is the unit test application for the ABDAC driver.
 * It contains two test case for the ABDACB module:
 * - Test Initialization.
 * - Test interrupt management.
 *
 * \section files Main Files
 * - \ref unit_tests.c
 * - \ref conf_test.h
 * - \ref conf_board.h
 * - \ref conf_clock.h
 * - \ref conf_uart_serial.h
 *
 * \section device_info Device Info
 * Only devices with ABDAC module can be used.
 * This example has been tested with the following setup:
 * - sam4lc4c_sam4l_ek
 *
 * \section compinfo Compilation info
 * This software was written for the GNU GCC and IAR for ARM. Other compilers
 * may or may not work.
 *
 * \section contactinfo Contact Information
 * For further information, visit <a href="http://www.atmel.com/">Atmel</a>.\n
 */

/** ABDAC instance */
struct abdac_dev_inst g_abdac_inst;

/** ABDAC configuration */
struct abdac_config   g_abdac_cfg;

volatile bool flag = false;

/**
 * \brief The ABDAC interrupt call back function.
 */
static void abdac_callback(void)
{
	volatile uint32_t status = abdac_read_interrupt_mask(&g_abdac_inst);

	if (status & ABDACB_IER_TXRDY) {
		abdac_disable_interrupt(&g_abdac_inst, ABDAC_INTERRUPT_TXRDY);
	} else if (status & ABDACB_IER_TXUR){
		abdac_disable_interrupt(&g_abdac_inst, ABDAC_INTERRUPT_TXUR);
	}
	flag = true;
}

/**
 * \brief Test ABDAC initialization APIs.
 *
 * \param test Current test case.
 */
static void run_abdac_init_test(const struct test_case *test)
{
	status_code_t status;

	/* Config the ABDAC. */
	abdac_get_config_defaults(&g_abdac_cfg);
	status = abdac_init(&g_abdac_inst, ABDACB, &g_abdac_cfg);
	abdac_enable(&g_abdac_inst);
	abdac_clear_interrupt_flag(&g_abdac_inst, ABDAC_INTERRUPT_TXRDY);
	abdac_clear_interrupt_flag(&g_abdac_inst, ABDAC_INTERRUPT_TXUR);

	test_assert_true(test, status == STATUS_OK,
			"Initialization fails!");
}

/**
 * \brief Test ABDAC interrupt APIs.
 *
 * \param test Current test case.
 */
static void run_abdac_interrupt_test(const struct test_case *test)
{
	flag = false;

	/* Enable ABDAC transfer ready interrupt. */
	abdac_set_callback(&g_abdac_inst, ABDAC_INTERRUPT_TXRDY,
			abdac_callback, 1);

	/* Wait for the interrupt. */
	delay_ms(30);

	test_assert_true(test, flag == true,
			"Transfer ready interrupt fails!");

	flag = false;

	/* Enable ABDAC transfer underrun interrupt. */
	abdac_set_callback(&g_abdac_inst, ABDAC_INTERRUPT_TXUR,
			abdac_callback, 1);

	/* Wait for the interrupt. */
	delay_ms(30);

	test_assert_true(test, flag == true,
			"Transfer underrun interrupt fails!");
}

/**
 * \brief Run ABDAC driver unit tests.
 */
int main(void)
{
	const usart_serial_options_t usart_serial_options = {
		.baudrate = CONF_TEST_BAUDRATE,
		.charlength = CONF_TEST_CHARLENGTH,
		.paritytype = CONF_TEST_PARITY,
		.stopbits = CONF_TEST_STOPBITS
	};

	sysclk_init();
	board_init();
	stdio_serial_init(CONF_TEST_USART, &usart_serial_options);

	/* Define all the test cases. */
	DEFINE_TEST_CASE(abdac_init_test, NULL, run_abdac_init_test, NULL,
			"SAM ABDAC initialization test.");
	DEFINE_TEST_CASE(abdac_interrupt_test, NULL, run_abdac_interrupt_test,
			NULL, "SAM ABDAC interrupt test.");

	/* Put test case addresses in an array. */
	DEFINE_TEST_ARRAY(abdac_tests) = {
		&abdac_init_test,
		&abdac_interrupt_test,
	};

	/* Define the test suite. */
	DEFINE_TEST_SUITE(abdac_suite, abdac_tests,
			"SAM ABDAC driver test suite");

	/* Run all tests in the test suite. */
	test_suite_run(&abdac_suite);

	while (1) {
		/* Busy-wait forever. */
	}
}
