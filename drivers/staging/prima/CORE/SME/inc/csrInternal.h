/*
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
/** ------------------------------------------------------------------------- * 
    ------------------------------------------------------------------------- *  

  
    \file csrInternal.h
  
    Define internal data structure for MAC.
  
    Copyright (C) 2006 Airgo Networks, Incorporated 
=======
/** ------------------------------------------------------------------------- *
    ------------------------------------------------------------------------- *


    \file csrInternal.h

    Define internal data structure for MAC.

    Copyright (C) 2006 Airgo Networks, Incorporated
>>>>>>> d97af3b... add prima wlan driver
   ========================================================================== */
#ifndef CSRINTERNAL_H__
#define CSRINTERNAL_H__

<<<<<<< HEAD
#if defined(VOSS_ENABLED)
#include "vos_status.h"
#include "vos_lock.h"
#endif //#if defined(VOSS_ENABLED)
=======
#include "vos_status.h"
#include "vos_lock.h"
>>>>>>> d97af3b... add prima wlan driver

#include "palTimer.h"
#include "csrSupport.h"
#include "vos_nvitem.h"
#include "wlan_qct_tl.h"

#ifdef WLAN_FEATURE_NEIGHBOR_ROAMING
#include "csrNeighborRoam.h"
#endif

#define CSR_MAX_STA (HAL_NUM_STA)

#define CSR_SME_SCAN_FLAGS_DELETE_CACHE     0x80

#define CSR_TITAN_MAX_RATE_MIMO_CB 240
#define CSR_TITAN_MAX_RATE_MIMO    126

//define scan return criteria. LIM should use these define as well
#define CSR_SCAN_RETURN_AFTER_ALL_CHANNELS          (    0 )
#define CSR_SCAN_RETURN_AFTER_FIRST_MATCH           ( 0x01 )
#define CSR_SCAN_RETURN_AFTER_5_BAND_11d_FOUND      ( 0x80 )
#define CSR_SCAN_RETURN_AFTER_24_BAND_11d_FOUND     ( 0x40 )
#define CSR_SCAN_RETURN_AFTER_EITHER_BAND_11d_FOUND ( CSR_SCAN_RETURN_AFTER_5_BAND_11d_FOUND | CSR_SCAN_RETURN_AFTER_24_BAND_11d_FOUND )
#define CSR_NUM_RSSI_CAT        15
#define CSR_MAX_STATISTICS_REQ        10

//Support for multiple session
#define CSR_SESSION_ID_INVALID    0xFF   // session ID invalid
#define CSR_ROAM_SESSION_MAX      5   // No of sessions to be supported, and a
                                      // session is for Infra, IBSS or BT-AMP

#define CSR_IS_SESSION_VALID( pMac, sessionId ) ( ( (sessionId) < CSR_ROAM_SESSION_MAX ) \
                                                  && ( (pMac)->roam.roamSession[(sessionId)].sessionActive ) )
#define CSR_GET_SESSION( pMac, sessionId ) \
( \
    (sessionId < CSR_ROAM_SESSION_MAX) ? \
     (&(pMac)->roam.roamSession[(sessionId)]) :\
     NULL \
)

<<<<<<< HEAD
//Support for "Fast roaming" (i.e., CCX, LFR, or 802.11r.)
#define CSR_BG_SCAN_OCCUPIED_CHANNEL_LIST_LEN 15  
#define CSR_BG_SCAN_VALID_CHANNEL_LIST_CHUNK_SIZE 3
#define CSR_BG_SCAN_CHANNEL_LIST_LEN (CSR_BG_SCAN_OCCUPIED_CHANNEL_LIST_LEN + CSR_BG_SCAN_VALID_CHANNEL_LIST_CHUNK_SIZE)


=======
#if  defined (WLAN_FEATURE_VOWIFI_11R) || defined (FEATURE_WLAN_CCX) || defined(FEATURE_WLAN_LFR)
#define CSR_IS_ROAM_PREFER_5GHZ( pMac ) \
( \
   (((pMac)->roam.configParam.nRoamPrefer5GHz)?eANI_BOOLEAN_TRUE:eANI_BOOLEAN_FALSE) \
)
#define CSR_IS_ROAM_INTRA_BAND_ENABLED( pMac ) \
( \
   (((pMac)->roam.configParam.nRoamIntraBand)?eANI_BOOLEAN_TRUE:eANI_BOOLEAN_FALSE) \
)
#endif

#ifdef WLAN_FEATURE_ROAM_SCAN_OFFLOAD
#define CSR_IS_ROAM_SCAN_OFFLOAD_ENABLED( pMac ) \
( \
   (((pMac)->roam.configParam.isRoamOffloadScanEnabled)?eANI_BOOLEAN_TRUE:eANI_BOOLEAN_FALSE) \
)

#define CSR_IS_FASTROAM_IN_CONCURRENCY_INI_FEATURE_ENABLED( pMac ) \
( \
   (((pMac)->roam.configParam.bFastRoamInConIniFeatureEnabled)?eANI_BOOLEAN_TRUE:eANI_BOOLEAN_FALSE) \
)
#endif

//Support for "Fast roaming" (i.e., CCX, LFR, or 802.11r.)
#define CSR_BG_SCAN_OCCUPIED_CHANNEL_LIST_LEN 15
>>>>>>> d97af3b... add prima wlan driver

typedef enum
{
    //eCSR_CFG_DOT11_MODE_BEST = 0,
    eCSR_CFG_DOT11_MODE_TAURUS = 0,
<<<<<<< HEAD
    eCSR_CFG_DOT11_MODE_ABG,    
    eCSR_CFG_DOT11_MODE_11A,    
    eCSR_CFG_DOT11_MODE_11B,    
    eCSR_CFG_DOT11_MODE_11G,    
    eCSR_CFG_DOT11_MODE_11N,   
    eCSR_CFG_DOT11_MODE_POLARIS,    
    eCSR_CFG_DOT11_MODE_TITAN,    
#ifdef WLAN_FEATURE_11AC
    eCSR_CFG_DOT11_MODE_11AC,
#endif
#ifdef WLAN_SOFTAP_FEATURE
    eCSR_CFG_DOT11_MODE_11G_ONLY,    
    eCSR_CFG_DOT11_MODE_11N_ONLY,   
#endif 
#ifdef WLAN_FEATURE_11AC
    eCSR_CFG_DOT11_MODE_11AC_ONLY,
#endif 
=======
    eCSR_CFG_DOT11_MODE_ABG,
    eCSR_CFG_DOT11_MODE_11A,
    eCSR_CFG_DOT11_MODE_11B,
    eCSR_CFG_DOT11_MODE_11G,
    eCSR_CFG_DOT11_MODE_11N,
    eCSR_CFG_DOT11_MODE_POLARIS,
    eCSR_CFG_DOT11_MODE_TITAN,
#ifdef WLAN_FEATURE_11AC
    eCSR_CFG_DOT11_MODE_11AC,
#endif
    eCSR_CFG_DOT11_MODE_11G_ONLY,
    eCSR_CFG_DOT11_MODE_11N_ONLY,
#ifdef WLAN_FEATURE_11AC
    eCSR_CFG_DOT11_MODE_11AC_ONLY,
#endif
>>>>>>> d97af3b... add prima wlan driver
    //This value can never set to CFG. It is for CSR's internal use
    eCSR_CFG_DOT11_MODE_AUTO,
}eCsrCfgDot11Mode;  //Used to determine what to set to the WNI_CFG_DOT11_MODE

<<<<<<< HEAD
typedef enum etCsrRoamCommands 
{
    eCsrRoamNoCommand,                 
    eCsrRoamCommandScan,
    eCsrRoamCommandRoam, 
    eCsrRoamCommandWmStatusChange, 
=======
typedef enum etCsrRoamCommands
{
    eCsrRoamNoCommand,
    eCsrRoamCommandScan,
    eCsrRoamCommandRoam,
    eCsrRoamCommandWmStatusChange,
>>>>>>> d97af3b... add prima wlan driver
    eCsrRoamCommandSetKey,
    eCsrRoamCommandRemoveKey,

} eCsrRoamCommands;

<<<<<<< HEAD
typedef enum  
=======
typedef enum
>>>>>>> d97af3b... add prima wlan driver
{
    eCsrScanOther = 1,
    eCsrScanLostLink1,
    eCsrScanLostLink2,
    eCsrScanLostLink3,
    eCsrScanLostLink4,
    eCsrScan11d1,  //First 11d scan
    eCsrScan11d2,  //First 11d scan has failed
    eCsrScan11dDone,  //11d scan succeeded, try the rest of the channel
    eCsrScanUserRequest,
    eCsrScanGetResult,
    eCsrScanSetBGScanParam, //used for HO too - bg scan request in NT Handoff sub-state
    eCsrScanForSsid,
    eCsrScanForCapsChange,
    eCsrScanBGScanAbort,
    eCsrScanBGScanEnable,
    eCsrScanIdleScan,
    eCsrScanGetScanChnInfo,     //To get the list of channels scanned

    eCsrScanBgScan, // bg scan request in NRT & RT Handoff sub-states
    eCsrScanProbeBss, // directed probe on an entry from the candidate list - HO
    eCsrScanAbortBgScan,    //aborting a BG scan (meaning the scan is triggered by LIM timer)
    eCsrScanAbortNormalScan, //aborting a normal scan (the scan is trigger by eWNI_SME_SCAN_REQ)
<<<<<<< HEAD
    eCsrScanP2PFindPeer    
}eCsrScanReason;

typedef enum 
=======
    eCsrScanP2PFindPeer,
    eCsrScanGetLfrResult, // get the LFR candidates from PE scan cache
}eCsrScanReason;

typedef enum
>>>>>>> d97af3b... add prima wlan driver
{
    eCsrNoConnection,          // Roaming because we have not established the initial connection.
    eCsrCapsChange,            // roaming because LIM reported a Capability change in the associated AP.
    eCsrForcedDisassoc,        // roaming becuase someone asked us to Disassoc and stay disassociated.
    eCsrHddIssued,             // roaming because an 802.11 request was issued to the driver.
    eCsrLostLink1,             // roaming because we lost link to an associated AP
<<<<<<< HEAD
    eCsrLostLink2, 
=======
    eCsrLostLink2,
>>>>>>> d97af3b... add prima wlan driver
    eCsrLostLink3,
    eCsrForcedDisassocMICFailure, // roaming because we need to force a Disassoc due to MIC failure
    eCsrHddIssuedReassocToSameAP,
    eCsrSmeIssuedReassocToSameAP,
    eCsrSmeIssuedReassocToDiffAP,
    eCsrForcedDeauth,        // roaming becuase someone asked us to deauth and stay disassociated.
    eCsrSmeIssuedDisassocForHandoff, // will be issued by Handoff logic to disconect from current AP
    eCsrSmeIssuedAssocToSimilarAP, // will be issued by Handoff logic to join a new AP with same profile
    eCsrSmeIssuedIbssJoinFailure, // ibss join timer fired before any perr showed up, so shut down the network
    eCsrForcedIbssLeave,
    eCsrStopBss,
    eCsrSmeIssuedFTReassoc,
    eCsrForcedDisassocSta,
    eCsrForcedDeauthSta,
    eCsrPerformPreauth,
<<<<<<< HEAD
    
=======
    eCsrLostLink1Abort,
    eCsrLostLink2Abort,
    eCsrLostLink3Abort,

>>>>>>> d97af3b... add prima wlan driver
}eCsrRoamReason;

