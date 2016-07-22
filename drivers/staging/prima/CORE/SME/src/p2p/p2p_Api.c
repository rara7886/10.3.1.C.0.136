/*
<<<<<<< HEAD
 * Copyright (c) 2012, The Linux Foundation. All rights reserved.
=======
 * Copyright (c) 2012-2013, The Linux Foundation. All rights reserved.
>>>>>>> d97af3b... add prima wlan driver
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

/*
 * Copyright (c) 2008 QUALCOMM Incorporated. All Rights Reserved.
 * Qualcomm Confidential and Proprietary 
 */

#if defined WLAN_FEATURE_P2P
=======
/*
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


>>>>>>> d97af3b... add prima wlan driver

#include "sme_Api.h"
#include "smsDebug.h"
#include "csrInsideApi.h"
#include "smeInside.h"
#include "p2p_Api.h"
#include "limApi.h"
#include "cfgApi.h"

#ifdef WLAN_FEATURE_P2P_INTERNAL
#include "p2p_ie.h"
#include "p2pFsm.h"

extern tp2pie gP2PIe;

static eHalStatus p2pSendActionFrame(tpAniSirGlobal pMac, tANI_U8 SessionID, eP2PFrameType actionFrameType);
static eHalStatus p2pListenStateDiscoverableCallback(tHalHandle halHandle, void *pContext, eHalStatus retStatus);
static eHalStatus p2pRemainOnChannelReadyCallback(tHalHandle halHandle, void *pContext, eHalStatus scan_status);
static tANI_BOOLEAN p2pIsGOportEnabled(tpAniSirGlobal pMac);
#endif

eHalStatus p2pProcessNoAReq(tpAniSirGlobal pMac, tSmeCmd *pNoACmd);
/*------------------------------------------------------------------
 *
 * handle SME remain on channel request.
 *
 *------------------------------------------------------------------*/

eHalStatus p2pProcessRemainOnChannelCmd(tpAniSirGlobal pMac, tSmeCmd *p2pRemainonChn)
{
    eHalStatus status = eHAL_STATUS_SUCCESS;
    tSirRemainOnChnReq* pMsg;
    tANI_U16 len;
    tCsrRoamSession *pSession = CSR_GET_SESSION( pMac, p2pRemainonChn->sessionId );

    if(!pSession)
    {
       smsLog(pMac, LOGE, FL("  session %d not found "), p2pRemainonChn->sessionId);
       return eHAL_STATUS_FAILURE;
    }

#ifdef WLAN_FEATURE_P2P_INTERNAL
    tANI_U8 P2PsessionId = getP2PSessionIdFromSMESessionId(pMac, p2pRemainonChn->sessionId);
    tp2pContext *p2pContext = &pMac->p2pContext[P2PsessionId];
    tANI_U32 ieLen = 0;
#endif

#ifdef WLAN_FEATURE_P2P_INTERNAL
    if( !pSession->sessionActive || (CSR_SESSION_ID_INVALID == P2PsessionId)) 
    {
<<<<<<< HEAD
       smsLog(pMac, LOGE, FL("  session %d (P2P session %d) is invalid or listen is disabled "), 
=======
       smsLog(pMac, LOGE, FL("  session %d (P2P session %d) is invalid or listen is disabled "),
>>>>>>> d97af3b... add prima wlan driver
            p2pRemainonChn->sessionId, P2PsessionId);
       return eHAL_STATUS_FAILURE;
    }
#else
    if(!pSession->sessionActive) 
    {
<<<<<<< HEAD
       smsLog(pMac, LOGE, FL("  session %d is invalid or listen is disabled "), 
=======
       smsLog(pMac, LOGE, FL("  session %d is invalid or listen is disabled "),
>>>>>>> d97af3b... add prima wlan driver
            p2pRemainonChn->sessionId);
       return eHAL_STATUS_FAILURE;
    }
#endif
#ifdef WLAN_FEATURE_P2P_INTERNAL
    P2P_GetIE(p2pContext, 
              p2pContext->sessionId, eP2P_PROBE_RSP, 
              &p2pContext->probeRspIe, &ieLen);
    p2pContext->probeRspIeLength = ieLen;
    len = sizeof(tSirRemainOnChnReq) + ieLen;
#else
    len = sizeof(tSirRemainOnChnReq) + pMac->p2pContext.probeRspIeLength;
#endif

    status = palAllocateMemory(pMac->hHdd, (void**)&pMsg, len );
    if(HAL_STATUS_SUCCESS(status))
    {
<<<<<<< HEAD
        VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_INFO, "%s call\n", __FUNCTION__);
=======
        VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_INFO, "%s call", __func__);
>>>>>>> d97af3b... add prima wlan driver
        palZeroMemory(pMac->hHdd, pMsg, sizeof(tSirRemainOnChnReq));
        pMsg->messageType = eWNI_SME_REMAIN_ON_CHANNEL_REQ;
        pMsg->length = len;
        palCopyMemory( pMac, pMsg->selfMacAddr, pSession->selfMacAddr, sizeof(tSirMacAddr) ); 
        pMsg->chnNum = p2pRemainonChn->u.remainChlCmd.chn;
        pMsg->phyMode = p2pRemainonChn->u.remainChlCmd.phyMode;
        pMsg->duration = p2pRemainonChn->u.remainChlCmd.duration;
        pMsg->sessionId = p2pRemainonChn->sessionId;
<<<<<<< HEAD
=======
        pMsg->isProbeRequestAllowed = p2pRemainonChn->u.remainChlCmd.isP2PProbeReqAllowed;
>>>>>>> d97af3b... add prima wlan driver
#ifdef WLAN_FEATURE_P2P_INTERNAL
        pMsg->sessionId = pSession->sessionId;
        if( p2pContext->probeRspIeLength )
        {
            palCopyMemory(pMac->hHdd, (void *)pMsg->probeRspIe,
                         (void *)p2pContext->probeRspIe, 
                         p2pContext->probeRspIeLength);
        }
#else
        if( pMac->p2pContext.probeRspIeLength )
           palCopyMemory(pMac->hHdd, (void *)pMsg->probeRspIe, (void *)pMac->p2pContext.probeRspIe, pMac->p2pContext.probeRspIeLength);
#endif
        status = palSendMBMessage(pMac->hHdd, pMsg);
    }
    
    return status;
}


/*------------------------------------------------------------------
 *
 * handle LIM remain on channel rsp: Success/failure.
 *
 *------------------------------------------------------------------*/

eHalStatus sme_remainOnChnRsp( tpAniSirGlobal pMac, tANI_U8 *pMsg)
{
    eHalStatus                         status = eHAL_STATUS_SUCCESS;
    tListElem                          *pEntry = NULL;
    tSmeCmd                            *pCommand = NULL;

    pEntry = csrLLPeekHead(&pMac->sme.smeCmdActiveList, LL_ACCESS_LOCK);
    if( pEntry )
    {
        pCommand = GET_BASE_ADDR(pEntry, tSmeCmd, Link);
        if( eSmeCommandRemainOnChannel == pCommand->command )
        {
            remainOnChanCallback callback = pCommand->u.remainChlCmd.callback;
            /* process the msg */
            if( callback )
                callback(pMac, pCommand->u.remainChlCmd.callbackCtx, 0);
             
            if( csrLLRemoveEntry( &pMac->sme.smeCmdActiveList, pEntry, LL_ACCESS_LOCK ) )
            {
                //Now put this command back on the avilable command list
                smeReleaseCommand(pMac, pCommand);
            }
            smeProcessPendingQueue( pMac );
        }
    }
    return status;
}


/*------------------------------------------------------------------
 *
 * Handle the Mgmt frm ind from LIM and forward to HDD.
 *
 *------------------------------------------------------------------*/

eHalStatus sme_mgmtFrmInd( tHalHandle hHal, tpSirSmeMgmtFrameInd pSmeMgmtFrm)
{
    tpAniSirGlobal pMac = PMAC_STRUCT( hHal );
    eHalStatus  status = eHAL_STATUS_SUCCESS;
    tCsrRoamInfo pRoamInfo = {0};
#ifndef WLAN_FEATURE_P2P_INTERNAL
    tANI_U32 SessionId = pSmeMgmtFrm->sessionId;
#endif

#ifdef WLAN_FEATURE_P2P_INTERNAL
    tANI_U8 i;

    //For now, only action frames are needed.
    if(SIR_MAC_MGMT_ACTION == pSmeMgmtFrm->frameType)
    {
       pRoamInfo.nFrameLength = pSmeMgmtFrm->mesgLen - sizeof(tSirSmeMgmtFrameInd);
       pRoamInfo.pbFrames = pSmeMgmtFrm->frameBuf;
       pRoamInfo.frameType = pSmeMgmtFrm->frameType;
       pRoamInfo.rxChan   = pSmeMgmtFrm->rxChan;
<<<<<<< HEAD
=======
       pRoamInfo.rxRssi   = pSmeMgmtFrm->rxRssi;
>>>>>>> d97af3b... add prima wlan driver

       //Somehow we don't get the right sessionId.
       for(i = 0; i < CSR_ROAM_SESSION_MAX; i++)
       {
          if( CSR_IS_SESSION_VALID( pMac, i ) )
          {
              status = eHAL_STATUS_SUCCESS;
              /* forward the mgmt frame to all active sessions*/
              csrRoamCallCallback(pMac, i, &pRoamInfo, 0, eCSR_ROAM_INDICATE_MGMT_FRAME, 0);
          }
       }
    }
#else
    pRoamInfo.nFrameLength = pSmeMgmtFrm->mesgLen - sizeof(tSirSmeMgmtFrameInd);
    pRoamInfo.pbFrames = pSmeMgmtFrm->frameBuf;
    pRoamInfo.frameType = pSmeMgmtFrm->frameType;
    pRoamInfo.rxChan   = pSmeMgmtFrm->rxChan;
<<<<<<< HEAD
=======
    pRoamInfo.rxRssi   = pSmeMgmtFrm->rxRssi;
>>>>>>> d97af3b... add prima wlan driver

    /* forward the mgmt frame to HDD */
    csrRoamCallCallback(pMac, SessionId, &pRoamInfo, 0, eCSR_ROAM_INDICATE_MGMT_FRAME, 0);
#endif

    return status;
}


/*------------------------------------------------------------------
 *
 * Handle the remain on channel ready indication from PE
 *
 *------------------------------------------------------------------*/

eHalStatus sme_remainOnChnReady( tHalHandle hHal, tANI_U8* pMsg)
{
    tpAniSirGlobal pMac = PMAC_STRUCT( hHal );
    eHalStatus  status = eHAL_STATUS_SUCCESS;
    tListElem *pEntry = NULL;
    tSmeCmd *pCommand = NULL;
    tCsrRoamInfo RoamInfo; 
#ifdef WLAN_FEATURE_P2P_INTERNAL
    tSirSmeRsp *pRsp = (tSirSmeRsp *)pMsg;
    //pRsp->sessionId is SME's session index
    tANI_U8  P2PSessionID = getP2PSessionIdFromSMESessionId(pMac, pRsp->sessionId);

    if(CSR_SESSION_ID_INVALID == P2PSessionID)
    {
       return eHAL_STATUS_FAILURE;
    }
#endif

    pEntry = csrLLPeekHead(&pMac->sme.smeCmdActiveList, LL_ACCESS_LOCK);
    if( pEntry )
    {
        pCommand = GET_BASE_ADDR(pEntry, tSmeCmd, Link);
        if( eSmeCommandRemainOnChannel == pCommand->command )
        {

#ifdef WLAN_FEATURE_P2P_INTERNAL
            if (pMac->p2pContext[P2PSessionID].PeerFound)
            {
                p2pRemainOnChannelReadyCallback(pMac, &pMac->p2pContext[P2PSessionID], eHAL_STATUS_SUCCESS);
            }
#else
            /* forward the indication to HDD */
            RoamInfo.pRemainCtx = pCommand->u.remainChlCmd.callbackCtx;
            csrRoamCallCallback(pMac, ((tSirSmeRsp*)pMsg)->sessionId, &RoamInfo, 
                                0, eCSR_ROAM_REMAIN_CHAN_READY, 0);
#endif
        }
    }
  
    return status;
}


eHalStatus sme_sendActionCnf( tHalHandle hHal, tANI_U8* pMsg)
{
   tpAniSirGlobal pMac = PMAC_STRUCT( hHal );
   eHalStatus  status = eHAL_STATUS_SUCCESS;
   tCsrRoamInfo RoamInfo;
   tSirSmeRsp* pSmeRsp = (tSirSmeRsp*)pMsg;

#ifdef WLAN_FEATURE_P2P_INTERNAL
   tSirResultCodes rspStatus = pSmeRsp->statusCode;
   tANI_U8 HDDsessionId = getP2PSessionIdFromSMESessionId(pMac, pSmeRsp->sessionId);
   tANI_U8 *pBuf = NULL;
   tp2pContext *pP2pContext;

   if(CSR_SESSION_ID_INVALID == HDDsessionId)
   {
      VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_ERROR,
<<<<<<< HEAD
         " %s fail to get HDD sessionID (SMESessionID %d)", __FUNCTION__, pSmeRsp->sessionId);
=======
         " %s fail to get HDD sessionID (SMESessionID %d)", __func__, pSmeRsp->sessionId);
>>>>>>> d97af3b... add prima wlan driver
      return eHAL_STATUS_INVALID_PARAMETER;
   }

   pP2pContext = &pMac->p2pContext[HDDsessionId];

<<<<<<< HEAD
   VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_INFO, "%s status %d Action Frame %d actionFrameTimeout %d\n", 
         __FUNCTION__, pSmeRsp->statusCode, pP2pContext->actionFrameType
=======
   VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_INFO, "%s status %d Action Frame %d actionFrameTimeout %d",
         __func__, pSmeRsp->statusCode, pP2pContext->actionFrameType
