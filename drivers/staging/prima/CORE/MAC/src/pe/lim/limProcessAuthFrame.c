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
 * Airgo Networks, Inc proprietary. All rights reserved.
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
/*
 *
 * Airgo Networks, Inc proprietary. All rights reserved.
=======

/*
>>>>>>> d97af3b... add prima wlan driver
=======
/*
 *
 * Airgo Networks, Inc proprietary. All rights reserved.
>>>>>>> 657b0e9... prima update
 * This file limProcessAuthFrame.cc contains the code
 * for processing received Authentication Frame.
 * Author:        Chandra Modumudi
 * Date:          03/11/02
 * History:-
 * Date           Modified by    Modification Information
 * --------------------------------------------------------------------
 * 05/12/2010     js             To support Shared key authentication at AP side
 *
 */

#include "wniApi.h"
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
#ifdef FEATURE_WLAN_NON_INTEGRATED_SOC
#include "halDataStruct.h"
#endif
#if (WNI_POLARIS_FW_PRODUCT == AP)
#include "wniCfgAp.h"
#else
#include "wniCfgSta.h"
#endif
<<<<<<< HEAD
=======
#include "wniCfgSta.h"
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
#include "aniGlobal.h"
#include "cfgApi.h"

#include "utilsApi.h"
#include "limUtils.h"
#include "limAssocUtils.h"
#include "limSecurityUtils.h"
#include "limSerDesUtils.h"
#ifdef WLAN_FEATURE_VOWIFI_11R
#include "limFT.h"
#endif
#include "vos_utils.h"


/**
 * isAuthValid
 *
 *FUNCTION:
 * This function is called by limProcessAuthFrame() upon Authentication
 * frame reception.
 *
 *LOGIC:
 * This function is used to test validity of auth frame:
 * - AUTH1 and AUTH3 must be received in AP mode
 * - AUTH2 and AUTH4 must be received in STA mode
 * - AUTH3 and AUTH4 must have challenge text IE, that is,'type' field has been set to
 *                 SIR_MAC_CHALLENGE_TEXT_EID by parser
 * -
 *
 *ASSUMPTIONS:
 *
 *NOTE:
 *
 * @param  *auth - Pointer to extracted auth frame body
 *
 * @return 0 or 1 (Valid)
 */


static inline unsigned int isAuthValid(tpAniSirGlobal pMac, tpSirMacAuthFrameBody auth,tpPESession sessionEntry) {
    unsigned int valid;
    valid=1;

    if (  ((auth->authTransactionSeqNumber==SIR_MAC_AUTH_FRAME_1)||
           (auth->authTransactionSeqNumber==SIR_MAC_AUTH_FRAME_3)) &&
          ((sessionEntry->limSystemRole == eLIM_STA_ROLE)||(sessionEntry->limSystemRole == eLIM_BT_AMP_STA_ROLE)))
        valid=0;

    if ( ((auth->authTransactionSeqNumber==SIR_MAC_AUTH_FRAME_2)||(auth->authTransactionSeqNumber==SIR_MAC_AUTH_FRAME_4))&&
         ((sessionEntry->limSystemRole == eLIM_AP_ROLE)||(sessionEntry->limSystemRole == eLIM_BT_AMP_AP_ROLE)))
        valid=0;

    if ( ((auth->authTransactionSeqNumber==SIR_MAC_AUTH_FRAME_3)||(auth->authTransactionSeqNumber==SIR_MAC_AUTH_FRAME_4))&&
         (auth->type!=SIR_MAC_CHALLENGE_TEXT_EID)&&(auth->authAlgoNumber != eSIR_SHARED_KEY))
        valid=0;

    return valid;
}


/**
 * limProcessAuthFrame
 *
 *FUNCTION:
 * This function is called by limProcessMessageQueue() upon Authentication
 * frame reception.
 *
 *LOGIC:
 * This function processes received Authentication frame and responds
 * with either next Authentication frame in sequence to peer MAC entity
 * or LIM_MLM_AUTH_IND on AP or LIM_MLM_AUTH_CNF on STA.
 *
 *ASSUMPTIONS:
 *
 *NOTE:
 * 1. Authentication failures are reported to SME with same status code
 *    received from the peer MAC entity.
 * 2. Authentication frame2/4 received with alogirthm number other than
 *    one requested in frame1/3 are logged with an error and auth confirm
 *    will be sent to SME only after auth failure timeout.
 * 3. Inconsistency in the spec:
 *    On receiving Auth frame2, specs says that if WEP key mapping key
 *    or default key is NULL, Auth frame3 with a status code 15 (challenge
 *    failure to be returned to peer entity. However, section 7.2.3.10,
 *    table 14 says that status code field is 'reserved' for frame3 !
 *    In the current implementation, Auth frame3 is returned with status
 *    code 15 overriding section 7.2.3.10.
 * 4. If number pre-authentications reach configrable max limit,
 *    Authentication frame with 'unspecified failure' status code is
 *    returned to requesting entity.
 *
 * @param  pMac - Pointer to Global MAC structure
 * @param  *pRxPacketInfo - A pointer to Rx packet info structure
 * @return None
 */

void
limProcessAuthFrame(tpAniSirGlobal pMac, tANI_U8 *pRxPacketInfo, tpPESession psessionEntry)
{
    tANI_U8                 *pBody, keyId, cfgPrivacyOptImp,
                            defaultKey[SIR_MAC_KEY_LENGTH],
                            encrAuthFrame[LIM_ENCR_AUTH_BODY_LEN],
                            plainBody[256];
    tANI_U16                frameLen;
    //tANI_U32                authRspTimeout, maxNumPreAuth, val;
    tANI_U32                maxNumPreAuth, val;
    tSirMacAuthFrameBody    *pRxAuthFrameBody, rxAuthFrame, authFrame;
    tpSirMacMgmtHdr         pHdr;
    tCfgWepKeyEntry         *pKeyMapEntry = NULL;
    struct tLimPreAuthNode  *pAuthNode;
    tLimMlmAuthInd          mlmAuthInd;
    tANI_U8                 decryptResult;
    tANI_U8                 *pChallenge;
    tANI_U32                key_length=8;
    tANI_U8                 challengeTextArray[SIR_MAC_AUTH_CHALLENGE_LENGTH];
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
#ifdef WLAN_SOFTAP_FEATURE
    tpDphHashNode           pStaDs = NULL;
    tANI_U16                assocId = 0;
#endif
<<<<<<< HEAD
=======
    tpDphHashNode           pStaDs = NULL;
    tANI_U16                assocId = 0;
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
    /* Added For BT -AMP support */
    // Get pointer to Authentication frame header and body
 

    pHdr = WDA_GET_RX_MAC_HEADER(pRxPacketInfo);
    frameLen = WDA_GET_RX_PAYLOAD_LEN(pRxPacketInfo);
    

    if (!frameLen)
    {
        // Log error
        limLog(pMac, LOGE,
               FL("received Authentication frame with no body from "));
        limPrintMacAddr(pMac, pHdr->sa, LOGE);

        return;
    }

    if (limIsGroupAddr(pHdr->sa))
    {
        // Received Auth frame from a BC/MC address
        // Log error and ignore it
        PELOG1(limLog(pMac, LOG1,
               FL("received Auth frame from a BC/MC address - "));)
       PELOG1( limPrintMacAddr(pMac, pHdr->sa, LOG1);)

        return;
    }

<<<<<<< HEAD
<<<<<<< HEAD
=======
    VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_DEBUG,
              FL("Auth Frame Received: BSSID " MAC_ADDRESS_STR " (RSSI %d)"),
              MAC_ADDR_ARRAY(pHdr->bssId),
              (uint)abs((tANI_S8)WDA_GET_RX_RSSI_DB(pRxPacketInfo)));

>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
    pBody = WDA_GET_RX_MPDU_DATA(pRxPacketInfo);

    //PELOG3(sirDumpBuf(pMac, SIR_LIM_MODULE_ID, LOG3, (tANI_U8*)pBd, ((tpHalBufDesc) pBd)->mpduDataOffset + frameLen);)

<<<<<<< HEAD
<<<<<<< HEAD

=======
    //Restore default failure timeout
    if (VOS_P2P_CLIENT_MODE == psessionEntry->pePersona && psessionEntry->defaultAuthFailureTimeout)
    {
        ccmCfgSetInt(pMac,WNI_CFG_AUTHENTICATE_FAILURE_TIMEOUT ,
                          psessionEntry->defaultAuthFailureTimeout, NULL, eANI_BOOLEAN_FALSE);
    }
>>>>>>> d97af3b... add prima wlan driver
=======

>>>>>>> 657b0e9... prima update
   
    /// Determine if WEP bit is set in the FC or received MAC header
    if (pHdr->fc.wep)
    {
        /**
         * WEP bit is set in FC of MAC header.
         */

<<<<<<< HEAD
<<<<<<< HEAD
#ifdef WLAN_SOFTAP_FEATURE
=======
>>>>>>> d97af3b... add prima wlan driver
=======
#ifdef WLAN_SOFTAP_FEATURE
>>>>>>> 657b0e9... prima update
        // If TKIP counter measures enabled issue Deauth frame to station
        if ((psessionEntry->bTkipCntrMeasActive) && (psessionEntry->limSystemRole == eLIM_AP_ROLE))
        {
            PELOGE( limLog(pMac, LOGE,
               FL("Tkip counter measures Enabled, sending Deauth frame to")); )
            limPrintMacAddr(pMac, pHdr->sa, LOGE);

            limSendDeauthMgmtFrame( pMac, eSIR_MAC_MIC_FAILURE_REASON,
<<<<<<< HEAD
<<<<<<< HEAD
                                    pHdr->sa, psessionEntry );
            return;
        }
#endif
=======
                                    pHdr->sa, psessionEntry, FALSE );
            return;
        }
>>>>>>> d97af3b... add prima wlan driver
=======
                                    pHdr->sa, psessionEntry );
            return;
        }
#endif
>>>>>>> 657b0e9... prima update

        // Extract key ID from IV (most 2 bits of 4th byte of IV)

        keyId = (*(pBody + 3)) >> 6;

        /**
         * On STA in infrastructure BSS, Authentication frames received
         * with WEP bit set in the FC must be rejected with challenge
         * failure status code (wierd thing in the spec - this should have
         * been rejected with unspecified failure or unexpected assertion
         * of wep bit (this status code does not exist though) or
         * Out-of-sequence-Authentication-Frame status code.
         */

        if (psessionEntry->limSystemRole == eLIM_STA_ROLE || psessionEntry->limSystemRole == eLIM_BT_AMP_STA_ROLE)
        {
            authFrame.authAlgoNumber = eSIR_SHARED_KEY;
            authFrame.authTransactionSeqNumber = SIR_MAC_AUTH_FRAME_4;
            authFrame.authStatusCode = eSIR_MAC_CHALLENGE_FAILURE_STATUS;

            limSendAuthMgmtFrame(pMac, &authFrame,
                                 pHdr->sa,
                                 LIM_NO_WEP_IN_FC,psessionEntry);
            // Log error
            PELOGE(limLog(pMac, LOGE,
                   FL("received Authentication frame with wep bit set on role=%d "MAC_ADDRESS_STR),
                   psessionEntry->limSystemRole, MAC_ADDR_ARRAY(pHdr->sa) );)

            return;
        }

        if (frameLen < LIM_ENCR_AUTH_BODY_LEN)
        {
            // Log error
            limLog(pMac, LOGE,
                   FL("Not enough size [%d] to decrypt received Auth frame"),
                   frameLen);
            limPrintMacAddr(pMac, pHdr->sa, LOGE);

            return;
        }
<<<<<<< HEAD
<<<<<<< HEAD
#ifdef WLAN_SOFTAP_FEATURE
=======
>>>>>>> d97af3b... add prima wlan driver
=======
#ifdef WLAN_SOFTAP_FEATURE
>>>>>>> 657b0e9... prima update
        if(psessionEntry->limSystemRole == eLIM_AP_ROLE)
        {
            val = psessionEntry->privacy; 
        } 
        else 
