/*
<<<<<<< HEAD
<<<<<<< HEAD
=======
 * Copyright (c) 2012-2013, The Linux Foundation. All rights reserved.
 *
 * Previously licensed under the ISC license by Qualcomm Atheros, Inc.
 *
 *
 * Permission to use, copy, modify, and/or distribute this software for
 * any purpose with or without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all
 * copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
 * WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE
 * AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */
/*
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
 * Copyright (c) 2012, The Linux Foundation. All rights reserved.
 *
 * Previously licensed under the ISC license by Qualcomm Atheros, Inc.
 *
 *
 * Permission to use, copy, modify, and/or distribute this software for
 * any purpose with or without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all
 * copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
 * WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE
 * AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
/**========================================================================= 

                       EDIT HISTORY FOR FILE 
   
   
  This section contains comments describing changes made to the module. 
  Notice that changes are listed in reverse chronological order. 
   
   
  $Header:$   $DateTime: $ $Author: $ 
   
   
  when        who    what, where, why 
<<<<<<< HEAD
  --------    ---    --------------------------------------------------------
  07/27/09    kanand Created module. 
=======
/**=========================================================================

                       EDIT HISTORY FOR FILE


  This section contains comments describing changes made to the module.
  Notice that changes are listed in reverse chronological order.


  $Header:$   $DateTime: $ $Author: $


  when        who    what, where, why
  --------    ---    --------------------------------------------------------
  07/27/09    kanand Created module.
>>>>>>> d97af3b... add prima wlan driver
=======
  --------    ---    --------------------------------------------------------
  07/27/09    kanand Created module. 
>>>>>>> 657b0e9... prima update

  ==========================================================================*/

/*--------------------------------------------------------------------------
  Include Files
  ------------------------------------------------------------------------*/


#include <linux/firmware.h>
#include <linux/string.h>
#include <wlan_hdd_includes.h>
#include <wlan_hdd_main.h>
#include <wlan_hdd_assoc.h>
#include <wlan_hdd_cfg.h>
#include <linux/string.h>
#include <vos_types.h>
#include <csrApi.h>
#include <pmcApi.h>
#include <wlan_hdd_misc.h>

<<<<<<< HEAD
<<<<<<< HEAD
=======
#if  defined (WLAN_FEATURE_VOWIFI_11R) || defined (FEATURE_WLAN_CCX) || defined(FEATURE_WLAN_LFR)
static void cbNotifySetRoamPrefer5GHz(hdd_context_t *pHddCtx, unsigned long NotifyId)
{
    sme_UpdateRoamPrefer5GHz((tHalHandle)(pHddCtx->hHal), pHddCtx->cfg_ini->nRoamPrefer5GHz);
}

static void cbNotifySetImmediateRoamRssiDiff(hdd_context_t *pHddCtx, unsigned long NotifyId)
{
    sme_UpdateImmediateRoamRssiDiff((tHalHandle)(pHddCtx->hHal),
                                    pHddCtx->cfg_ini->nImmediateRoamRssiDiff);
}

static void cbNotifySetRoamRssiDiff(hdd_context_t *pHddCtx, unsigned long NotifyId)
{
    sme_UpdateRoamRssiDiff((tHalHandle)(pHddCtx->hHal),
                                    pHddCtx->cfg_ini->RoamRssiDiff);
}

static void cbNotifySetFastTransitionEnabled(hdd_context_t *pHddCtx, unsigned long NotifyId)
{
    sme_UpdateFastTransitionEnabled((tHalHandle)(pHddCtx->hHal), pHddCtx->cfg_ini->isFastTransitionEnabled);
}

static void cbNotifySetRoamIntraBand(hdd_context_t *pHddCtx, unsigned long NotifyId)
{
    sme_setRoamIntraBand((tHalHandle)(pHddCtx->hHal), pHddCtx->cfg_ini->nRoamIntraBand);
}

static void cbNotifySetRoamScanNProbes(hdd_context_t *pHddCtx, unsigned long NotifyId)
{
    sme_UpdateRoamScanNProbes((tHalHandle)(pHddCtx->hHal), pHddCtx->cfg_ini->nProbes);
}

static void cbNotifySetRoamScanHomeAwayTime(hdd_context_t *pHddCtx, unsigned long NotifyId)
{
    tANI_U16 scanChannelMaxTime = 0;

    /* Home Away Time should be atleast equal to (MaxDwell time + (2*RFS)),
     * where RFS is the RF Switching time. It is twice RFS to consider the
     * time to go off channel and return to the home channel. */

     scanChannelMaxTime = sme_getNeighborScanMaxChanTime((tHalHandle)(pHddCtx->hHal));
     if (pHddCtx->cfg_ini->nRoamScanHomeAwayTime < (scanChannelMaxTime + (2 * HDD_ROAM_SCAN_CHANNEL_SWITCH_TIME)))
     {
         VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_WARN,
                "%s: Invalid config, Home away time(%d) is less than (twice RF switching time + channel max time)(%d)",
                " Hence enforcing home away time to disable (0)",
                __func__, pHddCtx->cfg_ini->nRoamScanHomeAwayTime, (scanChannelMaxTime + (2 * HDD_ROAM_SCAN_CHANNEL_SWITCH_TIME)));
         pHddCtx->cfg_ini->nRoamScanHomeAwayTime = 0;
     }

     sme_UpdateRoamScanHomeAwayTime((tHalHandle)(pHddCtx->hHal), pHddCtx->cfg_ini->nRoamScanHomeAwayTime, eANI_BOOLEAN_TRUE);
}
#endif

#ifdef FEATURE_WLAN_OKC
static void cbNotifySetOkcFeatureEnabled(hdd_context_t *pHddCtx, unsigned long NotifyId)
{
    // at the point this routine is called, the value in the cfg_ini table has already been updated
}
#endif

#ifdef FEATURE_WLAN_LFR
static void NotifyIsFastRoamIniFeatureEnabled(hdd_context_t *pHddCtx, unsigned long NotifyId)
{
    // at the point this routine is called, the value in the cfg_ini table has already been updated
    sme_UpdateIsFastRoamIniFeatureEnabled((tHalHandle)(pHddCtx->hHal), pHddCtx->cfg_ini->isFastRoamIniFeatureEnabled );
}
#endif

#ifdef FEATURE_WLAN_CCX
static void cbNotifySetCcxFeatureEnabled(hdd_context_t *pHddCtx, unsigned long NotifyId)
{
    // at the point this routine is called, the value in the cfg_ini table has already been updated
    sme_UpdateIsCcxFeatureEnabled((tHalHandle)(pHddCtx->hHal), pHddCtx->cfg_ini->isCcxIniFeatureEnabled );
}
#endif

static void cbNotifySetFwRssiMonitoring(hdd_context_t *pHddCtx, unsigned long NotifyId)
{
    // at the point this routine is called, the value in the cfg_ini table has already been updated
    sme_UpdateConfigFwRssiMonitoring((tHalHandle)(pHddCtx->hHal), pHddCtx->cfg_ini->fEnableFwRssiMonitoring );
}

#ifdef WLAN_FEATURE_NEIGHBOR_ROAMING
static void cbNotifySetNeighborLookupRssiThreshold(hdd_context_t *pHddCtx, unsigned long NotifyId)
{
    // at the point this routine is called, the value in the cfg_ini table has already been updated
    sme_setNeighborLookupRssiThreshold((tHalHandle)(pHddCtx->hHal), pHddCtx->cfg_ini->nNeighborLookupRssiThreshold );
}

static void cbNotifySetNeighborScanPeriod(hdd_context_t *pHddCtx, unsigned long NotifyId)
{
    // at the point this routine is called, the value in the cfg_ini table has already been updated
    sme_setNeighborScanPeriod((tHalHandle)(pHddCtx->hHal), pHddCtx->cfg_ini->nNeighborScanPeriod );
}

static void cbNotifySetNeighborResultsRefreshPeriod(hdd_context_t *pHddCtx, unsigned long NotifyId)
{
    // at the point this routine is called, the value in the cfg_ini table has already been updated
    sme_setNeighborScanRefreshPeriod((tHalHandle)(pHddCtx->hHal), pHddCtx->cfg_ini->nNeighborResultsRefreshPeriod );
}

static void cbNotifySetEmptyScanRefreshPeriod(hdd_context_t *pHddCtx, unsigned long NotifyId)
{
    // at the point this routine is called, the value in the cfg_ini table has already been updated
    sme_UpdateEmptyScanRefreshPeriod((tHalHandle)(pHddCtx->hHal), pHddCtx->cfg_ini->nEmptyScanRefreshPeriod);
}

static void cbNotifySetNeighborScanMinChanTime(hdd_context_t *pHddCtx, unsigned long NotifyId)
{
    // at the point this routine is called, the value in the cfg_ini table has already been updated
    sme_setNeighborScanMinChanTime((tHalHandle)(pHddCtx->hHal), pHddCtx->cfg_ini->nNeighborScanMinChanTime);
}

static void cbNotifySetNeighborScanMaxChanTime(hdd_context_t *pHddCtx, unsigned long NotifyId)
{
    tANI_U16 homeAwayTime = 0;

    /* Home Away Time should be atleast equal to (MaxDwell time + (2*RFS)),
    *  where RFS is the RF Switching time. It is twice RFS to consider the
    *  time to go off channel and return to the home channel. */
    homeAwayTime = sme_getRoamScanHomeAwayTime((tHalHandle)(pHddCtx->hHal));
    if (homeAwayTime < (pHddCtx->cfg_ini->nNeighborScanMaxChanTime + (2 * HDD_ROAM_SCAN_CHANNEL_SWITCH_TIME)))
    {
        VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_WARN,
               "%s: Invalid config, Home away time(%d) is less than (twice RF switching time + channel max time)(%d)",
               " Hence enforcing home away time to disable (0)",
               __func__, homeAwayTime, (pHddCtx->cfg_ini->nNeighborScanMaxChanTime + (2 * HDD_ROAM_SCAN_CHANNEL_SWITCH_TIME)));
        homeAwayTime = 0;
        pHddCtx->cfg_ini->nRoamScanHomeAwayTime = homeAwayTime;
        sme_UpdateRoamScanHomeAwayTime((tHalHandle)(pHddCtx->hHal), homeAwayTime, eANI_BOOLEAN_FALSE);
    }
    sme_setNeighborScanMaxChanTime((tHalHandle)(pHddCtx->hHal), pHddCtx->cfg_ini->nNeighborScanMaxChanTime);
}
#endif

static void cbNotifySetEnableSSR(hdd_context_t *pHddCtx, unsigned long NotifyId)
{
    sme_UpdateEnableSSR((tHalHandle)(pHddCtx->hHal), pHddCtx->cfg_ini->enableSSR);
}

#ifdef WLAN_FEATURE_ROAM_SCAN_OFFLOAD
static void cbNotifyUpdateRoamScanOffloadEnabled(hdd_context_t *pHddCtx, unsigned long NotifyId)
{
    sme_UpdateRoamScanOffloadEnabled((tHalHandle)(pHddCtx->hHal), pHddCtx->cfg_ini->isRoamOffloadScanEnabled);
    if (0 == pHddCtx->cfg_ini->isRoamOffloadScanEnabled)
    {
        pHddCtx->cfg_ini->bFastRoamInConIniFeatureEnabled = 0;
        sme_UpdateEnableFastRoamInConcurrency((tHalHandle)(pHddCtx->hHal), pHddCtx->cfg_ini->bFastRoamInConIniFeatureEnabled );
    }
}

static void cbNotifySetEnableFastRoamInConcurrency(hdd_context_t *pHddCtx, unsigned long NotifyId)
{
    sme_UpdateEnableFastRoamInConcurrency((tHalHandle)(pHddCtx->hHal), pHddCtx->cfg_ini->bFastRoamInConIniFeatureEnabled );
}

#endif
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update

REG_TABLE_ENTRY g_registry_table[] =
{
   REG_VARIABLE( CFG_RTS_THRESHOLD_NAME, WLAN_PARAM_Integer,
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
                 hdd_config_t, RTSThreshold, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_RTS_THRESHOLD_DEFAULT, 
                 CFG_RTS_THRESHOLD_MIN, 
                 CFG_RTS_THRESHOLD_MAX ), 
<<<<<<< HEAD

   REG_VARIABLE( CFG_FRAG_THRESHOLD_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, FragmentationThreshold, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_FRAG_THRESHOLD_DEFAULT, 
                 CFG_FRAG_THRESHOLD_MIN, 
                 CFG_FRAG_THRESHOLD_MAX ),              

   REG_VARIABLE( CFG_CALIBRATION_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, Calibration, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_CALIBRATION_DEFAULT, 
                 CFG_CALIBRATION_MIN, 
                 CFG_CALIBRATION_MAX ),
                
   REG_VARIABLE( CFG_CALIBRATION_PERIOD_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, CalibrationPeriod, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_CALIBRATION_PERIOD_DEFAULT, 
                 CFG_CALIBRATION_PERIOD_MIN, 
                 CFG_CALIBRATION_PERIOD_MAX ), 

   REG_VARIABLE( CFG_OPERATING_CHANNEL_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, OperatingChannel,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_OPERATING_CHANNEL_DEFAULT, 
                 CFG_OPERATING_CHANNEL_MIN, 
                 CFG_OPERATING_CHANNEL_MAX ),

   REG_VARIABLE( CFG_SHORT_SLOT_TIME_ENABLED_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, ShortSlotTimeEnabled, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK, 
                 CFG_SHORT_SLOT_TIME_ENABLED_DEFAULT, 
                 CFG_SHORT_SLOT_TIME_ENABLED_MIN, 
                 CFG_SHORT_SLOT_TIME_ENABLED_MAX ),

   REG_VARIABLE( CFG_11D_SUPPORT_ENABLED_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, Is11dSupportEnabled, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK, 
                 CFG_11D_SUPPORT_ENABLED_DEFAULT, 
                 CFG_11D_SUPPORT_ENABLED_MIN, 
                 CFG_11D_SUPPORT_ENABLED_MAX ),

   REG_VARIABLE( CFG_ENFORCE_11D_CHANNELS_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, fEnforce11dChannels, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK, 
                 CFG_ENFORCE_11D_CHANNELS_DEFAULT, 
                 CFG_ENFORCE_11D_CHANNELS_MIN, 
                 CFG_ENFORCE_11D_CHANNELS_MAX ),

   REG_VARIABLE( CFG_COUNTRY_CODE_PRIORITY_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, fSupplicantCountryCodeHasPriority, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK, 
                 CFG_COUNTRY_CODE_PRIORITY_DEFAULT, 
                 CFG_COUNTRY_CODE_PRIORITY_MIN, 
                 CFG_COUNTRY_CODE_PRIORITY_MAX),

   REG_VARIABLE( CFG_ENFORCE_COUNTRY_CODE_MATCH_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, fEnforceCountryCodeMatch, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK, 
                 CFG_ENFORCE_COUNTRY_CODE_MATCH_DEFAULT, 
                 CFG_ENFORCE_COUNTRY_CODE_MATCH_MIN, 
                 CFG_ENFORCE_COUNTRY_CODE_MATCH_MAX ),

   REG_VARIABLE( CFG_ENFORCE_DEFAULT_DOMAIN_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, fEnforceDefaultDomain, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK, 
                 CFG_ENFORCE_DEFAULT_DOMAIN_DEFAULT, 
                 CFG_ENFORCE_DEFAULT_DOMAIN_MIN, 
                 CFG_ENFORCE_DEFAULT_DOMAIN_MAX ),
                
   REG_VARIABLE( CFG_GENERIC_ID1_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, Cfg1Id,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_GENERIC_ID1_DEFAULT, 
                 CFG_GENERIC_ID1_MIN, 
                 CFG_GENERIC_ID1_MAX ),
                
   REG_VARIABLE( CFG_GENERIC_ID2_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, Cfg2Id,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_GENERIC_ID2_DEFAULT, 
                 CFG_GENERIC_ID2_MIN, 
                 CFG_GENERIC_ID2_MAX ),
                
   REG_VARIABLE( CFG_GENERIC_ID3_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, Cfg3Id,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_GENERIC_ID3_DEFAULT, 
                 CFG_GENERIC_ID3_MIN, 
                 CFG_GENERIC_ID3_MAX ),
                
   REG_VARIABLE( CFG_GENERIC_ID4_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, Cfg4Id,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_GENERIC_ID4_DEFAULT, 
                 CFG_GENERIC_ID4_MIN, 
                 CFG_GENERIC_ID4_MAX ),
                
   REG_VARIABLE( CFG_GENERIC_ID5_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, Cfg5Id,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_GENERIC_ID5_DEFAULT, 
                 CFG_GENERIC_ID5_MIN, 
=======
                 hdd_config_t, RTSThreshold,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_RTS_THRESHOLD_DEFAULT,
                 CFG_RTS_THRESHOLD_MIN,
                 CFG_RTS_THRESHOLD_MAX ),
=======
>>>>>>> 657b0e9... prima update

   REG_VARIABLE( CFG_FRAG_THRESHOLD_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, FragmentationThreshold, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_FRAG_THRESHOLD_DEFAULT, 
                 CFG_FRAG_THRESHOLD_MIN, 
                 CFG_FRAG_THRESHOLD_MAX ),              

   REG_VARIABLE( CFG_CALIBRATION_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, Calibration, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_CALIBRATION_DEFAULT, 
                 CFG_CALIBRATION_MIN, 
                 CFG_CALIBRATION_MAX ),
                
   REG_VARIABLE( CFG_CALIBRATION_PERIOD_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, CalibrationPeriod, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_CALIBRATION_PERIOD_DEFAULT, 
                 CFG_CALIBRATION_PERIOD_MIN, 
                 CFG_CALIBRATION_PERIOD_MAX ), 

   REG_VARIABLE( CFG_OPERATING_CHANNEL_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, OperatingChannel,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_OPERATING_CHANNEL_DEFAULT, 
                 CFG_OPERATING_CHANNEL_MIN, 
                 CFG_OPERATING_CHANNEL_MAX ),

   REG_VARIABLE( CFG_SHORT_SLOT_TIME_ENABLED_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, ShortSlotTimeEnabled, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK, 
                 CFG_SHORT_SLOT_TIME_ENABLED_DEFAULT, 
                 CFG_SHORT_SLOT_TIME_ENABLED_MIN, 
                 CFG_SHORT_SLOT_TIME_ENABLED_MAX ),

   REG_VARIABLE( CFG_11D_SUPPORT_ENABLED_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, Is11dSupportEnabled, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK, 
                 CFG_11D_SUPPORT_ENABLED_DEFAULT, 
                 CFG_11D_SUPPORT_ENABLED_MIN, 
                 CFG_11D_SUPPORT_ENABLED_MAX ),

   REG_VARIABLE( CFG_ENFORCE_11D_CHANNELS_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, fEnforce11dChannels, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK, 
                 CFG_ENFORCE_11D_CHANNELS_DEFAULT, 
                 CFG_ENFORCE_11D_CHANNELS_MIN, 
                 CFG_ENFORCE_11D_CHANNELS_MAX ),

   REG_VARIABLE( CFG_COUNTRY_CODE_PRIORITY_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, fSupplicantCountryCodeHasPriority, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK, 
                 CFG_COUNTRY_CODE_PRIORITY_DEFAULT, 
                 CFG_COUNTRY_CODE_PRIORITY_MIN, 
                 CFG_COUNTRY_CODE_PRIORITY_MAX),

   REG_VARIABLE( CFG_ENFORCE_COUNTRY_CODE_MATCH_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, fEnforceCountryCodeMatch, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK, 
                 CFG_ENFORCE_COUNTRY_CODE_MATCH_DEFAULT, 
                 CFG_ENFORCE_COUNTRY_CODE_MATCH_MIN, 
                 CFG_ENFORCE_COUNTRY_CODE_MATCH_MAX ),

   REG_VARIABLE( CFG_ENFORCE_DEFAULT_DOMAIN_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, fEnforceDefaultDomain, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK, 
                 CFG_ENFORCE_DEFAULT_DOMAIN_DEFAULT, 
                 CFG_ENFORCE_DEFAULT_DOMAIN_MIN, 
                 CFG_ENFORCE_DEFAULT_DOMAIN_MAX ),
                
   REG_VARIABLE( CFG_GENERIC_ID1_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, Cfg1Id,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_GENERIC_ID1_DEFAULT, 
                 CFG_GENERIC_ID1_MIN, 
                 CFG_GENERIC_ID1_MAX ),
                
   REG_VARIABLE( CFG_GENERIC_ID2_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, Cfg2Id,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_GENERIC_ID2_DEFAULT, 
                 CFG_GENERIC_ID2_MIN, 
                 CFG_GENERIC_ID2_MAX ),
                
   REG_VARIABLE( CFG_GENERIC_ID3_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, Cfg3Id,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_GENERIC_ID3_DEFAULT, 
                 CFG_GENERIC_ID3_MIN, 
                 CFG_GENERIC_ID3_MAX ),
                
   REG_VARIABLE( CFG_GENERIC_ID4_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, Cfg4Id,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_GENERIC_ID4_DEFAULT, 
                 CFG_GENERIC_ID4_MIN, 
                 CFG_GENERIC_ID4_MAX ),
                
   REG_VARIABLE( CFG_GENERIC_ID5_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, Cfg5Id,
<<<<<<< HEAD
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_GENERIC_ID5_DEFAULT,
                 CFG_GENERIC_ID5_MIN,
>>>>>>> d97af3b... add prima wlan driver
=======
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_GENERIC_ID5_DEFAULT, 
                 CFG_GENERIC_ID5_MIN, 
>>>>>>> 657b0e9... prima update
                 CFG_GENERIC_ID5_MAX ),

   REG_VARIABLE( CFG_GENERIC_VALUE1_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, Cfg1Value,
<<<<<<< HEAD
<<<<<<< HEAD
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_GENERIC_VALUE1_DEFAULT, 
                 CFG_GENERIC_VALUE1_MIN, 
                 CFG_GENERIC_VALUE1_MAX ),
                
   REG_VARIABLE( CFG_GENERIC_VALUE2_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, Cfg2Value,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_GENERIC_VALUE2_DEFAULT, 
                 CFG_GENERIC_VALUE2_MIN, 
                 CFG_GENERIC_VALUE2_MAX ),
                
   REG_VARIABLE( CFG_GENERIC_VALUE3_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, Cfg3Value,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_GENERIC_VALUE3_DEFAULT, 
                 CFG_GENERIC_VALUE3_MIN, 
                 CFG_GENERIC_VALUE3_MAX ),
                
   REG_VARIABLE( CFG_GENERIC_VALUE4_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, Cfg4Value,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_GENERIC_VALUE4_DEFAULT, 
                 CFG_GENERIC_VALUE4_MIN, 
                 CFG_GENERIC_VALUE4_MAX ),
                
   REG_VARIABLE( CFG_GENERIC_VALUE5_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, Cfg5Value,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_GENERIC_VALUE5_DEFAULT, 
                 CFG_GENERIC_VALUE5_MIN, 
                 CFG_GENERIC_VALUE5_MAX ),

   REG_VARIABLE( CFG_HEARTBEAT_THRESH_24_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, HeartbeatThresh24, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_HEARTBEAT_THRESH_24_DEFAULT, 
                 CFG_HEARTBEAT_THRESH_24_MIN, 
                 CFG_HEARTBEAT_THRESH_24_MAX ),
                
   REG_VARIABLE_STRING( CFG_POWER_USAGE_NAME, WLAN_PARAM_String,
                        hdd_config_t, PowerUsageControl, 
=======
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_GENERIC_VALUE1_DEFAULT,
                 CFG_GENERIC_VALUE1_MIN,
=======
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_GENERIC_VALUE1_DEFAULT, 
                 CFG_GENERIC_VALUE1_MIN, 
>>>>>>> 657b0e9... prima update
                 CFG_GENERIC_VALUE1_MAX ),
                
   REG_VARIABLE( CFG_GENERIC_VALUE2_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, Cfg2Value,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_GENERIC_VALUE2_DEFAULT, 
                 CFG_GENERIC_VALUE2_MIN, 
                 CFG_GENERIC_VALUE2_MAX ),
                
   REG_VARIABLE( CFG_GENERIC_VALUE3_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, Cfg3Value,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_GENERIC_VALUE3_DEFAULT, 
                 CFG_GENERIC_VALUE3_MIN, 
                 CFG_GENERIC_VALUE3_MAX ),
                
   REG_VARIABLE( CFG_GENERIC_VALUE4_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, Cfg4Value,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_GENERIC_VALUE4_DEFAULT, 
                 CFG_GENERIC_VALUE4_MIN, 
                 CFG_GENERIC_VALUE4_MAX ),
                
   REG_VARIABLE( CFG_GENERIC_VALUE5_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, Cfg5Value,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_GENERIC_VALUE5_DEFAULT, 
                 CFG_GENERIC_VALUE5_MIN, 
                 CFG_GENERIC_VALUE5_MAX ),

   REG_VARIABLE( CFG_HEARTBEAT_THRESH_24_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, HeartbeatThresh24, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_HEARTBEAT_THRESH_24_DEFAULT, 
                 CFG_HEARTBEAT_THRESH_24_MIN, 
                 CFG_HEARTBEAT_THRESH_24_MAX ),
                
   REG_VARIABLE_STRING( CFG_POWER_USAGE_NAME, WLAN_PARAM_String,
<<<<<<< HEAD
                        hdd_config_t, PowerUsageControl,
>>>>>>> d97af3b... add prima wlan driver
=======
                        hdd_config_t, PowerUsageControl, 
>>>>>>> 657b0e9... prima update
                        VAR_FLAGS_OPTIONAL,
                        (void *)CFG_POWER_USAGE_DEFAULT ),

   REG_VARIABLE( CFG_ENABLE_SUSPEND_NAME, WLAN_PARAM_Integer,
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
                 hdd_config_t, nEnableSuspend, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_ENABLE_SUSPEND_DEFAULT, 
                 CFG_ENABLE_SUSPEND_MIN, 
<<<<<<< HEAD
                 CFG_ENABLE_SUSPEND_MAX ),

   REG_VARIABLE( CFG_ENABLE_ENABLE_DRIVER_STOP_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, nEnableDriverStop, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_ENABLE_ENABLE_DRIVER_STOP_DEFAULT, 
                 CFG_ENABLE_ENABLE_DRIVER_STOP_MIN, 
                 CFG_ENABLE_ENABLE_DRIVER_STOP_MAX ),

   REG_VARIABLE( CFG_ENABLE_IMPS_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, fIsImpsEnabled, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_ENABLE_IMPS_DEFAULT, 
                 CFG_ENABLE_IMPS_MIN, 
                 CFG_ENABLE_IMPS_MAX ),

   REG_VARIABLE( CFG_ENABLE_LOGP_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, fIsLogpEnabled, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_ENABLE_LOGP_DEFAULT, 
                 CFG_ENABLE_LOGP_MIN, 
                 CFG_ENABLE_LOGP_MAX ),

   REG_VARIABLE( CFG_IMPS_MINIMUM_SLEEP_TIME_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, nImpsMinSleepTime, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_IMPS_MINIMUM_SLEEP_TIME_DEFAULT, 
                 CFG_IMPS_MINIMUM_SLEEP_TIME_MIN, 
                 CFG_IMPS_MINIMUM_SLEEP_TIME_MAX ),

   REG_VARIABLE( CFG_IMPS_MAXIMUM_SLEEP_TIME_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, nImpsMaxSleepTime, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_IMPS_MAXIMUM_SLEEP_TIME_DEFAULT, 
                 CFG_IMPS_MAXIMUM_SLEEP_TIME_MIN, 
=======
                 hdd_config_t, nEnableSuspend,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_ENABLE_SUSPEND_DEFAULT,
                 CFG_ENABLE_SUSPEND_MIN,
=======
>>>>>>> 657b0e9... prima update
                 CFG_ENABLE_SUSPEND_MAX ),

   REG_VARIABLE( CFG_ENABLE_ENABLE_DRIVER_STOP_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, nEnableDriverStop, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_ENABLE_ENABLE_DRIVER_STOP_DEFAULT, 
                 CFG_ENABLE_ENABLE_DRIVER_STOP_MIN, 
                 CFG_ENABLE_ENABLE_DRIVER_STOP_MAX ),

   REG_VARIABLE( CFG_ENABLE_IMPS_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, fIsImpsEnabled, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_ENABLE_IMPS_DEFAULT, 
                 CFG_ENABLE_IMPS_MIN, 
                 CFG_ENABLE_IMPS_MAX ),

   REG_VARIABLE( CFG_ENABLE_LOGP_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, fIsLogpEnabled, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_ENABLE_LOGP_DEFAULT, 
                 CFG_ENABLE_LOGP_MIN, 
                 CFG_ENABLE_LOGP_MAX ),

   REG_VARIABLE( CFG_IMPS_MINIMUM_SLEEP_TIME_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, nImpsMinSleepTime, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_IMPS_MINIMUM_SLEEP_TIME_DEFAULT, 
                 CFG_IMPS_MINIMUM_SLEEP_TIME_MIN, 
                 CFG_IMPS_MINIMUM_SLEEP_TIME_MAX ),

   REG_VARIABLE( CFG_IMPS_MAXIMUM_SLEEP_TIME_NAME, WLAN_PARAM_Integer,
<<<<<<< HEAD
                 hdd_config_t, nImpsMaxSleepTime,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_IMPS_MAXIMUM_SLEEP_TIME_DEFAULT,
                 CFG_IMPS_MAXIMUM_SLEEP_TIME_MIN,
>>>>>>> d97af3b... add prima wlan driver
=======
                 hdd_config_t, nImpsMaxSleepTime, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_IMPS_MAXIMUM_SLEEP_TIME_DEFAULT, 
                 CFG_IMPS_MAXIMUM_SLEEP_TIME_MIN, 
>>>>>>> 657b0e9... prima update
                 CFG_IMPS_MAXIMUM_SLEEP_TIME_MAX ),

   REG_VARIABLE( CFG_IMPS_MODERATE_SLEEP_TIME_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, nImpsModSleepTime,
<<<<<<< HEAD
<<<<<<< HEAD
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_IMPS_MODERATE_SLEEP_TIME_DEFAULT, 
                 CFG_IMPS_MODERATE_SLEEP_TIME_MIN, 
                 CFG_IMPS_MODERATE_SLEEP_TIME_MAX ),

   REG_VARIABLE( CFG_ENABLE_BMPS_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, fIsBmpsEnabled, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_ENABLE_BMPS_DEFAULT, 
                 CFG_ENABLE_BMPS_MIN, 
                 CFG_ENABLE_BMPS_MAX ),

   REG_VARIABLE( CFG_BMPS_MINIMUM_LI_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, nBmpsMinListenInterval, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_BMPS_MINIMUM_LI_DEFAULT, 
                 CFG_BMPS_MINIMUM_LI_MIN, 
                 CFG_BMPS_MINIMUM_LI_MAX ),

   REG_VARIABLE( CFG_BMPS_MAXIMUM_LI_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, nBmpsMaxListenInterval, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_BMPS_MAXIMUM_LI_DEFAULT, 
                 CFG_BMPS_MAXIMUM_LI_MIN, 
=======
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_IMPS_MODERATE_SLEEP_TIME_DEFAULT,
                 CFG_IMPS_MODERATE_SLEEP_TIME_MIN,
=======
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_IMPS_MODERATE_SLEEP_TIME_DEFAULT, 
                 CFG_IMPS_MODERATE_SLEEP_TIME_MIN, 
>>>>>>> 657b0e9... prima update
                 CFG_IMPS_MODERATE_SLEEP_TIME_MAX ),

   REG_VARIABLE( CFG_ENABLE_BMPS_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, fIsBmpsEnabled, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_ENABLE_BMPS_DEFAULT, 
                 CFG_ENABLE_BMPS_MIN, 
                 CFG_ENABLE_BMPS_MAX ),

   REG_VARIABLE( CFG_BMPS_MINIMUM_LI_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, nBmpsMinListenInterval, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_BMPS_MINIMUM_LI_DEFAULT, 
                 CFG_BMPS_MINIMUM_LI_MIN, 
                 CFG_BMPS_MINIMUM_LI_MAX ),

   REG_VARIABLE( CFG_BMPS_MAXIMUM_LI_NAME, WLAN_PARAM_Integer,
<<<<<<< HEAD
                 hdd_config_t, nBmpsMaxListenInterval,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_BMPS_MAXIMUM_LI_DEFAULT,
                 CFG_BMPS_MAXIMUM_LI_MIN,
>>>>>>> d97af3b... add prima wlan driver
=======
                 hdd_config_t, nBmpsMaxListenInterval, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_BMPS_MAXIMUM_LI_DEFAULT, 
                 CFG_BMPS_MAXIMUM_LI_MIN, 
>>>>>>> 657b0e9... prima update
                 CFG_BMPS_MAXIMUM_LI_MAX ),

   REG_VARIABLE( CFG_BMPS_MODERATE_LI_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, nBmpsModListenInterval,
<<<<<<< HEAD
<<<<<<< HEAD
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_BMPS_MODERATE_LI_DEFAULT, 
                 CFG_BMPS_MODERATE_LI_MIN, 
                 CFG_BMPS_MODERATE_LI_MAX ),

   REG_VARIABLE( CFG_ENABLE_AUTO_BMPS_TIMER_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, fIsAutoBmpsTimerEnabled, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_ENABLE_AUTO_BMPS_TIMER_DEFAULT, 
                 CFG_ENABLE_AUTO_BMPS_TIMER_MIN, 
                 CFG_ENABLE_AUTO_BMPS_TIMER_MAX ),

   REG_VARIABLE( CFG_AUTO_BMPS_TIMER_VALUE_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, nAutoBmpsTimerValue, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_AUTO_BMPS_TIMER_VALUE_DEFAULT, 
                 CFG_AUTO_BMPS_TIMER_VALUE_MIN, 
                 CFG_AUTO_BMPS_TIMER_VALUE_MAX ),

   REG_VARIABLE( CFG_DOT11_MODE_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, dot11Mode, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK, 
                 CFG_DOT11_MODE_DEFAULT, 
                 CFG_DOT11_MODE_MIN, 
                 CFG_DOT11_MODE_MAX ),
                 
   REG_VARIABLE( CFG_CHANNEL_BONDING_MODE_24GHZ_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, nChannelBondingMode24GHz, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK, 
                 CFG_CHANNEL_BONDING_MODE_DEFAULT, 
                 CFG_CHANNEL_BONDING_MODE_MIN, 
                 CFG_CHANNEL_BONDING_MODE_MAX),
              
   REG_VARIABLE( CFG_CHANNEL_BONDING_MODE_5GHZ_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, nChannelBondingMode5GHz, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK, 
                 CFG_CHANNEL_BONDING_MODE_DEFAULT, 
                 CFG_CHANNEL_BONDING_MODE_MIN, 
                 CFG_CHANNEL_BONDING_MODE_MAX),
              
   REG_VARIABLE( CFG_MAX_RX_AMPDU_FACTOR_NAME, WLAN_PARAM_Integer,   
                 hdd_config_t, MaxRxAmpduFactor, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK , 
                 CFG_MAX_RX_AMPDU_FACTOR_DEFAULT, 
                 CFG_MAX_RX_AMPDU_FACTOR_MIN, 
                 CFG_MAX_RX_AMPDU_FACTOR_MAX),
                
   REG_VARIABLE( CFG_FIXED_RATE_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, TxRate, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK, 
                 CFG_FIXED_RATE_DEFAULT, 
                 CFG_FIXED_RATE_MIN, 
                 CFG_FIXED_RATE_MAX ),

   REG_VARIABLE( CFG_SHORT_GI_20MHZ_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, ShortGI20MhzEnable, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_SHORT_GI_20MHZ_DEFAULT, 
                 CFG_SHORT_GI_20MHZ_MIN, 
                 CFG_SHORT_GI_20MHZ_MAX ),

   REG_VARIABLE( CFG_BLOCK_ACK_AUTO_SETUP_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, BlockAckAutoSetup, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK, 
                 CFG_BLOCK_ACK_AUTO_SETUP_DEFAULT, 
                 CFG_BLOCK_ACK_AUTO_SETUP_MIN, 
                 CFG_BLOCK_ACK_AUTO_SETUP_MAX ),
  
   REG_VARIABLE( CFG_SCAN_RESULT_AGE_COUNT_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, ScanResultAgeCount, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK, 
                 CFG_SCAN_RESULT_AGE_COUNT_DEFAULT, 
                 CFG_SCAN_RESULT_AGE_COUNT_MIN, 
                 CFG_SCAN_RESULT_AGE_COUNT_MAX ),

   REG_VARIABLE( CFG_SCAN_RESULT_AGE_TIME_NCNPS_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, nScanAgeTimeNCNPS, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK, 
                 CFG_SCAN_RESULT_AGE_TIME_NCNPS_DEFAULT, 
                 CFG_SCAN_RESULT_AGE_TIME_NCNPS_MIN, 
                 CFG_SCAN_RESULT_AGE_TIME_NCNPS_MAX ),

   REG_VARIABLE( CFG_SCAN_RESULT_AGE_TIME_NCPS_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, nScanAgeTimeNCPS, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK, 
                 CFG_SCAN_RESULT_AGE_TIME_NCPS_DEFAULT, 
                 CFG_SCAN_RESULT_AGE_TIME_NCPS_MIN, 
                 CFG_SCAN_RESULT_AGE_TIME_NCPS_MAX ),

   REG_VARIABLE( CFG_SCAN_RESULT_AGE_TIME_CNPS_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, nScanAgeTimeCNPS, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK, 
                 CFG_SCAN_RESULT_AGE_TIME_CNPS_DEFAULT, 
                 CFG_SCAN_RESULT_AGE_TIME_CNPS_MIN, 
                 CFG_SCAN_RESULT_AGE_TIME_CNPS_MAX ),

   REG_VARIABLE( CFG_SCAN_RESULT_AGE_TIME_CPS_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, nScanAgeTimeCPS, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK, 
                 CFG_SCAN_RESULT_AGE_TIME_CPS_DEFAULT, 
                 CFG_SCAN_RESULT_AGE_TIME_CPS_MIN, 
                 CFG_SCAN_RESULT_AGE_TIME_CPS_MAX ),

   REG_VARIABLE( CFG_RSSI_CATEGORY_GAP_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, nRssiCatGap, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_RSSI_CATEGORY_GAP_DEFAULT, 
                 CFG_RSSI_CATEGORY_GAP_MIN, 
                 CFG_RSSI_CATEGORY_GAP_MAX ),  

   REG_VARIABLE( CFG_STAT_TIMER_INTERVAL_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, nStatTimerInterval, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_STAT_TIMER_INTERVAL_DEFAULT, 
                 CFG_STAT_TIMER_INTERVAL_MIN, 
                 CFG_STAT_TIMER_INTERVAL_MAX ),

   REG_VARIABLE( CFG_SHORT_PREAMBLE_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, fIsShortPreamble, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_SHORT_PREAMBLE_DEFAULT, 
                 CFG_SHORT_PREAMBLE_MIN, 
                 CFG_SHORT_PREAMBLE_MAX ),

   REG_VARIABLE( CFG_IBSS_AUTO_BSSID_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, fIsAutoIbssBssid, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_IBSS_AUTO_BSSID_DEFAULT, 
                 CFG_IBSS_AUTO_BSSID_MIN, 
                 CFG_IBSS_AUTO_BSSID_MAX ),

   REG_VARIABLE_STRING( CFG_IBSS_BSSID_NAME, WLAN_PARAM_MacAddr,
                        hdd_config_t, IbssBssid, 
=======
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_BMPS_MODERATE_LI_DEFAULT,
                 CFG_BMPS_MODERATE_LI_MIN,
=======
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_BMPS_MODERATE_LI_DEFAULT, 
                 CFG_BMPS_MODERATE_LI_MIN, 
>>>>>>> 657b0e9... prima update
                 CFG_BMPS_MODERATE_LI_MAX ),

   REG_VARIABLE( CFG_ENABLE_AUTO_BMPS_TIMER_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, fIsAutoBmpsTimerEnabled, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_ENABLE_AUTO_BMPS_TIMER_DEFAULT, 
                 CFG_ENABLE_AUTO_BMPS_TIMER_MIN, 
                 CFG_ENABLE_AUTO_BMPS_TIMER_MAX ),

   REG_VARIABLE( CFG_AUTO_BMPS_TIMER_VALUE_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, nAutoBmpsTimerValue, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_AUTO_BMPS_TIMER_VALUE_DEFAULT, 
                 CFG_AUTO_BMPS_TIMER_VALUE_MIN, 
                 CFG_AUTO_BMPS_TIMER_VALUE_MAX ),

   REG_VARIABLE( CFG_DOT11_MODE_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, dot11Mode, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK, 
                 CFG_DOT11_MODE_DEFAULT, 
                 CFG_DOT11_MODE_MIN, 
                 CFG_DOT11_MODE_MAX ),
                 
   REG_VARIABLE( CFG_CHANNEL_BONDING_MODE_24GHZ_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, nChannelBondingMode24GHz, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK, 
                 CFG_CHANNEL_BONDING_MODE_DEFAULT, 
                 CFG_CHANNEL_BONDING_MODE_MIN, 
                 CFG_CHANNEL_BONDING_MODE_MAX),
              
   REG_VARIABLE( CFG_CHANNEL_BONDING_MODE_5GHZ_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, nChannelBondingMode5GHz, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK, 
                 CFG_CHANNEL_BONDING_MODE_DEFAULT, 
                 CFG_CHANNEL_BONDING_MODE_MIN, 
                 CFG_CHANNEL_BONDING_MODE_MAX),
              
   REG_VARIABLE( CFG_MAX_RX_AMPDU_FACTOR_NAME, WLAN_PARAM_Integer,   
                 hdd_config_t, MaxRxAmpduFactor, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK , 
                 CFG_MAX_RX_AMPDU_FACTOR_DEFAULT, 
                 CFG_MAX_RX_AMPDU_FACTOR_MIN, 
                 CFG_MAX_RX_AMPDU_FACTOR_MAX),
                
   REG_VARIABLE( CFG_FIXED_RATE_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, TxRate, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK, 
                 CFG_FIXED_RATE_DEFAULT, 
                 CFG_FIXED_RATE_MIN, 
                 CFG_FIXED_RATE_MAX ),

   REG_VARIABLE( CFG_SHORT_GI_20MHZ_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, ShortGI20MhzEnable, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_SHORT_GI_20MHZ_DEFAULT, 
                 CFG_SHORT_GI_20MHZ_MIN, 
                 CFG_SHORT_GI_20MHZ_MAX ),

   REG_VARIABLE( CFG_BLOCK_ACK_AUTO_SETUP_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, BlockAckAutoSetup, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK, 
                 CFG_BLOCK_ACK_AUTO_SETUP_DEFAULT, 
                 CFG_BLOCK_ACK_AUTO_SETUP_MIN, 
                 CFG_BLOCK_ACK_AUTO_SETUP_MAX ),
  
   REG_VARIABLE( CFG_SCAN_RESULT_AGE_COUNT_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, ScanResultAgeCount, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK, 
                 CFG_SCAN_RESULT_AGE_COUNT_DEFAULT, 
                 CFG_SCAN_RESULT_AGE_COUNT_MIN, 
                 CFG_SCAN_RESULT_AGE_COUNT_MAX ),

   REG_VARIABLE( CFG_SCAN_RESULT_AGE_TIME_NCNPS_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, nScanAgeTimeNCNPS, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK, 
                 CFG_SCAN_RESULT_AGE_TIME_NCNPS_DEFAULT, 
                 CFG_SCAN_RESULT_AGE_TIME_NCNPS_MIN, 
                 CFG_SCAN_RESULT_AGE_TIME_NCNPS_MAX ),

   REG_VARIABLE( CFG_SCAN_RESULT_AGE_TIME_NCPS_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, nScanAgeTimeNCPS, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK, 
                 CFG_SCAN_RESULT_AGE_TIME_NCPS_DEFAULT, 
                 CFG_SCAN_RESULT_AGE_TIME_NCPS_MIN, 
                 CFG_SCAN_RESULT_AGE_TIME_NCPS_MAX ),

   REG_VARIABLE( CFG_SCAN_RESULT_AGE_TIME_CNPS_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, nScanAgeTimeCNPS, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK, 
                 CFG_SCAN_RESULT_AGE_TIME_CNPS_DEFAULT, 
                 CFG_SCAN_RESULT_AGE_TIME_CNPS_MIN, 
                 CFG_SCAN_RESULT_AGE_TIME_CNPS_MAX ),

   REG_VARIABLE( CFG_SCAN_RESULT_AGE_TIME_CPS_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, nScanAgeTimeCPS, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK, 
                 CFG_SCAN_RESULT_AGE_TIME_CPS_DEFAULT, 
                 CFG_SCAN_RESULT_AGE_TIME_CPS_MIN, 
                 CFG_SCAN_RESULT_AGE_TIME_CPS_MAX ),

   REG_VARIABLE( CFG_RSSI_CATEGORY_GAP_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, nRssiCatGap, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_RSSI_CATEGORY_GAP_DEFAULT, 
                 CFG_RSSI_CATEGORY_GAP_MIN, 
                 CFG_RSSI_CATEGORY_GAP_MAX ),  

   REG_VARIABLE( CFG_STAT_TIMER_INTERVAL_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, nStatTimerInterval, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_STAT_TIMER_INTERVAL_DEFAULT, 
                 CFG_STAT_TIMER_INTERVAL_MIN, 
                 CFG_STAT_TIMER_INTERVAL_MAX ),

   REG_VARIABLE( CFG_SHORT_PREAMBLE_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, fIsShortPreamble, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_SHORT_PREAMBLE_DEFAULT, 
                 CFG_SHORT_PREAMBLE_MIN, 
                 CFG_SHORT_PREAMBLE_MAX ),

   REG_VARIABLE( CFG_IBSS_AUTO_BSSID_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, fIsAutoIbssBssid, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_IBSS_AUTO_BSSID_DEFAULT, 
                 CFG_IBSS_AUTO_BSSID_MIN, 
                 CFG_IBSS_AUTO_BSSID_MAX ),

   REG_VARIABLE_STRING( CFG_IBSS_BSSID_NAME, WLAN_PARAM_MacAddr,
<<<<<<< HEAD
                        hdd_config_t, IbssBssid,
>>>>>>> d97af3b... add prima wlan driver
=======
                        hdd_config_t, IbssBssid, 
>>>>>>> 657b0e9... prima update
                        VAR_FLAGS_OPTIONAL,
                        (void *)CFG_IBSS_BSSID_DEFAULT ),

   REG_VARIABLE_STRING( CFG_INTF0_MAC_ADDR_NAME, WLAN_PARAM_MacAddr,
<<<<<<< HEAD
<<<<<<< HEAD
                        hdd_config_t, intfMacAddr[0], 
=======
                        hdd_config_t, intfMacAddr[0],
>>>>>>> d97af3b... add prima wlan driver
=======
                        hdd_config_t, intfMacAddr[0], 
>>>>>>> 657b0e9... prima update
                        VAR_FLAGS_OPTIONAL,
                        (void *)CFG_INTF0_MAC_ADDR_DEFAULT ),

   REG_VARIABLE_STRING( CFG_INTF1_MAC_ADDR_NAME, WLAN_PARAM_MacAddr,
<<<<<<< HEAD
<<<<<<< HEAD
                        hdd_config_t, intfMacAddr[1], 
=======
                        hdd_config_t, intfMacAddr[1],
>>>>>>> d97af3b... add prima wlan driver
=======
                        hdd_config_t, intfMacAddr[1], 
>>>>>>> 657b0e9... prima update
                        VAR_FLAGS_OPTIONAL,
                        (void *)CFG_INTF1_MAC_ADDR_DEFAULT ),

   REG_VARIABLE_STRING( CFG_INTF2_MAC_ADDR_NAME, WLAN_PARAM_MacAddr,
<<<<<<< HEAD
<<<<<<< HEAD
                        hdd_config_t, intfMacAddr[2], 
=======
                        hdd_config_t, intfMacAddr[2],
>>>>>>> d97af3b... add prima wlan driver
=======
                        hdd_config_t, intfMacAddr[2], 
>>>>>>> 657b0e9... prima update
                        VAR_FLAGS_OPTIONAL,
                        (void *)CFG_INTF2_MAC_ADDR_DEFAULT ),

   REG_VARIABLE_STRING( CFG_INTF3_MAC_ADDR_NAME, WLAN_PARAM_MacAddr,
<<<<<<< HEAD
<<<<<<< HEAD
                        hdd_config_t, intfMacAddr[3], 
                        VAR_FLAGS_OPTIONAL,
                        (void *)CFG_INTF3_MAC_ADDR_DEFAULT ),

#ifdef WLAN_SOFTAP_FEATURE
   REG_VARIABLE( CFG_AP_QOS_UAPSD_MODE_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, apUapsdEnabled, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_AP_QOS_UAPSD_MODE_DEFAULT, 
                 CFG_AP_QOS_UAPSD_MODE_MIN, 
                 CFG_AP_QOS_UAPSD_MODE_MAX ),

   REG_VARIABLE_STRING( CFG_AP_COUNTRY_CODE, WLAN_PARAM_String,
                        hdd_config_t, apCntryCode, 
=======
                        hdd_config_t, intfMacAddr[3],
=======
                        hdd_config_t, intfMacAddr[3], 
>>>>>>> 657b0e9... prima update
                        VAR_FLAGS_OPTIONAL,
                        (void *)CFG_INTF3_MAC_ADDR_DEFAULT ),

#ifdef WLAN_SOFTAP_FEATURE
   REG_VARIABLE( CFG_AP_QOS_UAPSD_MODE_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, apUapsdEnabled, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_AP_QOS_UAPSD_MODE_DEFAULT, 
                 CFG_AP_QOS_UAPSD_MODE_MIN, 
                 CFG_AP_QOS_UAPSD_MODE_MAX ),

   REG_VARIABLE_STRING( CFG_AP_COUNTRY_CODE, WLAN_PARAM_String,
<<<<<<< HEAD
                        hdd_config_t, apCntryCode,
>>>>>>> d97af3b... add prima wlan driver
=======
                        hdd_config_t, apCntryCode, 
>>>>>>> 657b0e9... prima update
                        VAR_FLAGS_OPTIONAL,
                        (void *)CFG_AP_COUNTRY_CODE_DEFAULT ),

   REG_VARIABLE( CFG_AP_ENABLE_RANDOM_BSSID_NAME, WLAN_PARAM_Integer,
                        hdd_config_t, apRandomBssidEnabled,
                        VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                        CFG_AP_ENABLE_RANDOM_BSSID_DEFAULT,
                        CFG_AP_ENABLE_RANDOM_BSSID_MIN,
                        CFG_AP_ENABLE_RANDOM_BSSID_MAX ),

   REG_VARIABLE( CFG_AP_ENABLE_PROTECTION_MODE_NAME, WLAN_PARAM_Integer,
<<<<<<< HEAD
<<<<<<< HEAD
                        hdd_config_t, apProtEnabled, 
=======
                        hdd_config_t, apProtEnabled,
>>>>>>> d97af3b... add prima wlan driver
=======
                        hdd_config_t, apProtEnabled, 
>>>>>>> 657b0e9... prima update
                        VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                        CFG_AP_ENABLE_PROTECTION_MODE_DEFAULT,
                        CFG_AP_ENABLE_PROTECTION_MODE_MIN,
                        CFG_AP_ENABLE_PROTECTION_MODE_MAX ),

   REG_VARIABLE( CFG_AP_PROTECTION_MODE_NAME, WLAN_PARAM_HexInteger,
                        hdd_config_t, apProtection,
                        VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                        CFG_AP_PROTECTION_MODE_DEFAULT,
                        CFG_AP_PROTECTION_MODE_MIN,
                        CFG_AP_PROTECTION_MODE_MAX ),
<<<<<<< HEAD
<<<<<<< HEAD
                        
   REG_VARIABLE( CFG_AP_OBSS_PROTECTION_MODE_NAME, WLAN_PARAM_Integer,
                        hdd_config_t, apOBSSProtEnabled, 
=======

   REG_VARIABLE( CFG_AP_OBSS_PROTECTION_MODE_NAME, WLAN_PARAM_Integer,
                        hdd_config_t, apOBSSProtEnabled,
>>>>>>> d97af3b... add prima wlan driver
=======
                        
   REG_VARIABLE( CFG_AP_OBSS_PROTECTION_MODE_NAME, WLAN_PARAM_Integer,
                        hdd_config_t, apOBSSProtEnabled, 
>>>>>>> 657b0e9... prima update
                        VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                        CFG_AP_OBSS_PROTECTION_MODE_DEFAULT,
                        CFG_AP_OBSS_PROTECTION_MODE_MIN,
                        CFG_AP_OBSS_PROTECTION_MODE_MAX ),
<<<<<<< HEAD
<<<<<<< HEAD
                        
   REG_VARIABLE( CFG_AP_STA_SECURITY_SEPERATION_NAME, WLAN_PARAM_Integer,
                        hdd_config_t, apDisableIntraBssFwd, 
=======

   REG_VARIABLE( CFG_AP_STA_SECURITY_SEPERATION_NAME, WLAN_PARAM_Integer,
                        hdd_config_t, apDisableIntraBssFwd,
>>>>>>> d97af3b... add prima wlan driver
=======
                        
   REG_VARIABLE( CFG_AP_STA_SECURITY_SEPERATION_NAME, WLAN_PARAM_Integer,
                        hdd_config_t, apDisableIntraBssFwd, 
>>>>>>> 657b0e9... prima update
                        VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                        CFG_AP_STA_SECURITY_SEPERATION_DEFAULT,
                        CFG_AP_STA_SECURITY_SEPERATION_MIN,
                        CFG_AP_STA_SECURITY_SEPERATION_MAX ),

   REG_VARIABLE( CFG_FRAMES_PROCESSING_TH_MODE_NAME, WLAN_PARAM_Integer,
<<<<<<< HEAD
<<<<<<< HEAD
                        hdd_config_t, MinFramesProcThres, 
=======
                        hdd_config_t, MinFramesProcThres,
>>>>>>> d97af3b... add prima wlan driver
=======
                        hdd_config_t, MinFramesProcThres, 
>>>>>>> 657b0e9... prima update
                        VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                        CFG_FRAMES_PROCESSING_TH_DEFAULT,
                        CFG_FRAMES_PROCESSING_TH_MIN,
                        CFG_FRAMES_PROCESSING_TH_MAX ),

   REG_VARIABLE(CFG_SAP_CHANNEL_SELECT_START_CHANNEL , WLAN_PARAM_Integer,
                 hdd_config_t, apStartChannelNum,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_SAP_CHANNEL_SELECT_START_CHANNEL_DEFAULT,
                 CFG_SAP_CHANNEL_SELECT_START_CHANNEL_MIN,
                 CFG_SAP_CHANNEL_SELECT_START_CHANNEL_MAX ),

   REG_VARIABLE(CFG_SAP_CHANNEL_SELECT_END_CHANNEL , WLAN_PARAM_Integer,
                 hdd_config_t, apEndChannelNum,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_SAP_CHANNEL_SELECT_END_CHANNEL_DEFAULT,
                 CFG_SAP_CHANNEL_SELECT_END_CHANNEL_MIN,
                 CFG_SAP_CHANNEL_SELECT_END_CHANNEL_MAX ),

   REG_VARIABLE(CFG_SAP_CHANNEL_SELECT_OPERATING_BAND , WLAN_PARAM_Integer,
                 hdd_config_t, apOperatingBand,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_SAP_CHANNEL_SELECT_OPERATING_BAND_DEFAULT,
                 CFG_SAP_CHANNEL_SELECT_OPERATING_BAND_MIN,
                 CFG_SAP_CHANNEL_SELECT_OPERATING_BAND_MAX ),

   REG_VARIABLE(CFG_SAP_AUTO_CHANNEL_SELECTION_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, apAutoChannelSelection,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_SAP_AUTO_CHANNEL_SELECTION_DEFAULT,
                 CFG_SAP_AUTO_CHANNEL_SELECTION_MIN,
                 CFG_SAP_AUTO_CHANNEL_SELECTION_MAX ),
<<<<<<< HEAD
<<<<<<< HEAD
   
=======

>>>>>>> d97af3b... add prima wlan driver
=======
   
>>>>>>> 657b0e9... prima update
   REG_VARIABLE(CFG_ENABLE_LTE_COEX , WLAN_PARAM_Integer,
                 hdd_config_t, enableLTECoex,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_ENABLE_LTE_COEX_DEFAULT,
                 CFG_ENABLE_LTE_COEX_MIN,
                 CFG_ENABLE_LTE_COEX_MAX ),

   REG_VARIABLE( CFG_AP_KEEP_ALIVE_PERIOD_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, apKeepAlivePeriod,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_AP_KEEP_ALIVE_PERIOD_DEFAULT,
                 CFG_AP_KEEP_ALIVE_PERIOD_MIN,
                 CFG_AP_KEEP_ALIVE_PERIOD_MAX),

   REG_VARIABLE( CFG_GO_KEEP_ALIVE_PERIOD_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, goKeepAlivePeriod,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_GO_KEEP_ALIVE_PERIOD_DEFAULT,
                 CFG_GO_KEEP_ALIVE_PERIOD_MIN,
                 CFG_GO_KEEP_ALIVE_PERIOD_MAX),

<<<<<<< HEAD
<<<<<<< HEAD
#endif
=======
   REG_VARIABLE( CFG_AP_LINK_MONITOR_PERIOD_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, apLinkMonitorPeriod,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_AP_LINK_MONITOR_PERIOD_DEFAULT,
                 CFG_AP_LINK_MONITOR_PERIOD_MIN,
                 CFG_AP_LINK_MONITOR_PERIOD_MAX),

   REG_VARIABLE( CFG_GO_LINK_MONITOR_PERIOD_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, goLinkMonitorPeriod,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_GO_LINK_MONITOR_PERIOD_DEFAULT,
                 CFG_GO_LINK_MONITOR_PERIOD_MIN,
                 CFG_GO_LINK_MONITOR_PERIOD_MAX),

>>>>>>> d97af3b... add prima wlan driver
=======
#endif
>>>>>>> 657b0e9... prima update
   REG_VARIABLE(CFG_DISABLE_PACKET_FILTER , WLAN_PARAM_Integer,
                 hdd_config_t, disablePacketFilter,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_DISABLE_PACKET_FILTER_DEFAULT,
                 CFG_DISABLE_PACKET_FILTER_MIN,
                 CFG_DISABLE_PACKET_FILTER_MAX ),

   REG_VARIABLE( CFG_BEACON_INTERVAL_NAME, WLAN_PARAM_Integer,
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
                 hdd_config_t, nBeaconInterval, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK, 
                 CFG_BEACON_INTERVAL_DEFAULT, 
                 CFG_BEACON_INTERVAL_MIN, 
<<<<<<< HEAD
                 CFG_BEACON_INTERVAL_MAX ),

   REG_VARIABLE( CFG_ENABLE_HANDOFF_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, fIsHandoffEnabled, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_ENABLE_HANDOFF_DEFAULT, 
                 CFG_ENABLE_HANDOFF_MIN, 
                 CFG_ENABLE_HANDOFF_MAX ),


   REG_VARIABLE( CFG_ENABLE_IDLE_SCAN_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, nEnableIdleScan, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_ENABLE_IDLE_SCAN_DEFAULT, 
                 CFG_ENABLE_IDLE_SCAN_MIN, 
                 CFG_ENABLE_IDLE_SCAN_MAX ),

   REG_VARIABLE( CFG_ROAMING_TIME_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, nRoamingTime, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_ROAMING_TIME_DEFAULT, 
                 CFG_ROAMING_TIME_MIN, 
                 CFG_ROAMING_TIME_MAX ),

   REG_VARIABLE( CFG_VCC_RSSI_TRIGGER_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, nVccRssiTrigger, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_VCC_RSSI_TRIGGER_DEFAULT, 
                 CFG_VCC_RSSI_TRIGGER_MIN, 
                 CFG_VCC_RSSI_TRIGGER_MAX ),

   REG_VARIABLE( CFG_VCC_UL_MAC_LOSS_THRESH_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, nVccUlMacLossThreshold, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_VCC_UL_MAC_LOSS_THRESH_DEFAULT, 
                 CFG_VCC_UL_MAC_LOSS_THRESH_MIN, 
                 CFG_VCC_UL_MAC_LOSS_THRESH_MAX ),

   REG_VARIABLE( CFG_PASSIVE_MAX_CHANNEL_TIME_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, nPassiveMaxChnTime, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_PASSIVE_MAX_CHANNEL_TIME_DEFAULT, 
                 CFG_PASSIVE_MAX_CHANNEL_TIME_MIN, 
                 CFG_PASSIVE_MAX_CHANNEL_TIME_MAX ),

   REG_VARIABLE( CFG_PASSIVE_MIN_CHANNEL_TIME_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, nPassiveMinChnTime, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_PASSIVE_MIN_CHANNEL_TIME_DEFAULT, 
                 CFG_PASSIVE_MIN_CHANNEL_TIME_MIN, 
                 CFG_PASSIVE_MIN_CHANNEL_TIME_MAX ),

   REG_VARIABLE( CFG_ACTIVE_MAX_CHANNEL_TIME_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, nActiveMaxChnTime, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_ACTIVE_MAX_CHANNEL_TIME_DEFAULT, 
                 CFG_ACTIVE_MAX_CHANNEL_TIME_MIN, 
                 CFG_ACTIVE_MAX_CHANNEL_TIME_MAX ),

   REG_VARIABLE( CFG_ACTIVE_MIN_CHANNEL_TIME_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, nActiveMinChnTime, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_ACTIVE_MIN_CHANNEL_TIME_DEFAULT, 
                 CFG_ACTIVE_MIN_CHANNEL_TIME_MIN, 
                 CFG_ACTIVE_MIN_CHANNEL_TIME_MAX ),
   
   REG_VARIABLE( CFG_MAX_PS_POLL_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, nMaxPsPoll, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_MAX_PS_POLL_DEFAULT, 
                 CFG_MAX_PS_POLL_MIN, 
                 CFG_MAX_PS_POLL_MAX ),

    REG_VARIABLE( CFG_MAX_TX_POWER_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, nTxPowerCap, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_MAX_TX_POWER_DEFAULT, 
                 CFG_MAX_TX_POWER_MIN, 
=======
                 hdd_config_t, nBeaconInterval,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK,
                 CFG_BEACON_INTERVAL_DEFAULT,
                 CFG_BEACON_INTERVAL_MIN,
=======
>>>>>>> 657b0e9... prima update
                 CFG_BEACON_INTERVAL_MAX ),

   REG_VARIABLE( CFG_ENABLE_HANDOFF_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, fIsHandoffEnabled, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_ENABLE_HANDOFF_DEFAULT, 
                 CFG_ENABLE_HANDOFF_MIN, 
                 CFG_ENABLE_HANDOFF_MAX ),


   REG_VARIABLE( CFG_ENABLE_IDLE_SCAN_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, nEnableIdleScan, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_ENABLE_IDLE_SCAN_DEFAULT, 
                 CFG_ENABLE_IDLE_SCAN_MIN, 
                 CFG_ENABLE_IDLE_SCAN_MAX ),

   REG_VARIABLE( CFG_ROAMING_TIME_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, nRoamingTime, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_ROAMING_TIME_DEFAULT, 
                 CFG_ROAMING_TIME_MIN, 
                 CFG_ROAMING_TIME_MAX ),

   REG_VARIABLE( CFG_VCC_RSSI_TRIGGER_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, nVccRssiTrigger, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_VCC_RSSI_TRIGGER_DEFAULT, 
                 CFG_VCC_RSSI_TRIGGER_MIN, 
                 CFG_VCC_RSSI_TRIGGER_MAX ),

   REG_VARIABLE( CFG_VCC_UL_MAC_LOSS_THRESH_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, nVccUlMacLossThreshold, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_VCC_UL_MAC_LOSS_THRESH_DEFAULT, 
                 CFG_VCC_UL_MAC_LOSS_THRESH_MIN, 
                 CFG_VCC_UL_MAC_LOSS_THRESH_MAX ),

   REG_VARIABLE( CFG_PASSIVE_MAX_CHANNEL_TIME_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, nPassiveMaxChnTime, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_PASSIVE_MAX_CHANNEL_TIME_DEFAULT, 
                 CFG_PASSIVE_MAX_CHANNEL_TIME_MIN, 
                 CFG_PASSIVE_MAX_CHANNEL_TIME_MAX ),

   REG_VARIABLE( CFG_PASSIVE_MIN_CHANNEL_TIME_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, nPassiveMinChnTime, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_PASSIVE_MIN_CHANNEL_TIME_DEFAULT, 
                 CFG_PASSIVE_MIN_CHANNEL_TIME_MIN, 
                 CFG_PASSIVE_MIN_CHANNEL_TIME_MAX ),

   REG_VARIABLE( CFG_ACTIVE_MAX_CHANNEL_TIME_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, nActiveMaxChnTime, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_ACTIVE_MAX_CHANNEL_TIME_DEFAULT, 
                 CFG_ACTIVE_MAX_CHANNEL_TIME_MIN, 
                 CFG_ACTIVE_MAX_CHANNEL_TIME_MAX ),

   REG_VARIABLE( CFG_ACTIVE_MIN_CHANNEL_TIME_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, nActiveMinChnTime, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_ACTIVE_MIN_CHANNEL_TIME_DEFAULT, 
                 CFG_ACTIVE_MIN_CHANNEL_TIME_MIN, 
                 CFG_ACTIVE_MIN_CHANNEL_TIME_MAX ),
   
   REG_VARIABLE( CFG_MAX_PS_POLL_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, nMaxPsPoll, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_MAX_PS_POLL_DEFAULT, 
                 CFG_MAX_PS_POLL_MIN, 
                 CFG_MAX_PS_POLL_MAX ),

    REG_VARIABLE( CFG_MAX_TX_POWER_NAME, WLAN_PARAM_Integer,
<<<<<<< HEAD
                 hdd_config_t, nTxPowerCap,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_MAX_TX_POWER_DEFAULT,
                 CFG_MAX_TX_POWER_MIN,
>>>>>>> d97af3b... add prima wlan driver
=======
                 hdd_config_t, nTxPowerCap, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_MAX_TX_POWER_DEFAULT, 
                 CFG_MAX_TX_POWER_MIN, 
>>>>>>> 657b0e9... prima update
                 CFG_MAX_TX_POWER_MAX ),

   REG_VARIABLE( CFG_LOW_GAIN_OVERRIDE_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, fIsLowGainOverride,
<<<<<<< HEAD
<<<<<<< HEAD
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_LOW_GAIN_OVERRIDE_DEFAULT, 
                 CFG_LOW_GAIN_OVERRIDE_MIN, 
=======
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_LOW_GAIN_OVERRIDE_DEFAULT,
                 CFG_LOW_GAIN_OVERRIDE_MIN,
>>>>>>> d97af3b... add prima wlan driver
=======
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_LOW_GAIN_OVERRIDE_DEFAULT, 
                 CFG_LOW_GAIN_OVERRIDE_MIN, 
>>>>>>> 657b0e9... prima update
                 CFG_LOW_GAIN_OVERRIDE_MAX ),

   REG_VARIABLE( CFG_RSSI_FILTER_PERIOD_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, nRssiFilterPeriod,
<<<<<<< HEAD
<<<<<<< HEAD
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_RSSI_FILTER_PERIOD_DEFAULT, 
                 CFG_RSSI_FILTER_PERIOD_MIN, 
=======
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_RSSI_FILTER_PERIOD_DEFAULT,
                 CFG_RSSI_FILTER_PERIOD_MIN,
>>>>>>> d97af3b... add prima wlan driver
=======
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_RSSI_FILTER_PERIOD_DEFAULT, 
                 CFG_RSSI_FILTER_PERIOD_MIN, 
>>>>>>> 657b0e9... prima update
                 CFG_RSSI_FILTER_PERIOD_MAX ),

   REG_VARIABLE( CFG_IGNORE_DTIM_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, fIgnoreDtim,
<<<<<<< HEAD
<<<<<<< HEAD
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_IGNORE_DTIM_DEFAULT, 
                 CFG_IGNORE_DTIM_MIN, 
                 CFG_IGNORE_DTIM_MAX ),
                 
   REG_VARIABLE( CFG_RX_ANT_CONFIGURATION_NAME, WLAN_PARAM_Integer,
                hdd_config_t, nRxAnt, 
                VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                CFG_RX_ANT_CONFIGURATION_NAME_DEFAULT, 
                CFG_RX_ANT_CONFIGURATION_NAME_MIN, 
                CFG_RX_ANT_CONFIGURATION_NAME_MAX ),

   REG_VARIABLE( CFG_FW_HEART_BEAT_MONITORING_NAME, WLAN_PARAM_Integer,
                hdd_config_t, fEnableFwHeartBeatMonitoring, 
                VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                CFG_FW_HEART_BEAT_MONITORING_DEFAULT, 
                CFG_FW_HEART_BEAT_MONITORING_MIN, 
                CFG_FW_HEART_BEAT_MONITORING_MAX ),

   REG_VARIABLE( CFG_FW_BEACON_FILTERING_NAME, WLAN_PARAM_Integer,
                hdd_config_t, fEnableFwBeaconFiltering, 
                VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                CFG_FW_BEACON_FILTERING_DEFAULT, 
                CFG_FW_BEACON_FILTERING_MIN, 
                CFG_FW_BEACON_FILTERING_MAX ),

   REG_VARIABLE( CFG_FW_RSSI_MONITORING_NAME, WLAN_PARAM_Integer,
                hdd_config_t, fEnableFwRssiMonitoring, 
                VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                CFG_FW_RSSI_MONITORING_DEFAULT, 
                CFG_FW_RSSI_MONITORING_MIN, 
                CFG_FW_RSSI_MONITORING_MAX ),

   REG_VARIABLE( CFG_DATA_INACTIVITY_TIMEOUT_NAME, WLAN_PARAM_Integer,
                hdd_config_t, nDataInactivityTimeout, 
                VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                CFG_DATA_INACTIVITY_TIMEOUT_DEFAULT, 
                CFG_DATA_INACTIVITY_TIMEOUT_MIN, 
                CFG_DATA_INACTIVITY_TIMEOUT_MAX ),
                
   REG_VARIABLE( CFG_NTH_BEACON_FILTER_NAME, WLAN_PARAM_Integer,
                hdd_config_t, nthBeaconFilter, 
                VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                CFG_NTH_BEACON_FILTER_DEFAULT, 
                CFG_NTH_BEACON_FILTER_MIN, 
                CFG_NTH_BEACON_FILTER_MAX ),              

   REG_VARIABLE( CFG_QOS_WMM_MODE_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, WmmMode, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_WMM_MODE_DEFAULT, 
                 CFG_QOS_WMM_MODE_MIN, 
                 CFG_QOS_WMM_MODE_MAX ),

   REG_VARIABLE( CFG_QOS_WMM_80211E_ENABLED_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, b80211eIsEnabled, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_WMM_80211E_ENABLED_DEFAULT, 
                 CFG_QOS_WMM_80211E_ENABLED_MIN, 
                 CFG_QOS_WMM_80211E_ENABLED_MAX ),

   REG_VARIABLE( CFG_QOS_WMM_UAPSD_MASK_NAME , WLAN_PARAM_HexInteger,
                 hdd_config_t, UapsdMask, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_WMM_UAPSD_MASK_DEFAULT, 
                 CFG_QOS_WMM_UAPSD_MASK_MIN, 
                 CFG_QOS_WMM_UAPSD_MASK_MAX ),

   REG_VARIABLE( CFG_QOS_WMM_MAX_SP_LEN_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, MaxSpLength, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_WMM_MAX_SP_LEN_DEFAULT, 
                 CFG_QOS_WMM_MAX_SP_LEN_MIN, 
                 CFG_QOS_WMM_MAX_SP_LEN_MAX ),

   REG_VARIABLE( CFG_QOS_WMM_INFRA_UAPSD_VO_SRV_INTV_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, InfraUapsdVoSrvIntv, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_WMM_INFRA_UAPSD_VO_SRV_INTV_DEFAULT, 
                 CFG_QOS_WMM_INFRA_UAPSD_VO_SRV_INTV_MIN, 
                 CFG_QOS_WMM_INFRA_UAPSD_VO_SRV_INTV_MAX ),

   REG_VARIABLE( CFG_QOS_WMM_INFRA_UAPSD_VO_SUS_INTV_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, InfraUapsdVoSuspIntv, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_WMM_INFRA_UAPSD_VO_SUS_INTV_DEFAULT, 
                 CFG_QOS_WMM_INFRA_UAPSD_VO_SUS_INTV_MIN, 
                 CFG_QOS_WMM_INFRA_UAPSD_VO_SUS_INTV_MAX ),

   REG_VARIABLE( CFG_QOS_WMM_INFRA_UAPSD_VI_SRV_INTV_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, InfraUapsdViSrvIntv, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_WMM_INFRA_UAPSD_VI_SRV_INTV_DEFAULT, 
                 CFG_QOS_WMM_INFRA_UAPSD_VI_SRV_INTV_MIN, 
                 CFG_QOS_WMM_INFRA_UAPSD_VI_SRV_INTV_MAX ),

   REG_VARIABLE( CFG_QOS_WMM_INFRA_UAPSD_VI_SUS_INTV_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, InfraUapsdViSuspIntv, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_WMM_INFRA_UAPSD_VI_SUS_INTV_DEFAULT, 
                 CFG_QOS_WMM_INFRA_UAPSD_VI_SUS_INTV_MIN, 
                 CFG_QOS_WMM_INFRA_UAPSD_VI_SUS_INTV_MAX ),

   REG_VARIABLE( CFG_QOS_WMM_INFRA_UAPSD_BE_SRV_INTV_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, InfraUapsdBeSrvIntv, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_WMM_INFRA_UAPSD_BE_SRV_INTV_DEFAULT, 
                 CFG_QOS_WMM_INFRA_UAPSD_BE_SRV_INTV_MIN, 
                 CFG_QOS_WMM_INFRA_UAPSD_BE_SRV_INTV_MAX ),

   REG_VARIABLE( CFG_QOS_WMM_INFRA_UAPSD_BE_SUS_INTV_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, InfraUapsdBeSuspIntv, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_WMM_INFRA_UAPSD_BE_SUS_INTV_DEFAULT, 
                 CFG_QOS_WMM_INFRA_UAPSD_BE_SUS_INTV_MIN, 
                 CFG_QOS_WMM_INFRA_UAPSD_BE_SUS_INTV_MAX ),

   REG_VARIABLE( CFG_QOS_WMM_INFRA_UAPSD_BK_SRV_INTV_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, InfraUapsdBkSrvIntv, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_WMM_INFRA_UAPSD_BK_SRV_INTV_DEFAULT, 
                 CFG_QOS_WMM_INFRA_UAPSD_BK_SRV_INTV_MIN, 
                 CFG_QOS_WMM_INFRA_UAPSD_BK_SRV_INTV_MAX ),

   REG_VARIABLE( CFG_QOS_WMM_INFRA_UAPSD_BK_SUS_INTV_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, InfraUapsdBkSuspIntv, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_WMM_INFRA_UAPSD_BK_SUS_INTV_DEFAULT, 
                 CFG_QOS_WMM_INFRA_UAPSD_BK_SUS_INTV_MIN, 
=======
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_IGNORE_DTIM_DEFAULT,
                 CFG_IGNORE_DTIM_MIN,
=======
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_IGNORE_DTIM_DEFAULT, 
                 CFG_IGNORE_DTIM_MIN, 
>>>>>>> 657b0e9... prima update
                 CFG_IGNORE_DTIM_MAX ),
                 
   REG_VARIABLE( CFG_RX_ANT_CONFIGURATION_NAME, WLAN_PARAM_Integer,
                hdd_config_t, nRxAnt, 
                VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                CFG_RX_ANT_CONFIGURATION_NAME_DEFAULT, 
                CFG_RX_ANT_CONFIGURATION_NAME_MIN, 
                CFG_RX_ANT_CONFIGURATION_NAME_MAX ),

   REG_VARIABLE( CFG_FW_HEART_BEAT_MONITORING_NAME, WLAN_PARAM_Integer,
                hdd_config_t, fEnableFwHeartBeatMonitoring, 
                VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                CFG_FW_HEART_BEAT_MONITORING_DEFAULT, 
                CFG_FW_HEART_BEAT_MONITORING_MIN, 
                CFG_FW_HEART_BEAT_MONITORING_MAX ),

   REG_VARIABLE( CFG_FW_BEACON_FILTERING_NAME, WLAN_PARAM_Integer,
                hdd_config_t, fEnableFwBeaconFiltering, 
                VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                CFG_FW_BEACON_FILTERING_DEFAULT, 
                CFG_FW_BEACON_FILTERING_MIN, 
                CFG_FW_BEACON_FILTERING_MAX ),

   REG_VARIABLE( CFG_FW_RSSI_MONITORING_NAME, WLAN_PARAM_Integer,
                hdd_config_t, fEnableFwRssiMonitoring, 
                VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                CFG_FW_RSSI_MONITORING_DEFAULT, 
                CFG_FW_RSSI_MONITORING_MIN, 
                CFG_FW_RSSI_MONITORING_MAX ),

   REG_VARIABLE( CFG_DATA_INACTIVITY_TIMEOUT_NAME, WLAN_PARAM_Integer,
                hdd_config_t, nDataInactivityTimeout, 
                VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                CFG_DATA_INACTIVITY_TIMEOUT_DEFAULT, 
                CFG_DATA_INACTIVITY_TIMEOUT_MIN, 
                CFG_DATA_INACTIVITY_TIMEOUT_MAX ),
                
   REG_VARIABLE( CFG_NTH_BEACON_FILTER_NAME, WLAN_PARAM_Integer,
                hdd_config_t, nthBeaconFilter, 
                VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                CFG_NTH_BEACON_FILTER_DEFAULT, 
                CFG_NTH_BEACON_FILTER_MIN, 
                CFG_NTH_BEACON_FILTER_MAX ),              

   REG_VARIABLE( CFG_QOS_WMM_MODE_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, WmmMode, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_WMM_MODE_DEFAULT, 
                 CFG_QOS_WMM_MODE_MIN, 
                 CFG_QOS_WMM_MODE_MAX ),

   REG_VARIABLE( CFG_QOS_WMM_80211E_ENABLED_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, b80211eIsEnabled, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_WMM_80211E_ENABLED_DEFAULT, 
                 CFG_QOS_WMM_80211E_ENABLED_MIN, 
                 CFG_QOS_WMM_80211E_ENABLED_MAX ),

   REG_VARIABLE( CFG_QOS_WMM_UAPSD_MASK_NAME , WLAN_PARAM_HexInteger,
                 hdd_config_t, UapsdMask, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_WMM_UAPSD_MASK_DEFAULT, 
                 CFG_QOS_WMM_UAPSD_MASK_MIN, 
                 CFG_QOS_WMM_UAPSD_MASK_MAX ),

   REG_VARIABLE( CFG_QOS_WMM_MAX_SP_LEN_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, MaxSpLength, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_WMM_MAX_SP_LEN_DEFAULT, 
                 CFG_QOS_WMM_MAX_SP_LEN_MIN, 
                 CFG_QOS_WMM_MAX_SP_LEN_MAX ),

   REG_VARIABLE( CFG_QOS_WMM_INFRA_UAPSD_VO_SRV_INTV_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, InfraUapsdVoSrvIntv, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_WMM_INFRA_UAPSD_VO_SRV_INTV_DEFAULT, 
                 CFG_QOS_WMM_INFRA_UAPSD_VO_SRV_INTV_MIN, 
                 CFG_QOS_WMM_INFRA_UAPSD_VO_SRV_INTV_MAX ),

   REG_VARIABLE( CFG_QOS_WMM_INFRA_UAPSD_VO_SUS_INTV_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, InfraUapsdVoSuspIntv, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_WMM_INFRA_UAPSD_VO_SUS_INTV_DEFAULT, 
                 CFG_QOS_WMM_INFRA_UAPSD_VO_SUS_INTV_MIN, 
                 CFG_QOS_WMM_INFRA_UAPSD_VO_SUS_INTV_MAX ),

   REG_VARIABLE( CFG_QOS_WMM_INFRA_UAPSD_VI_SRV_INTV_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, InfraUapsdViSrvIntv, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_WMM_INFRA_UAPSD_VI_SRV_INTV_DEFAULT, 
                 CFG_QOS_WMM_INFRA_UAPSD_VI_SRV_INTV_MIN, 
                 CFG_QOS_WMM_INFRA_UAPSD_VI_SRV_INTV_MAX ),

   REG_VARIABLE( CFG_QOS_WMM_INFRA_UAPSD_VI_SUS_INTV_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, InfraUapsdViSuspIntv, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_WMM_INFRA_UAPSD_VI_SUS_INTV_DEFAULT, 
                 CFG_QOS_WMM_INFRA_UAPSD_VI_SUS_INTV_MIN, 
                 CFG_QOS_WMM_INFRA_UAPSD_VI_SUS_INTV_MAX ),

   REG_VARIABLE( CFG_QOS_WMM_INFRA_UAPSD_BE_SRV_INTV_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, InfraUapsdBeSrvIntv, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_WMM_INFRA_UAPSD_BE_SRV_INTV_DEFAULT, 
                 CFG_QOS_WMM_INFRA_UAPSD_BE_SRV_INTV_MIN, 
                 CFG_QOS_WMM_INFRA_UAPSD_BE_SRV_INTV_MAX ),

   REG_VARIABLE( CFG_QOS_WMM_INFRA_UAPSD_BE_SUS_INTV_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, InfraUapsdBeSuspIntv, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_WMM_INFRA_UAPSD_BE_SUS_INTV_DEFAULT, 
                 CFG_QOS_WMM_INFRA_UAPSD_BE_SUS_INTV_MIN, 
                 CFG_QOS_WMM_INFRA_UAPSD_BE_SUS_INTV_MAX ),

   REG_VARIABLE( CFG_QOS_WMM_INFRA_UAPSD_BK_SRV_INTV_NAME , WLAN_PARAM_Integer,
<<<<<<< HEAD
                 hdd_config_t, InfraUapsdBkSrvIntv,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_QOS_WMM_INFRA_UAPSD_BK_SRV_INTV_DEFAULT,
                 CFG_QOS_WMM_INFRA_UAPSD_BK_SRV_INTV_MIN,
                 CFG_QOS_WMM_INFRA_UAPSD_BK_SRV_INTV_MAX ),

   REG_VARIABLE( CFG_QOS_WMM_INFRA_UAPSD_BK_SUS_INTV_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, InfraUapsdBkSuspIntv,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_QOS_WMM_INFRA_UAPSD_BK_SUS_INTV_DEFAULT,
                 CFG_QOS_WMM_INFRA_UAPSD_BK_SUS_INTV_MIN,
>>>>>>> d97af3b... add prima wlan driver
                 CFG_QOS_WMM_INFRA_UAPSD_BK_SUS_INTV_MAX ),

#ifdef FEATURE_WLAN_CCX
   REG_VARIABLE( CFG_QOS_WMM_INFRA_INACTIVITY_INTERVAL_NAME, WLAN_PARAM_Integer,
<<<<<<< HEAD
                 hdd_config_t, InfraInactivityInterval, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_WMM_INFRA_INACTIVITY_INTERVAL_DEFAULT, 
                 CFG_QOS_WMM_INFRA_INACTIVITY_INTERVAL_MIN, 
                 CFG_QOS_WMM_INFRA_INACTIVITY_INTERVAL_MAX),
   REG_VARIABLE( CFG_CCX_FEATURE_ENABLED_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, isCcxIniFeatureEnabled, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_CCX_FEATURE_ENABLED_DEFAULT, 
                 CFG_CCX_FEATURE_ENABLED_MIN, 
                 CFG_CCX_FEATURE_ENABLED_MAX),
=======
                 hdd_config_t, InfraInactivityInterval,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_QOS_WMM_INFRA_INACTIVITY_INTERVAL_DEFAULT,
                 CFG_QOS_WMM_INFRA_INACTIVITY_INTERVAL_MIN,
                 CFG_QOS_WMM_INFRA_INACTIVITY_INTERVAL_MAX),
   REG_DYNAMIC_VARIABLE( CFG_CCX_FEATURE_ENABLED_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, isCcxIniFeatureEnabled,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_CCX_FEATURE_ENABLED_DEFAULT,
                 CFG_CCX_FEATURE_ENABLED_MIN,
                 CFG_CCX_FEATURE_ENABLED_MAX,
                 cbNotifySetCcxFeatureEnabled, 0 ),
>>>>>>> d97af3b... add prima wlan driver
#endif // FEATURE_WLAN_CCX

#ifdef FEATURE_WLAN_LFR
   // flag to turn ON/OFF Legacy Fast Roaming
<<<<<<< HEAD
   REG_VARIABLE( CFG_LFR_FEATURE_ENABLED_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, isFastRoamIniFeatureEnabled, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_LFR_FEATURE_ENABLED_DEFAULT, 
                 CFG_LFR_FEATURE_ENABLED_MIN, 
                 CFG_LFR_FEATURE_ENABLED_MAX),
#endif // FEATURE_WLAN_LFR

#if  defined (WLAN_FEATURE_VOWIFI_11R) || defined (FEATURE_WLAN_CCX) || defined(FEATURE_WLAN_LFR)
   REG_VARIABLE( CFG_FT_RSSI_FILTER_PERIOD_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, FTRssiFilterPeriod,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_FT_RSSI_FILTER_PERIOD_DEFAULT, 
                 CFG_FT_RSSI_FILTER_PERIOD_MIN, 
                 CFG_FT_RSSI_FILTER_PERIOD_MAX ),


   // flag to turn ON/OFF 11r and CCX FastTransition
   REG_VARIABLE( CFG_FAST_TRANSITION_ENABLED_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, isFastTransitionEnabled,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_FAST_TRANSITION_ENABLED_NAME_DEFAULT, 
                 CFG_FAST_TRANSITION_ENABLED_NAME_MIN, 
                 CFG_FAST_TRANSITION_ENABLED_NAME_MAX),

   /* Variable to specify the delta/difference between the RSSI of current AP 
    * and roamable AP while roaming */
   REG_VARIABLE( CFG_ROAM_RSSI_DIFF_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, RoamRssiDiff, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_ROAM_RSSI_DIFF_DEFAULT, 
                 CFG_ROAM_RSSI_DIFF_MIN, 
                 CFG_ROAM_RSSI_DIFF_MAX),
#endif

   REG_VARIABLE( CFG_QOS_WMM_PKT_CLASSIFY_BASIS_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, PktClassificationBasis, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_WMM_PKT_CLASSIFY_BASIS_DEFAULT, 
                 CFG_QOS_WMM_PKT_CLASSIFY_BASIS_MIN, 
                 CFG_QOS_WMM_PKT_CLASSIFY_BASIS_MAX ),

   REG_VARIABLE( CFG_QOS_WMM_INFRA_DIR_AC_VO_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, InfraDirAcVo, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_WMM_INFRA_DIR_AC_VO_DEFAULT, 
                 CFG_QOS_WMM_INFRA_DIR_AC_VO_MIN, 
                 CFG_QOS_WMM_INFRA_DIR_AC_VO_MAX ),

   REG_VARIABLE( CFG_QOS_WMM_INFRA_NOM_MSDU_SIZE_AC_VO_NAME , WLAN_PARAM_HexInteger,
                 hdd_config_t, InfraNomMsduSizeAcVo, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_WMM_INFRA_NOM_MSDU_SIZE_AC_VO_DEFAULT, 
                 CFG_QOS_WMM_INFRA_NOM_MSDU_SIZE_AC_VO_MIN, 
                 CFG_QOS_WMM_INFRA_NOM_MSDU_SIZE_AC_VO_MAX ),

   REG_VARIABLE( CFG_QOS_WMM_INFRA_MEAN_DATA_RATE_AC_VO_NAME , WLAN_PARAM_HexInteger,
                 hdd_config_t, InfraMeanDataRateAcVo, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_WMM_INFRA_MEAN_DATA_RATE_AC_VO_DEFAULT, 
                 CFG_QOS_WMM_INFRA_MEAN_DATA_RATE_AC_VO_MIN, 
                 CFG_QOS_WMM_INFRA_MEAN_DATA_RATE_AC_VO_MAX ),

   REG_VARIABLE( CFG_QOS_WMM_INFRA_MIN_PHY_RATE_AC_VO_NAME , WLAN_PARAM_HexInteger,
                 hdd_config_t, InfraMinPhyRateAcVo, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_WMM_INFRA_MIN_PHY_RATE_AC_VO_DEFAULT, 
                 CFG_QOS_WMM_INFRA_MIN_PHY_RATE_AC_VO_MIN, 
                 CFG_QOS_WMM_INFRA_MIN_PHY_RATE_AC_VO_MAX ),

   REG_VARIABLE( CFG_QOS_WMM_INFRA_SBA_AC_VO_NAME , WLAN_PARAM_HexInteger,
                 hdd_config_t, InfraSbaAcVo, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_WMM_INFRA_SBA_AC_VO_DEFAULT, 
                 CFG_QOS_WMM_INFRA_SBA_AC_VO_MIN, 
                 CFG_QOS_WMM_INFRA_SBA_AC_VO_MAX ),

   REG_VARIABLE( CFG_QOS_WMM_INFRA_DIR_AC_VI_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, InfraDirAcVi, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_WMM_INFRA_DIR_AC_VI_DEFAULT, 
                 CFG_QOS_WMM_INFRA_DIR_AC_VI_MIN, 
                 CFG_QOS_WMM_INFRA_DIR_AC_VI_MAX ),

   REG_VARIABLE( CFG_QOS_WMM_INFRA_NOM_MSDU_SIZE_AC_VI_NAME , WLAN_PARAM_HexInteger,
                 hdd_config_t, InfraNomMsduSizeAcVi, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_WMM_INFRA_NOM_MSDU_SIZE_AC_VI_DEFAULT, 
                 CFG_QOS_WMM_INFRA_NOM_MSDU_SIZE_AC_VI_MIN, 
                 CFG_QOS_WMM_INFRA_NOM_MSDU_SIZE_AC_VI_MAX ),

   REG_VARIABLE( CFG_QOS_WMM_INFRA_MEAN_DATA_RATE_AC_VI_NAME , WLAN_PARAM_HexInteger,
                 hdd_config_t, InfraMeanDataRateAcVi, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_WMM_INFRA_MEAN_DATA_RATE_AC_VI_DEFAULT, 
                 CFG_QOS_WMM_INFRA_MEAN_DATA_RATE_AC_VI_MIN, 
                 CFG_QOS_WMM_INFRA_MEAN_DATA_RATE_AC_VI_MAX ),

   REG_VARIABLE( CFG_QOS_WMM_INFRA_MIN_PHY_RATE_AC_VI_NAME , WLAN_PARAM_HexInteger,
                 hdd_config_t, InfraMinPhyRateAcVi, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_WMM_INFRA_MIN_PHY_RATE_AC_VI_DEFAULT, 
                 CFG_QOS_WMM_INFRA_MIN_PHY_RATE_AC_VI_MIN, 
                 CFG_QOS_WMM_INFRA_MIN_PHY_RATE_AC_VI_MAX ),

   REG_VARIABLE( CFG_QOS_WMM_INFRA_SBA_AC_VI_NAME , WLAN_PARAM_HexInteger,
                 hdd_config_t, InfraSbaAcVi, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_WMM_INFRA_SBA_AC_VI_DEFAULT, 
                 CFG_QOS_WMM_INFRA_SBA_AC_VI_MIN, 
                 CFG_QOS_WMM_INFRA_SBA_AC_VI_MAX ),

   REG_VARIABLE( CFG_QOS_WMM_INFRA_DIR_AC_BE_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, InfraDirAcBe, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_WMM_INFRA_DIR_AC_BE_DEFAULT, 
                 CFG_QOS_WMM_INFRA_DIR_AC_BE_MIN, 
                 CFG_QOS_WMM_INFRA_DIR_AC_BE_MAX ),

   REG_VARIABLE( CFG_QOS_WMM_INFRA_NOM_MSDU_SIZE_AC_BE_NAME , WLAN_PARAM_HexInteger,
                 hdd_config_t, InfraNomMsduSizeAcBe, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_WMM_INFRA_NOM_MSDU_SIZE_AC_BE_DEFAULT, 
                 CFG_QOS_WMM_INFRA_NOM_MSDU_SIZE_AC_BE_MIN, 
                 CFG_QOS_WMM_INFRA_NOM_MSDU_SIZE_AC_BE_MAX ),

   REG_VARIABLE( CFG_QOS_WMM_INFRA_MEAN_DATA_RATE_AC_BE_NAME , WLAN_PARAM_HexInteger,
                 hdd_config_t, InfraMeanDataRateAcBe, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_WMM_INFRA_MEAN_DATA_RATE_AC_BE_DEFAULT, 
                 CFG_QOS_WMM_INFRA_MEAN_DATA_RATE_AC_BE_MIN, 
                 CFG_QOS_WMM_INFRA_MEAN_DATA_RATE_AC_BE_MAX ),

   REG_VARIABLE( CFG_QOS_WMM_INFRA_MIN_PHY_RATE_AC_BE_NAME , WLAN_PARAM_HexInteger,
                 hdd_config_t, InfraMinPhyRateAcBe, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_WMM_INFRA_MIN_PHY_RATE_AC_BE_DEFAULT, 
                 CFG_QOS_WMM_INFRA_MIN_PHY_RATE_AC_BE_MIN, 
                 CFG_QOS_WMM_INFRA_MIN_PHY_RATE_AC_BE_MAX ),

   REG_VARIABLE( CFG_QOS_WMM_INFRA_SBA_AC_BE_NAME , WLAN_PARAM_HexInteger,
                 hdd_config_t, InfraSbaAcBe, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_WMM_INFRA_SBA_AC_BE_DEFAULT, 
                 CFG_QOS_WMM_INFRA_SBA_AC_BE_MIN, 
                 CFG_QOS_WMM_INFRA_SBA_AC_BE_MAX ),

   REG_VARIABLE( CFG_QOS_WMM_INFRA_DIR_AC_BK_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, InfraDirAcBk, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_WMM_INFRA_DIR_AC_BK_DEFAULT, 
                 CFG_QOS_WMM_INFRA_DIR_AC_BK_MIN, 
                 CFG_QOS_WMM_INFRA_DIR_AC_BK_MAX ),

   REG_VARIABLE( CFG_QOS_WMM_INFRA_NOM_MSDU_SIZE_AC_BK_NAME , WLAN_PARAM_HexInteger,
                 hdd_config_t, InfraNomMsduSizeAcBk, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_WMM_INFRA_NOM_MSDU_SIZE_AC_BK_DEFAULT, 
                 CFG_QOS_WMM_INFRA_NOM_MSDU_SIZE_AC_BK_MIN, 
                 CFG_QOS_WMM_INFRA_NOM_MSDU_SIZE_AC_BK_MAX ),

   REG_VARIABLE( CFG_QOS_WMM_INFRA_MEAN_DATA_RATE_AC_BK_NAME , WLAN_PARAM_HexInteger,
                 hdd_config_t, InfraMeanDataRateAcBk, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_WMM_INFRA_MEAN_DATA_RATE_AC_BK_DEFAULT, 
                 CFG_QOS_WMM_INFRA_MEAN_DATA_RATE_AC_BK_MIN, 
                 CFG_QOS_WMM_INFRA_MEAN_DATA_RATE_AC_BK_MAX ),

   REG_VARIABLE( CFG_QOS_WMM_INFRA_MIN_PHY_RATE_AC_BK_NAME , WLAN_PARAM_HexInteger,
                 hdd_config_t, InfraMinPhyRateAcBk, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_WMM_INFRA_MIN_PHY_RATE_AC_BK_DEFAULT, 
                 CFG_QOS_WMM_INFRA_MIN_PHY_RATE_AC_BK_MIN, 
                 CFG_QOS_WMM_INFRA_MIN_PHY_RATE_AC_BK_MAX ),

   REG_VARIABLE( CFG_QOS_WMM_INFRA_SBA_AC_BK_NAME , WLAN_PARAM_HexInteger,
                 hdd_config_t, InfraSbaAcBk, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_WMM_INFRA_SBA_AC_BK_DEFAULT, 
                 CFG_QOS_WMM_INFRA_SBA_AC_BK_MIN, 
                 CFG_QOS_WMM_INFRA_SBA_AC_BK_MAX ),

   REG_VARIABLE( CFG_TL_WFQ_BK_WEIGHT_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, WfqBkWeight, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_TL_WFQ_BK_WEIGHT_DEFAULT, 
                 CFG_TL_WFQ_BK_WEIGHT_MIN, 
                 CFG_TL_WFQ_BK_WEIGHT_MAX ),

   REG_VARIABLE( CFG_TL_WFQ_BE_WEIGHT_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, WfqBeWeight, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_TL_WFQ_BE_WEIGHT_DEFAULT, 
                 CFG_TL_WFQ_BE_WEIGHT_MIN, 
                 CFG_TL_WFQ_BE_WEIGHT_MAX ),

   REG_VARIABLE( CFG_TL_WFQ_VI_WEIGHT_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, WfqViWeight, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_TL_WFQ_VI_WEIGHT_DEFAULT, 
                 CFG_TL_WFQ_VI_WEIGHT_MIN, 
                 CFG_TL_WFQ_VI_WEIGHT_MAX ),

   REG_VARIABLE( CFG_TL_WFQ_VO_WEIGHT_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, WfqVoWeight, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_TL_WFQ_VO_WEIGHT_DEFAULT, 
                 CFG_TL_WFQ_VO_WEIGHT_MIN, 
                 CFG_TL_WFQ_VO_WEIGHT_MAX ),

   REG_VARIABLE( CFG_TL_DELAYED_TRGR_FRM_INT_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, DelayedTriggerFrmInt, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_TL_DELAYED_TRGR_FRM_INT_DEFAULT, 
                 CFG_TL_DELAYED_TRGR_FRM_INT_MIN, 
                 CFG_TL_DELAYED_TRGR_FRM_INT_MAX ),

   REG_VARIABLE_STRING( CFG_WOWL_PATTERN_NAME, WLAN_PARAM_String,
                        hdd_config_t, wowlPattern, 
=======
   REG_DYNAMIC_VARIABLE( CFG_LFR_FEATURE_ENABLED_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, isFastRoamIniFeatureEnabled,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_LFR_FEATURE_ENABLED_DEFAULT,
                 CFG_LFR_FEATURE_ENABLED_MIN,
                 CFG_LFR_FEATURE_ENABLED_MAX,
                 NotifyIsFastRoamIniFeatureEnabled, 0 ),
=======
                 hdd_config_t, InfraUapsdBkSrvIntv, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_WMM_INFRA_UAPSD_BK_SRV_INTV_DEFAULT, 
                 CFG_QOS_WMM_INFRA_UAPSD_BK_SRV_INTV_MIN, 
                 CFG_QOS_WMM_INFRA_UAPSD_BK_SRV_INTV_MAX ),

   REG_VARIABLE( CFG_QOS_WMM_INFRA_UAPSD_BK_SUS_INTV_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, InfraUapsdBkSuspIntv, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_WMM_INFRA_UAPSD_BK_SUS_INTV_DEFAULT, 
                 CFG_QOS_WMM_INFRA_UAPSD_BK_SUS_INTV_MIN, 
                 CFG_QOS_WMM_INFRA_UAPSD_BK_SUS_INTV_MAX ),

#ifdef FEATURE_WLAN_CCX
   REG_VARIABLE( CFG_QOS_WMM_INFRA_INACTIVITY_INTERVAL_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, InfraInactivityInterval, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_WMM_INFRA_INACTIVITY_INTERVAL_DEFAULT, 
                 CFG_QOS_WMM_INFRA_INACTIVITY_INTERVAL_MIN, 
                 CFG_QOS_WMM_INFRA_INACTIVITY_INTERVAL_MAX),
   REG_VARIABLE( CFG_CCX_FEATURE_ENABLED_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, isCcxIniFeatureEnabled, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_CCX_FEATURE_ENABLED_DEFAULT, 
                 CFG_CCX_FEATURE_ENABLED_MIN, 
                 CFG_CCX_FEATURE_ENABLED_MAX),
#endif // FEATURE_WLAN_CCX

#ifdef FEATURE_WLAN_LFR
   // flag to turn ON/OFF Legacy Fast Roaming
   REG_VARIABLE( CFG_LFR_FEATURE_ENABLED_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, isFastRoamIniFeatureEnabled, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_LFR_FEATURE_ENABLED_DEFAULT, 
                 CFG_LFR_FEATURE_ENABLED_MIN, 
                 CFG_LFR_FEATURE_ENABLED_MAX),
>>>>>>> 657b0e9... prima update
#endif // FEATURE_WLAN_LFR

#if  defined (WLAN_FEATURE_VOWIFI_11R) || defined (FEATURE_WLAN_CCX) || defined(FEATURE_WLAN_LFR)
   REG_VARIABLE( CFG_FT_RSSI_FILTER_PERIOD_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, FTRssiFilterPeriod,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_FT_RSSI_FILTER_PERIOD_DEFAULT, 
                 CFG_FT_RSSI_FILTER_PERIOD_MIN, 
                 CFG_FT_RSSI_FILTER_PERIOD_MAX ),


   // flag to turn ON/OFF 11r and CCX FastTransition
   REG_VARIABLE( CFG_FAST_TRANSITION_ENABLED_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, isFastTransitionEnabled,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_FAST_TRANSITION_ENABLED_NAME_DEFAULT, 
                 CFG_FAST_TRANSITION_ENABLED_NAME_MIN, 
                 CFG_FAST_TRANSITION_ENABLED_NAME_MAX),

   /* Variable to specify the delta/difference between the RSSI of current AP 
    * and roamable AP while roaming */
   REG_VARIABLE( CFG_ROAM_RSSI_DIFF_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, RoamRssiDiff, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_ROAM_RSSI_DIFF_DEFAULT, 
                 CFG_ROAM_RSSI_DIFF_MIN, 
                 CFG_ROAM_RSSI_DIFF_MAX),
#endif

   REG_VARIABLE( CFG_QOS_WMM_PKT_CLASSIFY_BASIS_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, PktClassificationBasis, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_WMM_PKT_CLASSIFY_BASIS_DEFAULT, 
                 CFG_QOS_WMM_PKT_CLASSIFY_BASIS_MIN, 
                 CFG_QOS_WMM_PKT_CLASSIFY_BASIS_MAX ),

   REG_VARIABLE( CFG_QOS_WMM_INFRA_DIR_AC_VO_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, InfraDirAcVo, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_WMM_INFRA_DIR_AC_VO_DEFAULT, 
                 CFG_QOS_WMM_INFRA_DIR_AC_VO_MIN, 
                 CFG_QOS_WMM_INFRA_DIR_AC_VO_MAX ),

   REG_VARIABLE( CFG_QOS_WMM_INFRA_NOM_MSDU_SIZE_AC_VO_NAME , WLAN_PARAM_HexInteger,
                 hdd_config_t, InfraNomMsduSizeAcVo, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_WMM_INFRA_NOM_MSDU_SIZE_AC_VO_DEFAULT, 
                 CFG_QOS_WMM_INFRA_NOM_MSDU_SIZE_AC_VO_MIN, 
                 CFG_QOS_WMM_INFRA_NOM_MSDU_SIZE_AC_VO_MAX ),

   REG_VARIABLE( CFG_QOS_WMM_INFRA_MEAN_DATA_RATE_AC_VO_NAME , WLAN_PARAM_HexInteger,
                 hdd_config_t, InfraMeanDataRateAcVo, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_WMM_INFRA_MEAN_DATA_RATE_AC_VO_DEFAULT, 
                 CFG_QOS_WMM_INFRA_MEAN_DATA_RATE_AC_VO_MIN, 
                 CFG_QOS_WMM_INFRA_MEAN_DATA_RATE_AC_VO_MAX ),

   REG_VARIABLE( CFG_QOS_WMM_INFRA_MIN_PHY_RATE_AC_VO_NAME , WLAN_PARAM_HexInteger,
                 hdd_config_t, InfraMinPhyRateAcVo, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_WMM_INFRA_MIN_PHY_RATE_AC_VO_DEFAULT, 
                 CFG_QOS_WMM_INFRA_MIN_PHY_RATE_AC_VO_MIN, 
                 CFG_QOS_WMM_INFRA_MIN_PHY_RATE_AC_VO_MAX ),

   REG_VARIABLE( CFG_QOS_WMM_INFRA_SBA_AC_VO_NAME , WLAN_PARAM_HexInteger,
                 hdd_config_t, InfraSbaAcVo, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_WMM_INFRA_SBA_AC_VO_DEFAULT, 
                 CFG_QOS_WMM_INFRA_SBA_AC_VO_MIN, 
                 CFG_QOS_WMM_INFRA_SBA_AC_VO_MAX ),

   REG_VARIABLE( CFG_QOS_WMM_INFRA_DIR_AC_VI_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, InfraDirAcVi, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_WMM_INFRA_DIR_AC_VI_DEFAULT, 
                 CFG_QOS_WMM_INFRA_DIR_AC_VI_MIN, 
                 CFG_QOS_WMM_INFRA_DIR_AC_VI_MAX ),

   REG_VARIABLE( CFG_QOS_WMM_INFRA_NOM_MSDU_SIZE_AC_VI_NAME , WLAN_PARAM_HexInteger,
                 hdd_config_t, InfraNomMsduSizeAcVi, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_WMM_INFRA_NOM_MSDU_SIZE_AC_VI_DEFAULT, 
                 CFG_QOS_WMM_INFRA_NOM_MSDU_SIZE_AC_VI_MIN, 
                 CFG_QOS_WMM_INFRA_NOM_MSDU_SIZE_AC_VI_MAX ),

   REG_VARIABLE( CFG_QOS_WMM_INFRA_MEAN_DATA_RATE_AC_VI_NAME , WLAN_PARAM_HexInteger,
                 hdd_config_t, InfraMeanDataRateAcVi, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_WMM_INFRA_MEAN_DATA_RATE_AC_VI_DEFAULT, 
                 CFG_QOS_WMM_INFRA_MEAN_DATA_RATE_AC_VI_MIN, 
                 CFG_QOS_WMM_INFRA_MEAN_DATA_RATE_AC_VI_MAX ),

   REG_VARIABLE( CFG_QOS_WMM_INFRA_MIN_PHY_RATE_AC_VI_NAME , WLAN_PARAM_HexInteger,
                 hdd_config_t, InfraMinPhyRateAcVi, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_WMM_INFRA_MIN_PHY_RATE_AC_VI_DEFAULT, 
                 CFG_QOS_WMM_INFRA_MIN_PHY_RATE_AC_VI_MIN, 
                 CFG_QOS_WMM_INFRA_MIN_PHY_RATE_AC_VI_MAX ),

   REG_VARIABLE( CFG_QOS_WMM_INFRA_SBA_AC_VI_NAME , WLAN_PARAM_HexInteger,
                 hdd_config_t, InfraSbaAcVi, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_WMM_INFRA_SBA_AC_VI_DEFAULT, 
                 CFG_QOS_WMM_INFRA_SBA_AC_VI_MIN, 
                 CFG_QOS_WMM_INFRA_SBA_AC_VI_MAX ),

   REG_VARIABLE( CFG_QOS_WMM_INFRA_DIR_AC_BE_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, InfraDirAcBe, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_WMM_INFRA_DIR_AC_BE_DEFAULT, 
                 CFG_QOS_WMM_INFRA_DIR_AC_BE_MIN, 
                 CFG_QOS_WMM_INFRA_DIR_AC_BE_MAX ),

   REG_VARIABLE( CFG_QOS_WMM_INFRA_NOM_MSDU_SIZE_AC_BE_NAME , WLAN_PARAM_HexInteger,
                 hdd_config_t, InfraNomMsduSizeAcBe, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_WMM_INFRA_NOM_MSDU_SIZE_AC_BE_DEFAULT, 
                 CFG_QOS_WMM_INFRA_NOM_MSDU_SIZE_AC_BE_MIN, 
                 CFG_QOS_WMM_INFRA_NOM_MSDU_SIZE_AC_BE_MAX ),

   REG_VARIABLE( CFG_QOS_WMM_INFRA_MEAN_DATA_RATE_AC_BE_NAME , WLAN_PARAM_HexInteger,
                 hdd_config_t, InfraMeanDataRateAcBe, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_WMM_INFRA_MEAN_DATA_RATE_AC_BE_DEFAULT, 
                 CFG_QOS_WMM_INFRA_MEAN_DATA_RATE_AC_BE_MIN, 
                 CFG_QOS_WMM_INFRA_MEAN_DATA_RATE_AC_BE_MAX ),

   REG_VARIABLE( CFG_QOS_WMM_INFRA_MIN_PHY_RATE_AC_BE_NAME , WLAN_PARAM_HexInteger,
                 hdd_config_t, InfraMinPhyRateAcBe, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_WMM_INFRA_MIN_PHY_RATE_AC_BE_DEFAULT, 
                 CFG_QOS_WMM_INFRA_MIN_PHY_RATE_AC_BE_MIN, 
                 CFG_QOS_WMM_INFRA_MIN_PHY_RATE_AC_BE_MAX ),

   REG_VARIABLE( CFG_QOS_WMM_INFRA_SBA_AC_BE_NAME , WLAN_PARAM_HexInteger,
                 hdd_config_t, InfraSbaAcBe, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_WMM_INFRA_SBA_AC_BE_DEFAULT, 
                 CFG_QOS_WMM_INFRA_SBA_AC_BE_MIN, 
                 CFG_QOS_WMM_INFRA_SBA_AC_BE_MAX ),

   REG_VARIABLE( CFG_QOS_WMM_INFRA_DIR_AC_BK_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, InfraDirAcBk, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_WMM_INFRA_DIR_AC_BK_DEFAULT, 
                 CFG_QOS_WMM_INFRA_DIR_AC_BK_MIN, 
                 CFG_QOS_WMM_INFRA_DIR_AC_BK_MAX ),

   REG_VARIABLE( CFG_QOS_WMM_INFRA_NOM_MSDU_SIZE_AC_BK_NAME , WLAN_PARAM_HexInteger,
                 hdd_config_t, InfraNomMsduSizeAcBk, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_WMM_INFRA_NOM_MSDU_SIZE_AC_BK_DEFAULT, 
                 CFG_QOS_WMM_INFRA_NOM_MSDU_SIZE_AC_BK_MIN, 
                 CFG_QOS_WMM_INFRA_NOM_MSDU_SIZE_AC_BK_MAX ),

   REG_VARIABLE( CFG_QOS_WMM_INFRA_MEAN_DATA_RATE_AC_BK_NAME , WLAN_PARAM_HexInteger,
                 hdd_config_t, InfraMeanDataRateAcBk, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_WMM_INFRA_MEAN_DATA_RATE_AC_BK_DEFAULT, 
                 CFG_QOS_WMM_INFRA_MEAN_DATA_RATE_AC_BK_MIN, 
                 CFG_QOS_WMM_INFRA_MEAN_DATA_RATE_AC_BK_MAX ),

   REG_VARIABLE( CFG_QOS_WMM_INFRA_MIN_PHY_RATE_AC_BK_NAME , WLAN_PARAM_HexInteger,
                 hdd_config_t, InfraMinPhyRateAcBk, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_WMM_INFRA_MIN_PHY_RATE_AC_BK_DEFAULT, 
                 CFG_QOS_WMM_INFRA_MIN_PHY_RATE_AC_BK_MIN, 
                 CFG_QOS_WMM_INFRA_MIN_PHY_RATE_AC_BK_MAX ),

   REG_VARIABLE( CFG_QOS_WMM_INFRA_SBA_AC_BK_NAME , WLAN_PARAM_HexInteger,
                 hdd_config_t, InfraSbaAcBk, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_WMM_INFRA_SBA_AC_BK_DEFAULT, 
                 CFG_QOS_WMM_INFRA_SBA_AC_BK_MIN, 
                 CFG_QOS_WMM_INFRA_SBA_AC_BK_MAX ),

   REG_VARIABLE( CFG_TL_WFQ_BK_WEIGHT_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, WfqBkWeight, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_TL_WFQ_BK_WEIGHT_DEFAULT, 
                 CFG_TL_WFQ_BK_WEIGHT_MIN, 
                 CFG_TL_WFQ_BK_WEIGHT_MAX ),

   REG_VARIABLE( CFG_TL_WFQ_BE_WEIGHT_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, WfqBeWeight, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_TL_WFQ_BE_WEIGHT_DEFAULT, 
                 CFG_TL_WFQ_BE_WEIGHT_MIN, 
                 CFG_TL_WFQ_BE_WEIGHT_MAX ),

   REG_VARIABLE( CFG_TL_WFQ_VI_WEIGHT_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, WfqViWeight, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_TL_WFQ_VI_WEIGHT_DEFAULT, 
                 CFG_TL_WFQ_VI_WEIGHT_MIN, 
                 CFG_TL_WFQ_VI_WEIGHT_MAX ),

   REG_VARIABLE( CFG_TL_WFQ_VO_WEIGHT_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, WfqVoWeight, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_TL_WFQ_VO_WEIGHT_DEFAULT, 
                 CFG_TL_WFQ_VO_WEIGHT_MIN, 
                 CFG_TL_WFQ_VO_WEIGHT_MAX ),

   REG_VARIABLE( CFG_TL_DELAYED_TRGR_FRM_INT_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, DelayedTriggerFrmInt, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_TL_DELAYED_TRGR_FRM_INT_DEFAULT, 
                 CFG_TL_DELAYED_TRGR_FRM_INT_MIN, 
                 CFG_TL_DELAYED_TRGR_FRM_INT_MAX ),

   REG_VARIABLE_STRING( CFG_WOWL_PATTERN_NAME, WLAN_PARAM_String,
<<<<<<< HEAD
                        hdd_config_t, wowlPattern,
>>>>>>> d97af3b... add prima wlan driver
=======
                        hdd_config_t, wowlPattern, 
>>>>>>> 657b0e9... prima update
                        VAR_FLAGS_OPTIONAL,
                        (void *)CFG_WOWL_PATTERN_DEFAULT ),

   REG_VARIABLE( CFG_QOS_IMPLICIT_SETUP_ENABLED_NAME , WLAN_PARAM_Integer,
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
                 hdd_config_t, bImplicitQosEnabled, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_IMPLICIT_SETUP_ENABLED_DEFAULT, 
                 CFG_QOS_IMPLICIT_SETUP_ENABLED_MIN, 
<<<<<<< HEAD
                 CFG_QOS_IMPLICIT_SETUP_ENABLED_MAX ),

   REG_VARIABLE( CFG_19P2_MHZ_PMIC_CLK_ENABLED_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, b19p2MhzPmicClkEnabled, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_19P2_MHZ_PMIC_CLK_ENABLED_DEFAULT, 
                 CFG_19P2_MHZ_PMIC_CLK_ENABLED_MIN, 
                 CFG_19P2_MHZ_PMIC_CLK_ENABLED_MAX ),

   REG_VARIABLE( CFG_BTC_EXECUTION_MODE_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, btcExecutionMode, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_BTC_EXECUTION_MODE_DEFAULT, 
                 CFG_BTC_EXECUTION_MODE_MIN, 
=======
                 hdd_config_t, bImplicitQosEnabled,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_QOS_IMPLICIT_SETUP_ENABLED_DEFAULT,
                 CFG_QOS_IMPLICIT_SETUP_ENABLED_MIN,
=======
>>>>>>> 657b0e9... prima update
                 CFG_QOS_IMPLICIT_SETUP_ENABLED_MAX ),

   REG_VARIABLE( CFG_19P2_MHZ_PMIC_CLK_ENABLED_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, b19p2MhzPmicClkEnabled, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_19P2_MHZ_PMIC_CLK_ENABLED_DEFAULT, 
                 CFG_19P2_MHZ_PMIC_CLK_ENABLED_MIN, 
                 CFG_19P2_MHZ_PMIC_CLK_ENABLED_MAX ),

   REG_VARIABLE( CFG_BTC_EXECUTION_MODE_NAME , WLAN_PARAM_Integer,
<<<<<<< HEAD
                 hdd_config_t, btcExecutionMode,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_BTC_EXECUTION_MODE_DEFAULT,
                 CFG_BTC_EXECUTION_MODE_MIN,
>>>>>>> d97af3b... add prima wlan driver
=======
                 hdd_config_t, btcExecutionMode, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_BTC_EXECUTION_MODE_DEFAULT, 
                 CFG_BTC_EXECUTION_MODE_MIN, 
>>>>>>> 657b0e9... prima update
                 CFG_BTC_EXECUTION_MODE_MAX ),

   REG_VARIABLE( CFG_BTC_DHCP_PROTECTION_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, btcConsBtSlotsToBlockDuringDhcp,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_BTC_DHCP_PROTECTION_DEFAULT,
                 CFG_BTC_DHCP_PROTECTION_MIN,
                 CFG_BTC_DHCP_PROTECTION_MAX ),

   REG_VARIABLE( CFG_BTC_A2DP_DHCP_PROTECTION_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, btcA2DPBtSubIntervalsDuringDhcp,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_BTC_A2DP_DHCP_PROTECTION_DEFAULT,
                 CFG_BTC_A2DP_DHCP_PROTECTION_MIN,
                 CFG_BTC_A2DP_DHCP_PROTECTION_MAX ),

   REG_VARIABLE( CFG_BTC_STATIC_LEN_INQ_BT_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, btcStaticLenInqBt,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_BTC_STATIC_LEN_INQ_BT_DEFAULT,
                 CFG_BTC_STATIC_LEN_INQ_BT_MIN,
                 CFG_BTC_STATIC_LEN_INQ_BT_MAX ),

   REG_VARIABLE( CFG_BTC_STATIC_LEN_PAGE_BT_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, btcStaticLenPageBt,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_BTC_STATIC_LEN_PAGE_BT_DEFAULT,
                 CFG_BTC_STATIC_LEN_PAGE_BT_MIN,
                 CFG_BTC_STATIC_LEN_PAGE_BT_MAX ),

   REG_VARIABLE( CFG_BTC_STATIC_LEN_CONN_BT_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, btcStaticLenConnBt,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_BTC_STATIC_LEN_CONN_BT_DEFAULT,
                 CFG_BTC_STATIC_LEN_CONN_BT_MIN,
                 CFG_BTC_STATIC_LEN_CONN_BT_MAX ),

   REG_VARIABLE( CFG_BTC_STATIC_LEN_LE_BT_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, btcStaticLenLeBt,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_BTC_STATIC_LEN_LE_BT_DEFAULT,
                 CFG_BTC_STATIC_LEN_LE_BT_MIN,
                 CFG_BTC_STATIC_LEN_LE_BT_MAX ),

   REG_VARIABLE( CFG_BTC_STATIC_LEN_INQ_WLAN_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, btcStaticLenInqWlan,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_BTC_STATIC_LEN_INQ_WLAN_DEFAULT,
                 CFG_BTC_STATIC_LEN_INQ_WLAN_MIN,
                 CFG_BTC_STATIC_LEN_INQ_WLAN_MAX ),

   REG_VARIABLE( CFG_BTC_STATIC_LEN_PAGE_WLAN_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, btcStaticLenPageWlan,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_BTC_STATIC_LEN_PAGE_WLAN_DEFAULT,
                 CFG_BTC_STATIC_LEN_PAGE_WLAN_MIN,
                 CFG_BTC_STATIC_LEN_PAGE_WLAN_MAX ),

   REG_VARIABLE( CFG_BTC_STATIC_LEN_CONN_WLAN_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, btcStaticLenConnWlan,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_BTC_STATIC_LEN_CONN_WLAN_DEFAULT,
                 CFG_BTC_STATIC_LEN_CONN_WLAN_MIN,
                 CFG_BTC_STATIC_LEN_CONN_WLAN_MAX ),

   REG_VARIABLE( CFG_BTC_STATIC_LEN_LE_WLAN_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, btcStaticLenLeWlan,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_BTC_STATIC_LEN_LE_WLAN_DEFAULT,
                 CFG_BTC_STATIC_LEN_LE_WLAN_MIN,
                 CFG_BTC_STATIC_LEN_LE_WLAN_MAX ),

   REG_VARIABLE( CFG_BTC_DYN_MAX_LEN_BT_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, btcDynMaxLenBt,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_BTC_DYN_MAX_LEN_BT_DEFAULT,
                 CFG_BTC_DYN_MAX_LEN_BT_MIN,
                 CFG_BTC_DYN_MAX_LEN_BT_MAX ),

   REG_VARIABLE( CFG_BTC_DYN_MAX_LEN_WLAN_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, btcDynMaxLenWlan,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_BTC_DYN_MAX_LEN_WLAN_DEFAULT,
                 CFG_BTC_DYN_MAX_LEN_WLAN_MIN,
                 CFG_BTC_DYN_MAX_LEN_WLAN_MAX ),

   REG_VARIABLE( CFG_BTC_MAX_SCO_BLOCK_PERC_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, btcMaxScoBlockPerc,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_BTC_MAX_SCO_BLOCK_PERC_DEFAULT,
                 CFG_BTC_MAX_SCO_BLOCK_PERC_MIN,
                 CFG_BTC_MAX_SCO_BLOCK_PERC_MAX ),

   REG_VARIABLE( CFG_BTC_DHCP_PROT_ON_A2DP_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, btcDhcpProtOnA2dp,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_BTC_DHCP_PROT_ON_A2DP_DEFAULT,
                 CFG_BTC_DHCP_PROT_ON_A2DP_MIN,
                 CFG_BTC_DHCP_PROT_ON_A2DP_MAX ),

   REG_VARIABLE( CFG_BTC_DHCP_PROT_ON_SCO_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, btcDhcpProtOnSco,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_BTC_DHCP_PROT_ON_SCO_DEFAULT,
                 CFG_BTC_DHCP_PROT_ON_SCO_MIN,
                 CFG_BTC_DHCP_PROT_ON_SCO_MAX ),

<<<<<<< HEAD
<<<<<<< HEAD
#ifdef WLAN_SOFTAP_FEATURE
   REG_VARIABLE( CFG_AP_LISTEN_MODE_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, nEnableListenMode, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_AP_LISTEN_MODE_DEFAULT, 
                 CFG_AP_LISTEN_MODE_MIN, 
                 CFG_AP_LISTEN_MODE_MAX ),                     
=======
   REG_VARIABLE( CFG_MWS_COEX_V1_WAN_FREQ_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, mwsCoexVictimWANFreq[0],
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_MWS_COEX_VX_WAN_FREQ_DEFAULT,
                 CFG_MWS_COEX_VX_WAN_FREQ_MIN,
                 CFG_MWS_COEX_VX_WAN_FREQ_MAX ),

   REG_VARIABLE( CFG_MWS_COEX_V1_WLAN_FREQ_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, mwsCoexVictimWLANFreq[0],
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_MWS_COEX_VX_WLAN_FREQ_DEFAULT,
                 CFG_MWS_COEX_VX_WLAN_FREQ_MIN,
                 CFG_MWS_COEX_VX_WLAN_FREQ_MAX ),

   REG_VARIABLE( CFG_MWS_COEX_V1_CONFIG_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, mwsCoexVictimConfig[0],
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_MWS_COEX_VX_CONFIG_DEFAULT,
                 CFG_MWS_COEX_VX_CONFIG_MIN,
                 CFG_MWS_COEX_VX_CONFIG_MAX ),

   REG_VARIABLE( CFG_MWS_COEX_V1_CONFIG2_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, mwsCoexVictimConfig2[0],
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_MWS_COEX_VX_CONFIG_DEFAULT,
                 CFG_MWS_COEX_VX_CONFIG_MIN,
                 CFG_MWS_COEX_VX_CONFIG_MAX ),

   REG_VARIABLE( CFG_MWS_COEX_V2_WAN_FREQ_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, mwsCoexVictimWANFreq[1],
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_MWS_COEX_VX_WAN_FREQ_DEFAULT,
                 CFG_MWS_COEX_VX_WAN_FREQ_MIN,
                 CFG_MWS_COEX_VX_WAN_FREQ_MAX ),

   REG_VARIABLE( CFG_MWS_COEX_V2_WLAN_FREQ_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, mwsCoexVictimWLANFreq[1],
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_MWS_COEX_VX_WLAN_FREQ_DEFAULT,
                 CFG_MWS_COEX_VX_WLAN_FREQ_MIN,
                 CFG_MWS_COEX_VX_WLAN_FREQ_MAX ),

   REG_VARIABLE( CFG_MWS_COEX_V2_CONFIG_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, mwsCoexVictimConfig[1],
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_MWS_COEX_VX_CONFIG_DEFAULT,
                 CFG_MWS_COEX_VX_CONFIG_MIN,
                 CFG_MWS_COEX_VX_CONFIG_MAX ),

   REG_VARIABLE( CFG_MWS_COEX_V2_CONFIG2_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, mwsCoexVictimConfig2[1],
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_MWS_COEX_VX_CONFIG_DEFAULT,
                 CFG_MWS_COEX_VX_CONFIG_MIN,
                 CFG_MWS_COEX_VX_CONFIG_MAX ),

   REG_VARIABLE( CFG_MWS_COEX_V3_WAN_FREQ_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, mwsCoexVictimWANFreq[2],
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_MWS_COEX_VX_WAN_FREQ_DEFAULT,
                 CFG_MWS_COEX_VX_WAN_FREQ_MIN,
                 CFG_MWS_COEX_VX_WAN_FREQ_MAX ),

   REG_VARIABLE( CFG_MWS_COEX_V3_WLAN_FREQ_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, mwsCoexVictimWLANFreq[2],
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_MWS_COEX_VX_WLAN_FREQ_DEFAULT,
                 CFG_MWS_COEX_VX_WLAN_FREQ_MIN,
                 CFG_MWS_COEX_VX_WLAN_FREQ_MAX ),

   REG_VARIABLE( CFG_MWS_COEX_V3_CONFIG_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, mwsCoexVictimConfig[2],
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_MWS_COEX_VX_CONFIG_DEFAULT,
                 CFG_MWS_COEX_VX_CONFIG_MIN,
                 CFG_MWS_COEX_VX_CONFIG_MAX ),

   REG_VARIABLE( CFG_MWS_COEX_V3_CONFIG2_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, mwsCoexVictimConfig2[2],
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_MWS_COEX_VX_CONFIG_DEFAULT,
                 CFG_MWS_COEX_VX_CONFIG_MIN,
                 CFG_MWS_COEX_VX_CONFIG_MAX ),

   REG_VARIABLE( CFG_MWS_COEX_V4_WAN_FREQ_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, mwsCoexVictimWANFreq[3],
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_MWS_COEX_VX_WAN_FREQ_DEFAULT,
                 CFG_MWS_COEX_VX_WAN_FREQ_MIN,
                 CFG_MWS_COEX_VX_WAN_FREQ_MAX ),

   REG_VARIABLE( CFG_MWS_COEX_V4_WLAN_FREQ_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, mwsCoexVictimWLANFreq[3],
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_MWS_COEX_VX_WLAN_FREQ_DEFAULT,
                 CFG_MWS_COEX_VX_WLAN_FREQ_MIN,
                 CFG_MWS_COEX_VX_WLAN_FREQ_MAX ),

   REG_VARIABLE( CFG_MWS_COEX_V4_CONFIG_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, mwsCoexVictimConfig[3],
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_MWS_COEX_VX_CONFIG_DEFAULT,
                 CFG_MWS_COEX_VX_CONFIG_MIN,
                 CFG_MWS_COEX_VX_CONFIG_MAX ),

   REG_VARIABLE( CFG_MWS_COEX_V4_CONFIG2_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, mwsCoexVictimConfig2[3],
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_MWS_COEX_VX_CONFIG_DEFAULT,
                 CFG_MWS_COEX_VX_CONFIG_MIN,
                 CFG_MWS_COEX_VX_CONFIG_MAX ),

   REG_VARIABLE( CFG_MWS_COEX_V5_WAN_FREQ_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, mwsCoexVictimWANFreq[4],
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_MWS_COEX_VX_WAN_FREQ_DEFAULT,
                 CFG_MWS_COEX_VX_WAN_FREQ_MIN,
                 CFG_MWS_COEX_VX_WAN_FREQ_MAX ),

   REG_VARIABLE( CFG_MWS_COEX_V5_WLAN_FREQ_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, mwsCoexVictimWLANFreq[4],
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_MWS_COEX_VX_WLAN_FREQ_DEFAULT,
                 CFG_MWS_COEX_VX_WLAN_FREQ_MIN,
                 CFG_MWS_COEX_VX_WLAN_FREQ_MAX ),

   REG_VARIABLE( CFG_MWS_COEX_V5_CONFIG_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, mwsCoexVictimConfig[4],
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_MWS_COEX_VX_CONFIG_DEFAULT,
                 CFG_MWS_COEX_VX_CONFIG_MIN,
                 CFG_MWS_COEX_VX_CONFIG_MAX ),

   REG_VARIABLE( CFG_MWS_COEX_V5_CONFIG2_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, mwsCoexVictimConfig2[4],
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_MWS_COEX_VX_CONFIG_DEFAULT,
                 CFG_MWS_COEX_VX_CONFIG_MIN,
                 CFG_MWS_COEX_VX_CONFIG_MAX ),

   REG_VARIABLE( CFG_MWS_COEX_V6_WAN_FREQ_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, mwsCoexVictimWANFreq[5],
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_MWS_COEX_VX_WAN_FREQ_DEFAULT,
                 CFG_MWS_COEX_VX_WAN_FREQ_MIN,
                 CFG_MWS_COEX_VX_WAN_FREQ_MAX ),

   REG_VARIABLE( CFG_MWS_COEX_V6_WLAN_FREQ_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, mwsCoexVictimWLANFreq[5],
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_MWS_COEX_VX_WLAN_FREQ_DEFAULT,
                 CFG_MWS_COEX_VX_WLAN_FREQ_MIN,
                 CFG_MWS_COEX_VX_WLAN_FREQ_MAX ),

   REG_VARIABLE( CFG_MWS_COEX_V6_CONFIG_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, mwsCoexVictimConfig[5],
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_MWS_COEX_VX_CONFIG_DEFAULT,
                 CFG_MWS_COEX_VX_CONFIG_MIN,
                 CFG_MWS_COEX_VX_CONFIG_MAX ),

   REG_VARIABLE( CFG_MWS_COEX_V6_CONFIG2_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, mwsCoexVictimConfig2[5],
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_MWS_COEX_VX_CONFIG_DEFAULT,
                 CFG_MWS_COEX_VX_CONFIG_MIN,
                 CFG_MWS_COEX_VX_CONFIG_MAX ),

   REG_VARIABLE( CFG_MWS_COEX_V7_WAN_FREQ_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, mwsCoexVictimWANFreq[6],
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_MWS_COEX_VX_WAN_FREQ_DEFAULT,
                 CFG_MWS_COEX_VX_WAN_FREQ_MIN,
                 CFG_MWS_COEX_VX_WAN_FREQ_MAX ),

   REG_VARIABLE( CFG_MWS_COEX_V7_WLAN_FREQ_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, mwsCoexVictimWLANFreq[6],
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_MWS_COEX_VX_WLAN_FREQ_DEFAULT,
                 CFG_MWS_COEX_VX_WLAN_FREQ_MIN,
                 CFG_MWS_COEX_VX_WLAN_FREQ_MAX ),

   REG_VARIABLE( CFG_MWS_COEX_V7_CONFIG_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, mwsCoexVictimConfig[6],
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_MWS_COEX_VX_CONFIG_DEFAULT,
                 CFG_MWS_COEX_VX_CONFIG_MIN,
                 CFG_MWS_COEX_VX_CONFIG_MAX ),

   REG_VARIABLE( CFG_MWS_COEX_V7_CONFIG2_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, mwsCoexVictimConfig2[6],
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_MWS_COEX_VX_CONFIG_DEFAULT,
                 CFG_MWS_COEX_VX_CONFIG_MIN,
                 CFG_MWS_COEX_VX_CONFIG_MAX ),

   REG_VARIABLE( CFG_MWS_COEX_V8_WAN_FREQ_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, mwsCoexVictimWANFreq[7],
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_MWS_COEX_VX_WAN_FREQ_DEFAULT,
                 CFG_MWS_COEX_VX_WAN_FREQ_MIN,
                 CFG_MWS_COEX_VX_WAN_FREQ_MAX ),

   REG_VARIABLE( CFG_MWS_COEX_V8_WLAN_FREQ_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, mwsCoexVictimWLANFreq[7],
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_MWS_COEX_VX_WLAN_FREQ_DEFAULT,
                 CFG_MWS_COEX_VX_WLAN_FREQ_MIN,
                 CFG_MWS_COEX_VX_WLAN_FREQ_MAX ),

   REG_VARIABLE( CFG_MWS_COEX_V8_CONFIG_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, mwsCoexVictimConfig[7],
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_MWS_COEX_VX_CONFIG_DEFAULT,
                 CFG_MWS_COEX_VX_CONFIG_MIN,
                 CFG_MWS_COEX_VX_CONFIG_MAX ),

   REG_VARIABLE( CFG_MWS_COEX_V8_CONFIG2_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, mwsCoexVictimConfig2[7],
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_MWS_COEX_VX_CONFIG_DEFAULT,
                 CFG_MWS_COEX_VX_CONFIG_MIN,
                 CFG_MWS_COEX_VX_CONFIG_MAX ),

   REG_VARIABLE( CFG_MWS_COEX_V9_WAN_FREQ_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, mwsCoexVictimWANFreq[8],
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_MWS_COEX_VX_WAN_FREQ_DEFAULT,
                 CFG_MWS_COEX_VX_WAN_FREQ_MIN,
                 CFG_MWS_COEX_VX_WAN_FREQ_MAX ),

   REG_VARIABLE( CFG_MWS_COEX_V9_WLAN_FREQ_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, mwsCoexVictimWLANFreq[8],
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_MWS_COEX_VX_WLAN_FREQ_DEFAULT,
                 CFG_MWS_COEX_VX_WLAN_FREQ_MIN,
                 CFG_MWS_COEX_VX_WLAN_FREQ_MAX ),

   REG_VARIABLE( CFG_MWS_COEX_V9_CONFIG_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, mwsCoexVictimConfig[8],
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_MWS_COEX_VX_CONFIG_DEFAULT,
                 CFG_MWS_COEX_VX_CONFIG_MIN,
                 CFG_MWS_COEX_VX_CONFIG_MAX ),

   REG_VARIABLE( CFG_MWS_COEX_V9_CONFIG2_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, mwsCoexVictimConfig2[8],
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_MWS_COEX_VX_CONFIG_DEFAULT,
                 CFG_MWS_COEX_VX_CONFIG_MIN,
                 CFG_MWS_COEX_VX_CONFIG_MAX ),

   REG_VARIABLE( CFG_MWS_COEX_V10_WAN_FREQ_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, mwsCoexVictimWANFreq[9],
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_MWS_COEX_VX_WAN_FREQ_DEFAULT,
                 CFG_MWS_COEX_VX_WAN_FREQ_MIN,
                 CFG_MWS_COEX_VX_WAN_FREQ_MAX ),

   REG_VARIABLE( CFG_MWS_COEX_V10_WLAN_FREQ_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, mwsCoexVictimWLANFreq[9],
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_MWS_COEX_VX_WLAN_FREQ_DEFAULT,
                 CFG_MWS_COEX_VX_WLAN_FREQ_MIN,
                 CFG_MWS_COEX_VX_WLAN_FREQ_MAX ),

   REG_VARIABLE( CFG_MWS_COEX_V10_CONFIG_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, mwsCoexVictimConfig[9],
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_MWS_COEX_VX_CONFIG_DEFAULT,
                 CFG_MWS_COEX_VX_CONFIG_MIN,
                 CFG_MWS_COEX_VX_CONFIG_MAX ),

   REG_VARIABLE( CFG_MWS_COEX_V10_CONFIG2_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, mwsCoexVictimConfig2[9],
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_MWS_COEX_VX_CONFIG_DEFAULT,
                 CFG_MWS_COEX_VX_CONFIG_MIN,
                 CFG_MWS_COEX_VX_CONFIG_MAX ),

   REG_VARIABLE( CFG_MWS_COEX_MODEM_BACKOFF_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, mwsCoexModemBackoff,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_MWS_COEX_MODEM_BACKOFF_DEFAULT,
                 CFG_MWS_COEX_MODEM_BACKOFF_MIN,
                 CFG_MWS_COEX_MODEM_BACKOFF_MAX ),

   REG_VARIABLE( CFG_MWS_COEX_CONFIG1_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, mwsCoexConfig[0],
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_MWS_COEX_CONFIGX_DEFAULT,
                 CFG_MWS_COEX_CONFIGX_MIN,
                 CFG_MWS_COEX_CONFIGX_MAX ),

   REG_VARIABLE( CFG_MWS_COEX_CONFIG2_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, mwsCoexConfig[1],
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_MWS_COEX_CONFIGX_DEFAULT,
                 CFG_MWS_COEX_CONFIGX_MIN,
                 CFG_MWS_COEX_CONFIGX_MAX ),

   REG_VARIABLE( CFG_MWS_COEX_CONFIG3_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, mwsCoexConfig[2],
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_MWS_COEX_CONFIGX_DEFAULT,
                 CFG_MWS_COEX_CONFIGX_MIN,
                 CFG_MWS_COEX_CONFIGX_MAX ),

   REG_VARIABLE( CFG_MWS_COEX_CONFIG4_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, mwsCoexConfig[3],
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_MWS_COEX_CONFIGX_DEFAULT,
                 CFG_MWS_COEX_CONFIGX_MIN,
                 CFG_MWS_COEX_CONFIGX_MAX ),

   REG_VARIABLE( CFG_MWS_COEX_CONFIG5_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, mwsCoexConfig[4],
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_MWS_COEX_CONFIGX_DEFAULT,
                 CFG_MWS_COEX_CONFIGX_MIN,
                 CFG_MWS_COEX_CONFIGX_MAX ),

   REG_VARIABLE( CFG_MWS_COEX_CONFIG6_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, mwsCoexConfig[5],
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_MWS_COEX_CONFIGX_DEFAULT,
                 CFG_MWS_COEX_CONFIGX_MIN,
                 CFG_MWS_COEX_CONFIGX_MAX ),

   REG_VARIABLE( CFG_SAR_POWER_BACKOFF_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, SARPowerBackoff,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_SAR_POWER_BACKOFF_DEFAULT,
                 CFG_SAR_POWER_BACKOFF_MIN,
                 CFG_SAR_POWER_BACKOFF_MAX ),

   REG_VARIABLE( CFG_AP_LISTEN_MODE_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, nEnableListenMode,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_AP_LISTEN_MODE_DEFAULT,
                 CFG_AP_LISTEN_MODE_MIN,
                 CFG_AP_LISTEN_MODE_MAX ),
>>>>>>> d97af3b... add prima wlan driver
=======
#ifdef WLAN_SOFTAP_FEATURE
   REG_VARIABLE( CFG_AP_LISTEN_MODE_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, nEnableListenMode, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_AP_LISTEN_MODE_DEFAULT, 
                 CFG_AP_LISTEN_MODE_MIN, 
                 CFG_AP_LISTEN_MODE_MAX ),                     
>>>>>>> 657b0e9... prima update

   REG_VARIABLE( CFG_AP_AUTO_SHUT_OFF , WLAN_PARAM_Integer,
                 hdd_config_t, nAPAutoShutOff,
                  VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_AP_AUTO_SHUT_OFF_DEFAULT,
                 CFG_AP_AUTO_SHUT_OFF_MIN,
                 CFG_AP_AUTO_SHUT_OFF_MAX ),
<<<<<<< HEAD
<<<<<<< HEAD
#endif

#if defined WLAN_FEATURE_VOWIFI
   REG_VARIABLE( CFG_RRM_ENABLE_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, fRrmEnable, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_RRM_ENABLE_DEFAULT, 
                 CFG_RRM_ENABLE_MIN, 
                 CFG_RRM_ENABLE_MAX ),

   REG_VARIABLE( CFG_RRM_OPERATING_CHAN_MAX_DURATION_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, nInChanMeasMaxDuration, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_RRM_OPERATING_CHAN_MAX_DURATION_DEFAULT, 
                 CFG_RRM_OPERATING_CHAN_MAX_DURATION_MIN, 
                 CFG_RRM_OPERATING_CHAN_MAX_DURATION_MAX ),

   REG_VARIABLE( CFG_RRM_NON_OPERATING_CHAN_MAX_DURATION_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, nOutChanMeasMaxDuration, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_RRM_NON_OPERATING_CHAN_MAX_DURATION_DEFAULT, 
                 CFG_RRM_NON_OPERATING_CHAN_MAX_DURATION_MIN, 
                 CFG_RRM_NON_OPERATING_CHAN_MAX_DURATION_MAX ),

   REG_VARIABLE( CFG_RRM_MEAS_RANDOMIZATION_INTVL_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, nRrmRandnIntvl, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_RRM_MEAS_RANDOMIZATION_INTVL_DEFAULT, 
                 CFG_RRM_MEAS_RANDOMIZATION_INTVL_MIN, 
                 CFG_RRM_MEAS_RANDOMIZATION_INTVL_MAX ),
#endif

#ifdef WLAN_FEATURE_VOWIFI_11R   
   REG_VARIABLE( CFG_FT_ENABLE_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, fFTEnable, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_FT_ENABLE_DEFAULT, 
                 CFG_FT_ENABLE_MIN, 
                 CFG_FT_ENABLE_MAX ),

   REG_VARIABLE( CFG_FT_RESOURCE_REQ_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, fFTResourceReqSupported, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_FT_RESOURCE_REQ_DEFAULT, 
                 CFG_FT_RESOURCE_REQ_MIN, 
=======
=======
#endif
>>>>>>> 657b0e9... prima update

#if defined WLAN_FEATURE_VOWIFI
   REG_VARIABLE( CFG_RRM_ENABLE_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, fRrmEnable, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_RRM_ENABLE_DEFAULT, 
                 CFG_RRM_ENABLE_MIN, 
                 CFG_RRM_ENABLE_MAX ),

   REG_VARIABLE( CFG_RRM_OPERATING_CHAN_MAX_DURATION_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, nInChanMeasMaxDuration, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_RRM_OPERATING_CHAN_MAX_DURATION_DEFAULT, 
                 CFG_RRM_OPERATING_CHAN_MAX_DURATION_MIN, 
                 CFG_RRM_OPERATING_CHAN_MAX_DURATION_MAX ),

   REG_VARIABLE( CFG_RRM_NON_OPERATING_CHAN_MAX_DURATION_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, nOutChanMeasMaxDuration, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_RRM_NON_OPERATING_CHAN_MAX_DURATION_DEFAULT, 
                 CFG_RRM_NON_OPERATING_CHAN_MAX_DURATION_MIN, 
                 CFG_RRM_NON_OPERATING_CHAN_MAX_DURATION_MAX ),

   REG_VARIABLE( CFG_RRM_MEAS_RANDOMIZATION_INTVL_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, nRrmRandnIntvl, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_RRM_MEAS_RANDOMIZATION_INTVL_DEFAULT, 
                 CFG_RRM_MEAS_RANDOMIZATION_INTVL_MIN, 
                 CFG_RRM_MEAS_RANDOMIZATION_INTVL_MAX ),
#endif

#ifdef WLAN_FEATURE_VOWIFI_11R   
   REG_VARIABLE( CFG_FT_ENABLE_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, fFTEnable, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_FT_ENABLE_DEFAULT, 
                 CFG_FT_ENABLE_MIN, 
                 CFG_FT_ENABLE_MAX ),

   REG_VARIABLE( CFG_FT_RESOURCE_REQ_NAME, WLAN_PARAM_Integer,
<<<<<<< HEAD
                 hdd_config_t, fFTResourceReqSupported,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_FT_RESOURCE_REQ_DEFAULT,
                 CFG_FT_RESOURCE_REQ_MIN,
>>>>>>> d97af3b... add prima wlan driver
=======
                 hdd_config_t, fFTResourceReqSupported, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_FT_RESOURCE_REQ_DEFAULT, 
                 CFG_FT_RESOURCE_REQ_MIN, 
>>>>>>> 657b0e9... prima update
                 CFG_FT_RESOURCE_REQ_MAX ),
#endif

#ifdef WLAN_FEATURE_NEIGHBOR_ROAMING
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
   REG_VARIABLE( CFG_NEIGHBOR_SCAN_TIMER_PERIOD_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, nNeighborScanPeriod, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_NEIGHBOR_SCAN_TIMER_PERIOD_DEFAULT, 
                 CFG_NEIGHBOR_SCAN_TIMER_PERIOD_MIN, 
                 CFG_NEIGHBOR_SCAN_TIMER_PERIOD_MAX ),
<<<<<<< HEAD

   REG_VARIABLE( CFG_NEIGHBOR_REASSOC_RSSI_THRESHOLD_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, nNeighborReassocRssiThreshold, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_NEIGHBOR_REASSOC_RSSI_THRESHOLD_DEFAULT, 
                 CFG_NEIGHBOR_REASSOC_RSSI_THRESHOLD_MIN, 
                 CFG_NEIGHBOR_REASSOC_RSSI_THRESHOLD_MAX ),

   REG_VARIABLE( CFG_NEIGHBOR_LOOKUP_RSSI_THRESHOLD_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, nNeighborLookupRssiThreshold, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_NEIGHBOR_LOOKUP_RSSI_THRESHOLD_DEFAULT, 
                 CFG_NEIGHBOR_LOOKUP_RSSI_THRESHOLD_MIN, 
                 CFG_NEIGHBOR_LOOKUP_RSSI_THRESHOLD_MAX ),

   REG_VARIABLE_STRING( CFG_NEIGHBOR_SCAN_CHAN_LIST_NAME, WLAN_PARAM_String,
                        hdd_config_t, neighborScanChanList, 
                        VAR_FLAGS_OPTIONAL,
                        (void *)CFG_NEIGHBOR_SCAN_CHAN_LIST_DEFAULT ),

   REG_VARIABLE( CFG_NEIGHBOR_SCAN_MIN_CHAN_TIME_NAME, WLAN_PARAM_Integer,
=======
   REG_DYNAMIC_VARIABLE( CFG_NEIGHBOR_SCAN_TIMER_PERIOD_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, nNeighborScanPeriod,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_NEIGHBOR_SCAN_TIMER_PERIOD_DEFAULT,
                 CFG_NEIGHBOR_SCAN_TIMER_PERIOD_MIN,
                 CFG_NEIGHBOR_SCAN_TIMER_PERIOD_MAX,
                 cbNotifySetNeighborScanPeriod, 0 ),
=======
>>>>>>> 657b0e9... prima update

   REG_VARIABLE( CFG_NEIGHBOR_REASSOC_RSSI_THRESHOLD_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, nNeighborReassocRssiThreshold, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_NEIGHBOR_REASSOC_RSSI_THRESHOLD_DEFAULT, 
                 CFG_NEIGHBOR_REASSOC_RSSI_THRESHOLD_MIN, 
                 CFG_NEIGHBOR_REASSOC_RSSI_THRESHOLD_MAX ),

   REG_VARIABLE( CFG_NEIGHBOR_LOOKUP_RSSI_THRESHOLD_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, nNeighborLookupRssiThreshold, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_NEIGHBOR_LOOKUP_RSSI_THRESHOLD_DEFAULT, 
                 CFG_NEIGHBOR_LOOKUP_RSSI_THRESHOLD_MIN, 
                 CFG_NEIGHBOR_LOOKUP_RSSI_THRESHOLD_MAX ),

   REG_VARIABLE_STRING( CFG_NEIGHBOR_SCAN_CHAN_LIST_NAME, WLAN_PARAM_String,
                        hdd_config_t, neighborScanChanList, 
                        VAR_FLAGS_OPTIONAL,
                        (void *)CFG_NEIGHBOR_SCAN_CHAN_LIST_DEFAULT ),

<<<<<<< HEAD
   REG_DYNAMIC_VARIABLE( CFG_NEIGHBOR_SCAN_MIN_CHAN_TIME_NAME, WLAN_PARAM_Integer,
>>>>>>> d97af3b... add prima wlan driver
=======
   REG_VARIABLE( CFG_NEIGHBOR_SCAN_MIN_CHAN_TIME_NAME, WLAN_PARAM_Integer,
>>>>>>> 657b0e9... prima update
                 hdd_config_t, nNeighborScanMinChanTime,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_NEIGHBOR_SCAN_MIN_CHAN_TIME_DEFAULT,
                 CFG_NEIGHBOR_SCAN_MIN_CHAN_TIME_MIN,
<<<<<<< HEAD
<<<<<<< HEAD
                 CFG_NEIGHBOR_SCAN_MIN_CHAN_TIME_MAX ),

   REG_VARIABLE( CFG_NEIGHBOR_SCAN_MAX_CHAN_TIME_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, nNeighborScanMaxChanTime, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_NEIGHBOR_SCAN_MAX_CHAN_TIME_DEFAULT, 
                 CFG_NEIGHBOR_SCAN_MAX_CHAN_TIME_MIN, 
                 CFG_NEIGHBOR_SCAN_MAX_CHAN_TIME_MAX ),
=======
                 CFG_NEIGHBOR_SCAN_MIN_CHAN_TIME_MAX,
                 cbNotifySetNeighborScanMinChanTime, 0 ),

   REG_DYNAMIC_VARIABLE( CFG_NEIGHBOR_SCAN_MAX_CHAN_TIME_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, nNeighborScanMaxChanTime,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_NEIGHBOR_SCAN_MAX_CHAN_TIME_DEFAULT,
                 CFG_NEIGHBOR_SCAN_MAX_CHAN_TIME_MIN,
                 CFG_NEIGHBOR_SCAN_MAX_CHAN_TIME_MAX,
                 cbNotifySetNeighborScanMaxChanTime, 0 ),
>>>>>>> d97af3b... add prima wlan driver
=======
                 CFG_NEIGHBOR_SCAN_MIN_CHAN_TIME_MAX ),

   REG_VARIABLE( CFG_NEIGHBOR_SCAN_MAX_CHAN_TIME_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, nNeighborScanMaxChanTime, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_NEIGHBOR_SCAN_MAX_CHAN_TIME_DEFAULT, 
                 CFG_NEIGHBOR_SCAN_MAX_CHAN_TIME_MIN, 
                 CFG_NEIGHBOR_SCAN_MAX_CHAN_TIME_MAX ),
>>>>>>> 657b0e9... prima update

   REG_VARIABLE( CFG_11R_NEIGHBOR_REQ_MAX_TRIES_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, nMaxNeighborReqTries,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_11R_NEIGHBOR_REQ_MAX_TRIES_DEFAULT,
                 CFG_11R_NEIGHBOR_REQ_MAX_TRIES_MIN,
                 CFG_11R_NEIGHBOR_REQ_MAX_TRIES_MAX),

<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
   REG_VARIABLE( CFG_NEIGHBOR_SCAN_RESULTS_REFRESH_PERIOD_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, nNeighborResultsRefreshPeriod, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_NEIGHBOR_SCAN_RESULTS_REFRESH_PERIOD_DEFAULT, 
                 CFG_NEIGHBOR_SCAN_RESULTS_REFRESH_PERIOD_MIN, 
                 CFG_NEIGHBOR_SCAN_RESULTS_REFRESH_PERIOD_MAX ),
<<<<<<< HEAD
#endif /* WLAN_FEATURE_NEIGHBOR_ROAMING */

   REG_VARIABLE( CFG_QOS_WMM_BURST_SIZE_DEFN_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, burstSizeDefinition, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_WMM_BURST_SIZE_DEFN_DEFAULT, 
                 CFG_QOS_WMM_BURST_SIZE_DEFN_MIN, 
=======
   REG_DYNAMIC_VARIABLE( CFG_NEIGHBOR_SCAN_RESULTS_REFRESH_PERIOD_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, nNeighborResultsRefreshPeriod,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_NEIGHBOR_SCAN_RESULTS_REFRESH_PERIOD_DEFAULT,
                 CFG_NEIGHBOR_SCAN_RESULTS_REFRESH_PERIOD_MIN,
                 CFG_NEIGHBOR_SCAN_RESULTS_REFRESH_PERIOD_MAX,
                 cbNotifySetNeighborResultsRefreshPeriod, 0 ),

   REG_DYNAMIC_VARIABLE( CFG_EMPTY_SCAN_REFRESH_PERIOD_NAME, WLAN_PARAM_Integer,
                         hdd_config_t, nEmptyScanRefreshPeriod,
                         VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                         CFG_EMPTY_SCAN_REFRESH_PERIOD_DEFAULT,
                         CFG_EMPTY_SCAN_REFRESH_PERIOD_MIN,
                         CFG_EMPTY_SCAN_REFRESH_PERIOD_MAX,
                         cbNotifySetEmptyScanRefreshPeriod, 0 ),
#endif /* WLAN_FEATURE_NEIGHBOR_ROAMING */

   REG_VARIABLE( CFG_QOS_WMM_BURST_SIZE_DEFN_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, burstSizeDefinition,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_QOS_WMM_BURST_SIZE_DEFN_DEFAULT,
                 CFG_QOS_WMM_BURST_SIZE_DEFN_MIN,
>>>>>>> d97af3b... add prima wlan driver
=======
#endif /* WLAN_FEATURE_NEIGHBOR_ROAMING */

   REG_VARIABLE( CFG_QOS_WMM_BURST_SIZE_DEFN_NAME , WLAN_PARAM_Integer,
                 hdd_config_t, burstSizeDefinition, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_WMM_BURST_SIZE_DEFN_DEFAULT, 
                 CFG_QOS_WMM_BURST_SIZE_DEFN_MIN, 
>>>>>>> 657b0e9... prima update
                 CFG_QOS_WMM_BURST_SIZE_DEFN_MAX ),

   REG_VARIABLE( CFG_MCAST_BCAST_FILTER_SETTING_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, mcastBcastFilterSetting,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_MCAST_BCAST_FILTER_SETTING_DEFAULT,
                 CFG_MCAST_BCAST_FILTER_SETTING_MIN,
                 CFG_MCAST_BCAST_FILTER_SETTING_MAX ),

   REG_VARIABLE( CFG_ENABLE_HOST_ARPOFFLOAD_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, fhostArpOffload,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_ENABLE_HOST_ARPOFFLOAD_DEFAULT,
                 CFG_ENABLE_HOST_ARPOFFLOAD_MIN,
                 CFG_ENABLE_HOST_ARPOFFLOAD_MAX ),

<<<<<<< HEAD
<<<<<<< HEAD
   REG_VARIABLE( CFG_QOS_WMM_TS_INFO_ACK_POLICY_NAME , WLAN_PARAM_HexInteger,
                 hdd_config_t, tsInfoAckPolicy, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_WMM_TS_INFO_ACK_POLICY_DEFAULT, 
                 CFG_QOS_WMM_TS_INFO_ACK_POLICY_MIN, 
=======
   REG_VARIABLE( CFG_ENABLE_HOST_NSOFFLOAD_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, fhostNSOffload,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_ENABLE_HOST_NSOFFLOAD_DEFAULT,
                 CFG_ENABLE_HOST_NSOFFLOAD_MIN,
                 CFG_ENABLE_HOST_NSOFFLOAD_MAX ),

   REG_VARIABLE( CFG_QOS_WMM_TS_INFO_ACK_POLICY_NAME , WLAN_PARAM_HexInteger,
                 hdd_config_t, tsInfoAckPolicy,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_QOS_WMM_TS_INFO_ACK_POLICY_DEFAULT,
                 CFG_QOS_WMM_TS_INFO_ACK_POLICY_MIN,
>>>>>>> d97af3b... add prima wlan driver
=======
   REG_VARIABLE( CFG_QOS_WMM_TS_INFO_ACK_POLICY_NAME , WLAN_PARAM_HexInteger,
                 hdd_config_t, tsInfoAckPolicy, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_QOS_WMM_TS_INFO_ACK_POLICY_DEFAULT, 
                 CFG_QOS_WMM_TS_INFO_ACK_POLICY_MIN, 
>>>>>>> 657b0e9... prima update
                 CFG_QOS_WMM_TS_INFO_ACK_POLICY_MAX ),

    REG_VARIABLE( CFG_SINGLE_TID_RC_NAME, WLAN_PARAM_Integer,
                  hdd_config_t, bSingleTidRc,
                  VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                  CFG_SINGLE_TID_RC_DEFAULT,
                  CFG_SINGLE_TID_RC_MIN,
                  CFG_SINGLE_TID_RC_MAX),

    REG_VARIABLE( CFG_DYNAMIC_PSPOLL_VALUE_NAME, WLAN_PARAM_Integer,
                  hdd_config_t, dynamicPsPollValue,
                  VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                  CFG_DYNAMIC_PSPOLL_VALUE_DEFAULT,
                  CFG_DYNAMIC_PSPOLL_VALUE_MIN,
                  CFG_DYNAMIC_PSPOLL_VALUE_MAX ),

   REG_VARIABLE( CFG_TELE_BCN_WAKEUP_EN_NAME, WLAN_PARAM_Integer,
                  hdd_config_t, teleBcnWakeupEn,
                  VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                  CFG_TELE_BCN_WAKEUP_EN_DEFAULT,
                  CFG_TELE_BCN_WAKEUP_EN_MIN,
                  CFG_TELE_BCN_WAKEUP_EN_MAX ),

    REG_VARIABLE( CFG_INFRA_STA_KEEP_ALIVE_PERIOD_NAME, WLAN_PARAM_Integer,
                  hdd_config_t, infraStaKeepAlivePeriod,
                  VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                  CFG_INFRA_STA_KEEP_ALIVE_PERIOD_DEFAULT,
                  CFG_INFRA_STA_KEEP_ALIVE_PERIOD_MIN,
                  CFG_INFRA_STA_KEEP_ALIVE_PERIOD_MAX),

    REG_VARIABLE( CFG_QOS_ADDTS_WHEN_ACM_IS_OFF_NAME , WLAN_PARAM_Integer,
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
                  hdd_config_t, AddTSWhenACMIsOff, 
                  VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                  CFG_QOS_ADDTS_WHEN_ACM_IS_OFF_DEFAULT, 
                  CFG_QOS_ADDTS_WHEN_ACM_IS_OFF_MIN, 
<<<<<<< HEAD
=======
                  hdd_config_t, AddTSWhenACMIsOff,
                  VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                  CFG_QOS_ADDTS_WHEN_ACM_IS_OFF_DEFAULT,
                  CFG_QOS_ADDTS_WHEN_ACM_IS_OFF_MIN,
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
                  CFG_QOS_ADDTS_WHEN_ACM_IS_OFF_MAX ),


    REG_VARIABLE( CFG_VALIDATE_SCAN_LIST_NAME , WLAN_PARAM_Integer,
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
                  hdd_config_t, fValidateScanList, 
                  VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                  CFG_VALIDATE_SCAN_LIST_DEFAULT, 
                  CFG_VALIDATE_SCAN_LIST_MIN, 
<<<<<<< HEAD
                  CFG_VALIDATE_SCAN_LIST_MAX ),
   
    REG_VARIABLE( CFG_NULLDATA_AP_RESP_TIMEOUT_NAME, WLAN_PARAM_Integer,
                hdd_config_t, nNullDataApRespTimeout, 
                VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                CFG_NULLDATA_AP_RESP_TIMEOUT_DEFAULT, 
                CFG_NULLDATA_AP_RESP_TIMEOUT_MIN, 
                CFG_NULLDATA_AP_RESP_TIMEOUT_MAX ),

    REG_VARIABLE( CFG_AP_DATA_AVAIL_POLL_PERIOD_NAME, WLAN_PARAM_Integer,
                hdd_config_t, apDataAvailPollPeriodInMs, 
                VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                CFG_AP_DATA_AVAIL_POLL_PERIOD_DEFAULT, 
                CFG_AP_DATA_AVAIL_POLL_PERIOD_MIN, 
                CFG_AP_DATA_AVAIL_POLL_PERIOD_MAX ),
                                
   REG_VARIABLE( CFG_ENABLE_BTAMP_NAME, WLAN_PARAM_Integer,
                 hdd_config_t, enableBtAmp, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_ENABLE_BTAMP_DEFAULT, 
                 CFG_ENABLE_BTAMP_MIN, 
=======
                  hdd_config_t, fValidateScanList,
                  VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                  CFG_VALIDATE_SCAN_LIST_DEFAULT,
                  CFG_VALIDATE_SCAN_LIST_MIN,
=======
>>>>>>> 657b0e9... prima update
                  CFG_VALIDATE_SCAN_LIST_MAX ),
   
    REG_VARIABLE( CFG_NULLDATA_AP_RESP_TIMEOUT_NAME, WLAN_PARAM_Integer,
                hdd_config_t, nNullDataApRespTimeout, 
                VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                CFG_NULLDATA_AP_RESP_TIMEOUT_DEFAULT, 
                CFG_NULLDATA_AP_RESP_TIMEOUT_MIN, 
                CFG_NULLDATA_AP_RESP_TIMEOUT_MAX ),

    REG_VARIABLE( CFG_AP_DATA_AVAIL_POLL_PERIOD_NAME, WLAN_PARAM_Integer,
                hdd_config_t, apDataAvailPollPeriodInMs, 
                VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                CFG_AP_DATA_AVAIL_POLL_PERIOD_DEFAULT, 
                CFG_AP_DATA_AVAIL_POLL_PERIOD_MIN, 
                CFG_AP_DATA_AVAIL_POLL_PERIOD_MAX ),
                                
   REG_VARIABLE( CFG_ENABLE_BTAMP_NAME, WLAN_PARAM_Integer,
<<<<<<< HEAD
                 hdd_config_t, enableBtAmp,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_ENABLE_BTAMP_DEFAULT,
                 CFG_ENABLE_BTAMP_MIN,
>>>>>>> d97af3b... add prima wlan driver
=======
                 hdd_config_t, enableBtAmp, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_ENABLE_BTAMP_DEFAULT, 
                 CFG_ENABLE_BTAMP_MIN, 
>>>>>>> 657b0e9... prima update
                 CFG_ENABLE_BTAMP_MAX ),

#ifdef WLAN_BTAMP_FEATURE
   REG_VARIABLE( CFG_BT_AMP_PREFERRED_CHANNEL_NAME, WLAN_PARAM_Integer,
<<<<<<< HEAD
<<<<<<< HEAD
                 hdd_config_t, preferredChannel, 
=======
                 hdd_config_t, preferredChannel,
>>>>>>> d97af3b... add prima wlan driver
=======
                 hdd_config_t, preferredChannel, 
>>>>>>> 657b0e9... prima update
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_BT_AMP_PREFERRED_CHANNEL_DEFAULT,
                 CFG_BT_AMP_PREFERRED_CHANNEL_MIN,
                 CFG_BT_AMP_PREFERRED_CHANNEL_MAX ),
#endif //WLAN_BTAMP_FEATURE
   REG_VARIABLE( CFG_BAND_CAPABILITY_NAME, WLAN_PARAM_Integer,
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
                 hdd_config_t, nBandCapability, 
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                 CFG_BAND_CAPABILITY_DEFAULT, 
                 CFG_BAND_CAPABILITY_MIN, 
                 CFG_BAND_CAPABILITY_MAX ), 
<<<<<<< HEAD

   REG_VARIABLE( CFG_ENABLE_BEACON_EARLY_TERMINATION_NAME, WLAN_PARAM_Integer,
                hdd_config_t, fEnableBeaconEarlyTermination, 
                VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                CFG_ENABLE_BEACON_EARLY_TERMINATION_DEFAULT, 
                CFG_ENABLE_BEACON_EARLY_TERMINATION_MIN, 
                CFG_ENABLE_BEACON_EARLY_TERMINATION_MAX ), 

#ifdef FEATURE_WLAN_INTEGRATED_SOC
=======
                 hdd_config_t, nBandCapability,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_BAND_CAPABILITY_DEFAULT,
                 CFG_BAND_CAPABILITY_MIN,
                 CFG_BAND_CAPABILITY_MAX ),
=======
>>>>>>> 657b0e9... prima update

   REG_VARIABLE( CFG_ENABLE_BEACON_EARLY_TERMINATION_NAME, WLAN_PARAM_Integer,
                hdd_config_t, fEnableBeaconEarlyTermination, 
                VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                CFG_ENABLE_BEACON_EARLY_TERMINATION_DEFAULT, 
                CFG_ENABLE_BEACON_EARLY_TERMINATION_MIN, 
                CFG_ENABLE_BEACON_EARLY_TERMINATION_MAX ), 

<<<<<<< HEAD
>>>>>>> d97af3b... add prima wlan driver
=======
#ifdef FEATURE_WLAN_INTEGRATED_SOC
>>>>>>> 657b0e9... prima update
   /* note that since the default value is out of range we cannot
      enable range check, otherwise we get a system log message */
   REG_VARIABLE( CFG_WDI_TRACE_ENABLE_DAL_NAME, WLAN_PARAM_Integer,
                hdd_config_t, wdiTraceEnableDAL,
                VAR_FLAGS_OPTIONAL,
                CFG_WDI_TRACE_ENABLE_DEFAULT,
                CFG_WDI_TRACE_ENABLE_MIN,
                CFG_WDI_TRACE_ENABLE_MAX ),

   REG_VARIABLE( CFG_WDI_TRACE_ENABLE_CTL_NAME, WLAN_PARAM_Integer,
                hdd_config_t, wdiTraceEnableCTL,
                VAR_FLAGS_OPTIONAL,
                CFG_WDI_TRACE_ENABLE_DEFAULT,
                CFG_WDI_TRACE_ENABLE_MIN,
                CFG_WDI_TRACE_ENABLE_MAX ),

   REG_VARIABLE( CFG_WDI_TRACE_ENABLE_DAT_NAME, WLAN_PARAM_Integer,
                hdd_config_t, wdiTraceEnableDAT,
                VAR_FLAGS_OPTIONAL,
                CFG_WDI_TRACE_ENABLE_DEFAULT,
                CFG_WDI_TRACE_ENABLE_MIN,
                CFG_WDI_TRACE_ENABLE_MAX ),

   REG_VARIABLE( CFG_WDI_TRACE_ENABLE_PAL_NAME, WLAN_PARAM_Integer,
                hdd_config_t, wdiTraceEnablePAL,
                VAR_FLAGS_OPTIONAL,
                CFG_WDI_TRACE_ENABLE_DEFAULT,
                CFG_WDI_TRACE_ENABLE_MIN,
                CFG_WDI_TRACE_ENABLE_MAX ),
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
#endif /* FEATURE_WLAN_INTEGRATED_SOC */

  REG_VARIABLE( CFG_TELE_BCN_TRANS_LI_NAME, WLAN_PARAM_Integer,
               hdd_config_t, nTeleBcnTransListenInterval, 
               VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
               CFG_TELE_BCN_TRANS_LI_DEFAULT, 
               CFG_TELE_BCN_TRANS_LI_MIN, 
               CFG_TELE_BCN_TRANS_LI_MAX ), 

  REG_VARIABLE( CFG_TELE_BCN_TRANS_LI_NUM_IDLE_BCNS_NAME, WLAN_PARAM_Integer,
               hdd_config_t, nTeleBcnTransLiNumIdleBeacons, 
               VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
               CFG_TELE_BCN_TRANS_LI_NUM_IDLE_BCNS_DEFAULT, 
               CFG_TELE_BCN_TRANS_LI_NUM_IDLE_BCNS_MIN, 
               CFG_TELE_BCN_TRANS_LI_NUM_IDLE_BCNS_MAX ), 

  REG_VARIABLE( CFG_TELE_BCN_MAX_LI_NAME, WLAN_PARAM_Integer,
               hdd_config_t, nTeleBcnMaxListenInterval, 
               VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
               CFG_TELE_BCN_MAX_LI_DEFAULT, 
               CFG_TELE_BCN_MAX_LI_MIN, 
               CFG_TELE_BCN_MAX_LI_MAX ), 

  REG_VARIABLE( CFG_TELE_BCN_MAX_LI_NUM_IDLE_BCNS_NAME, WLAN_PARAM_Integer,
               hdd_config_t, nTeleBcnMaxLiNumIdleBeacons, 
               VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
               CFG_TELE_BCN_MAX_LI_NUM_IDLE_BCNS_DEFAULT, 
               CFG_TELE_BCN_MAX_LI_NUM_IDLE_BCNS_MIN, 
               CFG_TELE_BCN_MAX_LI_NUM_IDLE_BCNS_MAX ), 

  REG_VARIABLE( CFG_BCN_EARLY_TERM_WAKE_NAME, WLAN_PARAM_Integer,
               hdd_config_t, bcnEarlyTermWakeInterval, 
               VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
               CFG_BCN_EARLY_TERM_WAKE_DEFAULT, 
               CFG_BCN_EARLY_TERM_WAKE_MIN, 
               CFG_BCN_EARLY_TERM_WAKE_MAX ), 

 REG_VARIABLE( CFG_AP_DATA_AVAIL_POLL_PERIOD_NAME, WLAN_PARAM_Integer,
              hdd_config_t, apDataAvailPollPeriodInMs, 
              VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
              CFG_AP_DATA_AVAIL_POLL_PERIOD_DEFAULT, 
              CFG_AP_DATA_AVAIL_POLL_PERIOD_MIN, 
<<<<<<< HEAD
              CFG_AP_DATA_AVAIL_POLL_PERIOD_MAX ),

   REG_VARIABLE( CFG_ENABLE_CLOSE_LOOP_NAME, WLAN_PARAM_Integer,
                hdd_config_t, enableCloseLoop, 
                VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                CFG_ENABLE_CLOSE_LOOP_DEFAULT, 
                CFG_ENABLE_CLOSE_LOOP_MIN, 
                CFG_ENABLE_CLOSE_LOOP_MAX ),

 REG_VARIABLE( CFG_ENABLE_BYPASS_11D_NAME, WLAN_PARAM_Integer,
              hdd_config_t, enableBypass11d, 
              VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
              CFG_ENABLE_BYPASS_11D_DEFAULT, 
              CFG_ENABLE_BYPASS_11D_MIN, 
              CFG_ENABLE_BYPASS_11D_MAX ),

 REG_VARIABLE( CFG_ENABLE_DFS_CHNL_SCAN_NAME, WLAN_PARAM_Integer,
              hdd_config_t, enableDFSChnlScan, 
              VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
              CFG_ENABLE_DFS_CHNL_SCAN_DEFAULT, 
              CFG_ENABLE_DFS_CHNL_SCAN_MIN, 
              CFG_ENABLE_DFS_CHNL_SCAN_MAX ),

 REG_VARIABLE( CFG_ENABLE_DYNAMIC_DTIM_NAME, WLAN_PARAM_Integer,
              hdd_config_t, enableDynamicDTIM, 
              VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
              CFG_ENABLE_DYNAMIC_DTIM_DEFAULT, 
              CFG_ENABLE_DYNAMIC_DTIM_MIN, 
              CFG_ENABLE_DYNAMIC_DTIM_MAX ),

 REG_VARIABLE( CFG_ENABLE_AUTOMATIC_TX_POWER_CONTROL_NAME, WLAN_PARAM_Integer,
              hdd_config_t, enableAutomaticTxPowerControl, 
              VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
              CFG_ENABLE_AUTOMATIC_TX_POWER_CONTROL_DEFAULT, 
              CFG_ENABLE_AUTOMATIC_TX_POWER_CONTROL_MIN, 
              CFG_ENABLE_AUTOMATIC_TX_POWER_CONTROL_MAX ),

 REG_VARIABLE( CFG_SHORT_GI_40MHZ_NAME, WLAN_PARAM_Integer,
              hdd_config_t, ShortGI40MhzEnable, 
              VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
              CFG_SHORT_GI_40MHZ_DEFAULT, 
              CFG_SHORT_GI_40MHZ_MIN, 
              CFG_SHORT_GI_40MHZ_MAX ),

 REG_DYNAMIC_VARIABLE( CFG_REPORT_MAX_LINK_SPEED, WLAN_PARAM_Integer,
                       hdd_config_t, reportMaxLinkSpeed, 
                       VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                       CFG_REPORT_MAX_LINK_SPEED_DEFAULT, 
                       CFG_REPORT_MAX_LINK_SPEED_MIN, 
                       CFG_REPORT_MAX_LINK_SPEED_MAX,
                       NULL, 0 ),

 REG_DYNAMIC_VARIABLE( CFG_LINK_SPEED_RSSI_HIGH, WLAN_PARAM_SignedInteger,
=======

   REG_VARIABLE( CFG_TELE_BCN_TRANS_LI_NAME, WLAN_PARAM_Integer,
               hdd_config_t, nTeleBcnTransListenInterval,
               VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
               CFG_TELE_BCN_TRANS_LI_DEFAULT,
               CFG_TELE_BCN_TRANS_LI_MIN,
               CFG_TELE_BCN_TRANS_LI_MAX ),

   REG_VARIABLE( CFG_TELE_BCN_TRANS_LI_NUM_IDLE_BCNS_NAME, WLAN_PARAM_Integer,
               hdd_config_t, nTeleBcnTransLiNumIdleBeacons,
               VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
               CFG_TELE_BCN_TRANS_LI_NUM_IDLE_BCNS_DEFAULT,
               CFG_TELE_BCN_TRANS_LI_NUM_IDLE_BCNS_MIN,
               CFG_TELE_BCN_TRANS_LI_NUM_IDLE_BCNS_MAX ),

   REG_VARIABLE( CFG_TELE_BCN_MAX_LI_NAME, WLAN_PARAM_Integer,
               hdd_config_t, nTeleBcnMaxListenInterval,
               VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
               CFG_TELE_BCN_MAX_LI_DEFAULT,
               CFG_TELE_BCN_MAX_LI_MIN,
               CFG_TELE_BCN_MAX_LI_MAX ),

   REG_VARIABLE( CFG_TELE_BCN_MAX_LI_NUM_IDLE_BCNS_NAME, WLAN_PARAM_Integer,
               hdd_config_t, nTeleBcnMaxLiNumIdleBeacons,
               VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
               CFG_TELE_BCN_MAX_LI_NUM_IDLE_BCNS_DEFAULT,
               CFG_TELE_BCN_MAX_LI_NUM_IDLE_BCNS_MIN,
               CFG_TELE_BCN_MAX_LI_NUM_IDLE_BCNS_MAX ),

   REG_VARIABLE( CFG_BCN_EARLY_TERM_WAKE_NAME, WLAN_PARAM_Integer,
               hdd_config_t, bcnEarlyTermWakeInterval,
               VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
               CFG_BCN_EARLY_TERM_WAKE_DEFAULT,
               CFG_BCN_EARLY_TERM_WAKE_MIN,
               CFG_BCN_EARLY_TERM_WAKE_MAX ),

   REG_VARIABLE( CFG_AP_DATA_AVAIL_POLL_PERIOD_NAME, WLAN_PARAM_Integer,
              hdd_config_t, apDataAvailPollPeriodInMs,
              VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
              CFG_AP_DATA_AVAIL_POLL_PERIOD_DEFAULT,
              CFG_AP_DATA_AVAIL_POLL_PERIOD_MIN,
=======
>>>>>>> 657b0e9... prima update
              CFG_AP_DATA_AVAIL_POLL_PERIOD_MAX ),

   REG_VARIABLE( CFG_ENABLE_CLOSE_LOOP_NAME, WLAN_PARAM_Integer,
                hdd_config_t, enableCloseLoop, 
                VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                CFG_ENABLE_CLOSE_LOOP_DEFAULT, 
                CFG_ENABLE_CLOSE_LOOP_MIN, 
                CFG_ENABLE_CLOSE_LOOP_MAX ),

 REG_VARIABLE( CFG_ENABLE_BYPASS_11D_NAME, WLAN_PARAM_Integer,
              hdd_config_t, enableBypass11d, 
              VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
              CFG_ENABLE_BYPASS_11D_DEFAULT, 
              CFG_ENABLE_BYPASS_11D_MIN, 
              CFG_ENABLE_BYPASS_11D_MAX ),

 REG_VARIABLE( CFG_ENABLE_DFS_CHNL_SCAN_NAME, WLAN_PARAM_Integer,
              hdd_config_t, enableDFSChnlScan, 
              VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
              CFG_ENABLE_DFS_CHNL_SCAN_DEFAULT, 
              CFG_ENABLE_DFS_CHNL_SCAN_MIN, 
              CFG_ENABLE_DFS_CHNL_SCAN_MAX ),

 REG_VARIABLE( CFG_ENABLE_DYNAMIC_DTIM_NAME, WLAN_PARAM_Integer,
              hdd_config_t, enableDynamicDTIM, 
              VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
              CFG_ENABLE_DYNAMIC_DTIM_DEFAULT, 
              CFG_ENABLE_DYNAMIC_DTIM_MIN, 
              CFG_ENABLE_DYNAMIC_DTIM_MAX ),

 REG_VARIABLE( CFG_ENABLE_AUTOMATIC_TX_POWER_CONTROL_NAME, WLAN_PARAM_Integer,
              hdd_config_t, enableAutomaticTxPowerControl, 
              VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
              CFG_ENABLE_AUTOMATIC_TX_POWER_CONTROL_DEFAULT, 
              CFG_ENABLE_AUTOMATIC_TX_POWER_CONTROL_MIN, 
              CFG_ENABLE_AUTOMATIC_TX_POWER_CONTROL_MAX ),

 REG_VARIABLE( CFG_SHORT_GI_40MHZ_NAME, WLAN_PARAM_Integer,
              hdd_config_t, ShortGI40MhzEnable, 
              VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
              CFG_SHORT_GI_40MHZ_DEFAULT, 
              CFG_SHORT_GI_40MHZ_MIN, 
              CFG_SHORT_GI_40MHZ_MAX ),

 REG_DYNAMIC_VARIABLE( CFG_REPORT_MAX_LINK_SPEED, WLAN_PARAM_Integer,
                       hdd_config_t, reportMaxLinkSpeed, 
                       VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
                       CFG_REPORT_MAX_LINK_SPEED_DEFAULT, 
                       CFG_REPORT_MAX_LINK_SPEED_MIN, 
                       CFG_REPORT_MAX_LINK_SPEED_MAX,
                       NULL, 0 ),

<<<<<<< HEAD
   REG_DYNAMIC_VARIABLE( CFG_LINK_SPEED_RSSI_HIGH, WLAN_PARAM_SignedInteger,
>>>>>>> d97af3b... add prima wlan driver
=======
 REG_DYNAMIC_VARIABLE( CFG_LINK_SPEED_RSSI_HIGH, WLAN_PARAM_SignedInteger,
>>>>>>> 657b0e9... prima update
                       hdd_config_t, linkSpeedRssiHigh,
                       VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                       CFG_LINK_SPEED_RSSI_HIGH_DEFAULT,
                       CFG_LINK_SPEED_RSSI_HIGH_MIN,
                       CFG_LINK_SPEED_RSSI_HIGH_MAX,
                       NULL, 0 ),

<<<<<<< HEAD
<<<<<<< HEAD
 REG_DYNAMIC_VARIABLE( CFG_LINK_SPEED_RSSI_LOW, WLAN_PARAM_SignedInteger,
=======
   REG_DYNAMIC_VARIABLE( CFG_LINK_SPEED_RSSI_MID, WLAN_PARAM_SignedInteger,
                       hdd_config_t, linkSpeedRssiMid,
                       VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                       CFG_LINK_SPEED_RSSI_MID_DEFAULT,
                       CFG_LINK_SPEED_RSSI_MID_MIN,
                       CFG_LINK_SPEED_RSSI_MID_MAX,
                       NULL, 0 ),

   REG_DYNAMIC_VARIABLE( CFG_LINK_SPEED_RSSI_LOW, WLAN_PARAM_SignedInteger,
>>>>>>> d97af3b... add prima wlan driver
=======
 REG_DYNAMIC_VARIABLE( CFG_LINK_SPEED_RSSI_LOW, WLAN_PARAM_SignedInteger,
>>>>>>> 657b0e9... prima update
                       hdd_config_t, linkSpeedRssiLow,
                       VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                       CFG_LINK_SPEED_RSSI_LOW_DEFAULT,
                       CFG_LINK_SPEED_RSSI_LOW_MIN,
                       CFG_LINK_SPEED_RSSI_LOW_MAX,
                       NULL, 0 ),
<<<<<<< HEAD

<<<<<<< HEAD
#ifdef WLAN_FEATURE_P2P
 REG_VARIABLE( CFG_P2P_DEVICE_ADDRESS_ADMINISTRATED_NAME, WLAN_PARAM_Integer,
              hdd_config_t, isP2pDeviceAddrAdministrated,
              VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
              CFG_P2P_DEVICE_ADDRESS_ADMINISTRATED_DEFAULT,
              CFG_P2P_DEVICE_ADDRESS_ADMINISTRATED_MIN,
              CFG_P2P_DEVICE_ADDRESS_ADMINISTRATED_MAX ),
#endif

REG_VARIABLE( CFG_ENABLE_MCC_ENABLED_NAME, WLAN_PARAM_Integer,
             hdd_config_t, enableMCC, 
             VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
             CFG_ENABLE_MCC_ENABLED_DEFAULT, 
             CFG_ENABLE_MCC_ENABLED_MIN, 
             CFG_ENABLE_MCC_ENABLED_MAX ),

REG_VARIABLE( CFG_ALLOW_MCC_GO_DIFF_BI_NAME, WLAN_PARAM_Integer, 
             hdd_config_t, allowMCCGODiffBI,
             VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
             CFG_ALLOW_MCC_GO_DIFF_BI_DEFAULT, 
             CFG_ALLOW_MCC_GO_DIFF_BI_MIN, 
             CFG_ALLOW_MCC_GO_DIFF_BI_MAX ),             

 REG_VARIABLE( CFG_THERMAL_MIGRATION_ENABLE_NAME, WLAN_PARAM_Integer,
              hdd_config_t, thermalMitigationEnable, 
              VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
              CFG_THERMAL_MIGRATION_ENABLE_DEFAULT, 
              CFG_THERMAL_MIGRATION_ENABLE_MIN, 
              CFG_THERMAL_MIGRATION_ENABLE_MAX ),
#ifdef WLAN_FEATURE_PACKET_FILTERING
 REG_VARIABLE( CFG_MC_ADDR_LIST_FILTER_NAME, WLAN_PARAM_Integer,
              hdd_config_t, isMcAddrListFilter,
              VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
              CFG_MC_ADDR_LIST_FILTER_DEFAULT,
              CFG_MC_ADDR_LIST_FILTER_MIN,
              CFG_MC_ADDR_LIST_FILTER_MAX ),
#endif
  
REG_VARIABLE( CFG_ENABLE_MODULATED_DTIM_NAME, WLAN_PARAM_Integer,
              hdd_config_t, enableModulatedDTIM, 
              VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
              CFG_ENABLE_MODULATED_DTIM_DEFAULT, 
              CFG_ENABLE_MODULATED_DTIM_MIN, 
              CFG_ENABLE_MODULATED_DTIM_MAX ),

 REG_VARIABLE( CFG_MC_ADDR_LIST_ENABLE_NAME, WLAN_PARAM_Integer,
              hdd_config_t, fEnableMCAddrList,
              VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
              CFG_MC_ADDR_LIST_ENABLE_DEFAULT,
              CFG_MC_ADDR_LIST_ENABLE_MIN,
              CFG_MC_ADDR_LIST_ENABLE_MAX ),

#ifdef WLAN_FEATURE_11AC              
REG_VARIABLE( CFG_VHT_CHANNEL_WIDTH, WLAN_PARAM_Integer,
              hdd_config_t, vhtChannelWidth, 
              VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK, 
              CFG_VHT_CHANNEL_WIDTH_DEFAULT, 
              CFG_VHT_CHANNEL_WIDTH_MIN, 
              CFG_VHT_CHANNEL_WIDTH_MAX),

REG_VARIABLE( CFG_VHT_ENABLE_RX_MCS_8_9, WLAN_PARAM_Integer,
              hdd_config_t, vhtRxMCS, 
              VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK, 
              CFG_VHT_ENABLE_RX_MCS_8_9_DEFAULT, 
              CFG_VHT_ENABLE_RX_MCS_8_9_MIN, 
              CFG_VHT_ENABLE_RX_MCS_8_9_MAX),

REG_VARIABLE( CFG_VHT_ENABLE_TX_MCS_8_9, WLAN_PARAM_Integer,
              hdd_config_t, vhtTxMCS, 
              VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK, 
              CFG_VHT_ENABLE_TX_MCS_8_9_DEFAULT, 
              CFG_VHT_ENABLE_TX_MCS_8_9_MIN, 
              CFG_VHT_ENABLE_TX_MCS_8_9_MAX),
#endif

REG_VARIABLE( CFG_ENABLE_FIRST_SCAN_2G_ONLY_NAME, WLAN_PARAM_Integer,
              hdd_config_t, enableFirstScan2GOnly, 
              VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
              CFG_ENABLE_FIRST_SCAN_2G_ONLY_DEFAULT, 
              CFG_ENABLE_FIRST_SCAN_2G_ONLY_MIN, 
              CFG_ENABLE_FIRST_SCAN_2G_ONLY_MAX ),

REG_VARIABLE( CFG_ENABLE_SKIP_DFS_IN_P2P_SEARCH_NAME, WLAN_PARAM_Integer,
              hdd_config_t, skipDfsChnlInP2pSearch, 
              VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
              CFG_ENABLE_SKIP_DFS_IN_P2P_SEARCH_DEFAULT, 
              CFG_ENABLE_SKIP_DFS_IN_P2P_SEARCH_MIN, 
              CFG_ENABLE_SKIP_DFS_IN_P2P_SEARCH_MAX ),

REG_VARIABLE( CFG_IGNORE_DYNAMIC_DTIM_IN_P2P_MODE_NAME, WLAN_PARAM_Integer,
              hdd_config_t, ignoreDynamicDtimInP2pMode, 
              VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
              CFG_IGNORE_DYNAMIC_DTIM_IN_P2P_MODE_DEFAULT, 
              CFG_IGNORE_DYNAMIC_DTIM_IN_P2P_MODE_MIN, 
              CFG_IGNORE_DYNAMIC_DTIM_IN_P2P_MODE_MAX ),


 REG_VARIABLE( CFG_ENABLE_IGNORE_CHAN165, WLAN_PARAM_Integer,
              hdd_config_t, ignore_chan165, 
              VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
              CFG_ENABLE_IGNORE_CHAN165_DEFAULT, 
              CFG_ENABLE_IGNORE_CHAN165_MIN, 
              CFG_ENABLE_IGNORE_CHAN165_MAX ),              
=======
#if  defined (WLAN_FEATURE_VOWIFI_11R) || defined (FEATURE_WLAN_CCX) || defined(FEATURE_WLAN_LFR)
   REG_DYNAMIC_VARIABLE( CFG_ROAM_PREFER_5GHZ, WLAN_PARAM_Integer,
                       hdd_config_t, nRoamPrefer5GHz,
                       VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                       CFG_ROAM_PREFER_5GHZ_DEFAULT,
                       CFG_ROAM_PREFER_5GHZ_MIN,
                       CFG_ROAM_PREFER_5GHZ_MAX,
                       cbNotifySetRoamPrefer5GHz, 0 ),

   REG_DYNAMIC_VARIABLE( CFG_ROAM_INTRA_BAND, WLAN_PARAM_Integer,
                       hdd_config_t, nRoamIntraBand,
                       VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                       CFG_ROAM_INTRA_BAND_DEFAULT,
                       CFG_ROAM_INTRA_BAND_MIN,
                       CFG_ROAM_INTRA_BAND_MAX,
                       cbNotifySetRoamIntraBand, 0 ),

 REG_DYNAMIC_VARIABLE( CFG_ROAM_SCAN_N_PROBES, WLAN_PARAM_Integer,
                       hdd_config_t, nProbes,
                       VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                       CFG_ROAM_SCAN_N_PROBES_DEFAULT,
                       CFG_ROAM_SCAN_N_PROBES_MIN,
                       CFG_ROAM_SCAN_N_PROBES_MAX,
                       cbNotifySetRoamScanNProbes, 0 ),

 REG_DYNAMIC_VARIABLE( CFG_ROAM_SCAN_HOME_AWAY_TIME, WLAN_PARAM_Integer,
                       hdd_config_t, nRoamScanHomeAwayTime,
                       VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                       CFG_ROAM_SCAN_HOME_AWAY_TIME_DEFAULT,
                       CFG_ROAM_SCAN_HOME_AWAY_TIME_MIN,
                       CFG_ROAM_SCAN_HOME_AWAY_TIME_MAX,
                       cbNotifySetRoamScanHomeAwayTime, 0 ),

#endif

   REG_VARIABLE( CFG_P2P_DEVICE_ADDRESS_ADMINISTRATED_NAME, WLAN_PARAM_Integer,
              hdd_config_t, isP2pDeviceAddrAdministrated,
              VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
              CFG_P2P_DEVICE_ADDRESS_ADMINISTRATED_DEFAULT,
              CFG_P2P_DEVICE_ADDRESS_ADMINISTRATED_MIN,
              CFG_P2P_DEVICE_ADDRESS_ADMINISTRATED_MAX ),

   REG_VARIABLE( CFG_ENABLE_MCC_ENABLED_NAME, WLAN_PARAM_Integer,
             hdd_config_t, enableMCC,
             VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
             CFG_ENABLE_MCC_ENABLED_DEFAULT,
             CFG_ENABLE_MCC_ENABLED_MIN,
             CFG_ENABLE_MCC_ENABLED_MAX ),

   REG_VARIABLE( CFG_ALLOW_MCC_GO_DIFF_BI_NAME, WLAN_PARAM_Integer,
             hdd_config_t, allowMCCGODiffBI,
             VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
             CFG_ALLOW_MCC_GO_DIFF_BI_DEFAULT,
             CFG_ALLOW_MCC_GO_DIFF_BI_MIN,
             CFG_ALLOW_MCC_GO_DIFF_BI_MAX ),

   REG_VARIABLE( CFG_THERMAL_MIGRATION_ENABLE_NAME, WLAN_PARAM_Integer,
              hdd_config_t, thermalMitigationEnable,
              VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
              CFG_THERMAL_MIGRATION_ENABLE_DEFAULT,
              CFG_THERMAL_MIGRATION_ENABLE_MIN,
              CFG_THERMAL_MIGRATION_ENABLE_MAX ),

   REG_VARIABLE( CFG_ENABLE_MODULATED_DTIM_NAME, WLAN_PARAM_Integer,
              hdd_config_t, enableModulatedDTIM,
              VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
              CFG_ENABLE_MODULATED_DTIM_DEFAULT,
              CFG_ENABLE_MODULATED_DTIM_MIN,
              CFG_ENABLE_MODULATED_DTIM_MAX ),

   REG_VARIABLE( CFG_MC_ADDR_LIST_ENABLE_NAME, WLAN_PARAM_Integer,
              hdd_config_t, fEnableMCAddrList,
              VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
              CFG_MC_ADDR_LIST_ENABLE_DEFAULT,
              CFG_MC_ADDR_LIST_ENABLE_MIN,
              CFG_MC_ADDR_LIST_ENABLE_MAX ),

#ifdef WLAN_FEATURE_11AC
   REG_VARIABLE( CFG_VHT_CHANNEL_WIDTH, WLAN_PARAM_Integer,
              hdd_config_t, vhtChannelWidth,
              VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK,
              CFG_VHT_CHANNEL_WIDTH_DEFAULT,
              CFG_VHT_CHANNEL_WIDTH_MIN,
              CFG_VHT_CHANNEL_WIDTH_MAX),

   REG_VARIABLE( CFG_VHT_ENABLE_RX_MCS_8_9, WLAN_PARAM_Integer,
              hdd_config_t, vhtRxMCS,
              VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK,
              CFG_VHT_ENABLE_RX_MCS_8_9_DEFAULT,
              CFG_VHT_ENABLE_RX_MCS_8_9_MIN,
              CFG_VHT_ENABLE_RX_MCS_8_9_MAX),

   REG_VARIABLE( CFG_VHT_ENABLE_TX_MCS_8_9, WLAN_PARAM_Integer,
              hdd_config_t, vhtTxMCS,
              VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK,
              CFG_VHT_ENABLE_TX_MCS_8_9_DEFAULT,
              CFG_VHT_ENABLE_TX_MCS_8_9_MIN,
              CFG_VHT_ENABLE_TX_MCS_8_9_MAX),
#endif

   REG_VARIABLE( CFG_ENABLE_FIRST_SCAN_2G_ONLY_NAME, WLAN_PARAM_Integer,
              hdd_config_t, enableFirstScan2GOnly,
              VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
              CFG_ENABLE_FIRST_SCAN_2G_ONLY_DEFAULT,
              CFG_ENABLE_FIRST_SCAN_2G_ONLY_MIN,
              CFG_ENABLE_FIRST_SCAN_2G_ONLY_MAX ),

   REG_VARIABLE( CFG_ENABLE_SKIP_DFS_IN_P2P_SEARCH_NAME, WLAN_PARAM_Integer,
              hdd_config_t, skipDfsChnlInP2pSearch,
              VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
              CFG_ENABLE_SKIP_DFS_IN_P2P_SEARCH_DEFAULT,
              CFG_ENABLE_SKIP_DFS_IN_P2P_SEARCH_MIN,
              CFG_ENABLE_SKIP_DFS_IN_P2P_SEARCH_MAX ),

   REG_VARIABLE( CFG_IGNORE_DYNAMIC_DTIM_IN_P2P_MODE_NAME, WLAN_PARAM_Integer,
              hdd_config_t, ignoreDynamicDtimInP2pMode,
              VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
              CFG_IGNORE_DYNAMIC_DTIM_IN_P2P_MODE_DEFAULT,
              CFG_IGNORE_DYNAMIC_DTIM_IN_P2P_MODE_MIN,
              CFG_IGNORE_DYNAMIC_DTIM_IN_P2P_MODE_MAX ),

   REG_VARIABLE( CFG_NUM_BUFF_ADVERT_NAME, WLAN_PARAM_Integer,
              hdd_config_t,numBuffAdvert ,
              VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK,
              CFG_NUM_BUFF_ADVERT_DEFAULT,
              CFG_NUM_BUFF_ADVERT_MIN,
              CFG_NUM_BUFF_ADVERT_MAX ),

   REG_VARIABLE( CFG_MCC_CONFIG_PARAM_NAME, WLAN_PARAM_Integer,
             hdd_config_t, configMccParam,
             VAR_FLAGS_OPTIONAL,
             CFG_MCC_CONFIG_PARAM_DEFAULT,
             CFG_MCC_CONFIG_PARAM_MIN,
             CFG_MCC_CONFIG_PARAM_MAX ),
   REG_VARIABLE( CFG_ENABLE_RX_STBC, WLAN_PARAM_Integer,
              hdd_config_t, enableRxSTBC,
              VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
              CFG_ENABLE_RX_STBC_DEFAULT,
              CFG_ENABLE_RX_STBC_MIN,
              CFG_ENABLE_RX_STBC_MAX ),
#ifdef FEATURE_WLAN_TDLS
   REG_VARIABLE( CFG_TDLS_SUPPORT_ENABLE, WLAN_PARAM_Integer,
              hdd_config_t, fEnableTDLSSupport,
              VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
              CFG_TDLS_SUPPORT_ENABLE_DEFAULT,
              CFG_TDLS_SUPPORT_ENABLE_MIN,
              CFG_TDLS_SUPPORT_ENABLE_MAX ),

   REG_VARIABLE( CFG_TDLS_IMPLICIT_TRIGGER, WLAN_PARAM_Integer,
              hdd_config_t, fEnableTDLSImplicitTrigger,
              VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
              CFG_TDLS_IMPLICIT_TRIGGER_DEFAULT,
              CFG_TDLS_IMPLICIT_TRIGGER_MIN,
              CFG_TDLS_IMPLICIT_TRIGGER_MAX ),

   REG_VARIABLE( CFG_TDLS_TX_STATS_PERIOD, WLAN_PARAM_Integer,
              hdd_config_t, fTDLSTxStatsPeriod,
              VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
              CFG_TDLS_TX_STATS_PERIOD_DEFAULT,
              CFG_TDLS_TX_STATS_PERIOD_MIN,
              CFG_TDLS_TX_STATS_PERIOD_MAX ),

   REG_VARIABLE( CFG_TDLS_TX_PACKET_THRESHOLD, WLAN_PARAM_Integer,
              hdd_config_t, fTDLSTxPacketThreshold,
              VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
              CFG_TDLS_TX_PACKET_THRESHOLD_DEFAULT,
              CFG_TDLS_TX_PACKET_THRESHOLD_MIN,
              CFG_TDLS_TX_PACKET_THRESHOLD_MAX ),

   REG_VARIABLE( CFG_TDLS_DISCOVERY_PERIOD, WLAN_PARAM_Integer,
              hdd_config_t, fTDLSDiscoveryPeriod,
              VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
              CFG_TDLS_DISCOVERY_PERIOD_DEFAULT,
              CFG_TDLS_DISCOVERY_PERIOD_MIN,
              CFG_TDLS_DISCOVERY_PERIOD_MAX ),

   REG_VARIABLE( CFG_TDLS_MAX_DISCOVERY_ATTEMPT, WLAN_PARAM_Integer,
              hdd_config_t, fTDLSMaxDiscoveryAttempt,
              VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
              CFG_TDLS_MAX_DISCOVERY_ATTEMPT_DEFAULT,
              CFG_TDLS_MAX_DISCOVERY_ATTEMPT_MIN,
              CFG_TDLS_MAX_DISCOVERY_ATTEMPT_MAX ),

   REG_VARIABLE( CFG_TDLS_IDLE_TIMEOUT, WLAN_PARAM_Integer,
              hdd_config_t, fTDLSIdleTimeout,
              VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
              CFG_TDLS_IDLE_TIMEOUT_DEFAULT,
              CFG_TDLS_IDLE_TIMEOUT_MIN,
              CFG_TDLS_IDLE_TIMEOUT_MAX ),

   REG_VARIABLE( CFG_TDLS_IDLE_PACKET_THRESHOLD, WLAN_PARAM_Integer,
              hdd_config_t, fTDLSIdlePacketThreshold,
              VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
              CFG_TDLS_IDLE_PACKET_THRESHOLD_DEFAULT,
              CFG_TDLS_IDLE_PACKET_THRESHOLD_MIN,
              CFG_TDLS_IDLE_PACKET_THRESHOLD_MAX ),

   REG_VARIABLE( CFG_TDLS_RSSI_HYSTERESIS, WLAN_PARAM_Integer,
              hdd_config_t, fTDLSRSSIHysteresis,
              VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
              CFG_TDLS_RSSI_HYSTERESIS_DEFAULT,
              CFG_TDLS_RSSI_HYSTERESIS_MIN,
              CFG_TDLS_RSSI_HYSTERESIS_MAX ),

   REG_VARIABLE( CFG_TDLS_RSSI_TRIGGER_THRESHOLD, WLAN_PARAM_SignedInteger,
              hdd_config_t, fTDLSRSSITriggerThreshold,
              VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
              CFG_TDLS_RSSI_TRIGGER_THRESHOLD_DEFAULT,
              CFG_TDLS_RSSI_TRIGGER_THRESHOLD_MIN,
              CFG_TDLS_RSSI_TRIGGER_THRESHOLD_MAX ),

   REG_VARIABLE( CFG_TDLS_RSSI_TEARDOWN_THRESHOLD, WLAN_PARAM_SignedInteger,
              hdd_config_t, fTDLSRSSITeardownThreshold,
              VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
              CFG_TDLS_RSSI_TEARDOWN_THRESHOLD_DEFAULT,
              CFG_TDLS_RSSI_TEARDOWN_THRESHOLD_MIN,
              CFG_TDLS_RSSI_TEARDOWN_THRESHOLD_MAX ),

REG_VARIABLE( CFG_TDLS_QOS_WMM_UAPSD_MASK_NAME , WLAN_PARAM_HexInteger,
                 hdd_config_t, fTDLSUapsdMask,
                 VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
                 CFG_TDLS_QOS_WMM_UAPSD_MASK_DEFAULT,
                 CFG_TDLS_QOS_WMM_UAPSD_MASK_MIN,
                 CFG_TDLS_QOS_WMM_UAPSD_MASK_MAX ),

REG_VARIABLE( CFG_TDLS_BUFFER_STA_SUPPORT_ENABLE, WLAN_PARAM_Integer,
              hdd_config_t, fEnableTDLSBufferSta,
              VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
              CFG_TDLS_BUFFER_STA_SUPPORT_ENABLE_DEFAULT,
              CFG_TDLS_BUFFER_STA_SUPPORT_ENABLE_MIN,
              CFG_TDLS_BUFFER_STA_SUPPORT_ENABLE_MAX ),

REG_VARIABLE( CFG_TDLS_PUAPSD_INACTIVITY_TIME, WLAN_PARAM_Integer,
              hdd_config_t, fTDLSPuapsdInactivityTimer,
              VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
              CFG_TDLS_PUAPSD_INACTIVITY_TIME_DEFAULT,
              CFG_TDLS_PUAPSD_INACTIVITY_TIME_MIN,
              CFG_TDLS_PUAPSD_INACTIVITY_TIME_MAX ),

REG_VARIABLE( CFG_TDLS_PUAPSD_RX_FRAME_THRESHOLD, WLAN_PARAM_Integer,
              hdd_config_t, fTDLSRxFrameThreshold,
              VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
              CFG_TDLS_PUAPSD_RX_FRAME_THRESHOLD_DEFAULT,
              CFG_TDLS_PUAPSD_RX_FRAME_THRESHOLD_MIN,
              CFG_TDLS_PUAPSD_RX_FRAME_THRESHOLD_MAX ),
#endif

#ifdef WLAN_SOFTAP_VSTA_FEATURE
   REG_VARIABLE( CFG_VSTA_SUPPORT_ENABLE, WLAN_PARAM_Integer,
              hdd_config_t, fEnableVSTASupport,
              VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
              CFG_VSTA_SUPPORT_ENABLE_DEFAULT,
              CFG_VSTA_SUPPORT_ENABLE_MIN,
              CFG_VSTA_SUPPORT_ENABLE_MAX ),
#endif
   REG_VARIABLE( CFG_ENABLE_LPWR_IMG_TRANSITION_NAME, WLAN_PARAM_Integer,
             hdd_config_t, enableLpwrImgTransition,
             VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
             CFG_ENABLE_LPWR_IMG_TRANSITION_DEFAULT,
             CFG_ENABLE_LPWR_IMG_TRANSITION_MIN,
             CFG_ENABLE_LPWR_IMG_TRANSITION_MAX ),

#ifdef WLAN_ACTIVEMODE_OFFLOAD_FEATURE
   REG_VARIABLE( CFG_ACTIVEMODE_OFFLOAD_ENABLE, WLAN_PARAM_Integer,
              hdd_config_t, fEnableActiveModeOffload,
              VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
              CFG_ACTIVEMODE_OFFLOAD_ENABLE_DEFAULT,
              CFG_ACTIVEMODE_OFFLOAD_ENABLE_MIN,
              CFG_ACTIVEMODE_OFFLOAD_ENABLE_MAX ),
#endif
   REG_VARIABLE( CFG_ENABLE_LPWR_IMG_TRANSITION_NAME, WLAN_PARAM_Integer,
             hdd_config_t, enableLpwrImgTransition,
             VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
             CFG_ENABLE_LPWR_IMG_TRANSITION_DEFAULT,
             CFG_ENABLE_LPWR_IMG_TRANSITION_MIN,
             CFG_ENABLE_LPWR_IMG_TRANSITION_MAX ),


   REG_VARIABLE( CFG_SCAN_AGING_PARAM_NAME, WLAN_PARAM_Integer,
             hdd_config_t, scanAgingTimeout,
             VAR_FLAGS_OPTIONAL,
             CFG_SCAN_AGING_PARAM_DEFAULT,
             CFG_SCAN_AGING_PARAM_MIN,
             CFG_SCAN_AGING_PARAM_MAX ),

   REG_VARIABLE( CFG_TX_LDPC_ENABLE_FEATURE, WLAN_PARAM_Integer,
              hdd_config_t, enableTxLdpc,
              VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
              CFG_TX_LDPC_ENABLE_FEATURE_DEFAULT,
              CFG_TX_LDPC_ENABLE_FEATURE_MIN,
              CFG_TX_LDPC_ENABLE_FEATURE_MAX ),

   REG_VARIABLE( CFG_ENABLE_MCC_ADATIVE_SCHEDULER_ENABLED_NAME, WLAN_PARAM_Integer,
             hdd_config_t, enableMCCAdaptiveScheduler,
             VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
             CFG_ENABLE_MCC_ADATIVE_SCHEDULER_ENABLED_DEFAULT,
             CFG_ENABLE_MCC_ADATIVE_SCHEDULER_ENABLED_MIN,
             CFG_ENABLE_MCC_ADATIVE_SCHEDULER_ENABLED_MAX ),

   REG_VARIABLE( CFG_ANDRIOD_POWER_SAVE_NAME, WLAN_PARAM_Integer,
              hdd_config_t, isAndroidPsEn,
              VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
              CFG_ANDRIOD_POWER_SAVE_DEFAULT,
              CFG_ANDRIOD_POWER_SAVE_MIN,
              CFG_ANDRIOD_POWER_SAVE_MAX),

   REG_VARIABLE( CFG_IBSS_ADHOC_CHANNEL_5GHZ_NAME, WLAN_PARAM_Integer,
              hdd_config_t, AdHocChannel5G,
              VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
              CFG_IBSS_ADHOC_CHANNEL_5GHZ_DEFAULT,
              CFG_IBSS_ADHOC_CHANNEL_5GHZ_MIN,
              CFG_IBSS_ADHOC_CHANNEL_5GHZ_MAX),
=======
>>>>>>> 657b0e9... prima update

#ifdef WLAN_FEATURE_P2P
 REG_VARIABLE( CFG_P2P_DEVICE_ADDRESS_ADMINISTRATED_NAME, WLAN_PARAM_Integer,
              hdd_config_t, isP2pDeviceAddrAdministrated,
              VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
              CFG_P2P_DEVICE_ADDRESS_ADMINISTRATED_DEFAULT,
              CFG_P2P_DEVICE_ADDRESS_ADMINISTRATED_MIN,
              CFG_P2P_DEVICE_ADDRESS_ADMINISTRATED_MAX ),
#endif

REG_VARIABLE( CFG_ENABLE_MCC_ENABLED_NAME, WLAN_PARAM_Integer,
             hdd_config_t, enableMCC, 
             VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
             CFG_ENABLE_MCC_ENABLED_DEFAULT, 
             CFG_ENABLE_MCC_ENABLED_MIN, 
             CFG_ENABLE_MCC_ENABLED_MAX ),

REG_VARIABLE( CFG_ALLOW_MCC_GO_DIFF_BI_NAME, WLAN_PARAM_Integer, 
             hdd_config_t, allowMCCGODiffBI,
             VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
             CFG_ALLOW_MCC_GO_DIFF_BI_DEFAULT, 
             CFG_ALLOW_MCC_GO_DIFF_BI_MIN, 
             CFG_ALLOW_MCC_GO_DIFF_BI_MAX ),             

 REG_VARIABLE( CFG_THERMAL_MIGRATION_ENABLE_NAME, WLAN_PARAM_Integer,
              hdd_config_t, thermalMitigationEnable, 
              VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
              CFG_THERMAL_MIGRATION_ENABLE_DEFAULT, 
              CFG_THERMAL_MIGRATION_ENABLE_MIN, 
              CFG_THERMAL_MIGRATION_ENABLE_MAX ),
#ifdef WLAN_FEATURE_PACKET_FILTERING
 REG_VARIABLE( CFG_MC_ADDR_LIST_FILTER_NAME, WLAN_PARAM_Integer,
              hdd_config_t, isMcAddrListFilter,
              VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
              CFG_MC_ADDR_LIST_FILTER_DEFAULT,
              CFG_MC_ADDR_LIST_FILTER_MIN,
              CFG_MC_ADDR_LIST_FILTER_MAX ),
#endif
  
REG_VARIABLE( CFG_ENABLE_MODULATED_DTIM_NAME, WLAN_PARAM_Integer,
              hdd_config_t, enableModulatedDTIM, 
              VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
              CFG_ENABLE_MODULATED_DTIM_DEFAULT, 
              CFG_ENABLE_MODULATED_DTIM_MIN, 
              CFG_ENABLE_MODULATED_DTIM_MAX ),

 REG_VARIABLE( CFG_MC_ADDR_LIST_ENABLE_NAME, WLAN_PARAM_Integer,
              hdd_config_t, fEnableMCAddrList,
              VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT,
              CFG_MC_ADDR_LIST_ENABLE_DEFAULT,
              CFG_MC_ADDR_LIST_ENABLE_MIN,
              CFG_MC_ADDR_LIST_ENABLE_MAX ),

#ifdef WLAN_FEATURE_11AC              
REG_VARIABLE( CFG_VHT_CHANNEL_WIDTH, WLAN_PARAM_Integer,
              hdd_config_t, vhtChannelWidth, 
              VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK, 
              CFG_VHT_CHANNEL_WIDTH_DEFAULT, 
              CFG_VHT_CHANNEL_WIDTH_MIN, 
              CFG_VHT_CHANNEL_WIDTH_MAX),

REG_VARIABLE( CFG_VHT_ENABLE_RX_MCS_8_9, WLAN_PARAM_Integer,
              hdd_config_t, vhtRxMCS, 
              VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK, 
              CFG_VHT_ENABLE_RX_MCS_8_9_DEFAULT, 
              CFG_VHT_ENABLE_RX_MCS_8_9_MIN, 
              CFG_VHT_ENABLE_RX_MCS_8_9_MAX),

REG_VARIABLE( CFG_VHT_ENABLE_TX_MCS_8_9, WLAN_PARAM_Integer,
              hdd_config_t, vhtTxMCS, 
              VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK, 
              CFG_VHT_ENABLE_TX_MCS_8_9_DEFAULT, 
              CFG_VHT_ENABLE_TX_MCS_8_9_MIN, 
              CFG_VHT_ENABLE_TX_MCS_8_9_MAX),
#endif

REG_VARIABLE( CFG_ENABLE_FIRST_SCAN_2G_ONLY_NAME, WLAN_PARAM_Integer,
              hdd_config_t, enableFirstScan2GOnly, 
              VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
              CFG_ENABLE_FIRST_SCAN_2G_ONLY_DEFAULT, 
              CFG_ENABLE_FIRST_SCAN_2G_ONLY_MIN, 
              CFG_ENABLE_FIRST_SCAN_2G_ONLY_MAX ),

REG_VARIABLE( CFG_ENABLE_SKIP_DFS_IN_P2P_SEARCH_NAME, WLAN_PARAM_Integer,
              hdd_config_t, skipDfsChnlInP2pSearch, 
              VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
              CFG_ENABLE_SKIP_DFS_IN_P2P_SEARCH_DEFAULT, 
              CFG_ENABLE_SKIP_DFS_IN_P2P_SEARCH_MIN, 
              CFG_ENABLE_SKIP_DFS_IN_P2P_SEARCH_MAX ),

REG_VARIABLE( CFG_IGNORE_DYNAMIC_DTIM_IN_P2P_MODE_NAME, WLAN_PARAM_Integer,
              hdd_config_t, ignoreDynamicDtimInP2pMode, 
              VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
              CFG_IGNORE_DYNAMIC_DTIM_IN_P2P_MODE_DEFAULT, 
              CFG_IGNORE_DYNAMIC_DTIM_IN_P2P_MODE_MIN, 
              CFG_IGNORE_DYNAMIC_DTIM_IN_P2P_MODE_MAX ),


<<<<<<< HEAD
>>>>>>> d97af3b... add prima wlan driver
=======
 REG_VARIABLE( CFG_ENABLE_IGNORE_CHAN165, WLAN_PARAM_Integer,
              hdd_config_t, ignore_chan165, 
              VAR_FLAGS_OPTIONAL | VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT, 
              CFG_ENABLE_IGNORE_CHAN165_DEFAULT, 
              CFG_ENABLE_IGNORE_CHAN165_MIN, 
              CFG_ENABLE_IGNORE_CHAN165_MAX ),              
>>>>>>> 657b0e9... prima update
};

/*
 * This function returns a pointer to the character after the occurence
 * of a new line character. It also modifies the original string by replacing
 * the '\n' character with the null character.
 * Function returns NULL if no new line character was found before end of
 * string was reached
 */
static char* get_next_line(char* str)
{
  char c;

  if( str == NULL || *str == '\0') {
    return NULL;
  }

  c = *str;
<<<<<<< HEAD
<<<<<<< HEAD
  while(c != '\n'  && c != '\0' && c != 0xd)  { 
=======
  while(c != '\n'  && c != '\0' && c != 0xd)  {
>>>>>>> d97af3b... add prima wlan driver
=======
  while(c != '\n'  && c != '\0' && c != 0xd)  { 
>>>>>>> 657b0e9... prima update
    str = str + 1;
    c = *str;
  }

  if (c == '\0' ) {
    return NULL;
  }
  else
  {
<<<<<<< HEAD
<<<<<<< HEAD
    *str = '\0'; 
=======
    *str = '\0';
>>>>>>> d97af3b... add prima wlan driver
=======
    *str = '\0'; 
>>>>>>> 657b0e9... prima update
    return (str+1);
  }

  return NULL;
}

// look for space. Ascii values to look are -
// 0x09 == horizontal tab
// 0x0a == Newline ("\n")
// 0x0b == vertical tab
// 0x0c == Newpage or feed form.
// 0x0d == carriage return (CR or "\r")
// Null ('\0') should not considered as space.
#define i_isspace(ch)  (((ch) >= 0x09 && (ch) <= 0x0d) || (ch) == ' ')

/*
 * This function trims any leading and trailing white spaces
 */
static char *i_trim(char *str)

{
   char *ptr;

   if(*str == '\0') return str;

   /* Find the first non white-space*/
   for (ptr = str; i_isspace(*ptr); ptr++);
      if (*ptr == '\0')
         return str;

   /* This is the new start of the string*/
   str = ptr;

   /* Find the last non white-space */
   ptr += strlen(ptr) - 1;
   for (; ptr != str && i_isspace(*ptr); ptr--);
      /* Null terminate the following character */
      ptr[1] = '\0';
<<<<<<< HEAD
<<<<<<< HEAD
                                  
=======

>>>>>>> d97af3b... add prima wlan driver
=======
                                  
>>>>>>> 657b0e9... prima update
   return str;
}


//Structure to store each entry in qcom_cfg.ini file
typedef struct
{
   char *name;
   char *value;
}tCfgIniEntry;

<<<<<<< HEAD
<<<<<<< HEAD
static VOS_STATUS hdd_apply_cfg_ini( hdd_context_t * pHddCtx, 
    tCfgIniEntry* iniTable, unsigned long entries);

#ifdef WLAN_CFG_DEBUG
void dump_cfg_ini (tCfgIniEntry* iniTable, unsigned long entries) 
=======
static VOS_STATUS hdd_apply_cfg_ini( hdd_context_t * pHddCtx,
    tCfgIniEntry* iniTable, unsigned long entries);

#ifdef WLAN_CFG_DEBUG
void dump_cfg_ini (tCfgIniEntry* iniTable, unsigned long entries)
>>>>>>> d97af3b... add prima wlan driver
=======
static VOS_STATUS hdd_apply_cfg_ini( hdd_context_t * pHddCtx, 
    tCfgIniEntry* iniTable, unsigned long entries);

#ifdef WLAN_CFG_DEBUG
void dump_cfg_ini (tCfgIniEntry* iniTable, unsigned long entries) 
>>>>>>> 657b0e9... prima update
{
   unsigned long i;

   for (i = 0; i < entries; i++) {
<<<<<<< HEAD
<<<<<<< HEAD
       VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "%s entry Name=[%s] value=[%s]", 
           WLAN_INI_FILE, iniTable[i].name, iniTable[i].value);
     }
}
#endif 
=======
       VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "%s entry Name=[%s] value=[%s]",
           WLAN_INI_FILE, iniTable[i].name, iniTable[i].value);
     }
}
#endif
>>>>>>> d97af3b... add prima wlan driver
=======
       VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "%s entry Name=[%s] value=[%s]", 
           WLAN_INI_FILE, iniTable[i].name, iniTable[i].value);
     }
}
#endif 
>>>>>>> 657b0e9... prima update

/*
 * This function reads the qcom_cfg.ini file and
 * parses each 'Name=Value' pair in the ini file
 */
VOS_STATUS hdd_parse_config_ini(hdd_context_t* pHddCtx)
{
   int status, i=0;
   /** Pointer for firmware image data */
   const struct firmware *fw = NULL;
<<<<<<< HEAD
<<<<<<< HEAD
   char *buffer, *line,*pTemp;
=======
   char *buffer, *line, *pTemp = NULL;
>>>>>>> d97af3b... add prima wlan driver
=======
   char *buffer, *line,*pTemp;
>>>>>>> 657b0e9... prima update
   size_t size;
   char *name, *value;
   /* cfgIniTable is static to avoid excess stack usage */
   static tCfgIniEntry cfgIniTable[MAX_CFG_INI_ITEMS];
   VOS_STATUS vos_status = VOS_STATUS_SUCCESS;

   memset(cfgIniTable, 0, sizeof(cfgIniTable));

   status = request_firmware(&fw, WLAN_INI_FILE, pHddCtx->parent_dev);
<<<<<<< HEAD
<<<<<<< HEAD
   
   if(status)
   {
      hddLog(VOS_TRACE_LEVEL_FATAL, "%s: request_firmware failed %d\n",__FUNCTION__, status);
      return VOS_STATUS_E_FAILURE;   
   }
   if(!fw || !fw->data || !fw->size) 
   {
      hddLog(VOS_TRACE_LEVEL_FATAL, "%s: %s download failed\n",
             __FUNCTION__, WLAN_INI_FILE);
      return VOS_STATUS_E_FAILURE;
   } 

   hddLog(LOG1, "%s: qcom_cfg.ini Size %d\n",__FUNCTION__, fw->size);

   buffer = (char*)vos_mem_malloc(fw->size);
   
   if(NULL == buffer) {
      hddLog(VOS_TRACE_LEVEL_FATAL, "%s: kmalloc failure",__FUNCTION__);
      release_firmware(fw);
      return VOS_STATUS_E_FAILURE;
   } 
=======

=======
   
>>>>>>> 657b0e9... prima update
   if(status)
   {
      hddLog(VOS_TRACE_LEVEL_FATAL, "%s: request_firmware failed %d\n",__FUNCTION__, status);
      return VOS_STATUS_E_FAILURE;   
   }
   if(!fw || !fw->data || !fw->size) 
   {
      hddLog(VOS_TRACE_LEVEL_FATAL, "%s: %s download failed\n",
             __FUNCTION__, WLAN_INI_FILE);
      return VOS_STATUS_E_FAILURE;
   } 

   hddLog(LOG1, "%s: qcom_cfg.ini Size %d\n",__FUNCTION__, fw->size);

   buffer = (char*)vos_mem_malloc(fw->size);
   
   if(NULL == buffer) {
      hddLog(VOS_TRACE_LEVEL_FATAL, "%s: kmalloc failure",__FUNCTION__);
      release_firmware(fw);
      return VOS_STATUS_E_FAILURE;
<<<<<<< HEAD
   }
>>>>>>> d97af3b... add prima wlan driver
=======
   } 
>>>>>>> 657b0e9... prima update
   pTemp = buffer;

   vos_mem_copy((void*)buffer,(void *)fw->data, fw->size);
   size = fw->size;
<<<<<<< HEAD
<<<<<<< HEAD
  
=======

>>>>>>> d97af3b... add prima wlan driver
=======
  
>>>>>>> 657b0e9... prima update
   while (buffer != NULL)
   {
      line = get_next_line(buffer);
      buffer = i_trim(buffer);

      hddLog(LOG1, "%s: item", buffer);

      if(strlen((char*)buffer) == 0 || *buffer == '#')  {
         buffer = line;
         continue;
      }
      else if(strncmp(buffer, "END", 3) == 0 ) {
         break;
      }
      else
      {
         name = buffer;
<<<<<<< HEAD
<<<<<<< HEAD
         while(*buffer != '=' && *buffer != '\0') 
=======
         while(*buffer != '=' && *buffer != '\0')
>>>>>>> d97af3b... add prima wlan driver
=======
         while(*buffer != '=' && *buffer != '\0') 
>>>>>>> 657b0e9... prima update
            buffer++;
         if(*buffer != '\0') {
            *buffer++ = '\0';
            i_trim(name);
            if(strlen (name) != 0) {
               buffer = i_trim(buffer);
               if(strlen(buffer)>0) {
                  value = buffer;
<<<<<<< HEAD
<<<<<<< HEAD
                  while(!i_isspace(*buffer) && *buffer != '\0') 
=======
                  while(!i_isspace(*buffer) && *buffer != '\0')
>>>>>>> d97af3b... add prima wlan driver
=======
                  while(!i_isspace(*buffer) && *buffer != '\0') 
>>>>>>> 657b0e9... prima update
                     buffer++;
                  *buffer = '\0';
                  cfgIniTable[i].name= name;
                  cfgIniTable[i++].value= value;
                  if(i >= MAX_CFG_INI_ITEMS) {
                     hddLog(LOGE,"%s: Number of items in %s > %d \n",
<<<<<<< HEAD
<<<<<<< HEAD
                        __FUNCTION__, WLAN_INI_FILE, MAX_CFG_INI_ITEMS);
=======
                        __func__, WLAN_INI_FILE, MAX_CFG_INI_ITEMS);
>>>>>>> d97af3b... add prima wlan driver
=======
                        __FUNCTION__, WLAN_INI_FILE, MAX_CFG_INI_ITEMS);
>>>>>>> 657b0e9... prima update
                     break;
                  }
               }
            }
         }
      }
      buffer = line;
   }

   //Loop through the registry table and apply all these configs
   vos_status = hdd_apply_cfg_ini(pHddCtx, cfgIniTable, i);

<<<<<<< HEAD
<<<<<<< HEAD
   release_firmware(fw);
   vos_mem_free(pTemp);
   return vos_status;
} 
=======
config_exit:
   release_firmware(fw);
   vos_mem_free(pTemp);
   return vos_status;
}
>>>>>>> d97af3b... add prima wlan driver
=======
   release_firmware(fw);
   vos_mem_free(pTemp);
   return vos_status;
} 
>>>>>>> 657b0e9... prima update


static void print_hdd_cfg(hdd_context_t *pHddCtx)
{
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "*********Config values in HDD Adapter*******");
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [RTSThreshold] Value = %lu",pHddCtx->cfg_ini->RTSThreshold) ;
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [OperatingChannel] Value = [%u]",pHddCtx->cfg_ini->OperatingChannel);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [PowerUsageControl] Value = [%s]",pHddCtx->cfg_ini->PowerUsageControl);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [fIsImpsEnabled] Value = [%u]",pHddCtx->cfg_ini->fIsImpsEnabled);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [AutoBmpsTimerEnabled] Value = [%u]",pHddCtx->cfg_ini->fIsAutoBmpsTimerEnabled);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [nAutoBmpsTimerValue] Value = [%lu]",pHddCtx->cfg_ini->nAutoBmpsTimerValue);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [nVccRssiTrigger] Value = [%u]",pHddCtx->cfg_ini->nVccRssiTrigger);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [gIbssBssid] Value =[0x%x 0x%x 0x%x 0x%x 0x%x 0x%x]",
      pHddCtx->cfg_ini->IbssBssid.bytes[0],pHddCtx->cfg_ini->IbssBssid.bytes[1],
      pHddCtx->cfg_ini->IbssBssid.bytes[2],pHddCtx->cfg_ini->IbssBssid.bytes[3],
      pHddCtx->cfg_ini->IbssBssid.bytes[4],pHddCtx->cfg_ini->IbssBssid.bytes[5]);

<<<<<<< HEAD
<<<<<<< HEAD
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, 
=======
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH,
>>>>>>> d97af3b... add prima wlan driver
=======
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, 
>>>>>>> 657b0e9... prima update
          "Name = [Intf0MacAddress] Value =[0x%x 0x%x 0x%x 0x%x 0x%x 0x%x]",
                                  pHddCtx->cfg_ini->intfMacAddr[0].bytes[0],
                                  pHddCtx->cfg_ini->intfMacAddr[0].bytes[1],
                                  pHddCtx->cfg_ini->intfMacAddr[0].bytes[2],
                                  pHddCtx->cfg_ini->intfMacAddr[0].bytes[3],
                                  pHddCtx->cfg_ini->intfMacAddr[0].bytes[4],
                                  pHddCtx->cfg_ini->intfMacAddr[0].bytes[5]);


<<<<<<< HEAD
<<<<<<< HEAD
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, 
=======
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH,
>>>>>>> d97af3b... add prima wlan driver
=======
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, 
>>>>>>> 657b0e9... prima update
          "Name = [Intf1MacAddress] Value =[0x%x 0x%x 0x%x 0x%x 0x%x 0x%x]",
                                  pHddCtx->cfg_ini->intfMacAddr[1].bytes[0],
                                  pHddCtx->cfg_ini->intfMacAddr[1].bytes[1],
                                  pHddCtx->cfg_ini->intfMacAddr[1].bytes[2],
                                  pHddCtx->cfg_ini->intfMacAddr[1].bytes[3],
                                  pHddCtx->cfg_ini->intfMacAddr[1].bytes[4],
                                  pHddCtx->cfg_ini->intfMacAddr[1].bytes[5]);

<<<<<<< HEAD
<<<<<<< HEAD
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, 
=======
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH,
>>>>>>> d97af3b... add prima wlan driver
=======
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, 
>>>>>>> 657b0e9... prima update
          "Name = [Intf2MacAddress] Value =[0x%x 0x%x 0x%x 0x%x 0x%x 0x%x]",
                                  pHddCtx->cfg_ini->intfMacAddr[2].bytes[0],
                                  pHddCtx->cfg_ini->intfMacAddr[2].bytes[1],
                                  pHddCtx->cfg_ini->intfMacAddr[2].bytes[2],
                                  pHddCtx->cfg_ini->intfMacAddr[2].bytes[3],
                                  pHddCtx->cfg_ini->intfMacAddr[2].bytes[4],
                                  pHddCtx->cfg_ini->intfMacAddr[2].bytes[5]);

<<<<<<< HEAD
<<<<<<< HEAD
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, 
=======
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH,
>>>>>>> d97af3b... add prima wlan driver
=======
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, 
>>>>>>> 657b0e9... prima update
          "Name = [Intf3MacAddress] Value =[0x%x 0x%x 0x%x 0x%x 0x%x 0x%x]",
                                  pHddCtx->cfg_ini->intfMacAddr[3].bytes[0],
                                  pHddCtx->cfg_ini->intfMacAddr[3].bytes[1],
                                  pHddCtx->cfg_ini->intfMacAddr[3].bytes[2],
                                  pHddCtx->cfg_ini->intfMacAddr[3].bytes[3],
                                  pHddCtx->cfg_ini->intfMacAddr[3].bytes[4],
                                  pHddCtx->cfg_ini->intfMacAddr[3].bytes[5]);

<<<<<<< HEAD
<<<<<<< HEAD
#ifdef WLAN_SOFTAP_FEATURE
=======
>>>>>>> d97af3b... add prima wlan driver
=======
#ifdef WLAN_SOFTAP_FEATURE
>>>>>>> 657b0e9... prima update

  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [gApEnableUapsd] value = [%u]\n",pHddCtx->cfg_ini->apUapsdEnabled);

  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [gAPCntryCode] Value =[%c%c%c]\n",
      pHddCtx->cfg_ini->apCntryCode[0],pHddCtx->cfg_ini->apCntryCode[1],
      pHddCtx->cfg_ini->apCntryCode[2]);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [gEnableApProt] value = [%u]", pHddCtx->cfg_ini->apProtEnabled);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [gAPAutoShutOff] Value = [%u]\n", pHddCtx->cfg_ini->nAPAutoShutOff);

<<<<<<< HEAD
<<<<<<< HEAD
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [gEnableListenMode] Value = [%u]\n", pHddCtx->cfg_ini->nEnableListenMode);  
  VOS_TRACE (VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [gApProtection] value = [%u]\n",pHddCtx->cfg_ini->apProtection);
  VOS_TRACE (VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [gEnableApOBSSProt] value = [%u]\n",pHddCtx->cfg_ini->apOBSSProtEnabled);
  VOS_TRACE (VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [gApAutoChannelSelection] value = [%u]\n",pHddCtx->cfg_ini->apAutoChannelSelection);
#endif
  
=======
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [gEnableListenMode] Value = [%u]\n", pHddCtx->cfg_ini->nEnableListenMode);
  VOS_TRACE (VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [gApProtection] value = [%u]\n",pHddCtx->cfg_ini->apProtection);
  VOS_TRACE (VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [gEnableApOBSSProt] value = [%u]\n",pHddCtx->cfg_ini->apOBSSProtEnabled);
  VOS_TRACE (VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [gApAutoChannelSelection] value = [%u]\n",pHddCtx->cfg_ini->apAutoChannelSelection);

>>>>>>> d97af3b... add prima wlan driver
=======
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [gEnableListenMode] Value = [%u]\n", pHddCtx->cfg_ini->nEnableListenMode);  
  VOS_TRACE (VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [gApProtection] value = [%u]\n",pHddCtx->cfg_ini->apProtection);
  VOS_TRACE (VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [gEnableApOBSSProt] value = [%u]\n",pHddCtx->cfg_ini->apOBSSProtEnabled);
  VOS_TRACE (VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [gApAutoChannelSelection] value = [%u]\n",pHddCtx->cfg_ini->apAutoChannelSelection);
#endif
  
>>>>>>> 657b0e9... prima update
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [ChannelBondingMode] Value = [%lu]",pHddCtx->cfg_ini->nChannelBondingMode24GHz);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [ChannelBondingMode] Value = [%lu]",pHddCtx->cfg_ini->nChannelBondingMode5GHz);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [dot11Mode] Value = [%lu]",pHddCtx->cfg_ini->dot11Mode);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [WmmMode] Value = [%u] ",pHddCtx->cfg_ini->WmmMode);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [UapsdMask] Value = [0x%x] ",pHddCtx->cfg_ini->UapsdMask);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [PktClassificationBasis] Value = [%u] ",pHddCtx->cfg_ini->PktClassificationBasis);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [ImplicitQosIsEnabled] Value = [%u]",(int)pHddCtx->cfg_ini->bImplicitQosEnabled);

  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [InfraUapsdVoSrvIntv] Value = [%lu] ",pHddCtx->cfg_ini->InfraUapsdVoSrvIntv);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [InfraUapsdVoSuspIntv] Value = [%lu] ",pHddCtx->cfg_ini->InfraUapsdVoSuspIntv);

  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [InfraUapsdViSrvIntv] Value = [%lu] ",pHddCtx->cfg_ini->InfraUapsdViSrvIntv);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [InfraUapsdViSuspIntv] Value = [%lu] ",pHddCtx->cfg_ini->InfraUapsdViSuspIntv);

  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [InfraUapsdBeSrvIntv] Value = [%lu] ",pHddCtx->cfg_ini->InfraUapsdBeSrvIntv);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [InfraUapsdBeSuspIntv] Value = [%lu] ",pHddCtx->cfg_ini->InfraUapsdBeSuspIntv);

  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [InfraUapsdBkSrvIntv] Value = [%lu] ",pHddCtx->cfg_ini->InfraUapsdBkSrvIntv);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [InfraUapsdBkSuspIntv] Value = [%lu] ",pHddCtx->cfg_ini->InfraUapsdBkSuspIntv);
#ifdef FEATURE_WLAN_CCX
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [InfraInactivityInterval] Value = [%lu] ",pHddCtx->cfg_ini->InfraInactivityInterval);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [CcxEnabled] Value = [%lu] ",pHddCtx->cfg_ini->isCcxIniFeatureEnabled);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [FastTransitionEnabled] Value = [%lu] ",pHddCtx->cfg_ini->isFastTransitionEnabled);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [gTxPowerCap] Value = [%lu] dBm ",pHddCtx->cfg_ini->nTxPowerCap);
<<<<<<< HEAD
<<<<<<< HEAD
#endif 
#ifdef FEATURE_WLAN_LFR
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [FastRoamEnabled] Value = [%lu] ",pHddCtx->cfg_ini->isFastRoamIniFeatureEnabled);
#endif 
#if  defined (WLAN_FEATURE_VOWIFI_11R) || defined (FEATURE_WLAN_CCX) || defined(FEATURE_WLAN_LFR)
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [RoamRssiDiff] Value = [%lu] ",pHddCtx->cfg_ini->RoamRssiDiff);
=======
#endif
=======
#endif 
>>>>>>> 657b0e9... prima update
#ifdef FEATURE_WLAN_LFR
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [FastRoamEnabled] Value = [%lu] ",pHddCtx->cfg_ini->isFastRoamIniFeatureEnabled);
#endif 
#if  defined (WLAN_FEATURE_VOWIFI_11R) || defined (FEATURE_WLAN_CCX) || defined(FEATURE_WLAN_LFR)
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [RoamRssiDiff] Value = [%lu] ",pHddCtx->cfg_ini->RoamRssiDiff);
<<<<<<< HEAD
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [ImmediateRoamRssiDiff] Value = [%lu] ",pHddCtx->cfg_ini->nImmediateRoamRssiDiff);
#endif
#ifdef FEATURE_WLAN_OKC
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [OkcEnabled] Value = [%lu] ",pHddCtx->cfg_ini->isOkcIniFeatureEnabled);
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
#endif
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [InfraDirAcVo] Value = [%u] ",pHddCtx->cfg_ini->InfraDirAcVo);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [InfraNomMsduSizeAcVo] Value = [0x%x] ",pHddCtx->cfg_ini->InfraNomMsduSizeAcVo);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [InfraMeanDataRateAcVo] Value = [0x%lx] ",pHddCtx->cfg_ini->InfraMeanDataRateAcVo);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [InfraMinPhyRateAcVo] Value = [0x%lx] ",pHddCtx->cfg_ini->InfraMinPhyRateAcVo);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [InfraSbaAcVo] Value = [0x%x] ",pHddCtx->cfg_ini->InfraSbaAcVo);

  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [InfraDirAcVi] Value = [%u] ",pHddCtx->cfg_ini->InfraDirAcVi);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [InfraNomMsduSizeAcVi] Value = [0x%x] ",pHddCtx->cfg_ini->InfraNomMsduSizeAcVi);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [InfraMeanDataRateAcVi] Value = [0x%lx] ",pHddCtx->cfg_ini->InfraMeanDataRateAcVi);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [InfraMinPhyRateAcVi] Value = [0x%lx] ",pHddCtx->cfg_ini->InfraMinPhyRateAcVi);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [InfraSbaAcVi] Value = [0x%x] ",pHddCtx->cfg_ini->InfraSbaAcVi);

  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [InfraDirAcBe] Value = [%u] ",pHddCtx->cfg_ini->InfraDirAcBe);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [InfraNomMsduSizeAcBe] Value = [0x%x] ",pHddCtx->cfg_ini->InfraNomMsduSizeAcBe);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [InfraMeanDataRateAcBe] Value = [0x%lx] ",pHddCtx->cfg_ini->InfraMeanDataRateAcBe);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [InfraMinPhyRateAcBe] Value = [0x%lx] ",pHddCtx->cfg_ini->InfraMinPhyRateAcBe);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [InfraSbaAcBe] Value = [0x%x] ",pHddCtx->cfg_ini->InfraSbaAcBe);

  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [InfraDirAcBk] Value = [%u] ",pHddCtx->cfg_ini->InfraDirAcBk);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [InfraNomMsduSizeAcBk] Value = [0x%x] ",pHddCtx->cfg_ini->InfraNomMsduSizeAcBk);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [InfraMeanDataRateAcBk] Value = [0x%lx] ",pHddCtx->cfg_ini->InfraMeanDataRateAcBk);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [InfraMinPhyRateAcBk] Value = [0x%lx] ",pHddCtx->cfg_ini->InfraMinPhyRateAcBk);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [InfraSbaAcBk] Value = [0x%x] ",pHddCtx->cfg_ini->InfraSbaAcBk);

  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [WfqBkWeight] Value = [%u] ",pHddCtx->cfg_ini->WfqBkWeight);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [WfqBeWeight] Value = [%u] ",pHddCtx->cfg_ini->WfqBeWeight);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [WfqViWeight] Value = [%u] ",pHddCtx->cfg_ini->WfqViWeight);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [WfqVoWeight] Value = [%u] ",pHddCtx->cfg_ini->WfqVoWeight);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [DelayedTriggerFrmInt] Value = [%lu] ",pHddCtx->cfg_ini->DelayedTriggerFrmInt);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [mcastBcastFilterSetting] Value = [%u] ",pHddCtx->cfg_ini->mcastBcastFilterSetting);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [fhostArpOffload] Value = [%u] ",pHddCtx->cfg_ini->fhostArpOffload);
<<<<<<< HEAD
<<<<<<< HEAD
#ifdef WLAN_FEATURE_VOWIFI_11R  
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [fFTEnable] Value = [%lu] ",pHddCtx->cfg_ini->fFTEnable);
=======
#ifdef WLAN_FEATURE_VOWIFI_11R
>>>>>>> d97af3b... add prima wlan driver
=======
#ifdef WLAN_FEATURE_VOWIFI_11R  
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [fFTEnable] Value = [%lu] ",pHddCtx->cfg_ini->fFTEnable);
>>>>>>> 657b0e9... prima update
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [fFTResourceReqSupported] Value = [%lu] ",pHddCtx->cfg_ini->fFTResourceReqSupported);
#endif

#ifdef WLAN_FEATURE_NEIGHBOR_ROAMING
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [nNeighborReassocRssiThreshold] Value = [%lu] ",pHddCtx->cfg_ini->nNeighborReassocRssiThreshold);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [nNeighborLookupRssiThreshold] Value = [%lu] ",pHddCtx->cfg_ini->nNeighborLookupRssiThreshold);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [nNeighborScanMinChanTime] Value = [%lu] ",pHddCtx->cfg_ini->nNeighborScanMinChanTime);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [nNeighborScanMaxChanTime] Value = [%lu] ",pHddCtx->cfg_ini->nNeighborScanMaxChanTime);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [nMaxNeighborRetries] Value = [%lu] ",pHddCtx->cfg_ini->nMaxNeighborReqTries);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [nNeighborScanPeriod] Value = [%lu] ",pHddCtx->cfg_ini->nNeighborScanPeriod);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [nNeighborScanResultsRefreshPeriod] Value = [%lu] ",pHddCtx->cfg_ini->nNeighborResultsRefreshPeriod);
<<<<<<< HEAD
<<<<<<< HEAD
=======
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [nEmptyScanRefreshPeriod] Value = [%lu] ",pHddCtx->cfg_ini->nEmptyScanRefreshPeriod);
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
#endif
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [burstSizeDefinition] Value = [0x%x] ",pHddCtx->cfg_ini->burstSizeDefinition);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [tsInfoAckPolicy] Value = [0x%x] ",pHddCtx->cfg_ini->tsInfoAckPolicy);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [rfSettlingTimeUs] Value = [%u] ",pHddCtx->cfg_ini->rfSettlingTimeUs);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [bSingleTidRc] Value = [%u] ",pHddCtx->cfg_ini->bSingleTidRc);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [gDynamicPSPollvalue] Value = [%u] ",pHddCtx->cfg_ini->dynamicPsPollValue);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [gAddTSWhenACMIsOff] Value = [%u] ",pHddCtx->cfg_ini->AddTSWhenACMIsOff);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [gValidateScanList] Value = [%u] ",pHddCtx->cfg_ini->fValidateScanList);

  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [gStaKeepAlivePeriod] Value = [%u] ",pHddCtx->cfg_ini->infraStaKeepAlivePeriod);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [gApDataAvailPollInterVal] Value = [%u] ",pHddCtx->cfg_ini->apDataAvailPollPeriodInMs);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [gEnableBtAmp] Value = [%u] ",pHddCtx->cfg_ini->enableBtAmp);
#ifdef WLAN_BTAMP_FEATURE
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [BtAmpPreferredChannel] Value = [%u] ",pHddCtx->cfg_ini->preferredChannel);
#endif //WLAN_BTAMP_FEATURE
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [BandCapability] Value = [%u] ",pHddCtx->cfg_ini->nBandCapability);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [fEnableBeaconEarlyTermination] Value = [%u] ",pHddCtx->cfg_ini->fEnableBeaconEarlyTermination);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [teleBcnWakeupEnable] Value = [%u] ",pHddCtx->cfg_ini->teleBcnWakeupEn);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [transListenInterval] Value = [%u] ",pHddCtx->cfg_ini->nTeleBcnTransListenInterval);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [transLiNumIdleBeacons] Value = [%u] ",pHddCtx->cfg_ini->nTeleBcnTransLiNumIdleBeacons);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [maxListenInterval] Value = [%u] ",pHddCtx->cfg_ini->nTeleBcnMaxListenInterval);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [maxLiNumIdleBeacons] Value = [%u] ",pHddCtx->cfg_ini->nTeleBcnMaxLiNumIdleBeacons);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [bcnEarlyTermWakeInterval] Value = [%u] ",pHddCtx->cfg_ini->bcnEarlyTermWakeInterval);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [gApDataAvailPollInterVal] Value = [%u] ",pHddCtx->cfg_ini->apDataAvailPollPeriodInMs);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [gEnableBypass11d] Value = [%u] ",pHddCtx->cfg_ini->enableBypass11d);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [gEnableDFSChnlScan] Value = [%u] ",pHddCtx->cfg_ini->enableDFSChnlScan);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [gReportMaxLinkSpeed] Value = [%u] ",pHddCtx->cfg_ini->reportMaxLinkSpeed);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [thermalMitigationEnable] Value = [%u] ",pHddCtx->cfg_ini->thermalMitigationEnable);
#ifdef WLAN_FEATURE_11AC
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [gVhtChannelWidth] value = [%u]\n",pHddCtx->cfg_ini->vhtChannelWidth);
#endif
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [enableFirstScan2GOnly] Value = [%u] ",pHddCtx->cfg_ini->enableFirstScan2GOnly);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [skipDfsChnlInP2pSearch] Value = [%u] ",pHddCtx->cfg_ini->skipDfsChnlInP2pSearch);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [ignoreDynamicDtimInP2pMode] Value = [%u] ",pHddCtx->cfg_ini->ignoreDynamicDtimInP2pMode);
<<<<<<< HEAD
<<<<<<< HEAD
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [gIgnore_Chan165] Value = [%u] ",pHddCtx->cfg_ini->ignore_chan165);
}


=======
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [enableRxSTBC] Value = [%u] ",pHddCtx->cfg_ini->enableRxSTBC);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [gEnableLpwrImgTransition] Value = [%u] ",pHddCtx->cfg_ini->enableLpwrImgTransition);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [gEnableSSR] Value = [%u] ",pHddCtx->cfg_ini->enableSSR);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [gEnableVhtFor24GHzBand] Value = [%u] ",pHddCtx->cfg_ini->enableVhtFor24GHzBand);

  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [gEnableTrafficMonitor] Value = [%u] ", pHddCtx->cfg_ini->enableTrafficMonitor);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [gTrafficIdleTimeout] Value = [%u] ", pHddCtx->cfg_ini->trafficIdleTimeout);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [gFlexConnectPowerFactor] Value = [%u] ", pHddCtx->cfg_ini->flexConnectPowerFactor);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [gEnableIbssHeartBeatOffload] Value = [%u] ", pHddCtx->cfg_ini->enableIbssHeartBeatOffload);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [gAntennaDiversity] Value = [%u] ", pHddCtx->cfg_ini->antennaDiversity);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [gGoLinkMonitorPeriod] Value = [%u]",pHddCtx->cfg_ini->goLinkMonitorPeriod);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [gApLinkMonitorPeriod] Value = [%u]",pHddCtx->cfg_ini->apLinkMonitorPeriod);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [gGoKeepAlivePeriod] Value = [%u]",pHddCtx->cfg_ini->goKeepAlivePeriod);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [gApKeepAlivePeriod]Value = [%u]",pHddCtx->cfg_ini->apKeepAlivePeriod);
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [gAmsduSupportInAMPDU] Value = [%lu] ",pHddCtx->cfg_ini->isAmsduSupportInAMPDU);

}



>>>>>>> d97af3b... add prima wlan driver
=======
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Name = [gIgnore_Chan165] Value = [%u] ",pHddCtx->cfg_ini->ignore_chan165);
}


>>>>>>> 657b0e9... prima update
#define CFG_VALUE_MAX_LEN 256
#define CFG_ENTRY_MAX_LEN (32+CFG_VALUE_MAX_LEN)
VOS_STATUS hdd_cfg_get_config(hdd_context_t *pHddCtx, char *pBuf, int buflen)
{
   unsigned int idx;
   REG_TABLE_ENTRY *pRegEntry = g_registry_table;
   unsigned long cRegTableEntries  = sizeof(g_registry_table) / sizeof( g_registry_table[ 0 ]);
   v_U32_t value;
   char valueStr[CFG_VALUE_MAX_LEN];
   char configStr[CFG_ENTRY_MAX_LEN];
   char *fmt;
   void *pField;
   v_MACADDR_t *pMacAddr;
   char *pCur = pBuf;
   int curlen;

   // start with an empty string
   *pCur = '\0';

<<<<<<< HEAD
<<<<<<< HEAD
   for ( idx = 0; idx < cRegTableEntries; idx++, pRegEntry++ ) 
=======
   for ( idx = 0; idx < cRegTableEntries; idx++, pRegEntry++ )
>>>>>>> d97af3b... add prima wlan driver
=======
   for ( idx = 0; idx < cRegTableEntries; idx++, pRegEntry++ ) 
>>>>>>> 657b0e9... prima update
   {
      pField = ( (v_U8_t *)pHddCtx->cfg_ini) + pRegEntry->VarOffset;

      if ( ( WLAN_PARAM_Integer       == pRegEntry->RegType ) ||
           ( WLAN_PARAM_SignedInteger == pRegEntry->RegType ) ||
<<<<<<< HEAD
<<<<<<< HEAD
           ( WLAN_PARAM_HexInteger    == pRegEntry->RegType ) ) 
=======
           ( WLAN_PARAM_HexInteger    == pRegEntry->RegType ) )
>>>>>>> d97af3b... add prima wlan driver
=======
           ( WLAN_PARAM_HexInteger    == pRegEntry->RegType ) ) 
>>>>>>> 657b0e9... prima update
      {
         value = 0;
         memcpy( &value, pField, pRegEntry->VarSize );
         if ( WLAN_PARAM_HexInteger == pRegEntry->RegType )
         {
            fmt = "%x";
         }
         else if ( WLAN_PARAM_SignedInteger == pRegEntry->RegType )
         {
            fmt = "%d";
         }
         else
         {
            fmt = "%u";
         }
         snprintf(valueStr, CFG_VALUE_MAX_LEN, fmt, value);
      }
      else if ( WLAN_PARAM_String == pRegEntry->RegType )
      {
         snprintf(valueStr, CFG_VALUE_MAX_LEN, "%s", (char *)pField);
      }
      else if ( WLAN_PARAM_MacAddr == pRegEntry->RegType )
      {
         pMacAddr = (v_MACADDR_t *) pField;
         snprintf(valueStr, CFG_VALUE_MAX_LEN,
                  "%02x:%02x:%02x:%02x:%02x:%02x",
                  pMacAddr->bytes[0],
                  pMacAddr->bytes[1],
                  pMacAddr->bytes[2],
                  pMacAddr->bytes[3],
                  pMacAddr->bytes[4],
                  pMacAddr->bytes[5]);
      }
      else
      {
         snprintf(valueStr, CFG_VALUE_MAX_LEN, "(unhandled)");
      }
<<<<<<< HEAD
<<<<<<< HEAD
      curlen = snprintf(configStr, CFG_ENTRY_MAX_LEN,
=======
      curlen = scnprintf(configStr, CFG_ENTRY_MAX_LEN,
>>>>>>> d97af3b... add prima wlan driver
=======
      curlen = snprintf(configStr, CFG_ENTRY_MAX_LEN,
>>>>>>> 657b0e9... prima update
                        "%s=[%s]%s\n",
                        pRegEntry->RegName,
                        valueStr,
                        test_bit(idx, (void *)&pHddCtx->cfg_ini->bExplicitCfg) ?
                        "*" : "");

      // ideally we want to return the config to the application
      // however the config is too big so we just printk() for now
#ifdef RETURN_IN_BUFFER
      if (curlen <= buflen)
      {
         // copy string + '\0'
         memcpy(pCur, configStr, curlen+1);

         // account for addition;
         pCur += curlen;
         buflen -= curlen;
      }
      else
      {
         // buffer space exhausted, return what we have
         return VOS_STATUS_E_RESOURCES;
      }
#else
      printk(KERN_CRIT "%s", configStr);
#endif // RETURN_IN_BUFFER

}

#ifndef RETURN_IN_BUFFER
   // notify application that output is in system log
   snprintf(pCur, buflen, "WLAN configuration written to system log");
#endif // RETURN_IN_BUFFER

   return VOS_STATUS_SUCCESS;
}

static VOS_STATUS find_cfg_item (tCfgIniEntry* iniTable, unsigned long entries,
<<<<<<< HEAD
<<<<<<< HEAD
    char *name, char** value) 
=======
    char *name, char** value)
>>>>>>> d97af3b... add prima wlan driver
=======
    char *name, char** value) 
>>>>>>> 657b0e9... prima update
{
   VOS_STATUS status = VOS_STATUS_E_FAILURE;
   unsigned long i;

   for (i = 0; i < entries; i++) {
     if (strcmp(iniTable[i].name, name) == 0) {
       *value = iniTable[i].value;
       VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "Found %s entry for Name=[%s] Value=[%s] ",
           WLAN_INI_FILE, name, *value);
       return VOS_STATUS_SUCCESS;
     }
   }

   return status;
}

static int parseHexDigit(char c)
{
  if (c >= '0' && c <= '9')
    return c-'0';
  if (c >= 'a' && c <= 'f')
    return c-'a'+10;
  if (c >= 'A' && c <= 'F')
    return c-'A'+10;

  return 0;
}


static VOS_STATUS hdd_apply_cfg_ini( hdd_context_t *pHddCtx, tCfgIniEntry* iniTable, unsigned long entries)
{
   VOS_STATUS match_status = VOS_STATUS_E_FAILURE;
   VOS_STATUS ret_status = VOS_STATUS_SUCCESS;
   unsigned int idx;
   void *pField;
   char *value_str = NULL;
   unsigned long len_value_str;
   char *candidate;
   v_U32_t value;
   v_S31_t svalue;
   void *pStructBase = pHddCtx->cfg_ini;
   REG_TABLE_ENTRY *pRegEntry = g_registry_table;
   unsigned long cRegTableEntries  = sizeof(g_registry_table) / sizeof( g_registry_table[ 0 ]);
   v_U32_t cbOutString;
   int i;
<<<<<<< HEAD
<<<<<<< HEAD
=======
   int rv;
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update

   // sanity test
   if (MAX_CFG_INI_ITEMS < cRegTableEntries)
   {
      hddLog(LOGE, "%s: MAX_CFG_INI_ITEMS too small, must be at least %d",
<<<<<<< HEAD
<<<<<<< HEAD
             __FUNCTION__, cRegTableEntries);
=======
             __func__, cRegTableEntries);
>>>>>>> d97af3b... add prima wlan driver
=======
             __FUNCTION__, cRegTableEntries);
>>>>>>> 657b0e9... prima update
   }

   for ( idx = 0; idx < cRegTableEntries; idx++, pRegEntry++ )
   {
      //Calculate the address of the destination field in the structure.
      pField = ( (v_U8_t *)pStructBase )+ pRegEntry->VarOffset;

      match_status = find_cfg_item(iniTable, entries, pRegEntry->RegName, &value_str);

      if( (match_status != VOS_STATUS_SUCCESS) && ( pRegEntry->Flags & VAR_FLAGS_REQUIRED ) )
      {
         // If we could not read the cfg item and it is required, this is an error.
         hddLog(LOGE, "%s: Failed to read required config parameter %s",
<<<<<<< HEAD
<<<<<<< HEAD
            __FUNCTION__, pRegEntry->RegName);
=======
            __func__, pRegEntry->RegName);
>>>>>>> d97af3b... add prima wlan driver
=======
            __FUNCTION__, pRegEntry->RegName);
>>>>>>> 657b0e9... prima update
         ret_status = VOS_STATUS_E_FAILURE;
         break;
      }

      if ( ( WLAN_PARAM_Integer    == pRegEntry->RegType ) ||
           ( WLAN_PARAM_HexInteger == pRegEntry->RegType ) )
      {
         // If successfully read from the registry, use the value read.
         // If not, use the default value.
         if ( match_status == VOS_STATUS_SUCCESS && (WLAN_PARAM_Integer == pRegEntry->RegType)) {
<<<<<<< HEAD
<<<<<<< HEAD
            value = simple_strtoul(value_str, NULL, 10);
         }
         else if ( match_status == VOS_STATUS_SUCCESS && (WLAN_PARAM_HexInteger == pRegEntry->RegType)) {
            value = simple_strtoul(value_str, NULL, 16);
=======
            rv = kstrtoul(value_str, 10, &value);
            if (rv < 0) {
                hddLog(LOGE, "%s: Reg Parameter %s invalid. Enforcing default",
                       __func__, pRegEntry->RegName);
                value = pRegEntry->VarDefault;
            }
         }
         else if ( match_status == VOS_STATUS_SUCCESS && (WLAN_PARAM_HexInteger == pRegEntry->RegType)) {
            rv = kstrtoul(value_str, 16, &value);
            if (rv < 0) {
                hddLog(LOGE, "%s: Reg paramter %s invalid. Enforcing default",
                       __func__, pRegEntry->RegName);
                value = pRegEntry->VarDefault;
            }
>>>>>>> d97af3b... add prima wlan driver
=======
            value = simple_strtoul(value_str, NULL, 10);
         }
         else if ( match_status == VOS_STATUS_SUCCESS && (WLAN_PARAM_HexInteger == pRegEntry->RegType)) {
            value = simple_strtoul(value_str, NULL, 16);
>>>>>>> 657b0e9... prima update
         }
         else {
            value = pRegEntry->VarDefault;
         }

         // If this parameter needs range checking, do it here.
         if ( pRegEntry->Flags & VAR_FLAGS_RANGE_CHECK )
         {
            if ( value > pRegEntry->VarMax )
            {
               hddLog(LOGE, "%s: Reg Parameter %s > allowed Maximum [%lu > %lu]. Enforcing Maximum",
<<<<<<< HEAD
<<<<<<< HEAD
                      __FUNCTION__, pRegEntry->RegName, value, pRegEntry->VarMax );
=======
                      __func__, pRegEntry->RegName, value, pRegEntry->VarMax );
>>>>>>> d97af3b... add prima wlan driver
=======
                      __FUNCTION__, pRegEntry->RegName, value, pRegEntry->VarMax );
>>>>>>> 657b0e9... prima update
               value = pRegEntry->VarMax;
            }

            if ( value < pRegEntry->VarMin )
            {
               hddLog(LOGE, "%s: Reg Parameter %s < allowed Minimum [%lu < %lu]. Enforcing Minimum",
<<<<<<< HEAD
<<<<<<< HEAD
                      __FUNCTION__, pRegEntry->RegName, value, pRegEntry->VarMin);
=======
                      __func__, pRegEntry->RegName, value, pRegEntry->VarMin);
>>>>>>> d97af3b... add prima wlan driver
=======
                      __FUNCTION__, pRegEntry->RegName, value, pRegEntry->VarMin);
>>>>>>> 657b0e9... prima update
               value = pRegEntry->VarMin;
            }
         }
         // If this parameter needs range checking, do it here.
         else if ( pRegEntry->Flags & VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT )
         {
            if ( value > pRegEntry->VarMax )
            {
               hddLog(LOGE, "%s: Reg Parameter %s > allowed Maximum [%lu > %lu]. Enforcing Default= %lu",
<<<<<<< HEAD
<<<<<<< HEAD
                  __FUNCTION__, pRegEntry->RegName, value, pRegEntry->VarMax, pRegEntry->VarDefault  );
=======
                  __func__, pRegEntry->RegName, value, pRegEntry->VarMax, pRegEntry->VarDefault  );
>>>>>>> d97af3b... add prima wlan driver
=======
                  __FUNCTION__, pRegEntry->RegName, value, pRegEntry->VarMax, pRegEntry->VarDefault  );
>>>>>>> 657b0e9... prima update
               value = pRegEntry->VarDefault;
            }

            if ( value < pRegEntry->VarMin )
            {
               hddLog(LOGE, "%s: Reg Parameter %s < allowed Minimum [%lu < %lu]. Enforcing Default= %lu",
<<<<<<< HEAD
<<<<<<< HEAD
                  __FUNCTION__, pRegEntry->RegName, value, pRegEntry->VarMin, pRegEntry->VarDefault  );
=======
                  __func__, pRegEntry->RegName, value, pRegEntry->VarMin, pRegEntry->VarDefault  );
>>>>>>> d97af3b... add prima wlan driver
=======
                  __FUNCTION__, pRegEntry->RegName, value, pRegEntry->VarMin, pRegEntry->VarDefault  );
>>>>>>> 657b0e9... prima update
               value = pRegEntry->VarDefault;
            }
         }

         // Move the variable into the output field.
         memcpy( pField, &value, pRegEntry->VarSize );
      }
      else if ( WLAN_PARAM_SignedInteger == pRegEntry->RegType )
      {
         // If successfully read from the registry, use the value read.
         // If not, use the default value.
         if (VOS_STATUS_SUCCESS == match_status)
         {
<<<<<<< HEAD
<<<<<<< HEAD
            svalue = simple_strtol(value_str, NULL, 10);
=======
            rv = kstrtol(value_str, 10, &svalue);
            if (rv < 0) {
                hddLog(VOS_TRACE_LEVEL_WARN, "%s: Reg Parameter %s invalid. Enforcing Default",
                       __func__, pRegEntry->RegName);
                svalue = (v_S31_t)pRegEntry->VarDefault;
            }
>>>>>>> d97af3b... add prima wlan driver
=======
            svalue = simple_strtol(value_str, NULL, 10);
>>>>>>> 657b0e9... prima update
         }
         else
         {
            svalue = (v_S31_t)pRegEntry->VarDefault;
         }

         // If this parameter needs range checking, do it here.
         if ( pRegEntry->Flags & VAR_FLAGS_RANGE_CHECK )
         {
            if ( svalue > (v_S31_t)pRegEntry->VarMax )
            {
               hddLog(LOGE, "%s: Reg Parameter %s > allowed Maximum "
<<<<<<< HEAD
<<<<<<< HEAD
                      "[%ld > %ld]. Enforcing Maximum", __FUNCTION__,
=======
                      "[%ld > %ld]. Enforcing Maximum", __func__,
>>>>>>> d97af3b... add prima wlan driver
=======
                      "[%ld > %ld]. Enforcing Maximum", __FUNCTION__,
>>>>>>> 657b0e9... prima update
                      pRegEntry->RegName, svalue, (int)pRegEntry->VarMax );
               svalue = (v_S31_t)pRegEntry->VarMax;
            }

            if ( svalue < (v_S31_t)pRegEntry->VarMin )
            {
               hddLog(LOGE, "%s: Reg Parameter %s < allowed Minimum "
<<<<<<< HEAD
<<<<<<< HEAD
                      "[%ld < %ld]. Enforcing Minimum",  __FUNCTION__,
=======
                      "[%ld < %ld]. Enforcing Minimum",  __func__,
>>>>>>> d97af3b... add prima wlan driver
=======
                      "[%ld < %ld]. Enforcing Minimum",  __FUNCTION__,
>>>>>>> 657b0e9... prima update
                      pRegEntry->RegName, svalue, (int)pRegEntry->VarMin);
               svalue = (v_S31_t)pRegEntry->VarMin;
            }
         }
         // If this parameter needs range checking, do it here.
         else if ( pRegEntry->Flags & VAR_FLAGS_RANGE_CHECK_ASSUME_DEFAULT )
         {
            if ( svalue > (v_S31_t)pRegEntry->VarMax )
            {
               hddLog(LOGE, "%s: Reg Parameter %s > allowed Maximum "
                      "[%ld > %ld]. Enforcing Default= %ld",
<<<<<<< HEAD
<<<<<<< HEAD
                      __FUNCTION__, pRegEntry->RegName, svalue,
=======
                      __func__, pRegEntry->RegName, svalue,
>>>>>>> d97af3b... add prima wlan driver
=======
                      __FUNCTION__, pRegEntry->RegName, svalue,
>>>>>>> 657b0e9... prima update
                      (int)pRegEntry->VarMax,
                      (int)pRegEntry->VarDefault  );
               svalue = (v_S31_t)pRegEntry->VarDefault;
            }

            if ( svalue < (v_S31_t)pRegEntry->VarMin )
            {
               hddLog(LOGE, "%s: Reg Parameter %s < allowed Minimum "
                      "[%ld < %ld]. Enforcing Default= %ld",
<<<<<<< HEAD
<<<<<<< HEAD
                      __FUNCTION__, pRegEntry->RegName, svalue,
=======
                      __func__, pRegEntry->RegName, svalue,
>>>>>>> d97af3b... add prima wlan driver
=======
                      __FUNCTION__, pRegEntry->RegName, svalue,
>>>>>>> 657b0e9... prima update
                      (int)pRegEntry->VarMin,
                      (int)pRegEntry->VarDefault);
               svalue = pRegEntry->VarDefault;
            }
         }

         // Move the variable into the output field.
         memcpy( pField, &svalue, pRegEntry->VarSize );
      }
      // Handle string parameters
      else if ( WLAN_PARAM_String == pRegEntry->RegType )
      {
#ifdef WLAN_CFG_DEBUG
         VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "RegName = %s, VarOffset %u VarSize %u VarDefault %s\n",
<<<<<<< HEAD
<<<<<<< HEAD
            pRegEntry->RegName, pRegEntry->VarOffset, pRegEntry->VarSize, (char*)pRegEntry->VarDefault); 
#endif

         if ( match_status == VOS_STATUS_SUCCESS) 
=======
            pRegEntry->RegName, pRegEntry->VarOffset, pRegEntry->VarSize, (char*)pRegEntry->VarDefault);
#endif

         if ( match_status == VOS_STATUS_SUCCESS)
>>>>>>> d97af3b... add prima wlan driver
=======
            pRegEntry->RegName, pRegEntry->VarOffset, pRegEntry->VarSize, (char*)pRegEntry->VarDefault); 
#endif

         if ( match_status == VOS_STATUS_SUCCESS) 
>>>>>>> 657b0e9... prima update
         {
            len_value_str = strlen(value_str);

            if(len_value_str > (pRegEntry->VarSize - 1)) {
<<<<<<< HEAD
<<<<<<< HEAD
               hddLog(LOGE, "%s: Invalid Value=[%s] specified for Name=[%s] in %s\n", 
                  __FUNCTION__, value_str, pRegEntry->RegName, WLAN_INI_FILE);
=======
               hddLog(LOGE, "%s: Invalid Value=[%s] specified for Name=[%s] in %s\n",
                  __func__, value_str, pRegEntry->RegName, WLAN_INI_FILE);
>>>>>>> d97af3b... add prima wlan driver
=======
               hddLog(LOGE, "%s: Invalid Value=[%s] specified for Name=[%s] in %s\n", 
                  __FUNCTION__, value_str, pRegEntry->RegName, WLAN_INI_FILE);
>>>>>>> 657b0e9... prima update
               cbOutString = utilMin( strlen( (char *)pRegEntry->VarDefault ), pRegEntry->VarSize - 1 );
               memcpy( pField, (void *)(pRegEntry->VarDefault), cbOutString );
               ( (v_U8_t *)pField )[ cbOutString ] = '\0';
            }
            else
            {
               memcpy( pField, (void *)(value_str), len_value_str);
               ( (v_U8_t *)pField )[ len_value_str ] = '\0';
            }
         }
<<<<<<< HEAD
<<<<<<< HEAD
         else 
=======
         else
>>>>>>> d97af3b... add prima wlan driver
=======
         else 
>>>>>>> 657b0e9... prima update
         {
            // Failed to read the string parameter from the registry.  Use the default.
            cbOutString = utilMin( strlen( (char *)pRegEntry->VarDefault ), pRegEntry->VarSize - 1 );
            memcpy( pField, (void *)(pRegEntry->VarDefault), cbOutString );
<<<<<<< HEAD
<<<<<<< HEAD
            ( (v_U8_t *)pField )[ cbOutString ] = '\0';                 
=======
            ( (v_U8_t *)pField )[ cbOutString ] = '\0';
>>>>>>> d97af3b... add prima wlan driver
=======
            ( (v_U8_t *)pField )[ cbOutString ] = '\0';                 
>>>>>>> 657b0e9... prima update
         }
      }
      else if ( WLAN_PARAM_MacAddr == pRegEntry->RegType )
      {
         if(pRegEntry->VarSize != VOS_MAC_ADDR_SIZE) {
<<<<<<< HEAD
<<<<<<< HEAD
               hddLog(LOGE, "%s: Invalid VarSize %u for Name=[%s]\n", 
                   __FUNCTION__, pRegEntry->VarSize, pRegEntry->RegName); 
=======
               hddLog(LOGE, "%s: Invalid VarSize %u for Name=[%s]\n",
                   __func__, pRegEntry->VarSize, pRegEntry->RegName);
>>>>>>> d97af3b... add prima wlan driver
=======
               hddLog(LOGE, "%s: Invalid VarSize %u for Name=[%s]\n", 
                   __FUNCTION__, pRegEntry->VarSize, pRegEntry->RegName); 
>>>>>>> 657b0e9... prima update
            continue;
         }
         candidate = (char*)pRegEntry->VarDefault;
         if ( match_status == VOS_STATUS_SUCCESS) {
            len_value_str = strlen(value_str);
            if(len_value_str != (VOS_MAC_ADDR_SIZE*2)) {
<<<<<<< HEAD
<<<<<<< HEAD
               hddLog(LOGE, "%s: Invalid MAC addr [%s] specified for Name=[%s] in %s\n", 
                  __FUNCTION__, value_str, pRegEntry->RegName, WLAN_INI_FILE);
=======
               hddLog(LOGE, "%s: Invalid MAC addr [%s] specified for Name=[%s] in %s\n",
                  __func__, value_str, pRegEntry->RegName, WLAN_INI_FILE);
>>>>>>> d97af3b... add prima wlan driver
=======
               hddLog(LOGE, "%s: Invalid MAC addr [%s] specified for Name=[%s] in %s\n", 
                  __FUNCTION__, value_str, pRegEntry->RegName, WLAN_INI_FILE);
>>>>>>> 657b0e9... prima update
            }
            else
               candidate = value_str;
         }
         //parse the string and store it in the byte array
         for(i=0; i<VOS_MAC_ADDR_SIZE; i++)
         {
<<<<<<< HEAD
<<<<<<< HEAD
            ((char*)pField)[i] = 
              (char)(parseHexDigit(candidate[i*2])*16 + parseHexDigit(candidate[i*2+1])); 
=======
            ((char*)pField)[i] =
              (char)(parseHexDigit(candidate[i*2])*16 + parseHexDigit(candidate[i*2+1]));
>>>>>>> d97af3b... add prima wlan driver
=======
            ((char*)pField)[i] = 
              (char)(parseHexDigit(candidate[i*2])*16 + parseHexDigit(candidate[i*2+1])); 
>>>>>>> 657b0e9... prima update
         }
      }
      else
      {
<<<<<<< HEAD
<<<<<<< HEAD
         hddLog(LOGE, "%s: Unknown param type for name[%s] in registry table\n", 
            __FUNCTION__, pRegEntry->RegName);
=======
         hddLog(LOGE, "%s: Unknown param type for name[%s] in registry table\n",
            __func__, pRegEntry->RegName);
>>>>>>> d97af3b... add prima wlan driver
=======
         hddLog(LOGE, "%s: Unknown param type for name[%s] in registry table\n", 
            __FUNCTION__, pRegEntry->RegName);
>>>>>>> 657b0e9... prima update
      }

      // did we successfully parse a cfg item for this parameter?
      if( (match_status == VOS_STATUS_SUCCESS) &&
          (idx < MAX_CFG_INI_ITEMS) )
      {
         set_bit(idx, (void *)&pHddCtx->cfg_ini->bExplicitCfg);
      }
   }

   print_hdd_cfg(pHddCtx);

  return( ret_status );
}

eCsrPhyMode hdd_cfg_xlate_to_csr_phy_mode( eHddDot11Mode dot11Mode )
{
<<<<<<< HEAD
<<<<<<< HEAD
   switch (dot11Mode) 
=======
   switch (dot11Mode)
>>>>>>> d97af3b... add prima wlan driver
=======
   switch (dot11Mode) 
>>>>>>> 657b0e9... prima update
   {
      case (eHDD_DOT11_MODE_abg):
         return eCSR_DOT11_MODE_abg;
      case (eHDD_DOT11_MODE_11b):
         return eCSR_DOT11_MODE_11b;
      case (eHDD_DOT11_MODE_11g):
         return eCSR_DOT11_MODE_11g;
      default:
      case (eHDD_DOT11_MODE_11n):
         return eCSR_DOT11_MODE_11n;
      case (eHDD_DOT11_MODE_11g_ONLY):
         return eCSR_DOT11_MODE_11g_ONLY;
      case (eHDD_DOT11_MODE_11n_ONLY):
         return eCSR_DOT11_MODE_11n_ONLY;
      case (eHDD_DOT11_MODE_11b_ONLY):
         return eCSR_DOT11_MODE_11b_ONLY;
#ifdef WLAN_FEATURE_11AC
      case (eHDD_DOT11_MODE_11ac_ONLY):
         return eCSR_DOT11_MODE_11ac_ONLY;
      case (eHDD_DOT11_MODE_11ac):
         return eCSR_DOT11_MODE_11ac;
#endif
      case (eHDD_DOT11_MODE_AUTO):
         return eCSR_DOT11_MODE_AUTO;
   }

}

<<<<<<< HEAD
<<<<<<< HEAD
static void hdd_set_btc_config(hdd_context_t *pHddCtx) 
{
   hdd_config_t *pConfig = pHddCtx->cfg_ini;
   tSmeBtcConfig btcParams;
   
=======
static void hdd_set_btc_config(hdd_context_t *pHddCtx)
{
   hdd_config_t *pConfig = pHddCtx->cfg_ini;
   tSmeBtcConfig btcParams;
   int i;

>>>>>>> d97af3b... add prima wlan driver
=======
static void hdd_set_btc_config(hdd_context_t *pHddCtx) 
{
   hdd_config_t *pConfig = pHddCtx->cfg_ini;
   tSmeBtcConfig btcParams;
   
>>>>>>> 657b0e9... prima update
   sme_BtcGetConfig(pHddCtx->hHal, &btcParams);

   btcParams.btcExecutionMode = pConfig->btcExecutionMode;
   btcParams.btcConsBtSlotsToBlockDuringDhcp = pConfig->btcConsBtSlotsToBlockDuringDhcp;
   btcParams.btcA2DPBtSubIntervalsDuringDhcp = pConfig->btcA2DPBtSubIntervalsDuringDhcp;

   btcParams.btcStaticLenInqBt = pConfig->btcStaticLenInqBt;
   btcParams.btcStaticLenPageBt = pConfig->btcStaticLenPageBt;
   btcParams.btcStaticLenConnBt = pConfig->btcStaticLenConnBt;
   btcParams.btcStaticLenLeBt = pConfig->btcStaticLenLeBt;
   btcParams.btcStaticLenInqWlan = pConfig->btcStaticLenInqWlan;
   btcParams.btcStaticLenPageWlan = pConfig->btcStaticLenPageWlan;
   btcParams.btcStaticLenConnWlan = pConfig->btcStaticLenConnWlan;
   btcParams.btcStaticLenLeWlan = pConfig->btcStaticLenLeWlan;
   btcParams.btcDynMaxLenBt = pConfig->btcDynMaxLenBt;
   btcParams.btcDynMaxLenWlan = pConfig->btcDynMaxLenWlan;
   btcParams.btcMaxScoBlockPerc = pConfig->btcMaxScoBlockPerc;
   btcParams.btcDhcpProtOnA2dp = pConfig->btcDhcpProtOnA2dp;
   btcParams.btcDhcpProtOnSco = pConfig->btcDhcpProtOnSco;

<<<<<<< HEAD
<<<<<<< HEAD
   sme_BtcSetConfig(pHddCtx->hHal, &btcParams);
}

static void hdd_set_power_save_config(hdd_context_t *pHddCtx, tSmeConfigParams *smeConfig) 
=======
   for (i = 0; i < 10; i++)
   {
      btcParams.mwsCoexVictimWANFreq[i] = pConfig->mwsCoexVictimWANFreq[i];
      btcParams.mwsCoexVictimWLANFreq[i] = pConfig->mwsCoexVictimWLANFreq[i];
      btcParams.mwsCoexVictimConfig[i] = pConfig->mwsCoexVictimConfig[i];
      btcParams.mwsCoexVictimConfig2[i] = pConfig->mwsCoexVictimConfig2[i];
   }
   for (i = 0; i < 6; i++)
   {
      btcParams.mwsCoexConfig[i] = pConfig->mwsCoexConfig[i];
   }
   btcParams.mwsCoexModemBackoff = pConfig->mwsCoexModemBackoff;
   btcParams.SARPowerBackoff = pConfig->SARPowerBackoff;

   sme_BtcSetConfig(pHddCtx->hHal, &btcParams);
}

static void hdd_set_power_save_config(hdd_context_t *pHddCtx, tSmeConfigParams *smeConfig)
>>>>>>> d97af3b... add prima wlan driver
=======
   sme_BtcSetConfig(pHddCtx->hHal, &btcParams);
}

static void hdd_set_power_save_config(hdd_context_t *pHddCtx, tSmeConfigParams *smeConfig) 
>>>>>>> 657b0e9... prima update
{
   hdd_config_t *pConfig = pHddCtx->cfg_ini;

   tPmcBmpsConfigParams bmpsParams;
<<<<<<< HEAD
<<<<<<< HEAD
   
   sme_GetConfigPowerSave(pHddCtx->hHal, ePMC_BEACON_MODE_POWER_SAVE, &bmpsParams);
   
=======

   sme_GetConfigPowerSave(pHddCtx->hHal, ePMC_BEACON_MODE_POWER_SAVE, &bmpsParams);

>>>>>>> d97af3b... add prima wlan driver
=======
   
   sme_GetConfigPowerSave(pHddCtx->hHal, ePMC_BEACON_MODE_POWER_SAVE, &bmpsParams);
   
>>>>>>> 657b0e9... prima update
   if (strcmp(pConfig->PowerUsageControl, "Min") == 0)
   {
      smeConfig->csrConfig.impsSleepTime   = pConfig->nImpsMinSleepTime;
      bmpsParams.bmpsPeriod                = pConfig->nBmpsMinListenInterval;
      bmpsParams.enableBeaconEarlyTermination = pConfig->fEnableBeaconEarlyTermination;
      bmpsParams.bcnEarlyTermWakeInterval  = pConfig->bcnEarlyTermWakeInterval;
   }
   if (strcmp(pConfig->PowerUsageControl, "Max") == 0)
   {
      smeConfig->csrConfig.impsSleepTime   = pConfig->nImpsMaxSleepTime;
      bmpsParams.bmpsPeriod                = pConfig->nBmpsMaxListenInterval;
      bmpsParams.enableBeaconEarlyTermination = pConfig->fEnableBeaconEarlyTermination;
      bmpsParams.bcnEarlyTermWakeInterval  = pConfig->bcnEarlyTermWakeInterval;
   }
   if (strcmp(pConfig->PowerUsageControl, "Mod") == 0)
   {
      smeConfig->csrConfig.impsSleepTime   = pConfig->nImpsModSleepTime;
      bmpsParams.bmpsPeriod                = pConfig->nBmpsModListenInterval;
      bmpsParams.enableBeaconEarlyTermination = pConfig->fEnableBeaconEarlyTermination;
      bmpsParams.bcnEarlyTermWakeInterval  = pConfig->bcnEarlyTermWakeInterval;
   }

   if (pConfig->fIsImpsEnabled)
   {
      sme_EnablePowerSave (pHddCtx->hHal, ePMC_IDLE_MODE_POWER_SAVE);
   }
   else
   {
      sme_DisablePowerSave (pHddCtx->hHal, ePMC_IDLE_MODE_POWER_SAVE);
   }

<<<<<<< HEAD
<<<<<<< HEAD
=======
  /*If isAndroidPsEn is 1 then Host driver and above layers control the PS mechanism
    If Value set to 0 Driver/Core Stack internally control the Power saving mechanism */
   sme_SetHostPowerSave (pHddCtx->hHal, pConfig->isAndroidPsEn);

>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
   if (pConfig->fIsBmpsEnabled)
   {
      sme_EnablePowerSave (pHddCtx->hHal, ePMC_BEACON_MODE_POWER_SAVE);
   }
   else
   {
      sme_DisablePowerSave (pHddCtx->hHal, ePMC_BEACON_MODE_POWER_SAVE);
   }

   bmpsParams.trafficMeasurePeriod = pConfig->nAutoBmpsTimerValue;

   if (sme_SetConfigPowerSave(pHddCtx->hHal, ePMC_BEACON_MODE_POWER_SAVE, &bmpsParams)== eHAL_STATUS_FAILURE)
   {
      hddLog(LOGE, "SetConfigPowerSave failed to set BMPS params\n");
   }
<<<<<<< HEAD
<<<<<<< HEAD
  
=======

>>>>>>> d97af3b... add prima wlan driver
=======
  
>>>>>>> 657b0e9... prima update
   if(pConfig->fIsAutoBmpsTimerEnabled)
   {
      sme_StartAutoBmpsTimer(pHddCtx->hHal);
   }

}

#ifdef WLAN_FEATURE_NEIGHBOR_ROAMING
static VOS_STATUS hdd_string_to_u8_array( char *str, tANI_U8 *intArray, tANI_U8 *len, tANI_U8 intArrayMaxLen )
{
   char *s = str;

   if( str == NULL || intArray == NULL || len == NULL )
   {
      return VOS_STATUS_E_INVAL;
   }
   *len = 0;

<<<<<<< HEAD
<<<<<<< HEAD
#ifdef VERSION_USING_STRPBRK
=======
>>>>>>> d97af3b... add prima wlan driver
=======
#ifdef VERSION_USING_STRPBRK
>>>>>>> 657b0e9... prima update
   while ( (s != NULL) && (*len < intArrayMaxLen) )
   {
      int val;
      //Increment length only if sscanf succesfully extracted one element.
      //Any other return value means error. Ignore it.
      if( sscanf(s, "%d", &val ) == 1 )
      {
         intArray[*len] = (tANI_U8) val;
         *len += 1;
      }
      s = strpbrk( s, "," );
      if( s )
         s++;
   }
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
#else
   while( (*s != '\0')  && (*len < intArrayMaxLen) )
   {
      unsigned long val;
<<<<<<< HEAD

      val = simple_strtoul( s, &s, 10 );
      if( val )
      {
         intArray[*len] = (tANI_U8) val;
         *len += 1;
      }
      if( *s )
         s++;
   }
#endif

   return VOS_STATUS_SUCCESS;
   
=======
=======
>>>>>>> 657b0e9... prima update

      val = simple_strtoul( s, &s, 10 );
      if( val )
      {
         intArray[*len] = (tANI_U8) val;
         *len += 1;
      }
      if( *s )
         s++;
   }
#endif

<<<<<<< HEAD
>>>>>>> d97af3b... add prima wlan driver
=======
   return VOS_STATUS_SUCCESS;
   
>>>>>>> 657b0e9... prima update
}
#endif


v_BOOL_t hdd_update_config_dat( hdd_context_t *pHddCtx )
{
   v_BOOL_t  fStatus = TRUE;
<<<<<<< HEAD
<<<<<<< HEAD

   hdd_config_t *pConfig = pHddCtx->cfg_ini;

   if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_SHORT_GI_20MHZ, 
=======
#ifdef WLAN_SOFTAP_VSTA_FEATURE
   tANI_U32 val;
#endif
=======
>>>>>>> 657b0e9... prima update

   hdd_config_t *pConfig = pHddCtx->cfg_ini;

<<<<<<< HEAD

   if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_SHORT_GI_20MHZ,
>>>>>>> d97af3b... add prima wlan driver
=======
   if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_SHORT_GI_20MHZ, 
>>>>>>> 657b0e9... prima update
      pConfig->ShortGI20MhzEnable, NULL, eANI_BOOLEAN_FALSE)==eHAL_STATUS_FAILURE)
   {
      fStatus = FALSE;
      hddLog(LOGE, "Could not pass on WNI_CFG_SHORT_GI_20MHZ to CCM\n");
   }
<<<<<<< HEAD
<<<<<<< HEAD
       
   if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_CAL_CONTROL, pConfig->Calibration, 
=======

   if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_CAL_CONTROL, pConfig->Calibration,
>>>>>>> d97af3b... add prima wlan driver
=======
       
   if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_CAL_CONTROL, pConfig->Calibration, 
>>>>>>> 657b0e9... prima update
      NULL, eANI_BOOLEAN_FALSE)==eHAL_STATUS_FAILURE)
   {
      fStatus = FALSE;
      hddLog(LOGE, "Could not pass on WNI_CFG_CAL_CONTROL to CCM\n");
   }

   if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_CAL_PERIOD, pConfig->CalibrationPeriod,
      NULL, eANI_BOOLEAN_FALSE)==eHAL_STATUS_FAILURE)
   {
      fStatus = FALSE;
      hddLog(LOGE, "Could not pass on WNI_CFG_CAL_PERIOD to CCM\n");
   }

   if ( 0 != pConfig->Cfg1Id )
   {
<<<<<<< HEAD
<<<<<<< HEAD
      if (ccmCfgSetInt(pHddCtx->hHal, pConfig->Cfg1Id, pConfig->Cfg1Value, NULL, 
=======
      if (ccmCfgSetInt(pHddCtx->hHal, pConfig->Cfg1Id, pConfig->Cfg1Value, NULL,
>>>>>>> d97af3b... add prima wlan driver
=======
      if (ccmCfgSetInt(pHddCtx->hHal, pConfig->Cfg1Id, pConfig->Cfg1Value, NULL, 
>>>>>>> 657b0e9... prima update
         eANI_BOOLEAN_FALSE)==eHAL_STATUS_FAILURE)
      {
         fStatus = FALSE;
         hddLog(LOGE, "Could not pass on Cfg1Id to CCM\n");
      }
<<<<<<< HEAD
<<<<<<< HEAD
          
=======

>>>>>>> d97af3b... add prima wlan driver
=======
          
>>>>>>> 657b0e9... prima update
   }

   if ( 0 != pConfig->Cfg2Id )
   {
<<<<<<< HEAD
<<<<<<< HEAD
      if (ccmCfgSetInt(pHddCtx->hHal, pConfig->Cfg2Id, pConfig->Cfg2Value, 
=======
      if (ccmCfgSetInt(pHddCtx->hHal, pConfig->Cfg2Id, pConfig->Cfg2Value,
>>>>>>> d97af3b... add prima wlan driver
=======
      if (ccmCfgSetInt(pHddCtx->hHal, pConfig->Cfg2Id, pConfig->Cfg2Value, 
>>>>>>> 657b0e9... prima update
         NULL, eANI_BOOLEAN_FALSE)==eHAL_STATUS_FAILURE)
      {
         fStatus = FALSE;
         hddLog(LOGE, "Could not pass on Cfg2Id to CCM\n");
      }
   }

   if ( 0 != pConfig->Cfg3Id )
   {
<<<<<<< HEAD
<<<<<<< HEAD
      if (ccmCfgSetInt(pHddCtx->hHal, pConfig->Cfg3Id, pConfig->Cfg3Value, 
=======
      if (ccmCfgSetInt(pHddCtx->hHal, pConfig->Cfg3Id, pConfig->Cfg3Value,
>>>>>>> d97af3b... add prima wlan driver
=======
      if (ccmCfgSetInt(pHddCtx->hHal, pConfig->Cfg3Id, pConfig->Cfg3Value, 
>>>>>>> 657b0e9... prima update
         NULL, eANI_BOOLEAN_FALSE)==eHAL_STATUS_FAILURE)
      {
         fStatus = FALSE;
         hddLog(LOGE, "Could not pass on Cfg3Id to CCM\n");
      }
   }

   if ( 0 != pConfig->Cfg4Id )
   {
<<<<<<< HEAD
<<<<<<< HEAD
      if (ccmCfgSetInt(pHddCtx->hHal, pConfig->Cfg4Id, pConfig->Cfg4Value, 
=======
      if (ccmCfgSetInt(pHddCtx->hHal, pConfig->Cfg4Id, pConfig->Cfg4Value,
>>>>>>> d97af3b... add prima wlan driver
=======
      if (ccmCfgSetInt(pHddCtx->hHal, pConfig->Cfg4Id, pConfig->Cfg4Value, 
>>>>>>> 657b0e9... prima update
         NULL, eANI_BOOLEAN_FALSE)==eHAL_STATUS_FAILURE)
      {
         fStatus = FALSE;
         hddLog(LOGE, "Could not pass on Cfg4Id to CCM\n");
      }
   }

   if ( 0 != pConfig->Cfg5Id )
   {
<<<<<<< HEAD
<<<<<<< HEAD
      if (ccmCfgSetInt(pHddCtx->hHal, pConfig->Cfg5Id, pConfig->Cfg5Value, 
=======
      if (ccmCfgSetInt(pHddCtx->hHal, pConfig->Cfg5Id, pConfig->Cfg5Value,
>>>>>>> d97af3b... add prima wlan driver
=======
      if (ccmCfgSetInt(pHddCtx->hHal, pConfig->Cfg5Id, pConfig->Cfg5Value, 
>>>>>>> 657b0e9... prima update
         NULL, eANI_BOOLEAN_FALSE)==eHAL_STATUS_FAILURE)
      {
         fStatus = FALSE;
         hddLog(LOGE, "Could not pass on Cfg5Id to CCM\n");
      }
   }

<<<<<<< HEAD
<<<<<<< HEAD
   if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_BA_AUTO_SETUP, pConfig->BlockAckAutoSetup, 
=======
   if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_BA_AUTO_SETUP, pConfig->BlockAckAutoSetup,
>>>>>>> d97af3b... add prima wlan driver
=======
   if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_BA_AUTO_SETUP, pConfig->BlockAckAutoSetup, 
>>>>>>> 657b0e9... prima update
      NULL, eANI_BOOLEAN_FALSE)==eHAL_STATUS_FAILURE)
   {
      fStatus = FALSE;
      hddLog(LOGE, "Could not pass on WNI_CFG_BA_AUTO_SETUP to CCM\n");
   }
<<<<<<< HEAD
<<<<<<< HEAD
       
   if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_FIXED_RATE, pConfig->TxRate, 
=======

   if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_FIXED_RATE, pConfig->TxRate,
>>>>>>> d97af3b... add prima wlan driver
=======
       
   if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_FIXED_RATE, pConfig->TxRate, 
>>>>>>> 657b0e9... prima update
      NULL, eANI_BOOLEAN_FALSE)==eHAL_STATUS_FAILURE)
   {
      fStatus = FALSE;
      hddLog(LOGE, "Could not pass on WNI_CFG_FIXED_RATE to CCM\n");
   }

<<<<<<< HEAD
<<<<<<< HEAD
   if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_MAX_RX_AMPDU_FACTOR, 
=======
   if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_MAX_RX_AMPDU_FACTOR,
>>>>>>> d97af3b... add prima wlan driver
=======
   if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_MAX_RX_AMPDU_FACTOR, 
>>>>>>> 657b0e9... prima update
      pConfig->MaxRxAmpduFactor, NULL, eANI_BOOLEAN_FALSE)==eHAL_STATUS_FAILURE)
   {
      fStatus = FALSE;
      hddLog(LOGE,"Could not pass on WNI_CFG_HT_AMPDU_PARAMS_MAX_RX_AMPDU_FACTOR to CCM\n");
   }

   if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_SHORT_PREAMBLE, pConfig->fIsShortPreamble,
      NULL, eANI_BOOLEAN_FALSE)==eHAL_STATUS_FAILURE)
   {
      fStatus = FALSE;
      hddLog(LOGE,"Could not pass on WNI_CFG_SHORT_PREAMBLE to CCM\n");
   }

<<<<<<< HEAD
<<<<<<< HEAD
   if (pConfig->fIsAutoIbssBssid) 
   {
      if (ccmCfgSetStr(pHddCtx->hHal, WNI_CFG_BSSID, (v_U8_t *)"000000000000", 
=======
   if (pConfig->fIsAutoIbssBssid)
   {
      if (ccmCfgSetStr(pHddCtx->hHal, WNI_CFG_BSSID, (v_U8_t *)"000000000000",
>>>>>>> d97af3b... add prima wlan driver
=======
   if (pConfig->fIsAutoIbssBssid) 
   {
      if (ccmCfgSetStr(pHddCtx->hHal, WNI_CFG_BSSID, (v_U8_t *)"000000000000", 
>>>>>>> 657b0e9... prima update
         sizeof(v_BYTE_t) * VOS_MAC_ADDR_SIZE, NULL, eANI_BOOLEAN_FALSE)==eHAL_STATUS_FAILURE)
      {
         fStatus = FALSE;
         hddLog(LOGE,"Could not pass on WNI_CFG_BSSID to CCM\n");
      }
   }
   else
<<<<<<< HEAD
<<<<<<< HEAD
   { 
=======
   {
>>>>>>> d97af3b... add prima wlan driver
=======
   { 
>>>>>>> 657b0e9... prima update
      if ( VOS_FALSE == vos_is_macaddr_group( &pConfig->IbssBssid ))
      {
         VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_MED,
                    "MAC Addr (IBSS BSSID) read from Registry is: %02x-%02x-%02x-%02x-%02x-%02x",
<<<<<<< HEAD
<<<<<<< HEAD
                    pConfig->IbssBssid.bytes[0], pConfig->IbssBssid.bytes[1], pConfig->IbssBssid.bytes[2], 
                    pConfig->IbssBssid.bytes[3], pConfig->IbssBssid.bytes[4], pConfig->IbssBssid.bytes[5]);
         if (ccmCfgSetStr(pHddCtx->hHal, WNI_CFG_BSSID, pConfig->IbssBssid.bytes, 
=======
                    pConfig->IbssBssid.bytes[0], pConfig->IbssBssid.bytes[1], pConfig->IbssBssid.bytes[2],
                    pConfig->IbssBssid.bytes[3], pConfig->IbssBssid.bytes[4], pConfig->IbssBssid.bytes[5]);
         if (ccmCfgSetStr(pHddCtx->hHal, WNI_CFG_BSSID, pConfig->IbssBssid.bytes,
>>>>>>> d97af3b... add prima wlan driver
=======
                    pConfig->IbssBssid.bytes[0], pConfig->IbssBssid.bytes[1], pConfig->IbssBssid.bytes[2], 
                    pConfig->IbssBssid.bytes[3], pConfig->IbssBssid.bytes[4], pConfig->IbssBssid.bytes[5]);
         if (ccmCfgSetStr(pHddCtx->hHal, WNI_CFG_BSSID, pConfig->IbssBssid.bytes, 
>>>>>>> 657b0e9... prima update
            sizeof(v_BYTE_t) * VOS_MAC_ADDR_SIZE, NULL, eANI_BOOLEAN_FALSE)==eHAL_STATUS_FAILURE)
         {
            fStatus = FALSE;
            hddLog(LOGE,"Could not pass on WNI_CFG_BSSID to CCM\n");
         }
      }
      else
      {
         fStatus = FALSE;
         hddLog(LOGE,"Could not pass on WNI_CFG_BSSID to CCM\n");
      }
   }

<<<<<<< HEAD
<<<<<<< HEAD
   if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_BEACON_INTERVAL, pConfig->nBeaconInterval, 
=======
   if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_BEACON_INTERVAL, pConfig->nBeaconInterval,
>>>>>>> d97af3b... add prima wlan driver
=======
   if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_BEACON_INTERVAL, pConfig->nBeaconInterval, 
>>>>>>> 657b0e9... prima update
      NULL, eANI_BOOLEAN_FALSE)==eHAL_STATUS_FAILURE)
   {
      fStatus = FALSE;
      hddLog(LOGE, "Could not pass on WNI_CFG_BEACON_INTERVAL to CCM\n");
   }

<<<<<<< HEAD
<<<<<<< HEAD
   if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_MAX_PS_POLL, pConfig->nMaxPsPoll, 
=======
   if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_MAX_PS_POLL, pConfig->nMaxPsPoll,
>>>>>>> d97af3b... add prima wlan driver
=======
   if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_MAX_PS_POLL, pConfig->nMaxPsPoll, 
>>>>>>> 657b0e9... prima update
      NULL, eANI_BOOLEAN_FALSE)==eHAL_STATUS_FAILURE)
   {
      fStatus = FALSE;
      hddLog(LOGE, "Could not pass on WNI_CFG_MAX_PS_POLL to CCM\n");
   }

   if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_CURRENT_RX_ANTENNA, pConfig-> nRxAnt, NULL, eANI_BOOLEAN_FALSE)==eHAL_STATUS_FAILURE)
   {
      fStatus = FALSE;
      hddLog(LOGE, "Failure: Could not pass on WNI_CFG_CURRENT_RX_ANTENNA configuration info to HAL\n"  );
   }

<<<<<<< HEAD
<<<<<<< HEAD
   if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_LOW_GAIN_OVERRIDE, pConfig->fIsLowGainOverride, 
=======
   if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_LOW_GAIN_OVERRIDE, pConfig->fIsLowGainOverride,
>>>>>>> d97af3b... add prima wlan driver
=======
   if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_LOW_GAIN_OVERRIDE, pConfig->fIsLowGainOverride, 
>>>>>>> 657b0e9... prima update
         NULL, eANI_BOOLEAN_FALSE)==eHAL_STATUS_FAILURE)
   {
      fStatus = FALSE;
      hddLog(LOGE, "Could not pass on WNI_CFG_LOW_GAIN_OVERRIDE to HAL\n");
   }
<<<<<<< HEAD
<<<<<<< HEAD
 
=======

>>>>>>> d97af3b... add prima wlan driver
=======
 
>>>>>>> 657b0e9... prima update
   if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_RSSI_FILTER_PERIOD, pConfig->nRssiFilterPeriod,
         NULL, eANI_BOOLEAN_FALSE)==eHAL_STATUS_FAILURE)
   {
      fStatus = FALSE;
      hddLog(LOGE, "Could not pass on WNI_CFG_RSSI_FILTER_PERIOD to CCM\n");
   }

<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
#if  defined (WLAN_FEATURE_VOWIFI_11R) || defined (FEATURE_WLAN_CCX) || defined(FEATURE_WLAN_LFR)
   if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_FT_RSSI_FILTER_PERIOD, pConfig->FTRssiFilterPeriod,
         NULL, eANI_BOOLEAN_FALSE)==eHAL_STATUS_FAILURE)
   {
      fStatus = FALSE;
      hddLog(LOGE, "Could not pass on WNI_CFG_FT_RSSI_FILTER_PERIOD to CCM\n");
   }
#endif

<<<<<<< HEAD
=======
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
   if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_IGNORE_DTIM, pConfig->fIgnoreDtim,
         NULL, eANI_BOOLEAN_FALSE)==eHAL_STATUS_FAILURE)
   {
      fStatus = FALSE;
      hddLog(LOGE, "Could not pass on WNI_IGNORE_DTIM configuration to CCM\n"  );
   }

<<<<<<< HEAD
<<<<<<< HEAD
   if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_PS_ENABLE_HEART_BEAT, pConfig->fEnableFwHeartBeatMonitoring, 
=======
   if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_PS_ENABLE_HEART_BEAT, pConfig->fEnableFwHeartBeatMonitoring,
>>>>>>> d97af3b... add prima wlan driver
=======
   if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_PS_ENABLE_HEART_BEAT, pConfig->fEnableFwHeartBeatMonitoring, 
>>>>>>> 657b0e9... prima update
                    NULL, eANI_BOOLEAN_FALSE)==eHAL_STATUS_FAILURE)
   {
      fStatus = FALSE;
      hddLog(LOGE, "Failure: Could not pass on WNI_CFG_PS_HEART_BEAT configuration info to CCM\n");
   }

<<<<<<< HEAD
<<<<<<< HEAD
   if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_PS_ENABLE_BCN_FILTER, pConfig->fEnableFwBeaconFiltering, 
=======
   if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_PS_ENABLE_BCN_FILTER, pConfig->fEnableFwBeaconFiltering,
>>>>>>> d97af3b... add prima wlan driver
=======
   if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_PS_ENABLE_BCN_FILTER, pConfig->fEnableFwBeaconFiltering, 
>>>>>>> 657b0e9... prima update
                    NULL, eANI_BOOLEAN_FALSE)==eHAL_STATUS_FAILURE)
   {
      fStatus = FALSE;
      hddLog(LOGE, "Failure: Could not pass on WNI_CFG_PS_BCN_FILTER configuration info to CCM\n");
   }

<<<<<<< HEAD
<<<<<<< HEAD
   if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_PS_ENABLE_RSSI_MONITOR, pConfig->fEnableFwRssiMonitoring, 
=======
   if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_PS_ENABLE_RSSI_MONITOR, pConfig->fEnableFwRssiMonitoring,
>>>>>>> d97af3b... add prima wlan driver
=======
   if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_PS_ENABLE_RSSI_MONITOR, pConfig->fEnableFwRssiMonitoring, 
>>>>>>> 657b0e9... prima update
                    NULL, eANI_BOOLEAN_FALSE)==eHAL_STATUS_FAILURE)
   {
      fStatus = FALSE;
      hddLog(LOGE, "Failure: Could not pass on WNI_CFG_PS_RSSI_MONITOR configuration info to CCM\n");
   }

<<<<<<< HEAD
<<<<<<< HEAD
   if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_PS_DATA_INACTIVITY_TIMEOUT, pConfig->nDataInactivityTimeout, 
=======
   if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_PS_DATA_INACTIVITY_TIMEOUT, pConfig->nDataInactivityTimeout,
>>>>>>> d97af3b... add prima wlan driver
=======
   if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_PS_DATA_INACTIVITY_TIMEOUT, pConfig->nDataInactivityTimeout, 
>>>>>>> 657b0e9... prima update
                    NULL, eANI_BOOLEAN_FALSE)==eHAL_STATUS_FAILURE)
   {
      fStatus = FALSE;
      hddLog(LOGE,"Failure: Could not pass on WNI_CFG_PS_DATA_INACTIVITY_TIMEOUT configuration info to CCM\n");
   }

<<<<<<< HEAD
<<<<<<< HEAD
   if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_NTH_BEACON_FILTER, pConfig->nthBeaconFilter, 
=======
   if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_NTH_BEACON_FILTER, pConfig->nthBeaconFilter,
>>>>>>> d97af3b... add prima wlan driver
=======
   if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_NTH_BEACON_FILTER, pConfig->nthBeaconFilter, 
>>>>>>> 657b0e9... prima update
                    NULL, eANI_BOOLEAN_FALSE)==eHAL_STATUS_FAILURE)
   {
      fStatus = FALSE;
      hddLog(LOGE,"Failure: Could not pass on WNI_CFG_NTH_BEACON_FILTER configuration info to CCM\n");
   }

<<<<<<< HEAD
<<<<<<< HEAD
#ifdef WLAN_SOFTAP_FEATURE
     if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_ENABLE_LTE_COEX, pConfig->enableLTECoex, 
=======
     if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_ENABLE_LTE_COEX, pConfig->enableLTECoex,
>>>>>>> d97af3b... add prima wlan driver
=======
#ifdef WLAN_SOFTAP_FEATURE
     if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_ENABLE_LTE_COEX, pConfig->enableLTECoex, 
>>>>>>> 657b0e9... prima update
        NULL, eANI_BOOLEAN_FALSE)==eHAL_STATUS_FAILURE)
     {
        fStatus = FALSE;
        hddLog(LOGE, "Could not pass on WNI_CFG_ENABLE_LTE_COEX to CCM\n");
     }

<<<<<<< HEAD
<<<<<<< HEAD
     if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_ENABLE_PHY_AGC_LISTEN_MODE, pConfig->nEnableListenMode, 
=======
     if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_ENABLE_PHY_AGC_LISTEN_MODE, pConfig->nEnableListenMode,
>>>>>>> d97af3b... add prima wlan driver
=======
     if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_ENABLE_PHY_AGC_LISTEN_MODE, pConfig->nEnableListenMode, 
>>>>>>> 657b0e9... prima update
        NULL, eANI_BOOLEAN_FALSE)==eHAL_STATUS_FAILURE)
     {
        fStatus = FALSE;
        hddLog(LOGE, "Could not pass on WNI_CFG_ENABLE_PHY_AGC_LISTEN_MODE to CCM\n");
     }

<<<<<<< HEAD
<<<<<<< HEAD
     WLANSAP_SetChannelRange(pHddCtx->hHal, pConfig->apStartChannelNum, pConfig->apEndChannelNum, pConfig->apOperatingBand);

     if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_AP_KEEP_ALIVE_TIMEOUT, pConfig->apKeepAlivePeriod, 
=======
     if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_AP_KEEP_ALIVE_TIMEOUT, pConfig->apKeepAlivePeriod,
>>>>>>> d97af3b... add prima wlan driver
=======
     WLANSAP_SetChannelRange(pHddCtx->hHal, pConfig->apStartChannelNum, pConfig->apEndChannelNum, pConfig->apOperatingBand);

     if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_AP_KEEP_ALIVE_TIMEOUT, pConfig->apKeepAlivePeriod, 
>>>>>>> 657b0e9... prima update
        NULL, eANI_BOOLEAN_FALSE)==eHAL_STATUS_FAILURE)
     {
        fStatus = FALSE;
        hddLog(LOGE, "Could not pass on WNI_CFG_AP_KEEP_ALIVE_TIMEOUT to CCM\n");
<<<<<<< HEAD
<<<<<<< HEAD
     } 

     if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_GO_KEEP_ALIVE_TIMEOUT, pConfig->goKeepAlivePeriod, 
=======
     }

     if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_GO_KEEP_ALIVE_TIMEOUT, pConfig->goKeepAlivePeriod,
>>>>>>> d97af3b... add prima wlan driver
=======
     } 

     if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_GO_KEEP_ALIVE_TIMEOUT, pConfig->goKeepAlivePeriod, 
>>>>>>> 657b0e9... prima update
        NULL, eANI_BOOLEAN_FALSE)==eHAL_STATUS_FAILURE)
     {
        fStatus = FALSE;
        hddLog(LOGE, "Could not pass on WNI_CFG_GO_KEEP_ALIVE_TIMEOUT to CCM\n");
     }
<<<<<<< HEAD
<<<<<<< HEAD
#endif
   
#if defined WLAN_FEATURE_VOWIFI
    if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_RRM_ENABLED, pConfig->fRrmEnable, 
=======

     if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_AP_LINK_MONITOR_TIMEOUT, pConfig->apLinkMonitorPeriod,
        NULL, eANI_BOOLEAN_FALSE)==eHAL_STATUS_FAILURE)
     {
        fStatus = FALSE;
        hddLog(LOGE, "Could not pass on WNI_CFG_AP_LINK_MONITOR_TIMEOUT to CCM\n");
     }

    if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_GO_LINK_MONITOR_TIMEOUT, pConfig->goLinkMonitorPeriod,
        NULL, eANI_BOOLEAN_FALSE)==eHAL_STATUS_FAILURE)
     {
        fStatus = FALSE;
        hddLog(LOGE, "Could not pass on WNI_CFG_GO_LINK_MONITOR_TIMEOUT to CCM\n");
     }


#if defined WLAN_FEATURE_VOWIFI
    if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_RRM_ENABLED, pConfig->fRrmEnable,
>>>>>>> d97af3b... add prima wlan driver
=======
#endif
   
#if defined WLAN_FEATURE_VOWIFI
    if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_RRM_ENABLED, pConfig->fRrmEnable, 
>>>>>>> 657b0e9... prima update
                     NULL, eANI_BOOLEAN_FALSE)==eHAL_STATUS_FAILURE)
    {
       fStatus = FALSE;
       hddLog(LOGE,"Failure: Could not pass on WNI_CFG_RRM_ENABLE configuration info to CCM\n");
    }

<<<<<<< HEAD
<<<<<<< HEAD
    if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_RRM_OPERATING_CHAN_MAX, pConfig->nInChanMeasMaxDuration, 
=======
    if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_RRM_OPERATING_CHAN_MAX, pConfig->nInChanMeasMaxDuration,
>>>>>>> d97af3b... add prima wlan driver
=======
    if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_RRM_OPERATING_CHAN_MAX, pConfig->nInChanMeasMaxDuration, 
>>>>>>> 657b0e9... prima update
                     NULL, eANI_BOOLEAN_FALSE)==eHAL_STATUS_FAILURE)
    {
       fStatus = FALSE;
       hddLog(LOGE,"Failure: Could not pass on WNI_CFG_RRM_OPERATING_CHAN_MAX configuration info to CCM\n");
    }

<<<<<<< HEAD
<<<<<<< HEAD
    if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_RRM_NON_OPERATING_CHAN_MAX, pConfig->nOutChanMeasMaxDuration, 
=======
    if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_RRM_NON_OPERATING_CHAN_MAX, pConfig->nOutChanMeasMaxDuration,
>>>>>>> d97af3b... add prima wlan driver
=======
    if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_RRM_NON_OPERATING_CHAN_MAX, pConfig->nOutChanMeasMaxDuration, 
>>>>>>> 657b0e9... prima update
                     NULL, eANI_BOOLEAN_FALSE)==eHAL_STATUS_FAILURE)
    {
       fStatus = FALSE;
       hddLog(LOGE,"Failure: Could not pass on WNI_CFG_RRM_OUT_CHAN_MAX configuration info to CCM\n");
    }

<<<<<<< HEAD
<<<<<<< HEAD
    if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_MCAST_BCAST_FILTER_SETTING, pConfig->mcastBcastFilterSetting, 
                     NULL, eANI_BOOLEAN_FALSE)==eHAL_STATUS_FAILURE)
#endif

     if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_SINGLE_TID_RC, pConfig->bSingleTidRc, 
=======
    if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_MCAST_BCAST_FILTER_SETTING, pConfig->mcastBcastFilterSetting,
                     NULL, eANI_BOOLEAN_FALSE)==eHAL_STATUS_FAILURE)
#endif

     if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_SINGLE_TID_RC, pConfig->bSingleTidRc,
>>>>>>> d97af3b... add prima wlan driver
=======
    if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_MCAST_BCAST_FILTER_SETTING, pConfig->mcastBcastFilterSetting, 
                     NULL, eANI_BOOLEAN_FALSE)==eHAL_STATUS_FAILURE)
#endif

     if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_SINGLE_TID_RC, pConfig->bSingleTidRc, 
>>>>>>> 657b0e9... prima update
                      NULL, eANI_BOOLEAN_FALSE)==eHAL_STATUS_FAILURE)
     {
        fStatus = FALSE;
        hddLog(LOGE,"Failure: Could not pass on WNI_CFG_SINGLE_TID_RC configuration info to CCM\n");
     }

<<<<<<< HEAD
<<<<<<< HEAD
     if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_TELE_BCN_WAKEUP_EN, pConfig->teleBcnWakeupEn, 
=======
     if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_TELE_BCN_WAKEUP_EN, pConfig->teleBcnWakeupEn,
>>>>>>> d97af3b... add prima wlan driver
=======
     if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_TELE_BCN_WAKEUP_EN, pConfig->teleBcnWakeupEn, 
>>>>>>> 657b0e9... prima update
                      NULL, eANI_BOOLEAN_FALSE)==eHAL_STATUS_FAILURE)
     {
        fStatus = FALSE;
        hddLog(LOGE,"Failure: Could not pass on WNI_CFG_TELE_BCN_WAKEUP_EN configuration info to CCM\n"  );
     }

<<<<<<< HEAD
<<<<<<< HEAD
     if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_TELE_BCN_TRANS_LI, pConfig->nTeleBcnTransListenInterval, 
=======
     if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_TELE_BCN_TRANS_LI, pConfig->nTeleBcnTransListenInterval,
>>>>>>> d97af3b... add prima wlan driver
=======
     if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_TELE_BCN_TRANS_LI, pConfig->nTeleBcnTransListenInterval, 
>>>>>>> 657b0e9... prima update
      NULL, eANI_BOOLEAN_FALSE)==eHAL_STATUS_FAILURE)
    {
      fStatus = FALSE;
      hddLog(LOGE,"Failure: Could not pass on WNI_CFG_TELE_BCN_TRANS_LI configuration info to CCM\n"  );
    }

<<<<<<< HEAD
<<<<<<< HEAD
     if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_TELE_BCN_MAX_LI, pConfig->nTeleBcnMaxListenInterval, 
=======
     if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_TELE_BCN_MAX_LI, pConfig->nTeleBcnMaxListenInterval,
>>>>>>> d97af3b... add prima wlan driver
=======
     if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_TELE_BCN_MAX_LI, pConfig->nTeleBcnMaxListenInterval, 
>>>>>>> 657b0e9... prima update
      NULL, eANI_BOOLEAN_FALSE)==eHAL_STATUS_FAILURE)
    {
      fStatus = FALSE;
      hddLog(LOGE,"Failure: Could not pass on WNI_CFG_TELE_BCN_MAX_LI configuration info to CCM\n"  );
    }

<<<<<<< HEAD
<<<<<<< HEAD
     if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_TELE_BCN_TRANS_LI_IDLE_BCNS, pConfig->nTeleBcnTransLiNumIdleBeacons, 
=======
     if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_TELE_BCN_TRANS_LI_IDLE_BCNS, pConfig->nTeleBcnTransLiNumIdleBeacons,
>>>>>>> d97af3b... add prima wlan driver
=======
     if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_TELE_BCN_TRANS_LI_IDLE_BCNS, pConfig->nTeleBcnTransLiNumIdleBeacons, 
>>>>>>> 657b0e9... prima update
      NULL, eANI_BOOLEAN_FALSE)==eHAL_STATUS_FAILURE)
    {
      fStatus = FALSE;
      hddLog(LOGE,"Failure: Could not pass on WNI_CFG_TELE_BCN_TRANS_LI_IDLE_BCNS configuration info to CCM\n"  );
    }

<<<<<<< HEAD
<<<<<<< HEAD
     if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_TELE_BCN_MAX_LI_IDLE_BCNS, pConfig->nTeleBcnMaxLiNumIdleBeacons, 
=======
     if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_TELE_BCN_MAX_LI_IDLE_BCNS, pConfig->nTeleBcnMaxLiNumIdleBeacons,
>>>>>>> d97af3b... add prima wlan driver
=======
     if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_TELE_BCN_MAX_LI_IDLE_BCNS, pConfig->nTeleBcnMaxLiNumIdleBeacons, 
>>>>>>> 657b0e9... prima update
      NULL, eANI_BOOLEAN_FALSE)==eHAL_STATUS_FAILURE)
    {
      fStatus = FALSE;
      hddLog(LOGE,"Failure: Could not pass on WNI_CFG_TELE_BCN_MAX_LI_IDLE_BCNS configuration info to CCM\n"  );
    }

     if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_RF_SETTLING_TIME_CLK, pConfig->rfSettlingTimeUs,
        NULL, eANI_BOOLEAN_FALSE)==eHAL_STATUS_FAILURE)
    {
        fStatus = FALSE;
        hddLog(LOGE,"Failure: Could not pass on WNI_CFG_RF_SETTLING_TIME_CLK configuration info to CCM\n"  );
    }

<<<<<<< HEAD
<<<<<<< HEAD
     if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_INFRA_STA_KEEP_ALIVE_PERIOD, pConfig->infraStaKeepAlivePeriod, 
=======
     if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_INFRA_STA_KEEP_ALIVE_PERIOD, pConfig->infraStaKeepAlivePeriod,
>>>>>>> d97af3b... add prima wlan driver
=======
     if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_INFRA_STA_KEEP_ALIVE_PERIOD, pConfig->infraStaKeepAlivePeriod, 
>>>>>>> 657b0e9... prima update
                      NULL, eANI_BOOLEAN_FALSE)==eHAL_STATUS_FAILURE)
     {
        fStatus = FALSE;
        hddLog(LOGE,"Failure: Could not pass on WNI_CFG_INFRA_STA_KEEP_ALIVE_PERIOD configuration info to CCM\n"  );
     }
<<<<<<< HEAD
<<<<<<< HEAD
    if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_DYNAMIC_PS_POLL_VALUE, pConfig->dynamicPsPollValue, 
=======
    if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_DYNAMIC_PS_POLL_VALUE, pConfig->dynamicPsPollValue,
>>>>>>> d97af3b... add prima wlan driver
=======
    if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_DYNAMIC_PS_POLL_VALUE, pConfig->dynamicPsPollValue, 
>>>>>>> 657b0e9... prima update
                     NULL, eANI_BOOLEAN_FALSE)==eHAL_STATUS_FAILURE)
    {
       fStatus = FALSE;
       hddLog(LOGE,"Failure: Could not pass on WNI_CFG_DYNAMIC_PS_POLL_VALUE configuration info to CCM\n"  );
    }

    if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_PS_NULLDATA_AP_RESP_TIMEOUT, pConfig->nNullDataApRespTimeout,
               NULL, eANI_BOOLEAN_FALSE)==eHAL_STATUS_FAILURE)
    {
       fStatus = FALSE;
       hddLog(LOGE,"Failure: Could not pass on WNI_CFG_PS_NULLDATA_DELAY_TIMEOUT configuration info to CCM\n"  );
<<<<<<< HEAD
<<<<<<< HEAD
    } 

   if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_AP_DATA_AVAIL_POLL_PERIOD, pConfig->apDataAvailPollPeriodInMs,
               NULL, eANI_BOOLEAN_FALSE)==eHAL_STATUS_FAILURE)
   {
       fStatus = FALSE;
       hddLog(LOGE,"Failure: Could not pass on WNI_CFG_AP_DATA_AVAIL_POLL_PERIOD configuration info to CCM\n"  );
   } 
#ifdef FEATURE_WLAN_INTEGRATED_SOC
    if(ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_FRAGMENTATION_THRESHOLD, pConfig->FragmentationThreshold, 
=======
    }
=======
    } 
>>>>>>> 657b0e9... prima update

   if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_AP_DATA_AVAIL_POLL_PERIOD, pConfig->apDataAvailPollPeriodInMs,
               NULL, eANI_BOOLEAN_FALSE)==eHAL_STATUS_FAILURE)
<<<<<<< HEAD
    {
        fStatus = FALSE;
        hddLog(LOGE,"Failure: Could not pass on WNI_CFG_AP_DATA_AVAIL_POLL_PERIOD configuration info to CCM\n"  );
    }
    if(ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_FRAGMENTATION_THRESHOLD, pConfig->FragmentationThreshold,
>>>>>>> d97af3b... add prima wlan driver
=======
   {
       fStatus = FALSE;
       hddLog(LOGE,"Failure: Could not pass on WNI_CFG_AP_DATA_AVAIL_POLL_PERIOD configuration info to CCM\n"  );
   } 
#ifdef FEATURE_WLAN_INTEGRATED_SOC
    if(ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_FRAGMENTATION_THRESHOLD, pConfig->FragmentationThreshold, 
>>>>>>> 657b0e9... prima update
                   NULL, eANI_BOOLEAN_FALSE) == eHAL_STATUS_FAILURE)
    {
        fStatus = FALSE;
        hddLog(LOGE,"Failure: Could not pass on WNI_CFG_FRAGMENTATION_THRESHOLD configuration info to CCM\n"  );
    }
<<<<<<< HEAD
<<<<<<< HEAD
    if(ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_RTS_THRESHOLD, pConfig->RTSThreshold, 
=======
    if(ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_RTS_THRESHOLD, pConfig->RTSThreshold,
>>>>>>> d97af3b... add prima wlan driver
=======
    if(ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_RTS_THRESHOLD, pConfig->RTSThreshold, 
>>>>>>> 657b0e9... prima update
                        NULL, eANI_BOOLEAN_FALSE) == eHAL_STATUS_FAILURE)
    {
        fStatus = FALSE;
        hddLog(LOGE,"Failure: Could not pass on WNI_CFG_RTS_THRESHOLD configuration info to CCM\n"  );
    }

<<<<<<< HEAD
<<<<<<< HEAD
    if(ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_11D_ENABLED, pConfig->Is11dSupportEnabled, 
=======
    if(ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_11D_ENABLED, pConfig->Is11dSupportEnabled,
>>>>>>> d97af3b... add prima wlan driver
=======
    if(ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_11D_ENABLED, pConfig->Is11dSupportEnabled, 
>>>>>>> 657b0e9... prima update
                        NULL, eANI_BOOLEAN_FALSE) == eHAL_STATUS_FAILURE)
    {
        fStatus = FALSE;
        hddLog(LOGE,"Failure: Could not pass on WNI_CFG_11D_ENABLED configuration info to CCM\n"  );
    }
<<<<<<< HEAD
<<<<<<< HEAD
    if(ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_HEART_BEAT_THRESHOLD, pConfig->HeartbeatThresh24, 
=======
    if(ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_HEART_BEAT_THRESHOLD, pConfig->HeartbeatThresh24,
>>>>>>> d97af3b... add prima wlan driver
=======
    if(ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_HEART_BEAT_THRESHOLD, pConfig->HeartbeatThresh24, 
>>>>>>> 657b0e9... prima update
                        NULL, eANI_BOOLEAN_FALSE) == eHAL_STATUS_FAILURE)
    {
        fStatus = FALSE;
        hddLog(LOGE,"Failure: Could not pass on WNI_CFG_HEART_BEAT_THRESHOLD configuration info to CCM\n"  );
    }

<<<<<<< HEAD
<<<<<<< HEAD
#endif
=======
>>>>>>> d97af3b... add prima wlan driver
=======
#endif
>>>>>>> 657b0e9... prima update
   if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_AP_DATA_AVAIL_POLL_PERIOD, pConfig->apDataAvailPollPeriodInMs,
               NULL, eANI_BOOLEAN_FALSE)==eHAL_STATUS_FAILURE)
   {
      fStatus = FALSE;
      hddLog(LOGE,"Failure: Could not pass on WNI_CFG_AP_DATA_AVAIL_POLL_PERIOD configuration info to CCM\n"  );
   }

<<<<<<< HEAD
<<<<<<< HEAD
   if(ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_ENABLE_CLOSE_LOOP, 
=======
   if(ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_ENABLE_CLOSE_LOOP,
>>>>>>> d97af3b... add prima wlan driver
=======
   if(ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_ENABLE_CLOSE_LOOP, 
>>>>>>> 657b0e9... prima update
                   pConfig->enableCloseLoop, NULL, eANI_BOOLEAN_FALSE)
       ==eHAL_STATUS_FAILURE)
   {
      fStatus = FALSE;
      hddLog(LOGE, "Could not pass on WNI_CFG_ENABLE_CLOSE_LOOP to CCM\n");
   }

<<<<<<< HEAD
<<<<<<< HEAD
   if(ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_TX_PWR_CTRL_ENABLE, 
=======
   if(ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_TX_PWR_CTRL_ENABLE,
>>>>>>> d97af3b... add prima wlan driver
=======
   if(ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_TX_PWR_CTRL_ENABLE, 
>>>>>>> 657b0e9... prima update
                   pConfig->enableAutomaticTxPowerControl, NULL, eANI_BOOLEAN_FALSE)
                   ==eHAL_STATUS_FAILURE)
   {
      fStatus = FALSE;
      hddLog(LOGE, "Could not pass on WNI_CFG_TX_PWR_CTRL_ENABLE to CCM\n");
   }

<<<<<<< HEAD
<<<<<<< HEAD
   if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_SHORT_GI_40MHZ, 
=======
   if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_SHORT_GI_40MHZ,
>>>>>>> d97af3b... add prima wlan driver
=======
   if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_SHORT_GI_40MHZ, 
>>>>>>> 657b0e9... prima update
      pConfig->ShortGI40MhzEnable, NULL, eANI_BOOLEAN_FALSE)==eHAL_STATUS_FAILURE)
   {
      fStatus = FALSE;
      hddLog(LOGE, "Could not pass on WNI_CFG_SHORT_GI_40MHZ to CCM\n");
   }


<<<<<<< HEAD
<<<<<<< HEAD
     if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_ENABLE_MC_ADDR_LIST, pConfig->fEnableMCAddrList, 
=======
     if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_ENABLE_MC_ADDR_LIST, pConfig->fEnableMCAddrList,
>>>>>>> d97af3b... add prima wlan driver
=======
     if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_ENABLE_MC_ADDR_LIST, pConfig->fEnableMCAddrList, 
>>>>>>> 657b0e9... prima update
        NULL, eANI_BOOLEAN_FALSE)==eHAL_STATUS_FAILURE)
     {
        fStatus = FALSE;
        hddLog(LOGE, "Could not pass on WNI_CFG_ENABLE_MC_ADDR_LIST to CCM\n");
     }

#ifdef WLAN_FEATURE_11AC
   /* Based on cfg.ini, update the Basic MCS set, RX/TX MCS map in the cfg.dat */
   /* valid values are 0(MCS0-7), 1(MCS0-8), 2(MCS0-9) */
   /* we update only the least significant 2 bits in the corresponding fields */
   if( (pConfig->dot11Mode == eHDD_DOT11_MODE_AUTO) ||
       (pConfig->dot11Mode == eHDD_DOT11_MODE_11ac_ONLY) ||
       (pConfig->dot11Mode == eHDD_DOT11_MODE_11ac) )
   {
       {
           tANI_U32 temp = 0;

           ccmCfgGetInt(pHddCtx->hHal, WNI_CFG_VHT_BASIC_MCS_SET, &temp);
<<<<<<< HEAD
<<<<<<< HEAD
           temp = (temp & 0xFFFC) | pConfig->vhtRxMCS; 

           if(ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_VHT_BASIC_MCS_SET, 
=======
           temp = (temp & 0xFFFC) | pConfig->vhtRxMCS;

           if(ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_VHT_BASIC_MCS_SET,
>>>>>>> d97af3b... add prima wlan driver
=======
           temp = (temp & 0xFFFC) | pConfig->vhtRxMCS; 

           if(ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_VHT_BASIC_MCS_SET, 
>>>>>>> 657b0e9... prima update
                           temp, NULL, eANI_BOOLEAN_FALSE)
               ==eHAL_STATUS_FAILURE)
           {
               fStatus = FALSE;
               hddLog(LOGE, "Could not pass on WNI_CFG_VHT_BASIC_MCS_SET to CCM\n");
           }

           ccmCfgGetInt(pHddCtx->hHal, WNI_CFG_VHT_RX_MCS_MAP, &temp);
<<<<<<< HEAD
<<<<<<< HEAD
           temp = (temp & 0xFFFC) | pConfig->vhtRxMCS; 

           if(ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_VHT_RX_MCS_MAP, 
=======
           temp = (temp & 0xFFFC) | pConfig->vhtRxMCS;

           if(ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_VHT_RX_MCS_MAP,
>>>>>>> d97af3b... add prima wlan driver
=======
           temp = (temp & 0xFFFC) | pConfig->vhtRxMCS; 

           if(ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_VHT_RX_MCS_MAP, 
>>>>>>> 657b0e9... prima update
                           temp, NULL, eANI_BOOLEAN_FALSE)
               ==eHAL_STATUS_FAILURE)
           {
              fStatus = FALSE;
              hddLog(LOGE, "Could not pass on WNI_CFG_VHT_RX_MCS_MAP to CCM\n");
           }

           ccmCfgGetInt(pHddCtx->hHal, WNI_CFG_VHT_TX_MCS_MAP, &temp);
<<<<<<< HEAD
<<<<<<< HEAD
           temp = (temp & 0xFFFC) | pConfig->vhtTxMCS; 

           if(ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_VHT_TX_MCS_MAP, 
=======
           temp = (temp & 0xFFFC) | pConfig->vhtTxMCS;

           if(ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_VHT_TX_MCS_MAP,
>>>>>>> d97af3b... add prima wlan driver
=======
           temp = (temp & 0xFFFC) | pConfig->vhtTxMCS; 

           if(ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_VHT_TX_MCS_MAP, 
>>>>>>> 657b0e9... prima update
                           temp, NULL, eANI_BOOLEAN_FALSE)
               ==eHAL_STATUS_FAILURE)
           {
               fStatus = FALSE;
               hddLog(LOGE, "Could not pass on WNI_CFG_VHT_TX_MCS_MAP to CCM\n");
           }
       }
   }
#endif

<<<<<<< HEAD
<<<<<<< HEAD
=======
     if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_NUM_BUFF_ADVERT,pConfig->numBuffAdvert,
        NULL, eANI_BOOLEAN_FALSE)==eHAL_STATUS_FAILURE)
     {
        fStatus = FALSE;
        hddLog(LOGE, "Could not pass on WNI_CFG_NUM_BUFF_ADVERT to CCM\n");
     }

     if(ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_HT_RX_STBC,
                     pConfig->enableRxSTBC, NULL, eANI_BOOLEAN_FALSE)
         ==eHAL_STATUS_FAILURE)
     {
         fStatus = FALSE;
         hddLog(LOGE, "Could not pass on WNI_CFG_HT_RX_STBC to CCM\n");
     }

     ccmCfgGetInt(pHddCtx->hHal, WNI_CFG_HT_CAP_INFO, (tANI_U32 *)&htCapInfo);
     htCapInfo.rxSTBC = pConfig->enableRxSTBC;

     if(ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_HT_CAP_INFO,
                     *(tANI_U32 *)&htCapInfo, NULL, eANI_BOOLEAN_FALSE)
         ==eHAL_STATUS_FAILURE)
     {
         fStatus = FALSE;
         hddLog(LOGE, "Could not pass on WNI_CFG_HT_CAP_INFO to CCM\n");
     }

     if(ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_VHT_RXSTBC,
                     pConfig->enableRxSTBC, NULL, eANI_BOOLEAN_FALSE)
         ==eHAL_STATUS_FAILURE)
     {
         fStatus = FALSE;
         hddLog(LOGE, "Could not pass on WNI_CFG_VHT_RXSTBC to CCM\n");
     }

#ifdef WLAN_SOFTAP_VSTA_FEATURE
     if(pConfig->fEnableVSTASupport)
     {
        ccmCfgGetInt(pHddCtx->hHal, WNI_CFG_ASSOC_STA_LIMIT, &val);
        if( val <= WNI_CFG_ASSOC_STA_LIMIT_STADEF)
            val = WNI_CFG_ASSOC_STA_LIMIT_STAMAX;
     }
     else
     {
            val = WNI_CFG_ASSOC_STA_LIMIT_STADEF;
     }
     if(ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_ASSOC_STA_LIMIT, val,
         NULL, eANI_BOOLEAN_FALSE) == eHAL_STATUS_FAILURE)
     {
         fStatus = FALSE;
         hddLog(LOGE,"Failure: Could not pass on WNI_CFG_ASSOC_STA_LIMIT configuration info to CCM\n"  );
     }
#endif
   if(ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_ENABLE_LPWR_IMG_TRANSITION,
                   pConfig->enableLpwrImgTransition, NULL, eANI_BOOLEAN_FALSE)
       ==eHAL_STATUS_FAILURE)
   {
      fStatus = FALSE;
      hddLog(LOGE, "Could not pass on WNI_CFG_ENABLE_LPWR_IMG_TRANSITION to CCM\n");
   }

   if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_ENABLE_MCC_ADAPTIVE_SCHED, pConfig->enableMCCAdaptiveScheduler,
      NULL, eANI_BOOLEAN_FALSE)==eHAL_STATUS_FAILURE)
   {
      fStatus = FALSE;
      hddLog(LOGE, "Could not pass on WNI_CFG_ENABLE_MCC_ADAPTIVE_SCHED to CCM\n");
   }
   if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_DISABLE_LDPC_WITH_TXBF_AP, pConfig->disableLDPCWithTxbfAP,
      NULL, eANI_BOOLEAN_FALSE)==eHAL_STATUS_FAILURE)
   {
      fStatus = FALSE;
      hddLog(LOGE, "Could not pass on WNI_CFG_DISABLE_LDPC_WITH_TXBF_AP to CCM");
   }

   if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_DYNAMIC_THRESHOLD_ZERO, pConfig->retryLimitZero,
      NULL, eANI_BOOLEAN_FALSE)==eHAL_STATUS_FAILURE)
   {
      fStatus = FALSE;
      hddLog(LOGE, "Could not pass on WNI_CFG_DYNAMIC_THRESHOLD_ZERO to CCM");
   }

   if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_DYNAMIC_THRESHOLD_ONE, pConfig->retryLimitOne,
      NULL, eANI_BOOLEAN_FALSE)==eHAL_STATUS_FAILURE)
   {
      fStatus = FALSE;
      hddLog(LOGE, "Could not pass on WNI_CFG_DYNAMIC_THRESHOLD_ONE to CCM");
   }

   if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_DYNAMIC_THRESHOLD_TWO, pConfig->retryLimitTwo,
      NULL, eANI_BOOLEAN_FALSE)==eHAL_STATUS_FAILURE)
   {
      fStatus = FALSE;
      hddLog(LOGE, "Could not pass on WNI_CFG_DYNAMIC_THRESHOLD_TWO to CCM");
   }

   if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_MAX_MEDIUM_TIME, pConfig->cfgMaxMediumTime,
      NULL, eANI_BOOLEAN_FALSE) == eHAL_STATUS_FAILURE)
   {
      fStatus = FALSE;
      hddLog(LOGE, "Could not pass on WNI_CFG_MAX_MEDIUM_TIME to CCM");
   }

#ifdef FEATURE_WLAN_TDLS

   if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_TDLS_QOS_WMM_UAPSD_MASK,
                    pConfig->fTDLSUapsdMask, NULL,
                    eANI_BOOLEAN_FALSE) == eHAL_STATUS_FAILURE)
   {
      fStatus = FALSE;
      hddLog(LOGE, "Could not pass on WNI_CFG_TDLS_QOS_WMM_UAPSD_MASK to CCM");
   }
   if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_TDLS_BUF_STA_ENABLED,
                    pConfig->fEnableTDLSBufferSta, NULL,
                    eANI_BOOLEAN_FALSE) == eHAL_STATUS_FAILURE)
   {
      fStatus = FALSE;
      hddLog(LOGE, "Could not pass on WNI_CFG_TDLS_BUF_STA_ENABLED to CCM");
   }
   if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_TDLS_PUAPSD_INACT_TIME,
                    pConfig->fTDLSPuapsdInactivityTimer, NULL,
                    eANI_BOOLEAN_FALSE) == eHAL_STATUS_FAILURE)
   {
      fStatus = FALSE;
      hddLog(LOGE, "Could not pass on WNI_CFG_TDLS_PUAPSD_INACT_TIME to CCM");
   }
   if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_TDLS_RX_FRAME_THRESHOLD,
                    pConfig->fTDLSRxFrameThreshold, NULL,
                    eANI_BOOLEAN_FALSE) == eHAL_STATUS_FAILURE)
   {
      fStatus = FALSE;
      hddLog(LOGE, "Could not pass on WNI_CFG_TDLS_RX_FRAME_THRESHOLD to CCM");
   }
#endif

   if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_ENABLE_ADAPT_RX_DRAIN,
                    pConfig->fEnableAdaptRxDrain, NULL,
                    eANI_BOOLEAN_FALSE) == eHAL_STATUS_FAILURE)
   {
      fStatus = FALSE;
      hddLog(LOGE, "Could not pass on WNI_CFG_ENABLE_ADAPT_RX_DRAIN to CCM");
   }

   if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_FLEX_CONNECT_POWER_FACTOR,
                    pConfig->flexConnectPowerFactor, NULL,
                    eANI_BOOLEAN_FALSE) == eHAL_STATUS_FAILURE)
   {
      fStatus = FALSE;
      hddLog(LOGE, "Failure: Could not pass on "
             "WNI_CFG_FLEX_CONNECT_POWER_FACTOR to CCM");
   }

   if (ccmCfgSetInt(pHddCtx->hHal, WNI_CFG_ANTENNA_DIVESITY,
                    pConfig->antennaDiversity, NULL,
                    eANI_BOOLEAN_FALSE)==eHAL_STATUS_FAILURE)
   {
      fStatus = FALSE;
      hddLog(LOGE, "Could not pass on WNI_CFG_ANTENNA_DIVESITY to CCM");
   }

>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
   return fStatus;
}


/**---------------------------------------------------------------------------

<<<<<<< HEAD
<<<<<<< HEAD
  \brief hdd_init_set_sme_config() - 

   This function initializes the sme configuration parameters
   
  \param  - pHddCtx - Pointer to the HDD Adapter.
              
  \return - 0 for success, non zero for failure
    
=======
  \brief hdd_init_set_sme_config() -
=======
  \brief hdd_init_set_sme_config() - 
>>>>>>> 657b0e9... prima update

   This function initializes the sme configuration parameters
   
  \param  - pHddCtx - Pointer to the HDD Adapter.
              
  \return - 0 for success, non zero for failure
<<<<<<< HEAD

>>>>>>> d97af3b... add prima wlan driver
=======
    
>>>>>>> 657b0e9... prima update
  --------------------------------------------------------------------------*/

VOS_STATUS hdd_set_sme_config( hdd_context_t *pHddCtx )
{
   VOS_STATUS status = VOS_STATUS_SUCCESS;
   eHalStatus halStatus;
   tSmeConfigParams smeConfig;

   hdd_config_t *pConfig = pHddCtx->cfg_ini;

<<<<<<< HEAD
<<<<<<< HEAD
   vos_mem_zero( &smeConfig, sizeof( smeConfig ) );

   VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, 
=======

   vos_mem_zero( &smeConfig, sizeof( smeConfig ) );

   VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH,
>>>>>>> d97af3b... add prima wlan driver
=======
   vos_mem_zero( &smeConfig, sizeof( smeConfig ) );

   VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, 
>>>>>>> 657b0e9... prima update
              "%s bWmmIsEnabled=%d 802_11e_enabled=%d dot11Mode=%d\n", __func__,
              pConfig->WmmMode, pConfig->b80211eIsEnabled, pConfig->dot11Mode);

   // Config params obtained from the registry
<<<<<<< HEAD
<<<<<<< HEAD
=======

>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
   smeConfig.csrConfig.RTSThreshold             = pConfig->RTSThreshold;
   smeConfig.csrConfig.FragmentationThreshold   = pConfig->FragmentationThreshold;
   smeConfig.csrConfig.shortSlotTime            = pConfig->ShortSlotTimeEnabled;
   smeConfig.csrConfig.Is11dSupportEnabled      = pConfig->Is11dSupportEnabled;
   smeConfig.csrConfig.HeartbeatThresh24        = pConfig->HeartbeatThresh24;

   smeConfig.csrConfig.phyMode                  = hdd_cfg_xlate_to_csr_phy_mode ( pConfig->dot11Mode );

   smeConfig.csrConfig.channelBondingMode24GHz  = pConfig->nChannelBondingMode24GHz;
   smeConfig.csrConfig.channelBondingMode5GHz   = pConfig->nChannelBondingMode5GHz;
   smeConfig.csrConfig.TxRate                   = pConfig->TxRate;
   smeConfig.csrConfig.nScanResultAgeCount      = pConfig->ScanResultAgeCount;
   smeConfig.csrConfig.scanAgeTimeNCNPS         = pConfig->nScanAgeTimeNCNPS;
   smeConfig.csrConfig.scanAgeTimeNCPS          = pConfig->nScanAgeTimeNCPS;
   smeConfig.csrConfig.scanAgeTimeCNPS          = pConfig->nScanAgeTimeCNPS;
   smeConfig.csrConfig.scanAgeTimeCPS           = pConfig->nScanAgeTimeCPS;
   smeConfig.csrConfig.AdHocChannel24           = pConfig->OperatingChannel;
   smeConfig.csrConfig.fEnforce11dChannels      = pConfig->fEnforce11dChannels;
   smeConfig.csrConfig.fSupplicantCountryCodeHasPriority     = pConfig->fSupplicantCountryCodeHasPriority;
   smeConfig.csrConfig.fEnforceCountryCodeMatch = pConfig->fEnforceCountryCodeMatch;
   smeConfig.csrConfig.fEnforceDefaultDomain    = pConfig->fEnforceDefaultDomain;
   smeConfig.csrConfig.bCatRssiOffset           = pConfig->nRssiCatGap;
   smeConfig.csrConfig.vccRssiThreshold         = pConfig->nVccRssiTrigger;
   smeConfig.csrConfig.vccUlMacLossThreshold    = pConfig->nVccUlMacLossThreshold;
   smeConfig.csrConfig.nRoamingTime             = pConfig->nRoamingTime;
<<<<<<< HEAD
<<<<<<< HEAD
   smeConfig.csrConfig.IsIdleScanEnabled        = pConfig->nEnableIdleScan; 
=======
   smeConfig.csrConfig.IsIdleScanEnabled        = pConfig->nEnableIdleScan;
>>>>>>> d97af3b... add prima wlan driver
=======
   smeConfig.csrConfig.IsIdleScanEnabled        = pConfig->nEnableIdleScan; 
>>>>>>> 657b0e9... prima update
   smeConfig.csrConfig.nActiveMaxChnTime        = pConfig->nActiveMaxChnTime;
   smeConfig.csrConfig.nActiveMinChnTime        = pConfig->nActiveMinChnTime;
   smeConfig.csrConfig.nPassiveMaxChnTime       = pConfig->nPassiveMaxChnTime;
   smeConfig.csrConfig.nPassiveMinChnTime       = pConfig->nPassiveMinChnTime;
<<<<<<< HEAD
<<<<<<< HEAD
=======
   smeConfig.csrConfig.nActiveMaxChnTimeBtc     = pConfig->nActiveMaxChnTimeBtc;
   smeConfig.csrConfig.nActiveMinChnTimeBtc     = pConfig->nActiveMinChnTimeBtc;
   smeConfig.csrConfig.disableAggWithBtc        = pConfig->disableAggWithBtc;
#ifdef WLAN_AP_STA_CONCURRENCY
   smeConfig.csrConfig.nActiveMaxChnTimeConc    = pConfig->nActiveMaxChnTimeConc;
   smeConfig.csrConfig.nActiveMinChnTimeConc    = pConfig->nActiveMinChnTimeConc;
   smeConfig.csrConfig.nPassiveMaxChnTimeConc   = pConfig->nPassiveMaxChnTimeConc;
   smeConfig.csrConfig.nPassiveMinChnTimeConc   = pConfig->nPassiveMinChnTimeConc;
   smeConfig.csrConfig.nRestTimeConc            = pConfig->nRestTimeConc;
   smeConfig.csrConfig.nNumStaChanCombinedConc  = pConfig->nNumStaChanCombinedConc;
   smeConfig.csrConfig.nNumP2PChanCombinedConc  = pConfig->nNumP2PChanCombinedConc;

#endif
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
   smeConfig.csrConfig.Is11eSupportEnabled      = pConfig->b80211eIsEnabled;
   smeConfig.csrConfig.WMMSupportMode           = pConfig->WmmMode;

#if defined WLAN_FEATURE_VOWIFI
   smeConfig.rrmConfig.rrmEnabled = pConfig->fRrmEnable;
   smeConfig.rrmConfig.maxRandnInterval = pConfig->nRrmRandnIntvl;
#endif
   //Remaining config params not obtained from registry
   // On RF EVB beacon using channel 1.
#ifdef WLAN_FEATURE_11AC
    smeConfig.csrConfig.nVhtChannelWidth = pConfig->vhtChannelWidth;
<<<<<<< HEAD
<<<<<<< HEAD
#endif
   smeConfig.csrConfig.AdHocChannel5G            = 44; 
   smeConfig.csrConfig.ProprietaryRatesEnabled   = 0;  
   smeConfig.csrConfig.HeartbeatThresh50         = 40; 
   smeConfig.csrConfig.Is11hSupportEnabled       = 1;
   smeConfig.csrConfig.bandCapability            = pConfig->nBandCapability; 
   smeConfig.csrConfig.cbChoice                  = 0;   
   smeConfig.csrConfig.bgScanInterval            = 0; 
   smeConfig.csrConfig.eBand                     = pConfig->nBandCapability; 
   smeConfig.csrConfig.nTxPowerCap = pConfig->nTxPowerCap;
   smeConfig.csrConfig.fEnableBypass11d          = pConfig->enableBypass11d;
   smeConfig.csrConfig.fEnableDFSChnlScan        = pConfig->enableDFSChnlScan;
   smeConfig.csrConfig.fIgnore_chan165           = pConfig->ignore_chan165;
   smeConfig.csrConfig.fFirstScanOnly2GChnl      = pConfig->enableFirstScan2GOnly;

   //FIXME 11d config is hardcoded
#ifdef WLAN_SOFTAP_FEATURE
   if ( VOS_STA_SAP_MODE != hdd_get_conparam()){
#endif
   smeConfig.csrConfig.Csr11dinfo.Channels.numChannels = 0;

   //if there is a requirement that HDD will control the default channel list & 
   //country code (say from .ini file) we need to add some logic here. Otherwise 
   //the default 11d info should come from NV as per our current implementation
   
#ifdef WLAN_SOFTAP_FEATURE
   }
   else{

    VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
               "AP country Code %s", pConfig->apCntryCode);

    if (memcmp(pConfig->apCntryCode, CFG_AP_COUNTRY_CODE_DEFAULT, 3) != 0)
       sme_setRegInfo(pHddCtx->hHal, pConfig->apCntryCode);
       sme_set11dinfo(pHddCtx->hHal, &smeConfig);
    }
#endif
   hdd_set_power_save_config(pHddCtx, &smeConfig);
   hdd_set_btc_config(pHddCtx);

#ifdef WLAN_FEATURE_VOWIFI_11R   
=======
    smeConfig.csrConfig.enableTxBF = pConfig->enableTxBF;
    smeConfig.csrConfig.txBFCsnValue = pConfig->txBFCsnValue;
    smeConfig.csrConfig.enableVhtFor24GHz = pConfig->enableVhtFor24GHzBand;
=======
>>>>>>> 657b0e9... prima update
#endif
   smeConfig.csrConfig.AdHocChannel5G            = 44; 
   smeConfig.csrConfig.ProprietaryRatesEnabled   = 0;  
   smeConfig.csrConfig.HeartbeatThresh50         = 40; 
   smeConfig.csrConfig.Is11hSupportEnabled       = 1;
   smeConfig.csrConfig.bandCapability            = pConfig->nBandCapability; 
   smeConfig.csrConfig.cbChoice                  = 0;   
   smeConfig.csrConfig.bgScanInterval            = 0; 
   smeConfig.csrConfig.eBand                     = pConfig->nBandCapability; 
   smeConfig.csrConfig.nTxPowerCap = pConfig->nTxPowerCap;
   smeConfig.csrConfig.fEnableBypass11d          = pConfig->enableBypass11d;
   smeConfig.csrConfig.fEnableDFSChnlScan        = pConfig->enableDFSChnlScan;
   smeConfig.csrConfig.fIgnore_chan165           = pConfig->ignore_chan165;
   smeConfig.csrConfig.fFirstScanOnly2GChnl      = pConfig->enableFirstScan2GOnly;

   //FIXME 11d config is hardcoded
#ifdef WLAN_SOFTAP_FEATURE
   if ( VOS_STA_SAP_MODE != hdd_get_conparam()){
#endif
   smeConfig.csrConfig.Csr11dinfo.Channels.numChannels = 0;

   //if there is a requirement that HDD will control the default channel list & 
   //country code (say from .ini file) we need to add some logic here. Otherwise 
   //the default 11d info should come from NV as per our current implementation
   
#ifdef WLAN_SOFTAP_FEATURE
   }
   else{

    VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
               "AP country Code %s", pConfig->apCntryCode);

    if (memcmp(pConfig->apCntryCode, CFG_AP_COUNTRY_CODE_DEFAULT, 3) != 0)
       sme_setRegInfo(pHddCtx->hHal, pConfig->apCntryCode);
       sme_set11dinfo(pHddCtx->hHal, &smeConfig);
    }
#endif
   hdd_set_power_save_config(pHddCtx, &smeConfig);
   hdd_set_btc_config(pHddCtx);

<<<<<<< HEAD
#ifdef WLAN_FEATURE_VOWIFI_11R
>>>>>>> d97af3b... add prima wlan driver
=======
#ifdef WLAN_FEATURE_VOWIFI_11R   
>>>>>>> 657b0e9... prima update
   smeConfig.csrConfig.csr11rConfig.IsFTResourceReqSupported = pConfig->fFTResourceReqSupported;
#endif
#ifdef FEATURE_WLAN_LFR
   smeConfig.csrConfig.isFastRoamIniFeatureEnabled = pConfig->isFastRoamIniFeatureEnabled;
#endif
#ifdef FEATURE_WLAN_CCX
   smeConfig.csrConfig.isCcxIniFeatureEnabled = pConfig->isCcxIniFeatureEnabled;
<<<<<<< HEAD
<<<<<<< HEAD
=======
   if( pConfig->isCcxIniFeatureEnabled )
   {
       pConfig->isFastTransitionEnabled = TRUE;
   }
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
#endif
#if  defined (WLAN_FEATURE_VOWIFI_11R) || defined (FEATURE_WLAN_CCX) || defined(FEATURE_WLAN_LFR)
   smeConfig.csrConfig.isFastTransitionEnabled = pConfig->isFastTransitionEnabled;
   smeConfig.csrConfig.RoamRssiDiff = pConfig->RoamRssiDiff;
<<<<<<< HEAD
<<<<<<< HEAD
#endif

#ifdef WLAN_FEATURE_NEIGHBOR_ROAMING
   smeConfig.csrConfig.neighborRoamConfig.nNeighborReassocRssiThreshold = pConfig->nNeighborReassocRssiThreshold;
   smeConfig.csrConfig.neighborRoamConfig.nNeighborLookupRssiThreshold = pConfig->nNeighborLookupRssiThreshold;
   smeConfig.csrConfig.neighborRoamConfig.nNeighborScanMaxChanTime = pConfig->nNeighborScanMaxChanTime; 
   smeConfig.csrConfig.neighborRoamConfig.nNeighborScanMinChanTime = pConfig->nNeighborScanMinChanTime; 
   smeConfig.csrConfig.neighborRoamConfig.nNeighborScanTimerPeriod = pConfig->nNeighborScanPeriod;
   smeConfig.csrConfig.neighborRoamConfig.nMaxNeighborRetries = pConfig->nMaxNeighborReqTries; 
   smeConfig.csrConfig.neighborRoamConfig.nNeighborResultsRefreshPeriod = pConfig->nNeighborResultsRefreshPeriod;
   hdd_string_to_u8_array( pConfig->neighborScanChanList, 
                                        smeConfig.csrConfig.neighborRoamConfig.neighborScanChanList.channelList, 
                                        &smeConfig.csrConfig.neighborRoamConfig.neighborScanChanList.numChannels, 
=======
   smeConfig.csrConfig.nImmediateRoamRssiDiff = pConfig->nImmediateRoamRssiDiff;
=======
>>>>>>> 657b0e9... prima update
#endif

#ifdef WLAN_FEATURE_NEIGHBOR_ROAMING
   smeConfig.csrConfig.neighborRoamConfig.nNeighborReassocRssiThreshold = pConfig->nNeighborReassocRssiThreshold;
   smeConfig.csrConfig.neighborRoamConfig.nNeighborLookupRssiThreshold = pConfig->nNeighborLookupRssiThreshold;
   smeConfig.csrConfig.neighborRoamConfig.nNeighborScanMaxChanTime = pConfig->nNeighborScanMaxChanTime; 
   smeConfig.csrConfig.neighborRoamConfig.nNeighborScanMinChanTime = pConfig->nNeighborScanMinChanTime; 
   smeConfig.csrConfig.neighborRoamConfig.nNeighborScanTimerPeriod = pConfig->nNeighborScanPeriod;
   smeConfig.csrConfig.neighborRoamConfig.nMaxNeighborRetries = pConfig->nMaxNeighborReqTries; 
   smeConfig.csrConfig.neighborRoamConfig.nNeighborResultsRefreshPeriod = pConfig->nNeighborResultsRefreshPeriod;
<<<<<<< HEAD
   smeConfig.csrConfig.neighborRoamConfig.nEmptyScanRefreshPeriod = pConfig->nEmptyScanRefreshPeriod;
   hdd_string_to_u8_array( pConfig->neighborScanChanList,
                                        smeConfig.csrConfig.neighborRoamConfig.neighborScanChanList.channelList,
                                        &smeConfig.csrConfig.neighborRoamConfig.neighborScanChanList.numChannels,
>>>>>>> d97af3b... add prima wlan driver
=======
   hdd_string_to_u8_array( pConfig->neighborScanChanList, 
                                        smeConfig.csrConfig.neighborRoamConfig.neighborScanChanList.channelList, 
                                        &smeConfig.csrConfig.neighborRoamConfig.neighborScanChanList.numChannels, 
>>>>>>> 657b0e9... prima update
                                        WNI_CFG_VALID_CHANNEL_LIST_LEN );
#endif

   smeConfig.csrConfig.addTSWhenACMIsOff = pConfig->AddTSWhenACMIsOff;
   smeConfig.csrConfig.fValidateList = pConfig->fValidateScanList;

<<<<<<< HEAD
<<<<<<< HEAD
   //Enable/Disable MCC 
   smeConfig.csrConfig.fEnableMCCMode = pConfig->enableMCC;
   smeConfig.csrConfig.fAllowMCCGODiffBI = pConfig->allowMCCGODiffBI;

   halStatus = sme_UpdateConfig( pHddCtx->hHal, &smeConfig);    
=======
   //Enable/Disable MCC
   smeConfig.csrConfig.fEnableMCCMode = pConfig->enableMCC;
   smeConfig.csrConfig.fAllowMCCGODiffBI = pConfig->allowMCCGODiffBI;

   //Scan Results Aging Time out value
   smeConfig.csrConfig.scanCfgAgingTime = pConfig->scanAgingTimeout;

   smeConfig.csrConfig.enableTxLdpc = pConfig->enableTxLdpc;

   smeConfig.csrConfig.isAmsduSupportInAMPDU = pConfig->isAmsduSupportInAMPDU;

   /* update SSR config */
   sme_UpdateEnableSSR((tHalHandle)(pHddCtx->hHal), pHddCtx->cfg_ini->enableSSR);
   /* Update the Directed scan offload setting */
   smeConfig.fScanOffload =  pHddCtx->cfg_ini->fScanOffload;

   halStatus = sme_UpdateConfig( pHddCtx->hHal, &smeConfig);
>>>>>>> d97af3b... add prima wlan driver
=======
   //Enable/Disable MCC 
   smeConfig.csrConfig.fEnableMCCMode = pConfig->enableMCC;
   smeConfig.csrConfig.fAllowMCCGODiffBI = pConfig->allowMCCGODiffBI;

   halStatus = sme_UpdateConfig( pHddCtx->hHal, &smeConfig);    
>>>>>>> 657b0e9... prima update
   if ( !HAL_STATUS_SUCCESS( halStatus ) )
   {
      status = VOS_STATUS_E_FAILURE;
   }

<<<<<<< HEAD
<<<<<<< HEAD
   
   return status;   
=======

   return status;
>>>>>>> d97af3b... add prima wlan driver
=======
   
   return status;   
>>>>>>> 657b0e9... prima update
}


/**---------------------------------------------------------------------------

  \brief hdd_execute_config_command() -

   This function executes an arbitrary configuration set command

  \param - pHddCtx - Pointer to the HDD Adapter.
  \parmm - command - a configuration command of the form:
                     <name>=<value>

  \return - 0 for success, non zero for failure

  --------------------------------------------------------------------------*/

VOS_STATUS hdd_execute_config_command(hdd_context_t *pHddCtx, char *command)
{
   size_t tableSize = sizeof(g_registry_table)/sizeof(g_registry_table[0]);
   REG_TABLE_ENTRY *pRegEntry;
   char *clone;
   char *pCmd;
   void *pField;
   char *name;
   char *value_str;
   v_U32_t value;
   v_S31_t svalue;
   size_t len_value_str;
   unsigned int idx;
   unsigned int i;
   VOS_STATUS vstatus;
<<<<<<< HEAD
<<<<<<< HEAD
=======
   int rv;
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update

   // assume failure until proven otherwise
   vstatus = VOS_STATUS_E_FAILURE;

   // clone the command so that we can manipulate it
   clone = kstrdup(command, GFP_ATOMIC);
   if (NULL == clone)
   {
      hddLog(LOGE, "%s: memory allocation failure, unable to process [%s]",
<<<<<<< HEAD
<<<<<<< HEAD
             __FUNCTION__, command);
=======
             __func__, command);
>>>>>>> d97af3b... add prima wlan driver
=======
             __FUNCTION__, command);
>>>>>>> 657b0e9... prima update
      return vstatus;
   }

   // 'clone' will point to the beginning of the string so it can be freed
   // 'pCmd' will be used to walk/parse the command
   pCmd = clone;

   // get rid of leading/trailing whitespace
   pCmd = i_trim(pCmd);
   if ('\0' == *pCmd)
   {
      // only whitespace
      hddLog(LOGE, "%s: invalid command, only whitespace:[%s]",
<<<<<<< HEAD
<<<<<<< HEAD
             __FUNCTION__, command);
=======
             __func__, command);
>>>>>>> d97af3b... add prima wlan driver
=======
             __FUNCTION__, command);
>>>>>>> 657b0e9... prima update
      goto done;
   }

   // parse the <name> = <value>
   name = pCmd;
   while (('=' != *pCmd) && ('\0' != *pCmd))
   {
      pCmd++;
   }
   if ('\0' == *pCmd)
   {
      // did not find '='
      hddLog(LOGE, "%s: invalid command, no '=':[%s]",
<<<<<<< HEAD
<<<<<<< HEAD
             __FUNCTION__, command);
=======
             __func__, command);
>>>>>>> d97af3b... add prima wlan driver
=======
             __FUNCTION__, command);
>>>>>>> 657b0e9... prima update
      goto done;
   }

   // replace '=' with NUL to terminate the <name>
   *pCmd++ = '\0';
   name = i_trim(name);
   if ('\0' == *name)
   {
      // did not find a name
      hddLog(LOGE, "%s: invalid command, no <name>:[%s]",
<<<<<<< HEAD
<<<<<<< HEAD
             __FUNCTION__, command);
=======
             __func__, command);
>>>>>>> d97af3b... add prima wlan driver
=======
             __FUNCTION__, command);
>>>>>>> 657b0e9... prima update
      goto done;
   }

   value_str = i_trim(pCmd);
   if ('\0' == *value_str)
   {
      // did not find a value
      hddLog(LOGE, "%s: invalid command, no <value>:[%s]",
<<<<<<< HEAD
<<<<<<< HEAD
             __FUNCTION__, command);
=======
             __func__, command);
>>>>>>> d97af3b... add prima wlan driver
=======
             __FUNCTION__, command);
>>>>>>> 657b0e9... prima update
      goto done;
   }

   // lookup the configuration item
   for (idx = 0; idx < tableSize; idx++)
   {
      if (0 == strcmp(name, g_registry_table[idx].RegName))
      {
         // found a match
         break;
      }
   }
   if (tableSize == idx)
   {
      // did not match the name
      hddLog(LOGE, "%s: invalid command, unknown configuration item:[%s]",
<<<<<<< HEAD
<<<<<<< HEAD
             __FUNCTION__, command);
=======
             __func__, command);
>>>>>>> d97af3b... add prima wlan driver
=======
             __FUNCTION__, command);
>>>>>>> 657b0e9... prima update
      goto done;
   }

   pRegEntry = &g_registry_table[idx];
   if (!(pRegEntry->Flags & VAR_FLAGS_DYNAMIC_CFG))
   {
      // does not support dynamic configuration
      hddLog(LOGE, "%s: invalid command, %s does not support "
<<<<<<< HEAD
<<<<<<< HEAD
             "dynamic configuration", __FUNCTION__, name);
=======
             "dynamic configuration", __func__, name);
>>>>>>> d97af3b... add prima wlan driver
=======
             "dynamic configuration", __FUNCTION__, name);
>>>>>>> 657b0e9... prima update
      goto done;
   }

   pField = ((v_U8_t *)pHddCtx->cfg_ini) + pRegEntry->VarOffset;

   switch (pRegEntry->RegType)
   {
   case WLAN_PARAM_Integer:
<<<<<<< HEAD
<<<<<<< HEAD
      value = simple_strtoul(value_str, NULL, 10);
=======
      rv = kstrtoul(value_str, 10, &value);
      if (rv < 0)
          goto done;
>>>>>>> d97af3b... add prima wlan driver
=======
      value = simple_strtoul(value_str, NULL, 10);
>>>>>>> 657b0e9... prima update
      if (value < pRegEntry->VarMin)
      {
         // out of range
         hddLog(LOGE, "%s: invalid command, value %u < min value %u",
<<<<<<< HEAD
<<<<<<< HEAD
                __FUNCTION__, value, pRegEntry->VarMin);
=======
                __func__, value, pRegEntry->VarMin);
>>>>>>> d97af3b... add prima wlan driver
=======
                __FUNCTION__, value, pRegEntry->VarMin);
>>>>>>> 657b0e9... prima update
         goto done;
      }
      if (value > pRegEntry->VarMax)
      {
         // out of range
         hddLog(LOGE, "%s: invalid command, value %u > max value %u",
<<<<<<< HEAD
<<<<<<< HEAD
                __FUNCTION__, value, pRegEntry->VarMax);
=======
                __func__, value, pRegEntry->VarMax);
>>>>>>> d97af3b... add prima wlan driver
=======
                __FUNCTION__, value, pRegEntry->VarMax);
>>>>>>> 657b0e9... prima update
         goto done;
      }
      memcpy(pField, &value, pRegEntry->VarSize);
      break;

   case WLAN_PARAM_HexInteger:
<<<<<<< HEAD
<<<<<<< HEAD
      value = simple_strtoul(value_str, NULL, 16);
=======
      rv = kstrtoul(value_str, 16, &value);
      if (rv < 0)
         goto done;
>>>>>>> d97af3b... add prima wlan driver
=======
      value = simple_strtoul(value_str, NULL, 16);
>>>>>>> 657b0e9... prima update
      if (value < pRegEntry->VarMin)
      {
         // out of range
         hddLog(LOGE, "%s: invalid command, value %x < min value %x",
<<<<<<< HEAD
<<<<<<< HEAD
                __FUNCTION__, value, pRegEntry->VarMin);
=======
                __func__, value, pRegEntry->VarMin);
>>>>>>> d97af3b... add prima wlan driver
=======
                __FUNCTION__, value, pRegEntry->VarMin);
>>>>>>> 657b0e9... prima update
         goto done;
      }
      if (value > pRegEntry->VarMax)
      {
         // out of range
         hddLog(LOGE, "%s: invalid command, value %x > max value %x",
<<<<<<< HEAD
<<<<<<< HEAD
                __FUNCTION__, value, pRegEntry->VarMax);
=======
                __func__, value, pRegEntry->VarMax);
>>>>>>> d97af3b... add prima wlan driver
=======
                __FUNCTION__, value, pRegEntry->VarMax);
>>>>>>> 657b0e9... prima update
         goto done;
      }
      memcpy(pField, &value, pRegEntry->VarSize);
      break;

   case WLAN_PARAM_SignedInteger:
<<<<<<< HEAD
<<<<<<< HEAD
      svalue = simple_strtol(value_str, NULL, 10);
=======
      rv = kstrtol(value_str, 10, &svalue);
      if (rv < 0)
         goto done;
>>>>>>> d97af3b... add prima wlan driver
=======
      svalue = simple_strtol(value_str, NULL, 10);
>>>>>>> 657b0e9... prima update
      if (svalue < (v_S31_t)pRegEntry->VarMin)
      {
         // out of range
         hddLog(LOGE, "%s: invalid command, value %d < min value %d",
<<<<<<< HEAD
<<<<<<< HEAD
                __FUNCTION__, svalue, (int)pRegEntry->VarMin);
=======
                __func__, svalue, (int)pRegEntry->VarMin);
>>>>>>> d97af3b... add prima wlan driver
=======
                __FUNCTION__, svalue, (int)pRegEntry->VarMin);
>>>>>>> 657b0e9... prima update
         goto done;
      }
      if (svalue > (v_S31_t)pRegEntry->VarMax)
      {
         // out of range
         hddLog(LOGE, "%s: invalid command, value %d > max value %d",
<<<<<<< HEAD
<<<<<<< HEAD
                __FUNCTION__, svalue, (int)pRegEntry->VarMax);
=======
                __func__, svalue, (int)pRegEntry->VarMax);
>>>>>>> d97af3b... add prima wlan driver
=======
                __FUNCTION__, svalue, (int)pRegEntry->VarMax);
>>>>>>> 657b0e9... prima update
         goto done;
      }
      memcpy(pField, &svalue, pRegEntry->VarSize);
      break;

   case WLAN_PARAM_String:
      len_value_str = strlen(value_str);
      if (len_value_str > (pRegEntry->VarSize - 1))
      {
         // too big
         hddLog(LOGE,
                "%s: invalid command, string [%s] length "
                "%u exceeds maximum length %u",
<<<<<<< HEAD
<<<<<<< HEAD
                __FUNCTION__, value_str,
=======
                __func__, value_str,
>>>>>>> d97af3b... add prima wlan driver
=======
                __FUNCTION__, value_str,
>>>>>>> 657b0e9... prima update
                len_value_str, (pRegEntry->VarSize - 1));
         goto done;
      }
      // copy string plus NUL
      memcpy(pField, value_str, (len_value_str + 1));
      break;

   case WLAN_PARAM_MacAddr:
      len_value_str = strlen(value_str);
      if (len_value_str != (VOS_MAC_ADDR_SIZE * 2))
      {
         // out of range
         hddLog(LOGE,
                "%s: invalid command, MAC address [%s] length "
                "%u is not expected length %u",
<<<<<<< HEAD
<<<<<<< HEAD
                __FUNCTION__, value_str,
=======
                __func__, value_str,
>>>>>>> d97af3b... add prima wlan driver
=======
                __FUNCTION__, value_str,
>>>>>>> 657b0e9... prima update
                len_value_str, (VOS_MAC_ADDR_SIZE * 2));
         goto done;
      }
      //parse the string and store it in the byte array
      for (i = 0; i < VOS_MAC_ADDR_SIZE; i++)
      {
         ((char*)pField)[i] = (char)
            ((parseHexDigit(value_str[(i * 2)]) * 16) +
             parseHexDigit(value_str[(i * 2) + 1]));
      }
      break;

   default:
      goto done;
   }

   // if we get here, we had a successful modification
   vstatus = VOS_STATUS_SUCCESS;

   // config table has been modified, is there a notifier?
   if (NULL != pRegEntry->pfnDynamicNotify)
   {
      (pRegEntry->pfnDynamicNotify)(pHddCtx, pRegEntry->NotifyId);
   }

   // note that this item was explicitly configured
   if (idx < MAX_CFG_INI_ITEMS)
   {
      set_bit(idx, (void *)&pHddCtx->cfg_ini->bExplicitCfg);
   }
 done:
   kfree(clone);
   return vstatus;
}
<<<<<<< HEAD
<<<<<<< HEAD
=======

/**---------------------------------------------------------------------------

  \brief hdd_is_okc_mode_enabled() -

   This function returns whether OKC mode is enabled or not

  \param - pHddCtx - Pointer to the HDD Adapter.

  \return - 1 for enabled, zero for disabled

  --------------------------------------------------------------------------*/

tANI_BOOLEAN hdd_is_okc_mode_enabled(hdd_context_t *pHddCtx)
{
    if (NULL == pHddCtx)
    {
        hddLog(VOS_TRACE_LEVEL_FATAL, "%s: pHddCtx is NULL", __func__);
        return -EINVAL;
    }

#ifdef FEATURE_WLAN_OKC
    return pHddCtx->cfg_ini->isOkcIniFeatureEnabled;
#else
    return eANI_BOOLEAN_FALSE;
#endif
}
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
