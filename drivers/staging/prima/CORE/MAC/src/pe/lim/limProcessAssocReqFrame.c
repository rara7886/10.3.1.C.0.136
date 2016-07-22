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
 * Airgo Networks, Inc proprietary. All rights reserved.
 * This file limProcessAssocReqFrame.cc contains the code
 * for processing Re/Association Request Frame.
 * Author:        Chandra Modumudi
 * Date:          03/18/02
 * History:-
 * Date           Modified by    Modification Information
 * --------------------------------------------------------------------
 * 05/26/10       js             WPA handling in (Re)Assoc frames
 *
 */
#include "palTypes.h"
#include "aniGlobal.h"
<<<<<<< HEAD
<<<<<<< HEAD
#include "wniCfgAp.h"
=======
#include "wniCfgSta.h"
>>>>>>> d97af3b... add prima wlan driver
=======
#include "wniCfgAp.h"
>>>>>>> 657b0e9... prima update
#include "sirApi.h"
#include "cfgApi.h"

#include "schApi.h"
#include "pmmApi.h"
#include "utilsApi.h"
#include "limTypes.h"
#include "limUtils.h"
#include "limAssocUtils.h"
#include "limSecurityUtils.h"
#include "limSerDesUtils.h"
#include "limStaHashApi.h"
#include "limAdmitControl.h"
#include "palApi.h"
<<<<<<< HEAD
<<<<<<< HEAD
=======
#include "limSessionUtils.h"
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update


#include "vos_types.h"
/**
 * limConvertSupportedChannels
 *
 *FUNCTION:
 * This function is called by limProcessAssocReqFrame() to
 * parse the channel support IE in the Assoc/Reassoc Request
 * frame, and send relevant information in the SME_ASSOC_IND
 *
 *NOTE:
 *
 * @param  pMac         - A pointer to Global MAC structure
 * @param  pMlmAssocInd - A pointer to SME ASSOC/REASSOC IND
 * @param  assocReq     - A pointer to ASSOC/REASSOC Request frame
 *
 * @return None
 */