<<<<<<< HEAD
<<<<<<< HEAD
#endif
=======
>>>>>>> d97af3b... add prima wlan driver
=======
#endif
>>>>>>> 657b0e9... prima update
        // Accept Authentication frame only if Privacy is implemented
        if (wlan_cfgGetInt(pMac, WNI_CFG_PRIVACY_ENABLED,
                      &val) != eSIR_SUCCESS)
        {
            /**
             * Could not get Privacy option
             * from CFG. Log error.
             */
<<<<<<< HEAD
<<<<<<< HEAD
            limLog(pMac, LOGP, FL("could not retrieve Privacy option\n"));
=======
            limLog(pMac, LOGP, FL("could not retrieve Privacy option"));
>>>>>>> d97af3b... add prima wlan driver
=======
            limLog(pMac, LOGP, FL("could not retrieve Privacy option\n"));
>>>>>>> 657b0e9... prima update
        }

        cfgPrivacyOptImp = (tANI_U8)val;
        if (cfgPrivacyOptImp)
        {
            /**
             * Privacy option is implemented.
             * Check if the received frame is Authentication
             * frame3 and there is a context for requesting STA.
             * If not, reject with unspecified failure status code
             */
            pAuthNode = limSearchPreAuthList(pMac, pHdr->sa);

            if (pAuthNode == NULL)
            {
                /**
                 * No 'pre-auth' context exists for this STA that sent
                 * an Authentication frame with FC bit set.
                 * Send Auth frame4 with 'out of sequence' status code.
                 */
                authFrame.authAlgoNumber = eSIR_SHARED_KEY;
                authFrame.authTransactionSeqNumber =
                SIR_MAC_AUTH_FRAME_4;
                authFrame.authStatusCode =
                eSIR_MAC_AUTH_FRAME_OUT_OF_SEQ_STATUS;

                limSendAuthMgmtFrame(pMac, &authFrame,
                                     pHdr->sa,
                                     LIM_NO_WEP_IN_FC,psessionEntry);

                // Log error
                PELOGE(limLog(pMac, LOGE,
                       FL("received Authentication frame from peer that has "
                       "no preauth context with WEP bit set "MAC_ADDRESS_STR),
                       MAC_ADDR_ARRAY(pHdr->sa));)

                return;
            }
            else
            {
                /// Change the auth-response timeout
                limDeactivateAndChangePerStaIdTimer(pMac,
                                                    eLIM_AUTH_RSP_TIMER,
                                                    pAuthNode->authNodeIdx);

                /// 'Pre-auth' status exists for STA
                if ((pAuthNode->mlmState !=
                     eLIM_MLM_WT_AUTH_FRAME3_STATE) &&
                    (pAuthNode->mlmState !=
                     eLIM_MLM_AUTH_RSP_TIMEOUT_STATE))
                {
                    /**
                     * Should not have received Authentication frame
                     * with WEP bit set in FC in other states.
                     * Reject by sending Authenticaton frame with
                     * out of sequence Auth frame status code.
                     */

                    authFrame.authAlgoNumber = eSIR_SHARED_KEY;
                    authFrame.authTransactionSeqNumber =
                    SIR_MAC_AUTH_FRAME_4;
                    authFrame.authStatusCode =
                    eSIR_MAC_AUTH_FRAME_OUT_OF_SEQ_STATUS;

                    limSendAuthMgmtFrame(pMac, &authFrame,
                                         pHdr->sa,
                                         LIM_NO_WEP_IN_FC,psessionEntry);

                    // Log error
                    PELOGE(limLog(pMac, LOGE,
                           FL("received Authentication frame from peer that is in state %d "
                           MAC_ADDRESS_STR), pAuthNode->mlmState, MAC_ADDR_ARRAY(pHdr->sa));)

                    return;
                }
            }

            /**
             * Check if there exists a key mappping key
             * for the STA that sent Authentication frame
             */
            pKeyMapEntry = limLookUpKeyMappings(pHdr->sa);

            if (pKeyMapEntry)
            {
                if (!pKeyMapEntry->wepOn)
                {
                    /**
                     * Key Mapping entry has null key.
                     * Send Authentication frame
                     * with challenge failure status code
                     */
                    authFrame.authAlgoNumber = eSIR_SHARED_KEY;
                    authFrame.authTransactionSeqNumber =
                    SIR_MAC_AUTH_FRAME_4;
                    authFrame.authStatusCode =
                    eSIR_MAC_CHALLENGE_FAILURE_STATUS;

                    limSendAuthMgmtFrame(pMac, &authFrame,
                                         pHdr->sa,
                                         LIM_NO_WEP_IN_FC,psessionEntry);

                    // Log error
                    PELOGE(limLog(pMac, LOGE,
                           FL("received Auth frame3 from peer that has NULL key map entry "
                           MAC_ADDRESS_STR),MAC_ADDR_ARRAY(pHdr->sa));)

                    return;
                } // if (!pKeyMapEntry->wepOn)
                else
                {
                    decryptResult = limDecryptAuthFrame(pMac, pKeyMapEntry->key,
                                                        pBody,
                                                        plainBody,
                                                        key_length,
                                                        (tANI_U16) (frameLen-SIR_MAC_WEP_IV_LENGTH));
                    if (decryptResult == LIM_DECRYPT_ICV_FAIL)
                    {
                        /// ICV failure
                        PELOGW(limLog(pMac, LOGW, FL("=====> decryptResult == LIM_DECRYPT_ICV_FAIL ..."));)
                        limDeletePreAuthNode(pMac,
                                             pHdr->sa);
                        authFrame.authAlgoNumber = eSIR_SHARED_KEY;
                        authFrame.authTransactionSeqNumber =
                        SIR_MAC_AUTH_FRAME_4;
                        authFrame.authStatusCode =
                        eSIR_MAC_CHALLENGE_FAILURE_STATUS;

                        limSendAuthMgmtFrame(
                                            pMac, &authFrame,
                                            pHdr->sa,
                                            LIM_NO_WEP_IN_FC,psessionEntry);

                        // Log error
                        PELOGE(limLog(pMac, LOGE,
                               FL("received Authentication frame from peer that failed decryption, Addr "
                               MAC_ADDRESS_STR), MAC_ADDR_ARRAY(pHdr->sa));)

                        return;
                    }

                    if ((sirConvertAuthFrame2Struct(pMac, plainBody, frameLen-8, &rxAuthFrame)!=eSIR_SUCCESS)||(!isAuthValid(pMac, &rxAuthFrame,psessionEntry)))
                        return;


                } // end if (pKeyMapEntry->key == NULL)
            } // if keyMappings has entry
            else
            {

                val = SIR_MAC_KEY_LENGTH;

<<<<<<< HEAD
<<<<<<< HEAD
#ifdef WLAN_SOFTAP_FEATURE  
=======
>>>>>>> d97af3b... add prima wlan driver
=======
#ifdef WLAN_SOFTAP_FEATURE  
>>>>>>> 657b0e9... prima update
                if(psessionEntry->limSystemRole == eLIM_AP_ROLE)
                {   
                    tpSirKeys pKey;
                    pKey =  &psessionEntry->WEPKeyMaterial[keyId].key[0];              
<<<<<<< HEAD
<<<<<<< HEAD
                    palCopyMemory( pMac->hHdd, defaultKey, pKey->key, pKey->keyLength);
                    val = pKey->keyLength;
                }                   
                else                              
#endif                                    
=======
                    vos_mem_copy(defaultKey, pKey->key, pKey->keyLength);
                    val = pKey->keyLength;
                }                   
                else                              
>>>>>>> d97af3b... add prima wlan driver
=======
                    palCopyMemory( pMac->hHdd, defaultKey, pKey->key, pKey->keyLength);
                    val = pKey->keyLength;
                }                   
                else                              
#endif                                    
>>>>>>> 657b0e9... prima update
                if (wlan_cfgGetStr(pMac, (tANI_U16) (WNI_CFG_WEP_DEFAULT_KEY_1 + keyId),
                              defaultKey, &val) != eSIR_SUCCESS)
                {
                    /// Could not get Default key from CFG.
                    //Log error.
                    limLog(pMac, LOGP,
<<<<<<< HEAD
<<<<<<< HEAD
                           FL("could not retrieve Default key\n"));
=======
                           FL("could not retrieve Default key"));
>>>>>>> d97af3b... add prima wlan driver
=======
                           FL("could not retrieve Default key\n"));