>>>>>>> d97af3b... add prima wlan driver
         , pP2pContext->actionFrameTimeout);
   vos_mem_zero(&RoamInfo, sizeof(tCsrRoamInfo));

   if (pSmeRsp->statusCode != eSIR_SME_SUCCESS && !pP2pContext->actionFrameTimeout
         && pP2pContext->pSentActionFrame)
   {
<<<<<<< HEAD
      VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_INFO, "%s Action frame:Ack not received. Retransmitting\n", __FUNCTION__);

      if(NULL == pP2pContext->pNextActionFrm)
      {
         status = palTimerStart(pMac->hHdd, pP2pContext->retryActionFrameTimer, 
                        ACTION_FRAME_RETRY_TIMEOUT * PAL_TIMER_TO_MS_UNIT, eANI_BOOLEAN_FALSE);
         if (!HAL_STATUS_SUCCESS(status))
         {
            smsLog(pMac, LOGE, " %s fail to start retryActionFrameTimerHandler\n", 
               __FUNCTION__, pP2pContext->NextActionFrameType);
=======
      VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_INFO, "%s Action frame:Ack not received. Retransmitting", __func__);

      if(NULL == pP2pContext->pNextActionFrm)
      {
         status = vos_timer_start(&pP2pContext->retryActionFrameTimer, ACTION_FRAME_RETRY_TIMEOUT);
         if (!VOS_IS_STATUS_SUCCESS(status))
         {
            smsLog(pMac, LOGE, " %s fail to start retryActionFrameTimerHandler",
               __func__, pP2pContext->NextActionFrameType);
>>>>>>> d97af3b... add prima wlan driver
         }
         return status;
      }
      //In case if there is new frame to send, finish the current frame
      else
      {
         smsLog(pMac, LOGE, " %s send next action frame type %d Last frame status (%d)",
<<<<<<< HEAD
            __FUNCTION__, rspStatus);
=======
            __func__, rspStatus);
>>>>>>> d97af3b... add prima wlan driver
         //Force it to be success
         rspStatus = eSIR_SME_SUCCESS;
      }
   }

   if (pP2pContext->actionFrameTimer)
   {
<<<<<<< HEAD
      status = palTimerStop(pMac, pP2pContext->actionFrameTimer);
=======
      vos_timer_stop(&pP2pContext->actionFrameTimer);
      status = eHAL_STATUS_SUCCESS;
>>>>>>> d97af3b... add prima wlan driver
   }

   if (pP2pContext->retryActionFrameTimer)
   {
<<<<<<< HEAD
      status = palTimerStop(pMac, pP2pContext->retryActionFrameTimer);
=======
      vos_timer_stop(&pP2pContext->retryActionFrameTimer);
      status = eHAL_STATUS_SUCCESS;
>>>>>>> d97af3b... add prima wlan driver
   }

   if(pP2pContext->pSentActionFrame)
   {
      csrRoamCallCallback((tpAniSirGlobal)pP2pContext->hHal, 
                     pP2pContext->SMEsessionId, &RoamInfo, 0, 
                     eCSR_ROAM_SEND_ACTION_CNF, 
                     ((rspStatus == eSIR_SME_SUCCESS) ? 
                     eCSR_ROAM_RESULT_NONE: eCSR_ROAM_RESULT_SEND_ACTION_FAIL));
   }

   if(VOS_IS_STATUS_SUCCESS(vos_spin_lock_acquire(&pP2pContext->lState)))
   {
      if(pP2pContext->pSentActionFrame)
      {
         pBuf = pP2pContext->pSentActionFrame;
         pP2pContext->pSentActionFrame = NULL;
      }
      vos_spin_lock_release(&pP2pContext->lState);

      if(NULL != pBuf)
      {
         vos_mem_free(pBuf);
         pBuf = NULL;
      }
      else
      {
<<<<<<< HEAD
         VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_WARN, "%s pSentActionFrame is null \n", __FUNCTION__);
=======
         VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_WARN, "%s pSentActionFrame is null ", __func__);
>>>>>>> d97af3b... add prima wlan driver
      }
      if(pP2pContext->pNextActionFrm)
      {
         //need to send the next action frame
         pP2pContext->pSentActionFrame = pP2pContext->pNextActionFrm;
         pP2pContext->ActionFrameLen = pP2pContext->nNextFrmLen;
         pP2pContext->actionFrameType = pP2pContext->NextActionFrameType;
         pP2pContext->pNextActionFrm = NULL;
         pP2pContext->ActionFrameSendTimeout = pP2pContext->nNextFrameTimeOut;
      }
   }
   else
   {
<<<<<<< HEAD
      VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_ERROR, "%s cannot get lock1", __FUNCTION__);
=======
      VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_ERROR, "%s cannot get lock1", __func__);
>>>>>>> d97af3b... add prima wlan driver
   }

   if(NULL != pP2pContext->pSentActionFrame)
   {
<<<<<<< HEAD
      VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_INFO, " sending next frame %d type\n", 
                  pP2pContext->NextActionFrameType);
      status = palTimerStart(pMac->hHdd, pP2pContext->actionFrameTimer, 
                        pP2pContext->ActionFrameSendTimeout * PAL_TIMER_TO_MS_UNIT, eANI_BOOLEAN_FALSE);
      if (!HAL_STATUS_SUCCESS(status))
      {
         smsLog(pMac, LOGE, FL(" %s fail to start timer status %d"), __FUNCTION__, status);
=======
      VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_INFO, " sending next frame %d type",
                  pP2pContext->NextActionFrameType);
      status = vos_timer_start(&pP2pContext->actionFrameTimer, pP2pContext->ActionFrameSendTimeout);
      if (!VOS_IS_STATUS_SUCCESS(status))
      {
         smsLog(pMac, LOGE, FL(" %s fail to start timer status %d"), __func__, status);
>>>>>>> d97af3b... add prima wlan driver
         //Without the timer we cannot continue
         csrRoamCallCallback((tpAniSirGlobal)pP2pContext->hHal, 
                     pP2pContext->SMEsessionId, &RoamInfo, 0, 
                     eCSR_ROAM_SEND_ACTION_CNF, 
                     eCSR_ROAM_RESULT_SEND_ACTION_FAIL);
         vos_spin_lock_acquire(&pP2pContext->lState);
         pBuf = pP2pContext->pSentActionFrame;
         pP2pContext->pSentActionFrame = NULL;
         vos_spin_lock_release(&pP2pContext->lState);
         vos_mem_free(pBuf);
         pBuf = NULL;
         p2pFsm(pP2pContext, eP2P_TRIGGER_DISCONNECTED);
         return status;
      }
      status = p2pSendActionFrame(pMac, pP2pContext->sessionId, pP2pContext->actionFrameType);
      if(!HAL_STATUS_SUCCESS(status))
      {
<<<<<<< HEAD
         VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_ERROR, " sending next frame %d type\n", 
                  pP2pContext->NextActionFrameType);
         status = palTimerStart(pMac->hHdd, pP2pContext->retryActionFrameTimer, 
                     ACTION_FRAME_RETRY_TIMEOUT * PAL_TIMER_TO_MS_UNIT, eANI_BOOLEAN_FALSE);
         if (!HAL_STATUS_SUCCESS(status))
         {
            smsLog(pMac, LOGE, " %s fail to start retryActionFrameTimerHandler\n", __FUNCTION__);
=======
         VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_ERROR, " sending next frame %d type",
                  pP2pContext->NextActionFrameType);
         status = vos_timer_start(&pP2pContext->retryActionFrameTimer, ACTION_FRAME_RETRY_TIMEOUT);
         if (!VOS_IS_STATUS_SUCCESS(status))
         {
            smsLog(pMac, LOGE, " %s fail to start retryActionFrameTimerHandler", __func__);
>>>>>>> d97af3b... add prima wlan driver
         }
      }
   }
   else
   {
      p2pFsm(pP2pContext, eP2P_TRIGGER_DISCONNECTED);
   }
    
#else  
    /* forward the indication to HDD */
    //RoamInfo can be passed as NULL....todo
    csrRoamCallCallback(pMac, pSmeRsp->sessionId, &RoamInfo, 0, 
                        eCSR_ROAM_SEND_ACTION_CNF, 
                       (pSmeRsp->statusCode == eSIR_SME_SUCCESS) ? 0:
                        eCSR_ROAM_RESULT_SEND_ACTION_FAIL);
#endif    
    return status;
}


#ifdef WLAN_FEATURE_P2P_INTERNAL
void p2pResetContext(tp2pContext *pP2pContext)
{
   if(NULL != pP2pContext)
   {
      tpAniSirGlobal pMac = PMAC_STRUCT(pP2pContext->hHal);
      int i;

      //When it is resetting a GO or client session, we
      //need to reset the group capability back to the original one
      if( (OPERATION_MODE_P2P_GROUP_OWNER == pP2pContext->operatingmode) ||
         (OPERATION_MODE_P2P_CLIENT == pP2pContext->operatingmode) )
      {
         for( i = 0; i < MAX_NO_OF_P2P_SESSIONS; i++ )
         {
            if(OPERATION_MODE_P2P_DEVICE == pMac->p2pContext[i].operatingmode)
            {
               gP2PIe[i].p2pCapabilityAttrib.groupCapability = pMac->p2pContext[i].OriginalGroupCapability;
            }
         }
      }

      pP2pContext->state = eP2P_STATE_DISCONNECTED;
      pP2pContext->currentSearchIndex = 0;
      pP2pContext->listenIndex = 1;

      pP2pContext->actionFrameType = eP2P_INVALID_FRM;

      pP2pContext->dialogToken = 0;
      pP2pContext->PeerFound = FALSE;
      pP2pContext->GroupFormationPending = FALSE;
      pP2pContext->directedDiscovery = FALSE;
      pP2pContext->listenDiscoverableState = eStateDisabled;


      if(pP2pContext->pSentActionFrame)
      {
         vos_mem_free(pP2pContext->pSentActionFrame);
         pP2pContext->pSentActionFrame = NULL;
      }
      if(pP2pContext->pNextActionFrm)
      {
         vos_mem_free(pP2pContext->pSentActionFrame);
         pP2pContext->pSentActionFrame = NULL;
      }      
      if( pP2pContext->probeRspIe )
      {
         vos_mem_free( pP2pContext->probeRspIe );
         pP2pContext->probeRspIe = NULL;
         pP2pContext->probeRspIeLength = 0;
      }

      if( pP2pContext->DiscoverReqIeField )
      {
         vos_mem_free(pP2pContext->DiscoverReqIeField );
         pP2pContext->DiscoverReqIeField = NULL;
         pP2pContext->DiscoverReqIeLength = 0;
      }

      if( pP2pContext->GoNegoCnfIeField )
      {
         vos_mem_free( pP2pContext->GoNegoCnfIeField);
         pP2pContext->GoNegoCnfIeField = NULL;
         pP2pContext->GoNegoCnfIeLength = 0;
      }

      if( pP2pContext->GoNegoReqIeField )
      {
         vos_mem_free( pP2pContext->GoNegoReqIeField );
         pP2pContext->GoNegoReqIeField = NULL;
         pP2pContext->GoNegoReqIeLength = 0;
      }

      if( pP2pContext->GoNegoResIeField )
      {
         vos_mem_free( pP2pContext->GoNegoResIeField );
         pP2pContext->GoNegoResIeField = NULL;
         pP2pContext->GoNegoResIeLength = 0;
      }

      if( pP2pContext->ProvDiscReqIeField )
      {
         vos_mem_free( pP2pContext->ProvDiscReqIeField );
         pP2pContext->ProvDiscReqIeField = NULL;
         pP2pContext->ProvDiscReqIeLength = 0;
      }

      if( pP2pContext->ProvDiscResIeField )
      {
         vos_mem_free( pP2pContext->ProvDiscResIeField );
         pP2pContext->ProvDiscResIeLength = 0;
         pP2pContext->ProvDiscResIeField = NULL;
      }

      if (pP2pContext->actionFrameTimer)
      {
<<<<<<< HEAD
         palTimerStop(pMac->hHdd, pP2pContext->actionFrameTimer);
=======
         vos_timer_stop(&pP2pContext->actionFrameTimer);
>>>>>>> d97af3b... add prima wlan driver
      }

      if (pP2pContext->discoverTimer)
      {
<<<<<<< HEAD
         palTimerStop(pMac->hHdd, pP2pContext->discoverTimer);
=======
         vos_timer_stop(&pP2pContext->discoverTimer);
>>>>>>> d97af3b... add prima wlan driver
      }

      if (pP2pContext->listenTimerHandler)
      {
<<<<<<< HEAD
         palTimerStop(pMac->hHdd, pP2pContext->listenTimerHandler);
=======
         vos_timer_stop(&pP2pContext->listenTimerHandler);
>>>>>>> d97af3b... add prima wlan driver
      }

      if (pP2pContext->WPSRegistrarCheckTimerHandler)
      {
<<<<<<< HEAD
         palTimerStop(pMac->hHdd, pP2pContext->WPSRegistrarCheckTimerHandler);
=======
         vos_timer_stop(&pP2pContext->WPSRegistrarCheckTimerHandler);
>>>>>>> d97af3b... add prima wlan driver
      }

      if (pP2pContext->directedDiscoveryFilter)
      {
         pP2pContext->uNumDeviceFilterAllocated = 0;
         vos_mem_free(pP2pContext->directedDiscoveryFilter);
         pP2pContext->directedDiscoveryFilter = NULL;
      }

      vos_mem_zero(pP2pContext->peerMacAddress, P2P_MAC_ADDRESS_LEN);
   }
}
#endif    


