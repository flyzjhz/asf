/**
 * \file
 *
 * \brief Common Sensor Service Light/Proximity Sensor Wake Event Example
 *
 * Copyright (C) 2012-2014 Atmel Corporation. All rights reserved.
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
 *
 * \section intro Introduction
 *
 * This application demonstrates the use of sensor events generated by the
 * light and/or proximity sensor devices installed on an Atmel Sensors Xplained
 * board.  The application sets up the sensor event handler(s), then places
 * the microcontroller in a low-power sleep state.  When the specified
 * sensor event occurs, the system wakes up, reads and displays sensor data,
 * and re-enters the sleep mode.  This wake/sleep cycle repeats indefinitely.
 *
 * \section contactinfo Contact Information
 * For further information, visit
 * <A href="http://www.atmel.com/avr">Atmel AVR</A>.\n
 * Support and FAQ: http://www.atmel.com/design-support/
 */
 /**
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */

#include <stdio.h>
#include <asf.h>
#include <led.h>

/* Configuration Constants */
#define LIGHT_WAKE         (true) /* If true, use light level to wake up */
#define LIGHT_SAMPLE_RATE  (10)   /* Light sensor sample rate (Hz) */
#define LIGHT_THRESH       (300)  /* Light threshold (lux) */

#define PROX_WAKE          (true) /* If true, use near proximity to wake up */
#define PROX_SAMPLE_RATE   (10)   /* proximity sensor sample rate (Hz) */
#define PROX_THRESH        (100)  /* Set "near" proximity threshold (counts) */

#define SET_PROX_THRESHOLD (true) /* If true, manually set proximity
	                           * threshold */
#define PROX_THRESHOLD     (100)  /* Manual prox. sensor threshold for "near" */

#define SET_PROX_CURRENT   (true) /* If true, manually set proximity current */
#define PROX_CURRENT_mA    (50)   /* Prox sensor LED current value (mA) */

#define USE_PRINTF         (true)
#define SCALED_DATA        (true)

#if UC3
/* UC3 Sleep Mode to use, one of: */
/*   SLEEPMGR_ACTIVE, SLEEPMGR_IDLE, SLEEPMGR_FROZEN, SLEEPMGR_STDBY, */
/*   SLEEPMGR_STOP, SLEEPMGR_DEEPSTOP, SLEEPMGR_STATIC, */
/*   SLEEPMGR_SHUTDOWN (UC3L only) */
#  define SLEEP_MODE     (SLEEPMGR_FROZEN)   /* sleep mode to use */

#elif XMEGA
/* XMega Sleep Mode to use, one of: */
/*   SLEEPMGR_ACTIVE, SLEEPMGR_IDLE, SLEEPMGR_ESTDBY, SLEEPMGR_PSAVE, */
/*   SLEEPMGR_STDBY, SLEEPMGR_PDOWN */
#  define SLEEP_MODE     (SLEEPMGR_IDLE)     /* sleep mode to use */
#endif

/* LED definitions */
#if (BOARD == UC3_L0_XPLAINED)
#  define ACTIVITY_LED  LED4  /* LED to show awake/operating */
#  define LIGHT_LED     LED1  /* LED to indicate light sensor interrupt */
#  define PROX_LED      LED0  /* LED to indicate proximity sensor interrupt */

#elif (BOARD == UC3_A3_XPLAINED)
#  define ACTIVITY_LED  LED0  /* LED to show awake/operating */
#  define LIGHT_LED     LED1  /* LED to indicate light sensor interrupt */
#  define PROX_LED      LED3  /* LED to indicate proximity sensor interrupt */

#elif (BOARD == XMEGA_A1_XPLAINED) || (BOARD == XMEGA_B1_XPLAINED) || \
	(BOARD == XMEGA_A3BU_XPLAINED)
#  define ACTIVITY_LED  LED0  /* LED to show awake/operating */
#  define LIGHT_LED     LED2  /* LED to indicate light sensor interrupt */
#  define PROX_LED      LED3  /* LED to indicate proximity sensor interrupt */

#endif

/** Strings to display based on proximity values */
static const char *const prox_labels[4] = {
	"none  ",       /* PROXIMITY_NONE */
	"FAR   ",       /* PROXIMITY_FAR */
	"MEDIUM",       /* PROXIMITY_MEDIUM */
	"NEAR  "        /* PROXIMITY_NEAR */
};

/* Set up sensor data storage and data formats. */
#if (LIGHT_WAKE == true)
sensor_t light_dev;                 /* Light sensor descriptor */
volatile sensor_data_t light_data = { .scaled = SCALED_DATA };
bool light_event_occurred = false;  /* Flag to indicate event */
#endif

#if (PROX_WAKE == true)
sensor_t prox_dev;                  /* Proximity sensor descriptor */
volatile sensor_data_t prox_data    = { .scaled = SCALED_DATA };
volatile int16_t prox_channel;
bool prox_event_occurred = false;   /* Flag to indicate event */
#endif


#if (LIGHT_WAKE == true)
/** \internal Light Sensor Event Callback Routine */
static void light_event(volatile sensor_event_data_t *event_data,
		volatile void *in)
{
	light_data = event_data->data;

	LED_Toggle(LIGHT_LED);
	light_event_occurred = true;
}
#endif