>>>>>>> 657b0e9... prima update

                    /**
                     * Send Authentication frame
                     * with challenge failure status code
                     */

                    authFrame.authAlgoNumber = eSIR_SHARED_KEY;
                    authFrame.authTransactionSeqNumber =
                    SIR_MAC_AUTH_FRAME_4;
                    authFrame.authStatusCode =
                    eSIR_MAC_CHALLENGE_FAILURE_STATUS;

                    limSendAuthMgmtFrame(pMac, &authFrame,
                                         pHdr->sa,
                                         LIM_NO_WEP_IN_FC,psessionEntry);

                    return;
                }

                    key_length=val;

                    decryptResult = limDecryptAuthFrame(pMac, defaultKey,
                                                        pBody,
                                                        plainBody,
                                                        key_length,
                                                        (tANI_U16) (frameLen-SIR_MAC_WEP_IV_LENGTH));
                    if (decryptResult == LIM_DECRYPT_ICV_FAIL)
                    {
<<<<<<< HEAD
<<<<<<< HEAD
                        PELOGW(limLog(pMac, LOGW, FL("=====> decryptResult == LIM_DECRYPT_ICV_FAIL ...\n"));)
=======
                        PELOGW(limLog(pMac, LOGW, FL("=====> decryptResult == LIM_DECRYPT_ICV_FAIL ..."));)
>>>>>>> d97af3b... add prima wlan driver
=======
                        PELOGW(limLog(pMac, LOGW, FL("=====> decryptResult == LIM_DECRYPT_ICV_FAIL ...\n"));)
>>>>>>> 657b0e9... prima update
                        /// ICV failure
                        limDeletePreAuthNode(pMac,
                                             pHdr->sa);
                        authFrame.authAlgoNumber = eSIR_SHARED_KEY;
                        authFrame.authTransactionSeqNumber =
                        SIR_MAC_AUTH_FRAME_4;
                        authFrame.authStatusCode =
                        eSIR_MAC_CHALLENGE_FAILURE_STATUS;

                        limSendAuthMgmtFrame(
                                            pMac, &authFrame,
                                            pHdr->sa,
                                            LIM_NO_WEP_IN_FC,psessionEntry);

                        // Log error
                        PELOGE(limLog(pMac, LOGE,
                               FL("received Authentication frame from peer that failed decryption: "
                               MAC_ADDRESS_STR), MAC_ADDR_ARRAY(pHdr->sa));)

                        return;
                    }
                    if ((sirConvertAuthFrame2Struct(pMac, plainBody, frameLen-8, &rxAuthFrame)!=eSIR_SUCCESS)||(!isAuthValid(pMac, &rxAuthFrame,psessionEntry)))
                        return;

            } // End of check for Key Mapping/Default key presence
        }
        else
        {
            /**
             * Privacy option is not implemented.
             * So reject Authentication frame received with
             * WEP bit set by sending Authentication frame
             * with 'challenge failure' status code. This is
             * another strange thing in the spec. Status code
             * should have been 'unsupported algorithm' status code.
             */

            authFrame.authAlgoNumber = eSIR_SHARED_KEY;
            authFrame.authTransactionSeqNumber =
            SIR_MAC_AUTH_FRAME_4;
            authFrame.authStatusCode =
            eSIR_MAC_CHALLENGE_FAILURE_STATUS;

            limSendAuthMgmtFrame(pMac, &authFrame,
                                 pHdr->sa,
                                 LIM_NO_WEP_IN_FC,psessionEntry);

            // Log error
            PELOGE(limLog(pMac, LOGE,
                   FL("received Authentication frame3 from peer that while privacy option is turned OFF "
                   MAC_ADDRESS_STR), MAC_ADDR_ARRAY(pHdr->sa));)

            return;
        } // else if (wlan_cfgGetInt(CFG_PRIVACY_OPTION_IMPLEMENTED))
    } // if (fc.wep)
    else
    {


        if ((sirConvertAuthFrame2Struct(pMac, pBody, frameLen, &rxAuthFrame)!=eSIR_SUCCESS)||(!isAuthValid(pMac, &rxAuthFrame,psessionEntry)))
            return;
    }


    pRxAuthFrameBody = &rxAuthFrame;

   PELOGW(limLog(pMac, LOGW,
<<<<<<< HEAD
<<<<<<< HEAD
           FL("Received Auth frame with type=%d seqnum=%d, status=%d (%d)\n"),
=======
           FL("Received Auth frame with type=%d seqnum=%d, status=%d (%d)"),
>>>>>>> d97af3b... add prima wlan driver
=======
           FL("Received Auth frame with type=%d seqnum=%d, status=%d (%d)\n"),
>>>>>>> 657b0e9... prima update
           (tANI_U32) pRxAuthFrameBody->authAlgoNumber,
           (tANI_U32) pRxAuthFrameBody->authTransactionSeqNumber,
           (tANI_U32) pRxAuthFrameBody->authStatusCode,(tANI_U32)pMac->lim.gLimNumPreAuthContexts);)

    switch (pRxAuthFrameBody->authTransactionSeqNumber)
    {
        case SIR_MAC_AUTH_FRAME_1:
            // AuthFrame 1
<<<<<<< HEAD
<<<<<<< HEAD
=======
            
            pStaDs = dphLookupHashEntry(pMac, pHdr->sa,
                    &assocId, &psessionEntry->dph.dphHashTable);
            if (pStaDs)
            {
                tLimMlmDisassocReq       *pMlmDisassocReq = NULL;
                tLimMlmDeauthReq        *pMlmDeauthReq = NULL;
                pMlmDisassocReq = pMac->lim.limDisassocDeauthCnfReq.pMlmDisassocReq;
                if (pMlmDisassocReq &&
                        (vos_mem_compare((tANI_U8 *) pHdr->sa,
                                         (tANI_U8 *) &pMlmDisassocReq->peerMacAddr,
                                          sizeof(tSirMacAddr))))
                {
                    PELOGE(limLog(pMac, LOGE, FL("\nTODO:Ack for disassoc "
                                "frame is pending Issue delsta for"
                                " %02x:%02x:%02x:%02x:%02x:%02x"),
                                pMlmDisassocReq->peerMacAddr[0],
                                pMlmDisassocReq->peerMacAddr[1],
                                pMlmDisassocReq->peerMacAddr[2],
                                pMlmDisassocReq->peerMacAddr[3],
                                pMlmDisassocReq->peerMacAddr[4],
                                pMlmDisassocReq->peerMacAddr[5]);)
                    limProcessDisassocAckTimeout(pMac);
                }
                pMlmDeauthReq = pMac->lim.limDisassocDeauthCnfReq.pMlmDeauthReq;
                if (pMlmDeauthReq &&
                        (vos_mem_compare((tANI_U8 *) pHdr->sa,
                                         (tANI_U8 *) &pMlmDeauthReq->peerMacAddr,
                                         sizeof(tSirMacAddr))))
                {
                    PELOGE(limLog(pMac, LOGE, FL("\nTODO:Ack for deauth frame "
                                "is pending Issue delsta for "
                                "%02x:%02x:%02x:%02x:%02x:%02x"),
                                pMlmDeauthReq->peerMacAddr[0],
                                pMlmDeauthReq->peerMacAddr[1],
                                pMlmDeauthReq->peerMacAddr[2],
                                pMlmDeauthReq->peerMacAddr[3],
                                pMlmDeauthReq->peerMacAddr[4],
                                pMlmDeauthReq->peerMacAddr[5]
                                );)
                    limProcessDeauthAckTimeout(pMac);
                }
            }
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update

            /// Check if there exists pre-auth context for this STA
            pAuthNode = limSearchPreAuthList(pMac, pHdr->sa);
            if (pAuthNode)
            {
                /// Pre-auth context exists for the STA
                if (pHdr->fc.retry == 0)
                {
                    /**
                     * STA is initiating brand-new Authentication
                     * sequence after local Auth Response timeout.
                     * Or STA retrying to transmit First Auth frame due to packet drop OTA
                     * Delete Pre-auth node and fall through.
                     */
                    if(pAuthNode->fTimerStarted)
                    {
                        limDeactivateAndChangePerStaIdTimer(pMac,
                                                    eLIM_AUTH_RSP_TIMER,
                                                    pAuthNode->authNodeIdx);
                    }
<<<<<<< HEAD
<<<<<<< HEAD
                    PELOGE(limLog(pMac, LOGE, FL("STA is initiating brand-new Authentication ...\n"));)
                    limDeletePreAuthNode(pMac,
                                         pHdr->sa);
#ifdef WLAN_SOFTAP_FEATURE                    
=======
                    PELOGE(limLog(pMac, LOGE, FL("STA is initiating brand-new Authentication ..."));)
                    limDeletePreAuthNode(pMac,
                                         pHdr->sa);
>>>>>>> d97af3b... add prima wlan driver
=======
                    PELOGE(limLog(pMac, LOGE, FL("STA is initiating brand-new Authentication ...\n"));)
                    limDeletePreAuthNode(pMac,
                                         pHdr->sa);
#ifdef WLAN_SOFTAP_FEATURE                    
>>>>>>> 657b0e9... prima update
                    /**
                     *  SAP Mode:Disassociate the station and 
                     *  delete its entry if we have its entry 
                     *  already and received "auth" from the 
                     *  same station.
                     */  

                    for (assocId = 0; assocId < psessionEntry->dph.dphHashTable.size; assocId++)// Softap dphHashTable.size = 8
                    {
                        pStaDs = dphGetHashEntry(pMac, assocId, &psessionEntry->dph.dphHashTable);

                        if (NULL == pStaDs)
                             continue;

                        if (pStaDs->valid)
                        {
<<<<<<< HEAD
<<<<<<< HEAD
                             if (palEqualMemory( pMac->hHdd,(tANI_U8 *) &pStaDs->staAddr,
=======
                             if (vos_mem_compare((tANI_U8 *) &pStaDs->staAddr,
>>>>>>> d97af3b... add prima wlan driver
=======
                             if (palEqualMemory( pMac->hHdd,(tANI_U8 *) &pStaDs->staAddr,
>>>>>>> 657b0e9... prima update
                                      (tANI_U8 *) &(pHdr->sa), (tANI_U8) (sizeof(tSirMacAddr))) )
                                  break;
                        }
                    }

                    if (NULL != pStaDs)
                    {
<<<<<<< HEAD
<<<<<<< HEAD
                        PELOGE(limLog(pMac, LOGE, FL("lim Delete Station Context (staId: %d, assocId: %d) \n"),pStaDs->staIndex, assocId);)
                        limSendDeauthMgmtFrame(pMac,
                               eSIR_MAC_UNSPEC_FAILURE_REASON, (tANI_U8 *) pAuthNode->peerMacAddr,psessionEntry);
                        limTriggerSTAdeletion(pMac, pStaDs, psessionEntry);
                        return;
                    }
#endif
=======
                        PELOGE(limLog(pMac, LOGE, FL("lim Delete Station Context (staId: %d, assocId: %d) "),pStaDs->staIndex, assocId);)
=======
                        PELOGE(limLog(pMac, LOGE, FL("lim Delete Station Context (staId: %d, assocId: %d) \n"),pStaDs->staIndex, assocId);)
>>>>>>> 657b0e9... prima update
                        limSendDeauthMgmtFrame(pMac,
                               eSIR_MAC_UNSPEC_FAILURE_REASON, (tANI_U8 *) pAuthNode->peerMacAddr,psessionEntry);
                        limTriggerSTAdeletion(pMac, pStaDs, psessionEntry);
                        return;
                    }
<<<<<<< HEAD
>>>>>>> d97af3b... add prima wlan driver
=======
#endif
>>>>>>> 657b0e9... prima update
                }
                else
                {
                    /* 
                     * This can happen when first authentication frame is received
                     * but ACK lost at STA side, in this case 2nd auth frame is already 
                     * in transmission queue
                     * */
<<<<<<< HEAD
<<<<<<< HEAD
                    PELOGE(limLog(pMac, LOGE, FL("STA is initiating Authentication after ACK lost...\n"));)
=======
                    PELOGE(limLog(pMac, LOGE, FL("STA is initiating Authentication after ACK lost..."));)
>>>>>>> d97af3b... add prima wlan driver
=======
                    PELOGE(limLog(pMac, LOGE, FL("STA is initiating Authentication after ACK lost...\n"));)
>>>>>>> 657b0e9... prima update
                    return;
                }
            }
            if (wlan_cfgGetInt(pMac, WNI_CFG_MAX_NUM_PRE_AUTH,
                          (tANI_U32 *) &maxNumPreAuth) != eSIR_SUCCESS)
            {
                /**
                 * Could not get MaxNumPreAuth
                 * from CFG. Log error.
                 */
                limLog(pMac, LOGP,
<<<<<<< HEAD
<<<<<<< HEAD
                       FL("could not retrieve MaxNumPreAuth\n"));
            }
#ifdef ANI_AP_SDK_OPT
            if(maxNumPreAuth > SIR_SDK_OPT_MAX_NUM_PRE_AUTH)
                maxNumPreAuth = SIR_SDK_OPT_MAX_NUM_PRE_AUTH;
#endif // ANI_AP_SDK_OPT
=======
                       FL("could not retrieve MaxNumPreAuth"));
            }
>>>>>>> d97af3b... add prima wlan driver
=======
                       FL("could not retrieve MaxNumPreAuth\n"));
            }
#ifdef ANI_AP_SDK_OPT
            if(maxNumPreAuth > SIR_SDK_OPT_MAX_NUM_PRE_AUTH)
                maxNumPreAuth = SIR_SDK_OPT_MAX_NUM_PRE_AUTH;
#endif // ANI_AP_SDK_OPT
>>>>>>> 657b0e9... prima update
            if (pMac->lim.gLimNumPreAuthContexts == maxNumPreAuth)
            {
                /**
                 * Maximum number of pre-auth contexts
                 * reached. Send Authentication frame
                 * with unspecified failure
                 */
                authFrame.authAlgoNumber =
                pRxAuthFrameBody->authAlgoNumber;
                authFrame.authTransactionSeqNumber =
                pRxAuthFrameBody->authTransactionSeqNumber + 1;
                authFrame.authStatusCode =
                eSIR_MAC_UNSPEC_FAILURE_STATUS;

                limSendAuthMgmtFrame(pMac, &authFrame,
                                     pHdr->sa,
                                     LIM_NO_WEP_IN_FC,psessionEntry);

                return;
            }
            /// No Pre-auth context exists for the STA.
<<<<<<< HEAD
<<<<<<< HEAD
#ifdef WLAN_SOFTAP_FEATURE
=======
>>>>>>> d97af3b... add prima wlan driver
=======
#ifdef WLAN_SOFTAP_FEATURE
>>>>>>> 657b0e9... prima update
            if (limIsAuthAlgoSupported(
                                      pMac,
                                      (tAniAuthType)
                                      pRxAuthFrameBody->authAlgoNumber, psessionEntry))
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
#else
            if (limIsAuthAlgoSupported(
                                      pMac,
                                      (tAniAuthType)
                                      pRxAuthFrameBody->authAlgoNumber))