eHalStatus sme_p2pOpen( tHalHandle hHal )
{
   tpAniSirGlobal pMac = PMAC_STRUCT(hHal);
   eHalStatus status = eHAL_STATUS_SUCCESS;

#ifdef WLAN_FEATURE_P2P_INTERNAL
   int i;
   tp2pContext *pP2pContext;

   for ( i=0; i < MAX_NO_OF_P2P_SESSIONS; i++ ) 
   {
      pP2pContext = &pMac->p2pContext[i];
      pP2pContext->hHal = hHal;

      pP2pContext->socialChannel[0] = 1;
      pP2pContext->socialChannel[1] = 6;
      pP2pContext->socialChannel[2] = 11;

      vos_spin_lock_init(&pP2pContext->lState);

      p2pResetContext(pP2pContext);

<<<<<<< HEAD
      status = palTimerAlloc(pMac->hHdd, &pP2pContext->actionFrameTimer, 
                                    p2pActionFrameTimerHandler, pP2pContext);
      if (!HAL_STATUS_SUCCESS(status))
      {
         smsLog(pMac, LOGE, " %s fail to alloc actionFrame timer for session %d\n", __FUNCTION__, i);
         break;
      }
      status = palTimerAlloc(pMac->hHdd, &pP2pContext->listenTimerHandler, 
                              p2pListenDiscoverTimerHandler, pP2pContext);
      if (!HAL_STATUS_SUCCESS(status))
      {
         smsLog(pMac, LOGE, " %s fail to alloc listen timer for session %d\n", __FUNCTION__, i);
         break;
      } 
      status = palTimerAlloc(pMac->hHdd, &pP2pContext->discoverTimer, p2pDiscoverTimerHandler, pP2pContext);
      if (!HAL_STATUS_SUCCESS(status))
      {
         smsLog(pMac, LOGE, " %s fail to alloc discover timer for session %d\n", __FUNCTION__, i);
         break;
      }

      status = palTimerAlloc(pMac->hHdd, &pP2pContext->retryActionFrameTimer, 
                     p2pRetryActionFrameTimerHandler, pP2pContext);
      if (!HAL_STATUS_SUCCESS(status))
      {
         smsLog(pMac, LOGE, " %s fail to alloc retryActionFrameTimerHandler timer for session %d\n", __FUNCTION__, i);
=======
      status = vos_timer_init(&pP2pContext->actionFrameTimer, VOS_TIMER_TYPE_SW, p2pActionFrameTimerHandler, pP2pContext);
      if (!VOS_IS_STATUS_SUCCESS(status))
      {
         smsLog(pMac, LOGE, " %s fail to alloc actionFrame timer for session %d", __func__, i);
         break;
      }
      status = vos_timer_init(&pP2pContext->listenTimerHandler, VOS_TIMER_TYPE_SW,
                                        p2pListenDiscoverTimerHandler, pP2pContext);
      if (!VOS_IS_STATUS_SUCCESS(status))
      {
         smsLog(pMac, LOGE, " %s fail to alloc listen timer for session %d", __func__, i);
         break;
      } 
      status = vos_timer_init(&pP2pContext->discoverTimer, VOS_TIMER_TYPE_SW, p2pDiscoverTimerHandler, pP2pContext);
      if (!VOS_IS_STATUS_SUCCESS(status))
      {
         smsLog(pMac, LOGE, " %s fail to alloc discover timer for session %d", __func__, i);
         break;
      }

      status = vos_timer_init(&pP2pContext->retryActionFrameTimer, VOS_TIMER_TYPE_SW,
                     p2pRetryActionFrameTimerHandler, pP2pContext);
      if (!VOS_IS_STATUS_SUCCESS(status))
      {
         smsLog(pMac, LOGE, " %s fail to alloc retryActionFrameTimerHandler timer for session %d", __func__, i);
>>>>>>> d97af3b... add prima wlan driver
         break;
      }

      p2pCreateDefaultIEs(hHal, i);
   }
#else
   //If static structure is too big, Need to change this function to allocate memory dynamically
   vos_mem_zero( &pMac->p2pContext, sizeof( tp2pContext ) );
#endif

   if(!HAL_STATUS_SUCCESS(status))
   {
      sme_p2pClose(hHal);
    }

   return status;
}


eHalStatus p2pStop( tHalHandle hHal )
{
   tpAniSirGlobal pMac = PMAC_STRUCT(hHal);

#ifdef WLAN_FEATURE_P2P_INTERNAL
   int i;

   for ( i = 0; i < MAX_NO_OF_P2P_SESSIONS; i++ ) 
   {
      p2pCloseSession(pMac, i);
   }
#else  
   if( pMac->p2pContext.probeRspIe )
   {
      vos_mem_free( pMac->p2pContext.probeRspIe );
      pMac->p2pContext.probeRspIe = NULL;
   }
  
   pMac->p2pContext.probeRspIeLength = 0;
#endif

   return eHAL_STATUS_SUCCESS;
}


eHalStatus sme_p2pClose( tHalHandle hHal )
{
   tpAniSirGlobal pMac = PMAC_STRUCT(hHal);

#ifdef WLAN_FEATURE_P2P_INTERNAL
   tp2pContext *pContext;
   int i;

   p2pStop(hHal);

   for ( i = 0; i < MAX_NO_OF_P2P_SESSIONS; i++ ) 
   {
      p2pCloseSession(pMac, i);
      pContext = &pMac->p2pContext[i];
      if (pContext->actionFrameTimer)
      {
<<<<<<< HEAD
         palTimerFree(hHal, pContext->actionFrameTimer);
=======
         vos_timer_destroy(&pContext->actionFrameTimer);
>>>>>>> d97af3b... add prima wlan driver
         pContext->actionFrameTimer = NULL;
      }

      if (pContext->discoverTimer)
      {
<<<<<<< HEAD
         palTimerFree(hHal, pContext->discoverTimer);
=======
         vos_timer_destroy(&pContext->discoverTimer);
>>>>>>> d97af3b... add prima wlan driver
         pContext->discoverTimer = NULL;
      }

      if (pContext->listenTimerHandler)
      {
<<<<<<< HEAD
         palTimerFree(hHal, pContext->listenTimerHandler);
=======
         vos_timer_destroy(&pContext->listenTimerHandler);
>>>>>>> d97af3b... add prima wlan driver
         pContext->listenTimerHandler = NULL;
      }

      if (pContext->WPSRegistrarCheckTimerHandler)
      {
<<<<<<< HEAD
         palTimerFree(hHal, pContext->WPSRegistrarCheckTimerHandler);
=======
         vos_timer_destroy(&pContext->WPSRegistrarCheckTimerHandler);
>>>>>>> d97af3b... add prima wlan driver
         pContext->WPSRegistrarCheckTimerHandler = NULL;
      }

      vos_spin_lock_destroy(&pContext->lState);
   }
#else  
    if( pMac->p2pContext.probeRspIe )
    {
        vos_mem_free( pMac->p2pContext.probeRspIe );
        pMac->p2pContext.probeRspIe = NULL;
    }
  
    pMac->p2pContext.probeRspIeLength = 0;
#endif

   return eHAL_STATUS_SUCCESS;
}


tSirRFBand GetRFBand(tANI_U8 channel)
{
    if ((channel >= SIR_11A_CHANNEL_BEGIN) &&
        (channel <= SIR_11A_CHANNEL_END))
        return SIR_BAND_5_GHZ;

    if ((channel >= SIR_11B_CHANNEL_BEGIN) &&
        (channel <= SIR_11B_CHANNEL_END))
        return SIR_BAND_2_4_GHZ;

    return SIR_BAND_UNKNOWN;
}

/* ---------------------------------------------------------------------------

    \fn p2pRemainOnChannel
    \brief  API to post the remain on channel command.
    \param  hHal - The handle returned by macOpen.
    \param  sessinId - HDD session ID.
    \param  channel - Channel to remain on channel.
    \param  duration - Duration for which we should remain on channel
    \param  callback - callback function.
    \param  pContext - argument to the callback function
    \return eHalStatus

  -------------------------------------------------------------------------------*/
eHalStatus p2pRemainOnChannel(tHalHandle hHal, tANI_U8 sessionId,
         tANI_U8 channel, tANI_U32 duration,
        remainOnChanCallback callback, 
<<<<<<< HEAD
        void *pContext
=======
        void *pContext, tANI_U8 isP2PProbeReqAllowed
>>>>>>> d97af3b... add prima wlan driver
#ifdef WLAN_FEATURE_P2P_INTERNAL
        , eP2PRemainOnChnReason reason
#endif
        )
{
    eHalStatus status = eHAL_STATUS_SUCCESS;
    tpAniSirGlobal pMac = PMAC_STRUCT(hHal);
    tSmeCmd *pRemainChlCmd = NULL;
    tANI_U32 phyMode;
  
    pRemainChlCmd = smeGetCommandBuffer(pMac);
    if(pRemainChlCmd == NULL)
        return eHAL_STATUS_FAILURE;
  
    if (SIR_BAND_5_GHZ == GetRFBand(channel))
    {
       phyMode = WNI_CFG_PHY_MODE_11A;
    }
    else
    {
       phyMode = WNI_CFG_PHY_MODE_11G;
    }
    
    cfgSetInt(pMac, WNI_CFG_PHY_MODE, phyMode);

    do
    {
        /* call set in context */
        pRemainChlCmd->command = eSmeCommandRemainOnChannel;
        pRemainChlCmd->sessionId = sessionId;
        pRemainChlCmd->u.remainChlCmd.chn = channel;
        pRemainChlCmd->u.remainChlCmd.duration = duration;
<<<<<<< HEAD
=======
        pRemainChlCmd->u.remainChlCmd.isP2PProbeReqAllowed = isP2PProbeReqAllowed;
>>>>>>> d97af3b... add prima wlan driver
        pRemainChlCmd->u.remainChlCmd.callback = callback;
        pRemainChlCmd->u.remainChlCmd.callbackCtx = pContext;
    
        //Put it at the head of the Q if we just finish finding the peer and ready to send a frame
#ifdef WLAN_FEATURE_P2P_INTERNAL
        smePushCommand(pMac, pRemainChlCmd, (eP2PRemainOnChnReasonSendFrame == reason));
#else
        csrQueueSmeCommand(pMac, pRemainChlCmd, eANI_BOOLEAN_FALSE);
#endif
    } while(0);
  
<<<<<<< HEAD
    smsLog(pMac, LOGW, "exiting function %s\n", __FUNCTION__);
=======
    smsLog(pMac, LOGW, "exiting function %s", __func__);
>>>>>>> d97af3b... add prima wlan driver
  
    return(status);
}

eHalStatus p2pSendAction(tHalHandle hHal, tANI_U8 sessionId,
         const tANI_U8 *pBuf, tANI_U32 len, tANI_U16 wait, tANI_BOOLEAN noack)
{
    eHalStatus status = eHAL_STATUS_SUCCESS;
    tpAniSirGlobal pMac = PMAC_STRUCT(hHal);
    tSirMbMsgP2p *pMsg;
    tANI_U16 msgLen;

    VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_INFO_MED,
<<<<<<< HEAD
       " %s sends action frame", __FUNCTION__);
=======
       " %s sends action frame", __func__);
>>>>>>> d97af3b... add prima wlan driver
    msgLen = (tANI_U16)((sizeof( tSirMbMsg )) + len);
    status = palAllocateMemory(pMac->hHdd, (void **)&pMsg, msgLen);
    if(HAL_STATUS_SUCCESS(status))
    {
        palZeroMemory(pMac->hHdd, (void *)pMsg, msgLen);
        pMsg->type = pal_cpu_to_be16((tANI_U16)eWNI_SME_SEND_ACTION_FRAME_IND);
        pMsg->msgLen = pal_cpu_to_be16(msgLen);
        pMsg->sessionId = sessionId;
        pMsg->noack = noack;
        pMsg->wait = (tANI_U16)wait;
        palCopyMemory( pMac->hHdd, pMsg->data, pBuf, len );
        status = palSendMBMessage(pMac->hHdd, pMsg);
    }

    return( status );
}

eHalStatus p2pCancelRemainOnChannel(tHalHandle hHal, tANI_U8 sessionId)
{
    eHalStatus status = eHAL_STATUS_SUCCESS;
    tpAniSirGlobal pMac = PMAC_STRUCT(hHal);
    tSirMbMsg *pMsg;
    tANI_U16 msgLen;

    //Need to check session ID to support concurrency

    msgLen = (tANI_U16)(sizeof( tSirMbMsg ));
    status = palAllocateMemory(pMac->hHdd, (void **)&pMsg, msgLen);
    if(HAL_STATUS_SUCCESS(status))
    {
        palZeroMemory(pMac->hHdd, (void *)pMsg, msgLen);
        pMsg->type = pal_cpu_to_be16((tANI_U16)eWNI_SME_ABORT_REMAIN_ON_CHAN_IND);
        pMsg->msgLen = pal_cpu_to_be16(msgLen);
        status = palSendMBMessage(pMac->hHdd, pMsg);
    }                             

    return( status );
}

eHalStatus p2pSetPs(tHalHandle hHal, tP2pPsConfig *pNoA)
{
    tpP2pPsConfig pNoAParam;
    tSirMsgQ msg;
    eHalStatus status = eHAL_STATUS_SUCCESS;
    tpAniSirGlobal pMac = PMAC_STRUCT( hHal );

    status = palAllocateMemory(pMac->hHdd, (void**)&pNoAParam, sizeof(tP2pPsConfig));
    if(HAL_STATUS_SUCCESS(status))
    {
        palZeroMemory(pMac->hHdd, pNoAParam, sizeof(tP2pPsConfig));
        palCopyMemory(pMac->hHdd, pNoAParam, pNoA, sizeof(tP2pPsConfig)); 
        msg.type = eWNI_SME_UPDATE_NOA;
        msg.bodyval = 0;
        msg.bodyptr = pNoAParam;
        limPostMsgApi(pMac, &msg);
    }   
    return status;
}

#ifdef WLAN_FEATURE_P2P_INTERNAL
eHalStatus p2pGetConfigParam(tHalHandle hHal, tP2PConfigParam *pParam)
{
   eHalStatus status = eHAL_STATUS_INVALID_PARAMETER;
   tpAniSirGlobal pMac = PMAC_STRUCT(hHal);

   if(pParam)
   {
      pParam->P2PListenChannel = pMac->p2pContext[0].P2PListenChannel;
      pParam->P2POperatingChannel = pMac->p2pContext[0].P2POperatingChannel;
      pParam->P2POpPSCTWindow = pMac->p2pContext[0].pNoA.ctWindow;
      pParam->P2PPSSelection = pMac->p2pContext[0].pNoA.psSelection;
      pParam->P2POpPSCTWindow = pMac->p2pContext[0].pNoA.ctWindow;
      pParam->P2PNoADuration = pMac->p2pContext[0].pNoA.duration;
      pParam->P2PNoACount = pMac->p2pContext[0].pNoA.count;
      pParam->P2PNoAInterval = pMac->p2pContext[0].pNoA.interval;

      status = eHAL_STATUS_SUCCESS;
   }

   return (status);
}

eHalStatus p2pChangeDefaultConfigParam(tHalHandle hHal, tP2PConfigParam *pParam)
{
    eHalStatus status = eHAL_STATUS_SUCCESS;
    tpAniSirGlobal pMac = PMAC_STRUCT(hHal);

   int i;
   tANI_U8 pBuf[P2P_COUNTRY_CODE_LEN];
   tANI_U8 uBufLen = P2P_COUNTRY_CODE_LEN;
   tP2P_OperatingChannel p2pChannel;

   status = sme_GetCountryCode( pMac, pBuf, &uBufLen );
   if ( !HAL_STATUS_SUCCESS( status ) )
   {
      status = eHAL_STATUS_FAILURE;
<<<<<<< HEAD
      VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_ERROR, "%s Cannot get the country code\n", __FUNCTION__);
=======
      VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_ERROR, "%s Cannot get the country code", __func__);