typedef enum
{
<<<<<<< HEAD
    eCSR_ROAM_SUBSTATE_NONE = 0,                 
    eCSR_ROAM_SUBSTATE_START_BSS_REQ,            
    eCSR_ROAM_SUBSTATE_JOIN_REQ,                 
    eCSR_ROAM_SUBSTATE_REASSOC_REQ,              
    eCSR_ROAM_SUBSTATE_DISASSOC_REQ,             
    eCSR_ROAM_SUBSTATE_STOP_BSS_REQ,             
    eCSR_ROAM_SUBSTATE_DISCONNECT_CONTINUE_ROAMING,   //Continue the current roam command after disconnect            
    eCSR_ROAM_SUBSTATE_AUTH_REQ,                 
    eCSR_ROAM_SUBSTATE_CONFIG,                   
    eCSR_ROAM_SUBSTATE_DEAUTH_REQ,               
    eCSR_ROAM_SUBSTATE_DISASSOC_NOTHING_TO_JOIN, 
    eCSR_ROAM_SUBSTATE_DISASSOC_REASSOC_FAILURE, 
    eCSR_ROAM_SUBSTATE_DISASSOC_FORCED,          
=======
    eCSR_ROAM_SUBSTATE_NONE = 0,
    eCSR_ROAM_SUBSTATE_START_BSS_REQ,
    eCSR_ROAM_SUBSTATE_JOIN_REQ,
    eCSR_ROAM_SUBSTATE_REASSOC_REQ,
    eCSR_ROAM_SUBSTATE_DISASSOC_REQ,
    eCSR_ROAM_SUBSTATE_STOP_BSS_REQ,
    eCSR_ROAM_SUBSTATE_DISCONNECT_CONTINUE_ROAMING,   //Continue the current roam command after disconnect
    eCSR_ROAM_SUBSTATE_AUTH_REQ,
    eCSR_ROAM_SUBSTATE_CONFIG,
    eCSR_ROAM_SUBSTATE_DEAUTH_REQ,
    eCSR_ROAM_SUBSTATE_DISASSOC_NOTHING_TO_JOIN,
    eCSR_ROAM_SUBSTATE_DISASSOC_REASSOC_FAILURE,
    eCSR_ROAM_SUBSTATE_DISASSOC_FORCED,
>>>>>>> d97af3b... add prima wlan driver
    eCSR_ROAM_SUBSTATE_WAIT_FOR_KEY,
    eCSR_ROAM_SUBSTATE_DISASSOC_HANDOFF,
    eCSR_ROAM_SUBSTATE_JOINED_NO_TRAFFIC,
    eCSR_ROAM_SUBSTATE_JOINED_NON_REALTIME_TRAFFIC,
    eCSR_ROAM_SUBSTATE_JOINED_REALTIME_TRAFFIC,
//  max is 15 unless the bitfield is expanded...
} eCsrRoamSubState;


<<<<<<< HEAD
typedef enum 
=======
typedef enum
>>>>>>> d97af3b... add prima wlan driver
{
  eCSR_ROAMING_STATE_STOP = 0,
  eCSR_ROAMING_STATE_IDLE,
  eCSR_ROAMING_STATE_SCANNING,
  eCSR_ROAMING_STATE_JOINING,
  eCSR_ROAMING_STATE_JOINED,
}eCsrRoamState;


<<<<<<< HEAD
typedef enum 
=======
typedef enum
>>>>>>> d97af3b... add prima wlan driver
{
    eCsrContinueRoaming,
    eCsrStopRoaming,
    eCsrStartIbss,
    eCsrStartIbssSameIbss,
    eCsrReassocToSelfNoCapChange,
    eCsrStopRoamingDueToConcurrency,
<<<<<<< HEAD
    
=======

>>>>>>> d97af3b... add prima wlan driver
}eCsrJoinState;

typedef enum
{
    eCsrNotRoaming,
    eCsrLostlinkRoamingDisassoc,
    eCsrLostlinkRoamingDeauth,
    eCsrDynamicRoaming,
   eCsrReassocRoaming,
}eCsrRoamingReason;

<<<<<<< HEAD
typedef enum 
=======
typedef enum
>>>>>>> d97af3b... add prima wlan driver
{
    eCsrDisassociated,
    eCsrDeauthenticated

}eCsrRoamWmStatusChangeTypes;

typedef enum
{
   eCsrSummaryStats = 0,
   eCsrGlobalClassAStats,
   eCsrGlobalClassBStats,
   eCsrGlobalClassCStats,
   eCsrGlobalClassDStats,
   eCsrPerStaStats,
   eCsrMaxStats
}eCsrRoamStatsClassTypes;

#ifdef FEATURE_WLAN_DIAG_SUPPORT
typedef enum
{
   eCSR_WLAN_STATUS_CONNECT =0,
   eCSR_WLAN_STATUS_DISCONNECT

}eCsrDiagWlanStatusEventSubtype;

typedef enum
{
   eCSR_REASON_UNSPECIFIED = 0,
   eCSR_REASON_USER_REQUESTED,
   eCSR_REASON_MIC_ERROR,
   eCSR_REASON_DISASSOC,
   eCSR_REASON_DEAUTH,
   eCSR_REASON_HANDOFF,

}eCsrDiagWlanStatusEventReason;

typedef enum
{
   eCSR_WLAN_HANDOFF_EVENT =0,

}eCsrDiagWlanHandoffEventSubtype;

typedef enum
{
   eCSR_WLAN_VCC_EVENT =0,

}eCsrDiagWlanVccEventSubtype;

#endif //FEATURE_WLAN_DIAG_SUPPORT

typedef struct tagCsrChannel
{
    tANI_U8 numChannels;
    tANI_U8 channelList[WNI_CFG_VALID_CHANNEL_LIST_LEN];
}tCsrChannel;

typedef struct tagScanProfile
{
    tANI_U32 minChnTime;
    tANI_U32 maxChnTime;
    tANI_U32 restTime;  //This is ignored if not associated
    tANI_U32 numOfChannels;
    tANI_U8 *pChannelList;
    tSirScanType scanType;  //active or passive
    eCsrRoamBssType bssType;    //BSS or IBSS
    tANI_U8 ssid[WNI_CFG_SSID_LEN];
    tANI_U8 bReturnAfter1stMatch;
    tANI_U8 fUniqueResult;
    tANI_U8 freshScan;
    tCsrBssid bssid;
}tScanProfile;

typedef struct tagBssConfigParam
{
    eCsrMediaAccessType qosType;
    tSirMacSSid SSID;
    tANI_U32 uRTSThresh;
    tANI_U32 uDeferThresh;  //
    eCsrCfgDot11Mode uCfgDot11Mode;
    eCsrBand eBand;
    tANI_U8 standardRate[CSR_DOT11_SUPPORTED_RATES_MAX];
    tANI_U8 extendedRate[CSR_DOT11_EXTENDED_SUPPORTED_RATES_MAX];
    eCsrExposedTxRate txRate;
    tAniAuthType authType;
    eCsrEncryptionType encType;
    tANI_U32 uShortSlotTime;
    tANI_U32 uHTSupport;    //High throughput
    tANI_U32 uPowerLimit;
    tANI_U32 uHeartBeatThresh;
    tANI_U32 uJoinTimeOut;
    tSirMacCapabilityInfo BssCap;
    tANI_BOOLEAN f11hSupport;
    ePhyChanBondState cbMode;
}tBssConfigParam;


typedef struct tagCsrRoamStartBssParams
{
    tSirMacSSid         ssId;
    tCsrBssid           bssid;    //this is the BSSID for the party we want to join (only use for IBSS or WDS)
    tSirNwType          sirNwType;
    ePhyChanBondState   cbMode;
    tSirMacRateSet      operationalRateSet;
    tSirMacRateSet      extendedRateSet;
    tANI_U8             operationChn;
    eCsrCfgDot11Mode    uCfgDot11Mode;
<<<<<<< HEAD
#ifdef WLAN_SOFTAP_FEATURE
=======
>>>>>>> d97af3b... add prima wlan driver
    tANI_U8             privacy;
    tANI_BOOLEAN        fwdWPSPBCProbeReq;
    tANI_BOOLEAN        protEnabled;
    tANI_BOOLEAN        obssProtEnabled;
    tAniAuthType        authType;
    tANI_U16            beaconInterval;    //If this is 0, SME will fill in for caller.
    tANI_U16            ht_protection;
    tANI_U32            dtimPeriod;
    tANI_U8             ApUapsdEnable;
    tANI_U8             ssidHidden;
    tANI_U8             wps_state;
<<<<<<< HEAD
#endif
    tVOS_CON_MODE       bssPersona;
    tANI_U16            nRSNIELength;  //The byte count in the pRSNIE, if 0, pRSNIE is ignored.
    tANI_U8             *pRSNIE;     //If not null, it has the IE byte stream for RSN
=======
    tVOS_CON_MODE       bssPersona;
    tANI_U16            nRSNIELength;  //The byte count in the pRSNIE, if 0, pRSNIE is ignored.
    tANI_U8             *pRSNIE;     //If not null, it has the IE byte stream for RSN
    tANI_BOOLEAN        updatebeaconInterval; //Flag used to indicate update
                                             // beaconInterval
>>>>>>> d97af3b... add prima wlan driver
}tCsrRoamStartBssParams;


typedef struct tagScanCmd
{
    tANI_U32                scanID;
    csrScanCompleteCallback callback;
    void                    *pContext;
    eCsrScanReason          reason;
    eCsrRoamState           lastRoamState[CSR_ROAM_SESSION_MAX];
    tCsrRoamProfile         *pToRoamProfile;
    tANI_U32                roamId;    //this is the ID related to the pToRoamProfile
    union
    {
        tCsrScanRequest   scanRequest;
        tCsrBGScanRequest bgScanRequest;
    }u;
}tScanCmd;

<<<<<<< HEAD
typedef struct tagRoamCmd 
=======
typedef struct tagRoamCmd
>>>>>>> d97af3b... add prima wlan driver
{
    tANI_U32 roamId;
    eCsrRoamReason roamReason;
    tCsrRoamProfile roamProfile;
    tScanResultHandle hBSSList;     //BSS list fits the profile
<<<<<<< HEAD
    tListElem *pRoamBssEntry;  //point to the current BSS in the list that is roaming. It starts from head to tail        
    tSirBssDescription *pLastRoamBss;   //the last BSS we try and failed
    tANI_BOOLEAN fReleaseBssList;  //whether to free hBSSList 
=======
    tListElem *pRoamBssEntry;  //point to the current BSS in the list that is roaming. It starts from head to tail
    tSirBssDescription *pLastRoamBss;   //the last BSS we try and failed
    tANI_BOOLEAN fReleaseBssList;  //whether to free hBSSList
>>>>>>> d97af3b... add prima wlan driver
    tANI_BOOLEAN fReleaseProfile;  //whether to free roamProfile
    tANI_BOOLEAN fReassoc;  //whether this command is for reassociation
    tANI_BOOLEAN fUpdateCurRoamProfile;     //whether pMac->roam.pCurRoamProfile needs to be updated
    //this is for CSR internal used only. And it should not be assigned when creating the command
    //This causes the roam command not to do anything.
<<<<<<< HEAD
    tANI_BOOLEAN fReassocToSelfNoCapChange;    
=======
    tANI_BOOLEAN fReassocToSelfNoCapChange;
>>>>>>> d97af3b... add prima wlan driver

    tANI_BOOLEAN fStopWds;
    tSirMacAddr peerMac;
    tSirMacReasonCodes reason;
}tRoamCmd;

typedef struct tagSetKeyCmd
{
    tANI_U32 roamId;
    eCsrEncryptionType encType;
    eCsrAuthType authType;
    tAniKeyDirection keyDirection;    //Tx, Rx or Tx-and-Rx
    tSirMacAddr peerMac;   //Peer's MAC address. ALL 1's for group key
    tANI_U8 paeRole;      //0 for supplicant
    tANI_U8 keyId;  // Kye index
    tANI_U8 keyLength;  //Number of bytes containing the key in pKey
    tANI_U8 Key[CSR_MAX_KEY_LEN];
    tANI_U8 keyRsc[CSR_MAX_RSC_LEN];
} tSetKeyCmd;

typedef struct tahRemoveKeyCmd
{
    tANI_U32 roamId;
    eCsrEncryptionType encType;
    eCsrAuthType authType;
    tSirMacAddr peerMac;   //Peer's MAC address. ALL 1's for group key
    tANI_U8 keyId;  //key index
} tRemoveKeyCmd;

<<<<<<< HEAD
typedef struct tagWmStatusChangeCmd 
{
    eCsrRoamWmStatusChangeTypes Type;
    union 
    {    
        tSirSmeDeauthInd   DeauthIndMsg;
        tSirSmeDisassocInd DisassocIndMsg;
    }u;    

}tWmStatusChangeCmd;

=======
typedef struct tagWmStatusChangeCmd
{
    eCsrRoamWmStatusChangeTypes Type;
    union
    {
        tSirSmeDeauthInd   DeauthIndMsg;
        tSirSmeDisassocInd DisassocIndMsg;
    }u;

}tWmStatusChangeCmd;


>>>>>>> d97af3b... add prima wlan driver
typedef struct tagAddStaForSessionCmd
{
   //Session self mac addr
   tSirMacAddr selfMacAddr;
<<<<<<< HEAD
=======
   tVOS_CON_MODE currDeviceMode;
>>>>>>> d97af3b... add prima wlan driver
}tAddStaForSessionCmd;

typedef struct tagDelStaForSessionCmd
{
   //Session self mac addr
   tSirMacAddr selfMacAddr;
   csrRoamSessionCloseCallback callback;
   void *pContext;
}tDelStaForSessionCmd;