#endif
<<<<<<< HEAD
=======
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
            {
                switch (pRxAuthFrameBody->authAlgoNumber)
                {
                    case eSIR_OPEN_SYSTEM:
<<<<<<< HEAD
<<<<<<< HEAD
                        PELOGW(limLog(pMac, LOGW, FL("=======> eSIR_OPEN_SYSTEM  ...\n"));)
=======
                        PELOGW(limLog(pMac, LOGW, FL("=======> eSIR_OPEN_SYSTEM  ..."));)
>>>>>>> d97af3b... add prima wlan driver
=======
                        PELOGW(limLog(pMac, LOGW, FL("=======> eSIR_OPEN_SYSTEM  ...\n"));)
>>>>>>> 657b0e9... prima update
                        /// Create entry for this STA in pre-auth list
                        pAuthNode = limAcquireFreePreAuthNode(pMac, &pMac->lim.gLimPreAuthTimerTable);
                        if (pAuthNode == NULL)
                        {
                            // Log error
                            limLog(pMac, LOGW,
                                   FL("Max pre-auth nodes reached "));
                            limPrintMacAddr(pMac, pHdr->sa, LOGW);

                            return;
                        }

<<<<<<< HEAD
<<<<<<< HEAD
                        PELOG1(limLog(pMac, LOG1, FL("Alloc new data: %x peer \n"), pAuthNode);
                        limPrintMacAddr(pMac, pHdr->sa, LOG1);)

                        palCopyMemory( pMac->hHdd,
                                     (tANI_U8 *) pAuthNode->peerMacAddr,
                                     pHdr->sa,
                                     sizeof(tSirMacAddr));
=======
                        PELOG1(limLog(pMac, LOG1, FL("Alloc new data: %x peer "), pAuthNode);
                        limPrintMacAddr(pMac, pHdr->sa, LOG1);)

                        vos_mem_copy((tANI_U8 *) pAuthNode->peerMacAddr,
                                      pHdr->sa,
                                      sizeof(tSirMacAddr));
>>>>>>> d97af3b... add prima wlan driver
=======
                        PELOG1(limLog(pMac, LOG1, FL("Alloc new data: %x peer \n"), pAuthNode);
                        limPrintMacAddr(pMac, pHdr->sa, LOG1);)

                        palCopyMemory( pMac->hHdd,
                                     (tANI_U8 *) pAuthNode->peerMacAddr,
                                     pHdr->sa,
                                     sizeof(tSirMacAddr));
>>>>>>> 657b0e9... prima update

                        pAuthNode->mlmState =
                        eLIM_MLM_AUTHENTICATED_STATE;
                        pAuthNode->authType = (tAniAuthType)
                                              pRxAuthFrameBody->authAlgoNumber;
                        pAuthNode->fSeen = 0;
                        pAuthNode->fTimerStarted = 0;
                        limAddPreAuthNode(pMac, pAuthNode);

                        /**
                         * Send Authenticaton frame with Success
                         * status code.
                         */

                        authFrame.authAlgoNumber =
                        pRxAuthFrameBody->authAlgoNumber;
                        authFrame.authTransactionSeqNumber =
                        pRxAuthFrameBody->authTransactionSeqNumber + 1;
                        authFrame.authStatusCode = eSIR_MAC_SUCCESS_STATUS;
                        limSendAuthMgmtFrame(
                                            pMac, &authFrame,
                                            pHdr->sa,
                                            LIM_NO_WEP_IN_FC,psessionEntry);

                        /// Send Auth indication to SME

<<<<<<< HEAD
<<<<<<< HEAD
                        palCopyMemory( pMac->hHdd,
                                     (tANI_U8 *) mlmAuthInd.peerMacAddr,
=======
                        vos_mem_copy((tANI_U8 *) mlmAuthInd.peerMacAddr,
>>>>>>> d97af3b... add prima wlan driver
=======
                        palCopyMemory( pMac->hHdd,
                                     (tANI_U8 *) mlmAuthInd.peerMacAddr,
>>>>>>> 657b0e9... prima update
                                     (tANI_U8 *) pHdr->sa,
                                     sizeof(tSirMacAddr));
                        mlmAuthInd.authType = (tAniAuthType)
                                              pRxAuthFrameBody->authAlgoNumber;
                        mlmAuthInd.sessionId = psessionEntry->smeSessionId;

                        limPostSmeMessage(pMac,
                                          LIM_MLM_AUTH_IND,
                                          (tANI_U32 *) &mlmAuthInd);
                        break;

                    case eSIR_SHARED_KEY:
<<<<<<< HEAD
<<<<<<< HEAD
                        PELOGW(limLog(pMac, LOGW, FL("=======> eSIR_SHARED_KEY  ...\n"));)
#ifdef WLAN_SOFTAP_FEATURE
=======
                        PELOGW(limLog(pMac, LOGW, FL("=======> eSIR_SHARED_KEY  ..."));)
>>>>>>> d97af3b... add prima wlan driver
=======
                        PELOGW(limLog(pMac, LOGW, FL("=======> eSIR_SHARED_KEY  ...\n"));)
#ifdef WLAN_SOFTAP_FEATURE
>>>>>>> 657b0e9... prima update
                        if(psessionEntry->limSystemRole == eLIM_AP_ROLE)
                        {
                            val = psessionEntry->privacy;
                        }
                        else   
<<<<<<< HEAD
<<<<<<< HEAD
#endif
=======
>>>>>>> d97af3b... add prima wlan driver
=======
#endif
>>>>>>> 657b0e9... prima update
                        if (wlan_cfgGetInt(pMac, WNI_CFG_PRIVACY_ENABLED,
                                      &val) != eSIR_SUCCESS)
                        {
                            /**
                             * Could not get Privacy option
                             * from CFG. Log error.
                             */
                            limLog(pMac, LOGP,
<<<<<<< HEAD
<<<<<<< HEAD
                                   FL("could not retrieve Privacy option\n"));
=======
                                   FL("could not retrieve Privacy option"));
>>>>>>> d97af3b... add prima wlan driver
=======
                                   FL("could not retrieve Privacy option\n"));
>>>>>>> 657b0e9... prima update
                        }
                        cfgPrivacyOptImp = (tANI_U8)val;
                        if (!cfgPrivacyOptImp)
                        {
                            /**
                             * Authenticator does not have WEP
                             * implemented.
                             * Reject by sending Authentication frame
                             * with Auth algorithm not supported status
                             * code.
                             */

                            authFrame.authAlgoNumber =
                            pRxAuthFrameBody->authAlgoNumber;
                            authFrame.authTransactionSeqNumber =
                            pRxAuthFrameBody->authTransactionSeqNumber + 1;
                            authFrame.authStatusCode =
                            eSIR_MAC_AUTH_ALGO_NOT_SUPPORTED_STATUS;

                            limSendAuthMgmtFrame(
                                                pMac, &authFrame,
                                                pHdr->sa,
                                                LIM_NO_WEP_IN_FC,psessionEntry);

                            // Log error
                            PELOGE(limLog(pMac, LOGE,
                                   FL("received Auth frame for unsupported auth algorithm %d "
                                   MAC_ADDRESS_STR), pRxAuthFrameBody->authAlgoNumber, 
                                   MAC_ADDR_ARRAY(pHdr->sa));)

                            return;
                        }
                        else
                        {
                            // Create entry for this STA
                            //in pre-auth list
                            pAuthNode = limAcquireFreePreAuthNode(pMac, &pMac->lim.gLimPreAuthTimerTable);
                            if (pAuthNode == NULL)
                            {
                                // Log error
                                limLog(pMac, LOGW,
                                       FL("Max pre-auth nodes reached "));
                                limPrintMacAddr(pMac, pHdr->sa, LOGW);

                                return;
                            }

<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
                            palCopyMemory( pMac->hHdd,
                                         (tANI_U8 *) pAuthNode->peerMacAddr,
                                         pHdr->sa,
                                         sizeof(tSirMacAddr));
<<<<<<< HEAD
=======
                            vos_mem_copy((tANI_U8 *) pAuthNode->peerMacAddr,
                                          pHdr->sa,
                                          sizeof(tSirMacAddr));
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update

                            pAuthNode->mlmState =
                            eLIM_MLM_WT_AUTH_FRAME3_STATE;
                            pAuthNode->authType =
                            (tAniAuthType)
                            pRxAuthFrameBody->authAlgoNumber;
                            pAuthNode->fSeen = 0;
                            pAuthNode->fTimerStarted = 0;
                            limAddPreAuthNode(pMac, pAuthNode);

<<<<<<< HEAD
<<<<<<< HEAD
                            PELOG1(limLog(pMac, LOG1, FL("Alloc new data: %x id %d peer \n"),
=======
                            PELOG1(limLog(pMac, LOG1, FL("Alloc new data: %x id %d peer "),
>>>>>>> d97af3b... add prima wlan driver
=======
                            PELOG1(limLog(pMac, LOG1, FL("Alloc new data: %x id %d peer \n"),
>>>>>>> 657b0e9... prima update
                                          pAuthNode, pAuthNode->authNodeIdx);)
                            PELOG1(limPrintMacAddr(pMac, pHdr->sa, LOG1);)

                            /// Create and activate Auth Response timer
                            if (tx_timer_change_context(&pAuthNode->timer, pAuthNode->authNodeIdx) != TX_SUCCESS)
                            {
                                /// Could not start Auth response timer.
                                // Log error
                                limLog(pMac, LOGP,
                                   FL("Unable to chg context auth response timer for peer "));
                                limPrintMacAddr(pMac, pHdr->sa, LOGP);

                                /**
                                 * Send Authenticaton frame with
                                 * unspecified failure status code.
                                 */

                                authFrame.authAlgoNumber =
                                        pRxAuthFrameBody->authAlgoNumber;
                                authFrame.authTransactionSeqNumber =
                                        pRxAuthFrameBody->authTransactionSeqNumber + 1;
                                authFrame.authStatusCode =
                                        eSIR_MAC_UNSPEC_FAILURE_STATUS;

                                limSendAuthMgmtFrame(pMac, &authFrame,
                                                     pHdr->sa,
                                                     LIM_NO_WEP_IN_FC,psessionEntry);

                                limDeletePreAuthNode(pMac, pHdr->sa);
                                return;
                            }

                            limActivateAuthRspTimer(pMac, pAuthNode);

                            pAuthNode->fTimerStarted = 1;

                            // get random bytes and use as
                            // challenge text
                            // TODO
                            //if( !VOS_IS_STATUS_SUCCESS( vos_rand_get_bytes( 0, (tANI_U8 *)challengeTextArray, SIR_MAC_AUTH_CHALLENGE_LENGTH ) ) )
                            {
                               limLog(pMac, LOGE,FL("Challenge text preparation failed in limProcessAuthFrame"));
                            }
                            
                            pChallenge = pAuthNode->challengeText;

<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
                            palCopyMemory( pMac->hHdd,
                                           pChallenge,
                                          (tANI_U8 *) challengeTextArray,
                                          sizeof(challengeTextArray));
<<<<<<< HEAD
=======
                            vos_mem_copy(pChallenge,
                                        (tANI_U8 *) challengeTextArray,
                                         sizeof(challengeTextArray));
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update

                            /**
                             * Sending Authenticaton frame with challenge.
                             */

                            authFrame.authAlgoNumber =
                            pRxAuthFrameBody->authAlgoNumber;
                            authFrame.authTransactionSeqNumber =
                            pRxAuthFrameBody->authTransactionSeqNumber + 1;
                            authFrame.authStatusCode =
                            eSIR_MAC_SUCCESS_STATUS;
                            authFrame.type   = SIR_MAC_CHALLENGE_TEXT_EID;
                            authFrame.length = SIR_MAC_AUTH_CHALLENGE_LENGTH;
<<<<<<< HEAD
<<<<<<< HEAD
                            palCopyMemory( pMac->hHdd,
                                         authFrame.challengeText,
=======
                            vos_mem_copy(authFrame.challengeText,
>>>>>>> d97af3b... add prima wlan driver
=======
                            palCopyMemory( pMac->hHdd,
                                         authFrame.challengeText,
>>>>>>> 657b0e9... prima update
                                         pAuthNode->challengeText,
                                         SIR_MAC_AUTH_CHALLENGE_LENGTH);

                            limSendAuthMgmtFrame(
                                                pMac, &authFrame,
                                                pHdr->sa,
                                                LIM_NO_WEP_IN_FC,psessionEntry);
                        } // if (wlan_cfgGetInt(CFG_PRIVACY_OPTION_IMPLEMENTED))

                        break;

                    default:
                        /**
                         * Responding party does not support the
                         * authentication algorithm requested by
                         * sending party.
                         * Reject by sending Authentication frame
                         * with auth algorithm not supported status code
                         */

                        authFrame.authAlgoNumber =
                        pRxAuthFrameBody->authAlgoNumber;
                        authFrame.authTransactionSeqNumber =
                        pRxAuthFrameBody->authTransactionSeqNumber + 1;
                        authFrame.authStatusCode =
                        eSIR_MAC_AUTH_ALGO_NOT_SUPPORTED_STATUS;

                        limSendAuthMgmtFrame(
                                            pMac, &authFrame,
                                            pHdr->sa,
                                            LIM_NO_WEP_IN_FC,psessionEntry);

                        // Log error
                       PELOGE( limLog(pMac, LOGE,
                               FL("received Auth frame for unsupported auth algorithm %d "
                               MAC_ADDRESS_STR), pRxAuthFrameBody->authAlgoNumber, 
                               MAC_ADDR_ARRAY(pHdr->sa));)

                        return;
                } // end switch(pRxAuthFrameBody->authAlgoNumber)
            } // if (limIsAuthAlgoSupported(pRxAuthFrameBody->authAlgoNumber))
            else
            {
                /**
                 * Responding party does not support the
                 * authentication algorithm requested by sending party.
                 * Reject Authentication with StatusCode=13.
                 */
                authFrame.authAlgoNumber =
                pRxAuthFrameBody->authAlgoNumber;
                authFrame.authTransactionSeqNumber =
                pRxAuthFrameBody->authTransactionSeqNumber + 1;
                authFrame.authStatusCode =
                eSIR_MAC_AUTH_ALGO_NOT_SUPPORTED_STATUS;

                limSendAuthMgmtFrame(pMac, &authFrame,
                                     pHdr->sa,
                                     LIM_NO_WEP_IN_FC,psessionEntry);

                // Log error
                PELOGE(limLog(pMac, LOGE,
                       FL("received Authentication frame for unsupported auth algorithm %d "
                       MAC_ADDRESS_STR), pRxAuthFrameBody->authAlgoNumber, 
                       MAC_ADDR_ARRAY(pHdr->sa));)
                return;
            } //end if (limIsAuthAlgoSupported(pRxAuthFrameBody->authAlgoNumber))
            break;

        case SIR_MAC_AUTH_FRAME_2:
            // AuthFrame 2

            if (psessionEntry->limMlmState != eLIM_MLM_WT_AUTH_FRAME2_STATE)
            {
                /**
                 * Received Authentication frame2 in an unexpected state.
                 * Log error and ignore the frame.
                 */

                // Log error
                PELOG1(limLog(pMac, LOG1,
                       FL("received Auth frame2 from peer in state %d, addr "),
                       psessionEntry->limMlmState);)
                PELOG1(limPrintMacAddr(pMac, pHdr->sa, LOG1);)

                return;
            }

<<<<<<< HEAD
<<<<<<< HEAD
            if ( !palEqualMemory( pMac->hHdd,(tANI_U8 *) pHdr->sa,
                          (tANI_U8 *) &pMac->lim.gpLimMlmAuthReq->peerMacAddr,
                          sizeof(tSirMacAddr)) )
=======
            if ( !vos_mem_compare((tANI_U8 *) pHdr->sa,
                                  (tANI_U8 *) &pMac->lim.gpLimMlmAuthReq->peerMacAddr,
                                  sizeof(tSirMacAddr)) )
>>>>>>> d97af3b... add prima wlan driver
=======
            if ( !palEqualMemory( pMac->hHdd,(tANI_U8 *) pHdr->sa,
                          (tANI_U8 *) &pMac->lim.gpLimMlmAuthReq->peerMacAddr,
                          sizeof(tSirMacAddr)) )
>>>>>>> 657b0e9... prima update
            {
                /**
                 * Received Authentication frame from an entity
                 * other than one request was initiated.
                 * Wait until Authentication Failure Timeout.
                 */

                // Log error
                PELOGW(limLog(pMac, LOGW,
                       FL("received Auth frame2 from unexpected peer "MAC_ADDRESS_STR),
                       MAC_ADDR_ARRAY(pHdr->sa));)

                break;
            }

            if (pRxAuthFrameBody->authStatusCode ==
                eSIR_MAC_AUTH_ALGO_NOT_SUPPORTED_STATUS)
            {
                /**
                 * Interoperability workaround: Linksys WAP4400N is returning
                 * wrong authType in OpenAuth response in case of 
                 * SharedKey AP configuration. Pretend we don't see that,
                 * so upper layer can fallback to SharedKey authType,
                 * and successfully connect to the AP.
                 */
                if (pRxAuthFrameBody->authAlgoNumber !=
                    pMac->lim.gpLimMlmAuthReq->authType)
                {
                    pRxAuthFrameBody->authAlgoNumber =
                    pMac->lim.gpLimMlmAuthReq->authType;
                }
            }

            if (pRxAuthFrameBody->authAlgoNumber !=
                pMac->lim.gpLimMlmAuthReq->authType)
            {
                /**
                 * Received Authentication frame with an auth
                 * algorithm other than one requested.
                 * Wait until Authentication Failure Timeout.
                 */

                // Log error
                PELOGW(limLog(pMac, LOGW,
                       FL("received Auth frame2 for unexpected auth algo number %d "
                       MAC_ADDRESS_STR), pRxAuthFrameBody->authAlgoNumber, 
                       MAC_ADDR_ARRAY(pHdr->sa));)

                break;
            }

            if (pRxAuthFrameBody->authStatusCode ==
                eSIR_MAC_SUCCESS_STATUS)
            {
                if (pRxAuthFrameBody->authAlgoNumber ==
                    eSIR_OPEN_SYSTEM)
                {
                    psessionEntry->limCurrentAuthType = eSIR_OPEN_SYSTEM;

                    pAuthNode = limAcquireFreePreAuthNode(pMac, &pMac->lim.gLimPreAuthTimerTable);

                    if (pAuthNode == NULL)
                    {
                        // Log error
                        limLog(pMac, LOGW,
                               FL("Max pre-auth nodes reached "));
                        limPrintMacAddr(pMac, pHdr->sa, LOGW);

                        return;
                    }

<<<<<<< HEAD
<<<<<<< HEAD
                    PELOG1(limLog(pMac, LOG1, FL("Alloc new data: %x peer \n"), pAuthNode);)
                    PELOG1(limPrintMacAddr(pMac, pHdr->sa, LOG1);)

                    palCopyMemory( pMac->hHdd,
                                 (tANI_U8 *) pAuthNode->peerMacAddr,
=======
                    PELOG1(limLog(pMac, LOG1, FL("Alloc new data: %x peer "), pAuthNode);)
                    PELOG1(limPrintMacAddr(pMac, pHdr->sa, LOG1);)

                    vos_mem_copy((tANI_U8 *) pAuthNode->peerMacAddr,
>>>>>>> d97af3b... add prima wlan driver
=======
                    PELOG1(limLog(pMac, LOG1, FL("Alloc new data: %x peer \n"), pAuthNode);)
                    PELOG1(limPrintMacAddr(pMac, pHdr->sa, LOG1);)

                    palCopyMemory( pMac->hHdd,
                                 (tANI_U8 *) pAuthNode->peerMacAddr,
>>>>>>> 657b0e9... prima update
                                 pMac->lim.gpLimMlmAuthReq->peerMacAddr,
                                 sizeof(tSirMacAddr));
                    pAuthNode->fTimerStarted = 0;
                    pAuthNode->authType = pMac->lim.gpLimMlmAuthReq->authType;
                    limAddPreAuthNode(pMac, pAuthNode);

                    limRestoreFromAuthState(pMac, eSIR_SME_SUCCESS,
                                            pRxAuthFrameBody->authStatusCode,psessionEntry);
                } // if (pRxAuthFrameBody->authAlgoNumber == eSIR_OPEN_SYSTEM)
                else
                {
                    // Shared key authentication

<<<<<<< HEAD
<<<<<<< HEAD
#ifdef WLAN_SOFTAP_FEATURE
=======
>>>>>>> d97af3b... add prima wlan driver
=======
#ifdef WLAN_SOFTAP_FEATURE
>>>>>>> 657b0e9... prima update
                    if(psessionEntry->limSystemRole == eLIM_AP_ROLE)
                    {
                        val = psessionEntry->privacy;
                    }
                    else   
<<<<<<< HEAD
<<<<<<< HEAD
#endif
=======
>>>>>>> d97af3b... add prima wlan driver
=======
#endif
>>>>>>> 657b0e9... prima update
                    if (wlan_cfgGetInt(pMac, WNI_CFG_PRIVACY_ENABLED,
                                  &val) != eSIR_SUCCESS)
                    {
                        /**
                         * Could not get Privacy option
                         * from CFG. Log error.
                         */
                        limLog(pMac, LOGP,
<<<<<<< HEAD
<<<<<<< HEAD
                               FL("could not retrieve Privacy option\n"));
=======
                               FL("could not retrieve Privacy option"));
>>>>>>> d97af3b... add prima wlan driver
=======
                               FL("could not retrieve Privacy option\n"));
>>>>>>> 657b0e9... prima update
                    }
                    cfgPrivacyOptImp = (tANI_U8)val;
                    if (!cfgPrivacyOptImp)
                    {
                        /**
                         * Requesting STA does not have WEP implemented.
                         * Reject with unsupported authentication algorithm
                         * Status code and wait until auth failure timeout
                         */

                        // Log error
                       PELOGE( limLog(pMac, LOGE,
                               FL("received Auth frame from peer for unsupported auth algo %d "
                               MAC_ADDRESS_STR), pRxAuthFrameBody->authAlgoNumber, 
                               MAC_ADDR_ARRAY(pHdr->sa));)

                        authFrame.authAlgoNumber =
                        pRxAuthFrameBody->authAlgoNumber;
                        authFrame.authTransactionSeqNumber =
                        pRxAuthFrameBody->authTransactionSeqNumber + 1;
                        authFrame.authStatusCode =
                        eSIR_MAC_AUTH_ALGO_NOT_SUPPORTED_STATUS;

                        limSendAuthMgmtFrame(pMac, &authFrame,
                                            pHdr->sa,
                                            LIM_NO_WEP_IN_FC,psessionEntry);
                        return;
                    }
                    else
                    {

                        if (pRxAuthFrameBody->type !=
                            SIR_MAC_CHALLENGE_TEXT_EID)
                        {
                            // Log error
                            PELOGE(limLog(pMac, LOGE,
<<<<<<< HEAD
<<<<<<< HEAD
                                   FL("received Auth frame with invalid challenge text IE\n"));)
=======
                                   FL("received Auth frame with invalid challenge text IE"));)
>>>>>>> d97af3b... add prima wlan driver
=======
                                   FL("received Auth frame with invalid challenge text IE\n"));)
>>>>>>> 657b0e9... prima update

                            return;
                        }

                        /**
                         * Check if there exists a key mappping key
                         * for the STA that sent Authentication frame
                         */
                        pKeyMapEntry = limLookUpKeyMappings(
                                                           pHdr->sa);

                        if (pKeyMapEntry)
                        {
                            if (pKeyMapEntry->key == NULL)
                            {
                                /**
                                 * Key Mapping entry has null key.
                                 * Send Auth frame with
                                 * challenge failure status code
                                 */
                                authFrame.authAlgoNumber =
                                pRxAuthFrameBody->authAlgoNumber;
                                authFrame.authTransactionSeqNumber =
                                pRxAuthFrameBody->authTransactionSeqNumber + 1;
                                authFrame.authStatusCode =
                                eSIR_MAC_CHALLENGE_FAILURE_STATUS;

                                limSendAuthMgmtFrame(pMac, &authFrame,
                                                     pHdr->sa,
                                                     LIM_NO_WEP_IN_FC,psessionEntry);

                                // Log error
                                PELOGE(limLog(pMac, LOGE,
                                       FL("received Auth frame from peer when key mapping key is NULL"
                                       MAC_ADDRESS_STR),MAC_ADDR_ARRAY(pHdr->sa));)

                                limRestoreFromAuthState(pMac, eSIR_SME_NO_KEY_MAPPING_KEY_FOR_PEER,
                                                              eSIR_MAC_UNSPEC_FAILURE_REASON,psessionEntry);

                                return;
                            } // if (pKeyMapEntry->key == NULL)
                            else
                            {
                                ((tpSirMacAuthFrameBody) plainBody)->authAlgoNumber =
                                sirSwapU16ifNeeded(pRxAuthFrameBody->authAlgoNumber);
                                ((tpSirMacAuthFrameBody) plainBody)->authTransactionSeqNumber =
                                sirSwapU16ifNeeded((tANI_U16) (pRxAuthFrameBody->authTransactionSeqNumber + 1));
                                ((tpSirMacAuthFrameBody) plainBody)->authStatusCode = eSIR_MAC_SUCCESS_STATUS;
                                ((tpSirMacAuthFrameBody) plainBody)->type   = SIR_MAC_CHALLENGE_TEXT_EID;
                                ((tpSirMacAuthFrameBody) plainBody)->length = SIR_MAC_AUTH_CHALLENGE_LENGTH;
<<<<<<< HEAD
<<<<<<< HEAD
                                palCopyMemory( pMac->hHdd, (tANI_U8 *) ((tpSirMacAuthFrameBody) plainBody)->challengeText,
=======
                                vos_mem_copy((tANI_U8 *) ((tpSirMacAuthFrameBody) plainBody)->challengeText,
>>>>>>> d97af3b... add prima wlan driver
=======
                                palCopyMemory( pMac->hHdd, (tANI_U8 *) ((tpSirMacAuthFrameBody) plainBody)->challengeText,
>>>>>>> 657b0e9... prima update
                                              pRxAuthFrameBody->challengeText,
                                              SIR_MAC_AUTH_CHALLENGE_LENGTH);

                                limEncryptAuthFrame(pMac, 0,
                                                    pKeyMapEntry->key,
                                                    plainBody,
                                                    encrAuthFrame,key_length);

                                psessionEntry->limMlmState = eLIM_MLM_WT_AUTH_FRAME4_STATE;
                                MTRACE(macTrace(pMac, TRACE_CODE_MLM_STATE, psessionEntry->peSessionId, psessionEntry->limMlmState));

                                limSendAuthMgmtFrame(pMac,
                                                     (tpSirMacAuthFrameBody) encrAuthFrame,
                                                     pHdr->sa,
                                                     LIM_WEP_IN_FC,psessionEntry);

                                break;
                            } // end if (pKeyMapEntry->key == NULL)
                        } // if (pKeyMapEntry)
                        else
                        {
                            if (wlan_cfgGetInt(pMac, WNI_CFG_WEP_DEFAULT_KEYID,
                                          &val) != eSIR_SUCCESS)
                            {
                                /**
                                 * Could not get Default keyId
                                 * from CFG. Log error.
                                 */
                                limLog(pMac, LOGP,
<<<<<<< HEAD
<<<<<<< HEAD
                                       FL("could not retrieve Default keyId\n"));
=======
                                       FL("could not retrieve Default keyId"));
>>>>>>> d97af3b... add prima wlan driver
=======
                                       FL("could not retrieve Default keyId\n"));
>>>>>>> 657b0e9... prima update
                            }
                            keyId = (tANI_U8)val;

                            val = SIR_MAC_KEY_LENGTH;

<<<<<<< HEAD
<<<<<<< HEAD
#ifdef WLAN_SOFTAP_FEATURE  
=======
>>>>>>> d97af3b... add prima wlan driver
=======
#ifdef WLAN_SOFTAP_FEATURE  
>>>>>>> 657b0e9... prima update
                            if(psessionEntry->limSystemRole == eLIM_AP_ROLE)
                            {
                                tpSirKeys pKey;
                                pKey =  &psessionEntry->WEPKeyMaterial[keyId].key[0];
<<<<<<< HEAD
<<<<<<< HEAD
                                palCopyMemory( pMac->hHdd, defaultKey, pKey->key, pKey->keyLength);
                            }
                            else
#endif
=======
                                vos_mem_copy(defaultKey, pKey->key, pKey->keyLength);
                            }
                            else
>>>>>>> d97af3b... add prima wlan driver
=======
                                palCopyMemory( pMac->hHdd, defaultKey, pKey->key, pKey->keyLength);
                            }
                            else
#endif
>>>>>>> 657b0e9... prima update
                            if (wlan_cfgGetStr(pMac, (tANI_U16) (WNI_CFG_WEP_DEFAULT_KEY_1 + keyId),
                                          defaultKey,
                                          &val)
                                != eSIR_SUCCESS)
                            {
                                /// Could not get Default key from CFG.
                                //Log error.
                                limLog(pMac, LOGP,
<<<<<<< HEAD
<<<<<<< HEAD
                                       FL("could not retrieve Default key\n"));
=======
                                       FL("could not retrieve Default key"));
>>>>>>> d97af3b... add prima wlan driver
=======
                                       FL("could not retrieve Default key\n"));
>>>>>>> 657b0e9... prima update

                                authFrame.authAlgoNumber =
                                pRxAuthFrameBody->authAlgoNumber;
                                authFrame.authTransactionSeqNumber =
                                pRxAuthFrameBody->authTransactionSeqNumber + 1;
                                authFrame.authStatusCode =
                                eSIR_MAC_CHALLENGE_FAILURE_STATUS;

                                limSendAuthMgmtFrame(
                                                    pMac, &authFrame,
                                                    pHdr->sa,
                                                    LIM_NO_WEP_IN_FC,psessionEntry);

                                limRestoreFromAuthState(pMac, eSIR_SME_INVALID_WEP_DEFAULT_KEY,
                                                              eSIR_MAC_UNSPEC_FAILURE_REASON,psessionEntry);

                                break;
                            }
                                key_length=val;
                                ((tpSirMacAuthFrameBody) plainBody)->authAlgoNumber =
                                sirSwapU16ifNeeded(pRxAuthFrameBody->authAlgoNumber);
                                ((tpSirMacAuthFrameBody) plainBody)->authTransactionSeqNumber =
                                sirSwapU16ifNeeded((tANI_U16) (pRxAuthFrameBody->authTransactionSeqNumber + 1));
                                ((tpSirMacAuthFrameBody) plainBody)->authStatusCode = eSIR_MAC_SUCCESS_STATUS;
                                ((tpSirMacAuthFrameBody) plainBody)->type   = SIR_MAC_CHALLENGE_TEXT_EID;
                                ((tpSirMacAuthFrameBody) plainBody)->length = SIR_MAC_AUTH_CHALLENGE_LENGTH;
<<<<<<< HEAD
<<<<<<< HEAD
                                palCopyMemory( pMac->hHdd, (tANI_U8 *) ((tpSirMacAuthFrameBody) plainBody)->challengeText,
=======
                                vos_mem_copy((tANI_U8 *) ((tpSirMacAuthFrameBody) plainBody)->challengeText,
>>>>>>> d97af3b... add prima wlan driver
=======
                                palCopyMemory( pMac->hHdd, (tANI_U8 *) ((tpSirMacAuthFrameBody) plainBody)->challengeText,
>>>>>>> 657b0e9... prima update
                                              pRxAuthFrameBody->challengeText,
                                              SIR_MAC_AUTH_CHALLENGE_LENGTH);

                                limEncryptAuthFrame(pMac, keyId,
                                                    defaultKey,
                                                    plainBody,
                                                    encrAuthFrame,key_length);

                                psessionEntry->limMlmState =
                                eLIM_MLM_WT_AUTH_FRAME4_STATE;
                                MTRACE(macTrace(pMac, TRACE_CODE_MLM_STATE, psessionEntry->peSessionId, psessionEntry->limMlmState));

                                limSendAuthMgmtFrame(pMac,
                                                     (tpSirMacAuthFrameBody) encrAuthFrame,
                                                     pHdr->sa,
                                                     LIM_WEP_IN_FC,psessionEntry);

                                break;
                        } // end if (pKeyMapEntry)
                    } // end if (!wlan_cfgGetInt(CFG_PRIVACY_OPTION_IMPLEMENTED))
                } // end if (pRxAuthFrameBody->authAlgoNumber == eSIR_OPEN_SYSTEM)
            } // if (pRxAuthFrameBody->authStatusCode == eSIR_MAC_SUCCESS_STATUS)
            else
            {
                /**
                 * Authentication failure.
                 * Return Auth confirm with received failure code to SME
                 */

                // Log error
                PELOGE(limLog(pMac, LOGE,
                       FL("received Auth frame from peer with failure code %d "
                       MAC_ADDRESS_STR), pRxAuthFrameBody->authStatusCode, 
                       MAC_ADDR_ARRAY(pHdr->sa));)

                limRestoreFromAuthState(pMac, eSIR_SME_AUTH_REFUSED,
                                              pRxAuthFrameBody->authStatusCode,psessionEntry);
            } // end if (pRxAuthFrameBody->authStatusCode == eSIR_MAC_SUCCESS_STATUS)

            break;

        case SIR_MAC_AUTH_FRAME_3:
            // AuthFrame 3

            if (pRxAuthFrameBody->authAlgoNumber != eSIR_SHARED_KEY)
            {
                /**
                 * Received Authentication frame3 with algorithm other than
                 * Shared Key authentication type. Reject with Auth frame4
                 * with 'out of sequence' status code.
                 */
                authFrame.authAlgoNumber = eSIR_SHARED_KEY;
                authFrame.authTransactionSeqNumber =
                SIR_MAC_AUTH_FRAME_4;
                authFrame.authStatusCode =
                eSIR_MAC_AUTH_FRAME_OUT_OF_SEQ_STATUS;

                limSendAuthMgmtFrame(pMac, &authFrame,
                                     pHdr->sa,
                                     LIM_NO_WEP_IN_FC,psessionEntry);

                // Log error
                PELOGE(limLog(pMac, LOGE,
                       FL("received Auth frame3 from peer with auth algo number %d "
                       MAC_ADDRESS_STR), pRxAuthFrameBody->authAlgoNumber, 
                       MAC_ADDR_ARRAY(pHdr->sa));)

                return;
            }

            if (psessionEntry->limSystemRole == eLIM_AP_ROLE || psessionEntry->limSystemRole == eLIM_BT_AMP_AP_ROLE ||
                psessionEntry->limSystemRole == eLIM_STA_IN_IBSS_ROLE)
            {
                /**
                 * Check if wep bit was set in FC. If not set,
                 * reject with Authentication frame4 with
                 * 'challenge failure' status code.
                 */
                if (!pHdr->fc.wep)
                {
                    /// WEP bit is not set in FC of Auth Frame3
                    authFrame.authAlgoNumber = eSIR_SHARED_KEY;
                    authFrame.authTransactionSeqNumber =
                    SIR_MAC_AUTH_FRAME_4;
                    authFrame.authStatusCode =
                    eSIR_MAC_CHALLENGE_FAILURE_STATUS;

                    limSendAuthMgmtFrame(pMac, &authFrame,
                                         pHdr->sa,
                                         LIM_NO_WEP_IN_FC,psessionEntry);

                    // Log error
                    PELOGE(limLog(pMac, LOGE,
                           FL("received Auth frame3 from peer with no WEP bit set "MAC_ADDRESS_STR),
                           MAC_ADDR_ARRAY(pHdr->sa));)

                    return;
                }

                pAuthNode = limSearchPreAuthList(pMac,
                                                pHdr->sa);
                if (pAuthNode == NULL)
                {
                    /**
                     * No 'pre-auth' context exists for
                     * this STA that sent an Authentication
                     * frame3.
                     * Send Auth frame4 with 'out of sequence'
                     * status code.
                     */
                    authFrame.authAlgoNumber = eSIR_SHARED_KEY;
                    authFrame.authTransactionSeqNumber =
                    SIR_MAC_AUTH_FRAME_4;
                    authFrame.authStatusCode =
                    eSIR_MAC_AUTH_FRAME_OUT_OF_SEQ_STATUS;

                    limSendAuthMgmtFrame(pMac, &authFrame,
                                         pHdr->sa,
                                         LIM_NO_WEP_IN_FC,psessionEntry);

                    // Log error
                    PELOGE(limLog(pMac, LOGW,
                           FL("received AuthFrame3 from peer that has no preauth context "
                           MAC_ADDRESS_STR), MAC_ADDR_ARRAY(pHdr->sa));)

                    return;
                }

                if (pAuthNode->mlmState == eLIM_MLM_AUTH_RSP_TIMEOUT_STATE)
                {
                    /**
                     * Received Auth Frame3 after Auth Response timeout.
                     * Reject by sending Auth Frame4 with
                     * Auth respone timeout Status Code.
                     */
                    authFrame.authAlgoNumber = eSIR_SHARED_KEY;
                    authFrame.authTransactionSeqNumber =
                    SIR_MAC_AUTH_FRAME_4;
                    authFrame.authStatusCode =
                    eSIR_MAC_AUTH_RSP_TIMEOUT_STATUS;

                    limSendAuthMgmtFrame(
                                        pMac, &authFrame,
                                        pHdr->sa,
                                        LIM_NO_WEP_IN_FC,psessionEntry);

                    // Log error
                    limLog(pMac, LOGW,
                           FL("auth response timer timedout for peer "));
                    limPrintMacAddr(pMac, pHdr->sa, LOGW);

                    /// Delete pre-auth context of STA
                    limDeletePreAuthNode(pMac,
                                         pHdr->sa);

                    return;
                } // end switch (pAuthNode->mlmState)

                if (pRxAuthFrameBody->authStatusCode != eSIR_MAC_SUCCESS_STATUS)
                {
                    /**
                     * Received Authenetication Frame 3 with status code
                     * other than success. Wait until Auth response timeout
                     * to delete STA context.
                     */

                    // Log error
                    PELOGE(limLog(pMac, LOGE,
                           FL("received Auth frame3 from peer with status code %d "
                           MAC_ADDRESS_STR), pRxAuthFrameBody->authStatusCode, 
                           MAC_ADDR_ARRAY(pHdr->sa));)

                    return;
                }

                /**
                 * Check if received challenge text is same as one sent in
                 * Authentication frame3
                 */

<<<<<<< HEAD
<<<<<<< HEAD
                if (palEqualMemory( pMac->hHdd,pRxAuthFrameBody->challengeText,
                              pAuthNode->challengeText,
                              SIR_MAC_AUTH_CHALLENGE_LENGTH))
=======
                if (vos_mem_compare(pRxAuthFrameBody->challengeText,
                                    pAuthNode->challengeText,
                                    SIR_MAC_AUTH_CHALLENGE_LENGTH))
>>>>>>> d97af3b... add prima wlan driver
=======
                if (palEqualMemory( pMac->hHdd,pRxAuthFrameBody->challengeText,
                              pAuthNode->challengeText,
                              SIR_MAC_AUTH_CHALLENGE_LENGTH))
>>>>>>> 657b0e9... prima update
                {
                    /// Challenge match. STA is autheticated !

                    /// Delete Authentication response timer if running
                    limDeactivateAndChangePerStaIdTimer(pMac,
                                                        eLIM_AUTH_RSP_TIMER,
                                                        pAuthNode->authNodeIdx);

                    pAuthNode->fTimerStarted = 0;
                    pAuthNode->mlmState = eLIM_MLM_AUTHENTICATED_STATE;

                    /**
                     * Send Authentication Frame4 with 'success' Status Code.
                     */
                    authFrame.authAlgoNumber = eSIR_SHARED_KEY;
                    authFrame.authTransactionSeqNumber =
<<<<<<< HEAD
<<<<<<< HEAD
                    SIR_MAC_AUTH_FRAME_4;
=======
                        SIR_MAC_AUTH_FRAME_4;
>>>>>>> d97af3b... add prima wlan driver
=======
                    SIR_MAC_AUTH_FRAME_4;
>>>>>>> 657b0e9... prima update
                    authFrame.authStatusCode = eSIR_MAC_SUCCESS_STATUS;

                    limSendAuthMgmtFrame(pMac, &authFrame,
                                         pHdr->sa,
                                         LIM_NO_WEP_IN_FC,psessionEntry);

                    /// Send Auth indication to SME
<<<<<<< HEAD
<<<<<<< HEAD
                    palCopyMemory( pMac->hHdd,
                                 (tANI_U8 *) mlmAuthInd.peerMacAddr,
                                 (tANI_U8 *) pHdr->sa,
                                 sizeof(tSirMacAddr));
=======
                    vos_mem_copy((tANI_U8 *) mlmAuthInd.peerMacAddr,
                                 (tANI_U8 *) pHdr->sa,
                                  sizeof(tSirMacAddr));
>>>>>>> d97af3b... add prima wlan driver
=======
                    palCopyMemory( pMac->hHdd,
                                 (tANI_U8 *) mlmAuthInd.peerMacAddr,
                                 (tANI_U8 *) pHdr->sa,
                                 sizeof(tSirMacAddr));
>>>>>>> 657b0e9... prima update
                    mlmAuthInd.authType = (tAniAuthType)
                                          pRxAuthFrameBody->authAlgoNumber;
                    mlmAuthInd.sessionId = psessionEntry->smeSessionId;

                    limPostSmeMessage(pMac,
                                      LIM_MLM_AUTH_IND,
                                      (tANI_U32 *) &mlmAuthInd);

                    break;
                }
                else
                {
                    /**
                     * Challenge Failure.
                     * Send Authentication frame4 with 'challenge failure'
                     * status code and wait until Auth response timeout to
                     * delete STA context.
                     */

                    authFrame.authAlgoNumber =
<<<<<<< HEAD
<<<<<<< HEAD
                    pRxAuthFrameBody->authAlgoNumber;
                    authFrame.authTransactionSeqNumber =
                    SIR_MAC_AUTH_FRAME_4;
                    authFrame.authStatusCode =
                    eSIR_MAC_CHALLENGE_FAILURE_STATUS;
=======
                        pRxAuthFrameBody->authAlgoNumber;
=======
                    pRxAuthFrameBody->authAlgoNumber;
>>>>>>> 657b0e9... prima update
                    authFrame.authTransactionSeqNumber =
                    SIR_MAC_AUTH_FRAME_4;
                    authFrame.authStatusCode =
<<<<<<< HEAD
                        eSIR_MAC_CHALLENGE_FAILURE_STATUS;
>>>>>>> d97af3b... add prima wlan driver
=======
                    eSIR_MAC_CHALLENGE_FAILURE_STATUS;
>>>>>>> 657b0e9... prima update

                    limSendAuthMgmtFrame(pMac, &authFrame,
                                         pHdr->sa,
                                         LIM_NO_WEP_IN_FC,psessionEntry);

                    // Log error
<<<<<<< HEAD
<<<<<<< HEAD
                   PELOGE( limLog(pMac, LOGW,
                           FL("Challenge failure for peer "MAC_ADDRESS_STR), 
						   MAC_ADDR_ARRAY(pHdr->sa));)
=======
                    PELOGE( limLog(pMac, LOGW,
                                   FL("Challenge failure for peer "MAC_ADDRESS_STR),
                                   MAC_ADDR_ARRAY(pHdr->sa));)
>>>>>>> d97af3b... add prima wlan driver
=======
                   PELOGE( limLog(pMac, LOGW,
                           FL("Challenge failure for peer "MAC_ADDRESS_STR), 
						   MAC_ADDR_ARRAY(pHdr->sa));)
>>>>>>> 657b0e9... prima update
                    return;
                }
            } // if (pMac->lim.gLimSystemRole == eLIM_AP_ROLE || ...

            break;

        case SIR_MAC_AUTH_FRAME_4:
            // AuthFrame 4
            if (psessionEntry->limMlmState != eLIM_MLM_WT_AUTH_FRAME4_STATE)
            {
                /**
                 * Received Authentication frame4 in an unexpected state.
                 * Log error and ignore the frame.
                 */

                // Log error
                PELOG1(limLog(pMac, LOG1,
                       FL("received unexpected Auth frame4 from peer in state %d, addr "),
                       psessionEntry->limMlmState);)
               PELOG1( limPrintMacAddr(pMac, pHdr->sa, LOG1);)

                return;
            }

            if (pRxAuthFrameBody->authAlgoNumber != eSIR_SHARED_KEY)
            {
                /**
                 * Received Authentication frame4 with algorithm other than
                 * Shared Key authentication type.
                 * Wait until Auth failure timeout to report authentication
                 * failure to SME.
                 */

                // Log error
                PELOGE(limLog(pMac, LOGE,
                       FL("received Auth frame4 from peer with invalid auth algo %d "
                       MAC_ADDRESS_STR), pRxAuthFrameBody->authAlgoNumber, 
                       MAC_ADDR_ARRAY(pHdr->sa));)

                return;
            }