static void
limConvertSupportedChannels(tpAniSirGlobal pMac,
                            tpLimMlmAssocInd pMlmAssocInd,
                            tSirAssocReq *assocReq)
{

    tANI_U16   i, j, index=0;
    tANI_U8    firstChannelNumber;
    tANI_U8    numberOfChannel;
    tANI_U8    nextChannelNumber;

    if(assocReq->supportedChannels.length >= SIR_MAX_SUPPORTED_CHANNEL_LIST)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        limLog(pMac, LOG1, FL("Number of supported channels:%d is more than MAX\n"),
=======
        limLog(pMac, LOG1, FL("Number of supported channels:%d is more than MAX"),
>>>>>>> d97af3b... add prima wlan driver
=======
        limLog(pMac, LOG1, FL("Number of supported channels:%d is more than MAX\n"),
>>>>>>> 657b0e9... prima update
                              assocReq->supportedChannels.length);
        pMlmAssocInd->supportedChannels.numChnl = 0;
        return;
    }

    for(i=0; i < (assocReq->supportedChannels.length); i++)
    {
        // Get First Channel Number
        firstChannelNumber = assocReq->supportedChannels.supportedChannels[i];
        pMlmAssocInd->supportedChannels.channelList[index] = firstChannelNumber;
        i++;
        index++;
        if (index >= SIR_MAX_SUPPORTED_CHANNEL_LIST)
        {
            pMlmAssocInd->supportedChannels.numChnl = 0;
            return;
        }
        // Get Number of Channels in a Subband
        numberOfChannel = assocReq->supportedChannels.supportedChannels[i];
<<<<<<< HEAD
<<<<<<< HEAD
        PELOG2(limLog(pMac, LOG2, FL("Rcv AssocReq: chnl=%d, numOfChnl=%d \n"),
=======
        PELOG2(limLog(pMac, LOG2, FL("Rcv AssocReq: chnl=%d, numOfChnl=%d "),
>>>>>>> d97af3b... add prima wlan driver
=======
        PELOG2(limLog(pMac, LOG2, FL("Rcv AssocReq: chnl=%d, numOfChnl=%d \n"),
>>>>>>> 657b0e9... prima update
                              firstChannelNumber, numberOfChannel);)

        if (numberOfChannel > 1)
        {
            nextChannelNumber = firstChannelNumber;
            if(SIR_BAND_5_GHZ == limGetRFBand(firstChannelNumber))
            {
                for (j=1; j < numberOfChannel; j++)
                {
                    nextChannelNumber += SIR_11A_FREQUENCY_OFFSET;
                    pMlmAssocInd->supportedChannels.channelList[index] = nextChannelNumber;
                    index++;
                    if (index >= SIR_MAX_SUPPORTED_CHANNEL_LIST)
                    {
                        pMlmAssocInd->supportedChannels.numChnl = 0;
                        return;
                    }
                }
            }
            else if(SIR_BAND_2_4_GHZ == limGetRFBand(firstChannelNumber))
            {
                for (j=1; j < numberOfChannel; j++)
                {
                    nextChannelNumber += SIR_11B_FREQUENCY_OFFSET;
                    pMlmAssocInd->supportedChannels.channelList[index] = nextChannelNumber;
                    index++;
                    if (index >= SIR_MAX_SUPPORTED_CHANNEL_LIST)
                    {
                        pMlmAssocInd->supportedChannels.numChnl = 0;
                        return;
                    }
                }
            }
        }
    }

    pMlmAssocInd->supportedChannels.numChnl = (tANI_U8) index;
   PELOG2(limLog(pMac, LOG2,
<<<<<<< HEAD
<<<<<<< HEAD
        FL("Send AssocInd to WSM: spectrum ON, minPwr %d, maxPwr %d, numChnl %d\n"),
=======
        FL("Send AssocInd to WSM: spectrum ON, minPwr %d, maxPwr %d, numChnl %d"),
>>>>>>> d97af3b... add prima wlan driver
=======
        FL("Send AssocInd to WSM: spectrum ON, minPwr %d, maxPwr %d, numChnl %d\n"),
>>>>>>> 657b0e9... prima update
        pMlmAssocInd->powerCap.minTxPower,
        pMlmAssocInd->powerCap.maxTxPower,
        pMlmAssocInd->supportedChannels.numChnl);)
}


/**---------------------------------------------------------------
\fn     limProcessAssocReqFrame
\brief  This function is called by limProcessMessageQueue()
<<<<<<< HEAD
<<<<<<< HEAD
\       upon Re/Association Request frame reception in 
=======
\       upon Re/Association Request frame reception in
>>>>>>> d97af3b... add prima wlan driver
=======
\       upon Re/Association Request frame reception in 
>>>>>>> 657b0e9... prima update
\       BTAMP AP or Soft AP role.
\
\param pMac
\param *pRxPacketInfo    - A pointer to Buffer descriptor + associated PDUs
<<<<<<< HEAD
<<<<<<< HEAD
\param subType - Indicates whether it is Association Request(=0) 
=======
\param subType - Indicates whether it is Association Request(=0)
>>>>>>> d97af3b... add prima wlan driver
=======
\param subType - Indicates whether it is Association Request(=0) 
>>>>>>> 657b0e9... prima update
\                or Reassociation Request(=1) frame
\return None
------------------------------------------------------------------*/
void
limProcessAssocReqFrame(tpAniSirGlobal pMac, tANI_U8 *pRxPacketInfo,
                        tANI_U8 subType, tpPESession psessionEntry)
{
    tANI_U8                 updateContext;
    tANI_U8                 *pBody;
<<<<<<< HEAD
<<<<<<< HEAD
    tANI_U16                aid, temp;
=======
    tANI_U16                peerIdx, temp;
>>>>>>> d97af3b... add prima wlan driver
=======
    tANI_U16                aid, temp;
>>>>>>> 657b0e9... prima update
    tANI_U32                val;
    tANI_S32                framelen;
    tSirRetStatus           status;
    tpSirMacMgmtHdr         pHdr;
    struct tLimPreAuthNode  *pStaPreAuthContext;
    tAniAuthType            authType;
    tSirMacCapabilityInfo   localCapabilities;
    tpDphHashNode           pStaDs = NULL;
    tpSirAssocReq           pAssocReq;
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
#ifdef WLAN_SOFTAP_FEATURE
    tLimMlmStates           mlmPrevState;
    tDot11fIERSN            Dot11fIERSN;
    tDot11fIEWPA            Dot11fIEWPA;
#endif
<<<<<<< HEAD
=======
    tLimMlmStates           mlmPrevState;
    tDot11fIERSN            Dot11fIERSN;
    tDot11fIEWPA            Dot11fIEWPA;
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
    tANI_U32 phyMode;
    tHalBitVal qosMode;
    tHalBitVal wsmMode, wmeMode;
    tANI_U8    *wpsIe = NULL;
    tSirMacRateSet  basicRates;
    tANI_U8 i = 0, j = 0;
<<<<<<< HEAD
<<<<<<< HEAD
=======
    tANI_BOOLEAN pmfConnection = eANI_BOOLEAN_FALSE;
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update

    limGetPhyMode(pMac, &phyMode, psessionEntry);

    limGetQosMode(psessionEntry, &qosMode);

    pHdr = WDA_GET_RX_MAC_HEADER(pRxPacketInfo);
    framelen = WDA_GET_RX_PAYLOAD_LEN(pRxPacketInfo);

   if (psessionEntry->limSystemRole == eLIM_STA_ROLE || psessionEntry->limSystemRole == eLIM_BT_AMP_STA_ROLE )
   {
<<<<<<< HEAD
<<<<<<< HEAD
        limLog(pMac, LOGE, FL("received unexpected ASSOC REQ subType=%d for role=%d, radioId=%d from \n"),
                                            subType, psessionEntry->limSystemRole, pMac->sys.gSirRadioId);
=======
        limLog(pMac, LOGE, FL("received unexpected ASSOC REQ subType=%d for role=%d"),
               subType, psessionEntry->limSystemRole);
>>>>>>> d97af3b... add prima wlan driver
=======
        limLog(pMac, LOGE, FL("received unexpected ASSOC REQ subType=%d for role=%d, radioId=%d from \n"),
                                            subType, psessionEntry->limSystemRole, pMac->sys.gSirRadioId);
>>>>>>> 657b0e9... prima update
        limPrintMacAddr(pMac, pHdr->sa, LOGE);
        sirDumpBuf(pMac, SIR_LIM_MODULE_ID, LOG3,
        WDA_GET_RX_MPDU_DATA(pRxPacketInfo), framelen);
        return;
    }

    // Get pointer to Re/Association Request frame body
    pBody = WDA_GET_RX_MPDU_DATA(pRxPacketInfo);

    if (limIsGroupAddr(pHdr->sa))
    {
        // Received Re/Assoc Req frame from a BC/MC address
        // Log error and ignore it
        if (subType == LIM_ASSOC)
<<<<<<< HEAD
<<<<<<< HEAD
			limLog(pMac, LOGW, FL("received Assoc frame from a BC/MC address "MAC_ADDRESS_STR),
=======
            limLog(pMac, LOGW, FL("received Assoc frame from a BC/MC address "MAC_ADDRESS_STR),
>>>>>>> d97af3b... add prima wlan driver
=======
			limLog(pMac, LOGW, FL("received Assoc frame from a BC/MC address "MAC_ADDRESS_STR),
>>>>>>> 657b0e9... prima update
                   MAC_ADDR_ARRAY(pHdr->sa));
        else
            limLog(pMac, LOGW, FL("received ReAssoc frame from a BC/MC address "MAC_ADDRESS_STR),
                   MAC_ADDR_ARRAY(pHdr->sa));
        return;
    }
    limLog(pMac, LOGW, FL("Received AssocReq Frame: "MAC_ADDRESS_STR), MAC_ADDR_ARRAY(pHdr->sa));

    sirDumpBuf(pMac, SIR_LIM_MODULE_ID, LOG2, (tANI_U8 *) pBody, framelen);

<<<<<<< HEAD
<<<<<<< HEAD
    if( palEqualMemory( pMac->hHdd,  (tANI_U8* ) pHdr->sa, (tANI_U8 *) pHdr->da, 
=======
    if (vos_mem_compare((tANI_U8* ) pHdr->sa, (tANI_U8 *) pHdr->da,
>>>>>>> d97af3b... add prima wlan driver
=======
    if( palEqualMemory( pMac->hHdd,  (tANI_U8* ) pHdr->sa, (tANI_U8 *) pHdr->da, 
>>>>>>> 657b0e9... prima update
                        (tANI_U8) (sizeof(tSirMacAddr))))
    {
        limSendAssocRspMgmtFrame(pMac,
                    eSIR_MAC_UNSPEC_FAILURE_STATUS,
                    1,
                    pHdr->sa,
                    subType, 0,psessionEntry);
<<<<<<< HEAD
<<<<<<< HEAD
        limLog(pMac, LOGE, FL("Rejected Assoc Req frame Since same mac as SAP/GO\n"));
        return ;
    }

#ifdef WLAN_SOFTAP_FEATURE
=======
        limLog(pMac, LOGE, FL("Rejected Assoc Req frame Since same mac as SAP/GO"));
        return ;
    }

>>>>>>> d97af3b... add prima wlan driver
=======
        limLog(pMac, LOGE, FL("Rejected Assoc Req frame Since same mac as SAP/GO\n"));
        return ;
    }

#ifdef WLAN_SOFTAP_FEATURE
>>>>>>> 657b0e9... prima update
    // If TKIP counter measures active send Assoc Rsp frame to station with eSIR_MAC_MIC_FAILURE_REASON
    if ((psessionEntry->bTkipCntrMeasActive) && (psessionEntry->limSystemRole == eLIM_AP_ROLE))
    {
        limSendAssocRspMgmtFrame(pMac,
                                    eSIR_MAC_MIC_FAILURE_REASON,
                                    1,
                                    pHdr->sa,
                                    subType, 0, psessionEntry);
        return;
    }
<<<<<<< HEAD
<<<<<<< HEAD
#endif

    // Allocate memory for the Assoc Request frame
    if ( palAllocateMemory(pMac->hHdd, (void **)&pAssocReq, sizeof(*pAssocReq)) != eHAL_STATUS_SUCCESS) 
    {
        limLog(pMac, LOGP, FL("PAL Allocate Memory failed in AssocReq\n"));
        return;
    }
    palZeroMemory( pMac->hHdd, (void *)pAssocReq , sizeof(*pAssocReq));
   
=======
=======
#endif
>>>>>>> 657b0e9... prima update

    // Allocate memory for the Assoc Request frame
    if ( palAllocateMemory(pMac->hHdd, (void **)&pAssocReq, sizeof(*pAssocReq)) != eHAL_STATUS_SUCCESS) 
    {
        limLog(pMac, LOGP, FL("PAL Allocate Memory failed in AssocReq\n"));
        return;
    }
<<<<<<< HEAD
    vos_mem_set((void *)pAssocReq , sizeof(*pAssocReq), 0);

>>>>>>> d97af3b... add prima wlan driver
=======
    palZeroMemory( pMac->hHdd, (void *)pAssocReq , sizeof(*pAssocReq));
   
>>>>>>> 657b0e9... prima update
    // Parse Assoc Request frame
    if (subType == LIM_ASSOC)
        status = sirConvertAssocReqFrame2Struct(pMac, pBody, framelen, pAssocReq);
    else
        status = sirConvertReassocReqFrame2Struct(pMac, pBody, framelen, pAssocReq);

    if (status != eSIR_SUCCESS)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        limLog(pMac, LOGW, FL("Parse error AssocRequest, length=%d from \n"),framelen);
=======
        limLog(pMac, LOGW, FL("Parse error AssocRequest, length=%d from "),framelen);
>>>>>>> d97af3b... add prima wlan driver
=======
        limLog(pMac, LOGW, FL("Parse error AssocRequest, length=%d from \n"),framelen);
>>>>>>> 657b0e9... prima update
        limPrintMacAddr(pMac, pHdr->sa, LOGW);
        limSendAssocRspMgmtFrame(pMac, eSIR_MAC_UNSPEC_FAILURE_STATUS, 1, pHdr->sa, subType, 0, psessionEntry);
        goto error;
    }

<<<<<<< HEAD
<<<<<<< HEAD
    if ( palAllocateMemory(pMac->hHdd, (void **)&pAssocReq->assocReqFrame, framelen) != eHAL_STATUS_SUCCESS) 
    {
        limLog(pMac, LOGE, FL("Unable to allocate memory for the assoc req, length=%d from \n"),framelen);
        goto error;
    }
    
    palCopyMemory( pMac->hHdd, (tANI_U8 *) pAssocReq->assocReqFrame,
=======
    pAssocReq->assocReqFrame = vos_mem_malloc(framelen);
    if ( NULL == pAssocReq->assocReqFrame )
=======
    if ( palAllocateMemory(pMac->hHdd, (void **)&pAssocReq->assocReqFrame, framelen) != eHAL_STATUS_SUCCESS) 
>>>>>>> 657b0e9... prima update
    {
        limLog(pMac, LOGE, FL("Unable to allocate memory for the assoc req, length=%d from \n"),framelen);
        goto error;
    }
    
<<<<<<< HEAD
    vos_mem_copy((tANI_U8 *) pAssocReq->assocReqFrame,
>>>>>>> d97af3b... add prima wlan driver
=======
    palCopyMemory( pMac->hHdd, (tANI_U8 *) pAssocReq->assocReqFrame,
>>>>>>> 657b0e9... prima update
                  (tANI_U8 *) pBody, framelen);
    pAssocReq->assocReqFrameLength = framelen;    

    if (cfgGetCapabilityInfo(pMac, &temp,psessionEntry) != eSIR_SUCCESS)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        limLog(pMac, LOGP, FL("could not retrieve Capabilities\n"));
        goto error;
    }
#if defined(ANI_PRODUCT_TYPE_AP) && defined(ANI_LITTLE_BYTE_ENDIAN)
    *(tANI_U16*)&localCapabilities=(tANI_U16)(temp);
#else
    limCopyU16((tANI_U8 *) &localCapabilities, temp);
#endif
=======
        limLog(pMac, LOGP, FL("could not retrieve Capabilities"));
=======
        limLog(pMac, LOGP, FL("could not retrieve Capabilities\n"));
>>>>>>> 657b0e9... prima update
        goto error;
    }
#if defined(ANI_PRODUCT_TYPE_AP) && defined(ANI_LITTLE_BYTE_ENDIAN)
    *(tANI_U16*)&localCapabilities=(tANI_U16)(temp);
#else
    limCopyU16((tANI_U8 *) &localCapabilities, temp);
<<<<<<< HEAD
>>>>>>> d97af3b... add prima wlan driver
=======
#endif
>>>>>>> 657b0e9... prima update

    if (limCompareCapabilities(pMac,
                               pAssocReq,
                               &localCapabilities,psessionEntry) == false)
    {
        /**
         * Capabilities of requesting STA does not match with
         * local capabilities. Respond with 'unsupported capabilities'
         * status code.
         */
        limSendAssocRspMgmtFrame(
                        pMac,
                        eSIR_MAC_CAPABILITIES_NOT_SUPPORTED_STATUS,
                        1,
                        pHdr->sa,
                        subType, 0,psessionEntry);

<<<<<<< HEAD
<<<<<<< HEAD
        limLog(pMac, LOGW, FL("local caps 0x%x received 0x%x\n"), localCapabilities, pAssocReq->capabilityInfo);
=======
        limLog(pMac, LOGW, FL("local caps 0x%x received 0x%x"), localCapabilities, pAssocReq->capabilityInfo);
>>>>>>> d97af3b... add prima wlan driver
=======
        limLog(pMac, LOGW, FL("local caps 0x%x received 0x%x\n"), localCapabilities, pAssocReq->capabilityInfo);
>>>>>>> 657b0e9... prima update

        // Log error
        if (subType == LIM_ASSOC)
            limLog(pMac, LOGW,
               FL("received Assoc req with unsupported capabilities "MAC_ADDRESS_STR),
                  MAC_ADDR_ARRAY(pHdr->sa));
        else
            limLog(pMac, LOGW,
                   FL("received ReAssoc req with unsupported capabilities "MAC_ADDRESS_STR),
                   MAC_ADDR_ARRAY(pHdr->sa));
        goto error;
    }

    updateContext = false;

<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
#if (WNI_POLARIS_FW_PACKAGE == ADVANCED)
    // Check if multiple SSID feature is not enabled
    if (psessionEntry->pLimStartBssReq->ssId.length)
    {
        if (limCmpSSid(pMac, &pAssocReq->ssId, psessionEntry) == false)
        {
            /*Temp hack for UPF35 - skip SSID check in order to be able to interop 
             with Marvel - they send their own SSID instead of ours*/
            if ( 0 != vos_get_skip_ssid_check())
            {
                limLog(pMac, LOG1, FL("Received unmatched SSID but cfg to suppress - continuing\n"));
            }
            else
            {
              /**
              * Received Re/Association Request with either
              * Broadcast SSID OR with SSID that does not
              * match with local one.
              * Respond with unspecified status code.
              */
              limSendAssocRspMgmtFrame(pMac,
                               eSIR_MAC_UNSPEC_FAILURE_STATUS,
                               1,
                               pHdr->sa,
                               subType, 0,psessionEntry);
  
              // Log error
              if (subType == LIM_ASSOC)
                  limLog(pMac, LOGW, FL("received Assoc req with unmatched SSID from \n"));
              else
                  limLog(pMac, LOGW, FL("received ReAssoc req with unmatched SSID from \n"));
              limPrintMacAddr(pMac, pHdr->sa, LOGW);
              goto error;
          }
      }
    }
    else
        limLog(pMac, LOG1, FL("Suppressed SSID, App is going to check SSID\n"));
#else
<<<<<<< HEAD
=======
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
    if (limCmpSSid(pMac, &pAssocReq->ssId, psessionEntry) == false)
    {
        /**
         * Received Re/Association Request with either
         * Broadcast SSID OR with SSID that does not
         * match with local one.
         * Respond with unspecified status code.
         */
        limSendAssocRspMgmtFrame(pMac,
                             eSIR_MAC_UNSPEC_FAILURE_STATUS,
                             1,
                             pHdr->sa,
                             subType, 0,psessionEntry);

        // Log error
        if (subType == LIM_ASSOC)
            limLog(pMac, LOGW,
<<<<<<< HEAD
<<<<<<< HEAD
                   FL("received Assoc req with unmatched SSID from \n"));
        else
            limLog(pMac, LOGW,
                   FL("received ReAssoc req with unmatched SSID from \n"));
        limPrintMacAddr(pMac, pHdr->sa, LOGW);
        goto error;
    }
#endif
=======
                   FL("received Assoc req with unmatched SSID from "));
=======
                   FL("received Assoc req with unmatched SSID from \n"));
>>>>>>> 657b0e9... prima update
        else
            limLog(pMac, LOGW,
                   FL("received ReAssoc req with unmatched SSID from \n"));
        limPrintMacAddr(pMac, pHdr->sa, LOGW);
        goto error;
    }
<<<<<<< HEAD
>>>>>>> d97af3b... add prima wlan driver
=======
#endif
>>>>>>> 657b0e9... prima update

    /***************************************************************
      ** Verify if the requested rates are available in supported rate
      ** set or Extended rate set. Some APs are adding basic rates in
      ** Extended rateset IE
      ***************************************************************/
    basicRates.numRates = 0;

<<<<<<< HEAD
<<<<<<< HEAD
    for(i = 0; i < pAssocReq->supportedRates.numRates; i++)
=======
    for(i = 0; i < pAssocReq->supportedRates.numRates && (i < SIR_MAC_RATESET_EID_MAX); i++)
>>>>>>> d97af3b... add prima wlan driver
=======
    for(i = 0; i < pAssocReq->supportedRates.numRates; i++)
>>>>>>> 657b0e9... prima update
    {
        basicRates.rate[i] = pAssocReq->supportedRates.rate[i];
        basicRates.numRates++;
    }

    for(j = 0; (j < pAssocReq->extendedRates.numRates) && (i < SIR_MAC_RATESET_EID_MAX); i++,j++)
    {
        basicRates.rate[i] = pAssocReq->extendedRates.rate[j];
        basicRates.numRates++;
    }
    if (limCheckRxBasicRates(pMac, basicRates, psessionEntry) == false)
    {
        /**
         * Requesting STA does not support ALL BSS basic
         * rates. Respond with 'basic rates not supported'
         * status code.
         */
        limSendAssocRspMgmtFrame(
                    pMac,
                    eSIR_MAC_BASIC_RATES_NOT_SUPPORTED_STATUS,
                    1,
                    pHdr->sa,
                    subType, 0,psessionEntry);

        // Log error
        if (subType == LIM_ASSOC)
            limLog(pMac, LOGW,
<<<<<<< HEAD
<<<<<<< HEAD
               FL("received Assoc req with unsupported rates from \n"));
        else
            limLog(pMac, LOGW,
               FL("received ReAssoc req with unsupported rates from\n"));
=======
               FL("received Assoc req with unsupported rates from "));
        else
            limLog(pMac, LOGW,
               FL("received ReAssoc req with unsupported rates from"));
>>>>>>> d97af3b... add prima wlan driver
=======
               FL("received Assoc req with unsupported rates from \n"));
        else
            limLog(pMac, LOGW,
               FL("received ReAssoc req with unsupported rates from\n"));
>>>>>>> 657b0e9... prima update
        limPrintMacAddr(pMac, pHdr->sa, LOGW);
        goto error;
    }

<<<<<<< HEAD
<<<<<<< HEAD
#ifdef WLAN_SOFTAP_FEATURE
=======
>>>>>>> d97af3b... add prima wlan driver
=======
#ifdef WLAN_SOFTAP_FEATURE
>>>>>>> 657b0e9... prima update

    if((psessionEntry->limSystemRole == eLIM_AP_ROLE ) &&
       (psessionEntry->dot11mode == WNI_CFG_DOT11_MODE_11G_ONLY) &&
       ((!pAssocReq->extendedRatesPresent ) || (pAssocReq->HTCaps.present)))
    {
        limSendAssocRspMgmtFrame( pMac, eSIR_MAC_CAPABILITIES_NOT_SUPPORTED_STATUS, 
                                  1, pHdr->sa, subType, 0, psessionEntry );
<<<<<<< HEAD
<<<<<<< HEAD
        limLog(pMac, LOGE, FL("SOFTAP was in 11G only mode, rejecting legacy STA's\n"));
=======
        limLog(pMac, LOGE, FL("SOFTAP was in 11G only mode, rejecting legacy STA's"));
>>>>>>> d97af3b... add prima wlan driver
=======
        limLog(pMac, LOGE, FL("SOFTAP was in 11G only mode, rejecting legacy STA's\n"));
>>>>>>> 657b0e9... prima update
        goto error;

    }//end if phyMode == 11G_only
 
    if((psessionEntry->limSystemRole == eLIM_AP_ROLE) && 
       (psessionEntry->dot11mode == WNI_CFG_DOT11_MODE_11N_ONLY) && 
       (!pAssocReq->HTCaps.present))
    {
        limSendAssocRspMgmtFrame( pMac, eSIR_MAC_CAPABILITIES_NOT_SUPPORTED_STATUS, 
                                  1, pHdr->sa, subType, 0, psessionEntry );
<<<<<<< HEAD
<<<<<<< HEAD
        limLog(pMac, LOGE, FL("SOFTAP was in 11N only mode, rejecting legacy STA's\n"));
        goto error;
    }//end if PhyMode == 11N_only

#endif
=======
        limLog(pMac, LOGE, FL("SOFTAP was in 11N only mode, rejecting legacy STA's"));
        goto error;
    }//end if PhyMode == 11N_only

>>>>>>> d97af3b... add prima wlan driver
=======
        limLog(pMac, LOGE, FL("SOFTAP was in 11N only mode, rejecting legacy STA's\n"));
        goto error;
    }//end if PhyMode == 11N_only

#endif
>>>>>>> 657b0e9... prima update

    /* Spectrum Management (11h) specific checks */
    if (localCapabilities.spectrumMgt)
    {
        tSirRetStatus status = eSIR_SUCCESS;

        /* If station is 11h capable, then it SHOULD send all mandatory 
         * IEs in assoc request frame. Let us verify that
         */
        if (pAssocReq->capabilityInfo.spectrumMgt)
        {
            if (!((pAssocReq->powerCapabilityPresent) && (pAssocReq->supportedChannelsPresent)))
            {
                /* One or more required information elements are missing, log the peers error */
                if (!pAssocReq->powerCapabilityPresent)
                {
                    if(subType == LIM_ASSOC)
<<<<<<< HEAD
<<<<<<< HEAD
                       limLog(pMac, LOG1, FL("LIM Info: Missing Power capability IE in assoc request\n"));
                    else
                       limLog(pMac, LOG1, FL("LIM Info: Missing Power capability IE in Reassoc request\n"));
=======
                       limLog(pMac, LOG1, FL("LIM Info: Missing Power capability IE in assoc request"));
                    else
                       limLog(pMac, LOG1, FL("LIM Info: Missing Power capability IE in Reassoc request"));
>>>>>>> d97af3b... add prima wlan driver
=======
                       limLog(pMac, LOG1, FL("LIM Info: Missing Power capability IE in assoc request\n"));
                    else
                       limLog(pMac, LOG1, FL("LIM Info: Missing Power capability IE in Reassoc request\n"));
>>>>>>> 657b0e9... prima update
                }
                if (!pAssocReq->supportedChannelsPresent)
                {
                    if(subType == LIM_ASSOC)
<<<<<<< HEAD
<<<<<<< HEAD
                        limLog(pMac, LOG1, FL("LIM Info: Missing Supported channel IE in assoc request\n"));
                    else
                        limLog(pMac, LOG1, FL("LIM Info: Missing Supported channel IE in Reassoc request\n"));
=======
                        limLog(pMac, LOG1, FL("LIM Info: Missing Supported channel IE in assoc request"));
                    else
                        limLog(pMac, LOG1, FL("LIM Info: Missing Supported channel IE in Reassoc request"));
>>>>>>> d97af3b... add prima wlan driver
=======
                        limLog(pMac, LOG1, FL("LIM Info: Missing Supported channel IE in assoc request\n"));
                    else
                        limLog(pMac, LOG1, FL("LIM Info: Missing Supported channel IE in Reassoc request\n"));
>>>>>>> 657b0e9... prima update
                }
                limPrintMacAddr(pMac, pHdr->sa, LOG1);
            }
            else
            {
                /* Assoc request has mandatory fields */
                status = limIsDot11hPowerCapabilitiesInRange(pMac, pAssocReq, psessionEntry);
                if (eSIR_SUCCESS != status)
                {
                    if (subType == LIM_ASSOC)
<<<<<<< HEAD
<<<<<<< HEAD
                        limLog(pMac, LOGW, FL("LIM Info: Association MinTxPower(STA) > MaxTxPower(AP)\n"));
                    else
                        limLog(pMac, LOGW, FL("LIM Info: Reassociation MinTxPower(STA) > MaxTxPower(AP)\n"));
=======
                        limLog(pMac, LOGW, FL("LIM Info: Association MinTxPower(STA) > MaxTxPower(AP)"));
                    else
                        limLog(pMac, LOGW, FL("LIM Info: Reassociation MinTxPower(STA) > MaxTxPower(AP)"));
>>>>>>> d97af3b... add prima wlan driver
=======
                        limLog(pMac, LOGW, FL("LIM Info: Association MinTxPower(STA) > MaxTxPower(AP)\n"));
                    else
                        limLog(pMac, LOGW, FL("LIM Info: Reassociation MinTxPower(STA) > MaxTxPower(AP)\n"));
>>>>>>> 657b0e9... prima update
                    limPrintMacAddr(pMac, pHdr->sa, LOGW);
                }
                status = limIsDot11hSupportedChannelsValid(pMac, pAssocReq);
                if (eSIR_SUCCESS != status)
                {
                    if (subType == LIM_ASSOC)
<<<<<<< HEAD
<<<<<<< HEAD
                        limLog(pMac, LOGW, FL("LIM Info: Association wrong supported channels (STA)\n"));
                    else
                        limLog(pMac, LOGW, FL("LIM Info: Reassociation wrong supported channels (STA)\n"));
=======
                        limLog(pMac, LOGW, FL("LIM Info: Association wrong supported channels (STA)"));
                    else
                        limLog(pMac, LOGW, FL("LIM Info: Reassociation wrong supported channels (STA)"));
>>>>>>> d97af3b... add prima wlan driver
=======
                        limLog(pMac, LOGW, FL("LIM Info: Association wrong supported channels (STA)\n"));
                    else
                        limLog(pMac, LOGW, FL("LIM Info: Reassociation wrong supported channels (STA)\n"));
>>>>>>> 657b0e9... prima update
                    limPrintMacAddr(pMac, pHdr->sa, LOGW);
                }
                /* IEs are valid, use them if needed */
            }
        } //if(assoc.capabilityInfo.spectrumMgt)
        else
        {
            /* As per the capabiities, the spectrum management is not enabled on the station
             * The AP may allow the associations to happen even if spectrum management is not
             * allowed, if the transmit power of station is below the regulatory maximum
             */

            /* TODO: presently, this is not handled. In the current implemetation, the AP would
             * allow the station to associate even if it doesn't support spectrum management.
             */
        }
    }// end of spectrum management related processing

    if ( (pAssocReq->HTCaps.present) && (limCheckMCSSet(pMac, pAssocReq->HTCaps.supportedMCSSet) == false))
    {
        /**
         * Requesting STA does not support ALL BSS MCS basic Rate set rates.
         * Spec does not define any status code for this scenario.
         */
        limSendAssocRspMgmtFrame(
                    pMac,
                    eSIR_MAC_OUTSIDE_SCOPE_OF_SPEC_STATUS,
                    1,
                    pHdr->sa,
                    subType, 0,psessionEntry);

        // Log error
        if (subType == LIM_ASSOC)
            limLog(pMac, LOGW,
<<<<<<< HEAD
<<<<<<< HEAD
               FL("received Assoc req with unsupported MCS Rate Set from \n"));
        else
            limLog(pMac, LOGW,
               FL("received ReAssoc req with unsupported MCS Rate Set from\n"));
=======
               FL("received Assoc req with unsupported MCS Rate Set from "));
        else
            limLog(pMac, LOGW,
               FL("received ReAssoc req with unsupported MCS Rate Set from"));
>>>>>>> d97af3b... add prima wlan driver
=======
               FL("received Assoc req with unsupported MCS Rate Set from \n"));
        else
            limLog(pMac, LOGW,
               FL("received ReAssoc req with unsupported MCS Rate Set from\n"));
>>>>>>> 657b0e9... prima update
        limPrintMacAddr(pMac, pHdr->sa, LOGW);
        goto error;
    }

    //if (pMac->dph.gDphPhyMode == WNI_CFG_PHY_MODE_11G)
    if (phyMode == WNI_CFG_PHY_MODE_11G)
    {

        if (wlan_cfgGetInt(pMac, WNI_CFG_11G_ONLY_POLICY, &val) != eSIR_SUCCESS)
        {
<<<<<<< HEAD
<<<<<<< HEAD
            limLog(pMac, LOGP, FL("could not retrieve 11g-only flag\n"));
=======
            limLog(pMac, LOGP, FL("could not retrieve 11g-only flag"));
>>>>>>> d97af3b... add prima wlan driver
=======
            limLog(pMac, LOGP, FL("could not retrieve 11g-only flag\n"));
>>>>>>> 657b0e9... prima update
            goto error;
        }

        if (!pAssocReq->extendedRatesPresent && val)
        {
            /**
             * Received Re/Association Request from
             * 11b STA when 11g only policy option
             * is set.
             * Reject with unspecified status code.
             */
            limSendAssocRspMgmtFrame(
                           pMac,
                           eSIR_MAC_BASIC_RATES_NOT_SUPPORTED_STATUS,
                           1,
                           pHdr->sa,
                           subType, 0,psessionEntry);

            limLog(pMac, LOGW, FL("Rejecting Re/Assoc req from 11b STA: "));
            limPrintMacAddr(pMac, pHdr->sa, LOGW);
            
#ifdef WLAN_DEBUG    
            pMac->lim.gLim11bStaAssocRejectCount++;
#endif
            goto error;
        }
    }

