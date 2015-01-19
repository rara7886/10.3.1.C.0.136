/*
<<<<<<< HEAD
<<<<<<< HEAD
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
 * This file limProcessDeauthFrame.cc contains the code
 * for processing Deauthentication Frame.
 * Author:        Chandra Modumudi
 * Date:          03/24/02
 * History:-
 * Date           Modified by    Modification Information
 * --------------------------------------------------------------------
 *
 */
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
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
#include "palTypes.h"
#include "aniGlobal.h"

#include "utilsApi.h"
#include "limTypes.h"
#include "limUtils.h"
#include "limAssocUtils.h"
#include "limSecurityUtils.h"
#include "limSerDesUtils.h"
#include "schApi.h"
#include "limSendMessages.h"



/**
 * limProcessDeauthFrame
 *
 *FUNCTION:
 * This function is called by limProcessMessageQueue() upon
 * Deauthentication frame reception.
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 *
 *NOTE:
 *
 * @param  pMac - Pointer to Global MAC structure
 * @param  *pRxPacketInfo - A pointer to Buffer descriptor + associated PDUs
 * @return None
 */

void
limProcessDeauthFrame(tpAniSirGlobal pMac, tANI_U8 *pRxPacketInfo, tpPESession psessionEntry)
{
    tANI_U8           *pBody;
    tANI_U16          aid, reasonCode;
    tpSirMacMgmtHdr   pHdr;
    tLimMlmAssocCnf   mlmAssocCnf;
    tLimMlmDeauthInd  mlmDeauthInd;
    tpDphHashNode     pStaDs;
<<<<<<< HEAD
<<<<<<< HEAD
=======
    tpPESession       pRoamSessionEntry=NULL;
    tANI_U8           roamSessionId;
#ifdef WLAN_FEATURE_11W
    tANI_U32          frameLen;
#endif
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update


    pHdr = WDA_GET_RX_MAC_HEADER(pRxPacketInfo);

    pBody = WDA_GET_RX_MPDU_DATA(pRxPacketInfo);


    if ((eLIM_STA_ROLE == psessionEntry->limSystemRole) && (eLIM_SME_WT_DEAUTH_STATE == psessionEntry->limSmeState))
    {
<<<<<<< HEAD
<<<<<<< HEAD
       PELOGE(limLog(pMac, LOGE,
        FL("received Deauth frame in DEAUTH_WT_STATE(already processing previously received DEAUTH frame).. Dropping this..\n "));)
       return;
=======
        /*Every 15th deauth frame will be logged in kmsg*/
        if(!(pMac->lim.deauthMsgCnt & 0xF))
        {
            PELOGE(limLog(pMac, LOGE,
             FL("received Deauth frame in DEAUTH_WT_STATE"
                "(already processing previously received DEAUTH frame).."
                "Dropping this.. Deauth Failed %d \n "),++pMac->lim.deauthMsgCnt);)
        }
        else
        {
            pMac->lim.deauthMsgCnt++;
        }
        return;
>>>>>>> d97af3b... add prima wlan driver
=======
       PELOGE(limLog(pMac, LOGE,
        FL("received Deauth frame in DEAUTH_WT_STATE(already processing previously received DEAUTH frame).. Dropping this..\n "));)
       return;
>>>>>>> 657b0e9... prima update
    }

    if (limIsGroupAddr(pHdr->sa))
    {
        // Received Deauth frame from a BC/MC address
        // Log error and ignore it
        PELOG1(limLog(pMac, LOG1,
<<<<<<< HEAD
<<<<<<< HEAD
               FL("received Deauth frame from a BC/MC address\n"));)
=======
               FL("received Deauth frame from a BC/MC address"));)
>>>>>>> d97af3b... add prima wlan driver
=======
               FL("received Deauth frame from a BC/MC address\n"));)
>>>>>>> 657b0e9... prima update

        return;
    }

    if (limIsGroupAddr(pHdr->da) && !limIsAddrBC(pHdr->da))
    {
        // Received Deauth frame for a MC address
        // Log error and ignore it
        PELOG1(limLog(pMac, LOG1,
<<<<<<< HEAD
<<<<<<< HEAD
               FL("received Deauth frame for a MC address\n"));)

        return;
    }
