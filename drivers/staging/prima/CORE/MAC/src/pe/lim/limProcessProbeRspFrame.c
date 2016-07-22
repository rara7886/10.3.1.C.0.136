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

/*
 *
 * Airgo Networks, Inc proprietary. All rights reserved.
 * This file limProcessProbeRspFrame.cc contains the code
 * for processing Probe Response Frame.
 * Author:        Chandra Modumudi
 * Date:          03/01/02
 * History:-
 * Date           Modified by    Modification Information
 * --------------------------------------------------------------------
 *
 */

#include "wniApi.h"
<<<<<<< HEAD
<<<<<<< HEAD
#ifdef ANI_PRODUCT_TYPE_AP
#include "wniCfgAp.h"
#else
#include "wniCfgSta.h"
#endif
#include "aniGlobal.h"
#ifdef FEATURE_WLAN_NON_INTEGRATED_SOC
#include "halCommonApi.h"
#endif
=======
=======
#ifdef ANI_PRODUCT_TYPE_AP
#include "wniCfgAp.h"
#else
>>>>>>> 657b0e9... prima update
#include "wniCfgSta.h"
#endif
#include "aniGlobal.h"
<<<<<<< HEAD
>>>>>>> d97af3b... add prima wlan driver
=======
#ifdef FEATURE_WLAN_NON_INTEGRATED_SOC
#include "halCommonApi.h"
#endif
>>>>>>> 657b0e9... prima update
#include "schApi.h"
#include "utilsApi.h"
#include "limApi.h"
#include "limTypes.h"
#include "limUtils.h"
#include "limAssocUtils.h"
#include "limPropExtsUtils.h"
#include "limSerDesUtils.h"
#include "limSendMessages.h"

#include "parserApi.h"

<<<<<<< HEAD
<<<<<<< HEAD
=======
tSirRetStatus
limValidateIEInformationInProbeRspFrame (tANI_U8 *pRxPacketInfo)
{
   tSirRetStatus       status = eSIR_SUCCESS;

   if (WDA_GET_RX_PAYLOAD_LEN(pRxPacketInfo) < (SIR_MAC_B_PR_SSID_OFFSET + SIR_MAC_MIN_IE_LEN))
   {
      status = eSIR_FAILURE;
   }

   return status;
}

>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
/**
 * limProcessProbeRspFrame
 *
 *FUNCTION:
 * This function is called by limProcessMessageQueue() upon
 * Probe Response frame reception.
 *
 *LOGIC:
 * This function processes received Probe Response frame.
 *
 *ASSUMPTIONS:
 *
 *NOTE:
 * 1. Frames with out-of-order IEs are dropped.
 * 2. In case of IBSS, join 'success' makes MLM state machine
 *    transition into 'BSS started' state. This may have to change
 *    depending on supporting what kinda Authentication in IBSS.
 *
 * @param pMac   Pointer to Global MAC structure
 * @param  *pRxPacketInfo  A pointer to Buffer descriptor + associated PDUs
 * @return None
 */