#ifdef WMM_APSD
    // Save the QOS info element in assoc request..
    limGetWmeMode(pMac, &wmeMode);
    if (wmeMode == eHAL_SET)
    {
        tpQosInfoSta qInfo;

        qInfo = (tpQosInfoSta) (pAssocReq->qosCapability.qosInfo);

        if ((pMac->lim.gWmmApsd.apsdEnable == 0) && (qInfo->ac_be || qInfo->ac_bk || qInfo->ac_vo || qInfo->ac_vi))
        {

            /**
             * Received Re/Association Request from
             * 11b STA when 11g only policy option
             * is set.
             * Reject with unspecified status code.
             */
            limSendAssocRspMgmtFrame(
                           pMac,
                           eSIR_MAC_WME_REFUSED_STATUS,
                           1,
                           pHdr->sa,
                           subType, 0,psessionEntry);

            limLog(pMac, LOGW,
                   FL("Rejecting Re/Assoc req from STA: "));
            limPrintMacAddr(pMac, pHdr->sa, LOGW);
<<<<<<< HEAD
<<<<<<< HEAD
            limLog(pMac, LOGE, FL("APSD not enabled, qosInfo - 0x%x\n"), *qInfo);
=======
            limLog(pMac, LOGE, FL("APSD not enabled, qosInfo - 0x%x"), *qInfo);
>>>>>>> d97af3b... add prima wlan driver
=======
            limLog(pMac, LOGE, FL("APSD not enabled, qosInfo - 0x%x\n"), *qInfo);
>>>>>>> 657b0e9... prima update
            goto error;
        }
    }
#endif

    // Check for 802.11n HT caps compatibility; are HT Capabilities
    // turned on in lim?
    if ( psessionEntry->htCapability )
    {
        // There are; are they turned on in the STA?
        if ( pAssocReq->HTCaps.present )
        {
            // The station *does* support 802.11n HT capability...

            limLog( pMac, LOG1, FL( "AdvCodingCap:%d ChaWidthSet:%d "
                                    "PowerSave:%d greenField:%d "
<<<<<<< HEAD
<<<<<<< HEAD
                                    "shortGI20:%d shortGI40:%d\n"
                                    "txSTBC:%d rxSTBC:%d delayBA:%d"
                                    "maxAMSDUsize:%d DSSS/CCK:%d "
                                    "PSMP:%d stbcCntl:%d lsigTXProt:%d\n"),
=======
                                    "shortGI20:%d shortGI40:%d"
                                    "txSTBC:%d rxSTBC:%d delayBA:%d"
                                    "maxAMSDUsize:%d DSSS/CCK:%d "
                                    "PSMP:%d stbcCntl:%d lsigTXProt:%d"),
>>>>>>> d97af3b... add prima wlan driver
=======
                                    "shortGI20:%d shortGI40:%d\n"
                                    "txSTBC:%d rxSTBC:%d delayBA:%d"
                                    "maxAMSDUsize:%d DSSS/CCK:%d "
                                    "PSMP:%d stbcCntl:%d lsigTXProt:%d\n"),
>>>>>>> 657b0e9... prima update
                    pAssocReq->HTCaps.advCodingCap,
                    pAssocReq->HTCaps.supportedChannelWidthSet,
                    pAssocReq->HTCaps.mimoPowerSave,
                    pAssocReq->HTCaps.greenField,
                    pAssocReq->HTCaps.shortGI20MHz,
                    pAssocReq->HTCaps.shortGI40MHz,
                    pAssocReq->HTCaps.txSTBC,
                    pAssocReq->HTCaps.rxSTBC,
                    pAssocReq->HTCaps.delayedBA,
                    pAssocReq->HTCaps.maximalAMSDUsize,
                    pAssocReq->HTCaps.dsssCckMode40MHz,
                    pAssocReq->HTCaps.psmp,
                    pAssocReq->HTCaps.stbcControlFrame,
                    pAssocReq->HTCaps.lsigTXOPProtection );

                // Make sure the STA's caps are compatible with our own:
                //11.15.2 Support of DSSS/CCK in 40 MHz
                //the AP shall refuse association requests from an HT STA that has the DSSS/CCK 
                //Mode in 40 MHz subfield set to 1;

            //FIXME_BTAMP_AP : Need to be enabled 
            /*
            if ( !pMac->lim.gHTDsssCckRate40MHzSupport && pAssocReq->HTCaps.dsssCckMode40MHz )
            {
                statusCode = eSIR_MAC_DSSS_CCK_RATE_NOT_SUPPORT_STATUS;
                limLog( pMac, LOGW, FL( "AP DSSS/CCK is disabled; "
<<<<<<< HEAD
<<<<<<< HEAD
                                        "STA rejected.\n" ) );
=======
                                        "STA rejected." ) );
>>>>>>> d97af3b... add prima wlan driver
=======
                                        "STA rejected.\n" ) );
>>>>>>> 657b0e9... prima update
                // Reject association
                limSendAssocRspMgmtFrame( pMac, statusCode, 1, pHdr->sa, subType, 0,psessionEntry);
                goto error;
            }
            */
        }
    } // End if on HT caps turned on in lim.

<<<<<<< HEAD
<<<<<<< HEAD
#ifdef WLAN_SOFTAP_FEATURE
    /* Clear the buffers so that frame parser knows that there isn't a previously decoded IE in these buffers */
    palZeroMemory( pMac->hHdd, ( tANI_U8* )&Dot11fIERSN, sizeof( Dot11fIERSN ) );
    palZeroMemory( pMac->hHdd, ( tANI_U8* )&Dot11fIEWPA, sizeof( Dot11fIEWPA ) );
=======
    /* Clear the buffers so that frame parser knows that there isn't a previously decoded IE in these buffers */
    vos_mem_set((tANI_U8*)&Dot11fIERSN, sizeof( Dot11fIERSN ), 0);
    vos_mem_set((tANI_U8*)&Dot11fIEWPA, sizeof( Dot11fIEWPA ), 0);
>>>>>>> d97af3b... add prima wlan driver
=======
#ifdef WLAN_SOFTAP_FEATURE
    /* Clear the buffers so that frame parser knows that there isn't a previously decoded IE in these buffers */
    palZeroMemory( pMac->hHdd, ( tANI_U8* )&Dot11fIERSN, sizeof( Dot11fIERSN ) );
    palZeroMemory( pMac->hHdd, ( tANI_U8* )&Dot11fIEWPA, sizeof( Dot11fIEWPA ) );
>>>>>>> 657b0e9... prima update

    /* if additional IE is present, check if it has WscIE */
    if( pAssocReq->addIEPresent && pAssocReq->addIE.length )
        wpsIe = limGetWscIEPtr(pMac, pAssocReq->addIE.addIEdata, pAssocReq->addIE.length);
    /* when wpsIe is present, RSN/WPA IE is ignored */
    if( wpsIe == NULL )
    {
        /** check whether as RSN IE is present */
        if(psessionEntry->limSystemRole == eLIM_AP_ROLE 
            && psessionEntry->pLimStartBssReq->privacy 
            && psessionEntry->pLimStartBssReq->rsnIE.length)
        {
            limLog(pMac, LOGE,
<<<<<<< HEAD
<<<<<<< HEAD
                   FL("AP supports RSN enabled authentication\n"));
=======
                   FL("AP supports RSN enabled authentication"));
>>>>>>> d97af3b... add prima wlan driver
=======
                   FL("AP supports RSN enabled authentication\n"));
