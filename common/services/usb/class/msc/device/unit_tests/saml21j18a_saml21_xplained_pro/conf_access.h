/**
 * \file
 *
 * \brief Memory access control configuration file.
 *
 * Copyright (c) 2014 Atmel Corporation. All rights reserved.
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

#ifndef _CONF_ACCESS_H_
#define _CONF_ACCESS_H_

#include "compiler.h"
#include "board.h"


/*! \name Activation of Logical Unit Numbers
 */
//! @{
#define LUN_0                ENABLE    //!< On-Chip Virtual Memory.
#define LUN_1                DISABLE   //!< AT45DBX Data Flash.
#define LUN_2                DISABLE   //!< SD/MMC Card over SPI.
#define LUN_3                DISABLE   //!< SD/MMC Card over MCI Slot 0.
#define LUN_4                DISABLE
#define LUN_5                DISABLE
#define LUN_6                DISABLE
#define LUN_7                DISABLE
#define LUN_USB              DISABLE   //!< Host Mass-Storage Memory.
//! @}

/*! \name LUN 0 Definitions
 */
//! @{
#define VIRTUAL_MEM                             LUN_0
#define LUN_ID_VIRTUAL_MEM                      LUN_ID_0
#define LUN_0_INCLUDE                           "virtual_mem.h"
#define Lun_0_test_unit_ready                   virtual_test_unit_ready
#define Lun_0_read_capacity                     virtual_read_capacity
#define Lun_0_wr_protect                        virtual_wr_protect
#define Lun_0_removal                           virtual_removal
#define Lun_0_usb_read_10                       virtual_usb_read_10
#define Lun_0_usb_write_10                      virtual_usb_write_10
#define Lun_0_mem_2_ram                         virtual_mem_2_ram
#define Lun_0_ram_2_mem                         virtual_ram_2_mem
#define LUN_0_NAME                              "\"On-Chip Virtual Memory\""
//! @}

/*! \name USB LUNs Definitions
 */
//! @{
#define MEM_USB                                 LUN_USB
#define LUN_ID_MEM_USB                          LUN_ID_USB
#define LUN_USB_INCLUDE                         "host_mem.h"
#define Lun_usb_test_unit_ready(lun)            host_test_unit_ready(lun)
#define Lun_usb_read_capacity(lun, nb_sect)     host_read_capacity(lun, nb_sect)
#define Lun_usb_read_sector_size(lun)           host_read_sector_size(lun)
#define Lun_usb_wr_protect(lun)                 host_wr_protect(lun)
#define Lun_usb_removal()                       host_removal()
#define Lun_usb_mem_2_ram(addr, ram)            host_read_10_ram(addr, ram)
#define Lun_usb_ram_2_mem(addr, ram)            host_write_10_ram(addr, ram)
#define LUN_USB_NAME                            "\"Host Mass-Storage Memory\""
//! @}

/*! \name Actions Associated with Memory Accesses
 *
 * Write here the action to associate with each memory access.
 *
 * \warning Be careful not to waste time in order not to disturb the functions.
 */
//! @{
#define memory_start_read_action(nb_sectors)
#define memory_stop_read_action()               main_msc_read_finish()
#define memory_start_write_action(nb_sectors)
#define memory_stop_write_action()
#include "unit_tests.h"
//! @}

/*! \name Activation of Interface Features
 */
//! @{
#define ACCESS_USB           true    //!< MEM <-> USB interface.
#define ACCESS_MEM_TO_RAM    false   //!< MEM <-> RAM interface.
#define ACCESS_STREAM        false   //!< Streaming MEM <-> MEM interface.
#define ACCESS_STREAM_RECORD false   //!< Streaming MEM <-> MEM interface in record mode.
#define ACCESS_MEM_TO_MEM    false   //!< MEM <-> MEM interface.
#define ACCESS_CODEC         false   //!< Codec interface.
//! @}

/*! \name Specific Options for Access Control
 */
//! @{
#define GLOBAL_WR_PROTECT    false   //!< Management of a global write protection.
//! @}


#endif // _CONF_ACCESS_H_