//This structure represents one scan request
typedef struct tagCsrCmd
{
    tListElem Link;
    eCsrRoamCommands command;
    tANI_U8 sessionId;              // Session ID for this command
    union
    {
        tScanCmd scanCmd;
        tRoamCmd roamCmd;
        tWmStatusChangeCmd wmStatusChangeCmd;
        tSetKeyCmd setKeyCmd;
        tRemoveKeyCmd removeKeyCmd;
        tAddStaForSessionCmd addStaSessionCmd;
        tDelStaForSessionCmd delStaSessionCmd;
    }u;
}tCsrCmd;

#ifdef WLAN_FEATURE_VOWIFI_11R
typedef struct tagCsr11rConfig
{
    tANI_BOOLEAN   IsFTResourceReqSupported;
} tCsr11rConfig;
#endif

#ifdef WLAN_FEATURE_NEIGHBOR_ROAMING
typedef struct tagCsrNeighborRoamConfig
{
    tANI_U32       nNeighborScanTimerPeriod;
    tANI_U8        nNeighborLookupRssiThreshold;
    tANI_U8        nNeighborReassocRssiThreshold;
    tANI_U16       nNeighborScanMinChanTime;
    tANI_U16       nNeighborScanMaxChanTime;
    sCsrChannel    neighborScanChanList;
    tANI_U8        nMaxNeighborRetries;
    tANI_U16       nNeighborResultsRefreshPeriod;
<<<<<<< HEAD
=======
    tANI_U16       nEmptyScanRefreshPeriod;
>>>>>>> d97af3b... add prima wlan driver
}tCsrNeighborRoamConfig;
#endif

typedef struct tagCsrConfig
{
    tANI_U32 agingCount;
    tANI_U32 FragmentationThreshold;
    tANI_U32 channelBondingMode24GHz;
    tANI_U32 channelBondingMode5GHz;
    tANI_U32 RTSThreshold;
    eCsrPhyMode phyMode;
    eCsrCfgDot11Mode uCfgDot11Mode;
    eCsrBand eBand;
    tANI_U32 HeartbeatThresh50;
    tANI_U32 HeartbeatThresh24;
    tANI_U32 bgScanInterval;
    eCsrCBChoice cbChoice;
    eCsrBand bandCapability;     //indicate hw capability
    eCsrRoamWmmUserModeType WMMSupportMode;
    tANI_BOOLEAN Is11eSupportEnabled;
    tANI_BOOLEAN Is11dSupportEnabled;
    tANI_BOOLEAN Is11dSupportEnabledOriginal;
    tANI_BOOLEAN Is11hSupportEnabled;
    tANI_BOOLEAN shortSlotTime;
    tANI_BOOLEAN ProprietaryRatesEnabled;
    tANI_BOOLEAN  fenableMCCMode;
<<<<<<< HEAD
    tANI_BOOLEAN  fAllowMCCGODiffBI;
    tANI_U16 TxRate;
=======
    tANI_U16 TxRate;
    tANI_U8  fAllowMCCGODiffBI;
>>>>>>> d97af3b... add prima wlan driver
    tANI_U8 AdHocChannel24;
    tANI_U8 AdHocChannel5G;
    tANI_U32 impsSleepTime;     //in units of microseconds
    tANI_U32 scanAgeTimeNCNPS;  //scan result aging time threshold when Not-Connect-No-Power-Save, in seconds
    tANI_U32 scanAgeTimeNCPS;   //scan result aging time threshold when Not-Connect-Power-Save, in seconds
    tANI_U32 scanAgeTimeCNPS;   //scan result aging time threshold when Connect-No-Power-Save, in seconds,
    tANI_U32 scanAgeTimeCPS;   //scan result aging time threshold when Connect-Power-Savein seconds
    tANI_U32 BssPreferValue[CSR_NUM_RSSI_CAT];  //each RSSI category has one value
    int RSSICat[CSR_NUM_RSSI_CAT];
    tANI_U8 bCatRssiOffset;     //to set the RSSI difference for each category
    tANI_U32 nRoamingTime;  //In seconds, CSR will try this long before gives up, 0 means no roaming
    //Whether to limit the channels to the ones set in Csr11dInfo. If true, the opertaional
<<<<<<< HEAD
    //channels are limited to the default channel list. It is an "AND" operation between the 
    //default channels and the channels in the 802.11d IE.
    tANI_BOOLEAN fEnforce11dChannels;   
    //Country Code Priority
    //0 = 802.11D > Configured Country > NV 
    //1 = Configured Country > 802.11D > NV
    tANI_BOOLEAN fSupplicantCountryCodeHasPriority;
    //When true, AP with unknown country code won't be see. 
    //"Unknown country code" means either Ap doesn't have 11d IE or we cannot 
    //find a domain for the country code in its 11d IE.
    tANI_BOOLEAN fEnforceCountryCodeMatch;  
    //When true, only APs in the default domain can be seen. If the Ap has "unknown country
    //code", or the doamin of the country code doesn't match the default domain, the Ap is
    //not acceptable.
    tANI_BOOLEAN fEnforceDefaultDomain;     
=======
    //channels are limited to the default channel list. It is an "AND" operation between the
    //default channels and the channels in the 802.11d IE.
    tANI_BOOLEAN fEnforce11dChannels;
    //Country Code Priority
    //0 = 802.11D > Configured Country > NV
    //1 = Configured Country > 802.11D > NV
    tANI_BOOLEAN fSupplicantCountryCodeHasPriority;
    //When true, AP with unknown country code won't be see.
    //"Unknown country code" means either Ap doesn't have 11d IE or we cannot
    //find a domain for the country code in its 11d IE.
    tANI_BOOLEAN fEnforceCountryCodeMatch;
    //When true, only APs in the default domain can be seen. If the Ap has "unknown country
    //code", or the doamin of the country code doesn't match the default domain, the Ap is
    //not acceptable.
    tANI_BOOLEAN fEnforceDefaultDomain;
>>>>>>> d97af3b... add prima wlan driver

    tANI_U16 vccRssiThreshold;
    tANI_U32 vccUlMacLossThreshold;

    tANI_U32  nPassiveMinChnTime;    //in units of milliseconds
    tANI_U32  nPassiveMaxChnTime;    //in units of milliseconds
    tANI_U32  nActiveMinChnTime;     //in units of milliseconds
    tANI_U32  nActiveMaxChnTime;     //in units of milliseconds

<<<<<<< HEAD
    tANI_BOOLEAN IsIdleScanEnabled;
    //in dBm, the maximum TX power
    //The actual TX power is the lesser of this value and 11d. 
=======
    tANI_U32  nActiveMinChnTimeBtc;     //in units of milliseconds
    tANI_U32  nActiveMaxChnTimeBtc;     //in units of milliseconds
    tANI_U8   disableAggWithBtc;
#ifdef WLAN_AP_STA_CONCURRENCY
    tANI_U32  nPassiveMinChnTimeConc;    //in units of milliseconds
    tANI_U32  nPassiveMaxChnTimeConc;    //in units of milliseconds
    tANI_U32  nActiveMinChnTimeConc;     //in units of milliseconds
    tANI_U32  nActiveMaxChnTimeConc;     //in units of milliseconds
    tANI_U32  nRestTimeConc;             //in units of milliseconds
    tANI_U8   nNumStaChanCombinedConc;   //number of channels combined for
                                         //Sta in each split scan operation
    tANI_U8   nNumP2PChanCombinedConc;   //number of channels combined for
                                         //P2P in each split scan operation
#endif

    tANI_BOOLEAN IsIdleScanEnabled;
    //in dBm, the maximum TX power
    //The actual TX power is the lesser of this value and 11d.
>>>>>>> d97af3b... add prima wlan driver
    //If 11d is disable, the lesser of this and default setting.
    tANI_U8 nTxPowerCap;
    tANI_U32  statsReqPeriodicity;  //stats request frequency from PE while in full power
    tANI_U32  statsReqPeriodicityInPS;//stats request frequency from PE while in power save
<<<<<<< HEAD
#ifdef WLAN_SOFTAP_FEATURE
    tANI_U32 dtimPeriod;
    tANI_BOOLEAN    ssidHidden;
#endif
=======
    tANI_U32 dtimPeriod;
    tANI_BOOLEAN    ssidHidden;
>>>>>>> d97af3b... add prima wlan driver

#ifdef WLAN_FEATURE_VOWIFI_11R
    tCsr11rConfig csr11rConfig;
#endif

#ifdef FEATURE_WLAN_LFR
<<<<<<< HEAD
    tANI_U8   isFastRoamIniFeatureEnabled;
=======
    tANI_U8      isFastRoamIniFeatureEnabled;
#ifdef WLAN_FEATURE_ROAM_SCAN_OFFLOAD
    tANI_U8      isRoamOffloadScanEnabled;
    tANI_BOOLEAN bFastRoamInConIniFeatureEnabled;
#endif
>>>>>>> d97af3b... add prima wlan driver
#endif

#ifdef FEATURE_WLAN_CCX
    tANI_U8   isCcxIniFeatureEnabled;
#endif

#if  defined (WLAN_FEATURE_VOWIFI_11R) || defined (FEATURE_WLAN_CCX) || defined(FEATURE_WLAN_LFR)
<<<<<<< HEAD
    tANI_U8   isFastTransitionEnabled;
    tANI_U8   RoamRssiDiff;
=======
    tANI_U8       isFastTransitionEnabled;
    tANI_U8       RoamRssiDiff;
    tANI_U8       nImmediateRoamRssiDiff;
    tANI_BOOLEAN  nRoamPrefer5GHz;
    tANI_BOOLEAN  nRoamIntraBand;
    tANI_BOOLEAN  nRoamScanControl;
    tANI_U8       nProbes;
    tANI_U16      nRoamScanHomeAwayTime;
>>>>>>> d97af3b... add prima wlan driver
#endif

#ifdef WLAN_FEATURE_NEIGHBOR_ROAMING
    tCsrNeighborRoamConfig neighborRoamConfig;
#endif

<<<<<<< HEAD
    /* Instead of Reassoc, send ADDTS/DELTS even when ACM is off for that AC 
=======
    /* Instead of Reassoc, send ADDTS/DELTS even when ACM is off for that AC
>>>>>>> d97af3b... add prima wlan driver
     * This is mandated by WMM-AC certification */
    tANI_BOOLEAN addTSWhenACMIsOff;

    tANI_BOOLEAN fValidateList;
<<<<<<< HEAD
=======
    //Remove this code once SLM_Sessionization is supported
    //BMPS_WORKAROUND_NOT_NEEDED
>>>>>>> d97af3b... add prima wlan driver
    tANI_BOOLEAN doBMPSWorkaround;

    //To enable/disable scanning 2.4Ghz channels twice on a single scan request from HDD
    tANI_BOOLEAN fScanTwice;
#ifdef WLAN_FEATURE_11AC
    tANI_U32  nVhtChannelWidth;
<<<<<<< HEAD
#endif

}tCsrConfig;

typedef struct tagCsrChannelPowerInfo 
=======
    tANI_U8   txBFEnable;
    tANI_U8   txBFCsnValue;
    tANI_BOOLEAN enableVhtFor24GHz;
#endif
    tANI_U8   txLdpcEnable;

    /*
     * Enable/Disable heartbeat offload
     */
    tANI_BOOLEAN enableHeartBeatOffload;
    tANI_U8 isAmsduSupportInAMPDU;
}tCsrConfig;

typedef struct tagCsrChannelPowerInfo
>>>>>>> d97af3b... add prima wlan driver
{
    tListElem link;
    tANI_U8 firstChannel;
    tANI_U8 numChannels;
    tANI_U8 txPower;
    tANI_U8 interChannelOffset;
}tCsrChannelPowerInfo;

typedef struct tagRoamJoinStatus
{
    tSirResultCodes statusCode;
    //this is set to unspecified if statusCode indicates timeout. Or it is the failed reason from the other BSS(per 802.11 spec)
<<<<<<< HEAD
    tANI_U32 reasonCode;    
=======
    tANI_U32 reasonCode;
    tSirMacAddr bssId;
>>>>>>> d97af3b... add prima wlan driver
}tCsrRoamJoinStatus;

typedef struct tagCsrOsChannelMask
{
    tANI_U8 numChannels;
    tANI_BOOLEAN scanEnabled[WNI_CFG_VALID_CHANNEL_LIST_LEN];
    tANI_U8 channelList[WNI_CFG_VALID_CHANNEL_LIST_LEN];
}tCsrOsChannelMask;