>>>>>>> 657b0e9... prima update

            if(pAssocReq->rsnPresent)
            {
                if(pAssocReq->rsn.length)
                {
                    // Unpack the RSN IE 
                    dot11fUnpackIeRSN(pMac, 
                                        &pAssocReq->rsn.info[0], 
                                        pAssocReq->rsn.length, 
                                        &Dot11fIERSN);

                    /* Check RSN version is supported or not */
                    if(SIR_MAC_OUI_VERSION_1 == Dot11fIERSN.version)
                    {
                        /* check the groupwise and pairwise cipher suites */
<<<<<<< HEAD
<<<<<<< HEAD
                        if(eSIR_SUCCESS != (status = limCheckRxRSNIeMatch(pMac, Dot11fIERSN, psessionEntry, pAssocReq->HTCaps.present) ) )
=======
                        if(eSIR_SUCCESS != (status = limCheckRxRSNIeMatch(pMac, Dot11fIERSN, psessionEntry,
                                                                          pAssocReq->HTCaps.present, &pmfConnection)))
>>>>>>> d97af3b... add prima wlan driver
=======
                        if(eSIR_SUCCESS != (status = limCheckRxRSNIeMatch(pMac, Dot11fIERSN, psessionEntry, pAssocReq->HTCaps.present) ) )
>>>>>>> 657b0e9... prima update
                        {
                            /* some IE is not properly sent */
                            /* received Association req frame with RSN IE but length is 0 */
                            limSendAssocRspMgmtFrame(
                                           pMac,
                                           status,
                                           1,
                                           pHdr->sa,
                                           subType, 0,psessionEntry);

                            limLog(pMac, LOGW, FL("Rejecting Re/Assoc req from STA: "));
                            limPrintMacAddr(pMac, pHdr->sa, LOGW);
                            goto error;

                        }
                    }
                    else
                    {
                        /* received Association req frame with RSN IE version wrong */
                        limSendAssocRspMgmtFrame(
                                       pMac,
                                       eSIR_MAC_UNSUPPORTED_RSN_IE_VERSION_STATUS,
                                       1,
                                       pHdr->sa,
                                       subType, 0,psessionEntry);

                        limLog(pMac, LOGW, FL("Rejecting Re/Assoc req from STA: "));
                        limPrintMacAddr(pMac, pHdr->sa, LOGW);
                        goto error;

                    }
                }
                else
                {
                    /* received Association req frame with RSN IE but length is 0 */
                    limSendAssocRspMgmtFrame(
                                   pMac,
                                   eSIR_MAC_INVALID_INFORMATION_ELEMENT_STATUS,
                                   1,
                                   pHdr->sa,
                                   subType, 0,psessionEntry);

                    limLog(pMac, LOGW, FL("Rejecting Re/Assoc req from STA: "));
                    limPrintMacAddr(pMac, pHdr->sa, LOGW);
                    goto error;
                    
                }
            } /* end - if(pAssocReq->rsnPresent) */
            if((!pAssocReq->rsnPresent) && pAssocReq->wpaPresent)
            {
                // Unpack the WPA IE 
                if(pAssocReq->wpa.length)
                {
                    dot11fUnpackIeWPA(pMac, 
                                        &pAssocReq->wpa.info[4], //OUI is not taken care
                                        pAssocReq->wpa.length, 
                                        &Dot11fIEWPA);
                    /* check the groupwise and pairwise cipher suites */
                    if(eSIR_SUCCESS != (status = limCheckRxWPAIeMatch(pMac, Dot11fIEWPA, psessionEntry, pAssocReq->HTCaps.present)))
                    {
                        /* received Association req frame with WPA IE but mismatch */
                        limSendAssocRspMgmtFrame(
                                       pMac,
                                       status,
                                       1,
                                       pHdr->sa,
                                       subType, 0,psessionEntry);

                        limLog(pMac, LOGW, FL("Rejecting Re/Assoc req from STA: "));
                        limPrintMacAddr(pMac, pHdr->sa, LOGW);
                        goto error;

                    }
                }
                else
                {
                    /* received Association req frame with invalid WPA IE */
                    limSendAssocRspMgmtFrame(
                                   pMac,
                                   eSIR_MAC_INVALID_INFORMATION_ELEMENT_STATUS,
                                   1,
                                   pHdr->sa,
                                   subType, 0,psessionEntry);

                    limLog(pMac, LOGW, FL("Rejecting Re/Assoc req from STA: "));
                    limPrintMacAddr(pMac, pHdr->sa, LOGW);
                    goto error;
                }/* end - if(pAssocReq->wpa.length) */
            } /* end - if(pAssocReq->wpaPresent) */
        } /* end of if(psessionEntry->pLimStartBssReq->privacy 
            && psessionEntry->pLimStartBssReq->rsnIE->length) */

    } /* end of     if( ! pAssocReq->wscInfo.present ) */
<<<<<<< HEAD
<<<<<<< HEAD
#endif //WLAN_SOFTAP_FEATURE
=======
>>>>>>> d97af3b... add prima wlan driver
=======
#endif //WLAN_SOFTAP_FEATURE
>>>>>>> 657b0e9... prima update

    /**
     * Extract 'associated' context for STA, if any.
     * This is maintained by DPH and created by LIM.
     */
<<<<<<< HEAD
<<<<<<< HEAD
    pStaDs = dphLookupHashEntry(pMac, pHdr->sa, &aid, &psessionEntry->dph.dphHashTable);
=======
    pStaDs = dphLookupHashEntry(pMac, pHdr->sa, &peerIdx, &psessionEntry->dph.dphHashTable);
>>>>>>> d97af3b... add prima wlan driver
=======
    pStaDs = dphLookupHashEntry(pMac, pHdr->sa, &aid, &psessionEntry->dph.dphHashTable);
>>>>>>> 657b0e9... prima update

    /// Extract pre-auth context for the STA, if any.
    pStaPreAuthContext = limSearchPreAuthList(pMac, pHdr->sa);

    if (pStaDs == NULL)
    {
        /// Requesting STA is not currently associated
<<<<<<< HEAD
<<<<<<< HEAD
        if (pMac->lim.gLimNumOfCurrentSTAs == pMac->lim.maxStation)
=======
        if (peGetCurrentSTAsCount(pMac) == pMac->lim.maxStation)
>>>>>>> d97af3b... add prima wlan driver
=======
        if (pMac->lim.gLimNumOfCurrentSTAs == pMac->lim.maxStation)
>>>>>>> 657b0e9... prima update
        {
            /**
             * Maximum number of STAs that AP can handle reached.
             * Send Association response to peer MAC entity
             */
            limRejectAssociation(pMac, pHdr->sa,
                                 subType, false,
                                 (tAniAuthType) 0, 0,
                                 false,
                                 (tSirResultCodes) eSIR_MAC_UNSPEC_FAILURE_STATUS, psessionEntry);

            goto error;
        }

        /// Check if STA is pre-authenticated.
        if ((pStaPreAuthContext == NULL) ||
            (pStaPreAuthContext &&
             (pStaPreAuthContext->mlmState !=
                              eLIM_MLM_AUTHENTICATED_STATE)))
        {
            /**
             * STA is not pre-authenticated yet requesting
             * Re/Association before Authentication.
             * OR STA is in the process of getting authenticated
             * and sent Re/Association request.
             * Send Deauthentication frame with 'prior
             * authentication required' reason code.
             */
            limSendDeauthMgmtFrame(
                     pMac,
                     eSIR_MAC_STA_NOT_PRE_AUTHENTICATED_REASON, //=9
<<<<<<< HEAD
<<<<<<< HEAD
                     pHdr->sa,psessionEntry);
=======
                     pHdr->sa, psessionEntry, FALSE);
>>>>>>> d97af3b... add prima wlan driver
=======
                     pHdr->sa,psessionEntry);
>>>>>>> 657b0e9... prima update

            // Log error
            if (subType == LIM_ASSOC)
                limLog(pMac, LOGW,
                       FL("received Assoc req from STA that does not have pre-auth context "MAC_ADDRESS_STR),
                       MAC_ADDR_ARRAY(pHdr->sa));
            else
                limLog(pMac, LOGW,
                       FL("received ReAssoc req from STA that does not have pre-auth context "
                       MAC_ADDRESS_STR), MAC_ADDR_ARRAY(pHdr->sa));
            goto error;
        }

        /// Delete 'pre-auth' context of STA
        authType = pStaPreAuthContext->authType;
        limDeletePreAuthNode(pMac, pHdr->sa);

        // All is well. Assign AID (after else part)

    } // if (pStaDs == NULL)
    else
    {
        // STA context does exist for this STA

        if (pStaDs->mlmStaContext.mlmState != eLIM_MLM_LINK_ESTABLISHED_STATE)
        {
            /**
             * Requesting STA is in some 'transient' state?
             * Ignore the Re/Assoc Req frame by incrementing
             * debug counter & logging error.
             */
            if (subType == LIM_ASSOC)
            {
            
#ifdef WLAN_DEBUG    
                pMac->lim.gLimNumAssocReqDropInvldState++;
#endif
                limLog(pMac, LOG1, FL("received Assoc req in state %X from "), pStaDs->mlmStaContext.mlmState);
            }
            else
            {     
#ifdef WLAN_DEBUG    
                pMac->lim.gLimNumReassocReqDropInvldState++;
#endif
                limLog(pMac, LOG1, FL("received ReAssoc req in state %X from "), pStaDs->mlmStaContext.mlmState);
            }
            limPrintMacAddr(pMac, pHdr->sa, LOG1);
            limPrintMlmState(pMac, LOG1, (tLimMlmStates) pStaDs->mlmStaContext.mlmState);

            goto error;
        } // if (pStaDs->mlmStaContext.mlmState != eLIM_MLM_LINK_ESTABLISHED_STATE)

<<<<<<< HEAD
<<<<<<< HEAD
        /**
         * STA sent Re/Association Request frame while already in
         * 'associated' state. Update STA capabilities and
         * send Association response frame with same AID
         */

        pStaDs->mlmStaContext.capabilityInfo = pAssocReq->capabilityInfo;

        if (pStaPreAuthContext &&
            (pStaPreAuthContext->mlmState ==
                                       eLIM_MLM_AUTHENTICATED_STATE))
        {
            /// STA has triggered pre-auth again
            authType = pStaPreAuthContext->authType;
            limDeletePreAuthNode(pMac, pHdr->sa);
        }
        else
            authType = pStaDs->mlmStaContext.authType;

        updateContext = true;

        if (dphInitStaState(pMac, pHdr->sa, aid, true, &psessionEntry->dph.dphHashTable) == NULL)   
        {
            limLog(pMac, LOGE, FL("could not Init STAid=%d\n"), aid);
            goto  error;
        }


        goto sendIndToSme;
=======
           /* STA sent association Request frame while already in
            * 'associated' state and no change in the capability
            *  so drop the frame */
        if ((VOS_TRUE == vos_mem_compare(&pStaDs->mlmStaContext.capabilityInfo,
                                          &pAssocReq->capabilityInfo,
                                          sizeof(tSirMacCapabilityInfo)))&&
                                         (subType == LIM_ASSOC))
        {
            limLog(pMac, LOGE, FL(" Received Assoc req in state %X STAid=%d"),
                                       pStaDs->mlmStaContext.mlmState,peerIdx);
            goto error;
        }
        else
        {
         /**
         * STA sent Re/association Request frame while already in
=======
        /**
         * STA sent Re/Association Request frame while already in
>>>>>>> 657b0e9... prima update
         * 'associated' state. Update STA capabilities and
         * send Association response frame with same AID
         */

        pStaDs->mlmStaContext.capabilityInfo = pAssocReq->capabilityInfo;

        if (pStaPreAuthContext &&
            (pStaPreAuthContext->mlmState ==
                                       eLIM_MLM_AUTHENTICATED_STATE))
        {
            /// STA has triggered pre-auth again
            authType = pStaPreAuthContext->authType;
            limDeletePreAuthNode(pMac, pHdr->sa);
        }
        else
            authType = pStaDs->mlmStaContext.authType;

        updateContext = true;

        if (dphInitStaState(pMac, pHdr->sa, aid, true, &psessionEntry->dph.dphHashTable) == NULL)   
        {
            limLog(pMac, LOGE, FL("could not Init STAid=%d\n"), aid);
            goto  error;
        }
<<<<<<< HEAD
       goto sendIndToSme;
>>>>>>> d97af3b... add prima wlan driver
=======


        goto sendIndToSme;
>>>>>>> 657b0e9... prima update
    } // end if (lookup for STA in perStaDs fails)



    // check if sta is allowed per QoS AC rules
    //if (pMac->dph.gDphQosEnabled || pMac->dph.gDphWmeEnabled)
    limGetWmeMode(psessionEntry, &wmeMode);
    if ((qosMode == eHAL_SET) || (wmeMode == eHAL_SET))
    {
        // for a qsta, check if the requested Traffic spec
        // is admissible
        // for a non-qsta check if the sta can be admitted
        if (pAssocReq->addtsPresent)
        {
            tANI_U8 tspecIdx = 0; //index in the sch tspec table.
            if (limAdmitControlAddTS(pMac, pHdr->sa, &(pAssocReq->addtsReq),
                                     &(pAssocReq->qosCapability), 0, false, NULL, &tspecIdx, psessionEntry) != eSIR_SUCCESS)
            {
<<<<<<< HEAD
<<<<<<< HEAD
                limLog(pMac, LOGW, FL("AdmitControl: TSPEC rejected\n"));
=======
                limLog(pMac, LOGW, FL("AdmitControl: TSPEC rejected"));
>>>>>>> d97af3b... add prima wlan driver
=======
                limLog(pMac, LOGW, FL("AdmitControl: TSPEC rejected\n"));
>>>>>>> 657b0e9... prima update
                limSendAssocRspMgmtFrame(
                               pMac,
                               eSIR_MAC_QAP_NO_BANDWIDTH_REASON,
                               1,
                               pHdr->sa,
                               subType, 0,psessionEntry);
#ifdef WLAN_DEBUG    
                pMac->lim.gLimNumAssocReqDropACRejectTS++;
#endif
                goto error;
            }
        }
        else if (limAdmitControlAddSta(pMac, pHdr->sa, false)
                                               != eSIR_SUCCESS)
        {
<<<<<<< HEAD
<<<<<<< HEAD
            limLog(pMac, LOGW, FL("AdmitControl: Sta rejected\n"));
=======
            limLog(pMac, LOGW, FL("AdmitControl: Sta rejected"));
>>>>>>> d97af3b... add prima wlan driver
=======
            limLog(pMac, LOGW, FL("AdmitControl: Sta rejected\n"));
>>>>>>> 657b0e9... prima update
            limSendAssocRspMgmtFrame(
                    pMac,
                    eSIR_MAC_QAP_NO_BANDWIDTH_REASON,
                    1,
                    pHdr->sa,
                    subType, 0,psessionEntry);
#ifdef WLAN_DEBUG    
            pMac->lim.gLimNumAssocReqDropACRejectSta++;
#endif
            goto error;
        }

        // else all ok
<<<<<<< HEAD
<<<<<<< HEAD
        limLog(pMac, LOG1, FL("AdmitControl: Sta OK!\n"));
=======
        limLog(pMac, LOG1, FL("AdmitControl: Sta OK!"));
>>>>>>> d97af3b... add prima wlan driver
=======
        limLog(pMac, LOG1, FL("AdmitControl: Sta OK!\n"));
>>>>>>> 657b0e9... prima update
    }

    /**
     * STA is Associated !
     */
    if (subType == LIM_ASSOC)
        limLog(pMac, LOGW, FL("received Assoc req successful "MAC_ADDRESS_STR),
               MAC_ADDR_ARRAY(pHdr->sa));
    else
        limLog(pMac, LOGW, FL("received ReAssoc req successful"MAC_ADDRESS_STR),
               MAC_ADDR_ARRAY(pHdr->sa));

    /**
<<<<<<< HEAD
<<<<<<< HEAD
     * Assign unused/least recently used AID from perStaDs.
     * This will 12-bit STAid used by MAC HW.
     * NOTE: limAssignAID() assigns AID values ranging between 1 - 255
     */

    aid = limAssignAID(pMac);

    if (!aid)
=======
     * AID for this association will be same as the peer Index used in DPH table.
     * Assign unused/least recently used peer Index from perStaDs.
     * NOTE: limAssignPeerIdx() assigns AID values ranging 
     * between 1 - cfg_item(WNI_CFG_ASSOC_STA_LIMIT)
=======
     * Assign unused/least recently used AID from perStaDs.
     * This will 12-bit STAid used by MAC HW.
     * NOTE: limAssignAID() assigns AID values ranging between 1 - 255
>>>>>>> 657b0e9... prima update
     */

    aid = limAssignAID(pMac);

<<<<<<< HEAD
    if (!peerIdx)
>>>>>>> d97af3b... add prima wlan driver
=======
    if (!aid)
>>>>>>> 657b0e9... prima update
    {
        // Could not assign AID
        // Reject association
        limRejectAssociation(pMac, pHdr->sa,
                             subType, true, authType,
<<<<<<< HEAD
<<<<<<< HEAD
                             aid, false,
=======
                             peerIdx, false,
>>>>>>> d97af3b... add prima wlan driver
=======
                             aid, false,
>>>>>>> 657b0e9... prima update
                             (tSirResultCodes) eSIR_MAC_UNSPEC_FAILURE_STATUS, psessionEntry);

        goto error;
    }

    /**
     * Add an entry to hash table maintained by DPH module
     */

<<<<<<< HEAD
<<<<<<< HEAD
    pStaDs = dphAddHashEntry(pMac, pHdr->sa, aid, &psessionEntry->dph.dphHashTable);
=======
    pStaDs = dphAddHashEntry(pMac, pHdr->sa, peerIdx, &psessionEntry->dph.dphHashTable);
>>>>>>> d97af3b... add prima wlan driver
=======
    pStaDs = dphAddHashEntry(pMac, pHdr->sa, aid, &psessionEntry->dph.dphHashTable);
>>>>>>> 657b0e9... prima update

    if (pStaDs == NULL)
    {
        // Could not add hash table entry at DPH
        limLog(pMac, LOGE,
<<<<<<< HEAD
<<<<<<< HEAD
           FL("could not add hash entry at DPH for aid=%d, MacAddr:\n"),
           aid);
        limPrintMacAddr(pMac, pHdr->sa, LOGE);

        // Release AID
        limReleaseAID(pMac, aid);

        limRejectAssociation(pMac, pHdr->sa,
                             subType, true, authType, aid, false,
=======
           FL("could not add hash entry at DPH for aid=%d, MacAddr:"),
           peerIdx);
=======
           FL("could not add hash entry at DPH for aid=%d, MacAddr:\n"),
           aid);
>>>>>>> 657b0e9... prima update
        limPrintMacAddr(pMac, pHdr->sa, LOGE);

        // Release AID
        limReleaseAID(pMac, aid);

        limRejectAssociation(pMac, pHdr->sa,
<<<<<<< HEAD
                             subType, true, authType, peerIdx, false,
>>>>>>> d97af3b... add prima wlan driver
=======
                             subType, true, authType, aid, false,
>>>>>>> 657b0e9... prima update
                             (tSirResultCodes) eSIR_MAC_UNSPEC_FAILURE_STATUS, psessionEntry);

        goto error;
    }