>>>>>>> d97af3b... add prima wlan driver
   }

   vos_mem_copy(p2pChannel.countryString, pBuf, sizeof(pBuf));
   p2pChannel.regulatoryClass = 0x51;

   if(pParam)
   {
      for ( i=0; i < MAX_NO_OF_P2P_SESSIONS; i++ ) 
      {
         if (pParam->P2PListenChannel == 1 || pParam->P2PListenChannel == 6 
               || pParam->P2PListenChannel == 11)
         {
            pMac->p2pContext[i].P2PListenChannel = pParam->P2PListenChannel;
         }
         else
         {
            pMac->p2pContext[i].P2PListenChannel = P2P_OPERATING_CHANNEL;
            VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_INFO_HIGH, 
<<<<<<< HEAD
               "Invalid P2P Listen Channel in config. Switch to default Listen Channel %d\n",
               __FUNCTION__, P2P_OPERATING_CHANNEL);
=======
               "Invalid P2P Listen Channel in config. Switch to default Listen Channel %d",
               __func__, P2P_OPERATING_CHANNEL);
>>>>>>> d97af3b... add prima wlan driver
         }
         
         if(csrRoamIsChannelValid(pMac, pParam->P2POperatingChannel))
         {
            pMac->p2pContext[i].P2POperatingChannel = pParam->P2POperatingChannel;
         }
         else
         {
            pMac->p2pContext[i].P2POperatingChannel = P2P_OPERATING_CHANNEL;
<<<<<<< HEAD
            VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_INFO_HIGH, 
               "Invalid P2P Operating Channel in config. Switch to default Channel %d\n", 
               __FUNCTION__, P2P_OPERATING_CHANNEL);
=======
            VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_INFO_HIGH,
               "Invalid P2P Operating Channel in config. Switch to default Channel %d",
               __func__, P2P_OPERATING_CHANNEL);
>>>>>>> d97af3b... add prima wlan driver
         }
         pMac->p2pContext[i].pNoA.ctWindow = pParam->P2POpPSCTWindow;
         pMac->p2pContext[i].pNoA.psSelection = pParam->P2PPSSelection;
         pMac->p2pContext[i].pNoA.ctWindow = pParam->P2POpPSCTWindow;
         pMac->p2pContext[i].pNoA.duration = pParam->P2PNoADuration;
         pMac->p2pContext[i].pNoA.count = pParam->P2PNoACount;
         pMac->p2pContext[i].pNoA.interval = pParam->P2PNoAInterval;

         p2pChannel.channel = pMac->p2pContext[i].P2POperatingChannel;
         P2P_UpdateIE(pMac, i, eWFD_OPERATING_CHANNEL, &p2pChannel, 1);
         p2pChannel.channel = pMac->p2pContext[i].P2PListenChannel;
         P2P_UpdateIE(pMac, i, eWFD_LISTEN_CHANNEL, &p2pChannel, 1);
      }
   }

    return status;
}

eHalStatus p2pPS(tHalHandle hHal, tANI_U8 sessionId)
{
   eHalStatus status = eHAL_STATUS_SUCCESS;
   tpAniSirGlobal pMac = PMAC_STRUCT(hHal);
   tP2pPsConfig pNoA;

   /* call set in context */
   pNoA.psSelection = pMac->p2pContext[sessionId].pNoA.psSelection;
   pNoA.sessionid = sessionId;

   if (pMac->p2pContext[sessionId].pNoA.psSelection == P2P_CLEAR_POWERSAVE)
   {
      return status;
   }

   if (pMac->p2pContext[sessionId].pNoA.psSelection == P2P_OPPORTUNISTIC_PS)
   {
      pNoA.opp_ps = TRUE;
      pNoA.ctWindow = pMac->p2pContext[sessionId].pNoA.ctWindow;
      pNoA.count = 0;
      pNoA.duration = 0;
      pNoA.interval = 0; 
      pNoA.single_noa_duration = 0;
   }
   else if (pMac->p2pContext[sessionId].pNoA.psSelection == P2P_PERIODIC_NOA)
   {
      pNoA.opp_ps = 0;
      pNoA.ctWindow = 0;
      pNoA.count = pMac->p2pContext[sessionId].pNoA.count;
      pNoA.duration = pMac->p2pContext[sessionId].pNoA.duration;
      pNoA.interval = pMac->p2pContext[sessionId].pNoA.interval; 
      pNoA.single_noa_duration = 0;
   } 
   else if(pMac->p2pContext[sessionId].pNoA.psSelection == P2P_SINGLE_NOA)
   {
      pNoA.opp_ps = 0;
      pNoA.ctWindow = 0;
      pNoA.count = 0;
      pNoA.duration = 0;
      pNoA.interval = 0; 
      pNoA.single_noa_duration = pMac->p2pContext[sessionId].pNoA.duration;
   }

   VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_INFO_MED, 
      " %s HDDSession %d set NoA parameters. Selection %d, opp_ps %d, ctWindow %d, count %d, "
      "duration %d, interval %d single NoA duration %d",
<<<<<<< HEAD
      __FUNCTION__, sessionId, pMac->p2pContext[sessionId].pNoA.psSelection,
=======
      __func__, sessionId, pMac->p2pContext[sessionId].pNoA.psSelection,
>>>>>>> d97af3b... add prima wlan driver
      pNoA.opp_ps, pNoA.ctWindow, pNoA.count, pNoA.duration, 
      pNoA.interval, pNoA.single_noa_duration );

   status = sme_p2pSetPs(pMac, &pNoA);
   if(!HAL_STATUS_SUCCESS(status))
   {
      smsLog(pMac, LOGE, FL(" sme_p2pSetPs fail with status %d"), status);
      return status;
   }

   return status;
}

void P2P_UpdateMacHdr(tHalHandle hHal, tANI_U8 SessionID, tANI_U8 *pBuf)
{
   tpAniSirGlobal pMac = PMAC_STRUCT(hHal);
   tSirMacMgmtHdr *macHdr = (tSirMacMgmtHdr *)pBuf;

   macHdr->fc.protVer = 0;
   macHdr->fc.type = 0;
   macHdr->fc.subType = 13;
   macHdr->durationLo = 0;
   macHdr->durationHi = 0;
   vos_mem_copy(macHdr->da, pMac->p2pContext[SessionID].peerMacAddress, P2P_MAC_ADDRESS_LEN);
   vos_mem_copy(macHdr->sa, pMac->p2pContext[SessionID].selfMacAddress, P2P_MAC_ADDRESS_LEN);
   vos_mem_copy(macHdr->bssId, pMac->p2pContext[SessionID].peerMacAddress, P2P_MAC_ADDRESS_LEN);

   return;
}

static eHalStatus p2pRemainOnChannelReadyCallback(tHalHandle halHandle,
                     void *pContext,
                     eHalStatus scan_status)
{
   eHalStatus status = eHAL_STATUS_SUCCESS;
   tp2pContext *p2pContext = (tp2pContext*) pContext;

<<<<<<< HEAD
   VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_INFO, "%s GroupFormationPending %d  PeerFound %d\n", 
               __FUNCTION__, p2pContext->GroupFormationPending, p2pContext->PeerFound);
=======
   VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_INFO, "%s GroupFormationPending %d  PeerFound %d",
               __func__, p2pContext->GroupFormationPending, p2pContext->PeerFound);
>>>>>>> d97af3b... add prima wlan driver

   if (p2pContext->PeerFound)
   {
      p2pContext->PeerFound = FALSE;

<<<<<<< HEAD
      VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_INFO, "%s Sending actionframe\n", __FUNCTION__);
      if (p2pContext->pSentActionFrame)
      {
         VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_ERROR, "%s calling p2pSendAction\n", __FUNCTION__);
=======
      VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_INFO, "%s Sending actionframe", __func__);
      if (p2pContext->pSentActionFrame)
      {
         VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_ERROR, "%s calling p2pSendAction", __func__);
>>>>>>> d97af3b... add prima wlan driver
         p2pSendAction(halHandle, p2pContext->SMEsessionId, (tANI_U8 *)p2pContext->pSentActionFrame, p2pContext->ActionFrameLen);
      }
   }

   return status;
}

eHalStatus p2pGrpFormationRemainOnChanRspCallback(tHalHandle halHandle, void *pContext, tANI_U32 scanId, eCsrScanStatus scan_status)
{
   return eHAL_STATUS_SUCCESS;
}

tANI_U8 p2pGetDialogToken(tHalHandle hHal, tANI_U8 SessionID, eP2PFrameType actionFrameType)
{
   tANI_U8 dialogToken = 0;

   dialogToken = (tANI_U8) vos_timer_get_system_ticks();

   return(dialogToken);
}

void p2pRetryActionFrameTimerHandler(void *pContext)
{
   tp2pContext *p2pContext = (tp2pContext*) pContext;
   eHalStatus status = eHAL_STATUS_SUCCESS;
   tpAniSirGlobal pMac = PMAC_STRUCT( p2pContext->hHal );

   p2pContext->PeerFound = TRUE;
<<<<<<< HEAD
   smsLog( pMac, LOGE, "%s Calling remain on channel \n", __FUNCTION__);
   status = p2pRemainOnChannel( pMac, p2pContext->SMEsessionId, p2pContext->P2PListenChannel/*pScanResult->BssDescriptor.channelId*/, P2P_REMAIN_ON_CHAN_TIMEOUT_LOW,
                                    NULL, NULL, eP2PRemainOnChnReasonSendFrame);
   if(status != eHAL_STATUS_SUCCESS)
   {
      smsLog( pMac, LOGE, "%s remain on channel failed\n", __FUNCTION__);
=======
   smsLog( pMac, LOGE, "%s Calling remain on channel ", __func__);
   status = p2pRemainOnChannel( pMac, p2pContext->SMEsessionId, p2pContext->P2PListenChannel/*pScanResult->BssDescriptor.channelId*/, P2P_REMAIN_ON_CHAN_TIMEOUT_LOW,
                                    NULL, NULL, TRUE, eP2PRemainOnChnReasonSendFrame);
   if(status != eHAL_STATUS_SUCCESS)
   {
      smsLog( pMac, LOGE, "%s remain on channel failed", __func__);
>>>>>>> d97af3b... add prima wlan driver
   }

   return;
}

void p2pActionFrameTimerHandler(void *pContext)
{
   tp2pContext *p2pContext = (tp2pContext*) pContext;
   eHalStatus status = eHAL_STATUS_SUCCESS;
   tANI_U8 *pBuf = NULL, *pNextBuf = NULL;
   tCsrRoamInfo roamInfo;


   if(p2pContext->pSentActionFrame)
   {
      vos_mem_zero(&roamInfo, sizeof(tCsrRoamInfo));
      csrRoamCallCallback((tpAniSirGlobal)p2pContext->hHal, p2pContext->SMEsessionId, &roamInfo, 0, 
                          eCSR_ROAM_SEND_ACTION_CNF, 
                          eCSR_ROAM_RESULT_SEND_ACTION_FAIL);
   }

   if(VOS_IS_STATUS_SUCCESS(vos_spin_lock_acquire(&p2pContext->lState)))
   {
      if(p2pContext->pSentActionFrame)
      {
         VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_WARN,
<<<<<<< HEAD
            " %s actionframe timeout type %d", __FUNCTION__, p2pContext->actionFrameType);
=======
            " %s actionframe timeout type %d", __func__, p2pContext->actionFrameType);
>>>>>>> d97af3b... add prima wlan driver
         pBuf = p2pContext->pSentActionFrame;
         p2pContext->pSentActionFrame = NULL;
      }
      if(p2pContext->pNextActionFrm)
      {
         VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_WARN,
<<<<<<< HEAD
            " %s next actionframe timeout type %d", __FUNCTION__, p2pContext->NextActionFrameType);
=======
            " %s next actionframe timeout type %d", __func__, p2pContext->NextActionFrameType);
>>>>>>> d97af3b... add prima wlan driver
         pNextBuf = p2pContext->pNextActionFrm;
         p2pContext->pNextActionFrm = NULL;
      }
      vos_spin_lock_release(&p2pContext->lState);

      if(pBuf)
      {
         vos_mem_free(pBuf);
      }
      if(pNextBuf)
      {
         //Inform the failure of the next frame.
         p2pContext->pSentActionFrame = pNextBuf;
         p2pContext->ActionFrameLen = p2pContext->nNextFrmLen;
         p2pContext->actionFrameType = p2pContext->NextActionFrameType;
         vos_mem_zero(&roamInfo, sizeof(tCsrRoamInfo));
         csrRoamCallCallback((tpAniSirGlobal)p2pContext->hHal, p2pContext->SMEsessionId, &roamInfo, 0, 
                          eCSR_ROAM_SEND_ACTION_CNF, 
                          eCSR_ROAM_RESULT_SEND_ACTION_FAIL);
         p2pContext->pSentActionFrame = NULL;
         vos_mem_free(pNextBuf);
      }
   }
   status = p2pFsm(p2pContext, eP2P_TRIGGER_DISCONNECTED);
   p2pContext->actionFrameTimeout = TRUE;
<<<<<<< HEAD
   VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_INFO, "%s timedout\n", __FUNCTION__);
=======
   VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_INFO, "%s timedout", __func__);
>>>>>>> d97af3b... add prima wlan driver

   return;
}