void
limProcessProbeRspFrame(tpAniSirGlobal pMac, tANI_U8 *pRxPacketInfo,tpPESession psessionEntry)
{
    tANI_U8                 *pBody;
    tANI_U32                frameLen = 0;
    tSirMacAddr             currentBssId;
    tpSirMacMgmtHdr         pHdr;
    tSirProbeRespBeacon    *pProbeRsp;
    tANI_U8 qosEnabled =    false;
    tANI_U8 wmeEnabled =    false;

<<<<<<< HEAD
<<<<<<< HEAD
    if(eHAL_STATUS_SUCCESS != palAllocateMemory(pMac->hHdd, 
                                                (void **)&pProbeRsp, sizeof(tSirProbeRespBeacon)))
    {
        limLog(pMac, LOGE, FL("Unable to PAL allocate memory in limProcessProbeRspFrame\n") );
=======
    pProbeRsp = vos_mem_malloc(sizeof(tSirProbeRespBeacon));
    if ( NULL == pProbeRsp )
    {
        limLog(pMac, LOGE, FL("Unable to allocate memory in limProcessProbeRspFrame") );
>>>>>>> d97af3b... add prima wlan driver
=======
    if(eHAL_STATUS_SUCCESS != palAllocateMemory(pMac->hHdd, 
                                                (void **)&pProbeRsp, sizeof(tSirProbeRespBeacon)))
    {
        limLog(pMac, LOGE, FL("Unable to PAL allocate memory in limProcessProbeRspFrame\n") );
>>>>>>> 657b0e9... prima update
        return;
    }

    pProbeRsp->ssId.length              = 0;
    pProbeRsp->wpa.length               = 0;
    pProbeRsp->propIEinfo.apName.length = 0;
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
#if (WNI_POLARIS_FW_PACKAGE == ADVANCED)
    pProbeRsp->propIEinfo.aniIndicator  = 0;
    pProbeRsp->propIEinfo.wdsLength     = 0;
#endif
<<<<<<< HEAD
=======
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update


    pHdr = WDA_GET_RX_MAC_HEADER(pRxPacketInfo);


   PELOG2(limLog(pMac, LOG2,
             FL("Received Probe Response frame with length=%d from "),
             WDA_GET_RX_MPDU_LEN(pRxPacketInfo));
    limPrintMacAddr(pMac, pHdr->sa, LOG2);)

<<<<<<< HEAD
<<<<<<< HEAD
   if (limDeactivateMinChannelTimerDuringScan(pMac) != eSIR_SUCCESS)
   {
       palFreeMemory(pMac->hHdd, pProbeRsp);    
       return;
   }

=======
   if (!pMac->fScanOffload)
   {
       if (limDeactivateMinChannelTimerDuringScan(pMac) != eSIR_SUCCESS)
       {
           vos_mem_free(pProbeRsp);
           return;
       }
   }

   // Validate IE information before processing Probe Response Frame
   if (limValidateIEInformationInProbeRspFrame(pRxPacketInfo) != eSIR_SUCCESS)
=======
   if (limDeactivateMinChannelTimerDuringScan(pMac) != eSIR_SUCCESS)
>>>>>>> 657b0e9... prima update
   {
       palFreeMemory(pMac->hHdd, pProbeRsp);    
       return;
   }
>>>>>>> d97af3b... add prima wlan driver


    /**
     * Expect Probe Response only when
     * 1. STA is in scan mode waiting for Beacon/Probe response or
     * 2. STA is waiting for Beacon/Probe Response to announce
     *    join success or
     * 3. STA is in IBSS mode in BSS started state or
     * 4. STA/AP is in learn mode
     * 5. STA in link established state. In this state, the probe response is
     *     expected for two scenarios:
     *     -- As part of heart beat mechanism, probe req is sent out
     *     -- If QoS Info IE in beacon has a different count for EDCA Params,
     *         and EDCA IE is not present in beacon,
     *         then probe req is sent out to get the EDCA params.
     *
     * Ignore Probe Response frame in all other states
     */
<<<<<<< HEAD
<<<<<<< HEAD
        // TO SUPPORT BT-AMP
=======
        /*  */
   // TO SUPPORT BT-AMP
>>>>>>> d97af3b... add prima wlan driver
=======
        // TO SUPPORT BT-AMP
>>>>>>> 657b0e9... prima update
    if (((pMac->lim.gLimMlmState == eLIM_MLM_WT_PROBE_RESP_STATE) ||   //mlm state check should be global - 18th oct
        (pMac->lim.gLimMlmState == eLIM_MLM_PASSIVE_SCAN_STATE) ||     //mlm state check should be global - 18th oct
        (pMac->lim.gLimMlmState == eLIM_MLM_LEARN_STATE) ||            //mlm state check should be global - 18th oct 
        (psessionEntry->limMlmState == eLIM_MLM_WT_JOIN_BEACON_STATE) ||
        (psessionEntry->limMlmState == eLIM_MLM_LINK_ESTABLISHED_STATE) )||
        ((GET_LIM_SYSTEM_ROLE(psessionEntry) == eLIM_STA_IN_IBSS_ROLE) &&
<<<<<<< HEAD
<<<<<<< HEAD
         (psessionEntry->limMlmState == eLIM_MLM_BSS_STARTED_STATE)))
    {
        frameLen = WDA_GET_RX_PAYLOAD_LEN(pRxPacketInfo);

        // Get pointer to Probe Response frame body
        pBody = WDA_GET_RX_MPDU_DATA(pRxPacketInfo);

        if (sirConvertProbeFrame2Struct(pMac, pBody, frameLen, pProbeRsp)
                          ==eSIR_FAILURE)
        {
            PELOG1(limLog(pMac, LOG1,
               FL("PArse error ProbeResponse, length=%d\n"),
               frameLen);)
            palFreeMemory(pMac->hHdd, pProbeRsp);
            return;
        }
                                                                            //To Support BT-AMP                    
=======
        (psessionEntry->limMlmState == eLIM_MLM_BSS_STARTED_STATE)) ||
        pMac->fScanOffload)
=======
         (psessionEntry->limMlmState == eLIM_MLM_BSS_STARTED_STATE)))