#if (PROX_WAKE == true)
/** \internal Proximity Sensor Event Callback Routine */
static void prox_event(volatile sensor_event_data_t *event_data,
		volatile void *in)
{
	prox_data    = event_data->data;
	prox_channel = event_data->channel;

	LED_Toggle(PROX_LED);
	prox_event_occurred = true;
}
#endif

/** \brief Inertial sensor demo application entry
 *
 * After initializing the Xplained platform and sensor boards, this application
 * attaches descriptors to the ambient light and proximity sensor devices on
 * an Xplained inertial sensor board.  The sensors are configured to wake up
 * the processor if given threshold values are surpassed.
 */
int main(void)
{
#if (USE_PRINTF == true)
	uint32_t id;      /* Device ID */
	uint8_t version;  /* Device version */
#endif

	/* Initialize the board (Xplained UC3 or XMEGA & Xplained Sensor boards)
	 * I/O pin mappings and any other configurable resources selected in
	 * the build configuration.
	 */
	sensor_platform_init();

	LED_On(ACTIVITY_LED);

#if (USE_PRINTF == true)
	printf("\r\n");
#endif

	/* Initialize the MCU sleep manager API and specify a sleep mode. */
	sleepmgr_init();
	sleepmgr_lock_mode(SLEEP_MODE);

#if (LIGHT_WAKE == true)
	/* Attach light sensor */
	sensor_attach(&light_dev, SENSOR_TYPE_LIGHT, 0, 0);

	if (light_dev.err) {
		puts("\r\nLight sensor initialization error.");

		while (true) {
			/* Error occurred, loop forever */
		}
	}

#  if (USE_PRINTF == true)
	sensor_device_id(&light_dev, &id, &version);
	printf("Light sensor: %s    ID = 0x%02x ver. 0x%02x\r\n",
			light_dev.drv->caps.name, (unsigned)id,
			(unsigned)version);
#  endif

	sensor_set_sample_rate(&light_dev, LIGHT_SAMPLE_RATE);

	sensor_set_threshold(&light_dev, SENSOR_THRESHOLD_HIGH_LIGHT,
			LIGHT_THRESH);

	/* Enable high light level event for wakeup */
	sensor_add_event(&light_dev, SENSOR_EVENT_HIGH_LIGHT,
			light_event, 0, true);
#endif

#if (PROX_WAKE == true)
	/* Attach proximity sensor */
	sensor_attach(&prox_dev, SENSOR_TYPE_PROXIMITY, 0, 0);

	if (prox_dev.err) {
		puts("\r\nProximity sensor initialization error.");

		while (true) {
			/* Error occurred, loop forever */
		}
	}

#  if (USE_PRINTF == true)
	sensor_device_id(&prox_dev, &id, &version);
	printf("Proximity sensor: %s    ID = 0x%02x ver. 0x%02x\r\n",
			prox_dev.drv->caps.name, (unsigned)id,
			(unsigned)version);
#  endif

	sensor_set_sample_rate(&prox_dev, PROX_SAMPLE_RATE);

	/* Select all proximity sensor channels */
	sensor_set_channel(&prox_dev, 0);

#  if (SET_PROX_THRESHOLD == true)
	/* Manually set proximity threshold values for each channel */
	/* Otherwise, sensor will use values previously stored in nvram. */
	sensor_set_threshold(&prox_dev, SENSOR_THRESHOLD_NEAR_PROXIMITY,
			PROX_THRESHOLD);
#  endif

#  if (SET_PROX_CURRENT == true)
	/* Manually set LED current value for each channel */
	/* Otherwise, sensor will use default values. */
	sensor_set_current(&prox_dev, PROX_CURRENT_mA);
#  endif

	/* Enable near proximity event for wakeup */
	sensor_add_event(&prox_dev, SENSOR_EVENT_NEAR_PROXIMITY,
			prox_event, 0, true);
#endif

	while (true) {
		LED_Off(ACTIVITY_LED);

		/* Put device in low power sleep mode; wait for an interrupt to
		 * wake. */
		sleepmgr_enter_sleep();

		/* Device has woken up */
		LED_On(ACTIVITY_LED);

#if (USE_PRINTF == true)
#  if (LIGHT_WAKE == true)
		if (light_event_occurred) {
			light_event_occurred = false;
			
			printf("light level = %5d\r\n",
					(int16_t)light_data.light.value);
		}
#  endif

#  if (PROX_WAKE == true)
		if (prox_event_occurred) {
			prox_event_occurred = false;

			printf("proximity: source channel=%d  time=%010ld  ",
					prox_channel, prox_data.timestamp);

			if (SCALED_DATA) {
				printf("Chan1:%s Chan2:%s Chan3:%s\r\n",
						prox_labels[prox_data.proximity.value[0]],
						prox_labels[prox_data.proximity.value[1]],
						prox_labels[prox_data.proximity.value[2]]);
			} else {
				printf("Chan1:%4d Chan2:%4d Chan3:%4d\r\n",
						(int16_t)prox_data.proximity.value[0],
						(int16_t)prox_data.proximity.value[1],
						(int16_t)prox_data.proximity.value[2]);
			}
		}
#  endif
#endif

		delay_ms(500);
	}

	return 0;
}