eHalStatus p2pCreateActionFrame(tpAniSirGlobal pMac, tANI_U8 SessionID, void *p2pactionframe, 
                                 eP2PFrameType actionFrameType, tANI_U8 **ppFrm)
{
   eHalStatus status = eHAL_STATUS_SUCCESS;
   tANI_U32 len = 0;
   tANI_U32 nActionFrmlen = 0, pendingFrameLen;
   tANI_U8 *pActionFrm = NULL;
   tANI_U8 *pBuf = NULL, *pLocal = NULL;
   eP2PFrameType pendingActionFrameType;
   tp2pContext *pP2pContext = &pMac->p2pContext[SessionID];

   if(NULL == ppFrm)
   {
      smsLog(pMac, LOGE, FL("  invalid parameters"));
      return eHAL_STATUS_FAILURE;
   }

   csrScanAbortMacScan(pMac);

   switch (actionFrameType)
   {
   case eP2P_GONEGO_REQ:
      status = P2P_UpdateIE(pMac, SessionID, eWFD_SEND_GO_NEGOTIATION_REQUEST, p2pactionframe, len);
      break;

   case eP2P_GONEGO_RES:
      status = P2P_UpdateIE(pMac, SessionID, eWFD_SEND_GO_NEGOTIATION_RESPONSE, p2pactionframe, len);
      break;

   case eP2P_GONEGO_CNF:
      status = P2P_UpdateIE(pMac, SessionID, eWFD_SEND_GO_NEGOTIATION_CONFIRMATION, p2pactionframe, len);
      break;

   case eP2P_PROVISION_DISCOVERY_REQUEST:
      status = P2P_UpdateIE(pMac, SessionID, eWFD_SEND_PROVISION_DISCOVERY_REQUEST, p2pactionframe, len);
      break;

   case eP2P_PROVISION_DISCOVERY_RESPONSE:
      status = P2P_UpdateIE(pMac, SessionID, eWFD_SEND_PROVISION_DISCOVERY_RESPONSE, p2pactionframe, len);
      break;

   case eP2P_INVITATION_REQ:
      status = P2P_UpdateIE(pMac, SessionID, eWFD_SEND_INVITATION_REQUEST, p2pactionframe, len);
      break;

   case eP2P_INVITATION_RSP:
      status = P2P_UpdateIE(pMac, SessionID, eWFD_SEND_INVITATION_RESPONSE, p2pactionframe, len);
      break;
   default:
      return status;
   }

   status = P2P_GetActionFrame(pMac, SessionID, actionFrameType, &pActionFrm, &nActionFrmlen);
   if(!HAL_STATUS_SUCCESS(status))
   {
      smsLog(pMac, LOGE, FL(" P2P_GetActionFrame fail with status %d"), status);
      return status;
   }

   P2P_UpdateMacHdr(pMac, SessionID, pActionFrm);

   pBuf = (tANI_U8 *)vos_mem_malloc( nActionFrmlen);
   if(NULL == pBuf)
   {
      smsLog(pMac, LOGE, FL("  fail to allocate memory"));
      if (pActionFrm) 
         vos_mem_free(pActionFrm);
      return eHAL_STATUS_FAILURE;
   }

   vos_mem_copy(pBuf, pActionFrm, nActionFrmlen);
   vos_mem_free(pActionFrm);

   if( !VOS_IS_STATUS_SUCCESS(vos_spin_lock_acquire(&pP2pContext->lState)))
   {
      smsLog(pMac, LOGE, FL("  fail to acquire spinlock"));
      vos_mem_free(pBuf);
      return eHAL_STATUS_FAILURE;
   }

   if(NULL != pP2pContext->pSentActionFrame)
   {
      //If there is one pending frame already. Drop that one and save the new one
      pLocal = pP2pContext->pNextActionFrm;
      pendingActionFrameType = pP2pContext->NextActionFrameType;
      pendingFrameLen = pP2pContext->nNextFrmLen;
      pP2pContext->pNextActionFrm = pBuf;
      pP2pContext->nNextFrmLen = nActionFrmlen;
      pP2pContext->NextActionFrameType = actionFrameType;
      *ppFrm = NULL;
   }
   else
   {
      pP2pContext->pSentActionFrame = pBuf;
      pP2pContext->ActionFrameLen = nActionFrmlen;
      pP2pContext->actionFrameType = actionFrameType;
      *ppFrm = pBuf;
   }
   vos_spin_lock_release(&pP2pContext->lState);

   if(NULL != pLocal)
   {
<<<<<<< HEAD
      smsLog(pMac, LOGE, FL(" Drop a waiting action frame 0x%x, type %d lenth %d"), 
=======
      smsLog(pMac, LOGE, FL(" Drop a waiting action frame 0x%x, type %d lenth %d"),
>>>>>>> d97af3b... add prima wlan driver
         pLocal, pendingActionFrameType, pendingFrameLen);
      vos_mem_free(pLocal);
   }

   return status;
}


extern eHalStatus p2pGetSSID(tANI_U8 *ssId, tANI_U32 *ssIdLen, tANI_U8 SessionID);

static eHalStatus p2pSendActionFrame(tpAniSirGlobal pMac, tANI_U8 HDDSessionID, eP2PFrameType actionFrameType)
{
   tCsrScanResultFilter filter;
   eHalStatus status = eHAL_STATUS_SUCCESS;
   tScanResultHandle hScanResult = NULL;
   tCsrScanResultInfo   *pScanResult   = NULL;
   tANI_U8 ssId[SIR_MAC_MAX_SSID_LENGTH];
   tANI_U32 ssIdLen = 0;
   tp2pContext *pP2pContext = &pMac->p2pContext[HDDSessionID];

   pP2pContext->GroupFormationPending = TRUE;
   if (actionFrameType == eP2P_GONEGO_REQ || actionFrameType == eP2P_PROVISION_DISCOVERY_REQUEST 
      || actionFrameType == eP2P_INVITATION_REQ)
   {
      vos_mem_zero(&filter, sizeof(filter));
      filter.BSSIDs.numOfBSSIDs = 1;
      filter.BSSIDs.bssid = &pP2pContext->peerMacAddress;
      filter.bWPSAssociation = TRUE;
      filter.BSSType = eCSR_BSS_TYPE_ANY;

      status = csrScanGetResult(pMac, &filter, &hScanResult);

      if (hScanResult)
      {
         pScanResult = csrScanResultGetFirst(pMac, hScanResult );
         if(pScanResult)
         {

            VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_INFO_MED, "%s found match on channel %d", 
<<<<<<< HEAD
               __FUNCTION__, pScanResult->BssDescriptor.channelId);
=======
               __func__, pScanResult->BssDescriptor.channelId);
>>>>>>> d97af3b... add prima wlan driver
            pP2pContext->formationReq.targetListenChannel = pScanResult->BssDescriptor.channelId;
            if(pP2pContext->P2PListenChannel != pScanResult->BssDescriptor.channelId)
            {
               VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_INFO_MED, 
                  "%s adapt listen channel to %d", 
<<<<<<< HEAD
                  __FUNCTION__, pScanResult->BssDescriptor.channelId);
=======
                  __func__, pScanResult->BssDescriptor.channelId);
>>>>>>> d97af3b... add prima wlan driver
               p2pSetListenChannel(pMac, pP2pContext->sessionId, pScanResult->BssDescriptor.channelId);
            }
            vos_mem_copy(pP2pContext->formationReq.deviceAddress, pScanResult->BssDescriptor.bssId, P2P_MAC_ADDRESS_LEN);
         }
         csrScanResultPurge(pMac, hScanResult);
      } 
      else 
      {
         vos_mem_zero(&filter, sizeof(filter));
         filter.bWPSAssociation = TRUE;
         filter.BSSType = eCSR_BSS_TYPE_ANY;
         filter.SSIDs.SSIDList =( tCsrSSIDInfo *)vos_mem_malloc(sizeof(tCsrSSIDInfo));
         if( filter.SSIDs.SSIDList == NULL )
         {
            smsLog( pMac, LOGP, FL("vos_mem_malloc failed:") );
            pP2pContext->GroupFormationPending = FALSE;
            return eHAL_STATUS_FAILURE;
         }
         vos_mem_zero( filter.SSIDs.SSIDList, sizeof(tCsrSSIDInfo) );
         p2pGetSSID(ssId, &ssIdLen, HDDSessionID);

         if (ssIdLen)
         {
            filter.SSIDs.SSIDList->SSID.length = ssIdLen;
            vos_mem_copy(&filter.SSIDs.SSIDList[0].SSID.ssId, &ssId, ssIdLen);
            filter.SSIDs.numOfSSIDs = 1;
            status = csrScanGetResult(pMac, &filter, &hScanResult);
            if (hScanResult)
            {
               pScanResult = csrScanResultGetFirst(pMac, hScanResult );
               pP2pContext->formationReq.targetListenChannel = pScanResult->BssDescriptor.channelId;
               vos_mem_copy(pP2pContext->formationReq.deviceAddress, pScanResult->BssDescriptor.bssId, P2P_MAC_ADDRESS_LEN);
               csrScanResultPurge(pMac, hScanResult);
            }
            else
            {
<<<<<<< HEAD
               VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_INFO, "%s not found match\n", __FUNCTION__);
=======
               VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_INFO, "%s not found match", __func__);
>>>>>>> d97af3b... add prima wlan driver
               pP2pContext->formationReq.targetListenChannel = 0;
               vos_mem_copy(pP2pContext->formationReq.deviceAddress, pP2pContext->peerMacAddress, P2P_MAC_ADDRESS_LEN);
               status = eHAL_STATUS_SUCCESS;
            }
            vos_mem_free(filter.SSIDs.SSIDList);
         }
         else
         {
<<<<<<< HEAD
            VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_INFO, "%s not found match\n", __FUNCTION__);
=======
            VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_INFO, "%s not found match", __func__);
>>>>>>> d97af3b... add prima wlan driver
            pP2pContext->formationReq.targetListenChannel = 0;
            vos_mem_copy(pP2pContext->formationReq.deviceAddress, pP2pContext->peerMacAddress, P2P_MAC_ADDRESS_LEN);
            status = eHAL_STATUS_SUCCESS;
         }    
      }
      sme_CancelRemainOnChannel(pMac, pP2pContext->SMEsessionId );
      p2pFsm(pP2pContext, eP2P_TRIGGER_GROUP_FORMATION);     
<<<<<<< HEAD
      VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_INFO, " %s send action frame %d timeout %d\n", 
               __FUNCTION__, actionFrameType, pP2pContext->ActionFrameSendTimeout);
=======
      VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_INFO, " %s send action frame %d timeout %d",
               __func__, actionFrameType, pP2pContext->ActionFrameSendTimeout);
>>>>>>> d97af3b... add prima wlan driver
   } 
   else
   {
      pP2pContext->PeerFound = TRUE;

      status = p2pSendAction(pMac, pP2pContext->SMEsessionId, (tANI_U8 *)pP2pContext->pSentActionFrame, 
                              pP2pContext->ActionFrameLen);
      if(status != eHAL_STATUS_SUCCESS)
      {
         VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_ERROR,  
<<<<<<< HEAD
            "%s p2pSendAction failed to send frame type %d\n", __FUNCTION__, actionFrameType);
=======
            "%s p2pSendAction failed to send frame type %d", __func__, actionFrameType);
>>>>>>> d97af3b... add prima wlan driver
         pP2pContext->GroupFormationPending = FALSE;
         return status;
      }

      if ( actionFrameType == eP2P_GONEGO_RES )
      {
         VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_INFO, "%s Calling p2pRemainOnChannel with duration"
<<<<<<< HEAD
            "%d on channel %d\n", __FUNCTION__, P2P_REMAIN_ON_CHAN_TIMEOUT, pP2pContext->P2PListenChannel);

         if(p2pRemainOnChannel( pMac, pP2pContext->SMEsessionId, 
                                      pP2pContext->P2PListenChannel, P2P_REMAIN_ON_CHAN_TIMEOUT_LOW,
                                      NULL, NULL, eP2PRemainOnChnReasonSendFrame))
         {
            VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_ERROR,  "%s remain on channel failed\n", __FUNCTION__);
=======
            "%d on channel %d", __func__, P2P_REMAIN_ON_CHAN_TIMEOUT, pP2pContext->P2PListenChannel);

         if(p2pRemainOnChannel( pMac, pP2pContext->SMEsessionId, 
                                      pP2pContext->P2PListenChannel, P2P_REMAIN_ON_CHAN_TIMEOUT_LOW,
                                      NULL, NULL, TRUE, eP2PRemainOnChnReasonSendFrame))
         {
            VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_ERROR,  "%s remain on channel failed", __func__);
>>>>>>> d97af3b... add prima wlan driver
         }
      }
   }

   return(status);
}


#define WLAN_P2P_DEF_ACTION_FRM_TIMEOUT_VALUE 1000  //1s

eHalStatus p2pCreateSendActionFrame(tHalHandle hHal, tANI_U8 HDDSessionID, 
   void *p2pactionframe, eP2PFrameType actionFrameType, tANI_U32 timeout)
{
   eHalStatus status = eHAL_STATUS_SUCCESS;
   tpAniSirGlobal pMac = PMAC_STRUCT(hHal);
   tANI_U8 *pBuf = NULL;
   tp2pContext *pP2pContext = &pMac->p2pContext[HDDSessionID];
   
   status = p2pCreateActionFrame(pMac, HDDSessionID, p2pactionframe, actionFrameType, &pBuf);
   if(!HAL_STATUS_SUCCESS(status))
   {
      smsLog(pMac, LOGE, FL("  fail to create action frame"));
      return status;
   }
      
<<<<<<< HEAD
   VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_INFO, " %s send action frame %d timeout %d\n", 
                  __FUNCTION__, actionFrameType, timeout);
=======
   VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_INFO, " %s send action frame %d timeout %d",
                  __func__, actionFrameType, timeout);
>>>>>>> d97af3b... add prima wlan driver

   if(NULL != pBuf)
   {
      if (timeout)
      {
         pP2pContext->ActionFrameSendTimeout = timeout;
      }
      else
      {
         pP2pContext->ActionFrameSendTimeout = WLAN_P2P_DEF_ACTION_FRM_TIMEOUT_VALUE;
      }

<<<<<<< HEAD
      status = palTimerStart(pMac->hHdd, pP2pContext->actionFrameTimer, 
                        pP2pContext->ActionFrameSendTimeout * PAL_TIMER_TO_MS_UNIT, eANI_BOOLEAN_FALSE);
      if (!HAL_STATUS_SUCCESS(status))
=======
      status = vos_timer_start(&pP2pContext->actionFrameTimer,
                        pP2pContext->ActionFrameSendTimeout);
      if (!VOS_IS_STATUS_SUCCESS(status))
>>>>>>> d97af3b... add prima wlan driver
      {
         tCsrRoamInfo RoamInfo;

         vos_mem_zero(&RoamInfo, sizeof(tCsrRoamInfo));
<<<<<<< HEAD
         smsLog(pMac, LOGE, FL(" %s fail to start timer status %d"), __FUNCTION__, status);
=======
         smsLog(pMac, LOGE, FL(" %s fail to start timer status %d"), __func__, status);
>>>>>>> d97af3b... add prima wlan driver
         //Without the timer we cannot continue
         csrRoamCallCallback((tpAniSirGlobal)pP2pContext->hHal, 
                     pP2pContext->SMEsessionId, &RoamInfo, 0, 
                     eCSR_ROAM_SEND_ACTION_CNF, 
                     eCSR_ROAM_RESULT_SEND_ACTION_FAIL);
         vos_spin_lock_acquire(&pP2pContext->lState);
         pBuf = pP2pContext->pSentActionFrame;
         pP2pContext->pSentActionFrame = NULL;
         vos_spin_lock_release(&pP2pContext->lState);
         vos_mem_free(pBuf);
         pBuf = NULL;
         p2pFsm(pP2pContext, eP2P_TRIGGER_DISCONNECTED);
         return status;
      }
      //We can send this frame now
      status = p2pSendActionFrame(pMac, HDDSessionID, actionFrameType);
      if(!HAL_STATUS_SUCCESS(status))
      {
         smsLog(pMac, LOGE, FL("  fail to send action frame status %d"), status);
      }
      //Let them retry
      pP2pContext->actionFrameTimeout = FALSE;
   }
   else
   {
      //An action frame is pedning at lower layer
      smsLog(pMac, LOGW, FL("  An action frame is pending while trying to send frametype %d"), actionFrameType);
      if (timeout)
      {
         pP2pContext->nNextFrameTimeOut = timeout;
      }
      else
      {
         pP2pContext->nNextFrameTimeOut = WLAN_P2P_DEF_ACTION_FRM_TIMEOUT_VALUE;
      }
   }

   return status;
}