>>>>>>> 657b0e9... prima update
    {
        frameLen = WDA_GET_RX_PAYLOAD_LEN(pRxPacketInfo);

        // Get pointer to Probe Response frame body
        pBody = WDA_GET_RX_MPDU_DATA(pRxPacketInfo);

        if (sirConvertProbeFrame2Struct(pMac, pBody, frameLen, pProbeRsp)
                          ==eSIR_FAILURE)
        {
            PELOG1(limLog(pMac, LOG1,
               FL("PArse error ProbeResponse, length=%d\n"),
               frameLen);)
            palFreeMemory(pMac->hHdd, pProbeRsp);
            return;
        }
<<<<<<< HEAD

        if (pMac->fScanOffload)
        {
            limCheckAndAddBssDescription(pMac, pProbeRsp, pRxPacketInfo,
                    eANI_BOOLEAN_FALSE, eANI_BOOLEAN_TRUE);
        }

        //To Support BT-AMP
>>>>>>> d97af3b... add prima wlan driver
=======
                                                                            //To Support BT-AMP                    
>>>>>>> 657b0e9... prima update
        if ((pMac->lim.gLimMlmState == eLIM_MLM_WT_PROBE_RESP_STATE) ||    //mlm state check should be global - 18th oct
            (pMac->lim.gLimMlmState == eLIM_MLM_PASSIVE_SCAN_STATE))
            limCheckAndAddBssDescription(pMac, pProbeRsp, pRxPacketInfo, 
               ((pMac->lim.gLimHalScanState == eLIM_HAL_SCANNING_STATE) ? eANI_BOOLEAN_TRUE : eANI_BOOLEAN_FALSE), eANI_BOOLEAN_TRUE);
        else if (pMac->lim.gLimMlmState == eLIM_MLM_LEARN_STATE)           //mlm state check should be global - 18th oct
        {
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
#if defined(ANI_PRODUCT_TYPE_AP) && (WNI_POLARIS_FW_PACKAGE == ADVANCED)
            // STA/AP is in learn mode
            /* Not sure whether the below 2 lines are needed for the station. TODO If yes, this should be 
             * uncommented. Also when we tested enabling this, there is a crash as soon as the station
             * comes up which needs to be fixed*/
            //if (pMac->lim.gLimSystemRole == eLIM_STA_ROLE)
              //  limCheckAndAddBssDescription(pMac, pProbeRsp, pRxPacketInfo, eANI_BOOLEAN_TRUE);
            limCollectMeasurementData(pMac, pRxPacketInfo, pProbeRsp);
           PELOG3(limLog(pMac, LOG3,
               FL("Parsed WDS info in ProbeRsp frames: wdsLength=%d\n"),
               pProbeRsp->propIEinfo.wdsLength);)
#endif
<<<<<<< HEAD
=======
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
        }
        else if (psessionEntry->limMlmState ==
                                     eLIM_MLM_WT_JOIN_BEACON_STATE)
        {
            if( psessionEntry->beacon != NULL )//Either Beacon/probe response is required. Hence store it in same buffer.
            {
<<<<<<< HEAD
<<<<<<< HEAD
                palFreeMemory(pMac->hHdd, psessionEntry->beacon);
                psessionEntry->beacon = NULL;
            }
            psessionEntry->bcnLen = WDA_GET_RX_PAYLOAD_LEN(pRxPacketInfo);
            if ((palAllocateMemory(pMac->hHdd, (void**)&psessionEntry->beacon,
                                   psessionEntry->bcnLen))
                != eHAL_STATUS_SUCCESS)
=======
                vos_mem_free(psessionEntry->beacon);
                psessionEntry->beacon = NULL;
            }
            psessionEntry->bcnLen = WDA_GET_RX_PAYLOAD_LEN(pRxPacketInfo);

            psessionEntry->beacon = vos_mem_malloc(psessionEntry->bcnLen);
            if ( NULL == psessionEntry->beacon )
>>>>>>> d97af3b... add prima wlan driver
=======
                palFreeMemory(pMac->hHdd, psessionEntry->beacon);
                psessionEntry->beacon = NULL;
            }
            psessionEntry->bcnLen = WDA_GET_RX_PAYLOAD_LEN(pRxPacketInfo);
            if ((palAllocateMemory(pMac->hHdd, (void**)&psessionEntry->beacon,
                                   psessionEntry->bcnLen))
                != eHAL_STATUS_SUCCESS)
