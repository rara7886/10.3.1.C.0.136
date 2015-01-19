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
 * This file limProcessAssocRspFrame.cc contains the code
 * for processing Re/Association Response Frame.
 * Author:        Chandra Modumudi
 * Date:          03/18/02
 * History:-
 * Date           Modified by    Modification Information
 * --------------------------------------------------------------------
 *
 */

#include "wniApi.h"
<<<<<<< HEAD
<<<<<<< HEAD
#if (WNI_POLARIS_FW_PRODUCT == AP)
#include "wniCfgAp.h"
#else
#include "wniCfgSta.h"
#endif
=======
#include "wniCfgSta.h"
>>>>>>> d97af3b... add prima wlan driver
=======
#if (WNI_POLARIS_FW_PRODUCT == AP)
#include "wniCfgAp.h"
#else
#include "wniCfgSta.h"
#endif
>>>>>>> 657b0e9... prima update
#include "aniGlobal.h"
#include "cfgApi.h"

#include "utilsApi.h"
#include "pmmApi.h"
#include "limTypes.h"
#include "limUtils.h"
#include "limAssocUtils.h"
#include "limSecurityUtils.h"
#include "limSerDesUtils.h"
#include "limStaHashApi.h"
#include "limSendMessages.h"

#ifdef FEATURE_WLAN_CCX
#include "ccxApi.h"
#endif

extern tSirRetStatus schBeaconEdcaProcess(tpAniSirGlobal pMac, tSirMacEdcaParamSetIE *edca, tpPESession psessionEntry);


/**
 * @function : limUpdateAssocStaDatas
 *
 * @brief :  This function is called to Update the Station Descriptor (dph) Details from
 *                  Association / ReAssociation Response Frame
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 *
 *NOTE:
 *
 * @param  pMac    - Pointer to Global MAC structure
 * @param  pStaDs   - Station Descriptor in DPH
 * @param  pAssocRsp    - Pointer to Association Response Structure
 *
 * @return None
 */
