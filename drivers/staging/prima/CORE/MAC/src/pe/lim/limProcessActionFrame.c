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
 * This file limProcessActionFrame.cc contains the code
 * for processing Action Frame.
 * Author:      Michael Lui
 * Date:        05/23/03
 * History:-
 * Date           Modified by    Modification Information
 * --------------------------------------------------------------------
 *
 */
#include "palTypes.h"
#include "wniApi.h"
#include "sirApi.h"
#include "aniGlobal.h"
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
#include "schApi.h"
#include "utilsApi.h"
#include "limTypes.h"
#include "limUtils.h"
#include "limAssocUtils.h"
#include "limSecurityUtils.h"
#include "limSerDesUtils.h"
#include "limSendSmeRspMessages.h"
#include "parserApi.h"
#include "limAdmitControl.h"
#include "wmmApsd.h"
#include "limSendMessages.h"
#if defined WLAN_FEATURE_VOWIFI
#include "rrmApi.h"
#endif
#include "limSessionUtils.h"

#if defined FEATURE_WLAN_CCX
#include "ccxApi.h"
#endif
#include "wlan_qct_wda.h"


#define BA_DEFAULT_TX_BUFFER_SIZE 64

typedef enum
{
  LIM_ADDBA_RSP = 0,
  LIM_ADDBA_REQ = 1
}tLimAddBaValidationReqType;

/* Note: The test passes if the STAUT stops sending any frames, and no further
 frames are transmitted on this channel by the station when the AP has sent
 the last 6 beacons, with the channel switch information elements as seen
 with the sniffer.*/