<<<<<<< HEAD
<<<<<<< HEAD
            if ( !palEqualMemory( pMac->hHdd,(tANI_U8 *) pHdr->sa,
                          (tANI_U8 *) &pMac->lim.gpLimMlmAuthReq->peerMacAddr,
                          sizeof(tSirMacAddr)) )
=======
            if ( !vos_mem_compare((tANI_U8 *) pHdr->sa,
                                  (tANI_U8 *) &pMac->lim.gpLimMlmAuthReq->peerMacAddr,
                                  sizeof(tSirMacAddr)) )
>>>>>>> d97af3b... add prima wlan driver
=======
            if ( !palEqualMemory( pMac->hHdd,(tANI_U8 *) pHdr->sa,
                          (tANI_U8 *) &pMac->lim.gpLimMlmAuthReq->peerMacAddr,
                          sizeof(tSirMacAddr)) )
>>>>>>> 657b0e9... prima update
            {
                /**
                 * Received Authentication frame from an entity
                 * other than one to which request was initiated.
                 * Wait until Authentication Failure Timeout.
                 */

                // Log error
                PELOGE(limLog(pMac, LOGW,
                       FL("received Auth frame4 from unexpected peer "
                       MAC_ADDRESS_STR), MAC_ADDR_ARRAY(pHdr->sa));)

                break;
            }

            if (pRxAuthFrameBody->authAlgoNumber !=
                pMac->lim.gpLimMlmAuthReq->authType)
            {
                /**
                 * Received Authentication frame with an auth algorithm
                 * other than one requested.
                 * Wait until Authentication Failure Timeout.
                 */

                PELOGE(limLog(pMac, LOGE,
                       FL("received Authentication frame from peer with invalid auth seq number %d "
                       MAC_ADDRESS_STR), pRxAuthFrameBody->authTransactionSeqNumber, 
                       MAC_ADDR_ARRAY(pHdr->sa));)

                break;
            }

            if (pRxAuthFrameBody->authStatusCode ==
                eSIR_MAC_SUCCESS_STATUS)
            {
                /**
                 * Authentication Success !
                 * Inform SME of same.
                 */
                psessionEntry->limCurrentAuthType = eSIR_SHARED_KEY;

                pAuthNode = limAcquireFreePreAuthNode(pMac, &pMac->lim.gLimPreAuthTimerTable);
                if (pAuthNode == NULL)
                {
                    // Log error
                    limLog(pMac, LOGW,
                           FL("Max pre-auth nodes reached "));
                    limPrintMacAddr(pMac, pHdr->sa, LOGW);

                    return;
                }
<<<<<<< HEAD
<<<<<<< HEAD
                PELOG1(limLog(pMac, LOG1, FL("Alloc new data: %x peer \n"), pAuthNode);
                limPrintMacAddr(pMac, pHdr->sa, LOG1);)

                palCopyMemory( pMac->hHdd,
                             (tANI_U8 *) pAuthNode->peerMacAddr,
=======
                PELOG1(limLog(pMac, LOG1, FL("Alloc new data: %x peer "), pAuthNode);
                limPrintMacAddr(pMac, pHdr->sa, LOG1);)

                vos_mem_copy((tANI_U8 *) pAuthNode->peerMacAddr,
>>>>>>> d97af3b... add prima wlan driver
=======
                PELOG1(limLog(pMac, LOG1, FL("Alloc new data: %x peer \n"), pAuthNode);
                limPrintMacAddr(pMac, pHdr->sa, LOG1);)

                palCopyMemory( pMac->hHdd,
                             (tANI_U8 *) pAuthNode->peerMacAddr,
>>>>>>> 657b0e9... prima update
                             pMac->lim.gpLimMlmAuthReq->peerMacAddr,
                             sizeof(tSirMacAddr));
                pAuthNode->fTimerStarted = 0;
                pAuthNode->authType = pMac->lim.gpLimMlmAuthReq->authType;
                limAddPreAuthNode(pMac, pAuthNode);

                limRestoreFromAuthState(pMac, eSIR_SME_SUCCESS,
                                              pRxAuthFrameBody->authStatusCode,psessionEntry);

            } // if (pRxAuthFrameBody->authStatusCode == eSIR_MAC_SUCCESS_STATUS)
            else
            {
                /**
                 * Authentication failure.
                 * Return Auth confirm with received failure code to SME
                 */

                // Log error
                PELOGE(limLog(pMac, LOGE, FL("Authentication failure from peer "
                       MAC_ADDRESS_STR), MAC_ADDR_ARRAY(pHdr->sa));)

                limRestoreFromAuthState(pMac, eSIR_SME_AUTH_REFUSED,
                                              pRxAuthFrameBody->authStatusCode,psessionEntry);
            } // end if (pRxAuthFrameBody->Status == 0)

            break;

        default:
            /// Invalid Authentication Frame received. Ignore it.

            // Log error
            PELOGE(limLog(pMac, LOGE,
                   FL("received Auth frame from peer with invalid auth seq number %d "
                   MAC_ADDRESS_STR), pRxAuthFrameBody->authTransactionSeqNumber, 
                   MAC_ADDR_ARRAY(pHdr->sa));)

            break;
    } // end switch (pRxAuthFrameBody->authTransactionSeqNumber)
} /*** end limProcessAuthFrame() ***/