=======
               FL("received Deauth frame for a MC address"));)

        return;
    }

#ifdef WLAN_FEATURE_11W
    /* PMF: If this session is a PMF session, then ensure that this frame was protected */
    if(psessionEntry->limRmfEnabled  && (WDA_GET_RX_DPU_FEEDBACK(pRxPacketInfo) & DPU_FEEDBACK_UNPROTECTED_ERROR))
    {
        PELOGE(limLog(pMac, LOGE, FL("received an unprotected deauth from AP"));)
        // If the frame received is unprotected, forward it to the supplicant to initiate
        // an SA query
        frameLen = WDA_GET_RX_PAYLOAD_LEN(pRxPacketInfo);

        //send the unprotected frame indication to SME
        limSendSmeUnprotectedMgmtFrameInd( pMac, pHdr->fc.subType,
                                           (tANI_U8*)pHdr, (frameLen + sizeof(tSirMacMgmtHdr)),
                                           psessionEntry->smeSessionId, psessionEntry);
        return;
    }
#endif

>>>>>>> d97af3b... add prima wlan driver
=======
               FL("received Deauth frame for a MC address\n"));)

        return;
    }
>>>>>>> 657b0e9... prima update
    // Get reasonCode from Deauthentication frame body
    reasonCode = sirReadU16(pBody);

    PELOGE(limLog(pMac, LOGE,
        FL("received Deauth frame (mlm state = %s) with reason code %d from "),
        limMlmStateStr(psessionEntry->limMlmState), reasonCode);
    limPrintMacAddr(pMac, pHdr->sa, LOGE);)
      
<<<<<<< HEAD
<<<<<<< HEAD
=======
    if (limCheckDisassocDeauthAckPending(pMac, (tANI_U8*)pHdr->sa))
    {
        PELOGW(limLog(pMac, LOGW,
                    FL("Ignore the Deauth received, while waiting for ack of disassoc/deauth"));)
        limCleanUpDisassocDeauthReq(pMac,(tANI_U8*)pHdr->sa, 1);
        return;
    }

  
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
    if ( (psessionEntry->limSystemRole == eLIM_AP_ROLE )||(psessionEntry->limSystemRole == eLIM_BT_AMP_AP_ROLE) )
    {
        switch (reasonCode)
        {
            case eSIR_MAC_UNSPEC_FAILURE_REASON:
            case eSIR_MAC_DEAUTH_LEAVING_BSS_REASON:
                // Valid reasonCode in received Deauthentication frame
                break;

            default:
                // Invalid reasonCode in received Deauthentication frame
                // Log error and ignore the frame
                PELOG1(limLog(pMac, LOG1,
<<<<<<< HEAD
<<<<<<< HEAD
                   FL("received Deauth frame with invalid reasonCode %d from \n"),
=======
                   FL("received Deauth frame with invalid reasonCode %d from "),
>>>>>>> d97af3b... add prima wlan driver
=======
                   FL("received Deauth frame with invalid reasonCode %d from \n"),
>>>>>>> 657b0e9... prima update
                   reasonCode);
                limPrintMacAddr(pMac, pHdr->sa, LOG1);)

                break;
        }
    }
    else if (psessionEntry->limSystemRole == eLIM_STA_ROLE ||psessionEntry->limSystemRole == eLIM_BT_AMP_STA_ROLE)
    {
        switch (reasonCode)
        {
            case eSIR_MAC_UNSPEC_FAILURE_REASON:
            case eSIR_MAC_PREV_AUTH_NOT_VALID_REASON:
            case eSIR_MAC_DEAUTH_LEAVING_BSS_REASON:
            case eSIR_MAC_CLASS2_FRAME_FROM_NON_AUTH_STA_REASON:
            case eSIR_MAC_CLASS3_FRAME_FROM_NON_ASSOC_STA_REASON:
            case eSIR_MAC_STA_NOT_PRE_AUTHENTICATED_REASON:
                // Valid reasonCode in received Deauth frame
                break;

            default:
                // Invalid reasonCode in received Deauth frame
                // Log error and ignore the frame
                PELOG1(limLog(pMac, LOG1,
<<<<<<< HEAD
<<<<<<< HEAD
                   FL("received Deauth frame with invalid reasonCode %d from \n"),
=======
                   FL("received Deauth frame with invalid reasonCode %d from "),
>>>>>>> d97af3b... add prima wlan driver
=======
                   FL("received Deauth frame with invalid reasonCode %d from \n"),
>>>>>>> 657b0e9... prima update
                   reasonCode);
                limPrintMacAddr(pMac, pHdr->sa, LOG1);)

                break;
        }
    }
    else
    {
        // Received Deauth frame in either IBSS
<<<<<<< HEAD
<<<<<<< HEAD
        // or un-known role. Log error and ignore it
        limLog(pMac, LOGE,
           FL("received Deauth frame with reasonCode %d in role %d from \n"),
           reasonCode, psessionEntry->limSystemRole);
          limPrintMacAddr(pMac, pHdr->sa, LOGE);
=======
        // or un-known role. Log and ignore it
        limLog(pMac, LOG1,
           FL("received Deauth frame with reasonCode %d in role %d from "),
           reasonCode, psessionEntry->limSystemRole);
          limPrintMacAddr(pMac, pHdr->sa, LOG1);
>>>>>>> d97af3b... add prima wlan driver
=======
        // or un-known role. Log error and ignore it
        limLog(pMac, LOGE,
           FL("received Deauth frame with reasonCode %d in role %d from \n"),
           reasonCode, psessionEntry->limSystemRole);
          limPrintMacAddr(pMac, pHdr->sa, LOGE);
>>>>>>> 657b0e9... prima update

        return;
    }

    /** If we are in the middle of ReAssoc, a few things could happen:
     *  - STA is reassociating to current AP, and receives deauth from:
     *         a) current AP 
     *         b) other AP
     *  - STA is reassociating to a new AP, and receives deauth from:
     *         c) current AP
     *         d) reassoc AP
     *         e) other AP
     *
     *  The logic is: 
     *  1) If rcv deauth from an AP other than the one we're trying to
     *     reassociate with, then drop the deauth frame (case b, c, e)
     *  2) If rcv deauth from the "new" reassoc AP (case d), then restore
     *     context with previous AP and send SME_REASSOC_RSP failure.
     *  3) If rcv deauth from the reassoc AP, which is also the same
     *     AP we're currently associated with (case a), then proceed
     *     with normal deauth processing. 
     */