#define SIR_CHANSW_TX_STOP_MAX_COUNT 6
/**-----------------------------------------------------------------
\fn     limStopTxAndSwitchChannel
\brief  Stops the transmission if channel switch mode is silent and
        starts the channel switch timer.

\param  pMac
\return NONE
-----------------------------------------------------------------*/
void limStopTxAndSwitchChannel(tpAniSirGlobal pMac, tANI_U8 sessionId)
{
    tANI_U8 isFullPowerRequested = 0;
    tpPESession psessionEntry;

    psessionEntry = peFindSessionBySessionId( pMac , sessionId );

    if( NULL == psessionEntry )
    {
      limLog(pMac, LOGE, FL("Session %d  not active\n "), sessionId);
      return;
    }

<<<<<<< HEAD
<<<<<<< HEAD
    PELOG1(limLog(pMac, LOG1, FL("Channel switch Mode == %d\n"), 
=======
    PELOG1(limLog(pMac, LOG1, FL("Channel switch Mode == %d"),
>>>>>>> d97af3b... add prima wlan driver
=======
    PELOG1(limLog(pMac, LOG1, FL("Channel switch Mode == %d\n"), 
>>>>>>> 657b0e9... prima update
                       psessionEntry->gLimChannelSwitch.switchMode);)

    if (psessionEntry->gLimChannelSwitch.switchMode == eSIR_CHANSW_MODE_SILENT ||
        psessionEntry->gLimChannelSwitch.switchCount <= SIR_CHANSW_TX_STOP_MAX_COUNT)
    {
        /* Freeze the transmission */
        limFrameTransmissionControl(pMac, eLIM_TX_ALL, eLIM_STOP_TX);

        /*Request for Full power only if the device is in powersave*/
        if(!limIsSystemInActiveState(pMac))
        {
            /* Request Full Power */
            limSendSmePreChannelSwitchInd(pMac);
            isFullPowerRequested = 1;
        }
    }
    else
    {
        /* Resume the transmission */
        limFrameTransmissionControl(pMac, eLIM_TX_ALL, eLIM_RESUME_TX);
    }

    pMac->lim.limTimers.gLimChannelSwitchTimer.sessionId = sessionId;
    /* change the channel immediatly only if the channel switch count is 0 and the 
     * device is not in powersave 
     * If the device is in powersave channel switch should happen only after the
     * device comes out of the powersave */
    if (psessionEntry->gLimChannelSwitch.switchCount == 0) 
    {
        if(limIsSystemInActiveState(pMac))
        {
            limProcessChannelSwitchTimeout(pMac);
        }
        else if(!isFullPowerRequested)
        {
            /* If the Full power is already not requested 
             * Request Full Power so the channel switch happens 
             * after device comes to full power */
            limSendSmePreChannelSwitchInd(pMac);
        }
        return;
    }
<<<<<<< HEAD
<<<<<<< HEAD
    MTRACE(macTrace(pMac, TRACE_CODE_TIMER_ACTIVATE, NO_SESSION, eLIM_CHANNEL_SWITCH_TIMER));
=======
    MTRACE(macTrace(pMac, TRACE_CODE_TIMER_ACTIVATE, sessionId, eLIM_CHANNEL_SWITCH_TIMER));
>>>>>>> d97af3b... add prima wlan driver
=======
    MTRACE(macTrace(pMac, TRACE_CODE_TIMER_ACTIVATE, NO_SESSION, eLIM_CHANNEL_SWITCH_TIMER));
>>>>>>> 657b0e9... prima update


    if (tx_timer_activate(&pMac->lim.limTimers.gLimChannelSwitchTimer) != TX_SUCCESS)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        limLog(pMac, LOGP, FL("tx_timer_activate failed\n"));
=======
        limLog(pMac, LOGP, FL("tx_timer_activate failed"));
>>>>>>> d97af3b... add prima wlan driver
=======
        limLog(pMac, LOGP, FL("tx_timer_activate failed\n"));
>>>>>>> 657b0e9... prima update
    }
    return;
}

/**------------------------------------------------------------
\fn     limStartChannelSwitch
\brief  Switches the channel if switch count == 0, otherwise
        starts the timer for channel switch and stops BG scan
        and heartbeat timer tempororily.

\param  pMac
\param  psessionEntry
\return NONE
------------------------------------------------------------*/
tSirRetStatus limStartChannelSwitch(tpAniSirGlobal pMac, tpPESession psessionEntry)
{
<<<<<<< HEAD
<<<<<<< HEAD
    PELOG1(limLog(pMac, LOG1, FL("Starting the channel switch\n"));)
=======
    PELOG1(limLog(pMac, LOG1, FL("Starting the channel switch"));)
>>>>>>> d97af3b... add prima wlan driver
=======
    PELOG1(limLog(pMac, LOG1, FL("Starting the channel switch\n"));)
>>>>>>> 657b0e9... prima update
    
    /*If channel switch is already running and it is on a different session, just return*/  
    /*This need to be removed for MCC */
    if( limIsChanSwitchRunning (pMac) &&
        psessionEntry->gLimSpecMgmt.dot11hChanSwState != eLIM_11H_CHANSW_RUNNING )
    {
<<<<<<< HEAD
<<<<<<< HEAD
       limLog(pMac, LOGW, FL("Ignoring channel switch on session %d\n"), psessionEntry->peSessionId);
=======
       limLog(pMac, LOGW, FL("Ignoring channel switch on session %d"), psessionEntry->peSessionId);
>>>>>>> d97af3b... add prima wlan driver
=======
       limLog(pMac, LOGW, FL("Ignoring channel switch on session %d\n"), psessionEntry->peSessionId);
>>>>>>> 657b0e9... prima update
       return eSIR_SUCCESS;
    }
     
    /* Deactivate and change reconfigure the timeout value */
    //limDeactivateAndChangeTimer(pMac, eLIM_CHANNEL_SWITCH_TIMER);
<<<<<<< HEAD
<<<<<<< HEAD
    if (tx_timer_deactivate(&pMac->lim.limTimers.gLimChannelSwitchTimer) != eSIR_SUCCESS)
    {
        limLog(pMac, LOGP, FL("tx_timer_deactivate failed!\n"));
=======
    MTRACE(macTrace(pMac, TRACE_CODE_TIMER_DEACTIVATE, psessionEntry->peSessionId, eLIM_CHANNEL_SWITCH_TIMER));
    if (tx_timer_deactivate(&pMac->lim.limTimers.gLimChannelSwitchTimer) != eSIR_SUCCESS)
    {
        limLog(pMac, LOGP, FL("tx_timer_deactivate failed!"));
>>>>>>> d97af3b... add prima wlan driver
=======
    if (tx_timer_deactivate(&pMac->lim.limTimers.gLimChannelSwitchTimer) != eSIR_SUCCESS)
    {
        limLog(pMac, LOGP, FL("tx_timer_deactivate failed!\n"));
>>>>>>> 657b0e9... prima update
        return eSIR_FAILURE;
    }

    if (tx_timer_change(&pMac->lim.limTimers.gLimChannelSwitchTimer,
                psessionEntry->gLimChannelSwitch.switchTimeoutValue,
                            0) != TX_SUCCESS)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        limLog(pMac, LOGP, FL("tx_timer_change failed \n"));
=======
        limLog(pMac, LOGP, FL("tx_timer_change failed "));
>>>>>>> d97af3b... add prima wlan driver
=======
        limLog(pMac, LOGP, FL("tx_timer_change failed \n"));
>>>>>>> 657b0e9... prima update
        return eSIR_FAILURE;
    }

    /* Follow the channel switch, forget about the previous quiet. */
    //If quiet is running, chance is there to resume tx on its timeout.
    //so stop timer for a safer side.
    if (psessionEntry->gLimSpecMgmt.quietState == eLIM_QUIET_BEGIN)
    {
        MTRACE(macTrace(pMac, TRACE_CODE_TIMER_DEACTIVATE, psessionEntry->peSessionId, eLIM_QUIET_TIMER));
        if (tx_timer_deactivate(&pMac->lim.limTimers.gLimQuietTimer) != TX_SUCCESS)
        {
<<<<<<< HEAD
<<<<<<< HEAD
            limLog(pMac, LOGP, FL("tx_timer_deactivate failed\n"));
=======
            limLog(pMac, LOGP, FL("tx_timer_deactivate failed"));
>>>>>>> d97af3b... add prima wlan driver
=======
            limLog(pMac, LOGP, FL("tx_timer_deactivate failed\n"));
>>>>>>> 657b0e9... prima update
            return eSIR_FAILURE;
        }
    }
    else if (psessionEntry->gLimSpecMgmt.quietState == eLIM_QUIET_RUNNING)
    {
        MTRACE(macTrace(pMac, TRACE_CODE_TIMER_DEACTIVATE, psessionEntry->peSessionId, eLIM_QUIET_BSS_TIMER));
        if (tx_timer_deactivate(&pMac->lim.limTimers.gLimQuietBssTimer) != TX_SUCCESS)
        {
<<<<<<< HEAD
<<<<<<< HEAD
            limLog(pMac, LOGP, FL("tx_timer_deactivate failed\n"));
=======
            limLog(pMac, LOGP, FL("tx_timer_deactivate failed"));
>>>>>>> d97af3b... add prima wlan driver
=======
            limLog(pMac, LOGP, FL("tx_timer_deactivate failed\n"));
>>>>>>> 657b0e9... prima update
            return eSIR_FAILURE;
        }
    }
    psessionEntry->gLimSpecMgmt.quietState = eLIM_QUIET_INIT;

    /* Prepare for 11h channel switch */
    limPrepareFor11hChannelSwitch(pMac, psessionEntry);

    /** Dont add any more statements here as we posted finish scan request
     * to HAL, wait till we get the response
     */
    return eSIR_SUCCESS;
}


/**
 *  __limProcessChannelSwitchActionFrame
 *
 *FUNCTION:
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 *
 *NOTE:
 *
 * @param  pMac - Pointer to Global MAC structure
 * @param  *pRxPacketInfo - A pointer to packet info structure
 * @return None
 */

static void

__limProcessChannelSwitchActionFrame(tpAniSirGlobal pMac, tANI_U8 *pRxPacketInfo,tpPESession psessionEntry)
{

    tpSirMacMgmtHdr         pHdr;
    tANI_U8                 *pBody;
    tDot11fChannelSwitch    *pChannelSwitchFrame;
    tANI_U16                beaconPeriod;
    tANI_U32                val;
    tANI_U32                frameLen;
    tANI_U32                nStatus;
<<<<<<< HEAD
<<<<<<< HEAD
    eHalStatus              status;
=======
>>>>>>> d97af3b... add prima wlan driver
=======
    eHalStatus              status;
>>>>>>> 657b0e9... prima update

    pHdr = WDA_GET_RX_MAC_HEADER(pRxPacketInfo);
    pBody = WDA_GET_RX_MPDU_DATA(pRxPacketInfo);
    frameLen = WDA_GET_RX_PAYLOAD_LEN(pRxPacketInfo);

<<<<<<< HEAD
<<<<<<< HEAD
    PELOG3(limLog(pMac, LOG3, FL("Received Channel switch action frame\n"));)
    if (!psessionEntry->lim11hEnable)
        return;

    status = palAllocateMemory( pMac->hHdd, (void **)&pChannelSwitchFrame, sizeof(*pChannelSwitchFrame));
    if (eHAL_STATUS_SUCCESS != status)
    {
        limLog(pMac, LOGE,
            FL("palAllocateMemory failed, status = %d \n"), status);
=======
    PELOG3(limLog(pMac, LOG3, FL("Received Channel switch action frame"));)
=======
    PELOG3(limLog(pMac, LOG3, FL("Received Channel switch action frame\n"));)
>>>>>>> 657b0e9... prima update
    if (!psessionEntry->lim11hEnable)
        return;

    status = palAllocateMemory( pMac->hHdd, (void **)&pChannelSwitchFrame, sizeof(*pChannelSwitchFrame));
    if (eHAL_STATUS_SUCCESS != status)
    {
        limLog(pMac, LOGE,
<<<<<<< HEAD
            FL("AllocateMemory failed"));
>>>>>>> d97af3b... add prima wlan driver
=======
            FL("palAllocateMemory failed, status = %d \n"), status);
>>>>>>> 657b0e9... prima update
        return;
    }

    /* Unpack channel switch frame */
    nStatus = dot11fUnpackChannelSwitch(pMac, pBody, frameLen, pChannelSwitchFrame);

    if( DOT11F_FAILED( nStatus ))
    {
        limLog( pMac, LOGE,
<<<<<<< HEAD
<<<<<<< HEAD
            FL( "Failed to unpack and parse an 11h-CHANSW Request (0x%08x, %d bytes):\n"),
            nStatus,
            frameLen);
        palFreeMemory(pMac->hHdd, pChannelSwitchFrame);
=======
            FL( "Failed to unpack and parse an 11h-CHANSW Request (0x%08x, %d bytes):"),
            nStatus,
            frameLen);
        vos_mem_free(pChannelSwitchFrame);
>>>>>>> d97af3b... add prima wlan driver
=======
            FL( "Failed to unpack and parse an 11h-CHANSW Request (0x%08x, %d bytes):\n"),
            nStatus,
            frameLen);
        palFreeMemory(pMac->hHdd, pChannelSwitchFrame);
>>>>>>> 657b0e9... prima update
        return;
    }
    else if(DOT11F_WARNED( nStatus ))
    {
        limLog( pMac, LOGW,
<<<<<<< HEAD
<<<<<<< HEAD
            FL( "There were warnings while unpacking an 11h-CHANSW Request (0x%08x, %d bytes):\n"),
=======
            FL( "There were warnings while unpacking an 11h-CHANSW Request (0x%08x, %d bytes):"),
>>>>>>> d97af3b... add prima wlan driver
=======
            FL( "There were warnings while unpacking an 11h-CHANSW Request (0x%08x, %d bytes):\n"),
>>>>>>> 657b0e9... prima update
            nStatus,
            frameLen);
    }

<<<<<<< HEAD
<<<<<<< HEAD
    if (palEqualMemory( pMac->hHdd,(tANI_U8 *) &psessionEntry->bssId,
                  (tANI_U8 *) &pHdr->sa,
                  sizeof(tSirMacAddr)))
=======
    if (vos_mem_compare((tANI_U8 *) &psessionEntry->bssId,
                        (tANI_U8 *) &pHdr->sa,
                        sizeof(tSirMacAddr)))
>>>>>>> d97af3b... add prima wlan driver
=======
    if (palEqualMemory( pMac->hHdd,(tANI_U8 *) &psessionEntry->bssId,
                  (tANI_U8 *) &pHdr->sa,
                  sizeof(tSirMacAddr)))
>>>>>>> 657b0e9... prima update
    {
        #if 0
        if (wlan_cfgGetInt(pMac, WNI_CFG_BEACON_INTERVAL, &val) != eSIR_SUCCESS)
        {
<<<<<<< HEAD
<<<<<<< HEAD
            palFreeMemory(pMac->hHdd, pChannelSwitchFrame);
            limLog(pMac, LOGP, FL("could not retrieve Beacon interval\n"));
=======
            vos_mem_free(pChannelSwitchFrame);
            limLog(pMac, LOGP, FL("could not retrieve Beacon interval"));
>>>>>>> d97af3b... add prima wlan driver
=======
            palFreeMemory(pMac->hHdd, pChannelSwitchFrame);
            limLog(pMac, LOGP, FL("could not retrieve Beacon interval\n"));
>>>>>>> 657b0e9... prima update
            return;
        }
        #endif// TO SUPPORT BT-AMP

        /* copy the beacon interval from psessionEntry*/
        val = psessionEntry->beaconParams.beaconInterval;

        beaconPeriod = (tANI_U16) val;

        psessionEntry->gLimChannelSwitch.primaryChannel = pChannelSwitchFrame->ChanSwitchAnn.newChannel;
        psessionEntry->gLimChannelSwitch.switchCount = pChannelSwitchFrame->ChanSwitchAnn.switchCount;
        psessionEntry->gLimChannelSwitch.switchTimeoutValue = SYS_MS_TO_TICKS(beaconPeriod) *
                                                         psessionEntry->gLimChannelSwitch.switchCount;
        psessionEntry->gLimChannelSwitch.switchMode = pChannelSwitchFrame->ChanSwitchAnn.switchMode;
<<<<<<< HEAD
<<<<<<< HEAD

       PELOG3(limLog(pMac, LOG3, FL("Rcv Chnl Swtch Frame: Timeout in %d ticks\n"),
=======
#ifdef WLAN_FEATURE_11AC
        if ( pChannelSwitchFrame->WiderBWChanSwitchAnn.present && psessionEntry->vhtCapability)
        {
            psessionEntry->gLimWiderBWChannelSwitch.newChanWidth = pChannelSwitchFrame->WiderBWChanSwitchAnn.newChanWidth;
            psessionEntry->gLimWiderBWChannelSwitch.newCenterChanFreq0 = pChannelSwitchFrame->WiderBWChanSwitchAnn.newCenterChanFreq0;
            psessionEntry->gLimWiderBWChannelSwitch.newCenterChanFreq1 = pChannelSwitchFrame->WiderBWChanSwitchAnn.newCenterChanFreq1;
        }
#endif

       PELOG3(limLog(pMac, LOG3, FL("Rcv Chnl Swtch Frame: Timeout in %d ticks"),
>>>>>>> d97af3b... add prima wlan driver
=======

       PELOG3(limLog(pMac, LOG3, FL("Rcv Chnl Swtch Frame: Timeout in %d ticks\n"),
>>>>>>> 657b0e9... prima update
                             psessionEntry->gLimChannelSwitch.switchTimeoutValue);)

        /* Only primary channel switch element is present */
        psessionEntry->gLimChannelSwitch.state = eLIM_CHANNEL_SWITCH_PRIMARY_ONLY;
        psessionEntry->gLimChannelSwitch.secondarySubBand = PHY_SINGLE_CHANNEL_CENTERED;

        if (psessionEntry->htSupportedChannelWidthSet)
        {
            if ((pChannelSwitchFrame->ExtChanSwitchAnn.secondaryChannelOffset == PHY_DOUBLE_CHANNEL_LOW_PRIMARY) ||
                (pChannelSwitchFrame->ExtChanSwitchAnn.secondaryChannelOffset == PHY_DOUBLE_CHANNEL_HIGH_PRIMARY))
            {
                psessionEntry->gLimChannelSwitch.state = eLIM_CHANNEL_SWITCH_PRIMARY_AND_SECONDARY;
                psessionEntry->gLimChannelSwitch.secondarySubBand = pChannelSwitchFrame->ExtChanSwitchAnn.secondaryChannelOffset;
            }
<<<<<<< HEAD
<<<<<<< HEAD
=======
#ifdef WLAN_FEATURE_11AC
            if(psessionEntry->vhtCapability && pChannelSwitchFrame->WiderBWChanSwitchAnn.present)
            {
                if (pChannelSwitchFrame->WiderBWChanSwitchAnn.newChanWidth == WNI_CFG_VHT_CHANNEL_WIDTH_80MHZ)
                {
                    if (pChannelSwitchFrame->ExtChanSwitchAnn.present && ((pChannelSwitchFrame->ExtChanSwitchAnn.secondaryChannelOffset == PHY_DOUBLE_CHANNEL_LOW_PRIMARY) ||
                        (pChannelSwitchFrame->ExtChanSwitchAnn.secondaryChannelOffset == PHY_DOUBLE_CHANNEL_HIGH_PRIMARY)))
                    {
                        psessionEntry->gLimChannelSwitch.state = eLIM_CHANNEL_SWITCH_PRIMARY_AND_SECONDARY;
                        psessionEntry->gLimChannelSwitch.secondarySubBand =
                           limGet11ACPhyCBState(pMac,
                                                psessionEntry->gLimChannelSwitch.primaryChannel,
                                                pChannelSwitchFrame->ExtChanSwitchAnn.secondaryChannelOffset,
                                                pChannelSwitchFrame->WiderBWChanSwitchAnn.newCenterChanFreq0,
                                                psessionEntry);
                    }
                }
            }
#endif
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
        }

    }
    else
    {
        PELOG1(limLog(pMac, LOG1, FL("LIM: Received action frame not from our BSS, dropping..."));)
    }

    if (eSIR_SUCCESS != limStartChannelSwitch(pMac, psessionEntry))
    {
<<<<<<< HEAD
<<<<<<< HEAD
        PELOG1(limLog(pMac, LOG1, FL("Could not start channel switch\n"));)
    }

    palFreeMemory(pMac->hHdd, pChannelSwitchFrame);
=======
        PELOG1(limLog(pMac, LOG1, FL("Could not start channel switch"));)
    }

    vos_mem_free(pChannelSwitchFrame);
>>>>>>> d97af3b... add prima wlan driver
=======
        PELOG1(limLog(pMac, LOG1, FL("Could not start channel switch\n"));)
    }

    palFreeMemory(pMac->hHdd, pChannelSwitchFrame);
>>>>>>> 657b0e9... prima update
    return;
} /*** end limProcessChannelSwitchActionFrame() ***/


<<<<<<< HEAD
<<<<<<< HEAD
static void
__limProcessAddTsReq(tpAniSirGlobal pMac, tANI_U8 *pRxPacketInfo,tpPESession psessionEntry)
{
#if (WNI_POLARIS_FW_PRODUCT == AP)

    tSirAddtsReqInfo addts;
    tSirRetStatus    retval;
    tpSirMacMgmtHdr  pHdr;
    tSirMacScheduleIE schedule;
    tpDphHashNode    pSta;
    tANI_U16              status;
    tANI_U16              aid;
    tANI_U32              frameLen;
    tANI_U8              *pBody;
    tANI_U8 tspecIdx = 0; //index in the sch tspec table.
=======
#ifdef WLAN_FEATURE_11AC
=======
>>>>>>> 657b0e9... prima update
static void
__limProcessAddTsReq(tpAniSirGlobal pMac, tANI_U8 *pRxPacketInfo,tpPESession psessionEntry)
{
#if (WNI_POLARIS_FW_PRODUCT == AP)

<<<<<<< HEAD
    tpSirMacMgmtHdr         pHdr;
    tANI_U8                 *pBody;
    tDot11fOperatingMode    *pOperatingModeframe;
    tANI_U32                frameLen;
    tANI_U32                nStatus;
    tpDphHashNode           pSta;
    tANI_U16                aid;
    tANI_U8  operMode;
>>>>>>> d97af3b... add prima wlan driver
=======
    tSirAddtsReqInfo addts;
    tSirRetStatus    retval;
    tpSirMacMgmtHdr  pHdr;
    tSirMacScheduleIE schedule;
    tpDphHashNode    pSta;
    tANI_U16              status;
    tANI_U16              aid;
    tANI_U32              frameLen;
    tANI_U8              *pBody;
    tANI_U8 tspecIdx = 0; //index in the sch tspec table.
>>>>>>> 657b0e9... prima update

    pHdr = WDA_GET_RX_MAC_HEADER(pRxPacketInfo);
    pBody = WDA_GET_RX_MPDU_DATA(pRxPacketInfo);
    frameLen = WDA_GET_RX_PAYLOAD_LEN(pRxPacketInfo);

<<<<<<< HEAD
<<<<<<< HEAD

    if ((psessionEntry->limSystemRole != eLIM_AP_ROLE)||(psessionEntry->limSystemRole != eLIM_BT_AMP_AP_ROLE))
    {
        PELOGW(limLog(pMac, LOGW, FL("AddTs request at non-AP: ignoring\n"));)
        return;
    }

    pSta = dphLookupHashEntry(pMac, pHdr->sa, &aid, &psessionEntry->dph.dphHashTable);
    if (pSta == NULL)
    {
        PELOGE(limLog(pMac, LOGE, FL("Station context not found - ignoring AddTs\n"));)
        return;
    }

    PELOGW(limLog(pMac, LOGW, "AddTs Request from STA %d\n", aid);)
    retval = sirConvertAddtsReq2Struct(pMac, pBody, frameLen, &addts);
    if (retval != eSIR_SUCCESS)
    {
        PELOGW(limLog(pMac, LOGW, FL("AddTs parsing failed (error %d)\n"), retval);)
        return;
    }

    status = eSIR_MAC_SUCCESS_STATUS;


    if (addts.wmeTspecPresent)
    {
        if ((! psessionEntry->limWmeEnabled) || (! pSta->wmeEnabled))
        {
            PELOGW(limLog(pMac, LOGW, FL("Ignoring addts request: wme not enabled/capable\n"));)
            status = eSIR_MAC_WME_REFUSED_STATUS;
        }
        else
        {
            PELOG2(limLog(pMac, LOG2, FL("WME Addts received\n"));)
        }
    }
    else if (addts.wsmTspecPresent)
    {
        if ((! psessionEntry->limWsmEnabled) || (! pSta->wsmEnabled))
        {
            PELOGW(limLog(pMac, LOGW, FL("Ignoring addts request: wsm not enabled/capable\n"));)
            status = eSIR_MAC_REQ_DECLINED_STATUS;
        }
        else
        {
            PELOG2(limLog(pMac, LOG2, FL("WSM Addts received\n"));)
        }
    }
    else if ((! psessionEntry->limQosEnabled) || (! pSta->lleEnabled))
    {
        PELOGW(limLog(pMac, LOGW, FL("Ignoring addts request: qos not enabled/capable\n"));)
        status = eSIR_MAC_REQ_DECLINED_STATUS;
    }
    else
    {
        PELOG2(limLog(pMac, LOG2, FL("11e QoS Addts received\n"));)
    }

    // for edca, if no Admit Control, ignore the request
    if ((status == eSIR_MAC_SUCCESS_STATUS) &&
        (addts.tspec.tsinfo.traffic.accessPolicy == SIR_MAC_ACCESSPOLICY_EDCA) &&
        (! psessionEntry->gLimEdcaParamsBC[upToAc(addts.tspec.tsinfo.traffic.userPrio)].aci.acm))
    {
        limLog(pMac, LOGW, FL("AddTs with UP %d has no ACM - ignoring request\n"),
               addts.tspec.tsinfo.traffic.userPrio);
        status = (addts.wmeTspecPresent) ?
                 eSIR_MAC_WME_REFUSED_STATUS : eSIR_MAC_UNSPEC_FAILURE_STATUS;
    }

    if (status != eSIR_MAC_SUCCESS_STATUS)
    {
        limSendAddtsRspActionFrame(pMac, pHdr->sa, status, &addts, NULL,psessionEntry);
        return;
    }

    // try to admit the STA and send the appropriate response
    retval = limAdmitControlAddTS(pMac, &pSta->staAddr[0], &addts, NULL, pSta->assocId, true, &schedule, &tspecIdx, psessionEntry);
    if (retval != eSIR_SUCCESS)
    {
        PELOGW(limLog(pMac, LOGW, FL("Unable to admit TS\n"));)
        status = (addts.wmeTspecPresent) ?
                 eSIR_MAC_WME_REFUSED_STATUS : eSIR_MAC_UNSPEC_FAILURE_STATUS;
    }
    else if (addts.tspec.tsinfo.traffic.accessPolicy == SIR_MAC_ACCESSPOLICY_EDCA)
    {
        if(eSIR_SUCCESS != limSendHalMsgAddTs(pMac, pSta->staIndex, tspecIdx, addts.tspec, psessionEntry->peSessionId))
        {
          limLog(pMac, LOGW, FL("AddTs with UP %d failed in limSendHalMsgAddTs - ignoring request\n"),
                 addts.tspec.tsinfo.traffic.userPrio);
          status = (addts.wmeTspecPresent) ?
                   eSIR_MAC_WME_REFUSED_STATUS : eSIR_MAC_UNSPEC_FAILURE_STATUS;

           limAdmitControlDeleteTS(pMac, pSta->assocId, &addts.tspec.tsinfo, NULL, &tspecIdx);
        }
        if (status != eSIR_MAC_SUCCESS_STATUS)
        {
            limSendAddtsRspActionFrame(pMac, pHdr->sa, status, &addts, NULL,psessionEntry);
            return;
        }
    }
#if 0 //only EDCA is supported now.
    else if (addts.numTclas > 1)
    {
        limLog(pMac, LOGE, FL("Sta %d: Too many Tclas (%d), only 1 supported\n"),
               aid, addts.numTclas);
        status = (addts.wmeTspecPresent) ?
                 eSIR_MAC_WME_REFUSED_STATUS : eSIR_MAC_UNSPEC_FAILURE_STATUS;
    }
    else if (addts.numTclas == 1)
    {
        limLog(pMac, LOGW, "AddTs Request from STA %d: tsid %d, UP %d, OK!\n", aid,
               addts.tspec.tsinfo.traffic.tsid, addts.tspec.tsinfo.traffic.userPrio);
        status = eSIR_MAC_SUCCESS_STATUS;
    }
#endif

    limLog(pMac, LOGW, "AddTs Request from STA %d: Sending AddTs Response with status %d\n",
           aid, status);

    limSendAddtsRspActionFrame(pMac, pHdr->sa, status, &addts, &schedule,psessionEntry);
#endif
=======
    PELOG3(limLog(pMac, LOG3, FL("Received Operating Mode action frame"));)
    pOperatingModeframe = vos_mem_malloc(sizeof(*pOperatingModeframe));
    if (NULL == pOperatingModeframe)
=======

    if ((psessionEntry->limSystemRole != eLIM_AP_ROLE)||(psessionEntry->limSystemRole != eLIM_BT_AMP_AP_ROLE))
>>>>>>> 657b0e9... prima update
    {
        PELOGW(limLog(pMac, LOGW, FL("AddTs request at non-AP: ignoring\n"));)
        return;
    }

    pSta = dphLookupHashEntry(pMac, pHdr->sa, &aid, &psessionEntry->dph.dphHashTable);
    if (pSta == NULL)
    {
        PELOGE(limLog(pMac, LOGE, FL("Station context not found - ignoring AddTs\n"));)
        return;
    }

    PELOGW(limLog(pMac, LOGW, "AddTs Request from STA %d\n", aid);)
    retval = sirConvertAddtsReq2Struct(pMac, pBody, frameLen, &addts);
    if (retval != eSIR_SUCCESS)
    {
        PELOGW(limLog(pMac, LOGW, FL("AddTs parsing failed (error %d)\n"), retval);)
        return;
    }

    status = eSIR_MAC_SUCCESS_STATUS;


    if (addts.wmeTspecPresent)
    {
        if ((! psessionEntry->limWmeEnabled) || (! pSta->wmeEnabled))
        {
            PELOGW(limLog(pMac, LOGW, FL("Ignoring addts request: wme not enabled/capable\n"));)
            status = eSIR_MAC_WME_REFUSED_STATUS;
        }
        else
        {
            PELOG2(limLog(pMac, LOG2, FL("WME Addts received\n"));)
        }
    }
    else if (addts.wsmTspecPresent)
    {
        if ((! psessionEntry->limWsmEnabled) || (! pSta->wsmEnabled))
        {
            PELOGW(limLog(pMac, LOGW, FL("Ignoring addts request: wsm not enabled/capable\n"));)
            status = eSIR_MAC_REQ_DECLINED_STATUS;
        }
        else
        {
            PELOG2(limLog(pMac, LOG2, FL("WSM Addts received\n"));)
        }
    }
    else if ((! psessionEntry->limQosEnabled) || (! pSta->lleEnabled))
    {
        PELOGW(limLog(pMac, LOGW, FL("Ignoring addts request: qos not enabled/capable\n"));)
        status = eSIR_MAC_REQ_DECLINED_STATUS;
    }
    else
    {
        PELOG2(limLog(pMac, LOG2, FL("11e QoS Addts received\n"));)
    }

    // for edca, if no Admit Control, ignore the request
    if ((status == eSIR_MAC_SUCCESS_STATUS) &&
        (addts.tspec.tsinfo.traffic.accessPolicy == SIR_MAC_ACCESSPOLICY_EDCA) &&
        (! psessionEntry->gLimEdcaParamsBC[upToAc(addts.tspec.tsinfo.traffic.userPrio)].aci.acm))
    {
        limLog(pMac, LOGW, FL("AddTs with UP %d has no ACM - ignoring request\n"),
               addts.tspec.tsinfo.traffic.userPrio);
        status = (addts.wmeTspecPresent) ?
                 eSIR_MAC_WME_REFUSED_STATUS : eSIR_MAC_UNSPEC_FAILURE_STATUS;
    }

    if (status != eSIR_MAC_SUCCESS_STATUS)
    {
        limSendAddtsRspActionFrame(pMac, pHdr->sa, status, &addts, NULL,psessionEntry);
        return;
    }

    // try to admit the STA and send the appropriate response
    retval = limAdmitControlAddTS(pMac, &pSta->staAddr[0], &addts, NULL, pSta->assocId, true, &schedule, &tspecIdx, psessionEntry);
    if (retval != eSIR_SUCCESS)
    {
        PELOGW(limLog(pMac, LOGW, FL("Unable to admit TS\n"));)
        status = (addts.wmeTspecPresent) ?
                 eSIR_MAC_WME_REFUSED_STATUS : eSIR_MAC_UNSPEC_FAILURE_STATUS;
    }
    else if (addts.tspec.tsinfo.traffic.accessPolicy == SIR_MAC_ACCESSPOLICY_EDCA)
    {
        if(eSIR_SUCCESS != limSendHalMsgAddTs(pMac, pSta->staIndex, tspecIdx, addts.tspec, psessionEntry->peSessionId))
        {
          limLog(pMac, LOGW, FL("AddTs with UP %d failed in limSendHalMsgAddTs - ignoring request\n"),
                 addts.tspec.tsinfo.traffic.userPrio);
          status = (addts.wmeTspecPresent) ?
                   eSIR_MAC_WME_REFUSED_STATUS : eSIR_MAC_UNSPEC_FAILURE_STATUS;

           limAdmitControlDeleteTS(pMac, pSta->assocId, &addts.tspec.tsinfo, NULL, &tspecIdx);
        }
        if (status != eSIR_MAC_SUCCESS_STATUS)
        {
            limSendAddtsRspActionFrame(pMac, pHdr->sa, status, &addts, NULL,psessionEntry);
            return;
        }
    }
#if 0 //only EDCA is supported now.
    else if (addts.numTclas > 1)
    {
        limLog(pMac, LOGE, FL("Sta %d: Too many Tclas (%d), only 1 supported\n"),
               aid, addts.numTclas);
        status = (addts.wmeTspecPresent) ?
                 eSIR_MAC_WME_REFUSED_STATUS : eSIR_MAC_UNSPEC_FAILURE_STATUS;
    }
    else if (addts.numTclas == 1)
    {
        limLog(pMac, LOGW, "AddTs Request from STA %d: tsid %d, UP %d, OK!\n", aid,
               addts.tspec.tsinfo.traffic.tsid, addts.tspec.tsinfo.traffic.userPrio);
        status = eSIR_MAC_SUCCESS_STATUS;
    }
#endif

<<<<<<< HEAD
static void
__limProcessAddTsReq(tpAniSirGlobal pMac, tANI_U8 *pRxPacketInfo,tpPESession psessionEntry)
{
>>>>>>> d97af3b... add prima wlan driver
=======
    limLog(pMac, LOGW, "AddTs Request from STA %d: Sending AddTs Response with status %d\n",
           aid, status);

    limSendAddtsRspActionFrame(pMac, pHdr->sa, status, &addts, &schedule,psessionEntry);
#endif
>>>>>>> 657b0e9... prima update
}


static void
__limProcessAddTsRsp(tpAniSirGlobal pMac, tANI_U8 *pRxPacketInfo,tpPESession psessionEntry)
{
    tSirAddtsRspInfo addts;
    tSirRetStatus    retval;
    tpSirMacMgmtHdr  pHdr;
    tpDphHashNode    pSta;
    tANI_U16         aid;
    tANI_U32         frameLen;
    tANI_U8          *pBody;
    tpLimTspecInfo   tspecInfo;
    tANI_U8          ac; 
    tpDphHashNode    pStaDs = NULL;
    tANI_U8          rspReqd = 1;
    tANI_U32   cfgLen;
    tSirMacAddr  peerMacAddr;


    pHdr = WDA_GET_RX_MAC_HEADER(pRxPacketInfo);
    pBody = WDA_GET_RX_MPDU_DATA(pRxPacketInfo);
    frameLen = WDA_GET_RX_PAYLOAD_LEN(pRxPacketInfo);


<<<<<<< HEAD
<<<<<<< HEAD
    PELOGW(limLog(pMac, LOGW, "Recv AddTs Response\n");)
    if ((psessionEntry->limSystemRole == eLIM_AP_ROLE)||(psessionEntry->limSystemRole == eLIM_BT_AMP_AP_ROLE))
    {
        PELOGW(limLog(pMac, LOGW, FL("AddTsRsp recvd at AP: ignoring\n"));)
=======
    PELOGW(limLog(pMac, LOGW, "Recv AddTs Response");)
    if ((psessionEntry->limSystemRole == eLIM_AP_ROLE)||(psessionEntry->limSystemRole == eLIM_BT_AMP_AP_ROLE))
    {
        PELOGW(limLog(pMac, LOGW, FL("AddTsRsp recvd at AP: ignoring"));)
>>>>>>> d97af3b... add prima wlan driver
=======
    PELOGW(limLog(pMac, LOGW, "Recv AddTs Response\n");)
    if ((psessionEntry->limSystemRole == eLIM_AP_ROLE)||(psessionEntry->limSystemRole == eLIM_BT_AMP_AP_ROLE))
    {
        PELOGW(limLog(pMac, LOGW, FL("AddTsRsp recvd at AP: ignoring\n"));)
>>>>>>> 657b0e9... prima update
        return;
    }

    pSta = dphLookupHashEntry(pMac, pHdr->sa, &aid, &psessionEntry->dph.dphHashTable);
    if (pSta == NULL)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        PELOGE(limLog(pMac, LOGE, FL("Station context not found - ignoring AddTsRsp\n"));)
=======
        PELOGE(limLog(pMac, LOGE, FL("Station context not found - ignoring AddTsRsp"));)
>>>>>>> d97af3b... add prima wlan driver
=======
        PELOGE(limLog(pMac, LOGE, FL("Station context not found - ignoring AddTsRsp\n"));)
>>>>>>> 657b0e9... prima update
        return;
    }

    retval = sirConvertAddtsRsp2Struct(pMac, pBody, frameLen, &addts);
    if (retval != eSIR_SUCCESS)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        PELOGW(limLog(pMac, LOGW, FL("AddTsRsp parsing failed (error %d)\n"), retval);)
=======
        PELOGW(limLog(pMac, LOGW, FL("AddTsRsp parsing failed (error %d)"), retval);)
>>>>>>> d97af3b... add prima wlan driver
=======
        PELOGW(limLog(pMac, LOGW, FL("AddTsRsp parsing failed (error %d)\n"), retval);)
>>>>>>> 657b0e9... prima update
        return;
    }

    // don't have to check for qos/wme capabilities since we wouldn't have this
    // flag set otherwise
    if (! pMac->lim.gLimAddtsSent)
    {
        // we never sent an addts request!
<<<<<<< HEAD
<<<<<<< HEAD
        PELOGW(limLog(pMac, LOGW, "Recvd AddTsRsp but no request was ever sent - ignoring\n");)
=======
        PELOGW(limLog(pMac, LOGW, "Recvd AddTsRsp but no request was ever sent - ignoring");)
>>>>>>> d97af3b... add prima wlan driver
=======
        PELOGW(limLog(pMac, LOGW, "Recvd AddTsRsp but no request was ever sent - ignoring\n");)
>>>>>>> 657b0e9... prima update
        return;
    }

    if (pMac->lim.gLimAddtsReq.req.dialogToken != addts.dialogToken)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        limLog(pMac, LOGW, "AddTsRsp: token mismatch (got %d, exp %d) - ignoring\n",
=======
        limLog(pMac, LOGW, "AddTsRsp: token mismatch (got %d, exp %d) - ignoring",
>>>>>>> d97af3b... add prima wlan driver
=======
        limLog(pMac, LOGW, "AddTsRsp: token mismatch (got %d, exp %d) - ignoring\n",
>>>>>>> 657b0e9... prima update
               addts.dialogToken, pMac->lim.gLimAddtsReq.req.dialogToken);
        return;
    }

    /*
     * for successful addts reponse, try to add the classifier.
     * if this fails for any reason, we should send a delts request to the ap
     * for now, its ok not to send a delts since we are going to add support for
     * multiple tclas soon and until then we won't send any addts requests with
     * multiple tclas elements anyway.
     * In case of addClassifier failure, we just let the addts timer run out
     */
    if (((addts.tspec.tsinfo.traffic.accessPolicy == SIR_MAC_ACCESSPOLICY_HCCA) ||
         (addts.tspec.tsinfo.traffic.accessPolicy == SIR_MAC_ACCESSPOLICY_BOTH)) &&
        (addts.status == eSIR_MAC_SUCCESS_STATUS))
    {
        // add the classifier - this should always succeed
        if (addts.numTclas > 1) // currently no support for multiple tclas elements
        {
<<<<<<< HEAD
<<<<<<< HEAD
            limLog(pMac, LOGE, FL("Sta %d: Too many Tclas (%d), only 1 supported\n"),
=======
            limLog(pMac, LOGE, FL("Sta %d: Too many Tclas (%d), only 1 supported"),
>>>>>>> d97af3b... add prima wlan driver
=======
            limLog(pMac, LOGE, FL("Sta %d: Too many Tclas (%d), only 1 supported\n"),
>>>>>>> 657b0e9... prima update
                   aid, addts.numTclas);
            return;
        }
        else if (addts.numTclas == 1)
        {
<<<<<<< HEAD
<<<<<<< HEAD
            limLog(pMac, LOGW, "AddTs Response from STA %d: tsid %d, UP %d, OK!\n", aid,
                   addts.tspec.tsinfo.traffic.tsid, addts.tspec.tsinfo.traffic.userPrio);
        }
    }
    limLog(pMac, LOGW, "Recv AddTsRsp: tsid %d, UP %d, status %d \n",
=======
            limLog(pMac, LOGW, "AddTs Response from STA %d: tsid %d, UP %d, OK!", aid,
                   addts.tspec.tsinfo.traffic.tsid, addts.tspec.tsinfo.traffic.userPrio);
        }
    }
    limLog(pMac, LOGW, "Recv AddTsRsp: tsid %d, UP %d, status %d ",
>>>>>>> d97af3b... add prima wlan driver
=======
            limLog(pMac, LOGW, "AddTs Response from STA %d: tsid %d, UP %d, OK!\n", aid,
                   addts.tspec.tsinfo.traffic.tsid, addts.tspec.tsinfo.traffic.userPrio);
        }
    }
    limLog(pMac, LOGW, "Recv AddTsRsp: tsid %d, UP %d, status %d \n",
>>>>>>> 657b0e9... prima update
          addts.tspec.tsinfo.traffic.tsid, addts.tspec.tsinfo.traffic.userPrio,
          addts.status);

    // deactivate the response timer
    limDeactivateAndChangeTimer(pMac, eLIM_ADDTS_RSP_TIMER);

    if (addts.status != eSIR_MAC_SUCCESS_STATUS)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        limLog(pMac, LOGW, "Recv AddTsRsp: tsid %d, UP %d, status %d \n",
=======
        limLog(pMac, LOGW, "Recv AddTsRsp: tsid %d, UP %d, status %d ",
>>>>>>> d97af3b... add prima wlan driver
=======
        limLog(pMac, LOGW, "Recv AddTsRsp: tsid %d, UP %d, status %d \n",
>>>>>>> 657b0e9... prima update
              addts.tspec.tsinfo.traffic.tsid, addts.tspec.tsinfo.traffic.userPrio,
              addts.status);
        limSendSmeAddtsRsp(pMac, true, addts.status, psessionEntry, addts.tspec, 
                psessionEntry->smeSessionId, psessionEntry->transactionId);

        // clear the addts flag
        pMac->lim.gLimAddtsSent = false;

        return;
    }
#ifdef FEATURE_WLAN_CCX
    if (addts.tsmPresent)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        limLog(pMac, LOGW, "TSM IE Present\n");
=======
        limLog(pMac, LOGW, "TSM IE Present");
>>>>>>> d97af3b... add prima wlan driver
=======
        limLog(pMac, LOGW, "TSM IE Present\n");
>>>>>>> 657b0e9... prima update
        psessionEntry->ccxContext.tsm.tid = addts.tspec.tsinfo.traffic.userPrio;
        vos_mem_copy(&psessionEntry->ccxContext.tsm.tsmInfo,
                                         &addts.tsmIE,sizeof(tSirMacCCXTSMIE));
        limActivateTSMStatsTimer(pMac, psessionEntry);
    }
#endif
    /* Since AddTS response was successful, check for the PSB flag
     * and directional flag inside the TS Info field. 
     * An AC is trigger enabled AC if the PSB subfield is set to 1  
     * in the uplink direction.
     * An AC is delivery enabled AC if the PSB subfield is set to 1 
     * in the downlink direction.
     * An AC is trigger and delivery enabled AC if the PSB subfield  
     * is set to 1 in the bi-direction field.
     */
    if (addts.tspec.tsinfo.traffic.psb == 1)
        limSetTspecUapsdMask(pMac, &addts.tspec.tsinfo, SET_UAPSD_MASK);
    else 
        limSetTspecUapsdMask(pMac, &addts.tspec.tsinfo, CLEAR_UAPSD_MASK);


    /* ADDTS success, so AC is now admitted. We shall now use the default
     * EDCA parameters as advertised by AP and send the updated EDCA params
     * to HAL. 
     */
    ac = upToAc(addts.tspec.tsinfo.traffic.userPrio);
    if(addts.tspec.tsinfo.traffic.direction == SIR_MAC_DIRECTION_UPLINK)
    {
      pMac->lim.gAcAdmitMask[SIR_MAC_DIRECTION_UPLINK] |= (1 << ac);
    }
    else if(addts.tspec.tsinfo.traffic.direction == SIR_MAC_DIRECTION_DNLINK)
    {
      pMac->lim.gAcAdmitMask[SIR_MAC_DIRECTION_DNLINK] |= (1 << ac);
    }
    else if(addts.tspec.tsinfo.traffic.direction == SIR_MAC_DIRECTION_BIDIR)
    {
      pMac->lim.gAcAdmitMask[SIR_MAC_DIRECTION_UPLINK] |= (1 << ac);
      pMac->lim.gAcAdmitMask[SIR_MAC_DIRECTION_DNLINK] |= (1 << ac);
    }

    limSetActiveEdcaParams(pMac, psessionEntry->gLimEdcaParams, psessionEntry);

    pStaDs = dphGetHashEntry(pMac, DPH_STA_HASH_INDEX_PEER, &psessionEntry->dph.dphHashTable);
    if (pStaDs != NULL)
    {
        if (pStaDs->aniPeer == eANI_BOOLEAN_TRUE) 
            limSendEdcaParams(pMac, psessionEntry->gLimEdcaParamsActive, pStaDs->bssId, eANI_BOOLEAN_TRUE);
        else
            limSendEdcaParams(pMac, psessionEntry->gLimEdcaParamsActive, pStaDs->bssId, eANI_BOOLEAN_FALSE);
    }
    else
<<<<<<< HEAD
<<<<<<< HEAD
        limLog(pMac, LOGE, FL("Self entry missing in Hash Table \n"));
=======
        limLog(pMac, LOGE, FL("Self entry missing in Hash Table "));
>>>>>>> d97af3b... add prima wlan driver
=======
        limLog(pMac, LOGE, FL("Self entry missing in Hash Table \n"));
>>>>>>> 657b0e9... prima update

        
    sirCopyMacAddr(peerMacAddr,psessionEntry->bssId);

    //if schedule is not present then add TSPEC with svcInterval as 0.
    if(!addts.schedulePresent)
      addts.schedule.svcInterval = 0;
    if(eSIR_SUCCESS != limTspecAdd(pMac, pSta->staAddr, pSta->assocId, &addts.tspec,  addts.schedule.svcInterval, &tspecInfo))
    {
<<<<<<< HEAD
<<<<<<< HEAD
        PELOGE(limLog(pMac, LOGE, FL("Adding entry in lim Tspec Table failed \n"));)
=======
        PELOGE(limLog(pMac, LOGE, FL("Adding entry in lim Tspec Table failed "));)
>>>>>>> d97af3b... add prima wlan driver
=======
        PELOGE(limLog(pMac, LOGE, FL("Adding entry in lim Tspec Table failed \n"));)
>>>>>>> 657b0e9... prima update
        limSendDeltsReqActionFrame(pMac, peerMacAddr, rspReqd, &addts.tspec.tsinfo, &addts.tspec,
                psessionEntry);
        pMac->lim.gLimAddtsSent = false;
        return;   //Error handling. send the response with error status. need to send DelTS to tear down the TSPEC status.
    }
    if((addts.tspec.tsinfo.traffic.accessPolicy != SIR_MAC_ACCESSPOLICY_EDCA) ||
<<<<<<< HEAD
<<<<<<< HEAD
       ((upToAc(addts.tspec.tsinfo.traffic.userPrio) < MAX_NUM_AC) &&
       (psessionEntry->gLimEdcaParams[upToAc(addts.tspec.tsinfo.traffic.userPrio)].aci.acm)))
=======
       ((upToAc(addts.tspec.tsinfo.traffic.userPrio) < MAX_NUM_AC)))
>>>>>>> d97af3b... add prima wlan driver
=======
       ((upToAc(addts.tspec.tsinfo.traffic.userPrio) < MAX_NUM_AC) &&
       (psessionEntry->gLimEdcaParams[upToAc(addts.tspec.tsinfo.traffic.userPrio)].aci.acm)))
>>>>>>> 657b0e9... prima update
    {
        retval = limSendHalMsgAddTs(pMac, pSta->staIndex, tspecInfo->idx, addts.tspec, psessionEntry->peSessionId);
        if(eSIR_SUCCESS != retval)
        {
            limAdmitControlDeleteTS(pMac, pSta->assocId, &addts.tspec.tsinfo, NULL, &tspecInfo->idx);
    
            // Send DELTS action frame to AP        
            cfgLen = sizeof(tSirMacAddr);
            limSendDeltsReqActionFrame(pMac, peerMacAddr, rspReqd, &addts.tspec.tsinfo, &addts.tspec,
                    psessionEntry);
            limSendSmeAddtsRsp(pMac, true, retval, psessionEntry, addts.tspec,
                    psessionEntry->smeSessionId, psessionEntry->transactionId);
            pMac->lim.gLimAddtsSent = false;
            return;
        }
<<<<<<< HEAD
<<<<<<< HEAD
        PELOGW(limLog(pMac, LOGW, FL("AddTsRsp received successfully(UP %d, TSID %d)\n"),
=======
        PELOGW(limLog(pMac, LOGW, FL("AddTsRsp received successfully(UP %d, TSID %d)"),
>>>>>>> d97af3b... add prima wlan driver
=======
        PELOGW(limLog(pMac, LOGW, FL("AddTsRsp received successfully(UP %d, TSID %d)\n"),
>>>>>>> 657b0e9... prima update
           addts.tspec.tsinfo.traffic.userPrio, addts.tspec.tsinfo.traffic.tsid);)
    }
    else
    {
<<<<<<< HEAD
<<<<<<< HEAD
        PELOGW(limLog(pMac, LOGW, FL("AddTsRsp received successfully(UP %d, TSID %d)\n"),
               addts.tspec.tsinfo.traffic.userPrio, addts.tspec.tsinfo.traffic.tsid);)
        PELOGW(limLog(pMac, LOGW, FL("no ACM: Bypass sending WDA_ADD_TS_REQ to HAL \n"));)
=======
        PELOGW(limLog(pMac, LOGW, FL("AddTsRsp received successfully(UP %d, TSID %d)"),
               addts.tspec.tsinfo.traffic.userPrio, addts.tspec.tsinfo.traffic.tsid);)
        PELOGW(limLog(pMac, LOGW, FL("no ACM: Bypass sending WDA_ADD_TS_REQ to HAL "));)
>>>>>>> d97af3b... add prima wlan driver
=======
        PELOGW(limLog(pMac, LOGW, FL("AddTsRsp received successfully(UP %d, TSID %d)\n"),
               addts.tspec.tsinfo.traffic.userPrio, addts.tspec.tsinfo.traffic.tsid);)
        PELOGW(limLog(pMac, LOGW, FL("no ACM: Bypass sending WDA_ADD_TS_REQ to HAL \n"));)
>>>>>>> 657b0e9... prima update
        // Use the smesessionId and smetransactionId from the PE session context
        limSendSmeAddtsRsp(pMac, true, eSIR_SME_SUCCESS, psessionEntry, addts.tspec,
                psessionEntry->smeSessionId, psessionEntry->transactionId);
    }

    // clear the addts flag
    pMac->lim.gLimAddtsSent = false;
    return;
}


static void
__limProcessDelTsReq(tpAniSirGlobal pMac, tANI_U8 *pRxPacketInfo,tpPESession psessionEntry)
{
    tSirRetStatus    retval;
    tSirDeltsReqInfo delts;
    tpSirMacMgmtHdr  pHdr;
    tpDphHashNode    pSta;
    tANI_U32              frameLen;
    tANI_U16              aid;
    tANI_U8              *pBody;
    tANI_U8               tsStatus;
    tSirMacTSInfo   *tsinfo;
    tANI_U8 tspecIdx;
    tANI_U8  ac;
    tpDphHashNode  pStaDs = NULL;


    pHdr = WDA_GET_RX_MAC_HEADER(pRxPacketInfo);
    pBody = WDA_GET_RX_MPDU_DATA(pRxPacketInfo);
    frameLen = WDA_GET_RX_PAYLOAD_LEN(pRxPacketInfo);

    pSta = dphLookupHashEntry(pMac, pHdr->sa, &aid, &psessionEntry->dph.dphHashTable);
    if (pSta == NULL)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        PELOGE(limLog(pMac, LOGE, FL("Station context not found - ignoring DelTs\n"));)
=======
        PELOGE(limLog(pMac, LOGE, FL("Station context not found - ignoring DelTs"));)
>>>>>>> d97af3b... add prima wlan driver
=======
        PELOGE(limLog(pMac, LOGE, FL("Station context not found - ignoring DelTs\n"));)
>>>>>>> 657b0e9... prima update
        return;
    }

    // parse the delts request
    retval = sirConvertDeltsReq2Struct(pMac, pBody, frameLen, &delts);
    if (retval != eSIR_SUCCESS)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        PELOGW(limLog(pMac, LOGW, FL("DelTs parsing failed (error %d)\n"), retval);)
=======
        PELOGW(limLog(pMac, LOGW, FL("DelTs parsing failed (error %d)"), retval);)
>>>>>>> d97af3b... add prima wlan driver
=======
        PELOGW(limLog(pMac, LOGW, FL("DelTs parsing failed (error %d)\n"), retval);)
>>>>>>> 657b0e9... prima update
        return;
    }

    if (delts.wmeTspecPresent)
    {
        if ((!psessionEntry->limWmeEnabled) || (! pSta->wmeEnabled))
        {
<<<<<<< HEAD
<<<<<<< HEAD
            PELOGW(limLog(pMac, LOGW, FL("Ignoring delts request: wme not enabled/capable\n"));)
            return;
        }
        PELOG2(limLog(pMac, LOG2, FL("WME Delts received\n"));)
    }
    else if ((psessionEntry->limQosEnabled) && pSta->lleEnabled)
        {
        PELOG2(limLog(pMac, LOG2, FL("11e QoS Delts received\n"));)
        }
    else if ((psessionEntry->limWsmEnabled) && pSta->wsmEnabled)
        {
        PELOG2(limLog(pMac, LOG2, FL("WSM Delts received\n"));)
        }
    else
    {
        PELOGW(limLog(pMac, LOGW, FL("Ignoring delts request: qos not enabled/capable\n"));)
=======
            PELOGW(limLog(pMac, LOGW, FL("Ignoring delts request: wme not enabled/capable"));)
=======
            PELOGW(limLog(pMac, LOGW, FL("Ignoring delts request: wme not enabled/capable\n"));)
>>>>>>> 657b0e9... prima update
            return;
        }
        PELOG2(limLog(pMac, LOG2, FL("WME Delts received\n"));)
    }
    else if ((psessionEntry->limQosEnabled) && pSta->lleEnabled)
        {
        PELOG2(limLog(pMac, LOG2, FL("11e QoS Delts received\n"));)
        }
    else if ((psessionEntry->limWsmEnabled) && pSta->wsmEnabled)
        {
        PELOG2(limLog(pMac, LOG2, FL("WSM Delts received\n"));)
        }
    else
    {
<<<<<<< HEAD
        PELOGW(limLog(pMac, LOGW, FL("Ignoring delts request: qos not enabled/capable"));)
>>>>>>> d97af3b... add prima wlan driver
=======
        PELOGW(limLog(pMac, LOGW, FL("Ignoring delts request: qos not enabled/capable\n"));)
>>>>>>> 657b0e9... prima update
        return;
    }

    tsinfo = delts.wmeTspecPresent ? &delts.tspec.tsinfo : &delts.tsinfo;

    // if no Admit Control, ignore the request
    if ((tsinfo->traffic.accessPolicy == SIR_MAC_ACCESSPOLICY_EDCA))
    {
    
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
#if(defined(ANI_PRODUCT_TYPE_AP) || defined(ANI_PRODUCT_TYPE_AP_SDK))
        if ((psessionEntry->limSystemRole == eLIM_AP_ROLE &&
        (! psessionEntry->gLimEdcaParamsBC[upToAc(tsinfo->traffic.userPrio)].aci.acm)) ||
        (psessionEntry->limSystemRole != eLIM_AP_ROLE &&
        (! psessionEntry->gLimEdcaParams[upToAc(tsinfo->traffic.userPrio)].aci.acm)))
#else
<<<<<<< HEAD
        if ((upToAc(tsinfo->traffic.userPrio) >= MAX_NUM_AC) || (! psessionEntry->gLimEdcaParams[upToAc(tsinfo->traffic.userPrio)].aci.acm))
#endif
        {
            limLog(pMac, LOGW, FL("DelTs with UP %d has no AC - ignoring request\n"),
=======
=======
>>>>>>> 657b0e9... prima update
        if ((upToAc(tsinfo->traffic.userPrio) >= MAX_NUM_AC) || (! psessionEntry->gLimEdcaParams[upToAc(tsinfo->traffic.userPrio)].aci.acm))
#endif
        {
<<<<<<< HEAD
            limLog(pMac, LOGW, FL("DelTs with UP %d has no AC - ignoring request"),
>>>>>>> d97af3b... add prima wlan driver
=======
            limLog(pMac, LOGW, FL("DelTs with UP %d has no AC - ignoring request\n"),
>>>>>>> 657b0e9... prima update
                   tsinfo->traffic.userPrio);
            return;
        }
    }

    // try to delete the TS
    if (eSIR_SUCCESS != limAdmitControlDeleteTS(pMac, pSta->assocId, tsinfo, &tsStatus, &tspecIdx))
    {
<<<<<<< HEAD
<<<<<<< HEAD
        PELOGW(limLog(pMac, LOGW, FL("Unable to Delete TS\n"));)
=======
        PELOGW(limLog(pMac, LOGW, FL("Unable to Delete TS"));)
>>>>>>> d97af3b... add prima wlan driver
=======
        PELOGW(limLog(pMac, LOGW, FL("Unable to Delete TS\n"));)
>>>>>>> 657b0e9... prima update
        return;
    }

    else if ((tsinfo->traffic.accessPolicy == SIR_MAC_ACCESSPOLICY_HCCA) ||
             (tsinfo->traffic.accessPolicy == SIR_MAC_ACCESSPOLICY_BOTH))
    {
      //Edca only for now.
    }
    else
    {
      //send message to HAL to delete TS
      if(eSIR_SUCCESS != limSendHalMsgDelTs(pMac, pSta->staIndex, tspecIdx, delts, psessionEntry->peSessionId))
      {
<<<<<<< HEAD
<<<<<<< HEAD
        limLog(pMac, LOGW, FL("DelTs with UP %d failed in limSendHalMsgDelTs - ignoring request\n"),
=======
        limLog(pMac, LOGW, FL("DelTs with UP %d failed in limSendHalMsgDelTs - ignoring request"),
>>>>>>> d97af3b... add prima wlan driver
=======
        limLog(pMac, LOGW, FL("DelTs with UP %d failed in limSendHalMsgDelTs - ignoring request\n"),
>>>>>>> 657b0e9... prima update
                         tsinfo->traffic.userPrio);
         return;
      }
    }

    /* We successfully deleted the TSPEC. Update the dynamic UAPSD Mask.
     * The AC for this TSPEC is no longer trigger enabled if this Tspec
     * was set-up in uplink direction only.
     * The AC for this TSPEC is no longer delivery enabled if this Tspec
     * was set-up in downlink direction only.
     * The AC for this TSPEC is no longer triiger enabled and delivery 
     * enabled if this Tspec was a bidirectional TSPEC.
     */
    limSetTspecUapsdMask(pMac, tsinfo, CLEAR_UAPSD_MASK);


    /* We're deleting the TSPEC.
     * The AC for this TSPEC is no longer admitted in uplink/downlink direction
     * if this TSPEC was set-up in uplink/downlink direction only.
     * The AC for this TSPEC is no longer admitted in both uplink and downlink
     * directions if this TSPEC was a bi-directional TSPEC.
     * If ACM is set for this AC and this AC is admitted only in downlink
     * direction, PE needs to downgrade the EDCA parameter 
     * (for the AC for which TS is being deleted) to the
     * next best AC for which ACM is not enabled, and send the
     * updated values to HAL. 
     */ 
    ac = upToAc(tsinfo->traffic.userPrio);

    if(tsinfo->traffic.direction == SIR_MAC_DIRECTION_UPLINK)
    {
      pMac->lim.gAcAdmitMask[SIR_MAC_DIRECTION_UPLINK] &= ~(1 << ac);
    }
    else if(tsinfo->traffic.direction == SIR_MAC_DIRECTION_DNLINK)
    {
      pMac->lim.gAcAdmitMask[SIR_MAC_DIRECTION_DNLINK] &= ~(1 << ac);
    }
    else if(tsinfo->traffic.direction == SIR_MAC_DIRECTION_BIDIR)
    {
      pMac->lim.gAcAdmitMask[SIR_MAC_DIRECTION_UPLINK] &= ~(1 << ac);
      pMac->lim.gAcAdmitMask[SIR_MAC_DIRECTION_DNLINK] &= ~(1 << ac);
    }

    limSetActiveEdcaParams(pMac, psessionEntry->gLimEdcaParams, psessionEntry);

    pStaDs = dphGetHashEntry(pMac, DPH_STA_HASH_INDEX_PEER, &psessionEntry->dph.dphHashTable);
    if (pStaDs != NULL)
    {
        if (pStaDs->aniPeer == eANI_BOOLEAN_TRUE) 
            limSendEdcaParams(pMac, psessionEntry->gLimEdcaParamsActive, pStaDs->bssId, eANI_BOOLEAN_TRUE);
        else
            limSendEdcaParams(pMac, psessionEntry->gLimEdcaParamsActive, pStaDs->bssId, eANI_BOOLEAN_FALSE);
    }
    else
<<<<<<< HEAD
<<<<<<< HEAD
        limLog(pMac, LOGE, FL("Self entry missing in Hash Table \n"));

    PELOG1(limLog(pMac, LOG1, FL("DeleteTS succeeded\n"));)
=======
        limLog(pMac, LOGE, FL("Self entry missing in Hash Table "));

    PELOG1(limLog(pMac, LOG1, FL("DeleteTS succeeded"));)
>>>>>>> d97af3b... add prima wlan driver
=======
        limLog(pMac, LOGE, FL("Self entry missing in Hash Table \n"));

    PELOG1(limLog(pMac, LOG1, FL("DeleteTS succeeded\n"));)
>>>>>>> 657b0e9... prima update
    if((psessionEntry->limSystemRole != eLIM_AP_ROLE)&&(psessionEntry->limSystemRole != eLIM_BT_AMP_AP_ROLE))
      limSendSmeDeltsInd(pMac, &delts, aid,psessionEntry);

#ifdef FEATURE_WLAN_CCX
    limDeactivateAndChangeTimer(pMac,eLIM_TSM_TIMER);
#endif

}


#ifdef ANI_SUPPORT_11H
/**
 *  limProcessBasicMeasReq
 *
 *FUNCTION:
 * This function is called by limProcessMeasurementRequestFrame()
 * when it received a Basic measurement Request action frame.
 * Station/BP receiving this should perform basic measurements
 * and then send Basic Measurement Report. AP should not perform
 * any measurements, and send report indicating refusal.
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 *
 *NOTE:
 *
 * @param  pMac - Pointer to Global MAC structure
 * @param  pMeasReqFrame - A pointer to Basic Meas. Req structure
 * @return None
 */
static void
__limProcessBasicMeasReq(tpAniSirGlobal pMac,
                       tpSirMacMeasReqActionFrame pMeasReqFrame,
                       tSirMacAddr peerMacAddr)
{
    // TBD - Station shall perform basic measurements

    if (limSendMeasReportFrame(pMac,
                               pMeasReqFrame,
                               peerMacAddr) != eSIR_SUCCESS)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        PELOGE(limLog(pMac, LOGE, FL("fail to send Basic Meas report \n"));)
=======
        PELOGE(limLog(pMac, LOGE, FL("fail to send Basic Meas report "));)
>>>>>>> d97af3b... add prima wlan driver
=======
        PELOGE(limLog(pMac, LOGE, FL("fail to send Basic Meas report \n"));)
>>>>>>> 657b0e9... prima update
        return;
    }
}


/**
 *  limProcessCcaMeasReq
 *
 *FUNCTION:
 * This function is called by limProcessMeasurementRequestFrame()
 * when it received a CCA measurement Request action frame.
 * Station/BP receiving this should perform CCA measurements
 * and then send CCA Measurement Report. AP should not perform
 * any measurements, and send report indicating refusal.
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 *
 *NOTE:
 *
 * @param  pMac - Pointer to Global MAC structure
 * @param  pMeasReqFrame - A pointer to CCA Meas. Req structure
 * @return None
 */
static void
__limProcessCcaMeasReq(tpAniSirGlobal pMac,
                     tpSirMacMeasReqActionFrame pMeasReqFrame,
                     tSirMacAddr peerMacAddr)
{
    // TBD - Station shall perform cca measurements

    if (limSendMeasReportFrame(pMac,
                               pMeasReqFrame,
                               peerMacAddr) != eSIR_SUCCESS)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        PELOGE(limLog(pMac, LOGE, FL("fail to send CCA Meas report \n"));)
=======
        PELOGE(limLog(pMac, LOGE, FL("fail to send CCA Meas report "));)
>>>>>>> d97af3b... add prima wlan driver
=======
        PELOGE(limLog(pMac, LOGE, FL("fail to send CCA Meas report \n"));)
>>>>>>> 657b0e9... prima update
        return;
    }
}


/**
 *  __limProcessRpiMeasReq
 *
 *FUNCTION:
 * This function is called by limProcessMeasurementRequestFrame()
 * when it received a RPI measurement Request action frame.
 * Station/BP/AP  receiving this shall not perform any measurements,
 * and send report indicating refusal.
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 *
 *NOTE:
 *
 * @param  pMac - Pointer to Global MAC structure
 * @param  pMeasReqFrame - A pointer to RPI Meas. Req structure
 * @return None
 */
static void
__limProcessRpiMeasReq(tpAniSirGlobal pMac,
                     tpSirMacMeasReqActionFrame pMeasReqFrame,
                     tSirMacAddr peerMacAddr)
{
    if (limSendMeasReportFrame(pMac,
                               pMeasReqFrame,
                               peerMacAddr) != eSIR_SUCCESS)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        PELOGE(limLog(pMac, LOGE, FL("fail to send RPI Meas report \n"));)
=======
        PELOGE(limLog(pMac, LOGE, FL("fail to send RPI Meas report "));)
>>>>>>> d97af3b... add prima wlan driver
=======
        PELOGE(limLog(pMac, LOGE, FL("fail to send RPI Meas report \n"));)
>>>>>>> 657b0e9... prima update
        return;
    }
}


/**
 *  __limProcessMeasurementRequestFrame
 *
 *FUNCTION:
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 *
 *NOTE:
 *
 * @param  pMac - Pointer to Global MAC structure
 * @param  *pRxPacketInfo - A pointer to packet info structure
 * @return None
 */

static void
__limProcessMeasurementRequestFrame(tpAniSirGlobal pMac, tANI_U8 *pRxPacketInfo)
{
    tpSirMacMgmtHdr                       pHdr;
    tANI_U8                                    *pBody;
    tpSirMacMeasReqActionFrame            pMeasReqFrame;
    tANI_U32                                   frameLen;

    pHdr = WDA_GET_RX_MAC_HEADER(pRxPacketInfo);
    pBody = WDA_GET_RX_MPDU_DATA(pRxPacketInfo);
    frameLen = WDA_GET_RX_PAYLOAD_LEN(pRxPacketInfo);

<<<<<<< HEAD
<<<<<<< HEAD
    if ( eHAL_STATUS_SUCCESS !=
        palAllocateMemory( pMac->hHdd, (void **)&pMeasReqFrame, sizeof( tSirMacMeasReqActionFrame ) ) )
    {
        limLog(pMac, LOGE,
            FL("limProcessMeasurementRequestFrame: palAllocateMemory failed \n"));
=======
    pMeasReqFrame = vos_mem_malloc(sizeof( tSirMacMeasReqActionFrame ));
    if (NULL == pMeasReqFrame)
    {
        limLog(pMac, LOGE,
            FL("limProcessMeasurementRequestFrame: AllocateMemory failed "));
>>>>>>> d97af3b... add prima wlan driver
=======
    if ( eHAL_STATUS_SUCCESS !=
        palAllocateMemory( pMac->hHdd, (void **)&pMeasReqFrame, sizeof( tSirMacMeasReqActionFrame ) ) )
    {
        limLog(pMac, LOGE,
            FL("limProcessMeasurementRequestFrame: palAllocateMemory failed \n"));
>>>>>>> 657b0e9... prima update
        return;
    }

    if (sirConvertMeasReqFrame2Struct(pMac, pBody, pMeasReqFrame, frameLen) !=
        eSIR_SUCCESS)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        PELOGW(limLog(pMac, LOGW, FL("Rcv invalid Measurement Request Action Frame \n"));)
=======
        PELOGW(limLog(pMac, LOGW, FL("Rcv invalid Measurement Request Action Frame "));)
>>>>>>> d97af3b... add prima wlan driver
=======
        PELOGW(limLog(pMac, LOGW, FL("Rcv invalid Measurement Request Action Frame \n"));)
>>>>>>> 657b0e9... prima update
        return;
    }


    switch(pMeasReqFrame->measReqIE.measType)
    {
        case SIR_MAC_BASIC_MEASUREMENT_TYPE:
            __limProcessBasicMeasReq(pMac, pMeasReqFrame, pHdr->sa);
            break;

        case SIR_MAC_CCA_MEASUREMENT_TYPE:
            __limProcessCcaMeasReq(pMac, pMeasReqFrame, pHdr->sa);
            break;

        case SIR_MAC_RPI_MEASUREMENT_TYPE:
            __limProcessRpiMeasReq(pMac, pMeasReqFrame, pHdr->sa);
            break;

        default:
<<<<<<< HEAD
<<<<<<< HEAD
            PELOG1(limLog(pMac, LOG1, FL("Unknown Measurement Type %d \n"),
=======
            PELOG1(limLog(pMac, LOG1, FL("Unknown Measurement Type %d "),
>>>>>>> d97af3b... add prima wlan driver
=======
            PELOG1(limLog(pMac, LOG1, FL("Unknown Measurement Type %d \n"),
>>>>>>> 657b0e9... prima update
                   pMeasReqFrame->measReqIE.measType);)
            break;
    }

} /*** end limProcessMeasurementRequestFrame ***/


/**
 *  limProcessTpcRequestFrame
 *
 *FUNCTION:
 *  This function is called upon receiving Tpc Request frame.
 *
 *NOTE:
 *
 * @param  pMac - Pointer to Global MAC structure
 * @param  *pRxPacketInfo - A pointer to packet info structure
 * @return None
 */

static void
__limProcessTpcRequestFrame(tpAniSirGlobal pMac, tANI_U8 *pRxPacketInfo)
{
    tpSirMacMgmtHdr                       pHdr;
    tANI_U8                                    *pBody;
    tpSirMacTpcReqActionFrame             pTpcReqFrame;
    tANI_U32                                   frameLen;

    pHdr = WDA_GET_RX_MAC_HEADER(pRxPacketInfo);
    pBody = WDA_GET_RX_MPDU_DATA(pRxPacketInfo);
    frameLen = WDA_GET_RX_PAYLOAD_LEN(pRxPacketInfo);

    PELOG1(limLog(pMac, LOG1, FL("****LIM: Processing TPC Request from peer ****"));)

<<<<<<< HEAD
<<<<<<< HEAD
    if ( eHAL_STATUS_SUCCESS !=
        palAllocateMemory( pMac->hHdd, (void **)&pTpcReqFrame, sizeof( tSirMacTpcReqActionFrame ) ) )
    {
        PELOGE(limLog(pMac, LOGE, FL("palAllocateMemory failed \n"));)
=======
    pTpcReqFrame = vos_mem_malloc(sizeof( tSirMacTpcReqActionFrame ));
    if (NULL == pTpcReqFrame)
    {
        PELOGE(limLog(pMac, LOGE, FL("AllocateMemory failed "));)
>>>>>>> d97af3b... add prima wlan driver
=======
    if ( eHAL_STATUS_SUCCESS !=
        palAllocateMemory( pMac->hHdd, (void **)&pTpcReqFrame, sizeof( tSirMacTpcReqActionFrame ) ) )
    {
        PELOGE(limLog(pMac, LOGE, FL("palAllocateMemory failed \n"));)
>>>>>>> 657b0e9... prima update
        return;
    }

    if (sirConvertTpcReqFrame2Struct(pMac, pBody, pTpcReqFrame, frameLen) !=
        eSIR_SUCCESS)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        PELOGW(limLog(pMac, LOGW, FL("Rcv invalid TPC Req Action Frame \n"));)
=======
        PELOGW(limLog(pMac, LOGW, FL("Rcv invalid TPC Req Action Frame "));)
>>>>>>> d97af3b... add prima wlan driver
=======
        PELOGW(limLog(pMac, LOGW, FL("Rcv invalid TPC Req Action Frame \n"));)
>>>>>>> 657b0e9... prima update
        return;
    }

    if (limSendTpcReportFrame(pMac,
                              pTpcReqFrame,
                              pHdr->sa) != eSIR_SUCCESS)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        PELOGE(limLog(pMac, LOGE, FL("fail to send TPC Report Frame. \n"));)
=======
        PELOGE(limLog(pMac, LOGE, FL("fail to send TPC Report Frame. "));)
>>>>>>> d97af3b... add prima wlan driver
=======
        PELOGE(limLog(pMac, LOGE, FL("fail to send TPC Report Frame. \n"));)
>>>>>>> 657b0e9... prima update
        return;
    }
}
#endif


/**
 * \brief Validate an ADDBA Req from peer with respect
 * to our own BA configuration
 *
 * \sa __limValidateAddBAParameterSet
 *
 * \param pMac The global tpAniSirGlobal object
 *
 * \param baParameterSet The ADDBA Parameter Set.
 *
 * \param pDelBAFlag this parameter is NULL except for call from processAddBAReq
 *        delBAFlag is set when entry already exists.
 *
 * \param reqType ADDBA Req v/s ADDBA Rsp
 * 1 - ADDBA Req
 * 0 - ADDBA Rsp
 *
 * \return eSIR_SUCCESS if setup completes successfully
 *         eSIR_FAILURE is some problem is encountered
 */

static tSirMacStatusCodes
__limValidateAddBAParameterSet( tpAniSirGlobal pMac,
    tpDphHashNode pSta,
    tDot11fFfAddBAParameterSet baParameterSet,
    tANI_U8 dialogueToken,
    tLimAddBaValidationReqType reqType ,
    tANI_U8* pDelBAFlag /*this parameter is NULL except for call from processAddBAReq*/)
{
  if(baParameterSet.tid >= STACFG_MAX_TC)
  {
      return eSIR_MAC_WME_INVALID_PARAMS_STATUS;
  }

  //check if there is already a BA session setup with this STA/TID while processing AddBaReq
  if((true == pSta->tcCfg[baParameterSet.tid].fUseBARx) &&
        (LIM_ADDBA_REQ == reqType))
  {
      //There is already BA session setup for STA/TID.
<<<<<<< HEAD
<<<<<<< HEAD
      limLog( pMac, LOGW,
=======
      limLog( pMac, LOGE,
>>>>>>> d97af3b... add prima wlan driver
=======
      limLog( pMac, LOGW,
>>>>>>> 657b0e9... prima update
          FL( "AddBAReq rcvd when there is already a session for this StaId = %d, tid = %d\n " ),
          pSta->staIndex, baParameterSet.tid);
      limPrintMacAddr( pMac, pSta->staAddr, LOGW );

      if(pDelBAFlag)
        *pDelBAFlag = true;
  }
  return eSIR_MAC_SUCCESS_STATUS;
}

/**
 * \brief Validate a DELBA Ind from peer with respect
 * to our own BA configuration
 *
 * \sa __limValidateDelBAParameterSet
 *
 * \param pMac The global tpAniSirGlobal object
 *
 * \param baParameterSet The DELBA Parameter Set.
 *
 * \param pSta Runtime, STA-related configuration cached
 * in the HashNode object
 *
 * \return eSIR_SUCCESS if setup completes successfully
 *         eSIR_FAILURE is some problem is encountered
 */
static tSirMacStatusCodes 
__limValidateDelBAParameterSet( tpAniSirGlobal pMac,
    tDot11fFfDelBAParameterSet baParameterSet,
    tpDphHashNode pSta )
{
tSirMacStatusCodes statusCode = eSIR_MAC_STA_BLK_ACK_NOT_SUPPORTED_STATUS;

  // Validate if a BA is active for the requested TID
    if( pSta->tcCfg[baParameterSet.tid].fUseBATx ||
        pSta->tcCfg[baParameterSet.tid].fUseBARx )
    {
      statusCode = eSIR_MAC_SUCCESS_STATUS;

      limLog( pMac, LOGW,
<<<<<<< HEAD
<<<<<<< HEAD
          FL("Valid DELBA Ind received. Time to send WDA_DELBA_IND to HAL...\n"));
    }
    else
      limLog( pMac, LOGW,
          FL("Received an INVALID DELBA Ind for TID %d...\n"),
=======
          FL("Valid DELBA Ind received. Time to send WDA_DELBA_IND to HAL..."));
    }
    else
      limLog( pMac, LOGW,
          FL("Received an INVALID DELBA Ind for TID %d..."),
>>>>>>> d97af3b... add prima wlan driver
=======
          FL("Valid DELBA Ind received. Time to send WDA_DELBA_IND to HAL...\n"));
    }
    else
      limLog( pMac, LOGW,
          FL("Received an INVALID DELBA Ind for TID %d...\n"),
>>>>>>> 657b0e9... prima update
          baParameterSet.tid );

  return statusCode;
}

/**
 * \brief Process an ADDBA REQ
 *
 * \sa limProcessAddBAReq
 *
 * \param pMac The global tpAniSirGlobal object
 *
 * \param pRxPacketInfo Handle to the Rx packet info from HDD
 *
 * \return none
 *
 */
static void
__limProcessAddBAReq( tpAniSirGlobal pMac, tANI_U8 *pRxPacketInfo,tpPESession psessionEntry)
{
    tDot11fAddBAReq frmAddBAReq;
    tpSirMacMgmtHdr pHdr;
    tpDphHashNode pSta;
    tSirMacStatusCodes status = eSIR_MAC_SUCCESS_STATUS;
    tANI_U16 aid;
<<<<<<< HEAD
<<<<<<< HEAD
    tANI_U32 frameLen, nStatus;
=======
    tANI_U32 frameLen, nStatus,val;
>>>>>>> d97af3b... add prima wlan driver
=======
    tANI_U32 frameLen, nStatus;
>>>>>>> 657b0e9... prima update
    tANI_U8 *pBody;
    tANI_U8 delBAFlag =0;

    pHdr = WDA_GET_RX_MAC_HEADER( pRxPacketInfo );
    pBody = WDA_GET_RX_MPDU_DATA( pRxPacketInfo );
    frameLen = WDA_GET_RX_PAYLOAD_LEN( pRxPacketInfo );
<<<<<<< HEAD
<<<<<<< HEAD
=======
    val = 0;
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update

    // Unpack the received frame
    nStatus = dot11fUnpackAddBAReq( pMac, pBody, frameLen, &frmAddBAReq );
    if( DOT11F_FAILED( nStatus ))
    {
        limLog( pMac, LOGE,
<<<<<<< HEAD
<<<<<<< HEAD
            FL("Failed to unpack and parse an ADDBA Request (0x%08x, %d bytes):\n"),
=======
            FL("Failed to unpack and parse an ADDBA Request (0x%08x, %d bytes):"),
>>>>>>> d97af3b... add prima wlan driver
=======
            FL("Failed to unpack and parse an ADDBA Request (0x%08x, %d bytes):\n"),
>>>>>>> 657b0e9... prima update
            nStatus,
            frameLen );

        PELOG2(sirDumpBuf( pMac, SIR_DBG_MODULE_ID, LOG2, pBody, frameLen );)

        // Without an unpacked request we cannot respond, so silently ignore the request
        return;
    }
    else if ( DOT11F_WARNED( nStatus ) )
    {
        limLog( pMac, LOGW,
<<<<<<< HEAD
<<<<<<< HEAD
            FL( "There were warnings while unpacking an ADDBA Request (0x%08x, %d bytes):\n"),
=======
            FL( "There were warnings while unpacking an ADDBA Request (0x%08x, %d bytes):"),
>>>>>>> d97af3b... add prima wlan driver
=======
            FL( "There were warnings while unpacking an ADDBA Request (0x%08x, %d bytes):\n"),
>>>>>>> 657b0e9... prima update
            nStatus,
            frameLen );

        PELOG2(sirDumpBuf( pMac, SIR_DBG_MODULE_ID, LOG2, pBody, frameLen );)
    }

<<<<<<< HEAD
<<<<<<< HEAD
=======
    psessionEntry->amsduSupportedInBA = frmAddBAReq.AddBAParameterSet.amsduSupported;

>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
    pSta = dphLookupHashEntry( pMac, pHdr->sa, &aid, &psessionEntry->dph.dphHashTable );
    if( pSta == NULL )
    {
        limLog( pMac, LOGE,
<<<<<<< HEAD
<<<<<<< HEAD
            FL( "STA context not found - ignoring ADDBA from \n" ));
        limPrintMacAddr( pMac, pHdr->sa, LOGW );
=======
            FL( "STA context not found - ignoring ADDBA from " ));
        limPrintMacAddr( pMac, pHdr->sa, LOGE );
>>>>>>> d97af3b... add prima wlan driver
=======
            FL( "STA context not found - ignoring ADDBA from \n" ));
        limPrintMacAddr( pMac, pHdr->sa, LOGW );
>>>>>>> 657b0e9... prima update

        // FIXME - Should we do this?
        status = eSIR_MAC_INABLITY_TO_CONFIRM_ASSOC_STATUS;
        goto returnAfterError;
    }

    limLog( pMac, LOGW,
<<<<<<< HEAD
<<<<<<< HEAD
      FL( "ADDBA Req from STA with AID %d, tid = %d\n" ),
=======
      FL( "ADDBA Req from STA with AID %d, tid = %d" ),
>>>>>>> d97af3b... add prima wlan driver
=======
      FL( "ADDBA Req from STA with AID %d, tid = %d\n" ),
>>>>>>> 657b0e9... prima update
      aid, frmAddBAReq.AddBAParameterSet.tid);

#ifdef WLAN_SOFTAP_VSTA_FEATURE
    // we can only do BA on "hard" STAs
    if (!(IS_HWSTA_IDX(pSta->staIndex)))
    {
        status = eSIR_MAC_REQ_DECLINED_STATUS;
        goto returnAfterError;
    }
#endif //WLAN_SOFTAP_VSTA_FEATURE

<<<<<<< HEAD
<<<<<<< HEAD
=======
    if (wlan_cfgGetInt(pMac, WNI_CFG_DEL_ALL_RX_BA_SESSIONS_2_4_G_BTC, &val) !=
                    eSIR_SUCCESS)
    {
        limLog(pMac, LOGE,
               FL("Unable to get WNI_CFG_DEL_ALL_RX_BA_SESSIONS_2_4_G_BTC"));
        val = 0;
    }
    if ((SIR_BAND_2_4_GHZ == limGetRFBand(psessionEntry->currentOperChannel)) &&
                    val)
    {
        limLog( pMac, LOGW,
            FL( "BTC disabled aggregation - ignoring ADDBA from " ));
        limPrintMacAddr( pMac, pHdr->sa, LOGW );

        status = eSIR_MAC_REQ_DECLINED_STATUS;
        goto returnAfterError;
    }
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update

    // Now, validate the ADDBA Req
    if( eSIR_MAC_SUCCESS_STATUS !=
      (status = __limValidateAddBAParameterSet( pMac, pSta,
                                              frmAddBAReq.AddBAParameterSet,
                                              0, //dialogue token is don't care in request validation.
                                              LIM_ADDBA_REQ, &delBAFlag)))
        goto returnAfterError;

    //BA already set, so we need to delete it before adding new one.
    if(delBAFlag)
    {
        if( eSIR_SUCCESS != limPostMsgDelBAInd( pMac,
            pSta,
            (tANI_U8)frmAddBAReq.AddBAParameterSet.tid,
            eBA_RECIPIENT,psessionEntry))
        {
            status = eSIR_MAC_UNSPEC_FAILURE_STATUS;
            goto returnAfterError;
        }
    }

  // Check if the ADD BA Declined configuration is Disabled
    if ((pMac->lim.gAddBA_Declined & ( 1 << frmAddBAReq.AddBAParameterSet.tid ) )) {
<<<<<<< HEAD
<<<<<<< HEAD
        limLog( pMac, LOGE, FL( "Declined the ADDBA Req for the TID %d  \n" ),
=======
        limLog( pMac, LOGE, FL( "Declined the ADDBA Req for the TID %d  " ),
>>>>>>> d97af3b... add prima wlan driver
=======
        limLog( pMac, LOGE, FL( "Declined the ADDBA Req for the TID %d  \n" ),
>>>>>>> 657b0e9... prima update
                        frmAddBAReq.AddBAParameterSet.tid);
        status = eSIR_MAC_REQ_DECLINED_STATUS;
        goto returnAfterError;
    }

  //
  // Post WDA_ADDBA_REQ to HAL.
  // If HAL/HDD decide to allow this ADDBA Req session,
  // then this BA session is termed active
  //

  // Change the Block Ack state of this STA to wait for
  // ADDBA Rsp from HAL
  LIM_SET_STA_BA_STATE(pSta, frmAddBAReq.AddBAParameterSet.tid, eLIM_BA_STATE_WT_ADD_RSP);

<<<<<<< HEAD
<<<<<<< HEAD
=======
  if (wlan_cfgGetInt(pMac, WNI_CFG_NUM_BUFF_ADVERT , &val) != eSIR_SUCCESS)
  {
        limLog(pMac, LOGP, FL("Unable to get WNI_CFG_NUM_BUFF_ADVERT"));
        return ;
  }


  if (frmAddBAReq.AddBAParameterSet.bufferSize)
  {
      frmAddBAReq.AddBAParameterSet.bufferSize =
            VOS_MIN(val, frmAddBAReq.AddBAParameterSet.bufferSize);
  }
  else
  {
      frmAddBAReq.AddBAParameterSet.bufferSize = val;
  }
  limLog( pMac, LOG1, FL( "ADDBAREQ NUMBUFF %d" ),
                        frmAddBAReq.AddBAParameterSet.bufferSize);

>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
  if( eSIR_SUCCESS != limPostMsgAddBAReq( pMac,
        pSta,
        (tANI_U8) frmAddBAReq.DialogToken.token,
        (tANI_U8) frmAddBAReq.AddBAParameterSet.tid,
        (tANI_U8) frmAddBAReq.AddBAParameterSet.policy,
        frmAddBAReq.AddBAParameterSet.bufferSize,
        frmAddBAReq.BATimeout.timeout,
        (tANI_U16) frmAddBAReq.BAStartingSequenceControl.ssn,
        eBA_RECIPIENT,psessionEntry))
    status = eSIR_MAC_UNSPEC_FAILURE_STATUS;
  else
    return;

returnAfterError:

  //
  // Package LIM_MLM_ADDBA_RSP to MLME, with proper
  // status code. MLME will then send an ADDBA RSP
  // over the air to the peer MAC entity
  //
  if( eSIR_SUCCESS != limPostMlmAddBARsp( pMac,
        pHdr->sa,
        status,
        frmAddBAReq.DialogToken.token,
        (tANI_U8) frmAddBAReq.AddBAParameterSet.tid,
        (tANI_U8) frmAddBAReq.AddBAParameterSet.policy,
        frmAddBAReq.AddBAParameterSet.bufferSize,
        frmAddBAReq.BATimeout.timeout,psessionEntry))
  {
    limLog( pMac, LOGW,
        FL( "Failed to post LIM_MLM_ADDBA_RSP to " ));
    limPrintMacAddr( pMac, pHdr->sa, LOGW );
  }

}

/**
 * \brief Process an ADDBA RSP
 *
 * \sa limProcessAddBARsp
 *
 * \param pMac The global tpAniSirGlobal object
 *
 * \param pRxPacketInfo Handle to the packet info structure from HDD
 *
 * \return none
 *
 */
static void
__limProcessAddBARsp( tpAniSirGlobal pMac, tANI_U8 *pRxPacketInfo,tpPESession psessionEntry)
{
tDot11fAddBARsp frmAddBARsp;
tpSirMacMgmtHdr pHdr;
tpDphHashNode pSta;
tSirMacReasonCodes reasonCode = eSIR_MAC_UNSPEC_FAILURE_REASON;
tANI_U16 aid;
tANI_U32 frameLen, nStatus;
tANI_U8 *pBody;

  pHdr = WDA_GET_RX_MAC_HEADER( pRxPacketInfo );
  pBody = WDA_GET_RX_MPDU_DATA( pRxPacketInfo );
  frameLen = WDA_GET_RX_PAYLOAD_LEN( pRxPacketInfo );

  pSta = dphLookupHashEntry( pMac, pHdr->sa, &aid, &psessionEntry->dph.dphHashTable );
  if( pSta == NULL )
  {
    limLog( pMac, LOGE,
<<<<<<< HEAD
<<<<<<< HEAD
        FL( "STA context not found - ignoring ADDBA from \n" ));
=======
        FL( "STA context not found - ignoring ADDBA from " ));
>>>>>>> d97af3b... add prima wlan driver
=======
        FL( "STA context not found - ignoring ADDBA from \n" ));
>>>>>>> 657b0e9... prima update
    limPrintMacAddr( pMac, pHdr->sa, LOGW );
    return;
  }

#ifdef WLAN_SOFTAP_VSTA_FEATURE
  // We can only do BA on "hard" STAs.  We should not have issued an ADDBA
  // Request, so we should never be processing a ADDBA Response
  if (!(IS_HWSTA_IDX(pSta->staIndex)))
  {
    return;
  }
#endif //WLAN_SOFTAP_VSTA_FEATURE

  // Unpack the received frame
  nStatus = dot11fUnpackAddBARsp( pMac, pBody, frameLen, &frmAddBARsp );
  if( DOT11F_FAILED( nStatus ))
  {
    limLog( pMac, LOGE,
<<<<<<< HEAD
<<<<<<< HEAD
        FL( "Failed to unpack and parse an ADDBA Response (0x%08x, %d bytes):\n"),
=======
        FL( "Failed to unpack and parse an ADDBA Response (0x%08x, %d bytes):"),
>>>>>>> d97af3b... add prima wlan driver
=======
        FL( "Failed to unpack and parse an ADDBA Response (0x%08x, %d bytes):\n"),
>>>>>>> 657b0e9... prima update
        nStatus,
        frameLen );

    PELOG2(sirDumpBuf( pMac, SIR_DBG_MODULE_ID, LOG2, pBody, frameLen );)
    goto returnAfterError;
  }
  else if ( DOT11F_WARNED( nStatus ) )
  {
    limLog( pMac, LOGW,
<<<<<<< HEAD
<<<<<<< HEAD
        FL( "There were warnings while unpacking an ADDBA Response (0x%08x, %d bytes):\n"),
=======
        FL( "There were warnings while unpacking an ADDBA Response (0x%08x, %d bytes):"),
>>>>>>> d97af3b... add prima wlan driver
=======
        FL( "There were warnings while unpacking an ADDBA Response (0x%08x, %d bytes):\n"),
>>>>>>> 657b0e9... prima update
        nStatus,
        frameLen );

    PELOG2(sirDumpBuf( pMac, SIR_DBG_MODULE_ID, LOG2, pBody, frameLen );)
  }

<<<<<<< HEAD
<<<<<<< HEAD
  limLog( pMac, LOGW,
      FL( "ADDBA Rsp from STA with AID %d, tid = %d, status = %d\n" ),
=======
  limLog( pMac, LOGE,
      FL( "ADDBA Rsp from STA with AID %d, tid = %d, status = %d" ),
>>>>>>> d97af3b... add prima wlan driver
=======
  limLog( pMac, LOGW,
      FL( "ADDBA Rsp from STA with AID %d, tid = %d, status = %d\n" ),
>>>>>>> 657b0e9... prima update
      aid, frmAddBARsp.AddBAParameterSet.tid, frmAddBARsp.Status.status);

  //if there is no matchin dialougue token then ignore the response.

  if(eSIR_SUCCESS != limSearchAndDeleteDialogueToken(pMac, frmAddBARsp.DialogToken.token,
        pSta->assocId, frmAddBARsp.AddBAParameterSet.tid))
  {
<<<<<<< HEAD
<<<<<<< HEAD
      PELOGW(limLog(pMac, LOGW, FL("dialogueToken in received addBARsp did not match with outstanding requests\n"));)
=======
      PELOGW(limLog(pMac, LOGE, FL("dialogueToken in received addBARsp did not match with outstanding requests"));)
>>>>>>> d97af3b... add prima wlan driver
=======
      PELOGW(limLog(pMac, LOGW, FL("dialogueToken in received addBARsp did not match with outstanding requests\n"));)
>>>>>>> 657b0e9... prima update
      return;
  }

  // Check first if the peer accepted the ADDBA Req
  if( eSIR_MAC_SUCCESS_STATUS == frmAddBARsp.Status.status )
  {
    //if peer responded with buffer size 0 then we should pick the default.
    if(0 == frmAddBARsp.AddBAParameterSet.bufferSize)
        frmAddBARsp.AddBAParameterSet.bufferSize = BA_DEFAULT_TX_BUFFER_SIZE;

    // Now, validate the ADDBA Rsp
    if( eSIR_MAC_SUCCESS_STATUS !=
        __limValidateAddBAParameterSet( pMac, pSta,
                                       frmAddBARsp.AddBAParameterSet,
                                       (tANI_U8)frmAddBARsp.DialogToken.token,
                                       LIM_ADDBA_RSP, NULL))
      goto returnAfterError;
  }
  else
    goto returnAfterError;

  // Change STA state to wait for ADDBA Rsp from HAL
  LIM_SET_STA_BA_STATE(pSta, frmAddBARsp.AddBAParameterSet.tid, eLIM_BA_STATE_WT_ADD_RSP);

  //
  // Post WDA_ADDBA_REQ to HAL.
  // If HAL/HDD decide to allow this ADDBA Rsp session,
  // then this BA session is termed active
  //

  if( eSIR_SUCCESS != limPostMsgAddBAReq( pMac,
        pSta,
        (tANI_U8) frmAddBARsp.DialogToken.token,
        (tANI_U8) frmAddBARsp.AddBAParameterSet.tid,
        (tANI_U8) frmAddBARsp.AddBAParameterSet.policy,
        frmAddBARsp.AddBAParameterSet.bufferSize,
        frmAddBARsp.BATimeout.timeout,
        0,
        eBA_INITIATOR,psessionEntry))
    reasonCode = eSIR_MAC_UNSPEC_FAILURE_REASON;
  else
    return;

returnAfterError:

  // TODO: Do we need to signal an error status to SME,
  // if status != eSIR_MAC_SUCCESS_STATUS

  // Restore STA "BA" State
  LIM_SET_STA_BA_STATE(pSta, frmAddBARsp.AddBAParameterSet.tid, eLIM_BA_STATE_IDLE);
  //
  // Need to send a DELBA IND to peer, who
  // would have setup a BA session with this STA
  //
  if( eSIR_MAC_SUCCESS_STATUS == frmAddBARsp.Status.status )
  {
    //
    // Package LIM_MLM_DELBA_REQ to MLME, with proper
    // status code. MLME will then send a DELBA IND
    // over the air to the peer MAC entity
    //
    if( eSIR_SUCCESS != limPostMlmDelBAReq( pMac,
          pSta,
          eBA_INITIATOR,
          (tANI_U8) frmAddBARsp.AddBAParameterSet.tid,
          reasonCode, psessionEntry))
    {
      limLog( pMac, LOGW,
          FL( "Failed to post LIM_MLM_DELBA_REQ to " ));
      limPrintMacAddr( pMac, pHdr->sa, LOGW );
    }
  }
}

/**
 * \brief Process a DELBA Indication
 *
 * \sa limProcessDelBAInd
 *
 * \param pMac The global tpAniSirGlobal object
 *
 * \param pRxPacketInfo Handle to the Rx packet info from HDD
 *
 * \return none
 *
 */
static void
__limProcessDelBAReq( tpAniSirGlobal pMac, tANI_U8 *pRxPacketInfo,tpPESession psessionEntry)
{
tDot11fDelBAInd frmDelBAInd;
tpSirMacMgmtHdr pHdr;
tpDphHashNode pSta;
tANI_U16 aid;
tANI_U32 frameLen, nStatus;
tANI_U8 *pBody;

  pHdr = WDA_GET_RX_MAC_HEADER( pRxPacketInfo );
  pBody = WDA_GET_RX_MPDU_DATA( pRxPacketInfo );
  frameLen = WDA_GET_RX_PAYLOAD_LEN( pRxPacketInfo );

  pSta = dphLookupHashEntry( pMac, pHdr->sa, &aid, &psessionEntry->dph.dphHashTable );
  if( pSta == NULL )
  {
<<<<<<< HEAD
<<<<<<< HEAD
    limLog( pMac, LOGE, FL( "STA context not found - ignoring DELBA from \n"));
=======
    limLog( pMac, LOGE, FL( "STA context not found - ignoring DELBA from "));
>>>>>>> d97af3b... add prima wlan driver
=======
    limLog( pMac, LOGE, FL( "STA context not found - ignoring DELBA from \n"));
>>>>>>> 657b0e9... prima update
    limPrintMacAddr( pMac, pHdr->sa, LOGW );
    return;
  }

<<<<<<< HEAD
<<<<<<< HEAD
  limLog( pMac, LOG1, FL( "DELBA Ind from STA with AID %d\n" ), aid );
=======
  limLog( pMac, LOG1, FL( "DELBA Ind from STA with AID %d" ), aid );
>>>>>>> d97af3b... add prima wlan driver
=======
  limLog( pMac, LOG1, FL( "DELBA Ind from STA with AID %d\n" ), aid );
>>>>>>> 657b0e9... prima update

  // Unpack the received frame
  nStatus = dot11fUnpackDelBAInd( pMac, pBody, frameLen, &frmDelBAInd );
  if( DOT11F_FAILED( nStatus ))
  {
    limLog( pMac, LOGE,
<<<<<<< HEAD
<<<<<<< HEAD
        FL( "Failed to unpack and parse a DELBA Indication (0x%08x, %d bytes):\n"),
=======
        FL( "Failed to unpack and parse a DELBA Indication (0x%08x, %d bytes):"),
>>>>>>> d97af3b... add prima wlan driver
=======
        FL( "Failed to unpack and parse a DELBA Indication (0x%08x, %d bytes):\n"),
>>>>>>> 657b0e9... prima update
        nStatus,
        frameLen );

    PELOG2(sirDumpBuf( pMac, SIR_DBG_MODULE_ID, LOG2, pBody, frameLen );)
    return;
  }
  else if ( DOT11F_WARNED( nStatus ) )
  {
    limLog( pMac, LOGW,
<<<<<<< HEAD
<<<<<<< HEAD
        FL( "There were warnings while unpacking a DELBA Indication (0x%08x, %d bytes):\n"),
=======
        FL( "There were warnings while unpacking a DELBA Indication (0x%08x, %d bytes):"),
>>>>>>> d97af3b... add prima wlan driver
=======
        FL( "There were warnings while unpacking a DELBA Indication (0x%08x, %d bytes):\n"),
>>>>>>> 657b0e9... prima update
        nStatus,
        frameLen );

    PELOG2(sirDumpBuf( pMac, SIR_DBG_MODULE_ID, LOG2, pBody, frameLen );)
  }

  limLog( pMac, LOGW,
<<<<<<< HEAD
<<<<<<< HEAD
      FL( "Received DELBA for TID %d, Reason code %d\n" ),
=======
      FL( "Received DELBA for TID %d, Reason code %d" ),
>>>>>>> d97af3b... add prima wlan driver
=======
      FL( "Received DELBA for TID %d, Reason code %d\n" ),
>>>>>>> 657b0e9... prima update
      frmDelBAInd.DelBAParameterSet.tid,
      frmDelBAInd.Reason.code );

  // Now, validate the DELBA Ind
  if( eSIR_MAC_SUCCESS_STATUS != __limValidateDelBAParameterSet( pMac,
                                             frmDelBAInd.DelBAParameterSet,
                                             pSta ))
      return;

  //
  // Post WDA_DELBA_IND to HAL and delete the
  // existing BA session
  //
  // NOTE - IEEE 802.11-REVma-D8.0, Section 7.3.1.16
  // is kind of confusing...
  //
  if( eSIR_SUCCESS != limPostMsgDelBAInd( pMac,
        pSta,
        (tANI_U8) frmDelBAInd.DelBAParameterSet.tid,
        (eBA_RECIPIENT == frmDelBAInd.DelBAParameterSet.initiator)?
          eBA_INITIATOR: eBA_RECIPIENT,psessionEntry))
<<<<<<< HEAD
<<<<<<< HEAD
    limLog( pMac, LOGE, FL( "Posting WDA_DELBA_IND to HAL failed \n"));
=======
    limLog( pMac, LOGE, FL( "Posting WDA_DELBA_IND to HAL failed "));
>>>>>>> d97af3b... add prima wlan driver
=======
    limLog( pMac, LOGE, FL( "Posting WDA_DELBA_IND to HAL failed \n"));
>>>>>>> 657b0e9... prima update

  return;

}

static void
__limProcessSMPowerSaveUpdate(tpAniSirGlobal pMac, tANI_U8 *pRxPacketInfo ,tpPESession psessionEntry)
{

#if 0
        tpSirMacMgmtHdr                           pHdr;
        tDot11fSMPowerSave                    frmSMPower;
        tSirMacHTMIMOPowerSaveState  state;
        tpDphHashNode                             pSta;
        tANI_U16                                        aid;
        tANI_U32                                        frameLen, nStatus;
        tANI_U8                                          *pBody;

        pHdr = SIR_MAC_BD_TO_MPDUHEADER( pBd );
        pBody = SIR_MAC_BD_TO_MPDUDATA( pBd );
        frameLen = SIR_MAC_BD_TO_PAYLOAD_LEN( pBd );

        pSta = dphLookupHashEntry(pMac, pHdr->sa, &aid, &psessionEntry->dph.dphHashTable );
        if( pSta == NULL ) {
<<<<<<< HEAD
<<<<<<< HEAD
            limLog( pMac, LOGE,FL( "STA context not found - ignoring UpdateSM PSave Mode from \n" ));
=======
            limLog( pMac, LOGE,FL( "STA context not found - ignoring UpdateSM PSave Mode from " ));
>>>>>>> d97af3b... add prima wlan driver
=======
            limLog( pMac, LOGE,FL( "STA context not found - ignoring UpdateSM PSave Mode from \n" ));
>>>>>>> 657b0e9... prima update
            limPrintMacAddr( pMac, pHdr->sa, LOGW );
            return;
        }

        /**Unpack the received frame */
        nStatus = dot11fUnpackSMPowerSave( pMac, pBody, frameLen, &frmSMPower);

        if( DOT11F_FAILED( nStatus )) {
<<<<<<< HEAD
<<<<<<< HEAD
            limLog( pMac, LOGE, FL( "Failed to unpack and parse a Update SM Power (0x%08x, %d bytes):\n"),
=======
            limLog( pMac, LOGE, FL( "Failed to unpack and parse a Update SM Power (0x%08x, %d bytes):"),
>>>>>>> d97af3b... add prima wlan driver
=======
            limLog( pMac, LOGE, FL( "Failed to unpack and parse a Update SM Power (0x%08x, %d bytes):\n"),
>>>>>>> 657b0e9... prima update
                                                    nStatus, frameLen );
            PELOG2(sirDumpBuf( pMac, SIR_DBG_MODULE_ID, LOG2, pBody, frameLen );)
            return;
        }else if ( DOT11F_WARNED( nStatus ) ) {
<<<<<<< HEAD
<<<<<<< HEAD
            limLog(pMac, LOGW, FL( "There were warnings while unpacking a SMPower Save update (0x%08x, %d bytes):\n"),
=======
            limLog(pMac, LOGW, FL( "There were warnings while unpacking a SMPower Save update (0x%08x, %d bytes):"),
>>>>>>> d97af3b... add prima wlan driver
=======
            limLog(pMac, LOGW, FL( "There were warnings while unpacking a SMPower Save update (0x%08x, %d bytes):\n"),
>>>>>>> 657b0e9... prima update
                                nStatus, frameLen );
            PELOG2(sirDumpBuf( pMac, SIR_DBG_MODULE_ID, LOG2, pBody, frameLen );)
        }

        limLog(pMac, LOGW, FL("Received SM Power save Mode update Frame with PS_Enable:%d"
                            "PS Mode: %d"), frmSMPower.SMPowerModeSet.PowerSave_En,
                                                    frmSMPower.SMPowerModeSet.Mode);

        /** Update in the DPH Table about the Update in the SM Power Save mode*/
        if (frmSMPower.SMPowerModeSet.PowerSave_En && frmSMPower.SMPowerModeSet.Mode)
            state = eSIR_HT_MIMO_PS_DYNAMIC;
        else if ((frmSMPower.SMPowerModeSet.PowerSave_En) && (frmSMPower.SMPowerModeSet.Mode ==0))
            state = eSIR_HT_MIMO_PS_STATIC;
        else if ((frmSMPower.SMPowerModeSet.PowerSave_En == 0) && (frmSMPower.SMPowerModeSet.Mode == 0))
            state = eSIR_HT_MIMO_PS_NO_LIMIT;
        else {
            PELOGW(limLog(pMac, LOGW, FL("Received SM Power save Mode update Frame with invalid mode"));)
            return;
        }

        if (state == pSta->htMIMOPSState) {
            PELOGE(limLog(pMac, LOGE, FL("The PEER is already set in the same mode"));)
            return;
        }

        /** Update in the HAL Station Table for the Update of the Protection Mode */
        pSta->htMIMOPSState = state;
        limPostSMStateUpdate(pMac,pSta->staIndex, pSta->htMIMOPSState);

#endif
        
}

#if defined WLAN_FEATURE_VOWIFI

static void
__limProcessRadioMeasureRequest( tpAniSirGlobal pMac, tANI_U8 *pRxPacketInfo ,tpPESession psessionEntry )
{
     tpSirMacMgmtHdr                pHdr;
     tDot11fRadioMeasurementRequest frm;
     tANI_U32                       frameLen, nStatus;
     tANI_U8                        *pBody;

     pHdr = WDA_GET_RX_MAC_HEADER( pRxPacketInfo );
     pBody = WDA_GET_RX_MPDU_DATA( pRxPacketInfo );
     frameLen = WDA_GET_RX_PAYLOAD_LEN( pRxPacketInfo );

     if( psessionEntry == NULL )
     {
          return;
     }

     /**Unpack the received frame */
     nStatus = dot11fUnpackRadioMeasurementRequest( pMac, pBody, frameLen, &frm );

     if( DOT11F_FAILED( nStatus )) {
<<<<<<< HEAD
<<<<<<< HEAD
          limLog( pMac, LOGE, FL( "Failed to unpack and parse a Radio Measure request (0x%08x, %d bytes):\n"),
=======
          limLog( pMac, LOGE, FL( "Failed to unpack and parse a Radio Measure request (0x%08x, %d bytes):"),
>>>>>>> d97af3b... add prima wlan driver
=======
          limLog( pMac, LOGE, FL( "Failed to unpack and parse a Radio Measure request (0x%08x, %d bytes):\n"),
>>>>>>> 657b0e9... prima update
                    nStatus, frameLen );
          PELOG2(sirDumpBuf( pMac, SIR_DBG_MODULE_ID, LOG2, pBody, frameLen );)
               return;
     }else if ( DOT11F_WARNED( nStatus ) ) {
<<<<<<< HEAD
<<<<<<< HEAD
          limLog(pMac, LOGW, FL( "There were warnings while unpacking a Radio Measure request (0x%08x, %d bytes):\n"),
=======
          limLog(pMac, LOGW, FL( "There were warnings while unpacking a Radio Measure request (0x%08x, %d bytes):"),
>>>>>>> d97af3b... add prima wlan driver
=======
          limLog(pMac, LOGW, FL( "There were warnings while unpacking a Radio Measure request (0x%08x, %d bytes):\n"),
>>>>>>> 657b0e9... prima update
                    nStatus, frameLen );
          PELOG2(sirDumpBuf( pMac, SIR_DBG_MODULE_ID, LOG2, pBody, frameLen );)
     }

     // Call rrm function to handle the request.

     rrmProcessRadioMeasurementRequest( pMac, pHdr->sa, &frm, psessionEntry );
}

static void
__limProcessLinkMeasurementReq( tpAniSirGlobal pMac, tANI_U8 *pRxPacketInfo ,tpPESession psessionEntry )
{
     tpSirMacMgmtHdr               pHdr;
     tDot11fLinkMeasurementRequest frm;
     tANI_U32                      frameLen, nStatus;
     tANI_U8                       *pBody;

     pHdr = WDA_GET_RX_MAC_HEADER( pRxPacketInfo );
     pBody = WDA_GET_RX_MPDU_DATA( pRxPacketInfo );
     frameLen = WDA_GET_RX_PAYLOAD_LEN( pRxPacketInfo );

     if( psessionEntry == NULL )
     {
          return;
     }

     /**Unpack the received frame */
     nStatus = dot11fUnpackLinkMeasurementRequest( pMac, pBody, frameLen, &frm );

     if( DOT11F_FAILED( nStatus )) {
<<<<<<< HEAD
<<<<<<< HEAD
          limLog( pMac, LOGE, FL( "Failed to unpack and parse a Link Measure request (0x%08x, %d bytes):\n"),
=======
          limLog( pMac, LOGE, FL( "Failed to unpack and parse a Link Measure request (0x%08x, %d bytes):"),
>>>>>>> d97af3b... add prima wlan driver
=======
          limLog( pMac, LOGE, FL( "Failed to unpack and parse a Link Measure request (0x%08x, %d bytes):\n"),
>>>>>>> 657b0e9... prima update
                    nStatus, frameLen );
          PELOG2(sirDumpBuf( pMac, SIR_DBG_MODULE_ID, LOG2, pBody, frameLen );)
               return;
     }else if ( DOT11F_WARNED( nStatus ) ) {
<<<<<<< HEAD
<<<<<<< HEAD
          limLog(pMac, LOGW, FL( "There were warnings while unpacking a Link Measure request (0x%08x, %d bytes):\n"),
=======
          limLog(pMac, LOGW, FL( "There were warnings while unpacking a Link Measure request (0x%08x, %d bytes):"),
>>>>>>> d97af3b... add prima wlan driver
=======
          limLog(pMac, LOGW, FL( "There were warnings while unpacking a Link Measure request (0x%08x, %d bytes):\n"),
>>>>>>> 657b0e9... prima update
                    nStatus, frameLen );
          PELOG2(sirDumpBuf( pMac, SIR_DBG_MODULE_ID, LOG2, pBody, frameLen );)
     }

     // Call rrm function to handle the request.

     rrmProcessLinkMeasurementRequest( pMac, pRxPacketInfo, &frm, psessionEntry );

}

static void
__limProcessNeighborReport( tpAniSirGlobal pMac, tANI_U8 *pRxPacketInfo ,tpPESession psessionEntry )
{
     tpSirMacMgmtHdr               pHdr;
     tDot11fNeighborReportResponse *pFrm;
     tANI_U32                      frameLen, nStatus;
     tANI_U8                       *pBody;

     pHdr = WDA_GET_RX_MAC_HEADER( pRxPacketInfo );
     pBody = WDA_GET_RX_MPDU_DATA( pRxPacketInfo );
     frameLen = WDA_GET_RX_PAYLOAD_LEN( pRxPacketInfo );

<<<<<<< HEAD
<<<<<<< HEAD
     if(eHAL_STATUS_SUCCESS != palAllocateMemory(pMac->hHdd, 
                                                 (void **)&pFrm, sizeof(tDot11fNeighborReportResponse)))
     {
         limLog(pMac, LOGE, FL("Unable to PAL allocate memory in __limProcessNeighborReport\n") );
         return;
     }

     if( psessionEntry == NULL )
     {
          palFreeMemory(pMac->hHdd, pFrm);
=======
     pFrm = vos_mem_malloc(sizeof(tDot11fNeighborReportResponse));
     if (NULL == pFrm)
=======
     if(eHAL_STATUS_SUCCESS != palAllocateMemory(pMac->hHdd, 
                                                 (void **)&pFrm, sizeof(tDot11fNeighborReportResponse)))
>>>>>>> 657b0e9... prima update
     {
         limLog(pMac, LOGE, FL("Unable to PAL allocate memory in __limProcessNeighborReport\n") );
         return;
     }

     if( psessionEntry == NULL )
     {
<<<<<<< HEAD
          vos_mem_free(pFrm);
>>>>>>> d97af3b... add prima wlan driver
=======
          palFreeMemory(pMac->hHdd, pFrm);
>>>>>>> 657b0e9... prima update
          return;
     }

     /**Unpack the received frame */
     nStatus = dot11fUnpackNeighborReportResponse( pMac, pBody, frameLen,pFrm );

     if( DOT11F_FAILED( nStatus )) {
<<<<<<< HEAD
<<<<<<< HEAD
          limLog( pMac, LOGE, FL( "Failed to unpack and parse a Neighbor report response (0x%08x, %d bytes):\n"),
                    nStatus, frameLen );
          PELOG2(sirDumpBuf( pMac, SIR_DBG_MODULE_ID, LOG2, pBody, frameLen );)
          palFreeMemory(pMac->hHdd, pFrm);
          return;
     }else if ( DOT11F_WARNED( nStatus ) ) {
          limLog(pMac, LOGW, FL( "There were warnings while unpacking a Neighbor report response (0x%08x, %d bytes):\n"),
=======
          limLog( pMac, LOGE, FL( "Failed to unpack and parse a Neighbor report response (0x%08x, %d bytes):"),
=======
          limLog( pMac, LOGE, FL( "Failed to unpack and parse a Neighbor report response (0x%08x, %d bytes):\n"),
>>>>>>> 657b0e9... prima update
                    nStatus, frameLen );
          PELOG2(sirDumpBuf( pMac, SIR_DBG_MODULE_ID, LOG2, pBody, frameLen );)
          palFreeMemory(pMac->hHdd, pFrm);
          return;
     }else if ( DOT11F_WARNED( nStatus ) ) {
<<<<<<< HEAD
          limLog(pMac, LOGW, FL( "There were warnings while unpacking a Neighbor report response (0x%08x, %d bytes):"),
>>>>>>> d97af3b... add prima wlan driver
=======
          limLog(pMac, LOGW, FL( "There were warnings while unpacking a Neighbor report response (0x%08x, %d bytes):\n"),
>>>>>>> 657b0e9... prima update
                    nStatus, frameLen );
          PELOG2(sirDumpBuf( pMac, SIR_DBG_MODULE_ID, LOG2, pBody, frameLen );)
     }

     //Call rrm function to handle the request.
     rrmProcessNeighborReportResponse( pMac, pFrm, psessionEntry ); 
     
<<<<<<< HEAD
<<<<<<< HEAD
     palFreeMemory(pMac->hHdd, pFrm);
=======
     vos_mem_free(pFrm);
>>>>>>> d97af3b... add prima wlan driver
=======
     palFreeMemory(pMac->hHdd, pFrm);
>>>>>>> 657b0e9... prima update
}

#endif

#ifdef WLAN_FEATURE_11W
/**
<<<<<<< HEAD
<<<<<<< HEAD
 * limProcessActionFrame
=======
 * limProcessSAQueryRequestActionFrame
>>>>>>> d97af3b... add prima wlan driver
=======
 * limProcessActionFrame
>>>>>>> 657b0e9... prima update
 *
 *FUNCTION:
 * This function is called by limProcessActionFrame() upon
 * SA query request Action frame reception.
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 *
 *NOTE:
 *
 * @param  pMac - Pointer to Global MAC structure
<<<<<<< HEAD
<<<<<<< HEAD
 * @param  *pBd - A pointer to Buffer descriptor + associated PDUs
 * @return None
 */
static void __limProcessSAQueryRequestActionFrame(tpAniSirGlobal pMac, tANI_U8 *pRxPacketInfo,tpPESession psessionEntry)
{
    tpSirMacMgmtHdr     pHdr;
    tANI_U8             *pBody;
    tANI_U16            transId = 0;           
=======
 * @param  *pRxPacketInfo - Handle to the Rx packet info
 * @param  psessionEntry - PE session entry
 *
=======
 * @param  *pBd - A pointer to Buffer descriptor + associated PDUs
>>>>>>> 657b0e9... prima update
 * @return None
 */
static void __limProcessSAQueryRequestActionFrame(tpAniSirGlobal pMac, tANI_U8 *pRxPacketInfo,tpPESession psessionEntry)
{
    tpSirMacMgmtHdr     pHdr;
    tANI_U8             *pBody;
<<<<<<< HEAD
    tANI_U8             transId[2];
>>>>>>> d97af3b... add prima wlan driver
=======
    tANI_U16            transId = 0;           
>>>>>>> 657b0e9... prima update

    /* Prima  --- Below Macro not available in prima 
       pHdr = SIR_MAC_BD_TO_MPDUHEADER(pBd);
       pBody = SIR_MAC_BD_TO_MPDUDATA(pBd); */

    pHdr = WDA_GET_RX_MAC_HEADER(pRxPacketInfo);
    pBody = WDA_GET_RX_MPDU_DATA(pRxPacketInfo);

<<<<<<< HEAD
<<<<<<< HEAD
=======
    /* If this is an unprotected SA Query Request, then ignore it. */
    if (pHdr->fc.wep == 0)
        return;

>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
    /*Extract 11w trsansId from SA query request action frame
      In SA query response action frame we will send same transId
      In SA query request action frame:
      Category       : 1 byte
      Action         : 1 byte
<<<<<<< HEAD
<<<<<<< HEAD
      Transaction ID : 2 bbytes */

    transId = pBody[2];
    transId = transId << 8;
    transId |= pBody[3];
    
=======
      Transaction ID : 2 bytes */
    vos_mem_copy(&transId[0], &pBody[2], 2);

>>>>>>> d97af3b... add prima wlan driver
=======
      Transaction ID : 2 bbytes */

    transId = pBody[2];
    transId = transId << 8;
    transId |= pBody[3];
    
>>>>>>> 657b0e9... prima update
    //Send 11w SA query response action frame
    if (limSendSaQueryResponseFrame(pMac,
                              transId,
                              pHdr->sa,psessionEntry) != eSIR_SUCCESS)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        PELOGE(limLog(pMac, LOGE, FL("fail to send SA query response action frame. \n"));)
=======
        PELOGE(limLog(pMac, LOGE, FL("fail to send SA query response action frame."));)
>>>>>>> d97af3b... add prima wlan driver
=======
        PELOGE(limLog(pMac, LOGE, FL("fail to send SA query response action frame. \n"));)
>>>>>>> 657b0e9... prima update
        return;
    }
}

<<<<<<< HEAD
<<<<<<< HEAD
=======
/**
 * __limProcessSAQueryResponseActionFrame
 *
 *FUNCTION:
 * This function is called by limProcessActionFrame() upon
 * SA query response Action frame reception.
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 *
 *NOTE:
 *
 * @param  pMac - Pointer to Global MAC structure
 * @param  *pRxPacketInfo - Handle to the Rx packet info
 * @param  psessionEntry - PE session entry
 * @return None
 */
static void __limProcessSAQueryResponseActionFrame(tpAniSirGlobal pMac, tANI_U8 *pRxPacketInfo, tpPESession psessionEntry)
{
    tpSirMacMgmtHdr     pHdr;
    tANI_U32            frameLen;

    pHdr = WDA_GET_RX_MAC_HEADER(pRxPacketInfo);
    frameLen = WDA_GET_RX_PAYLOAD_LEN(pRxPacketInfo);
    VOS_TRACE(VOS_MODULE_ID_PE, VOS_TRACE_LEVEL_INFO,
                         ("SA Query Response received...")) ;
    /* Forward to the SME to HDD to wpa_supplicant */
    // type is ACTION
    limSendSmeMgmtFrameInd(pMac, pHdr->fc.subType,
       (tANI_U8*)pHdr, frameLen + sizeof(tSirMacMgmtHdr), 0,
       WDA_GET_RX_CH( pRxPacketInfo ), psessionEntry, 0);
}

>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
#endif

/**
 * limProcessActionFrame
 *
 *FUNCTION:
 * This function is called by limProcessMessageQueue() upon
 * Action frame reception.
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 *
 *NOTE:
 *
 * @param  pMac - Pointer to Global MAC structure
 * @param  *pRxPacketInfo - A pointer to packet info structure
 * @return None
 */

void
limProcessActionFrame(tpAniSirGlobal pMac, tANI_U8 *pRxPacketInfo,tpPESession psessionEntry)
{
    tANI_U8 *pBody = WDA_GET_RX_MPDU_DATA(pRxPacketInfo);
    tpSirMacActionFrameHdr pActionHdr = (tpSirMacActionFrameHdr) pBody;
<<<<<<< HEAD
<<<<<<< HEAD

   
    switch (pActionHdr->category)
    {
        case SIR_MAC_ACTION_QOS_MGMT:
=======
#ifdef WLAN_FEATURE_11W
    tpSirMacMgmtHdr pHdr = WDA_GET_RX_MAC_HEADER(pRxPacketInfo);
#endif
=======
>>>>>>> 657b0e9... prima update

   
    switch (pActionHdr->category)
    {
        case SIR_MAC_ACTION_QOS_MGMT:
<<<<<<< HEAD
#ifdef WLAN_FEATURE_11W
            if ((psessionEntry->limRmfEnabled) && (pHdr->fc.wep == 0))
            {
                PELOGE(limLog(pMac, LOGE, FL("Dropping unprotected Action category %d frame "
                                             "since RMF is enabled."), pActionHdr->category);)
                break;
            }
#endif
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
            if (psessionEntry->limQosEnabled)
            {
                switch (pActionHdr->actionID)
                {
                    case SIR_MAC_QOS_ADD_TS_REQ:
                        __limProcessAddTsReq(pMac, (tANI_U8 *) pRxPacketInfo,psessionEntry);
                        break;

                    case SIR_MAC_QOS_ADD_TS_RSP:
                        __limProcessAddTsRsp(pMac, (tANI_U8 *) pRxPacketInfo,psessionEntry);
                        break;

                    case SIR_MAC_QOS_DEL_TS_REQ:
                        __limProcessDelTsReq(pMac, (tANI_U8 *) pRxPacketInfo,psessionEntry);
                        break;

                    default:
<<<<<<< HEAD
<<<<<<< HEAD
                        PELOGE(limLog(pMac, LOGE, FL("Qos action %d not handled\n"), pActionHdr->actionID);)
=======
                        PELOGE(limLog(pMac, LOGE, FL("Qos action %d not handled"), pActionHdr->actionID);)
>>>>>>> d97af3b... add prima wlan driver
=======
                        PELOGE(limLog(pMac, LOGE, FL("Qos action %d not handled\n"), pActionHdr->actionID);)
>>>>>>> 657b0e9... prima update
                        break;
                }
                break ;
            }

           break;

        case SIR_MAC_ACTION_SPECTRUM_MGMT:
<<<<<<< HEAD
<<<<<<< HEAD
=======
#ifdef WLAN_FEATURE_11W
            if ((psessionEntry->limRmfEnabled) && (pHdr->fc.wep == 0))
            {
                PELOGE(limLog(pMac, LOGE, FL("Dropping unprotected Action category %d frame "
                                             "since RMF is enabled."), pActionHdr->category);)
                break;
            }
#endif
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
            switch (pActionHdr->actionID)
            {
#ifdef ANI_SUPPORT_11H
                case SIR_MAC_ACTION_MEASURE_REQUEST_ID:
                    if(psessionEntry->lim11hEnable)
                    {
                        __limProcessMeasurementRequestFrame(pMac, pRxPacketInfo);
                    }
                    break;

                case SIR_MAC_ACTION_TPC_REQUEST_ID:
                    if ((psessionEntry->limSystemRole == eLIM_STA_ROLE) ||
                        (pessionEntry->limSystemRole == eLIM_AP_ROLE))
                    {
                        if(psessionEntry->lim11hEnable)
                        {
                            __limProcessTpcRequestFrame(pMac, pRxPacketInfo);
                        }
                    }
                    break;

#endif
                case SIR_MAC_ACTION_CHANNEL_SWITCH_ID:
                    if (psessionEntry->limSystemRole == eLIM_STA_ROLE)
                    {
                        __limProcessChannelSwitchActionFrame(pMac, pRxPacketInfo,psessionEntry);
                    }
                    break;
                default:
<<<<<<< HEAD
<<<<<<< HEAD
                    PELOGE(limLog(pMac, LOGE, FL("Spectrum mgmt action id %d not handled\n"), pActionHdr->actionID);)
=======
                    PELOGE(limLog(pMac, LOGE, FL("Spectrum mgmt action id %d not handled"), pActionHdr->actionID);)
>>>>>>> d97af3b... add prima wlan driver
=======
                    PELOGE(limLog(pMac, LOGE, FL("Spectrum mgmt action id %d not handled\n"), pActionHdr->actionID);)
>>>>>>> 657b0e9... prima update
                    break;
            }
            break;

        case SIR_MAC_ACTION_WME:
            if (! psessionEntry->limWmeEnabled)
            {
<<<<<<< HEAD
<<<<<<< HEAD
                limLog(pMac, LOGW, FL("WME mode disabled - dropping action frame %d\n"),
=======
                limLog(pMac, LOGW, FL("WME mode disabled - dropping action frame %d"),
>>>>>>> d97af3b... add prima wlan driver
=======
                limLog(pMac, LOGW, FL("WME mode disabled - dropping action frame %d\n"),
>>>>>>> 657b0e9... prima update
                       pActionHdr->actionID);
                break;
            }
            switch(pActionHdr->actionID)
            {
                case SIR_MAC_QOS_ADD_TS_REQ:
                    __limProcessAddTsReq(pMac, (tANI_U8 *) pRxPacketInfo,psessionEntry);
                    break;

                case SIR_MAC_QOS_ADD_TS_RSP:
                    __limProcessAddTsRsp(pMac, (tANI_U8 *) pRxPacketInfo,psessionEntry);
                    break;

                case SIR_MAC_QOS_DEL_TS_REQ:
                    __limProcessDelTsReq(pMac, (tANI_U8 *) pRxPacketInfo,psessionEntry);
                    break;

                default:
<<<<<<< HEAD
<<<<<<< HEAD
                    PELOGE(limLog(pMac, LOGE, FL("WME action %d not handled\n"), pActionHdr->actionID);)
=======
                    PELOGE(limLog(pMac, LOGE, FL("WME action %d not handled"), pActionHdr->actionID);)
>>>>>>> d97af3b... add prima wlan driver
=======
                    PELOGE(limLog(pMac, LOGE, FL("WME action %d not handled\n"), pActionHdr->actionID);)
>>>>>>> 657b0e9... prima update
                    break;
            }
            break;

        case SIR_MAC_ACTION_BLKACK:
            // Determine the "type" of BA Action Frame
<<<<<<< HEAD
<<<<<<< HEAD
=======
#ifdef WLAN_FEATURE_11W
            if ((psessionEntry->limRmfEnabled) && (pHdr->fc.wep == 0))
            {
                PELOGE(limLog(pMac, LOGE, FL("Dropping unprotected Action category %d frame "
                                             "since RMF is enabled."), pActionHdr->category);)
                break;
            }
#endif
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
            switch(pActionHdr->actionID)
            {
              case SIR_MAC_BLKACK_ADD_REQ:
                __limProcessAddBAReq( pMac, (tANI_U8 *) pRxPacketInfo,psessionEntry);
                break;

              case SIR_MAC_BLKACK_ADD_RSP:
                __limProcessAddBARsp( pMac, (tANI_U8 *) pRxPacketInfo,psessionEntry);
                break;

              case SIR_MAC_BLKACK_DEL:
                __limProcessDelBAReq( pMac, (tANI_U8 *) pRxPacketInfo,psessionEntry);
                break;

              default:
                break;
            }

            break;
    case SIR_MAC_ACTION_HT:
        /** Type of HT Action to be performed*/
        switch(pActionHdr->actionID) {
        case SIR_MAC_SM_POWER_SAVE:
            __limProcessSMPowerSaveUpdate(pMac, (tANI_U8 *) pRxPacketInfo,psessionEntry);
            break;
        default:
<<<<<<< HEAD
<<<<<<< HEAD
            PELOGE(limLog(pMac, LOGE, FL("Action ID %d not handled in HT Action category\n"), pActionHdr->actionID);)
=======
            PELOGE(limLog(pMac, LOGE, FL("Action ID %d not handled in HT Action category"), pActionHdr->actionID);)
>>>>>>> d97af3b... add prima wlan driver
=======
            PELOGE(limLog(pMac, LOGE, FL("Action ID %d not handled in HT Action category\n"), pActionHdr->actionID);)
>>>>>>> 657b0e9... prima update
            break;
        }
        break;

#if defined WLAN_FEATURE_VOWIFI
    case SIR_MAC_ACTION_RRM:
<<<<<<< HEAD
<<<<<<< HEAD
=======
#ifdef WLAN_FEATURE_11W
            if ((psessionEntry->limRmfEnabled) && (pHdr->fc.wep == 0))
            {
                PELOGE(limLog(pMac, LOGE, FL("Dropping unprotected Action category %d frame "
                                             "since RMF is enabled."), pActionHdr->category);)
                break;
            }
#endif
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
        if( pMac->rrm.rrmPEContext.rrmEnable )
        {
            switch(pActionHdr->actionID) {
                case SIR_MAC_RRM_RADIO_MEASURE_REQ:
                    __limProcessRadioMeasureRequest( pMac, (tANI_U8 *) pRxPacketInfo, psessionEntry );
                    break;
                case SIR_MAC_RRM_LINK_MEASUREMENT_REQ:
                    __limProcessLinkMeasurementReq( pMac, (tANI_U8 *) pRxPacketInfo, psessionEntry );
                    break;
                case SIR_MAC_RRM_NEIGHBOR_RPT:   
                    __limProcessNeighborReport( pMac, (tANI_U8*) pRxPacketInfo, psessionEntry );
                    break;
                default:
<<<<<<< HEAD
<<<<<<< HEAD
                    PELOGE( limLog( pMac, LOGE, FL("Action ID %d not handled in RRM\n"), pActionHdr->actionID);)
=======
                    PELOGE( limLog( pMac, LOGE, FL("Action ID %d not handled in RRM"), pActionHdr->actionID);)
>>>>>>> d97af3b... add prima wlan driver
=======
                    PELOGE( limLog( pMac, LOGE, FL("Action ID %d not handled in RRM\n"), pActionHdr->actionID);)
>>>>>>> 657b0e9... prima update
                    break;

            }
        }
        else
        {
            // Else we will just ignore the RRM messages.
<<<<<<< HEAD
<<<<<<< HEAD
            PELOGE( limLog( pMac, LOGE, FL("RRM Action frame ignored as RRM is disabled in cfg\n"));)
        }
        break;
#endif
#if defined WLAN_FEATURE_P2P
=======
            PELOGE( limLog( pMac, LOGE, FL("RRM Action frame ignored as RRM is disabled in cfg"));)
        }
        break;
#endif
#if  defined (WLAN_FEATURE_VOWIFI_11R) || defined (FEATURE_WLAN_CCX) || defined(FEATURE_WLAN_LFR)
        case SIR_MAC_ACTION_VENDOR_SPECIFIC_CATEGORY:
            {
              tpSirMacVendorSpecificFrameHdr pVendorSpecific = (tpSirMacVendorSpecificFrameHdr) pActionHdr;
              tpSirMacMgmtHdr     pHdr;
              tANI_U32            frameLen;
              tANI_U8 Oui[] = { 0x00, 0x00, 0xf0 };

              pHdr = WDA_GET_RX_MAC_HEADER(pRxPacketInfo);
              frameLen = WDA_GET_RX_PAYLOAD_LEN(pRxPacketInfo);

              //Check if it is a vendor specific action frame.
              if ((eLIM_STA_ROLE == psessionEntry->limSystemRole) &&
                  (VOS_TRUE == vos_mem_compare(psessionEntry->selfMacAddr,
                    &pHdr->da[0], sizeof(tSirMacAddr))) &&
                   vos_mem_compare(pVendorSpecific->Oui, Oui, 3))
              {
                  PELOGE( limLog( pMac, LOGW, FL("Received Vendor specific action frame, OUI %x %x %x"),
                         pVendorSpecific->Oui[0], pVendorSpecific->Oui[1], pVendorSpecific->Oui[2]);)
                 /* Forward to the SME to HDD to wpa_supplicant */
                 // type is ACTION
                 limSendSmeMgmtFrameInd(pMac, pHdr->fc.subType,
                    (tANI_U8*)pHdr, frameLen + sizeof(tSirMacMgmtHdr), 0,
                    WDA_GET_RX_CH( pRxPacketInfo ), psessionEntry, 0);
              }
              else
              {
                 limLog( pMac, LOGE, FL("Dropping the vendor specific action frame because of( "
                                        "OUI mismatch (%02x %02x %02x) or "
                                        "not received with SelfSta Mac address) system role = %d"),
                                        pVendorSpecific->Oui[0], pVendorSpecific->Oui[1],
                                        pVendorSpecific->Oui[2],
                                        psessionEntry->limSystemRole );
              }
           }
           break;
#endif
>>>>>>> d97af3b... add prima wlan driver
=======
            PELOGE( limLog( pMac, LOGE, FL("RRM Action frame ignored as RRM is disabled in cfg\n"));)
        }
        break;
#endif
#if defined WLAN_FEATURE_P2P
>>>>>>> 657b0e9... prima update
    case SIR_MAC_ACTION_PUBLIC_USAGE:
        switch(pActionHdr->actionID) {
        case SIR_MAC_ACTION_VENDOR_SPECIFIC:
            {
              tpSirMacVendorSpecificPublicActionFrameHdr pPubAction = (tpSirMacVendorSpecificPublicActionFrameHdr) pActionHdr;
              tpSirMacMgmtHdr     pHdr;
              tANI_U32            frameLen;
              tANI_U8 P2POui[] = { 0x50, 0x6F, 0x9A, 0x09 };

              pHdr = WDA_GET_RX_MAC_HEADER(pRxPacketInfo);
              frameLen = WDA_GET_RX_PAYLOAD_LEN(pRxPacketInfo);

              //Check if it is a P2P public action frame.
<<<<<<< HEAD
<<<<<<< HEAD
              if( palEqualMemory( pMac->hHdd, pPubAction->Oui, P2POui, 4 ) )
=======
              if (vos_mem_compare(pPubAction->Oui, P2POui, 4))
>>>>>>> d97af3b... add prima wlan driver
=======
              if( palEqualMemory( pMac->hHdd, pPubAction->Oui, P2POui, 4 ) )
>>>>>>> 657b0e9... prima update
              {
                 /* Forward to the SME to HDD to wpa_supplicant */
                 // type is ACTION
                 limSendSmeMgmtFrameInd(pMac, pHdr->fc.subType, 
                    (tANI_U8*)pHdr, frameLen + sizeof(tSirMacMgmtHdr), 0, 
<<<<<<< HEAD
<<<<<<< HEAD
                    WDA_GET_RX_CH( pRxPacketInfo ), psessionEntry);
              }
              else
              {
                 limLog( pMac, LOGE, FL("Unhandled public action frame (Vendor specific). OUI %x %x %x %x\n"),
=======
                    WDA_GET_RX_CH( pRxPacketInfo ), psessionEntry, 0);
              }
              else
              {
                 limLog( pMac, LOGE, FL("Unhandled public action frame (Vendor specific). OUI %x %x %x %x"),
>>>>>>> d97af3b... add prima wlan driver
=======
                    WDA_GET_RX_CH( pRxPacketInfo ), psessionEntry);
              }
              else
              {
                 limLog( pMac, LOGE, FL("Unhandled public action frame (Vendor specific). OUI %x %x %x %x\n"),
>>>>>>> 657b0e9... prima update
                      pPubAction->Oui[0], pPubAction->Oui[1], pPubAction->Oui[2], pPubAction->Oui[3] );
              }
           }
            break;
<<<<<<< HEAD
<<<<<<< HEAD

        default:
            PELOGE(limLog(pMac, LOGE, FL("Unhandled public action frame -- %x \n"), pActionHdr->actionID);)
            break;
        }
        break;
#endif
=======
#ifdef FEATURE_WLAN_TDLS
           case SIR_MAC_TDLS_DIS_RSP:
           {
#ifdef FEATURE_WLAN_TDLS_INTERNAL
               //LIM_LOG_TDLS(printk("Public Action TDLS Discovery RSP ..")) ;
               limProcessTdlsPublicActionFrame(pMac, (tANI_U32*)pRxPacketInfo, psessionEntry) ;
#else
               tpSirMacMgmtHdr     pHdr;
               tANI_U32            frameLen;
               tANI_S8             rssi;

               pHdr = WDA_GET_RX_MAC_HEADER(pRxPacketInfo);
               frameLen = WDA_GET_RX_PAYLOAD_LEN(pRxPacketInfo);
               rssi = WDA_GET_RX_RSSI_DB(pRxPacketInfo);
               VOS_TRACE(VOS_MODULE_ID_PE, VOS_TRACE_LEVEL_INFO, 
                                    ("Public Action TDLS Discovery RSP ..")) ;
               limSendSmeMgmtFrameInd(pMac, pHdr->fc.subType, 
                  (tANI_U8*)pHdr, frameLen + sizeof(tSirMacMgmtHdr), 0, 
                  WDA_GET_RX_CH( pRxPacketInfo ), psessionEntry, rssi);
#endif
           }
               break;
#endif
=======
>>>>>>> 657b0e9... prima update

        default:
            PELOGE(limLog(pMac, LOGE, FL("Unhandled public action frame -- %x \n"), pActionHdr->actionID);)
            break;
        }
        break;
<<<<<<< HEAD
>>>>>>> d97af3b... add prima wlan driver
=======
#endif
>>>>>>> 657b0e9... prima update

#ifdef WLAN_FEATURE_11W
    case SIR_MAC_ACTION_SA_QUERY:
    {
<<<<<<< HEAD
<<<<<<< HEAD
        /**11w SA query request action frame received**/
        __limProcessSAQueryRequestActionFrame(pMac,(tANI_U8*) pRxPacketInfo, psessionEntry );
        break;
     }
#endif

    default:
       PELOGE(limLog(pMac, LOGE, FL("Action category %d not handled\n"), pActionHdr->category);)
=======
        PELOGE(limLog(pMac, LOG1, FL("SA Query Action category %d action %d."), pActionHdr->category, pActionHdr->actionID);)
        switch (pActionHdr->actionID)
        {
            case  SIR_MAC_SA_QUERY_REQ:
                /**11w SA query request action frame received**/
                /* Respond directly to the incoming request in LIM */
                __limProcessSAQueryRequestActionFrame(pMac,(tANI_U8*) pRxPacketInfo, psessionEntry );
                break;
            case  SIR_MAC_SA_QUERY_RSP:
                /**11w SA query response action frame received**/
                /* Forward to the SME to HDD to wpa_supplicant */
                __limProcessSAQueryResponseActionFrame(pMac,(tANI_U8*) pRxPacketInfo, psessionEntry );
                break;
            default:
                break;
        }
=======
        /**11w SA query request action frame received**/
        __limProcessSAQueryRequestActionFrame(pMac,(tANI_U8*) pRxPacketInfo, psessionEntry );
>>>>>>> 657b0e9... prima update
        break;
     }
#endif

    default:
<<<<<<< HEAD
       PELOGE(limLog(pMac, LOGE, FL("Action category %d not handled"), pActionHdr->category);)
>>>>>>> d97af3b... add prima wlan driver
=======
       PELOGE(limLog(pMac, LOGE, FL("Action category %d not handled\n"), pActionHdr->category);)
>>>>>>> 657b0e9... prima update
       break;
    }
}

<<<<<<< HEAD
<<<<<<< HEAD
#if defined WLAN_FEATURE_P2P
=======
>>>>>>> d97af3b... add prima wlan driver
=======
#if defined WLAN_FEATURE_P2P
>>>>>>> 657b0e9... prima update
/**
 * limProcessActionFrameNoSession
 *
 *FUNCTION:
 * This function is called by limProcessMessageQueue() upon
 * Action frame reception and no session.
 * Currently only public action frames can be received from
 * a non-associated station.
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 *
 *NOTE:
 *
 * @param  pMac - Pointer to Global MAC structure
 * @param  *pBd - A pointer to Buffer descriptor + associated PDUs
 * @return None
 */

void
limProcessActionFrameNoSession(tpAniSirGlobal pMac, tANI_U8 *pBd)
{
   tANI_U8 *pBody = WDA_GET_RX_MPDU_DATA(pBd);
   tpSirMacVendorSpecificPublicActionFrameHdr pActionHdr = (tpSirMacVendorSpecificPublicActionFrameHdr) pBody;

   limLog( pMac, LOG1, "Received a Action frame -- no session");

   switch ( pActionHdr->category )
   {
      case SIR_MAC_ACTION_PUBLIC_USAGE:
         switch(pActionHdr->actionID) {
            case SIR_MAC_ACTION_VENDOR_SPECIFIC:
              {
                tpSirMacMgmtHdr     pHdr;
                tANI_U32            frameLen;
                tANI_U8 P2POui[] = { 0x50, 0x6F, 0x9A, 0x09 };

                pHdr = WDA_GET_RX_MAC_HEADER(pBd);
                frameLen = WDA_GET_RX_PAYLOAD_LEN(pBd);

                //Check if it is a P2P public action frame.
<<<<<<< HEAD
<<<<<<< HEAD
                if( palEqualMemory( pMac->hHdd, pActionHdr->Oui, P2POui, 4 ) )
=======
                if (vos_mem_compare(pActionHdr->Oui, P2POui, 4))
>>>>>>> d97af3b... add prima wlan driver
=======
                if( palEqualMemory( pMac->hHdd, pActionHdr->Oui, P2POui, 4 ) )
>>>>>>> 657b0e9... prima update
                {
                  /* Forward to the SME to HDD to wpa_supplicant */
                  // type is ACTION
                  limSendSmeMgmtFrameInd(pMac, pHdr->fc.subType, 
                      (tANI_U8*)pHdr, frameLen + sizeof(tSirMacMgmtHdr), 0,
<<<<<<< HEAD
<<<<<<< HEAD
                      WDA_GET_RX_CH( pBd ), NULL);
                }
                else
                {
                  limLog( pMac, LOGE, FL("Unhandled public action frame (Vendor specific). OUI %x %x %x %x\n"),
=======
                      WDA_GET_RX_CH( pBd ), NULL, 0);
                }
                else
                {
                  limLog( pMac, LOGE, FL("Unhandled public action frame (Vendor specific). OUI %x %x %x %x"),
>>>>>>> d97af3b... add prima wlan driver
=======
                      WDA_GET_RX_CH( pBd ), NULL);
                }
                else
                {
                  limLog( pMac, LOGE, FL("Unhandled public action frame (Vendor specific). OUI %x %x %x %x\n"),
>>>>>>> 657b0e9... prima update
                      pActionHdr->Oui[0], pActionHdr->Oui[1], pActionHdr->Oui[2], pActionHdr->Oui[3] );
                }
              }
               break;
            default:
<<<<<<< HEAD
<<<<<<< HEAD
               PELOGE(limLog(pMac, LOGE, FL("Unhandled public action frame -- %x \n"), pActionHdr->actionID);)
=======
               PELOGE(limLog(pMac, LOGE, FL("Unhandled public action frame -- %x "), pActionHdr->actionID);)
>>>>>>> d97af3b... add prima wlan driver
=======
               PELOGE(limLog(pMac, LOGE, FL("Unhandled public action frame -- %x \n"), pActionHdr->actionID);)
>>>>>>> 657b0e9... prima update
                  break;
         }
         break;
      default:
<<<<<<< HEAD
<<<<<<< HEAD
         PELOGE(limLog(pMac, LOG1, FL("Unhandled action frame without session -- %x \n"), pActionHdr->category);)
=======
         PELOGE(limLog(pMac, LOG1, FL("Unhandled action frame without session -- %x "), pActionHdr->category);)
>>>>>>> d97af3b... add prima wlan driver
=======
         PELOGE(limLog(pMac, LOG1, FL("Unhandled action frame without session -- %x \n"), pActionHdr->category);)
>>>>>>> 657b0e9... prima update
            break;

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