#ifdef WLAN_FEATURE_VOWIFI_11R

/*----------------------------------------------------------------------
 *
 * Pass the received Auth frame. This is possibly the pre-auth from the
 * neighbor AP, in the same mobility domain.
 * This will be used in case of 11r FT.
 *
 * !!!! This is going to be renoved for the next checkin. We will be creating
 * the session before sending out the Auth. Thus when auth response
 * is received we will have a session in progress. !!!!!
 *----------------------------------------------------------------------
 */
<<<<<<< HEAD
<<<<<<< HEAD
int limProcessAuthFrameNoSession(tpAniSirGlobal pMac, tANI_U8 *pBd, void *body)
=======
tSirRetStatus limProcessAuthFrameNoSession(tpAniSirGlobal pMac, tANI_U8 *pBd, void *body)
>>>>>>> d97af3b... add prima wlan driver
=======
int limProcessAuthFrameNoSession(tpAniSirGlobal pMac, tANI_U8 *pBd, void *body)
>>>>>>> 657b0e9... prima update
{
    tpSirMacMgmtHdr pHdr;
    tpPESession psessionEntry = NULL;
    tANI_U8 *pBody;
    tANI_U16  frameLen;
    tSirMacAuthFrameBody rxAuthFrame;
    tSirMacAuthFrameBody *pRxAuthFrameBody = NULL;
<<<<<<< HEAD
<<<<<<< HEAD
    int ret_status = eSIR_FAILURE;
=======
    tSirRetStatus ret_status = eSIR_FAILURE;
>>>>>>> d97af3b... add prima wlan driver
=======
    int ret_status = eSIR_FAILURE;
>>>>>>> 657b0e9... prima update

    pHdr = WDA_GET_RX_MAC_HEADER(pBd);
    pBody = WDA_GET_RX_MPDU_DATA(pBd);
    frameLen = WDA_GET_RX_PAYLOAD_LEN(pBd);

<<<<<<< HEAD
<<<<<<< HEAD
=======
    VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_DEBUG,
              FL("Auth Frame Received: BSSID " MAC_ADDRESS_STR " (RSSI %d)"),
              MAC_ADDR_ARRAY(pHdr->bssId),
              (uint)abs((tANI_S8)WDA_GET_RX_RSSI_DB(pBd)));