>>>>>>> 657b0e9... prima update
            {
                PELOGE(limLog(pMac, LOGE,
                              FL("Unable to allocate memory to store beacon"));)
            }
            else
            {
                //Store the Beacon/ProbeRsp. This is sent to csr/hdd in join cnf response. 
<<<<<<< HEAD
<<<<<<< HEAD
                palCopyMemory(pMac->hHdd, psessionEntry->beacon,
                              WDA_GET_RX_MPDU_DATA(pRxPacketInfo),
                              psessionEntry->bcnLen);
=======
                vos_mem_copy(psessionEntry->beacon,
                             WDA_GET_RX_MPDU_DATA(pRxPacketInfo),
                             psessionEntry->bcnLen);
>>>>>>> d97af3b... add prima wlan driver
=======
                palCopyMemory(pMac->hHdd, psessionEntry->beacon,
                              WDA_GET_RX_MPDU_DATA(pRxPacketInfo),
                              psessionEntry->bcnLen);
>>>>>>> 657b0e9... prima update
            }

            // STA in WT_JOIN_BEACON_STATE
            limCheckAndAnnounceJoinSuccess(pMac, pProbeRsp, pHdr, psessionEntry);
        }
        else if(psessionEntry->limMlmState == eLIM_MLM_LINK_ESTABLISHED_STATE)
        {
            tpDphHashNode pStaDs = NULL;
            /**
             * Check if this Probe Response is for
            * our Probe Request sent upon reaching
            * heart beat threshold
            */
            #if 0
            if (wlan_cfgGetStr(pMac,
                          WNI_CFG_BSSID,
                          currentBssId,
                          &cfg) != eSIR_SUCCESS)
            {
                /// Could not get BSSID from CFG. Log error.
<<<<<<< HEAD
<<<<<<< HEAD
                limLog(pMac, LOGP, FL("could not retrieve BSSID\n"));
=======
                limLog(pMac, LOGP, FL("could not retrieve BSSID"));
>>>>>>> d97af3b... add prima wlan driver
=======
                limLog(pMac, LOGP, FL("could not retrieve BSSID\n"));
>>>>>>> 657b0e9... prima update
            }
            #endif //TO SUPPORT BT-AMP
            sirCopyMacAddr(currentBssId,psessionEntry->bssId);

<<<<<<< HEAD
<<<<<<< HEAD
            if ( !palEqualMemory( pMac->hHdd,currentBssId, pHdr->bssId, sizeof(tSirMacAddr)) )
            {
                palFreeMemory(pMac->hHdd, pProbeRsp);    
=======
            if ( !vos_mem_compare(currentBssId, pHdr->bssId, sizeof(tSirMacAddr)) )
            {
                vos_mem_free(pProbeRsp);
>>>>>>> d97af3b... add prima wlan driver
=======
            if ( !palEqualMemory( pMac->hHdd,currentBssId, pHdr->bssId, sizeof(tSirMacAddr)) )
            {
                palFreeMemory(pMac->hHdd, pProbeRsp);    
>>>>>>> 657b0e9... prima update
                return;
            }

            if (!LIM_IS_CONNECTION_ACTIVE(psessionEntry))
            {
                limLog(pMac, LOGW,
<<<<<<< HEAD
<<<<<<< HEAD
                    FL("Received Probe Resp from AP. So it is alive!!\n"));
=======
                    FL("Received Probe Resp from AP. So it is alive!!"));
>>>>>>> d97af3b... add prima wlan driver
=======
                    FL("Received Probe Resp from AP. So it is alive!!\n"));
>>>>>>> 657b0e9... prima update

                if (pProbeRsp->HTInfo.present)
                    limReceivedHBHandler(pMac, (tANI_U8)pProbeRsp->HTInfo.primaryChannel, psessionEntry);
                else
                    limReceivedHBHandler(pMac, (tANI_U8)pProbeRsp->channelNumber, psessionEntry);
            }

<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
#if defined ANI_PRODUCT_TYPE_CLIENT || defined (ANI_AP_CLIENT_SDK)
            
            if (psessionEntry->limSystemRole == eLIM_STA_ROLE)
            {
                if (pProbeRsp->quietIEPresent)
                {
                    limUpdateQuietIEFromBeacon(pMac, &(pProbeRsp->quietIE), psessionEntry);
                }
                else if ((psessionEntry->gLimSpecMgmt.quietState == eLIM_QUIET_BEGIN) ||
                     (psessionEntry->gLimSpecMgmt.quietState == eLIM_QUIET_RUNNING))
                {
                    PELOG1(limLog(pMac, LOG1, FL("Received a probe rsp without Quiet IE\n"));)
                    limCancelDot11hQuiet(pMac, psessionEntry);
                }

<<<<<<< HEAD
=======
            
            if (psessionEntry->limSystemRole == eLIM_STA_ROLE)
            {
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
                if (pProbeRsp->channelSwitchPresent ||
                    pProbeRsp->propIEinfo.propChannelSwitchPresent)
                {
                    limUpdateChannelSwitch(pMac, pProbeRsp, psessionEntry);
                }
                else if (psessionEntry->gLimSpecMgmt.dot11hChanSwState == eLIM_11H_CHANSW_RUNNING)
                {
                    limCancelDot11hChannelSwitch(pMac, psessionEntry);
                }
            }
        
<<<<<<< HEAD
<<<<<<< HEAD
#endif
=======
>>>>>>> d97af3b... add prima wlan driver
=======
#endif
>>>>>>> 657b0e9... prima update
            
            /**
            * Now Process EDCA Parameters, if EDCAParamSet count is different.
            *     -- While processing beacons in link established state if it is determined that
            *         QoS Info IE has a different count for EDCA Params,
            *         and EDCA IE is not present in beacon,
            *         then probe req is sent out to get the EDCA params.
            */

            pStaDs = dphGetHashEntry(pMac, DPH_STA_HASH_INDEX_PEER, &psessionEntry->dph.dphHashTable);

            limGetQosMode(psessionEntry, &qosEnabled);
            limGetWmeMode(psessionEntry, &wmeEnabled);
           PELOG2(limLog(pMac, LOG2,
<<<<<<< HEAD
<<<<<<< HEAD
                    FL("wmeEdcaPresent: %d wmeEnabled: %d, edcaPresent: %d, qosEnabled: %d,  edcaParams.qosInfo.count: %d schObject.gLimEdcaParamSetCount: %d\n"),
=======
                    FL("wmeEdcaPresent: %d wmeEnabled: %d, edcaPresent: %d, qosEnabled: %d,  edcaParams.qosInfo.count: %d schObject.gLimEdcaParamSetCount: %d"),
>>>>>>> d97af3b... add prima wlan driver
=======
                    FL("wmeEdcaPresent: %d wmeEnabled: %d, edcaPresent: %d, qosEnabled: %d,  edcaParams.qosInfo.count: %d schObject.gLimEdcaParamSetCount: %d\n"),
>>>>>>> 657b0e9... prima update
                          pProbeRsp->wmeEdcaPresent, wmeEnabled, pProbeRsp->edcaPresent, qosEnabled,
                          pProbeRsp->edcaParams.qosInfo.count, psessionEntry->gLimEdcaParamSetCount);)
            if (((pProbeRsp->wmeEdcaPresent && wmeEnabled) ||
                (pProbeRsp->edcaPresent && qosEnabled)) &&
                (pProbeRsp->edcaParams.qosInfo.count != psessionEntry->gLimEdcaParamSetCount))
            {
                if (schBeaconEdcaProcess(pMac, &pProbeRsp->edcaParams, psessionEntry) != eSIR_SUCCESS)
<<<<<<< HEAD
<<<<<<< HEAD
                    PELOGE(limLog(pMac, LOGE, FL("EDCA parameter processing error\n"));)
=======
                    PELOGE(limLog(pMac, LOGE, FL("EDCA parameter processing error"));)
>>>>>>> d97af3b... add prima wlan driver
=======
                    PELOGE(limLog(pMac, LOGE, FL("EDCA parameter processing error\n"));)
>>>>>>> 657b0e9... prima update
                else if (pStaDs != NULL)
                {
                    // If needed, downgrade the EDCA parameters
                    limSetActiveEdcaParams(pMac, psessionEntry->gLimEdcaParams, psessionEntry); 

                    if (pStaDs->aniPeer == eANI_BOOLEAN_TRUE)
                        limSendEdcaParams(pMac, psessionEntry->gLimEdcaParamsActive, pStaDs->bssId, eANI_BOOLEAN_TRUE);
                    else
                        limSendEdcaParams(pMac, psessionEntry->gLimEdcaParamsActive, pStaDs->bssId, eANI_BOOLEAN_FALSE);
                }
                else
<<<<<<< HEAD
<<<<<<< HEAD
                    PELOGE(limLog(pMac, LOGE, FL("Self Entry missing in Hash Table\n"));)

            }
=======
                    PELOGE(limLog(pMac, LOGE, FL("Self Entry missing in Hash Table"));)

            }

           if (psessionEntry->fWaitForProbeRsp == true)
           {
               limLog(pMac, LOGW, FL("Checking probe response for capability change\n") );
               limDetectChangeInApCapabilities(pMac, pProbeRsp, psessionEntry);
           }
>>>>>>> d97af3b... add prima wlan driver
=======
                    PELOGE(limLog(pMac, LOGE, FL("Self Entry missing in Hash Table\n"));)

            }