typedef struct tagCsrScanStruct
{
    tScanProfile scanProfile;
    tANI_U32 nextScanID;
    tDblLinkList scanResultList;
    tDblLinkList tempScanResults;
    tANI_BOOLEAN fScanEnable;
    tANI_BOOLEAN fFullScanIssued;
<<<<<<< HEAD
    tPalTimerHandle hTimerGetResult;
#ifdef WLAN_AP_STA_CONCURRENCY
    tPalTimerHandle hTimerStaApConcTimer;
#endif
    tPalTimerHandle hTimerIdleScan;
    tPalTimerHandle hTimerResultAging;
    tPalTimerHandle hTimerBgScan;
    //changes on every scan, it is used as a flag for whether 11d info is found on every scan
    tANI_U8 channelOf11dInfo;   
    //changes on every scan, a flag to tell whether conflict 11d info found on each BSS
    tANI_BOOLEAN fAmbiguous11dInfoFound;    
    //Tush: changes on every scan, a flag to tell whether the applied 11d info present in one of the scan results
    tANI_BOOLEAN fCurrent11dInfoMatch;    
=======
    vos_timer_t hTimerGetResult;
#ifdef WLAN_AP_STA_CONCURRENCY
    vos_timer_t hTimerStaApConcTimer;
#endif
    vos_timer_t hTimerIdleScan;
    vos_timer_t hTimerResultAging;
    vos_timer_t hTimerResultCfgAging;
    tPalTimerHandle hTimerBgScan;
    //changes on every scan, it is used as a flag for whether 11d info is found on every scan
    tANI_U8 channelOf11dInfo;
    tANI_U8 scanResultCfgAgingTime;
    //changes on every scan, a flag to tell whether conflict 11d info found on each BSS
    tANI_BOOLEAN fAmbiguous11dInfoFound;
    //Tush: changes on every scan, a flag to tell whether the applied 11d info present in one of the scan results
    tANI_BOOLEAN fCurrent11dInfoMatch;
>>>>>>> d97af3b... add prima wlan driver
    tANI_BOOLEAN f11dInfoReset;     //to indicate whether the 11d info in CFG is reset to default
    tSirScanType curScanType;
    tCsrChannel baseChannels;   //This are all the supported channels AND(&) to the current eBand
    tCsrChannel channels11d;
    tChannelListWithPower defaultPowerTable[WNI_CFG_VALID_CHANNEL_LIST_LEN]; //From NV
    tChannelListWithPower defaultPowerTable40MHz[WNI_CFG_VALID_CHANNEL_LIST_LEN]; //From NV
    tANI_U32 numChannelsDefault; //total channels of NV
    tCsrChannel base20MHzChannels;   //The channel base to work on
    tCsrChannel base40MHzChannels;   //center channels for 40MHz channels
    tDblLinkList channelPowerInfoList24;
    tDblLinkList channelPowerInfoList5G;
    tANI_U32 nLastAgeTimeOut;
    tANI_U32 nAgingCountDown;
<<<<<<< HEAD
    tANI_U8 countryCodeDefault[WNI_CFG_COUNTRY_CODE_LEN+1];     //The country code from NV
    tANI_U8 countryCodeCurrent[WNI_CFG_COUNTRY_CODE_LEN+1];
    tANI_U8 countryCode11d[WNI_CFG_COUNTRY_CODE_LEN+1];
    v_REGDOMAIN_t domainIdDefault;  //default regulatory domain
    v_REGDOMAIN_t domainIdCurrent;  //current regulatory domain
=======
    tANI_U8 countryCodeDefault[WNI_CFG_COUNTRY_CODE_LEN];     //The country code from NV
    tANI_U8 countryCodeCurrent[WNI_CFG_COUNTRY_CODE_LEN];
    tANI_U8 countryCode11d[WNI_CFG_COUNTRY_CODE_LEN];
    v_REGDOMAIN_t domainIdDefault;  //default regulatory domain
    v_REGDOMAIN_t domainIdCurrent;  //current regulatory domain
    tCsrBssid currentCountryBssid;  // Bssid for current country code
>>>>>>> d97af3b... add prima wlan driver
    tANI_BOOLEAN f11dInfoApplied;
    tANI_BOOLEAN fCancelIdleScan;
#ifdef FEATURE_WLAN_WAPI
//    tANI_U16 NumBkidCandidate;
//    tBkidCandidateInfo BkidCandidateInfo[CSR_MAX_BKID_ALLOWED]; /* Move this as part of SessionEntry */
#endif /* FEATURE_WLAN_WAPI */
    tANI_U8 numBGScanChannel;   //number of valid channels in the bgScanChannelList
    tANI_U8 bgScanChannelList[WNI_CFG_BG_SCAN_CHANNEL_LIST_LEN];
    //the ChannelInfo member is not used in this structure.
    //numBGScanChannel and bgScanChannelList are used for the BG scan channel info
<<<<<<< HEAD
    tCsrBGScanRequest bgScanParams;  
=======
    tCsrBGScanRequest bgScanParams;
>>>>>>> d97af3b... add prima wlan driver
    tANI_BOOLEAN fRestartIdleScan;
    tANI_U32 nIdleScanTimeGap;  //the time since last trying to trigger idle scan
    tCsrOsChannelMask osScanChannelMask;//keep a track of channels to be scnned while in traffic condition
    tANI_U16 nBssLimit; //the maximum number of BSS in scan cache
<<<<<<< HEAD
    /*channelPowerInfoList24 has been seen corrupted. Set this flag to true trying to 
=======
    /*channelPowerInfoList24 has been seen corrupted. Set this flag to true trying to
>>>>>>> d97af3b... add prima wlan driver
    * detect when it happens. Adding this into code because we can't reproduce it easily.
    * We don't know when it happens. */
    tANI_BOOLEAN fValidateList;
    /*Customer wants to start with an active scan based on the default country code.
    * This optimization will minimize the driver load to association time.
    * Based on this flag we will bypass the initial passive scan needed for 11d
    * to determine the country code & domain */
    tANI_BOOLEAN fEnableBypass11d;

<<<<<<< HEAD
    /*Customer wants to optimize the scan time. Avoiding scans(passive) on DFS 
    * channels while swipping through both bands can save some time 
=======
    /*Customer wants to optimize the scan time. Avoiding scans(passive) on DFS
    * channels while swipping through both bands can save some time
>>>>>>> d97af3b... add prima wlan driver
    * (apprx 1.3 sec) */
    tANI_BOOLEAN fEnableDFSChnlScan;

    /*
    * To enable/disable scanning only 2.4Ghz channels on first scan
    */
    tANI_BOOLEAN fFirstScanOnly2GChnl;

    tANI_BOOLEAN fDropScanCmd; //true means we don't accept scan commands

#ifdef WLAN_AP_STA_CONCURRENCY
    tDblLinkList scanCmdPendingList;
<<<<<<< HEAD
#endif    
    tCsrChannel occupiedChannels;   //This includes all channels on which candidate APs are found
    
    tANI_BOOLEAN fIgnore_chan165;
}tCsrScanStruct;

=======
#endif
    tCsrChannel occupiedChannels;   //This includes all channels on which candidate APs are found
}tCsrScanStruct;

#ifdef FEATURE_WLAN_TDLS_INTERNAL
/*
 * struct to carry TDLS discovery info..
 */
typedef struct sCsrTdlsContext
{
    tDblLinkList tdlsPotentialPeerList ;
    tANI_U16 tdlsCommonFlag ;
    tANI_U16 tdlsCommonState ;
    tANI_U16 tdlsPeerCount ;
}tCsrTdlsCtxStruct;

typedef struct sCsrTdlsPeerLinkInfo
{
    tListElem tdlsPeerStaLink ;
    tSirTdlsPeerInfo tdlsDisPeerInfo ;
}tCsrTdlsPeerLinkinfo ;
#endif



>>>>>>> d97af3b... add prima wlan driver

//Save the connected information. This structure + connectedProfile
//should contain all information about the connection
typedef struct tagRoamCsrConnectedInfo
{
    tANI_U32 nBeaconLength; //the length, in bytes, of the beacon frame, can be 0
    tANI_U32 nAssocReqLength;   //the length, in bytes, of the assoc req frame, can be 0
    tANI_U32 nAssocRspLength;   //The length, in bytes, of the assoc rsp frame, can be 0
#ifdef WLAN_FEATURE_VOWIFI_11R
    tANI_U32 nRICRspLength; //Length of the parsed RIC response IEs received in reassoc response
<<<<<<< HEAD
#endif    
#ifdef FEATURE_WLAN_CCX
    tANI_U32 nTspecIeLength;
#endif    
=======
#endif
#ifdef FEATURE_WLAN_CCX
    tANI_U32 nTspecIeLength;
#endif
>>>>>>> d97af3b... add prima wlan driver
    tANI_U8 *pbFrames;  //Point to a buffer contain the beacon, assoc req, assoc rsp frame, in that order
                        //user needs to use nBeaconLength, nAssocReqLength, nAssocRspLength to desice where
                        //each frame starts and ends.
    tANI_U8 staId;
}tCsrRoamConnectedInfo;