void limUpdateAssocStaDatas(tpAniSirGlobal pMac, tpDphHashNode pStaDs, tpSirAssocRsp pAssocRsp,tpPESession psessionEntry)
{
    tANI_U32        prop;
    tANI_U32        phyMode;
    tANI_U32        val;
    //tpSirBoardCapabilities pBoardCaps;
    tANI_BOOLEAN    qosMode; 
    tANI_U16        rxHighestRate = 0;

    limGetPhyMode(pMac, &phyMode, psessionEntry);

    pStaDs->staType= STA_ENTRY_SELF;

    limGetQosMode(psessionEntry, &qosMode);    
    // set the ani peer bit, if self mode is one of the proprietary modes
    if(IS_DOT11_MODE_PROPRIETARY(psessionEntry->dot11mode)) 
    {
       wlan_cfgGetInt(pMac, WNI_CFG_PROPRIETARY_ANI_FEATURES_ENABLED, &prop);

       if (prop) 
       {
           pStaDs->aniPeer = eHAL_SET;
           pStaDs->propCapability = pAssocRsp->propIEinfo.capability;
       }
    }
    
       //pMac->lim.gLimMlmState         = eLIM_MLM_LINK_ESTABLISHED_STATE;
       pStaDs->mlmStaContext.authType = psessionEntry->limCurrentAuthType;
    
       // Add capabilities information, rates and AID
       pStaDs->mlmStaContext.capabilityInfo = pAssocRsp->capabilityInfo;
       pStaDs->shortPreambleEnabled= (tANI_U8)pAssocRsp->capabilityInfo.shortPreamble;
    
       //Update HT Capabilites only when the self mode supports HT
       if(IS_DOT11_MODE_HT(psessionEntry->dot11mode)) {
           pStaDs->mlmStaContext.htCapability = pAssocRsp->HTCaps.present;
    
           if ( pAssocRsp->HTCaps.present ) {
               pStaDs->htGreenfield = ( tANI_U8 ) pAssocRsp->HTCaps.greenField;
               pStaDs->htSupportedChannelWidthSet = ( tANI_U8 ) (pAssocRsp->HTCaps.supportedChannelWidthSet ? 
                                                                               pAssocRsp->HTInfo.recommendedTxWidthSet : 
                                                                               pAssocRsp->HTCaps.supportedChannelWidthSet );
                   pStaDs->htLsigTXOPProtection = ( tANI_U8 ) pAssocRsp->HTCaps.lsigTXOPProtection;
                   pStaDs->htMIMOPSState =  (tSirMacHTMIMOPowerSaveState)pAssocRsp->HTCaps.mimoPowerSave;
                   pStaDs->htMaxAmsduLength = ( tANI_U8 ) pAssocRsp->HTCaps.maximalAMSDUsize;
                   pStaDs->htAMpduDensity =             pAssocRsp->HTCaps.mpduDensity;
                   pStaDs->htDsssCckRate40MHzSupport = (tANI_U8)pAssocRsp->HTCaps.dsssCckMode40MHz;
                   pStaDs->htShortGI20Mhz = (tANI_U8)pAssocRsp->HTCaps.shortGI20MHz;
                   pStaDs->htShortGI40Mhz = (tANI_U8)pAssocRsp->HTCaps.shortGI40MHz;
                   pStaDs->htMaxRxAMpduFactor = pAssocRsp->HTCaps.maxRxAMPDUFactor;
                   limFillRxHighestSupportedRate(pMac, &rxHighestRate, pAssocRsp->HTCaps.supportedMCSSet);
                   pStaDs->supportedRates.rxHighestDataRate = rxHighestRate;
                   /* This is for AP as peer STA and we are INFRA STA. We will put APs offset in dph node which is peer STA */
                   pStaDs->htSecondaryChannelOffset = (tANI_U8)pAssocRsp->HTInfo.secondaryChannelOffset;

                   //FIXME_AMPDU
                   // In the future, may need to check for "assoc.HTCaps.delayedBA"
                   // For now, it is IMMEDIATE BA only on ALL TID's
                   pStaDs->baPolicyFlag = 0xFF;
           }
       }

#ifdef WLAN_FEATURE_11AC
       if(IS_DOT11_MODE_VHT(psessionEntry->dot11mode))
       {
           pStaDs->mlmStaContext.vhtCapability = pAssocRsp->VHTCaps.present;
       }
<<<<<<< HEAD
<<<<<<< HEAD
       if (limPopulateOwnRateSet(pMac, &pStaDs->supportedRates, 
                                pAssocRsp->HTCaps.supportedMCSSet,
                                false,psessionEntry , &pAssocRsp->VHTCaps) != eSIR_SUCCESS) 
#else
       if (limPopulateOwnRateSet(pMac, &pStaDs->supportedRates, pAssocRsp->HTCaps.supportedMCSSet, false,psessionEntry) != eSIR_SUCCESS) 
#endif
       {
           limLog(pMac, LOGP, FL("could not get rateset and extended rate set\n"));
=======
       if (limPopulatePeerRateSet(pMac, &pStaDs->supportedRates,
=======
       if (limPopulateOwnRateSet(pMac, &pStaDs->supportedRates, 
>>>>>>> 657b0e9... prima update
                                pAssocRsp->HTCaps.supportedMCSSet,
                                false,psessionEntry , &pAssocRsp->VHTCaps) != eSIR_SUCCESS) 
#else
       if (limPopulateOwnRateSet(pMac, &pStaDs->supportedRates, pAssocRsp->HTCaps.supportedMCSSet, false,psessionEntry) != eSIR_SUCCESS) 
#endif
       {
<<<<<<< HEAD
           limLog(pMac, LOGP, FL("could not get rateset and extended rate set"));
>>>>>>> d97af3b... add prima wlan driver
=======
           limLog(pMac, LOGP, FL("could not get rateset and extended rate set\n"));
>>>>>>> 657b0e9... prima update
           return;
       }
   
       //If one of the rates is 11g rates, set the ERP mode.
       if ((phyMode == WNI_CFG_PHY_MODE_11G) && sirIsArate(pStaDs->supportedRates.llaRates[0] & 0x7f))
           pStaDs->erpEnabled = eHAL_SET;
    
    
       val = WNI_CFG_PROPRIETARY_OPERATIONAL_RATE_SET_LEN;
       if (wlan_cfgGetStr(pMac, WNI_CFG_PROPRIETARY_OPERATIONAL_RATE_SET,
                     (tANI_U8 *) &pStaDs->mlmStaContext.propRateSet.propRate,
                     &val) != eSIR_SUCCESS) {
           /// Could not get prop rateset from CFG. Log error.
<<<<<<< HEAD
<<<<<<< HEAD
           limLog(pMac, LOGP, FL("could not retrieve prop rateset\n"));
=======
           limLog(pMac, LOGP, FL("could not retrieve prop rateset"));
>>>>>>> d97af3b... add prima wlan driver
=======
           limLog(pMac, LOGP, FL("could not retrieve prop rateset\n"));
>>>>>>> 657b0e9... prima update
           return;
       }
       pStaDs->mlmStaContext.propRateSet.numPropRates = (tANI_U8) val;
    
       pStaDs->qosMode    = 0;
       pStaDs->lleEnabled = 0;
    
       // update TSID to UP mapping
       //if (pMac->lim.gLimQosEnabled)
       if (qosMode) {
           if (pAssocRsp->edcaPresent) {
               tSirRetStatus status;
               status = schBeaconEdcaProcess(pMac,&pAssocRsp->edca, psessionEntry);
<<<<<<< HEAD
<<<<<<< HEAD
              PELOG2(limLog(pMac, LOG2, "Edca set update based on AssocRsp: status %d\n",
                      status);)
               if (status != eSIR_SUCCESS) {
                   PELOGE(limLog(pMac, LOGE, FL("Edca error in AssocResp \n"));)
=======
              PELOG2(limLog(pMac, LOG2, "Edca set update based on AssocRsp: status %d",
                      status);)
               if (status != eSIR_SUCCESS) {
                   PELOGE(limLog(pMac, LOGE, FL("Edca error in AssocResp "));)
>>>>>>> d97af3b... add prima wlan driver
=======
              PELOG2(limLog(pMac, LOG2, "Edca set update based on AssocRsp: status %d\n",
                      status);)
               if (status != eSIR_SUCCESS) {
                   PELOGE(limLog(pMac, LOGE, FL("Edca error in AssocResp \n"));)
>>>>>>> 657b0e9... prima update
               } else { // update default tidmap based on ACM
                   pStaDs->qosMode    = 1;
                   pStaDs->lleEnabled = 1;
               }
           }
       }
    
       pStaDs->wmeEnabled = 0;
       pStaDs->wsmEnabled = 0;
       if (psessionEntry->limWmeEnabled && pAssocRsp->wmeEdcaPresent)
       {
           tSirRetStatus status;
           status = schBeaconEdcaProcess(pMac,&pAssocRsp->edca, psessionEntry);
<<<<<<< HEAD
<<<<<<< HEAD
           PELOGW(limLog(pMac, LOGW, "WME Edca set update based on AssocRsp: status %d\n", status);)

           if (status != eSIR_SUCCESS)
               PELOGE(limLog(pMac, LOGE, FL("WME Edca error in AssocResp - ignoring\n"));)
=======
           PELOGW(limLog(pMac, LOGW, "WME Edca set update based on AssocRsp: status %d", status);)

           if (status != eSIR_SUCCESS)
               PELOGE(limLog(pMac, LOGE, FL("WME Edca error in AssocResp - ignoring"));)
>>>>>>> d97af3b... add prima wlan driver
=======
           PELOGW(limLog(pMac, LOGW, "WME Edca set update based on AssocRsp: status %d\n", status);)

           if (status != eSIR_SUCCESS)
               PELOGE(limLog(pMac, LOGE, FL("WME Edca error in AssocResp - ignoring\n"));)
>>>>>>> 657b0e9... prima update
           else { // update default tidmap based on HashACM
               pStaDs->qosMode    = 1;
               pStaDs->wmeEnabled = 1;
           }
       } 
       else {
           /* We received assoc rsp from a legacy AP. So fill in the default 
            * local EDCA params. This is needed (refer to bug #14989) as we'll 
            * be passing the gLimEdcaParams to HAL in limProcessStaMlmAddBssRsp().
            */ 
           schSetDefaultEdcaParams(pMac, psessionEntry);
       }

<<<<<<< HEAD
<<<<<<< HEAD

}

#if defined(ANI_PRODUCT_TYPE_CLIENT) || defined(ANI_AP_CLIENT_SDK)
=======
       if(qosMode && (!pStaDs->qosMode) && pStaDs->mlmStaContext.htCapability)
       {
           // Enable QOS for all HT AP's even though WMM or 802.11E IE is not present
           pStaDs->qosMode    = 1;
           pStaDs->wmeEnabled = 1;
       }
=======
>>>>>>> 657b0e9... prima update

}

<<<<<<< HEAD
>>>>>>> d97af3b... add prima wlan driver
=======
#if defined(ANI_PRODUCT_TYPE_CLIENT) || defined(ANI_AP_CLIENT_SDK)
>>>>>>> 657b0e9... prima update
/**
 * @function : limUpdateReAssocGlobals
 *
 * @brief :  This function is called to Update the Globals (LIM) during ReAssoc.
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 *
 *NOTE:
 *
 * @param  pMac    - Pointer to Global MAC structure
 * @param  pAssocRsp    - Pointer to Association Response Structure
 *
 * @return None
 */

void limUpdateReAssocGlobals(tpAniSirGlobal pMac, tpSirAssocRsp pAssocRsp,tpPESession psessionEntry)
{
    /**
     * Update the status for PMM module
     */
    pmmResetPmmState(pMac);

    // Update the current Bss Information
<<<<<<< HEAD
<<<<<<< HEAD
    palCopyMemory( pMac->hHdd, psessionEntry->bssId,
                  psessionEntry->limReAssocbssId, sizeof(tSirMacAddr));
=======
    vos_mem_copy(psessionEntry->bssId,
                 psessionEntry->limReAssocbssId, sizeof(tSirMacAddr));
>>>>>>> d97af3b... add prima wlan driver
=======
    palCopyMemory( pMac->hHdd, psessionEntry->bssId,
                  psessionEntry->limReAssocbssId, sizeof(tSirMacAddr));
>>>>>>> 657b0e9... prima update
    psessionEntry->currentOperChannel = psessionEntry->limReassocChannelId;
    psessionEntry->htSecondaryChannelOffset = psessionEntry->reAssocHtSupportedChannelWidthSet;
    psessionEntry->htRecommendedTxWidthSet = psessionEntry->reAssocHtRecommendedTxWidthSet;
    psessionEntry->htSecondaryChannelOffset = psessionEntry->reAssocHtSecondaryChannelOffset;
    psessionEntry->limCurrentBssCaps   = psessionEntry->limReassocBssCaps;
    psessionEntry->limCurrentBssQosCaps = psessionEntry->limReassocBssQosCaps;
    psessionEntry->limCurrentBssPropCap = psessionEntry->limReassocBssPropCap;

<<<<<<< HEAD
<<<<<<< HEAD
    palCopyMemory( pMac->hHdd, (tANI_U8 *) &psessionEntry->ssId,
                  (tANI_U8 *) &psessionEntry->limReassocSSID,
=======
    vos_mem_copy((tANI_U8 *) &psessionEntry->ssId,
                 (tANI_U8 *) &psessionEntry->limReassocSSID,
>>>>>>> d97af3b... add prima wlan driver
=======
    palCopyMemory( pMac->hHdd, (tANI_U8 *) &psessionEntry->ssId,
                  (tANI_U8 *) &psessionEntry->limReassocSSID,
>>>>>>> 657b0e9... prima update
                  psessionEntry->limReassocSSID.length+1);
    
    // Store assigned AID for TIM processing
    psessionEntry->limAID = pAssocRsp->aid & 0x3FFF;
    /** Set the State Back to ReAssoc Rsp*/
    psessionEntry->limMlmState = eLIM_MLM_WT_REASSOC_RSP_STATE; 
    MTRACE(macTrace(pMac, TRACE_CODE_MLM_STATE, psessionEntry->peSessionId, psessionEntry->limMlmState));

    
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
 * @function : limProcessAssocRspFrame
 *
 * @brief :  This function is called by limProcessMessageQueue() upon
 *              Re/Association Response frame reception.
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 *
 *NOTE:
 *
 * @param  pMac    - Pointer to Global MAC structure
 * @param  *pRxPacketInfo    - A pointer to Rx packet info structure
 * @param  subType - Indicates whether it is Association Response (=0) or
 *                   Reassociation Response (=1) frame
 *
 * @return None
 */

void
limProcessAssocRspFrame(tpAniSirGlobal pMac, tANI_U8 *pRxPacketInfo, tANI_U8 subType,tpPESession psessionEntry)
{
    tANI_U8               *pBody;
    tANI_U16              caps;
    tANI_U32              frameLen;
    tSirMacAddr           currentBssId;
    tpSirMacMgmtHdr       pHdr;
    tSirMacCapabilityInfo localCapabilities;
    tpDphHashNode         pStaDs;
    tpSirAssocRsp         pAssocRsp;
    tLimMlmAssocCnf       mlmAssocCnf;
    
<<<<<<< HEAD
<<<<<<< HEAD
#ifdef ANI_PRODUCT_TYPE_CLIENT
    tSchBeaconStruct *pBeaconStruct;
#endif
=======
    tSchBeaconStruct *pBeaconStruct;
>>>>>>> d97af3b... add prima wlan driver
=======
#ifdef ANI_PRODUCT_TYPE_CLIENT
    tSchBeaconStruct *pBeaconStruct;
#endif
>>>>>>> 657b0e9... prima update

    //Initialize status code to success.

    pHdr = WDA_GET_RX_MAC_HEADER(pRxPacketInfo);

    mlmAssocCnf.resultCode = eSIR_SME_SUCCESS;
    /* Update PE session Id*/
    mlmAssocCnf.sessionId = psessionEntry->peSessionId;

<<<<<<< HEAD
<<<<<<< HEAD
    if(eHAL_STATUS_SUCCESS != palAllocateMemory(pMac->hHdd, 
                                                (void **)&pBeaconStruct, sizeof(tSchBeaconStruct)))
    {
        limLog(pMac, LOGE, FL("Unable to PAL allocate memory in limProcessAssocRspFrame\n") );
=======
    pBeaconStruct = vos_mem_malloc(sizeof(tSchBeaconStruct));
    if (NULL == pBeaconStruct)
    {
        limLog(pMac, LOGE, FL("Unable to allocate memory in limProcessAssocRspFrame") );
>>>>>>> d97af3b... add prima wlan driver
=======
    if(eHAL_STATUS_SUCCESS != palAllocateMemory(pMac->hHdd, 
                                                (void **)&pBeaconStruct, sizeof(tSchBeaconStruct)))
    {
        limLog(pMac, LOGE, FL("Unable to PAL allocate memory in limProcessAssocRspFrame\n") );
>>>>>>> 657b0e9... prima update
        return;
    }

   
    if (psessionEntry->limSystemRole == eLIM_AP_ROLE || psessionEntry->limSystemRole == eLIM_BT_AMP_AP_ROLE )
    {
        // Should not have received Re/Association Response
        // frame on AP. Log error
        limLog(pMac, LOGE,
<<<<<<< HEAD
<<<<<<< HEAD
               FL("received Re/Assoc response frame on role %d \n"),
               psessionEntry->limSystemRole);

        palFreeMemory(pMac->hHdd, pBeaconStruct);
=======
               FL("received Re/Assoc response frame on role %d "),
               psessionEntry->limSystemRole);

        vos_mem_free(pBeaconStruct);
>>>>>>> d97af3b... add prima wlan driver
=======
               FL("received Re/Assoc response frame on role %d \n"),
               psessionEntry->limSystemRole);

        palFreeMemory(pMac->hHdd, pBeaconStruct);
>>>>>>> 657b0e9... prima update
        return;
    }


    pHdr = WDA_GET_RX_MAC_HEADER(pRxPacketInfo);
    frameLen = WDA_GET_RX_PAYLOAD_LEN(pRxPacketInfo);

    if (((subType == LIM_ASSOC) &&
         (psessionEntry->limMlmState != eLIM_MLM_WT_ASSOC_RSP_STATE)) ||
        ((subType == LIM_REASSOC) &&
         ((psessionEntry->limMlmState != eLIM_MLM_WT_REASSOC_RSP_STATE) 
#if defined (WLAN_FEATURE_VOWIFI_11R) || defined (FEATURE_WLAN_CCX) || defined(FEATURE_WLAN_LFR)
         && (psessionEntry->limMlmState != eLIM_MLM_WT_FT_REASSOC_RSP_STATE)
#endif
         )))
    {
        /// Received unexpected Re/Association Response frame

#ifdef WLAN_FEATURE_VOWIFI_11R_DEBUG
<<<<<<< HEAD
<<<<<<< HEAD
        PELOG1(limLog(pMac, LOG1,  FL("mlm state is set to %d session=%d\n"), 
=======
        PELOG1(limLog(pMac, LOG1,  FL("mlm state is set to %d session=%d"),
>>>>>>> d97af3b... add prima wlan driver
=======
        PELOG1(limLog(pMac, LOG1,  FL("mlm state is set to %d session=%d\n"), 
>>>>>>> 657b0e9... prima update
            psessionEntry->limMlmState, psessionEntry->peSessionId);)
#endif
        // Log error
        if (!pHdr->fc.retry)
        {
            limLog(pMac, LOGE,
<<<<<<< HEAD
<<<<<<< HEAD
               FL("received Re/Assoc rsp frame in unexpected state\n"));
            limPrintMlmState(pMac, LOGE, psessionEntry->limMlmState);
        }
        palFreeMemory(pMac->hHdd, pBeaconStruct);
=======
               FL("received Re/Assoc rsp frame in unexpected state"));
            limPrintMlmState(pMac, LOGE, psessionEntry->limMlmState);
        }
        vos_mem_free(pBeaconStruct);
>>>>>>> d97af3b... add prima wlan driver
=======
               FL("received Re/Assoc rsp frame in unexpected state\n"));
            limPrintMlmState(pMac, LOGE, psessionEntry->limMlmState);
        }
        palFreeMemory(pMac->hHdd, pBeaconStruct);
>>>>>>> 657b0e9... prima update
        return;
    }
#if 0
    if (wlan_cfgGetStr(pMac, WNI_CFG_BSSID, currentBssId, &cfg) !=
                                eSIR_SUCCESS)
    {
        /// Could not get BSSID from CFG. Log error.
<<<<<<< HEAD
<<<<<<< HEAD
        limLog(pMac, LOGP, FL("could not retrieve BSSID\n"));
        palFreeMemory(pMac->hHdd, pBeaconStruct);
=======
        limLog(pMac, LOGP, FL("could not retrieve BSSID"));
        vos_mem_free(pBeaconStruct);
>>>>>>> d97af3b... add prima wlan driver
=======
        limLog(pMac, LOGP, FL("could not retrieve BSSID\n"));
        palFreeMemory(pMac->hHdd, pBeaconStruct);
>>>>>>> 657b0e9... prima update
        return;
    }
#endif //TO SUPPORT BT-AMP
    sirCopyMacAddr(currentBssId,psessionEntry->bssId);

    if (subType == LIM_ASSOC)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        if (!palEqualMemory( pMac->hHdd,pHdr->sa, currentBssId, sizeof(tSirMacAddr)) )
=======
        if (!vos_mem_compare(pHdr->sa, currentBssId, sizeof(tSirMacAddr)))
>>>>>>> d97af3b... add prima wlan driver
=======
        if (!palEqualMemory( pMac->hHdd,pHdr->sa, currentBssId, sizeof(tSirMacAddr)) )
>>>>>>> 657b0e9... prima update
        {
            /**
             * Received Association Response frame from an entity
             * other than one to which request was initiated.
             * Ignore this and wait until Association Failure Timeout.
             */

            // Log error
            PELOGW(limLog(pMac, LOGW,
                   FL("received AssocRsp frame from unexpected peer "MAC_ADDRESS_STR),
                   MAC_ADDR_ARRAY(pHdr->sa));)
<<<<<<< HEAD
<<<<<<< HEAD
            palFreeMemory(pMac->hHdd, pBeaconStruct);
=======
            vos_mem_free(pBeaconStruct);
>>>>>>> d97af3b... add prima wlan driver
=======
            palFreeMemory(pMac->hHdd, pBeaconStruct);
>>>>>>> 657b0e9... prima update
            return;
        }
    }
    else
    {
<<<<<<< HEAD
<<<<<<< HEAD
        if ( !palEqualMemory( pMac->hHdd,pHdr->sa, psessionEntry->limReAssocbssId, sizeof(tSirMacAddr)) )
=======
        if (!vos_mem_compare(pHdr->sa, psessionEntry->limReAssocbssId, sizeof(tSirMacAddr)))
>>>>>>> d97af3b... add prima wlan driver
=======
        if ( !palEqualMemory( pMac->hHdd,pHdr->sa, psessionEntry->limReAssocbssId, sizeof(tSirMacAddr)) )
>>>>>>> 657b0e9... prima update
        {
            /**
             * Received Reassociation Response frame from an entity
             * other than one to which request was initiated.
             * Ignore this and wait until Reassociation Failure Timeout.
             */

            // Log error
            PELOGW(limLog(pMac, LOGW,
                   FL("received ReassocRsp frame from unexpected peer "MAC_ADDRESS_STR),
                   MAC_ADDR_ARRAY(pHdr->sa));)
<<<<<<< HEAD
<<<<<<< HEAD
            palFreeMemory(pMac->hHdd, pBeaconStruct);
=======
            vos_mem_free(pBeaconStruct);
>>>>>>> d97af3b... add prima wlan driver
=======
            palFreeMemory(pMac->hHdd, pBeaconStruct);
>>>>>>> 657b0e9... prima update

            return;
        }
    }

<<<<<<< HEAD
<<<<<<< HEAD
   if ( palAllocateMemory(pMac->hHdd, (void **)&pAssocRsp, sizeof(*pAssocRsp)) != eHAL_STATUS_SUCCESS) {
        limLog(pMac, LOGP, FL("Pal Allocate Memory failed in AssocRsp\n"));
        palFreeMemory(pMac->hHdd, pBeaconStruct);
=======
   pAssocRsp = vos_mem_malloc(sizeof(*pAssocRsp));
   if (NULL == pAssocRsp)
   {
        limLog(pMac, LOGP, FL("Allocate Memory failed in AssocRsp"));
        vos_mem_free(pBeaconStruct);
>>>>>>> d97af3b... add prima wlan driver
=======
   if ( palAllocateMemory(pMac->hHdd, (void **)&pAssocRsp, sizeof(*pAssocRsp)) != eHAL_STATUS_SUCCESS) {
        limLog(pMac, LOGP, FL("Pal Allocate Memory failed in AssocRsp\n"));
        palFreeMemory(pMac->hHdd, pBeaconStruct);
>>>>>>> 657b0e9... prima update

        return;
    }
   
<<<<<<< HEAD
<<<<<<< HEAD
=======
   VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_DEBUG,
             FL("Re/Assoc Resp Frame Received: BSSID " MAC_ADDRESS_STR " (RSSI %d)"),
             MAC_ADDR_ARRAY(pHdr->bssId),
             (uint)abs((tANI_S8)WDA_GET_RX_RSSI_DB(pRxPacketInfo)));

>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
    // Get pointer to Re/Association Response frame body
    pBody = WDA_GET_RX_MPDU_DATA(pRxPacketInfo);

    // parse Re/Association Response frame.
    if (sirConvertAssocRespFrame2Struct(
                        pMac, pBody, frameLen, pAssocRsp) == eSIR_FAILURE) 
    {
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
        if (palFreeMemory(pMac->hHdd, pAssocRsp) != eHAL_STATUS_SUCCESS) 
        {
            limLog(pMac, LOGP, FL("PalFree Memory failed \n"));
        }
        PELOGE(limLog(pMac, LOGE, FL("Parse error Assoc resp subtype %d, length=%d\n"), frameLen,subType);)
        palFreeMemory(pMac->hHdd, pBeaconStruct);
<<<<<<< HEAD
=======
        vos_mem_free(pAssocRsp);
        PELOGE(limLog(pMac, LOGE, FL("Parse error Assoc resp subtype %d, length=%d"), frameLen,subType);)
        vos_mem_free(pBeaconStruct);
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update

        return;
    }

    if(!pAssocRsp->suppRatesPresent)
    {
        PELOGE(limLog(pMac, LOGW, FL("assoc response does not have supported rate set"));)
<<<<<<< HEAD
<<<<<<< HEAD
        palCopyMemory(pMac->hHdd, &pAssocRsp->supportedRates,
=======
        vos_mem_copy(&pAssocRsp->supportedRates,
>>>>>>> d97af3b... add prima wlan driver
=======
        palCopyMemory(pMac->hHdd, &pAssocRsp->supportedRates,
>>>>>>> 657b0e9... prima update
                      &psessionEntry->rateSet, sizeof(tSirMacRateSet));
    }

    mlmAssocCnf.protStatusCode = pAssocRsp->statusCode;

    if( psessionEntry->assocRsp != NULL )
    {
<<<<<<< HEAD
<<<<<<< HEAD
        palFreeMemory(pMac->hHdd, psessionEntry->assocRsp);
        psessionEntry->assocRsp = NULL;
    }
    if( (palAllocateMemory(pMac->hHdd, (void**)&psessionEntry->assocRsp, frameLen)) != eHAL_STATUS_SUCCESS)
=======
        vos_mem_free(psessionEntry->assocRsp);
        psessionEntry->assocRsp = NULL;
    }

    psessionEntry->assocRsp = vos_mem_malloc(frameLen);
    if (NULL == psessionEntry->assocRsp)
>>>>>>> d97af3b... add prima wlan driver
=======
        palFreeMemory(pMac->hHdd, psessionEntry->assocRsp);
        psessionEntry->assocRsp = NULL;
    }
    if( (palAllocateMemory(pMac->hHdd, (void**)&psessionEntry->assocRsp, frameLen)) != eHAL_STATUS_SUCCESS)
>>>>>>> 657b0e9... prima update
    {
        PELOGE(limLog(pMac, LOGE, FL("Unable to allocate memory to store assoc response, len = %d"), frameLen);)
    }
    else
    {
        //Store the Assoc response. This is sent to csr/hdd in join cnf response. 
<<<<<<< HEAD
<<<<<<< HEAD
        palCopyMemory(pMac->hHdd, psessionEntry->assocRsp, pBody, frameLen);
=======
        vos_mem_copy(psessionEntry->assocRsp, pBody, frameLen);
>>>>>>> d97af3b... add prima wlan driver
=======
        palCopyMemory(pMac->hHdd, psessionEntry->assocRsp, pBody, frameLen);
>>>>>>> 657b0e9... prima update
        psessionEntry->assocRspLen = frameLen;
    }

#ifdef WLAN_FEATURE_VOWIFI_11R
    if (psessionEntry->ricData != NULL) 
    {
<<<<<<< HEAD
<<<<<<< HEAD
        palFreeMemory(pMac->hHdd, psessionEntry->ricData);
=======
        vos_mem_free(psessionEntry->ricData);
>>>>>>> d97af3b... add prima wlan driver
=======
        palFreeMemory(pMac->hHdd, psessionEntry->ricData);
>>>>>>> 657b0e9... prima update
        psessionEntry->ricData = NULL;
    }
    if(pAssocRsp->ricPresent)
    {
        psessionEntry->RICDataLen = pAssocRsp->num_RICData * sizeof(tDot11fIERICDataDesc);
<<<<<<< HEAD
<<<<<<< HEAD
        if( (palAllocateMemory(pMac->hHdd, (void**)&psessionEntry->ricData, psessionEntry->RICDataLen)) != eHAL_STATUS_SUCCESS)
=======
        psessionEntry->ricData = vos_mem_malloc(psessionEntry->RICDataLen);
        if ( NULL == psessionEntry->ricData )
>>>>>>> d97af3b... add prima wlan driver
=======
        if( (palAllocateMemory(pMac->hHdd, (void**)&psessionEntry->ricData, psessionEntry->RICDataLen)) != eHAL_STATUS_SUCCESS)
>>>>>>> 657b0e9... prima update
        {
            PELOGE(limLog(pMac, LOGE, FL("Unable to allocate memory to store assoc response"));)
            psessionEntry->RICDataLen = 0; 
        }
        else
        {
<<<<<<< HEAD
<<<<<<< HEAD
            palCopyMemory(pMac->hHdd, psessionEntry->ricData, &pAssocRsp->RICData[0], psessionEntry->RICDataLen);
=======
            vos_mem_copy(psessionEntry->ricData,
                         &pAssocRsp->RICData[0], psessionEntry->RICDataLen);
>>>>>>> d97af3b... add prima wlan driver
=======
            palCopyMemory(pMac->hHdd, psessionEntry->ricData, &pAssocRsp->RICData[0], psessionEntry->RICDataLen);
>>>>>>> 657b0e9... prima update
        }
    }
    else
    {
        psessionEntry->RICDataLen = 0;
        psessionEntry->ricData = NULL;
    }
#endif    

#ifdef FEATURE_WLAN_CCX    
    if (psessionEntry->tspecIes != NULL) 
    {
<<<<<<< HEAD
<<<<<<< HEAD
        palFreeMemory(pMac->hHdd, psessionEntry->tspecIes);
=======
        vos_mem_free(psessionEntry->tspecIes);
>>>>>>> d97af3b... add prima wlan driver
=======
        palFreeMemory(pMac->hHdd, psessionEntry->tspecIes);
>>>>>>> 657b0e9... prima update
        psessionEntry->tspecIes = NULL;
    }
    if(pAssocRsp->tspecPresent)
    {
        psessionEntry->tspecLen = pAssocRsp->num_tspecs * sizeof(tDot11fIEWMMTSPEC);
<<<<<<< HEAD
<<<<<<< HEAD
        if( (palAllocateMemory(pMac->hHdd, (void**)&psessionEntry->tspecIes, psessionEntry->tspecLen)) != eHAL_STATUS_SUCCESS)
=======
        psessionEntry->tspecIes = vos_mem_malloc(psessionEntry->tspecLen);
        if ( NULL == psessionEntry->tspecIes )
>>>>>>> d97af3b... add prima wlan driver
=======
        if( (palAllocateMemory(pMac->hHdd, (void**)&psessionEntry->tspecIes, psessionEntry->tspecLen)) != eHAL_STATUS_SUCCESS)
>>>>>>> 657b0e9... prima update
        {
            PELOGE(limLog(pMac, LOGE, FL("Unable to allocate memory to store assoc response"));)
            psessionEntry->tspecLen = 0; 
        }
        else
        {
<<<<<<< HEAD
<<<<<<< HEAD
            palCopyMemory(pMac->hHdd, psessionEntry->tspecIes, &pAssocRsp->TSPECInfo[0], psessionEntry->tspecLen);
=======
            vos_mem_copy(psessionEntry->tspecIes,
                         &pAssocRsp->TSPECInfo[0], psessionEntry->tspecLen);
>>>>>>> d97af3b... add prima wlan driver
=======
            palCopyMemory(pMac->hHdd, psessionEntry->tspecIes, &pAssocRsp->TSPECInfo[0], psessionEntry->tspecLen);
>>>>>>> 657b0e9... prima update
        }
        PELOG1(limLog(pMac, LOG1, FL(" Tspec EID present in assoc rsp "));)
    }
    else
    {
        psessionEntry->tspecLen = 0;
        psessionEntry->tspecIes = NULL;
        PELOG1(limLog(pMac, LOG1, FL(" Tspec EID *NOT* present in assoc rsp "));)
    }
#endif

    if (pAssocRsp->capabilityInfo.ibss)
    {
        /**
         * Received Re/Association Response from peer
         * with IBSS capability set.
         * Ignore the frame and wait until Re/assoc
         * failure timeout.
         */
        
        // Log error
        limLog(pMac, LOGE,
<<<<<<< HEAD
<<<<<<< HEAD
               FL("received Re/AssocRsp frame with IBSS capability\n"));
        palFreeMemory(pMac->hHdd, pAssocRsp);
        palFreeMemory(pMac->hHdd, pBeaconStruct);
=======
               FL("received Re/AssocRsp frame with IBSS capability"));
        vos_mem_free(pAssocRsp);
        vos_mem_free(pBeaconStruct);
>>>>>>> d97af3b... add prima wlan driver
=======
               FL("received Re/AssocRsp frame with IBSS capability\n"));
        palFreeMemory(pMac->hHdd, pAssocRsp);
        palFreeMemory(pMac->hHdd, pBeaconStruct);
>>>>>>> 657b0e9... prima update

        return;
    }

    if (cfgGetCapabilityInfo(pMac, &caps,psessionEntry) != eSIR_SUCCESS)
    {
        /**
         * Could not get Capabilities value
         * from CFG. Log error.
         */         
<<<<<<< HEAD
<<<<<<< HEAD
        palFreeMemory(pMac->hHdd, pAssocRsp);
        palFreeMemory(pMac->hHdd, pBeaconStruct);

        limLog(pMac, LOGP, FL("could not retrieve Capabilities value\n"));
=======
        vos_mem_free(pAssocRsp);
        vos_mem_free(pBeaconStruct);

        limLog(pMac, LOGP, FL("could not retrieve Capabilities value"));
>>>>>>> d97af3b... add prima wlan driver
=======
        palFreeMemory(pMac->hHdd, pAssocRsp);
        palFreeMemory(pMac->hHdd, pBeaconStruct);

        limLog(pMac, LOGP, FL("could not retrieve Capabilities value\n"));
>>>>>>> 657b0e9... prima update
        return;
    }
    limCopyU16((tANI_U8 *) &localCapabilities, caps);

    if (subType == LIM_ASSOC)        // Stop Association failure timer
        limDeactivateAndChangeTimer(pMac, eLIM_ASSOC_FAIL_TIMER);
    else        // Stop Reassociation failure timer
<<<<<<< HEAD
<<<<<<< HEAD
        limDeactivateAndChangeTimer(pMac, eLIM_REASSOC_FAIL_TIMER);
=======
    {
#if  defined (WLAN_FEATURE_VOWIFI_11R) || defined (FEATURE_WLAN_CCX) || defined(FEATURE_WLAN_LFR)
        pMac->lim.reAssocRetryAttempt = 0;
        if ((NULL != pMac->lim.pSessionEntry) && (NULL != pMac->lim.pSessionEntry->pLimMlmReassocRetryReq))
        {
            vos_mem_free(pMac->lim.pSessionEntry->pLimMlmReassocRetryReq);
            pMac->lim.pSessionEntry->pLimMlmReassocRetryReq = NULL;
        }
#endif
        limDeactivateAndChangeTimer(pMac, eLIM_REASSOC_FAIL_TIMER);
    }
>>>>>>> d97af3b... add prima wlan driver
=======
        limDeactivateAndChangeTimer(pMac, eLIM_REASSOC_FAIL_TIMER);
>>>>>>> 657b0e9... prima update

    if (pAssocRsp->statusCode != eSIR_MAC_SUCCESS_STATUS)
    {
        // Re/Association response was received
        // either with failure code.
        // Log error.
<<<<<<< HEAD
<<<<<<< HEAD
        PELOGE(limLog(pMac, LOGE, FL("received Re/AssocRsp frame failure code %d\n"), pAssocRsp->statusCode);)
=======
        PELOGE(limLog(pMac, LOGE, FL("received Re/AssocRsp frame failure code %d"), pAssocRsp->statusCode);)
>>>>>>> d97af3b... add prima wlan driver
=======
        PELOGE(limLog(pMac, LOGE, FL("received Re/AssocRsp frame failure code %d\n"), pAssocRsp->statusCode);)
>>>>>>> 657b0e9... prima update
        // Need to update 'association failure' error counter
        // along with STATUS CODE

        // Return Assoc confirm to SME with received failure code

        if (pAssocRsp->propIEinfo.loadBalanceInfoPresent)
        {
            mlmAssocCnf.resultCode = eSIR_SME_TRANSFER_STA;
<<<<<<< HEAD
<<<<<<< HEAD
            palCopyMemory( pMac->hHdd, pMac->lim.gLimAlternateRadio.bssId,
                          pAssocRsp->propIEinfo.alternateRadio.bssId, sizeof(tSirMacAddr));
=======
            vos_mem_copy(pMac->lim.gLimAlternateRadio.bssId,
                         pAssocRsp->propIEinfo.alternateRadio.bssId, sizeof(tSirMacAddr));
>>>>>>> d97af3b... add prima wlan driver
=======
            palCopyMemory( pMac->hHdd, pMac->lim.gLimAlternateRadio.bssId,
                          pAssocRsp->propIEinfo.alternateRadio.bssId, sizeof(tSirMacAddr));
>>>>>>> 657b0e9... prima update
            pMac->lim.gLimAlternateRadio.channelId =
                          pAssocRsp->propIEinfo.alternateRadio.channelId;
        }else
            mlmAssocCnf.resultCode = eSIR_SME_ASSOC_REFUSED;

        // Delete Pre-auth context for the associated BSS
        if (limSearchPreAuthList(pMac, pHdr->sa))
            limDeletePreAuthNode(pMac, pHdr->sa);

        goto assocReject;
    }
    else if ((pAssocRsp->aid & 0x3FFF) > 2007)
    {
        // Re/Association response was received
        // with invalid AID value
        // Log error
<<<<<<< HEAD
<<<<<<< HEAD
        PELOGW(limLog(pMac, LOGW, FL("received Re/AssocRsp frame with invalid aid %X \n"),  pAssocRsp->aid);)
=======
        PELOGW(limLog(pMac, LOGW, FL("received Re/AssocRsp frame with invalid aid %X "),  pAssocRsp->aid);)
>>>>>>> d97af3b... add prima wlan driver
=======
        PELOGW(limLog(pMac, LOGW, FL("received Re/AssocRsp frame with invalid aid %X \n"),  pAssocRsp->aid);)
>>>>>>> 657b0e9... prima update
        mlmAssocCnf.resultCode = eSIR_SME_INVALID_ASSOC_RSP_RXED;
        mlmAssocCnf.protStatusCode = eSIR_MAC_UNSPEC_FAILURE_STATUS;

        // Send advisory Disassociation frame to AP
<<<<<<< HEAD
<<<<<<< HEAD
        limSendDisassocMgmtFrame(pMac, eSIR_MAC_UNSPEC_FAILURE_REASON, pHdr->sa,psessionEntry);
=======
        limSendDisassocMgmtFrame(pMac, eSIR_MAC_UNSPEC_FAILURE_REASON,
                                 pHdr->sa, psessionEntry, FALSE);
>>>>>>> d97af3b... add prima wlan driver
=======
        limSendDisassocMgmtFrame(pMac, eSIR_MAC_UNSPEC_FAILURE_REASON, pHdr->sa,psessionEntry);
>>>>>>> 657b0e9... prima update

        goto assocReject;
    }
    // Association Response received with success code
<<<<<<< HEAD
<<<<<<< HEAD

    if (subType == LIM_REASSOC)
    {
        // Log success
        PELOG1(limLog(pMac, LOG1, FL("Successfully Reassociated with BSS\n"));)
=======
    /*
     * Set the link state to POSTASSOC now that we have received
     * assoc/reassoc response
     * NOTE: for BTAMP case, it is being handled in limProcessMlmAssocReq
     */
    if (!((psessionEntry->bssType == eSIR_BTAMP_STA_MODE) ||
          ((psessionEntry->bssType == eSIR_BTAMP_AP_MODE) &&
          (psessionEntry->limSystemRole == eLIM_BT_AMP_STA_ROLE))))
    {
            if (limSetLinkState(pMac, eSIR_LINK_POSTASSOC_STATE, psessionEntry->bssId,
                                psessionEntry->selfMacAddr, NULL, NULL) != eSIR_SUCCESS)
            {
                PELOGE(limLog(pMac, LOGE, FL("Set link state to POSTASSOC failed"));)
                vos_mem_free(pBeaconStruct);
                vos_mem_free(pAssocRsp);
                return;
            }
    }
    if (subType == LIM_REASSOC)
    {
        // Log success
        PELOG1(limLog(pMac, LOG1, FL("Successfully Reassociated with BSS"));)
>>>>>>> d97af3b... add prima wlan driver
=======

    if (subType == LIM_REASSOC)
    {
        // Log success
        PELOG1(limLog(pMac, LOG1, FL("Successfully Reassociated with BSS\n"));)
>>>>>>> 657b0e9... prima update
#ifdef FEATURE_WLAN_CCX
        {
            tANI_U8 cnt = 0;
            if (pAssocRsp->tsmPresent)
            {
<<<<<<< HEAD
<<<<<<< HEAD
                limLog(pMac, LOGW, "TSM IE Present in Reassoc Rsp\n");
=======
                limLog(pMac, LOGW, "TSM IE Present in Reassoc Rsp");
>>>>>>> d97af3b... add prima wlan driver
=======
                limLog(pMac, LOGW, "TSM IE Present in Reassoc Rsp\n");
>>>>>>> 657b0e9... prima update
                // Start the TSM  timer only if the TSPEC Ie is present in the reassoc rsp
                if (pAssocRsp->tspecPresent) {
                    // Find the TSPEC IE with VO user priority
                    for (cnt=0; cnt<pAssocRsp->num_tspecs; cnt++) {
                        if ( upToAc(pAssocRsp->TSPECInfo[cnt].user_priority) == EDCA_AC_VO) {
                            psessionEntry->ccxContext.tsm.tid = pAssocRsp->TSPECInfo[cnt].user_priority;
                            vos_mem_copy(&psessionEntry->ccxContext.tsm.tsmInfo,
                                    &pAssocRsp->tsmIE, sizeof(tSirMacCCXTSMIE));
                            limActivateTSMStatsTimer(pMac, psessionEntry);
                            if(psessionEntry->ccxContext.tsm.tsmInfo.state) {
                                psessionEntry->ccxContext.tsm.tsmMetrics.RoamingCount++;
                            }
                            break;
                        }
                    }
                } else {
<<<<<<< HEAD
<<<<<<< HEAD
                    limLog(pMac, LOGE, "TSM present but TSPEC IE not present in Reassoc Rsp\n");
=======
                    limLog(pMac, LOGE, "TSM present but TSPEC IE not present in Reassoc Rsp");
>>>>>>> d97af3b... add prima wlan driver
=======
                    limLog(pMac, LOGE, "TSM present but TSPEC IE not present in Reassoc Rsp\n");
>>>>>>> 657b0e9... prima update
                }
            }
        }
#endif
        if (psessionEntry->pLimMlmJoinReq)
        {
<<<<<<< HEAD
<<<<<<< HEAD
            palFreeMemory( pMac->hHdd, psessionEntry->pLimMlmJoinReq);
=======
            vos_mem_free(psessionEntry->pLimMlmJoinReq);
>>>>>>> d97af3b... add prima wlan driver
=======
            palFreeMemory( pMac->hHdd, psessionEntry->pLimMlmJoinReq);
>>>>>>> 657b0e9... prima update
            psessionEntry->pLimMlmJoinReq = NULL;
        }

        psessionEntry->limAssocResponseData  = (void *) pAssocRsp; /** Store the ReAssocRsp Frame in DphTable to be used 
                                                        during processing DelSta nd DelBss to send AddBss again*/
        pStaDs = dphGetHashEntry(pMac, DPH_STA_HASH_INDEX_PEER, &psessionEntry->dph.dphHashTable);

        if(!pStaDs)
        {
<<<<<<< HEAD
<<<<<<< HEAD
            PELOGE(limLog(pMac, LOG1, FL("could not get hash entry at DPH for \n"));)
=======
            PELOGE(limLog(pMac, LOGE, FL("could not get hash entry at DPH for"));)
>>>>>>> d97af3b... add prima wlan driver
=======
            PELOGE(limLog(pMac, LOG1, FL("could not get hash entry at DPH for \n"));)
>>>>>>> 657b0e9... prima update
            limPrintMacAddr(pMac, pHdr->sa, LOGE);
            mlmAssocCnf.resultCode = eSIR_SME_INVALID_ASSOC_RSP_RXED;
            mlmAssocCnf.protStatusCode = eSIR_MAC_UNSPEC_FAILURE_STATUS;
            
            // Send advisory Disassociation frame to AP
<<<<<<< HEAD
<<<<<<< HEAD
            limSendDisassocMgmtFrame(pMac, eSIR_MAC_UNSPEC_FAILURE_REASON, pHdr->sa,psessionEntry);
=======
            limSendDisassocMgmtFrame(pMac, eSIR_MAC_UNSPEC_FAILURE_REASON,
                                     pHdr->sa, psessionEntry, FALSE);
>>>>>>> d97af3b... add prima wlan driver
=======
            limSendDisassocMgmtFrame(pMac, eSIR_MAC_UNSPEC_FAILURE_REASON, pHdr->sa,psessionEntry);
>>>>>>> 657b0e9... prima update
            
            goto assocReject;
        }

#if defined(WLAN_FEATURE_VOWIFI_11R) || defined (FEATURE_WLAN_CCX) || defined(FEATURE_WLAN_LFR)
        if (psessionEntry->limMlmState == eLIM_MLM_WT_FT_REASSOC_RSP_STATE)
        {
#ifdef WLAN_FEATURE_VOWIFI_11R_DEBUG
<<<<<<< HEAD
<<<<<<< HEAD
            PELOGE(limLog(pMac, LOGE, FL("Sending self sta\n"));)
=======
            PELOGE(limLog(pMac, LOG1, FL("Sending self sta"));)
>>>>>>> d97af3b... add prima wlan driver
=======
            PELOGE(limLog(pMac, LOGE, FL("Sending self sta\n"));)
>>>>>>> 657b0e9... prima update
#endif
            pmmResetPmmState(pMac);

            limUpdateAssocStaDatas(pMac, pStaDs, pAssocRsp,psessionEntry);

            // Store assigned AID for TIM processing
            psessionEntry->limAID = pAssocRsp->aid & 0x3FFF;

<<<<<<< HEAD
<<<<<<< HEAD
            limAddFTStaSelf(pMac, (pAssocRsp->aid & 0x3FFF), psessionEntry);
            palFreeMemory(pMac->hHdd, pBeaconStruct);
=======
            // Downgrade the EDCA parameters if needed
            limSetActiveEdcaParams(pMac, psessionEntry->gLimEdcaParams, psessionEntry);

            // Send the active EDCA parameters to HAL
            if (pStaDs->aniPeer == eANI_BOOLEAN_TRUE)
            {
                limSendEdcaParams(pMac, psessionEntry->gLimEdcaParamsActive, pStaDs->bssId, eANI_BOOLEAN_TRUE);
            }
            else
            {
                limSendEdcaParams(pMac, psessionEntry->gLimEdcaParamsActive, pStaDs->bssId, eANI_BOOLEAN_FALSE);
            }
            limAddFTStaSelf(pMac, (pAssocRsp->aid & 0x3FFF), psessionEntry);
            vos_mem_free(pBeaconStruct);
>>>>>>> d97af3b... add prima wlan driver
=======
            limAddFTStaSelf(pMac, (pAssocRsp->aid & 0x3FFF), psessionEntry);
            palFreeMemory(pMac->hHdd, pBeaconStruct);
>>>>>>> 657b0e9... prima update

            return;
        }
#endif /* WLAN_FEATURE_VOWIFI_11R */

        /* If we're re-associating to the same BSS, we don't want to invoke delete
         * STA, delete BSS, as that would remove the already established TSPEC.  
         * Just go ahead and re-add the BSS, STA with new capability information. 
         * However, if we're re-associating to a different BSS, then follow thru
         * with del STA, del BSS, add BSS, add STA.       
         */
        if (sirCompareMacAddr( psessionEntry->bssId, psessionEntry->limReAssocbssId))
            limHandleAddBssInReAssocContext(pMac, pStaDs, psessionEntry);
        else
        {
            // reset the uapsd mask settings since we're re-associating to new AP
            pMac->lim.gUapsdPerAcDeliveryEnableMask = 0;
            pMac->lim.gUapsdPerAcTriggerEnableMask = 0;

            if (limCleanupRxPath(pMac, pStaDs,psessionEntry) != eSIR_SUCCESS)
                goto assocReject;
        }
<<<<<<< HEAD
<<<<<<< HEAD
        palFreeMemory(pMac->hHdd, pBeaconStruct);
=======
        vos_mem_free(pBeaconStruct);
>>>>>>> d97af3b... add prima wlan driver
=======
        palFreeMemory(pMac->hHdd, pBeaconStruct);
>>>>>>> 657b0e9... prima update

        return;
    }

    // Log success
<<<<<<< HEAD
<<<<<<< HEAD
    PELOGE(limLog(pMac, LOGE, FL("Successfully Associated with BSS "MAC_ADDRESS_STR),
=======
    PELOG1(limLog(pMac, LOG1, FL("Successfully Associated with BSS "MAC_ADDRESS_STR),
>>>>>>> d97af3b... add prima wlan driver
=======
    PELOGE(limLog(pMac, LOGE, FL("Successfully Associated with BSS "MAC_ADDRESS_STR),
>>>>>>> 657b0e9... prima update
           MAC_ADDR_ARRAY(pHdr->sa));)
#ifdef FEATURE_WLAN_CCX
    if(psessionEntry->ccxContext.tsm.tsmInfo.state)
    {
        psessionEntry->ccxContext.tsm.tsmMetrics.RoamingCount = 0;
    }
#endif
    /**
     * Update the status for PMM module
     */
    pmmResetPmmState(pMac);

    // Store assigned AID for TIM processing
    psessionEntry->limAID = pAssocRsp->aid & 0x3FFF;


    //STA entry was created during pre-assoc state.
    if ((pStaDs = dphGetHashEntry(pMac, DPH_STA_HASH_INDEX_PEER, &psessionEntry->dph.dphHashTable)) == NULL) 
    {
        // Could not add hash table entry
<<<<<<< HEAD
<<<<<<< HEAD
        PELOGE(limLog(pMac, LOGE, FL("could not get hash entry at DPH for \n"));)
=======
        PELOGE(limLog(pMac, LOGE, FL("could not get hash entry at DPH for "));)
>>>>>>> d97af3b... add prima wlan driver
=======
        PELOGE(limLog(pMac, LOGE, FL("could not get hash entry at DPH for \n"));)
>>>>>>> 657b0e9... prima update
        limPrintMacAddr(pMac, pHdr->sa, LOGE);

        mlmAssocCnf.resultCode = eSIR_SME_RESOURCES_UNAVAILABLE;
        mlmAssocCnf.protStatusCode = eSIR_SME_SUCCESS;
        

        limPostSmeMessage(pMac, LIM_MLM_ASSOC_CNF,
                              (tANI_U32 *) &mlmAssocCnf);
<<<<<<< HEAD
<<<<<<< HEAD
        palFreeMemory(pMac->hHdd, pAssocRsp); 
        palFreeMemory(pMac->hHdd, pBeaconStruct);
=======
        vos_mem_free(pAssocRsp);
        vos_mem_free(pBeaconStruct);
>>>>>>> d97af3b... add prima wlan driver
=======
        palFreeMemory(pMac->hHdd, pAssocRsp); 
        palFreeMemory(pMac->hHdd, pBeaconStruct);
>>>>>>> 657b0e9... prima update

        return;
    }
   
     // Delete Pre-auth context for the associated BSS
    if (limSearchPreAuthList(pMac, pHdr->sa))
        limDeletePreAuthNode(pMac, pHdr->sa);

    limUpdateAssocStaDatas(pMac, pStaDs, pAssocRsp,psessionEntry);
<<<<<<< HEAD
<<<<<<< HEAD
#ifdef ANI_PRODUCT_TYPE_CLIENT
=======
>>>>>>> d97af3b... add prima wlan driver
=======
#ifdef ANI_PRODUCT_TYPE_CLIENT
>>>>>>> 657b0e9... prima update
    // Extract the AP capabilities from the beacon that was received earlier
    // TODO - Watch out for an error response!
    limExtractApCapabilities( pMac,
                            (tANI_U8 *) psessionEntry->pLimJoinReq->bssDescription.ieFields,
                            limGetIElenFromBssDescription( &psessionEntry->pLimJoinReq->bssDescription ),
                            pBeaconStruct );

    if(pMac->lim.gLimProtectionControl != WNI_CFG_FORCE_POLICY_PROTECTION_DISABLE)
        limDecideStaProtectionOnAssoc(pMac, pBeaconStruct, psessionEntry);
    
    if(pBeaconStruct->erpPresent) {
        if (pBeaconStruct->erpIEInfo.barkerPreambleMode)
            psessionEntry->beaconParams.fShortPreamble = false;
        else
            psessionEntry->beaconParams.fShortPreamble = true;
    }
<<<<<<< HEAD
<<<<<<< HEAD
=======
#ifdef FEATURE_WLAN_DIAG_SUPPORT_LIM //FEATURE_WLAN_DIAG_SUPPORT
    limDiagEventReport(pMac, WLAN_PE_DIAG_CONNECTED, psessionEntry, 0, 0);
#endif
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update


     //Update the BSS Entry, this entry was added during preassoc.
    if( eSIR_SUCCESS == limStaSendAddBss( pMac, pAssocRsp,  pBeaconStruct,
                   &psessionEntry->pLimJoinReq->bssDescription, true, psessionEntry))  
    {
<<<<<<< HEAD
<<<<<<< HEAD
        palFreeMemory(pMac->hHdd, pAssocRsp);   
        palFreeMemory(pMac->hHdd, pBeaconStruct);
=======
        vos_mem_free(pAssocRsp);
        vos_mem_free(pBeaconStruct);
>>>>>>> d97af3b... add prima wlan driver
=======
        palFreeMemory(pMac->hHdd, pAssocRsp);   
        palFreeMemory(pMac->hHdd, pBeaconStruct);
>>>>>>> 657b0e9... prima update
        return;
    }
    else
    {
        mlmAssocCnf.resultCode = eSIR_SME_RESOURCES_UNAVAILABLE;
        mlmAssocCnf.protStatusCode = eSIR_MAC_UNSPEC_FAILURE_STATUS;
    }

<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
#elif defined(ANI_AP_CLIENT_SDK)
    if( eSIR_SUCCESS == limStaSendAddBss( pMac, *pAssocRsp, 
                            &psessionEntry->pLimJoinReq->neighborBssList.bssList[0], true))
    {
        palFreeMemory(pMac->hHdd, pAssocRsp);   
        return;
    }
    else
    {
        mlmAssocCnf.resultCode = eSIR_SME_RESOURCES_UNAVAILABLE;
        mlmAssocCnf.protStatusCode = eSIR_MAC_UNSPEC_FAILURE_STATUS;
    }
#else
    palFreeMemory(pMac->hHdd, pAssocRsp);   
    return;
#endif
<<<<<<< HEAD
=======
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
  

assocReject:
    if ((subType == LIM_ASSOC)
#ifdef WLAN_FEATURE_VOWIFI_11R
                    || ((subType == LIM_REASSOC) && (psessionEntry->limMlmState == eLIM_MLM_WT_FT_REASSOC_RSP_STATE))
#endif
       ) {
<<<<<<< HEAD
<<<<<<< HEAD
        PELOGE(limLog(pMac, LOGE,  FL("Assoc Rejected by the peer. Reason: %d\n"), mlmAssocCnf.resultCode);)
=======
        PELOGE(limLog(pMac, LOGE,  FL("Assoc Rejected by the peer. Reason: %d"), mlmAssocCnf.resultCode);)
>>>>>>> d97af3b... add prima wlan driver
=======
        PELOGE(limLog(pMac, LOGE,  FL("Assoc Rejected by the peer. Reason: %d\n"), mlmAssocCnf.resultCode);)
>>>>>>> 657b0e9... prima update
        psessionEntry->limMlmState = eLIM_MLM_IDLE_STATE;
        MTRACE(macTrace(pMac, TRACE_CODE_MLM_STATE, psessionEntry->peSessionId, psessionEntry->limMlmState));

        if (psessionEntry->pLimMlmJoinReq)
        {
<<<<<<< HEAD
<<<<<<< HEAD
            palFreeMemory( pMac->hHdd, psessionEntry->pLimMlmJoinReq);
=======
            vos_mem_free(psessionEntry->pLimMlmJoinReq);
>>>>>>> d97af3b... add prima wlan driver
=======
            palFreeMemory( pMac->hHdd, psessionEntry->pLimMlmJoinReq);
>>>>>>> 657b0e9... prima update
            psessionEntry->pLimMlmJoinReq = NULL;
        }

        if (subType == LIM_ASSOC)
        {
           limPostSmeMessage(pMac, LIM_MLM_ASSOC_CNF, (tANI_U32 *) &mlmAssocCnf);
        }
#ifdef WLAN_FEATURE_VOWIFI_11R
        else
        {
                mlmAssocCnf.resultCode = eSIR_SME_FT_REASSOC_FAILURE;
                limPostSmeMessage(pMac, LIM_MLM_REASSOC_CNF, (tANI_U32 *) &mlmAssocCnf);
        }
#endif /* WLAN_FEATURE_VOWIFI_11R */
    } else {
        limRestorePreReassocState( pMac, 
                  eSIR_SME_REASSOC_REFUSED, mlmAssocCnf.protStatusCode,psessionEntry); 
    }

    /* CR: vos packet memory is leaked when assoc rsp timeouted/failed. */
    /* notify TL that association is failed so that TL can flush the cached frame  */
    WLANTL_AssocFailed (psessionEntry->staId);

<<<<<<< HEAD
<<<<<<< HEAD
    palFreeMemory(pMac->hHdd, pBeaconStruct);
    palFreeMemory(pMac->hHdd, pAssocRsp);      
=======
    vos_mem_free(pBeaconStruct);
    vos_mem_free(pAssocRsp);
>>>>>>> d97af3b... add prima wlan driver
=======
    palFreeMemory(pMac->hHdd, pBeaconStruct);
    palFreeMemory(pMac->hHdd, pAssocRsp);      
>>>>>>> 657b0e9... prima update
    return;
} /*** end limProcessAssocRspFrame() ***/

