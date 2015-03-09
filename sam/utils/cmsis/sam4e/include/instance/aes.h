/**
 * \file
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

#ifndef _SAM4E_AES_INSTANCE_
#define _SAM4E_AES_INSTANCE_

/* ========== Register definition for AES peripheral ========== */
#if (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
  #define REG_AES_CR                      (0x40004000U) /**< \brief (AES) Control Register */
  #define REG_AES_MR                      (0x40004004U) /**< \brief (AES) Mode Register */
  #define REG_AES_IER                     (0x40004010U) /**< \brief (AES) Interrupt Enable Register */
  #define REG_AES_IDR                     (0x40004014U) /**< \brief (AES) Interrupt Disable Register */
  #define REG_AES_IMR                     (0x40004018U) /**< \brief (AES) Interrupt Mask Register */
  #define REG_AES_ISR                     (0x4000401CU) /**< \brief (AES) Interrupt Status Register */
  #define REG_AES_KEYWR                   (0x40004020U) /**< \brief (AES) Key Word Register */
  #define REG_AES_IDATAR                  (0x40004040U) /**< \brief (AES) Input Data Register */
  #define REG_AES_ODATAR                  (0x40004050U) /**< \brief (AES) Output Data Register */
  #define REG_AES_IVR                     (0x40004060U) /**< \brief (AES) Initialization Vector Register */
#else
  #define REG_AES_CR     (*(__O  uint32_t*)0x40004000U) /**< \brief (AES) Control Register */
  #define REG_AES_MR     (*(__IO uint32_t*)0x40004004U) /**< \brief (AES) Mode Register */
  #define REG_AES_IER    (*(__O  uint32_t*)0x40004010U) /**< \brief (AES) Interrupt Enable Register */
  #define REG_AES_IDR    (*(__O  uint32_t*)0x40004014U) /**< \brief (AES) Interrupt Disable Register */
  #define REG_AES_IMR    (*(__I  uint32_t*)0x40004018U) /**< \brief (AES) Interrupt Mask Register */
  #define REG_AES_ISR    (*(__I  uint32_t*)0x4000401CU) /**< \brief (AES) Interrupt Status Register */
  #define REG_AES_KEYWR  (*(__O  uint32_t*)0x40004020U) /**< \brief (AES) Key Word Register */
  #define REG_AES_IDATAR (*(__O  uint32_t*)0x40004040U) /**< \brief (AES) Input Data Register */
  #define REG_AES_ODATAR (*(__I  uint32_t*)0x40004050U) /**< \brief (AES) Output Data Register */
  #define REG_AES_IVR    (*(__O  uint32_t*)0x40004060U) /**< \brief (AES) Initialization Vector Register */
#endif /* (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#endif /* _SAM4E_AES_INSTANCE_ */