typedef struct tagCsrLinkQualityIndInfo
<<<<<<< HEAD
{   
=======
{
>>>>>>> d97af3b... add prima wlan driver
   csrRoamLinkQualityIndCallback  callback;
   void                          *context;
}tCsrLinkQualityIndInfo;

typedef struct tagCsrPeStatsReqInfo
{
   tListElem              link;  /* list links */
   tANI_U32               statsMask;
   tANI_U32               periodicity;
   tANI_BOOLEAN           rspPending;
   vos_timer_t            hPeStatsTimer;
   tANI_BOOLEAN           timerRunning;
   tANI_U8                staId;
   tANI_U8                numClient;
   tpAniSirGlobal         pMac;
<<<<<<< HEAD
   /* To remember if the peStats timer is stopped successfully or not */   
=======
   /* To remember if the peStats timer is stopped successfully or not */
>>>>>>> d97af3b... add prima wlan driver
   tANI_BOOLEAN           timerStopFailed;

}tCsrPeStatsReqInfo;

typedef struct tagCsrStatsClientReqInfo
{
   tListElem              link;  /* list links */
   eCsrStatsRequesterType requesterId;
   tCsrStatsCallback      callback;
   tANI_U32               periodicity;
   void                  *pContext;
   tANI_U32               statsMask;
   tCsrPeStatsReqInfo    *pPeStaEntry;
   tANI_U8                staId;
   vos_timer_t            timer;
   tANI_BOOLEAN           timerExpired;
   tpAniSirGlobal         pMac; // TODO: Confirm this change BTAMP
}tCsrStatsClientReqInfo;

typedef struct tagCsrTlStatsReqInfo
{
   tANI_U32               periodicity;
   tANI_BOOLEAN           timerRunning;
<<<<<<< HEAD
   tPalTimerHandle        hTlStatsTimer;
=======
   vos_timer_t            hTlStatsTimer;
>>>>>>> d97af3b... add prima wlan driver
   tANI_U8                numClient;
}tCsrTlStatsReqInfo;

typedef struct tagCsrRoamSession
{
    tANI_U8 sessionId;             // Session ID
    tANI_BOOLEAN sessionActive;      // TRUE if it is used
    tCsrBssid selfMacAddr;           // For BT-AMP station, this serve as BSSID for self-BSS.
    csrRoamCompleteCallback callback;
    void *pContext;
    eCsrConnectState connectState;
    tCsrRoamConnectedProfile connectedProfile;
    tCsrRoamConnectedInfo connectedInfo;
<<<<<<< HEAD
    tCsrRoamProfile *pCurRoamProfile;   
=======
    tCsrRoamProfile *pCurRoamProfile;
>>>>>>> d97af3b... add prima wlan driver
    tSirBssDescription *pConnectBssDesc;
    tANI_U16 NumPmkidCache;
    tPmkidCacheInfo PmkidCacheInfo[CSR_MAX_PMKID_ALLOWED];
    tANI_U8 cJoinAttemps;
    //This may or may not have the up-to-date valid channel list
    //It is used to get WNI_CFG_VALID_CHANNEL_LIST and not allocate memory all the time
    tSirMacChanNum validChannelList[WNI_CFG_VALID_CHANNEL_LIST_LEN];
    tANI_S32 sPendingCommands;    //0 means CSR is ok to low power
#ifdef FEATURE_WLAN_WAPI
    tANI_U16 NumBkidCache;
    tBkidCacheInfo BkidCacheInfo[CSR_MAX_BKID_ALLOWED];
#endif /* FEATURE_WLAN_WAPI */
    tANI_BOOLEAN fRoaming;  //indicate whether CSR is roaming (either via lostlink or dynamic roaming)
    //to remember some parameters needed for START_BSS.
    //All member must be set every time we try to join or start an IBSS or BT-AMP
<<<<<<< HEAD
    tCsrRoamStartBssParams bssParams;   
=======
    tCsrRoamStartBssParams bssParams;
>>>>>>> d97af3b... add prima wlan driver
    tANI_U32 nWpaRsnReqIeLength;   //the byte count of pWpaRsnIE;
    tANI_U8 *pWpaRsnReqIE; //this contain the WPA/RSN IE in assoc request or the one sent in beacon (IBSS)
    tANI_U32 nWpaRsnRspIeLength;    //the byte count for pWpaRsnRspIE
    tANI_U8 *pWpaRsnRspIE;  //this contain the WPA/RSN IE in beacon/probe rsp
#ifdef FEATURE_WLAN_WAPI
    tANI_U32 nWapiReqIeLength;   //the byte count of pWapiReqIE;
    tANI_U8 *pWapiReqIE; //this contain the WAPI IE in assoc request or the one sent in beacon (IBSS)
    tANI_U32 nWapiRspIeLength;    //the byte count for pWapiRspIE
    tANI_U8 *pWapiRspIE;  //this contain the WAPI IE in beacon/probe rsp
#endif /* FEATURE_WLAN_WAPI */
    tANI_U32 nAddIEScanLength;  //the byte count of pAddIeScanIE;
    tANI_U8 *pAddIEScan; //this contains the additional IE in (unicast) probe request at the time of join
    tANI_U32 nAddIEAssocLength;      //the byte count for pAddIeAssocIE
    tANI_U8 *pAddIEAssoc; //this contains the additional IE in (re) assoc request

    tANI_TIMESTAMP roamingStartTime;    //in units of 10ms
    tCsrTimerInfo roamingTimerInfo;
    eCsrRoamingReason roamingReason;
    tANI_BOOLEAN fCancelRoaming;
<<<<<<< HEAD
    tPalTimerHandle hTimerRoaming;
    tPalTimerHandle hTimerIbssJoining;
=======
    vos_timer_t hTimerRoaming;
    vos_timer_t hTimerIbssJoining;
>>>>>>> d97af3b... add prima wlan driver
    tCsrTimerInfo ibssJoinTimerInfo;
    tANI_BOOLEAN ibss_join_pending;
    eCsrRoamResult roamResult;  //the roamResult that is used when the roaming timer fires
    tCsrRoamJoinStatus joinFailStatusCode;    //This is the reason code for join(assoc) failure
    //The status code returned from PE for deauth or disassoc (in case of lostlink), or our own dynamic roaming
<<<<<<< HEAD
    tANI_U32 roamingStatusCode;     
=======
    tANI_U32 roamingStatusCode;
>>>>>>> d97af3b... add prima wlan driver
    tANI_U16 NumPmkidCandidate;
    tPmkidCandidateInfo PmkidCandidateInfo[CSR_MAX_PMKID_ALLOWED];
 #ifdef FEATURE_WLAN_WAPI
    tANI_U16 NumBkidCandidate;
<<<<<<< HEAD
    tBkidCandidateInfo BkidCandidateInfo[CSR_MAX_BKID_ALLOWED]; 
=======
    tBkidCandidateInfo BkidCandidateInfo[CSR_MAX_BKID_ALLOWED];
>>>>>>> d97af3b... add prima wlan driver
#endif
    tANI_BOOLEAN fWMMConnection;
#ifdef FEATURE_WLAN_BTAMP_UT_RF
    //To retry a join later when it fails if so desired
<<<<<<< HEAD
    tPalTimerHandle hTimerJoinRetry;
=======
    vos_timer_t hTimerJoinRetry;
>>>>>>> d97af3b... add prima wlan driver
    tCsrTimerInfo joinRetryTimerInfo;
    tANI_U32 maxRetryCount;
#endif
#ifdef FEATURE_WLAN_CCX
    tCsrCcxCckmInfo ccxCckmInfo;
    tANI_BOOLEAN isPrevApInfoValid;
    tSirMacSSid prevApSSID;
    tCsrBssid prevApBssid;
    tANI_U8 prevOpChannel;
    tANI_U16 clientDissSecs;
    tANI_U32 roamTS1;
#endif
    tANI_U8 bRefAssocStartCnt;   //Tracking assoc start indication
<<<<<<< HEAD
=======
   /* to force the AP initiate fresh 802.1x authentication after re-association need to clear
    * the PMKID cache. To clear the cache in this particular case this is added
    * it is needed by the HS 2.0 passpoint certification 5.2.a and b testcases */
    tANI_BOOLEAN fIgnorePMKIDCache;
>>>>>>> d97af3b... add prima wlan driver
} tCsrRoamSession;

typedef struct tagCsrRoamStruct
{
    tANI_U32 nextRoamId;
    tDblLinkList roamCmdPendingList;
    tDblLinkList channelList5G;
    tDblLinkList channelList24;
    tCsrConfig configParam;
    tANI_U32 numChannelsEeprom; //total channels of eeprom
<<<<<<< HEAD
    tCsrChannel base20MHzChannels;   //The channel base to work on              
    tCsrChannel base40MHzChannels;   //center channels for 40MHz channels      
    eCsrRoamState curState[CSR_ROAM_SESSION_MAX];  
=======
    tCsrChannel base20MHzChannels;   //The channel base to work on
    tCsrChannel base40MHzChannels;   //center channels for 40MHz channels
    eCsrRoamState curState[CSR_ROAM_SESSION_MAX];
>>>>>>> d97af3b... add prima wlan driver
    eCsrRoamSubState curSubState[CSR_ROAM_SESSION_MAX];
    //This may or may not have the up-to-date valid channel list
    //It is used to get WNI_CFG_VALID_CHANNEL_LIST and not allocate memory all the time
    tSirMacChanNum validChannelList[WNI_CFG_VALID_CHANNEL_LIST_LEN];
    tANI_U32 numValidChannels; //total number of channels in CFG
<<<<<<< HEAD
    
    tANI_S32 sPendingCommands;
    tChannelListWithPower   *powerTableFromEeprom;
    tChannelListWithPower   *powerTableFromEeprom40MHz;
    tPalTimerHandle hTimerWaitForKey;  //To support timeout for WaitForKey state
=======

    tANI_S32 sPendingCommands;
    vos_timer_t hTimerWaitForKey;  //To support timeout for WaitForKey state
>>>>>>> d97af3b... add prima wlan driver
    tCsrSummaryStatsInfo       summaryStatsInfo;
    tCsrGlobalClassAStatsInfo  classAStatsInfo;
    tCsrGlobalClassBStatsInfo  classBStatsInfo;
    tCsrGlobalClassCStatsInfo  classCStatsInfo;
    tCsrGlobalClassDStatsInfo  classDStatsInfo;
    tCsrPerStaStatsInfo        perStaStatsInfo[CSR_MAX_STA];
    tDblLinkList  statsClientReqList;
    tDblLinkList  peStatsReqList;
    tCsrTlStatsReqInfo  tlStatsReqInfo;
    eCsrRoamLinkQualityInd vccLinkQuality;
    tCsrLinkQualityIndInfo linkQualityIndInfo;
    v_CONTEXT_t gVosContext; //used for interaction with TL
    //To specify whether an association or a IBSS is WMM enabled
    //This parameter is only valid during a join or start BSS command is being executed
    //tANI_BOOLEAN fWMMConnection;      /* Moving it to be part of roamsession */
    v_U8_t ucACWeights[WLANTL_MAX_AC];
    /* TODO : Upto here */
    tCsrTimerInfo WaitForKeyTimerInfo;
    tCsrRoamSession   *roamSession;
<<<<<<< HEAD
    tANI_U32 transactionId;        // Current transaction ID for internal use. 
#ifdef WLAN_FEATURE_NEIGHBOR_ROAMING    
=======
    tANI_U32 transactionId;        // Current transaction ID for internal use.
#ifdef WLAN_FEATURE_NEIGHBOR_ROAMING
>>>>>>> d97af3b... add prima wlan driver
    tCsrNeighborRoamControlInfo neighborRoamInfo;
#endif
#ifdef FEATURE_WLAN_LFR
    tANI_U8   isFastRoamIniFeatureEnabled;
#endif
#ifdef FEATURE_WLAN_CCX
    tANI_U8   isCcxIniFeatureEnabled;
#endif
#if  defined (WLAN_FEATURE_VOWIFI_11R) || defined (FEATURE_WLAN_CCX) || defined(FEATURE_WLAN_LFR)
<<<<<<< HEAD
    tANI_U8   RoamRssiDiff;
=======
    tANI_U8        RoamRssiDiff;
>>>>>>> d97af3b... add prima wlan driver
#endif
}tCsrRoamStruct;


#define GET_NEXT_ROAM_ID(pRoamStruct)  (((pRoamStruct)->nextRoamId + 1 == 0) ? 1 : (pRoamStruct)->nextRoamId)
#define CSR_IS_ROAM_STATE(pMac, state, sessionId)  ( (state) == (pMac)->roam.curState[sessionId] )

<<<<<<< HEAD
#define CSR_IS_ROAM_STOP(pMac, sessionId) CSR_IS_ROAM_STATE( (pMac), eCSR_ROAMING_STATE_STOP, sessionId ) 
#define CSR_IS_ROAM_INIT(pMac, sessionId)  CSR_IS_ROAM_STATE( (pMac), eCSR_ROAMING_STATE_INIT, sessionId ) 
#define CSR_IS_ROAM_SCANNING(pMac, sessionId)  CSR_IS_ROAM_STATE( pMac, eCSR_ROAMING_STATE_SCANNING, sessionId )
#define CSR_IS_ROAM_JOINING(pMac, sessionId)   CSR_IS_ROAM_STATE( pMac, eCSR_ROAMING_STATE_JOINING, sessionId )
#define CSR_IS_ROAM_IDLE(pMac, sessionId) CSR_IS_ROAM_STATE( pMac, eCSR_ROAMING_STATE_IDLE, sessionId ) 
#define CSR_IS_ROAM_JOINED(pMac, sessionId)    CSR_IS_ROAM_STATE( pMac, eCSR_ROAMING_STATE_JOINED, sessionId )

#define CSR_IS_ROAM_SUBSTATE(pMac, subState, sessionId)   ((subState) == (pMac)->roam.curSubState[sessionId])
#define CSR_IS_ROAM_SUBSTATE_JOIN_REQ(pMac, sessionId)    CSR_IS_ROAM_SUBSTATE((pMac), eCSR_ROAM_SUBSTATE_JOIN_REQ, sessionId) 
#define CSR_IS_ROAM_SUBSTATE_AUTH_REQ(pMac, sessionId)    CSR_IS_ROAM_SUBSTATE((pMac), eCSR_ROAM_SUBSTATE_AUTH_REQ, sessionId) 
#define CSR_IS_ROAM_SUBSTATE_REASSOC_REQ(pMac, sessionId)    CSR_IS_ROAM_SUBSTATE((pMac), eCSR_ROAM_SUBSTATE_REASSOC_REQ, sessionId) 
#define CSR_IS_ROAM_SUBSTATE_DISASSOC_REQ(pMac, sessionId)    CSR_IS_ROAM_SUBSTATE((pMac), eCSR_ROAM_SUBSTATE_DISASSOC_REQ, sessionId) 
#define CSR_IS_ROAM_SUBSTATE_DISASSOC_NO_JOIN(pMac, sessionId)    CSR_IS_ROAM_SUBSTATE((pMac), eCSR_ROAM_SUBSTATE_DISASSOC_NOTHING_TO_JOIN, sessionId) 
#define CSR_IS_ROAM_SUBSTATE_REASSOC_FAIL(pMac, sessionId)    CSR_IS_ROAM_SUBSTATE((pMac), eCSR_ROAM_SUBSTATE_DISASSOC_REASSOC_FAILURE, sessionId) 
#define CSR_IS_ROAM_SUBSTATE_DISASSOC_FORCED(pMac, sessionId)    CSR_IS_ROAM_SUBSTATE((pMac), eCSR_ROAM_SUBSTATE_DISASSOC_FORCED, sessionId) 
#define CSR_IS_ROAM_SUBSTATE_DEAUTH_REQ(pMac, sessionId)    CSR_IS_ROAM_SUBSTATE((pMac), eCSR_ROAM_SUBSTATE_DEAUTH_REQ, sessionId) 
#define CSR_IS_ROAM_SUBSTATE_START_BSS_REQ(pMac, sessionId)    CSR_IS_ROAM_SUBSTATE((pMac), eCSR_ROAM_SUBSTATE_START_BSS_REQ, sessionId) 
#define CSR_IS_ROAM_SUBSTATE_STOP_BSS_REQ(pMac, sessionId)    CSR_IS_ROAM_SUBSTATE((pMac), eCSR_ROAM_SUBSTATE_STOP_BSS_REQ, sessionId) 
#define CSR_IS_ROAM_SUBSTATE_DISCONNECT_CONTINUE(pMac, sessionId)    CSR_IS_ROAM_SUBSTATE((pMac), eCSR_ROAM_SUBSTATE_DISCONNECT_CONTINUE_ROAMING, sessionId) 
#define CSR_IS_ROAM_SUBSTATE_CONFIG(pMac, sessionId)    CSR_IS_ROAM_SUBSTATE((pMac), eCSR_ROAM_SUBSTATE_CONFIG, sessionId)
#define CSR_IS_ROAM_SUBSTATE_WAITFORKEY(pMac, sessionId)    CSR_IS_ROAM_SUBSTATE((pMac), eCSR_ROAM_SUBSTATE_WAIT_FOR_KEY, sessionId)
#define CSR_IS_ROAM_SUBSTATE_DISASSOC_HO(pMac, sessionId)    CSR_IS_ROAM_SUBSTATE((pMac), eCSR_ROAM_SUBSTATE_DISASSOC_HANDOFF, sessionId) 
#define CSR_IS_ROAM_SUBSTATE_HO_NT(pMac, sessionId)    CSR_IS_ROAM_SUBSTATE((pMac), eCSR_ROAM_SUBSTATE_JOINED_NO_TRAFFIC, sessionId) 
#define CSR_IS_ROAM_SUBSTATE_HO_NRT(pMac, sessionId)    CSR_IS_ROAM_SUBSTATE((pMac), eCSR_ROAM_SUBSTATE_JOINED_NON_REALTIME_TRAFFIC, sessionId) 
#define CSR_IS_ROAM_SUBSTATE_HO_RT(pMac, sessionId)    CSR_IS_ROAM_SUBSTATE((pMac), eCSR_ROAM_SUBSTATE_JOINED_REALTIME_TRAFFIC, sessionId) 
=======
#define CSR_IS_ROAM_STOP(pMac, sessionId) CSR_IS_ROAM_STATE( (pMac), eCSR_ROAMING_STATE_STOP, sessionId )
#define CSR_IS_ROAM_INIT(pMac, sessionId)  CSR_IS_ROAM_STATE( (pMac), eCSR_ROAMING_STATE_INIT, sessionId )
#define CSR_IS_ROAM_SCANNING(pMac, sessionId)  CSR_IS_ROAM_STATE( pMac, eCSR_ROAMING_STATE_SCANNING, sessionId )
#define CSR_IS_ROAM_JOINING(pMac, sessionId)   CSR_IS_ROAM_STATE( pMac, eCSR_ROAMING_STATE_JOINING, sessionId )
#define CSR_IS_ROAM_IDLE(pMac, sessionId) CSR_IS_ROAM_STATE( pMac, eCSR_ROAMING_STATE_IDLE, sessionId )
#define CSR_IS_ROAM_JOINED(pMac, sessionId)    CSR_IS_ROAM_STATE( pMac, eCSR_ROAMING_STATE_JOINED, sessionId )

#define CSR_IS_ROAM_SUBSTATE(pMac, subState, sessionId)   ((subState) == (pMac)->roam.curSubState[sessionId])
#define CSR_IS_ROAM_SUBSTATE_JOIN_REQ(pMac, sessionId)    CSR_IS_ROAM_SUBSTATE((pMac), eCSR_ROAM_SUBSTATE_JOIN_REQ, sessionId)
#define CSR_IS_ROAM_SUBSTATE_AUTH_REQ(pMac, sessionId)    CSR_IS_ROAM_SUBSTATE((pMac), eCSR_ROAM_SUBSTATE_AUTH_REQ, sessionId)
#define CSR_IS_ROAM_SUBSTATE_REASSOC_REQ(pMac, sessionId)    CSR_IS_ROAM_SUBSTATE((pMac), eCSR_ROAM_SUBSTATE_REASSOC_REQ, sessionId)
#define CSR_IS_ROAM_SUBSTATE_DISASSOC_REQ(pMac, sessionId)    CSR_IS_ROAM_SUBSTATE((pMac), eCSR_ROAM_SUBSTATE_DISASSOC_REQ, sessionId)
#define CSR_IS_ROAM_SUBSTATE_DISASSOC_NO_JOIN(pMac, sessionId)    CSR_IS_ROAM_SUBSTATE((pMac), eCSR_ROAM_SUBSTATE_DISASSOC_NOTHING_TO_JOIN, sessionId)
#define CSR_IS_ROAM_SUBSTATE_REASSOC_FAIL(pMac, sessionId)    CSR_IS_ROAM_SUBSTATE((pMac), eCSR_ROAM_SUBSTATE_DISASSOC_REASSOC_FAILURE, sessionId)
#define CSR_IS_ROAM_SUBSTATE_DISASSOC_FORCED(pMac, sessionId)    CSR_IS_ROAM_SUBSTATE((pMac), eCSR_ROAM_SUBSTATE_DISASSOC_FORCED, sessionId)
#define CSR_IS_ROAM_SUBSTATE_DEAUTH_REQ(pMac, sessionId)    CSR_IS_ROAM_SUBSTATE((pMac), eCSR_ROAM_SUBSTATE_DEAUTH_REQ, sessionId)
#define CSR_IS_ROAM_SUBSTATE_START_BSS_REQ(pMac, sessionId)    CSR_IS_ROAM_SUBSTATE((pMac), eCSR_ROAM_SUBSTATE_START_BSS_REQ, sessionId)
#define CSR_IS_ROAM_SUBSTATE_STOP_BSS_REQ(pMac, sessionId)    CSR_IS_ROAM_SUBSTATE((pMac), eCSR_ROAM_SUBSTATE_STOP_BSS_REQ, sessionId)
#define CSR_IS_ROAM_SUBSTATE_DISCONNECT_CONTINUE(pMac, sessionId)    CSR_IS_ROAM_SUBSTATE((pMac), eCSR_ROAM_SUBSTATE_DISCONNECT_CONTINUE_ROAMING, sessionId)
#define CSR_IS_ROAM_SUBSTATE_CONFIG(pMac, sessionId)    CSR_IS_ROAM_SUBSTATE((pMac), eCSR_ROAM_SUBSTATE_CONFIG, sessionId)
#define CSR_IS_ROAM_SUBSTATE_WAITFORKEY(pMac, sessionId)    CSR_IS_ROAM_SUBSTATE((pMac), eCSR_ROAM_SUBSTATE_WAIT_FOR_KEY, sessionId)
#define CSR_IS_ROAM_SUBSTATE_DISASSOC_HO(pMac, sessionId)    CSR_IS_ROAM_SUBSTATE((pMac), eCSR_ROAM_SUBSTATE_DISASSOC_HANDOFF, sessionId)
#define CSR_IS_ROAM_SUBSTATE_HO_NT(pMac, sessionId)    CSR_IS_ROAM_SUBSTATE((pMac), eCSR_ROAM_SUBSTATE_JOINED_NO_TRAFFIC, sessionId)
#define CSR_IS_ROAM_SUBSTATE_HO_NRT(pMac, sessionId)    CSR_IS_ROAM_SUBSTATE((pMac), eCSR_ROAM_SUBSTATE_JOINED_NON_REALTIME_TRAFFIC, sessionId)
#define CSR_IS_ROAM_SUBSTATE_HO_RT(pMac, sessionId)    CSR_IS_ROAM_SUBSTATE((pMac), eCSR_ROAM_SUBSTATE_JOINED_REALTIME_TRAFFIC, sessionId)
>>>>>>> d97af3b... add prima wlan driver

#define CSR_IS_PHY_MODE_B_ONLY(pMac) \
        ((eCSR_DOT11_MODE_11b == (pMac)->roam.configParam.phyMode) ||\
        (eCSR_DOT11_MODE_11b_ONLY == (pMac)->roam.configParam.phyMode))
<<<<<<< HEAD
        
#define CSR_IS_PHY_MODE_G_ONLY(pMac) \
        (eCSR_DOT11_MODE_11g == (pMac)->roam.configParam.phyMode || eCSR_DOT11_MODE_11g_ONLY == (pMac)->roam.configParam.phyMode)        
        
#define CSR_IS_PHY_MODE_A_ONLY(pMac) \
        ((eCSR_DOT11_MODE_11a == (pMac)->roam.configParam.phyMode) ||\
        (eCSR_DOT11_MODE_11a_ONLY == (pMac)->roam.configParam.phyMode))
        
=======

#define CSR_IS_PHY_MODE_G_ONLY(pMac) \
        (eCSR_DOT11_MODE_11g == (pMac)->roam.configParam.phyMode || eCSR_DOT11_MODE_11g_ONLY == (pMac)->roam.configParam.phyMode)

#define CSR_IS_PHY_MODE_A_ONLY(pMac) \
        ((eCSR_DOT11_MODE_11a == (pMac)->roam.configParam.phyMode) ||\
        (eCSR_DOT11_MODE_11a_ONLY == (pMac)->roam.configParam.phyMode))

>>>>>>> d97af3b... add prima wlan driver
#ifdef WLAN_FEATURE_11AC
#define CSR_IS_PHY_MODE_DUAL_BAND(phyMode) \
        ((eCSR_DOT11_MODE_abg & (phyMode)) || (eCSR_DOT11_MODE_11n & (phyMode)) || \
        (eCSR_DOT11_MODE_11ac & (phyMode)) || \
        (eCSR_DOT11_MODE_TAURUS & (phyMode)) || \
        (eCSR_DOT11_MODE_AUTO & (phyMode)))
#else
#define CSR_IS_PHY_MODE_DUAL_BAND(phyMode) \
        ((eCSR_DOT11_MODE_abg & (phyMode)) || (eCSR_DOT11_MODE_11n & (phyMode)) || \
        (eCSR_DOT11_MODE_TAURUS & (phyMode)) || \
        (eCSR_DOT11_MODE_AUTO & (phyMode)))
#endif


// this function returns TRUE if the NIC is operating exclusively in the 2.4 GHz band, meaning
// it is NOT operating in the 5.0 GHz band.
#define CSR_IS_24_BAND_ONLY(pMac) \
        (eCSR_BAND_24 == (pMac)->roam.configParam.eBand)

#define CSR_IS_5G_BAND_ONLY(pMac) \
        (eCSR_BAND_5G == (pMac)->roam.configParam.eBand)

#define CSR_IS_RADIO_DUAL_BAND(pMac) \
        (eCSR_BAND_ALL == (pMac)->roam.configParam.bandCapability)

#define CSR_IS_RADIO_BG_ONLY(pMac) \
        (eCSR_BAND_24 == (pMac)->roam.configParam.bandCapability)

// this function returns TRUE if the NIC is operating exclusively in the 5.0 GHz band, meaning
// it is NOT operating in the 2.4 GHz band
#define CSR_IS_RADIO_A_ONLY(pMac) \
        (eCSR_BAND_5G == (pMac)->roam.configParam.bandCapability)

// this function returns TRUE if the NIC is operating in both bands.
#define CSR_IS_OPEARTING_DUAL_BAND(pMac) \
        ((eCSR_BAND_ALL == (pMac)->roam.configParam.bandCapability) && (eCSR_BAND_ALL == (pMac)->roam.configParam.eBand))

// this function returns TRUE if the NIC can operate in the 5.0 GHz band (could operate in the
// 2.4 GHz band also).
#define CSR_IS_OPERATING_A_BAND(pMac) \
        (CSR_IS_OPEARTING_DUAL_BAND((pMac)) || CSR_IS_RADIO_A_ONLY((pMac)) || CSR_IS_5G_BAND_ONLY((pMac)))

// this function returns TRUE if the NIC can operate in the 2.4 GHz band (could operate in the
// 5.0 GHz band also).
#define CSR_IS_OPERATING_BG_BAND(pMac) \
        (CSR_IS_OPEARTING_DUAL_BAND((pMac)) || CSR_IS_RADIO_BG_ONLY((pMac)) || CSR_IS_24_BAND_ONLY((pMac)))

#define CSR_IS_CHANNEL_5GHZ(chnNum) \
        (((chnNum) >= CSR_MIN_5GHz_CHANNEL_NUMBER) && ((chnNum) <= CSR_MAX_5GHz_CHANNEL_NUMBER))

<<<<<<< HEAD
#define CSR_IS_CHANNEL_24GHZ(chnNum) \
        (((chnNum) > 0) && ((chnNum) <= CSR_MAX_24GHz_CHANNEL_NUMBER))
        
=======
#define CSR_IS_CHANNEL_DFS(chnNum) \
         (NV_CHANNEL_ENABLE != vos_nv_getChannelEnabledState(chnNum))

#define CSR_IS_CHANNEL_24GHZ(chnNum) \
        (((chnNum) > 0) && ((chnNum) <= CSR_MAX_24GHz_CHANNEL_NUMBER))

>>>>>>> d97af3b... add prima wlan driver
#define CSR_IS_SAME_BAND_CHANNELS(ch1, ch2) (CSR_IS_CHANNEL_5GHZ(ch1) == CSR_IS_CHANNEL_5GHZ(ch2))


#define CSR_IS_11D_INFO_FOUND(pMac) \
        (0 != (pMac)->scan.channelOf11dInfo)
// DEAUTHIND
#define CSR_IS_ROAMING(pSession) ((CSR_IS_LOSTLINK_ROAMING((pSession)->roamingReason)) || \
                              (eCsrDynamicRoaming == (pSession)->roamingReason)  || \
<<<<<<< HEAD
                              (eCsrReassocRoaming == (pSession)->roamingReason))   