void p2pListenDiscoverTimerHandlerCB(void *pContext)
{
}

void p2pListenDiscoverTimerHandler(void *pContext)
{
   tp2pContext *p2pContext = (tp2pContext*) pContext;
   eHalStatus status = eHAL_STATUS_SUCCESS;

   if( (eP2P_STATE_DISCONNECTED == p2pContext->state) && 
       (eStateDisabled != p2pContext->listenDiscoverableState) )
   {
<<<<<<< HEAD
      VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_INFO, "%s Calling RemainOnChannel with duration %d on channel %d\n", 
             __FUNCTION__, p2pContext->listenDuration, p2pContext->P2PListenChannel);
      status = p2pRemainOnChannel( p2pContext->hHal, p2pContext->SMEsessionId, p2pContext->P2PListenChannel, p2pContext->listenDuration, 
                                    p2pListenStateDiscoverableCallback, p2pContext, eP2PRemainOnChnReasonListen);
   }
   else
   {
      smsLog(((tpAniSirGlobal)p2pContext->hHal), LOGW, FL(" cannot call p2pRemainOnChannel state %d\n"), p2pContext->state);
=======
      VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_INFO, "%s Calling RemainOnChannel with duration %d on channel %d",
             __func__, p2pContext->listenDuration, p2pContext->P2PListenChannel);
      status = p2pRemainOnChannel( p2pContext->hHal, p2pContext->SMEsessionId, p2pContext->P2PListenChannel, p2pContext->listenDuration, 
                                    p2pListenStateDiscoverableCallback, p2pContext, TRUE, eP2PRemainOnChnReasonListen);
   }
   else
   {
      smsLog(((tpAniSirGlobal)p2pContext->hHal), LOGW, FL(" cannot call p2pRemainOnChannel state %d"), p2pContext->state);
>>>>>>> d97af3b... add prima wlan driver
   }

   return;
}


static eHalStatus p2pListenStateDiscoverableCallback(tHalHandle halHandle, void *pContext, eHalStatus retStatus)
{
   eHalStatus status = eHAL_STATUS_SUCCESS;
   tpAniSirGlobal pMac = PMAC_STRUCT(halHandle);
   tp2pContext *p2pContext = (tp2pContext*) pContext;

   if( (eP2P_STATE_DISCONNECTED == p2pContext->state) && 
       (eStateDisabled != p2pContext->listenDiscoverableState) && 
       (NULL == p2pContext->p2pDiscoverCBFunc) )
   {
<<<<<<< HEAD
      VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_INFO, "%s restart listen timer expire time %d\n", 
                  __FUNCTION__, p2pContext->expire_time);
      //We can restart the listening
      status = palTimerStart(pMac->hHdd, p2pContext->listenTimerHandler, p2pContext->expire_time, eANI_BOOLEAN_FALSE);
      if (eHAL_STATUS_SUCCESS != status)
=======
      VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_INFO, "%s restart listen timer expire time %d",
                  __func__, p2pContext->expire_time);
      //We can restart the listening
      status = vos_timer_start(&p2pContext->listenTimerHandler, (p2pContext->expire_time)/PAL_TIMER_TO_MS_UNIT);
      if (!VOS_IS_STATUS_SUCCESS(status))
>>>>>>> d97af3b... add prima wlan driver
      {
         VOS_ASSERT(status);
      }
   }
   else
   {
<<<<<<< HEAD
      VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_INFO, "%s not restart listen timer  state (%d)\n", 
                  __FUNCTION__, p2pContext->state);
=======
      VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_INFO, "%s not restart listen timer  state (%d)",
                  __func__, p2pContext->state);
>>>>>>> d97af3b... add prima wlan driver
   }

   return status;
}


eHalStatus P2P_ListenStateDiscoverable(tHalHandle hHal, tANI_U8 sessionId,
                                       ep2pListenStateDiscoverability listenState)
{
   eHalStatus status = eHAL_STATUS_SUCCESS;
   tpAniSirGlobal pMac = PMAC_STRUCT(hHal);

   switch (listenState) 
   {
   case P2P_DEVICE_NOT_DISCOVERABLE:
<<<<<<< HEAD
      VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_INFO, "%s P2P_NOT_DISCOVERABLE\n", __FUNCTION__);
=======
      VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_INFO, "%s P2P_NOT_DISCOVERABLE", __func__);
>>>>>>> d97af3b... add prima wlan driver
      pMac->p2pContext[sessionId].listenDiscoverableState = eStateDisabled;
      pMac->p2pContext[sessionId].DiscoverableCfg = listenState;
      if (pMac->p2pContext[sessionId].state == eP2P_STATE_DISCONNECTED)
      {
         sme_CancelRemainOnChannel(hHal, sessionId );

         if (pMac->p2pContext[sessionId].listenTimerHandler)
         {
<<<<<<< HEAD
            status = palTimerStop(pMac->hHdd, pMac->p2pContext[sessionId].listenTimerHandler);
            VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_INFO, "%s Timer Stop status %d\n", 
                        __FUNCTION__, status);
=======
            vos_timer_stop(&pMac->p2pContext[sessionId].listenTimerHandler);
            status = eHAL_STATUS_SUCCESS;
            VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_INFO, "%s Timer Stop status %d",
                        __func__, status);
>>>>>>> d97af3b... add prima wlan driver
         }
      }
      else
      {
         VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_INFO_MED, "%s P2P_NOT_DISCOVERABLE not in right state (%d)",
<<<<<<< HEAD
            __FUNCTION__, pMac->p2pContext[sessionId].state);
=======
            __func__, pMac->p2pContext[sessionId].state);
>>>>>>> d97af3b... add prima wlan driver
      }
      break;

   case P2P_DEVICE_AUTO_AVAILABILITY:
<<<<<<< HEAD
      VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_INFO, "%s P2P_AUTO_AVAILABILITY\n",__FUNCTION__);
=======
      VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_INFO, "%s P2P_AUTO_AVAILABILITY",__func__);
>>>>>>> d97af3b... add prima wlan driver
      pMac->p2pContext[sessionId].listenDiscoverableState = eStateEnabled;
      pMac->p2pContext[sessionId].DiscoverableCfg = listenState;
      pMac->p2pContext[sessionId].expire_time = P2P_LISTEN_TIMEOUT_AUTO * PAL_TIMER_TO_MS_UNIT;
      pMac->p2pContext[sessionId].listenDuration = P2P_LISTEN_TIMEOUT;
      if (pMac->p2pContext[sessionId].state == eP2P_STATE_DISCONNECTED)
      {
<<<<<<< HEAD
         VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_INFO, "%s Calling RemainOnChannel with diration %d on channel %d\n",
                     __FUNCTION__, pMac->p2pContext[sessionId].listenDuration, pMac->p2pContext[sessionId].P2PListenChannel);
         p2pRemainOnChannel( pMac, pMac->p2pContext[sessionId].SMEsessionId, pMac->p2pContext[sessionId].P2PListenChannel, 
                              pMac->p2pContext[sessionId].listenDuration, p2pListenStateDiscoverableCallback, 
                              &pMac->p2pContext[sessionId], eP2PRemainOnChnReasonListen);
=======
         VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_INFO, "%s Calling RemainOnChannel with diration %d on channel %d",
                     __func__, pMac->p2pContext[sessionId].listenDuration, pMac->p2pContext[sessionId].P2PListenChannel);
         p2pRemainOnChannel( pMac, pMac->p2pContext[sessionId].SMEsessionId, pMac->p2pContext[sessionId].P2PListenChannel, 
                              pMac->p2pContext[sessionId].listenDuration, p2pListenStateDiscoverableCallback, 
                              &pMac->p2pContext[sessionId], TRUE, eP2PRemainOnChnReasonListen);
>>>>>>> d97af3b... add prima wlan driver
      }
      else
      {
         VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_INFO_MED, "%s P2P_AUTO_DISCOVERABLE not in right state (%d)",
<<<<<<< HEAD
            __FUNCTION__, pMac->p2pContext[sessionId].state);
=======
            __func__, pMac->p2pContext[sessionId].state);
>>>>>>> d97af3b... add prima wlan driver
      }
      break;

   case P2P_DEVICE_HIGH_AVAILABILITY:
<<<<<<< HEAD
      VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_INFO, "%s P2P_HIGH_AVAILABILITY\n",__FUNCTION__);
=======
      VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_INFO, "%s P2P_HIGH_AVAILABILITY",__func__);
>>>>>>> d97af3b... add prima wlan driver
      pMac->p2pContext[sessionId].listenDiscoverableState = eStateEnabled;
      pMac->p2pContext[sessionId].DiscoverableCfg = listenState;
      pMac->p2pContext[sessionId].expire_time = P2P_REMAIN_ON_CHAN_TIMEOUT_LOW * PAL_TIMER_TO_MS_UNIT;
      pMac->p2pContext[sessionId].listenDuration = P2P_LISTEN_TIMEOUT_HIGH;
      if (pMac->p2pContext[sessionId].state == eP2P_STATE_DISCONNECTED)
      {
<<<<<<< HEAD
         VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_INFO, "%s Calling RemainOnChannel with diration %d on channel %d\n",
                     __FUNCTION__, pMac->p2pContext[sessionId].listenDuration, pMac->p2pContext[sessionId].P2PListenChannel);
         p2pRemainOnChannel( pMac, pMac->p2pContext[sessionId].SMEsessionId, pMac->p2pContext[sessionId].P2PListenChannel, 
                              pMac->p2pContext[sessionId].listenDuration, p2pListenStateDiscoverableCallback, 
                              &pMac->p2pContext[sessionId], eP2PRemainOnChnReasonListen);
=======
         VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_INFO, "%s Calling RemainOnChannel with diration %d on channel %d",
                     __func__, pMac->p2pContext[sessionId].listenDuration, pMac->p2pContext[sessionId].P2PListenChannel);
         p2pRemainOnChannel( pMac, pMac->p2pContext[sessionId].SMEsessionId, pMac->p2pContext[sessionId].P2PListenChannel, 
                              pMac->p2pContext[sessionId].listenDuration, p2pListenStateDiscoverableCallback, 
                              &pMac->p2pContext[sessionId], TRUE, eP2PRemainOnChnReasonListen);
>>>>>>> d97af3b... add prima wlan driver
      }
      else
      {
         VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_INFO_MED, "%s P2P_HIGH_DISCOVERABLE not in right state (%d)",
<<<<<<< HEAD
            __FUNCTION__, pMac->p2pContext[sessionId].state);
=======
            __func__, pMac->p2pContext[sessionId].state);
>>>>>>> d97af3b... add prima wlan driver
      }
      break;

   case 234: //Not to use this as it enabling GO to be concurrent with P2P device P2P_DEVICE_HIGH_AVAILABILITY:
<<<<<<< HEAD
      VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_INFO, "%s P2P_HIGH_AVAILABILITY\n",__FUNCTION__);
=======
      VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_INFO, "%s P2P_HIGH_AVAILABILITY",__func__);
>>>>>>> d97af3b... add prima wlan driver
      pMac->p2pContext[sessionId].listenDiscoverableState = eStateEnabled;
      pMac->p2pContext[sessionId].DiscoverableCfg = listenState;

      if ((pMac->p2pContext[sessionId].P2POperatingChannel != pMac->p2pContext[sessionId].P2PListenChannel)
           && p2pIsGOportEnabled(pMac))
      {
         pMac->p2pContext[sessionId].expire_time = P2P_LISTEN_TIMEOUT_HIGH * PAL_TIMER_TO_MS_UNIT * 5;
         pMac->p2pContext[sessionId].listenDuration = P2P_REMAIN_ON_CHAN_TIMEOUT_LOW;
      } 
      else
      {
         pMac->p2pContext[sessionId].expire_time = P2P_LISTEN_TIMEOUT_HIGH * PAL_TIMER_TO_MS_UNIT;
         pMac->p2pContext[sessionId].listenDuration = P2P_LISTEN_TIMEOUT;
      }

      if (pMac->p2pContext[sessionId].state == eP2P_STATE_DISCONNECTED)
      {
<<<<<<< HEAD
         VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_INFO, "%s Calling RemainOnChannel with diration %d on channel %d\n",
                     __FUNCTION__, pMac->p2pContext[sessionId].listenDuration, pMac->p2pContext[sessionId].P2PListenChannel);
         p2pRemainOnChannel( pMac, pMac->p2pContext[sessionId].SMEsessionId, pMac->p2pContext[sessionId].P2PListenChannel, 
                              pMac->p2pContext[sessionId].listenDuration, p2pListenStateDiscoverableCallback, 
                              &pMac->p2pContext[sessionId], eP2PRemainOnChnReasonListen);
=======
         VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_INFO, "%s Calling RemainOnChannel with diration %d on channel %d",
                     __func__, pMac->p2pContext[sessionId].listenDuration, pMac->p2pContext[sessionId].P2PListenChannel);
         p2pRemainOnChannel( pMac, pMac->p2pContext[sessionId].SMEsessionId, pMac->p2pContext[sessionId].P2PListenChannel, 
                              pMac->p2pContext[sessionId].listenDuration, p2pListenStateDiscoverableCallback, 
                              &pMac->p2pContext[sessionId], TRUE, eP2PRemainOnChnReasonListen);
