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
/*
 * Airgo Networks, Inc proprietary. All rights reserved.
=======

/*
>>>>>>> d97af3b... add prima wlan driver
=======
/*
 * Airgo Networks, Inc proprietary. All rights reserved.
>>>>>>> 657b0e9... prima update
 * This file limProcessMlmRspMessages.cc contains the code
 * for processing response messages from MLM state machine.
 * Author:        Chandra Modumudi
 * Date:          02/11/02
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
=======
#include "wniCfgSta.h"
>>>>>>> d97af3b... add prima wlan driver
=======
#ifdef ANI_PRODUCT_TYPE_AP
#include "wniCfgAp.h"
#else
#include "wniCfgSta.h"
#endif
>>>>>>> 657b0e9... prima update
#include "cfgApi.h"
#include "sirApi.h"
#include "schApi.h"
#include "utilsApi.h"
#include "limUtils.h"
#include "limAssocUtils.h"
#include "limSecurityUtils.h"
#include "limSerDesUtils.h"
#include "limTimerUtils.h"
#include "limSendMessages.h"
#include "limAdmitControl.h"
#include "limSendMessages.h"
#include "limIbssPeerMgmt.h"
#include "limSession.h"
#include "limSessionUtils.h"
#if defined WLAN_FEATURE_VOWIFI
#include "rrmApi.h"
#endif
#if defined WLAN_FEATURE_VOWIFI_11R
#include <limFT.h>
#endif
#include "wlan_qct_wda.h"

static void limHandleSmeJoinResult(tpAniSirGlobal, tSirResultCodes, tANI_U16,tpPESession);
static void limHandleSmeReaasocResult(tpAniSirGlobal, tSirResultCodes, tANI_U16, tpPESession);
void limProcessMlmScanCnf(tpAniSirGlobal, tANI_U32 *);
#ifdef FEATURE_OEM_DATA_SUPPORT
void limProcessMlmOemDataReqCnf(tpAniSirGlobal, tANI_U32 *);
#endif
void limProcessMlmJoinCnf(tpAniSirGlobal, tANI_U32 *);
void limProcessMlmAuthCnf(tpAniSirGlobal, tANI_U32 *);
void limProcessMlmStartCnf(tpAniSirGlobal, tANI_U32 *);
void limProcessMlmAuthInd(tpAniSirGlobal, tANI_U32 *);
void limProcessMlmAssocInd(tpAniSirGlobal, tANI_U32 *);
void limProcessMlmAssocCnf(tpAniSirGlobal, tANI_U32 *);
void limProcessMlmReassocCnf(tpAniSirGlobal, tANI_U32 *);
void limProcessMlmReassocInd(tpAniSirGlobal, tANI_U32 *);
void limProcessMlmSetKeysCnf(tpAniSirGlobal, tANI_U32 *);
void limProcessMlmDisassocInd(tpAniSirGlobal, tANI_U32 *);
void limProcessMlmDisassocCnf(tpAniSirGlobal, tANI_U32 *);
void limProcessMlmDeauthInd(tpAniSirGlobal, tANI_U32 *);
void limProcessMlmDeauthCnf(tpAniSirGlobal, tANI_U32 *);
void limProcessMlmPurgeStaInd(tpAniSirGlobal, tANI_U32 *);
void limProcessMlmAddBACnf(tpAniSirGlobal, tANI_U32 *);
void limProcessMlmDelBACnf(tpAniSirGlobal, tANI_U32 *);
void limProcessMlmRemoveKeyCnf(tpAniSirGlobal pMac, tANI_U32 * pMsgBuf);
static void  limHandleDelBssInReAssocContext(tpAniSirGlobal pMac, tpDphHashNode pStaDs,tpPESession psessionEntry);
void limGetSessionInfo(tpAniSirGlobal pMac, tANI_U8 *, tANI_U8 *, tANI_U16 *);
static void
limProcessBtampAddBssRsp( tpAniSirGlobal pMac, tpSirMsgQ limMsgQ ,tpPESession psessionEntry);
/**
 * limProcessMlmRspMessages()
 *
 *FUNCTION:
 * This function is called to processes various MLM response (CNF/IND
 * messages from MLM State machine.
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 *
 *NOTE:
 *
 * @param pMac       Pointer to Global MAC structure
 * @param  msgType   Indicates the MLM message type
 * @param  *pMsgBuf  A pointer to the MLM message buffer
 *
 * @return None
 */
void
limProcessMlmRspMessages(tpAniSirGlobal pMac, tANI_U32 msgType, tANI_U32 *pMsgBuf)
{

   if(pMsgBuf == NULL)
    {
<<<<<<< HEAD
<<<<<<< HEAD
           PELOGE(limLog(pMac, LOGE,FL("Buffer is Pointing to NULL\n"));)
=======
           PELOGE(limLog(pMac, LOGE,FL("Buffer is Pointing to NULL"));)
>>>>>>> d97af3b... add prima wlan driver
=======
           PELOGE(limLog(pMac, LOGE,FL("Buffer is Pointing to NULL\n"));)
>>>>>>> 657b0e9... prima update
           return;
    }
    switch (msgType)
    {
        case LIM_MLM_SCAN_CNF:
            limProcessMlmScanCnf(pMac, pMsgBuf);
            break;

#ifdef FEATURE_OEM_DATA_SUPPORT
        case LIM_MLM_OEM_DATA_CNF:
            limProcessMlmOemDataReqCnf(pMac, pMsgBuf);
            break;
#endif

        case LIM_MLM_AUTH_CNF:
            limProcessMlmAuthCnf(pMac, pMsgBuf);
            break;
        case LIM_MLM_AUTH_IND:
            limProcessMlmAuthInd(pMac, pMsgBuf);
            break;
        case LIM_MLM_ASSOC_CNF:
            limProcessMlmAssocCnf(pMac, pMsgBuf);
            break;
        case LIM_MLM_START_CNF:
            limProcessMlmStartCnf(pMac, pMsgBuf);
            break;
        case LIM_MLM_JOIN_CNF:
            limProcessMlmJoinCnf(pMac, pMsgBuf);
            break;
        case LIM_MLM_ASSOC_IND:
             limProcessMlmAssocInd(pMac, pMsgBuf);
            break;
        case LIM_MLM_REASSOC_CNF:
            limProcessMlmReassocCnf(pMac, pMsgBuf);
            break;
        case LIM_MLM_REASSOC_IND:
           limProcessMlmReassocInd(pMac, pMsgBuf);
           break;
        case LIM_MLM_DISASSOC_CNF:
            limProcessMlmDisassocCnf(pMac, pMsgBuf);
            break;
        case LIM_MLM_DISASSOC_IND:
            limProcessMlmDisassocInd(pMac, pMsgBuf);
            break;
        case LIM_MLM_PURGE_STA_IND:
            limProcessMlmPurgeStaInd(pMac, pMsgBuf);
            break;
        case LIM_MLM_DEAUTH_CNF:
            limProcessMlmDeauthCnf(pMac, pMsgBuf);
            break;
        case LIM_MLM_DEAUTH_IND:
            limProcessMlmDeauthInd(pMac, pMsgBuf);
            break;
        case LIM_MLM_SETKEYS_CNF:
            limProcessMlmSetKeysCnf(pMac, pMsgBuf);
            break;
        case LIM_MLM_REMOVEKEY_CNF:
            limProcessMlmRemoveKeyCnf(pMac, pMsgBuf);
            break;
        case LIM_MLM_TSPEC_CNF:
            break;
        case LIM_MLM_ADDBA_CNF:
            limProcessMlmAddBACnf( pMac, pMsgBuf );
            break;
        case LIM_MLM_DELBA_CNF:
            limProcessMlmDelBACnf( pMac, pMsgBuf );
            break;
        default:
            break;
    } // switch (msgType)
    return;
} /*** end limProcessMlmRspMessages() ***/

/**
 * limProcessMlmScanCnf()
 *
 *FUNCTION:
 * This function is called to processes MLM_SCAN_CNF
 * message from MLM State machine.
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 *
 *NOTE:
 *
 * @param pMac       Pointer to Global MAC structure
 * @param pMsgBuf    A pointer to the MLM message buffer
 *
 * @return None
 */
void
limProcessMlmScanCnf(tpAniSirGlobal pMac, tANI_U32 *pMsgBuf)
{
    switch(pMac->lim.gLimSmeState)
    {
        case eLIM_SME_WT_SCAN_STATE:
        //case eLIM_SME_LINK_EST_WT_SCAN_STATE:  //TO SUPPORT BT-AMP
        //case eLIM_SME_NORMAL_CHANNEL_SCAN_STATE:   //TO SUPPORT BT-AMP
            pMac->lim.gLimSmeState = pMac->lim.gLimPrevSmeState;
            MTRACE(macTrace(pMac, TRACE_CODE_SME_STATE, NO_SESSION, pMac->lim.gLimSmeState));
            pMac->lim.gLimSystemInScanLearnMode = 0;
            break;
        default:
            /**
             * Should not have received scan confirm
             * from MLM in other states.
             * Log error
             */
            PELOGE(limLog(pMac, LOGE,
<<<<<<< HEAD
<<<<<<< HEAD
               FL("received unexpected MLM_SCAN_CNF in state %X\n"),
=======
               FL("received unexpected MLM_SCAN_CNF in state %X"),
>>>>>>> d97af3b... add prima wlan driver
=======
               FL("received unexpected MLM_SCAN_CNF in state %X\n"),
>>>>>>> 657b0e9... prima update
               pMac->lim.gLimSmeState);)
            return;
    }

    /// Process received scan confirm
    /// Increment length of cached scan results
    pMac->lim.gLimSmeScanResultLength +=
                    ((tLimMlmScanCnf *) pMsgBuf)->scanResultLength;
    if ((pMac->lim.gLimRspReqd) || pMac->lim.gLimReportBackgroundScanResults)
    {
        tANI_U16    scanRspLen = 0;
        /// Need to send response to Host
        pMac->lim.gLimRspReqd = false;
        if ((((tLimMlmScanCnf *) pMsgBuf)->resultCode ==
                                                eSIR_SME_SUCCESS) ||
            pMac->lim.gLimSmeScanResultLength)
        {
                    scanRspLen = sizeof(tSirSmeScanRsp) +
                                 pMac->lim.gLimSmeScanResultLength -
                                 sizeof(tSirBssDescription);
        }
        else
        {
            scanRspLen = sizeof(tSirSmeScanRsp);
        }
       if(pMac->lim.gLimReportBackgroundScanResults)
        {
            pMac->lim.gLimBackgroundScanTerminate = TRUE;
        }
        if (pMac->lim.gLimSmeScanResultLength == 0)
        {
            limSendSmeScanRsp(pMac, scanRspLen, eSIR_SME_SUCCESS, pMac->lim.gSmeSessionId, pMac->lim.gTransactionId);
        }
        else
        {
            limSendSmeScanRsp(pMac, scanRspLen,
                              eSIR_SME_SUCCESS,pMac->lim.gSmeSessionId, pMac->lim.gTransactionId);
        }
    } // if (pMac->lim.gLimRspReqd)
    //check to see whether we need to run bgScan timer
    if(pMac->lim.gLimBackgroundScanTerminate == FALSE)
    {
        if (tx_timer_activate(
            &pMac->lim.limTimers.gLimBackgroundScanTimer) != TX_SUCCESS)
        {
            /// Could not activate background scan timer.
            // Log error
            limLog(pMac, LOGP,
<<<<<<< HEAD
<<<<<<< HEAD
            FL("could not activate background scan timer\n"));
=======
            FL("could not activate background scan timer"));
>>>>>>> d97af3b... add prima wlan driver
=======
            FL("could not activate background scan timer\n"));
>>>>>>> 657b0e9... prima update
            pMac->lim.gLimBackgroundScanStarted = FALSE;
        }
        else
        {
            pMac->lim.gLimBackgroundScanStarted = TRUE;
        }
    }
} /*** end limProcessMlmScanCnf() ***/

#ifdef FEATURE_OEM_DATA_SUPPORT

/**
 * limProcessMlmOemDataReqCnf()
 *
 *FUNCTION:
 * This function is called to processes LIM_MLM_OEM_DATA_REQ_CNF
 * message from MLM State machine.
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 *
 *NOTE:
 *
 * @param pMac       Pointer to Global MAC structure
 * @param pMsgBuf    A pointer to the MLM message buffer
 *
 * @return None
 */

void limProcessMlmOemDataReqCnf(tpAniSirGlobal pMac, tANI_U32 *pMsgBuf)
{
    tLimMlmOemDataRsp*    measRsp;

    tSirResultCodes resultCode = eSIR_SME_SUCCESS;

    measRsp = (tLimMlmOemDataRsp*)(pMsgBuf);

    //Now send the meas confirm message to the sme
    limSendSmeOemDataRsp(pMac, (tANI_U32*)measRsp, resultCode);

    //Dont free the memory here. It will be freed up by the callee

    return;
}
#endif

/**
 * limProcessMlmStartCnf()
 *
 *FUNCTION:
 * This function is called to processes MLM_START_CNF
 * message from MLM State machine.
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 *
 *NOTE:
 *
 * @param pMac       Pointer to Global MAC structure
 * @param pMsgBuf    A pointer to the MLM message buffer
 *
 * @return None
 */
void
limProcessMlmStartCnf(tpAniSirGlobal pMac, tANI_U32 *pMsgBuf)
{
    tpPESession         psessionEntry = NULL;
    tLimMlmStartCnf     *pLimMlmStartCnf;
    tANI_U8             smesessionId;
    tANI_U16            smetransactionId;

    if(pMsgBuf == NULL)
    {
<<<<<<< HEAD
<<<<<<< HEAD
           PELOGE(limLog(pMac, LOGE,FL("Buffer is Pointing to NULL\n"));)
=======
           PELOGE(limLog(pMac, LOGE,FL("Buffer is Pointing to NULL"));)
>>>>>>> d97af3b... add prima wlan driver
=======
           PELOGE(limLog(pMac, LOGE,FL("Buffer is Pointing to NULL\n"));)
>>>>>>> 657b0e9... prima update
           return;
    }
    pLimMlmStartCnf = (tLimMlmStartCnf*)pMsgBuf;
    if((psessionEntry = peFindSessionBySessionId(pMac,pLimMlmStartCnf->sessionId))==NULL)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        PELOGE(limLog(pMac, LOGE,FL("Session does Not exist with given sessionId \n"));)
=======
        PELOGE(limLog(pMac, LOGE,FL("Session does Not exist with given sessionId "));)
>>>>>>> d97af3b... add prima wlan driver
=======
        PELOGE(limLog(pMac, LOGE,FL("Session does Not exist with given sessionId \n"));)
>>>>>>> 657b0e9... prima update
        return;
    }
   smesessionId = psessionEntry->smeSessionId;
   smetransactionId = psessionEntry->transactionId;

    if (psessionEntry->limSmeState != eLIM_SME_WT_START_BSS_STATE)
    {
        /**
         * Should not have received Start confirm from MLM
         * in other states.
         * Log error
         */
        PELOGE(limLog(pMac, LOGE,
<<<<<<< HEAD
<<<<<<< HEAD
           FL("received unexpected MLM_START_CNF in state %X\n"),
=======
           FL("received unexpected MLM_START_CNF in state %X"),
>>>>>>> d97af3b... add prima wlan driver
=======
           FL("received unexpected MLM_START_CNF in state %X\n"),
>>>>>>> 657b0e9... prima update
           psessionEntry->limSmeState);)
        return;
    }
    if (((tLimMlmStartCnf *) pMsgBuf)->resultCode ==
                                            eSIR_SME_SUCCESS)
    {

        /**
         * Update global SME state so that Beacon Generation
         * module starts writing Beacon frames into TFP's
         * Beacon file register.
         */
        psessionEntry->limSmeState = eLIM_SME_NORMAL_STATE;
        MTRACE(macTrace(pMac, TRACE_CODE_SME_STATE, psessionEntry->peSessionId, psessionEntry->limSmeState));
        if(psessionEntry->bssType == eSIR_BTAMP_STA_MODE)
        {
<<<<<<< HEAD
<<<<<<< HEAD
             limLog(pMac, LOG1, FL("*** Started BSS in BT_AMP STA SIDE***\n"));
        }
        else if(psessionEntry->bssType == eSIR_BTAMP_AP_MODE)
        {
             limLog(pMac, LOG1, FL("*** Started BSS in BT_AMP AP SIDE***\n"));
        }
#ifdef WLAN_SOFTAP_FEATURE
        else if(psessionEntry->bssType == eSIR_INFRA_AP_MODE)
        {
             limLog(pMac, LOG1, FL("*** Started BSS in INFRA AP SIDE***\n"));
        }
#endif
        else
            PELOG1(limLog(pMac, LOG1, FL("*** Started BSS ***\n"));)
=======
             limLog(pMac, LOG1, FL("*** Started BSS in BT_AMP STA SIDE***"));
=======
             limLog(pMac, LOG1, FL("*** Started BSS in BT_AMP STA SIDE***\n"));
>>>>>>> 657b0e9... prima update
        }
        else if(psessionEntry->bssType == eSIR_BTAMP_AP_MODE)
        {
             limLog(pMac, LOG1, FL("*** Started BSS in BT_AMP AP SIDE***\n"));
        }
#ifdef WLAN_SOFTAP_FEATURE
        else if(psessionEntry->bssType == eSIR_INFRA_AP_MODE)
        {
             limLog(pMac, LOG1, FL("*** Started BSS in INFRA AP SIDE***\n"));
        }
#endif
        else
<<<<<<< HEAD
            PELOG1(limLog(pMac, LOG1, FL("*** Started BSS ***"));)
>>>>>>> d97af3b... add prima wlan driver
=======
            PELOG1(limLog(pMac, LOG1, FL("*** Started BSS ***\n"));)
>>>>>>> 657b0e9... prima update
    }
    else
    {
        /// Start BSS is a failure
        peDeleteSession(pMac,psessionEntry);
        psessionEntry = NULL;
    }
    /// Send response to Host
    limSendSmeStartBssRsp(pMac, eWNI_SME_START_BSS_RSP,
                          ((tLimMlmStartCnf *) pMsgBuf)->resultCode,psessionEntry,
                          smesessionId,smetransactionId);
<<<<<<< HEAD
<<<<<<< HEAD
#ifdef WLAN_SOFTAP_FEATURE
=======
>>>>>>> d97af3b... add prima wlan driver
=======
#ifdef WLAN_SOFTAP_FEATURE
>>>>>>> 657b0e9... prima update
    if (((tLimMlmStartCnf *) pMsgBuf)->resultCode == eSIR_SME_SUCCESS)
    {
        //Configure beacon and send beacons to HAL
        limSendBeaconInd(pMac, psessionEntry);
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

 /*** end limProcessMlmStartCnf() ***/

/**
 * limProcessMlmJoinCnf()
 *
 *FUNCTION:
 * This function is called to processes MLM_JOIN_CNF
 * message from MLM State machine.
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 *
 *NOTE:
 *
 * @param pMac       Pointer to Global MAC structure
 * @param pMsgBuf    A pointer to the MLM message buffer
 *
 * @return None
 */
void
limProcessMlmJoinCnf(tpAniSirGlobal pMac, tANI_U32 *pMsgBuf)
{
    tSirResultCodes resultCode;
    tLimMlmJoinCnf      *pLimMlmJoinCnf;
    tpPESession         psessionEntry;
     pLimMlmJoinCnf = (tLimMlmJoinCnf*)pMsgBuf;
    if( (psessionEntry = peFindSessionBySessionId(pMac,pLimMlmJoinCnf->sessionId))== NULL)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        PELOGE(limLog(pMac, LOGE,FL("Session does not exist for given sessionId\n"));)
=======
        PELOGE(limLog(pMac, LOGE,FL("Session does not exist for given sessionId"));)
>>>>>>> d97af3b... add prima wlan driver
=======
        PELOGE(limLog(pMac, LOGE,FL("Session does not exist for given sessionId\n"));)
>>>>>>> 657b0e9... prima update
        return;
    }

    if (psessionEntry->limSmeState!= eLIM_SME_WT_JOIN_STATE)
    {
        PELOGE(limLog(pMac, LOGE,
<<<<<<< HEAD
<<<<<<< HEAD
               FL("received unexpected MLM_JOIN_CNF in state %X\n"),
=======
               FL("received unexpected MLM_JOIN_CNF in state %X"),
>>>>>>> d97af3b... add prima wlan driver
=======
               FL("received unexpected MLM_JOIN_CNF in state %X\n"),
>>>>>>> 657b0e9... prima update
               psessionEntry->limSmeState);)
         return;
    }

    resultCode = ((tLimMlmJoinCnf *) pMsgBuf)->resultCode ;
    /// Process Join confirm from MLM
    if (resultCode ==  eSIR_SME_SUCCESS)
    {
            PELOG1(limLog(pMac, LOG1, FL("*** Joined ESS ***"));)
            //Setup hardware upfront
           //Done: 7-27-2009. JIM_FIX_ME   sessionize the following function
            if(limStaSendAddBssPreAssoc( pMac, false, psessionEntry) == eSIR_SUCCESS)
                return;
            else
                resultCode = eSIR_SME_REFUSED;
    }
    {
        /// Join failure
        psessionEntry->limSmeState = eLIM_SME_JOIN_FAILURE_STATE;
        MTRACE(macTrace(pMac, TRACE_CODE_SME_STATE, psessionEntry->peSessionId, psessionEntry->limSmeState));
        /// Send Join response to Host
        limHandleSmeJoinResult(pMac, resultCode, ((tLimMlmJoinCnf *) pMsgBuf)->protStatusCode, psessionEntry );
    }
} /*** end limProcessMlmJoinCnf() ***/

/**
 * limProcessMlmAuthCnf()
 *
 *FUNCTION:
 * This function is called to processes MLM_AUTH_CNF
 * message from MLM State machine.
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 *
 *NOTE:
 *
 * @param pMac       Pointer to Global MAC structure
 * @param pMsgBuf    A pointer to the MLM message buffer
 *
 * @return None
 */
void
limProcessMlmAuthCnf(tpAniSirGlobal pMac, tANI_U32 *pMsgBuf)
{
    tANI_U16                caps;
    tANI_U32                val;
    tAniAuthType       cfgAuthType, authMode;
    tLimMlmAuthReq     *pMlmAuthReq;
    tLimMlmAssocReq    *pMlmAssocReq;
    tLimMlmAuthCnf     *pMlmAuthCnf;
    tpPESession     psessionEntry;
    tANI_U32        teleBcnEn = 0;
//    tANI_U8         sessionId;

    if(pMsgBuf == NULL)
    {
<<<<<<< HEAD
<<<<<<< HEAD
           PELOGE(limLog(pMac, LOGE,FL("Buffer is Pointing to NULL\n"));)
=======
           PELOGE(limLog(pMac, LOGE,FL("Buffer is Pointing to NULL"));)
>>>>>>> d97af3b... add prima wlan driver
=======
           PELOGE(limLog(pMac, LOGE,FL("Buffer is Pointing to NULL\n"));)
>>>>>>> 657b0e9... prima update
           return;
    }
    pMlmAuthCnf = (tLimMlmAuthCnf*)pMsgBuf;
    if((psessionEntry = peFindSessionBySessionId(pMac,pMlmAuthCnf->sessionId))== NULL)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        PELOGE(limLog(pMac, LOGE, FL("session does not exist for given sessionId\n"));)
=======
        PELOGE(limLog(pMac, LOGE, FL("session does not exist for given sessionId"));)
>>>>>>> d97af3b... add prima wlan driver
=======
        PELOGE(limLog(pMac, LOGE, FL("session does not exist for given sessionId\n"));)
>>>>>>> 657b0e9... prima update
        return;
    }

    if (((psessionEntry->limSmeState != eLIM_SME_WT_AUTH_STATE) &&
         (psessionEntry->limSmeState != eLIM_SME_WT_PRE_AUTH_STATE)) ||
        (psessionEntry->limSystemRole == eLIM_AP_ROLE)|| (psessionEntry->limSystemRole == eLIM_BT_AMP_AP_ROLE))
    {
        /**
         * Should not have received AUTH confirm
         * from MLM in other states or on AP.
         * Log error
         */
        PELOGE(limLog(pMac, LOGE,
<<<<<<< HEAD
<<<<<<< HEAD
               FL("received unexpected MLM_AUTH_CNF in state %X\n"),
=======
               FL("received unexpected MLM_AUTH_CNF in state %X"),
>>>>>>> d97af3b... add prima wlan driver
=======
               FL("received unexpected MLM_AUTH_CNF in state %X\n"),
>>>>>>> 657b0e9... prima update
               psessionEntry->limSmeState);)
        return;
    }
    /// Process AUTH confirm from MLM
    if (((tLimMlmAuthCnf *) pMsgBuf)->resultCode != eSIR_SME_SUCCESS)
    {
        if (psessionEntry->limSmeState == eLIM_SME_WT_AUTH_STATE)
                {
            if (wlan_cfgGetInt(pMac, WNI_CFG_AUTHENTICATION_TYPE,
                          (tANI_U32 *) &cfgAuthType) != eSIR_SUCCESS)
            {
                /**
                 * Could not get AuthType value from CFG.
                 * Log error.
                 */
                limLog(pMac, LOGP,
<<<<<<< HEAD
<<<<<<< HEAD
                       FL("could not retrieve AuthType value\n"));
=======
                       FL("could not retrieve AuthType value"));
>>>>>>> d97af3b... add prima wlan driver
=======
                       FL("could not retrieve AuthType value\n"));
>>>>>>> 657b0e9... prima update
            }
                }
        else
            cfgAuthType = pMac->lim.gLimPreAuthType;
        
        if ((cfgAuthType == eSIR_AUTO_SWITCH) &&
                (((tLimMlmAuthCnf *) pMsgBuf)->authType == eSIR_OPEN_SYSTEM)
                && (eSIR_MAC_AUTH_ALGO_NOT_SUPPORTED_STATUS == ((tLimMlmAuthCnf *) pMsgBuf)->protStatusCode))
        {
            /**
             * When Open authentication fails with reason code "13" and
             * authType set to 'auto switch', Try with Shared Authentication
             */
            authMode = eSIR_SHARED_KEY;
            // Trigger MAC based Authentication
<<<<<<< HEAD
<<<<<<< HEAD
            if( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd, (void **)&pMlmAuthReq, sizeof(tLimMlmAuthReq)))
            {
                // Log error
                limLog(pMac, LOGP,
                   FL("call to palAllocateMemory failed for mlmAuthReq\n"));
                return;
            }
            palZeroMemory( pMac->hHdd, (tANI_U8 *) pMlmAuthReq, sizeof(tLimMlmAuthReq));
=======
            pMlmAuthReq = vos_mem_malloc(sizeof(tLimMlmAuthReq));
            if ( NULL == pMlmAuthReq )
=======
            if( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd, (void **)&pMlmAuthReq, sizeof(tLimMlmAuthReq)))
>>>>>>> 657b0e9... prima update
            {
                // Log error
                limLog(pMac, LOGP,
                   FL("call to palAllocateMemory failed for mlmAuthReq\n"));
                return;
            }
<<<<<<< HEAD
            vos_mem_set((tANI_U8 *) pMlmAuthReq, sizeof(tLimMlmAuthReq), 0);
>>>>>>> d97af3b... add prima wlan driver
=======
            palZeroMemory( pMac->hHdd, (tANI_U8 *) pMlmAuthReq, sizeof(tLimMlmAuthReq));
>>>>>>> 657b0e9... prima update
            val = sizeof(tSirMacAddr);
            if (psessionEntry->limSmeState == eLIM_SME_WT_AUTH_STATE)
            {
                sirCopyMacAddr(pMlmAuthReq->peerMacAddr,psessionEntry->bssId);
            }
            else
<<<<<<< HEAD
<<<<<<< HEAD
                palCopyMemory( pMac->hHdd, (tANI_U8 *) &pMlmAuthReq->peerMacAddr,
                              (tANI_U8 *) &pMac->lim.gLimPreAuthPeerAddr,
=======
                vos_mem_copy((tANI_U8 *) &pMlmAuthReq->peerMacAddr,
                             (tANI_U8 *) &pMac->lim.gLimPreAuthPeerAddr,
>>>>>>> d97af3b... add prima wlan driver
=======
                palCopyMemory( pMac->hHdd, (tANI_U8 *) &pMlmAuthReq->peerMacAddr,
                              (tANI_U8 *) &pMac->lim.gLimPreAuthPeerAddr,
>>>>>>> 657b0e9... prima update
                              sizeof(tSirMacAddr));
            pMlmAuthReq->authType = authMode;
            /* Update PE session Id*/
            pMlmAuthReq->sessionId = pMlmAuthCnf->sessionId;
            if (wlan_cfgGetInt(pMac, WNI_CFG_AUTHENTICATE_FAILURE_TIMEOUT,
                          (tANI_U32 *) &pMlmAuthReq->authFailureTimeout)
                            != eSIR_SUCCESS)
            {
                /**
                 * Could not get AuthFailureTimeout value from CFG.
                 * Log error.
                 */
                limLog(pMac, LOGP,
<<<<<<< HEAD
<<<<<<< HEAD
                   FL("could not retrieve AuthFailureTimeout value\n"));
=======
                   FL("could not retrieve AuthFailureTimeout value"));
>>>>>>> d97af3b... add prima wlan driver
=======
                   FL("could not retrieve AuthFailureTimeout value\n"));
>>>>>>> 657b0e9... prima update
            }
            limPostMlmMessage(pMac,
                              LIM_MLM_AUTH_REQ,
                              (tANI_U32 *) pMlmAuthReq);
            return;
        }
        else
        {
            // MAC based authentication failure
            if (psessionEntry->limSmeState == eLIM_SME_WT_AUTH_STATE)
            {
<<<<<<< HEAD
<<<<<<< HEAD
                PELOGE(limLog(pMac, LOGE, FL("Auth Failure occurred.\n"));)
=======
                PELOGE(limLog(pMac, LOGE, FL("Auth Failure occurred."));)
>>>>>>> d97af3b... add prima wlan driver
=======
                PELOGE(limLog(pMac, LOGE, FL("Auth Failure occurred.\n"));)
>>>>>>> 657b0e9... prima update
                psessionEntry->limSmeState = eLIM_SME_JOIN_FAILURE_STATE;
                MTRACE(macTrace(pMac, TRACE_CODE_SME_STATE, psessionEntry->peSessionId, psessionEntry->limSmeState));
                psessionEntry->limMlmState = eLIM_MLM_IDLE_STATE;
                MTRACE(macTrace(pMac, TRACE_CODE_MLM_STATE, psessionEntry->peSessionId, psessionEntry->limMlmState));

<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
#if defined(ANI_AP_CLIENT_SDK)
                if (psessionEntry->limSystemRole == eLIM_STA_ROLE)
                {
                    tSirMacAddr nullMacAddr = {0, 0, 0, 0, 0, 0};
                    PELOGE(limLog(pMac, LOGE, FL("Setting current BSSID as NULL in cfg\n"));)
                    palCopyMemory(pMac->hHdd, pMac->lim.gLimBssid, nullMacAddr, sizeof(tSirMacAddr));
                    if (cfgSetStr(pMac, WNI_CFG_BSSID, nullMacAddr, sizeof(tSirMacAddr)) != eSIR_SUCCESS)
                    {
                        limLog(pMac, LOGP, FL("Could not update BSSID on CFG"));
                    }
                }
#endif
<<<<<<< HEAD
=======
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
                /**
                 * Need to send Join response with
                 * auth failure to Host.
                 */
                limHandleSmeJoinResult(pMac,
                              ((tLimMlmAuthCnf *) pMsgBuf)->resultCode, ((tLimMlmAuthCnf *) pMsgBuf)->protStatusCode,psessionEntry);
            }
            else
            {
                /**
                 * Pre-authentication failure.
                 * Send Pre-auth failure response to host
                 */
                psessionEntry->limSmeState = psessionEntry->limPrevSmeState;
                MTRACE(macTrace(pMac, TRACE_CODE_SME_STATE, psessionEntry->peSessionId, psessionEntry->limSmeState));
                limSendSmeAuthRsp(
                            pMac,
                            ((tLimMlmAuthCnf *) pMsgBuf)->resultCode,
                            ((tLimMlmAuthCnf *) pMsgBuf)->peerMacAddr,
                            ((tLimMlmAuthCnf *) pMsgBuf)->authType,
                            ((tLimMlmAuthCnf *) pMsgBuf)->protStatusCode,psessionEntry,psessionEntry->smeSessionId,psessionEntry->transactionId);
            }
        } // end if (cfgAuthType == eAUTO_SWITCH)
    } // if (((tLimMlmAuthCnf *) pMsgBuf)->resultCode != ...
    else
    {
        if (psessionEntry->limSmeState == eLIM_SME_WT_AUTH_STATE)
        {
            /**
             * Successful MAC based authentication
             * Trigger Association with BSS
             */
            PELOG1(limLog(pMac, LOG1,
<<<<<<< HEAD
<<<<<<< HEAD
                   FL("*** Authenticated with BSS ***\n"));)
            if( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd, (void **)&pMlmAssocReq, sizeof(tLimMlmAssocReq)))
            {
                // Log error
                limLog(pMac, LOGP,
                   FL("call to palAllocateMemory failed for mlmAssocReq\n"));
=======
                   FL("*** Authenticated with BSS ***"));)
            pMlmAssocReq = vos_mem_malloc(sizeof(tLimMlmAssocReq));
            if ( NULL == pMlmAssocReq )
            {
                // Log error
                limLog(pMac, LOGP,
                   FL("call to AllocateMemory failed for mlmAssocReq"));
>>>>>>> d97af3b... add prima wlan driver
=======
                   FL("*** Authenticated with BSS ***\n"));)
            if( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd, (void **)&pMlmAssocReq, sizeof(tLimMlmAssocReq)))
            {
                // Log error
                limLog(pMac, LOGP,
                   FL("call to palAllocateMemory failed for mlmAssocReq\n"));
>>>>>>> 657b0e9... prima update
                return;
            }
            val = sizeof(tSirMacAddr);
            #if 0
            if (cfgGetStr(pMac, WNI_CFG_BSSID,
                          pMlmAssocReq->peerMacAddr,
                          &val) != eSIR_SUCCESS)
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
            #endif //SUPPORT BT-AMP
            sirCopyMacAddr(pMlmAssocReq->peerMacAddr,psessionEntry->bssId);
            if (wlan_cfgGetInt(pMac, WNI_CFG_ASSOCIATION_FAILURE_TIMEOUT,
                          (tANI_U32 *) &pMlmAssocReq->assocFailureTimeout)
                           != eSIR_SUCCESS)
            {
                /**
                 * Could not get AssocFailureTimeout value
                 * from CFG. Log error.
                 */
                limLog(pMac, LOGP,
<<<<<<< HEAD
<<<<<<< HEAD
                   FL("could not retrieve AssocFailureTimeout value\n"));
=======
                   FL("could not retrieve AssocFailureTimeout value"));
>>>>>>> d97af3b... add prima wlan driver
=======
                   FL("could not retrieve AssocFailureTimeout value\n"));
>>>>>>> 657b0e9... prima update
            }
            if (cfgGetCapabilityInfo(pMac, &caps,psessionEntry) != eSIR_SUCCESS)
            {
                /**
                 * Could not get Capabilities value
                 * from CFG. Log error.
                 */
                limLog(pMac, LOGP,
<<<<<<< HEAD
<<<<<<< HEAD
                       FL("could not retrieve Capabilities value\n"));
=======
                       FL("could not retrieve Capabilities value"));
>>>>>>> d97af3b... add prima wlan driver
=======
                       FL("could not retrieve Capabilities value\n"));
>>>>>>> 657b0e9... prima update
            }
            /*Clear spectrum management bit if AP doesn't support it*/
            if(!(psessionEntry->pLimJoinReq->bssDescription.capabilityInfo & LIM_SPECTRUM_MANAGEMENT_BIT_MASK))
            {
                /*AP doesn't support spectrum management clear spectrum management bit*/
                caps &= (~LIM_SPECTRUM_MANAGEMENT_BIT_MASK);
            }

            pMlmAssocReq->capabilityInfo = caps;
           PELOG3(limLog(pMac, LOG3,
<<<<<<< HEAD
<<<<<<< HEAD
               FL("Capabilities to be used in AssocReq=0x%X, privacy bit=%x shortSlotTime %x\n"),
=======
               FL("Capabilities to be used in AssocReq=0x%X, privacy bit=%x shortSlotTime %x"),
>>>>>>> d97af3b... add prima wlan driver
=======
               FL("Capabilities to be used in AssocReq=0x%X, privacy bit=%x shortSlotTime %x\n"),
>>>>>>> 657b0e9... prima update
               caps,
               ((tpSirMacCapabilityInfo) &pMlmAssocReq->capabilityInfo)->privacy,
               ((tpSirMacCapabilityInfo) &pMlmAssocReq->capabilityInfo)->shortSlotTime);)

           /* If telescopic beaconing is enabled, set listen interval to
              WNI_CFG_TELE_BCN_MAX_LI */
            if(wlan_cfgGetInt(pMac, WNI_CFG_TELE_BCN_WAKEUP_EN, &teleBcnEn) !=
               eSIR_SUCCESS)
<<<<<<< HEAD
<<<<<<< HEAD
               limLog(pMac, LOGP, FL("Couldn't get WNI_CFG_TELE_BCN_WAKEUP_EN\n"));
=======
               limLog(pMac, LOGP, FL("Couldn't get WNI_CFG_TELE_BCN_WAKEUP_EN"));
>>>>>>> d97af3b... add prima wlan driver
=======
               limLog(pMac, LOGP, FL("Couldn't get WNI_CFG_TELE_BCN_WAKEUP_EN\n"));
>>>>>>> 657b0e9... prima update

            val = WNI_CFG_LISTEN_INTERVAL_STADEF;

            if(teleBcnEn)
            {
               if(wlan_cfgGetInt(pMac, WNI_CFG_TELE_BCN_MAX_LI, &val) !=
                  eSIR_SUCCESS)
               {
                   /**
                  * Could not get ListenInterval value
                  * from CFG. Log error.
                  */
<<<<<<< HEAD
<<<<<<< HEAD
                  limLog(pMac, LOGP, FL("could not retrieve ListenInterval\n"));
=======
                  limLog(pMac, LOGP, FL("could not retrieve ListenInterval"));
>>>>>>> d97af3b... add prima wlan driver
=======
                  limLog(pMac, LOGP, FL("could not retrieve ListenInterval\n"));
>>>>>>> 657b0e9... prima update
               }
            }
            else
            {
            if (wlan_cfgGetInt(pMac, WNI_CFG_LISTEN_INTERVAL, &val) != eSIR_SUCCESS)
            {
                /**
                 * Could not get ListenInterval value
                 * from CFG. Log error.
                 */
<<<<<<< HEAD
<<<<<<< HEAD
                  limLog(pMac, LOGP, FL("could not retrieve ListenInterval\n"));
=======
                  limLog(pMac, LOGP, FL("could not retrieve ListenInterval"));
>>>>>>> d97af3b... add prima wlan driver
=======
                  limLog(pMac, LOGP, FL("could not retrieve ListenInterval\n"));
>>>>>>> 657b0e9... prima update
               }
            }

            pMlmAssocReq->listenInterval = (tANI_U16)val;
            /* Update PE session ID*/
            pMlmAssocReq->sessionId = psessionEntry->peSessionId;
            psessionEntry->limPrevSmeState = psessionEntry->limSmeState;
            psessionEntry->limSmeState     = eLIM_SME_WT_ASSOC_STATE;
            MTRACE(macTrace(pMac, TRACE_CODE_SME_STATE, psessionEntry->peSessionId, psessionEntry->limSmeState));
            limPostMlmMessage(pMac,
                              LIM_MLM_ASSOC_REQ,
                              (tANI_U32 *) pMlmAssocReq);
        }
        else
        {
            /**
             * Successful Pre-authentication.
             * Send Pre-auth response to host
             */
            psessionEntry->limSmeState = psessionEntry->limPrevSmeState;
            MTRACE(macTrace(pMac, TRACE_CODE_SME_STATE, psessionEntry->peSessionId, psessionEntry->limSmeState));
            limSendSmeAuthRsp(
                        pMac,
                        ((tLimMlmAuthCnf *) pMsgBuf)->resultCode,
                        ((tLimMlmAuthCnf *) pMsgBuf)->peerMacAddr,
                        ((tLimMlmAuthCnf *) pMsgBuf)->authType,
                        ((tLimMlmAuthCnf *) pMsgBuf)->protStatusCode,psessionEntry,psessionEntry->smeSessionId,psessionEntry->transactionId);
        }
    } // end if (((tLimMlmAuthCnf *) pMsgBuf)->resultCode != ...
} /*** end limProcessMlmAuthCnf() ***/

/**
 * limProcessMlmAssocCnf()
 *
 *FUNCTION:
 * This function is called to processes MLM_ASSOC_CNF
 * message from MLM State machine.
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 *
 *NOTE:
 *
 * @param pMac       Pointer to Global MAC structure
 * @param pMsgBuf    A pointer to the MLM message buffer
 *
 * @return None
 */
void
limProcessMlmAssocCnf(tpAniSirGlobal pMac, tANI_U32 *pMsgBuf)
{
    tpPESession     psessionEntry;
    tLimMlmAssocCnf *pLimMlmAssocCnf;

    if(pMsgBuf == NULL)
    {
<<<<<<< HEAD
<<<<<<< HEAD
           limLog(pMac, LOGE,FL("Buffer is Pointing to NULL\n"));
=======
           limLog(pMac, LOGE,FL("Buffer is Pointing to NULL"));
>>>>>>> d97af3b... add prima wlan driver
=======
           limLog(pMac, LOGE,FL("Buffer is Pointing to NULL\n"));
>>>>>>> 657b0e9... prima update
           return;
    }
    pLimMlmAssocCnf = (tLimMlmAssocCnf*)pMsgBuf;
    if((psessionEntry = peFindSessionBySessionId(pMac,pLimMlmAssocCnf->sessionId)) == NULL)
    {
<<<<<<< HEAD
<<<<<<< HEAD
         PELOGE(limLog(pMac, LOGE,FL("Session does not exist for given sessionId\n"));)
=======
         PELOGE(limLog(pMac, LOGE,FL("Session does not exist for given sessionId"));)
>>>>>>> d97af3b... add prima wlan driver
=======
         PELOGE(limLog(pMac, LOGE,FL("Session does not exist for given sessionId\n"));)
>>>>>>> 657b0e9... prima update
         return;
    }
    if (psessionEntry->limSmeState != eLIM_SME_WT_ASSOC_STATE ||
        psessionEntry->limSystemRole == eLIM_AP_ROLE || psessionEntry ->limSystemRole == eLIM_BT_AMP_AP_ROLE)
    {
        /**
         * Should not have received Assocication confirm
         * from MLM in other states OR on AP.
         * Log error
         */
        PELOGE(limLog(pMac, LOGE,
<<<<<<< HEAD
<<<<<<< HEAD
               FL("received unexpected MLM_ASSOC_CNF in state %X\n"),
=======
               FL("received unexpected MLM_ASSOC_CNF in state %X"),
>>>>>>> d97af3b... add prima wlan driver
=======
               FL("received unexpected MLM_ASSOC_CNF in state %X\n"),
>>>>>>> 657b0e9... prima update
               psessionEntry->limSmeState);)
        return;
    }
    if (((tLimMlmAssocCnf *) pMsgBuf)->resultCode != eSIR_SME_SUCCESS)
    {
        // Association failure
<<<<<<< HEAD
<<<<<<< HEAD
        PELOG1(limLog(pMac, LOG1, FL("*** Association failure ***\n"));)
        psessionEntry->limSmeState = eLIM_SME_JOIN_FAILURE_STATE;
        MTRACE(macTrace(pMac, TRACE_CODE_SME_STATE, psessionEntry->peSessionId, pMac->lim.gLimSmeState));
#if defined(ANI_AP_CLIENT_SDK)
        if (psessionEntry->limSystemRole == eLIM_STA_ROLE)
        {
            tSirMacAddr nullMacAddr = {0, 0, 0, 0, 0, 0};
            palCopyMemory(pMac->hHdd, pMac->lim.gLimBssid, nullMacAddr, sizeof(tSirMacAddr));
            if (cfgSetStr(pMac, WNI_CFG_BSSID, nullMacAddr, sizeof(tSirMacAddr)) != eSIR_SUCCESS)
            {
                limLog(pMac, LOGP, FL("Could not update BSSID on CFG"));
            }
        }
#endif
=======
        PELOG1(limLog(pMac, LOG1, FL("*** Association failure ***"));)
        psessionEntry->limSmeState = eLIM_SME_JOIN_FAILURE_STATE;
        MTRACE(macTrace(pMac, TRACE_CODE_SME_STATE, psessionEntry->peSessionId, pMac->lim.gLimSmeState));
>>>>>>> d97af3b... add prima wlan driver
=======
        PELOG1(limLog(pMac, LOG1, FL("*** Association failure ***\n"));)
        psessionEntry->limSmeState = eLIM_SME_JOIN_FAILURE_STATE;
        MTRACE(macTrace(pMac, TRACE_CODE_SME_STATE, psessionEntry->peSessionId, pMac->lim.gLimSmeState));
#if defined(ANI_AP_CLIENT_SDK)
        if (psessionEntry->limSystemRole == eLIM_STA_ROLE)
        {
            tSirMacAddr nullMacAddr = {0, 0, 0, 0, 0, 0};
            palCopyMemory(pMac->hHdd, pMac->lim.gLimBssid, nullMacAddr, sizeof(tSirMacAddr));
            if (cfgSetStr(pMac, WNI_CFG_BSSID, nullMacAddr, sizeof(tSirMacAddr)) != eSIR_SUCCESS)
            {
                limLog(pMac, LOGP, FL("Could not update BSSID on CFG"));
            }
        }
#endif
>>>>>>> 657b0e9... prima update
        /**
         * Need to send Join response with
         * Association failure to Host.
         */
        limHandleSmeJoinResult(pMac,
                            ((tLimMlmAssocCnf *) pMsgBuf)->resultCode,
                            ((tLimMlmAssocCnf *) pMsgBuf)->protStatusCode,psessionEntry);
    } // if (((tLimMlmAssocCnf *) pMsgBuf)->resultCode != ...
    else
    {
        // Successful Association
<<<<<<< HEAD
<<<<<<< HEAD
        PELOG1(limLog(pMac, LOG1, FL("*** Associated with BSS ***\n"));)
=======
        PELOG1(limLog(pMac, LOG1, FL("*** Associated with BSS ***"));)
>>>>>>> d97af3b... add prima wlan driver
=======
        PELOG1(limLog(pMac, LOG1, FL("*** Associated with BSS ***\n"));)
>>>>>>> 657b0e9... prima update
        psessionEntry->limSmeState = eLIM_SME_LINK_EST_STATE;
        MTRACE(macTrace(pMac, TRACE_CODE_SME_STATE, psessionEntry->peSessionId, psessionEntry->limSmeState));
        /**
         * Need to send Join response with
         * Association success to Host.
         */
        limHandleSmeJoinResult(pMac,
                            ((tLimMlmAssocCnf *) pMsgBuf)->resultCode,
                            ((tLimMlmAssocCnf *) pMsgBuf)->protStatusCode,psessionEntry);
    } // end if (((tLimMlmAssocCnf *) pMsgBuf)->resultCode != ....
} /*** end limProcessMlmAssocCnf() ***/

/**
 * limProcessMlmReassocCnf()
 *
 *FUNCTION:
 * This function is called to processes MLM_REASSOC_CNF
 * message from MLM State machine.
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 *
 *NOTE:
 *
 * @param pMac       Pointer to Global MAC structure
 * @param pMsgBuf    A pointer to the MLM message buffer
 *
 * @return None
 */
void
limProcessMlmReassocCnf(tpAniSirGlobal pMac, tANI_U32 *pMsgBuf)
{
    tpPESession psessionEntry;
    tLimMlmReassocCnf *pLimMlmReassocCnf;

    if(pMsgBuf == NULL)
    {
<<<<<<< HEAD
<<<<<<< HEAD
           PELOGE(limLog(pMac, LOGE,FL("Buffer is Pointing to NULL\n"));)
=======
           PELOGE(limLog(pMac, LOGE,FL("Buffer is Pointing to NULL"));)
>>>>>>> d97af3b... add prima wlan driver
=======
           PELOGE(limLog(pMac, LOGE,FL("Buffer is Pointing to NULL\n"));)
>>>>>>> 657b0e9... prima update
           return;
    }
    pLimMlmReassocCnf = (tLimMlmReassocCnf*) pMsgBuf;
    if((psessionEntry = peFindSessionBySessionId(pMac,pLimMlmReassocCnf->sessionId))==NULL)
    {
<<<<<<< HEAD
<<<<<<< HEAD
         PELOGE(limLog(pMac, LOGE, FL("session Does not exist for given session Id\n"));)
=======
         PELOGE(limLog(pMac, LOGE, FL("session Does not exist for given session Id"));)
>>>>>>> d97af3b... add prima wlan driver
=======
         PELOGE(limLog(pMac, LOGE, FL("session Does not exist for given session Id\n"));)
>>>>>>> 657b0e9... prima update
         return;
    }
    if ((psessionEntry->limSmeState != eLIM_SME_WT_REASSOC_STATE) ||
         (psessionEntry->limSystemRole == eLIM_AP_ROLE)||(psessionEntry->limSystemRole == eLIM_BT_AMP_AP_ROLE))
    {
        /**
         * Should not have received Reassocication confirm
         * from MLM in other states OR on AP.
         * Log error
         */
        PELOGE(limLog(pMac, LOGE,
<<<<<<< HEAD
<<<<<<< HEAD
                   FL("Rcv unexpected MLM_REASSOC_CNF in role %d, sme state 0x%X\n"),
=======
                   FL("Rcv unexpected MLM_REASSOC_CNF in role %d, sme state 0x%X"),
>>>>>>> d97af3b... add prima wlan driver
=======
                   FL("Rcv unexpected MLM_REASSOC_CNF in role %d, sme state 0x%X\n"),
>>>>>>> 657b0e9... prima update
                   psessionEntry->limSystemRole, psessionEntry->limSmeState);)
                return;
    }
    if (psessionEntry->pLimReAssocReq) {
<<<<<<< HEAD
<<<<<<< HEAD
        palFreeMemory( pMac->hHdd, psessionEntry->pLimReAssocReq);
        psessionEntry->pLimReAssocReq = NULL;
    }

    PELOGE(limLog(pMac, LOGE, FL("Rcv MLM_REASSOC_CNF with result code %d\n"), pLimMlmReassocCnf->resultCode);)
    if (pLimMlmReassocCnf->resultCode == eSIR_SME_SUCCESS) {
        // Successful Reassociation
        PELOG1(limLog(pMac, LOG1, FL("*** Reassociated with new BSS ***\n"));)
=======
        vos_mem_free(psessionEntry->pLimReAssocReq);
=======
        palFreeMemory( pMac->hHdd, psessionEntry->pLimReAssocReq);
>>>>>>> 657b0e9... prima update
        psessionEntry->pLimReAssocReq = NULL;
    }

    PELOGE(limLog(pMac, LOGE, FL("Rcv MLM_REASSOC_CNF with result code %d\n"), pLimMlmReassocCnf->resultCode);)
    if (pLimMlmReassocCnf->resultCode == eSIR_SME_SUCCESS) {
        // Successful Reassociation
<<<<<<< HEAD
        PELOG1(limLog(pMac, LOG1, FL("*** Reassociated with new BSS ***"));)
>>>>>>> d97af3b... add prima wlan driver
=======
        PELOG1(limLog(pMac, LOG1, FL("*** Reassociated with new BSS ***\n"));)
>>>>>>> 657b0e9... prima update

        psessionEntry->limSmeState = eLIM_SME_LINK_EST_STATE;
        MTRACE(macTrace(pMac, TRACE_CODE_SME_STATE, psessionEntry->peSessionId, psessionEntry->limSmeState));

        /**
        * Need to send Reassoc response with
        * Reassociation success to Host.
        */
        limSendSmeJoinReassocRsp(
                               pMac, eWNI_SME_REASSOC_RSP,
                              pLimMlmReassocCnf->resultCode, pLimMlmReassocCnf->protStatusCode,psessionEntry,
                              psessionEntry->smeSessionId,psessionEntry->transactionId);
    }else if (pLimMlmReassocCnf->resultCode == eSIR_SME_REASSOC_REFUSED) {
        /** Reassociation failure With the New AP
        *   but we still have the link with the Older AP
        */
        psessionEntry->limSmeState = eLIM_SME_LINK_EST_STATE;
        MTRACE(macTrace(pMac, TRACE_CODE_SME_STATE, psessionEntry->peSessionId, psessionEntry->limSmeState));

        /**
        * Need to send Reassoc response with
        * Association failure to Host.
        */
        limSendSmeJoinReassocRsp(pMac, eWNI_SME_REASSOC_RSP,
                              pLimMlmReassocCnf->resultCode, pLimMlmReassocCnf->protStatusCode,psessionEntry,
                              psessionEntry->smeSessionId,psessionEntry->transactionId);
    }else {
        // Reassociation failure
        psessionEntry->limSmeState = eLIM_SME_JOIN_FAILURE_STATE;
    MTRACE(macTrace(pMac, TRACE_CODE_SME_STATE, psessionEntry->peSessionId, psessionEntry->limSmeState));
        /**
         * Need to send Reassoc response with
         * Association failure to Host.
         */
        limHandleSmeReaasocResult(pMac, pLimMlmReassocCnf->resultCode, pLimMlmReassocCnf->protStatusCode, psessionEntry);
    }
} /*** end limProcessMlmReassocCnf() ***/

/**
 * limProcessMlmReassocInd()
 *
 *FUNCTION:
 * This function is called to processes MLM_REASSOC_IND
 * message from MLM State machine.
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 *
 *NOTE:
 *
 * @param pMac       Pointer to Global MAC structure
 * @param pMsgBuf    A pointer to the MLM message buffer
 *
 * @return None
 */
void
limProcessMlmReassocInd(tpAniSirGlobal pMac, tANI_U32 *pMsgBuf)
{
    tANI_U32                len;
    tSirMsgQ           msgQ;
    tSirSmeReassocInd  *pSirSmeReassocInd;
    tpDphHashNode      pStaDs=0;
    tpPESession  psessionEntry;
    tANI_U8      sessionId;
    if(pMsgBuf == NULL)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        PELOGE(limLog(pMac, LOGE,FL("Buffer is Pointing to NULL\n"));)
=======
        PELOGE(limLog(pMac, LOGE,FL("Buffer is Pointing to NULL"));)
>>>>>>> d97af3b... add prima wlan driver
=======
        PELOGE(limLog(pMac, LOGE,FL("Buffer is Pointing to NULL\n"));)
>>>>>>> 657b0e9... prima update
        return;
    }
    if((psessionEntry = peFindSessionByBssid(pMac,((tpLimMlmReassocInd)pMsgBuf)->peerMacAddr, &sessionId))== NULL)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        PELOGE(limLog(pMac, LOGE,FL("session does not exist for given BSSId\n"));)
        return;
    }
    /// Inform Host of STA reassociation
#if (WNI_POLARIS_FW_PACKAGE == ADVANCED)
    len = sizeof(tSirSmeReassocInd) -
          sizeof(tSirNeighborBssInfo) +
          (((tpLimMlmReassocInd) pMsgBuf)->numBss *
           sizeof(tSirNeighborBssInfo)) -
           SIR_MAC_MAX_SSID_LENGTH +
           ((tpLimMlmReassocInd) pMsgBuf)->ssId.length;
#else
    len = sizeof(tSirSmeReassocInd);
#endif
    if( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd, (void **)&pSirSmeReassocInd, len))
    {
        // Log error
        limLog(pMac, LOGP,
           FL("call to palAllocateMemory failed for eWNI_SME_REASSOC_IND\n"));
=======
        PELOGE(limLog(pMac, LOGE,FL("session does not exist for given BSSId"));)
=======
        PELOGE(limLog(pMac, LOGE,FL("session does not exist for given BSSId\n"));)
>>>>>>> 657b0e9... prima update
        return;
    }
    /// Inform Host of STA reassociation
#if (WNI_POLARIS_FW_PACKAGE == ADVANCED)
    len = sizeof(tSirSmeReassocInd) -
          sizeof(tSirNeighborBssInfo) +
          (((tpLimMlmReassocInd) pMsgBuf)->numBss *
           sizeof(tSirNeighborBssInfo)) -
           SIR_MAC_MAX_SSID_LENGTH +
           ((tpLimMlmReassocInd) pMsgBuf)->ssId.length;
#else
    len = sizeof(tSirSmeReassocInd);
#endif
    if( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd, (void **)&pSirSmeReassocInd, len))
    {
        // Log error
        limLog(pMac, LOGP,
<<<<<<< HEAD
           FL("call to AllocateMemory failed for eWNI_SME_REASSOC_IND"));
>>>>>>> d97af3b... add prima wlan driver
=======
           FL("call to palAllocateMemory failed for eWNI_SME_REASSOC_IND\n"));
>>>>>>> 657b0e9... prima update
        return;

    }
    sirStoreU16N((tANI_U8 *) &pSirSmeReassocInd->messageType,
                 eWNI_SME_REASSOC_IND);
    limReassocIndSerDes(pMac, (tpLimMlmReassocInd) pMsgBuf,
                        (tANI_U8 *) &(pSirSmeReassocInd->length), psessionEntry);

    // Required for indicating the frames to upper layer
    pSirSmeReassocInd->assocReqLength = ((tpLimMlmReassocInd) pMsgBuf)->assocReqLength;
    pSirSmeReassocInd->assocReqPtr = ((tpLimMlmReassocInd) pMsgBuf)->assocReqPtr;
    pSirSmeReassocInd->beaconPtr = psessionEntry->beacon;
    pSirSmeReassocInd->beaconLength = psessionEntry->bcnLen;
    
    msgQ.type = eWNI_SME_REASSOC_IND;
    msgQ.bodyptr = pSirSmeReassocInd;
    msgQ.bodyval = 0;
    MTRACE(macTraceMsgTx(pMac, psessionEntry->peSessionId, msgQ.type));
#ifdef FEATURE_WLAN_DIAG_SUPPORT_LIM //FEATURE_WLAN_DIAG_SUPPORT
    limDiagEventReport(pMac, WLAN_PE_DIAG_REASSOC_IND_EVENT, psessionEntry, 0, 0);
#endif //FEATURE_WLAN_DIAG_SUPPORT
    pStaDs = dphGetHashEntry(pMac, ((tpLimMlmReassocInd) pMsgBuf)->aid, &psessionEntry->dph.dphHashTable);
    if (! pStaDs)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        limLog( pMac, LOGP, FL("MLM ReAssocInd: Station context no longer valid (aid %d)\n"),
                ((tpLimMlmReassocInd) pMsgBuf)->aid);
        palFreeMemory(pMac->hHdd, pSirSmeReassocInd);
=======
        limLog( pMac, LOGP, FL("MLM ReAssocInd: Station context no longer valid (aid %d)"),
                ((tpLimMlmReassocInd) pMsgBuf)->aid);
        vos_mem_free(pSirSmeReassocInd);
>>>>>>> d97af3b... add prima wlan driver
=======
        limLog( pMac, LOGP, FL("MLM ReAssocInd: Station context no longer valid (aid %d)\n"),
                ((tpLimMlmReassocInd) pMsgBuf)->aid);
        palFreeMemory(pMac->hHdd, pSirSmeReassocInd);
>>>>>>> 657b0e9... prima update
        return;
    }

    limSysProcessMmhMsgApi(pMac, &msgQ,  ePROT);
    PELOG1(limLog(pMac, LOG1,
<<<<<<< HEAD
<<<<<<< HEAD
       FL("Create CNF_WAIT_TIMER after received LIM_MLM_REASSOC_IND\n"));)
=======
       FL("Create CNF_WAIT_TIMER after received LIM_MLM_REASSOC_IND"));)
>>>>>>> d97af3b... add prima wlan driver
=======
       FL("Create CNF_WAIT_TIMER after received LIM_MLM_REASSOC_IND\n"));)
>>>>>>> 657b0e9... prima update
    /*
     ** turn on a timer to detect the loss of REASSOC CNF
     **/
    limActivateCnfTimer(pMac,
                        (tANI_U16) ((tpLimMlmReassocInd) pMsgBuf)->aid, psessionEntry);
} /*** end limProcessMlmReassocInd() ***/

/**
 * limProcessMlmAuthInd()
 *
 *FUNCTION:
 * This function is called to processes MLM_AUTH_IND
 * message from MLM State machine.
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 *
 *NOTE:
 *
 * @param pMac       Pointer to Global MAC structure
 * @param pMsgBuf    A pointer to the MLM message buffer
 *
 * @return None
 */
void
limProcessMlmAuthInd(tpAniSirGlobal pMac, tANI_U32 *pMsgBuf)
{
    tSirMsgQ           msgQ;
    tSirSmeAuthInd     *pSirSmeAuthInd;

    if(pMsgBuf == NULL)
    {
<<<<<<< HEAD
<<<<<<< HEAD
           PELOGE(limLog(pMac, LOGE,FL("Buffer is Pointing to NULL\n"));)
           return;
    }
    if( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd, (void **)&pSirSmeAuthInd, sizeof(tSirSmeAuthInd)))
    {
        // Log error
        limLog(pMac, LOGP,
           FL("call to palAllocateMemory failed for eWNI_SME_AUTH_IND\n"));
=======
           PELOGE(limLog(pMac, LOGE,FL("Buffer is Pointing to NULL"));)
=======
           PELOGE(limLog(pMac, LOGE,FL("Buffer is Pointing to NULL\n"));)
>>>>>>> 657b0e9... prima update
           return;
    }
    if( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd, (void **)&pSirSmeAuthInd, sizeof(tSirSmeAuthInd)))
    {
        // Log error
        limLog(pMac, LOGP,
<<<<<<< HEAD
           FL("call to AllocateMemory failed for eWNI_SME_AUTH_IND"));
>>>>>>> d97af3b... add prima wlan driver
=======
           FL("call to palAllocateMemory failed for eWNI_SME_AUTH_IND\n"));
>>>>>>> 657b0e9... prima update
    }
    limCopyU16((tANI_U8 *) &pSirSmeAuthInd->messageType, eWNI_SME_AUTH_IND);
    limAuthIndSerDes(pMac, (tpLimMlmAuthInd) pMsgBuf,
                        (tANI_U8 *) &(pSirSmeAuthInd->length));
    msgQ.type = eWNI_SME_AUTH_IND;
    msgQ.bodyptr = pSirSmeAuthInd;
    msgQ.bodyval = 0;
    MTRACE(macTraceMsgTx(pMac, NO_SESSION, msgQ.type));
#ifdef FEATURE_WLAN_DIAG_SUPPORT_LIM //FEATURE_WLAN_DIAG_SUPPORT
    limDiagEventReport(pMac, WLAN_PE_DIAG_AUTH_IND_EVENT, NULL, 0, 0);
#endif //FEATURE_WLAN_DIAG_SUPPORT
    limSysProcessMmhMsgApi(pMac, &msgQ,  ePROT);
} /*** end limProcessMlmAuthInd() ***/




void
limFillAssocIndParams(tpAniSirGlobal pMac, tpLimMlmAssocInd pAssocInd,
                                            tSirSmeAssocInd    *pSirSmeAssocInd,
                                            tpPESession psessionEntry)
{
    pSirSmeAssocInd->length = sizeof(tSirSmeAssocInd);
    pSirSmeAssocInd->sessionId = psessionEntry->smeSessionId;

    // Required for indicating the frames to upper layer
    pSirSmeAssocInd->assocReqLength = pAssocInd->assocReqLength;
    pSirSmeAssocInd->assocReqPtr = pAssocInd->assocReqPtr;

    pSirSmeAssocInd->beaconPtr = psessionEntry->beacon;
    pSirSmeAssocInd->beaconLength = psessionEntry->bcnLen;    

    // Fill in peerMacAddr
<<<<<<< HEAD
<<<<<<< HEAD
    palCopyMemory( pMac->hHdd, pSirSmeAssocInd->peerMacAddr, pAssocInd->peerMacAddr, sizeof(tSirMacAddr));
    // Fill in aid
    pSirSmeAssocInd->aid = pAssocInd->aid;
    // Fill in bssId
    palCopyMemory( pMac->hHdd, pSirSmeAssocInd->bssId, psessionEntry->bssId, sizeof(tSirMacAddr));
=======
    vos_mem_copy(pSirSmeAssocInd->peerMacAddr, pAssocInd->peerMacAddr,
                 sizeof(tSirMacAddr));

    // Fill in aid
    pSirSmeAssocInd->aid = pAssocInd->aid;
    // Fill in bssId
    vos_mem_copy(pSirSmeAssocInd->bssId, psessionEntry->bssId, sizeof(tSirMacAddr));
>>>>>>> d97af3b... add prima wlan driver
=======
    palCopyMemory( pMac->hHdd, pSirSmeAssocInd->peerMacAddr, pAssocInd->peerMacAddr, sizeof(tSirMacAddr));
    // Fill in aid
    pSirSmeAssocInd->aid = pAssocInd->aid;
    // Fill in bssId
    palCopyMemory( pMac->hHdd, pSirSmeAssocInd->bssId, psessionEntry->bssId, sizeof(tSirMacAddr));
>>>>>>> 657b0e9... prima update
    // Fill in staId
    //pSirSmeAssocInd->staId = psessionEntry->staId;
    // Fill in authType
    pSirSmeAssocInd->authType = pAssocInd->authType;
    // Fill in ssId
<<<<<<< HEAD
<<<<<<< HEAD
    palCopyMemory( pMac->hHdd,  (tANI_U8*)&pSirSmeAssocInd->ssId,
                                (tANI_U8 *) &(pAssocInd->ssId), pAssocInd->ssId.length + 1);
    pSirSmeAssocInd->rsnIE.length = pAssocInd->rsnIE.length;
    palCopyMemory( pMac->hHdd, (tANI_U8*) &pSirSmeAssocInd->rsnIE.rsnIEdata,
                                (tANI_U8 *) &(pAssocInd->rsnIE.rsnIEdata),
                                pAssocInd->rsnIE.length);

    pSirSmeAssocInd->addIE.length = pAssocInd->addIE.length;
    palCopyMemory( pMac->hHdd, (tANI_U8*) &pSirSmeAssocInd->addIE.addIEdata,
                                (tANI_U8 *) &(pAssocInd->addIE.addIEdata),
                                pAssocInd->addIE.length);
=======
    vos_mem_copy((tANI_U8*)&pSirSmeAssocInd->ssId,
                 (tANI_U8 *) &(pAssocInd->ssId), pAssocInd->ssId.length + 1);
=======
    palCopyMemory( pMac->hHdd,  (tANI_U8*)&pSirSmeAssocInd->ssId,
                                (tANI_U8 *) &(pAssocInd->ssId), pAssocInd->ssId.length + 1);
>>>>>>> 657b0e9... prima update
    pSirSmeAssocInd->rsnIE.length = pAssocInd->rsnIE.length;
    palCopyMemory( pMac->hHdd, (tANI_U8*) &pSirSmeAssocInd->rsnIE.rsnIEdata,
                                (tANI_U8 *) &(pAssocInd->rsnIE.rsnIEdata),
                                pAssocInd->rsnIE.length);

    pSirSmeAssocInd->addIE.length = pAssocInd->addIE.length;
<<<<<<< HEAD
    vos_mem_copy((tANI_U8*) &pSirSmeAssocInd->addIE.addIEdata,
                 (tANI_U8 *) &(pAssocInd->addIE.addIEdata),
                 pAssocInd->addIE.length);
>>>>>>> d97af3b... add prima wlan driver
=======
    palCopyMemory( pMac->hHdd, (tANI_U8*) &pSirSmeAssocInd->addIE.addIEdata,
                                (tANI_U8 *) &(pAssocInd->addIE.addIEdata),
                                pAssocInd->addIE.length);
>>>>>>> 657b0e9... prima update

    // Copy the new TITAN capabilities
    pSirSmeAssocInd->spectrumMgtIndicator = pAssocInd->spectrumMgtIndicator;
    if (pAssocInd->spectrumMgtIndicator == eSIR_TRUE)
    {
        pSirSmeAssocInd->powerCap.minTxPower = pAssocInd->powerCap.minTxPower;
        pSirSmeAssocInd->powerCap.maxTxPower = pAssocInd->powerCap.maxTxPower;
        pSirSmeAssocInd->supportedChannels.numChnl = pAssocInd->supportedChannels.numChnl;
<<<<<<< HEAD
<<<<<<< HEAD
        palCopyMemory( pMac->hHdd, (tANI_U8*) &pSirSmeAssocInd->supportedChannels.channelList,
                     (tANI_U8 *) &(pAssocInd->supportedChannels.channelList),
                     pAssocInd->supportedChannels.numChnl);
    }
#ifdef WLAN_SOFTAP_FEATURE
    // Fill in WmmInfo
    pSirSmeAssocInd->wmmEnabledSta = pAssocInd->WmmStaInfoPresent;
#endif
=======
        vos_mem_copy((tANI_U8*) &pSirSmeAssocInd->supportedChannels.channelList,
=======
        palCopyMemory( pMac->hHdd, (tANI_U8*) &pSirSmeAssocInd->supportedChannels.channelList,
>>>>>>> 657b0e9... prima update
                     (tANI_U8 *) &(pAssocInd->supportedChannels.channelList),
                     pAssocInd->supportedChannels.numChnl);
    }
#ifdef WLAN_SOFTAP_FEATURE
    // Fill in WmmInfo
    pSirSmeAssocInd->wmmEnabledSta = pAssocInd->WmmStaInfoPresent;
<<<<<<< HEAD
>>>>>>> d97af3b... add prima wlan driver
=======
#endif
>>>>>>> 657b0e9... prima update
} /*** end limAssocIndSerDes() ***/



/**
 * limProcessMlmAssocInd()
 *
 *FUNCTION:
 * This function is called to processes MLM_ASSOC_IND
 * message from MLM State machine.
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 *
 *NOTE:
 *
 * @param pMac       Pointer to Global MAC structure
 * @param pMsgBuf    A pointer to the MLM message buffer
 *
 * @return None
 */
void
limProcessMlmAssocInd(tpAniSirGlobal pMac, tANI_U32 *pMsgBuf)
{
    tANI_U32            len;
    tSirMsgQ            msgQ;
    tSirSmeAssocInd    *pSirSmeAssocInd;
    tpDphHashNode       pStaDs=0;
    tpPESession         psessionEntry;
    if(pMsgBuf == NULL)
    {
<<<<<<< HEAD
<<<<<<< HEAD
           PELOGE(limLog(pMac, LOGE,FL("Buffer is Pointing to NULL\n"));)
=======
           PELOGE(limLog(pMac, LOGE,FL("Buffer is Pointing to NULL"));)
>>>>>>> d97af3b... add prima wlan driver
=======
           PELOGE(limLog(pMac, LOGE,FL("Buffer is Pointing to NULL\n"));)
>>>>>>> 657b0e9... prima update
           return;
    }
    if((psessionEntry = peFindSessionBySessionId(pMac,((tpLimMlmAssocInd) pMsgBuf)->sessionId))== NULL)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        limLog( pMac, LOGE, FL( "Session Does not exist for given sessionId\n" ));
        return;
    }
    /// Inform Host of STA association
#if defined (ANI_PRODUCT_TYPE_AP)
    len = sizeof(tSirSmeAssocInd) -
              sizeof(tSirNeighborBssInfo) +
              (((tpLimMlmAssocInd) pMsgBuf)->numBss *
               sizeof(tSirNeighborBssInfo)) -
              SIR_MAC_MAX_SSID_LENGTH +
              ((tpLimMlmAssocInd) pMsgBuf)->ssId.length;
#else
    len = sizeof(tSirSmeAssocInd);
#endif
    if( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd, (void **)&pSirSmeAssocInd, len))
    {
        // Log error
        limLog(pMac, LOGP,
               FL("call to palAllocateMemory failed for eWNI_SME_ASSOC_IND\n"));
        return;
    }

#if defined (ANI_PRODUCT_TYPE_AP)
    sirStoreU16N((tANI_U8 *) &pSirSmeAssocInd->messageType,
                 eWNI_SME_ASSOC_IND);
    limAssocIndSerDes(pMac, (tpLimMlmAssocInd) pMsgBuf,
                      (tANI_U8 *) &(pSirSmeAssocInd->length), psessionEntry);
#else
    pSirSmeAssocInd->messageType = eWNI_SME_ASSOC_IND;
    limFillAssocIndParams(pMac, (tpLimMlmAssocInd) pMsgBuf, pSirSmeAssocInd, psessionEntry);
#endif
=======
        limLog( pMac, LOGE, FL( "Session Does not exist for given sessionId" ));
=======
        limLog( pMac, LOGE, FL( "Session Does not exist for given sessionId\n" ));
>>>>>>> 657b0e9... prima update
        return;
    }
    /// Inform Host of STA association
#if defined (ANI_PRODUCT_TYPE_AP)
    len = sizeof(tSirSmeAssocInd) -
              sizeof(tSirNeighborBssInfo) +
              (((tpLimMlmAssocInd) pMsgBuf)->numBss *
               sizeof(tSirNeighborBssInfo)) -
              SIR_MAC_MAX_SSID_LENGTH +
              ((tpLimMlmAssocInd) pMsgBuf)->ssId.length;
#else
    len = sizeof(tSirSmeAssocInd);
#endif
    if( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd, (void **)&pSirSmeAssocInd, len))
    {
        // Log error
        limLog(pMac, LOGP,
               FL("call to palAllocateMemory failed for eWNI_SME_ASSOC_IND\n"));
        return;
    }

#if defined (ANI_PRODUCT_TYPE_AP)
    sirStoreU16N((tANI_U8 *) &pSirSmeAssocInd->messageType,
                 eWNI_SME_ASSOC_IND);
    limAssocIndSerDes(pMac, (tpLimMlmAssocInd) pMsgBuf,
                      (tANI_U8 *) &(pSirSmeAssocInd->length), psessionEntry);
#else
    pSirSmeAssocInd->messageType = eWNI_SME_ASSOC_IND;
    limFillAssocIndParams(pMac, (tpLimMlmAssocInd) pMsgBuf, pSirSmeAssocInd, psessionEntry);
<<<<<<< HEAD
>>>>>>> d97af3b... add prima wlan driver
=======
#endif
>>>>>>> 657b0e9... prima update
    msgQ.type = eWNI_SME_ASSOC_IND;
    msgQ.bodyptr = pSirSmeAssocInd;
    msgQ.bodyval = 0;
    pStaDs = dphGetHashEntry(pMac,
                             ((tpLimMlmAssocInd) pMsgBuf)->aid, &psessionEntry->dph.dphHashTable);
    if (! pStaDs)
    {   // good time to panic...
<<<<<<< HEAD
<<<<<<< HEAD
        limLog(pMac, LOGE, FL("MLM AssocInd: Station context no longer valid (aid %d)\n"),
               ((tpLimMlmAssocInd) pMsgBuf)->aid);
        palFreeMemory(pMac->hHdd, pSirSmeAssocInd);
=======
        limLog(pMac, LOGE, FL("MLM AssocInd: Station context no longer valid (aid %d)"),
               ((tpLimMlmAssocInd) pMsgBuf)->aid);
        vos_mem_free(pSirSmeAssocInd);
>>>>>>> d97af3b... add prima wlan driver
=======
        limLog(pMac, LOGE, FL("MLM AssocInd: Station context no longer valid (aid %d)\n"),
               ((tpLimMlmAssocInd) pMsgBuf)->aid);
        palFreeMemory(pMac->hHdd, pSirSmeAssocInd);
>>>>>>> 657b0e9... prima update

        return;
    }
    pSirSmeAssocInd->staId = pStaDs->staIndex;
<<<<<<< HEAD
<<<<<<< HEAD
#ifdef WLAN_SOFTAP_FEATURE
   pSirSmeAssocInd->reassocReq = pStaDs->mlmStaContext.subType;
#endif
=======
   pSirSmeAssocInd->reassocReq = pStaDs->mlmStaContext.subType;
>>>>>>> d97af3b... add prima wlan driver
=======
#ifdef WLAN_SOFTAP_FEATURE
   pSirSmeAssocInd->reassocReq = pStaDs->mlmStaContext.subType;
#endif
>>>>>>> 657b0e9... prima update
    MTRACE(macTraceMsgTx(pMac, psessionEntry->peSessionId, msgQ.type));
#ifdef FEATURE_WLAN_DIAG_SUPPORT_LIM //FEATURE_WLAN_DIAG_SUPPORT
    limDiagEventReport(pMac, WLAN_PE_DIAG_ASSOC_IND_EVENT, psessionEntry, 0, 0);
#endif //FEATURE_WLAN_DIAG_SUPPORT
    limSysProcessMmhMsgApi(pMac, &msgQ,  ePROT);

    PELOG1(limLog(pMac, LOG1,
<<<<<<< HEAD
<<<<<<< HEAD
       FL("Create CNF_WAIT_TIMER after received LIM_MLM_ASSOC_IND\n"));)
=======
       FL("Create CNF_WAIT_TIMER after received LIM_MLM_ASSOC_IND"));)
>>>>>>> d97af3b... add prima wlan driver
=======
       FL("Create CNF_WAIT_TIMER after received LIM_MLM_ASSOC_IND\n"));)
>>>>>>> 657b0e9... prima update
    /*
     ** turn on a timer to detect the loss of ASSOC CNF
     **/
    limActivateCnfTimer(pMac, (tANI_U16) ((tpLimMlmAssocInd) pMsgBuf)->aid, psessionEntry);

// Enable this Compile flag to test the BT-AMP -AP assoc sequence
#ifdef TEST_BTAMP_AP
//tANI_U32 *pMsgBuf;
{
    tpSirSmeAssocCnf     pSmeAssoccnf;
<<<<<<< HEAD
<<<<<<< HEAD
    if(!palAllocateMemory(pMac->hHdd,(void **)&pSmeAssoccnf,sizeof(tSirSmeAssocCnf)))
        PELOGE(limLog(pMac, LOGE, FL("palAllocateMemory failed for pSmeAssoccnf \n"));)
    pSmeAssoccnf->messageType = eWNI_SME_ASSOC_CNF;
    pSmeAssoccnf->length = sizeof(tSirSmeAssocCnf);
    palCopyMemory( pMac->hHdd,pSmeAssoccnf->peerMacAddr,((tpLimMlmAssocInd)pMsgBuf)->peerMacAddr,6);
    pSmeAssoccnf->statusCode = eSIR_SME_SUCCESS;
    pSmeAssoccnf->aid = ((tpLimMlmAssocInd)pMsgBuf)->aid;
    palCopyMemory( pMac->hHdd, pSmeAssoccnf->alternateBssId,pSmeAssoccnf->peerMacAddr,sizeof(tSirMacAddr));
    pSmeAssoccnf->alternateChannelId = 6;
    palCopyMemory( pMac->hHdd,pSmeAssoccnf->bssId,psessionEntry->selfMacAddr,6);
    pMsgBuf = (tANI_U32)pSmeAssoccnf;
    __limProcessSmeAssocCnfNew(pMac, eWNI_SME_ASSOC_CNF, pMsgBuf);
    palFreeMemory(pMac->hHdd,pSmeAssoccnf);
=======
    pSmeAssoccnf = vos_mem_malloc(sizeof(tSirSmeAssocCnf));
    if ( NULL == pSmeAssoccnf )
        PELOGE(limLog(pMac, LOGE, FL("AllocateMemory failed for pSmeAssoccnf "));)
=======
    if(!palAllocateMemory(pMac->hHdd,(void **)&pSmeAssoccnf,sizeof(tSirSmeAssocCnf)))
        PELOGE(limLog(pMac, LOGE, FL("palAllocateMemory failed for pSmeAssoccnf \n"));)
>>>>>>> 657b0e9... prima update
    pSmeAssoccnf->messageType = eWNI_SME_ASSOC_CNF;
    pSmeAssoccnf->length = sizeof(tSirSmeAssocCnf);
    palCopyMemory( pMac->hHdd,pSmeAssoccnf->peerMacAddr,((tpLimMlmAssocInd)pMsgBuf)->peerMacAddr,6);
    pSmeAssoccnf->statusCode = eSIR_SME_SUCCESS;
    pSmeAssoccnf->aid = ((tpLimMlmAssocInd)pMsgBuf)->aid;
    palCopyMemory( pMac->hHdd, pSmeAssoccnf->alternateBssId,pSmeAssoccnf->peerMacAddr,sizeof(tSirMacAddr));
    pSmeAssoccnf->alternateChannelId = 6;
    palCopyMemory( pMac->hHdd,pSmeAssoccnf->bssId,psessionEntry->selfMacAddr,6);
    pMsgBuf = (tANI_U32)pSmeAssoccnf;
    __limProcessSmeAssocCnfNew(pMac, eWNI_SME_ASSOC_CNF, pMsgBuf);
<<<<<<< HEAD
    vos_mem_free(pSmeAssoccnf);
>>>>>>> d97af3b... add prima wlan driver
=======
    palFreeMemory(pMac->hHdd,pSmeAssoccnf);
>>>>>>> 657b0e9... prima update
}
#endif


} /*** end limProcessMlmAssocInd() ***/




/**
 * limProcessMlmDisassocInd()
 *
 *FUNCTION:
 * This function is called to processes MLM_DISASSOC_IND
 * message from MLM State machine.
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 *
 *NOTE:
 *
 * @param pMac       Pointer to Global MAC structure
 * @param pMsgBuf    A pointer to the MLM message buffer
 *
 * @return None
 */
void
limProcessMlmDisassocInd(tpAniSirGlobal pMac, tANI_U32 *pMsgBuf)
{
    tLimMlmDisassocInd  *pMlmDisassocInd;
    tpPESession         psessionEntry;
    pMlmDisassocInd = (tLimMlmDisassocInd *) pMsgBuf;
    if( (psessionEntry = peFindSessionBySessionId(pMac,pMlmDisassocInd->sessionId) )== NULL)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        limLog(pMac, LOGP,FL("Session Does not exist for given sessionID\n"));
=======
        limLog(pMac, LOGP,FL("Session Does not exist for given sessionID"));
>>>>>>> d97af3b... add prima wlan driver
=======
        limLog(pMac, LOGP,FL("Session Does not exist for given sessionID\n"));
>>>>>>> 657b0e9... prima update
        return;
    }
    switch (psessionEntry->limSystemRole)
    {
        case eLIM_STA_IN_IBSS_ROLE:
            break;
        case eLIM_STA_ROLE:
        case eLIM_BT_AMP_STA_ROLE:
        psessionEntry->limSmeState = eLIM_SME_WT_DISASSOC_STATE;
            MTRACE(macTrace(pMac, TRACE_CODE_SME_STATE, psessionEntry->peSessionId, psessionEntry->limSmeState));
            break;
        default: // eLIM_AP_ROLE //eLIM_BT_AMP_AP_ROLE
                PELOG1(limLog(pMac, LOG1,
<<<<<<< HEAD
<<<<<<< HEAD
                       FL("*** Peer staId=%d Disassociated ***\n"),
=======
                       FL("*** Peer staId=%d Disassociated ***"),
>>>>>>> d97af3b... add prima wlan driver
=======
                       FL("*** Peer staId=%d Disassociated ***\n"),
>>>>>>> 657b0e9... prima update
                        pMlmDisassocInd->aid);)
            // Send SME_DISASOC_IND after Polaris cleanup
            // (after receiving LIM_MLM_PURGE_STA_IND)
            break;
    } // end switch (psessionEntry->limSystemRole)
} /*** end limProcessMlmDisassocInd() ***/

/**
 * limProcessMlmDisassocCnf()
 *
 *FUNCTION:
 * This function is called to processes MLM_DISASSOC_CNF
 * message from MLM State machine.
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 *
 *NOTE:
 *
 * @param pMac       Pointer to Global MAC structure
 * @param pMsgBuf    A pointer to the MLM message buffer
 *
 * @return None
 */
void
limProcessMlmDisassocCnf(tpAniSirGlobal pMac, tANI_U32 *pMsgBuf)
{
    tSirResultCodes         resultCode;
    tLimMlmDisassocCnf      *pMlmDisassocCnf;
    tpPESession             psessionEntry;
    pMlmDisassocCnf = (tLimMlmDisassocCnf *) pMsgBuf;
    if((psessionEntry = peFindSessionBySessionId(pMac,pMlmDisassocCnf->sessionId))== NULL)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        PELOGE(limLog(pMac, LOGE,FL("session Does not exist for given session Id\n"));)
=======
        PELOGE(limLog(pMac, LOGE,FL("session Does not exist for given session Id"));)
>>>>>>> d97af3b... add prima wlan driver
=======
        PELOGE(limLog(pMac, LOGE,FL("session Does not exist for given session Id\n"));)
>>>>>>> 657b0e9... prima update
        return;
    }
    resultCode = (tSirResultCodes)
                 (pMlmDisassocCnf->disassocTrigger ==
                  eLIM_LINK_MONITORING_DISASSOC) ?
                 eSIR_SME_LOST_LINK_WITH_PEER_RESULT_CODE :
                 pMlmDisassocCnf->resultCode;
    if ((psessionEntry->limSystemRole == eLIM_STA_ROLE)|| (psessionEntry->limSystemRole == eLIM_BT_AMP_STA_ROLE))
    {
<<<<<<< HEAD
<<<<<<< HEAD
#if defined(ANI_AP_CLIENT_SDK)
        tSirMacAddr         nullMacAddr = {0, 0, 0, 0, 0, 0};
#endif
=======
>>>>>>> d97af3b... add prima wlan driver
=======
#if defined(ANI_AP_CLIENT_SDK)
        tSirMacAddr         nullMacAddr = {0, 0, 0, 0, 0, 0};
#endif
>>>>>>> 657b0e9... prima update
        // Disassociate Confirm from MLM
        if ( (psessionEntry->limSmeState != eLIM_SME_WT_DISASSOC_STATE) &&
             (psessionEntry->limSmeState != eLIM_SME_WT_DEAUTH_STATE) )
        {
            /**
             * Should not have received
             * Disassocate confirm
             * from MLM in other states.
             * Log error
             */
            PELOGE(limLog(pMac, LOGE,
<<<<<<< HEAD
<<<<<<< HEAD
               FL("received unexpected MLM_DISASSOC_CNF in state %X\n"),psessionEntry->limSmeState);)
            return;
        }
#if defined(ANI_AP_CLIENT_SDK)
        // Whenever there is a disassoc notification, make sure the bssId is cleared so that
        // if the station finds the same AP to which it was associated, it can try to associate
        // with it again. If this is not done, the beacons/probe rsp from this AP will not be given
        // up to WSM and it never see this is AP unless a cga/reboot is done.
        palCopyMemory(pMac->hHdd, pMac->lim.gLimBssid, nullMacAddr, sizeof(tSirMacAddr));
        if (cfgSetStr(pMac, WNI_CFG_BSSID, nullMacAddr, sizeof(tSirMacAddr)) != eSIR_SUCCESS)
        {
            limLog(pMac, LOGP, FL("Could not update BSSID on CFG"));
        }
#endif
=======
               FL("received unexpected MLM_DISASSOC_CNF in state %X"),psessionEntry->limSmeState);)
            return;
        }
>>>>>>> d97af3b... add prima wlan driver
=======
               FL("received unexpected MLM_DISASSOC_CNF in state %X\n"),psessionEntry->limSmeState);)
            return;
        }
#if defined(ANI_AP_CLIENT_SDK)
        // Whenever there is a disassoc notification, make sure the bssId is cleared so that
        // if the station finds the same AP to which it was associated, it can try to associate
        // with it again. If this is not done, the beacons/probe rsp from this AP will not be given
        // up to WSM and it never see this is AP unless a cga/reboot is done.
        palCopyMemory(pMac->hHdd, pMac->lim.gLimBssid, nullMacAddr, sizeof(tSirMacAddr));
        if (cfgSetStr(pMac, WNI_CFG_BSSID, nullMacAddr, sizeof(tSirMacAddr)) != eSIR_SUCCESS)
        {
            limLog(pMac, LOGP, FL("Could not update BSSID on CFG"));
        }
#endif
>>>>>>> 657b0e9... prima update
        if (pMac->lim.gLimRspReqd)
            pMac->lim.gLimRspReqd = false;
        if (pMlmDisassocCnf->disassocTrigger ==
                                    eLIM_PROMISCUOUS_MODE_DISASSOC)
        {
            if (pMlmDisassocCnf->resultCode != eSIR_SME_SUCCESS)
                psessionEntry->limSmeState = psessionEntry->limPrevSmeState;
            else
                psessionEntry->limSmeState = eLIM_SME_OFFLINE_STATE;
            MTRACE(macTrace(pMac, TRACE_CODE_SME_STATE, psessionEntry->peSessionId, psessionEntry->limSmeState));
            // Send Promiscuous mode response to host
            limSendSmePromiscuousModeRsp(pMac);
        }
        else
        {
            if (pMlmDisassocCnf->resultCode != eSIR_SME_SUCCESS)
                psessionEntry->limSmeState = psessionEntry->limPrevSmeState;
            else
                psessionEntry->limSmeState = eLIM_SME_IDLE_STATE;
            MTRACE(macTrace(pMac, TRACE_CODE_SME_STATE, psessionEntry->peSessionId, psessionEntry->limSmeState));
            limSendSmeDisassocNtf(pMac, pMlmDisassocCnf->peerMacAddr,
                                  resultCode,
                                  pMlmDisassocCnf->disassocTrigger,
                                  pMlmDisassocCnf->aid,psessionEntry->smeSessionId,psessionEntry->transactionId,psessionEntry);
        }
    }
    else if  ( (psessionEntry->limSystemRole == eLIM_AP_ROLE)|| (psessionEntry->limSystemRole == eLIM_BT_AMP_AP_ROLE) )
    {
        limSendSmeDisassocNtf(pMac, pMlmDisassocCnf->peerMacAddr,
                              resultCode,
                              pMlmDisassocCnf->disassocTrigger,
                              pMlmDisassocCnf->aid,psessionEntry->smeSessionId,psessionEntry->transactionId,psessionEntry);
    }
} /*** end limProcessMlmDisassocCnf() ***/

/**
 * limProcessMlmDeauthInd()
 *
 *FUNCTION:
 * This function is called to processes MLM_DEAUTH_IND
 * message from MLM State machine.
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 *
 *NOTE:
 *
 * @param pMac       Pointer to Global MAC structure
 * @param pMsgBuf    A pointer to the MLM message buffer
 *
 * @return None
 */
void
limProcessMlmDeauthInd(tpAniSirGlobal pMac, tANI_U32 *pMsgBuf)
{
    tLimMlmDeauthInd  *pMlmDeauthInd;
    tpPESession psessionEntry;
    tANI_U8     sessionId;
    pMlmDeauthInd = (tLimMlmDeauthInd *) pMsgBuf;
    if((psessionEntry = peFindSessionByBssid(pMac,pMlmDeauthInd->peerMacAddr,&sessionId))== NULL)
    {
<<<<<<< HEAD
<<<<<<< HEAD
         PELOGE(limLog(pMac, LOGE,FL("session does not exist for given BSSId\n"));)
=======
         PELOGE(limLog(pMac, LOGE,FL("session does not exist for given BSSId"));)
>>>>>>> d97af3b... add prima wlan driver
=======
         PELOGE(limLog(pMac, LOGE,FL("session does not exist for given BSSId\n"));)
>>>>>>> 657b0e9... prima update
         return;
    }
    switch (psessionEntry->limSystemRole)
    {
        case eLIM_STA_IN_IBSS_ROLE:
            break;
        case eLIM_STA_ROLE:
        case eLIM_BT_AMP_STA_ROLE:
            psessionEntry->limSmeState = eLIM_SME_WT_DEAUTH_STATE;
            MTRACE(macTrace(pMac, TRACE_CODE_SME_STATE, psessionEntry->peSessionId, psessionEntry->limSmeState));

        default: // eLIM_AP_ROLE
            {
                PELOG1(limLog(pMac, LOG1,
<<<<<<< HEAD
<<<<<<< HEAD
                   FL("*** Received Deauthentication from staId=%d ***\n"),
=======
                   FL("*** Received Deauthentication from staId=%d ***"),
>>>>>>> d97af3b... add prima wlan driver
=======
                   FL("*** Received Deauthentication from staId=%d ***\n"),
>>>>>>> 657b0e9... prima update
                   pMlmDeauthInd->aid);)
            }
            // Send SME_DEAUTH_IND after Polaris cleanup
            // (after receiving LIM_MLM_PURGE_STA_IND)
            break;
    } // end switch (psessionEntry->limSystemRole)
} /*** end limProcessMlmDeauthInd() ***/

/**
 * limProcessMlmDeauthCnf()
 *
 *FUNCTION:
 * This function is called to processes MLM_DEAUTH_CNF
 * message from MLM State machine.
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 *
 *NOTE:
 *
 * @param pMac       Pointer to Global MAC structure
 * @param pMsgBuf    A pointer to the MLM message buffer
 *
 * @return None
 */
void
limProcessMlmDeauthCnf(tpAniSirGlobal pMac, tANI_U32 *pMsgBuf)
{
    tANI_U16                aid;
    tSirResultCodes         resultCode;
    tLimMlmDeauthCnf        *pMlmDeauthCnf;
    tpPESession             psessionEntry;

    if(pMsgBuf == NULL)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        PELOGE(limLog(pMac, LOGE,FL("Buffer is Pointing to NULL\n"));)
=======
        PELOGE(limLog(pMac, LOGE,FL("Buffer is Pointing to NULL"));)
>>>>>>> d97af3b... add prima wlan driver
=======
        PELOGE(limLog(pMac, LOGE,FL("Buffer is Pointing to NULL\n"));)
>>>>>>> 657b0e9... prima update
        return;
    }
    pMlmDeauthCnf = (tLimMlmDeauthCnf *) pMsgBuf;
    if((psessionEntry = peFindSessionBySessionId(pMac,pMlmDeauthCnf->sessionId))==NULL)
    {
<<<<<<< HEAD
<<<<<<< HEAD
         PELOGE(limLog(pMac, LOGE,FL("session does not exist for given session Id \n"));)
=======
         PELOGE(limLog(pMac, LOGE,FL("session does not exist for given session Id "));)
>>>>>>> d97af3b... add prima wlan driver
=======
         PELOGE(limLog(pMac, LOGE,FL("session does not exist for given session Id \n"));)
>>>>>>> 657b0e9... prima update
         return;
    }

    resultCode = (tSirResultCodes)
                 (pMlmDeauthCnf->deauthTrigger ==
                  eLIM_LINK_MONITORING_DEAUTH) ?
                 eSIR_SME_LOST_LINK_WITH_PEER_RESULT_CODE :
                 pMlmDeauthCnf->resultCode;
    aid = (psessionEntry->limSystemRole == eLIM_AP_ROLE) ?
          pMlmDeauthCnf->aid : 1;
    if ((psessionEntry->limSystemRole == eLIM_STA_ROLE)|| (psessionEntry->limSystemRole == eLIM_BT_AMP_STA_ROLE))
    {
<<<<<<< HEAD
<<<<<<< HEAD
        #if defined(ANI_AP_CLIENT_SDK)
        tSirMacAddr         nullMacAddr = {0, 0, 0, 0, 0, 0};
        #endif
=======
>>>>>>> d97af3b... add prima wlan driver
=======
        #if defined(ANI_AP_CLIENT_SDK)
        tSirMacAddr         nullMacAddr = {0, 0, 0, 0, 0, 0};
        #endif
>>>>>>> 657b0e9... prima update
        // Deauth Confirm from MLM
        if (psessionEntry->limSmeState != eLIM_SME_WT_DEAUTH_STATE)
        {
            /**
             * Should not have received Deauth confirm
             * from MLM in other states.
             * Log error
             */
            PELOGE(limLog(pMac, LOGE,
<<<<<<< HEAD
<<<<<<< HEAD
               FL("received unexpected MLM_DEAUTH_CNF in state %X\n"),
               psessionEntry->limSmeState);)
            return;
        }
#if defined(ANI_AP_CLIENT_SDK)
        // Whenever there is a disassoc notification, make sure the bssId is cleared so that
        // if the station finds the same AP to which it was associated, it can try to associate
        // with it again. If this is not done, the beacons/probe rsp from this AP will not be given
        // up to WSM and it never see this is AP unless a cga/reboot is done.
        palCopyMemory(pMac->hHdd, pMac->lim.gLimBssid, nullMacAddr, sizeof(tSirMacAddr));
        if (cfgSetStr(pMac, WNI_CFG_BSSID, nullMacAddr, sizeof(tSirMacAddr)) != eSIR_SUCCESS)
        {
            limLog(pMac, LOGP, FL("Could not update BSSID on CFG"));
        }
#endif
=======
               FL("received unexpected MLM_DEAUTH_CNF in state %X"),
               psessionEntry->limSmeState);)
            return;
        }
>>>>>>> d97af3b... add prima wlan driver
=======
               FL("received unexpected MLM_DEAUTH_CNF in state %X\n"),
               psessionEntry->limSmeState);)
            return;
        }
#if defined(ANI_AP_CLIENT_SDK)
        // Whenever there is a disassoc notification, make sure the bssId is cleared so that
        // if the station finds the same AP to which it was associated, it can try to associate
        // with it again. If this is not done, the beacons/probe rsp from this AP will not be given
        // up to WSM and it never see this is AP unless a cga/reboot is done.
        palCopyMemory(pMac->hHdd, pMac->lim.gLimBssid, nullMacAddr, sizeof(tSirMacAddr));
        if (cfgSetStr(pMac, WNI_CFG_BSSID, nullMacAddr, sizeof(tSirMacAddr)) != eSIR_SUCCESS)
        {
            limLog(pMac, LOGP, FL("Could not update BSSID on CFG"));
        }
#endif
>>>>>>> 657b0e9... prima update
        if (pMlmDeauthCnf->resultCode == eSIR_SME_SUCCESS)
        {
            psessionEntry->limSmeState = eLIM_SME_IDLE_STATE;
            PELOG1(limLog(pMac, LOG1,
<<<<<<< HEAD
<<<<<<< HEAD
                   FL("*** Deauthenticated with BSS ***\n"));)
=======
                   FL("*** Deauthenticated with BSS ***"));)
>>>>>>> d97af3b... add prima wlan driver
=======
                   FL("*** Deauthenticated with BSS ***\n"));)
>>>>>>> 657b0e9... prima update
        }
        else
            psessionEntry->limSmeState = psessionEntry->limPrevSmeState;
        MTRACE(macTrace(pMac, TRACE_CODE_SME_STATE, psessionEntry->peSessionId, psessionEntry->limSmeState));

        if (pMac->lim.gLimRspReqd)
            pMac->lim.gLimRspReqd = false;
    }
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
#if (WNI_POLARIS_FW_PACKAGE == ADVANCED) && defined(ANI_PRODUCT_TYPE_AP)
    // BP deauthenticated by AP or vice versa
    // Send SME_DISASSOC_RSP to host.
    limSendSmeDisassocNtf(pMac, pMlmDeauthCnf->peerMacAddr,
                          resultCode,
                          pMlmDeauthCnf->deauthTrigger,
                          aid);
#else
<<<<<<< HEAD
=======
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
    // On STA or on BASIC AP, send SME_DEAUTH_RSP to host
    limSendSmeDeauthNtf(pMac, pMlmDeauthCnf->peerMacAddr,
                        resultCode,
                        pMlmDeauthCnf->deauthTrigger,
                        aid,psessionEntry->smeSessionId,psessionEntry->transactionId);
<<<<<<< HEAD
<<<<<<< HEAD
#endif
=======
>>>>>>> d97af3b... add prima wlan driver
=======
#endif
>>>>>>> 657b0e9... prima update
} /*** end limProcessMlmDeauthCnf() ***/

/**
 * limProcessMlmPurgeStaInd()
 *
 *FUNCTION:
 * This function is called to processes MLM_PURGE_STA_IND
 * message from MLM State machine.
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 *
 *NOTE:
 *
 * @param pMac       Pointer to Global MAC structure
 * @param pMsgBuf    A pointer to the MLM message buffer
 *
 * @return None
 */
void
limProcessMlmPurgeStaInd(tpAniSirGlobal pMac, tANI_U32 *pMsgBuf)
{
    tSirResultCodes      resultCode;
    tpLimMlmPurgeStaInd  pMlmPurgeStaInd;
    tpPESession          psessionEntry;
<<<<<<< HEAD
<<<<<<< HEAD
#if defined(ANI_AP_CLIENT_SDK)
    tSirMacAddr         nullMacAddr = {0, 0, 0, 0, 0, 0};
#endif
    if(pMsgBuf == NULL)
    {
        PELOGE(limLog(pMac, LOGE,FL("Buffer is Pointing to NULL\n"));)
=======
    if(pMsgBuf == NULL)
    {
        PELOGE(limLog(pMac, LOGE,FL("Buffer is Pointing to NULL"));)
>>>>>>> d97af3b... add prima wlan driver
=======
#if defined(ANI_AP_CLIENT_SDK)
    tSirMacAddr         nullMacAddr = {0, 0, 0, 0, 0, 0};
#endif
    if(pMsgBuf == NULL)
    {
        PELOGE(limLog(pMac, LOGE,FL("Buffer is Pointing to NULL\n"));)
>>>>>>> 657b0e9... prima update
        return;
    }
    pMlmPurgeStaInd = (tpLimMlmPurgeStaInd) pMsgBuf;
    if((psessionEntry = peFindSessionBySessionId(pMac,pMlmPurgeStaInd->sessionId))==NULL)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        PELOGE(limLog(pMac, LOGE,FL("session does not exist for given bssId\n"));)
=======
        PELOGE(limLog(pMac, LOGE,FL("session does not exist for given bssId"));)
>>>>>>> d97af3b... add prima wlan driver
=======
        PELOGE(limLog(pMac, LOGE,FL("session does not exist for given bssId\n"));)
>>>>>>> 657b0e9... prima update
        return;
    }
    // Purge STA indication from MLM
    resultCode = (tSirResultCodes) pMlmPurgeStaInd->reasonCode;
    switch (psessionEntry->limSystemRole)
    {
        case eLIM_STA_IN_IBSS_ROLE:
            break;
        case eLIM_STA_ROLE:
        case eLIM_BT_AMP_STA_ROLE:
        default: // eLIM_AP_ROLE
            if ((psessionEntry->limSystemRole == eLIM_STA_ROLE) &&
                (psessionEntry->limSmeState !=
                                       eLIM_SME_WT_DISASSOC_STATE) &&
                (psessionEntry->limSmeState != eLIM_SME_WT_DEAUTH_STATE))
            {
                /**
                 * Should not have received
                 * Purge STA indication
                 * from MLM in other states.
                 * Log error
                 */
                PELOGE(limLog(pMac, LOGE,
<<<<<<< HEAD
<<<<<<< HEAD
                   FL("received unexpected MLM_PURGE_STA_IND in state %X\n"),
=======
                   FL("received unexpected MLM_PURGE_STA_IND in state %X"),
>>>>>>> d97af3b... add prima wlan driver
=======
                   FL("received unexpected MLM_PURGE_STA_IND in state %X\n"),
>>>>>>> 657b0e9... prima update
                   psessionEntry->limSmeState);)
                break;
            }
            PELOG1(limLog(pMac, LOG1,
<<<<<<< HEAD
<<<<<<< HEAD
               FL("*** Polaris cleanup completed for staId=%d ***\n"),
=======
               FL("*** Polaris cleanup completed for staId=%d ***"),
>>>>>>> d97af3b... add prima wlan driver
=======
               FL("*** Polaris cleanup completed for staId=%d ***\n"),
>>>>>>> 657b0e9... prima update
               pMlmPurgeStaInd->aid);)
            if ((psessionEntry->limSystemRole == eLIM_STA_ROLE)||(psessionEntry->limSystemRole == eLIM_BT_AMP_STA_ROLE))
            {
                psessionEntry->limSmeState = eLIM_SME_IDLE_STATE;
                MTRACE(macTrace(pMac, TRACE_CODE_SME_STATE, psessionEntry->peSessionId, psessionEntry->limSmeState));

<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
#if defined(ANI_AP_CLIENT_SDK)
                // Whenever there is a disassoc notification, make sure the bssId is cleared so that
                // if the station finds the same AP to which it was associated, it can try to associate
                // with it again. If this is not done, the beacons/probe rsp from this AP will not be given
                // up to WSM and it never see this is AP unless a cga/reboot is done.
                palCopyMemory(pMac->hHdd, pMac->lim.gLimBssid, nullMacAddr, sizeof(tSirMacAddr));
                if (cfgSetStr(pMac, WNI_CFG_BSSID, nullMacAddr, sizeof(tSirMacAddr)) != eSIR_SUCCESS)
                {
                    limLog(pMac, LOGP, FL("Could not update BSSID on CFG"));
                }
#endif
<<<<<<< HEAD
            }
            if (pMlmPurgeStaInd->purgeTrigger == eLIM_PEER_ENTITY_DEAUTH)
            {
#if (WNI_POLARIS_FW_PACKAGE == ADVANCED) && defined(ANI_PRODUCT_TYPE_AP)
                // BP deauthenticated by AP or vice versa
                // Send SME_DISASSOC_IND to host.
                limSendSmeDisassocNtf(pMac,
                                    pMlmPurgeStaInd->peerMacAddr,
                                    resultCode,
                                    pMlmPurgeStaInd->purgeTrigger,
                                    pMlmPurgeStaInd->aid,psessionEntry);
#else
=======
            }
            if (pMlmPurgeStaInd->purgeTrigger == eLIM_PEER_ENTITY_DEAUTH)
            {
>>>>>>> d97af3b... add prima wlan driver
=======
            }
            if (pMlmPurgeStaInd->purgeTrigger == eLIM_PEER_ENTITY_DEAUTH)
            {
#if (WNI_POLARIS_FW_PACKAGE == ADVANCED) && defined(ANI_PRODUCT_TYPE_AP)
                // BP deauthenticated by AP or vice versa
                // Send SME_DISASSOC_IND to host.
                limSendSmeDisassocNtf(pMac,
                                    pMlmPurgeStaInd->peerMacAddr,
                                    resultCode,
                                    pMlmPurgeStaInd->purgeTrigger,
                                    pMlmPurgeStaInd->aid,psessionEntry);
#else
>>>>>>> 657b0e9... prima update
                limSendSmeDeauthNtf(pMac,
                            pMlmPurgeStaInd->peerMacAddr,
                            resultCode,
                            pMlmPurgeStaInd->purgeTrigger,
                            pMlmPurgeStaInd->aid,psessionEntry->smeSessionId,psessionEntry->transactionId);
<<<<<<< HEAD
<<<<<<< HEAD
#endif
=======
>>>>>>> d97af3b... add prima wlan driver
=======
#endif
>>>>>>> 657b0e9... prima update
            }
            else
                limSendSmeDisassocNtf(pMac,
                                    pMlmPurgeStaInd->peerMacAddr,
                                    resultCode,
                                    pMlmPurgeStaInd->purgeTrigger,
                                    pMlmPurgeStaInd->aid,psessionEntry->smeSessionId,psessionEntry->transactionId,psessionEntry);
    } // end switch (psessionEntry->limSystemRole)
} /*** end limProcessMlmPurgeStaInd() ***/

/**
 * limProcessMlmSetKeysCnf()
 *
 *FUNCTION:
 * This function is called to processes MLM_SETKEYS_CNF
 * message from MLM State machine.
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 *
 *NOTE:
 *
 * @param pMac       Pointer to Global MAC structure
 * @param pMsgBuf    A pointer to the MLM message buffer
 *
 * @return None
 */
void
limProcessMlmSetKeysCnf(tpAniSirGlobal pMac, tANI_U32 *pMsgBuf)
{
    // Prepare and send SME_SETCONTEXT_RSP message
    tLimMlmSetKeysCnf   *pMlmSetKeysCnf;
    tpPESession        psessionEntry;

    if(pMsgBuf == NULL)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        PELOGE(limLog(pMac, LOGE,FL("Buffer is Pointing to NULL\n"));)
=======
        PELOGE(limLog(pMac, LOGE,FL("Buffer is Pointing to NULL"));)
>>>>>>> d97af3b... add prima wlan driver
=======
        PELOGE(limLog(pMac, LOGE,FL("Buffer is Pointing to NULL\n"));)
>>>>>>> 657b0e9... prima update
        return;
    }
    pMlmSetKeysCnf = (tLimMlmSetKeysCnf *) pMsgBuf;
    if ((psessionEntry = peFindSessionBySessionId(pMac, pMlmSetKeysCnf->sessionId))== NULL)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        PELOGE(limLog(pMac, LOGE,FL("session does not exist for given sessionId \n"));)
        return;
    }
    limLog( pMac, LOG1,
        FL("Received MLM_SETKEYS_CNF with resultCode = %d\n"),
        pMlmSetKeysCnf->resultCode );
    limSendSmeSetContextRsp(pMac,
                            pMlmSetKeysCnf->peerMacAddr,
#ifdef ANI_PRODUCT_TYPE_AP
                            pMlmSetKeysCnf->aid,
#else
                            1,
#endif
=======
        PELOGE(limLog(pMac, LOGE,FL("session does not exist for given sessionId "));)
=======
        PELOGE(limLog(pMac, LOGE,FL("session does not exist for given sessionId \n"));)
>>>>>>> 657b0e9... prima update
        return;
    }
    limLog( pMac, LOG1,
        FL("Received MLM_SETKEYS_CNF with resultCode = %d\n"),
        pMlmSetKeysCnf->resultCode );
    limSendSmeSetContextRsp(pMac,
                            pMlmSetKeysCnf->peerMacAddr,
#ifdef ANI_PRODUCT_TYPE_AP
                            pMlmSetKeysCnf->aid,
#else
                            1,
<<<<<<< HEAD
>>>>>>> d97af3b... add prima wlan driver
=======
#endif
>>>>>>> 657b0e9... prima update
                            (tSirResultCodes) pMlmSetKeysCnf->resultCode,psessionEntry,psessionEntry->smeSessionId,
                            psessionEntry->transactionId);
} /*** end limProcessMlmSetKeysCnf() ***/
/**
 * limProcessMlmRemoveKeyCnf()
 *
 *FUNCTION:
 * This function is called to processes MLM_REMOVEKEY_CNF
 * message from MLM State machine.
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 *
 *NOTE:
 *
 * @param pMac       Pointer to Global MAC structure
 * @param pMsgBuf    A pointer to the MLM message buffer
 *
 * @return None
 */
void
limProcessMlmRemoveKeyCnf(tpAniSirGlobal pMac, tANI_U32 *pMsgBuf)
{
    // Prepare and send SME_REMOVECONTEXT_RSP message
    tLimMlmRemoveKeyCnf *pMlmRemoveKeyCnf;
    tpPESession          psessionEntry;

    if(pMsgBuf == NULL)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        PELOGE(limLog(pMac, LOGE,FL("Buffer is Pointing to NULL\n"));)
=======
        PELOGE(limLog(pMac, LOGE,FL("Buffer is Pointing to NULL"));)
>>>>>>> d97af3b... add prima wlan driver
=======
        PELOGE(limLog(pMac, LOGE,FL("Buffer is Pointing to NULL\n"));)
>>>>>>> 657b0e9... prima update
        return;
    }
    pMlmRemoveKeyCnf = (tLimMlmRemoveKeyCnf *) pMsgBuf;
    if((psessionEntry = peFindSessionBySessionId(pMac,pMlmRemoveKeyCnf->sessionId))== NULL)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        PELOGE(limLog(pMac, LOGE,FL("session Does not exist for given session Id\n"));)
        return;
    }
    limLog( pMac, LOG1,
        FL("Received MLM_REMOVEKEYS_CNF with resultCode = %d\n"),
=======
        PELOGE(limLog(pMac, LOGE,FL("session Does not exist for given session Id"));)
        return;
    }
    limLog( pMac, LOG1,
        FL("Received MLM_REMOVEKEYS_CNF with resultCode = %d"),
>>>>>>> d97af3b... add prima wlan driver
=======
        PELOGE(limLog(pMac, LOGE,FL("session Does not exist for given session Id\n"));)
        return;
    }
    limLog( pMac, LOG1,
        FL("Received MLM_REMOVEKEYS_CNF with resultCode = %d\n"),
>>>>>>> 657b0e9... prima update
        pMlmRemoveKeyCnf->resultCode );
    limSendSmeRemoveKeyRsp(pMac,
                           pMlmRemoveKeyCnf->peerMacAddr,
                            (tSirResultCodes) pMlmRemoveKeyCnf->resultCode,psessionEntry,
                            psessionEntry->smeSessionId,psessionEntry->transactionId);
} /*** end limProcessMlmRemoveKeyCnf() ***/


/**
 * limHandleSmeJoinResult()
 *
 *FUNCTION:
 * This function is called to process join/auth/assoc failures
 * upon receiving MLM_JOIN/AUTH/ASSOC_CNF with a failure code or
 * MLM_ASSOC_CNF with a success code in case of STA role and
 * MLM_JOIN_CNF with success in case of STA in IBSS role.
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 *
 *NOTE:
 *
 * @param  pMac         Pointer to Global MAC structure
 * @param  resultCode   Failure code to be sent
 *
 *
 * @return None
 */
static void
limHandleSmeJoinResult(tpAniSirGlobal pMac, tSirResultCodes resultCode, tANI_U16 protStatusCode, tpPESession psessionEntry)
{
    tpDphHashNode pStaDs = NULL;
    tANI_U8         smesessionId;
    tANI_U16        smetransactionId;

    /* Newly Added on oct 11 th*/
    if(psessionEntry == NULL)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        PELOGE(limLog(pMac, LOGE,FL("psessionEntry is NULL \n"));)
=======
        PELOGE(limLog(pMac, LOGE,FL("psessionEntry is NULL "));)
>>>>>>> d97af3b... add prima wlan driver
=======
        PELOGE(limLog(pMac, LOGE,FL("psessionEntry is NULL \n"));)
>>>>>>> 657b0e9... prima update
        return;
    }
    smesessionId = psessionEntry->smeSessionId;
    smetransactionId = psessionEntry->transactionId;
    /* When associations is failed , delete the session created  and pass NULL  to  limsendsmeJoinReassocRsp() */
    if(resultCode != eSIR_SME_SUCCESS)
    {
          pStaDs = dphGetHashEntry(pMac, DPH_STA_HASH_INDEX_PEER, &psessionEntry->dph.dphHashTable);
          if (pStaDs != NULL)
          {
            pStaDs->mlmStaContext.disassocReason = eSIR_MAC_UNSPEC_FAILURE_REASON;
            pStaDs->mlmStaContext.cleanupTrigger = eLIM_JOIN_FAILURE;
            pStaDs->mlmStaContext.resultCode = resultCode;
            pStaDs->mlmStaContext.protStatusCode = protStatusCode;
            //Done: 7-27-2009. JIM_FIX_ME: at the end of limCleanupRxPath, make sure PE is sending eWNI_SME_JOIN_RSP to SME
            limCleanupRxPath(pMac, pStaDs, psessionEntry);
<<<<<<< HEAD
<<<<<<< HEAD
            palFreeMemory( pMac->hHdd, psessionEntry->pLimJoinReq);
=======
            vos_mem_free(psessionEntry->pLimJoinReq);
>>>>>>> d97af3b... add prima wlan driver
=======
            palFreeMemory( pMac->hHdd, psessionEntry->pLimJoinReq);
>>>>>>> 657b0e9... prima update
            psessionEntry->pLimJoinReq = NULL;
            return;
        }
    }

<<<<<<< HEAD
<<<<<<< HEAD
    palFreeMemory( pMac->hHdd, psessionEntry->pLimJoinReq);
=======
    vos_mem_free(psessionEntry->pLimJoinReq);
>>>>>>> d97af3b... add prima wlan driver
=======
    palFreeMemory( pMac->hHdd, psessionEntry->pLimJoinReq);
>>>>>>> 657b0e9... prima update
    psessionEntry->pLimJoinReq = NULL;
    //Delete teh session if JOIN failure occurred.
    if(resultCode != eSIR_SME_SUCCESS)
    {
        if(NULL != psessionEntry)
        {
           if(limSetLinkState(pMac, eSIR_LINK_IDLE_STATE,psessionEntry->bssId,
                psessionEntry->selfMacAddr, NULL, NULL) != eSIR_SUCCESS)
<<<<<<< HEAD
<<<<<<< HEAD
               PELOGE(limLog(pMac, LOGE,  FL("Failed to set the LinkState.\n"));)
=======
               PELOGE(limLog(pMac, LOGE,  FL("Failed to set the LinkState."));)
>>>>>>> d97af3b... add prima wlan driver
=======
               PELOGE(limLog(pMac, LOGE,  FL("Failed to set the LinkState.\n"));)
>>>>>>> 657b0e9... prima update
            peDeleteSession(pMac,psessionEntry);
            psessionEntry = NULL;
        }
    }
    limSendSmeJoinReassocRsp(pMac, eWNI_SME_JOIN_RSP, resultCode, protStatusCode,psessionEntry,
                                                smesessionId,  smetransactionId);
} /*** end limHandleSmeJoinResult() ***/

/**
 * limHandleSmeReaasocResult()
 *
 *FUNCTION:
 * This function is called to process reassoc failures
 * upon receiving REASSOC_CNF with a failure code or
 * MLM_REASSOC_CNF with a success code in case of STA role 
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 *
 *NOTE:
 *
 * @param  pMac         Pointer to Global MAC structure
 * @param  resultCode   Failure code to be sent
 *
 *
 * @return None
 */
static void
limHandleSmeReaasocResult(tpAniSirGlobal pMac, tSirResultCodes resultCode, tANI_U16 protStatusCode, tpPESession psessionEntry)
{
    tpDphHashNode pStaDs = NULL;
    tANI_U8         smesessionId;
    tANI_U16        smetransactionId;

    if(psessionEntry == NULL)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        PELOGE(limLog(pMac, LOGE,FL("psessionEntry is NULL \n"));)
=======
        PELOGE(limLog(pMac, LOGE,FL("psessionEntry is NULL "));)
>>>>>>> d97af3b... add prima wlan driver
=======
        PELOGE(limLog(pMac, LOGE,FL("psessionEntry is NULL \n"));)
>>>>>>> 657b0e9... prima update
        return;
    }
    smesessionId = psessionEntry->smeSessionId;
    smetransactionId = psessionEntry->transactionId;
    /* When associations is failed , delete the session created  and pass NULL  to  limsendsmeJoinReassocRsp() */
    if(resultCode != eSIR_SME_SUCCESS)
    {
          pStaDs = dphGetHashEntry(pMac, DPH_STA_HASH_INDEX_PEER, &psessionEntry->dph.dphHashTable);
          if (pStaDs != NULL)
          {
            pStaDs->mlmStaContext.disassocReason = eSIR_MAC_UNSPEC_FAILURE_REASON;
            pStaDs->mlmStaContext.cleanupTrigger = eLIM_JOIN_FAILURE;
            pStaDs->mlmStaContext.resultCode = resultCode;
            pStaDs->mlmStaContext.protStatusCode = protStatusCode;
            limCleanupRxPath(pMac, pStaDs, psessionEntry);
            return;
        }
    }

    //Delete teh session if REASSOC failure occurred.
    if(resultCode != eSIR_SME_SUCCESS)
    {
        if(NULL != psessionEntry)
        {
            peDeleteSession(pMac,psessionEntry);
            psessionEntry = NULL;
        }
    }
    limSendSmeJoinReassocRsp(pMac, eWNI_SME_REASSOC_RSP, resultCode, protStatusCode,psessionEntry,
                                                smesessionId,  smetransactionId);
} /*** end limHandleSmeReassocResult() ***/

/**
  * limProcessMlmAddStaRsp()
 *
 *FUNCTION:
 * This function is called to process a WDA_ADD_STA_RSP from HAL.
 * Upon receipt of this message from HAL, MLME -
 * > Determines the "state" in which this message was received
 * > Forwards it to the appropriate callback
 *
 *ASSUMPTIONS:
 *
 *NOTE:
 *
 * @param  pMac      Pointer to Global MAC structure
 * @param  tSirMsgQ  The MsgQ header, which contains the response buffer
 *
 * @return None
 */
void limProcessMlmAddStaRsp( tpAniSirGlobal pMac, tpSirMsgQ limMsgQ,tpPESession psessionEntry )
{
    //we need to process the deferred message since the initiating req. there might be nested request.
    //in the case of nested request the new request initiated from the response will take care of resetting
    //the deffered flag.
    SET_LIM_PROCESS_DEFD_MESGS(pMac, true);
    if ((psessionEntry->limSystemRole == eLIM_BT_AMP_AP_ROLE)
<<<<<<< HEAD
<<<<<<< HEAD
#ifdef WLAN_SOFTAP_FEATURE
    || (psessionEntry->limSystemRole == eLIM_AP_ROLE)
#endif
=======
    || (psessionEntry->limSystemRole == eLIM_AP_ROLE)
>>>>>>> d97af3b... add prima wlan driver
=======
#ifdef WLAN_SOFTAP_FEATURE
    || (psessionEntry->limSystemRole == eLIM_AP_ROLE)
#endif
>>>>>>> 657b0e9... prima update
    )
    {
        limProcessBtAmpApMlmAddStaRsp(pMac, limMsgQ,psessionEntry);
        return;
    }
<<<<<<< HEAD
<<<<<<< HEAD
#if defined(ANI_PRODUCT_TYPE_CLIENT) || defined(ANI_AP_CLIENT_SDK)
    limProcessStaMlmAddStaRsp(pMac, limMsgQ,psessionEntry);
#endif
=======
    limProcessStaMlmAddStaRsp(pMac, limMsgQ,psessionEntry);
>>>>>>> d97af3b... add prima wlan driver
=======
#if defined(ANI_PRODUCT_TYPE_CLIENT) || defined(ANI_AP_CLIENT_SDK)
    limProcessStaMlmAddStaRsp(pMac, limMsgQ,psessionEntry);
#endif
>>>>>>> 657b0e9... prima update
}
void limProcessStaMlmAddStaRsp( tpAniSirGlobal pMac, tpSirMsgQ limMsgQ ,tpPESession psessionEntry)
{
    tLimMlmAssocCnf mlmAssocCnf;
    tpDphHashNode   pStaDs;
    tANI_U32        mesgType = LIM_MLM_ASSOC_CNF;
    tpAddStaParams  pAddStaParams = (tpAddStaParams) limMsgQ->bodyptr;

    if(NULL == pAddStaParams )
    {
<<<<<<< HEAD
<<<<<<< HEAD
        limLog( pMac, LOGE, FL( "Encountered NULL Pointer\n" ));
        return;
    }
    if( eHAL_STATUS_SUCCESS == pAddStaParams->status )
    {
        if( eLIM_MLM_WT_ADD_STA_RSP_STATE != psessionEntry->limMlmState)
        {
            //TODO: any response to be sent out here ?
            limLog( pMac, LOGE,
                FL( "Received unexpected WDA_ADD_STA_RSP in state %X\n" ),
=======
        limLog( pMac, LOGE, FL( "Encountered NULL Pointer" ));
=======
        limLog( pMac, LOGE, FL( "Encountered NULL Pointer\n" ));
>>>>>>> 657b0e9... prima update
        return;
    }
    if( eHAL_STATUS_SUCCESS == pAddStaParams->status )
    {
        if( eLIM_MLM_WT_ADD_STA_RSP_STATE != psessionEntry->limMlmState)
        {
            //TODO: any response to be sent out here ?
            limLog( pMac, LOGE,
<<<<<<< HEAD
                FL( "Received unexpected WDA_ADD_STA_RSP in state %X" ),
>>>>>>> d97af3b... add prima wlan driver
=======
                FL( "Received unexpected WDA_ADD_STA_RSP in state %X\n" ),
>>>>>>> 657b0e9... prima update
                psessionEntry->limMlmState);
            mlmAssocCnf.resultCode = (tSirResultCodes) eSIR_SME_REFUSED;
            goto end;
        }
    if (psessionEntry->limSmeState == eLIM_SME_WT_REASSOC_STATE)
             mesgType = LIM_MLM_REASSOC_CNF;
        //
        // Update the DPH Hash Entry for this STA
        // with proper state info
        //
        pStaDs = dphGetHashEntry( pMac, DPH_STA_HASH_INDEX_PEER, &psessionEntry->dph.dphHashTable);
        if( NULL != pStaDs)
            pStaDs->mlmStaContext.mlmState = eLIM_MLM_LINK_ESTABLISHED_STATE;
        else
            limLog( pMac, LOGW,
<<<<<<< HEAD
<<<<<<< HEAD
            FL( "Unable to get the DPH Hash Entry for AID - %d\n" ),
=======
            FL( "Unable to get the DPH Hash Entry for AID - %d" ),
>>>>>>> d97af3b... add prima wlan driver
=======
            FL( "Unable to get the DPH Hash Entry for AID - %d\n" ),
>>>>>>> 657b0e9... prima update
            DPH_STA_HASH_INDEX_PEER);
        psessionEntry->limMlmState = eLIM_MLM_LINK_ESTABLISHED_STATE;
        MTRACE(macTrace(pMac, TRACE_CODE_MLM_STATE, psessionEntry->peSessionId, psessionEntry->limMlmState));
        /*
        * Storing the self StaIndex(Generated by HAL) in session context,
        * instead of storing it in DPH Hash entry for Self STA.
        * DPH entry for the self STA stores the sta index for the BSS entry
        * to which the STA is associated.
        */
        psessionEntry->staId = pAddStaParams->staIdx;
        //if the AssocRsp frame is not acknowledged, then keep alive timer will take care of the state
<<<<<<< HEAD
<<<<<<< HEAD
        limReactivateHeartBeatTimer(pMac, psessionEntry);
=======
#ifdef WLAN_ACTIVEMODE_OFFLOAD_FEATURE
        if(!IS_ACTIVEMODE_OFFLOAD_FEATURE_ENABLE)
#endif
        {
           limReactivateHeartBeatTimer(pMac, psessionEntry);
        }
>>>>>>> d97af3b... add prima wlan driver
=======
        limReactivateHeartBeatTimer(pMac, psessionEntry);
>>>>>>> 657b0e9... prima update
        MTRACE(macTrace(pMac, TRACE_CODE_TIMER_ACTIVATE, psessionEntry->peSessionId, eLIM_KEEPALIVE_TIMER));

        //assign the sessionId to the timer Object
        pMac->lim.limTimers.gLimKeepaliveTimer.sessionId = psessionEntry->peSessionId;
        if (tx_timer_activate(&pMac->lim.limTimers.gLimKeepaliveTimer) != TX_SUCCESS)
<<<<<<< HEAD
<<<<<<< HEAD
            limLog(pMac, LOGP, FL("Cannot activate keepalive timer.\n"));
#ifdef WLAN_DEBUG
        pMac->lim.gLimNumLinkEsts++;
#endif
=======
            limLog(pMac, LOGP, FL("Cannot activate keepalive timer."));
#ifdef WLAN_DEBUG
        pMac->lim.gLimNumLinkEsts++;
#endif
#ifdef FEATURE_WLAN_TDLS
       /* initialize TDLS peer related data */
       limInitTdlsData(pMac,psessionEntry);
#endif
>>>>>>> d97af3b... add prima wlan driver
=======
            limLog(pMac, LOGP, FL("Cannot activate keepalive timer.\n"));
#ifdef WLAN_DEBUG
        pMac->lim.gLimNumLinkEsts++;
#endif
>>>>>>> 657b0e9... prima update
        // Return Assoc confirm to SME with success
        // FIXME_GEN4 - Need the correct ASSOC RSP code to
        // be passed in here....
        //mlmAssocCnf.resultCode = (tSirResultCodes) assoc.statusCode;
        mlmAssocCnf.resultCode = (tSirResultCodes) eSIR_SME_SUCCESS;
    }
    else
    {
<<<<<<< HEAD
<<<<<<< HEAD
        limLog( pMac, LOGW, FL( "ADD_STA failed!\n"));
=======
        limLog( pMac, LOGE, FL( "ADD_STA failed!"));
>>>>>>> d97af3b... add prima wlan driver
=======
        limLog( pMac, LOGW, FL( "ADD_STA failed!\n"));
>>>>>>> 657b0e9... prima update
        mlmAssocCnf.resultCode = (tSirResultCodes) eSIR_SME_REFUSED;
    }
end:
    if( 0 != limMsgQ->bodyptr )
    {
<<<<<<< HEAD
<<<<<<< HEAD
      palFreeMemory( pMac->hHdd, (void *) pAddStaParams );
=======
      vos_mem_free(pAddStaParams);
>>>>>>> d97af3b... add prima wlan driver
=======
      palFreeMemory( pMac->hHdd, (void *) pAddStaParams );
>>>>>>> 657b0e9... prima update
    }
    /* Updating PE session Id*/
    mlmAssocCnf.sessionId = psessionEntry->peSessionId;
    limPostSmeMessage( pMac, mesgType, (tANI_U32 *) &mlmAssocCnf );
<<<<<<< HEAD
<<<<<<< HEAD
=======
    if (true == psessionEntry->fDeauthReceived)
    {
       psessionEntry->fDeauthReceived = false;
    }
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
    return;
}
void limProcessMlmDelBssRsp( tpAniSirGlobal pMac, tpSirMsgQ limMsgQ,tpPESession psessionEntry)
{
 //we need to process the deferred message since the initiating req. there might be nested request.
  //in the case of nested request the new request initiated from the response will take care of resetting
  //the deffered flag.
   // tpPESession         psessionEntry;
  //  tpDeleteBssParams   pDeleteBssParams =( tpDeleteBssParams)limMsgQ->bodyptr;
   // if((psessionEntry = peFindSessionBySessionId(pMac,pDeleteBssParams->sessionId)) == NULL)
  //  {
<<<<<<< HEAD
<<<<<<< HEAD
   //     limLog( pMac, LOGE, FL( "Session deos not exist with given sessionId\n" ));
=======
   //     limLog( pMac, LOGE, FL( "Session deos not exist with given sessionId" ));
>>>>>>> d97af3b... add prima wlan driver
=======
   //     limLog( pMac, LOGE, FL( "Session deos not exist with given sessionId\n" ));
>>>>>>> 657b0e9... prima update
   //     return;
  //  }
  SET_LIM_PROCESS_DEFD_MESGS(pMac, true);

    if (((psessionEntry->limSystemRole == eLIM_BT_AMP_AP_ROLE)  ||
         (psessionEntry->limSystemRole == eLIM_BT_AMP_STA_ROLE)
<<<<<<< HEAD
<<<<<<< HEAD
#ifdef WLAN_SOFTAP_FEATURE
         || (psessionEntry->limSystemRole == eLIM_AP_ROLE)
#endif
=======
         || (psessionEntry->limSystemRole == eLIM_AP_ROLE)
>>>>>>> d97af3b... add prima wlan driver
=======
#ifdef WLAN_SOFTAP_FEATURE
         || (psessionEntry->limSystemRole == eLIM_AP_ROLE)
#endif
>>>>>>> 657b0e9... prima update
         ) &&
        (psessionEntry->statypeForBss == STA_ENTRY_SELF))
    {
        limProcessBtAmpApMlmDelBssRsp(pMac, limMsgQ,psessionEntry);
        return;
    }
<<<<<<< HEAD
<<<<<<< HEAD
#if defined(ANI_PRODUCT_TYPE_CLIENT) || defined(ANI_AP_CLIENT_SDK)
    limProcessStaMlmDelBssRsp(pMac, limMsgQ,psessionEntry);
=======
    limProcessStaMlmDelBssRsp(pMac, limMsgQ,psessionEntry);

   if(!limIsInMCC(pMac))
   {
      WDA_TrafficStatsTimerActivate(FALSE);
   }

#ifdef WLAN_FEATURE_11W
    if (psessionEntry->limRmfEnabled)
    {
        if ( eSIR_SUCCESS != limSendExcludeUnencryptInd(pMac, TRUE, psessionEntry) )
        {
            limLog( pMac, LOGE,
                    FL( "Could not send down Exclude Unencrypted Indication!" ),
                    psessionEntry->limMlmState );
        }
    }
>>>>>>> d97af3b... add prima wlan driver
=======
#if defined(ANI_PRODUCT_TYPE_CLIENT) || defined(ANI_AP_CLIENT_SDK)
    limProcessStaMlmDelBssRsp(pMac, limMsgQ,psessionEntry);
>>>>>>> 657b0e9... prima update
#endif
}

void limProcessStaMlmDelBssRsp( tpAniSirGlobal pMac, tpSirMsgQ limMsgQ,tpPESession psessionEntry)
{
    tpDeleteBssParams pDelBssParams =   (tpDeleteBssParams) limMsgQ->bodyptr;
    tpDphHashNode pStaDs =              dphGetHashEntry(pMac, DPH_STA_HASH_INDEX_PEER, &psessionEntry->dph.dphHashTable);
    tSirResultCodes statusCode =        eSIR_SME_SUCCESS;
<<<<<<< HEAD
<<<<<<< HEAD
    if( eHAL_STATUS_SUCCESS == pDelBssParams->status )
    {
        PELOGW(limLog( pMac, LOGW,
                      FL( "STA received the DEL_BSS_RSP for BSSID: %X.\n"),pDelBssParams->bssIdx);)
=======

    if (NULL == pDelBssParams)
    {
        limLog( pMac, LOGE, FL( "Invalid body pointer in message"));
        goto end;
    }
    if( eHAL_STATUS_SUCCESS == pDelBssParams->status )
    {
        PELOGW(limLog( pMac, LOGW,
                      FL( "STA received the DEL_BSS_RSP for BSSID: %X."),pDelBssParams->bssIdx);)
>>>>>>> d97af3b... add prima wlan driver
=======
    if( eHAL_STATUS_SUCCESS == pDelBssParams->status )
    {
        PELOGW(limLog( pMac, LOGW,
                      FL( "STA received the DEL_BSS_RSP for BSSID: %X.\n"),pDelBssParams->bssIdx);)
>>>>>>> 657b0e9... prima update
        if (limSetLinkState(pMac, eSIR_LINK_IDLE_STATE, psessionEntry->bssId,
             psessionEntry->selfMacAddr, NULL, NULL) != eSIR_SUCCESS)

        {
<<<<<<< HEAD
<<<<<<< HEAD
            PELOGE(limLog( pMac, LOGE, FL( "Failure in setting link state to IDLE\n"));)
=======
            PELOGE(limLog( pMac, LOGE, FL( "Failure in setting link state to IDLE"));)
>>>>>>> d97af3b... add prima wlan driver
=======
            PELOGE(limLog( pMac, LOGE, FL( "Failure in setting link state to IDLE\n"));)
>>>>>>> 657b0e9... prima update
            statusCode = eSIR_SME_REFUSED;
            goto end;
        }
        if(pStaDs == NULL)
        {
<<<<<<< HEAD
<<<<<<< HEAD
            limLog( pMac, LOGE, FL( "DPH Entry for STA 1 missing.\n"));
=======
            limLog( pMac, LOGE, FL( "DPH Entry for STA 1 missing."));
>>>>>>> d97af3b... add prima wlan driver
=======
            limLog( pMac, LOGE, FL( "DPH Entry for STA 1 missing.\n"));
>>>>>>> 657b0e9... prima update
            statusCode = eSIR_SME_REFUSED;
            goto end;
        }
         if( eLIM_MLM_WT_DEL_BSS_RSP_STATE != pStaDs->mlmStaContext.mlmState)
        {
<<<<<<< HEAD
<<<<<<< HEAD
            PELOGE(limLog( pMac, LOGE, FL( "Received unexpected WDA_DEL_BSS_RSP in state %X\n" ),
=======
            PELOGE(limLog( pMac, LOGE, FL( "Received unexpected WDA_DEL_BSS_RSP in state %X" ),
>>>>>>> d97af3b... add prima wlan driver
=======
            PELOGE(limLog( pMac, LOGE, FL( "Received unexpected WDA_DEL_BSS_RSP in state %X\n" ),
>>>>>>> 657b0e9... prima update
                           pStaDs->mlmStaContext.mlmState);)
            statusCode = eSIR_SME_REFUSED;
            goto end;
        }
        PELOG1(limLog( pMac, LOG1, FL("STA AssocID %d MAC "), pStaDs->assocId );
        limPrintMacAddr(pMac, pStaDs->staAddr, LOG1);)
    }
    else
    {
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
        limLog( pMac, LOGP, FL( "DEL BSS failed!\n" ) );
        if( NULL != pDelBssParams )
        {
            palFreeMemory( pMac->hHdd, (void *) pDelBssParams );
    	}
<<<<<<< HEAD
=======
        limLog( pMac, LOGE, FL( "DEL BSS failed!" ) );
        vos_mem_free(pDelBssParams);
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
        return;
    }
   end:
     if( 0 != limMsgQ->bodyptr )
     {
<<<<<<< HEAD
<<<<<<< HEAD
        palFreeMemory( pMac->hHdd, (void *) pDelBssParams );
=======
        vos_mem_free(pDelBssParams);
>>>>>>> d97af3b... add prima wlan driver
=======
        palFreeMemory( pMac->hHdd, (void *) pDelBssParams );
>>>>>>> 657b0e9... prima update
     }
    if(pStaDs == NULL)
          return;
    if ( ((psessionEntry->limSystemRole  == eLIM_STA_ROLE) || (psessionEntry->limSystemRole  == eLIM_BT_AMP_STA_ROLE)) &&
                (psessionEntry->limSmeState != eLIM_SME_WT_DISASSOC_STATE  &&
                 psessionEntry->limSmeState != eLIM_SME_WT_DEAUTH_STATE) &&
                 pStaDs->mlmStaContext.cleanupTrigger != eLIM_JOIN_FAILURE)
   {
        /** The Case where the DelBss is invoked from
        *   context of other than normal DisAssoc / Deauth OR
        *  as part of Join Failure.
        */
        limHandleDelBssInReAssocContext(pMac, pStaDs,psessionEntry);
        return;
    }
    limPrepareAndSendDelStaCnf(pMac, pStaDs, statusCode,psessionEntry);
    return;
}

void limProcessBtAmpApMlmDelBssRsp( tpAniSirGlobal pMac, tpSirMsgQ limMsgQ,tpPESession psessionEntry)
{
    tSirResultCodes rc = eSIR_SME_SUCCESS;
    tSirRetStatus status;
    tpDeleteBssParams pDelBss = (tpDeleteBssParams) limMsgQ->bodyptr;
    tSirMacAddr             nullBssid = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

    if(psessionEntry == NULL)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        limLog(pMac, LOGE,FL("Session entry passed is NULL\n"));
        if(pDelBss != NULL)
            palFreeMemory( pMac->hHdd, (void *) pDelBss );
=======
        limLog(pMac, LOGE,FL("Session entry passed is NULL"));
        if(pDelBss != NULL)
            vos_mem_free(pDelBss);
>>>>>>> d97af3b... add prima wlan driver
=======
        limLog(pMac, LOGE,FL("Session entry passed is NULL\n"));
        if(pDelBss != NULL)
            palFreeMemory( pMac->hHdd, (void *) pDelBss );
>>>>>>> 657b0e9... prima update
        return;
    }

    if (pDelBss == NULL)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        PELOGE(limLog(pMac, LOGE, FL("BSS: DEL_BSS_RSP with no body!\n"));)
=======
        PELOGE(limLog(pMac, LOGE, FL("BSS: DEL_BSS_RSP with no body!"));)
>>>>>>> d97af3b... add prima wlan driver
=======
        PELOGE(limLog(pMac, LOGE, FL("BSS: DEL_BSS_RSP with no body!\n"));)
>>>>>>> 657b0e9... prima update
        rc = eSIR_SME_REFUSED;
        goto end;
    }
    pMac->lim.gLimMlmState = eLIM_MLM_IDLE_STATE;
<<<<<<< HEAD
<<<<<<< HEAD
=======
    MTRACE(macTrace(pMac, TRACE_CODE_MLM_STATE, NO_SESSION, pMac->lim.gLimMlmState));

>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
    if( eLIM_MLM_WT_DEL_BSS_RSP_STATE != psessionEntry->limMlmState)
    {
            limLog( pMac, LOGE,
               FL( "Received unexpected WDA_DEL_BSS_RSP in state %X" ),
               psessionEntry->limMlmState);
            rc = eSIR_SME_REFUSED;
           goto end;
    }
    if (pDelBss->status != eHAL_STATUS_SUCCESS)
    {
        limLog(pMac, LOGE, FL("BSS: DEL_BSS_RSP error (%x) Bss %d "),
               pDelBss->status, pDelBss->bssIdx);
        rc = eSIR_SME_STOP_BSS_FAILURE;
        goto end;
    }
    status = limSetLinkState(pMac, eSIR_LINK_IDLE_STATE, nullBssid,
           psessionEntry->selfMacAddr, NULL, NULL);
    if (status != eSIR_SUCCESS)
    {
        rc = eSIR_SME_REFUSED;
        goto end;
    }
    /** Softmac may send all the buffered packets right after resuming the transmission hence
     * to occupy the medium during non channel occupancy period. So resume the transmission after
     * HAL gives back the response.
     */
#if 0 //TODO: How to handle this per session
    if (LIM_IS_RADAR_DETECTED(pMac))
    {
         limFrameTransmissionControl(pMac, eLIM_TX_BSS_BUT_BEACON, eLIM_RESUME_TX);
         LIM_SET_RADAR_DETECTED(pMac, eANI_BOOLEAN_FALSE);
    }
#endif
    dphHashTableClassInit(pMac, &psessionEntry->dph.dphHashTable);//TBD-RAJESH is it needed ?
    limDeletePreAuthList(pMac);
<<<<<<< HEAD
<<<<<<< HEAD
#ifdef WLAN_SOFTAP_FEATURE
    //Initialize number of associated stations during cleanup
    pMac->lim.gLimNumOfCurrentSTAs = 0;
#endif
=======
    //Initialize number of associated stations during cleanup
    psessionEntry->gLimNumOfCurrentSTAs = 0;
>>>>>>> d97af3b... add prima wlan driver
=======
#ifdef WLAN_SOFTAP_FEATURE
    //Initialize number of associated stations during cleanup
    pMac->lim.gLimNumOfCurrentSTAs = 0;
#endif
>>>>>>> 657b0e9... prima update
    end:
    limSendSmeRsp(pMac, eWNI_SME_STOP_BSS_RSP, rc,  psessionEntry->smeSessionId,  psessionEntry->transactionId);
    peDeleteSession(pMac, psessionEntry);

    if(pDelBss != NULL)
<<<<<<< HEAD
<<<<<<< HEAD
        palFreeMemory( pMac->hHdd, (void *) pDelBss );
=======
        vos_mem_free(pDelBss);
>>>>>>> d97af3b... add prima wlan driver
=======
        palFreeMemory( pMac->hHdd, (void *) pDelBss );
>>>>>>> 657b0e9... prima update
}

void limProcessMlmDelStaRsp( tpAniSirGlobal pMac, tpSirMsgQ limMsgQ )
{
 //we need to process the deferred message since the initiating req. there might be nested request.
  //in the case of nested request the new request initiated from the response will take care of resetting
  //the deffered flag.

    tpPESession         psessionEntry;
    tpDeleteStaParams   pDeleteStaParams;
    pDeleteStaParams = (tpDeleteStaParams)limMsgQ->bodyptr;
    SET_LIM_PROCESS_DEFD_MESGS(pMac, true);
<<<<<<< HEAD
<<<<<<< HEAD
    if((psessionEntry = peFindSessionBySessionId(pMac,pDeleteStaParams->sessionId))==NULL)
    {
        limLog(pMac, LOGP,FL("Session Does not exist for given sessionID\n"));
        if(pDeleteStaParams != NULL)
            palFreeMemory( pMac->hHdd, (void *) pDeleteStaParams );
=======

    if(NULL == pDeleteStaParams ||
       NULL == (psessionEntry = peFindSessionBySessionId(pMac, pDeleteStaParams->sessionId)))
=======
    if((psessionEntry = peFindSessionBySessionId(pMac,pDeleteStaParams->sessionId))==NULL)
>>>>>>> 657b0e9... prima update
    {
        limLog(pMac, LOGP,FL("Session Does not exist for given sessionID\n"));
        if(pDeleteStaParams != NULL)
<<<<<<< HEAD
            vos_mem_free(pDeleteStaParams);
>>>>>>> d97af3b... add prima wlan driver
=======
            palFreeMemory( pMac->hHdd, (void *) pDeleteStaParams );
>>>>>>> 657b0e9... prima update
        return;
    }

    if ((psessionEntry->limSystemRole == eLIM_BT_AMP_AP_ROLE)
<<<<<<< HEAD
<<<<<<< HEAD
#ifdef WLAN_SOFTAP_FEATURE
      || (psessionEntry->limSystemRole == eLIM_AP_ROLE)
#endif
=======
      || (psessionEntry->limSystemRole == eLIM_AP_ROLE)
>>>>>>> d97af3b... add prima wlan driver
=======
#ifdef WLAN_SOFTAP_FEATURE
      || (psessionEntry->limSystemRole == eLIM_AP_ROLE)
#endif
>>>>>>> 657b0e9... prima update
    )
    {
        limProcessBtAmpApMlmDelStaRsp(pMac,limMsgQ,psessionEntry);
        return;
    }
<<<<<<< HEAD
<<<<<<< HEAD
#if defined(ANI_PRODUCT_TYPE_CLIENT) || defined(ANI_AP_CLIENT_SDK)
    limProcessStaMlmDelStaRsp(pMac, limMsgQ,psessionEntry);
#endif
=======
    limProcessStaMlmDelStaRsp(pMac, limMsgQ,psessionEntry);
>>>>>>> d97af3b... add prima wlan driver
=======
#if defined(ANI_PRODUCT_TYPE_CLIENT) || defined(ANI_AP_CLIENT_SDK)
    limProcessStaMlmDelStaRsp(pMac, limMsgQ,psessionEntry);
#endif
>>>>>>> 657b0e9... prima update
}

void limProcessBtAmpApMlmDelStaRsp( tpAniSirGlobal pMac, tpSirMsgQ limMsgQ,tpPESession psessionEntry)
{
    tpDeleteStaParams pDelStaParams = (tpDeleteStaParams) limMsgQ->bodyptr;
    tpDphHashNode pStaDs;
    tSirResultCodes statusCode = eSIR_SME_SUCCESS;
    if(limMsgQ->bodyptr == NULL)
    {
      return;
    }

    pStaDs = dphGetHashEntry(pMac, pDelStaParams->assocId, &psessionEntry->dph.dphHashTable);
    if(pStaDs == NULL)
    {
        limLog( pMac, LOGE,
<<<<<<< HEAD
<<<<<<< HEAD
             FL( "DPH Entry for STA %X missing.\n"), pDelStaParams->assocId);
        statusCode = eSIR_SME_REFUSED;
        palFreeMemory( pMac->hHdd, (void *) pDelStaParams );
=======
             FL( "DPH Entry for STA %X missing."), pDelStaParams->assocId);
        statusCode = eSIR_SME_REFUSED;
        vos_mem_free(pDelStaParams);
>>>>>>> d97af3b... add prima wlan driver
=======
             FL( "DPH Entry for STA %X missing.\n"), pDelStaParams->assocId);
        statusCode = eSIR_SME_REFUSED;
        palFreeMemory( pMac->hHdd, (void *) pDelStaParams );
>>>>>>> 657b0e9... prima update

        return;
    }
    if( eHAL_STATUS_SUCCESS == pDelStaParams->status )
    {
        limLog( pMac, LOGW,
<<<<<<< HEAD
<<<<<<< HEAD
                   FL( "AP received the DEL_STA_RSP for assocID: %X.\n"), pDelStaParams->assocId);
=======
                   FL( "AP received the DEL_STA_RSP for assocID: %X."), pDelStaParams->assocId);
>>>>>>> d97af3b... add prima wlan driver
=======
                   FL( "AP received the DEL_STA_RSP for assocID: %X.\n"), pDelStaParams->assocId);
>>>>>>> 657b0e9... prima update

        if(( eLIM_MLM_WT_DEL_STA_RSP_STATE != pStaDs->mlmStaContext.mlmState) &&
           ( eLIM_MLM_WT_ASSOC_DEL_STA_RSP_STATE != pStaDs->mlmStaContext.mlmState))
        {
            limLog( pMac, LOGE,
<<<<<<< HEAD
<<<<<<< HEAD
              FL( "Received unexpected WDA_DEL_STA_RSP in state %s for staId %d assocId %d \n" ),
=======
              FL( "Received unexpected WDA_DEL_STA_RSP in state %s for staId %d assocId %d " ),
>>>>>>> d97af3b... add prima wlan driver
=======
              FL( "Received unexpected WDA_DEL_STA_RSP in state %s for staId %d assocId %d \n" ),
>>>>>>> 657b0e9... prima update
               limMlmStateStr(pStaDs->mlmStaContext.mlmState), pStaDs->staIndex, pStaDs->assocId);
            statusCode = eSIR_SME_REFUSED;
            goto end;
        }

        limLog( pMac, LOG1,
            FL("Deleted STA AssocID %d staId %d MAC "),
            pStaDs->assocId, pStaDs->staIndex);
        limPrintMacAddr(pMac, pStaDs->staAddr, LOG1);
       if(eLIM_MLM_WT_ASSOC_DEL_STA_RSP_STATE == pStaDs->mlmStaContext.mlmState)
       {
<<<<<<< HEAD
<<<<<<< HEAD
            palFreeMemory( pMac->hHdd, (void *) pDelStaParams );
            if (limAddSta(pMac, pStaDs,psessionEntry) != eSIR_SUCCESS)
            {
                PELOGE(limLog(pMac, LOGE,
                       FL("could not Add STA with assocId=%d\n"),
=======
            vos_mem_free(pDelStaParams);
            if (limAddSta(pMac, pStaDs, false, psessionEntry) != eSIR_SUCCESS)
            {
                PELOGE(limLog(pMac, LOGE,
                       FL("could not Add STA with assocId=%d"),
>>>>>>> d97af3b... add prima wlan driver
=======
            palFreeMemory( pMac->hHdd, (void *) pDelStaParams );
            if (limAddSta(pMac, pStaDs,psessionEntry) != eSIR_SUCCESS)
            {
                PELOGE(limLog(pMac, LOGE,
                       FL("could not Add STA with assocId=%d\n"),
>>>>>>> 657b0e9... prima update
                       pStaDs->assocId);)
              // delete the TS if it has already been added.
               // send the response with error status.
                if(pStaDs->qos.addtsPresent)
                {
                  tpLimTspecInfo pTspecInfo;
                  if(eSIR_SUCCESS == limTspecFindByAssocId(pMac, pStaDs->assocId,
                            &pStaDs->qos.addts.tspec, &pMac->lim.tspecInfo[0], &pTspecInfo))
                  {
                    limAdmitControlDeleteTS(pMac, pStaDs->assocId, &pStaDs->qos.addts.tspec.tsinfo,
                                                            NULL, &pTspecInfo->idx);
                  }
                }
                limRejectAssociation(pMac,
                         pStaDs->staAddr,
                         pStaDs->mlmStaContext.subType,
                         true, pStaDs->mlmStaContext.authType,
                         pStaDs->assocId, true,
                         (tSirResultCodes) eSIR_MAC_UNSPEC_FAILURE_STATUS,
                         psessionEntry);
            }
            return;
        }
    }
    else
    {
        limLog( pMac, LOGW,
<<<<<<< HEAD
<<<<<<< HEAD
             FL( "DEL STA failed!\n" ));
        statusCode = eSIR_SME_REFUSED;
    }
    end:
    palFreeMemory( pMac->hHdd, (void *) pDelStaParams );
=======
             FL( "DEL STA failed!" ));
        statusCode = eSIR_SME_REFUSED;
    }
    end:
    vos_mem_free(pDelStaParams);
>>>>>>> d97af3b... add prima wlan driver
=======
             FL( "DEL STA failed!\n" ));
        statusCode = eSIR_SME_REFUSED;
    }
    end:
    palFreeMemory( pMac->hHdd, (void *) pDelStaParams );
>>>>>>> 657b0e9... prima update
    if(eLIM_MLM_WT_ASSOC_DEL_STA_RSP_STATE != pStaDs->mlmStaContext.mlmState)
    {
       limPrepareAndSendDelStaCnf(pMac, pStaDs, statusCode,psessionEntry);
    }
    return;
}

void limProcessStaMlmDelStaRsp( tpAniSirGlobal pMac, tpSirMsgQ limMsgQ,tpPESession psessionEntry)
{
    tSirResultCodes   statusCode    = eSIR_SME_SUCCESS;
    tpDeleteStaParams pDelStaParams = (tpDeleteStaParams) limMsgQ->bodyptr;
    tpDphHashNode     pStaDs        = NULL;
    if(NULL == pDelStaParams )
    {
<<<<<<< HEAD
<<<<<<< HEAD
        limLog( pMac, LOGE, FL( "Encountered NULL Pointer\n" ));
=======
        limLog( pMac, LOGE, FL( "Encountered NULL Pointer" ));
>>>>>>> d97af3b... add prima wlan driver
=======
        limLog( pMac, LOGE, FL( "Encountered NULL Pointer\n" ));
>>>>>>> 657b0e9... prima update
        goto end;
    }
    if( eHAL_STATUS_SUCCESS == pDelStaParams->status )
    {
        pStaDs = dphGetHashEntry(pMac, DPH_STA_HASH_INDEX_PEER, &psessionEntry->dph.dphHashTable);
        if (pStaDs == NULL)
        {
            //TODO: any response to be sent out here ?
<<<<<<< HEAD
<<<<<<< HEAD
            limLog( pMac, LOGE, FL( "DPH Entry for STA %X missing.\n"),
=======
            limLog( pMac, LOGE, FL( "DPH Entry for STA %X missing."),
>>>>>>> d97af3b... add prima wlan driver
=======
            limLog( pMac, LOGE, FL( "DPH Entry for STA %X missing.\n"),
>>>>>>> 657b0e9... prima update
                    pDelStaParams->assocId);
            statusCode = eSIR_SME_REFUSED;
            goto end;
        }
        if( eLIM_MLM_WT_DEL_STA_RSP_STATE != psessionEntry->limMlmState)
        {
            //TODO: any response to be sent out here ?
<<<<<<< HEAD
<<<<<<< HEAD
            limLog( pMac, LOGE, FL( "Received unexpected WDA_DELETE_STA_RSP in state %s\n" ),
=======
            limLog( pMac, LOGE, FL( "Received unexpected WDA_DELETE_STA_RSP in state %s" ),
>>>>>>> d97af3b... add prima wlan driver
=======
            limLog( pMac, LOGE, FL( "Received unexpected WDA_DELETE_STA_RSP in state %s\n" ),
>>>>>>> 657b0e9... prima update
                  limMlmStateStr(psessionEntry->limMlmState));
            statusCode = eSIR_SME_REFUSED;
            goto end;
        }
        PELOG1(limLog( pMac, LOG1, FL("STA AssocID %d MAC "), pStaDs->assocId );
        limPrintMacAddr(pMac, pStaDs->staAddr, LOG1);)
<<<<<<< HEAD
<<<<<<< HEAD
        limLog( pMac, LOGW, FL( "DEL_STA_RSP received for assocID: %X\n"), pDelStaParams->assocId);
        //we must complete all cleanup related to delSta before calling limDelBSS.
        if( 0 != limMsgQ->bodyptr )
        {
            palFreeMemory( pMac->hHdd, (void *) pDelStaParams );
=======
        limLog( pMac, LOGW, FL( "DEL_STA_RSP received for assocID: %X"), pDelStaParams->assocId);
        //we must complete all cleanup related to delSta before calling limDelBSS.
        if( 0 != limMsgQ->bodyptr )
        {
            vos_mem_free(pDelStaParams);
>>>>>>> d97af3b... add prima wlan driver
=======
        limLog( pMac, LOGW, FL( "DEL_STA_RSP received for assocID: %X\n"), pDelStaParams->assocId);
        //we must complete all cleanup related to delSta before calling limDelBSS.
        if( 0 != limMsgQ->bodyptr )
        {
            palFreeMemory( pMac->hHdd, (void *) pDelStaParams );
>>>>>>> 657b0e9... prima update
        }
        statusCode = (tSirResultCodes) limDelBss(pMac, pStaDs, 0,psessionEntry);
        return;
    }
    else
    {
<<<<<<< HEAD
<<<<<<< HEAD
        limLog( pMac, LOGW, FL( "DEL_STA failed!\n" ));
=======
        limLog( pMac, LOGE, FL( "DEL_STA failed for sta Id %d" ), pDelStaParams->staIdx);
>>>>>>> d97af3b... add prima wlan driver
=======
        limLog( pMac, LOGW, FL( "DEL_STA failed!\n" ));
>>>>>>> 657b0e9... prima update
        statusCode = eSIR_SME_REFUSED;
    }
end:
    if( 0 != limMsgQ->bodyptr )
    {
<<<<<<< HEAD
<<<<<<< HEAD
        palFreeMemory( pMac->hHdd, (void *) pDelStaParams );
=======
        vos_mem_free(pDelStaParams);
>>>>>>> d97af3b... add prima wlan driver
=======
        palFreeMemory( pMac->hHdd, (void *) pDelStaParams );
>>>>>>> 657b0e9... prima update
    }
    return;
}

void limProcessBtAmpApMlmAddStaRsp( tpAniSirGlobal pMac, tpSirMsgQ limMsgQ,tpPESession psessionEntry)
{
    tpAddStaParams pAddStaParams = (tpAddStaParams) limMsgQ->bodyptr;
<<<<<<< HEAD
<<<<<<< HEAD
    tpDphHashNode pStaDs = dphGetHashEntry(pMac, pAddStaParams->assocId, &psessionEntry->dph.dphHashTable);
    if(pStaDs == NULL)
    {
        //TODO: any response to be sent out here ?
        limLog( pMac, LOGE, FL( "DPH Entry for STA %X missing.\n"), pAddStaParams->assocId);
=======
    tpDphHashNode pStaDs = NULL;

    if (NULL == pAddStaParams)
    {
        limLog( pMac, LOGE, FL( "Invalid body pointer in message"));
        goto end;
    }

    pStaDs = dphGetHashEntry(pMac, pAddStaParams->assocId, &psessionEntry->dph.dphHashTable);
    if(pStaDs == NULL)
    {
        //TODO: any response to be sent out here ?
        limLog( pMac, LOGE, FL( "DPH Entry for STA %X missing."), pAddStaParams->assocId);
>>>>>>> d97af3b... add prima wlan driver
=======
    tpDphHashNode pStaDs = dphGetHashEntry(pMac, pAddStaParams->assocId, &psessionEntry->dph.dphHashTable);
    if(pStaDs == NULL)
    {
        //TODO: any response to be sent out here ?
        limLog( pMac, LOGE, FL( "DPH Entry for STA %X missing.\n"), pAddStaParams->assocId);
>>>>>>> 657b0e9... prima update
        goto end;
    }
    //
    // TODO & FIXME_GEN4
    // Need to inspect tSirMsgQ.reserved for a valid Dialog token!
    //
    //TODO: any check for pMac->lim.gLimMlmState ?
    if( eLIM_MLM_WT_ADD_STA_RSP_STATE != pStaDs->mlmStaContext.mlmState)
    {
        //TODO: any response to be sent out here ?
        limLog( pMac, LOGE,
<<<<<<< HEAD
<<<<<<< HEAD
                FL( "Received unexpected WDA_ADD_STA_RSP in state %X\n" ),
=======
                FL( "Received unexpected WDA_ADD_STA_RSP in state %X" ),
>>>>>>> d97af3b... add prima wlan driver
=======
                FL( "Received unexpected WDA_ADD_STA_RSP in state %X\n" ),
>>>>>>> 657b0e9... prima update
                pStaDs->mlmStaContext.mlmState);
        goto end;
    }
    if(eHAL_STATUS_SUCCESS != pAddStaParams->status)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        PELOGE(limLog(pMac, LOGE, FL("Error! rcvd delSta rsp from HAL with status %d\n"),pAddStaParams->status);)
=======
        PELOGE(limLog(pMac, LOGE, FL("Error! rcvd delSta rsp from HAL with status %d"),pAddStaParams->status);)
>>>>>>> d97af3b... add prima wlan driver
=======
        PELOGE(limLog(pMac, LOGE, FL("Error! rcvd delSta rsp from HAL with status %d\n"),pAddStaParams->status);)
>>>>>>> 657b0e9... prima update
        limRejectAssociation(pMac, pStaDs->staAddr,
                 pStaDs->mlmStaContext.subType,
                 true, pStaDs->mlmStaContext.authType,
                 pStaDs->assocId, true,
                 (tSirResultCodes) eSIR_MAC_UNSPEC_FAILURE_STATUS,
                 psessionEntry);
        goto end;
    }
    pStaDs->bssId = pAddStaParams->bssIdx;
    pStaDs->staIndex = pAddStaParams->staIdx;
    //if the AssocRsp frame is not acknowledged, then keep alive timer will take care of the state
    pStaDs->valid = 1;
    pStaDs->mlmStaContext.mlmState = eLIM_MLM_WT_ASSOC_CNF_STATE;
    limLog( pMac, LOG1,
            FL("STA AssocID %d staId %d MAC "),
            pStaDs->assocId,
            pStaDs->staIndex);
    limPrintMacAddr(pMac, pStaDs->staAddr, LOG1);

    /* For BTAMP-AP, the flow sequence shall be:
     * 1) PE sends eWNI_SME_ASSOC_IND to SME
     * 2) PE receives eWNI_SME_ASSOC_CNF from SME
     * 3) BTAMP-AP sends Re/Association Response to BTAMP-STA
     */
    limSendMlmAssocInd(pMac, pStaDs, psessionEntry);
    // fall though to reclaim the original Add STA Response message
end:
    if( 0 != limMsgQ->bodyptr )
    {
<<<<<<< HEAD
<<<<<<< HEAD
        palFreeMemory( pMac->hHdd, (void *) pAddStaParams );
=======
        vos_mem_free(pAddStaParams);
>>>>>>> d97af3b... add prima wlan driver
=======
        palFreeMemory( pMac->hHdd, (void *) pAddStaParams );
>>>>>>> 657b0e9... prima update
    }
    return;
}

/**
 * limProcessApMlmAddBssRsp()
 *
 *FUNCTION:
 * This function is called to process a WDA_ADD_BSS_RSP from HAL.
 * Upon receipt of this message from HAL, MLME -
 * > Validates the result of WDA_ADD_BSS_REQ
 * > Init other remaining LIM variables
 * > Init the AID pool, for that BSSID
 * > Init the Pre-AUTH list, for that BSSID
 * > Create LIM timers, specific to that BSSID
 * > Init DPH related parameters that are specific to that BSSID
 * > TODO - When do we do the actual change channel?
 *
 *LOGIC:
 * SME sends eWNI_SME_START_BSS_REQ to LIM
 * LIM sends LIM_MLM_START_REQ to MLME
 * MLME sends WDA_ADD_BSS_REQ to HAL
 * HAL responds with WDA_ADD_BSS_RSP to MLME
 * MLME responds with LIM_MLM_START_CNF to LIM
 * LIM responds with eWNI_SME_START_BSS_RSP to SME
 *
 *ASSUMPTIONS:
 * tSirMsgQ.body is allocated by MLME during limProcessMlmStartReq
 * tSirMsgQ.body will now be freed by this routine
 *
 *NOTE:
 *
 * @param  pMac      Pointer to Global MAC structure
 * @param  tSirMsgQ  The MsgQ header, which contains the response buffer
 *
 * @return None
 */
static void
limProcessApMlmAddBssRsp( tpAniSirGlobal pMac, tpSirMsgQ limMsgQ)
{
    tLimMlmStartCnf mlmStartCnf;
    tANI_U32 val;
    tpPESession psessionEntry;
//    tANI_U8     sessionId;
    tpAddBssParams pAddBssParams = (tpAddBssParams) limMsgQ->bodyptr;
    if(NULL == pAddBssParams )
    {
<<<<<<< HEAD
<<<<<<< HEAD
        limLog( pMac, LOGE, FL( "Encountered NULL Pointer\n" ));
=======
        limLog( pMac, LOGE, FL( "Encountered NULL Pointer" ));
>>>>>>> d97af3b... add prima wlan driver
=======
        limLog( pMac, LOGE, FL( "Encountered NULL Pointer\n" ));
>>>>>>> 657b0e9... prima update
        goto end;
    }
    //TBD: free the memory before returning, do it for all places where lookup fails.
    if((psessionEntry = peFindSessionBySessionId(pMac,pAddBssParams->sessionId))== NULL)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        PELOGE(limLog(pMac, LOGE,FL("session does not exist for given sessionId\n"));)
        if( NULL != pAddBssParams )
            palFreeMemory( pMac->hHdd, (void *) pAddBssParams );
=======
        PELOGE(limLog(pMac, LOGE,FL("session does not exist for given sessionId"));)
        if( NULL != pAddBssParams )
            vos_mem_free(pAddBssParams);
>>>>>>> d97af3b... add prima wlan driver
=======
        PELOGE(limLog(pMac, LOGE,FL("session does not exist for given sessionId\n"));)
        if( NULL != pAddBssParams )
            palFreeMemory( pMac->hHdd, (void *) pAddBssParams );
>>>>>>> 657b0e9... prima update
        return;
    }
    /* Update PE session Id*/
    mlmStartCnf.sessionId = pAddBssParams->sessionId;
    if( eHAL_STATUS_SUCCESS == pAddBssParams->status )
    {
<<<<<<< HEAD
<<<<<<< HEAD
        PELOG2(limLog(pMac, LOG2, FL("WDA_ADD_BSS_RSP returned with eHAL_STATUS_SUCCESS\n"));)
=======
        PELOG2(limLog(pMac, LOG2, FL("WDA_ADD_BSS_RSP returned with eHAL_STATUS_SUCCESS"));)
>>>>>>> d97af3b... add prima wlan driver
=======
        PELOG2(limLog(pMac, LOG2, FL("WDA_ADD_BSS_RSP returned with eHAL_STATUS_SUCCESS\n"));)
>>>>>>> 657b0e9... prima update
        if (limSetLinkState(pMac, eSIR_LINK_AP_STATE,psessionEntry->bssId,
              psessionEntry->selfMacAddr, NULL, NULL) != eSIR_SUCCESS )
            goto end;
        // Set MLME state
        psessionEntry->limMlmState = eLIM_MLM_BSS_STARTED_STATE;
        MTRACE(macTrace(pMac, TRACE_CODE_MLM_STATE, psessionEntry->peSessionId,  psessionEntry->limMlmState));
        if( eSIR_IBSS_MODE == pAddBssParams->bssType )
        {
            /** IBSS is 'active' when we receive
             * Beacon frames from other STAs that are part of same IBSS.
             * Mark internal state as inactive until then.
             */
            psessionEntry->limIbssActive = false;
            psessionEntry->statypeForBss = STA_ENTRY_PEER; //to know session created for self/peer
            limResetHBPktCount( psessionEntry );
            limHeartBeatDeactivateAndChangeTimer(pMac, psessionEntry);
            MTRACE(macTrace(pMac, TRACE_CODE_TIMER_ACTIVATE, psessionEntry->peSessionId, eLIM_HEART_BEAT_TIMER));
<<<<<<< HEAD
<<<<<<< HEAD
            if (limActivateHearBeatTimer(pMac) != TX_SUCCESS)
                limLog(pMac, LOGP, FL("could not activate Heartbeat timer\n"));
        }
        psessionEntry->bssIdx     = (tANI_U8) pAddBssParams->bssIdx;

#ifdef ANI_PRODUCT_TYPE_AP
        psessionEntry->limSystemRole = eLIM_AP_ROLE;
#else
        psessionEntry->limSystemRole = eLIM_STA_IN_IBSS_ROLE;
#endif

#ifdef WLAN_SOFTAP_FEATURE
=======
            if (limActivateHearBeatTimer(pMac, psessionEntry) != TX_SUCCESS)
                limLog(pMac, LOGP, FL("could not activate Heartbeat timer"));
=======
            if (limActivateHearBeatTimer(pMac) != TX_SUCCESS)
                limLog(pMac, LOGP, FL("could not activate Heartbeat timer\n"));
>>>>>>> 657b0e9... prima update
        }
        psessionEntry->bssIdx     = (tANI_U8) pAddBssParams->bssIdx;

#ifdef ANI_PRODUCT_TYPE_AP
        psessionEntry->limSystemRole = eLIM_AP_ROLE;
#else
        psessionEntry->limSystemRole = eLIM_STA_IN_IBSS_ROLE;
#endif

<<<<<<< HEAD
>>>>>>> d97af3b... add prima wlan driver
=======
#ifdef WLAN_SOFTAP_FEATURE
>>>>>>> 657b0e9... prima update
        if ( eSIR_INFRA_AP_MODE == pAddBssParams->bssType )
            psessionEntry->limSystemRole = eLIM_AP_ROLE;
        else
            psessionEntry->limSystemRole = eLIM_STA_IN_IBSS_ROLE;
<<<<<<< HEAD
<<<<<<< HEAD
#endif
        schEdcaProfileUpdate(pMac, psessionEntry);
        limInitPreAuthList(pMac);
        limInitAIDpool(pMac,psessionEntry);
=======
        schEdcaProfileUpdate(pMac, psessionEntry);
        limInitPreAuthList(pMac);
        limInitPeerIdxpool(pMac,psessionEntry);
>>>>>>> d97af3b... add prima wlan driver
=======
#endif
        schEdcaProfileUpdate(pMac, psessionEntry);
        limInitPreAuthList(pMac);
        limInitAIDpool(pMac,psessionEntry);
>>>>>>> 657b0e9... prima update
        // Create timers used by LIM
        if (!pMac->lim.gLimTimersCreated)
            limCreateTimers(pMac);

        // Start OLBC timer
        if (tx_timer_activate(&pMac->lim.limTimers.gLimUpdateOlbcCacheTimer) != TX_SUCCESS)
        {
<<<<<<< HEAD
<<<<<<< HEAD
            limLog(pMac, LOGE, FL("tx_timer_activate failed\n"));
=======
            limLog(pMac, LOGE, FL("tx_timer_activate failed"));
>>>>>>> d97af3b... add prima wlan driver
=======
            limLog(pMac, LOGE, FL("tx_timer_activate failed\n"));
>>>>>>> 657b0e9... prima update
        }

        /* Update the lim global gLimTriggerBackgroundScanDuringQuietBss */
        if( eSIR_SUCCESS != wlan_cfgGetInt( pMac, WNI_CFG_TRIG_STA_BK_SCAN, &val ))
<<<<<<< HEAD
<<<<<<< HEAD
            limLog( pMac, LOGP, FL("Failed to get WNI_CFG_TRIG_STA_BK_SCAN!\n"));
=======
            limLog( pMac, LOGP, FL("Failed to get WNI_CFG_TRIG_STA_BK_SCAN!"));
>>>>>>> d97af3b... add prima wlan driver
=======
            limLog( pMac, LOGP, FL("Failed to get WNI_CFG_TRIG_STA_BK_SCAN!\n"));
>>>>>>> 657b0e9... prima update
        pMac->lim.gLimTriggerBackgroundScanDuringQuietBss = (val) ? 1 : 0;
        // Apply previously set configuration at HW
        limApplyConfiguration(pMac,psessionEntry);
        psessionEntry->staId = pAddBssParams->staContext.staIdx;
        mlmStartCnf.resultCode  = eSIR_SME_SUCCESS;
    }
    else
    {
<<<<<<< HEAD
<<<<<<< HEAD
        limLog( pMac, LOGE, FL( "WDA_ADD_BSS_REQ failed with status %d\n" ),pAddBssParams->status );
=======
        limLog( pMac, LOGE, FL( "WDA_ADD_BSS_REQ failed with status %d" ),pAddBssParams->status );
>>>>>>> d97af3b... add prima wlan driver
=======
        limLog( pMac, LOGE, FL( "WDA_ADD_BSS_REQ failed with status %d\n" ),pAddBssParams->status );
>>>>>>> 657b0e9... prima update
        mlmStartCnf.resultCode = eSIR_SME_HAL_SEND_MESSAGE_FAIL;
    }
    limPostSmeMessage( pMac, LIM_MLM_START_CNF, (tANI_U32 *) &mlmStartCnf );
    end:
    if( 0 != limMsgQ->bodyptr )
<<<<<<< HEAD
<<<<<<< HEAD
        palFreeMemory( pMac->hHdd, (void *) pAddBssParams );
=======
        vos_mem_free(pAddBssParams);
>>>>>>> d97af3b... add prima wlan driver
=======
        palFreeMemory( pMac->hHdd, (void *) pAddBssParams );
>>>>>>> 657b0e9... prima update
}


/**
 * limProcessIbssMlmAddBssRsp()
 *
 *FUNCTION:
 * This function is called to process a WDA_ADD_BSS_RSP from HAL.
 * Upon receipt of this message from HAL, MLME -
 * > Validates the result of WDA_ADD_BSS_REQ
 * > Init other remaining LIM variables
 * > Init the AID pool, for that BSSID
 * > Init the Pre-AUTH list, for that BSSID
 * > Create LIM timers, specific to that BSSID
 * > Init DPH related parameters that are specific to that BSSID
 * > TODO - When do we do the actual change channel?
 *
 *LOGIC:
 * SME sends eWNI_SME_START_BSS_REQ to LIM
 * LIM sends LIM_MLM_START_REQ to MLME
 * MLME sends WDA_ADD_BSS_REQ to HAL
 * HAL responds with WDA_ADD_BSS_RSP to MLME
 * MLME responds with LIM_MLM_START_CNF to LIM
 * LIM responds with eWNI_SME_START_BSS_RSP to SME
 *
 *ASSUMPTIONS:
 * tSirMsgQ.body is allocated by MLME during limProcessMlmStartReq
 * tSirMsgQ.body will now be freed by this routine
 *
 *NOTE:
 *
 * @param  pMac      Pointer to Global MAC structure
 * @param  tSirMsgQ  The MsgQ header, which contains the response buffer
 *
 * @return None
 */
static void
limProcessIbssMlmAddBssRsp( tpAniSirGlobal pMac, tpSirMsgQ limMsgQ ,tpPESession psessionEntry)
{
    tLimMlmStartCnf mlmStartCnf;
    tpAddBssParams pAddBssParams = (tpAddBssParams) limMsgQ->bodyptr;
    tANI_U32 val;
<<<<<<< HEAD
<<<<<<< HEAD
    if( eHAL_STATUS_SUCCESS == pAddBssParams->status )
    {
        PELOG1(limLog(pMac, LOG1, FL("WDA_ADD_BSS_RSP returned with eHAL_STATUS_SUCCESS\n"));)
=======

    if (NULL == pAddBssParams)
    {
        limLog( pMac, LOGE, FL( "Invalid body pointer in message"));
        goto end;
    }
    if( eHAL_STATUS_SUCCESS == pAddBssParams->status )
    {
        PELOG1(limLog(pMac, LOG1, FL("WDA_ADD_BSS_RSP returned with eHAL_STATUS_SUCCESS"));)
>>>>>>> d97af3b... add prima wlan driver
=======
    if( eHAL_STATUS_SUCCESS == pAddBssParams->status )
    {
        PELOG1(limLog(pMac, LOG1, FL("WDA_ADD_BSS_RSP returned with eHAL_STATUS_SUCCESS\n"));)
>>>>>>> 657b0e9... prima update
        if (limSetLinkState(pMac, eSIR_LINK_IBSS_STATE,psessionEntry->bssId,
             psessionEntry->selfMacAddr, NULL, NULL) != eSIR_SUCCESS )
            goto end;
        // Set MLME state
        psessionEntry->limMlmState = eLIM_MLM_BSS_STARTED_STATE;
        MTRACE(macTrace(pMac, TRACE_CODE_MLM_STATE, psessionEntry->peSessionId, psessionEntry->limMlmState));
        /** IBSS is 'active' when we receive
         * Beacon frames from other STAs that are part of same IBSS.
         * Mark internal state as inactive until then.
         */
        psessionEntry->limIbssActive = false;
        limResetHBPktCount( psessionEntry );
        /* Timer related functions are not modified for BT-AMP : To be Done */
        limHeartBeatDeactivateAndChangeTimer(pMac, psessionEntry);
        MTRACE(macTrace(pMac, TRACE_CODE_TIMER_ACTIVATE, psessionEntry->peSessionId, eLIM_HEART_BEAT_TIMER));
<<<<<<< HEAD
<<<<<<< HEAD
        if (limActivateHearBeatTimer(pMac) != TX_SUCCESS)
            limLog(pMac, LOGP, FL("could not activate Heartbeat timer\n"));
=======
        if (limActivateHearBeatTimer(pMac, psessionEntry) != TX_SUCCESS)
            limLog(pMac, LOGP, FL("could not activate Heartbeat timer"));
>>>>>>> d97af3b... add prima wlan driver
=======
        if (limActivateHearBeatTimer(pMac) != TX_SUCCESS)
            limLog(pMac, LOGP, FL("could not activate Heartbeat timer\n"));
>>>>>>> 657b0e9... prima update
        psessionEntry->bssIdx     = (tANI_U8) pAddBssParams->bssIdx;
        psessionEntry->limSystemRole = eLIM_STA_IN_IBSS_ROLE;
        psessionEntry->statypeForBss = STA_ENTRY_SELF;
        schEdcaProfileUpdate(pMac, psessionEntry);
        //TBD-RAJESH limInitPreauthList should re removed for IBSS also ?????
       //limInitPreAuthList(pMac);
<<<<<<< HEAD
<<<<<<< HEAD
        limInitAIDpool(pMac,psessionEntry);
=======
        if (0 == psessionEntry->freePeerIdxHead)
            limInitPeerIdxpool(pMac,psessionEntry);
>>>>>>> d97af3b... add prima wlan driver
=======
        limInitAIDpool(pMac,psessionEntry);
>>>>>>> 657b0e9... prima update
        // Create timers used by LIM
#ifdef FIXME_GEN6  //following code may not be required, as limCreateTimers is now invoked from limInitialize (peStart)
        if (!pMac->lim.gLimTimersCreated)
            limCreateTimers(pMac);
#endif
        /* Update the lim global gLimTriggerBackgroundScanDuringQuietBss */
        if( eSIR_SUCCESS != wlan_cfgGetInt( pMac, WNI_CFG_TRIG_STA_BK_SCAN, &val ))
<<<<<<< HEAD
<<<<<<< HEAD
            limLog( pMac, LOGP, FL("Failed to get WNI_CFG_TRIG_STA_BK_SCAN!\n"));
=======
            limLog( pMac, LOGP, FL("Failed to get WNI_CFG_TRIG_STA_BK_SCAN!"));
>>>>>>> d97af3b... add prima wlan driver
=======
            limLog( pMac, LOGP, FL("Failed to get WNI_CFG_TRIG_STA_BK_SCAN!\n"));
>>>>>>> 657b0e9... prima update
        pMac->lim.gLimTriggerBackgroundScanDuringQuietBss = (val) ? 1 : 0;
        // Apply previously set configuration at HW
        limApplyConfiguration(pMac,psessionEntry);
        psessionEntry->staId = pAddBssParams->staContext.staIdx;
        mlmStartCnf.resultCode  = eSIR_SME_SUCCESS;
        //If ADD BSS was issued as part of IBSS coalescing, don't send the message to SME, as that is internal to LIM
        if(true == pMac->lim.gLimIbssCoalescingHappened)
        {
            limIbssAddBssRspWhenCoalescing(pMac, limMsgQ->bodyptr, psessionEntry);
            goto end;
        }
    }
    else
    {
<<<<<<< HEAD
<<<<<<< HEAD
        limLog( pMac, LOGE, FL( "WDA_ADD_BSS_REQ failed with status %d\n" ),
=======
        limLog( pMac, LOGE, FL( "WDA_ADD_BSS_REQ failed with status %d" ),
>>>>>>> d97af3b... add prima wlan driver
=======
        limLog( pMac, LOGE, FL( "WDA_ADD_BSS_REQ failed with status %d\n" ),
>>>>>>> 657b0e9... prima update
            pAddBssParams->status );
        mlmStartCnf.resultCode = eSIR_SME_HAL_SEND_MESSAGE_FAIL;
    }
    //Send this message to SME, when ADD_BSS is initiated by SME
    //If ADD_BSS is done as part of coalescing, this won't happen.
    /* Update PE session Id*/
    mlmStartCnf.sessionId =psessionEntry->peSessionId;
    limPostSmeMessage( pMac, LIM_MLM_START_CNF, (tANI_U32 *) &mlmStartCnf );
    end:
    if( 0 != limMsgQ->bodyptr )
<<<<<<< HEAD
<<<<<<< HEAD
        palFreeMemory( pMac->hHdd, (void *) pAddBssParams );
=======
        vos_mem_free(pAddBssParams);
>>>>>>> d97af3b... add prima wlan driver
=======
        palFreeMemory( pMac->hHdd, (void *) pAddBssParams );
>>>>>>> 657b0e9... prima update
}

static void
limProcessStaMlmAddBssRspPreAssoc( tpAniSirGlobal pMac, tpSirMsgQ limMsgQ, tpPESession psessionEntry )
{
    tpAddBssParams pAddBssParams = (tpAddBssParams) limMsgQ->bodyptr;
    tAniAuthType       cfgAuthType, authMode;
    tLimMlmAuthReq     *pMlmAuthReq;
    tpDphHashNode pStaDs = NULL;
<<<<<<< HEAD
<<<<<<< HEAD
=======

    if (NULL == pAddBssParams)
    {
        limLog( pMac, LOGE, FL( "Invalid body pointer in message"));
        goto joinFailure;
    }
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
    if( eHAL_STATUS_SUCCESS == pAddBssParams->status )
    {
            if ((pStaDs = dphAddHashEntry(pMac, pAddBssParams->staContext.staMac, DPH_STA_HASH_INDEX_PEER, &psessionEntry->dph.dphHashTable)) == NULL)
            {
                // Could not add hash table entry
<<<<<<< HEAD
<<<<<<< HEAD
                PELOGE(limLog(pMac, LOGE, FL("could not add hash entry at DPH for \n"));)
=======
                PELOGE(limLog(pMac, LOGE, FL("could not add hash entry at DPH for "));)
>>>>>>> d97af3b... add prima wlan driver
=======
                PELOGE(limLog(pMac, LOGE, FL("could not add hash entry at DPH for \n"));)
>>>>>>> 657b0e9... prima update
                limPrintMacAddr(pMac, pAddBssParams->staContext.staMac, LOGE);
                goto joinFailure;
            }
            psessionEntry->bssIdx     = (tANI_U8) pAddBssParams->bssIdx;
            //Success, handle below
            pStaDs->bssId = pAddBssParams->bssIdx;
            //STA Index(genr by HAL) for the BSS entry is stored here
            pStaDs->staIndex = pAddBssParams->staContext.staIdx;
            // Trigger Authentication with AP
            if (wlan_cfgGetInt(pMac, WNI_CFG_AUTHENTICATION_TYPE,
                          (tANI_U32 *) &cfgAuthType) != eSIR_SUCCESS)
            {
                /**
                 * Could not get AuthType from CFG.
                 * Log error.
                 */
                limLog(pMac, LOGP,
<<<<<<< HEAD
<<<<<<< HEAD
                       FL("could not retrieve AuthType\n"));
=======
                       FL("could not retrieve AuthType"));
>>>>>>> d97af3b... add prima wlan driver
=======
                       FL("could not retrieve AuthType\n"));
>>>>>>> 657b0e9... prima update
            }
            if (cfgAuthType == eSIR_AUTO_SWITCH) 
                authMode = eSIR_OPEN_SYSTEM; // Try Open Authentication first
            else
                authMode = cfgAuthType;

            // Trigger MAC based Authentication
<<<<<<< HEAD
<<<<<<< HEAD
            if( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd, (void **)&pMlmAuthReq, sizeof(tLimMlmAuthReq)))
            {
                // Log error
                limLog(pMac, LOGP,
                       FL("call to palAllocateMemory failed for mlmAuthReq\n"));
=======
            pMlmAuthReq = vos_mem_malloc(sizeof(tLimMlmAuthReq));
            if ( NULL == pMlmAuthReq )
            {
                // Log error
                limLog(pMac, LOGP,
                       FL("call to AllocateMemory failed for mlmAuthReq"));
>>>>>>> d97af3b... add prima wlan driver
=======
            if( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd, (void **)&pMlmAuthReq, sizeof(tLimMlmAuthReq)))
            {
                // Log error
                limLog(pMac, LOGP,
                       FL("call to palAllocateMemory failed for mlmAuthReq\n"));
>>>>>>> 657b0e9... prima update
                return;
            }
            #if 0
            val = sizeof(tSirMacAddr);
            if (wlan_cfgGetStr(pMac, WNI_CFG_BSSID,
                          pMlmAuthReq->peerMacAddr,
                          &val) != eSIR_SUCCESS)
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
            sirCopyMacAddr(pMlmAuthReq->peerMacAddr,psessionEntry->bssId);

            pMlmAuthReq->authType = authMode;
            if (wlan_cfgGetInt(pMac, WNI_CFG_AUTHENTICATE_FAILURE_TIMEOUT,
                          (tANI_U32 *) &pMlmAuthReq->authFailureTimeout)
                          != eSIR_SUCCESS)
            {
                /**
                 * Could not get AuthFailureTimeout
                 * value from CFG. Log error.
                 */
                limLog(pMac, LOGP,
<<<<<<< HEAD
<<<<<<< HEAD
                   FL("could not retrieve AuthFailureTimeout value\n"));
=======
                   FL("could not retrieve AuthFailureTimeout value"));
>>>>>>> d97af3b... add prima wlan driver
=======
                   FL("could not retrieve AuthFailureTimeout value\n"));
>>>>>>> 657b0e9... prima update
            }
            // SUNIT_FIX_ME:  Set BOTH? Assume not. Please verify here and below.
            //pMac->lim.gLimMlmState = eLIM_MLM_JOINED_STATE;
            psessionEntry->limMlmState = eLIM_MLM_JOINED_STATE;
            MTRACE(macTrace(pMac, TRACE_CODE_MLM_STATE, psessionEntry->peSessionId, eLIM_MLM_JOINED_STATE));
            pMlmAuthReq->sessionId = psessionEntry->peSessionId;
            psessionEntry->limPrevSmeState = psessionEntry->limSmeState;
            psessionEntry->limSmeState     = eLIM_SME_WT_AUTH_STATE;
            // remember staId in case of assoc timeout/failure handling
            psessionEntry->staId = pAddBssParams->staContext.staIdx;

            MTRACE(macTrace(pMac, TRACE_CODE_SME_STATE, psessionEntry->peSessionId, psessionEntry->limSmeState));
            limPostMlmMessage(pMac,
                              LIM_MLM_AUTH_REQ,
                              (tANI_U32 *) pMlmAuthReq);
            return;
    }

joinFailure:
    {
        psessionEntry->limSmeState = eLIM_SME_JOIN_FAILURE_STATE;
        MTRACE(macTrace(pMac, TRACE_CODE_SME_STATE, psessionEntry->peSessionId, psessionEntry->limSmeState));

        /// Send Join response to Host
        limHandleSmeJoinResult(pMac,  eSIR_SME_REFUSED, eSIR_MAC_UNSPEC_FAILURE_STATUS, psessionEntry);

    }

}

#ifdef WLAN_FEATURE_VOWIFI_11R
/*------------------------------------------------------------------------------------------
 *
 * Function to handle WDA_ADD_BSS_RSP, in FT reassoc state.
<<<<<<< HEAD
<<<<<<< HEAD
=======
 * Function to Send ReAssociation Request.
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
 *
 *
 *------------------------------------------------------------------------------------------
 */
static inline void
limProcessStaMlmAddBssRspFT(tpAniSirGlobal pMac, tpSirMsgQ limMsgQ, tpPESession psessionEntry)
{
<<<<<<< HEAD
<<<<<<< HEAD
    tpDphHashNode pStaDs    = NULL;
    tpAddBssParams pAddBssParams = (tpAddBssParams) limMsgQ->bodyptr;
    tpAddStaParams pAddStaParams = NULL;
    tANI_U32 listenInterval = WNI_CFG_LISTEN_INTERVAL_STADEF;
    tLimMlmReassocReq       *pMlmReassocReq;
    tLimMlmReassocCnf       mlmReassocCnf; // keep sme 

    pMlmReassocReq = (tLimMlmReassocReq *)(psessionEntry->pLimMlmReassocReq);

=======
    tLimMlmReassocCnf       mlmReassocCnf; // keep sme 
=======
>>>>>>> 657b0e9... prima update
    tpDphHashNode pStaDs    = NULL;
    tpAddBssParams pAddBssParams = (tpAddBssParams) limMsgQ->bodyptr;
    tpAddStaParams pAddStaParams = NULL;
    tANI_U32 listenInterval = WNI_CFG_LISTEN_INTERVAL_STADEF;
    tLimMlmReassocReq       *pMlmReassocReq;
    tLimMlmReassocCnf       mlmReassocCnf; // keep sme 

    pMlmReassocReq = (tLimMlmReassocReq *)(psessionEntry->pLimMlmReassocReq);

<<<<<<< HEAD
    if (pAddBssParams == NULL)
    {
        PELOGE(limLog(pMac, LOGE, FL("Invalid parameters"));)
        goto end;
    }
    if((psessionEntry = peFindSessionBySessionId(pMac,pAddBssParams->sessionId))== NULL)
    {
        limLog( pMac, LOGE, FL( "Session Does not exist for given sessionId" ));
        goto end;
    }
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
    if ( eLIM_MLM_WT_ADD_BSS_RSP_FT_REASSOC_STATE != psessionEntry->limMlmState )
    {
        goto end;
    }

    if ((pStaDs = dphAddHashEntry(pMac, pAddBssParams->bssId, DPH_STA_HASH_INDEX_PEER,
        &psessionEntry->dph.dphHashTable)) == NULL)
    {
        // Could not add hash table entry
<<<<<<< HEAD
<<<<<<< HEAD
        PELOGE(limLog(pMac, LOGE, FL("could not add hash entry at DPH for \n"));)
        limPrintMacAddr(pMac, pAddBssParams->staContext.staMac, LOGE);
        goto end;
    }

    // Set the filter state to post assoc
    if (limSetLinkState(pMac, eSIR_LINK_POSTASSOC_STATE,
            pAddBssParams->bssId, psessionEntry->selfMacAddr,
            NULL, NULL) != eSIR_SUCCESS)
    {
        PELOGE(limLog(pMac, LOGE,  FL("Failed to set the LinkState\n"));)
        goto end;
    }

=======
        PELOGE(limLog(pMac, LOGE, FL("could not add hash entry at DPH for "));)
        limPrintMacAddr(pMac, pAddBssParams->staContext.staMac, LOGE);
        goto end;
    }
>>>>>>> d97af3b... add prima wlan driver
=======
        PELOGE(limLog(pMac, LOGE, FL("could not add hash entry at DPH for \n"));)
        limPrintMacAddr(pMac, pAddBssParams->staContext.staMac, LOGE);
        goto end;
    }

    // Set the filter state to post assoc
    if (limSetLinkState(pMac, eSIR_LINK_POSTASSOC_STATE,
            pAddBssParams->bssId, psessionEntry->selfMacAddr,
            NULL, NULL) != eSIR_SUCCESS)
    {
        PELOGE(limLog(pMac, LOGE,  FL("Failed to set the LinkState\n"));)
        goto end;
    }

>>>>>>> 657b0e9... prima update
    // Prepare and send Reassociation request frame
    // start reassoc timer.
    pMac->lim.limTimers.gLimReassocFailureTimer.sessionId = psessionEntry->peSessionId;
    /// Start reassociation failure timer
    MTRACE(macTrace(pMac, TRACE_CODE_TIMER_ACTIVATE, psessionEntry->peSessionId, eLIM_REASSOC_FAIL_TIMER));
    if (tx_timer_activate(&pMac->lim.limTimers.gLimReassocFailureTimer)
                                               != TX_SUCCESS)
    {
        /// Could not start reassoc failure timer.
        // Log error
        limLog(pMac, LOGP,
<<<<<<< HEAD
<<<<<<< HEAD
           FL("could not start Reassociation failure timer\n"));
=======
           FL("could not start Reassociation failure timer"));
>>>>>>> d97af3b... add prima wlan driver
=======
           FL("could not start Reassociation failure timer\n"));
>>>>>>> 657b0e9... prima update
        // Return Reassoc confirm with
        // Resources Unavailable
        mlmReassocCnf.resultCode = eSIR_SME_RESOURCES_UNAVAILABLE;
        mlmReassocCnf.protStatusCode = eSIR_MAC_UNSPEC_FAILURE_STATUS;
        goto end;
    }
<<<<<<< HEAD
<<<<<<< HEAD
    limSendReassocReqWithFTIEsMgmtFrame(pMac, psessionEntry->pLimMlmReassocReq, psessionEntry);
    psessionEntry->limPrevMlmState = psessionEntry->limMlmState;
    psessionEntry->limMlmState = eLIM_MLM_WT_FT_REASSOC_RSP_STATE;
    PELOGE(limLog(pMac, LOGE,  FL("Set the mlm state to %d session=%d\n"),
=======
#if  defined (WLAN_FEATURE_VOWIFI_11R) || defined (FEATURE_WLAN_CCX) || defined(FEATURE_WLAN_LFR)
    pMac->lim.pSessionEntry = psessionEntry;
    if(NULL == pMac->lim.pSessionEntry->pLimMlmReassocRetryReq)
    {
        /* Take a copy of reassoc request for retrying */
        pMac->lim.pSessionEntry->pLimMlmReassocRetryReq = vos_mem_malloc(sizeof(tLimMlmReassocReq));
        if ( NULL == pMac->lim.pSessionEntry->pLimMlmReassocRetryReq ) goto end;
        vos_mem_set(pMac->lim.pSessionEntry->pLimMlmReassocRetryReq, sizeof(tLimMlmReassocReq), 0);
        vos_mem_copy(pMac->lim.pSessionEntry->pLimMlmReassocRetryReq,
                     psessionEntry->pLimMlmReassocReq,
                     sizeof(tLimMlmReassocReq));
    }
    pMac->lim.reAssocRetryAttempt = 0;
#endif
=======
>>>>>>> 657b0e9... prima update
    limSendReassocReqWithFTIEsMgmtFrame(pMac, psessionEntry->pLimMlmReassocReq, psessionEntry);
    psessionEntry->limPrevMlmState = psessionEntry->limMlmState;
    psessionEntry->limMlmState = eLIM_MLM_WT_FT_REASSOC_RSP_STATE;
<<<<<<< HEAD
    MTRACE(macTrace(pMac, TRACE_CODE_MLM_STATE, psessionEntry->peSessionId, eLIM_MLM_WT_FT_REASSOC_RSP_STATE));
    PELOGE(limLog(pMac, LOG1,  FL("Set the mlm state to %d session=%d"),
>>>>>>> d97af3b... add prima wlan driver
=======
    PELOGE(limLog(pMac, LOGE,  FL("Set the mlm state to %d session=%d\n"),
>>>>>>> 657b0e9... prima update
        psessionEntry->limMlmState, psessionEntry->peSessionId);)

    psessionEntry->bssIdx     = (tANI_U8) pAddBssParams->bssIdx;

    //Success, handle below
    pStaDs->bssId = pAddBssParams->bssIdx;
    //STA Index(genr by HAL) for the BSS entry is stored here
    pStaDs->staIndex = pAddBssParams->staContext.staIdx;
    pStaDs->ucUcastSig   = pAddBssParams->staContext.ucUcastSig;
    pStaDs->ucBcastSig   = pAddBssParams->staContext.ucBcastSig;

<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
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

<<<<<<< HEAD
=======
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
#if defined WLAN_FEATURE_VOWIFI
    rrmCacheMgmtTxPower( pMac, pAddBssParams->txMgmtPower, psessionEntry );
#endif

<<<<<<< HEAD
<<<<<<< HEAD
    if( eHAL_STATUS_SUCCESS !=
        palAllocateMemory( pMac->hHdd, (void **) &pAddStaParams, sizeof( tAddStaParams )))
    {
        limLog( pMac, LOGP, FL( "Unable to PAL allocate memory during ADD_STA\n" ));
        return;
    }
    palZeroMemory( pMac->hHdd, (tANI_U8 *) pAddStaParams, sizeof(tAddStaParams));

    /// Add STA context at MAC HW (BMU, RHP & TFP)
    palCopyMemory( pMac->hHdd, (tANI_U8 *) pAddStaParams->staMac,
                  (tANI_U8 *) psessionEntry->selfMacAddr, sizeof(tSirMacAddr));

    palCopyMemory( pMac->hHdd, (tANI_U8 *) pAddStaParams->bssId,
                psessionEntry->bssId, sizeof(tSirMacAddr));
=======
    pAddStaParams = vos_mem_malloc(sizeof( tAddStaParams ));
    if ( NULL == pAddStaParams )
=======
    if( eHAL_STATUS_SUCCESS !=
        palAllocateMemory( pMac->hHdd, (void **) &pAddStaParams, sizeof( tAddStaParams )))
>>>>>>> 657b0e9... prima update
    {
        limLog( pMac, LOGP, FL( "Unable to PAL allocate memory during ADD_STA\n" ));
        return;
    }
    palZeroMemory( pMac->hHdd, (tANI_U8 *) pAddStaParams, sizeof(tAddStaParams));

    /// Add STA context at MAC HW (BMU, RHP & TFP)
    palCopyMemory( pMac->hHdd, (tANI_U8 *) pAddStaParams->staMac,
                  (tANI_U8 *) psessionEntry->selfMacAddr, sizeof(tSirMacAddr));

<<<<<<< HEAD
    vos_mem_copy((tANI_U8 *) pAddStaParams->bssId,
                  psessionEntry->bssId, sizeof(tSirMacAddr));
>>>>>>> d97af3b... add prima wlan driver
=======
    palCopyMemory( pMac->hHdd, (tANI_U8 *) pAddStaParams->bssId,
                psessionEntry->bssId, sizeof(tSirMacAddr));
>>>>>>> 657b0e9... prima update

    // Update this when we get reassoc rsp , with success.
    // pAddStaParams->assocId = psessionEntry->limAID;

    pAddStaParams->staType = STA_ENTRY_SELF;
    pAddStaParams->status = eHAL_STATUS_SUCCESS;
    pAddStaParams->respReqd = 1;

    /* Update  PE session ID */
    pAddStaParams->sessionId = psessionEntry->peSessionId;

    // This will indicate HAL to "allocate" a new STA index
    pAddStaParams->staIdx = HAL_STA_INVALID_IDX;
    pAddStaParams->updateSta = FALSE;

    pAddStaParams->shortPreambleSupported = (tANI_U8)psessionEntry->beaconParams.fShortPreamble;
#ifdef WLAN_FEATURE_11AC
<<<<<<< HEAD
<<<<<<< HEAD
    limPopulateOwnRateSet(pMac, &pAddStaParams->supportedRates, NULL, false,psessionEntry, NULL);
#else
    limPopulateOwnRateSet(pMac, &pAddStaParams->supportedRates, NULL, false,psessionEntry);
=======
    limPopulatePeerRateSet(pMac, &pAddStaParams->supportedRates, NULL, false,psessionEntry, NULL);
#else
    limPopulatePeerRateSet(pMac, &pAddStaParams->supportedRates, NULL, false,psessionEntry);
>>>>>>> d97af3b... add prima wlan driver
=======
    limPopulateOwnRateSet(pMac, &pAddStaParams->supportedRates, NULL, false,psessionEntry, NULL);
#else
    limPopulateOwnRateSet(pMac, &pAddStaParams->supportedRates, NULL, false,psessionEntry);
>>>>>>> 657b0e9... prima update
#endif

    if( psessionEntry->htCapability)
    {
        pAddStaParams->htCapable = psessionEntry->htCapability;
#ifdef DISABLE_GF_FOR_INTEROP
        /*
         * To resolve the interop problem with Broadcom AP,
         * where TQ STA could not pass traffic with GF enabled,
         * TQ STA will do Greenfield only with TQ AP, for
         * everybody else it will be turned off.
         */
        if( (psessionEntry->pLimJoinReq != NULL) && (!psessionEntry->pLimJoinReq->bssDescription.aniIndicator))
        {
            limLog( pMac, LOGE, FL(" Turning off Greenfield, when adding self entry"));
            pAddStaParams->greenFieldCapable = WNI_CFG_GREENFIELD_CAPABILITY_DISABLE;
        }
        else
#endif

<<<<<<< HEAD
<<<<<<< HEAD
#ifdef WLAN_SOFTAP_FEATURE
=======
>>>>>>> d97af3b... add prima wlan driver
=======
#ifdef WLAN_SOFTAP_FEATURE
>>>>>>> 657b0e9... prima update
        pAddStaParams->greenFieldCapable = limGetHTCapability( pMac, eHT_GREENFIELD, psessionEntry);
        pAddStaParams->txChannelWidthSet = limGetHTCapability( pMac, eHT_SUPPORTED_CHANNEL_WIDTH_SET, psessionEntry);
        pAddStaParams->mimoPS            = limGetHTCapability( pMac, eHT_MIMO_POWER_SAVE, psessionEntry );
        pAddStaParams->rifsMode          = limGetHTCapability( pMac, eHT_RIFS_MODE, psessionEntry );
        pAddStaParams->lsigTxopProtection = limGetHTCapability( pMac, eHT_LSIG_TXOP_PROTECTION, psessionEntry );
        pAddStaParams->delBASupport      = limGetHTCapability( pMac, eHT_DELAYED_BA, psessionEntry );
        pAddStaParams->maxAmpduDensity   = limGetHTCapability( pMac, eHT_MPDU_DENSITY, psessionEntry );
        pAddStaParams->maxAmpduSize   = limGetHTCapability(pMac, eHT_MAX_RX_AMPDU_FACTOR, psessionEntry);
        pAddStaParams->maxAmsduSize      = limGetHTCapability( pMac, eHT_MAX_AMSDU_LENGTH, psessionEntry );
        pAddStaParams->fDsssCckMode40Mhz = limGetHTCapability( pMac, eHT_DSSS_CCK_MODE_40MHZ, psessionEntry);
        pAddStaParams->fShortGI20Mhz     = limGetHTCapability( pMac, eHT_SHORT_GI_20MHZ, psessionEntry);
        pAddStaParams->fShortGI40Mhz     = limGetHTCapability( pMac, eHT_SHORT_GI_40MHZ, psessionEntry);
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
#else
        pAddStaParams->greenFieldCapable = limGetHTCapability( pMac, eHT_GREENFIELD );
        pAddStaParams->txChannelWidthSet = limGetHTCapability( pMac, eHT_SUPPORTED_CHANNEL_WIDTH_SET );
        pAddStaParams->mimoPS            = limGetHTCapability( pMac, eHT_MIMO_POWER_SAVE );
        pAddStaParams->rifsMode          = limGetHTCapability( pMac, eHT_RIFS_MODE );
        pAddStaParams->lsigTxopProtection = limGetHTCapability( pMac, eHT_LSIG_TXOP_PROTECTION );
        pAddStaParams->delBASupport      = limGetHTCapability( pMac, eHT_DELAYED_BA );
        pAddStaParams->maxAmpduDensity   = limGetHTCapability( pMac, eHT_MPDU_DENSITY );
        pAddStaParams->maxAmpduSize   = limGetHTCapability(pMac, eHT_MAX_RX_AMPDU_FACTOR);
        pAddStaParams->maxAmsduSize      = limGetHTCapability( pMac, eHT_MAX_AMSDU_LENGTH );
        pAddStaParams->fDsssCckMode40Mhz = limGetHTCapability( pMac, eHT_DSSS_CCK_MODE_40MHZ);
        pAddStaParams->fShortGI20Mhz     = limGetHTCapability( pMac, eHT_SHORT_GI_20MHZ);
        pAddStaParams->fShortGI40Mhz     = limGetHTCapability( pMac, eHT_SHORT_GI_40MHZ);
#endif
<<<<<<< HEAD
    }

    if (wlan_cfgGetInt(pMac, WNI_CFG_LISTEN_INTERVAL, &listenInterval) != eSIR_SUCCESS)
        limLog(pMac, LOGP, FL("Couldn't get LISTEN_INTERVAL\n"));
=======
    }

    if (wlan_cfgGetInt(pMac, WNI_CFG_LISTEN_INTERVAL, &listenInterval) != eSIR_SUCCESS)
        limLog(pMac, LOGP, FL("Couldn't get LISTEN_INTERVAL"));
>>>>>>> d97af3b... add prima wlan driver
=======
    }

    if (wlan_cfgGetInt(pMac, WNI_CFG_LISTEN_INTERVAL, &listenInterval) != eSIR_SUCCESS)
        limLog(pMac, LOGP, FL("Couldn't get LISTEN_INTERVAL\n"));
>>>>>>> 657b0e9... prima update
    pAddStaParams->listenInterval = (tANI_U16)listenInterval;

    limFillSupportedRatesInfo(pMac, NULL, &pAddStaParams->supportedRates,psessionEntry);

    // Lets save this for when we receive the Reassoc Rsp
    pMac->ft.ftPEContext.pAddStaReq = pAddStaParams;
<<<<<<< HEAD
<<<<<<< HEAD
=======

    if (pAddBssParams != NULL)
    {
        vos_mem_free(pAddBssParams);
        pAddBssParams = NULL;
        limMsgQ->bodyptr = NULL;
    }
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
    return;

end:
    // Free up buffer allocated for reassocReq
<<<<<<< HEAD
<<<<<<< HEAD
    if (pMlmReassocReq != NULL)
    {
        palFreeMemory( pMac->hHdd, (tANI_U8 *) pMlmReassocReq);
    }
    mlmReassocCnf.resultCode = eSIR_SME_FT_REASSOC_FAILURE;
    mlmReassocCnf.protStatusCode = eSIR_MAC_UNSPEC_FAILURE_STATUS;
    /* Update PE sessio Id*/
    mlmReassocCnf.sessionId = psessionEntry->peSessionId;
=======
    if (psessionEntry != NULL)
    if (psessionEntry->pLimMlmReassocReq != NULL)
    {
        vos_mem_free(psessionEntry->pLimMlmReassocReq);
        psessionEntry->pLimMlmReassocReq = NULL;
    }

    if (pAddBssParams != NULL)
=======
    if (pMlmReassocReq != NULL)
>>>>>>> 657b0e9... prima update
    {
        palFreeMemory( pMac->hHdd, (tANI_U8 *) pMlmReassocReq);
    }
    mlmReassocCnf.resultCode = eSIR_SME_FT_REASSOC_FAILURE;
    mlmReassocCnf.protStatusCode = eSIR_MAC_UNSPEC_FAILURE_STATUS;
<<<<<<< HEAD
    /* Update PE session Id*/
    if (psessionEntry != NULL)
        mlmReassocCnf.sessionId = psessionEntry->peSessionId;
    else
        mlmReassocCnf.sessionId = 0;
>>>>>>> d97af3b... add prima wlan driver
=======
    /* Update PE sessio Id*/
    mlmReassocCnf.sessionId = psessionEntry->peSessionId;
>>>>>>> 657b0e9... prima update

    limPostSmeMessage(pMac, LIM_MLM_REASSOC_CNF, (tANI_U32 *) &mlmReassocCnf);
}
#endif /* WLAN_FEATURE_VOWIFI_11R */
<<<<<<< HEAD
<<<<<<< HEAD


=======
>>>>>>> d97af3b... add prima wlan driver
=======


>>>>>>> 657b0e9... prima update
/**
 * limProcessStaMlmAddBssRsp()
 *
 *FUNCTION:
 * This function is called to process a WDA_ADD_BSS_RSP from HAL.
 * Upon receipt of this message from HAL, MLME -
 * > Validates the result of WDA_ADD_BSS_REQ
 * > Now, send an ADD_STA to HAL and ADD the "local" STA itself
 *
 *LOGIC:
 * MLME had sent WDA_ADD_BSS_REQ to HAL
 * HAL responded with WDA_ADD_BSS_RSP to MLME
 * MLME now sends WDA_ADD_STA_REQ to HAL
 *
 *ASSUMPTIONS:
 * tSirMsgQ.body is allocated by MLME during limProcessMlmJoinReq
 * tSirMsgQ.body will now be freed by this routine
 *
 *NOTE:
 *
 * @param  pMac      Pointer to Global MAC structure
 * @param  tSirMsgQ  The MsgQ header, which contains the response buffer
 *
 * @return None
 */
static void
limProcessStaMlmAddBssRsp( tpAniSirGlobal pMac, tpSirMsgQ limMsgQ,tpPESession psessionEntry)
{
    tpAddBssParams pAddBssParams = (tpAddBssParams) limMsgQ->bodyptr;
    tLimMlmAssocCnf mlmAssocCnf;
    tANI_U32 mesgType       = LIM_MLM_ASSOC_CNF;
    tANI_U32 subType        = LIM_ASSOC;
    tpDphHashNode pStaDs    = NULL;
    tANI_U16 staIdx = HAL_STA_INVALID_IDX;
    tANI_U8 updateSta = false;
    mlmAssocCnf.resultCode  = eSIR_SME_SUCCESS;

    if(eLIM_MLM_WT_ADD_BSS_RSP_PREASSOC_STATE == psessionEntry->limMlmState)
    {
        //Done: 7-28-2009. JIM_FIX_ME:  sessionize the following function
        limProcessStaMlmAddBssRspPreAssoc(pMac, limMsgQ, psessionEntry);
        goto end;
    }
    if( eLIM_MLM_WT_ADD_BSS_RSP_REASSOC_STATE == psessionEntry->limMlmState )
    {
        mesgType = LIM_MLM_REASSOC_CNF;
        subType = LIM_REASSOC;
     //If Reassoc is happening for the same BSS, then use the existing StaId and indicate to HAL
     //to update the existing STA entry.
     //If Reassoc is happening for the new BSS, then old BSS and STA entry would have been already deleted
     //before PE tries to add BSS for the new BSS, so set the updateSta to false and pass INVALID STA Index.
    if (sirCompareMacAddr( psessionEntry->bssId, psessionEntry->limReAssocbssId))
        {
            staIdx = psessionEntry->staId;
            updateSta  = true;
        }
    }
<<<<<<< HEAD
<<<<<<< HEAD
=======

    if(pAddBssParams == 0)
        goto end;

>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
    if( eHAL_STATUS_SUCCESS == pAddBssParams->status )
    {
#if defined(WLAN_FEATURE_VOWIFI_11R) || defined(FEATURE_WLAN_CCX) || defined(FEATURE_WLAN_LFR)
        if( eLIM_MLM_WT_ADD_BSS_RSP_FT_REASSOC_STATE == psessionEntry->limMlmState )
        {
#ifdef WLAN_FEATURE_VOWIFI_11R_DEBUG
<<<<<<< HEAD
<<<<<<< HEAD
            PELOGE(limLog(pMac, LOGE, FL("Mlm=%d %d\n"),
=======
            PELOGE(limLog(pMac, LOG1, FL("Mlm=%d %d"),
>>>>>>> d97af3b... add prima wlan driver
=======
            PELOGE(limLog(pMac, LOGE, FL("Mlm=%d %d\n"),
>>>>>>> 657b0e9... prima update
                psessionEntry->limMlmState,
                eLIM_MLM_WT_ADD_BSS_RSP_REASSOC_STATE);)
#endif
            limProcessStaMlmAddBssRspFT( pMac, limMsgQ, psessionEntry);
            goto end;
        }
#endif /* WLAN_FEATURE_VOWIFI_11R */

         // Set MLME state
        psessionEntry->limMlmState = eLIM_MLM_WT_ADD_STA_RSP_STATE;
        MTRACE(macTrace(pMac, TRACE_CODE_MLM_STATE, psessionEntry->peSessionId, psessionEntry->limMlmState));
        psessionEntry->statypeForBss = STA_ENTRY_PEER; //to know the session  started for self or for  peer oct6th
        // Now, send WDA_ADD_STA_REQ
<<<<<<< HEAD
<<<<<<< HEAD
        limLog( pMac, LOGW, FL( "On STA: ADD_BSS was successful\n" ));
        pStaDs = dphGetHashEntry(pMac, DPH_STA_HASH_INDEX_PEER, &psessionEntry->dph.dphHashTable);
        if (pStaDs == NULL)
        {
            PELOGE(limLog(pMac, LOGE, FL("could not Add Self Entry for the station\n"));)
=======
        limLog( pMac, LOGW, FL( "On STA: ADD_BSS was successful" ));
        pStaDs = dphGetHashEntry(pMac, DPH_STA_HASH_INDEX_PEER, &psessionEntry->dph.dphHashTable);
        if (pStaDs == NULL)
        {
            PELOGE(limLog(pMac, LOGE, FL("could not Add Self Entry for the station"));)
>>>>>>> d97af3b... add prima wlan driver
=======
        limLog( pMac, LOGW, FL( "On STA: ADD_BSS was successful\n" ));
        pStaDs = dphGetHashEntry(pMac, DPH_STA_HASH_INDEX_PEER, &psessionEntry->dph.dphHashTable);
        if (pStaDs == NULL)
        {
            PELOGE(limLog(pMac, LOGE, FL("could not Add Self Entry for the station\n"));)
>>>>>>> 657b0e9... prima update
            mlmAssocCnf.resultCode = (tSirResultCodes) eSIR_SME_REFUSED;
        }
        else
        {
            psessionEntry->bssIdx     = (tANI_U8) pAddBssParams->bssIdx;
            //Success, handle below
            pStaDs->bssId = pAddBssParams->bssIdx;
            //STA Index(genr by HAL) for the BSS entry is stored here
            pStaDs->staIndex = pAddBssParams->staContext.staIdx;
            pStaDs->ucUcastSig   = pAddBssParams->staContext.ucUcastSig;
            pStaDs->ucBcastSig   = pAddBssParams->staContext.ucBcastSig;
            // Downgrade the EDCA parameters if needed
            limSetActiveEdcaParams(pMac, psessionEntry->gLimEdcaParams, psessionEntry);
            // Send the active EDCA parameters to HAL
            if (pStaDs->aniPeer == eANI_BOOLEAN_TRUE) {
                limSendEdcaParams(pMac, psessionEntry->gLimEdcaParamsActive, pStaDs->bssId, eANI_BOOLEAN_TRUE);
            } else {
                limSendEdcaParams(pMac, psessionEntry->gLimEdcaParamsActive, pStaDs->bssId, eANI_BOOLEAN_FALSE);
            }
#if defined WLAN_FEATURE_VOWIFI
            rrmCacheMgmtTxPower( pMac, pAddBssParams->txMgmtPower, psessionEntry );
#endif

            if (subType == LIM_REASSOC)
                limDeactivateAndChangeTimer(pMac, eLIM_KEEPALIVE_TIMER);
            if (limAddStaSelf(pMac,staIdx, updateSta, psessionEntry) != eSIR_SUCCESS)
            {
                // Add STA context at HW
<<<<<<< HEAD
<<<<<<< HEAD
                PELOGE(limLog(pMac, LOGE, FL("could not Add Self Entry for the station\n"));)
=======
                PELOGE(limLog(pMac, LOGE, FL("could not Add Self Entry for the station"));)
>>>>>>> d97af3b... add prima wlan driver
=======
                PELOGE(limLog(pMac, LOGE, FL("could not Add Self Entry for the station\n"));)
>>>>>>> 657b0e9... prima update
                mlmAssocCnf.resultCode = (tSirResultCodes) eSIR_SME_REFUSED;
            }
        }
    }
    else
    {
<<<<<<< HEAD
<<<<<<< HEAD
        limLog( pMac, LOGP, FL( "ADD_BSS failed!\n" ));
=======
        limLog( pMac, LOGP, FL( "ADD_BSS failed!" ));
>>>>>>> d97af3b... add prima wlan driver
=======
        limLog( pMac, LOGP, FL( "ADD_BSS failed!\n" ));
>>>>>>> 657b0e9... prima update
        // Return Assoc confirm to SME with failure
        mlmAssocCnf.resultCode = (tSirResultCodes) eSIR_SME_REFUSED;
    }

    if(mlmAssocCnf.resultCode != eSIR_SME_SUCCESS)
    {
        /* Update PE session Id*/
        mlmAssocCnf.sessionId = psessionEntry->peSessionId;
        limPostSmeMessage( pMac, mesgType, (tANI_U32 *) &mlmAssocCnf );
    }
    end:
    if( 0 != limMsgQ->bodyptr )
<<<<<<< HEAD
<<<<<<< HEAD
        palFreeMemory( pMac->hHdd,(void *) pAddBssParams );
=======
        vos_mem_free(pAddBssParams);
>>>>>>> d97af3b... add prima wlan driver
=======
        palFreeMemory( pMac->hHdd,(void *) pAddBssParams );
>>>>>>> 657b0e9... prima update
}



/**
 * limProcessMlmAddBssRsp()
 *
 *FUNCTION:
 * This function is called to process a WDA_ADD_BSS_RSP from HAL.
 * Upon receipt of this message from HAL, MLME -
 * > Determines the "state" in which this message was received
 * > Forwards it to the appropriate callback
 *
 *LOGIC:
 * WDA_ADD_BSS_RSP can be received by MLME while the LIM is
 * in the following two states:
 * 1) As AP, LIM state = eLIM_SME_WT_START_BSS_STATE
 * 2) As STA, LIM state = eLIM_SME_WT_JOIN_STATE
 * Based on these two states, this API will determine where to
 * route the message to
 *
 *ASSUMPTIONS:
 *
 *NOTE:
 *
 * @param  pMac      Pointer to Global MAC structure
 * @param  tSirMsgQ  The MsgQ header, which contains the response buffer
 *
 * @return None
 */
void limProcessMlmAddBssRsp( tpAniSirGlobal pMac, tpSirMsgQ limMsgQ )
{
    tLimMlmStartCnf     mlmStartCnf;
    tpPESession         psessionEntry;
    tpAddBssParams      pAddBssParams = (tpAddBssParams) (limMsgQ->bodyptr);

    if(NULL == pAddBssParams )
    {
<<<<<<< HEAD
<<<<<<< HEAD
        limLog( pMac, LOGE, FL( "Encountered NULL Pointer\n" ));
=======
        limLog( pMac, LOGE, FL( "Encountered NULL Pointer" ));
>>>>>>> d97af3b... add prima wlan driver
=======
        limLog( pMac, LOGE, FL( "Encountered NULL Pointer\n" ));
>>>>>>> 657b0e9... prima update
        return;
    }

    //
    // TODO & FIXME_GEN4
    // Need to inspect tSirMsgQ.reserved for a valid Dialog token!
    //
    //we need to process the deferred message since the initiating req. there might be nested request.
    //in the case of nested request the new request initiated from the response will take care of resetting
    //the deffered flag.
    SET_LIM_PROCESS_DEFD_MESGS(pMac, true);
    // Validate SME/LIM state
    // Validate MLME state
    if((psessionEntry = peFindSessionBySessionId(pMac,pAddBssParams->sessionId))== NULL)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        limLog( pMac, LOGE, FL( "Session Does not exist for given sessionId\n" ));
            if( NULL != pAddBssParams )
                palFreeMemory( pMac->hHdd, (void *) pAddBssParams );
=======
        limLog( pMac, LOGE, FL( "Session Does not exist for given sessionId" ));
            if( NULL != pAddBssParams )
                vos_mem_free(pAddBssParams);
>>>>>>> d97af3b... add prima wlan driver
=======
        limLog( pMac, LOGE, FL( "Session Does not exist for given sessionId\n" ));
            if( NULL != pAddBssParams )
                palFreeMemory( pMac->hHdd, (void *) pAddBssParams );
>>>>>>> 657b0e9... prima update
        return;
    }
    /* update PE session Id*/
    mlmStartCnf.sessionId = psessionEntry->peSessionId;
    if( eSIR_IBSS_MODE == psessionEntry->bssType )
        limProcessIbssMlmAddBssRsp( pMac, limMsgQ, psessionEntry );
    else
    {
        if( eLIM_SME_WT_START_BSS_STATE == psessionEntry->limSmeState )
        {
            if( eLIM_MLM_WT_ADD_BSS_RSP_STATE != psessionEntry->limMlmState )
            {
                // Mesg received from HAL in Invalid state!
                limLog( pMac, LOGE,
<<<<<<< HEAD
<<<<<<< HEAD
                  FL( "Received unexpected WDA_ADD_BSS_RSP in state %X\n" ),
                  psessionEntry->limMlmState );
                mlmStartCnf.resultCode = eSIR_SME_BSS_ALREADY_STARTED_OR_JOINED;
                if( 0 != limMsgQ->bodyptr )
                    palFreeMemory( pMac->hHdd, (void *) pAddBssParams );
=======
                  FL( "Received unexpected WDA_ADD_BSS_RSP in state %X" ),
                  psessionEntry->limMlmState );
                mlmStartCnf.resultCode = eSIR_SME_BSS_ALREADY_STARTED_OR_JOINED;
                if( 0 != limMsgQ->bodyptr )
                    vos_mem_free(pAddBssParams);
>>>>>>> d97af3b... add prima wlan driver
=======
                  FL( "Received unexpected WDA_ADD_BSS_RSP in state %X\n" ),
                  psessionEntry->limMlmState );
                mlmStartCnf.resultCode = eSIR_SME_BSS_ALREADY_STARTED_OR_JOINED;
                if( 0 != limMsgQ->bodyptr )
                    palFreeMemory( pMac->hHdd, (void *) pAddBssParams );
>>>>>>> 657b0e9... prima update
                limPostSmeMessage( pMac, LIM_MLM_START_CNF, (tANI_U32 *) &mlmStartCnf );
            }
            else if ((psessionEntry->bssType == eSIR_BTAMP_AP_MODE)||(psessionEntry->bssType == eSIR_BTAMP_STA_MODE))
            {
                limProcessBtampAddBssRsp(pMac,limMsgQ,psessionEntry);
            }
            else
            limProcessApMlmAddBssRsp( pMac,limMsgQ);
        }
        else
            /* Called while processing assoc response */
            limProcessStaMlmAddBssRsp( pMac, limMsgQ,psessionEntry);
    }
<<<<<<< HEAD
<<<<<<< HEAD
=======

    if(limIsInMCC(pMac))
    {
       WDA_TrafficStatsTimerActivate(TRUE);
    }

#ifdef WLAN_FEATURE_11W
    if (psessionEntry->limRmfEnabled)
    {
        if ( eSIR_SUCCESS != limSendExcludeUnencryptInd(pMac, FALSE, psessionEntry) )
        {
            limLog( pMac, LOGE,
                    FL( "Could not send down Exclude Unencrypted Indication!" ),
                    psessionEntry->limMlmState );
        }
    }
#endif
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
}
/**
 * limProcessMlmSetKeyRsp()
 *
 *FUNCTION:
 * This function is called to process the following two
 * messages from HAL:
 * 1) WDA_SET_BSSKEY_RSP
 * 2) WDA_SET_STAKEY_RSP
 * 3) WDA_SET_STA_BCASTKEY_RSP
 * Upon receipt of this message from HAL,
 * MLME -
 * > Determines the "state" in which this message was received
 * > Forwards it to the appropriate callback
 *
 *LOGIC:
 * WDA_SET_BSSKEY_RSP/WDA_SET_STAKEY_RSP can be
 * received by MLME while in the following state:
 * MLME state = eLIM_MLM_WT_SET_BSS_KEY_STATE --OR--
 * MLME state = eLIM_MLM_WT_SET_STA_KEY_STATE --OR--
 * MLME state = eLIM_MLM_WT_SET_STA_BCASTKEY_STATE
 * Based on this state, this API will determine where to
 * route the message to
 *
 *ASSUMPTIONS:
 * ONLY the MLME state is being taken into account for now.
 * This is because, it appears that the handling of the
 * SETKEYS REQ is handled symmetrically on both the AP & STA
 *
 *NOTE:
 *
 * @param  pMac      Pointer to Global MAC structure
 * @param  tSirMsgQ  The MsgQ header, which contains the response buffer
 *
 * @return None
 */
void limProcessMlmSetStaKeyRsp( tpAniSirGlobal pMac, tpSirMsgQ limMsgQ )
{
    tANI_U8           respReqd = 1;
    tLimMlmSetKeysCnf mlmSetKeysCnf;
    tANI_U8  sessionId = 0;
    tpPESession  psessionEntry;
    SET_LIM_PROCESS_DEFD_MESGS(pMac, true);
<<<<<<< HEAD
<<<<<<< HEAD
    palZeroMemory( pMac->hHdd, (void *)&mlmSetKeysCnf, sizeof( tLimMlmSetKeysCnf ));
   //BTAMP
    if( NULL == limMsgQ->bodyptr )
    {
        PELOGE(limLog(pMac, LOGE,FL("limMsgQ bodyptr is NULL\n"));)
=======
    vos_mem_set((void *)&mlmSetKeysCnf, sizeof( tLimMlmSetKeysCnf ), 0);
   //BTAMP
    if( NULL == limMsgQ->bodyptr )
    {
        PELOGE(limLog(pMac, LOGE,FL("limMsgQ bodyptr is NULL"));)
>>>>>>> d97af3b... add prima wlan driver
=======
    palZeroMemory( pMac->hHdd, (void *)&mlmSetKeysCnf, sizeof( tLimMlmSetKeysCnf ));
   //BTAMP
    if( NULL == limMsgQ->bodyptr )
    {
        PELOGE(limLog(pMac, LOGE,FL("limMsgQ bodyptr is NULL\n"));)
>>>>>>> 657b0e9... prima update
        return;
    }
    sessionId = ((tpSetStaKeyParams) limMsgQ->bodyptr)->sessionId;
    if((psessionEntry = peFindSessionBySessionId(pMac, sessionId))== NULL)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        PELOGE(limLog(pMac, LOGE,FL("session does not exist for given sessionId\n"));)
        palFreeMemory( pMac->hHdd, (void *) limMsgQ->bodyptr );
=======
        PELOGE(limLog(pMac, LOGE,FL("session does not exist for given sessionId"));)
        vos_mem_free(limMsgQ->bodyptr);
>>>>>>> d97af3b... add prima wlan driver
=======
        PELOGE(limLog(pMac, LOGE,FL("session does not exist for given sessionId\n"));)
        palFreeMemory( pMac->hHdd, (void *) limMsgQ->bodyptr );
>>>>>>> 657b0e9... prima update
        return;
    }
    if( eLIM_MLM_WT_SET_STA_KEY_STATE != psessionEntry->limMlmState )
    {
        // Mesg received from HAL in Invalid state!
<<<<<<< HEAD
<<<<<<< HEAD
        limLog( pMac, LOGW, FL( "Received unexpected [Mesg Id - %d] in state %X\n" ), limMsgQ->type, psessionEntry->limMlmState );
=======
        limLog( pMac, LOGW, FL( "Received unexpected [Mesg Id - %d] in state %X" ), limMsgQ->type, psessionEntry->limMlmState );
>>>>>>> d97af3b... add prima wlan driver
=======
        limLog( pMac, LOGW, FL( "Received unexpected [Mesg Id - %d] in state %X\n" ), limMsgQ->type, psessionEntry->limMlmState );
>>>>>>> 657b0e9... prima update
        // There's not much that MLME can do at this stage...
        respReqd = 0;
    }
    else
      mlmSetKeysCnf.resultCode = (tANI_U16) (((tpSetStaKeyParams) limMsgQ->bodyptr)->status);

<<<<<<< HEAD
<<<<<<< HEAD
    palFreeMemory( pMac->hHdd, (void *) limMsgQ->bodyptr );
=======
    vos_mem_free(limMsgQ->bodyptr);
>>>>>>> d97af3b... add prima wlan driver
=======
    palFreeMemory( pMac->hHdd, (void *) limMsgQ->bodyptr );
>>>>>>> 657b0e9... prima update
    // Restore MLME state
    psessionEntry->limMlmState = psessionEntry->limPrevMlmState;
    MTRACE(macTrace(pMac, TRACE_CODE_MLM_STATE, psessionEntry->peSessionId, psessionEntry->limMlmState));
    if( respReqd )
    {
        tpLimMlmSetKeysReq lpLimMlmSetKeysReq = (tpLimMlmSetKeysReq) pMac->lim.gpLimMlmSetKeysReq;
        // Prepare and Send LIM_MLM_SETKEYS_CNF
        if( NULL != lpLimMlmSetKeysReq )
        {
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
            palCopyMemory( pMac->hHdd, (tANI_U8 *) &mlmSetKeysCnf.peerMacAddr, (tANI_U8 *) lpLimMlmSetKeysReq->peerMacAddr, sizeof(tSirMacAddr) );
#ifdef ANI_PRODUCT_TYPE_AP
            mlmSetKeysCnf.aid = lpLimMlmSetKeysReq->aid;
#endif
<<<<<<< HEAD
            // Free the buffer cached for the global pMac->lim.gpLimMlmSetKeysReq
            palFreeMemory(pMac->hHdd, (tANI_U8 *) pMac->lim.gpLimMlmSetKeysReq);
=======
            vos_mem_copy((tANI_U8 *) &mlmSetKeysCnf.peerMacAddr,
                         (tANI_U8 *) lpLimMlmSetKeysReq->peerMacAddr,
                          sizeof(tSirMacAddr));
            // Free the buffer cached for the global pMac->lim.gpLimMlmSetKeysReq
            vos_mem_free(pMac->lim.gpLimMlmSetKeysReq);
>>>>>>> d97af3b... add prima wlan driver
=======
            // Free the buffer cached for the global pMac->lim.gpLimMlmSetKeysReq
            palFreeMemory(pMac->hHdd, (tANI_U8 *) pMac->lim.gpLimMlmSetKeysReq);
>>>>>>> 657b0e9... prima update
            pMac->lim.gpLimMlmSetKeysReq = NULL;
        }
        mlmSetKeysCnf.sessionId = sessionId;
        limPostSmeMessage(pMac, LIM_MLM_SETKEYS_CNF, (tANI_U32 *) &mlmSetKeysCnf);
    }
}
void limProcessMlmSetBssKeyRsp( tpAniSirGlobal pMac, tpSirMsgQ limMsgQ )
{
    tANI_U8 respReqd = 1;
    tLimMlmSetKeysCnf mlmSetKeysCnf;
    tANI_U16          resultCode;
    tANI_U8           sessionId = 0;
    tpPESession  psessionEntry;
    SET_LIM_PROCESS_DEFD_MESGS(pMac, true);
<<<<<<< HEAD
<<<<<<< HEAD
    palZeroMemory( pMac->hHdd, (void *)&mlmSetKeysCnf, sizeof( tLimMlmSetKeysCnf ));
   //BTAMP
    if( NULL == limMsgQ->bodyptr )
    {
        PELOGE(limLog(pMac, LOGE,FL("limMsgQ bodyptr is null\n"));)
=======
    vos_mem_set((void *)&mlmSetKeysCnf, sizeof( tLimMlmSetKeysCnf ), 0);
   //BTAMP
    if( NULL == limMsgQ->bodyptr )
    {
        PELOGE(limLog(pMac, LOGE,FL("limMsgQ bodyptr is null"));)
>>>>>>> d97af3b... add prima wlan driver
=======
    palZeroMemory( pMac->hHdd, (void *)&mlmSetKeysCnf, sizeof( tLimMlmSetKeysCnf ));
   //BTAMP
    if( NULL == limMsgQ->bodyptr )
    {
        PELOGE(limLog(pMac, LOGE,FL("limMsgQ bodyptr is null\n"));)
>>>>>>> 657b0e9... prima update
        return;
    }
    sessionId = ((tpSetBssKeyParams) limMsgQ->bodyptr)->sessionId;
    if((psessionEntry = peFindSessionBySessionId(pMac, sessionId))== NULL)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        PELOGE(limLog(pMac, LOGE,FL("session does not exist for given sessionId\n"));)
        palFreeMemory( pMac->hHdd, (void *) limMsgQ->bodyptr );
=======
        PELOGE(limLog(pMac, LOGE,FL("session does not exist for given sessionId"));)
        vos_mem_free( limMsgQ->bodyptr );
>>>>>>> d97af3b... add prima wlan driver
=======
        PELOGE(limLog(pMac, LOGE,FL("session does not exist for given sessionId\n"));)
        palFreeMemory( pMac->hHdd, (void *) limMsgQ->bodyptr );
>>>>>>> 657b0e9... prima update
        return;
    }
    if( eLIM_MLM_WT_SET_BSS_KEY_STATE == psessionEntry->limMlmState )
        resultCode = (tANI_U16) (((tpSetBssKeyParams) limMsgQ->bodyptr)->status);
    else
        resultCode = (tANI_U16) (((tpSetStaKeyParams) limMsgQ->bodyptr)->status); //BCAST key also uses tpSetStaKeyParams. Done this way for readabilty.

    //
    // TODO & FIXME_GEN4
    // Need to inspect tSirMsgQ.reserved for a valid Dialog token!
    //
  // Validate SME/LIM state - Read the above "ASSUMPTIONS"
  //if( eLIM_SME_LINK_EST_STATE == pMac->lim.gLimSmeState )
  //{
    // Validate MLME state
    if( eLIM_MLM_WT_SET_BSS_KEY_STATE != psessionEntry->limMlmState &&
        eLIM_MLM_WT_SET_STA_BCASTKEY_STATE != psessionEntry->limMlmState )
    {
        // Mesg received from HAL in Invalid state!
<<<<<<< HEAD
<<<<<<< HEAD
        limLog( pMac, LOGW, FL( "Received unexpected [Mesg Id - %d] in state %X\n" ), limMsgQ->type, psessionEntry->limMlmState );
=======
        limLog( pMac, LOGW, FL( "Received unexpected [Mesg Id - %d] in state %X" ), limMsgQ->type, psessionEntry->limMlmState );
>>>>>>> d97af3b... add prima wlan driver
=======
        limLog( pMac, LOGW, FL( "Received unexpected [Mesg Id - %d] in state %X\n" ), limMsgQ->type, psessionEntry->limMlmState );
>>>>>>> 657b0e9... prima update
        // There's not much that MLME can do at this stage...
        respReqd = 0;
    }
    else
      mlmSetKeysCnf.resultCode = resultCode;

<<<<<<< HEAD
<<<<<<< HEAD
    palFreeMemory( pMac->hHdd, (void *) limMsgQ->bodyptr );
=======
    vos_mem_free(limMsgQ->bodyptr);
>>>>>>> d97af3b... add prima wlan driver
=======
    palFreeMemory( pMac->hHdd, (void *) limMsgQ->bodyptr );
>>>>>>> 657b0e9... prima update
    // Restore MLME state
    psessionEntry->limMlmState = psessionEntry->limPrevMlmState;

    MTRACE(macTrace(pMac, TRACE_CODE_MLM_STATE, psessionEntry->peSessionId, psessionEntry->limMlmState));
    if( respReqd )
    {
        tpLimMlmSetKeysReq lpLimMlmSetKeysReq = (tpLimMlmSetKeysReq) pMac->lim.gpLimMlmSetKeysReq;
        mlmSetKeysCnf.sessionId = sessionId;

        // Prepare and Send LIM_MLM_SETKEYS_CNF
        if( NULL != lpLimMlmSetKeysReq )
        {
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
            palCopyMemory( pMac->hHdd, (tANI_U8 *) &mlmSetKeysCnf.peerMacAddr, (tANI_U8 *) lpLimMlmSetKeysReq->peerMacAddr, sizeof(tSirMacAddr) );
#ifdef ANI_PRODUCT_TYPE_AP
            mlmSetKeysCnf.aid = lpLimMlmSetKeysReq->aid;
#endif
<<<<<<< HEAD
            // Free the buffer cached for the global pMac->lim.gpLimMlmSetKeysReq
            palFreeMemory(pMac->hHdd, (tANI_U8 *) pMac->lim.gpLimMlmSetKeysReq);
=======
            vos_mem_copy((tANI_U8 *) &mlmSetKeysCnf.peerMacAddr,
                         (tANI_U8 *) lpLimMlmSetKeysReq->peerMacAddr,
                         sizeof(tSirMacAddr));
            // Free the buffer cached for the global pMac->lim.gpLimMlmSetKeysReq
            vos_mem_free(pMac->lim.gpLimMlmSetKeysReq);
>>>>>>> d97af3b... add prima wlan driver
=======
            // Free the buffer cached for the global pMac->lim.gpLimMlmSetKeysReq
            palFreeMemory(pMac->hHdd, (tANI_U8 *) pMac->lim.gpLimMlmSetKeysReq);
>>>>>>> 657b0e9... prima update
            pMac->lim.gpLimMlmSetKeysReq = NULL;
        }
        limPostSmeMessage(pMac, LIM_MLM_SETKEYS_CNF, (tANI_U32 *) &mlmSetKeysCnf);
    }
}
/**
 * limProcessMlmRemoveKeyRsp()
 *
 *FUNCTION:
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 *
 *NOTE:
 *
 * @param  pMac      Pointer to Global MAC structure
 * @param  tSirMsgQ  The MsgQ header, which contains the response buffer
 *
 * @return None
 */
void limProcessMlmRemoveKeyRsp( tpAniSirGlobal pMac, tpSirMsgQ limMsgQ )
{
    tANI_U8 respReqd = 1;
    tLimMlmRemoveKeyCnf mlmRemoveCnf;
    tANI_U16             resultCode;
    tANI_U8              sessionId = 0;
    tpPESession  psessionEntry;
    SET_LIM_PROCESS_DEFD_MESGS(pMac, true);
<<<<<<< HEAD
<<<<<<< HEAD
    palZeroMemory( pMac->hHdd, (void *) &mlmRemoveCnf, sizeof( tLimMlmRemoveKeyCnf ));

    if( NULL == limMsgQ->bodyptr )
    {
        PELOGE(limLog(pMac, LOGE,FL("limMsgQ bodyptr is NULL\n"));)
=======
    vos_mem_set((void *) &mlmRemoveCnf, sizeof( tLimMlmRemoveKeyCnf ), 0);

    if( NULL == limMsgQ->bodyptr )
    {
        PELOGE(limLog(pMac, LOGE,FL("limMsgQ bodyptr is NULL"));)
>>>>>>> d97af3b... add prima wlan driver
=======
    palZeroMemory( pMac->hHdd, (void *) &mlmRemoveCnf, sizeof( tLimMlmRemoveKeyCnf ));

    if( NULL == limMsgQ->bodyptr )
    {
        PELOGE(limLog(pMac, LOGE,FL("limMsgQ bodyptr is NULL\n"));)
>>>>>>> 657b0e9... prima update
        return;
    }

    if (limMsgQ->type == WDA_REMOVE_STAKEY_RSP)
        sessionId = ((tpRemoveStaKeyParams) limMsgQ->bodyptr)->sessionId;
    else if (limMsgQ->type == WDA_REMOVE_BSSKEY_RSP)
        sessionId = ((tpRemoveBssKeyParams) limMsgQ->bodyptr)->sessionId;

    if((psessionEntry = peFindSessionBySessionId(pMac, sessionId))== NULL)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        PELOGE(limLog(pMac, LOGE,FL("session does not exist for given sessionId\n"));)
=======
        PELOGE(limLog(pMac, LOGE,FL("session does not exist for given sessionId"));)
>>>>>>> d97af3b... add prima wlan driver
=======
        PELOGE(limLog(pMac, LOGE,FL("session does not exist for given sessionId\n"));)
>>>>>>> 657b0e9... prima update
        return;
    }

    if( eLIM_MLM_WT_REMOVE_BSS_KEY_STATE == psessionEntry->limMlmState )
      resultCode = (tANI_U16) (((tpRemoveBssKeyParams) limMsgQ->bodyptr)->status);
    else
      resultCode = (tANI_U16) (((tpRemoveStaKeyParams) limMsgQ->bodyptr)->status);

    // Validate MLME state
    if( eLIM_MLM_WT_REMOVE_BSS_KEY_STATE != psessionEntry->limMlmState &&
        eLIM_MLM_WT_REMOVE_STA_KEY_STATE != psessionEntry->limMlmState )
    {
        // Mesg received from HAL in Invalid state!
        limLog(pMac, LOGW,
<<<<<<< HEAD
<<<<<<< HEAD
            FL("Received unexpected [Mesg Id - %d] in state %X\n"),
=======
            FL("Received unexpected [Mesg Id - %d] in state %X"),
>>>>>>> d97af3b... add prima wlan driver
=======
            FL("Received unexpected [Mesg Id - %d] in state %X\n"),
>>>>>>> 657b0e9... prima update
          limMsgQ->type,
          psessionEntry->limMlmState );
          respReqd = 0;
    }
    else
        mlmRemoveCnf.resultCode = resultCode;

    //
    // TODO & FIXME_GEN4
    // Need to inspect tSirMsgQ.reserved for a valid Dialog token!
    //

<<<<<<< HEAD
<<<<<<< HEAD
    palFreeMemory( pMac->hHdd, (void *) limMsgQ->bodyptr );
=======
    vos_mem_free(limMsgQ->bodyptr);
>>>>>>> d97af3b... add prima wlan driver
=======
    palFreeMemory( pMac->hHdd, (void *) limMsgQ->bodyptr );
>>>>>>> 657b0e9... prima update

    // Restore MLME state
    psessionEntry->limMlmState = psessionEntry->limPrevMlmState;
    MTRACE(macTrace(pMac, TRACE_CODE_MLM_STATE, psessionEntry->peSessionId, psessionEntry->limMlmState));

    if( respReqd )
    {
        tpLimMlmRemoveKeyReq lpLimMlmRemoveKeyReq = (tpLimMlmRemoveKeyReq) pMac->lim.gpLimMlmRemoveKeyReq;
        mlmRemoveCnf.sessionId = sessionId;

    // Prepare and Send LIM_MLM_REMOVEKEY_CNF
        if( NULL != lpLimMlmRemoveKeyReq )
    {
<<<<<<< HEAD
<<<<<<< HEAD
            palCopyMemory( pMac->hHdd, (tANI_U8 *) &mlmRemoveCnf.peerMacAddr, (tANI_U8 *) lpLimMlmRemoveKeyReq->peerMacAddr,
                      sizeof( tSirMacAddr ));
        // Free the buffer cached for the global pMac->lim.gpLimMlmRemoveKeyReq
        palFreeMemory(pMac->hHdd, (tANI_U8 *) pMac->lim.gpLimMlmRemoveKeyReq);
=======
            vos_mem_copy((tANI_U8 *) &mlmRemoveCnf.peerMacAddr,
                         (tANI_U8 *) lpLimMlmRemoveKeyReq->peerMacAddr,
                         sizeof( tSirMacAddr ));
        // Free the buffer cached for the global pMac->lim.gpLimMlmRemoveKeyReq
        vos_mem_free(pMac->lim.gpLimMlmRemoveKeyReq);
>>>>>>> d97af3b... add prima wlan driver
=======
            palCopyMemory( pMac->hHdd, (tANI_U8 *) &mlmRemoveCnf.peerMacAddr, (tANI_U8 *) lpLimMlmRemoveKeyReq->peerMacAddr,
                      sizeof( tSirMacAddr ));
        // Free the buffer cached for the global pMac->lim.gpLimMlmRemoveKeyReq
        palFreeMemory(pMac->hHdd, (tANI_U8 *) pMac->lim.gpLimMlmRemoveKeyReq);
>>>>>>> 657b0e9... prima update
        pMac->lim.gpLimMlmRemoveKeyReq = NULL;
    }
        limPostSmeMessage( pMac, LIM_MLM_REMOVEKEY_CNF, (tANI_U32 *) &mlmRemoveCnf );
    }
}

<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
#if (defined(ANI_PRODUCT_TYPE_AP) || defined(ANI_PRODUCT_TYPE_AP_SDK))
/**----------------------------------------------------
\fn     __limProcessFinishLearnRsp
\brief  Handle finish learn rsp state, only for AP.
\param  pMac
\return NONE
-----------------------------------------------------*/
static void __limProcessFinishLearnRsp(tpAniSirGlobal pMac)
{
    PELOG2(limLog(pMac, LOG2, FL("System Role: %d\n"), pMac->lim.gLimSystemRole);)
    if (pMac->lim.gpLimMeasReq == NULL)
    {
        limRestorePreLearnState(pMac);
        return;
    }
    /**
      * Initial measurement -> periodic measurement should keep enabled, so that
      * if system Role is UNKNOWN LIM can send indication to WSM. Overloading
      * periodic measurement to distinguish initial measurement and radar
      * detect park basically to avoid sending measurement indication after
      * radar detect park.
      * Radar detect park -> periodic measurement should be disabled, so that
      * LIM wont send indication even when role is UNKNOWN.
      * Final measurement -> periodic measurement should be enabled, so that
      * LIM could start measurement indication timer.
      */
    if (pMac->lim.gpLimMeasReq->measControl.periodicMeasEnabled &&
                !pMac->lim.gLimMeasParams.isMeasIndTimerActive)
    {
#if 0 /* Will we be ever in UNKNOWN ROLE: Veerendra */
        if (pMac->lim.gLimSystemRole == eLIM_UNKNOWN_ROLE)
        {
            limSendSmeMeasurementInd(pMac);
            limCleanupMeasResources(pMac);
            limRestorePreLearnState(pMac);
            return;
        }
        else
#endif
        {
#ifdef GEN6_TODO
            /* revisit this piece of code to assign the appropriate sessionId below
             * priority - MEDIUM
             */
            pMac->lim.gLimMeasParams.measurementIndTimer.sessionId = sessionId;
#endif
            // Activate periodic measurement indication timer
            if (tx_timer_activate(
               &pMac->lim.gLimMeasParams.measurementIndTimer)
               != TX_SUCCESS)
            {
                limLog(pMac, LOGP, FL("could not start Meas IND timer\n"));
                return;
            }
            pMac->lim.gLimMeasParams.isMeasIndTimerActive = 1;
        }
    }
    if (pMac->lim.gLimMeasParams.nextLearnChannelId >=
            pMac->lim.gpLimMeasReq->channelList.numChannels - 1)
    {
        // All channels in the channel set are learned.
        pMac->lim.gLimMeasParams.nextLearnChannelId = 0;
    }
    // Go back to previous state.
    limRestorePreLearnState(pMac);
    // Restart the learn interval timer.
    if (pMac->lim.gpLimMeasReq->measControl.periodicMeasEnabled)
        limReEnableLearnMode(pMac);
    return;
}
#endif
<<<<<<< HEAD
=======
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update

/** ---------------------------------------------------------------------
\fn      limProcessInitScanRsp
\brief   This function is called when LIM receives WDA_INIT_SCAN_RSP
\        message from HAL.  If status code is failure, then
\        update the gLimNumOfConsecutiveBkgndScanFailure count.
\param   tpAniSirGlobal  pMac
\param   tANI_U32        body
\return  none
\ ----------------------------------------------------------------------- */
void limProcessInitScanRsp(tpAniSirGlobal pMac,  void *body)
{
    tpInitScanParams    pInitScanParam;
    eHalStatus          status;
<<<<<<< HEAD
<<<<<<< HEAD
#if defined(ANI_PRODUCT_TYPE_AP) && (WNI_POLARIS_FW_PACKAGE == ADVANCED)
    tANI_U8             channelNum;
#endif
    SET_LIM_PROCESS_DEFD_MESGS(pMac, true);
    pInitScanParam = (tpInitScanParams) body;
    status = pInitScanParam->status;
    palFreeMemory( pMac->hHdd, (char *)body);
=======
    SET_LIM_PROCESS_DEFD_MESGS(pMac, true);
    pInitScanParam = (tpInitScanParams) body;
    status = pInitScanParam->status;
    vos_mem_free(body);
>>>>>>> d97af3b... add prima wlan driver
=======
#if defined(ANI_PRODUCT_TYPE_AP) && (WNI_POLARIS_FW_PACKAGE == ADVANCED)
    tANI_U8             channelNum;
#endif
    SET_LIM_PROCESS_DEFD_MESGS(pMac, true);
    pInitScanParam = (tpInitScanParams) body;
    status = pInitScanParam->status;
    palFreeMemory( pMac->hHdd, (char *)body);
>>>>>>> 657b0e9... prima update

    //Only abort scan if the we are scanning.
    if( pMac->lim.abortScan && 
       (eLIM_HAL_INIT_SCAN_WAIT_STATE == pMac->lim.gLimHalScanState) )
    {
<<<<<<< HEAD
<<<<<<< HEAD
        limLog( pMac, LOGW, FL(" finish scan\n") );
=======
        limLog( pMac, LOGW, FL(" abort scan") );
>>>>>>> d97af3b... add prima wlan driver
=======
        limLog( pMac, LOGW, FL(" finish scan\n") );
>>>>>>> 657b0e9... prima update
        pMac->lim.abortScan = 0;
        limDeactivateAndChangeTimer(pMac, eLIM_MIN_CHANNEL_TIMER);
        limDeactivateAndChangeTimer(pMac, eLIM_MAX_CHANNEL_TIMER);
        //Set the resume channel to Any valid channel (invalid). 
        //This will instruct HAL to set it to any previous valid channel.
        peSetResumeChannel(pMac, 0, 0);
<<<<<<< HEAD
<<<<<<< HEAD
        limSendHalFinishScanReq(pMac, eLIM_HAL_FINISH_SCAN_WAIT_STATE);
=======
        if (status != eHAL_STATUS_SUCCESS)
        {
           PELOGW(limLog(pMac, LOGW, FL("InitScnRsp failed status=%d"),status);)
           pMac->lim.gLimHalScanState = eLIM_HAL_IDLE_SCAN_STATE;
           pMac->lim.gLimNumOfConsecutiveBkgndScanFailure += 1;
           limCompleteMlmScan(pMac, eSIR_SME_HAL_SCAN_INIT_FAILED);
           return;
        }
        else
        {
           limSendHalFinishScanReq(pMac, eLIM_HAL_FINISH_SCAN_WAIT_STATE);
        }

>>>>>>> d97af3b... add prima wlan driver
=======
        limSendHalFinishScanReq(pMac, eLIM_HAL_FINISH_SCAN_WAIT_STATE);
>>>>>>> 657b0e9... prima update
    }
    switch(pMac->lim.gLimHalScanState)
    {
        case eLIM_HAL_INIT_SCAN_WAIT_STATE:
            if (status != (tANI_U32) eHAL_STATUS_SUCCESS)
            {
<<<<<<< HEAD
<<<<<<< HEAD
               PELOGW(limLog(pMac, LOGW, FL("InitScanRsp with failed status= %d\n"), status);)
=======
               PELOGW(limLog(pMac, LOGW, FL("InitScanRsp with failed status= %d"), status);)
>>>>>>> d97af3b... add prima wlan driver
=======
               PELOGW(limLog(pMac, LOGW, FL("InitScanRsp with failed status= %d\n"), status);)
>>>>>>> 657b0e9... prima update
               pMac->lim.gLimHalScanState = eLIM_HAL_IDLE_SCAN_STATE;
               pMac->lim.gLimNumOfConsecutiveBkgndScanFailure += 1;
               /*
                * On Windows eSIR_SME_HAL_SCAN_INIT_FAILED message to CSR may trigger
                * another Scan request in the same context (happens when 11d is enabled
                * and first scan request with 11d channels fails for whatever reason, then CSR issues next init
                * scan in the same context but with bigger channel list), so the state needs to be
                * changed before this response message is sent.
                */
               limCompleteMlmScan(pMac, eSIR_SME_HAL_SCAN_INIT_FAILED);
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
#if defined(ANI_PRODUCT_TYPE_AP) && (WNI_POLARIS_FW_PACKAGE == ADVANCED)
                /* For handling the measurement request from WSM as scan request in LIM*/
#if 0
               if (pMac->lim.gLimSystemRole == eLIM_STA_ROLE && pMac->lim.gpLimMeasReq != NULL)
                {
                    limRestorePreLearnState(pMac);
                    pMac->lim.gLimHalScanState = eLIM_HAL_IDLE_SCAN_STATE;
                    limReEnableLearnMode(pMac);
                }
#endif
#endif
<<<<<<< HEAD
=======
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
                return;
            }
            else if (status == eHAL_STATUS_SUCCESS)
            {
                /* since we have successfully triggered a background scan,
                 * reset the "consecutive bkgnd scan failure" count to 0
                 */
                pMac->lim.gLimNumOfConsecutiveBkgndScanFailure = 0;
                pMac->lim.gLimNumOfBackgroundScanSuccess += 1;
            }
            limContinueChannelScan(pMac);
            break;
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
#if defined(ANI_PRODUCT_TYPE_AP) && (WNI_POLARIS_FW_PACKAGE == ADVANCED)
        case eLIM_HAL_INIT_LEARN_WAIT_STATE:
//            if (pMac->lim.gLimSystemRole == eLIM_AP_ROLE)
            {
                if (status != (tANI_U32) eHAL_STATUS_SUCCESS)
                {
                    limRestorePreLearnState(pMac);
                    pMac->lim.gLimHalScanState = eLIM_HAL_IDLE_SCAN_STATE;
                    limReEnableLearnMode(pMac);
                    return;
                }
                channelNum = limGetCurrentLearnChannel(pMac);
                limSendHalStartScanReq(pMac, channelNum, eLIM_HAL_START_LEARN_WAIT_STATE);
            }
            break;
#endif
<<<<<<< HEAD
=======
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
//WLAN_SUSPEND_LINK Related
        case eLIM_HAL_SUSPEND_LINK_WAIT_STATE:
            if( pMac->lim.gpLimSuspendCallback )
            {
               if( status == eHAL_STATUS_SUCCESS )
                  pMac->lim.gLimHalScanState = eLIM_HAL_SUSPEND_LINK_STATE;
               else
                  pMac->lim.gLimHalScanState = eLIM_HAL_IDLE_SCAN_STATE;

               pMac->lim.gpLimSuspendCallback( pMac, status, pMac->lim.gpLimSuspendData );
               pMac->lim.gpLimSuspendCallback = NULL;
               pMac->lim.gpLimSuspendData = NULL;
            }
            else
            {
<<<<<<< HEAD
<<<<<<< HEAD
               limLog( pMac, LOGP, "No suspend link callback set but station is in suspend state\n");
=======
               limLog( pMac, LOGP, "No suspend link callback set but station is in suspend state");
>>>>>>> d97af3b... add prima wlan driver
=======
               limLog( pMac, LOGP, "No suspend link callback set but station is in suspend state\n");
>>>>>>> 657b0e9... prima update
               return;
            }
            break;
//end WLAN_SUSPEND_LINK Related
        default:
<<<<<<< HEAD
<<<<<<< HEAD
            limLog(pMac, LOGW, FL("limProcessInitScanRsp: Rcvd InitScanRsp not in WAIT State, state %d\n"),
=======
            limLog(pMac, LOGW, FL("limProcessInitScanRsp: Rcvd InitScanRsp not in WAIT State, state %d"),
>>>>>>> d97af3b... add prima wlan driver
=======
            limLog(pMac, LOGW, FL("limProcessInitScanRsp: Rcvd InitScanRsp not in WAIT State, state %d\n"),
>>>>>>> 657b0e9... prima update
                   pMac->lim.gLimHalScanState);
            break;
    }
    return;
}
/**
 * limProcessSwitchChannelReAssocReq()
 *
 *FUNCTION:
 * This function is called to send the reassoc req mgmt frame after the
 * switchChannelRsp message is received from HAL.
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 * NA
 *
 *NOTE:
 * NA
 *
 * @param  pMac          - Pointer to Global MAC structure.
 * @param  psessionEntry - session related information.
 * @param  status        - channel switch success/failure.
 *
 * @return None
 */
static void limProcessSwitchChannelReAssocReq(tpAniSirGlobal pMac, tpPESession psessionEntry, eHalStatus status)
{
    tLimMlmReassocCnf       mlmReassocCnf;
    tLimMlmReassocReq       *pMlmReassocReq;
    pMlmReassocReq = (tLimMlmReassocReq *)(psessionEntry->pLimMlmReassocReq);
    if(pMlmReassocReq == NULL)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        limLog(pMac, LOGP, FL("pLimMlmReassocReq does not exist for given switchChanSession\n"));
=======
        limLog(pMac, LOGP, FL("pLimMlmReassocReq does not exist for given switchChanSession"));
>>>>>>> d97af3b... add prima wlan driver
=======
        limLog(pMac, LOGP, FL("pLimMlmReassocReq does not exist for given switchChanSession\n"));
>>>>>>> 657b0e9... prima update
        mlmReassocCnf.resultCode = eSIR_SME_RESOURCES_UNAVAILABLE;
        goto end;
    }

    if(status != eHAL_STATUS_SUCCESS)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        PELOGE(limLog(pMac, LOGE, FL("Change channel failed!!\n"));)
=======
        PELOGE(limLog(pMac, LOGE, FL("Change channel failed!!"));)
>>>>>>> d97af3b... add prima wlan driver
=======
        PELOGE(limLog(pMac, LOGE, FL("Change channel failed!!\n"));)
>>>>>>> 657b0e9... prima update
        mlmReassocCnf.resultCode = eSIR_SME_CHANNEL_SWITCH_FAIL;
        goto end;
    }
    /// Start reassociation failure timer
    MTRACE(macTrace(pMac, TRACE_CODE_TIMER_ACTIVATE, psessionEntry->peSessionId, eLIM_REASSOC_FAIL_TIMER));
    if (tx_timer_activate(&pMac->lim.limTimers.gLimReassocFailureTimer)
                                               != TX_SUCCESS)
    {
        /// Could not start reassoc failure timer.
        // Log error
        limLog(pMac, LOGP,
<<<<<<< HEAD
<<<<<<< HEAD
           FL("could not start Reassociation failure timer\n"));
=======
           FL("could not start Reassociation failure timer"));
>>>>>>> d97af3b... add prima wlan driver
=======
           FL("could not start Reassociation failure timer\n"));
>>>>>>> 657b0e9... prima update
        // Return Reassoc confirm with
        // Resources Unavailable
        mlmReassocCnf.resultCode = eSIR_SME_RESOURCES_UNAVAILABLE;
        goto end;
    }
    /// Prepare and send Reassociation request frame
    limSendReassocReqMgmtFrame(pMac, pMlmReassocReq, psessionEntry);
    return;
end:
    // Free up buffer allocated for reassocReq
    if(pMlmReassocReq != NULL)
    {
        /* Update PE session Id*/
        mlmReassocCnf.sessionId = pMlmReassocReq->sessionId;
<<<<<<< HEAD
<<<<<<< HEAD
        palFreeMemory( pMac->hHdd, (tANI_U8 *) pMlmReassocReq);
=======
        vos_mem_free(pMlmReassocReq);
>>>>>>> d97af3b... add prima wlan driver
=======
        palFreeMemory( pMac->hHdd, (tANI_U8 *) pMlmReassocReq);
>>>>>>> 657b0e9... prima update
    }
    else
    {
        mlmReassocCnf.sessionId = 0;
    }

    mlmReassocCnf.protStatusCode = eSIR_MAC_UNSPEC_FAILURE_STATUS;
    /* Update PE sessio Id*/
    mlmReassocCnf.sessionId = psessionEntry->peSessionId;

    limPostSmeMessage(pMac, LIM_MLM_REASSOC_CNF, (tANI_U32 *) &mlmReassocCnf);
}
/**
 * limProcessSwitchChannelJoinReq()
 *
 *FUNCTION:
 * This function is called to send the probe req mgmt frame after the
 * switchChannelRsp message is received from HAL.
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 * NA
 *
 *NOTE:
 * NA
 *
 * @param  pMac          - Pointer to Global MAC structure.
 * @param  psessionEntry - session related information.
 * @param  status        - channel switch success/failure.
 *
 * @return None
 */
static void limProcessSwitchChannelJoinReq(tpAniSirGlobal pMac, tpPESession psessionEntry, eHalStatus status)
{
    tANI_U32            val;
    tSirMacSSid         ssId;
    tLimMlmJoinCnf      mlmJoinCnf;
    if(status != eHAL_STATUS_SUCCESS)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        PELOGE(limLog(pMac, LOGE, FL("Change channel failed!!\n"));)
=======
        PELOGE(limLog(pMac, LOGE, FL("Change channel failed!!"));)
>>>>>>> d97af3b... add prima wlan driver
=======
        PELOGE(limLog(pMac, LOGE, FL("Change channel failed!!\n"));)
>>>>>>> 657b0e9... prima update
        goto error;
    }

    if ( (NULL == psessionEntry ) || (NULL == psessionEntry->pLimMlmJoinReq) )
    {
<<<<<<< HEAD
<<<<<<< HEAD
        PELOGE(limLog(pMac, LOGE, FL("invalid pointer!!\n"));)
=======
        PELOGE(limLog(pMac, LOGE, FL("invalid pointer!!"));)
>>>>>>> d97af3b... add prima wlan driver
=======
        PELOGE(limLog(pMac, LOGE, FL("invalid pointer!!\n"));)
>>>>>>> 657b0e9... prima update
        goto error;
    }

   
    /* eSIR_BTAMP_AP_MODE stroed as bss type in session Table when join req is received, is to be veified   */
    if(psessionEntry->bssType == eSIR_BTAMP_AP_MODE)
    {
        if (limSetLinkState(pMac, eSIR_LINK_BTAMP_PREASSOC_STATE, psessionEntry->bssId,
             psessionEntry->selfMacAddr, NULL, NULL) != eSIR_SUCCESS )
            goto error;
    }
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
    else
    {
        if(limSetLinkState(pMac, eSIR_LINK_PREASSOC_STATE, psessionEntry->bssId,
            psessionEntry->selfMacAddr, NULL, NULL) != eSIR_SUCCESS)
            goto error;
    }
    // Update BSSID at CFG database
#if 0
    if (cfgSetStr(pMac, WNI_CFG_BSSID, pMac->lim.gpLimMlmJoinReq->bssDescription.bssId,
                  sizeof(tSirMacAddr))
        != eSIR_SUCCESS)
        limLog(pMac, LOGP, FL("could not update BSSID at CFG\n"));
#endif //TO SUPPORT BT-AMP
    //sirCopyMacAddr(psessionEntry->pLimMlmJoinReq->bssDescription.bssId,psessionEntry->bssId);
<<<<<<< HEAD

    /* Update the lim global gLimTriggerBackgroundScanDuringQuietBss */
    if(wlan_cfgGetInt(pMac, WNI_CFG_TRIG_STA_BK_SCAN, &val) != eSIR_SUCCESS)
        limLog(pMac, LOGP, FL("failed to get WNI_CFG_TRIG_STA_BK_SCAN cfg value!\n"));
=======

    /* Update the lim global gLimTriggerBackgroundScanDuringQuietBss */
    if(wlan_cfgGetInt(pMac, WNI_CFG_TRIG_STA_BK_SCAN, &val) != eSIR_SUCCESS)
        limLog(pMac, LOGP, FL("failed to get WNI_CFG_TRIG_STA_BK_SCAN cfg value!"));
>>>>>>> d97af3b... add prima wlan driver
=======

    /* Update the lim global gLimTriggerBackgroundScanDuringQuietBss */
    if(wlan_cfgGetInt(pMac, WNI_CFG_TRIG_STA_BK_SCAN, &val) != eSIR_SUCCESS)
        limLog(pMac, LOGP, FL("failed to get WNI_CFG_TRIG_STA_BK_SCAN cfg value!\n"));
>>>>>>> 657b0e9... prima update
    pMac->lim.gLimTriggerBackgroundScanDuringQuietBss = (val) ? 1 : 0;
    // Apply previously set configuration at HW
    limApplyConfiguration(pMac, psessionEntry);
    /// Wait for Beacon to announce join success
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
#if 0
    if (cfgGetStr(pMac, WNI_CFG_SSID, ssId.ssId, &cfgLen) != eSIR_SUCCESS)
        limLog(pMac, LOGP, FL("could not retrive SSID\n"));
#endif //To SUPPORT BT-AMP
    palCopyMemory( pMac->hHdd, ssId.ssId,
                          psessionEntry->ssId.ssId,
                          psessionEntry->ssId.length);
<<<<<<< HEAD
    ssId.length = psessionEntry->ssId.length;
=======
    vos_mem_copy(ssId.ssId,
                 psessionEntry->ssId.ssId,
                 psessionEntry->ssId.length);
    ssId.length = psessionEntry->ssId.length;

    limDeactivateAndChangeTimer(pMac, eLIM_PERIODIC_JOIN_PROBE_REQ_TIMER);

    //assign appropriate sessionId to the timer object
    pMac->lim.limTimers.gLimPeriodicJoinProbeReqTimer.sessionId = psessionEntry->peSessionId;
>>>>>>> d97af3b... add prima wlan driver
=======
    ssId.length = psessionEntry->ssId.length;
>>>>>>> 657b0e9... prima update
    // include additional IE if there is
    limSendProbeReqMgmtFrame( pMac, &ssId,
           psessionEntry->pLimMlmJoinReq->bssDescription.bssId, psessionEntry->currentOperChannel/*chanNum*/,
           psessionEntry->selfMacAddr, psessionEntry->dot11mode,
           psessionEntry->pLimJoinReq->addIEScan.length, psessionEntry->pLimJoinReq->addIEScan.addIEdata);

    // Sending mgmt frame is a blocking call activate Join failure timer now
    MTRACE(macTrace(pMac, TRACE_CODE_TIMER_ACTIVATE, psessionEntry->peSessionId, eLIM_JOIN_FAIL_TIMER));
    if (tx_timer_activate(&pMac->lim.limTimers.gLimJoinFailureTimer) != TX_SUCCESS)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        limLog(pMac, LOGP, FL("could not activate Join failure timer\n"));
=======
        limLog(pMac, LOGP, FL("could not activate Join failure timer"));
>>>>>>> d97af3b... add prima wlan driver
=======
        limLog(pMac, LOGP, FL("could not activate Join failure timer\n"));
>>>>>>> 657b0e9... prima update
        psessionEntry->limMlmState = psessionEntry->limPrevMlmState;
         MTRACE(macTrace(pMac, TRACE_CODE_MLM_STATE, psessionEntry->peSessionId, pMac->lim.gLimMlmState));
        //memory is freed up below.
        psessionEntry->pLimMlmJoinReq = NULL;
        goto error;
    }

<<<<<<< HEAD
<<<<<<< HEAD
=======
    if( psessionEntry->pePersona == VOS_P2P_CLIENT_MODE )
    {
        // Activate Join Periodic Probe Req timer
        if (tx_timer_activate(&pMac->lim.limTimers.gLimPeriodicJoinProbeReqTimer) != TX_SUCCESS)
        {
            limLog(pMac, LOGP, FL("could not activate Periodic Join req failure timer"));
            goto error;
        }
    }

>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
    return;
error:  
    if(NULL != psessionEntry)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        palFreeMemory( pMac->hHdd, (tANI_U8 *) (psessionEntry->pLimMlmJoinReq));
=======
        vos_mem_free(psessionEntry->pLimMlmJoinReq);
>>>>>>> d97af3b... add prima wlan driver
=======
        palFreeMemory( pMac->hHdd, (tANI_U8 *) (psessionEntry->pLimMlmJoinReq));
>>>>>>> 657b0e9... prima update
        psessionEntry->pLimMlmJoinReq = NULL;
        mlmJoinCnf.sessionId = psessionEntry->peSessionId;
    }
    else
    {
        mlmJoinCnf.sessionId = 0;
    }
    mlmJoinCnf.resultCode = eSIR_SME_RESOURCES_UNAVAILABLE;
    mlmJoinCnf.protStatusCode = eSIR_MAC_UNSPEC_FAILURE_STATUS;
    limPostSmeMessage(pMac, LIM_MLM_JOIN_CNF, (tANI_U32 *) &mlmJoinCnf);
}

/**
 * limProcessSwitchChannelRsp()
 *
 *FUNCTION:
 * This function is called to process switchChannelRsp message from HAL.
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 * NA
 *
 *NOTE:
 * NA
 *
 * @param  pMac    - Pointer to Global MAC structure
 * @param  body - message body.
 *
 * @return None
 */
void limProcessSwitchChannelRsp(tpAniSirGlobal pMac,  void *body)
{
    tpSwitchChannelParams pChnlParams = NULL;
    eHalStatus status;
    tANI_U16 channelChangeReasonCode;
    tANI_U8 peSessionId;
    tpPESession psessionEntry;
    //we need to process the deferred message since the initiating req. there might be nested request.
    //in the case of nested request the new request initiated from the response will take care of resetting
    //the deffered flag.
    SET_LIM_PROCESS_DEFD_MESGS(pMac, true);
    pChnlParams = (tpSwitchChannelParams) body;
    status = pChnlParams->status;
    peSessionId = pChnlParams->peSessionId;
    if((psessionEntry = peFindSessionBySessionId(pMac, peSessionId))== NULL)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        palFreeMemory( pMac->hHdd, (tANI_U8 *)body);
        limLog(pMac, LOGP, FL("session does not exist for given sessionId\n"));
=======
        vos_mem_free(body);
        limLog(pMac, LOGP, FL("session does not exist for given sessionId"));
>>>>>>> d97af3b... add prima wlan driver
=======
        palFreeMemory( pMac->hHdd, (tANI_U8 *)body);
        limLog(pMac, LOGP, FL("session does not exist for given sessionId\n"));
>>>>>>> 657b0e9... prima update
        return;
    }
#if defined WLAN_FEATURE_VOWIFI
    //HAL fills in the tx power used for mgmt frames in this field.
    //Store this value to use in TPC report IE.
    rrmCacheMgmtTxPower( pMac, pChnlParams->txMgmtPower, psessionEntry );
#endif
<<<<<<< HEAD
<<<<<<< HEAD
    palFreeMemory( pMac->hHdd, (tANI_U8 *)body);
=======
    vos_mem_free(body);
>>>>>>> d97af3b... add prima wlan driver
=======
    palFreeMemory( pMac->hHdd, (tANI_U8 *)body);
>>>>>>> 657b0e9... prima update
    channelChangeReasonCode = psessionEntry->channelChangeReasonCode;
    // initialize it back to invalid id
    psessionEntry->channelChangeReasonCode = 0xBAD;
    switch(channelChangeReasonCode)
    {
        case LIM_SWITCH_CHANNEL_REASSOC:
            limProcessSwitchChannelReAssocReq(pMac, psessionEntry, status);
            break;
        case LIM_SWITCH_CHANNEL_JOIN:
            limProcessSwitchChannelJoinReq(pMac, psessionEntry, status);
            break;

        case LIM_SWITCH_CHANNEL_OPERATION:
            /*
             * The above code should also use the callback.
             * mechanism below, there is scope for cleanup here.
             * THat way all this response handler does is call the call back
             * We can get rid of the reason code here.
             */
            if (pMac->lim.gpchangeChannelCallback)
            {
<<<<<<< HEAD
<<<<<<< HEAD
                PELOG1(limLog( pMac, LOG1, "Channel changed hence invoke registered call back\n");)
=======
                PELOG1(limLog( pMac, LOG1, "Channel changed hence invoke registered call back");)
>>>>>>> d97af3b... add prima wlan driver
=======
                PELOG1(limLog( pMac, LOG1, "Channel changed hence invoke registered call back\n");)
>>>>>>> 657b0e9... prima update
                pMac->lim.gpchangeChannelCallback(pMac, status, pMac->lim.gpchangeChannelData, psessionEntry);
            }
            break;
        default:
            break;
    }
}
/**
 * limProcessStartScanRsp()
 *
 *FUNCTION:
 * This function is called to process startScanRsp message from HAL. If scan/learn was successful
 *      then it will start scan/learn on the next channel.
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 * NA
 *
 *NOTE:
 * NA
 *
 * @param  pMac    - Pointer to Global MAC structure
 * @param  body - message body.
 *
 * @return None
 */

void limProcessStartScanRsp(tpAniSirGlobal pMac,  void *body)
{
    tpStartScanParams       pStartScanParam;
    eHalStatus              status;
    SET_LIM_PROCESS_DEFD_MESGS(pMac, true);
    pStartScanParam = (tpStartScanParams) body;
    status = pStartScanParam->status;
#if defined WLAN_FEATURE_VOWIFI
    //HAL fills in the tx power used for mgmt frames in this field.
    //Store this value to use in TPC report IE.
    rrmCacheMgmtTxPower( pMac, pStartScanParam->txMgmtPower, NULL );
    //Store start TSF of scan start. This will be stored in BSS params.
    rrmUpdateStartTSF( pMac, pStartScanParam->startTSF );
#endif
<<<<<<< HEAD
<<<<<<< HEAD
    palFreeMemory( pMac->hHdd, (tANI_U8 *)body);
    if( pMac->lim.abortScan )
    {
        limLog( pMac, LOGW, FL(" finish scan\n") );
=======
    vos_mem_free(body);
    if( pMac->lim.abortScan )
    {
        limLog( pMac, LOGW, FL(" finish scan") );
>>>>>>> d97af3b... add prima wlan driver
=======
    palFreeMemory( pMac->hHdd, (tANI_U8 *)body);
    if( pMac->lim.abortScan )
    {
        limLog( pMac, LOGW, FL(" finish scan\n") );
>>>>>>> 657b0e9... prima update
        pMac->lim.abortScan = 0;
        limDeactivateAndChangeTimer(pMac, eLIM_MIN_CHANNEL_TIMER);
        limDeactivateAndChangeTimer(pMac, eLIM_MAX_CHANNEL_TIMER);
        //Set the resume channel to Any valid channel (invalid). 
        //This will instruct HAL to set it to any previous valid channel.
        peSetResumeChannel(pMac, 0, 0);
        limSendHalFinishScanReq(pMac, eLIM_HAL_FINISH_SCAN_WAIT_STATE);
    }
    switch(pMac->lim.gLimHalScanState)
    {
        case eLIM_HAL_START_SCAN_WAIT_STATE:
            if (status != (tANI_U32) eHAL_STATUS_SUCCESS)
            {
<<<<<<< HEAD
<<<<<<< HEAD
               PELOGW(limLog(pMac, LOGW, FL("StartScanRsp with failed status= %d\n"), status);)
=======
               PELOGW(limLog(pMac, LOGW, FL("StartScanRsp with failed status= %d"), status);)
>>>>>>> d97af3b... add prima wlan driver
=======
               PELOGW(limLog(pMac, LOGW, FL("StartScanRsp with failed status= %d\n"), status);)
>>>>>>> 657b0e9... prima update
               //
               // FIXME - With this, LIM will try and recover state, but
               // eWNI_SME_SCAN_CNF maybe reporting an incorrect
               // status back to the SME
               //
               //Set the resume channel to Any valid channel (invalid). 
               //This will instruct HAL to set it to any previous valid channel.
               peSetResumeChannel(pMac, 0, 0);
               limSendHalFinishScanReq( pMac, eLIM_HAL_FINISH_SCAN_WAIT_STATE );
               //limCompleteMlmScan(pMac, eSIR_SME_HAL_SCAN_INIT_FAILED);
            }
            else
            {
               pMac->lim.gLimHalScanState = eLIM_HAL_SCANNING_STATE;
               limContinuePostChannelScan(pMac);
            }
            break;
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
#if defined(ANI_PRODUCT_TYPE_AP) && (WNI_POLARIS_FW_PACKAGE == ADVANCED)
        case eLIM_HAL_START_LEARN_WAIT_STATE:
 //           if (pMac->lim.gLimSystemRole == eLIM_AP_ROLE)
            {
                if (status != (tANI_U32) eHAL_STATUS_SUCCESS)
                {
                    //Set the resume channel to Any valid channel (invalid). 
                    //This will instruct HAL to set it to any previous valid channel.
                    peSetResumeChannel(pMac, 0, 0);
                    limSendHalFinishScanReq(pMac, eLIM_HAL_FINISH_LEARN_WAIT_STATE);
                }
                else
                {
                    limContinueChannelLearn(pMac);
                }
            }
            break;
#endif
<<<<<<< HEAD
        default:
            limLog(pMac, LOGW, FL("Rcvd StartScanRsp not in WAIT State, state %d\n"),
=======
        default:
            limLog(pMac, LOGW, FL("Rcvd StartScanRsp not in WAIT State, state %d"),
>>>>>>> d97af3b... add prima wlan driver
=======
        default:
            limLog(pMac, LOGW, FL("Rcvd StartScanRsp not in WAIT State, state %d\n"),
>>>>>>> 657b0e9... prima update
                     pMac->lim.gLimHalScanState);
            break;
    }
    return;
}
void limProcessEndScanRsp(tpAniSirGlobal pMac,  void *body)
{
    tpEndScanParams     pEndScanParam;
    eHalStatus          status;
<<<<<<< HEAD
<<<<<<< HEAD
#if defined(ANI_PRODUCT_TYPE_AP) && (WNI_POLARIS_FW_PACKAGE == ADVANCED)
    tANI_U8             channelNum;
#endif
    SET_LIM_PROCESS_DEFD_MESGS(pMac, true);
    pEndScanParam = (tpEndScanParams) body;
    status = pEndScanParam->status;
    palFreeMemory( pMac->hHdd, (char *)body);
=======
    SET_LIM_PROCESS_DEFD_MESGS(pMac, true);
    pEndScanParam = (tpEndScanParams) body;
    status = pEndScanParam->status;
    vos_mem_free(body);
>>>>>>> d97af3b... add prima wlan driver
=======
#if defined(ANI_PRODUCT_TYPE_AP) && (WNI_POLARIS_FW_PACKAGE == ADVANCED)
    tANI_U8             channelNum;
#endif
    SET_LIM_PROCESS_DEFD_MESGS(pMac, true);
    pEndScanParam = (tpEndScanParams) body;
    status = pEndScanParam->status;
    palFreeMemory( pMac->hHdd, (char *)body);
>>>>>>> 657b0e9... prima update
    switch(pMac->lim.gLimHalScanState)
    {
        case eLIM_HAL_END_SCAN_WAIT_STATE:
            if (status != (tANI_U32) eHAL_STATUS_SUCCESS)
            {
<<<<<<< HEAD
<<<<<<< HEAD
               PELOGW(limLog(pMac, LOGW, FL("EndScanRsp with failed status= %d\n"), status);)
=======
               PELOGW(limLog(pMac, LOGW, FL("EndScanRsp with failed status= %d"), status);)
>>>>>>> d97af3b... add prima wlan driver
=======
               PELOGW(limLog(pMac, LOGW, FL("EndScanRsp with failed status= %d\n"), status);)
>>>>>>> 657b0e9... prima update
               pMac->lim.gLimHalScanState = eLIM_HAL_IDLE_SCAN_STATE;
               limCompleteMlmScan(pMac, eSIR_SME_HAL_SCAN_INIT_FAILED);
            }
            else
            {
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
               //Skip Dfs Channel in case of P2P Search
               //If skipDfsChnlInP2pSearch is set in ini
               if( ( pMac->lim.gpLimMlmScanReq != NULL ) &&
                   pMac->lim.gpLimMlmScanReq->p2pSearch &&
                   pMac->lim.gpLimMlmScanReq->skipDfsChnlInP2pSearch )
               {
                  int flag = 0;
                  while(!flag)
                  {
                     pMac->lim.gLimCurrentScanChannelId++;
                     if( (pMac->lim.gLimCurrentScanChannelId >
                   (tANI_U32) (pMac->lim.gpLimMlmScanReq->channelList.numChannels - 1))||
                        (limActiveScanAllowed(pMac, limGetCurrentScanChannel(pMac))))
                     {
                       flag=1; //Bail out from here
                     }
                  }
               }
               else
               {
                  pMac->lim.gLimCurrentScanChannelId++;
               }

<<<<<<< HEAD
               limContinueChannelScan(pMac);
            }
            break;
#if defined(ANI_PRODUCT_TYPE_AP) && (WNI_POLARIS_FW_PACKAGE == ADVANCED)
        case eLIM_HAL_END_LEARN_WAIT_STATE:
            if (status != (tANI_U32) eHAL_STATUS_SUCCESS)
            {
                //Set the resume channel to Any valid channel (invalid). 
                //This will instruct HAL to set it to any previous valid channel.
                peSetResumeChannel(pMac, 0, 0);
                limSendHalFinishScanReq(pMac, eLIM_HAL_FINISH_LEARN_WAIT_STATE);
            }
#if 0 /* Will we be in UNKNOWN ROLE ever in this context: Veerendra */
            else if (pMac->lim.gLimSystemRole == eLIM_UNKNOWN_ROLE)
            {
               /** Before starting BSS, we do complete set of measurement before putting
                *   softmac back into normal mode.
                */
               channelNum = limGetCurrentLearnChannel(pMac);
               limSendHalStartScanReq(pMac, channelNum, eLIM_HAL_START_LEARN_WAIT_STATE);
            }
            else
#endif
            {
               limLog(pMac, LOGW, FL("ERROR! This state is set only when AP in UNKNOWN_ROLE\n"),
                        pMac->lim.gLimHalScanState);
                limSendHalFinishScanReq(pMac, eLIM_HAL_FINISH_LEARN_WAIT_STATE);
            }
            break;
#endif
        default:
            limLog(pMac, LOGW, FL("Rcvd endScanRsp not in WAIT State, state %d\n"),
=======
               pMac->lim.gLimCurrentScanChannelId++;
=======
>>>>>>> 657b0e9... prima update
               limContinueChannelScan(pMac);
            }
            break;
#if defined(ANI_PRODUCT_TYPE_AP) && (WNI_POLARIS_FW_PACKAGE == ADVANCED)
        case eLIM_HAL_END_LEARN_WAIT_STATE:
            if (status != (tANI_U32) eHAL_STATUS_SUCCESS)
            {
                //Set the resume channel to Any valid channel (invalid). 
                //This will instruct HAL to set it to any previous valid channel.
                peSetResumeChannel(pMac, 0, 0);
                limSendHalFinishScanReq(pMac, eLIM_HAL_FINISH_LEARN_WAIT_STATE);
            }
#if 0 /* Will we be in UNKNOWN ROLE ever in this context: Veerendra */
            else if (pMac->lim.gLimSystemRole == eLIM_UNKNOWN_ROLE)
            {
               /** Before starting BSS, we do complete set of measurement before putting
                *   softmac back into normal mode.
                */
               channelNum = limGetCurrentLearnChannel(pMac);
               limSendHalStartScanReq(pMac, channelNum, eLIM_HAL_START_LEARN_WAIT_STATE);
            }
            else
#endif
            {
               limLog(pMac, LOGW, FL("ERROR! This state is set only when AP in UNKNOWN_ROLE\n"),
                        pMac->lim.gLimHalScanState);
                limSendHalFinishScanReq(pMac, eLIM_HAL_FINISH_LEARN_WAIT_STATE);
            }
            break;
#endif
        default:
<<<<<<< HEAD
            limLog(pMac, LOGW, FL("Rcvd endScanRsp not in WAIT State, state %d"),
>>>>>>> d97af3b... add prima wlan driver
=======
            limLog(pMac, LOGW, FL("Rcvd endScanRsp not in WAIT State, state %d\n"),
>>>>>>> 657b0e9... prima update
                        pMac->lim.gLimHalScanState);
            break;
    }
    return;
}
/**
 *  limStopTxAndSwitch()
 *
 *FUNCTION:
 * Start channel switch on all sessions that is in channel switch state.
 *
 * @param pMac                   - pointer to global adapter context
 *
 * @return None
 *
 */
static void
limStopTxAndSwitch (tpAniSirGlobal pMac)
{
    tANI_U8 i;

    for(i =0; i < pMac->lim.maxBssId; i++)
    {
        if(pMac->lim.gpSession[i].valid && 
            pMac->lim.gpSession[i].gLimSpecMgmt.dot11hChanSwState == eLIM_11H_CHANSW_RUNNING)
        {
            limStopTxAndSwitchChannel(pMac, i);
        }
    }
    return; 
}
/**
 * limStartQuietOnSession()
 *
 *FUNCTION:
 * This function is called to start quiet timer after finish scan if there is  
 *      qeuieting on any session.
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 * NA
 *
 *NOTE:
 * NA
 *
 * @param  pMac    - Pointer to Global MAC structure
 *
 * @return None
 */
static void
limStartQuietOnSession (tpAniSirGlobal pMac)
{
    tANI_U8 i;

    for(i =0; i < pMac->lim.maxBssId; i++)
    {
        if(pMac->lim.gpSession[i].valid && 
            pMac->lim.gpSession[i].gLimSpecMgmt.quietState == eLIM_QUIET_BEGIN)
        {
            limStartQuietTimer(pMac, i);
        }
    }
    return;
}
void limProcessFinishScanRsp(tpAniSirGlobal pMac,  void *body)
{
    tpFinishScanParams      pFinishScanParam;
    eHalStatus              status;
    SET_LIM_PROCESS_DEFD_MESGS(pMac, true);
    pFinishScanParam = (tpFinishScanParams) body;
    status = pFinishScanParam->status;
<<<<<<< HEAD
<<<<<<< HEAD
    palFreeMemory( pMac->hHdd, (char *)body);
=======
    vos_mem_free(body);
>>>>>>> d97af3b... add prima wlan driver
=======
    palFreeMemory( pMac->hHdd, (char *)body);
>>>>>>> 657b0e9... prima update
    switch(pMac->lim.gLimHalScanState)
    {
        case eLIM_HAL_FINISH_SCAN_WAIT_STATE:
            pMac->lim.gLimHalScanState = eLIM_HAL_IDLE_SCAN_STATE;
            limCompleteMlmScan(pMac, eSIR_SME_SUCCESS);
            if (limIsChanSwitchRunning(pMac))
            {
                /** Right time to stop tx and start the timer for channel switch */
                /* Sending Session ID 0, may not be correct, since SCAN is global there should not
                 * be any associated session id
                */
                limStopTxAndSwitch(pMac);
            }
            else if (limIsQuietBegin(pMac))
            {
                /** Start the quieting */
                /* Sending Session ID 0, may not be correct, since SCAN is global there should not
                 * be any associated session id
                */
                limStartQuietOnSession(pMac);
            }
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
#ifdef ANI_PRODUCT_TYPE_AP
            /* For handling the measurement request from WSM as scan request in LIM*/
#if 0
            if (pMac->lim.gLimSystemRole == eLIM_STA_ROLE && pMac->lim.gpLimMeasReq != NULL)
            {
                limSendSmeMeasurementInd(pMac);
                limCleanupMeasResources(pMac);
                limRestorePreLearnState(pMac);
            }
#endif
#endif
<<<<<<< HEAD
            if (status != (tANI_U32) eHAL_STATUS_SUCCESS)
            {
               PELOGW(limLog(pMac, LOGW, FL("EndScanRsp with failed status= %d\n"), status);)
            }
            break;
#if (defined(ANI_PRODUCT_TYPE_AP) || defined(ANI_PRODUCT_TYPE_AP_SDK))
        case eLIM_HAL_FINISH_LEARN_WAIT_STATE:
            pMac->lim.gLimHalScanState = eLIM_HAL_IDLE_SCAN_STATE;
            __limProcessFinishLearnRsp(pMac);
            break;
#endif //#if (defined(ANI_PRODUCT_TYPE_AP) || defined(ANI_PRODUCT_TYPE_AP_SDK))
=======
=======
>>>>>>> 657b0e9... prima update
            if (status != (tANI_U32) eHAL_STATUS_SUCCESS)
            {
               PELOGW(limLog(pMac, LOGW, FL("EndScanRsp with failed status= %d\n"), status);)
            }
            break;
<<<<<<< HEAD
>>>>>>> d97af3b... add prima wlan driver
=======
#if (defined(ANI_PRODUCT_TYPE_AP) || defined(ANI_PRODUCT_TYPE_AP_SDK))
        case eLIM_HAL_FINISH_LEARN_WAIT_STATE:
            pMac->lim.gLimHalScanState = eLIM_HAL_IDLE_SCAN_STATE;
            __limProcessFinishLearnRsp(pMac);
            break;
#endif //#if (defined(ANI_PRODUCT_TYPE_AP) || defined(ANI_PRODUCT_TYPE_AP_SDK))
>>>>>>> 657b0e9... prima update
//WLAN_SUSPEND_LINK Related
        case eLIM_HAL_RESUME_LINK_WAIT_STATE:
            if( pMac->lim.gpLimResumeCallback )
            {
               pMac->lim.gLimHalScanState = eLIM_HAL_IDLE_SCAN_STATE;
               pMac->lim.gpLimResumeCallback( pMac, status, pMac->lim.gpLimResumeData );
               pMac->lim.gpLimResumeCallback = NULL;
               pMac->lim.gpLimResumeData = NULL;
               pMac->lim.gLimSystemInScanLearnMode = 0;
            }
            else
            {
<<<<<<< HEAD
<<<<<<< HEAD
               limLog( pMac, LOGP, "No Resume link callback set but station is in suspend state\n");
=======
               limLog( pMac, LOGP, "No Resume link callback set but station is in suspend state");
>>>>>>> d97af3b... add prima wlan driver
=======
               limLog( pMac, LOGP, "No Resume link callback set but station is in suspend state\n");
>>>>>>> 657b0e9... prima update
               return;
            }
            break;
//end WLAN_SUSPEND_LINK Related

        default:
<<<<<<< HEAD
<<<<<<< HEAD
            limLog(pMac, LOGW, FL("Rcvd FinishScanRsp not in WAIT State, state %d\n"),
=======
            limLog(pMac, LOGW, FL("Rcvd FinishScanRsp not in WAIT State, state %d"),
>>>>>>> d97af3b... add prima wlan driver
=======
            limLog(pMac, LOGW, FL("Rcvd FinishScanRsp not in WAIT State, state %d\n"),
>>>>>>> 657b0e9... prima update
                        pMac->lim.gLimHalScanState);
            break;
    }
    return;
}
/**
 * @function : limProcessMlmHalAddBARsp
 *
 * @brief:     Process WDA_ADDBA_RSP coming from HAL
 *
 *
 * @param pMac The global tpAniSirGlobal object
 *
 * @param tSirMsgQ The MsgQ header containing the response buffer
 *
 * @return none
 */
void limProcessMlmHalAddBARsp( tpAniSirGlobal pMac,
    tpSirMsgQ limMsgQ )
{
    // Send LIM_MLM_ADDBA_CNF to LIM
    tpLimMlmAddBACnf pMlmAddBACnf;
<<<<<<< HEAD
<<<<<<< HEAD
    tpPESession     psessionEntry;
    tpAddBAParams pAddBAParams = (tpAddBAParams) limMsgQ->bodyptr;
#ifdef FEATURE_WLAN_DIAG_SUPPORT_LIM //FEATURE_WLAN_DIAG_SUPPORT
    limDiagEventReport(pMac, WLAN_PE_DIAG_HAL_ADDBA_RSP_EVENT, psessionEntry, 0, 0);
#endif //FEATURE_WLAN_DIAG_SUPPORT
    //now LIM can process any defer message.
    SET_LIM_PROCESS_DEFD_MESGS(pMac, true);
    if (pAddBAParams == NULL) {
        PELOGE(limLog(pMac, LOGE,FL("NULL ADD BA Response from HAL\n"));)
=======
    tpPESession     psessionEntry = NULL;
=======
    tpPESession     psessionEntry;
>>>>>>> 657b0e9... prima update
    tpAddBAParams pAddBAParams = (tpAddBAParams) limMsgQ->bodyptr;
#ifdef FEATURE_WLAN_DIAG_SUPPORT_LIM //FEATURE_WLAN_DIAG_SUPPORT
    limDiagEventReport(pMac, WLAN_PE_DIAG_HAL_ADDBA_RSP_EVENT, psessionEntry, 0, 0);
#endif //FEATURE_WLAN_DIAG_SUPPORT
    //now LIM can process any defer message.
    SET_LIM_PROCESS_DEFD_MESGS(pMac, true);
    if (pAddBAParams == NULL) {
<<<<<<< HEAD
        PELOGE(limLog(pMac, LOGE,FL("NULL ADD BA Response from HAL"));)
>>>>>>> d97af3b... add prima wlan driver
=======
        PELOGE(limLog(pMac, LOGE,FL("NULL ADD BA Response from HAL\n"));)
>>>>>>> 657b0e9... prima update
        return;
    }
    if((psessionEntry = peFindSessionBySessionId(pMac, pAddBAParams->sessionId))==NULL)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        PELOGE(limLog(pMac, LOGE,FL("session does not exist for given sessionID: %d\n"),pAddBAParams->sessionId );)
        palFreeMemory(pMac->hHdd, (void*)limMsgQ->bodyptr);
=======
        PELOGE(limLog(pMac, LOGE,FL("session does not exist for given sessionID: %d"),pAddBAParams->sessionId );)
        vos_mem_free(limMsgQ->bodyptr);
>>>>>>> d97af3b... add prima wlan driver
=======
        PELOGE(limLog(pMac, LOGE,FL("session does not exist for given sessionID: %d\n"),pAddBAParams->sessionId );)
        palFreeMemory(pMac->hHdd, (void*)limMsgQ->bodyptr);
>>>>>>> 657b0e9... prima update
        return;
    }
#ifdef FEATURE_WLAN_DIAG_SUPPORT_LIM //FEATURE_WLAN_DIAG_SUPPORT 
    limDiagEventReport(pMac, WLAN_PE_DIAG_HAL_ADDBA_RSP_EVENT, psessionEntry, 0, 0);
#endif //FEATURE_WLAN_DIAG_SUPPORT

    // Allocate for LIM_MLM_ADDBA_CNF
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
    if( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd,
          (void **) &pMlmAddBACnf, sizeof( tLimMlmAddBACnf ))) {
        limLog( pMac, LOGP, FL(" palAllocateMemory failed with error code %d\n"));
        palFreeMemory(pMac->hHdd, (void*)limMsgQ->bodyptr);
<<<<<<< HEAD
        return;
    }
    palZeroMemory( pMac->hHdd, (void *) pMlmAddBACnf, sizeof( tLimMlmAddBACnf ));
     // Copy the peer MAC
     palCopyMemory( pMac->hHdd, pMlmAddBACnf->peerMacAddr, pAddBAParams->peerMacAddr,
                                                                                 sizeof( tSirMacAddr ));
=======
    pMlmAddBACnf = vos_mem_malloc(sizeof(tLimMlmAddBACnf));
    if ( NULL == pMlmAddBACnf ) {
        limLog( pMac, LOGP, FL(" AllocateMemory failed with error code %d"));
        vos_mem_free(limMsgQ->bodyptr);
=======
>>>>>>> 657b0e9... prima update
        return;
    }
    palZeroMemory( pMac->hHdd, (void *) pMlmAddBACnf, sizeof( tLimMlmAddBACnf ));
     // Copy the peer MAC
<<<<<<< HEAD
     vos_mem_copy(pMlmAddBACnf->peerMacAddr, pAddBAParams->peerMacAddr,
                  sizeof( tSirMacAddr ));
>>>>>>> d97af3b... add prima wlan driver
=======
     palCopyMemory( pMac->hHdd, pMlmAddBACnf->peerMacAddr, pAddBAParams->peerMacAddr,
                                                                                 sizeof( tSirMacAddr ));
>>>>>>> 657b0e9... prima update
     // Copy other ADDBA Rsp parameters
     pMlmAddBACnf->baDialogToken = pAddBAParams->baDialogToken;
     pMlmAddBACnf->baTID = pAddBAParams->baTID;
     pMlmAddBACnf->baPolicy = pAddBAParams->baPolicy;
     pMlmAddBACnf->baBufferSize = pAddBAParams->baBufferSize;
     pMlmAddBACnf->baTimeout = pAddBAParams->baTimeout;
     pMlmAddBACnf->baDirection = pAddBAParams->baDirection;
     pMlmAddBACnf->sessionId = psessionEntry->peSessionId;
     if(eHAL_STATUS_SUCCESS == pAddBAParams->status)
        pMlmAddBACnf->addBAResultCode = eSIR_MAC_SUCCESS_STATUS;
     else
        pMlmAddBACnf->addBAResultCode = eSIR_MAC_UNSPEC_FAILURE_STATUS;
<<<<<<< HEAD
<<<<<<< HEAD
     palFreeMemory(pMac->hHdd, (void*)limMsgQ->bodyptr);
=======
     vos_mem_free(limMsgQ->bodyptr);
>>>>>>> d97af3b... add prima wlan driver
=======
     palFreeMemory(pMac->hHdd, (void*)limMsgQ->bodyptr);
>>>>>>> 657b0e9... prima update
     // Send ADDBA CNF to LIM
     limPostSmeMessage( pMac, LIM_MLM_ADDBA_CNF, (tANI_U32 *) pMlmAddBACnf );
}
/**
 * \brief Process LIM_MLM_ADDBA_CNF
 *
 * \sa limProcessMlmAddBACnf
 *
 * \param pMac The global tpAniSirGlobal object
 *
 * \param tSirMsgQ The MsgQ header containing the response buffer
 *
 * \return none
 */
void limProcessMlmAddBACnf( tpAniSirGlobal pMac,
    tANI_U32 *pMsgBuf )
{
tpLimMlmAddBACnf pMlmAddBACnf;
tpDphHashNode pSta;
tANI_U16 aid;
tLimBAState curBaState;
tpPESession psessionEntry = NULL;
if(pMsgBuf == NULL)
{
<<<<<<< HEAD
<<<<<<< HEAD
    PELOGE(limLog(pMac, LOGE,FL("Buffer is Pointing to NULL\n"));)
=======
    PELOGE(limLog(pMac, LOGE,FL("Buffer is Pointing to NULL"));)
>>>>>>> d97af3b... add prima wlan driver
=======
    PELOGE(limLog(pMac, LOGE,FL("Buffer is Pointing to NULL\n"));)
>>>>>>> 657b0e9... prima update
    return;
}
pMlmAddBACnf = (tpLimMlmAddBACnf) pMsgBuf;
  if((psessionEntry = peFindSessionBySessionId(pMac,pMlmAddBACnf->sessionId))== NULL)
  {
<<<<<<< HEAD
<<<<<<< HEAD
        PELOGE(limLog(pMac, LOGE,FL("session does not exist for given BSSId\n"));)
        palFreeMemory( pMac->hHdd, (void *) pMsgBuf );
=======
        PELOGE(limLog(pMac, LOGE,FL("session does not exist for given BSSId"));)
        vos_mem_free(pMsgBuf);
>>>>>>> d97af3b... add prima wlan driver
=======
        PELOGE(limLog(pMac, LOGE,FL("session does not exist for given BSSId\n"));)
        palFreeMemory( pMac->hHdd, (void *) pMsgBuf );
>>>>>>> 657b0e9... prima update
        return;
  }
  // First, extract the DPH entry
  pSta = dphLookupHashEntry( pMac, pMlmAddBACnf->peerMacAddr, &aid, &psessionEntry->dph.dphHashTable);
  if( NULL == pSta )
  {
    PELOGE(limLog( pMac, LOGE,
<<<<<<< HEAD
<<<<<<< HEAD
        FL( "STA context not found - ignoring ADDBA CNF from HAL\n" ));)
    palFreeMemory( pMac->hHdd, (void *) pMsgBuf );
=======
        FL( "STA context not found - ignoring ADDBA CNF from HAL" ));)
    vos_mem_free(pMsgBuf);
>>>>>>> d97af3b... add prima wlan driver
=======
        FL( "STA context not found - ignoring ADDBA CNF from HAL\n" ));)
    palFreeMemory( pMac->hHdd, (void *) pMsgBuf );
>>>>>>> 657b0e9... prima update
    return;
  }
  LIM_GET_STA_BA_STATE(pSta, pMlmAddBACnf->baTID, &curBaState);
  // Need to validate SME state
  if( eLIM_BA_STATE_WT_ADD_RSP != curBaState)
  {
    PELOGE(limLog( pMac, LOGE,
<<<<<<< HEAD
<<<<<<< HEAD
        FL( "Received unexpected ADDBA CNF when STA BA state is %d\n" ),
        curBaState );)
      palFreeMemory( pMac->hHdd, (void *) pMsgBuf );
=======
        FL( "Received unexpected ADDBA CNF when STA BA state is %d" ),
        curBaState );)
      vos_mem_free(pMsgBuf);
>>>>>>> d97af3b... add prima wlan driver
=======
        FL( "Received unexpected ADDBA CNF when STA BA state is %d\n" ),
        curBaState );)
      palFreeMemory( pMac->hHdd, (void *) pMsgBuf );
>>>>>>> 657b0e9... prima update
    return;
  }
  // Restore STA BA state
  LIM_SET_STA_BA_STATE(pSta, pMlmAddBACnf->baTID, eLIM_BA_STATE_IDLE);
  if( eSIR_MAC_SUCCESS_STATUS == pMlmAddBACnf->addBAResultCode )
  {
    // Update LIM internal cache...
    if( eBA_RECIPIENT == pMlmAddBACnf->baDirection )
    {
      pSta->tcCfg[pMlmAddBACnf->baTID].fUseBARx = 1;
      pSta->tcCfg[pMlmAddBACnf->baTID].fRxCompBA = 1;
      pSta->tcCfg[pMlmAddBACnf->baTID].fRxBApolicy = pMlmAddBACnf->baPolicy;
      pSta->tcCfg[pMlmAddBACnf->baTID].rxBufSize = pMlmAddBACnf->baBufferSize;
      pSta->tcCfg[pMlmAddBACnf->baTID].tuRxBAWaitTimeout = pMlmAddBACnf->baTimeout;
<<<<<<< HEAD
<<<<<<< HEAD
=======
      // Package LIM_MLM_ADDBA_RSP to MLME, with proper
      // status code. MLME will then send an ADDBA RSP
      // over the air to the peer MAC entity
      if( eSIR_SUCCESS != limPostMlmAddBARsp( pMac,
            pMlmAddBACnf->peerMacAddr,
            pMlmAddBACnf->addBAResultCode,
            pMlmAddBACnf->baDialogToken,
            (tANI_U8) pMlmAddBACnf->baTID,
            (tANI_U8) pMlmAddBACnf->baPolicy,
            pMlmAddBACnf->baBufferSize,
            pMlmAddBACnf->baTimeout,psessionEntry))
      {
        PELOGW(limLog( pMac, LOGW,
            FL( "Failed to post LIM_MLM_ADDBA_RSP to " ));
        limPrintMacAddr( pMac, pMlmAddBACnf->peerMacAddr, LOGW );)
      }
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
    }
    else
    {
      pSta->tcCfg[pMlmAddBACnf->baTID].fUseBATx = 1;
      pSta->tcCfg[pMlmAddBACnf->baTID].fTxCompBA = 1;
      pSta->tcCfg[pMlmAddBACnf->baTID].fTxBApolicy = pMlmAddBACnf->baPolicy;
      pSta->tcCfg[pMlmAddBACnf->baTID].txBufSize = pMlmAddBACnf->baBufferSize;
      pSta->tcCfg[pMlmAddBACnf->baTID].tuTxBAWaitTimeout = pMlmAddBACnf->baTimeout;
    }
  }
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
  if( eBA_RECIPIENT == pMlmAddBACnf->baDirection )
  {
    //
    // Package LIM_MLM_ADDBA_RSP to MLME, with proper
    // status code. MLME will then send an ADDBA RSP
    // over the air to the peer MAC entity
    //
    if( eSIR_SUCCESS != limPostMlmAddBARsp( pMac,
          pMlmAddBACnf->peerMacAddr,
          pMlmAddBACnf->addBAResultCode,
          pMlmAddBACnf->baDialogToken,
          (tANI_U8) pMlmAddBACnf->baTID,
          (tANI_U8) pMlmAddBACnf->baPolicy,
          pMlmAddBACnf->baBufferSize,
          pMlmAddBACnf->baTimeout,psessionEntry))
    {
      PELOGW(limLog( pMac, LOGW,
          FL( "Failed to post LIM_MLM_ADDBA_RSP to " ));
      limPrintMacAddr( pMac, pMlmAddBACnf->peerMacAddr, LOGW );)
    }
  }
<<<<<<< HEAD
  // Free the memory allocated for LIM_MLM_ADDBA_CNF
  palFreeMemory( pMac->hHdd, (void *) pMsgBuf );
=======
  // Free the memory allocated for LIM_MLM_ADDBA_CNF
  vos_mem_free(pMsgBuf);
>>>>>>> d97af3b... add prima wlan driver
=======
  // Free the memory allocated for LIM_MLM_ADDBA_CNF
  palFreeMemory( pMac->hHdd, (void *) pMsgBuf );
>>>>>>> 657b0e9... prima update
}
/**
 * \brief Process LIM_MLM_DELBA_CNF
 *
 * \sa limProcessMlmDelBACnf
 *
 * \param pMac The global tpAniSirGlobal object
 *
 * \param tSirMsgQ The MsgQ header containing the response buffer
 *
 * \return none
 */
void limProcessMlmDelBACnf( tpAniSirGlobal pMac,
    tANI_U32 *pMsgBuf )
{
    tpLimMlmDelBACnf    pMlmDelBACnf;
    tpDphHashNode       pSta;
    tANI_U16            aid;
//    tANI_U8             sessionId;
    tLimBAState         curBaState;
    tpPESession         psessionEntry;

    if(pMsgBuf == NULL)
    {
<<<<<<< HEAD
<<<<<<< HEAD
         PELOGE(limLog(pMac, LOGE,FL("Buffer is Pointing to NULL\n"));)
=======
         PELOGE(limLog(pMac, LOGE,FL("Buffer is Pointing to NULL"));)
>>>>>>> d97af3b... add prima wlan driver
=======
         PELOGE(limLog(pMac, LOGE,FL("Buffer is Pointing to NULL\n"));)
>>>>>>> 657b0e9... prima update
         return;
    }
    pMlmDelBACnf = (tpLimMlmDelBACnf) pMsgBuf;
    if((psessionEntry = peFindSessionBySessionId(pMac, pMlmDelBACnf->sessionId))== NULL)
   {
<<<<<<< HEAD
<<<<<<< HEAD
        limLog(pMac, LOGP,FL("Session Does not exist for given sessionID\n"));
        palFreeMemory( pMac->hHdd, (void *) pMsgBuf );
=======
        limLog(pMac, LOGP,FL("Session Does not exist for given sessionID"));
        vos_mem_free(pMsgBuf);
>>>>>>> d97af3b... add prima wlan driver
=======
        limLog(pMac, LOGP,FL("Session Does not exist for given sessionID\n"));
        palFreeMemory( pMac->hHdd, (void *) pMsgBuf );
>>>>>>> 657b0e9... prima update
        return;
   }
    // First, extract the DPH entry
    pSta = dphLookupHashEntry( pMac, pMlmDelBACnf->peerMacAddr, &aid, &psessionEntry->dph.dphHashTable );
    if( NULL == pSta )
    {
        limLog( pMac, LOGE,
<<<<<<< HEAD
<<<<<<< HEAD
            FL( "STA context not found - ignoring DELBA CNF from HAL\n" ));
        palFreeMemory( pMac->hHdd, (void *) pMsgBuf );
=======
            FL( "STA context not found - ignoring DELBA CNF from HAL" ));
        vos_mem_free(pMsgBuf);
>>>>>>> d97af3b... add prima wlan driver
=======
            FL( "STA context not found - ignoring DELBA CNF from HAL\n" ));
        palFreeMemory( pMac->hHdd, (void *) pMsgBuf );
>>>>>>> 657b0e9... prima update
        return;
    }
    if(NULL == pMlmDelBACnf)
    {
        limLog( pMac, LOGE,
<<<<<<< HEAD
<<<<<<< HEAD
        FL( "pMlmDelBACnf is NULL - ignoring DELBA CNF from HAL\n" ));
=======
        FL( "pMlmDelBACnf is NULL - ignoring DELBA CNF from HAL" ));
>>>>>>> d97af3b... add prima wlan driver
=======
        FL( "pMlmDelBACnf is NULL - ignoring DELBA CNF from HAL\n" ));
>>>>>>> 657b0e9... prima update
        return;
    }
    // Need to validate baState
    LIM_GET_STA_BA_STATE(pSta, pMlmDelBACnf->baTID, &curBaState);
    if( eLIM_BA_STATE_WT_DEL_RSP != curBaState )
    {
        limLog( pMac, LOGE,
<<<<<<< HEAD
<<<<<<< HEAD
        FL( "Received unexpected DELBA CNF when STA BA state is %d\n" ),
        curBaState );
        palFreeMemory( pMac->hHdd, (void *) pMsgBuf );
=======
        FL( "Received unexpected DELBA CNF when STA BA state is %d" ),
        curBaState );
        vos_mem_free(pMsgBuf);
>>>>>>> d97af3b... add prima wlan driver
=======
        FL( "Received unexpected DELBA CNF when STA BA state is %d\n" ),
        curBaState );
        palFreeMemory( pMac->hHdd, (void *) pMsgBuf );
>>>>>>> 657b0e9... prima update
        return;
    }
    // Restore STA BA state
    LIM_SET_STA_BA_STATE(pSta, pMlmDelBACnf->baTID, eLIM_BA_STATE_IDLE);
    // Free the memory allocated for LIM_MLM_DELBA_CNF
<<<<<<< HEAD
<<<<<<< HEAD
    palFreeMemory( pMac->hHdd, (void *) pMsgBuf );
=======
    vos_mem_free(pMsgBuf);
>>>>>>> d97af3b... add prima wlan driver
=======
    palFreeMemory( pMac->hHdd, (void *) pMsgBuf );
>>>>>>> 657b0e9... prima update
}
/**
 * \brief Process SIR_LIM_DEL_BA_IND
 *
 * \sa limProcessMlmHalBADeleteInd
 *
 * \param pMac The global tpAniSirGlobal object
 *
 * \param tSirMsgQ The MsgQ header containing the indication buffer
 *
 * \return none
 */
void limProcessMlmHalBADeleteInd( tpAniSirGlobal pMac,
    tpSirMsgQ limMsgQ )
{
    tSirRetStatus       status = eSIR_SUCCESS;
    tpBADeleteParams    pBADeleteParams;
    tpDphHashNode       pSta;
    tANI_U16            aid;
    tLimBAState         curBaState;
    tpPESession         psessionEntry;
    tANI_U8             sessionId;

  pBADeleteParams = (tpBADeleteParams) limMsgQ->bodyptr;

    if((psessionEntry = peFindSessionByBssid(pMac,pBADeleteParams->bssId,&sessionId))== NULL)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        PELOGE(limLog(pMac, LOGE,FL("session does not exist for given BSSId\n"));)
        palFreeMemory( pMac->hHdd, (void *) limMsgQ->bodyptr );
=======
        PELOGE(limLog(pMac, LOGE,FL("session does not exist for given BSSId"));)
        vos_mem_free(limMsgQ->bodyptr);
>>>>>>> d97af3b... add prima wlan driver
=======
        PELOGE(limLog(pMac, LOGE,FL("session does not exist for given BSSId\n"));)
        palFreeMemory( pMac->hHdd, (void *) limMsgQ->bodyptr );
>>>>>>> 657b0e9... prima update
        return;
    }
    // First, extract the DPH entry
    pSta = dphLookupHashEntry( pMac, pBADeleteParams->peerMacAddr, &aid, &psessionEntry->dph.dphHashTable );
    if( NULL == pSta )
    {
        limLog( pMac, LOGE,
<<<<<<< HEAD
<<<<<<< HEAD
        FL( "STA context not found - ignoring BA Delete IND from HAL\n" ));
=======
        FL( "STA context not found - ignoring BA Delete IND from HAL" ));
>>>>>>> d97af3b... add prima wlan driver
=======
        FL( "STA context not found - ignoring BA Delete IND from HAL\n" ));
>>>>>>> 657b0e9... prima update
        goto returnAfterCleanup;
    }

  // Need to validate BA state
  LIM_GET_STA_BA_STATE(pSta, pBADeleteParams->baTID, &curBaState);
  if( eLIM_BA_STATE_IDLE != curBaState )
  {
    limLog( pMac, LOGE,
<<<<<<< HEAD
<<<<<<< HEAD
        FL( "Received unexpected BA Delete IND when STA BA state is %d\n" ),
=======
        FL( "Received unexpected BA Delete IND when STA BA state is %d" ),
>>>>>>> d97af3b... add prima wlan driver
=======
        FL( "Received unexpected BA Delete IND when STA BA state is %d\n" ),
>>>>>>> 657b0e9... prima update
        curBaState );
        goto returnAfterCleanup;
    }

  // Validate if a BA is active for the requested TID
  // AND in that desired direction
  if( eBA_INITIATOR == pBADeleteParams->baDirection )
  {
    if( 0 == pSta->tcCfg[pBADeleteParams->baTID].fUseBATx )
      status = eSIR_FAILURE;
  }
  else
  {
    if( 0 == pSta->tcCfg[pBADeleteParams->baTID].fUseBARx )
      status = eSIR_FAILURE;
  }
    if( eSIR_FAILURE == status )
    {
        limLog( pMac, LOGW,
<<<<<<< HEAD
<<<<<<< HEAD
        FL("Received an INVALID DELBA Delete Ind for TID %d...\n"),
=======
        FL("Received an INVALID DELBA Delete Ind for TID %d..."),
>>>>>>> d97af3b... add prima wlan driver
=======
        FL("Received an INVALID DELBA Delete Ind for TID %d...\n"),
>>>>>>> 657b0e9... prima update
        pBADeleteParams->baTID );
    }
    else
    {
        // Post DELBA REQ to MLME...
        if( eSIR_SUCCESS !=
        (status = limPostMlmDelBAReq( pMac,
                                      pSta,
                                      pBADeleteParams->baDirection,
                                      pBADeleteParams->baTID,
                                      eSIR_MAC_UNSPEC_FAILURE_REASON,psessionEntry )))
        {
            limLog( pMac, LOGE,
<<<<<<< HEAD
<<<<<<< HEAD
            FL( "Attempt to post LIM_MLM_DELBA_REQ failed with status %d\n" ), status);
=======
            FL( "Attempt to post LIM_MLM_DELBA_REQ failed with status %d" ), status);
>>>>>>> d97af3b... add prima wlan driver
=======
            FL( "Attempt to post LIM_MLM_DELBA_REQ failed with status %d\n" ), status);
>>>>>>> 657b0e9... prima update
    }
    else
    {
      limLog( pMac, LOGE,
          FL( "BA Delete - Reason 0x%08x. Attempting to delete BA session for TID %d with peer STA "  ),
          pBADeleteParams->reasonCode, pBADeleteParams->baTID );
            limPrintMacAddr( pMac, pSta->staAddr, LOGE );
        }
  }
returnAfterCleanup:
  // Free the memory allocated for SIR_LIM_DEL_BA_IND
<<<<<<< HEAD
<<<<<<< HEAD
  palFreeMemory( pMac->hHdd, (void *) limMsgQ->bodyptr );
=======
  vos_mem_free(limMsgQ->bodyptr);
>>>>>>> d97af3b... add prima wlan driver
=======
  palFreeMemory( pMac->hHdd, (void *) limMsgQ->bodyptr );
>>>>>>> 657b0e9... prima update
}
/**
 *  @function : limProcessSetMimoRsp()
 *
 *  @brief :  This function is called upon receiving the WDA_SET_MIMOPS_RSP from the HAL
 *                      after Processing the Req from the SME (PMC)
 *
 *      LOGIC:
 *
 *      ASSUMPTIONS:
 *          NA
 *
 *      NOTE:
 *          NA
 *
 * @param  pMac - Pointer to Global MAC structure
 * @param  limMsg - Lim Message structure object with the MimoPSparam in body
 * @return None
 */

void
limProcessSetMimoRsp(tpAniSirGlobal pMac, tpSirMsgQ limMsg)
{
#if 0
    tSirRetStatus           retStatus;
    tpSetMIMOPS          pMIMO_PSParams;


    do {

        pMIMO_PSParams = (tpSetMIMOPS)limMsg->bodyptr;
        if( NULL == pMIMO_PSParams ) {
            PELOGE(limLog(pMac, LOGE, "Received the WDA_SET_MIMOPS_RSP with NULL as the PS param");)
            return;
        }

        /** If Updation of the HAL Fail's*/
        if (pMIMO_PSParams->status != eSIR_SUCCESS) {
<<<<<<< HEAD
<<<<<<< HEAD
            limLog(pMac, LOGP, FL("Update HAL / SW Mac for MIMO State has Failed\n"));
=======
            limLog(pMac, LOGP, FL("Update HAL / SW Mac for MIMO State has Failed"));
>>>>>>> d97af3b... add prima wlan driver
=======
            limLog(pMac, LOGP, FL("Update HAL / SW Mac for MIMO State has Failed\n"));
>>>>>>> 657b0e9... prima update
            break;
        }

        if ((pMac->lim.gLimSystemRole != eSYSTEM_STA_ROLE) ||
                (pMac->lim.gLimSmeState != eLIM_SME_LINK_EST_STATE) )
            break;

        pMac->lim.gLimMlmState = pMac->lim.gLimPrevMlmState;
        MTRACE(macTrace(pMac, TRACE_CODE_MLM_STATE, 0, pMac->lim.gLimMlmState));

        /** In the Case of Exiting out of the Powersave (changing from Dynamic/Static mode to SM Enabled)
          *   send the action Frame to Peer to update the PS State of the STA , for the case of Entering PowerSave
          *   the Action Frame is being sent at first before setting the internal structures
          */
        if (!isEnteringMimoPS(pMac->lim.gHTMIMOPSState, pMIMO_PSParams->htMIMOPSState)) {
            tSirMacAddr            macAddr;

            /** Obtain the AP's Mac Address */
<<<<<<< HEAD
<<<<<<< HEAD
            palCopyMemory(pMac -> hHdd, (tANI_U8 *)macAddr, pMac->lim.gLimBssid, sizeof(tSirMacAddr));
=======
            vos_mem_copy((tANI_U8 *)macAddr, pMac->lim.gLimBssid, sizeof(tSirMacAddr));
>>>>>>> d97af3b... add prima wlan driver
=======
            palCopyMemory(pMac -> hHdd, (tANI_U8 *)macAddr, pMac->lim.gLimBssid, sizeof(tSirMacAddr));
>>>>>>> 657b0e9... prima update

            /** Send Action Frame with the corresponding mode */
            retStatus = limSendSMPowerStateFrame(pMac, macAddr, pMIMO_PSParams->htMIMOPSState);
            if (retStatus != eSIR_SUCCESS) {
<<<<<<< HEAD
<<<<<<< HEAD
                PELOGE(limLog(pMac, LOGE, FL("Sending Action Frame has failed\n"));)
=======
                PELOGE(limLog(pMac, LOGE, FL("Sending Action Frame has failed"));)
>>>>>>> d97af3b... add prima wlan driver
=======
                PELOGE(limLog(pMac, LOGE, FL("Sending Action Frame has failed\n"));)
>>>>>>> 657b0e9... prima update
                break;
            }
        }
        PELOG1(limLog(pMac, LOG1, FL("The Setting up of LimGlobals is successful for MIMOPS"));)
    }while(0);

<<<<<<< HEAD
<<<<<<< HEAD
    palFreeMemory( pMac->hHdd, (void *) pMIMO_PSParams );
=======
    vos_mem_free((void *) pMIMO_PSParams);
>>>>>>> d97af3b... add prima wlan driver
=======
    palFreeMemory( pMac->hHdd, (void *) pMIMO_PSParams );
>>>>>>> 657b0e9... prima update
#endif
}
/**
  *     @function : limHandleDelBssInReAssocContext
  *     @brief      : While Processing the ReAssociation Response Frame in STA,
  *                         a. immediately after receiving the Reassoc Response the RxCleanUp is
  *                         being issued and the end of DelBSS the new BSS is being added.
  *
  *                         b .If an AP rejects the ReAssociation (Disassoc / Deauth) with some context
  *                         change, We need to update CSR with ReAssocCNF Response with the
  *                         ReAssoc Fail and the reason Code, that is also being handled in the DELBSS
  *                         context only
  *
  *     @param :   pMac - tpAniSirGlobal
  *                     pStaDs - Station Descriptor
  *
  *     @return :  none
  */
static void
limHandleDelBssInReAssocContext(tpAniSirGlobal pMac, tpDphHashNode pStaDs,tpPESession psessionEntry)
{
    tLimMlmReassocCnf           mlmReassocCnf;
    /** Skipped the DeleteDPH Hash Entry as we need it for the new BSS*/
    /** Set the MlmState to IDLE*/
    psessionEntry->limMlmState = eLIM_MLM_IDLE_STATE;
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
    MTRACE(macTrace(pMac, TRACE_CODE_MLM_STATE, psessionEntry->peSessionId, psessionEntry->limMlmState));
   /* Update PE session Id*/
    mlmReassocCnf.sessionId = psessionEntry->peSessionId;
    switch (psessionEntry->limMlmState) {
#if defined(ANI_PRODUCT_TYPE_CLIENT) || defined(ANI_AP_CLIENT_SDK)
<<<<<<< HEAD
=======
   /* Update PE session Id*/
    mlmReassocCnf.sessionId = psessionEntry->peSessionId;
    switch (psessionEntry->limMlmState) {
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
        case eLIM_SME_WT_REASSOC_STATE :
        {
            tpSirAssocRsp assocRsp;
            tpDphHashNode   pStaDs;
            tSirRetStatus       retStatus = eSIR_SUCCESS;
<<<<<<< HEAD
<<<<<<< HEAD
#ifdef ANI_PRODUCT_TYPE_CLIENT
            tSchBeaconStruct beaconStruct;
#endif
=======
            tSchBeaconStruct beaconStruct;
>>>>>>> d97af3b... add prima wlan driver
=======
#ifdef ANI_PRODUCT_TYPE_CLIENT
            tSchBeaconStruct beaconStruct;
#endif
>>>>>>> 657b0e9... prima update
            /** Delete the older STA Table entry */
            limDeleteDphHashEntry(pMac, psessionEntry->bssId, DPH_STA_HASH_INDEX_PEER, psessionEntry);
       /**
             * Add an entry for AP to hash table
             * maintained by DPH module
             */
            if ((pStaDs = dphAddHashEntry(pMac, psessionEntry->limReAssocbssId, DPH_STA_HASH_INDEX_PEER, &psessionEntry->dph.dphHashTable)) == NULL)
            {
                // Could not add hash table entry
<<<<<<< HEAD
<<<<<<< HEAD
                PELOGE(limLog(pMac, LOGE, FL("could not add hash entry at DPH for \n"));)
=======
                PELOGE(limLog(pMac, LOGE, FL("could not add hash entry at DPH for "));)
>>>>>>> d97af3b... add prima wlan driver
=======
                PELOGE(limLog(pMac, LOGE, FL("could not add hash entry at DPH for \n"));)
>>>>>>> 657b0e9... prima update
                limPrintMacAddr(pMac, psessionEntry->limReAssocbssId, LOGE);
                mlmReassocCnf.resultCode = eSIR_SME_RESOURCES_UNAVAILABLE;
                mlmReassocCnf.protStatusCode = eSIR_SME_SUCCESS;
                goto Error;
            }
            /** While Processing the ReAssoc Response Frame the ReAssocRsp Frame
            *   is being stored to be used here for sending ADDBSS
            */
            assocRsp = (tpSirAssocRsp)psessionEntry->limAssocResponseData;
            limUpdateAssocStaDatas(pMac, pStaDs, assocRsp,psessionEntry);
            limUpdateReAssocGlobals(pMac, assocRsp,psessionEntry);
<<<<<<< HEAD
<<<<<<< HEAD
#ifdef ANI_PRODUCT_TYPE_CLIENT
=======
>>>>>>> d97af3b... add prima wlan driver
=======
#ifdef ANI_PRODUCT_TYPE_CLIENT
>>>>>>> 657b0e9... prima update
            limExtractApCapabilities( pMac,
                  (tANI_U8 *) psessionEntry->pLimReAssocReq->bssDescription.ieFields,
                  limGetIElenFromBssDescription( &psessionEntry->pLimReAssocReq->bssDescription ),
                    &beaconStruct );
            if(pMac->lim.gLimProtectionControl != WNI_CFG_FORCE_POLICY_PROTECTION_DISABLE)
                limDecideStaProtectionOnAssoc(pMac, &beaconStruct, psessionEntry);
                if(beaconStruct.erpPresent) {
                if (beaconStruct.erpIEInfo.barkerPreambleMode)
                    psessionEntry->beaconParams.fShortPreamble = 0;
                else
                    psessionEntry->beaconParams.fShortPreamble = 1;
            }
            //updateBss flag is false, as in this case, PE is first deleting the existing BSS and then adding a new one.
            if (eSIR_SUCCESS != limStaSendAddBss( pMac, assocRsp, &beaconStruct,
                                                    &psessionEntry->pLimReAssocReq->bssDescription, false, psessionEntry))  {
<<<<<<< HEAD
<<<<<<< HEAD
                limLog( pMac, LOGE, FL( "Posting ADDBSS in the ReAssocContext has Failed \n"));
                retStatus = eSIR_FAILURE;
            }
#elif defined(ANI_AP_CLIENT_SDK)
            if (eSIR_SUCCESS != limStaSendAddBss( pMac, (*assocRsp), &psessionEntry->pLimReAssocReq->neighborBssList.bssList[0],
                                                  false, psessionEntry))  {
                limLog( pMac, LOGE, FL( "Posting ADDBSS in the ReAssocContext has Failed \n"));
                retStatus = eSIR_FAILURE;
            }
#endif
=======
                limLog( pMac, LOGE, FL( "Posting ADDBSS in the ReAssocContext has Failed "));
                retStatus = eSIR_FAILURE;
            }
>>>>>>> d97af3b... add prima wlan driver
=======
                limLog( pMac, LOGE, FL( "Posting ADDBSS in the ReAssocContext has Failed \n"));
                retStatus = eSIR_FAILURE;
            }
#elif defined(ANI_AP_CLIENT_SDK)
            if (eSIR_SUCCESS != limStaSendAddBss( pMac, (*assocRsp), &psessionEntry->pLimReAssocReq->neighborBssList.bssList[0],
                                                  false, psessionEntry))  {
                limLog( pMac, LOGE, FL( "Posting ADDBSS in the ReAssocContext has Failed \n"));
                retStatus = eSIR_FAILURE;
            }
#endif
>>>>>>> 657b0e9... prima update
            if (retStatus != eSIR_SUCCESS)
            {
                mlmReassocCnf.resultCode = eSIR_SME_RESOURCES_UNAVAILABLE;
                mlmReassocCnf.protStatusCode = eSIR_MAC_UNSPEC_FAILURE_STATUS;
<<<<<<< HEAD
<<<<<<< HEAD
                palFreeMemory(pMac->hHdd, assocRsp);
                pMac->lim.gLimAssocResponseData = NULL;
                goto Error;
            }
            palFreeMemory(pMac->hHdd, assocRsp);
=======
                vos_mem_free(assocRsp);
                pMac->lim.gLimAssocResponseData = NULL;
                goto Error;
            }
            vos_mem_free(assocRsp);
>>>>>>> d97af3b... add prima wlan driver
=======
                palFreeMemory(pMac->hHdd, assocRsp);
                pMac->lim.gLimAssocResponseData = NULL;
                goto Error;
            }
            palFreeMemory(pMac->hHdd, assocRsp);
>>>>>>> 657b0e9... prima update
            psessionEntry->limAssocResponseData = NULL;
        }
        break;
        case eLIM_SME_WT_REASSOC_LINK_FAIL_STATE:
        {
            /** Case wherein the DisAssoc / Deauth
             *   being sent as response to ReAssoc Req*/
            /** Send the Reason code as the same received in Disassoc / Deauth Frame*/
            mlmReassocCnf.resultCode = pStaDs->mlmStaContext.disassocReason;
            mlmReassocCnf.protStatusCode = pStaDs->mlmStaContext.cleanupTrigger;
            /** Set the SME State back to WT_Reassoc State*/
            psessionEntry->limSmeState = eLIM_SME_WT_REASSOC_STATE;
<<<<<<< HEAD
<<<<<<< HEAD
            MTRACE(macTrace(pMac, TRACE_CODE_SME_STATE, psessionEntry->peSessionId, psessionEntry->limSmeState));
=======
>>>>>>> d97af3b... add prima wlan driver
=======
            MTRACE(macTrace(pMac, TRACE_CODE_SME_STATE, psessionEntry->peSessionId, psessionEntry->limSmeState));
>>>>>>> 657b0e9... prima update
            limDeleteDphHashEntry(pMac, pStaDs->staAddr, pStaDs->assocId,psessionEntry);
            if((psessionEntry->limSystemRole == eLIM_STA_ROLE)||
                (psessionEntry->limSystemRole == eLIM_BT_AMP_STA_ROLE))
            {
               psessionEntry->limMlmState = eLIM_MLM_IDLE_STATE;
<<<<<<< HEAD
<<<<<<< HEAD
               MTRACE(macTrace(pMac, TRACE_CODE_MLM_STATE, psessionEntry->peSessionId, psessionEntry->limMlmState));
=======
>>>>>>> d97af3b... add prima wlan driver
=======
               MTRACE(macTrace(pMac, TRACE_CODE_MLM_STATE, psessionEntry->peSessionId, psessionEntry->limMlmState));
>>>>>>> 657b0e9... prima update
            }
            limPostSmeMessage(pMac, LIM_MLM_REASSOC_CNF, (tANI_U32 *) &mlmReassocCnf);
        }
        break;
<<<<<<< HEAD
<<<<<<< HEAD
#endif
        default:
            PELOGE(limLog(pMac, LOGE, FL("DelBss is being invoked in the wrong system Role /unhandled  SME State\n"));)
=======
        default:
            PELOGE(limLog(pMac, LOGE, FL("DelBss is being invoked in the wrong system Role /unhandled  SME State"));)
>>>>>>> d97af3b... add prima wlan driver
=======
#endif
        default:
            PELOGE(limLog(pMac, LOGE, FL("DelBss is being invoked in the wrong system Role /unhandled  SME State\n"));)
>>>>>>> 657b0e9... prima update
            mlmReassocCnf.resultCode = eSIR_SME_REFUSED;
            mlmReassocCnf.protStatusCode = eSIR_SME_UNEXPECTED_REQ_RESULT_CODE;
            goto Error;
    }
    return;
Error:
    limPostSmeMessage(pMac, LIM_MLM_REASSOC_CNF, (tANI_U32 *) &mlmReassocCnf);
}

/* Added For BT -AMP Support */
static void
limProcessBtampAddBssRsp( tpAniSirGlobal pMac, tpSirMsgQ limMsgQ ,tpPESession psessionEntry)
{
    tLimMlmStartCnf mlmStartCnf;
    tANI_U32 val;
    tpAddBssParams pAddBssParams = (tpAddBssParams) limMsgQ->bodyptr;

<<<<<<< HEAD
<<<<<<< HEAD
    if( eHAL_STATUS_SUCCESS == pAddBssParams->status )
    {
        limLog(pMac, LOG2, FL("WDA_ADD_BSS_RSP returned with eHAL_STATUS_SUCCESS\n"));
=======
    if (NULL == pAddBssParams)
    {
        limLog( pMac, LOGE, FL( "Invalid body pointer in message"));
        goto end;
    }
    if( eHAL_STATUS_SUCCESS == pAddBssParams->status )
    {
        limLog(pMac, LOG2, FL("WDA_ADD_BSS_RSP returned with eHAL_STATUS_SUCCESS"));
>>>>>>> d97af3b... add prima wlan driver
=======
    if( eHAL_STATUS_SUCCESS == pAddBssParams->status )
    {
        limLog(pMac, LOG2, FL("WDA_ADD_BSS_RSP returned with eHAL_STATUS_SUCCESS\n"));
>>>>>>> 657b0e9... prima update
         if (psessionEntry->bssType == eSIR_BTAMP_AP_MODE)
         {
             if (limSetLinkState(pMac, eSIR_LINK_BTAMP_AP_STATE, psessionEntry->bssId,
                  psessionEntry->selfMacAddr, NULL, NULL) != eSIR_SUCCESS )
               goto end;
         } else if (psessionEntry->bssType == eSIR_BTAMP_STA_MODE) {
            if (limSetLinkState(pMac, eSIR_LINK_SCAN_STATE, psessionEntry->bssId,
                 psessionEntry->selfMacAddr, NULL, NULL) != eSIR_SUCCESS )
                goto end;
         }

        // Set MLME state
        psessionEntry->limMlmState= eLIM_MLM_BSS_STARTED_STATE;
        psessionEntry->statypeForBss = STA_ENTRY_SELF; // to know session started for peer or for self
        psessionEntry->bssIdx = (tANI_U8) pAddBssParams->bssIdx;
        schEdcaProfileUpdate(pMac, psessionEntry);
<<<<<<< HEAD
<<<<<<< HEAD
        limInitAIDpool(pMac,psessionEntry);
=======
        limInitPeerIdxpool(pMac,psessionEntry);
>>>>>>> d97af3b... add prima wlan driver
=======
        limInitAIDpool(pMac,psessionEntry);
>>>>>>> 657b0e9... prima update
        // Create timers used by LIM
        if (!pMac->lim.gLimTimersCreated)
        limCreateTimers(pMac);
      /* Update the lim global gLimTriggerBackgroundScanDuringQuietBss */
        if( eSIR_SUCCESS != wlan_cfgGetInt( pMac, WNI_CFG_TRIG_STA_BK_SCAN, &val ))
<<<<<<< HEAD
<<<<<<< HEAD
            limLog( pMac, LOGP, FL("Failed to get WNI_CFG_TRIG_STA_BK_SCAN!\n"));
=======
            limLog( pMac, LOGP, FL("Failed to get WNI_CFG_TRIG_STA_BK_SCAN!"));
>>>>>>> d97af3b... add prima wlan driver
=======
            limLog( pMac, LOGP, FL("Failed to get WNI_CFG_TRIG_STA_BK_SCAN!\n"));
>>>>>>> 657b0e9... prima update
        pMac->lim.gLimTriggerBackgroundScanDuringQuietBss = (val) ? 1 : 0;
        // Apply previously set configuration at HW
        limApplyConfiguration(pMac,psessionEntry);
        psessionEntry->staId = pAddBssParams->staContext.staIdx;
        mlmStartCnf.resultCode  = eSIR_SME_SUCCESS;
    }
    else
    {
<<<<<<< HEAD
<<<<<<< HEAD
        limLog( pMac, LOGE, FL( "WDA_ADD_BSS_REQ failed with status %d\n" ),pAddBssParams->status );
=======
        limLog( pMac, LOGE, FL( "WDA_ADD_BSS_REQ failed with status %d" ),pAddBssParams->status );
>>>>>>> d97af3b... add prima wlan driver
=======
        limLog( pMac, LOGE, FL( "WDA_ADD_BSS_REQ failed with status %d\n" ),pAddBssParams->status );
>>>>>>> 657b0e9... prima update
        mlmStartCnf.resultCode = eSIR_SME_HAL_SEND_MESSAGE_FAIL;
    }
    mlmStartCnf.sessionId = psessionEntry->peSessionId;
    limPostSmeMessage( pMac, LIM_MLM_START_CNF, (tANI_U32 *) &mlmStartCnf );
    end:
    if( 0 != limMsgQ->bodyptr )
<<<<<<< HEAD
<<<<<<< HEAD
        palFreeMemory( pMac->hHdd, (void *) pAddBssParams );
=======
        vos_mem_free(pAddBssParams);
>>>>>>> d97af3b... add prima wlan driver
=======
        palFreeMemory( pMac->hHdd, (void *) pAddBssParams );
>>>>>>> 657b0e9... prima update
}

/**
  *     @function : limHandleAddBssInReAssocContext
  *     @brief      : While Processing the ReAssociation Response Frame in STA,
  *                         a. immediately after receiving the Reassoc Response the RxCleanUp is
  *                         being issued and the end of DelBSS the new BSS is being added.
  *
  *                         b .If an AP rejects the ReAssociation (Disassoc / Deauth) with some context
  *                         change, We need to update CSR with ReAssocCNF Response with the
  *                         ReAssoc Fail and the reason Code, that is also being handled in the DELBSS
  *                         context only
  *
  *     @param :   pMac - tpAniSirGlobal
  *                     pStaDs - Station Descriptor
  *
  *     @return :  none
  */
void
limHandleAddBssInReAssocContext(tpAniSirGlobal pMac, tpDphHashNode pStaDs, tpPESession psessionEntry)
{
    tLimMlmReassocCnf           mlmReassocCnf;
    /** Skipped the DeleteDPH Hash Entry as we need it for the new BSS*/
    /** Set the MlmState to IDLE*/
    psessionEntry->limMlmState = eLIM_MLM_IDLE_STATE;
    MTRACE(macTrace(pMac, TRACE_CODE_MLM_STATE, psessionEntry->peSessionId, psessionEntry->limMlmState));
    switch (psessionEntry->limSmeState) {
<<<<<<< HEAD
<<<<<<< HEAD
#if defined(ANI_PRODUCT_TYPE_CLIENT) || defined(ANI_AP_CLIENT_SDK)
=======
>>>>>>> d97af3b... add prima wlan driver
=======
#if defined(ANI_PRODUCT_TYPE_CLIENT) || defined(ANI_AP_CLIENT_SDK)
>>>>>>> 657b0e9... prima update
        case eLIM_SME_WT_REASSOC_STATE : {
            tpSirAssocRsp assocRsp;
            tpDphHashNode   pStaDs;
            tSirRetStatus       retStatus = eSIR_SUCCESS;
<<<<<<< HEAD
<<<<<<< HEAD
#ifdef ANI_PRODUCT_TYPE_CLIENT
            tSchBeaconStruct *pBeaconStruct;
            if(eHAL_STATUS_SUCCESS != palAllocateMemory(pMac->hHdd, 
                                                        (void **)&pBeaconStruct, sizeof(tSchBeaconStruct)))
            {
                limLog(pMac, LOGE, FL("Unable to PAL allocate memory in limHandleAddBssInReAssocContext\n") );
=======
=======
#ifdef ANI_PRODUCT_TYPE_CLIENT
>>>>>>> 657b0e9... prima update
            tSchBeaconStruct *pBeaconStruct;
            if(eHAL_STATUS_SUCCESS != palAllocateMemory(pMac->hHdd, 
                                                        (void **)&pBeaconStruct, sizeof(tSchBeaconStruct)))
            {
<<<<<<< HEAD
                limLog(pMac, LOGE, FL("Unable to allocate memory in limHandleAddBssInReAssocContext") );
>>>>>>> d97af3b... add prima wlan driver
=======
                limLog(pMac, LOGE, FL("Unable to PAL allocate memory in limHandleAddBssInReAssocContext\n") );
>>>>>>> 657b0e9... prima update
                mlmReassocCnf.resultCode = eSIR_SME_RESOURCES_UNAVAILABLE;
                mlmReassocCnf.protStatusCode = eSIR_SME_RESOURCES_UNAVAILABLE;
                goto Error;
            }

<<<<<<< HEAD
<<<<<<< HEAD
#endif
=======
>>>>>>> d97af3b... add prima wlan driver
=======
#endif
>>>>>>> 657b0e9... prima update
            // Get the AP entry from DPH hash table
            pStaDs = dphGetHashEntry(pMac, DPH_STA_HASH_INDEX_PEER, &psessionEntry->dph.dphHashTable);
            if (pStaDs == NULL )
            {
<<<<<<< HEAD
<<<<<<< HEAD
                PELOGE(limLog(pMac, LOGE, FL("Fail to get STA PEER entry from hash\n"));)
                mlmReassocCnf.resultCode = eSIR_SME_RESOURCES_UNAVAILABLE;
                mlmReassocCnf.protStatusCode = eSIR_SME_SUCCESS;
                palFreeMemory(pMac->hHdd, pBeaconStruct);
=======
                PELOGE(limLog(pMac, LOGE, FL("Fail to get STA PEER entry from hash"));)
                mlmReassocCnf.resultCode = eSIR_SME_RESOURCES_UNAVAILABLE;
                mlmReassocCnf.protStatusCode = eSIR_SME_SUCCESS;
                vos_mem_free(pBeaconStruct);
>>>>>>> d97af3b... add prima wlan driver
=======
                PELOGE(limLog(pMac, LOGE, FL("Fail to get STA PEER entry from hash\n"));)
                mlmReassocCnf.resultCode = eSIR_SME_RESOURCES_UNAVAILABLE;
                mlmReassocCnf.protStatusCode = eSIR_SME_SUCCESS;
                palFreeMemory(pMac->hHdd, pBeaconStruct);
>>>>>>> 657b0e9... prima update
                goto Error;
            }
            /** While Processing the ReAssoc Response Frame the ReAssocRsp Frame
            *   is being stored to be used here for sending ADDBSS
            */
            assocRsp = (tpSirAssocRsp)psessionEntry->limAssocResponseData;
            limUpdateAssocStaDatas(pMac, pStaDs, assocRsp, psessionEntry);
            limUpdateReAssocGlobals(pMac, assocRsp, psessionEntry);
<<<<<<< HEAD
<<<<<<< HEAD
#ifdef ANI_PRODUCT_TYPE_CLIENT
=======
>>>>>>> d97af3b... add prima wlan driver
=======
#ifdef ANI_PRODUCT_TYPE_CLIENT
>>>>>>> 657b0e9... prima update
            limExtractApCapabilities( pMac,
                  (tANI_U8 *) psessionEntry->pLimReAssocReq->bssDescription.ieFields,
                  limGetIElenFromBssDescription( &psessionEntry->pLimReAssocReq->bssDescription ),
                    pBeaconStruct );
            if(pMac->lim.gLimProtectionControl != WNI_CFG_FORCE_POLICY_PROTECTION_DISABLE)
                limDecideStaProtectionOnAssoc(pMac, pBeaconStruct, psessionEntry);

            if(pBeaconStruct->erpPresent) 
            {
                if (pBeaconStruct->erpIEInfo.barkerPreambleMode)
                    psessionEntry->beaconParams.fShortPreamble = 0;
                else
                    psessionEntry->beaconParams.fShortPreamble = 1;
            }

            if (eSIR_SUCCESS != limStaSendAddBss( pMac, assocRsp, pBeaconStruct,
                                                    &psessionEntry->pLimReAssocReq->bssDescription, true, psessionEntry))  {
<<<<<<< HEAD
<<<<<<< HEAD
                limLog( pMac, LOGE, FL( "Posting ADDBSS in the ReAssocContext has Failed \n"));
                retStatus = eSIR_FAILURE;
            }
#elif defined(ANI_AP_CLIENT_SDK)
            if (eSIR_SUCCESS != limStaSendAddBss( pMac, (*assocRsp), &pMac->lim.gpLimReassocReq->neighborBssList.bssList[0], true))  {
                limLog( pMac, LOGE, FL( "Posting ADDBSS in the ReAssocContext has Failed \n"));
                retStatus = eSIR_FAILURE;
            }
#endif
=======
                limLog( pMac, LOGE, FL( "Posting ADDBSS in the ReAssocContext has Failed "));
                retStatus = eSIR_FAILURE;
            }
>>>>>>> d97af3b... add prima wlan driver
=======
                limLog( pMac, LOGE, FL( "Posting ADDBSS in the ReAssocContext has Failed \n"));
                retStatus = eSIR_FAILURE;
            }
#elif defined(ANI_AP_CLIENT_SDK)
            if (eSIR_SUCCESS != limStaSendAddBss( pMac, (*assocRsp), &pMac->lim.gpLimReassocReq->neighborBssList.bssList[0], true))  {
                limLog( pMac, LOGE, FL( "Posting ADDBSS in the ReAssocContext has Failed \n"));
                retStatus = eSIR_FAILURE;
            }
#endif
>>>>>>> 657b0e9... prima update
            if (retStatus != eSIR_SUCCESS)
            {
                mlmReassocCnf.resultCode = eSIR_SME_RESOURCES_UNAVAILABLE;
                mlmReassocCnf.protStatusCode = eSIR_MAC_UNSPEC_FAILURE_STATUS;
<<<<<<< HEAD
<<<<<<< HEAD
                palFreeMemory(pMac->hHdd, assocRsp);
                pMac->lim.gLimAssocResponseData = NULL;
                palFreeMemory(pMac->hHdd, pBeaconStruct);
                goto Error;
            }
            palFreeMemory(pMac->hHdd, assocRsp);
            psessionEntry->limAssocResponseData = NULL;
            palFreeMemory(pMac->hHdd, pBeaconStruct);
=======
                vos_mem_free(assocRsp);
=======
                palFreeMemory(pMac->hHdd, assocRsp);
>>>>>>> 657b0e9... prima update
                pMac->lim.gLimAssocResponseData = NULL;
                palFreeMemory(pMac->hHdd, pBeaconStruct);
                goto Error;
            }
            palFreeMemory(pMac->hHdd, assocRsp);
            psessionEntry->limAssocResponseData = NULL;
<<<<<<< HEAD
            vos_mem_free(pBeaconStruct);
>>>>>>> d97af3b... add prima wlan driver
=======
            palFreeMemory(pMac->hHdd, pBeaconStruct);
>>>>>>> 657b0e9... prima update
        }
        break;
        case eLIM_SME_WT_REASSOC_LINK_FAIL_STATE: {     /** Case wherein the DisAssoc / Deauth
                                                                                     *   being sent as response to ReAssoc Req*/
            /** Send the Reason code as the same received in Disassoc / Deauth Frame*/
            mlmReassocCnf.resultCode = pStaDs->mlmStaContext.disassocReason;
            mlmReassocCnf.protStatusCode = pStaDs->mlmStaContext.cleanupTrigger;
            /** Set the SME State back to WT_Reassoc State*/
            psessionEntry->limSmeState = eLIM_SME_WT_REASSOC_STATE;
            limDeleteDphHashEntry(pMac, pStaDs->staAddr, pStaDs->assocId, psessionEntry);
            if(psessionEntry->limSystemRole == eLIM_STA_ROLE)
<<<<<<< HEAD
<<<<<<< HEAD
              psessionEntry->limMlmState = eLIM_MLM_IDLE_STATE;
=======
            {
              psessionEntry->limMlmState = eLIM_MLM_IDLE_STATE;
               MTRACE(macTrace(pMac, TRACE_CODE_MLM_STATE, psessionEntry->peSessionId, psessionEntry->limMlmState));
            }
>>>>>>> d97af3b... add prima wlan driver
=======
              psessionEntry->limMlmState = eLIM_MLM_IDLE_STATE;
>>>>>>> 657b0e9... prima update

            limPostSmeMessage(pMac, LIM_MLM_REASSOC_CNF, (tANI_U32 *) &mlmReassocCnf);
        }
        break;
<<<<<<< HEAD
<<<<<<< HEAD
#endif
        default:
            PELOGE(limLog(pMac, LOGE, FL("DelBss is being invoked in the wrong system Role /unhandled  SME State\n"));)
=======
        default:
            PELOGE(limLog(pMac, LOGE, FL("DelBss is being invoked in the wrong system Role /unhandled  SME State"));)
>>>>>>> d97af3b... add prima wlan driver
=======
#endif
        default:
            PELOGE(limLog(pMac, LOGE, FL("DelBss is being invoked in the wrong system Role /unhandled  SME State\n"));)
>>>>>>> 657b0e9... prima update
            mlmReassocCnf.resultCode = eSIR_SME_REFUSED;
            mlmReassocCnf.protStatusCode = eSIR_SME_UNEXPECTED_REQ_RESULT_CODE;
            goto Error;
    }
return;
Error:
    limPostSmeMessage(pMac, LIM_MLM_REASSOC_CNF, (tANI_U32 *) &mlmReassocCnf);
}

#if 0
 static void
limProcessSmeAssocCnfNew(tpAniSirGlobal pMac, tANI_U32 msgType, tANI_U32 *pMsgBuf)
{
    tSirSmeAssocCnf    assocCnf;
    tpDphHashNode      pStaDs;
    tpPESession        psessionEntry;
    tANI_U8            sessionId;

    if(pMsgBuf == NULL)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        limLog(pMac, LOGE, FL("pMsgBuf is NULL \n"));
=======
        limLog(pMac, LOGE, FL("pMsgBuf is NULL "));
>>>>>>> d97af3b... add prima wlan driver
=======
        limLog(pMac, LOGE, FL("pMsgBuf is NULL \n"));
>>>>>>> 657b0e9... prima update
        goto end;
    }
    if ((limAssocCnfSerDes(pMac, &assocCnf, (tANI_U8 *) pMsgBuf) == eSIR_FAILURE) ||
        !__limIsSmeAssocCnfValid(&assocCnf))
    {
<<<<<<< HEAD
<<<<<<< HEAD
        limLog(pMac, LOGE, FL("Received invalid SME_RE(ASSOC)_CNF message \n"));
=======
        limLog(pMac, LOGE, FL("Received invalid SME_RE(ASSOC)_CNF message "));
>>>>>>> d97af3b... add prima wlan driver
=======
        limLog(pMac, LOGE, FL("Received invalid SME_RE(ASSOC)_CNF message \n"));
>>>>>>> 657b0e9... prima update
        goto end;
    }
    if((psessionEntry = peFindSessionByBssid(pMac, assocCnf.bssId, &sessionId))== NULL)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        limLog(pMac, LOGE, FL("session does not exist for given bssId\n"));
=======
        limLog(pMac, LOGE, FL("session does not exist for given bssId"));
>>>>>>> d97af3b... add prima wlan driver
=======
        limLog(pMac, LOGE, FL("session does not exist for given bssId\n"));
>>>>>>> 657b0e9... prima update
        goto end;
    }
    if ( ((psessionEntry->limSystemRole != eLIM_AP_ROLE) && (psessionEntry->limSystemRole != eLIM_BT_AMP_AP_ROLE)) ||
         ((psessionEntry->limSmeState != eLIM_SME_NORMAL_STATE) && (psessionEntry->limSmeState != eLIM_SME_NORMAL_CHANNEL_SCAN_STATE)))
    {
<<<<<<< HEAD
<<<<<<< HEAD
        limLog(pMac, LOGE, FL("Received unexpected message %X in state %X, in role %X\n"),
=======
        limLog(pMac, LOGE, FL("Received unexpected message %X in state %X, in role %X"),
>>>>>>> d97af3b... add prima wlan driver
=======
        limLog(pMac, LOGE, FL("Received unexpected message %X in state %X, in role %X\n"),
>>>>>>> 657b0e9... prima update
               msgType, psessionEntry->limSmeState , psessionEntry->limSystemRole);
        goto end;
    }
    pStaDs = dphGetHashEntry(pMac, assocCnf.aid, &psessionEntry->dph.dphHashTable);
    if (pStaDs == NULL)
    {
        limLog(pMac, LOG1,
            FL("Received invalid message %X due to no STA context, for aid %d, peer "),
            msgType, assocCnf.aid);
        limPrintMacAddr(pMac, assocCnf.peerMacAddr, LOG1);
        /*
        ** send a DISASSOC_IND message to WSM to make sure
        ** the state in WSM and LIM is the same
        **/
       limSendSmeDisassocNtf( pMac, assocCnf.peerMacAddr, eSIR_SME_STA_NOT_ASSOCIATED,
                              eLIM_PEER_ENTITY_DISASSOC, assocCnf.aid,psessionEntry->smeSessionId,psessionEntry->transactionId,psessionEntry);
       goto end;
    }
    if ((pStaDs &&
<<<<<<< HEAD
<<<<<<< HEAD
         (( !palEqualMemory( pMac->hHdd,(tANI_U8 *) pStaDs->staAddr,
=======
         (( !vos_mem_compare((tANI_U8 *) pStaDs->staAddr,
>>>>>>> d97af3b... add prima wlan driver
=======
         (( !palEqualMemory( pMac->hHdd,(tANI_U8 *) pStaDs->staAddr,
>>>>>>> 657b0e9... prima update
                     (tANI_U8 *) assocCnf.peerMacAddr,
                     sizeof(tSirMacAddr)) ) ||
          (pStaDs->mlmStaContext.mlmState != eLIM_MLM_WT_ASSOC_CNF_STATE) ||
          ((pStaDs->mlmStaContext.subType == LIM_ASSOC) &&
           (msgType != eWNI_SME_ASSOC_CNF)) ||
          ((pStaDs->mlmStaContext.subType == LIM_REASSOC) &&
           (msgType != eWNI_SME_REASSOC_CNF)))))
    {
        limLog(pMac, LOG1,
           FL("Received invalid message %X due to peerMacAddr mismatched or not in eLIM_MLM_WT_ASSOC_CNF_STATE state, for aid %d, peer "),
           msgType, assocCnf.aid);
        limPrintMacAddr(pMac, assocCnf.peerMacAddr, LOG1);
        goto end;
    }
    /*
    ** Deactivate/delet CNF_WAIT timer since ASSOC_CNF
    ** has been received
    **/
<<<<<<< HEAD
<<<<<<< HEAD
    limLog(pMac, LOG1, FL("Received SME_ASSOC_CNF. Delete Timer\n"));
=======
    limLog(pMac, LOG1, FL("Received SME_ASSOC_CNF. Delete Timer"));
>>>>>>> d97af3b... add prima wlan driver
=======
    limLog(pMac, LOG1, FL("Received SME_ASSOC_CNF. Delete Timer\n"));
>>>>>>> 657b0e9... prima update
    limDeactivateAndChangePerStaIdTimer(pMac, eLIM_CNF_WAIT_TIMER, pStaDs->assocId);
    if (assocCnf.statusCode == eSIR_SME_SUCCESS)
    {
        /* In BTAMP-AP, PE already finished the WDA_ADD_STA sequence
         * when it had received Assoc Request frame. Now, PE just needs to send
         * Association Response frame to the requesting BTAMP-STA.
         */
        pStaDs->mlmStaContext.mlmState = eLIM_MLM_LINK_ESTABLISHED_STATE;
<<<<<<< HEAD
<<<<<<< HEAD
        limLog(pMac, LOG1, FL("sending Assoc Rsp frame to STA (assoc id=%d) \n"), pStaDs->assocId);
=======
        limLog(pMac, LOG1, FL("sending Assoc Rsp frame to STA (assoc id=%d) "), pStaDs->assocId);
>>>>>>> d97af3b... add prima wlan driver
=======
        limLog(pMac, LOG1, FL("sending Assoc Rsp frame to STA (assoc id=%d) \n"), pStaDs->assocId);
>>>>>>> 657b0e9... prima update
        limSendAssocRspMgmtFrame( pMac, eSIR_SUCCESS, pStaDs->assocId, pStaDs->staAddr,
                                  pStaDs->mlmStaContext.subType, pStaDs, psessionEntry);
        goto end;
    } // (assocCnf.statusCode == eSIR_SME_SUCCESS)
    else
    {
        // SME_ASSOC_CNF status is non-success, so STA is not allowed to be associated
        limRejectAssociation(pMac, pStaDs->staAddr,
                             pStaDs->mlmStaContext.subType,
                             true, pStaDs->mlmStaContext.authType,
                             pStaDs->assocId, true,
                             assocCnf.statusCode, psessionEntry);
        return;
    }
end:
    if ( psessionEntry->parsedAssocReq[pStaDs->assocId] != NULL )
    {
        if ( ((tpSirAssocReq)(psessionEntry->parsedAssocReq[pStaDs->assocId]))->assocReqFrame) 
        {
<<<<<<< HEAD
<<<<<<< HEAD
            palFreeMemory(pMac->hHdd,((tpSirAssocReq)(psessionEntry->parsedAssocReq[pStaDs->assocId]))->assocReqFrame);
            ((tpSirAssocReq)(psessionEntry->parsedAssocReq[pStaDs->assocId]))->assocReqFrame = NULL;
        }        

        palFreeMemory(pMac->hHdd, psessionEntry->parsedAssocReq[pStaDs->assocId]);
=======
            vos_mem_free(((tpSirAssocReq)(psessionEntry->parsedAssocReq[pStaDs->assocId]))->assocReqFrame);
            ((tpSirAssocReq)(psessionEntry->parsedAssocReq[pStaDs->assocId]))->assocReqFrame = NULL;
        }        

        vos_mem_free(psessionEntry->parsedAssocReq[pStaDs->assocId]);
>>>>>>> d97af3b... add prima wlan driver
=======
            palFreeMemory(pMac->hHdd,((tpSirAssocReq)(psessionEntry->parsedAssocReq[pStaDs->assocId]))->assocReqFrame);
            ((tpSirAssocReq)(psessionEntry->parsedAssocReq[pStaDs->assocId]))->assocReqFrame = NULL;
        }        

        palFreeMemory(pMac->hHdd, psessionEntry->parsedAssocReq[pStaDs->assocId]);
>>>>>>> 657b0e9... prima update
        psessionEntry->parsedAssocReq[pStaDs->assocId] = NULL;
    }
} /*** end __limProcessSmeAssocCnfNew() ***/
#endif

<<<<<<< HEAD
<<<<<<< HEAD
#ifdef WLAN_SOFTAP_FEATURE
=======
>>>>>>> d97af3b... add prima wlan driver
=======
#ifdef WLAN_SOFTAP_FEATURE
>>>>>>> 657b0e9... prima update
void
limSendBeaconInd(tpAniSirGlobal pMac, tpPESession psessionEntry){
    tBeaconGenParams *pBeaconGenParams = NULL;
    tSirMsgQ limMsg;
    /** Allocate the Memory for Beacon Pre Message and for Stations in PoweSave*/
    if(psessionEntry == NULL ){
       PELOGE( limLog( pMac, LOGE,
<<<<<<< HEAD
<<<<<<< HEAD
                        FL( "Error:Unable to get the PESessionEntry\n" ));)
       return;
    }
    if( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd,
                                            (void **) &pBeaconGenParams, (sizeof(*pBeaconGenParams))))
    {
        PELOGE( limLog( pMac, LOGP,
                        FL( "Unable to PAL allocate memory during sending beaconPreMessage\n" ));)
        return;
    }
    palZeroMemory( pMac->hHdd, pBeaconGenParams, sizeof(*pBeaconGenParams));
    palCopyMemory( pMac->hHdd, (void *) pBeaconGenParams->bssId,
                    (void *)psessionEntry->bssId,
                    SIR_MAC_ADDR_LENGTH );
=======
                        FL( "Error:Unable to get the PESessionEntry" ));)
=======
                        FL( "Error:Unable to get the PESessionEntry\n" ));)
>>>>>>> 657b0e9... prima update
       return;
    }
    if( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd,
                                            (void **) &pBeaconGenParams, (sizeof(*pBeaconGenParams))))
    {
        PELOGE( limLog( pMac, LOGP,
                        FL( "Unable to PAL allocate memory during sending beaconPreMessage\n" ));)
        return;
    }
<<<<<<< HEAD
    vos_mem_set(pBeaconGenParams, sizeof(*pBeaconGenParams), 0);
    vos_mem_copy((void *) pBeaconGenParams->bssId,
                 (void *)psessionEntry->bssId,
                  SIR_MAC_ADDR_LENGTH );
>>>>>>> d97af3b... add prima wlan driver
=======
    palZeroMemory( pMac->hHdd, pBeaconGenParams, sizeof(*pBeaconGenParams));
    palCopyMemory( pMac->hHdd, (void *) pBeaconGenParams->bssId,
                    (void *)psessionEntry->bssId,
                    SIR_MAC_ADDR_LENGTH );
>>>>>>> 657b0e9... prima update
    limMsg.bodyptr = pBeaconGenParams;
    schProcessPreBeaconInd(pMac, &limMsg);
    return;
}
<<<<<<< HEAD
<<<<<<< HEAD
#endif
=======

void limSendScanOffloadComplete(tpAniSirGlobal pMac,
                                tSirResultCodes reasonCode)
{
    tANI_U16 scanRspLen = 0;

    pMac->lim.gLimSmeScanResultLength +=
        pMac->lim.gLimMlmScanResultLength;
    pMac->lim.gLimRspReqd = false;
    if ((reasonCode == eSIR_SME_SUCCESS) ||
            pMac->lim.gLimSmeScanResultLength) {
        scanRspLen = sizeof(tSirSmeScanRsp) +
            pMac->lim.gLimSmeScanResultLength -
            sizeof(tSirBssDescription);
    }
    else
        scanRspLen = sizeof(tSirSmeScanRsp);

    limSendSmeScanRsp(pMac, scanRspLen, reasonCode,
            pMac->lim.gSmeSessionId,
            pMac->lim.gTransactionId);
}


void limProcessRxScanEvent(tpAniSirGlobal pMac, void *buf)
{
    tSirScanOffloadEvent *pScanEvent = (tSirScanOffloadEvent *) buf;

    VOS_TRACE(VOS_MODULE_ID_PE, VOS_TRACE_LEVEL_INFO,
            "scan_id = %lu", pScanEvent->scanId);

    switch (pScanEvent->event)
    {
        case SCAN_EVENT_STARTED:
            break;
        case SCAN_EVENT_START_FAILED:
        case SCAN_EVENT_COMPLETED:
            limSendScanOffloadComplete(pMac, pScanEvent->reasonCode);
            break;
        case SCAN_EVENT_BSS_CHANNEL:
        case SCAN_EVENT_FOREIGN_CHANNEL:
        case SCAN_EVENT_DEQUEUED:
        case SCAN_EVENT_PREEMPTED:
        default:
            VOS_TRACE(VOS_MODULE_ID_PE, VOS_TRACE_LEVEL_DEBUG,
                    "Received unhandled scan event %lu", pScanEvent->event);
    }
}
>>>>>>> d97af3b... add prima wlan driver
=======
#endif
>>>>>>> 657b0e9... prima update