=======
                              (eCsrReassocRoaming == (pSession)->roamingReason))
>>>>>>> d97af3b... add prima wlan driver


#define CSR_IS_SET_KEY_COMMAND( pCommand )    ( eSmeCommandSetKey == (pCommand)->command )

#define CSR_IS_ADDTS_WHEN_ACMOFF_SUPPORTED(pMac) (pMac->roam.configParam.addTSWhenACMIsOff)
// DEAUTHIND
#define CSR_IS_LOSTLINK_ROAMING(reason)  ((eCsrLostlinkRoamingDisassoc == (reason)) || (eCsrLostlinkRoamingDeauth == (reason)))

<<<<<<< HEAD
=======
#define CSR_IS_ROAMING_COMMAND(pCommand) ((eCsrLostLink1 == (pCommand)->u.roamCmd.roamReason) ||\
                                          (eCsrLostLink2 == (pCommand)->u.roamCmd.roamReason) ||\
                                          (eCsrLostLink3 == (pCommand)->u.roamCmd.roamReason) )


>>>>>>> d97af3b... add prima wlan driver
//Stop CSR from asking for IMPS, This function doesn't disable IMPS from CSR
void csrScanSuspendIMPS( tpAniSirGlobal pMac );
//Start CSR from asking for IMPS. This function doesn't trigger CSR to request entering IMPS
//because IMPS maybe disabled.
void csrScanResumeIMPS( tpAniSirGlobal pMac );