>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
    // Check for the operating channel and see what needs to be done next.
    psessionEntry = pMac->ft.ftPEContext.psavedsessionEntry;
    if (psessionEntry == NULL) 
    {
        limLog(pMac, LOGW, FL("Error: Unable to find session id while in pre-auth phase for FT"));
        return eSIR_FAILURE;
    }

    if (pMac->ft.ftPEContext.pFTPreAuthReq == NULL)
    {
        // No FT in progress.
        return eSIR_FAILURE;
    }

    if (frameLen == 0) 
    {
        return eSIR_FAILURE;
    }
#ifdef WLAN_FEATURE_VOWIFI_11R_DEBUG
<<<<<<< HEAD
<<<<<<< HEAD
    limPrintMacAddr(pMac, pHdr->bssId, LOGE);
    limPrintMacAddr(pMac, pMac->ft.ftPEContext.pFTPreAuthReq->preAuthbssId, LOGE);
    limLog(pMac,LOG2,FL("seqControl 0x%X\n"), 
=======
    limPrintMacAddr(pMac, pHdr->bssId, LOG2);
    limPrintMacAddr(pMac, pMac->ft.ftPEContext.pFTPreAuthReq->preAuthbssId, LOG2);
    limLog(pMac,LOG2,FL("seqControl 0x%X"),
>>>>>>> d97af3b... add prima wlan driver
=======
    limPrintMacAddr(pMac, pHdr->bssId, LOGE);
    limPrintMacAddr(pMac, pMac->ft.ftPEContext.pFTPreAuthReq->preAuthbssId, LOGE);
    limLog(pMac,LOG2,FL("seqControl 0x%X\n"), 
>>>>>>> 657b0e9... prima update
            ((pHdr->seqControl.seqNumHi << 8) | 
            (pHdr->seqControl.seqNumLo << 4) |
            (pHdr->seqControl.fragNum)));
#endif

    // Check that its the same bssId we have for preAuth
<<<<<<< HEAD
<<<<<<< HEAD
    if (!palEqualMemory( pMac->hHdd, pMac->ft.ftPEContext.pFTPreAuthReq->preAuthbssId,
        pHdr->bssId, sizeof( tSirMacAddr )))
=======
    if (!vos_mem_compare(pMac->ft.ftPEContext.pFTPreAuthReq->preAuthbssId,
                         pHdr->bssId, sizeof( tSirMacAddr )))
>>>>>>> d97af3b... add prima wlan driver
=======
    if (!palEqualMemory( pMac->hHdd, pMac->ft.ftPEContext.pFTPreAuthReq->preAuthbssId,
        pHdr->bssId, sizeof( tSirMacAddr )))
>>>>>>> 657b0e9... prima update
    {
        // In this case SME if indeed has triggered a 
        // pre auth it will time out.
        return eSIR_FAILURE;
    }

    if (eANI_BOOLEAN_TRUE ==
        pMac->ft.ftPEContext.pFTPreAuthReq->bPreAuthRspProcessed)
    {
        /*
         * This is likely a duplicate for the same pre-auth request.
         * PE/LIM already posted a response to SME. Hence, drop it.
         * TBD: 
         * 1) How did we even receive multiple auth responses?
         * 2) Do we need to delete pre-auth session? Suppose we
         * previously received an auth resp with failure which
         * would not have created the session and forwarded to SME.
         * And, we subsequently received an auth resp with success
         * which would have created the session. This will now be
         * dropped without being forwarded to SME! However, it is
         * very unlikely to receive auth responses from the same
         * AP with different reason codes.
         * NOTE: return eSIR_SUCCESS so that the packet is dropped
         * as this was indeed a response from the BSSID we tried to 
         * pre-auth.
         */
<<<<<<< HEAD
<<<<<<< HEAD
        PELOGE(limLog(pMac,LOGE,"Auth rsp already posted to SME"
               " (session %p, FT session %p)\n", psessionEntry,
=======
        PELOGE(limLog(pMac,LOG1,"Auth rsp already posted to SME"
               " (session %p, FT session %p)", psessionEntry,
>>>>>>> d97af3b... add prima wlan driver
=======
        PELOGE(limLog(pMac,LOGE,"Auth rsp already posted to SME"
               " (session %p, FT session %p)\n", psessionEntry,
>>>>>>> 657b0e9... prima update
               pMac->ft.ftPEContext.pftSessionEntry););
        return eSIR_SUCCESS;
    }
    else
    {
<<<<<<< HEAD
<<<<<<< HEAD
        PELOGE(limLog(pMac,LOGE,"Auth rsp not yet posted to SME"
               " (session %p, FT session %p)\n", psessionEntry,
=======
        PELOGE(limLog(pMac,LOGW,"Auth rsp not yet posted to SME"
               " (session %p, FT session %p)", psessionEntry,
>>>>>>> d97af3b... add prima wlan driver
=======
        PELOGE(limLog(pMac,LOGE,"Auth rsp not yet posted to SME"
               " (session %p, FT session %p)\n", psessionEntry,
>>>>>>> 657b0e9... prima update
               pMac->ft.ftPEContext.pftSessionEntry););
        pMac->ft.ftPEContext.pFTPreAuthReq->bPreAuthRspProcessed =
            eANI_BOOLEAN_TRUE;
    }

#ifdef WLAN_FEATURE_VOWIFI_11R_DEBUG
<<<<<<< HEAD
<<<<<<< HEAD
    limLog(pMac, LOGE, FL("Pre-Auth response received from neighbor"));
    limLog(pMac, LOGE, FL("Pre-Auth done state"));
=======
    limLog(pMac, LOG1, FL("Pre-Auth response received from neighbor"));
    limLog(pMac, LOG1, FL("Pre-Auth done state"));
>>>>>>> d97af3b... add prima wlan driver
=======
    limLog(pMac, LOGE, FL("Pre-Auth response received from neighbor"));
    limLog(pMac, LOGE, FL("Pre-Auth done state"));
>>>>>>> 657b0e9... prima update
#endif
    // Stopping timer now, that we have our unicast from the AP
    // of our choice.
    limDeactivateAndChangeTimer(pMac, eLIM_FT_PREAUTH_RSP_TIMER);


    // Save off the auth resp.
    if ((sirConvertAuthFrame2Struct(pMac, pBody, frameLen, &rxAuthFrame) != eSIR_SUCCESS))
    {
        limHandleFTPreAuthRsp(pMac, eSIR_FAILURE, NULL, 0, psessionEntry);
        return eSIR_FAILURE;
    }
    pRxAuthFrameBody = &rxAuthFrame;

#ifdef WLAN_FEATURE_VOWIFI_11R_DEBUG
<<<<<<< HEAD
<<<<<<< HEAD
    PELOGE(limLog(pMac, LOGE,
           FL("Received Auth frame with type=%d seqnum=%d, status=%d (%d)\n"),
=======
    PELOGE(limLog(pMac, LOG1,
           FL("Received Auth frame with type=%d seqnum=%d, status=%d (%d)"),
>>>>>>> d97af3b... add prima wlan driver
=======
    PELOGE(limLog(pMac, LOGE,
           FL("Received Auth frame with type=%d seqnum=%d, status=%d (%d)\n"),
>>>>>>> 657b0e9... prima update
           (tANI_U32) pRxAuthFrameBody->authAlgoNumber,
           (tANI_U32) pRxAuthFrameBody->authTransactionSeqNumber,
           (tANI_U32) pRxAuthFrameBody->authStatusCode,(tANI_U32)pMac->lim.gLimNumPreAuthContexts);)
#endif

    switch (pRxAuthFrameBody->authTransactionSeqNumber)
    {
        case SIR_MAC_AUTH_FRAME_2:
            if (pRxAuthFrameBody->authStatusCode != eSIR_MAC_SUCCESS_STATUS)
            {
#ifdef WLAN_FEATURE_VOWIFI_11R_DEBUG
<<<<<<< HEAD
<<<<<<< HEAD
                PELOGE(limLog( pMac, LOGE, "Auth status code received is  %d\n", 
                    (tANI_U32) pRxAuthFrameBody->authStatusCode);)
#endif
=======
                PELOGE(limLog( pMac, LOGE, "Auth status code received is %d",
                    (tANI_U32) pRxAuthFrameBody->authStatusCode););
#endif
                if (eSIR_MAC_MAX_ASSOC_STA_REACHED_STATUS == pRxAuthFrameBody->authStatusCode)
                    ret_status = eSIR_LIM_MAX_STA_REACHED_ERROR;
>>>>>>> d97af3b... add prima wlan driver
=======
                PELOGE(limLog( pMac, LOGE, "Auth status code received is  %d\n", 
                    (tANI_U32) pRxAuthFrameBody->authStatusCode);)
#endif
>>>>>>> 657b0e9... prima update
            }
            else 
            {
                ret_status = eSIR_SUCCESS;
            }
            break;

        default:
#ifdef WLAN_FEATURE_VOWIFI_11R_DEBUG
<<<<<<< HEAD
<<<<<<< HEAD
            PELOGE(limLog( pMac, LOGE, "Seq. no incorrect expected 2 received %d\n", 
=======
            PELOGE(limLog( pMac, LOGE, "Seq. no incorrect expected 2 received %d",
>>>>>>> d97af3b... add prima wlan driver
=======
            PELOGE(limLog( pMac, LOGE, "Seq. no incorrect expected 2 received %d\n", 
>>>>>>> 657b0e9... prima update
                (tANI_U32) pRxAuthFrameBody->authTransactionSeqNumber);)
#endif
            break;
    }

    // Send the Auth response to SME
    limHandleFTPreAuthRsp(pMac, ret_status, pBody, frameLen, psessionEntry);

    return ret_status;
}

#endif /* WLAN_FEATURE_VOWIFI_11R */