sendIndToSme:

    psessionEntry->parsedAssocReq[pStaDs->assocId] = pAssocReq;

    pStaDs->mlmStaContext.htCapability = pAssocReq->HTCaps.present;
#ifdef WLAN_FEATURE_11AC
    pStaDs->mlmStaContext.vhtCapability = pAssocReq->VHTCaps.present;
#endif
    pStaDs->qos.addtsPresent = (pAssocReq->addtsPresent==0) ? false : true;
    pStaDs->qos.addts        = pAssocReq->addtsReq;
    pStaDs->qos.capability   = pAssocReq->qosCapability;
    pStaDs->versionPresent   = 0;
    /* short slot and short preamble should be updated before doing limaddsta */
    pStaDs->shortPreambleEnabled = (tANI_U8)pAssocReq->capabilityInfo.shortPreamble;
    pStaDs->shortSlotTimeEnabled = (tANI_U8)pAssocReq->capabilityInfo.shortSlotTime;
 
    if (pAssocReq->propIEinfo.versionPresent) //update STA version info
    {
        pStaDs->versionPresent = 1;
        pStaDs->version = pAssocReq->propIEinfo.version;
    }
    pStaDs->propCapability = 0;
    if (pAssocReq->propIEinfo.capabilityPresent)
    {
        if (sirGetCfgPropCaps(pMac, &pStaDs->propCapability))
            pStaDs->propCapability &= pAssocReq->propIEinfo.capability;
    }

    pStaDs->mlmStaContext.mlmState = eLIM_MLM_WT_ASSOC_CNF_STATE;
    pStaDs->valid                  = 0;
    pStaDs->mlmStaContext.authType = authType;
    pStaDs->staType = STA_ENTRY_PEER;

    //TODO: If listen interval is more than certain limit, reject the association.
    //Need to check customer requirements and then implement.
    pStaDs->mlmStaContext.listenInterval = pAssocReq->listenInterval;
    pStaDs->mlmStaContext.capabilityInfo = pAssocReq->capabilityInfo;

    /* The following count will be used to knock-off the station if it doesn't
     * come back to receive the buffered data. The AP will wait for numTimSent number
     * of beacons after sending TIM information for the station, before assuming that 
     * the station is no more associated and disassociates it
     */

    /** timWaitCount is used by PMM for monitoring the STA's in PS for LINK*/
    pStaDs->timWaitCount = (tANI_U8)GET_TIM_WAIT_COUNT(pAssocReq->listenInterval);
    
    /** Initialise the Current successful MPDU's tranfered to this STA count as 0 */
    pStaDs->curTxMpduCnt = 0;

    if(IS_DOT11_MODE_HT(psessionEntry->dot11mode) &&
      (pAssocReq->HTCaps.present))
    {
        pStaDs->htGreenfield = (tANI_U8)pAssocReq->HTCaps.greenField;
        pStaDs->htAMpduDensity = pAssocReq->HTCaps.mpduDensity;
        pStaDs->htDsssCckRate40MHzSupport = (tANI_U8)pAssocReq->HTCaps.dsssCckMode40MHz;
        pStaDs->htLsigTXOPProtection = (tANI_U8)pAssocReq->HTCaps.lsigTXOPProtection;
        pStaDs->htMaxAmsduLength = (tANI_U8)pAssocReq->HTCaps.maximalAMSDUsize;
        pStaDs->htMaxRxAMpduFactor = pAssocReq->HTCaps.maxRxAMPDUFactor;
        pStaDs->htMIMOPSState = pAssocReq->HTCaps.mimoPowerSave;
        pStaDs->htShortGI20Mhz = (tANI_U8)pAssocReq->HTCaps.shortGI20MHz;
        pStaDs->htShortGI40Mhz = (tANI_U8)pAssocReq->HTCaps.shortGI40MHz;
        pStaDs->htSupportedChannelWidthSet = (tANI_U8)pAssocReq->HTCaps.supportedChannelWidthSet;
        /* peer just follows AP; so when we are softAP/GO, we just store our session entry's secondary channel offset here in peer INFRA STA
         * However, if peer's 40MHz channel width support is disabled then secondary channel will be zero
         */
        pStaDs->htSecondaryChannelOffset = (pStaDs->htSupportedChannelWidthSet)?psessionEntry->htSecondaryChannelOffset:0;
#ifdef WLAN_FEATURE_11AC
<<<<<<< HEAD
<<<<<<< HEAD
        if (pAssocReq->VHTCaps.present)
        {
            pStaDs->vhtSupportedChannelWidthSet = (tANI_U8)pAssocReq->VHTCaps.supportedChannelWidthSet; 
        }
#endif
        pStaDs->baPolicyFlag = 0xFF;
    }

=======
        if(pAssocReq->operMode.present) 
        {
            pStaDs->vhtSupportedChannelWidthSet = (tANI_U8)((pAssocReq->operMode.chanWidth == eHT_CHANNEL_WIDTH_80MHZ) ? WNI_CFG_VHT_CHANNEL_WIDTH_80MHZ : WNI_CFG_VHT_CHANNEL_WIDTH_20_40MHZ);
            pStaDs->htSupportedChannelWidthSet  = (tANI_U8)(pAssocReq->operMode.chanWidth ? eHT_CHANNEL_WIDTH_40MHZ : eHT_CHANNEL_WIDTH_20MHZ);
        }
        else if (pAssocReq->VHTCaps.present)
=======
        if (pAssocReq->VHTCaps.present)
>>>>>>> 657b0e9... prima update
        {
            pStaDs->vhtSupportedChannelWidthSet = (tANI_U8)pAssocReq->VHTCaps.supportedChannelWidthSet; 
        }
#endif
        pStaDs->baPolicyFlag = 0xFF;
    }

<<<<<<< HEAD
    if(pAssocReq->VHTCaps.present)
    {
        pStaDs->vhtLdpcCapable = (tANI_U8)pAssocReq->VHTCaps.ldpcCodingCap;
    }
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update

#ifdef WLAN_FEATURE_11AC
if (limPopulateMatchingRateSet(pMac,
                               pStaDs,
                               &(pAssocReq->supportedRates),
                               &(pAssocReq->extendedRates),
                               pAssocReq->HTCaps.supportedMCSSet,
                               &(pAssocReq->propIEinfo.propRates),
                               psessionEntry , &pAssocReq->VHTCaps) 
                               != eSIR_SUCCESS)
#else

    if (limPopulateMatchingRateSet(pMac,
                                   pStaDs,
                                   &(pAssocReq->supportedRates),
                                   &(pAssocReq->extendedRates),
                                   pAssocReq->HTCaps.supportedMCSSet,
                                   &(pAssocReq->propIEinfo.propRates), psessionEntry) != eSIR_SUCCESS)
#endif
    {
        // Could not update hash table entry at DPH with rateset
        limLog(pMac, LOGE,
<<<<<<< HEAD
<<<<<<< HEAD
           FL("could not update hash entry at DPH for aid=%d, MacAddr:\n"),
           aid);
        limPrintMacAddr(pMac, pHdr->sa, LOGE);

                // Release AID
        limReleaseAID(pMac, aid);


        limRejectAssociation(pMac, pHdr->sa,
                             subType, true, authType, aid, true,
                             (tSirResultCodes) eSIR_MAC_UNSPEC_FAILURE_STATUS, psessionEntry);

        /*return it from here rather than goto error statement.This is done as the memory is getting free twice*/
        return;
        //goto error;
    }

    palCopyMemory( pMac->hHdd, (tANI_U8 *) &pStaDs->mlmStaContext.propRateSet,
                  (tANI_U8 *) &(pAssocReq->propIEinfo.propRates),
=======
           FL("could not update hash entry at DPH for aid=%d, MacAddr:"),
           peerIdx);
=======
           FL("could not update hash entry at DPH for aid=%d, MacAddr:\n"),
           aid);
>>>>>>> 657b0e9... prima update
        limPrintMacAddr(pMac, pHdr->sa, LOGE);

                // Release AID
        limReleaseAID(pMac, aid);


        limRejectAssociation(pMac, pHdr->sa,
                             subType, true, authType, aid, true,
                             (tSirResultCodes) eSIR_MAC_UNSPEC_FAILURE_STATUS, psessionEntry);

        /*return it from here rather than goto error statement.This is done as the memory is getting free twice*/
        return;
        //goto error;
    }

