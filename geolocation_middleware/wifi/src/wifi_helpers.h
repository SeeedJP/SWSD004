/**
 * @file      wifi_helpers.h
 *
 * @brief     Interface between the WI-Fi middleware and the LR11xx radio driver.
 *
 * The Clear BSD License
 * Copyright Semtech Corporation 2022. All rights reserved.
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
 */

#ifndef __WIFI_HELPERS_H__
#define __WIFI_HELPERS_H__

#ifdef __cplusplus
extern "C" {
#endif

/*
 * -----------------------------------------------------------------------------
 * --- DEPENDENCIES ------------------------------------------------------------
 */

#include <stdint.h>

/*
 * -----------------------------------------------------------------------------
 * --- PUBLIC MACROS -----------------------------------------------------------
 */

/*
 * -----------------------------------------------------------------------------
 * --- PUBLIC CONSTANTS --------------------------------------------------------
 */

/*!
 * @brief The maximal time to spend in preamble detection for each single scan, in ms
 */
#define WIFI_TIMEOUT_PER_SCAN_DEFAULT ( 90 )

/*!
 * @brief The time to spend scanning one channel, in ms
 */
#define WIFI_TIMEOUT_PER_CHANNEL_DEFAULT ( 300 )

/*!
 * @brief The maximal number of results to gather. Maximum value is 32.
 */
#define WIFI_MAX_RESULTS ( 5 )

/*
 * -----------------------------------------------------------------------------
 * --- PUBLIC TYPES ------------------------------------------------------------
 */

/*!
 * @brief Structure representing the configuration of Wi-Fi scan
 */
typedef struct
{
    lr11xx_wifi_channel_mask_t     channels;             //!< A mask of the channels to be scanned
    lr11xx_wifi_signal_type_scan_t types;                //!< Wi-Fi types to be scanned
    uint8_t                        max_results;          //!< The maximum number of results expected for a scan
    uint32_t                       timeout_per_channel;  //!< The time to spend scanning one channel, in ms.
    uint32_t timeout_per_scan;  //!< The maximal time to spend in preamble detection for each single scan, in ms.
} wifi_settings_t;

/*!
 * @brief Structure representing a single scan result
 */
typedef struct
{
    lr11xx_wifi_mac_address_t mac_address;  //!< The MAC address of the Wi-Fi access point which has been detected
    lr11xx_wifi_channel_t     channel;      //!< The channel on which the access point has been detected
    lr11xx_wifi_signal_type_result_t type;  //!< The type of Wi-Fi which has been detected
    int8_t                           rssi;  //!< The strength of the detected signal
} wifi_scan_single_result_t;

/*!
 * @brief Structure representing a collection of scan results
 */
typedef struct
{
    uint8_t                   nbr_results;                //!< The number of results
    uint32_t                  power_consumption_uah;      //!< The power consumption to acquire this set of results
    uint32_t                  timestamp;                  //!< The timestamp at which the data set has been completed
    wifi_scan_single_result_t results[WIFI_MAX_RESULTS];  //!< The buffer containing the results
} wifi_scan_all_result_t;

/*
 * -----------------------------------------------------------------------------
 * --- PUBLIC FUNCTIONS PROTOTYPES ---------------------------------------------
 */

/*!
 * @brief Initialise the settings for Wi-Fi scan
 *
 * @param [in] wifi_settings Wi-Fi settings \ref wifi_settings_t
 */
void smtc_wifi_settings_init( wifi_settings_t wifi_settings );

/*!
 * @brief Start a Wi-Fi scan
 *
 * @param [in] ral_context Chip implementation context
 *
 * @return a boolean: true for success, false otherwise.
 */
bool smtc_wifi_start_scan( const void* ral_context );

/*!
 * @brief Fetch the results obtained during previous Wi-Fi scan
 *
 * @param [in] ral_context Chip implementation context
 * @param [out] result the scan results \ref wifi_scan_all_result_t
 */
void smtc_wifi_get_results( const void* ral_context, wifi_scan_all_result_t* result );

/*!
 * @brief Tear down function for Wi-Fi scan termination actions
 *
 * This function is typically to be called when during the handling of the event of user radio access.
 */
void smtc_wifi_scan_ended( void );

/*!
 * @brief Get the power consumption of the last scan
 *
 * @param [in] ral_context Chip implementation context
 * @param [out] power_consumption_uah The number power consumption of the last scan in uAh.
 *
 * @return a boolean: true for success, false otherwise.
 */
bool smtc_wifi_get_power_consumption( const void* ral_context, uint32_t* power_consumption_uah );

#ifdef __cplusplus
}
#endif

#endif  // __WIFI_HELPERS_H__

/* --- EOF ------------------------------------------------------------------ */
