/*****************************************************************************
 *
 * \file
 *
 * \brief FIR coefficients for the dsp16_resampling function from the DSPLib.
 *        These coefficients have the following characterizations:
 *          - Input sampling frequency: 32000 Hz
 *          - Output sampling frequency: 48000 Hz
 *          - Polyphase FIR filter order: 100
 *          - Coefficients are normalized
 *          - Memory foot print: 600 bytes
 *         It matches the following parameters:
 *         (dsp16_resampling_options_t::dsp16_custom_filter)
 *          - Cut-off frequency (fc_hz): 16000
 *          - Sampling frequency (fs_hz): 96000
 *          - Actual FIR filter order (order): 300
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
 ******************************************************************************/
 /**
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */

A_ALIGNED static const dsp16_t dsp16_resampling_fircoef_ord100_32000_48000_norm[] = {
  DSP16_Q(-0.00000000),
  DSP16_Q(0.00000101),
  DSP16_Q(-0.00000411),
  DSP16_Q(0.00000943),
  DSP16_Q(-0.00001709),
  DSP16_Q(0.00002721),
  DSP16_Q(-0.00003993),
  DSP16_Q(0.00005538),
  DSP16_Q(-0.00007370),
  DSP16_Q(0.00009502),
  DSP16_Q(-0.00011949),
  DSP16_Q(0.00014727),
  DSP16_Q(-0.00017852),
  DSP16_Q(0.00021341),
  DSP16_Q(-0.00025212),
  DSP16_Q(0.00029485),
  DSP16_Q(-0.00034180),
  DSP16_Q(0.00039321),
  DSP16_Q(-0.00044933),
  DSP16_Q(0.00051044),
  DSP16_Q(-0.00057685),
  DSP16_Q(0.00064890),
  DSP16_Q(-0.00072700),
  DSP16_Q(0.00081158),
  DSP16_Q(-0.00090318),
  DSP16_Q(0.00100237),
  DSP16_Q(-0.00110988),
  DSP16_Q(0.00122650),
  DSP16_Q(-0.00135322),
  DSP16_Q(0.00149119),
  DSP16_Q(-0.00164181),
  DSP16_Q(0.00180677),
  DSP16_Q(-0.00198818),
  DSP16_Q(0.00218862),
  DSP16_Q(-0.00241134),
  DSP16_Q(0.00266050),
  DSP16_Q(-0.00294146),
  DSP16_Q(0.00326127),
  DSP16_Q(-0.00362940),
  DSP16_Q(0.00405882),
  DSP16_Q(-0.00456782),
  DSP16_Q(0.00518300),
  DSP16_Q(-0.00594459),
  DSP16_Q(0.00691640),
  DSP16_Q(-0.00820609),
  DSP16_Q(0.01001044),
  DSP16_Q(-0.01273171),
  DSP16_Q(0.01734016),
  DSP16_Q(-0.02692321),
  DSP16_Q(0.05938832),
  DSP16_Q(0.29713838),
  DSP16_Q(-0.04239213),
  DSP16_Q(0.02275098),
  DSP16_Q(-0.01548399),
  DSP16_Q(0.01168201),
  DSP16_Q(-0.00933338),
  DSP16_Q(0.00773135),
  DSP16_Q(-0.00656370),
  DSP16_Q(0.00567116),
  DSP16_Q(-0.00496402),
  DSP16_Q(0.00438789),
  DSP16_Q(-0.00390788),
  DSP16_Q(0.00350061),
  DSP16_Q(-0.00314982),
  DSP16_Q(0.00284387),
  DSP16_Q(-0.00257420),
  DSP16_Q(0.00233439),
  DSP16_Q(-0.00211950),
  DSP16_Q(0.00192574),
  DSP16_Q(-0.00175007),
  DSP16_Q(0.00159010),
  DSP16_Q(-0.00144387),
  DSP16_Q(0.00130979),
  DSP16_Q(-0.00118656),
  DSP16_Q(0.00107307),
  DSP16_Q(-0.00096842),
  DSP16_Q(0.00087183),
  DSP16_Q(-0.00078264),
  DSP16_Q(0.00070027),
  DSP16_Q(-0.00062423),
  DSP16_Q(0.00055410),
  DSP16_Q(-0.00048950),
  DSP16_Q(0.00043009),
  DSP16_Q(-0.00037557),
  DSP16_Q(0.00032567),
  DSP16_Q(-0.00028015),
  DSP16_Q(0.00023878),
  DSP16_Q(-0.00020137),
  DSP16_Q(0.00016771),
  DSP16_Q(-0.00013764),
  DSP16_Q(0.00011097),
  DSP16_Q(-0.00008757),
  DSP16_Q(0.00006727),
  DSP16_Q(-0.00004992),
  DSP16_Q(0.00003540),
  DSP16_Q(-0.00002355),
  DSP16_Q(0.00001427),
  DSP16_Q(-0.00000740),
  DSP16_Q(0.00000284),
  DSP16_Q(-0.00000044),
  DSP16_Q(-0.00000022),
  DSP16_Q(0.00000361),
  DSP16_Q(-0.00001126),
  DSP16_Q(0.00002343),
  DSP16_Q(-0.00004036),
  DSP16_Q(0.00006231),
  DSP16_Q(-0.00008955),
  DSP16_Q(0.00012232),
  DSP16_Q(-0.00016093),
  DSP16_Q(0.00020564),
  DSP16_Q(-0.00025676),
  DSP16_Q(0.00031459),
  DSP16_Q(-0.00037948),
  DSP16_Q(0.00045176),
  DSP16_Q(-0.00053182),
  DSP16_Q(0.00062004),
  DSP16_Q(-0.00071687),
  DSP16_Q(0.00082277),
  DSP16_Q(-0.00093827),
  DSP16_Q(0.00106395),
  DSP16_Q(-0.00120044),
  DSP16_Q(0.00134848),
  DSP16_Q(-0.00150889),
  DSP16_Q(0.00168261),
  DSP16_Q(-0.00187073),
  DSP16_Q(0.00207450),
  DSP16_Q(-0.00229539),
  DSP16_Q(0.00253513),
  DSP16_Q(-0.00279578),
  DSP16_Q(0.00307982),
  DSP16_Q(-0.00339021),
  DSP16_Q(0.00373060),
  DSP16_Q(-0.00410546),
  DSP16_Q(0.00452039),
  DSP16_Q(-0.00498243),
  DSP16_Q(0.00550062),
  DSP16_Q(-0.00608667),
  DSP16_Q(0.00675611),
  DSP16_Q(-0.00752991),
  DSP16_Q(0.00843708),
  DSP16_Q(-0.00951889),
  DSP16_Q(0.01083613),
  DSP16_Q(-0.01248207),
  DSP16_Q(0.01460751),
  DSP16_Q(-0.01747302),
  DSP16_Q(0.02157096),
  DSP16_Q(-0.02795663),
  DSP16_Q(0.03937402),
  DSP16_Q(-0.06588507),
  DSP16_Q(0.19804852),
  DSP16_Q(0.19804852),
  DSP16_Q(-0.06588507),
  DSP16_Q(0.03937402),
  DSP16_Q(-0.02795663),
  DSP16_Q(0.02157096),
  DSP16_Q(-0.01747302),
  DSP16_Q(0.01460751),
  DSP16_Q(-0.01248207),
  DSP16_Q(0.01083613),
  DSP16_Q(-0.00951889),
  DSP16_Q(0.00843708),
  DSP16_Q(-0.00752991),
  DSP16_Q(0.00675611),
  DSP16_Q(-0.00608667),
  DSP16_Q(0.00550062),
  DSP16_Q(-0.00498243),
  DSP16_Q(0.00452039),
  DSP16_Q(-0.00410546),
  DSP16_Q(0.00373060),
  DSP16_Q(-0.00339021),
  DSP16_Q(0.00307982),
  DSP16_Q(-0.00279578),
  DSP16_Q(0.00253513),
  DSP16_Q(-0.00229539),
  DSP16_Q(0.00207450),
  DSP16_Q(-0.00187073),
  DSP16_Q(0.00168261),
  DSP16_Q(-0.00150889),
  DSP16_Q(0.00134848),
  DSP16_Q(-0.00120044),
  DSP16_Q(0.00106395),
  DSP16_Q(-0.00093827),
  DSP16_Q(0.00082277),
  DSP16_Q(-0.00071687),
  DSP16_Q(0.00062004),
  DSP16_Q(-0.00053182),
  DSP16_Q(0.00045176),
  DSP16_Q(-0.00037948),
  DSP16_Q(0.00031459),
  DSP16_Q(-0.00025676),
  DSP16_Q(0.00020564),
  DSP16_Q(-0.00016093),
  DSP16_Q(0.00012232),
  DSP16_Q(-0.00008955),
  DSP16_Q(0.00006231),
  DSP16_Q(-0.00004036),
  DSP16_Q(0.00002343),
  DSP16_Q(-0.00001126),
  DSP16_Q(0.00000361),
  DSP16_Q(-0.00000022),
  DSP16_Q(-0.00000044),
  DSP16_Q(0.00000284),
  DSP16_Q(-0.00000740),
  DSP16_Q(0.00001427),
  DSP16_Q(-0.00002355),
  DSP16_Q(0.00003540),
  DSP16_Q(-0.00004992),
  DSP16_Q(0.00006727),
  DSP16_Q(-0.00008757),
  DSP16_Q(0.00011097),
  DSP16_Q(-0.00013764),
  DSP16_Q(0.00016771),
  DSP16_Q(-0.00020137),
  DSP16_Q(0.00023878),
  DSP16_Q(-0.00028015),
  DSP16_Q(0.00032567),
  DSP16_Q(-0.00037557),
  DSP16_Q(0.00043009),
  DSP16_Q(-0.00048950),
  DSP16_Q(0.00055410),
  DSP16_Q(-0.00062423),
  DSP16_Q(0.00070027),
  DSP16_Q(-0.00078264),
  DSP16_Q(0.00087183),
  DSP16_Q(-0.00096842),
  DSP16_Q(0.00107307),
  DSP16_Q(-0.00118656),
  DSP16_Q(0.00130979),
  DSP16_Q(-0.00144387),
  DSP16_Q(0.00159010),
  DSP16_Q(-0.00175007),
  DSP16_Q(0.00192574),
  DSP16_Q(-0.00211950),
  DSP16_Q(0.00233439),
  DSP16_Q(-0.00257420),
  DSP16_Q(0.00284387),
  DSP16_Q(-0.00314982),
  DSP16_Q(0.00350061),
  DSP16_Q(-0.00390788),
  DSP16_Q(0.00438789),
  DSP16_Q(-0.00496402),
  DSP16_Q(0.00567116),
  DSP16_Q(-0.00656370),
  DSP16_Q(0.00773135),
  DSP16_Q(-0.00933338),
  DSP16_Q(0.01168201),
  DSP16_Q(-0.01548399),
  DSP16_Q(0.02275098),
  DSP16_Q(-0.04239213),
  DSP16_Q(0.29713838),
  DSP16_Q(0.05938832),
  DSP16_Q(-0.02692321),
  DSP16_Q(0.01734016),
  DSP16_Q(-0.01273171),
  DSP16_Q(0.01001044),
  DSP16_Q(-0.00820609),
  DSP16_Q(0.00691640),
  DSP16_Q(-0.00594459),
  DSP16_Q(0.00518300),
  DSP16_Q(-0.00456782),
  DSP16_Q(0.00405882),
  DSP16_Q(-0.00362940),
  DSP16_Q(0.00326127),
  DSP16_Q(-0.00294146),
  DSP16_Q(0.00266050),
  DSP16_Q(-0.00241134),
  DSP16_Q(0.00218862),
  DSP16_Q(-0.00198818),
  DSP16_Q(0.00180677),
  DSP16_Q(-0.00164181),
  DSP16_Q(0.00149119),
  DSP16_Q(-0.00135322),
  DSP16_Q(0.00122650),
  DSP16_Q(-0.00110988),
  DSP16_Q(0.00100237),
  DSP16_Q(-0.00090318),
  DSP16_Q(0.00081158),
  DSP16_Q(-0.00072700),
  DSP16_Q(0.00064890),
  DSP16_Q(-0.00057685),
  DSP16_Q(0.00051044),
  DSP16_Q(-0.00044933),
  DSP16_Q(0.00039321),
  DSP16_Q(-0.00034180),
  DSP16_Q(0.00029485),
  DSP16_Q(-0.00025212),
  DSP16_Q(0.00021341),
  DSP16_Q(-0.00017852),
  DSP16_Q(0.00014727),
  DSP16_Q(-0.00011949),
  DSP16_Q(0.00009502),
  DSP16_Q(-0.00007370),
  DSP16_Q(0.00005538),
  DSP16_Q(-0.00003993),
  DSP16_Q(0.00002721),
  DSP16_Q(-0.00001709),
  DSP16_Q(0.00000943),
  DSP16_Q(-0.00000411),
  DSP16_Q(0.00000101),
  DSP16_Q(-0.00000000)
};