<<<<<<< HEAD
    vos_mem_copy((tANI_U8 *) &pStaDs->mlmStaContext.propRateSet,
                 (tANI_U8 *) &(pAssocReq->propIEinfo.propRates),
>>>>>>> d97af3b... add prima wlan driver
=======
    palCopyMemory( pMac->hHdd, (tANI_U8 *) &pStaDs->mlmStaContext.propRateSet,
                  (tANI_U8 *) &(pAssocReq->propIEinfo.propRates),
>>>>>>> 657b0e9... prima update
                  pAssocReq->propIEinfo.propRates.numPropRates + 1);

    /// Add STA context at MAC HW (BMU, RHP & TFP)

    pStaDs->qosMode    = eANI_BOOLEAN_FALSE;
    pStaDs->lleEnabled = eANI_BOOLEAN_FALSE;
    if (pAssocReq->capabilityInfo.qos && (qosMode == eHAL_SET))
    {
        pStaDs->lleEnabled = eANI_BOOLEAN_TRUE;
        pStaDs->qosMode    = eANI_BOOLEAN_TRUE; 
    }

    pStaDs->wmeEnabled = eANI_BOOLEAN_FALSE;
    pStaDs->wsmEnabled = eANI_BOOLEAN_FALSE;
    limGetWmeMode(psessionEntry, &wmeMode);
    //if ((! pStaDs->lleEnabled) && assoc.wmeInfoPresent && pMac->dph.gDphWmeEnabled)
    if ((! pStaDs->lleEnabled) && pAssocReq->wmeInfoPresent && (wmeMode == eHAL_SET))
    {
        pStaDs->wmeEnabled = eANI_BOOLEAN_TRUE;
        pStaDs->qosMode = eANI_BOOLEAN_TRUE;
        limGetWsmMode(psessionEntry, &wsmMode);
        /* WMM_APSD - WMM_SA related processing should be separate; WMM_SA and WMM_APSD
         can coexist */
<<<<<<< HEAD
<<<<<<< HEAD
#ifdef WLAN_SOFTAP_FEATURE
=======
>>>>>>> d97af3b... add prima wlan driver
=======
#ifdef WLAN_SOFTAP_FEATURE
>>>>>>> 657b0e9... prima update
        if( pAssocReq->WMMInfoStation.present)
        {
            /* check whether AP supports or not */
            if ((psessionEntry->limSystemRole == eLIM_AP_ROLE)
                 && (psessionEntry->apUapsdEnable == 0) && (pAssocReq->WMMInfoStation.acbe_uapsd 
                    || pAssocReq->WMMInfoStation.acbk_uapsd 
                    || pAssocReq->WMMInfoStation.acvo_uapsd 
                    || pAssocReq->WMMInfoStation.acvi_uapsd))
            {

                /**
                 * Received Re/Association Request from
                 * STA when UPASD is not supported.
                 */
<<<<<<< HEAD
<<<<<<< HEAD
                limLog( pMac, LOGE, FL( "AP do not support UPASD REASSOC Failed\n" ));
                limRejectAssociation(pMac, pHdr->sa,
                                     subType, true, authType, aid, true,
                                     (tSirResultCodes) eSIR_MAC_WME_REFUSED_STATUS, psessionEntry);


                /*return it from here rather than goto error statement.This is done as the memory is getting free twice in this uapsd scenario*/
                return;
                //goto error;
=======
                limLog( pMac, LOGE, FL( "AP do not support UPASD REASSOC Failed" ));
=======
                limLog( pMac, LOGE, FL( "AP do not support UPASD REASSOC Failed\n" ));
>>>>>>> 657b0e9... prima update
                limRejectAssociation(pMac, pHdr->sa,
                                     subType, true, authType, aid, true,
                                     (tSirResultCodes) eSIR_MAC_WME_REFUSED_STATUS, psessionEntry);


<<<<<<< HEAD
                pAssocReq = psessionEntry->parsedAssocReq[pStaDs->assocId];
                goto error;
>>>>>>> d97af3b... add prima wlan driver
=======
                /*return it from here rather than goto error statement.This is done as the memory is getting free twice in this uapsd scenario*/
                return;
                //goto error;
>>>>>>> 657b0e9... prima update
            }
            else
            {
                /* update UAPSD and send it to LIM to add STA */
                pStaDs->qos.capability.qosInfo.acbe_uapsd = pAssocReq->WMMInfoStation.acbe_uapsd;
                pStaDs->qos.capability.qosInfo.acbk_uapsd = pAssocReq->WMMInfoStation.acbk_uapsd;
                pStaDs->qos.capability.qosInfo.acvo_uapsd = pAssocReq->WMMInfoStation.acvo_uapsd;
                pStaDs->qos.capability.qosInfo.acvi_uapsd = pAssocReq->WMMInfoStation.acvi_uapsd;
                pStaDs->qos.capability.qosInfo.maxSpLen = pAssocReq->WMMInfoStation.max_sp_length;
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
        //if (assoc.wsmCapablePresent && pMac->dph.gDphWsmEnabled)
        if (pAssocReq->wsmCapablePresent && (wsmMode == eHAL_SET))
            pStaDs->wsmEnabled = eANI_BOOLEAN_TRUE;

    }

    // Re/Assoc Response frame to requesting STA
    pStaDs->mlmStaContext.subType = subType;

    if (pAssocReq->propIEinfo.aniIndicator)
        pStaDs->aniPeer = 1;

<<<<<<< HEAD
<<<<<<< HEAD
=======
#ifdef WLAN_FEATURE_11W
    pStaDs->rmfEnabled = (pmfConnection) ? 1 : 0;
#endif

>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
    // BTAMP: Storing the parsed assoc request in the psessionEntry array
    psessionEntry->parsedAssocReq[pStaDs->assocId] = pAssocReq;

    /* BTAMP: If STA context already exist (ie. updateContext = 1)  
     * for this STA, then we should delete the old one, and add 
     * the new STA. This is taken care of in the limDelSta() routine.   
     *
     * Prior to BTAMP, we were setting this flag so that when
     * PE receives SME_ASSOC_CNF, and if this flag is set, then 
     * PE shall delete the old station and then add. But now in
     * BTAMP, we're directly adding station before waiting for
     * SME_ASSOC_CNF, so we can do this now.  
     */
    if (!updateContext)
    {
        pStaDs->mlmStaContext.updateContext = 0;

        // BTAMP: Add STA context at HW - issue WDA_ADD_STA_REQ to HAL
<<<<<<< HEAD
<<<<<<< HEAD
        if (limAddSta(pMac, pStaDs,psessionEntry) != eSIR_SUCCESS)
        {
            limLog(pMac, LOGE, FL("could not Add STA with assocId=%d\n"), pStaDs->assocId);
=======
        if (limAddSta(pMac, pStaDs, false, psessionEntry) != eSIR_SUCCESS)
        {
            limLog(pMac, LOGE, FL("could not Add STA with assocId=%d"), pStaDs->assocId);
>>>>>>> d97af3b... add prima wlan driver
=======
        if (limAddSta(pMac, pStaDs,psessionEntry) != eSIR_SUCCESS)
        {
            limLog(pMac, LOGE, FL("could not Add STA with assocId=%d\n"), pStaDs->assocId);
>>>>>>> 657b0e9... prima update
            limRejectAssociation( pMac, pStaDs->staAddr, pStaDs->mlmStaContext.subType,
                                  true, pStaDs->mlmStaContext.authType, pStaDs->assocId, true,
                                  (tSirResultCodes) eSIR_MAC_UNSPEC_FAILURE_STATUS, psessionEntry);

<<<<<<< HEAD
<<<<<<< HEAD
            /*return it from here rather than goto error statement.This is done as the memory is getting free twice*/
            return;
            //goto error;
=======
            pAssocReq = psessionEntry->parsedAssocReq[pStaDs->assocId];
            goto error;
>>>>>>> d97af3b... add prima wlan driver
=======
            /*return it from here rather than goto error statement.This is done as the memory is getting free twice*/
            return;
            //goto error;
>>>>>>> 657b0e9... prima update
        }
    }
    else
    {
        pStaDs->mlmStaContext.updateContext = 1;

<<<<<<< HEAD
<<<<<<< HEAD
#ifdef WLAN_SOFTAP_FEATURE
=======
>>>>>>> d97af3b... add prima wlan driver
=======
#ifdef WLAN_SOFTAP_FEATURE
>>>>>>> 657b0e9... prima update
        mlmPrevState = pStaDs->mlmStaContext.mlmState;

        /* As per the HAL/FW needs the reassoc req need not be calling limDelSta */
        if(subType != LIM_REASSOC)
        {
            //we need to set the mlmState here in order differentiate in limDelSta.
            pStaDs->mlmStaContext.mlmState = eLIM_MLM_WT_ASSOC_DEL_STA_RSP_STATE;
            if(limDelSta(pMac, pStaDs, true, psessionEntry) != eSIR_SUCCESS)
            {
<<<<<<< HEAD
<<<<<<< HEAD
                limLog(pMac, LOGE, FL("could not DEL STA with assocId=%d staId %d\n"), pStaDs->assocId, pStaDs->staIndex);
=======
                limLog(pMac, LOGE, FL("could not DEL STA with assocId=%d staId %d"), pStaDs->assocId, pStaDs->staIndex);
>>>>>>> d97af3b... add prima wlan driver
=======
                limLog(pMac, LOGE, FL("could not DEL STA with assocId=%d staId %d\n"), pStaDs->assocId, pStaDs->staIndex);
>>>>>>> 657b0e9... prima update
                limRejectAssociation( pMac, pStaDs->staAddr, pStaDs->mlmStaContext.subType, true, pStaDs->mlmStaContext.authType,
                                      pStaDs->assocId, true,(tSirResultCodes) eSIR_MAC_UNSPEC_FAILURE_STATUS, psessionEntry);

                //Restoring the state back.
                pStaDs->mlmStaContext.mlmState = mlmPrevState;
<<<<<<< HEAD
<<<<<<< HEAD
=======
                pAssocReq = psessionEntry->parsedAssocReq[pStaDs->assocId];
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
                goto error;
            }
        }
        else
        {
            /* mlmState is changed in limAddSta context */
            /* use the same AID, already allocated */
<<<<<<< HEAD
<<<<<<< HEAD
            if (limAddSta(pMac, pStaDs,psessionEntry) != eSIR_SUCCESS)
            {
                    limLog( pMac, LOGE, FL( "AP do not support UPASD REASSOC Failed\n" ));
=======
            if (limAddSta(pMac, pStaDs, false, psessionEntry) != eSIR_SUCCESS)
            {
                    limLog( pMac, LOGE, FL( "AP do not support UPASD REASSOC Failed" ));
>>>>>>> d97af3b... add prima wlan driver
=======
            if (limAddSta(pMac, pStaDs,psessionEntry) != eSIR_SUCCESS)
            {
                    limLog( pMac, LOGE, FL( "AP do not support UPASD REASSOC Failed\n" ));
>>>>>>> 657b0e9... prima update
                    limRejectAssociation( pMac, pStaDs->staAddr, pStaDs->mlmStaContext.subType, true, pStaDs->mlmStaContext.authType,
                                          pStaDs->assocId, true,(tSirResultCodes) eSIR_MAC_WME_REFUSED_STATUS, psessionEntry);

                    //Restoring the state back.
                    pStaDs->mlmStaContext.mlmState = mlmPrevState;
<<<<<<< HEAD
<<<<<<< HEAD
=======
                    pAssocReq = psessionEntry->parsedAssocReq[pStaDs->assocId];
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
                    goto error;
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

    }

    return;

error:
    if (pAssocReq != NULL)
    {
        if ( pAssocReq->assocReqFrame ) 
        {
<<<<<<< HEAD
<<<<<<< HEAD
            palFreeMemory(pMac->hHdd, pAssocReq->assocReqFrame);
            pAssocReq->assocReqFrame = NULL;
        }

        if (palFreeMemory(pMac->hHdd, pAssocReq) != eHAL_STATUS_SUCCESS) 
        {
            limLog(pMac, LOGP, FL("PalFree Memory failed \n"));
            return;
        }
=======
            vos_mem_free(pAssocReq->assocReqFrame);
            pAssocReq->assocReqFrame = NULL;
        }

        vos_mem_free(pAssocReq);
>>>>>>> d97af3b... add prima wlan driver
=======
            palFreeMemory(pMac->hHdd, pAssocReq->assocReqFrame);
            pAssocReq->assocReqFrame = NULL;
        }

        if (palFreeMemory(pMac->hHdd, pAssocReq) != eHAL_STATUS_SUCCESS) 
        {
            limLog(pMac, LOGP, FL("PalFree Memory failed \n"));
            return;
        }
>>>>>>> 657b0e9... prima update
    }

    /* If it is not duplicate Assoc request then only make to Null */
    if ((pStaDs != NULL) &&
          (pStaDs->mlmStaContext.mlmState != eLIM_MLM_WT_ADD_STA_RSP_STATE))
        psessionEntry->parsedAssocReq[pStaDs->assocId] = NULL;

    return;

} /*** end limProcessAssocReqFrame() ***/



/**---------------------------------------------------------------
\fn     limSendMlmAssocInd
\brief  This function sends either LIM_MLM_ASSOC_IND  
\       or LIM_MLM_REASSOC_IND to SME.
\
\param  pMac
\param  *pStaDs - Station DPH hash entry
\param  psessionEntry - PE session entry
\return None

 * ?????? How do I get 
 *  - subtype   =====> psessionEntry->parsedAssocReq.reassocRequest
 *  - aid       =====> pStaDs->assocId
 *  - pHdr->sa  =====> pStaDs->staAddr
 *  - authType
 *  - pHdr->seqControl  =====> no longer needed
 *  - pStaDs
------------------------------------------------------------------*/
void limSendMlmAssocInd(tpAniSirGlobal pMac, tpDphHashNode pStaDs, tpPESession psessionEntry)
{
    tpLimMlmAssocInd        pMlmAssocInd = NULL;
    tpLimMlmReassocInd      pMlmReassocInd;
    tpSirAssocReq           pAssocReq;
    tANI_U16                temp;
    tANI_U32                phyMode;
    tANI_U8                 subType;
<<<<<<< HEAD
<<<<<<< HEAD
#ifdef WLAN_SOFTAP_FEATURE
    tANI_U8                 *wpsIe = NULL;
#endif
=======
    tANI_U8                 *wpsIe = NULL;
>>>>>>> d97af3b... add prima wlan driver
=======
#ifdef WLAN_SOFTAP_FEATURE
    tANI_U8                 *wpsIe = NULL;
#endif
>>>>>>> 657b0e9... prima update
    tANI_U32                tmp;
//    tANI_U16                statusCode;    
    tANI_U16                i, j=0;

    // Get a copy of the already parsed Assoc Request
    pAssocReq = (tpSirAssocReq) psessionEntry->parsedAssocReq[pStaDs->assocId];

    // Get the phyMode
    limGetPhyMode(pMac, &phyMode, psessionEntry);
 
    // Extract pre-auth context for the peer BTAMP-STA, if any.
 
    // Determiine if its Assoc or ReAssoc Request
    if (pAssocReq->reassocRequest == 1)
        subType = LIM_REASSOC;
    else 
        subType = LIM_ASSOC;
<<<<<<< HEAD
<<<<<<< HEAD
#ifdef WLAN_SOFTAP_FEATURE
    if (subType == LIM_ASSOC || subType == LIM_REASSOC)
#else
    if (subType == LIM_ASSOC )
#endif
    {
        temp  = sizeof(tLimMlmAssocInd);
#if (WNI_POLARIS_FW_PACKAGE == ADVANCED) && defined(ANI_PRODUCT_TYPE_AP)        
        temp += pAssocReq->propIEinfo.numBss * sizeof(tSirNeighborBssInfo);
#endif        

        if( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd, (void **)&pMlmAssocInd, temp))
        {
            limReleaseAID(pMac, pStaDs->assocId);
            limLog(pMac, LOGP, FL("palAllocateMemory failed for pMlmAssocInd\n"));
            return;
        }
        palZeroMemory( pMac->hHdd, pMlmAssocInd, temp);

        palCopyMemory( pMac->hHdd,(tANI_U8 *)pMlmAssocInd->peerMacAddr,(tANI_U8 *)pStaDs->staAddr,sizeof(tSirMacAddr));
 
        pMlmAssocInd->aid    = pStaDs->assocId;
        palCopyMemory( pMac->hHdd, (tANI_U8 *)&pMlmAssocInd->ssId,(tANI_U8 *)&(pAssocReq->ssId), pAssocReq->ssId.length + 1);
        pMlmAssocInd->sessionId = psessionEntry->peSessionId;
        pMlmAssocInd->authType =  pStaDs->mlmStaContext.authType;
 
#if (WNI_POLARIS_FW_PACKAGE == ADVANCED) && defined(ANI_PRODUCT_TYPE_AP)
        // Note for BTAMP: no need to fill in pMlmAssocInd->seqNum
        pMlmAssocInd->wniIndicator = (tAniBool) pAssocReq->propIEinfo.aniIndicator;
        pMlmAssocInd->bpIndicator  = (tAniBool) pAssocReq->propIEinfo.bpIndicator;
        pMlmAssocInd->bpType       = (tSirBpIndicatorType) pAssocReq->propIEinfo.bpType;
        if (pAssocReq->extendedRatesPresent)
        {
            pMlmAssocInd->nwType = eSIR_11G_NW_TYPE;
            limSetStaHashErpMode(pMac, pStaDs->assocId, eHAL_SET);
        }
        else
        {
            if (phyMode == WNI_CFG_PHY_MODE_11A)
                pMlmAssocInd->nwType = eSIR_11A_NW_TYPE;
            else
            {
                pMlmAssocInd->nwType = eSIR_11B_NW_TYPE;
                limSetStaHashErpMode(pMac, pStaDs->assocId, eHAL_CLEAR);
            }
        }
        pMlmAssocInd->assocType = (tSirAssocType)pAssocReq->propIEinfo.assocType;
        pMlmAssocInd->load.numStas = pMac->lim.gLimNumOfCurrentSTAs;
        pMlmAssocInd->load.channelUtilization =(pMac->lim.gpLimMeasData) ? pMac->lim.gpLimMeasData->avgChannelUtilization : 0;
        pMlmAssocInd->numBss = (tANI_U32) pAssocReq->propIEinfo.numBss;
        if (pAssocReq->propIEinfo.numBss)
        {
            palCopyMemory( pMac->hHdd,(tANI_U8 *) pMlmAssocInd->neighborList,(tANI_U8 *)pAssocReq->propIEinfo.pBssList,
                           (sizeof(tSirNeighborBssInfo) * pAssocReq->propIEinfo.numBss));
        } 
#endif
=======
=======
#ifdef WLAN_SOFTAP_FEATURE
>>>>>>> 657b0e9... prima update
    if (subType == LIM_ASSOC || subType == LIM_REASSOC)
#else
    if (subType == LIM_ASSOC )
#endif
    {
        temp  = sizeof(tLimMlmAssocInd);
#if (WNI_POLARIS_FW_PACKAGE == ADVANCED) && defined(ANI_PRODUCT_TYPE_AP)        
        temp += pAssocReq->propIEinfo.numBss * sizeof(tSirNeighborBssInfo);
#endif        

        if( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd, (void **)&pMlmAssocInd, temp))
        {
            limReleaseAID(pMac, pStaDs->assocId);
            limLog(pMac, LOGP, FL("palAllocateMemory failed for pMlmAssocInd\n"));
            return;
        }
        palZeroMemory( pMac->hHdd, pMlmAssocInd, temp);

        palCopyMemory( pMac->hHdd,(tANI_U8 *)pMlmAssocInd->peerMacAddr,(tANI_U8 *)pStaDs->staAddr,sizeof(tSirMacAddr));
 
        pMlmAssocInd->aid    = pStaDs->assocId;
        palCopyMemory( pMac->hHdd, (tANI_U8 *)&pMlmAssocInd->ssId,(tANI_U8 *)&(pAssocReq->ssId), pAssocReq->ssId.length + 1);
        pMlmAssocInd->sessionId = psessionEntry->peSessionId;
        pMlmAssocInd->authType =  pStaDs->mlmStaContext.authType;
 
<<<<<<< HEAD
>>>>>>> d97af3b... add prima wlan driver
=======
#if (WNI_POLARIS_FW_PACKAGE == ADVANCED) && defined(ANI_PRODUCT_TYPE_AP)
        // Note for BTAMP: no need to fill in pMlmAssocInd->seqNum
        pMlmAssocInd->wniIndicator = (tAniBool) pAssocReq->propIEinfo.aniIndicator;
        pMlmAssocInd->bpIndicator  = (tAniBool) pAssocReq->propIEinfo.bpIndicator;
        pMlmAssocInd->bpType       = (tSirBpIndicatorType) pAssocReq->propIEinfo.bpType;
        if (pAssocReq->extendedRatesPresent)
        {
            pMlmAssocInd->nwType = eSIR_11G_NW_TYPE;
            limSetStaHashErpMode(pMac, pStaDs->assocId, eHAL_SET);
        }
        else
        {
            if (phyMode == WNI_CFG_PHY_MODE_11A)
                pMlmAssocInd->nwType = eSIR_11A_NW_TYPE;
            else
            {
                pMlmAssocInd->nwType = eSIR_11B_NW_TYPE;
                limSetStaHashErpMode(pMac, pStaDs->assocId, eHAL_CLEAR);
            }
        }
        pMlmAssocInd->assocType = (tSirAssocType)pAssocReq->propIEinfo.assocType;
        pMlmAssocInd->load.numStas = pMac->lim.gLimNumOfCurrentSTAs;
        pMlmAssocInd->load.channelUtilization =(pMac->lim.gpLimMeasData) ? pMac->lim.gpLimMeasData->avgChannelUtilization : 0;
        pMlmAssocInd->numBss = (tANI_U32) pAssocReq->propIEinfo.numBss;
        if (pAssocReq->propIEinfo.numBss)
        {
            palCopyMemory( pMac->hHdd,(tANI_U8 *) pMlmAssocInd->neighborList,(tANI_U8 *)pAssocReq->propIEinfo.pBssList,
                           (sizeof(tSirNeighborBssInfo) * pAssocReq->propIEinfo.numBss));
        } 
#endif
>>>>>>> 657b0e9... prima update
        pMlmAssocInd->capabilityInfo = pAssocReq->capabilityInfo;

        // Fill in RSN IE information
        pMlmAssocInd->rsnIE.length = 0;
<<<<<<< HEAD
<<<<<<< HEAD
#ifdef WLAN_SOFTAP_FEATURE
=======
>>>>>>> d97af3b... add prima wlan driver
=======
#ifdef WLAN_SOFTAP_FEATURE
>>>>>>> 657b0e9... prima update
        // if WPS IE is present, ignore RSN IE
        if (pAssocReq->addIEPresent && pAssocReq->addIE.length ) {
            wpsIe = limGetWscIEPtr(pMac, pAssocReq->addIE.addIEdata, pAssocReq->addIE.length);
        }
        if (pAssocReq->rsnPresent && (NULL == wpsIe))
<<<<<<< HEAD
<<<<<<< HEAD
#else
        if (pAssocReq->rsnPresent)
#endif
        {
            limLog(pMac, LOG2, FL("Assoc Req RSN IE len = %d\n"), pAssocReq->rsn.length);
            pMlmAssocInd->rsnIE.length = 2 + pAssocReq->rsn.length;
            pMlmAssocInd->rsnIE.rsnIEdata[0] = SIR_MAC_RSN_EID;
            pMlmAssocInd->rsnIE.rsnIEdata[1] = pAssocReq->rsn.length;
            palCopyMemory( pMac->hHdd, 
                           &pMlmAssocInd->rsnIE.rsnIEdata[2],
                           pAssocReq->rsn.info,
                           pAssocReq->rsn.length);
=======
=======
#else
        if (pAssocReq->rsnPresent)
#endif
>>>>>>> 657b0e9... prima update
        {
            limLog(pMac, LOG2, FL("Assoc Req RSN IE len = %d\n"), pAssocReq->rsn.length);
            pMlmAssocInd->rsnIE.length = 2 + pAssocReq->rsn.length;
            pMlmAssocInd->rsnIE.rsnIEdata[0] = SIR_MAC_RSN_EID;
            pMlmAssocInd->rsnIE.rsnIEdata[1] = pAssocReq->rsn.length;
<<<<<<< HEAD
            vos_mem_copy(&pMlmAssocInd->rsnIE.rsnIEdata[2],
                         pAssocReq->rsn.info,
                         pAssocReq->rsn.length);
>>>>>>> d97af3b... add prima wlan driver
=======
            palCopyMemory( pMac->hHdd, 
                           &pMlmAssocInd->rsnIE.rsnIEdata[2],
                           pAssocReq->rsn.info,
                           pAssocReq->rsn.length);
>>>>>>> 657b0e9... prima update
        }

        // Fill in 802.11h related info
        if (pAssocReq->powerCapabilityPresent && pAssocReq->supportedChannelsPresent)
        {
            pMlmAssocInd->spectrumMgtIndicator = eSIR_TRUE;
            pMlmAssocInd->powerCap.minTxPower = pAssocReq->powerCapability.minTxPower;
            pMlmAssocInd->powerCap.maxTxPower = pAssocReq->powerCapability.maxTxPower;
            limConvertSupportedChannels(pMac, pMlmAssocInd, pAssocReq);
        }
        else
            pMlmAssocInd->spectrumMgtIndicator = eSIR_FALSE;


<<<<<<< HEAD
<<<<<<< HEAD
#ifdef WLAN_SOFTAP_FEATURE
        /* This check is to avoid extra Sec IEs present incase of WPS */
        if (pAssocReq->wpaPresent && (NULL == wpsIe))
#else
        if ((pAssocReq->wpaPresent) && (pMlmAssocInd->rsnIE.length < SIR_MAC_MAX_IE_LENGTH))
#endif
        {
            if((pMlmAssocInd->rsnIE.length + pAssocReq->wpa.length) >= SIR_MAC_MAX_IE_LENGTH)
            {
                PELOGE(limLog(pMac, LOGE, FL("rsnIEdata index out of bounds %d\n"), pMlmAssocInd->rsnIE.length);)
=======
=======
#ifdef WLAN_SOFTAP_FEATURE
>>>>>>> 657b0e9... prima update
        /* This check is to avoid extra Sec IEs present incase of WPS */
        if (pAssocReq->wpaPresent && (NULL == wpsIe))
#else
        if ((pAssocReq->wpaPresent) && (pMlmAssocInd->rsnIE.length < SIR_MAC_MAX_IE_LENGTH))
#endif
        {
            if((pMlmAssocInd->rsnIE.length + pAssocReq->wpa.length) >= SIR_MAC_MAX_IE_LENGTH)
            {
<<<<<<< HEAD
                PELOGE(limLog(pMac, LOGE, FL("rsnIEdata index out of bounds %d"), pMlmAssocInd->rsnIE.length);)
                vos_mem_free(pMlmAssocInd);
>>>>>>> d97af3b... add prima wlan driver
=======
                PELOGE(limLog(pMac, LOGE, FL("rsnIEdata index out of bounds %d\n"), pMlmAssocInd->rsnIE.length);)
>>>>>>> 657b0e9... prima update
                return;
            }
            pMlmAssocInd->rsnIE.rsnIEdata[pMlmAssocInd->rsnIE.length] = SIR_MAC_WPA_EID;
            pMlmAssocInd->rsnIE.rsnIEdata[pMlmAssocInd->rsnIE.length + 1] = pAssocReq->wpa.length;
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
            palCopyMemory( pMac->hHdd,
                           &pMlmAssocInd->rsnIE.rsnIEdata[pMlmAssocInd->rsnIE.length + 2],
                           pAssocReq->wpa.info,
                           pAssocReq->wpa.length);
<<<<<<< HEAD
=======
            vos_mem_copy(&pMlmAssocInd->rsnIE.rsnIEdata[pMlmAssocInd->rsnIE.length + 2],
                         pAssocReq->wpa.info,
                         pAssocReq->wpa.length);
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
            pMlmAssocInd->rsnIE.length += 2 + pAssocReq->wpa.length;
        }


       pMlmAssocInd->addIE.length = 0;
       if (pAssocReq->addIEPresent)
       {
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
            palCopyMemory( pMac->hHdd,
                           &pMlmAssocInd->addIE.addIEdata,
                           pAssocReq->addIE.addIEdata,
                           pAssocReq->addIE.length);
<<<<<<< HEAD
=======
            vos_mem_copy(&pMlmAssocInd->addIE.addIEdata,
                          pAssocReq->addIE.addIEdata,
                          pAssocReq->addIE.length);
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update

            pMlmAssocInd->addIE.length = pAssocReq->addIE.length;
       }

<<<<<<< HEAD
<<<<<<< HEAD
#ifdef WLAN_SOFTAP_FEATURE
=======
>>>>>>> d97af3b... add prima wlan driver
=======
#ifdef WLAN_SOFTAP_FEATURE
>>>>>>> 657b0e9... prima update
        if(pAssocReq->wmeInfoPresent)
        {

            if (wlan_cfgGetInt(pMac, (tANI_U16) WNI_CFG_WME_ENABLED, &tmp) != eSIR_SUCCESS)
<<<<<<< HEAD
<<<<<<< HEAD
                 limLog(pMac, LOGP, FL("wlan_cfgGetInt failed for id %d\n"), WNI_CFG_WME_ENABLED );
=======
                 limLog(pMac, LOGP, FL("wlan_cfgGetInt failed for id %d"), WNI_CFG_WME_ENABLED );
>>>>>>> d97af3b... add prima wlan driver
=======
                 limLog(pMac, LOGP, FL("wlan_cfgGetInt failed for id %d\n"), WNI_CFG_WME_ENABLED );
>>>>>>> 657b0e9... prima update

            /* check whether AP is enabled with WMM */
            if(tmp)
            {
                pMlmAssocInd->WmmStaInfoPresent = 1;
            }
            else
            {
                pMlmAssocInd->WmmStaInfoPresent= 0;
            }
            /* Note: we are not rejecting association here because IOT will fail */

        }
<<<<<<< HEAD
<<<<<<< HEAD
#endif
=======
>>>>>>> d97af3b... add prima wlan driver
=======
#endif
>>>>>>> 657b0e9... prima update

        // Required for indicating the frames to upper layer
        pMlmAssocInd->assocReqLength = pAssocReq->assocReqFrameLength;
        pMlmAssocInd->assocReqPtr = pAssocReq->assocReqFrame;
        
        pMlmAssocInd->beaconPtr = psessionEntry->beacon;
        pMlmAssocInd->beaconLength = psessionEntry->bcnLen;

        limPostSmeMessage(pMac, LIM_MLM_ASSOC_IND, (tANI_U32 *) pMlmAssocInd);
<<<<<<< HEAD
<<<<<<< HEAD
        palFreeMemory( pMac->hHdd, pMlmAssocInd);
=======
        vos_mem_free(pMlmAssocInd);
>>>>>>> d97af3b... add prima wlan driver
=======
        palFreeMemory( pMac->hHdd, pMlmAssocInd);
>>>>>>> 657b0e9... prima update
    }
    else
    {
        // If its of Reassociation Request, then post LIM_MLM_REASSOC_IND 
        temp  = sizeof(tLimMlmReassocInd);

<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
#if (WNI_POLARIS_FW_PACKAGE == ADVANCED)
        temp += pAssocReq->propIEinfo.numBss * sizeof(tSirNeighborBssInfo);
#endif
        if( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd, (void **)&pMlmReassocInd, temp))
<<<<<<< HEAD
        {
            limLog(pMac, LOGP, FL("call to palAllocateMemory failed for pMlmReassocInd\n"));
            limReleaseAID(pMac, pStaDs->assocId);
            return;
        }
        palZeroMemory( pMac->hHdd, pMlmReassocInd, temp);

        palCopyMemory( pMac->hHdd,(tANI_U8 *) pMlmReassocInd->peerMacAddr, (tANI_U8 *)pStaDs->staAddr, sizeof(tSirMacAddr));
        palCopyMemory( pMac->hHdd,(tANI_U8 *) pMlmReassocInd->currentApAddr, (tANI_U8 *)&(pAssocReq->currentApAddr), sizeof(tSirMacAddr));
        pMlmReassocInd->aid = pStaDs->assocId;
        pMlmReassocInd->authType = pStaDs->mlmStaContext.authType;
        palCopyMemory( pMac->hHdd,(tANI_U8 *)&pMlmReassocInd->ssId, (tANI_U8 *)&(pAssocReq->ssId), pAssocReq->ssId.length + 1);

#if (WNI_POLARIS_FW_PACKAGE == ADVANCED) && defined(ANI_PRODUCT_TYPE_AP)
        // Note for BTAMP: no need to fill in pMlmAssocInd->seqNum
        pMlmReassocInd->wniIndicator = (tAniBool) pAssocReq->propIEinfo.aniIndicator;
        pMlmReassocInd->bpIndicator  = (tAniBool) pAssocReq->propIEinfo.bpIndicator;
        pMlmReassocInd->bpType       = (tSirBpIndicatorType) pAssocReq->propIEinfo.bpType;
        if (pAssocReq->extendedRatesPresent)
        {
            pMlmReassocInd->nwType = eSIR_11G_NW_TYPE;
            limSetStaHashErpMode(pMac, pStaDs->assocId, eHAL_SET);
        }
        else
        {
            if (phyMode == WNI_CFG_PHY_MODE_11A)
                pMlmReassocInd->nwType = eSIR_11A_NW_TYPE;
            else
            {
                pMlmReassocInd->nwType = eSIR_11B_NW_TYPE;
                limSetStaHashErpMode(pMac, pStaDs->assocId, eHAL_CLEAR);
            }
        }

        pMlmReassocInd->reassocType  = (tSirAssocType)pAssocReq->propIEinfo.assocType;
        pMlmReassocInd->load.numStas = pMac->lim.gLimNumOfCurrentSTAs;
        pMlmReassocInd->load.channelUtilization = (pMac->lim.gpLimMeasData) ?
                                                  pMac->lim.gpLimMeasData->avgChannelUtilization : 0;
        pMlmReassocInd->numBss = (tANI_U32) pAssocReq->propIEinfo.numBss;
        if (pAssocReq->propIEinfo.numBss)
        {
            palCopyMemory( pMac->hHdd, 
                           (tANI_U8 *) pMlmReassocInd->neighborList,
                           (tANI_U8 *) pAssocReq->propIEinfo.pBssList,
                           (sizeof(tSirNeighborBssInfo) * pAssocReq->propIEinfo.numBss));
        }
#endif
=======
        pMlmReassocInd = vos_mem_malloc(temp);
        if (NULL == pMlmReassocInd)
=======
>>>>>>> 657b0e9... prima update
        {
            limLog(pMac, LOGP, FL("call to palAllocateMemory failed for pMlmReassocInd\n"));
            limReleaseAID(pMac, pStaDs->assocId);
            return;
        }
        palZeroMemory( pMac->hHdd, pMlmReassocInd, temp);

        palCopyMemory( pMac->hHdd,(tANI_U8 *) pMlmReassocInd->peerMacAddr, (tANI_U8 *)pStaDs->staAddr, sizeof(tSirMacAddr));
        palCopyMemory( pMac->hHdd,(tANI_U8 *) pMlmReassocInd->currentApAddr, (tANI_U8 *)&(pAssocReq->currentApAddr), sizeof(tSirMacAddr));
        pMlmReassocInd->aid = pStaDs->assocId;
        pMlmReassocInd->authType = pStaDs->mlmStaContext.authType;
        palCopyMemory( pMac->hHdd,(tANI_U8 *)&pMlmReassocInd->ssId, (tANI_U8 *)&(pAssocReq->ssId), pAssocReq->ssId.length + 1);

#if (WNI_POLARIS_FW_PACKAGE == ADVANCED) && defined(ANI_PRODUCT_TYPE_AP)
        // Note for BTAMP: no need to fill in pMlmAssocInd->seqNum
        pMlmReassocInd->wniIndicator = (tAniBool) pAssocReq->propIEinfo.aniIndicator;
        pMlmReassocInd->bpIndicator  = (tAniBool) pAssocReq->propIEinfo.bpIndicator;
        pMlmReassocInd->bpType       = (tSirBpIndicatorType) pAssocReq->propIEinfo.bpType;
        if (pAssocReq->extendedRatesPresent)
        {
            pMlmReassocInd->nwType = eSIR_11G_NW_TYPE;
            limSetStaHashErpMode(pMac, pStaDs->assocId, eHAL_SET);
        }
        else
        {
            if (phyMode == WNI_CFG_PHY_MODE_11A)
                pMlmReassocInd->nwType = eSIR_11A_NW_TYPE;
            else
            {
                pMlmReassocInd->nwType = eSIR_11B_NW_TYPE;
                limSetStaHashErpMode(pMac, pStaDs->assocId, eHAL_CLEAR);
            }
        }

<<<<<<< HEAD
>>>>>>> d97af3b... add prima wlan driver
=======
        pMlmReassocInd->reassocType  = (tSirAssocType)pAssocReq->propIEinfo.assocType;
        pMlmReassocInd->load.numStas = pMac->lim.gLimNumOfCurrentSTAs;
        pMlmReassocInd->load.channelUtilization = (pMac->lim.gpLimMeasData) ?
                                                  pMac->lim.gpLimMeasData->avgChannelUtilization : 0;
        pMlmReassocInd->numBss = (tANI_U32) pAssocReq->propIEinfo.numBss;
        if (pAssocReq->propIEinfo.numBss)
        {
            palCopyMemory( pMac->hHdd, 
                           (tANI_U8 *) pMlmReassocInd->neighborList,
                           (tANI_U8 *) pAssocReq->propIEinfo.pBssList,
                           (sizeof(tSirNeighborBssInfo) * pAssocReq->propIEinfo.numBss));
        }
#endif
>>>>>>> 657b0e9... prima update
        if (pAssocReq->propIEinfo.aniIndicator)
            pStaDs->aniPeer = 1;

        pMlmReassocInd->capabilityInfo = pAssocReq->capabilityInfo;
        pMlmReassocInd->rsnIE.length = 0;

<<<<<<< HEAD
<<<<<<< HEAD
#ifdef WLAN_SOFTAP_FEATURE
=======
>>>>>>> d97af3b... add prima wlan driver
=======
#ifdef WLAN_SOFTAP_FEATURE
>>>>>>> 657b0e9... prima update
        if (pAssocReq->addIEPresent && pAssocReq->addIE.length )
            wpsIe = limGetWscIEPtr(pMac, pAssocReq->addIE.addIEdata, pAssocReq->addIE.length);

        if (pAssocReq->rsnPresent && (NULL == wpsIe))
<<<<<<< HEAD
<<<<<<< HEAD
#else
        if (pAssocReq->rsnPresent)
#endif
        {
            limLog(pMac, LOG2, FL("Assoc Req: RSN IE length = %d\n"), pAssocReq->rsn.length);
            pMlmReassocInd->rsnIE.length = 2 + pAssocReq->rsn.length;
            pMlmReassocInd->rsnIE.rsnIEdata[0] = SIR_MAC_RSN_EID;
            pMlmReassocInd->rsnIE.rsnIEdata[1] = pAssocReq->rsn.length;
            palCopyMemory( pMac->hHdd, &pMlmReassocInd->rsnIE.rsnIEdata[2], pAssocReq->rsn.info, pAssocReq->rsn.length);
=======
=======
#else
        if (pAssocReq->rsnPresent)
#endif
>>>>>>> 657b0e9... prima update
        {
            limLog(pMac, LOG2, FL("Assoc Req: RSN IE length = %d\n"), pAssocReq->rsn.length);
            pMlmReassocInd->rsnIE.length = 2 + pAssocReq->rsn.length;
            pMlmReassocInd->rsnIE.rsnIEdata[0] = SIR_MAC_RSN_EID;
            pMlmReassocInd->rsnIE.rsnIEdata[1] = pAssocReq->rsn.length;
<<<<<<< HEAD
            vos_mem_copy(&pMlmReassocInd->rsnIE.rsnIEdata[2],
                          pAssocReq->rsn.info, pAssocReq->rsn.length);
>>>>>>> d97af3b... add prima wlan driver
=======
            palCopyMemory( pMac->hHdd, &pMlmReassocInd->rsnIE.rsnIEdata[2], pAssocReq->rsn.info, pAssocReq->rsn.length);
>>>>>>> 657b0e9... prima update
        }

        // 802.11h support
        if (pAssocReq->powerCapabilityPresent && pAssocReq->supportedChannelsPresent)
        {
            pMlmReassocInd->spectrumMgtIndicator = eSIR_TRUE;
            pMlmReassocInd->powerCap.minTxPower = pAssocReq->powerCapability.minTxPower;
            pMlmReassocInd->powerCap.maxTxPower = pAssocReq->powerCapability.maxTxPower;
            pMlmReassocInd->supportedChannels.numChnl = (tANI_U8)(pAssocReq->supportedChannels.length / 2);

            limLog(pMac, LOG1,
<<<<<<< HEAD
<<<<<<< HEAD
                FL("Sending Reassoc Ind: spectrum ON, minPwr %d, maxPwr %d, numChnl %d\n"),
=======
                FL("Sending Reassoc Ind: spectrum ON, minPwr %d, maxPwr %d, numChnl %d"),
>>>>>>> d97af3b... add prima wlan driver
=======
                FL("Sending Reassoc Ind: spectrum ON, minPwr %d, maxPwr %d, numChnl %d\n"),
>>>>>>> 657b0e9... prima update
                pMlmReassocInd->powerCap.minTxPower,
                pMlmReassocInd->powerCap.maxTxPower,
                pMlmReassocInd->supportedChannels.numChnl);

            for(i=0; i < pMlmReassocInd->supportedChannels.numChnl; i++)
            {
                pMlmReassocInd->supportedChannels.channelList[i] = pAssocReq->supportedChannels.supportedChannels[j];
<<<<<<< HEAD
<<<<<<< HEAD
                limLog(pMac, LOG1, FL("Sending ReassocInd: chn[%d] = %d \n"),
=======
                limLog(pMac, LOG1, FL("Sending ReassocInd: chn[%d] = %d "),
>>>>>>> d97af3b... add prima wlan driver
=======
                limLog(pMac, LOG1, FL("Sending ReassocInd: chn[%d] = %d \n"),
>>>>>>> 657b0e9... prima update
                       i, pMlmReassocInd->supportedChannels.channelList[i]);
                j+=2;
            }
        }
        else
            pMlmReassocInd->spectrumMgtIndicator = eSIR_FALSE;


<<<<<<< HEAD
<<<<<<< HEAD
#ifdef WLAN_SOFTAP_FEATURE
        /* This check is to avoid extra Sec IEs present incase of WPS */
        if (pAssocReq->wpaPresent && (NULL == wpsIe))
#else
        if (pAssocReq->wpaPresent)
#endif
        {
            limLog(pMac, LOG2, FL("Received WPA IE length in Assoc Req is %d\n"), pAssocReq->wpa.length);
            pMlmReassocInd->rsnIE.rsnIEdata[pMlmReassocInd->rsnIE.length] = SIR_MAC_WPA_EID;
            pMlmReassocInd->rsnIE.rsnIEdata[pMlmReassocInd->rsnIE.length + 1] = pAssocReq->wpa.length;
            palCopyMemory( pMac->hHdd,
                           &pMlmReassocInd->rsnIE.rsnIEdata[pMlmReassocInd->rsnIE.length + 2],
                           pAssocReq->wpa.info,
                           pAssocReq->wpa.length);
=======
=======
#ifdef WLAN_SOFTAP_FEATURE
>>>>>>> 657b0e9... prima update
        /* This check is to avoid extra Sec IEs present incase of WPS */
        if (pAssocReq->wpaPresent && (NULL == wpsIe))
#else
        if (pAssocReq->wpaPresent)
#endif
        {
            limLog(pMac, LOG2, FL("Received WPA IE length in Assoc Req is %d\n"), pAssocReq->wpa.length);
            pMlmReassocInd->rsnIE.rsnIEdata[pMlmReassocInd->rsnIE.length] = SIR_MAC_WPA_EID;
            pMlmReassocInd->rsnIE.rsnIEdata[pMlmReassocInd->rsnIE.length + 1] = pAssocReq->wpa.length;
<<<<<<< HEAD
            vos_mem_copy(&pMlmReassocInd->rsnIE.rsnIEdata[pMlmReassocInd->rsnIE.length + 2],
                          pAssocReq->wpa.info,
                          pAssocReq->wpa.length);
>>>>>>> d97af3b... add prima wlan driver
=======
            palCopyMemory( pMac->hHdd,
                           &pMlmReassocInd->rsnIE.rsnIEdata[pMlmReassocInd->rsnIE.length + 2],
                           pAssocReq->wpa.info,
                           pAssocReq->wpa.length);
>>>>>>> 657b0e9... prima update
            pMlmReassocInd->rsnIE.length += 2 + pAssocReq->wpa.length;
        }

       pMlmReassocInd->addIE.length = 0;
       if (pAssocReq->addIEPresent)
       {
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
            palCopyMemory( pMac->hHdd,
                           &pMlmReassocInd->addIE.addIEdata,
                           pAssocReq->addIE.addIEdata,
                           pAssocReq->addIE.length);
<<<<<<< HEAD
=======
            vos_mem_copy(&pMlmReassocInd->addIE.addIEdata,
                         pAssocReq->addIE.addIEdata,
                         pAssocReq->addIE.length);
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update

            pMlmReassocInd->addIE.length = pAssocReq->addIE.length;
       }

<<<<<<< HEAD
<<<<<<< HEAD
#ifdef WLAN_SOFTAP_FEATURE
=======
>>>>>>> d97af3b... add prima wlan driver
=======
#ifdef WLAN_SOFTAP_FEATURE
>>>>>>> 657b0e9... prima update
        if(pAssocReq->wmeInfoPresent)
        {

            if (wlan_cfgGetInt(pMac, (tANI_U16) WNI_CFG_WME_ENABLED, &tmp) != eSIR_SUCCESS)
<<<<<<< HEAD
<<<<<<< HEAD
                 limLog(pMac, LOGP, FL("wlan_cfgGetInt failed for id %d\n"), WNI_CFG_WME_ENABLED );
=======
                 limLog(pMac, LOGP, FL("wlan_cfgGetInt failed for id %d"), WNI_CFG_WME_ENABLED );
>>>>>>> d97af3b... add prima wlan driver
=======
                 limLog(pMac, LOGP, FL("wlan_cfgGetInt failed for id %d\n"), WNI_CFG_WME_ENABLED );
>>>>>>> 657b0e9... prima update

            /* check whether AP is enabled with WMM */
            if(tmp)
            {
                pMlmReassocInd->WmmStaInfoPresent = 1;
            }
            else
            {
                pMlmReassocInd->WmmStaInfoPresent = 0;
            }
            /* Note: we are not rejecting Re-association here because IOT will fail */

        }
<<<<<<< HEAD
<<<<<<< HEAD
#endif
=======
>>>>>>> d97af3b... add prima wlan driver
=======
#endif
>>>>>>> 657b0e9... prima update

        // Required for indicating the frames to upper layer
        pMlmReassocInd->assocReqLength = pAssocReq->assocReqFrameLength;
        pMlmReassocInd->assocReqPtr = pAssocReq->assocReqFrame;

        pMlmReassocInd->beaconPtr = psessionEntry->beacon;
        pMlmReassocInd->beaconLength = psessionEntry->bcnLen;

        limPostSmeMessage(pMac, LIM_MLM_REASSOC_IND, (tANI_U32 *) pMlmReassocInd);
<<<<<<< HEAD
<<<<<<< HEAD
        palFreeMemory( pMac->hHdd, pMlmReassocInd);
=======
        vos_mem_free(pMlmReassocInd);
>>>>>>> d97af3b... add prima wlan driver
=======
        palFreeMemory( pMac->hHdd, pMlmReassocInd);
>>>>>>> 657b0e9... prima update
    }

    return;

} /*** end limSendMlmAssocInd() ***/