<<<<<<< HEAD
<<<<<<< HEAD
    if (limIsReassocInProgress(pMac,psessionEntry)) {
        if (!IS_REASSOC_BSSID(pMac,pHdr->sa,psessionEntry)) {
            PELOGE(limLog(pMac, LOGE, FL("Rcv Deauth from unknown/different AP while ReAssoc. Ignore \n"));)
=======
    if ( psessionEntry->limReAssocbssId!=NULL )
    {
        pRoamSessionEntry = peFindSessionByBssid(pMac, psessionEntry->limReAssocbssId, &roamSessionId);
    }
    if (limIsReassocInProgress(pMac,psessionEntry) || limIsReassocInProgress(pMac,pRoamSessionEntry)) {
        if (!IS_REASSOC_BSSID(pMac,pHdr->sa,psessionEntry)) {
            PELOGE(limLog(pMac, LOGE, FL("Rcv Deauth from unknown/different AP while ReAssoc. Ignore "));)
>>>>>>> d97af3b... add prima wlan driver
=======
    if (limIsReassocInProgress(pMac,psessionEntry)) {
        if (!IS_REASSOC_BSSID(pMac,pHdr->sa,psessionEntry)) {
            PELOGE(limLog(pMac, LOGE, FL("Rcv Deauth from unknown/different AP while ReAssoc. Ignore \n"));)
>>>>>>> 657b0e9... prima update
            limPrintMacAddr(pMac, pHdr->sa, LOGE);
            limPrintMacAddr(pMac, psessionEntry->limReAssocbssId, LOGE);
            return;
        }

        /** Received deauth from the new AP to which we tried to ReAssociate.
         *  Drop ReAssoc and Restore the Previous context( current connected AP).
         */
        if (!IS_CURRENT_BSSID(pMac, pHdr->sa,psessionEntry)) {
<<<<<<< HEAD
<<<<<<< HEAD
            PELOGE(limLog(pMac, LOGE, FL("received DeAuth from the New AP to which ReAssoc is sent \n"));)
=======
            PELOGE(limLog(pMac, LOGE, FL("received DeAuth from the New AP to which ReAssoc is sent "));)
>>>>>>> d97af3b... add prima wlan driver
=======
            PELOGE(limLog(pMac, LOGE, FL("received DeAuth from the New AP to which ReAssoc is sent \n"));)
>>>>>>> 657b0e9... prima update
            limPrintMacAddr(pMac, pHdr->sa, LOGE);
            limPrintMacAddr(pMac, psessionEntry->bssId, LOGE);
            limRestorePreReassocState(pMac,
                                  eSIR_SME_REASSOC_REFUSED, reasonCode,psessionEntry);
            return;
        }
    }

    
    /* If received DeAuth from AP other than the one we're trying to join with
     * nor associated with, then ignore deauth and delete Pre-auth entry.
     */
<<<<<<< HEAD
<<<<<<< HEAD
#ifdef WLAN_SOFTAP_FEATURE
    if(psessionEntry->limSystemRole != eLIM_AP_ROLE ){
#endif
        if (!IS_CURRENT_BSSID(pMac, pHdr->sa,psessionEntry)) 
        {
            PELOGE(limLog(pMac, LOGE, FL("received DeAuth from an AP other than we're trying to join. Ignore. \n"));)
            if (limSearchPreAuthList(pMac, pHdr->sa))
            {
                PELOGE(limLog(pMac, LOGE, FL("Preauth entry exist. Deleting... \n"));)
=======
=======
#ifdef WLAN_SOFTAP_FEATURE
>>>>>>> 657b0e9... prima update
    if(psessionEntry->limSystemRole != eLIM_AP_ROLE ){
#endif
        if (!IS_CURRENT_BSSID(pMac, pHdr->sa,psessionEntry)) 
        {
            PELOGE(limLog(pMac, LOGE, FL("received DeAuth from an AP other than we're trying to join. Ignore. \n"));)
            if (limSearchPreAuthList(pMac, pHdr->sa))
            {
<<<<<<< HEAD
                PELOG1(limLog(pMac, LOG1, FL("Preauth entry exist. Deleting... "));)
>>>>>>> d97af3b... add prima wlan driver
=======
                PELOGE(limLog(pMac, LOGE, FL("Preauth entry exist. Deleting... \n"));)
>>>>>>> 657b0e9... prima update
                limDeletePreAuthNode(pMac, pHdr->sa);
            }
            return;
        }
<<<<<<< HEAD
<<<<<<< HEAD
#ifdef WLAN_SOFTAP_FEATURE
    }
#endif
=======
    }

        pStaDs = dphLookupHashEntry(pMac, pHdr->sa, &aid, &psessionEntry->dph.dphHashTable);
>>>>>>> d97af3b... add prima wlan driver
=======
#ifdef WLAN_SOFTAP_FEATURE
    }
#endif
>>>>>>> 657b0e9... prima update

        // Check for pre-assoc states
        switch (psessionEntry->limSystemRole)
        {
            case eLIM_STA_ROLE:
            case eLIM_BT_AMP_STA_ROLE:
                switch (psessionEntry->limMlmState)
                {
                    case eLIM_MLM_WT_AUTH_FRAME2_STATE:
                        /**
                         * AP sent Deauth frame while waiting
                         * for Auth frame2. Report Auth failure
                         * to SME.
                         */

                        // Log error
                        PELOG1(limLog(pMac, LOG1,
                           FL("received Deauth frame with failure code %d from "),
                           reasonCode);
                        limPrintMacAddr(pMac, pHdr->sa, LOG1);)

                        limRestoreFromAuthState(pMac, eSIR_SME_DEAUTH_WHILE_JOIN,
                                                reasonCode,psessionEntry);

                        return;

                    case eLIM_MLM_AUTHENTICATED_STATE:
                        /// Issue Deauth Indication to SME.
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
                        palCopyMemory( pMac->hHdd,
                               (tANI_U8 *) &mlmDeauthInd.peerMacAddr,
                               pHdr->sa,
                               sizeof(tSirMacAddr));
<<<<<<< HEAD
=======
                        vos_mem_copy((tANI_U8 *) &mlmDeauthInd.peerMacAddr,
                                     pHdr->sa,
                                     sizeof(tSirMacAddr));
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
                        mlmDeauthInd.reasonCode = reasonCode;

                        psessionEntry->limMlmState = eLIM_MLM_IDLE_STATE;
                        MTRACE(macTrace(pMac, TRACE_CODE_MLM_STATE, psessionEntry->peSessionId, psessionEntry->limMlmState));

                        
                        limPostSmeMessage(pMac,
                                          LIM_MLM_DEAUTH_IND,
                                          (tANI_U32 *) &mlmDeauthInd);
                        return;

                    case eLIM_MLM_WT_ASSOC_RSP_STATE:
                        /**
                         * AP may have 'aged-out' our Pre-auth
                         * context. Delete local pre-auth context
                         * if any and issue ASSOC_CNF to SME.
                         */
                        if (limSearchPreAuthList(pMac, pHdr->sa))
                            limDeletePreAuthNode(pMac, pHdr->sa);

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

                        mlmAssocCnf.resultCode = eSIR_SME_DEAUTH_WHILE_JOIN;
                        mlmAssocCnf.protStatusCode = reasonCode;
                        
                        /* PE session Id*/
                        mlmAssocCnf.sessionId = psessionEntry->peSessionId;

                        psessionEntry->limMlmState =
                                   psessionEntry->limPrevMlmState;
                        MTRACE(macTrace(pMac, TRACE_CODE_MLM_STATE, psessionEntry->peSessionId, psessionEntry->limMlmState));

                        // Deactive Association response timeout
                        limDeactivateAndChangeTimer(
                                     pMac,
                                     eLIM_ASSOC_FAIL_TIMER);

                        limPostSmeMessage(
                            pMac,
                            LIM_MLM_ASSOC_CNF,
                            (tANI_U32 *) &mlmAssocCnf);
                        
                        return;

<<<<<<< HEAD
<<<<<<< HEAD
                    case eLIM_MLM_IDLE_STATE:
                    case eLIM_MLM_LINK_ESTABLISHED_STATE:
                        /**
                         * This could be Deauthentication frame from
                         * a BSS with which pre-authentication was
                         * performed. Delete Pre-auth entry if found.
                         */
                        if (limSearchPreAuthList(pMac, pHdr->sa))
                           limDeletePreAuthNode(pMac, pHdr->sa);

=======
                    case eLIM_MLM_WT_ADD_STA_RSP_STATE:
                         psessionEntry->fDeauthReceived = true;
                         PELOGW(limLog(pMac, LOGW,
                            FL("Received Deauth frame with Reason Code %d from Peer"),
                                  reasonCode);
                         limPrintMacAddr(pMac, pHdr->sa, LOGW);)
                         return ;

=======
>>>>>>> 657b0e9... prima update
                    case eLIM_MLM_IDLE_STATE:
                    case eLIM_MLM_LINK_ESTABLISHED_STATE:
                        /**
                         * This could be Deauthentication frame from
                         * a BSS with which pre-authentication was
                         * performed. Delete Pre-auth entry if found.
                         */
                        if (limSearchPreAuthList(pMac, pHdr->sa))
                           limDeletePreAuthNode(pMac, pHdr->sa);

<<<<<<< HEAD
                            limDeleteTDLSPeers(pMac, psessionEntry);
#endif
                           /**
                            * This could be Deauthentication frame from
                            * a BSS with which pre-authentication was
                            * performed. Delete Pre-auth entry if found.
                            */
                           if (limSearchPreAuthList(pMac, pHdr->sa))
                              limDeletePreAuthNode(pMac, pHdr->sa);
#ifdef FEATURE_WLAN_TDLS
                        }
#endif
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
                        break;

                    case eLIM_MLM_WT_REASSOC_RSP_STATE:
                        break;

                    case eLIM_MLM_WT_FT_REASSOC_RSP_STATE:
                        PELOGE(limLog(pMac, LOGE,
                           FL("received Deauth frame in FT state %X with reasonCode=%d from "),
                           psessionEntry->limMlmState, reasonCode);)
                        limPrintMacAddr(pMac, pHdr->sa, LOGE);
                        break;

                    default:
                        PELOG1(limLog(pMac, LOG1,
                           FL("received Deauth frame in state %X with reasonCode=%d from "),
                           psessionEntry->limMlmState, reasonCode);)
                        limPrintMacAddr(pMac, pHdr->sa, LOG1);
                        return;
                }
                break;

            case eLIM_STA_IN_IBSS_ROLE:
                break;

<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
#ifdef WLAN_SOFTAP_FEATURE
            case eLIM_AP_ROLE:
                break;
#endif 

            default: // eLIM_AP_ROLE or eLIM_BT_AMP_AP_ROLE

#if (WNI_POLARIS_FW_PRODUCT == AP)
                /// Check if there exists pre-auth context for this STA
                if (limSearchPreAuthList(pMac, pHdr->sa) == NULL)
                {
                    /**
                     * Received Deauthentication from a STA that is neither
                     * Associated nor Pre-authenticated. Log error,
                     * and ignore Deauthentication frame.
                     */
                    PELOG1(limLog(pMac, LOG1,
                       FL("received Deauth frame from peer that does not have context, addr "));
                    limPrintMacAddr(pMac, pHdr->sa, LOG1);)
                }
                else
                {
                    /// Delete STA from pre-auth STA list
                    limDeletePreAuthNode(pMac,
                                         pHdr->sa);

                    palCopyMemory( pMac->hHdd,
                           (tANI_U8 *) &mlmDeauthInd.peerMacAddr,
                           pHdr->sa,
                           sizeof(tSirMacAddr));
                    mlmDeauthInd.reasonCode = reasonCode;
                    mlmDeauthInd.aid        = 0;

                    limPostSmeMessage(pMac,
                                      LIM_MLM_DEAUTH_IND,
                                      (tANI_U32 *) &mlmDeauthInd);
                }
#endif
<<<<<<< HEAD
=======
            case eLIM_AP_ROLE:
                break;

            default: // eLIM_AP_ROLE or eLIM_BT_AMP_AP_ROLE

>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update

                return;
        } // end switch (pMac->lim.gLimSystemRole)


        
    /**
     * Extract 'associated' context for STA, if any.
     * This is maintained by DPH and created by LIM.
     */
<<<<<<< HEAD
<<<<<<< HEAD
    if( (pStaDs = dphLookupHashEntry(pMac, pHdr->sa, &aid, &psessionEntry->dph.dphHashTable)) == NULL)
=======
    if (NULL == pStaDs)
>>>>>>> d97af3b... add prima wlan driver
=======
    if( (pStaDs = dphLookupHashEntry(pMac, pHdr->sa, &aid, &psessionEntry->dph.dphHashTable)) == NULL)
>>>>>>> 657b0e9... prima update
        return;


    if ((pStaDs->mlmStaContext.mlmState == eLIM_MLM_WT_DEL_STA_RSP_STATE) ||
        (pStaDs->mlmStaContext.mlmState == eLIM_MLM_WT_DEL_BSS_RSP_STATE))
    {
        /**
         * Already in the process of deleting context for the peer
         * and received Deauthentication frame. Log and Ignore.
         */
        PELOG1(limLog(pMac, LOG1,
           FL("received Deauth frame from peer that is in state %X, addr "),
           pStaDs->mlmStaContext.mlmState);
        limPrintMacAddr(pMac, pHdr->sa, LOG1);)
        return;
    } 
    pStaDs->mlmStaContext.disassocReason = (tSirMacReasonCodes)reasonCode;
    pStaDs->mlmStaContext.cleanupTrigger = eLIM_PEER_ENTITY_DEAUTH;

    /// Issue Deauth Indication to SME.
<<<<<<< HEAD
<<<<<<< HEAD
    palCopyMemory( pMac->hHdd, (tANI_U8 *) &mlmDeauthInd.peerMacAddr,
                  pStaDs->staAddr,
                  sizeof(tSirMacAddr));
#if (WNI_POLARIS_FW_PRODUCT == AP)
    mlmDeauthInd.aid           = pStaDs->assocId;
#endif
=======
    vos_mem_copy((tANI_U8 *) &mlmDeauthInd.peerMacAddr,
                  pStaDs->staAddr,
                  sizeof(tSirMacAddr));
>>>>>>> d97af3b... add prima wlan driver
=======
    palCopyMemory( pMac->hHdd, (tANI_U8 *) &mlmDeauthInd.peerMacAddr,
                  pStaDs->staAddr,
                  sizeof(tSirMacAddr));
#if (WNI_POLARIS_FW_PRODUCT == AP)
    mlmDeauthInd.aid           = pStaDs->assocId;
#endif
>>>>>>> 657b0e9... prima update
    mlmDeauthInd.reasonCode    = (tANI_U8) pStaDs->mlmStaContext.disassocReason;
    mlmDeauthInd.deauthTrigger = eLIM_PEER_ENTITY_DEAUTH;


    /* 
     * If we're in the middle of ReAssoc and received deauth from 
     * the ReAssoc AP, then notify SME by sending REASSOC_RSP with 
     * failure result code. SME will post the disconnect to the
     * supplicant and the latter would start a fresh assoc.
     */
    if (limIsReassocInProgress(pMac,psessionEntry)) {
        /**
         * AP may have 'aged-out' our Pre-auth
         * context. Delete local pre-auth context
         * if any and issue REASSOC_CNF to SME.
         */
        if (limSearchPreAuthList(pMac, pHdr->sa))
            limDeletePreAuthNode(pMac, pHdr->sa);

        if (psessionEntry->limAssocResponseData) {
<<<<<<< HEAD
<<<<<<< HEAD
            palFreeMemory(pMac->hHdd, psessionEntry->limAssocResponseData);
            psessionEntry->limAssocResponseData = NULL;                            
        }

        PELOGE(limLog(pMac, LOGE, FL("Rcv Deauth from ReAssoc AP. Issue REASSOC_CNF. \n"));)
=======
            vos_mem_free(psessionEntry->limAssocResponseData);
            psessionEntry->limAssocResponseData = NULL;                            
        }

        PELOGE(limLog(pMac, LOGE, FL("Rcv Deauth from ReAssoc AP. Issue REASSOC_CNF. "));)
>>>>>>> d97af3b... add prima wlan driver
=======
            palFreeMemory(pMac->hHdd, psessionEntry->limAssocResponseData);
            psessionEntry->limAssocResponseData = NULL;                            
        }

        PELOGE(limLog(pMac, LOGE, FL("Rcv Deauth from ReAssoc AP. Issue REASSOC_CNF. \n"));)
>>>>>>> 657b0e9... prima update
       /*
        * TODO: Instead of overloading eSIR_SME_FT_REASSOC_TIMEOUT_FAILURE
        * it would have been good to define/use a different failure type.
        * Using eSIR_SME_FT_REASSOC_FAILURE does not seem to clean-up
        * properly and we end up seeing "transmit queue timeout".
        */
       limPostReassocFailure(pMac, eSIR_SME_FT_REASSOC_TIMEOUT_FAILURE,
               eSIR_MAC_UNSPEC_FAILURE_STATUS, psessionEntry);
        return;
    }
<<<<<<< HEAD
<<<<<<< HEAD

=======
    /* reset the deauthMsgCnt here since we are able to Process
     * the deauth frame and sending up the indication as well */
    if(pMac->lim.deauthMsgCnt != 0)
    {
        pMac->lim.deauthMsgCnt = 0;
    }
>>>>>>> d97af3b... add prima wlan driver
=======

>>>>>>> 657b0e9... prima update
    /// Deauthentication from peer MAC entity
    limPostSmeMessage(pMac, LIM_MLM_DEAUTH_IND, (tANI_U32 *) &mlmDeauthInd);

    // send eWNI_SME_DEAUTH_IND to SME  
    limSendSmeDeauthInd(pMac, pStaDs, psessionEntry);
    return;

} /*** end limProcessDeauthFrame() ***/