eHalStatus csrInitGetChannels(tpAniSirGlobal pMac);
<<<<<<< HEAD
=======
// Getting the 5GHz Channel list
eHalStatus csrGet5GChannels(tpAniSirGlobal pMac);
// Getting the 2.4GHz Channel list
eHalStatus csrGet24GChannels(tpAniSirGlobal pMac);
>>>>>>> d97af3b... add prima wlan driver

eHalStatus csrSetModifyProfileFields(tpAniSirGlobal pMac, tANI_U32 sessionId,
                                     tCsrRoamModifyProfileFields *pModifyProfileFields);
/* ---------------------------------------------------------------------------
    \fn csrGetModifyProfileFields
<<<<<<< HEAD
    \brief HDD or SME - QOS calls this function to get the current values of 
    connected profile fields changing which can cause reassoc.
    This function must be called after CFG is downloaded and STA is in connected
    state.
    \param pModifyProfileFields - pointer to the connected profile fields 
    changing which can cause reassoc

    \return eHalStatus     
=======
    \brief HDD or SME - QOS calls this function to get the current values of
    connected profile fields changing which can cause reassoc.
    This function must be called after CFG is downloaded and STA is in connected
    state.
    \param pModifyProfileFields - pointer to the connected profile fields
    changing which can cause reassoc

    \return eHalStatus
>>>>>>> d97af3b... add prima wlan driver
  -------------------------------------------------------------------------------*/
eHalStatus csrGetModifyProfileFields(tpAniSirGlobal pMac, tANI_U32 sessionId,
                                     tCsrRoamModifyProfileFields * pModifyProfileFields);
void csrSetGlobalCfgs( tpAniSirGlobal pMac );
void csrSetDefaultDot11Mode( tpAniSirGlobal pMac );
void csrScanSetChannelMask(tpAniSirGlobal pMac, tCsrChannelInfo *pChannelInfo);
tANI_BOOLEAN csrIsConnStateDisconnected(tpAniSirGlobal pMac, tANI_U32 sessionId);
tANI_BOOLEAN csrIsConnStateConnectedIbss( tpAniSirGlobal pMac, tANI_U32 sessionId );
tANI_BOOLEAN csrIsConnStateDisconnectedIbss( tpAniSirGlobal pMac, tANI_U32 sessionId );
tANI_BOOLEAN csrIsConnStateConnectedInfra( tpAniSirGlobal pMac, tANI_U32 sessionId );
tANI_BOOLEAN csrIsConnStateConnected( tpAniSirGlobal pMac, tANI_U32 sessionId );
tANI_BOOLEAN csrIsConnStateInfra( tpAniSirGlobal pMac, tANI_U32 sessionId );
tANI_BOOLEAN csrIsConnStateIbss( tpAniSirGlobal pMac, tANI_U32 sessionId );
tANI_BOOLEAN csrIsConnStateWds( tpAniSirGlobal pMac, tANI_U32 sessionId );
tANI_BOOLEAN csrIsConnStateConnectedWds( tpAniSirGlobal pMac, tANI_U32 sessionId );
tANI_BOOLEAN csrIsConnStateDisconnectedWds( tpAniSirGlobal pMac, tANI_U32 sessionId );
tANI_BOOLEAN csrIsAnySessionInConnectState( tpAniSirGlobal pMac );
tANI_BOOLEAN csrIsAllSessionDisconnected( tpAniSirGlobal pMac );
<<<<<<< HEAD
=======
tANI_BOOLEAN csrIsStaSessionConnected( tpAniSirGlobal pMac );
tANI_BOOLEAN csrIsP2pSessionConnected( tpAniSirGlobal pMac );
tANI_BOOLEAN csrIsAnySessionConnected( tpAniSirGlobal pMac );
>>>>>>> d97af3b... add prima wlan driver
tANI_BOOLEAN csrIsInfraConnected( tpAniSirGlobal pMac );
tANI_BOOLEAN csrIsConcurrentInfraConnected( tpAniSirGlobal pMac );
tANI_BOOLEAN csrIsConcurrentSessionRunning( tpAniSirGlobal pMac );
tANI_BOOLEAN csrIsInfraApStarted( tpAniSirGlobal pMac );
tANI_BOOLEAN csrIsIBSSStarted( tpAniSirGlobal pMac );
tANI_BOOLEAN csrIsBTAMPStarted( tpAniSirGlobal pMac );
tANI_BOOLEAN csrIsBTAMP( tpAniSirGlobal pMac, tANI_U32 sessionId );
eHalStatus csrIsBTAMPAllowed( tpAniSirGlobal pMac, tANI_U32 chnId );
tANI_BOOLEAN csrIsValidMcConcurrentSession(tpAniSirGlobal pMac, tANI_U32 sessionId,
                                                  tSirBssDescription *pBssDesc);
<<<<<<< HEAD
#ifdef WLAN_SOFTAP_FEATURE
tANI_BOOLEAN csrIsConnStateConnectedInfraAp( tpAniSirGlobal pMac, tANI_U32 sessionId );
#endif
=======
tANI_BOOLEAN csrIsConnStateConnectedInfraAp( tpAniSirGlobal pMac, tANI_U32 sessionId );
>>>>>>> d97af3b... add prima wlan driver
/*----------------------------------------------------------------------------
  \fn csrRoamRegisterLinkQualityIndCallback

  \brief
<<<<<<< HEAD
  a CSR function to allow HDD to register a callback handler with CSR for 
  link quality indications. 
=======
  a CSR function to allow HDD to register a callback handler with CSR for
  link quality indications.
>>>>>>> d97af3b... add prima wlan driver

  Only one callback may be registered at any time.
  In order to deregister the callback, a NULL cback may be provided.

  Registration happens in the task context of the caller.

  \param callback - Call back being registered
  \param pContext - user data
<<<<<<< HEAD
  
  DEPENDENCIES: After CSR open

  \return eHalStatus  
-----------------------------------------------------------------------------*/
eHalStatus csrRoamRegisterLinkQualityIndCallback(tpAniSirGlobal pMac,
                                                 csrRoamLinkQualityIndCallback   callback,  
                                                 void                           *pContext);
/* ---------------------------------------------------------------------------
    \fn csrGetStatistics
    \brief csr function that client calls to register a callback to get 
    different PHY level statistics from CSR. 
    
    \param requesterId - different client requesting for statistics, HDD, UMA/GAN etc
    \param statsMask - The different category/categories of stats requester is looking for
    \param callback - SME sends back the requested stats using the callback
    \param periodicity - If requester needs periodic update, 0 means it's an one 
=======

  DEPENDENCIES: After CSR open

  \return eHalStatus
-----------------------------------------------------------------------------*/
eHalStatus csrRoamRegisterLinkQualityIndCallback(tpAniSirGlobal pMac,
                                                 csrRoamLinkQualityIndCallback   callback,
                                                 void                           *pContext);
/* ---------------------------------------------------------------------------
    \fn csrGetStatistics
    \brief csr function that client calls to register a callback to get
    different PHY level statistics from CSR.

    \param requesterId - different client requesting for statistics, HDD, UMA/GAN etc
    \param statsMask - The different category/categories of stats requester is looking for
    \param callback - SME sends back the requested stats using the callback
    \param periodicity - If requester needs periodic update, 0 means it's an one
>>>>>>> d97af3b... add prima wlan driver
                         time request
    \param cache - If requester is happy with cached stats
    \param staId - The station ID for which the stats is requested for
    \param pContext - user context to be passed back along with the callback

<<<<<<< HEAD
    \return eHalStatus     
  ---------------------------------------------------------------------------*/
eHalStatus csrGetStatistics(tpAniSirGlobal pMac, eCsrStatsRequesterType requesterId, 
                            tANI_U32 statsMask, 
                            tCsrStatsCallback callback, 
                            tANI_U32 periodicity, tANI_BOOLEAN cache, 
                            tANI_U8 staId, void *pContext);


eHalStatus csrGetRssi(tpAniSirGlobal pMac,tCsrRssiCallback callback,tANI_U8 staId,tCsrBssid bssId,void * pContext,void * pVosContext);
eHalStatus csrRoamRegisterCallback(tpAniSirGlobal pMac, csrRoamCompleteCallback callback, void *pContext);
/* ---------------------------------------------------------------------------
    \fn csrGetConfigParam
    \brief HDD calls this function to get the global settings currently maintained by CSR. 
    \param pParam - caller allocated memory
    \return eHalStatus     
=======
    \return eHalStatus
  ---------------------------------------------------------------------------*/
eHalStatus csrGetStatistics(tpAniSirGlobal pMac, eCsrStatsRequesterType requesterId,
                            tANI_U32 statsMask,
                            tCsrStatsCallback callback,
                            tANI_U32 periodicity, tANI_BOOLEAN cache,
                            tANI_U8 staId, void *pContext);

/* ---------------------------------------------------------------------------
    \fn csrGetTLSTAState
    \helper function to get the TL STA State whenever the function is called.

    \param staId - The staID to be passed to the TL
            to get the relevant TL STA State
    \return the state as tANI_U16
  ---------------------------------------------------------------------------*/
tANI_U16 csrGetTLSTAState(tpAniSirGlobal pMac, tANI_U8 staId);

eHalStatus csrGetRssi(tpAniSirGlobal pMac,tCsrRssiCallback callback,tANI_U8 staId,tCsrBssid bssId,void * pContext,void * pVosContext);

/* ---------------------------------------------------------------------------
    \fn csrGetSnr
    \brief csr function that client calls to register a callback to get
     SNR stored in TL

    \param callback - SME sends back the requested stats using the callback
    \param staId - The station ID for which the stats is requested for
    \param bssid - The bssid for the connected session
    \param pContext - user context to be passed back along with the callback

    \return eHalStatus
  ---------------------------------------------------------------------------*/
eHalStatus csrGetSnr(tpAniSirGlobal pMac, tCsrSnrCallback callback,
                     tANI_U8 staId, tCsrBssid bssId, void *pContext);

#if defined WLAN_FEATURE_VOWIFI_11R || defined FEATURE_WLAN_CCX || defined(FEATURE_WLAN_LFR)
eHalStatus csrGetRoamRssi(tpAniSirGlobal pMac,
                          tCsrRssiCallback callback,
                          tANI_U8 staId,
                          tCsrBssid bssId,
                          void * pContext,
                          void * pVosContext);
