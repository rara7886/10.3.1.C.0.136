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
>>>>>>> d97af3b... add prima wlan driver
=======

>>>>>>> 657b0e9... prima update
/*
 * Airgo Networks, Inc proprietary. All rights reserved.
 * This file schMessage.cc contains the message handler
 *
 * Author:      Sandesh Goel
 * Date:        02/25/02
 * History:-
 * Date            Modified by    Modification Information
 * --------------------------------------------------------------------
 *
 */
#include "palTypes.h"
#include "sirCommon.h"

<<<<<<< HEAD
<<<<<<< HEAD
#include "wniCfgAp.h"
#include "aniGlobal.h"
#ifdef FEATURE_WLAN_NON_INTEGRATED_SOC
#include "halCommonApi.h"
#endif
=======
#include "wniCfgSta.h"
#include "aniGlobal.h"
>>>>>>> d97af3b... add prima wlan driver
=======
#include "wniCfgAp.h"
#include "aniGlobal.h"
#ifdef FEATURE_WLAN_NON_INTEGRATED_SOC
#include "halCommonApi.h"
#endif
>>>>>>> 657b0e9... prima update
#include "cfgApi.h"
#include "limApi.h"
#include "pmmApi.h"
#include "limSendMessages.h"


#include "schApi.h"
#include "schDebug.h"

/// Minimum beacon interval allowed (in Kus)
#define SCH_BEACON_INTERVAL_MIN  10

/// Maximum beacon interval allowed (in Kus)
#define SCH_BEACON_INTERVAL_MAX  10000

/// convert the CW values into a tANI_U16
#define GET_CW(pCw) ((tANI_U16) ((*(pCw) << 8) + *((pCw) + 1)))

// local functions
static tSirRetStatus getWmmLocalParams(tpAniSirGlobal pMac, tANI_U32 params[][WNI_CFG_EDCA_ANI_ACBK_LOCAL_LEN]);
static void setSchEdcaParams(tpAniSirGlobal pMac, tANI_U32 params[][WNI_CFG_EDCA_ANI_ACBK_LOCAL_LEN], tpPESession psessionEntry);

// --------------------------------------------------------------------
/**
 * schSetBeaconInterval
 *
 * FUNCTION:
 *
 * LOGIC:
 *
 * ASSUMPTIONS:
 *
 * NOTE:
 *
 * @param None
 * @return None
 */

void schSetBeaconInterval(tpAniSirGlobal pMac,tpPESession psessionEntry)
{
    tANI_U32 bi;

    bi = psessionEntry->beaconParams.beaconInterval;

    if (bi < SCH_BEACON_INTERVAL_MIN || bi > SCH_BEACON_INTERVAL_MAX)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        schLog(pMac, LOGE, FL("Invalid beacon interval %d (should be [%d,%d]\n"),
=======
        schLog(pMac, LOGE, FL("Invalid beacon interval %d (should be [%d,%d]"),
>>>>>>> d97af3b... add prima wlan driver
=======
        schLog(pMac, LOGE, FL("Invalid beacon interval %d (should be [%d,%d]\n"),
>>>>>>> 657b0e9... prima update
               bi, SCH_BEACON_INTERVAL_MIN, SCH_BEACON_INTERVAL_MAX);
        return;
    }

    pMac->sch.schObject.gSchBeaconInterval = (tANI_U16)bi;
}


// --------------------------------------------------------------------
/**
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
 * schSetInitParams
 *
 * FUNCTION:
 * Initialize parameters from CFG which do not depend on any other config
 *
 * LOGIC:
 *
 * ASSUMPTIONS:
 *
 * NOTE:
 *
 * @param None
 * @return None
 */

#if 0 /* This function is not used anywhere */
void
schSetInitParams(tpAniSirGlobal pMac)
{
    pMac->sch.schObject.gSchDTIMCount = 0;
    pMac->sch.schObject.gSchCFPCount = 0;

    schQosUpdateLocal(pMac);

    PELOG1(schLog(pMac, LOG1, FL("Finished init of SCH params\n"));)
}
#endif

// --------------------------------------------------------------------
/**
<<<<<<< HEAD
=======
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
 * schProcessMessage
 *
 * FUNCTION:
 *
 * LOGIC:
 *
 * ASSUMPTIONS:
 *
 * NOTE:
 *
 * @param None
 * @return None
 */

void schProcessMessage(tpAniSirGlobal pMac,tpSirMsgQ pSchMsg)
{
#ifdef FIXME_GEN6
    tANI_U32            *pBD;
    tpSirMacMgmtHdr     mh;
    void                *pPacket;
#endif
    tANI_U32            val;

    tpPESession psessionEntry = &pMac->lim.gpSession[0];  //TBD-RAJESH HOW TO GET sessionEntry?????
<<<<<<< HEAD
<<<<<<< HEAD
    PELOG3(schLog(pMac, LOG3, FL("Received message (%x) \n"), pSchMsg->type);)
=======
    PELOG3(schLog(pMac, LOG3, FL("Received message (%x) "), pSchMsg->type);)
>>>>>>> d97af3b... add prima wlan driver
=======
    PELOG3(schLog(pMac, LOG3, FL("Received message (%x) \n"), pSchMsg->type);)
>>>>>>> 657b0e9... prima update

    switch (pSchMsg->type)
    {
#ifdef FIXME_GEN6
        case SIR_BB_XPORT_MGMT_MSG:
            pMac->sch.gSchBBXportRcvCnt++;


<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
#if defined (ANI_OS_TYPE_LINUX) || defined (ANI_OS_TYPE_OSX)
            {
                palGetPacketDataPtr( pMac->hHdd, HAL_TXRX_FRM_802_11_MGMT, pSchMsg->bodyptr, (void **) &(pBD) );
            }
#else
            pBD = (tANI_U32 *) pSchMsg->bodyptr;
#endif
<<<<<<< HEAD
=======
            pBD = (tANI_U32 *) pSchMsg->bodyptr;
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update


            mh = SIR_MAC_BD_TO_MPDUHEADER( pBD );

            if (mh->fc.type == SIR_MAC_MGMT_FRAME &&
                mh->fc.subType == SIR_MAC_MGMT_BEACON)
                schBeaconProcess(pMac, pBD);
            else
            {
<<<<<<< HEAD
<<<<<<< HEAD
                schLog(pMac, LOGE, FL("Unexpected message (%d,%d) rcvd\n"),
                       mh->fc.type, mh->fc.subType);
                pMac->sch.gSchUnknownRcvCnt++;
            }
#if defined (ANI_OS_TYPE_LINUX) || defined (ANI_OS_TYPE_OSX)
        // Free up allocated SK BUF
        //for Windows, this is freed up by palHandleRxFrames
        palPktFree( pMac->hHdd, HAL_TXRX_FRM_802_11_MGMT, pBD, (void *) pSchMsg->bodyptr) ;
#endif
=======
                schLog(pMac, LOGE, FL("Unexpected message (%d,%d) rcvd"),
                       mh->fc.type, mh->fc.subType);
                pMac->sch.gSchUnknownRcvCnt++;
            }
>>>>>>> d97af3b... add prima wlan driver
=======
                schLog(pMac, LOGE, FL("Unexpected message (%d,%d) rcvd\n"),
                       mh->fc.type, mh->fc.subType);
                pMac->sch.gSchUnknownRcvCnt++;
            }
#if defined (ANI_OS_TYPE_LINUX) || defined (ANI_OS_TYPE_OSX)
        // Free up allocated SK BUF
        //for Windows, this is freed up by palHandleRxFrames
        palPktFree( pMac->hHdd, HAL_TXRX_FRM_802_11_MGMT, pBD, (void *) pSchMsg->bodyptr) ;
#endif
>>>>>>> 657b0e9... prima update
            break;
#endif

        case SIR_SCH_CHANNEL_SWITCH_REQUEST:
            schLog(pMac, LOGE,
<<<<<<< HEAD
<<<<<<< HEAD
                   FL("Channel switch request not handled\n"));
            break;

        case SIR_SCH_START_SCAN_REQ:
            SIR_SCHED_LOCK();
=======
                   FL("Channel switch request not handled"));
            break;

        case SIR_SCH_START_SCAN_REQ:
>>>>>>> d97af3b... add prima wlan driver
=======
                   FL("Channel switch request not handled\n"));
            break;

        case SIR_SCH_START_SCAN_REQ:
            SIR_SCHED_LOCK();
>>>>>>> 657b0e9... prima update
            pMac->sch.gSchScanReqRcvd = true;
            if (pMac->sch.gSchHcfEnabled)
            {
                // In HCF mode, wait for TFP to stop before sending a response
                if (pMac->sch.schObject.gSchCFBInitiated ||
                    pMac->sch.schObject.gSchCFPInitiated)
                {
                   PELOG1(schLog(pMac, LOG1,
                           FL("Waiting for TFP to halt before sending "
<<<<<<< HEAD
<<<<<<< HEAD
                              "start scan response\n"));)
=======
                              "start scan response"));)
>>>>>>> d97af3b... add prima wlan driver
=======
                              "start scan response\n"));)
>>>>>>> 657b0e9... prima update
                }
                else
                    schSendStartScanRsp(pMac);
            }
            else
            {
                // In eDCF mode, send the response right away
                schSendStartScanRsp(pMac);
            }
<<<<<<< HEAD
<<<<<<< HEAD
            SIR_SCHED_UNLOCK();
=======
>>>>>>> d97af3b... add prima wlan driver
=======
            SIR_SCHED_UNLOCK();
>>>>>>> 657b0e9... prima update
            break;

        case SIR_SCH_END_SCAN_NTF:
           PELOG3(schLog(pMac, LOG3,
<<<<<<< HEAD
<<<<<<< HEAD
                   FL("Received STOP_SCAN_NTF from LIM\n"));)
            pMac->sch.gSchScanReqRcvd = false;
#ifdef WMM_SA
#if (WNI_POLARIS_FW_PRODUCT == AP)
            if (psessionEntry->limSystemRole == eLIM_AP_ROLE && pMac->sch.gSchHcfEnabled)
                startCFB();
#endif
#endif
=======
                   FL("Received STOP_SCAN_NTF from LIM"));)
            pMac->sch.gSchScanReqRcvd = false;
>>>>>>> d97af3b... add prima wlan driver
=======
                   FL("Received STOP_SCAN_NTF from LIM\n"));)
            pMac->sch.gSchScanReqRcvd = false;
#ifdef WMM_SA
#if (WNI_POLARIS_FW_PRODUCT == AP)
            if (psessionEntry->limSystemRole == eLIM_AP_ROLE && pMac->sch.gSchHcfEnabled)
                startCFB();