>>>>>>> 657b0e9... prima update
        }
        else if ((psessionEntry->limSystemRole == eLIM_STA_IN_IBSS_ROLE) &&
                 (psessionEntry->limMlmState == eLIM_MLM_BSS_STARTED_STATE))
                limHandleIBSScoalescing(pMac, pProbeRsp, pRxPacketInfo,psessionEntry);
    } // if ((pMac->lim.gLimMlmState == eLIM_MLM_WT_PROBE_RESP_STATE) || ...

<<<<<<< HEAD
<<<<<<< HEAD
    palFreeMemory(pMac->hHdd, pProbeRsp);
=======
    vos_mem_free(pProbeRsp);
>>>>>>> d97af3b... add prima wlan driver
=======
    palFreeMemory(pMac->hHdd, pProbeRsp);
>>>>>>> 657b0e9... prima update
    // Ignore Probe Response frame in all other states
    return;
} /*** end limProcessProbeRspFrame() ***/


void
limProcessProbeRspFrameNoSession(tpAniSirGlobal pMac, tANI_U8 *pRxPacketInfo)
{
    tANI_U8                 *pBody;
    tANI_U32                frameLen = 0;
    tpSirMacMgmtHdr         pHdr;
    tSirProbeRespBeacon    *pProbeRsp;

<<<<<<< HEAD
<<<<<<< HEAD
    if(eHAL_STATUS_SUCCESS != palAllocateMemory(pMac->hHdd, 
                                                (void **)&pProbeRsp, sizeof(tSirProbeRespBeacon)))
    {
        limLog(pMac, LOGE, FL("Unable to PAL allocate memory in limProcessProbeRspFrameNoSession\n") );
=======
    pProbeRsp = vos_mem_malloc(sizeof(tSirProbeRespBeacon));
    if ( NULL == pProbeRsp )
    {
        limLog(pMac, LOGE, FL("Unable to allocate memory in limProcessProbeRspFrameNoSession") );
>>>>>>> d97af3b... add prima wlan driver
=======
    if(eHAL_STATUS_SUCCESS != palAllocateMemory(pMac->hHdd, 
                                                (void **)&pProbeRsp, sizeof(tSirProbeRespBeacon)))
    {
        limLog(pMac, LOGE, FL("Unable to PAL allocate memory in limProcessProbeRspFrameNoSession\n") );
>>>>>>> 657b0e9... prima update
        return;
    }

    pProbeRsp->ssId.length              = 0;
    pProbeRsp->wpa.length               = 0;
    pProbeRsp->propIEinfo.apName.length = 0;
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
#if (WNI_POLARIS_FW_PACKAGE == ADVANCED)
    pProbeRsp->propIEinfo.aniIndicator  = 0;
    pProbeRsp->propIEinfo.wdsLength     = 0;
#endif
<<<<<<< HEAD
=======
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update


    pHdr = WDA_GET_RX_MAC_HEADER(pRxPacketInfo);


    limLog(pMac, LOG2,
             FL("Received Probe Response frame with length=%d from "),
             WDA_GET_RX_MPDU_LEN(pRxPacketInfo));
    limPrintMacAddr(pMac, pHdr->sa, LOG2);

<<<<<<< HEAD
<<<<<<< HEAD
    if (limDeactivateMinChannelTimerDuringScan(pMac) != eSIR_SUCCESS)
    {
        palFreeMemory(pMac->hHdd, pProbeRsp);
        return;
    }

=======
#ifdef WLAN_FEATURE_ROAM_SCAN_OFFLOAD
    if (!(WDA_GET_OFFLOADSCANLEARN(pRxPacketInfo) ||
          WDA_GET_ROAMCANDIDATEIND(pRxPacketInfo)))
    {
#endif
        if (!pMac->fScanOffload)
        {
            if (limDeactivateMinChannelTimerDuringScan(pMac) != eSIR_SUCCESS)
            {
                vos_mem_free(pProbeRsp);
                return;
            }
        }
#ifdef WLAN_FEATURE_ROAM_SCAN_OFFLOAD
    }
#endif
     // Validate IE information before processing Probe Response Frame
    if (limValidateIEInformationInProbeRspFrame(pRxPacketInfo) != eSIR_SUCCESS)
=======
    if (limDeactivateMinChannelTimerDuringScan(pMac) != eSIR_SUCCESS)
>>>>>>> 657b0e9... prima update
    {
        palFreeMemory(pMac->hHdd, pProbeRsp);
        return;
    }
<<<<<<< HEAD
>>>>>>> d97af3b... add prima wlan driver
=======

>>>>>>> 657b0e9... prima update
    /*  Since there is no psessionEntry, PE cannot be in the following states:
     *   - eLIM_MLM_WT_JOIN_BEACON_STATE
     *   - eLIM_MLM_LINK_ESTABLISHED_STATE
     *   - eLIM_MLM_BSS_STARTED_STATE
     *  Hence, expect Probe Response only when
     *   1. STA is in scan mode waiting for Beacon/Probe response 
<<<<<<< HEAD
<<<<<<< HEAD
     *  
     *  Ignore Probe Response frame in all other states
     */
    if( (pMac->lim.gLimMlmState == eLIM_MLM_WT_PROBE_RESP_STATE) ||
=======
     *   2. LFR logic in FW sends up candidate frames
     *  
     *  Ignore Probe Response frame in all other states
     */
#ifdef WLAN_FEATURE_ROAM_SCAN_OFFLOAD
    if (WDA_GET_OFFLOADSCANLEARN(pRxPacketInfo))
    {
        frameLen = WDA_GET_RX_PAYLOAD_LEN(pRxPacketInfo);

        if (pMac->lim.gLimBackgroundScanMode == eSIR_ROAMING_SCAN)
        {
            VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_INFO,
                      FL("Probe Resp Frame Received: BSSID " MAC_ADDRESS_STR " (RSSI %d)"),
                      MAC_ADDR_ARRAY(pHdr->bssId),
                      (uint)abs((tANI_S8)WDA_GET_RX_RSSI_DB(pRxPacketInfo)));
        }

        // Get pointer to Probe Response frame body
        pBody = WDA_GET_RX_MPDU_DATA(pRxPacketInfo);

        if (sirConvertProbeFrame2Struct(pMac, pBody, frameLen, pProbeRsp) == eSIR_FAILURE)
        {
            limLog(pMac, LOG1, FL("Parse error ProbeResponse, length=%d\n"), frameLen);
            vos_mem_free(pProbeRsp);
            return;
        }
        limLog( pMac, LOG2, FL("Save this probe rsp in LFR cache"));
        limCheckAndAddBssDescription(pMac, pProbeRsp, pRxPacketInfo,
                                     eANI_BOOLEAN_FALSE, eANI_BOOLEAN_TRUE);
    }
    else
#endif
    if (pMac->fScanOffload)
    {
        frameLen = WDA_GET_RX_PAYLOAD_LEN(pRxPacketInfo);

        // Get pointer to Probe Response frame body
        pBody = WDA_GET_RX_MPDU_DATA(pRxPacketInfo);

        if (sirConvertProbeFrame2Struct(pMac, pBody, frameLen, pProbeRsp)
                == eSIR_FAILURE)
        {
            limLog(pMac, LOG1,
                    FL("Parse error ProbeResponse, length=%d\n"), frameLen);
            vos_mem_free(pProbeRsp);
            return;
        }
        limCheckAndAddBssDescription(pMac, pProbeRsp, pRxPacketInfo,
                eANI_BOOLEAN_FALSE, eANI_BOOLEAN_TRUE);
    }
    else if( (pMac->lim.gLimMlmState == eLIM_MLM_WT_PROBE_RESP_STATE) ||
>>>>>>> d97af3b... add prima wlan driver
=======
     *  
     *  Ignore Probe Response frame in all other states
     */
    if( (pMac->lim.gLimMlmState == eLIM_MLM_WT_PROBE_RESP_STATE) ||
>>>>>>> 657b0e9... prima update
        (pMac->lim.gLimMlmState == eLIM_MLM_PASSIVE_SCAN_STATE)  ||     //mlm state check should be global - 18th oct
        (pMac->lim.gLimMlmState == eLIM_MLM_LEARN_STATE) )
    {
        frameLen = WDA_GET_RX_PAYLOAD_LEN(pRxPacketInfo);

<<<<<<< HEAD
<<<<<<< HEAD
=======
        if (pMac->lim.gLimBackgroundScanMode == eSIR_ROAMING_SCAN)
        {
            VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_INFO,
                      FL("Probe Resp Frame Received: BSSID " MAC_ADDRESS_STR " (RSSI %d)"),
                      MAC_ADDR_ARRAY(pHdr->bssId),
                      (uint)abs((tANI_S8)WDA_GET_RX_RSSI_DB(pRxPacketInfo)));
        }

>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
        // Get pointer to Probe Response frame body
        pBody = WDA_GET_RX_MPDU_DATA(pRxPacketInfo);

        if (sirConvertProbeFrame2Struct(pMac, pBody, frameLen, pProbeRsp) == eSIR_FAILURE)
        {
<<<<<<< HEAD
<<<<<<< HEAD
            limLog(pMac, LOG1, FL("Parse error ProbeResponse, length=%d\n"), frameLen);
            palFreeMemory(pMac->hHdd, pProbeRsp);
=======
            limLog(pMac, LOG1, FL("Parse error ProbeResponse, length=%d"), frameLen);
            vos_mem_free(pProbeRsp);
>>>>>>> d97af3b... add prima wlan driver
=======
            limLog(pMac, LOG1, FL("Parse error ProbeResponse, length=%d\n"), frameLen);
            palFreeMemory(pMac->hHdd, pProbeRsp);
>>>>>>> 657b0e9... prima update
            return;
        }

        if( (pMac->lim.gLimMlmState == eLIM_MLM_WT_PROBE_RESP_STATE) ||
             (pMac->lim.gLimMlmState == eLIM_MLM_PASSIVE_SCAN_STATE) )
            limCheckAndAddBssDescription(pMac, pProbeRsp, pRxPacketInfo, eANI_BOOLEAN_TRUE, eANI_BOOLEAN_TRUE);
        else if (pMac->lim.gLimMlmState == eLIM_MLM_LEARN_STATE)
        {
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
#if defined(ANI_PRODUCT_TYPE_AP) && (WNI_POLARIS_FW_PACKAGE == ADVANCED)
            // STA/AP is in learn mode
            /* Not sure whether the below 2 lines are needed for the station. TODO If yes, this should be 
             * uncommented. Also when we tested enabling this, there is a crash as soon as the station
             * comes up which needs to be fixed*/
            //if (pMac->lim.gLimSystemRole == eLIM_STA_ROLE)
              //  limCheckAndAddBssDescription(pMac, pProbeRsp, pRxPacketInfo, eANI_BOOLEAN_TRUE);
            limCollectMeasurementData(pMac, pRxPacketInfo, pProbeRsp);
            limLog(pMac, LOG3,
               FL("Parsed WDS info in ProbeRsp frames: wdsLength=%d\n"),
               pProbeRsp->propIEinfo.wdsLength);
#endif
<<<<<<< HEAD
        }
    } 
    palFreeMemory(pMac->hHdd, pProbeRsp);
=======
        }
    } 
    vos_mem_free(pProbeRsp);
>>>>>>> d97af3b... add prima wlan driver
=======
        }
    } 
    palFreeMemory(pMac->hHdd, pProbeRsp);
>>>>>>> 657b0e9... prima update
    return;
} /*** end limProcessProbeRspFrameNew() ***/