#endif
eHalStatus csrRoamRegisterCallback(tpAniSirGlobal pMac, csrRoamCompleteCallback callback, void *pContext);
/* ---------------------------------------------------------------------------
    \fn csrGetConfigParam
    \brief HDD calls this function to get the global settings currently maintained by CSR.
    \param pParam - caller allocated memory
    \return eHalStatus
>>>>>>> d97af3b... add prima wlan driver
  -------------------------------------------------------------------------------*/
eHalStatus csrGetConfigParam(tpAniSirGlobal pMac, tCsrConfigParam *pParam);

/* ---------------------------------------------------------------------------
    \fn csrMsgProcessor
<<<<<<< HEAD
    \brief HDD calls this function to change some global settings. 
    caller must set the all fields or call csrGetConfigParam to prefill the fields.
    \param pParam - caller allocated memory
    \return eHalStatus     
=======
    \brief HDD calls this function to change some global settings.
    caller must set the all fields or call csrGetConfigParam to prefill the fields.
    \param pParam - caller allocated memory
    \return eHalStatus
>>>>>>> d97af3b... add prima wlan driver
  -------------------------------------------------------------------------------*/
eHalStatus csrChangeDefaultConfigParam(tpAniSirGlobal pMac, tCsrConfigParam *pParam);


/* ---------------------------------------------------------------------------
    \fn csrMsgProcessor
    \brief HDD calls this function for the messages that are handled by CSR.
    \param pMsgBuf - a pointer to a buffer that maps to various structures base on the message type.
    The beginning of the buffer can always map to tSirSmeRsp.
<<<<<<< HEAD
    \return eHalStatus     
=======
    \return eHalStatus
>>>>>>> d97af3b... add prima wlan driver
  -------------------------------------------------------------------------------*/
eHalStatus csrMsgProcessor( tpAniSirGlobal pMac,  void *pMsgBuf );

/* ---------------------------------------------------------------------------
    \fn csrOpen
<<<<<<< HEAD
    \brief This function must be called before any API call to CSR. 
    \return eHalStatus     
=======
    \brief This function must be called before any API call to CSR.
    \return eHalStatus
>>>>>>> d97af3b... add prima wlan driver
  -------------------------------------------------------------------------------*/
eHalStatus csrOpen(tpAniSirGlobal pMac);
/* ---------------------------------------------------------------------------
    \fn csrClose
    \brief To close down CSR module. There should not be any API call into CSR after calling this function.
<<<<<<< HEAD
    \return eHalStatus     
=======
    \return eHalStatus
>>>>>>> d97af3b... add prima wlan driver
  -------------------------------------------------------------------------------*/
eHalStatus csrClose(tpAniSirGlobal pMac);
/* ---------------------------------------------------------------------------
    \fn csrStart
    \brief To start CSR.
<<<<<<< HEAD
    \return eHalStatus     
=======
    \return eHalStatus
>>>>>>> d97af3b... add prima wlan driver
  -------------------------------------------------------------------------------*/
eHalStatus csrStart(tpAniSirGlobal pMac);
/* ---------------------------------------------------------------------------
    \fn csrStop
    \brief To stop CSR. CSR still keeps its current setting.
<<<<<<< HEAD
    \return eHalStatus     
=======
    \return eHalStatus
>>>>>>> d97af3b... add prima wlan driver
  -------------------------------------------------------------------------------*/
eHalStatus csrStop(tpAniSirGlobal pMac);
/* ---------------------------------------------------------------------------
    \fn csrReady
    \brief To let CSR is ready to operate
<<<<<<< HEAD
    \return eHalStatus     
=======
    \return eHalStatus
>>>>>>> d97af3b... add prima wlan driver
  -------------------------------------------------------------------------------*/
eHalStatus csrReady(tpAniSirGlobal pMac);

#ifdef FEATURE_WLAN_WAPI
eHalStatus csrRoamGetBKIDCache(tpAniSirGlobal pMac, tANI_U32 sessionId, tANI_U32 *pNum,
                                tBkidCacheInfo *pBkidCache);


<<<<<<< HEAD
eHalStatus csrScanGetBKIDCandidateList(tpAniSirGlobal pMac, tANI_U32 sessionId, 
=======
eHalStatus csrScanGetBKIDCandidateList(tpAniSirGlobal pMac, tANI_U32 sessionId,
>>>>>>> d97af3b... add prima wlan driver
                                       tBkidCandidateInfo *pBkidList, tANI_U32 *pNumItems );
tANI_U32 csrRoamGetNumBKIDCache(tpAniSirGlobal pMac, tANI_U32 sessionId);
eHalStatus csrRoamSetBKIDCache( tpAniSirGlobal pMac, tANI_U32 sessionId, tBkidCacheInfo *pBKIDCache,
                                 tANI_U32 numItems );
/* ---------------------------------------------------------------------------
    \fn csrRoamGetWapiReqIE
    \brief return the WAPI IE CSR passes to PE to JOIN request or START_BSS request
<<<<<<< HEAD
    \param pLen - caller allocated memory that has the length of pBuf as input. Upon returned, *pLen has the 
=======
    \param pLen - caller allocated memory that has the length of pBuf as input. Upon returned, *pLen has the
>>>>>>> d97af3b... add prima wlan driver
    needed or IE length in pBuf.
    \param pBuf - Caller allocated memory that contain the IE field, if any, upon return
    \return eHalStatus - when fail, it usually means the buffer allocated is not big enough
  -------------------------------------------------------------------------------*/
eHalStatus csrRoamGetWapiReqIE(tpAniSirGlobal pMac, tANI_U32 sessionId, tANI_U32 *pLen, tANI_U8 *pBuf);

/* ---------------------------------------------------------------------------
    \fn csrRoamGetWapiRspIE
    \brief return the WAPI IE from the beacon or probe rsp if connected
<<<<<<< HEAD
    \param pLen - caller allocated memory that has the length of pBuf as input. Upon returned, *pLen has the 
=======
    \param pLen - caller allocated memory that has the length of pBuf as input. Upon returned, *pLen has the
>>>>>>> d97af3b... add prima wlan driver
    needed or IE length in pBuf.
    \param pBuf - Caller allocated memory that contain the IE field, if any, upon return
    \return eHalStatus - when fail, it usually means the buffer allocated is not big enough
  -------------------------------------------------------------------------------*/
eHalStatus csrRoamGetWapiRspIE(tpAniSirGlobal pMac, tANI_U32 sessionId, tANI_U32 *pLen, tANI_U8 *pBuf);
<<<<<<< HEAD
tANI_U8 csrConstructWapiIe( tpAniSirGlobal pMac, tANI_U32 sessionId, tCsrRoamProfile *pProfile, 
                            tSirBssDescription *pSirBssDesc, tDot11fBeaconIEs *pIes, tCsrWapiIe *pWapiIe );
#endif /* FEATURE_WLAN_WAPI */

#ifdef WLAN_SOFTAP_FEATURE
eHalStatus csrRoamUpdateAPWPSIE( tpAniSirGlobal pMac, tANI_U32 sessionId, tSirAPWPSIEs *pAPWPSIES );
eHalStatus csrRoamUpdateWPARSNIEs( tpAniSirGlobal pMac, tANI_U32 sessionId, tSirRSNie * pAPSirRSNie);
#endif
=======
tANI_U8 csrConstructWapiIe( tpAniSirGlobal pMac, tANI_U32 sessionId, tCsrRoamProfile *pProfile,
                            tSirBssDescription *pSirBssDesc, tDot11fBeaconIEs *pIes, tCsrWapiIe *pWapiIe );
#endif /* FEATURE_WLAN_WAPI */

eHalStatus csrRoamUpdateAPWPSIE( tpAniSirGlobal pMac, tANI_U32 sessionId, tSirAPWPSIEs *pAPWPSIES );
eHalStatus csrRoamUpdateWPARSNIEs( tpAniSirGlobal pMac, tANI_U32 sessionId, tSirRSNie * pAPSirRSNie);
>>>>>>> d97af3b... add prima wlan driver
void csrSetCfgPrivacy( tpAniSirGlobal pMac, tCsrRoamProfile *pProfile, tANI_BOOLEAN fPrivacy );
tANI_S8 csrGetInfraSessionId( tpAniSirGlobal pMac );
tANI_U8 csrGetInfraOperationChannel( tpAniSirGlobal pMac, tANI_U8 sessionId);
tANI_U8 csrGetConcurrentOperationChannel( tpAniSirGlobal pMac );

<<<<<<< HEAD
eHalStatus csrRoamCopyConnectProfile(tpAniSirGlobal pMac, tANI_U32 sessionId, 
=======
eHalStatus csrRoamCopyConnectProfile(tpAniSirGlobal pMac, tANI_U32 sessionId,
>>>>>>> d97af3b... add prima wlan driver
                               tCsrRoamConnectedProfile *pProfile);
tANI_BOOLEAN csrIsSetKeyAllowed(tpAniSirGlobal pMac, tANI_U32 sessionId);

void csrSetOppositeBandChannelInfo( tpAniSirGlobal pMac );
<<<<<<< HEAD
void csrConstructCurrentValidChannelList( tpAniSirGlobal pMac, tDblLinkList *pChannelSetList, 
                                            tANI_U8 *pChannelList, tANI_U8 bSize, tANI_U8 *pNumChannels );

=======
void csrConstructCurrentValidChannelList( tpAniSirGlobal pMac, tDblLinkList *pChannelSetList,
                                            tANI_U8 *pChannelList, tANI_U8 bSize, tANI_U8 *pNumChannels );
eHalStatus csrScanSavePreferredNetworkFound(tpAniSirGlobal pMac,
            tSirPrefNetworkFoundInd *pPrefNetworkFoundInd);
>>>>>>> d97af3b... add prima wlan driver
#endif

#ifdef WLAN_FEATURE_VOWIFI_11R
//Returns whether the current association is a 11r assoc or not
tANI_BOOLEAN csrRoamIs11rAssoc(tpAniSirGlobal pMac);
#endif

#ifdef FEATURE_WLAN_CCX
//Returns whether the current association is a CCX assoc or not
tANI_BOOLEAN csrRoamIsCCXAssoc(tpAniSirGlobal pMac);
#endif

<<<<<<< HEAD
=======
//Remove this code once SLM_Sessionization is supported
//BMPS_WORKAROUND_NOT_NEEDED
>>>>>>> d97af3b... add prima wlan driver
void csrDisconnectAllActiveSessions(tpAniSirGlobal pMac);

#ifdef FEATURE_WLAN_LFR
//Returns whether "Legacy Fast Roaming" is enabled...or not
<<<<<<< HEAD
tANI_BOOLEAN csrRoamIsFastRoamEnabled(tpAniSirGlobal pMac);
tANI_BOOLEAN csrIsChannelPresentInList( tANI_U8 *pChannelList, int  numChannels, tANI_U8   channel );
VOS_STATUS csrAddToChannelListFront( tANI_U8 *pChannelList, int  numChannels, tANI_U8   channel );
tANI_BOOLEAN csrNeighborRoamIsSsidCandidateMatch( tpAniSirGlobal pMac, tDot11fBeaconIEs *pIes);
=======
tANI_BOOLEAN csrRoamIsFastRoamEnabled(tpAniSirGlobal pMac, tANI_U32 sessionId);
#ifdef WLAN_FEATURE_ROAM_SCAN_OFFLOAD
tANI_BOOLEAN csrRoamIsRoamOffloadScanEnabled(tpAniSirGlobal pMac);
#endif
tANI_BOOLEAN csrIsChannelPresentInList( tANI_U8 *pChannelList, int  numChannels, tANI_U8   channel );
VOS_STATUS csrAddToChannelListFront( tANI_U8 *pChannelList, int  numChannels, tANI_U8   channel );
#ifdef WLAN_FEATURE_ROAM_SCAN_OFFLOAD
eHalStatus csrScanRequestLfrResult(tpAniSirGlobal pMac, tANI_U32 sessionId,
                                   csrScanCompleteCallback callback, void *pContext);
eHalStatus csrRoamOffloadScanRspHdlr(tpAniSirGlobal pMac, tANI_U8 reason);
eHalStatus csrHandoffRequest(tpAniSirGlobal pMac, tCsrHandoffRequest *pHandoffInfo);
#endif
tANI_BOOLEAN csrRoamIsStaMode(tpAniSirGlobal pMac, tANI_U32 sessionId);
>>>>>>> d97af3b... add prima wlan driver
#endif