#endif
#endif
>>>>>>> 657b0e9... prima update
            break;

        case SIR_CFG_PARAM_UPDATE_IND:

            if (wlan_cfgGetInt(pMac, (tANI_U16) pSchMsg->bodyval, &val) != eSIR_SUCCESS)
<<<<<<< HEAD
<<<<<<< HEAD
                schLog(pMac, LOGP, FL("failed to cfg get id %d\n"), pSchMsg->bodyval);
=======
                schLog(pMac, LOGP, FL("failed to cfg get id %d"), pSchMsg->bodyval);
>>>>>>> d97af3b... add prima wlan driver
=======
                schLog(pMac, LOGP, FL("failed to cfg get id %d\n"), pSchMsg->bodyval);
>>>>>>> 657b0e9... prima update

            switch (pSchMsg->bodyval)
            {
                case WNI_CFG_BEACON_INTERVAL:
                    // What to do for IBSS ?? - TBD
                    if (psessionEntry->limSystemRole == eLIM_AP_ROLE)
                        schSetBeaconInterval(pMac,psessionEntry);
                    break;


                case WNI_CFG_DTIM_PERIOD:
                    pMac->sch.schObject.gSchDTIMCount = 0;
                    break;

                case WNI_CFG_CFP_PERIOD:
                    pMac->sch.schObject.gSchCFPCount = 0;
                    break;

                case WNI_CFG_EDCA_PROFILE:
                    schEdcaProfileUpdate(pMac, psessionEntry);
                    break;

                case WNI_CFG_EDCA_ANI_ACBK_LOCAL:
                case WNI_CFG_EDCA_ANI_ACBE_LOCAL:
                case WNI_CFG_EDCA_ANI_ACVI_LOCAL:
                case WNI_CFG_EDCA_ANI_ACVO_LOCAL:
                case WNI_CFG_EDCA_WME_ACBK_LOCAL:
                case WNI_CFG_EDCA_WME_ACBE_LOCAL:
                case WNI_CFG_EDCA_WME_ACVI_LOCAL:
                case WNI_CFG_EDCA_WME_ACVO_LOCAL:
                    if (psessionEntry->limSystemRole == eLIM_AP_ROLE)
                        schQosUpdateLocal(pMac, psessionEntry);
                    break;

                case WNI_CFG_EDCA_ANI_ACBK:
                case WNI_CFG_EDCA_ANI_ACBE:
                case WNI_CFG_EDCA_ANI_ACVI:
                case WNI_CFG_EDCA_ANI_ACVO:
                case WNI_CFG_EDCA_WME_ACBK:
                case WNI_CFG_EDCA_WME_ACBE:
                case WNI_CFG_EDCA_WME_ACVI:
                case WNI_CFG_EDCA_WME_ACVO:
                    if (psessionEntry->limSystemRole == eLIM_AP_ROLE)
                    {
                        psessionEntry->gLimEdcaParamSetCount++;
                        schQosUpdateBroadcast(pMac, psessionEntry);
                    }
                    break;

                default:
<<<<<<< HEAD
<<<<<<< HEAD
                    schLog(pMac, LOGE, FL("Cfg param %d indication not handled\n"),
=======
                    schLog(pMac, LOGE, FL("Cfg param %d indication not handled"),
>>>>>>> d97af3b... add prima wlan driver
=======
                    schLog(pMac, LOGE, FL("Cfg param %d indication not handled\n"),
>>>>>>> 657b0e9... prima update
                           pSchMsg->bodyval);
            }
            break;

        default:
<<<<<<< HEAD
<<<<<<< HEAD
            schLog(pMac, LOGE, FL("Unknown message in schMsgQ type %d\n"),
=======
            schLog(pMac, LOGE, FL("Unknown message in schMsgQ type %d"),
>>>>>>> d97af3b... add prima wlan driver
=======
            schLog(pMac, LOGE, FL("Unknown message in schMsgQ type %d\n"),
>>>>>>> 657b0e9... prima update
                   pSchMsg->type);
    }

}


<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
// --------------------------------------------------------------------
/**
 * schProcessMessageQueue
 *
 * FUNCTION:
 *
 * LOGIC:
 *
 * ASSUMPTIONS:
 *
 * NOTE:
 *
 * @param None
 * @return None
 */

void schProcessMessageQueue(tpAniSirGlobal pMac)
{
    tSirMsgQ schMsg;

#if (WNI_POLARIS_FW_PRODUCT == AP)
    if (pMac->lim.gLimSystemRole == eLIM_AP_ROLE)
        pMac->sch.gSchRRRecd = false;
#endif
    memset(&schMsg, 0, sizeof(tSirMsgQ));
    while (1)
    {
        if (tx_queue_receive(&pMac->sys.gSirSchMsgQ, (void *) &schMsg, TX_WAIT_FOREVER)
            != TX_SUCCESS)
            break;

        schProcessMessage(pMac, &schMsg);
    }
#ifdef WMM_SA
#if (WNI_POLARIS_FW_PRODUCT == AP)
    if (pMac->lim.gLimSystemRole == eLIM_AP_ROLE && pMac->sch.gSchRRRecd)
        startCFB();
#endif
#endif
}

#if 0 /* This function is not used anywhere */
// set the default values for all params of interest
void
schUpdateQosInfo( tpAniSirGlobal pMac)
{
    // need to populate local info only on AP or IBSS, beacon processing
    // takes care of others
    psessionEntry->gLimEdcaParamSetCount = 0xFF;

    if (pMac->lim.gLimSystemRole == eLIM_STA_IN_IBSS_ROLE)
    {
        schQosUpdateLocal(pMac);
    }
    else if (pMac->lim.gLimSystemRole == eLIM_AP_ROLE)
    {
        // fill local AP values
        schQosUpdateLocal(pMac);

        // fill broadcast values
        schQosUpdateBroadcast(pMac, psessionEntry);
    }
}

#endif

<<<<<<< HEAD
=======
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
// get the local or broadcast parameters based on the profile sepcified in the config
// params are delivered in this order: BK, BE, VI, VO
tSirRetStatus
schGetParams(
    tpAniSirGlobal pMac,
    tANI_U32            params[][WNI_CFG_EDCA_ANI_ACBK_LOCAL_LEN],
    tANI_U8           local)
{
    tANI_U32 val;
    tANI_U32 i,idx;
    tANI_U32 *prf;

    tANI_U32 ani_l[] = { WNI_CFG_EDCA_ANI_ACBE_LOCAL,WNI_CFG_EDCA_ANI_ACBK_LOCAL,
                   WNI_CFG_EDCA_ANI_ACVI_LOCAL, WNI_CFG_EDCA_ANI_ACVO_LOCAL };
    tANI_U32 wme_l[] = {WNI_CFG_EDCA_WME_ACBE_LOCAL, WNI_CFG_EDCA_WME_ACBK_LOCAL,
                   WNI_CFG_EDCA_WME_ACVI_LOCAL, WNI_CFG_EDCA_WME_ACVO_LOCAL};
    tANI_U32 demo_l[] = {WNI_CFG_EDCA_TIT_DEMO_ACBE_LOCAL, WNI_CFG_EDCA_TIT_DEMO_ACBK_LOCAL,
                   WNI_CFG_EDCA_TIT_DEMO_ACVI_LOCAL, WNI_CFG_EDCA_TIT_DEMO_ACVO_LOCAL};
    tANI_U32 ani_b[] = {WNI_CFG_EDCA_ANI_ACBE, WNI_CFG_EDCA_ANI_ACBK,
                   WNI_CFG_EDCA_ANI_ACVI, WNI_CFG_EDCA_ANI_ACVO};
    tANI_U32 wme_b[] = {WNI_CFG_EDCA_WME_ACBE, WNI_CFG_EDCA_WME_ACBK,
                   WNI_CFG_EDCA_WME_ACVI, WNI_CFG_EDCA_WME_ACVO};
    tANI_U32 demo_b[] = {WNI_CFG_EDCA_TIT_DEMO_ACBE, WNI_CFG_EDCA_TIT_DEMO_ACBK,
                   WNI_CFG_EDCA_TIT_DEMO_ACVI, WNI_CFG_EDCA_TIT_DEMO_ACVO};

    if (wlan_cfgGetInt(pMac, WNI_CFG_EDCA_PROFILE, &val) != eSIR_SUCCESS)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        schLog(pMac, LOGP, FL("failed to cfg get EDCA_PROFILE id %d\n"),
=======
        schLog(pMac, LOGP, FL("failed to cfg get EDCA_PROFILE id %d"),
>>>>>>> d97af3b... add prima wlan driver
=======
        schLog(pMac, LOGP, FL("failed to cfg get EDCA_PROFILE id %d\n"),
>>>>>>> 657b0e9... prima update
               WNI_CFG_EDCA_PROFILE);
        return eSIR_FAILURE;
    }

    if (val >= WNI_CFG_EDCA_PROFILE_MAX)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        schLog(pMac, LOGE, FL("Invalid EDCA_PROFILE %d, using %d instead\n"),
=======
        schLog(pMac, LOGE, FL("Invalid EDCA_PROFILE %d, using %d instead"),
>>>>>>> d97af3b... add prima wlan driver
=======
        schLog(pMac, LOGE, FL("Invalid EDCA_PROFILE %d, using %d instead\n"),
>>>>>>> 657b0e9... prima update
               val, WNI_CFG_EDCA_PROFILE_ANI);
        val = WNI_CFG_EDCA_PROFILE_ANI;
    }

<<<<<<< HEAD
<<<<<<< HEAD
    schLog(pMac, LOGW, FL("EdcaProfile: Using %d (%s)\n"),  val,
=======
    schLog(pMac, LOGW, FL("EdcaProfile: Using %d (%s)"),  val,
>>>>>>> d97af3b... add prima wlan driver
=======
    schLog(pMac, LOGW, FL("EdcaProfile: Using %d (%s)\n"),  val,
>>>>>>> 657b0e9... prima update
           ((val == WNI_CFG_EDCA_PROFILE_WMM) ? "WMM"
           : ( (val == WNI_CFG_EDCA_PROFILE_TIT_DEMO) ? "Titan" : "HiPerf")));

    if (local)
    {
        switch (val)
        {
           case WNI_CFG_EDCA_PROFILE_WMM:
              prf = &wme_l[0];
              break;
           case WNI_CFG_EDCA_PROFILE_TIT_DEMO:
              prf = &demo_l[0];
              break;
           case WNI_CFG_EDCA_PROFILE_ANI:
           default:
              prf = &ani_l[0];
              break;
        }
    }
    else
    {
        switch (val)
        {
           case WNI_CFG_EDCA_PROFILE_WMM:
              prf = &wme_b[0];
              break;
           case WNI_CFG_EDCA_PROFILE_TIT_DEMO:
              prf = &demo_b[0];
              break;
           case WNI_CFG_EDCA_PROFILE_ANI:
           default:
              prf = &ani_b[0];
              break;
        }
    }

    for (i=0; i < 4; i++)
    {
        tANI_U8  data[WNI_CFG_EDCA_ANI_ACBK_LEN];
        tANI_U32 len = WNI_CFG_EDCA_ANI_ACBK_LOCAL_LEN;
        if (wlan_cfgGetStr(pMac, (tANI_U16) prf[i], (tANI_U8 *) &data[0], &len) != eSIR_SUCCESS)
        {
<<<<<<< HEAD
<<<<<<< HEAD
            schLog(pMac, LOGP, FL("cfgGet failed for %d\n"), prf[i]);
=======
            schLog(pMac, LOGP, FL("cfgGet failed for %d"), prf[i]);
>>>>>>> d97af3b... add prima wlan driver
=======
            schLog(pMac, LOGP, FL("cfgGet failed for %d\n"), prf[i]);
>>>>>>> 657b0e9... prima update
            return eSIR_FAILURE;
        }
        if (len > WNI_CFG_EDCA_ANI_ACBK_LOCAL_LEN)
        {
<<<<<<< HEAD
<<<<<<< HEAD
            schLog(pMac, LOGE, FL("cfgGet for %d: length is %d instead of %d\n"),
=======
            schLog(pMac, LOGE, FL("cfgGet for %d: length is %d instead of %d"),
>>>>>>> d97af3b... add prima wlan driver
=======
            schLog(pMac, LOGE, FL("cfgGet for %d: length is %d instead of %d\n"),
>>>>>>> 657b0e9... prima update
                   prf[i], len, WNI_CFG_EDCA_ANI_ACBK_LOCAL_LEN);
            return eSIR_FAILURE;
        }
        for (idx=0; idx < len; idx++)
            params[i][idx] = (tANI_U32) data[idx];
    }
<<<<<<< HEAD
<<<<<<< HEAD
    PELOG1(schLog(pMac, LOG1, FL("GetParams: local=%d, profile = %d Done\n"), local, val);)
=======
    PELOG1(schLog(pMac, LOG1, FL("GetParams: local=%d, profile = %d Done"), local, val);)
>>>>>>> d97af3b... add prima wlan driver
=======
    PELOG1(schLog(pMac, LOG1, FL("GetParams: local=%d, profile = %d Done\n"), local, val);)
>>>>>>> 657b0e9... prima update
    return eSIR_SUCCESS;
}

static void broadcastWMMOfConcurrentSTASession(tpAniSirGlobal pMac, tpPESession psessionEntry)
{
    tANI_U8         i,j;
    tpPESession     pConcurrentStaSessionEntry;

    for (i =0;i < pMac->lim.maxBssId;i++)
    {
        /* Find another INFRA STA AP session on same operating channel. The session entry passed to this API is for GO/SoftAP session that is getting added currently */
        if ( (pMac->lim.gpSession[i].valid == TRUE ) &&
             (pMac->lim.gpSession[i].peSessionId != psessionEntry->peSessionId) &&
             (pMac->lim.gpSession[i].currentOperChannel == psessionEntry->currentOperChannel) &&
             (pMac->lim.gpSession[i].limSystemRole == eLIM_STA_ROLE)
           )
        {
            pConcurrentStaSessionEntry = &(pMac->lim.gpSession[i]);
            for (j=0; j<MAX_NUM_AC; j++)
            {
                psessionEntry->gLimEdcaParamsBC[j].aci.acm = pConcurrentStaSessionEntry->gLimEdcaParams[j].aci.acm;
                psessionEntry->gLimEdcaParamsBC[j].aci.aifsn = pConcurrentStaSessionEntry->gLimEdcaParams[j].aci.aifsn;
                psessionEntry->gLimEdcaParamsBC[j].cw.min =  pConcurrentStaSessionEntry->gLimEdcaParams[j].cw.min;
                psessionEntry->gLimEdcaParamsBC[j].cw.max =  pConcurrentStaSessionEntry->gLimEdcaParams[j].cw.max;
                psessionEntry->gLimEdcaParamsBC[j].txoplimit=  pConcurrentStaSessionEntry->gLimEdcaParams[j].txoplimit;

<<<<<<< HEAD
<<<<<<< HEAD
               PELOG1(schLog(pMac, LOG1, "QoSUpdateBCast changed again due to concurrent INFRA STA session: AC :%d: AIFSN: %d, ACM %d, CWmin %d, CWmax %d, TxOp %d\n",
=======
               PELOG1(schLog(pMac, LOG1, "QoSUpdateBCast changed again due to concurrent INFRA STA session: AC :%d: AIFSN: %d, ACM %d, CWmin %d, CWmax %d, TxOp %d",
>>>>>>> d97af3b... add prima wlan driver
=======
               PELOG1(schLog(pMac, LOG1, "QoSUpdateBCast changed again due to concurrent INFRA STA session: AC :%d: AIFSN: %d, ACM %d, CWmin %d, CWmax %d, TxOp %d\n",
>>>>>>> 657b0e9... prima update
                        j,
                        psessionEntry->gLimEdcaParamsBC[j].aci.aifsn,
                        psessionEntry->gLimEdcaParamsBC[j].aci.acm,
                        psessionEntry->gLimEdcaParamsBC[j].cw.min,
                        psessionEntry->gLimEdcaParamsBC[j].cw.max,
                        psessionEntry->gLimEdcaParamsBC[j].txoplimit);)

            }
            /* Once atleast one concurrent session on same channel is found and WMM broadcast params for current SoftAP/GO session updated, return*/
            break;
        }
    }
}

void
schQosUpdateBroadcast(tpAniSirGlobal pMac, tpPESession psessionEntry)
{
    tANI_U32        params[4][WNI_CFG_EDCA_ANI_ACBK_LOCAL_LEN];
    tANI_U32        cwminidx, cwmaxidx, txopidx;
    tANI_U32        phyMode;
    tANI_U8         i;

    if (schGetParams(pMac, params, false) != eSIR_SUCCESS)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        PELOGE(schLog(pMac, LOGE, FL("QosUpdateBroadcast: failed\n"));)
=======
        PELOGE(schLog(pMac, LOGE, FL("QosUpdateBroadcast: failed"));)
>>>>>>> d97af3b... add prima wlan driver
=======
        PELOGE(schLog(pMac, LOGE, FL("QosUpdateBroadcast: failed\n"));)
>>>>>>> 657b0e9... prima update
        return;
    }
    limGetPhyMode(pMac, &phyMode, psessionEntry);

<<<<<<< HEAD
<<<<<<< HEAD
    PELOG1(schLog(pMac, LOG1, "QosUpdBcast: mode %d\n", phyMode);)
=======
    PELOG1(schLog(pMac, LOG1, "QosUpdBcast: mode %d", phyMode);)
>>>>>>> d97af3b... add prima wlan driver
=======
    PELOG1(schLog(pMac, LOG1, "QosUpdBcast: mode %d\n", phyMode);)
>>>>>>> 657b0e9... prima update

    if (phyMode == WNI_CFG_PHY_MODE_11G)
    {
        cwminidx = WNI_CFG_EDCA_PROFILE_CWMING_IDX;
        cwmaxidx = WNI_CFG_EDCA_PROFILE_CWMAXG_IDX;
        txopidx  = WNI_CFG_EDCA_PROFILE_TXOPG_IDX;
    }
    else if (phyMode == WNI_CFG_PHY_MODE_11B)
    {
        cwminidx = WNI_CFG_EDCA_PROFILE_CWMINB_IDX;
        cwmaxidx = WNI_CFG_EDCA_PROFILE_CWMAXB_IDX;
        txopidx  = WNI_CFG_EDCA_PROFILE_TXOPB_IDX;
    }
    else // This can happen if mode is not set yet, assume 11a mode
    {
        cwminidx = WNI_CFG_EDCA_PROFILE_CWMINA_IDX;
        cwmaxidx = WNI_CFG_EDCA_PROFILE_CWMAXA_IDX;
        txopidx  = WNI_CFG_EDCA_PROFILE_TXOPA_IDX;
    }


    for(i=0; i<MAX_NUM_AC; i++)
    {
        psessionEntry->gLimEdcaParamsBC[i].aci.acm = (tANI_U8) params[i][WNI_CFG_EDCA_PROFILE_ACM_IDX];
        psessionEntry->gLimEdcaParamsBC[i].aci.aifsn = (tANI_U8) params[i][WNI_CFG_EDCA_PROFILE_AIFSN_IDX];
        psessionEntry->gLimEdcaParamsBC[i].cw.min =  convertCW(GET_CW(&params[i][cwminidx]));
        psessionEntry->gLimEdcaParamsBC[i].cw.max =  convertCW(GET_CW(&params[i][cwmaxidx]));
        psessionEntry->gLimEdcaParamsBC[i].txoplimit=  (tANI_U16) params[i][txopidx];

<<<<<<< HEAD
<<<<<<< HEAD
       PELOG1(schLog(pMac, LOG1, "QoSUpdateBCast: AC :%d: AIFSN: %d, ACM %d, CWmin %d, CWmax %d, TxOp %d\n", i,
=======
       PELOG1(schLog(pMac, LOG1, "QoSUpdateBCast: AC :%d: AIFSN: %d, ACM %d, CWmin %d, CWmax %d, TxOp %d", i,
>>>>>>> d97af3b... add prima wlan driver
=======
       PELOG1(schLog(pMac, LOG1, "QoSUpdateBCast: AC :%d: AIFSN: %d, ACM %d, CWmin %d, CWmax %d, TxOp %d\n", i,
>>>>>>> 657b0e9... prima update
                psessionEntry->gLimEdcaParamsBC[i].aci.aifsn,
                psessionEntry->gLimEdcaParamsBC[i].aci.acm,
                psessionEntry->gLimEdcaParamsBC[i].cw.min,
                psessionEntry->gLimEdcaParamsBC[i].cw.max,
                psessionEntry->gLimEdcaParamsBC[i].txoplimit);)

    }

    /* If there exists a concurrent STA-AP session, use its WMM params to broadcast in beacons. WFA Wifi Direct test plan 6.1.14 requirement */
    broadcastWMMOfConcurrentSTASession(pMac, psessionEntry);

    if (schSetFixedBeaconFields(pMac,psessionEntry) != eSIR_SUCCESS)
<<<<<<< HEAD
<<<<<<< HEAD
        PELOGE(schLog(pMac, LOGE, "Unable to set beacon fields!\n");)
=======
        PELOGE(schLog(pMac, LOGE, "Unable to set beacon fields!");)
>>>>>>> d97af3b... add prima wlan driver
=======
        PELOGE(schLog(pMac, LOGE, "Unable to set beacon fields!\n");)
>>>>>>> 657b0e9... prima update
}

void
schQosUpdateLocal(tpAniSirGlobal pMac, tpPESession psessionEntry)
{

    tANI_U32 params[4][WNI_CFG_EDCA_ANI_ACBK_LOCAL_LEN];
    tANI_BOOLEAN highPerformance=eANI_BOOLEAN_TRUE;

    if (schGetParams(pMac, params, true /*local*/) != eSIR_SUCCESS)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        PELOGE(schLog(pMac, LOGE, FL("schGetParams(local) failed\n"));)
=======
        PELOGE(schLog(pMac, LOGE, FL("schGetParams(local) failed"));)
>>>>>>> d97af3b... add prima wlan driver
=======
        PELOGE(schLog(pMac, LOGE, FL("schGetParams(local) failed\n"));)
>>>>>>> 657b0e9... prima update
        return;
    }

    setSchEdcaParams(pMac, params, psessionEntry);

    if (psessionEntry->limSystemRole == eLIM_AP_ROLE)
    {
        if (pMac->lim.gLimNumOfAniSTAs)
            highPerformance = eANI_BOOLEAN_TRUE;
        else
            highPerformance = eANI_BOOLEAN_FALSE;
    }
    else if (psessionEntry->limSystemRole == eLIM_STA_IN_IBSS_ROLE)
    {
        highPerformance = eANI_BOOLEAN_TRUE;
    }

    //For AP, the bssID is stored in LIM Global context.
    limSendEdcaParams(pMac, psessionEntry->gLimEdcaParams, psessionEntry->bssIdx, highPerformance);
}

/** ----------------------------------------------------------
\fn      schSetDefaultEdcaParams
\brief   This function sets the gLimEdcaParams to the default
\        local wmm profile.
\param   tpAniSirGlobal  pMac
\return  none
\ ------------------------------------------------------------ */
void
schSetDefaultEdcaParams(tpAniSirGlobal pMac, tpPESession psessionEntry)
{
    tANI_U32 params[4][WNI_CFG_EDCA_ANI_ACBK_LOCAL_LEN];

    if (getWmmLocalParams(pMac, params) != eSIR_SUCCESS)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        PELOGE(schLog(pMac, LOGE, FL("getWmmLocalParams() failed\n"));)
=======
        PELOGE(schLog(pMac, LOGE, FL("getWmmLocalParams() failed"));)
>>>>>>> d97af3b... add prima wlan driver
=======
        PELOGE(schLog(pMac, LOGE, FL("getWmmLocalParams() failed\n"));)
>>>>>>> 657b0e9... prima update
        return;
    }

    setSchEdcaParams(pMac, params, psessionEntry);
    return;
}


/** ----------------------------------------------------------
\fn      setSchEdcaParams
\brief   This function fills in the gLimEdcaParams structure
\        with the given edca params.
\param   tpAniSirGlobal  pMac
\return  none
\ ------------------------------------------------------------ */
static void
setSchEdcaParams(tpAniSirGlobal pMac, tANI_U32 params[][WNI_CFG_EDCA_ANI_ACBK_LOCAL_LEN], tpPESession psessionEntry)
{
    tANI_U32 i;
    tANI_U32 cwminidx, cwmaxidx, txopidx;
    tANI_U32 phyMode;

    limGetPhyMode(pMac, &phyMode, psessionEntry);

<<<<<<< HEAD
<<<<<<< HEAD
    PELOG1(schLog(pMac, LOG1, FL("limGetPhyMode() = %d\n"), phyMode);)
=======
    PELOG1(schLog(pMac, LOG1, FL("limGetPhyMode() = %d"), phyMode);)
>>>>>>> d97af3b... add prima wlan driver
=======
    PELOG1(schLog(pMac, LOG1, FL("limGetPhyMode() = %d\n"), phyMode);)
>>>>>>> 657b0e9... prima update

    //if (pMac->lim.gLimPhyMode == WNI_CFG_PHY_MODE_11G)
    if (phyMode == WNI_CFG_PHY_MODE_11G)
    {
        cwminidx = WNI_CFG_EDCA_PROFILE_CWMING_IDX;
        cwmaxidx = WNI_CFG_EDCA_PROFILE_CWMAXG_IDX;
        txopidx  = WNI_CFG_EDCA_PROFILE_TXOPG_IDX;
    }
    //else if (pMac->lim.gLimPhyMode == WNI_CFG_PHY_MODE_11B)
    else if (phyMode == WNI_CFG_PHY_MODE_11B)
    {
        cwminidx = WNI_CFG_EDCA_PROFILE_CWMINB_IDX;
        cwmaxidx = WNI_CFG_EDCA_PROFILE_CWMAXB_IDX;
        txopidx  = WNI_CFG_EDCA_PROFILE_TXOPB_IDX;
    }
    else // This can happen if mode is not set yet, assume 11a mode
    {
        cwminidx = WNI_CFG_EDCA_PROFILE_CWMINA_IDX;
        cwmaxidx = WNI_CFG_EDCA_PROFILE_CWMAXA_IDX;
        txopidx  = WNI_CFG_EDCA_PROFILE_TXOPA_IDX;
    }

    for(i=0; i<MAX_NUM_AC; i++)
    {
        psessionEntry->gLimEdcaParams[i].aci.acm = (tANI_U8) params[i][WNI_CFG_EDCA_PROFILE_ACM_IDX];
        psessionEntry->gLimEdcaParams[i].aci.aifsn = (tANI_U8) params[i][WNI_CFG_EDCA_PROFILE_AIFSN_IDX];
        psessionEntry->gLimEdcaParams[i].cw.min =  convertCW(GET_CW(&params[i][cwminidx]));
        psessionEntry->gLimEdcaParams[i].cw.max =  convertCW(GET_CW(&params[i][cwmaxidx]));
        psessionEntry->gLimEdcaParams[i].txoplimit=  (tANI_U16) params[i][txopidx];

<<<<<<< HEAD
<<<<<<< HEAD
       PELOG1(schLog(pMac, LOG1, FL("AC :%d: AIFSN: %d, ACM %d, CWmin %d, CWmax %d, TxOp %d\n"), i,
=======
       PELOG1(schLog(pMac, LOG1, FL("AC :%d: AIFSN: %d, ACM %d, CWmin %d, CWmax %d, TxOp %d"), i,
>>>>>>> d97af3b... add prima wlan driver
=======
       PELOG1(schLog(pMac, LOG1, FL("AC :%d: AIFSN: %d, ACM %d, CWmin %d, CWmax %d, TxOp %d\n"), i,
>>>>>>> 657b0e9... prima update
                psessionEntry->gLimEdcaParams[i].aci.aifsn,
                psessionEntry->gLimEdcaParams[i].aci.acm,
                psessionEntry->gLimEdcaParams[i].cw.min,
                psessionEntry->gLimEdcaParams[i].cw.max,
                psessionEntry->gLimEdcaParams[i].txoplimit);)

    }
    return;
}

/** ----------------------------------------------------------
\fn      getWmmLocalParams
\brief   This function gets the WMM local edca parameters.
\param   tpAniSirGlobal  pMac
\param   tANI_U32 params[][WNI_CFG_EDCA_ANI_ACBK_LOCAL_LEN]
\return  none
\ ------------------------------------------------------------ */
static tSirRetStatus
getWmmLocalParams(tpAniSirGlobal  pMac,  tANI_U32 params[][WNI_CFG_EDCA_ANI_ACBK_LOCAL_LEN])
{
    tANI_U32 i,idx;
    tANI_U32 *prf;
    tANI_U32 wme_l[] = {WNI_CFG_EDCA_WME_ACBE_LOCAL, WNI_CFG_EDCA_WME_ACBK_LOCAL,
                   WNI_CFG_EDCA_WME_ACVI_LOCAL, WNI_CFG_EDCA_WME_ACVO_LOCAL};

    prf = &wme_l[0];
    for (i=0; i < 4; i++)
    {
        tANI_U8  data[WNI_CFG_EDCA_ANI_ACBK_LEN];
        tANI_U32 len = WNI_CFG_EDCA_ANI_ACBK_LOCAL_LEN;
        if (wlan_cfgGetStr(pMac, (tANI_U16) prf[i], (tANI_U8 *) &data[0], &len) != eSIR_SUCCESS)
        {
<<<<<<< HEAD
<<<<<<< HEAD
            schLog(pMac, LOGP, FL("cfgGet failed for %d\n"), prf[i]);
=======
            schLog(pMac, LOGP, FL("cfgGet failed for %d"), prf[i]);
>>>>>>> d97af3b... add prima wlan driver
=======
            schLog(pMac, LOGP, FL("cfgGet failed for %d\n"), prf[i]);
>>>>>>> 657b0e9... prima update
            return eSIR_FAILURE;
        }
        if (len > WNI_CFG_EDCA_ANI_ACBK_LOCAL_LEN)
        {
<<<<<<< HEAD
<<<<<<< HEAD
            schLog(pMac, LOGE, FL("cfgGet for %d: length is %d instead of %d\n"),
=======
            schLog(pMac, LOGE, FL("cfgGet for %d: length is %d instead of %d"),
>>>>>>> d97af3b... add prima wlan driver
=======
            schLog(pMac, LOGE, FL("cfgGet for %d: length is %d instead of %d\n"),
>>>>>>> 657b0e9... prima update
                   prf[i], len, WNI_CFG_EDCA_ANI_ACBK_LOCAL_LEN);
            return eSIR_FAILURE;
        }
        for (idx=0; idx < len; idx++)
            params[i][idx] = (tANI_U32) data[idx];
    }
    return eSIR_SUCCESS;
}


/** ----------------------------------------------------------
\fn      schEdcaProfileUpdate
\brief   This function updates the local and broadcast
\        EDCA params in the gLimEdcaParams structure. It also
\        updates the edcaParamSetCount.
\param   tpAniSirGlobal  pMac
\return  none
\ ------------------------------------------------------------ */
void
schEdcaProfileUpdate(tpAniSirGlobal pMac, tpPESession psessionEntry)
{
    if (psessionEntry->limSystemRole == eLIM_AP_ROLE || psessionEntry->limSystemRole == eLIM_STA_IN_IBSS_ROLE)
    {
        schQosUpdateLocal(pMac, psessionEntry);
        psessionEntry->gLimEdcaParamSetCount++;
        schQosUpdateBroadcast(pMac, psessionEntry);
    }
}

// --------------------------------------------------------------------