>>>>>>> d97af3b... add prima wlan driver
      }
      
      break;

   default:
      VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_ERROR, 
<<<<<<< HEAD
         "%s Unknown listen setting",__FUNCTION__, listenState);
=======
         "%s Unknown listen setting",__func__, listenState);
>>>>>>> d97af3b... add prima wlan driver
      break;
   }

    return( status );
}


void p2pCallDiscoverCallback(tp2pContext *p2pContext, eP2PDiscoverStatus statusCode)
{
   if (p2pContext->p2pDiscoverCBFunc)
   {
      p2pDiscoverCompleteCallback pcallback = p2pContext->p2pDiscoverCBFunc;
      p2pContext->p2pDiscoverCBFunc = NULL;
      pcallback(p2pContext->hHal, p2pContext->pContext, statusCode);
   }
   p2pContext->directedDiscovery = FALSE;
}


void p2pDiscoverTimerHandler(void *pContext)
{
   tp2pContext *p2pContext = (tp2pContext*) pContext;
   eHalStatus status = eHAL_STATUS_SUCCESS;

<<<<<<< HEAD
   VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_INFO_MED, "%s enter", __FUNCTION__);
=======
   VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_INFO_MED, "%s enter", __func__);
>>>>>>> d97af3b... add prima wlan driver
   p2pCallDiscoverCallback(p2pContext, 
         (p2pContext->directedDiscovery) ? eP2P_DIRECTED_DISCOVER : eP2P_DISCOVER_SUCCESS);

   status = p2pFsm(p2pContext, eP2P_TRIGGER_DISCONNECTED);

   return;
}



eHalStatus p2pGetResultFilter(tp2pContext *pP2pContext,
                              tCsrScanResultFilter *pFilter)
{
   eHalStatus status = eHAL_STATUS_SUCCESS;
   v_U32_t uNumDeviceFilters;
   tp2pDiscoverDeviceFilter *directedDiscoveryFilter;
   int i;
   tCsrBssid *bssid = NULL;

   do
   {
      if( (NULL != pP2pContext) && (NULL != pFilter) )
      {
         vos_mem_zero(pFilter, sizeof(tCsrScanResultFilter));
         uNumDeviceFilters = pP2pContext->uNumDeviceFilters;
         directedDiscoveryFilter = pP2pContext->directedDiscoveryFilter;
         for(i = 0; i < uNumDeviceFilters; i++)
         {
            if (directedDiscoveryFilter->ucBitmask & DISCOVERY_FILTER_BITMASK_DEVICE)
            {
               pFilter->BSSIDs.numOfBSSIDs++;
            }
            
            if ((directedDiscoveryFilter->ucBitmask != QCWLAN_P2P_DISCOVER_ANY) 
               && (directedDiscoveryFilter->ucBitmask & DISCOVERY_FILTER_BITMASK_GO))
            {
               //Matching Device ID and GroupSSID
               pFilter->BSSIDs.numOfBSSIDs++;
               if(directedDiscoveryFilter->GroupSSID.length)
               {
                  pFilter->SSIDs.numOfSSIDs++;
               }
            }
            directedDiscoveryFilter += sizeof(tp2pDiscoverDeviceFilter);
         }

         directedDiscoveryFilter = pP2pContext->directedDiscoveryFilter;
         if (pFilter->BSSIDs.numOfBSSIDs)
         {
            bssid = ( tCsrBssid *) vos_mem_malloc( sizeof( tCsrBssid ) * pFilter->BSSIDs.numOfBSSIDs );
            if(NULL == bssid)
            {
               VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_ERROR, 
<<<<<<< HEAD
                  " %s fail to allocate bssid", __FUNCTION__);
=======
                  " %s fail to allocate bssid", __func__);
>>>>>>> d97af3b... add prima wlan driver
               status = eHAL_STATUS_RESOURCES;
               break;
            }

            pFilter->BSSIDs.bssid = bssid;

            for (i = 0; i < uNumDeviceFilters; i++)
            {
               vos_mem_copy(bssid, directedDiscoveryFilter->DeviceID, P2P_MAC_ADDRESS_LEN);
               bssid += sizeof(tCsrBssid);
               directedDiscoveryFilter += sizeof(tp2pDiscoverDeviceFilter);
            }
         }

         directedDiscoveryFilter = pP2pContext->directedDiscoveryFilter;
         if (pFilter->SSIDs.numOfSSIDs)
         {
            pFilter->SSIDs.SSIDList = (tCsrSSIDInfo *)vos_mem_malloc( sizeof( *pFilter->SSIDs.SSIDList ) *
                                                      pFilter->SSIDs.numOfSSIDs );
            if(NULL == pFilter->SSIDs.SSIDList)
            {
               VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_ERROR, 
<<<<<<< HEAD
                  " %s fail to allocate bssid", __FUNCTION__);
=======
                  " %s fail to allocate bssid", __func__);
>>>>>>> d97af3b... add prima wlan driver
               status = eHAL_STATUS_RESOURCES;
               break;
            }

            if ( pFilter->SSIDs.SSIDList )
            {
               for ( i = 0; i < uNumDeviceFilters; i++ )
               {
                  if (directedDiscoveryFilter->ucBitmask == DISCOVERY_FILTER_BITMASK_GO)
                  {
                     if(directedDiscoveryFilter->GroupSSID.length)
                     {
                        pFilter->SSIDs.SSIDList[i].SSID.length = directedDiscoveryFilter->GroupSSID.length;
                        vos_mem_copy( pFilter->SSIDs.SSIDList[i].SSID.ssId,
                                       directedDiscoveryFilter->GroupSSID.ssId,
                                       directedDiscoveryFilter->GroupSSID.length );
                     }
                  }
                  directedDiscoveryFilter += sizeof(tp2pDiscoverDeviceFilter);
               }
            }
         }
      }

      pFilter->p2pResult = TRUE;
      pFilter->bWPSAssociation = TRUE;
      pFilter->BSSType = eCSR_BSS_TYPE_ANY;
   } while(0);

   if(!HAL_STATUS_SUCCESS(status))
   {
      if(pFilter->SSIDs.SSIDList)
      {
         vos_mem_free(pFilter->SSIDs.SSIDList);
         pFilter->SSIDs.SSIDList = NULL;
      }
      if( pFilter->BSSIDs.bssid )
      {
         vos_mem_free(pFilter->BSSIDs.bssid);
         pFilter->BSSIDs.bssid = NULL;
      }
   }

   return status;
}


/*
  @breif Function calls P2P_Fsm function to initiate the P2P Discover process

  @param[in] hHal - Handle to MAC structure.
        [in] sessionID - Session ID returned by sme_OpenSession
        [in] pDiscoverRequest - pointer to the tp2pDiscoverRequest structure
             whose parameters are filled in the HDD.
        [in] callback - HDD callback function to be called when Discover
             is complete
        [in] pContext - a pointer passed in for the callback

  @return eHAL_STATUS_FAILURE - If success.
          eHAL_STATUS_SUCCESS - If failure.
*/
eHalStatus P2P_DiscoverRequest(tHalHandle hHal,
                tANI_U8 SessionID,
                tP2PDiscoverRequest *pDiscoverRequest,
                p2pDiscoverCompleteCallback callback,
                void *pContext)
{
   eHalStatus           status = eHAL_STATUS_FAILURE;
   tpAniSirGlobal       pMac = PMAC_STRUCT(hHal);
   tScanResultHandle    hScanResult = NULL;
   tCsrScanResultFilter filter;
   tANI_U32 uNumDeviceFilters;
   tp2pDiscoverDeviceFilter *pDeviceFilters;
   tANI_U32 i = 0;
   tp2pContext *pP2pContext = &pMac->p2pContext[SessionID];
   tCsrBssid *bssid = NULL;
   tp2pDiscoverDeviceFilter discoverFilter;
   tANI_BOOLEAN fDirect = FALSE;

   if (pDiscoverRequest == NULL)
   {
      return status;
   }

   pP2pContext->discoverType      = pDiscoverRequest->discoverType;
   pP2pContext->scanType          = pDiscoverRequest->scanType;
   pP2pContext->uDiscoverTimeout  = pDiscoverRequest->uDiscoverTimeout;

   if (pP2pContext->DiscoverReqIeField)
   {
      vos_mem_free(pP2pContext->DiscoverReqIeField);
      pP2pContext->DiscoverReqIeLength = 0;
      pP2pContext->DiscoverReqIeField = NULL;
   }

   if (pDiscoverRequest->uIELen)
   {
      pP2pContext->DiscoverReqIeField = (tANI_U8 *)vos_mem_malloc(pDiscoverRequest->uIELen);
      vos_mem_copy((tANI_U8 *)pP2pContext->DiscoverReqIeField, pDiscoverRequest->pIEField, pDiscoverRequest->uIELen);
      pP2pContext->DiscoverReqIeLength = pDiscoverRequest->uIELen;
   } 
   else
   {
      pP2pContext->DiscoverReqIeLength = 0;
   }

   vos_mem_zero(&filter, sizeof(filter));

   do
   {
      if (pDiscoverRequest->uNumDeviceFilters)
      {
<<<<<<< HEAD
         VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_INFO, "%s directed\n", __FUNCTION__);
=======
         VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_INFO, "%s directed", __func__);
>>>>>>> d97af3b... add prima wlan driver
         fDirect = TRUE;
         uNumDeviceFilters = pDiscoverRequest->uNumDeviceFilters;

         pP2pContext->uDiscoverTimeout = pP2pContext->uDiscoverTimeout;
         pP2pContext->uNumDeviceFilters = pDiscoverRequest->uNumDeviceFilters;
         if(pP2pContext->uNumDeviceFilterAllocated < pDiscoverRequest->uNumDeviceFilters)
         {
            if(pP2pContext->directedDiscoveryFilter)
            {
               pP2pContext->uNumDeviceFilterAllocated = 0;
               vos_mem_free(pP2pContext->directedDiscoveryFilter);
               pP2pContext->directedDiscoveryFilter = NULL;
            }
            pP2pContext->directedDiscoveryFilter = (tp2pDiscoverDeviceFilter *)
                  vos_mem_malloc(sizeof(tp2pDiscoverDeviceFilter) * uNumDeviceFilters);
            if(NULL == pP2pContext->directedDiscoveryFilter)
            {
               VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_ERROR, 
<<<<<<< HEAD
                  "%s fail to allocate memory for discoverFilter", __FUNCTION__);
=======
                  "%s fail to allocate memory for discoverFilter", __func__);
>>>>>>> d97af3b... add prima wlan driver
               status = eHAL_STATUS_RESOURCES;
               break;
            }
            pP2pContext->uNumDeviceFilterAllocated = uNumDeviceFilters;
         }

         pDeviceFilters = pDiscoverRequest->pDeviceFilters;
         if(NULL != pDeviceFilters)
         {
            vos_mem_copy ( pP2pContext->directedDiscoveryFilter, pDeviceFilters,
                              sizeof(tp2pDiscoverDeviceFilter) * uNumDeviceFilters);

            if(!HAL_STATUS_SUCCESS(status = p2pGetResultFilter(pP2pContext, &filter)))
            {
               VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_ERROR, 
<<<<<<< HEAD
                  "%s fail to create filter", __FUNCTION__);
=======
                  "%s fail to create filter", __func__);
>>>>>>> d97af3b... add prima wlan driver
               break;
            }
         }//if(NULL != pDeviceFilters)

         status = csrScanGetResult(pMac, &filter, &hScanResult);
         if (hScanResult)
         {
            VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_ERROR, 
<<<<<<< HEAD
               "%s calling p2pDiscoverCompleteCallback\n", __FUNCTION__);
=======
               "%s calling p2pDiscoverCompleteCallback", __func__);
>>>>>>> d97af3b... add prima wlan driver
            if (callback)
            {
               callback(hHal, pContext, eP2P_DIRECTED_DISCOVER);

            }       
            status =  eHAL_STATUS_SUCCESS;
            break;
         }
         else
         {
            VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_ERROR, 
<<<<<<< HEAD
               "%s Directed find did not find BSSID in cache\n", __FUNCTION__);
=======
               "%s Directed find did not find BSSID in cache", __func__);
>>>>>>> d97af3b... add prima wlan driver
            pP2pContext->formationReq.targetListenChannel = 0;
            if (pDiscoverRequest->uNumDeviceFilters == 1 && filter.BSSIDs.numOfBSSIDs == 1)
            {
               vos_mem_copy(&pP2pContext->formationReq.deviceAddress, 
                              pDiscoverRequest->pDeviceFilters->DeviceID, P2P_MAC_ADDRESS_LEN);
            }
         }
      }

      pP2pContext->p2pDiscoverCBFunc = callback;
      pP2pContext->pContext          = pContext;
      pP2pContext->directedDiscovery = fDirect;
      if(!pP2pContext->GroupFormationPending)
      {
         p2pFsm(&pMac->p2pContext[SessionID], eP2P_TRIGGER_DEVICE_MODE_DEVICE);
      }
      else
      {
         VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_INFO_MED, 
<<<<<<< HEAD
               "%s while group formation", __FUNCTION__);
      }

      pP2pContext->uDiscoverTimeout = pDiscoverRequest->uDiscoverTimeout;
      VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_INFO_MED, "%s Start discover", __FUNCTION__);
      status = palTimerStart(pMac->hHdd, pP2pContext->discoverTimer, 
                     pP2pContext->uDiscoverTimeout * 1000, eANI_BOOLEAN_FALSE);
      if(!HAL_STATUS_SUCCESS(status))
      {
         VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_ERROR, 
            "%s failt to start discover timer", __FUNCTION__);
=======
               "%s while group formation", __func__);
      }

      pP2pContext->uDiscoverTimeout = pDiscoverRequest->uDiscoverTimeout;
      VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_INFO_MED, "%s Start discover", __func__);
      status = vos_timer_start(&pP2pContext->discoverTimer,
                     pP2pContext->uDiscoverTimeout);
      if (!VOS_IS_STATUS_SUCCESS(status))
      {
         VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_ERROR, 
            "%s failt to start discover timer", __func__);
