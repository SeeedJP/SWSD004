/*!
 * @ingroup   apps_geolocation
 * @file      main_geolocation_gnss.h
 *
 * @brief     LoRa Basics Modem LR11XX Geolocation GNSS example with *scan group" for static geolocation.
 *
 * @copyright
 * @parblock
 * The Clear BSD License
 * Copyright Semtech Corporation 2021. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted (subject to the limitations in the disclaimer
 * below) provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Semtech corporation nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * NO EXPRESS OR IMPLIED LICENSES TO ANY PARTY'S PATENT RIGHTS ARE GRANTED BY
 * THIS LICENSE. THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND
 * CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT
 * NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 * PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL SEMTECH CORPORATION BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 * @endparblock
 */

/*!
 * @addtogroup apps_geolocation
 * LoRa Basics Modem LR11XX Geolocation example
 * @{
 */

#ifndef MAIN_GEOLOCATION_GNSS_H
#define MAIN_GEOLOCATION_GNSS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/*
 * -----------------------------------------------------------------------------
 * --- Application Configuration -----------------------------------------------
 */

/*!
 * @brief Time during which a LED is turned on when a TX or RX event occurs, in [ms]
 */
#define LED_PERIOD_MS_DEFAULT 250

/**
 * @brief Let the application autonomously set the assistance position for GNSS geolocation (default, autonomous mode)
 */
#define MODEM_EXAMPLE_ASSISTANCE_POSITION_AUTO_DEFAULT true

/**
 * @brief User defined assistance position for GNSS geolocation (not used by default, autonomous mode)
 */
#define MODEM_EXAMPLE_ASSISTANCE_POSITION_LAT_DEFAULT ( 45.181454 )
#define MODEM_EXAMPLE_ASSISTANCE_POSITION_LONG_DEFAULT ( 5.720893 )
#define MODEM_EXAMPLE_ASSISTANCE_POSITION_TEXT_DEFAULT "Grenoble, FRANCE"

/*
 * -----------------------------------------------------------------------------
 * --- Geolocation scan group Configuration ------------------------------------
 */

/*!
 * @brief Defines the delay before starting a new GNSS scan group, value in [s].
 */
#define GNSS_SCAN_GROUP_PERIOD_DEFAULT 30

/*!
 * @brief Defines the scan mode used for GNSS (STATIC or MOBILE).
 */
#define GNSS_SCAN_MODE_DEFAULT GNSS_MW_MODE_STATIC

#ifndef LED_PERIOD_MS
#define LED_PERIOD_MS LED_PERIOD_MS_DEFAULT
#endif  // LED_PERIOD_MS

#ifndef MODEM_EXAMPLE_ASSISTANCE_POSITION_AUTO
#define MODEM_EXAMPLE_ASSISTANCE_POSITION_AUTO MODEM_EXAMPLE_ASSISTANCE_POSITION_AUTO_DEFAULT
#endif  // MODEM_EXAMPLE_ASSISTANCE_POSITION_AUTO

#ifndef MODEM_EXAMPLE_ASSISTANCE_POSITION_LAT
#define MODEM_EXAMPLE_ASSISTANCE_POSITION_LAT MODEM_EXAMPLE_ASSISTANCE_POSITION_LAT_DEFAULT
#endif  // MODEM_EXAMPLE_ASSISTANCE_POSITION_LAT

#ifndef MODEM_EXAMPLE_ASSISTANCE_POSITION_LONG
#define MODEM_EXAMPLE_ASSISTANCE_POSITION_LONG MODEM_EXAMPLE_ASSISTANCE_POSITION_LONG_DEFAULT
#endif  // MODEM_EXAMPLE_ASSISTANCE_POSITION_LONG

#ifndef MODEM_EXAMPLE_ASSISTANCE_POSITION_TEXT
#define MODEM_EXAMPLE_ASSISTANCE_POSITION_TEXT MODEM_EXAMPLE_ASSISTANCE_POSITION_TEXT_DEFAULT
#endif  // MODEM_EXAMPLE_ASSISTANCE_POSITION_TEXT

#ifndef GNSS_SCAN_GROUP_PERIOD
#define GNSS_SCAN_GROUP_PERIOD GNSS_SCAN_GROUP_PERIOD_DEFAULT
#endif  // GNSS_SCAN_GROUP_PERIOD

#ifndef GNSS_SCAN_MODE
#define GNSS_SCAN_MODE GNSS_SCAN_MODE_DEFAULT
#endif  // GNSS_SCAN_MODE
/*
 * -----------------------------------------------------------------------------
 * --- LoRaWAN Configuration ---------------------------------------------------
 */

/*!
 * @brief ADR custom list and retransmission parameters for EU868 region
 */
#define CUSTOM_NB_TRANS_EU868 1
#define ADR_CUSTOM_LIST_EU868                          \
    {                                                  \
        5, 5, 5, 5, 5, 5, 5, 5, 5, 4, 4, 4, 4, 4, 3, 3 \
    } /* 125kHz - SF7, SF8, SF9 */

/*!
 * @brief ADR custom list and retransmission parameters for CN470 region
 */
#define CUSTOM_NB_TRANS_CN470 2
#define ADR_CUSTOM_LIST_CN470                          \
    {                                                  \
        5, 5, 5, 5, 5, 5, 5, 5, 5, 4, 4, 4, 4, 4, 3, 3 \
    } /* 125kHz - SF7, SF8, SF9 */

/*!
 * @brief ADR custom list and retransmission parameters for US915 region
 */
#define CUSTOM_NB_TRANS_US915 2
#define ADR_CUSTOM_LIST_US915                          \
    {                                                  \
        3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 1, 1 \
    } /* 125kHz - SF7, SF8, SF9 */

#ifdef __cplusplus
}
#endif

#endif  // MAIN_GEOLOCATION_GNSS_H

/*!
 * @}
 */

/* --- EOF ------------------------------------------------------------------ */