>>>>>>> d97af3b... add prima wlan driver
            pP2pContext->p2pDiscoverCBFunc = NULL;
            pP2pContext->pContext          = NULL;
            if(callback)
            {
               callback(pMac, pContext, eP2P_DISCOVER_FAILURE);
            }
      }
   }while(0);

   if(filter.SSIDs.SSIDList)
   {
      vos_mem_free(filter.SSIDs.SSIDList);
   }
   if( hScanResult )
   {
      sme_ScanResultPurge( pMac, hScanResult );
   }
   if( filter.BSSIDs.bssid )
   {
      vos_mem_free(filter.BSSIDs.bssid);
   }

   return status;
}

eHalStatus p2pScanRequest(tp2pContext *p2pContext, p2pDiscoverCompleteCallback callback, void *pContext)
{
   tCsrScanRequest scanRequest;
   v_U32_t scanId = 0;
   tANI_U32 len = 0;
   tCsrSSIDInfo wcSSID = { {P2P_WILDCARD_SSID_LEN, P2P_WILDCARD_SSID}, 0, 0 };
   tANI_U8 Channel; 
   eHalStatus status = eHAL_STATUS_SUCCESS;
   tP2P_OperatingChannel p2pOperatingChannel;
   tpAniSirGlobal pMac = PMAC_STRUCT(p2pContext->hHal);
   tANI_U8 *p2pIe = NULL;
   tANI_U32 p2pIeLen;

   vos_mem_zero( &scanRequest, sizeof(scanRequest));

   P2P_GetOperatingChannel(p2pContext->hHal, p2pContext->sessionId, &p2pOperatingChannel);
   Channel = p2pOperatingChannel.channel;
   
   if (Channel)
   {
      scanRequest.ChannelInfo.numOfChannels = 1;      
      scanRequest.ChannelInfo.ChannelList = &Channel;
<<<<<<< HEAD
      VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_ERROR, "%s Scan on channel %d p2pContext->sessionId %d\n", 
                  __FUNCTION__, Channel, p2pContext->sessionId);
=======
      VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_ERROR, "%s Scan on channel %d p2pContext->sessionId %d",
                  __func__, Channel, p2pContext->sessionId);
>>>>>>> d97af3b... add prima wlan driver
   }
   else
   {
       getChannelInfo(p2pContext, &scanRequest.ChannelInfo, WFD_DISCOVER_TYPE_AUTO);
<<<<<<< HEAD
       VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_ERROR, "%s Scan on all channels\n", 
                  __FUNCTION__);
=======
       VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_ERROR, "%s Scan on all channels",
                  __func__);
>>>>>>> d97af3b... add prima wlan driver
   }

   /* set the scan type to active */
   scanRequest.scanType = eSIR_ACTIVE_SCAN;

   vos_mem_set( scanRequest.bssid, sizeof( tCsrBssid ), 0xff );

   scanRequest.requestType = eCSR_SCAN_P2P_FIND_PEER;
   /* set min and max channel time to zero */
   scanRequest.minChnTime = 30;
   scanRequest.maxChnTime = 100;

   /* set BSSType to default type */
   scanRequest.BSSType = eCSR_BSS_TYPE_ANY;

   scanRequest.SSIDs.numOfSSIDs = 1;
   scanRequest.SSIDs.SSIDList = &wcSSID;
   scanRequest.p2pSearch = VOS_FALSE;
       
   P2P_GetIE(p2pContext, p2pContext->sessionId, eP2P_GROUP_ID, &p2pIe, &p2pIeLen);
   vos_mem_copy(scanRequest.bssid, ((tP2PGroupId *)p2pIe)->deviceAddress, P2P_MAC_ADDRESS_LEN);

   P2P_GetIE(p2pContext, p2pContext->sessionId, eP2P_PROBE_REQ,  &scanRequest.pIEField, &len);

   scanRequest.uIEFieldLen = len;

   status = csrScanRequest( p2pContext->hHal, p2pContext->SMEsessionId, &scanRequest, &scanId, callback, pContext );

   if(scanRequest.pIEField)
   {
      vos_mem_free(scanRequest.pIEField);
   }

   if(p2pIe)
   {
      vos_mem_free(p2pIe);
   }
   return status;
}

tANI_U8 getP2PSessionIdFromSMESessionId(tHalHandle hHal, tANI_U8 SessionID)
{
   tpAniSirGlobal pMac = PMAC_STRUCT(hHal);
   tANI_U8 num_session;

   for (num_session = 0; num_session < MAX_NO_OF_P2P_SESSIONS; num_session++)
   {
      if(SessionID == pMac->p2pContext[num_session].SMEsessionId)
      {
         return pMac->p2pContext[num_session].sessionId;
      }
   }
   
   return CSR_SESSION_ID_INVALID;
}


/* SessionID is HDD session id, not SME sessionId*/
eHalStatus p2pCloseSession(tHalHandle hHal, tANI_U8 SessionID)
{
   tpAniSirGlobal pMac = PMAC_STRUCT(hHal);
   tp2pContext *pContext = &pMac->p2pContext[SessionID];

   pContext->SMEsessionId = CSR_SESSION_ID_INVALID;
   p2pResetContext(pContext);

   return eHAL_STATUS_SUCCESS;
}


eHalStatus p2pSetSessionId(tHalHandle hHal, tANI_U8 SessionID, tANI_U8 SmeSessionId)
{
   tpAniSirGlobal pMac = PMAC_STRUCT(hHal);

   pMac->p2pContext[SessionID].sessionId = SessionID;
   pMac->p2pContext[SessionID].SMEsessionId = SmeSessionId;

   return eHAL_STATUS_SUCCESS;
}

static tANI_BOOLEAN p2pIsGOportEnabled(tpAniSirGlobal pMac)
{

   tANI_U8 num_session = 0;

   for (num_session = 0; num_session < MAX_NO_OF_P2P_SESSIONS ; num_session++)
   {
      if (pMac->p2pContext[num_session].operatingmode == OPERATION_MODE_P2P_GROUP_OWNER)
      {
         return eANI_BOOLEAN_TRUE;
      }
   }

   return eANI_BOOLEAN_FALSE;
}

tANI_BOOLEAN p2pIsOperatingChannEqualListenChann(tHalHandle hHal, tANI_U8 SessionID)
{
   tpAniSirGlobal pMac = PMAC_STRUCT(hHal);

   if(pMac->p2pContext[SessionID].P2POperatingChannel == pMac->p2pContext[SessionID].P2PListenChannel)
   {
      return eANI_BOOLEAN_TRUE;
   }

   return eANI_BOOLEAN_FALSE;
}

eHalStatus p2pGetListenChannel(tHalHandle hHal, tANI_U8 SessionID, tANI_U8 *channel)
{
   tpAniSirGlobal pMac = PMAC_STRUCT(hHal);

   *channel = pMac->p2pContext[SessionID].P2PListenChannel;
  
   return eHAL_STATUS_SUCCESS;
}

eHalStatus p2pSetListenChannel(tHalHandle hHal, tANI_U8 SessionID, tANI_U8 channel)
{
   tpAniSirGlobal pMac = PMAC_STRUCT(hHal);
   tP2P_OperatingChannel p2pListenChannel;
   eHalStatus status = eHAL_STATUS_SUCCESS;

   if(csrRoamIsChannelValid(pMac, channel))
   {
      pMac->p2pContext[SessionID].P2PListenChannel = channel;
      p2pGetListenChannelAttrib(pMac, pMac->p2pContext[SessionID].sessionId, &p2pListenChannel);
      p2pListenChannel.channel = channel;
      p2pUpdateListenChannelAttrib(pMac, pMac->p2pContext[SessionID].sessionId, &p2pListenChannel);
   }
   else
   {
      VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_ERROR, 
<<<<<<< HEAD
         " %s fail with invalid channel %d", __FUNCTION__, channel);
=======
         " %s fail with invalid channel %d", __func__, channel);
>>>>>>> d97af3b... add prima wlan driver
      status = eHAL_STATUS_INVALID_PARAMETER;
   }
  
   return status;
}



eHalStatus p2pStopDiscovery(tHalHandle hHal, tANI_U8 SessionID)
{
   tpAniSirGlobal pMac = PMAC_STRUCT(hHal);
   eHalStatus status = eHAL_STATUS_SUCCESS;

<<<<<<< HEAD
   status = palTimerStop(pMac->hHdd, pMac->p2pContext[SessionID].discoverTimer);
   if (status != eHAL_STATUS_SUCCESS)
   {
      VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_ERROR, "%s Timer Stop status %d\n",  __FUNCTION__, status);
      return status;
   }

   VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_INFO, "%s Timer Stop status %d\n",  __FUNCTION__, status);
=======
   status = vos_timer_stop(&pMac->p2pContext[SessionID].discoverTimer);
   if (status != eHAL_STATUS_SUCCESS)
   {
      VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_ERROR, "%s Timer Stop status %d",  __func__, status);
      return status;
   }

   VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_INFO, "%s Timer Stop status %d",  __func__, status);
>>>>>>> d97af3b... add prima wlan driver
   p2pCallDiscoverCallback(&pMac->p2pContext[SessionID],  eP2P_DIRECTED_DISCOVER);

   status = p2pFsm( &pMac->p2pContext[SessionID], eP2P_TRIGGER_DISCONNECTED );

   return status;
}

//Purge P2P device/GO from the list
eHalStatus p2pPurgeDeviceList(tpAniSirGlobal pMac, tDblLinkList *pList)
{
   eHalStatus status = eHAL_STATUS_SUCCESS;
   tListElem *pEntry, *pNext;
   tCsrScanResult *pBssResult;
   tDot11fBeaconIEs *pIes;
    
   csrLLLock(pList);
   
   pEntry = csrLLPeekHead(pList, LL_ACCESS_NOLOCK);
   while( NULL != pEntry )
   {
      pNext = csrLLNext(pList, pEntry, LL_ACCESS_NOLOCK);
      pBssResult = GET_BASE_ADDR( pEntry, tCsrScanResult, Link );
      pIes = NULL;
      if(!HAL_STATUS_SUCCESS(csrGetParsedBssDescriptionIEs(pMac, &pBssResult->Result.BssDescriptor, &pIes)))
      {
         VOS_TRACE(VOS_MODULE_ID_SME, VOS_TRACE_LEVEL_ERROR,
            " %s fail to parse IEs. pEntry (0x%X)",
<<<<<<< HEAD
            __FUNCTION__, pEntry);
=======
            __func__, pEntry);
>>>>>>> d97af3b... add prima wlan driver
         pEntry = pNext;
         continue;
      }
      if( pIes->P2PBeaconProbeRes.present )
      {
         //Found a P2P BSS
         if(csrLLRemoveEntry(pList, pEntry, LL_ACCESS_NOLOCK) )
         {
            csrFreeScanResultEntry( pMac, pBssResult );
         }
      }
      palFreeMemory(pMac->hHdd, pIes);
      pEntry = pNext;
   }

   csrLLUnlock(pList);

   return (status);
}


eHalStatus sme_p2pFlushDeviceList(tHalHandle hHal, tANI_U8 HDDSessionId)
{
   eHalStatus status = eHAL_STATUS_FAILURE;
   tpAniSirGlobal pMac = PMAC_STRUCT( hHal );

   smsLog(pMac, LOG2, FL("enter"));
   status = sme_AcquireGlobalLock( &pMac->sme );
   if ( HAL_STATUS_SUCCESS( status ) )
   {
      status = p2pPurgeDeviceList(pMac, &pMac->scan.scanResultList);
      sme_ReleaseGlobalLock( &pMac->sme );
   }

   return (status);
}


eHalStatus sme_p2pResetSession(tHalHandle hHal, tANI_U8 HDDSessionId)
{
   eHalStatus status = eHAL_STATUS_FAILURE;
   tpAniSirGlobal pMac = PMAC_STRUCT( hHal );

   smsLog(pMac, LOG2, FL("enter"));
   status = sme_AcquireGlobalLock( &pMac->sme );
   if ( HAL_STATUS_SUCCESS( status ) )
   {
      if(MAX_NO_OF_P2P_SESSIONS > HDDSessionId)
      {
         p2pResetContext(&pMac->p2pContext[HDDSessionId]);
         status = eHAL_STATUS_SUCCESS;
      }
      sme_ReleaseGlobalLock( &pMac->sme );
   }

   return (status);
}



eHalStatus sme_p2pGetResultFilter(tHalHandle hHal, tANI_U8 HDDSessionId,
                              tCsrScanResultFilter *pFilter)
{
   eHalStatus status = eHAL_STATUS_FAILURE;
   tpAniSirGlobal pMac = PMAC_STRUCT( hHal );

   status = sme_AcquireGlobalLock( &pMac->sme );
   if ( HAL_STATUS_SUCCESS( status ) )
   {
      if(MAX_NO_OF_P2P_SESSIONS > HDDSessionId)
      {
         status = p2pGetResultFilter(&pMac->p2pContext[HDDSessionId], pFilter);
      }
      sme_ReleaseGlobalLock( &pMac->sme );
   }

   return status;
}



#endif //WLAN_FEATURE_P2P_INTERNAL

eHalStatus p2pProcessNoAReq(tpAniSirGlobal pMac, tSmeCmd *pNoACmd)
{
    tpP2pPsConfig pNoA;
    tSirMsgQ msg;
    eHalStatus status = eHAL_STATUS_SUCCESS;

    status = palAllocateMemory(pMac->hHdd, (void**)&pNoA, sizeof(tP2pPsConfig));
    if(HAL_STATUS_SUCCESS(status))
    {
        palZeroMemory(pMac->hHdd, pNoA, sizeof(tP2pPsConfig));
        pNoA->opp_ps = pNoACmd->u.NoACmd.NoA.opp_ps;
        pNoA->ctWindow = pNoACmd->u.NoACmd.NoA.ctWindow;
        pNoA->duration = pNoACmd->u.NoACmd.NoA.duration;
        pNoA->interval = pNoACmd->u.NoACmd.NoA.interval;
        pNoA->count = pNoACmd->u.NoACmd.NoA.count;
        pNoA->single_noa_duration = pNoACmd->u.NoACmd.NoA.single_noa_duration;
        pNoA->psSelection = pNoACmd->u.NoACmd.NoA.psSelection;
        pNoA->sessionid = pNoACmd->u.NoACmd.NoA.sessionid;
        msg.type = eWNI_SME_UPDATE_NOA;
        msg.bodyval = 0;
        msg.bodyptr = pNoA;
        limPostMsgApi(pMac, &msg);
    }   
    return status;
}




<<<<<<< HEAD
#endif //WLAN_FEATURE_P2P
=======
>>>>>>> d97af3b... add prima wlan driver
