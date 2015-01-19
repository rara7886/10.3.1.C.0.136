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
/**========================================================================

  \file  wlan_hdd_assoc.c
  \brief WLAN Host Device Driver implementation
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
               
   Copyright 2008 (c) Qualcomm, Incorporated.  All Rights Reserved.
   
   Qualcomm Confidential and Proprietary.
  
<<<<<<< HEAD
  ========================================================================*/
/**========================================================================= 
                       EDIT HISTORY FOR FILE 
   
   
  This section contains comments describing changes made to the module. 
  Notice that changes are listed in reverse chronological order. 
   
   
  $Header:$   $DateTime: $ $Author: $ 
   
   
  when        who    what, where, why 
  --------    ---    --------------------------------------------------------
  05/06/09     Shailender     Created module. 
  ==========================================================================*/
  
=======

=======
>>>>>>> 657b0e9... prima update
  ========================================================================*/
/**========================================================================= 
                       EDIT HISTORY FOR FILE 
   
   
  This section contains comments describing changes made to the module. 
  Notice that changes are listed in reverse chronological order. 
   
   
  $Header:$   $DateTime: $ $Author: $ 
   
   
  when        who    what, where, why 
  --------    ---    --------------------------------------------------------
  05/06/09     Shailender     Created module. 
  ==========================================================================*/
<<<<<<< HEAD

>>>>>>> d97af3b... add prima wlan driver
=======
  
>>>>>>> 657b0e9... prima update
#include "wlan_hdd_includes.h"
#include <aniGlobal.h>
#include "dot11f.h"
#include "wlan_nlink_common.h"
#include "wlan_btc_svc.h"
#include "wlan_hdd_power.h"
<<<<<<< HEAD
<<<<<<< HEAD
#ifdef CONFIG_CFG80211
=======
>>>>>>> d97af3b... add prima wlan driver
=======
#ifdef CONFIG_CFG80211
>>>>>>> 657b0e9... prima update
#include <linux/ieee80211.h>
#include <linux/wireless.h>
#include <net/cfg80211.h>
#include "wlan_hdd_cfg80211.h"
#include "csrInsideApi.h"
<<<<<<< HEAD
<<<<<<< HEAD
#endif
#if defined CONFIG_CFG80211
#include "wlan_hdd_p2p.h"
=======
#include "wlan_hdd_p2p.h"
#ifdef FEATURE_WLAN_TDLS
#include "wlan_hdd_tdls.h"
>>>>>>> d97af3b... add prima wlan driver
=======
#endif
#if defined CONFIG_CFG80211
#include "wlan_hdd_p2p.h"
>>>>>>> 657b0e9... prima update
#endif
#include "sme_Api.h"

v_BOOL_t mibIsDot11DesiredBssTypeInfrastructure( hdd_adapter_t *pAdapter );

<<<<<<< HEAD
<<<<<<< HEAD
struct ether_addr 
=======
struct ether_addr
>>>>>>> d97af3b... add prima wlan driver
=======
struct ether_addr 
>>>>>>> 657b0e9... prima update
{
    u_char  ether_addr_octet[6];
};
// These are needed to recognize WPA and RSN suite types
#define HDD_WPA_OUI_SIZE 4
v_U8_t ccpWpaOui00[ HDD_WPA_OUI_SIZE ] = { 0x00, 0x50, 0xf2, 0x00 };
v_U8_t ccpWpaOui01[ HDD_WPA_OUI_SIZE ] = { 0x00, 0x50, 0xf2, 0x01 };
v_U8_t ccpWpaOui02[ HDD_WPA_OUI_SIZE ] = { 0x00, 0x50, 0xf2, 0x02 };
v_U8_t ccpWpaOui03[ HDD_WPA_OUI_SIZE ] = { 0x00, 0x50, 0xf2, 0x03 };
v_U8_t ccpWpaOui04[ HDD_WPA_OUI_SIZE ] = { 0x00, 0x50, 0xf2, 0x04 };
v_U8_t ccpWpaOui05[ HDD_WPA_OUI_SIZE ] = { 0x00, 0x50, 0xf2, 0x05 };
#ifdef FEATURE_WLAN_CCX
v_U8_t ccpWpaOui06[ HDD_WPA_OUI_SIZE ] = { 0x00, 0x40, 0x96, 0x00 }; // CCKM
#endif /* FEATURE_WLAN_CCX */
#define HDD_RSN_OUI_SIZE 4
v_U8_t ccpRSNOui00[ HDD_RSN_OUI_SIZE ] = { 0x00, 0x0F, 0xAC, 0x00 }; // group cipher
v_U8_t ccpRSNOui01[ HDD_RSN_OUI_SIZE ] = { 0x00, 0x0F, 0xAC, 0x01 }; // WEP-40 or RSN
v_U8_t ccpRSNOui02[ HDD_RSN_OUI_SIZE ] = { 0x00, 0x0F, 0xAC, 0x02 }; // TKIP or RSN-PSK
v_U8_t ccpRSNOui03[ HDD_RSN_OUI_SIZE ] = { 0x00, 0x0F, 0xAC, 0x03 }; // Reserved
v_U8_t ccpRSNOui04[ HDD_RSN_OUI_SIZE ] = { 0x00, 0x0F, 0xAC, 0x04 }; // AES-CCMP
v_U8_t ccpRSNOui05[ HDD_RSN_OUI_SIZE ] = { 0x00, 0x0F, 0xAC, 0x05 }; // WEP-104
#ifdef FEATURE_WLAN_CCX
v_U8_t ccpRSNOui06[ HDD_RSN_OUI_SIZE ] = { 0x00, 0x40, 0x96, 0x00 }; // CCKM
#endif /* FEATURE_WLAN_CCX */
<<<<<<< HEAD
<<<<<<< HEAD

#if defined(WLAN_FEATURE_VOWIFI_11R) 
// Offset where the EID-Len-IE, start.
#define FT_ASSOC_RSP_IES_OFFSET 6
=======
#ifdef WLAN_FEATURE_11W
v_U8_t ccpRSNOui07[ HDD_RSN_OUI_SIZE ] = { 0x00, 0x0F, 0xAC, 0x06 }; // RSN-PSK-SHA256
#endif
=======
>>>>>>> 657b0e9... prima update

#if defined(WLAN_FEATURE_VOWIFI_11R) 
// Offset where the EID-Len-IE, start.
<<<<<<< HEAD
#define FT_ASSOC_RSP_IES_OFFSET 6 /* Capability(2) + AID(2) + Status Code(2)*/
#define FT_ASSOC_REQ_IES_OFFSET 4 /* Capability(2) + LI(2) */
>>>>>>> d97af3b... add prima wlan driver
=======
#define FT_ASSOC_RSP_IES_OFFSET 6
>>>>>>> 657b0e9... prima update
#endif

#define BEACON_FRAME_IES_OFFSET 12

<<<<<<< HEAD
<<<<<<< HEAD
#ifdef WLAN_FEATURE_PACKET_FILTERING
extern void wlan_hdd_set_mc_addr_list(hdd_context_t *pHddCtx, v_U8_t set, v_U8_t sessionId);
#endif

void hdd_ResetCountryCodeAfterDisAssoc(hdd_adapter_t *pAdapter);

static inline v_VOID_t hdd_connSetConnectionState( hdd_station_ctx_t *pHddStaCtx, eConnectionState connState )
{         
   // save the new connection state 
=======
#ifdef WLAN_FEATURE_11W
void hdd_indicateUnprotMgmtFrame(hdd_adapter_t *pAdapter,
                            tANI_U32 nFrameLength,
                            tANI_U8* pbFrames,
                            tANI_U8 frameType );
=======
#ifdef WLAN_FEATURE_PACKET_FILTERING
extern void wlan_hdd_set_mc_addr_list(hdd_context_t *pHddCtx, v_U8_t set, v_U8_t sessionId);
>>>>>>> 657b0e9... prima update
#endif

void hdd_ResetCountryCodeAfterDisAssoc(hdd_adapter_t *pAdapter);

<<<<<<< HEAD
v_VOID_t hdd_connSetConnectionState( hdd_station_ctx_t *pHddStaCtx,
                                        eConnectionState connState )
{
   // save the new connection state
>>>>>>> d97af3b... add prima wlan driver
=======
static inline v_VOID_t hdd_connSetConnectionState( hdd_station_ctx_t *pHddStaCtx, eConnectionState connState )
{         
   // save the new connection state 
>>>>>>> 657b0e9... prima update
   pHddStaCtx->conn_info.connState = connState;
}

// returns FALSE if not connected.
// returns TRUE for the two 'connected' states (Infra Associated or IBSS Connected ).
// returns the connection state.  Can specify NULL if you dont' want to get the actual state.

<<<<<<< HEAD
<<<<<<< HEAD
static inline v_BOOL_t hdd_connGetConnectionState( hdd_station_ctx_t *pHddStaCtx, 
                                    eConnectionState *pConnState ) 
{
   v_BOOL_t fConnected; 
   eConnectionState connState;
    
   // get the connection state.
   connState = pHddStaCtx->conn_info.connState;
   // Set the fConnected return variable based on the Connected State.  
   if ( eConnectionState_Associated == connState ||
        eConnectionState_IbssConnected == connState )
   {
      fConnected = VOS_TRUE;
   }
   else 
   {
      fConnected = VOS_FALSE;
   }
    
=======
static inline v_BOOL_t hdd_connGetConnectionState( hdd_station_ctx_t *pHddStaCtx,
                                    eConnectionState *pConnState )
=======
static inline v_BOOL_t hdd_connGetConnectionState( hdd_station_ctx_t *pHddStaCtx, 
                                    eConnectionState *pConnState ) 
>>>>>>> 657b0e9... prima update
{
   v_BOOL_t fConnected; 
   eConnectionState connState;
    
   // get the connection state.
   connState = pHddStaCtx->conn_info.connState;
   // Set the fConnected return variable based on the Connected State.  
   if ( eConnectionState_Associated == connState ||
        eConnectionState_IbssConnected == connState )
   {
      fConnected = VOS_TRUE;
   }
   else 
   {
      fConnected = VOS_FALSE;
   }
<<<<<<< HEAD

>>>>>>> d97af3b... add prima wlan driver
=======
    
>>>>>>> 657b0e9... prima update
   if ( pConnState )
   {
      *pConnState = connState;
   }
<<<<<<< HEAD
<<<<<<< HEAD
  
=======

>>>>>>> d97af3b... add prima wlan driver
=======
  
>>>>>>> 657b0e9... prima update
   return( fConnected );
}

v_BOOL_t hdd_connIsConnected( hdd_station_ctx_t *pHddStaCtx )
{
   return( hdd_connGetConnectionState( pHddStaCtx, NULL ) );
<<<<<<< HEAD
<<<<<<< HEAD
}  
=======
}
>>>>>>> d97af3b... add prima wlan driver
=======
}  
>>>>>>> 657b0e9... prima update

//TODO - Not used anyhwere. Can be removed.
#if 0
//
v_BOOL_t hdd_connIsConnectedInfra( hdd_adapter_t *pAdapter )
{
   v_BOOL_t fConnectedInfra = FALSE;
   eConnectionState connState;
<<<<<<< HEAD
<<<<<<< HEAD
   
   if ( hdd_connGetConnectionState( WLAN_HDD_GET_STATION_CTX_PTR(pAdapter), &connState ) )
   {   
      if ( eConnectionState_Associated == connState ) 
      {
         fConnectedInfra = TRUE;
      }   
   }
   
   return( fConnectedInfra );
}
#endif
    
static inline v_BOOL_t hdd_connGetConnectedCipherAlgo( hdd_station_ctx_t *pHddStaCtx, eCsrEncryptionType *pConnectedCipherAlgo )
{
    v_BOOL_t fConnected = VOS_FALSE;
    
    fConnected = hdd_connGetConnectionState( pHddStaCtx, NULL );
  
    if ( pConnectedCipherAlgo ) 
    {
        *pConnectedCipherAlgo = pHddStaCtx->conn_info.ucEncryptionType;
    }
    
    return( fConnected );
}
 
inline v_BOOL_t hdd_connGetConnectedBssType( hdd_station_ctx_t *pHddStaCtx, eMib_dot11DesiredBssType *pConnectedBssType )
{
    v_BOOL_t fConnected = VOS_FALSE;
    
    fConnected = hdd_connGetConnectionState( pHddStaCtx, NULL );
  
    if ( pConnectedBssType ) 
    {
        *pConnectedBssType = pHddStaCtx->conn_info.connDot11DesiredBssType;
    }
    
=======

=======
   
>>>>>>> 657b0e9... prima update
   if ( hdd_connGetConnectionState( WLAN_HDD_GET_STATION_CTX_PTR(pAdapter), &connState ) )
   {   
      if ( eConnectionState_Associated == connState ) 
      {
         fConnectedInfra = TRUE;
      }   
   }
   
   return( fConnectedInfra );
}
#endif
    
static inline v_BOOL_t hdd_connGetConnectedCipherAlgo( hdd_station_ctx_t *pHddStaCtx, eCsrEncryptionType *pConnectedCipherAlgo )
{
    v_BOOL_t fConnected = VOS_FALSE;
    
    fConnected = hdd_connGetConnectionState( pHddStaCtx, NULL );
  
    if ( pConnectedCipherAlgo ) 
    {
        *pConnectedCipherAlgo = pHddStaCtx->conn_info.ucEncryptionType;
    }
    
    return( fConnected );
}
 
inline v_BOOL_t hdd_connGetConnectedBssType( hdd_station_ctx_t *pHddStaCtx, eMib_dot11DesiredBssType *pConnectedBssType )
{
    v_BOOL_t fConnected = VOS_FALSE;
    
    fConnected = hdd_connGetConnectionState( pHddStaCtx, NULL );
  
    if ( pConnectedBssType ) 
    {
        *pConnectedBssType = pHddStaCtx->conn_info.connDot11DesiredBssType;
    }
<<<<<<< HEAD

>>>>>>> d97af3b... add prima wlan driver
=======
    
>>>>>>> 657b0e9... prima update
    return( fConnected );
}

static inline void hdd_connSaveConnectedBssType( hdd_station_ctx_t *pHddStaCtx, eCsrRoamBssType csrRoamBssType )
{
<<<<<<< HEAD
<<<<<<< HEAD
   switch( csrRoamBssType ) 
=======
   switch( csrRoamBssType )
>>>>>>> d97af3b... add prima wlan driver
=======
   switch( csrRoamBssType ) 
>>>>>>> 657b0e9... prima update
   {
      case eCSR_BSS_TYPE_INFRASTRUCTURE:
          pHddStaCtx->conn_info.connDot11DesiredBssType = eMib_dot11DesiredBssType_infrastructure;
         break;
<<<<<<< HEAD
<<<<<<< HEAD
                     
=======

>>>>>>> d97af3b... add prima wlan driver
=======
                     
>>>>>>> 657b0e9... prima update
      case eCSR_BSS_TYPE_IBSS:
      case eCSR_BSS_TYPE_START_IBSS:
          pHddStaCtx->conn_info.connDot11DesiredBssType = eMib_dot11DesiredBssType_independent;
         break;
<<<<<<< HEAD
<<<<<<< HEAD
           
      /** We will never set the BssType to 'any' when attempting a connection 
            so CSR should never send this back to us.*/
      case eCSR_BSS_TYPE_ANY:                      
      default:
         VOS_ASSERT( 0 );
         break;      
   }                     
    
=======

      /** We will never set the BssType to 'any' when attempting a connection
=======
           
      /** We will never set the BssType to 'any' when attempting a connection 
>>>>>>> 657b0e9... prima update
            so CSR should never send this back to us.*/
      case eCSR_BSS_TYPE_ANY:                      
      default:
         VOS_ASSERT( 0 );
<<<<<<< HEAD
         break;
   }

>>>>>>> d97af3b... add prima wlan driver
=======
         break;      
   }                     
    
>>>>>>> 657b0e9... prima update
}

void hdd_connSaveConnectInfo( hdd_adapter_t *pAdapter, tCsrRoamInfo *pRoamInfo, eCsrRoamBssType eBssType )
{
   hdd_station_ctx_t *pHddStaCtx = WLAN_HDD_GET_STATION_CTX_PTR(pAdapter);
   eCsrEncryptionType encryptType = eCSR_ENCRYPT_TYPE_NONE;
<<<<<<< HEAD
<<<<<<< HEAD
 
   VOS_ASSERT( pRoamInfo );
   
   if ( pRoamInfo )   
   {
      // Save the BSSID for the connection...  
=======

=======
 
>>>>>>> 657b0e9... prima update
   VOS_ASSERT( pRoamInfo );
   
   if ( pRoamInfo )   
   {
<<<<<<< HEAD
      // Save the BSSID for the connection...
>>>>>>> d97af3b... add prima wlan driver
=======
      // Save the BSSID for the connection...  
>>>>>>> 657b0e9... prima update
      if ( eCSR_BSS_TYPE_INFRASTRUCTURE == eBssType )
      {
          VOS_ASSERT( pRoamInfo->pBssDesc );
          vos_mem_copy(pHddStaCtx->conn_info.bssId, pRoamInfo->bssid,6 );

          // Save the Station ID for this station from the 'Roam Info'.
          //For IBSS mode, staId is assigned in NEW_PEER_IND
          //For reassoc, the staID doesn't change and it may be invalid in this structure
          //so no change here.
          if( !pRoamInfo->fReassocReq )
          {
              pHddStaCtx->conn_info.staId [0]= pRoamInfo->staId;
          }
      }
      else if ( eCSR_BSS_TYPE_IBSS == eBssType )
<<<<<<< HEAD
<<<<<<< HEAD
      {   
         vos_mem_copy(pHddStaCtx->conn_info.bssId, pRoamInfo->bssid,sizeof(pRoamInfo->bssid) );
      }   
=======
      {
         vos_mem_copy(pHddStaCtx->conn_info.bssId, pRoamInfo->bssid,sizeof(pRoamInfo->bssid) );
      }
>>>>>>> d97af3b... add prima wlan driver
=======
      {   
         vos_mem_copy(pHddStaCtx->conn_info.bssId, pRoamInfo->bssid,sizeof(pRoamInfo->bssid) );
      }   
>>>>>>> 657b0e9... prima update
      else
      {
         // can't happen.  We need a valid IBSS or Infra setting in the BSSDescription
         // or we can't function.
         VOS_ASSERT( 0 );
      }

      // notify WMM
      hdd_wmm_connect(pAdapter, pRoamInfo, eBssType);

      if( !pRoamInfo->u.pConnectedProfile )
      {
         VOS_ASSERT( pRoamInfo->u.pConnectedProfile );
      }
      else
      {
          // Get Multicast Encryption Type
          encryptType =  pRoamInfo->u.pConnectedProfile->mcEncryptionType;
          pHddStaCtx->conn_info.mcEncryptionType = encryptType;
          // Get Unicast Encrytion Type
          encryptType =  pRoamInfo->u.pConnectedProfile->EncryptionType;
          pHddStaCtx->conn_info.ucEncryptionType = encryptType;

          pHddStaCtx->conn_info.authType =  pRoamInfo->u.pConnectedProfile->AuthType;

          pHddStaCtx->conn_info.operationChannel = pRoamInfo->u.pConnectedProfile->operationChannel;

          // Save the ssid for the connection
          vos_mem_copy( &pHddStaCtx->conn_info.SSID.SSID, &pRoamInfo->u.pConnectedProfile->SSID, sizeof( tSirMacSSid ) );
<<<<<<< HEAD
<<<<<<< HEAD
      }
   }   
      
   // save the connected BssType
   hdd_connSaveConnectedBssType( pHddStaCtx, eBssType );  
   
=======

          // Save  dot11mode in which STA associated to AP
          pHddStaCtx->conn_info.dot11Mode = pRoamInfo->u.pConnectedProfile->dot11Mode;
=======
>>>>>>> 657b0e9... prima update
      }
   }   
      
   // save the connected BssType
<<<<<<< HEAD
   hdd_connSaveConnectedBssType( pHddStaCtx, eBssType );

>>>>>>> d97af3b... add prima wlan driver
=======
   hdd_connSaveConnectedBssType( pHddStaCtx, eBssType );  
   
>>>>>>> 657b0e9... prima update
}

#if defined(WLAN_FEATURE_VOWIFI_11R)
/*
 * Send the 11R key information to the supplicant.
 * Only then can the supplicant generate the PMK-R1.
 * (BTW, the CCX supplicant also needs the Assoc Resp IEs
 * for the same purpose.)
 *
 * Mainly the Assoc Rsp IEs are passed here. For the IMDA
 * this contains the R1KHID, R0KHID and the MDID.
 * For FT, this consists of the Reassoc Rsp FTIEs.
 * This is the Assoc Response.
 */
<<<<<<< HEAD
<<<<<<< HEAD
static void hdd_SendFTAssocResponse(struct net_device *dev, hdd_adapter_t *pAdapter, 
=======
static void hdd_SendFTAssocResponse(struct net_device *dev, hdd_adapter_t *pAdapter,
>>>>>>> d97af3b... add prima wlan driver
=======
static void hdd_SendFTAssocResponse(struct net_device *dev, hdd_adapter_t *pAdapter, 
>>>>>>> 657b0e9... prima update
                tCsrRoamInfo *pCsrRoamInfo)
{
    union iwreq_data wrqu;
    char *buff;
    unsigned int len = 0;
    u8 *pFTAssocRsp = NULL;
<<<<<<< HEAD
<<<<<<< HEAD
    
    if (pCsrRoamInfo->nAssocRspLength == 0) 
=======

    if (pCsrRoamInfo->nAssocRspLength == 0)
>>>>>>> d97af3b... add prima wlan driver
=======
    
    if (pCsrRoamInfo->nAssocRspLength == 0) 
>>>>>>> 657b0e9... prima update
    {
        hddLog(LOGE,
            "%s: pCsrRoamInfo->nAssocRspLength=%d",
            __func__, (int)pCsrRoamInfo->nAssocRspLength);
        return;
    }

<<<<<<< HEAD
<<<<<<< HEAD
    pFTAssocRsp = (u8 *)(pCsrRoamInfo->pbFrames + pCsrRoamInfo->nBeaconLength + 
        pCsrRoamInfo->nAssocReqLength);
    if (pFTAssocRsp == NULL) 
    {
        hddLog(LOGE, "%s: AssocReq or AssocRsp is NULL", __func__); 
=======
    pFTAssocRsp = (u8 *)(pCsrRoamInfo->pbFrames + pCsrRoamInfo->nBeaconLength +
=======
    pFTAssocRsp = (u8 *)(pCsrRoamInfo->pbFrames + pCsrRoamInfo->nBeaconLength + 
>>>>>>> 657b0e9... prima update
        pCsrRoamInfo->nAssocReqLength);
    if (pFTAssocRsp == NULL) 
    {
<<<<<<< HEAD
        hddLog(LOGE, "%s: AssocReq or AssocRsp is NULL", __func__);
>>>>>>> d97af3b... add prima wlan driver
=======
        hddLog(LOGE, "%s: AssocReq or AssocRsp is NULL", __func__); 
>>>>>>> 657b0e9... prima update
        return;
    }

    // pFTAssocRsp needs to point to the IEs
    pFTAssocRsp += FT_ASSOC_RSP_IES_OFFSET;
    hddLog(LOG1, "%s: AssocRsp is now at %02x%02x", __func__,
        (unsigned int)pFTAssocRsp[0],
        (unsigned int)pFTAssocRsp[1]);

    // We need to send the IEs to the supplicant.
    buff = kmalloc(IW_GENERIC_IE_MAX, GFP_ATOMIC);
<<<<<<< HEAD
<<<<<<< HEAD
    if (buff == NULL) 
    {
        hddLog(LOGE, "%s: kmalloc unable to allocate memory", __func__); 
=======
    if (buff == NULL)
    {
        hddLog(LOGE, "%s: kmalloc unable to allocate memory", __func__);
>>>>>>> d97af3b... add prima wlan driver
=======
    if (buff == NULL) 
    {
        hddLog(LOGE, "%s: kmalloc unable to allocate memory", __func__); 
>>>>>>> 657b0e9... prima update
        return;
    }

    // Send the Assoc Resp, the supplicant needs this for initial Auth.
    len = pCsrRoamInfo->nAssocRspLength - FT_ASSOC_RSP_IES_OFFSET;
<<<<<<< HEAD
<<<<<<< HEAD
    wrqu.data.length = len; 
    memset(buff, 0, IW_GENERIC_IE_MAX);
    memcpy(buff, pFTAssocRsp, len); 
=======
    wrqu.data.length = len;
    memset(buff, 0, IW_GENERIC_IE_MAX);
    memcpy(buff, pFTAssocRsp, len);
>>>>>>> d97af3b... add prima wlan driver
=======
    wrqu.data.length = len; 
    memset(buff, 0, IW_GENERIC_IE_MAX);
    memcpy(buff, pFTAssocRsp, len); 
>>>>>>> 657b0e9... prima update
    wireless_send_event(dev, IWEVASSOCRESPIE, &wrqu, buff);

    kfree(buff);
}
<<<<<<< HEAD
<<<<<<< HEAD
#endif /* WLAN_FEATURE_VOWIFI_11R */ 
=======
#endif /* WLAN_FEATURE_VOWIFI_11R */
>>>>>>> d97af3b... add prima wlan driver
=======
#endif /* WLAN_FEATURE_VOWIFI_11R */ 
>>>>>>> 657b0e9... prima update

#ifdef WLAN_FEATURE_VOWIFI_11R

/*---------------------------------------------------
 *
 * Send the FTIEs, RIC IEs during FT. This is eventually
 * used to send the FT events to the supplicant
 *
 * At the reception of Auth2 we send the RIC followed
 * by the auth response IEs to the supplicant.
 * Once both are received in the supplicant, an FT
 * event is generated to the supplicant.
 *
 *---------------------------------------------------
 */
void hdd_SendFTEvent(hdd_adapter_t *pAdapter)
{
<<<<<<< HEAD
<<<<<<< HEAD
    union iwreq_data wrqu;
    //struct wpabuf *ric = NULL;
    char *buff;
    tANI_U16 auth_resp_len = 0;
    tANI_U32 ric_ies_length = 0;
    tANI_U16 str_len;
    hdd_context_t *pHddCtx = WLAN_HDD_GET_CTX(pAdapter);

    // We need to send the IEs to the supplicant.
    buff = kmalloc(IW_CUSTOM_MAX, GFP_ATOMIC);
    if (buff == NULL) 
    {
        hddLog(LOGE, "%s: kmalloc unable to allocate memory", __func__); 
        return;
    }
    vos_mem_zero(buff, IW_CUSTOM_MAX); 

    // Sme needs to send the RIC IEs first 
    str_len = strlcpy(buff, "RIC=", IW_CUSTOM_MAX);
    sme_GetRICIEs( pHddCtx->hHal, (u8 *)&(buff[str_len]), 
                   (IW_CUSTOM_MAX - str_len), &ric_ies_length ); 
    if (ric_ies_length == 0) 
    {
        hddLog(LOGW, "%s: RIC IEs is of length 0 not sending RIC Information for now", __func__); 
=======
=======
    union iwreq_data wrqu;
    //struct wpabuf *ric = NULL;
    char *buff;
>>>>>>> 657b0e9... prima update
    tANI_U16 auth_resp_len = 0;
    tANI_U32 ric_ies_length = 0;
    tANI_U16 str_len;
    hdd_context_t *pHddCtx = WLAN_HDD_GET_CTX(pAdapter);

    // We need to send the IEs to the supplicant.
    buff = kmalloc(IW_CUSTOM_MAX, GFP_ATOMIC);
    if (buff == NULL) 
    {
        hddLog(LOGE, "%s: kmalloc unable to allocate memory", __func__); 
        return;
    }
    vos_mem_zero(buff, IW_CUSTOM_MAX); 

    // Sme needs to send the RIC IEs first 
    str_len = strlcpy(buff, "RIC=", IW_CUSTOM_MAX);
    sme_GetRICIEs( pHddCtx->hHal, (u8 *)&(buff[str_len]), 
                   (IW_CUSTOM_MAX - str_len), &ric_ies_length ); 
    if (ric_ies_length == 0) 
    {
<<<<<<< HEAD
        hddLog(LOGW,
               "%s: RIC IEs is of length 0 not sending RIC Information for now",
               __func__);
>>>>>>> d97af3b... add prima wlan driver
=======
        hddLog(LOGW, "%s: RIC IEs is of length 0 not sending RIC Information for now", __func__); 
>>>>>>> 657b0e9... prima update
    }
    else
    {
        wrqu.data.length = str_len + ric_ies_length;
        wireless_send_event(pAdapter->dev, IWEVCUSTOM, &wrqu, buff);
    }

    // Sme needs to provide the Auth Resp
<<<<<<< HEAD
<<<<<<< HEAD
    vos_mem_zero(buff, IW_CUSTOM_MAX); 
    str_len = strlcpy(buff, "AUTH=", IW_CUSTOM_MAX);
    sme_GetFTPreAuthResponse(pHddCtx->hHal, (u8 *)&buff[str_len], 
                             (IW_CUSTOM_MAX - str_len),  &auth_resp_len);

    if (auth_resp_len == 0) 
    {
        hddLog(LOGE, "%s: AuthRsp FTIES is of length 0", __func__); 
=======
    vos_mem_zero(buff, IW_CUSTOM_MAX);
=======
    vos_mem_zero(buff, IW_CUSTOM_MAX); 
>>>>>>> 657b0e9... prima update
    str_len = strlcpy(buff, "AUTH=", IW_CUSTOM_MAX);
    sme_GetFTPreAuthResponse(pHddCtx->hHal, (u8 *)&buff[str_len], 
                             (IW_CUSTOM_MAX - str_len),  &auth_resp_len);

    if (auth_resp_len == 0) 
    {
<<<<<<< HEAD
        hddLog(LOGE, "%s: AuthRsp FTIES is of length 0", __func__);
>>>>>>> d97af3b... add prima wlan driver
=======
        hddLog(LOGE, "%s: AuthRsp FTIES is of length 0", __func__); 
>>>>>>> 657b0e9... prima update
        return;
    }

    wrqu.data.length = str_len + auth_resp_len;
    wireless_send_event(pAdapter->dev, IWEVCUSTOM, &wrqu, buff);

    kfree(buff);
<<<<<<< HEAD
<<<<<<< HEAD
=======
#endif
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
}

#endif /* WLAN_FEATURE_VOWIFI_11R */

#ifdef FEATURE_WLAN_CCX

/*
 * Send the CCX required "new AP Channel info" to the supplicant.
 * (This keeps the supplicant "up to date" on the current channel.)
 *
 * The current (new AP) channel information is passed in.
 */
<<<<<<< HEAD
<<<<<<< HEAD
static void hdd_SendNewAPChannelInfo(struct net_device *dev, hdd_adapter_t *pAdapter, 
=======
static void hdd_SendNewAPChannelInfo(struct net_device *dev, hdd_adapter_t *pAdapter,
>>>>>>> d97af3b... add prima wlan driver
=======
static void hdd_SendNewAPChannelInfo(struct net_device *dev, hdd_adapter_t *pAdapter, 
>>>>>>> 657b0e9... prima update
                tCsrRoamInfo *pCsrRoamInfo)
{
    union iwreq_data wrqu;
    tSirBssDescription *descriptor = pCsrRoamInfo->pBssDesc;
<<<<<<< HEAD
<<<<<<< HEAD
     

    if (descriptor == NULL) 
=======


    if (descriptor == NULL)
>>>>>>> d97af3b... add prima wlan driver
=======
     

    if (descriptor == NULL) 
>>>>>>> 657b0e9... prima update
    {
        hddLog(LOGE,
            "%s: pCsrRoamInfo->pBssDesc=%p\n",
            __func__, descriptor);
        return;
    }

    // Send the Channel event, the supplicant needs this to generate the Adjacent AP report.
    hddLog(LOGW, "%s: Sending up an SIOCGIWFREQ, channelId=%d\n", __func__, descriptor->channelId);
    memset(&wrqu, '\0', sizeof(wrqu));
    wrqu.freq.m = descriptor->channelId;
    wrqu.freq.e = 0;
    wrqu.freq.i = 0;
    wireless_send_event(pAdapter->dev, SIOCGIWFREQ, &wrqu, NULL);
}

#endif /* FEATURE_WLAN_CCX */

void hdd_SendUpdateBeaconIEsEvent(hdd_adapter_t *pAdapter, tCsrRoamInfo *pCsrRoamInfo)
{
    union iwreq_data wrqu;
    u8  *pBeaconIes;
    u8 currentLen = 0;
    char *buff;
    int totalIeLen = 0, currentOffset = 0, strLen;

    memset(&wrqu, '\0', sizeof(wrqu));

    if (0 == pCsrRoamInfo->nBeaconLength)
    {
        hddLog(LOGE, "%s: pCsrRoamInfo->nBeaconFrameLength = 0", __func__);
        return;
    }
    pBeaconIes = (u8 *)(pCsrRoamInfo->pbFrames + BEACON_FRAME_IES_OFFSET);
<<<<<<< HEAD
<<<<<<< HEAD
    if (pBeaconIes == NULL) 
    {
        hddLog(LOGE, "%s: Beacon IEs is NULL", __func__); 
=======
    if (pBeaconIes == NULL)
    {
        hddLog(LOGE, "%s: Beacon IEs is NULL", __func__);
>>>>>>> d97af3b... add prima wlan driver
=======
    if (pBeaconIes == NULL) 
    {
        hddLog(LOGE, "%s: Beacon IEs is NULL", __func__); 
>>>>>>> 657b0e9... prima update
        return;
    }

    // pBeaconIes needs to point to the IEs
    hddLog(LOG1, "%s: Beacon IEs is now at %02x%02x", __func__,
        (unsigned int)pBeaconIes[0],
        (unsigned int)pBeaconIes[1]);
    hddLog(LOG1, "%s: Beacon IEs length = %d", __func__, pCsrRoamInfo->nBeaconLength - BEACON_FRAME_IES_OFFSET);
<<<<<<< HEAD
<<<<<<< HEAD
    
   // We need to send the IEs to the supplicant.
    buff = kmalloc(IW_CUSTOM_MAX, GFP_ATOMIC);
    if (buff == NULL) 
    {
        hddLog(LOGE, "%s: kmalloc unable to allocate memory", __func__); 
        return;
    }
    vos_mem_zero(buff, IW_CUSTOM_MAX); 
=======

=======
    
>>>>>>> 657b0e9... prima update
   // We need to send the IEs to the supplicant.
    buff = kmalloc(IW_CUSTOM_MAX, GFP_ATOMIC);
    if (buff == NULL) 
    {
        hddLog(LOGE, "%s: kmalloc unable to allocate memory", __func__); 
        return;
    }
<<<<<<< HEAD
    vos_mem_zero(buff, IW_CUSTOM_MAX);
>>>>>>> d97af3b... add prima wlan driver
=======
    vos_mem_zero(buff, IW_CUSTOM_MAX); 
>>>>>>> 657b0e9... prima update

    strLen = strlcpy(buff,"BEACONIEs=", IW_CUSTOM_MAX);
    currentLen = strLen + 1;

    totalIeLen = pCsrRoamInfo->nBeaconLength - BEACON_FRAME_IES_OFFSET;
    do
    {
<<<<<<< HEAD
<<<<<<< HEAD
        /* If the beacon size exceeds max CUSTOM event size, break it into chunks of CUSTOM event 
=======
        /* If the beacon size exceeds max CUSTOM event size, break it into chunks of CUSTOM event
>>>>>>> d97af3b... add prima wlan driver
=======
        /* If the beacon size exceeds max CUSTOM event size, break it into chunks of CUSTOM event 
>>>>>>> 657b0e9... prima update
         * max size and send it to supplicant. Changes are done in supplicant to handle this */
        vos_mem_zero(&buff[strLen + 1], IW_CUSTOM_MAX - (strLen + 1));
        currentLen = VOS_MIN(totalIeLen, IW_CUSTOM_MAX - (strLen + 1) - 1);
        vos_mem_copy(&buff[strLen + 1], pBeaconIes+currentOffset, currentLen);
        currentOffset += currentLen;
        totalIeLen -= currentLen;
        wrqu.data.length = strLen + 1 + currentLen;
        if (totalIeLen)
<<<<<<< HEAD
<<<<<<< HEAD
          buff[strLen] = 1;   // This tells supplicant more chunks are pending 
=======
          buff[strLen] = 1;   // This tells supplicant more chunks are pending
>>>>>>> d97af3b... add prima wlan driver
=======
          buff[strLen] = 1;   // This tells supplicant more chunks are pending 
>>>>>>> 657b0e9... prima update
        else
          buff[strLen] = 0;   // For last chunk of beacon IE to supplicant

        hddLog(LOG1, "%s: Beacon IEs length to supplicant = %d", __func__, currentLen);
        wireless_send_event(pAdapter->dev, IWEVCUSTOM, &wrqu, buff);
    } while (totalIeLen > 0);

    kfree(buff);
}

static void hdd_SendAssociationEvent(struct net_device *dev,tCsrRoamInfo *pCsrRoamInfo)
{
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
    hdd_context_t *pHddCtx = WLAN_HDD_GET_CTX(pAdapter);
    hdd_station_ctx_t *pHddStaCtx = WLAN_HDD_GET_STATION_CTX_PTR(pAdapter);
    union iwreq_data wrqu;
    int we_event;
    char *msg;
    int type = -1;

<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
#if defined (WLAN_FEATURE_VOWIFI_11R) 
    // Added to find the auth type on the fly at run time 
    // rather than with cfg to see if FT is enabled 
    hdd_wext_state_t  *pWextState =  WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter);   
<<<<<<< HEAD
    tCsrRoamProfile* pRoamProfile = &(pWextState->roamProfile);
#endif
 
    memset(&wrqu, '\0', sizeof(wrqu));
    wrqu.ap_addr.sa_family = ARPHRD_ETHER; 
    we_event = SIOCGIWAP;
   
=======
#if defined (WLAN_FEATURE_VOWIFI_11R)
    // Added to find the auth type on the fly at run time
    // rather than with cfg to see if FT is enabled
    hdd_wext_state_t  *pWextState =  WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter);
=======
>>>>>>> 657b0e9... prima update
    tCsrRoamProfile* pRoamProfile = &(pWextState->roamProfile);
#endif
 
    memset(&wrqu, '\0', sizeof(wrqu));
    wrqu.ap_addr.sa_family = ARPHRD_ETHER; 
    we_event = SIOCGIWAP;
<<<<<<< HEAD

>>>>>>> d97af3b... add prima wlan driver
=======
   
>>>>>>> 657b0e9... prima update
    if(eConnectionState_Associated == pHddStaCtx->conn_info.connState)/* Associated */
    {
        memcpy(wrqu.ap_addr.sa_data, pCsrRoamInfo->pBssDesc->bssId, sizeof(pCsrRoamInfo->pBssDesc->bssId));
        type = WLAN_STA_ASSOC_DONE_IND;

<<<<<<< HEAD
<<<<<<< HEAD
=======
#ifdef WLAN_FEATURE_P2P_DEBUG
        if(pAdapter->device_mode == WLAN_HDD_P2P_CLIENT)
        {
             if(globalP2PConnectionStatus == P2P_CLIENT_CONNECTING_STATE_1)
             {
                 globalP2PConnectionStatus = P2P_CLIENT_CONNECTED_STATE_1;
                 hddLog(VOS_TRACE_LEVEL_ERROR,"[P2P State] Changing state from "
                                "Connecting state to Connected State for 8-way "
                                "Handshake");
             }
             else if(globalP2PConnectionStatus == P2P_CLIENT_CONNECTING_STATE_2)
             {
                 globalP2PConnectionStatus = P2P_CLIENT_COMPLETED_STATE;
                 hddLog(VOS_TRACE_LEVEL_ERROR,"[P2P State] Changing state from "
                           "Connecting state to P2P Client Connection Completed");
             }
        }
#endif
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
        pr_info("wlan: connected to %02x:%02x:%02x:%02x:%02x:%02x\n",
                      wrqu.ap_addr.sa_data[0],
                      wrqu.ap_addr.sa_data[1],
                      wrqu.ap_addr.sa_data[2],
                      wrqu.ap_addr.sa_data[3],
                      wrqu.ap_addr.sa_data[4],
                      wrqu.ap_addr.sa_data[5]);
        hdd_SendUpdateBeaconIEsEvent(pAdapter, pCsrRoamInfo);

        /* Send IWEVASSOCRESPIE Event if WLAN_FEATURE_CIQ_METRICS is Enabled Or
         * Send IWEVASSOCRESPIE Event if WLAN_FEATURE_VOWIFI_11R is Enabled
         * and fFTEnable is TRUE */
#ifdef WLAN_FEATURE_VOWIFI_11R
        // Send FT Keys to the supplicant when FT is enabled
        if ((pRoamProfile->AuthType.authType[0] == eCSR_AUTH_TYPE_FT_RSN_PSK) ||
<<<<<<< HEAD
<<<<<<< HEAD
            (pRoamProfile->AuthType.authType[0] == eCSR_AUTH_TYPE_FT_RSN) 
=======
            (pRoamProfile->AuthType.authType[0] == eCSR_AUTH_TYPE_FT_RSN)
>>>>>>> d97af3b... add prima wlan driver
=======
            (pRoamProfile->AuthType.authType[0] == eCSR_AUTH_TYPE_FT_RSN) 
>>>>>>> 657b0e9... prima update
#ifdef FEATURE_WLAN_CCX
            || (pRoamProfile->AuthType.authType[0] == eCSR_AUTH_TYPE_CCKM_RSN) ||
            (pRoamProfile->AuthType.authType[0] == eCSR_AUTH_TYPE_CCKM_WPA)
#endif
        )
        {
            hdd_SendFTAssocResponse(dev, pAdapter, pCsrRoamInfo);
        }
#endif
    }
    else if (eConnectionState_IbssConnected == pHddStaCtx->conn_info.connState) // IBss Associated
    {
<<<<<<< HEAD
<<<<<<< HEAD
        memcpy(wrqu.ap_addr.sa_data, pHddStaCtx->conn_info.bssId, sizeof(wrqu.ap_addr.sa_data));
=======
        memcpy(wrqu.ap_addr.sa_data, pHddStaCtx->conn_info.bssId, ETH_ALEN);
>>>>>>> d97af3b... add prima wlan driver
=======
        memcpy(wrqu.ap_addr.sa_data, pHddStaCtx->conn_info.bssId, sizeof(wrqu.ap_addr.sa_data));
>>>>>>> 657b0e9... prima update
        type = WLAN_STA_ASSOC_DONE_IND;
        pr_info("wlan: new IBSS connection to %02x:%02x:%02x:%02x:%02x:%02x",
                      pHddStaCtx->conn_info.bssId[0],
                      pHddStaCtx->conn_info.bssId[1],
                      pHddStaCtx->conn_info.bssId[2],
                      pHddStaCtx->conn_info.bssId[3],
                      pHddStaCtx->conn_info.bssId[4],
                      pHddStaCtx->conn_info.bssId[5]);
    }
    else /* Not Associated */
    {
        pr_info("wlan: disconnected\n");
        type = WLAN_STA_DISASSOC_DONE_IND;
        memset(wrqu.ap_addr.sa_data,'\0',ETH_ALEN);
    }
<<<<<<< HEAD
<<<<<<< HEAD
=======
    hdd_dump_concurrency_info(pHddCtx);
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update

    msg = NULL;
    /*During the WLAN uninitialization,supplicant is stopped before the
      driver so not sending the status of the connection to supplicant*/
    if(pHddCtx->isLoadUnloadInProgress != TRUE)
    {
        wireless_send_event(dev, we_event, &wrqu, msg);
#ifdef FEATURE_WLAN_CCX
        if(eConnectionState_Associated == pHddStaCtx->conn_info.connState)/* Associated */
<<<<<<< HEAD
<<<<<<< HEAD
        {        
            if ( (pRoamProfile->AuthType.authType[0] == eCSR_AUTH_TYPE_CCKM_RSN) || 
                (pRoamProfile->AuthType.authType[0] == eCSR_AUTH_TYPE_CCKM_WPA) ) 
=======
        {
            if ( (pRoamProfile->AuthType.authType[0] == eCSR_AUTH_TYPE_CCKM_RSN) ||
                (pRoamProfile->AuthType.authType[0] == eCSR_AUTH_TYPE_CCKM_WPA) )
>>>>>>> d97af3b... add prima wlan driver
=======
        {        
            if ( (pRoamProfile->AuthType.authType[0] == eCSR_AUTH_TYPE_CCKM_RSN) || 
                (pRoamProfile->AuthType.authType[0] == eCSR_AUTH_TYPE_CCKM_WPA) ) 
>>>>>>> 657b0e9... prima update
            hdd_SendNewAPChannelInfo(dev, pAdapter, pCsrRoamInfo);
        }
#endif
    }
    send_btc_nlink_msg(type, 0);
}

void hdd_connRemoveConnectInfo( hdd_station_ctx_t *pHddStaCtx )
{
   // Remove staId, bssId and peerMacAddress
   pHddStaCtx->conn_info.staId [ 0 ] = 0;
   vos_mem_zero( &pHddStaCtx->conn_info.bssId, sizeof( v_MACADDR_t ) );
   vos_mem_zero( &pHddStaCtx->conn_info.peerMacAddress[ 0 ], sizeof( v_MACADDR_t ) );

   // Clear all security settings
   pHddStaCtx->conn_info.authType         = eCSR_AUTH_TYPE_OPEN_SYSTEM;
   pHddStaCtx->conn_info.mcEncryptionType = eCSR_ENCRYPT_TYPE_NONE;
   pHddStaCtx->conn_info.ucEncryptionType = eCSR_ENCRYPT_TYPE_NONE;

   vos_mem_zero( &pHddStaCtx->conn_info.Keys, sizeof( tCsrKeys ) );

   // Set not-connected state
   pHddStaCtx->conn_info.connDot11DesiredBssType = eCSR_BSS_TYPE_ANY;
<<<<<<< HEAD
<<<<<<< HEAD
   hdd_connSetConnectionState( pHddStaCtx, eConnectionState_NotConnected );  
=======
   hdd_connSetConnectionState( pHddStaCtx, eConnectionState_NotConnected );
>>>>>>> d97af3b... add prima wlan driver
=======
   hdd_connSetConnectionState( pHddStaCtx, eConnectionState_NotConnected );  
>>>>>>> 657b0e9... prima update

   vos_mem_zero( &pHddStaCtx->conn_info.SSID, sizeof( tCsrSSIDInfo ) );
}
/* TODO Revist this function. and data path */
static VOS_STATUS hdd_roamDeregisterSTA( hdd_adapter_t *pAdapter, tANI_U8 staId )
{
    VOS_STATUS vosStatus;
    hdd_disconnect_tx_rx(pAdapter);
    vosStatus = WLANTL_ClearSTAClient( (WLAN_HDD_GET_CTX(pAdapter))->pvosContext, staId );
    if ( !VOS_IS_STATUS_SUCCESS( vosStatus ) )
    {
<<<<<<< HEAD
<<<<<<< HEAD
        VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_WARN,
                   "%s: WLANTL_ClearSTAClient() failed to for staID %d.  "
                   "Status= %d [0x%08lX]",
                   __FUNCTION__, staId, vosStatus, vosStatus );
=======
        VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                   "%s: WLANTL_ClearSTAClient() failed to for staID %d.  "
                   "Status= %d [0x%08lX]",
                   __func__, staId, vosStatus, vosStatus );
>>>>>>> d97af3b... add prima wlan driver
=======
        VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_WARN,
                   "%s: WLANTL_ClearSTAClient() failed to for staID %d.  "
                   "Status= %d [0x%08lX]",
                   __FUNCTION__, staId, vosStatus, vosStatus );
>>>>>>> 657b0e9... prima update
    }
    return( vosStatus );
}


static eHalStatus hdd_DisConnectHandler( hdd_adapter_t *pAdapter, tCsrRoamInfo *pRoamInfo,
                                            tANI_U32 roamId, eRoamCmdStatus roamStatus,
                                            eCsrRoamResult roamResult )
{
    eHalStatus status = eHAL_STATUS_SUCCESS;
    VOS_STATUS vstatus;
    struct net_device *dev = pAdapter->dev;
    hdd_context_t *pHddCtx = WLAN_HDD_GET_CTX(pAdapter);
    hdd_station_ctx_t *pHddStaCtx = WLAN_HDD_GET_STATION_CTX_PTR(pAdapter);

    // Sanity check
    if(dev == NULL)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        hddLog(VOS_TRACE_LEVEL_INFO_HIGH, 
=======
        hddLog(VOS_TRACE_LEVEL_INFO_HIGH,
>>>>>>> d97af3b... add prima wlan driver
=======
        hddLog(VOS_TRACE_LEVEL_INFO_HIGH, 
>>>>>>> 657b0e9... prima update
          "%s: net_dev is released return", __func__);
        return eHAL_STATUS_FAILURE;
    }

    // notify apps that we can't pass traffic anymore
    netif_tx_disable(dev);
    netif_carrier_off(dev);
<<<<<<< HEAD
<<<<<<< HEAD
    
=======

>>>>>>> d97af3b... add prima wlan driver
=======
    
>>>>>>> 657b0e9... prima update
    INIT_COMPLETION(pAdapter->disconnect_comp_var);
    hdd_connSetConnectionState( pHddStaCtx, eConnectionState_Disconnecting );
    /* If only STA mode is on */
    if((pHddCtx->concurrency_mode <= 1) && (pHddCtx->no_of_sessions[WLAN_HDD_INFRA_STATION] <=1))
    {
        pHddCtx->isAmpAllowed = VOS_TRUE;
    }
    hdd_clearRoamProfileIe( pAdapter );

    // indicate 'disconnect' status to wpa_supplicant...
    hdd_SendAssociationEvent(dev,pRoamInfo);
<<<<<<< HEAD
<<<<<<< HEAD
#ifdef CONFIG_CFG80211
=======
>>>>>>> d97af3b... add prima wlan driver
=======
#ifdef CONFIG_CFG80211
>>>>>>> 657b0e9... prima update
    /* indicate disconnected event to nl80211 */
    if(roamStatus != eCSR_ROAM_IBSS_LEAVE)
    {
        /*During the WLAN uninitialization,supplicant is stopped before the
            driver so not sending the status of the connection to supplicant*/
        if(pHddCtx->isLoadUnloadInProgress != TRUE)
        {
<<<<<<< HEAD
<<<<<<< HEAD
            hddLog(VOS_TRACE_LEVEL_INFO_HIGH, 
                    "%s: sent disconnected event to nl80211", 
                    __func__);
=======
            hddLog(VOS_TRACE_LEVEL_INFO_HIGH,
                    "%s: sent disconnected event to nl80211",
                    __func__);
#ifdef WLAN_FEATURE_P2P_DEBUG
            if(pAdapter->device_mode == WLAN_HDD_P2P_CLIENT)
            {
                if(globalP2PConnectionStatus == P2P_CLIENT_CONNECTED_STATE_1)
                {
                    globalP2PConnectionStatus = P2P_CLIENT_DISCONNECTED_STATE;
                    hddLog(VOS_TRACE_LEVEL_ERROR,"[P2P State] 8 way Handshake completed "
                          "and moved to disconnected state");
                }
                else if(globalP2PConnectionStatus == P2P_CLIENT_COMPLETED_STATE)
                {
                    globalP2PConnectionStatus = P2P_NOT_ACTIVE;
                    hddLog(VOS_TRACE_LEVEL_ERROR,"[P2P State] P2P Client is removed "
                          "and moved to inactive state");
                }
            }
#endif

>>>>>>> d97af3b... add prima wlan driver
=======
            hddLog(VOS_TRACE_LEVEL_INFO_HIGH, 
                    "%s: sent disconnected event to nl80211", 
                    __func__);
>>>>>>> 657b0e9... prima update
            /* To avoid wpa_supplicant sending "HANGED" CMD to ICS UI */
            if( eCSR_ROAM_LOSTLINK == roamStatus )
            {
                cfg80211_disconnected(dev, pRoamInfo->reasonCode, NULL, 0, GFP_KERNEL);
            }
            else
            {
<<<<<<< HEAD
<<<<<<< HEAD
                cfg80211_disconnected(dev, WLAN_REASON_UNSPECIFIED, NULL, 0, GFP_KERNEL); 
=======
                cfg80211_disconnected(dev, WLAN_REASON_UNSPECIFIED, NULL, 0, GFP_KERNEL);
>>>>>>> d97af3b... add prima wlan driver
=======
                cfg80211_disconnected(dev, WLAN_REASON_UNSPECIFIED, NULL, 0, GFP_KERNEL); 
>>>>>>> 657b0e9... prima update
            }

            //If the Device Mode is Station
            // and the P2P Client is Connected
            //Enable BMPS

            // In case of JB, as Change-Iface may or maynot be called for p2p0
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
            // Enable BMPS/IMPS in case P2P_CLIENT disconnected   
            if(((WLAN_HDD_INFRA_STATION == pAdapter->device_mode) ||
                (WLAN_HDD_P2P_CLIENT == pAdapter->device_mode)) &&
                (vos_concurrent_sessions_running()))
<<<<<<< HEAD
            {
               //Enable BMPS only of other Session is P2P Client
               hdd_context_t *pHddCtx = NULL;
               v_CONTEXT_t pVosContext = vos_get_global_context( VOS_MODULE_ID_HDD, NULL );    
=======
            // Enable BMPS/IMPS in case P2P_CLIENT disconnected
            if(VOS_STATUS_SUCCESS == hdd_issta_p2p_clientconnected(pHddCtx))
            {
               //Enable BMPS only of other Session is P2P Client
               hdd_context_t *pHddCtx = NULL;
               v_CONTEXT_t pVosContext = vos_get_global_context( VOS_MODULE_ID_HDD, NULL );
>>>>>>> d97af3b... add prima wlan driver
=======
            {
               //Enable BMPS only of other Session is P2P Client
               hdd_context_t *pHddCtx = NULL;
               v_CONTEXT_t pVosContext = vos_get_global_context( VOS_MODULE_ID_HDD, NULL );    
>>>>>>> 657b0e9... prima update

               if (NULL != pVosContext)
               {
                   pHddCtx = vos_get_context( VOS_MODULE_ID_HDD, pVosContext);

                   if(NULL != pHddCtx)
                   {
                       //Only P2P Client is there Enable Bmps back
                       if((0 == pHddCtx->no_of_sessions[VOS_STA_SAP_MODE]) &&
                          (0 == pHddCtx->no_of_sessions[VOS_P2P_GO_MODE]))
                       {
<<<<<<< HEAD
<<<<<<< HEAD
                           hdd_enable_bmps_imps(pHddCtx);
                       }
=======
                           if (pHddCtx->hdd_wlan_suspended)
                           {
                               hdd_set_pwrparams(pHddCtx);
                           }
                           hdd_enable_bmps_imps(pHddCtx);
                      }
>>>>>>> d97af3b... add prima wlan driver
=======
                           hdd_enable_bmps_imps(pHddCtx);
                       }
>>>>>>> 657b0e9... prima update
                   }
               }
            }
        }
    }
<<<<<<< HEAD
<<<<<<< HEAD
#endif
    

=======

     hdd_wmm_adapter_clear(pAdapter);
>>>>>>> d97af3b... add prima wlan driver
=======
#endif
    

>>>>>>> 657b0e9... prima update
    //We should clear all sta register with TL, for now, only one.
    vstatus = hdd_roamDeregisterSTA( pAdapter, pHddStaCtx->conn_info.staId [0] );
    if ( !VOS_IS_STATUS_SUCCESS(vstatus ) )
    {
<<<<<<< HEAD
<<<<<<< HEAD
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_WARN,
=======
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
>>>>>>> d97af3b... add prima wlan driver
=======
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_WARN,
>>>>>>> 657b0e9... prima update
                  "hdd_roamDeregisterSTA() failed to for staID %d.  "
                  "Status= %d [0x%x]",
                    pHddStaCtx->conn_info.staId[0], status, status );

        status = eHAL_STATUS_FAILURE;
    }

    pHddCtx->sta_to_adapter[pHddStaCtx->conn_info.staId[0]] = NULL;
    // Clear saved connection information in HDD
    hdd_connRemoveConnectInfo( pHddStaCtx );
<<<<<<< HEAD
<<<<<<< HEAD
=======
#ifdef WLAN_FEATURE_GTK_OFFLOAD
    if ((WLAN_HDD_INFRA_STATION == pAdapter->device_mode) ||
        (WLAN_HDD_P2P_CLIENT == pAdapter->device_mode))
    {
        memset(&pHddStaCtx->gtkOffloadReqParams, 0,
              sizeof (tSirGtkOffloadParams));
        pHddStaCtx->gtkOffloadReqParams.ulFlags = GTK_OFFLOAD_DISABLE;
    }
#endif

#ifdef FEATURE_WLAN_TDLS
    wlan_hdd_tdls_disconnection_callback(pAdapter);
#endif
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update

    //Unblock anyone waiting for disconnect to complete
    complete(&pAdapter->disconnect_comp_var);
    return( status );
}
static VOS_STATUS hdd_roamRegisterSTA( hdd_adapter_t *pAdapter,
                                       tCsrRoamInfo *pRoamInfo,
                                       v_U8_t staId,
                                       v_MACADDR_t *pPeerMacAddress,
                                       tSirBssDescription *pBssDesc )
{
   VOS_STATUS vosStatus = VOS_STATUS_E_FAILURE;
   WLAN_STADescType staDesc = {0};
   eCsrEncryptionType connectedCipherAlgo;
   v_BOOL_t  fConnected;
   hdd_station_ctx_t *pHddStaCtx = WLAN_HDD_GET_STATION_CTX_PTR(pAdapter);
   hdd_context_t *pHddCtx = WLAN_HDD_GET_CTX(pAdapter);
<<<<<<< HEAD
<<<<<<< HEAD
   
=======
   hdd_config_t *cfg_param = pHddCtx->cfg_ini;

   if ( NULL == pBssDesc)
   {
       return VOS_STATUS_E_FAILURE;
   }
>>>>>>> d97af3b... add prima wlan driver
=======
   
>>>>>>> 657b0e9... prima update
   // Get the Station ID from the one saved during the assocation.
   staDesc.ucSTAId = staId;

   if ( pHddStaCtx->conn_info.connDot11DesiredBssType == eMib_dot11DesiredBssType_infrastructure)
<<<<<<< HEAD
<<<<<<< HEAD
   { 
      staDesc.wSTAType = WLAN_STA_INFRA;
      
      // grab the bssid from the connection info in the adapter structure and hand that 
      // over to TL when registering. 
      vos_mem_copy( staDesc.vSTAMACAddress.bytes, pHddStaCtx->conn_info.bssId,sizeof(pHddStaCtx->conn_info.bssId) ); 
   }
   else 
   {
      // for an IBSS 'connect', setup the Station Descriptor for TL.   
      staDesc.wSTAType = WLAN_STA_IBSS;
      
=======
   {
=======
   { 
>>>>>>> 657b0e9... prima update
      staDesc.wSTAType = WLAN_STA_INFRA;
      
      // grab the bssid from the connection info in the adapter structure and hand that 
      // over to TL when registering. 
      vos_mem_copy( staDesc.vSTAMACAddress.bytes, pHddStaCtx->conn_info.bssId,sizeof(pHddStaCtx->conn_info.bssId) ); 
   }
   else 
   {
      // for an IBSS 'connect', setup the Station Descriptor for TL.   
      staDesc.wSTAType = WLAN_STA_IBSS;
<<<<<<< HEAD

>>>>>>> d97af3b... add prima wlan driver
=======
      
>>>>>>> 657b0e9... prima update
      // Note that for IBSS, the STA MAC address and BSSID are goign to be different where
      // in infrastructure, they are the same (BSSID is the MAC address of the AP).  So,
      // for IBSS we have a second field to pass to TL in the STA descriptor that we don't
      // pass when making an Infrastructure connection.
      vos_mem_copy( staDesc.vSTAMACAddress.bytes, pPeerMacAddress->bytes,sizeof(pPeerMacAddress->bytes) );
      vos_mem_copy( staDesc.vBSSIDforIBSS.bytes, pHddStaCtx->conn_info.bssId,6 );
   }
<<<<<<< HEAD
<<<<<<< HEAD
      
=======

>>>>>>> d97af3b... add prima wlan driver
=======
      
>>>>>>> 657b0e9... prima update
   vos_copy_macaddr( &staDesc.vSelfMACAddress, &pAdapter->macAddressCurrent );

   // set the QoS field appropriately
   if (hdd_wmm_is_active(pAdapter))
   {
      staDesc.ucQosEnabled = 1;
   }
   else
   {
      staDesc.ucQosEnabled = 0;
   }

   fConnected = hdd_connGetConnectedCipherAlgo( pHddStaCtx, &connectedCipherAlgo );
   if ( connectedCipherAlgo != eCSR_ENCRYPT_TYPE_NONE )
   {
      staDesc.ucProtectedFrame = 1;
   }
   else
   {
      staDesc.ucProtectedFrame = 0;

   }

#ifdef FEATURE_WLAN_CCX
   staDesc.ucIsCcxSta = pRoamInfo->isCCXAssoc;
#endif //FEATURE_WLAN_CCX

#ifdef VOLANS_ENABLE_SW_REPLAY_CHECK
   /* check whether replay check is valid for the station or not */
   if( (eCSR_ENCRYPT_TYPE_TKIP == connectedCipherAlgo) || (eCSR_ENCRYPT_TYPE_AES == connectedCipherAlgo))
   {
       /* Encryption mode is either TKIP or AES
          and replay check is valid for only these
          two encryption modes */
       staDesc.ucIsReplayCheckValid = VOS_TRUE;
       VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO,
                 "HDD register TL ucIsReplayCheckValid %d: Replay check is needed for station", staDesc.ucIsReplayCheckValid);
   }
<<<<<<< HEAD
<<<<<<< HEAD
  
   else
   {
      /* For other encryption modes replay check is 
         not needed */
        staDesc.ucIsReplayCheckValid = VOS_FALSE; 
=======

=======
  
>>>>>>> 657b0e9... prima update
   else
   {
      /* For other encryption modes replay check is 
         not needed */
<<<<<<< HEAD
        staDesc.ucIsReplayCheckValid = VOS_FALSE;
>>>>>>> d97af3b... add prima wlan driver
=======
        staDesc.ucIsReplayCheckValid = VOS_FALSE; 
>>>>>>> 657b0e9... prima update
        VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO,
                 "HDD register TL ucIsReplayCheckValid %d", staDesc.ucIsReplayCheckValid);
   }
#endif

#ifdef FEATURE_WLAN_WAPI
<<<<<<< HEAD
<<<<<<< HEAD
   hddLog(LOG1, "%s: WAPI STA Registered: %d", __FUNCTION__, pAdapter->wapi_info.fIsWapiSta);
=======
   hddLog(LOG1, "%s: WAPI STA Registered: %d", __func__, pAdapter->wapi_info.fIsWapiSta);
>>>>>>> d97af3b... add prima wlan driver
=======
   hddLog(LOG1, "%s: WAPI STA Registered: %d", __FUNCTION__, pAdapter->wapi_info.fIsWapiSta);
>>>>>>> 657b0e9... prima update
   if (pAdapter->wapi_info.fIsWapiSta)
   {
      staDesc.ucIsWapiSta = 1;
   }
   else
   {
      staDesc.ucIsWapiSta = 0;
   }
#endif /* FEATURE_WLAN_WAPI */

   VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_MED,
                 "HDD register TL Sec_enabled= %d.", staDesc.ucProtectedFrame );

<<<<<<< HEAD
<<<<<<< HEAD
#ifdef FEATURE_WLAN_INTEGRATED_SOC
   // UMA is Not ready yet, Xlation will be done by TL
   staDesc.ucSwFrameTXXlation = 1;
#else
   /* Enable UMA for TX translation only when there is no concurrent session active */
   if (vos_concurrent_sessions_running())
   {
      staDesc.ucSwFrameTXXlation = 1;
   }
   else
   {
      staDesc.ucSwFrameTXXlation = 0;
   }
#endif
   staDesc.ucSwFrameRXXlation = 1;
   staDesc.ucAddRmvLLC = 1;
   VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "HDD register TL QoS_enabled=%d", 
=======
=======
#ifdef FEATURE_WLAN_INTEGRATED_SOC
>>>>>>> 657b0e9... prima update
   // UMA is Not ready yet, Xlation will be done by TL
   staDesc.ucSwFrameTXXlation = 1;
#else
   /* Enable UMA for TX translation only when there is no concurrent session active */
   if (vos_concurrent_sessions_running())
   {
      staDesc.ucSwFrameTXXlation = 1;
   }
   else
   {
      staDesc.ucSwFrameTXXlation = 0;
   }
#endif
   staDesc.ucSwFrameRXXlation = 1;
   staDesc.ucAddRmvLLC = 1;
<<<<<<< HEAD
   VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "HDD register TL QoS_enabled=%d",
>>>>>>> d97af3b... add prima wlan driver
=======
   VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "HDD register TL QoS_enabled=%d", 
>>>>>>> 657b0e9... prima update
              staDesc.ucQosEnabled );
   // Initialize signatures and state
   staDesc.ucUcastSig  = pRoamInfo->ucastSig;
   staDesc.ucBcastSig  = pRoamInfo->bcastSig;
   staDesc.ucInitState = pRoamInfo->fAuthRequired ?
      WLANTL_STA_CONNECTED : WLANTL_STA_AUTHENTICATED;
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
   // Register the Station with TL...      
   vosStatus = WLANTL_RegisterSTAClient( pHddCtx->pvosContext, 
                                         hdd_rx_packet_cbk, 
                                         hdd_tx_complete_cbk, 
<<<<<<< HEAD
                                         hdd_tx_fetch_packet_cbk, &staDesc,
                                         pBssDesc->rssi );
   
   if ( !VOS_IS_STATUS_SUCCESS( vosStatus ) )
   {
      VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_WARN, 
                 "WLANTL_RegisterSTAClient() failed to register.  Status= %d [0x%08lX]",
                 vosStatus, vosStatus );
      return vosStatus;      
   }                                            

   // if ( WPA ), tell TL to go to 'connected' and after keys come to the driver, 
   // then go to 'authenticated'.  For all other authentication types (those that do 
   // not require upper layer authentication) we can put TL directly into 'authenticated'
   // state.
   
   VOS_ASSERT( fConnected );
  
   if ( !pRoamInfo->fAuthRequired )
   {
      VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_MED,
                 "open/shared auth StaId= %d.  Changing TL state to AUTHENTICATED at Join time", pHddStaCtx->conn_info.staId[ 0 ] );
   
      // Connections that do not need Upper layer auth, transition TL directly
      // to 'Authenticated' state.      
      vosStatus = WLANTL_ChangeSTAState( pHddCtx->pvosContext, staDesc.ucSTAId, 
                                         WLANTL_STA_AUTHENTICATED );
  
      pHddStaCtx->conn_info.uIsAuthenticated = VOS_TRUE;
   }                                            
   else
   {
      VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_MED,
                 "ULA auth StaId= %d.  Changing TL state to CONNECTED at Join time", pHddStaCtx->conn_info.staId[ 0 ] );
   
      vosStatus = WLANTL_ChangeSTAState( pHddCtx->pvosContext, staDesc.ucSTAId, 
                                         WLANTL_STA_CONNECTED );

      pHddStaCtx->conn_info.uIsAuthenticated = VOS_FALSE;
   }      
   return( vosStatus );
}

#if  defined (FEATURE_WLAN_CCX) || defined(FEATURE_WLAN_LFR)
=======
   // Register the Station with TL...
   VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "%s: HDD register TL ucInitState=%d", __func__, staDesc.ucInitState );
   vosStatus = WLANTL_RegisterSTAClient( pHddCtx->pvosContext,
                                         hdd_rx_packet_cbk,
                                         hdd_tx_complete_cbk,
=======
>>>>>>> 657b0e9... prima update
                                         hdd_tx_fetch_packet_cbk, &staDesc,
                                         pBssDesc->rssi );
   
   if ( !VOS_IS_STATUS_SUCCESS( vosStatus ) )
   {
      VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_WARN, 
                 "WLANTL_RegisterSTAClient() failed to register.  Status= %d [0x%08lX]",
                 vosStatus, vosStatus );
      return vosStatus;      
   }                                            

   // if ( WPA ), tell TL to go to 'connected' and after keys come to the driver, 
   // then go to 'authenticated'.  For all other authentication types (those that do 
   // not require upper layer authentication) we can put TL directly into 'authenticated'
   // state.
   
   VOS_ASSERT( fConnected );
  
   if ( !pRoamInfo->fAuthRequired )
   {
      VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_MED,
                 "open/shared auth StaId= %d.  Changing TL state to AUTHENTICATED at Join time", pHddStaCtx->conn_info.staId[ 0 ] );
   
      // Connections that do not need Upper layer auth, transition TL directly
      // to 'Authenticated' state.      
      vosStatus = WLANTL_ChangeSTAState( pHddCtx->pvosContext, staDesc.ucSTAId, 
                                         WLANTL_STA_AUTHENTICATED );
  
      pHddStaCtx->conn_info.uIsAuthenticated = VOS_TRUE;
   }                                            
   else
   {
      VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_MED,
                 "ULA auth StaId= %d.  Changing TL state to CONNECTED at Join time", pHddStaCtx->conn_info.staId[ 0 ] );
   
      vosStatus = WLANTL_ChangeSTAState( pHddCtx->pvosContext, staDesc.ucSTAId, 
                                         WLANTL_STA_CONNECTED );

      pHddStaCtx->conn_info.uIsAuthenticated = VOS_FALSE;
   }      
   return( vosStatus );
}

<<<<<<< HEAD
>>>>>>> d97af3b... add prima wlan driver
=======
#if  defined (FEATURE_WLAN_CCX) || defined(FEATURE_WLAN_LFR)
>>>>>>> 657b0e9... prima update
static void hdd_SendReAssocEvent(struct net_device *dev, hdd_adapter_t *pAdapter,
    tCsrRoamInfo *pCsrRoamInfo, v_U8_t *reqRsnIe, tANI_U32 reqRsnLength)
{
    unsigned int len = 0;
    u8 *pFTAssocRsp = NULL;
    v_U8_t *rspRsnIe = kmalloc(IW_GENERIC_IE_MAX, GFP_KERNEL);
    tANI_U32 rspRsnLength = 0;
    struct ieee80211_channel *chan;

    if (!rspRsnIe)
    {
        hddLog(LOGE, "%s: Unable to allocate RSN IE", __func__);
        return;
    }

    if (pCsrRoamInfo == NULL)
    {
        hddLog(LOGE, "%s: Invalid CSR roam info", __func__);
        goto done;
    }

    if (pCsrRoamInfo->nAssocRspLength == 0)
    {
        hddLog(LOGE, "%s: Invalid assoc response length", __func__);
        goto done;
    }

    pFTAssocRsp = (u8 *)(pCsrRoamInfo->pbFrames + pCsrRoamInfo->nBeaconLength +
                    pCsrRoamInfo->nAssocReqLength);
    if (pFTAssocRsp == NULL)
        goto done;

    //pFTAssocRsp needs to point to the IEs
    pFTAssocRsp += FT_ASSOC_RSP_IES_OFFSET;
    hddLog(LOG1, "%s: AssocRsp is now at %02x%02x\n", __func__,
                    (unsigned int)pFTAssocRsp[0],
                    (unsigned int)pFTAssocRsp[1]);

    // Send the Assoc Resp, the supplicant needs this for initial Auth.
    len = pCsrRoamInfo->nAssocRspLength - FT_ASSOC_RSP_IES_OFFSET;
    rspRsnLength = len;
    memcpy(rspRsnIe, pFTAssocRsp, len);
    memset(rspRsnIe + len, 0, IW_GENERIC_IE_MAX - len);

    chan = ieee80211_get_channel(pAdapter->wdev.wiphy, (int) pCsrRoamInfo->pBssDesc->channelId);
    cfg80211_roamed(dev,chan,pCsrRoamInfo->bssid,
                    reqRsnIe, reqRsnLength,
                    rspRsnIe, rspRsnLength,GFP_KERNEL);

done:
    kfree(rspRsnIe);
}
<<<<<<< HEAD
<<<<<<< HEAD
#endif /* FEATURE_WLAN_CCX */

static eHalStatus hdd_AssociationCompletionHandler( hdd_adapter_t *pAdapter, tCsrRoamInfo *pRoamInfo, 
                                                    tANI_U32 roamId, eRoamCmdStatus roamStatus,                                                
=======

void hdd_PerformRoamSetKeyComplete(hdd_adapter_t *pAdapter)
{
    eHalStatus halStatus = eHAL_STATUS_SUCCESS;
    hdd_station_ctx_t *pHddStaCtx = WLAN_HDD_GET_STATION_CTX_PTR(pAdapter);
    tCsrRoamInfo roamInfo;
    roamInfo.fAuthRequired = FALSE;
    vos_mem_copy(roamInfo.bssid,
                 pHddStaCtx->roam_info.bssid,
                 WNI_CFG_BSSID_LEN);
    vos_mem_copy(roamInfo.peerMac,
                 pHddStaCtx->roam_info.peerMac,
                 WNI_CFG_BSSID_LEN);

    halStatus = hdd_RoamSetKeyCompleteHandler(pAdapter,
                                  &roamInfo,
                                  pHddStaCtx->roam_info.roamId,
                                  pHddStaCtx->roam_info.roamStatus,
                                  eCSR_ROAM_RESULT_AUTHENTICATED);
    if (halStatus != eHAL_STATUS_SUCCESS)
    {
        hddLog(LOGE, "%s: Set Key complete failure", __func__);
    }
    pHddStaCtx->roam_info.deferKeyComplete = FALSE;
}

static eHalStatus hdd_AssociationCompletionHandler( hdd_adapter_t *pAdapter, tCsrRoamInfo *pRoamInfo,
                                                    tANI_U32 roamId, eRoamCmdStatus roamStatus,
>>>>>>> d97af3b... add prima wlan driver
=======
#endif /* FEATURE_WLAN_CCX */

static eHalStatus hdd_AssociationCompletionHandler( hdd_adapter_t *pAdapter, tCsrRoamInfo *pRoamInfo, 
                                                    tANI_U32 roamId, eRoamCmdStatus roamStatus,                                                
>>>>>>> 657b0e9... prima update
                                                    eCsrRoamResult roamResult )
{
    struct net_device *dev = pAdapter->dev;
    hdd_context_t *pHddCtx = WLAN_HDD_GET_CTX(pAdapter);
    hdd_station_ctx_t *pHddStaCtx = WLAN_HDD_GET_STATION_CTX_PTR(pAdapter);
    VOS_STATUS vosStatus;
<<<<<<< HEAD
<<<<<<< HEAD
#if  defined (FEATURE_WLAN_CCX) || defined(FEATURE_WLAN_LFR)
    int ft_carrier_on = FALSE;
#endif
    int status;
 
=======
    v_U8_t reqRsnIe[DOT11F_IE_RSN_MAX_LEN];
    tANI_U32 reqRsnLength = DOT11F_IE_RSN_MAX_LEN;
#if  defined (FEATURE_WLAN_CCX) || defined(FEATURE_WLAN_LFR) || defined (WLAN_FEATURE_VOWIFI_11R)
    int ft_carrier_on = FALSE;
#endif
    int status;

>>>>>>> d97af3b... add prima wlan driver
=======
#if  defined (FEATURE_WLAN_CCX) || defined(FEATURE_WLAN_LFR)
    int ft_carrier_on = FALSE;
#endif
    int status;
 
>>>>>>> 657b0e9... prima update
    if ( eCSR_ROAM_RESULT_ASSOCIATED == roamResult )
    {
        hdd_connSetConnectionState( pHddStaCtx, eConnectionState_Associated );

        // Save the connection info from CSR...
        hdd_connSaveConnectInfo( pAdapter, pRoamInfo, eCSR_BSS_TYPE_INFRASTRUCTURE );
#ifdef FEATURE_WLAN_WAPI
        if ( pRoamInfo->u.pConnectedProfile->AuthType == eCSR_AUTH_TYPE_WAPI_WAI_CERTIFICATE ||
                pRoamInfo->u.pConnectedProfile->AuthType == eCSR_AUTH_TYPE_WAPI_WAI_PSK )
        {
            pAdapter->wapi_info.fIsWapiSta = 1;
        }
        else
        {
            pAdapter->wapi_info.fIsWapiSta = 0;
        }
#endif  /* FEATURE_WLAN_WAPI */

        // indicate 'connect' status to userspace
        hdd_SendAssociationEvent(dev,pRoamInfo);


<<<<<<< HEAD
<<<<<<< HEAD
        // Initialize the Linkup event completion variable 
=======
        // Initialize the Linkup event completion variable
>>>>>>> d97af3b... add prima wlan driver
=======
        // Initialize the Linkup event completion variable 
>>>>>>> 657b0e9... prima update
        INIT_COMPLETION(pAdapter->linkup_event_var);

        /*
           Sometimes Switching ON the Carrier is taking time to activate the device properly. Before allowing any
           packet to go up to the application, device activation has to be ensured for proper queue mapping by the
<<<<<<< HEAD
<<<<<<< HEAD
           kernel. we have registered net device notifier for device change notification. With this we will come to 
=======
           kernel. we have registered net device notifier for device change notification. With this we will come to
>>>>>>> d97af3b... add prima wlan driver
=======
           kernel. we have registered net device notifier for device change notification. With this we will come to 
>>>>>>> 657b0e9... prima update
           know that the device is getting activated properly.
           */
#if  defined (WLAN_FEATURE_VOWIFI_11R) || defined (FEATURE_WLAN_CCX) || defined(FEATURE_WLAN_LFR)
        if (pHddStaCtx->ft_carrier_on == FALSE)
        {
#endif
<<<<<<< HEAD
<<<<<<< HEAD
            // Enable Linkup Event Servicing which allows the net device notifier to set the linkup event variable       
            pAdapter->isLinkUpSvcNeeded = TRUE;

            // Enable Linkup Event Servicing which allows the net device notifier to set the linkup event variable       
=======
            // Enable Linkup Event Servicing which allows the net device notifier to set the linkup event variable
            pAdapter->isLinkUpSvcNeeded = TRUE;

            // Enable Linkup Event Servicing which allows the net device notifier to set the linkup event variable
>>>>>>> d97af3b... add prima wlan driver
=======
            // Enable Linkup Event Servicing which allows the net device notifier to set the linkup event variable       
            pAdapter->isLinkUpSvcNeeded = TRUE;

            // Enable Linkup Event Servicing which allows the net device notifier to set the linkup event variable       
>>>>>>> 657b0e9... prima update
            pAdapter->isLinkUpSvcNeeded = TRUE;

            // Switch on the Carrier to activate the device
            netif_carrier_on(dev);

            // Wait for the Link to up to ensure all the queues are set properly by the kernel
            status = wait_for_completion_interruptible_timeout(&pAdapter->linkup_event_var,
                                                   msecs_to_jiffies(ASSOC_LINKUP_TIMEOUT));
<<<<<<< HEAD
<<<<<<< HEAD
            if(!status) 
=======
            if(!status)
>>>>>>> d97af3b... add prima wlan driver
=======
            if(!status) 
>>>>>>> 657b0e9... prima update
            {
                hddLog(VOS_TRACE_LEVEL_WARN, "%s: Warning:ASSOC_LINKUP_TIMEOUT", __func__);
            }

            // Disable Linkup Event Servicing - no more service required from the net device notifier call
            pAdapter->isLinkUpSvcNeeded = FALSE;
#if  defined (WLAN_FEATURE_VOWIFI_11R) || defined (FEATURE_WLAN_CCX) || defined(FEATURE_WLAN_LFR)
        }
<<<<<<< HEAD
<<<<<<< HEAD
        else { 
            pHddStaCtx->ft_carrier_on = FALSE;
#if  defined (FEATURE_WLAN_CCX) || defined(FEATURE_WLAN_LFR)
            ft_carrier_on = TRUE;
#endif /* FEATURE_WLAN_CCX */
=======
        else {
=======
        else { 
>>>>>>> 657b0e9... prima update
            pHddStaCtx->ft_carrier_on = FALSE;
#if  defined (FEATURE_WLAN_CCX) || defined(FEATURE_WLAN_LFR)
            ft_carrier_on = TRUE;
<<<<<<< HEAD
>>>>>>> d97af3b... add prima wlan driver
=======
#endif /* FEATURE_WLAN_CCX */
>>>>>>> 657b0e9... prima update
        }
#endif
        pHddCtx->sta_to_adapter[pRoamInfo->staId] = pAdapter;

<<<<<<< HEAD
<<<<<<< HEAD
=======
#ifdef FEATURE_WLAN_TDLS
        wlan_hdd_tdls_connection_callback(pAdapter);
#endif
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
        //For reassoc, the station is already registered, all we need is to change the state
        //of the STA in TL.
        //If authentication is required (WPA/WPA2/DWEP), change TL to CONNECTED instead of AUTHENTICATED
        if( !pRoamInfo->fReassocReq )
        {
<<<<<<< HEAD
<<<<<<< HEAD
#ifdef CONFIG_CFG80211
            v_U8_t reqRsnIe[DOT11F_IE_RSN_MAX_LEN];
            v_U8_t rspRsnIe[DOT11F_IE_RSN_MAX_LEN];
            tANI_U32 reqRsnLength = DOT11F_IE_RSN_MAX_LEN;
            tANI_U32 rspRsnLength = DOT11F_IE_RSN_MAX_LEN;
            struct cfg80211_bss *bss;
=======
            struct cfg80211_bss *bss;
#ifdef WLAN_FEATURE_VOWIFI_11R
            u8 *pFTAssocRsp = NULL;
            unsigned int assocRsplen = 0;
            u8 *pFTAssocReq = NULL;
            unsigned int assocReqlen = 0;
            struct ieee80211_channel *chan;
#endif
=======
#ifdef CONFIG_CFG80211
            v_U8_t reqRsnIe[DOT11F_IE_RSN_MAX_LEN];
>>>>>>> 657b0e9... prima update
            v_U8_t rspRsnIe[DOT11F_IE_RSN_MAX_LEN];
            tANI_U32 reqRsnLength = DOT11F_IE_RSN_MAX_LEN;
            tANI_U32 rspRsnLength = DOT11F_IE_RSN_MAX_LEN;
<<<<<<< HEAD
>>>>>>> d97af3b... add prima wlan driver
=======
            struct cfg80211_bss *bss;
>>>>>>> 657b0e9... prima update

            /* add bss_id to cfg80211 data base */
            bss = wlan_hdd_cfg80211_update_bss_db(pAdapter, pRoamInfo);
            if (NULL == bss)
            {
                pr_err("wlan: Not able to create BSS entry\n");
                return eHAL_STATUS_FAILURE;
            }
<<<<<<< HEAD
<<<<<<< HEAD

            /* wpa supplicant expecting WPA/RSN IE in connect result */
            csrRoamGetWpaRsnReqIE(WLAN_HDD_GET_HAL_CTX(pAdapter),
                    pAdapter->sessionId,
                    &reqRsnLength,
                    reqRsnIe);

            csrRoamGetWpaRsnRspIE(WLAN_HDD_GET_HAL_CTX(pAdapter),
                    pAdapter->sessionId,
                    &rspRsnLength,
                    rspRsnIe);
#if  defined (FEATURE_WLAN_CCX) || defined(FEATURE_WLAN_LFR)
            if(ft_carrier_on)
                    hdd_SendReAssocEvent(dev, pAdapter, pRoamInfo, reqRsnIe, reqRsnLength);
            else
#endif /* FEATURE_WLAN_CCX */

            {
            /* inform connect result to nl80211 */
            cfg80211_connect_result(dev, pRoamInfo->bssid, 
                    reqRsnIe, reqRsnLength, 
                    rspRsnIe, rspRsnLength,
                    WLAN_STATUS_SUCCESS, 
                    GFP_KERNEL); 

            cfg80211_put_bss(bss);
            }
#endif

=======
#ifdef WLAN_FEATURE_VOWIFI_11R
            if(pRoamInfo->u.pConnectedProfile->AuthType == eCSR_AUTH_TYPE_FT_RSN ||
                pRoamInfo->u.pConnectedProfile->AuthType == eCSR_AUTH_TYPE_FT_RSN_PSK )
            {

                //Association Response
                pFTAssocRsp = (u8 *)(pRoamInfo->pbFrames + pRoamInfo->nBeaconLength +
                                    pRoamInfo->nAssocReqLength);
                if (pFTAssocRsp != NULL)
                {
                    // pFTAssocRsp needs to point to the IEs
                    pFTAssocRsp += FT_ASSOC_RSP_IES_OFFSET;
                    hddLog(LOG1, "%s: AssocRsp is now at %02x%02x", __func__,
                                        (unsigned int)pFTAssocRsp[0],
                                        (unsigned int)pFTAssocRsp[1]);
                    assocRsplen = pRoamInfo->nAssocRspLength - FT_ASSOC_RSP_IES_OFFSET;
                }
                else
                {
                    hddLog(LOGE, "%s:AssocRsp is NULL", __func__);
                    assocRsplen = 0;
                }
=======
>>>>>>> 657b0e9... prima update

            /* wpa supplicant expecting WPA/RSN IE in connect result */
            csrRoamGetWpaRsnReqIE(WLAN_HDD_GET_HAL_CTX(pAdapter),
                    pAdapter->sessionId,
                    &reqRsnLength,
                    reqRsnIe);

            csrRoamGetWpaRsnRspIE(WLAN_HDD_GET_HAL_CTX(pAdapter),
                    pAdapter->sessionId,
                    &rspRsnLength,
                    rspRsnIe);
#if  defined (FEATURE_WLAN_CCX) || defined(FEATURE_WLAN_LFR)
            if(ft_carrier_on)
                    hdd_SendReAssocEvent(dev, pAdapter, pRoamInfo, reqRsnIe, reqRsnLength);
            else
#endif /* FEATURE_WLAN_CCX */

            {
            /* inform connect result to nl80211 */
            cfg80211_connect_result(dev, pRoamInfo->bssid, 
                    reqRsnIe, reqRsnLength, 
                    rspRsnIe, rspRsnLength,
                    WLAN_STATUS_SUCCESS, 
                    GFP_KERNEL); 

            cfg80211_put_bss(bss);
            }
#endif
<<<<<<< HEAD
                             bss);
>>>>>>> d97af3b... add prima wlan driver
=======

>>>>>>> 657b0e9... prima update
            // Register the Station with TL after associated...
            vosStatus = hdd_roamRegisterSTA( pAdapter,
                    pRoamInfo,
                    pHddStaCtx->conn_info.staId[ 0 ],
                    NULL,
                    pRoamInfo->pBssDesc );
        }
        else
        {
<<<<<<< HEAD
<<<<<<< HEAD
            //Reassoc successfully
            if( pRoamInfo->fAuthRequired )
            {
                vosStatus = WLANTL_ChangeSTAState( pHddCtx->pvosContext, pHddStaCtx->conn_info.staId[ 0 ], 
                        WLANTL_STA_CONNECTED );
=======
            /* wpa supplicant expecting WPA/RSN IE in connect result */
            /*  in case of reassociation also need to indicate it to supplicant */
            csrRoamGetWpaRsnReqIE(WLAN_HDD_GET_HAL_CTX(pAdapter),
                    pAdapter->sessionId,
                    &reqRsnLength,
                    reqRsnIe);

            hdd_SendReAssocEvent(dev, pAdapter, pRoamInfo, reqRsnIe, reqRsnLength);
            //Reassoc successfully
            if( pRoamInfo->fAuthRequired )
            {
                vosStatus = WLANTL_ChangeSTAState( pHddCtx->pvosContext,
                                                   pHddStaCtx->conn_info.staId[ 0 ],
                                                   WLANTL_STA_CONNECTED );
>>>>>>> d97af3b... add prima wlan driver
=======
            //Reassoc successfully
            if( pRoamInfo->fAuthRequired )
            {
                vosStatus = WLANTL_ChangeSTAState( pHddCtx->pvosContext, pHddStaCtx->conn_info.staId[ 0 ], 
                        WLANTL_STA_CONNECTED );
>>>>>>> 657b0e9... prima update
                pHddStaCtx->conn_info.uIsAuthenticated = VOS_FALSE;
            }
            else
            {
<<<<<<< HEAD
<<<<<<< HEAD
                vosStatus = WLANTL_ChangeSTAState( pHddCtx->pvosContext, pHddStaCtx->conn_info.staId[ 0 ], 
                        WLANTL_STA_AUTHENTICATED );
=======
                VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH,
                          "%s: staId: %d Changing TL state to AUTHENTICATED",
                          __func__, pHddStaCtx->conn_info.staId[ 0 ] );
                vosStatus = WLANTL_ChangeSTAState( pHddCtx->pvosContext,
                                                   pHddStaCtx->conn_info.staId[ 0 ],
                                                   WLANTL_STA_AUTHENTICATED );
>>>>>>> d97af3b... add prima wlan driver
=======
                vosStatus = WLANTL_ChangeSTAState( pHddCtx->pvosContext, pHddStaCtx->conn_info.staId[ 0 ], 
                        WLANTL_STA_AUTHENTICATED );
>>>>>>> 657b0e9... prima update
                pHddStaCtx->conn_info.uIsAuthenticated = VOS_TRUE;
            }
        }

        if ( VOS_IS_STATUS_SUCCESS( vosStatus ) )
        {
            // perform any WMM-related association processing
            hdd_wmm_assoc(pAdapter, pRoamInfo, eCSR_BSS_TYPE_INFRASTRUCTURE);
        }
        else
        {
            VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_WARN,
                    "Cannot register STA with TL.  Failed with vosStatus = %d [%08lX]",
                    vosStatus, vosStatus );
        }
<<<<<<< HEAD
<<<<<<< HEAD

        // Start the Queue
        netif_tx_wake_all_queues(dev);
    }  
    else 
=======
#ifdef WLAN_FEATURE_11W
        vos_mem_zero( &pAdapter->hdd_stats.hddPmfStats,
                      sizeof(pAdapter->hdd_stats.hddPmfStats) );
#endif
        // Start the Queue
        netif_tx_wake_all_queues(dev);
    }
    else
>>>>>>> d97af3b... add prima wlan driver
=======

        // Start the Queue
        netif_tx_wake_all_queues(dev);
    }  
    else 
>>>>>>> 657b0e9... prima update
    {
        hdd_context_t* pHddCtx = (hdd_context_t*)pAdapter->pHddCtx;

        hdd_wext_state_t *pWextState = WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter);
<<<<<<< HEAD
<<<<<<< HEAD
        pr_info("wlan: connection failed with %02x:%02x:%02x:%02x:%02x:%02x"
=======
        if (pRoamInfo)
            pr_info("wlan: connection failed with %02x:%02x:%02x:%02x:%02x:%02x"
                " reason:%d and Status:%d\n", pRoamInfo->bssid[0],
                pRoamInfo->bssid[1], pRoamInfo->bssid[2],
                pRoamInfo->bssid[3], pRoamInfo->bssid[4],
                pRoamInfo->bssid[5], roamResult, roamStatus);
        else
            pr_info("wlan: connection failed with %02x:%02x:%02x:%02x:%02x:%02x"
>>>>>>> d97af3b... add prima wlan driver
=======
        pr_info("wlan: connection failed with %02x:%02x:%02x:%02x:%02x:%02x"
>>>>>>> 657b0e9... prima update
                " reason:%d and Status:%d\n", pWextState->req_bssId[0],
                pWextState->req_bssId[1], pWextState->req_bssId[2],
                pWextState->req_bssId[3], pWextState->req_bssId[4],
                pWextState->req_bssId[5], roamResult, roamStatus);

        /*Handle all failure conditions*/
        hdd_connSetConnectionState( pHddStaCtx, eConnectionState_NotConnected);
        if((pHddCtx->concurrency_mode <= 1) && (pHddCtx->no_of_sessions[WLAN_HDD_INFRA_STATION] <=1))
        {
            pHddCtx->isAmpAllowed = VOS_TRUE;
        }

        //If the Device Mode is Station
        // and the P2P Client is Connected
        //Enable BMPS

        // In case of JB, as Change-Iface may or maynot be called for p2p0
<<<<<<< HEAD
<<<<<<< HEAD
        // Enable BMPS/IMPS in case P2P_CLIENT disconnected   
=======
        // Enable BMPS/IMPS in case P2P_CLIENT disconnected
>>>>>>> d97af3b... add prima wlan driver
=======
        // Enable BMPS/IMPS in case P2P_CLIENT disconnected   
>>>>>>> 657b0e9... prima update
        if(((WLAN_HDD_INFRA_STATION == pAdapter->device_mode) ||
            (WLAN_HDD_P2P_CLIENT == pAdapter->device_mode)) &&
            (vos_concurrent_sessions_running()))
        {
           //Enable BMPS only of other Session is P2P Client
           hdd_context_t *pHddCtx = NULL;
           v_CONTEXT_t pVosContext = vos_get_global_context( VOS_MODULE_ID_HDD, NULL );

           if (NULL != pVosContext)
           {
               pHddCtx = vos_get_context( VOS_MODULE_ID_HDD, pVosContext);

               if(NULL != pHddCtx)
               {
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
                   //Only P2P Client is there Enable Bmps back
                   if((0 == pHddCtx->no_of_sessions[VOS_STA_SAP_MODE]) &&
                      (0 == pHddCtx->no_of_sessions[VOS_P2P_GO_MODE]))
                   {
                       hdd_enable_bmps_imps(pHddCtx);
                   }
<<<<<<< HEAD
=======
                    //Only P2P Client is there Enable Bmps back
                    if((0 == pHddCtx->no_of_sessions[VOS_STA_SAP_MODE]) &&
                       (0 == pHddCtx->no_of_sessions[VOS_P2P_GO_MODE]))
                    {
                         if (pHddCtx->hdd_wlan_suspended)
                         {
                             hdd_set_pwrparams(pHddCtx);
                         }
                         hdd_enable_bmps_imps(pHddCtx);
                    }
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
               }
           }
        }

<<<<<<< HEAD
<<<<<<< HEAD
#ifdef CONFIG_CFG80211
        /* inform association failure event to nl80211 */
        if(eCSR_ROAM_RESULT_ASSOC_FAIL_CON_CHANNEL == roamResult)
        {
           cfg80211_connect_result(dev, pWextState->req_bssId,
                NULL, 0, NULL, 0,
                WLAN_STATUS_ASSOC_DENIED_UNSPEC, 
                GFP_KERNEL);
        }
        else
        {
           cfg80211_connect_result(dev, pWextState->req_bssId,
                NULL, 0, NULL, 0,
                WLAN_STATUS_UNSPECIFIED_FAILURE, 
                GFP_KERNEL);
        }
#endif 
=======
        /* CR465478: Only send up a connection failure result when CSR has
         * completed operation - with a ASSOCIATION_FAILURE status. */
        if ( eCSR_ROAM_ASSOCIATION_FAILURE == roamStatus )
=======
#ifdef CONFIG_CFG80211
        /* inform association failure event to nl80211 */
        if(eCSR_ROAM_RESULT_ASSOC_FAIL_CON_CHANNEL == roamResult)
>>>>>>> 657b0e9... prima update
        {
           cfg80211_connect_result(dev, pWextState->req_bssId,
                NULL, 0, NULL, 0,
                WLAN_STATUS_ASSOC_DENIED_UNSPEC, 
                GFP_KERNEL);
        }
<<<<<<< HEAD
>>>>>>> d97af3b... add prima wlan driver
=======
        else
        {
           cfg80211_connect_result(dev, pWextState->req_bssId,
                NULL, 0, NULL, 0,
                WLAN_STATUS_UNSPECIFIED_FAILURE, 
                GFP_KERNEL);
        }
#endif 
>>>>>>> 657b0e9... prima update

        /*Clear the roam profile*/
        hdd_clearRoamProfileIe( pAdapter );

        netif_tx_disable(dev);
        netif_carrier_off(dev);
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
        
        if (WLAN_HDD_P2P_CLIENT != pAdapter->device_mode)
        {
            /* Association failed; Reset the country code information
             * so that it re-initialize the valid channel list*/
            hdd_ResetCountryCodeAfterDisAssoc(pAdapter);
        }
<<<<<<< HEAD
=======

>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
    }

    return eHAL_STATUS_SUCCESS;
}

/**============================================================================
 *
<<<<<<< HEAD
<<<<<<< HEAD
  @brief roamRoamIbssIndicationHandler() - Here we update the status of the 
  Ibss when we receive information that we have started/joined an ibss session
  We always return SUCCESS.
  
  ===========================================================================*/
static eHalStatus roamRoamIbssIndicationHandler( hdd_adapter_t *pAdapter, tCsrRoamInfo *pRoamInfo, 
   tANI_U32 roamId, eRoamCmdStatus roamStatus,                                                
   eCsrRoamResult roamResult )
{
=======
  @brief hdd_RoamIbssIndicationHandler() - Here we update the status of the
=======
  @brief roamRoamIbssIndicationHandler() - Here we update the status of the 
>>>>>>> 657b0e9... prima update
  Ibss when we receive information that we have started/joined an ibss session
  We always return SUCCESS.
  
  ===========================================================================*/
static eHalStatus roamRoamIbssIndicationHandler( hdd_adapter_t *pAdapter, tCsrRoamInfo *pRoamInfo, 
   tANI_U32 roamId, eRoamCmdStatus roamStatus,                                                
   eCsrRoamResult roamResult )
{
<<<<<<< HEAD
   hddLog(VOS_TRACE_LEVEL_INFO, "%s: %s: id %d, status %d, result %d",
          __func__, pAdapter->dev->name, roamId, roamStatus, roamResult);

>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
   switch( roamResult )
   {
      // both IBSS Started and IBSS Join should come in here.
      case eCSR_ROAM_RESULT_IBSS_STARTED:
      case eCSR_ROAM_RESULT_IBSS_JOIN_SUCCESS:
<<<<<<< HEAD
<<<<<<< HEAD
      {
         // we should have a pRoamInfo on this callback...
         VOS_ASSERT( pRoamInfo );
        
         // When IBSS Started comes from CSR, we need to move connection state to 
         // IBSS Disconnected (meaning no peers are in the IBSS).
         hdd_connSetConnectionState( WLAN_HDD_GET_STATION_CTX_PTR(pAdapter), eConnectionState_IbssDisconnected );

         break;
      }
      
      case eCSR_ROAM_RESULT_IBSS_START_FAILED:
      {
         VOS_ASSERT( pRoamInfo );
         
         break;
      }
      
      default:
         break;
   }   
   
    return( eHAL_STATUS_SUCCESS );
=======
      case eCSR_ROAM_RESULT_IBSS_COALESCED:
=======
>>>>>>> 657b0e9... prima update
      {
         // we should have a pRoamInfo on this callback...
         VOS_ASSERT( pRoamInfo );
        
         // When IBSS Started comes from CSR, we need to move connection state to 
         // IBSS Disconnected (meaning no peers are in the IBSS).
         hdd_connSetConnectionState( WLAN_HDD_GET_STATION_CTX_PTR(pAdapter), eConnectionState_IbssDisconnected );

         break;
      }
      
      case eCSR_ROAM_RESULT_IBSS_START_FAILED:
      {
         VOS_ASSERT( pRoamInfo );
         
         break;
      }
      
      default:
         break;
<<<<<<< HEAD
   }

   return;
>>>>>>> d97af3b... add prima wlan driver
=======
   }   
   
    return( eHAL_STATUS_SUCCESS );
>>>>>>> 657b0e9... prima update
}

/**============================================================================
 *
  @brief roamSaveIbssStation() - Save the IBSS peer MAC address in the adapter.
  This information is passed to iwconfig later. The peer that joined
  last is passed as information to iwconfig.
<<<<<<< HEAD
<<<<<<< HEAD
  If we add HDD_MAX_NUM_IBSS_STA or less STA we return success else we 
  return FALSE.
  
=======
  If we add HDD_MAX_NUM_IBSS_STA or less STA we return success else we
  return FALSE.

>>>>>>> d97af3b... add prima wlan driver
=======
  If we add HDD_MAX_NUM_IBSS_STA or less STA we return success else we 
  return FALSE.
  
>>>>>>> 657b0e9... prima update
  ===========================================================================*/
static int roamSaveIbssStation( hdd_station_ctx_t *pHddStaCtx, v_U8_t staId, v_MACADDR_t *peerMacAddress )
{
   int fSuccess = FALSE;
   int idx = 0;
<<<<<<< HEAD
<<<<<<< HEAD
   
=======

>>>>>>> d97af3b... add prima wlan driver
=======
   
>>>>>>> 657b0e9... prima update
   for ( idx = 0; idx < HDD_MAX_NUM_IBSS_STA; idx++ )
   {
      if ( 0 == pHddStaCtx->conn_info.staId[ idx ] )
      {
         pHddStaCtx->conn_info.staId[ idx ] = staId;
<<<<<<< HEAD
<<<<<<< HEAD
      
         vos_copy_macaddr( &pHddStaCtx->conn_info.peerMacAddress[ idx ], peerMacAddress );
         
=======

         vos_copy_macaddr( &pHddStaCtx->conn_info.peerMacAddress[ idx ], peerMacAddress );

>>>>>>> d97af3b... add prima wlan driver
=======
      
         vos_copy_macaddr( &pHddStaCtx->conn_info.peerMacAddress[ idx ], peerMacAddress );
         
>>>>>>> 657b0e9... prima update
         fSuccess = TRUE;
         break;
      }
   }
<<<<<<< HEAD
<<<<<<< HEAD
   
   return( fSuccess );   
=======

   return( fSuccess );
>>>>>>> d97af3b... add prima wlan driver
=======
   
   return( fSuccess );   
>>>>>>> 657b0e9... prima update
}
/**============================================================================
 *
  @brief roamRemoveIbssStation() - Remove the IBSS peer MAC address in the adapter.
<<<<<<< HEAD
<<<<<<< HEAD
  If we remove HDD_MAX_NUM_IBSS_STA or less STA we return success else we 
  return FALSE.
  
=======
  If we remove HDD_MAX_NUM_IBSS_STA or less STA we return success else we
  return FALSE.

>>>>>>> d97af3b... add prima wlan driver
=======
  If we remove HDD_MAX_NUM_IBSS_STA or less STA we return success else we 
  return FALSE.
  
>>>>>>> 657b0e9... prima update
  ===========================================================================*/
static int roamRemoveIbssStation( hdd_station_ctx_t *pHddStaCtx, v_U8_t staId )
{
   int fSuccess = FALSE;
   int idx = 0;
   v_U8_t  valid_idx   = 0;
   v_U8_t  del_idx   = 0;
<<<<<<< HEAD
<<<<<<< HEAD
   
=======
   v_U8_t  empty_slots = 0;

>>>>>>> d97af3b... add prima wlan driver
=======
   
>>>>>>> 657b0e9... prima update
   for ( idx = 0; idx < HDD_MAX_NUM_IBSS_STA; idx++ )
   {
      if ( staId == pHddStaCtx->conn_info.staId[ idx ] )
      {
         pHddStaCtx->conn_info.staId[ idx ] = 0;

         vos_zero_macaddr( &pHddStaCtx->conn_info.peerMacAddress[ idx ] );

         fSuccess = TRUE;
<<<<<<< HEAD
<<<<<<< HEAD
         // Note the deleted Index, if its 0 we need special handling
         del_idx = idx;
      }
      else
      {
         if (pHddStaCtx->conn_info.staId[idx] != 0) 
         {
            valid_idx = idx;
         }
      }
   }

=======

=======
>>>>>>> 657b0e9... prima update
         // Note the deleted Index, if its 0 we need special handling
         del_idx = idx;
      }
      else
      {
         if (pHddStaCtx->conn_info.staId[idx] != 0) 
         {
            valid_idx = idx;
         }
      }
   }

<<<<<<< HEAD
   if (HDD_MAX_NUM_IBSS_STA == empty_slots)
   {
      // Last peer departed, set the IBSS state appropriately
      pHddStaCtx->conn_info.connState = eConnectionState_IbssDisconnected;
      VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO,
                 "Last IBSS Peer Departed!!!" );
   }

>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
   // Find next active staId, to have a valid sta trigger for TL.
   if (fSuccess == TRUE)
   {
      if (del_idx == 0)
      {
         if (pHddStaCtx->conn_info.staId[valid_idx] != 0)
         {
            pHddStaCtx->conn_info.staId[0] = pHddStaCtx->conn_info.staId[valid_idx];
            vos_copy_macaddr( &pHddStaCtx->conn_info.peerMacAddress[ 0 ],
               &pHddStaCtx->conn_info.peerMacAddress[ valid_idx ]);

            pHddStaCtx->conn_info.staId[valid_idx] = 0;
            vos_zero_macaddr( &pHddStaCtx->conn_info.peerMacAddress[ valid_idx ] );
         }
      }
   }
   return( fSuccess );
}

/**============================================================================
 *
<<<<<<< HEAD
<<<<<<< HEAD
  @brief roamIbssConnectHandler() : We update the status of the IBSS to 
  connected in this function.
  
  ===========================================================================*/
static eHalStatus roamIbssConnectHandler( hdd_adapter_t *pAdapter, tCsrRoamInfo *pRoamInfo )
{
=======
  @brief roamIbssConnectHandler() : We update the status of the IBSS to
=======
  @brief roamIbssConnectHandler() : We update the status of the IBSS to 
>>>>>>> 657b0e9... prima update
  connected in this function.
  
  ===========================================================================*/
static eHalStatus roamIbssConnectHandler( hdd_adapter_t *pAdapter, tCsrRoamInfo *pRoamInfo )
{
<<<<<<< HEAD
   struct cfg80211_bss *bss;
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
   VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO, "IBSS Connect Indication from SME!!!" );
   // Set the internal connection state to show 'IBSS Connected' (IBSS with a partner stations)...
   hdd_connSetConnectionState( WLAN_HDD_GET_STATION_CTX_PTR(pAdapter), eConnectionState_IbssConnected );

   // Save the connection info from CSR...
   hdd_connSaveConnectInfo( pAdapter, pRoamInfo, eCSR_BSS_TYPE_IBSS );

   // Send the bssid address to the wext.
   hdd_SendAssociationEvent(pAdapter->dev, pRoamInfo);
<<<<<<< HEAD
<<<<<<< HEAD
#ifdef CONFIG_CFG80211
   /* add bss_id to cfg80211 data base */
   wlan_hdd_cfg80211_update_bss_db(pAdapter, pRoamInfo);
   /* send ibss join indication to nl80211 */
   cfg80211_ibss_joined(pAdapter->dev, &pRoamInfo->bssid[0], GFP_KERNEL);
#endif
=======
=======
#ifdef CONFIG_CFG80211
>>>>>>> 657b0e9... prima update
   /* add bss_id to cfg80211 data base */
   wlan_hdd_cfg80211_update_bss_db(pAdapter, pRoamInfo);
   /* send ibss join indication to nl80211 */
   cfg80211_ibss_joined(pAdapter->dev, &pRoamInfo->bssid[0], GFP_KERNEL);
#endif
<<<<<<< HEAD
                    bss);
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update

   return( eHAL_STATUS_SUCCESS );
}
/**============================================================================
 *
  @brief hdd_RoamSetKeyCompleteHandler() - Update the security parameters.
<<<<<<< HEAD
<<<<<<< HEAD
  
  ===========================================================================*/
static eHalStatus hdd_RoamSetKeyCompleteHandler( hdd_adapter_t *pAdapter, tCsrRoamInfo *pRoamInfo, 
                                                 tANI_U32 roamId, eRoamCmdStatus roamStatus,                                                
=======

  ===========================================================================*/
static eHalStatus hdd_RoamSetKeyCompleteHandler( hdd_adapter_t *pAdapter, tCsrRoamInfo *pRoamInfo,
                                                 tANI_U32 roamId, eRoamCmdStatus roamStatus,
>>>>>>> d97af3b... add prima wlan driver
=======
  
  ===========================================================================*/
static eHalStatus hdd_RoamSetKeyCompleteHandler( hdd_adapter_t *pAdapter, tCsrRoamInfo *pRoamInfo, 
                                                 tANI_U32 roamId, eRoamCmdStatus roamStatus,                                                
>>>>>>> 657b0e9... prima update
                                                 eCsrRoamResult roamResult )
{
   eCsrEncryptionType connectedCipherAlgo;
   v_BOOL_t fConnected   = FALSE;
   VOS_STATUS vosStatus    = VOS_STATUS_E_FAILURE;
   hdd_context_t *pHddCtx = WLAN_HDD_GET_CTX(pAdapter);
   hdd_station_ctx_t *pHddStaCtx = WLAN_HDD_GET_STATION_CTX_PTR(pAdapter);
   ENTER();
<<<<<<< HEAD
<<<<<<< HEAD
   // if ( WPA ), tell TL to go to 'authenticated' after the keys are set.
   // then go to 'authenticated'.  For all other authentication types (those that do 
   // not require upper layer authentication) we can put TL directly into 'authenticated'
   // state.
   fConnected = hdd_connGetConnectedCipherAlgo( pHddStaCtx, &connectedCipherAlgo );
   if( fConnected )
   {
      // TODO: Considering getting a state machine in HDD later.
      // This routuine is invoked twice. 1)set PTK 2)set GTK. The folloing if statement will be
      // TRUE when setting GTK. At this time we don't handle the state in detail.
      // Related CR: 174048 - TL not in authenticated state
      if(( eCSR_ROAM_RESULT_AUTHENTICATED == roamResult ) && (pRoamInfo != NULL) && !pRoamInfo->fAuthRequired)
      {
         VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_MED,
                    "Key set for StaId= %d.  Changing TL state to AUTHENTICATED", pHddStaCtx->conn_info.staId[ 0 ] );
                    
         // Connections that do not need Upper layer authentication, transition TL 
         // to 'Authenticated' state after the keys are set.
         vosStatus = WLANTL_ChangeSTAState( pHddCtx->pvosContext, pHddStaCtx->conn_info.staId[ 0 ], 
                                            WLANTL_STA_AUTHENTICATED );
 
         pHddStaCtx->conn_info.uIsAuthenticated = VOS_TRUE;
      }
      
      pHddStaCtx->roam_info.roamingState = HDD_ROAM_STATE_NONE;
=======

   if (NULL == pRoamInfo)
   {
       VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "pRoamInfo is NULL");
       return eHAL_STATUS_FAILURE;
   }
=======
>>>>>>> 657b0e9... prima update
   // if ( WPA ), tell TL to go to 'authenticated' after the keys are set.
   // then go to 'authenticated'.  For all other authentication types (those that do 
   // not require upper layer authentication) we can put TL directly into 'authenticated'
   // state.
   fConnected = hdd_connGetConnectedCipherAlgo( pHddStaCtx, &connectedCipherAlgo );
   if( fConnected )
   {
      // TODO: Considering getting a state machine in HDD later.
      // This routuine is invoked twice. 1)set PTK 2)set GTK. The folloing if statement will be
      // TRUE when setting GTK. At this time we don't handle the state in detail.
      // Related CR: 174048 - TL not in authenticated state
      if(( eCSR_ROAM_RESULT_AUTHENTICATED == roamResult ) && (pRoamInfo != NULL) && !pRoamInfo->fAuthRequired)
      {
         VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_MED,
                    "Key set for StaId= %d.  Changing TL state to AUTHENTICATED", pHddStaCtx->conn_info.staId[ 0 ] );
                    
         // Connections that do not need Upper layer authentication, transition TL 
         // to 'Authenticated' state after the keys are set.
         vosStatus = WLANTL_ChangeSTAState( pHddCtx->pvosContext, pHddStaCtx->conn_info.staId[ 0 ], 
                                            WLANTL_STA_AUTHENTICATED );
 
         pHddStaCtx->conn_info.uIsAuthenticated = VOS_TRUE;
      }
<<<<<<< HEAD
>>>>>>> d97af3b... add prima wlan driver
=======
      
      pHddStaCtx->roam_info.roamingState = HDD_ROAM_STATE_NONE;
>>>>>>> 657b0e9... prima update
   }
   else
   {
      // possible disassoc after issuing set key and waiting set key complete
      pHddStaCtx->roam_info.roamingState = HDD_ROAM_STATE_NONE;
   }
<<<<<<< HEAD
<<<<<<< HEAD
   
=======

>>>>>>> d97af3b... add prima wlan driver
=======
   
>>>>>>> 657b0e9... prima update
   EXIT();
   return( eHAL_STATUS_SUCCESS );
}
/**============================================================================
 *
  @brief hdd_RoamMicErrorIndicationHandler() - This function indicates the Mic failure to the supplicant.
  ===========================================================================*/
<<<<<<< HEAD
<<<<<<< HEAD
static eHalStatus hdd_RoamMicErrorIndicationHandler( hdd_adapter_t *pAdapter, tCsrRoamInfo *pRoamInfo, 
                                                 tANI_U32 roamId, eRoamCmdStatus roamStatus,                                                                              eCsrRoamResult roamResult )
{   
=======
static eHalStatus hdd_RoamMicErrorIndicationHandler( hdd_adapter_t *pAdapter, tCsrRoamInfo *pRoamInfo,
                                                 tANI_U32 roamId, eRoamCmdStatus roamStatus,                                                                              eCsrRoamResult roamResult )
{
>>>>>>> d97af3b... add prima wlan driver
=======
static eHalStatus hdd_RoamMicErrorIndicationHandler( hdd_adapter_t *pAdapter, tCsrRoamInfo *pRoamInfo, 
                                                 tANI_U32 roamId, eRoamCmdStatus roamStatus,                                                                              eCsrRoamResult roamResult )
{   
>>>>>>> 657b0e9... prima update
   hdd_station_ctx_t *pHddStaCtx = WLAN_HDD_GET_STATION_CTX_PTR(pAdapter);

   if( eConnectionState_Associated == pHddStaCtx->conn_info.connState &&
      TKIP_COUNTER_MEASURE_STOPED == pHddStaCtx->WextState.mTKIPCounterMeasures )
   {
      struct iw_michaelmicfailure msg;
      union iwreq_data wreq;
      memset(&msg, '\0', sizeof(msg));
      msg.src_addr.sa_family = ARPHRD_ETHER;
      memcpy(msg.src_addr.sa_data, pRoamInfo->u.pMICFailureInfo->taMacAddr, sizeof(pRoamInfo->u.pMICFailureInfo->taMacAddr));
      hddLog(LOG1, "MIC MAC %02x:%02x:%02x:%02x:%02x:%02x",
                                    msg.src_addr.sa_data[0],
                                    msg.src_addr.sa_data[1],
                                    msg.src_addr.sa_data[2],
                                    msg.src_addr.sa_data[3],
                                    msg.src_addr.sa_data[4],
                                    msg.src_addr.sa_data[5]);
<<<<<<< HEAD
<<<<<<< HEAD
  
      if(pRoamInfo->u.pMICFailureInfo->multicast == eSIR_TRUE)
         msg.flags = IW_MICFAILURE_GROUP;
      else 
=======

      if(pRoamInfo->u.pMICFailureInfo->multicast == eSIR_TRUE)
         msg.flags = IW_MICFAILURE_GROUP;
      else
>>>>>>> d97af3b... add prima wlan driver
=======
  
      if(pRoamInfo->u.pMICFailureInfo->multicast == eSIR_TRUE)
         msg.flags = IW_MICFAILURE_GROUP;
      else 
>>>>>>> 657b0e9... prima update
         msg.flags = IW_MICFAILURE_PAIRWISE;
      memset(&wreq, 0, sizeof(wreq));
      wreq.data.length = sizeof(msg);
      wireless_send_event(pAdapter->dev, IWEVMICHAELMICFAILURE, &wreq, (char *)&msg);
<<<<<<< HEAD
<<<<<<< HEAD
#ifdef CONFIG_CFG80211
      /* inform mic failure to nl80211 */
      cfg80211_michael_mic_failure(pAdapter->dev, 
=======
      /* inform mic failure to nl80211 */
      cfg80211_michael_mic_failure(pAdapter->dev,
>>>>>>> d97af3b... add prima wlan driver
=======
#ifdef CONFIG_CFG80211
      /* inform mic failure to nl80211 */
      cfg80211_michael_mic_failure(pAdapter->dev, 
>>>>>>> 657b0e9... prima update
              pRoamInfo->u.pMICFailureInfo->taMacAddr,
              ((pRoamInfo->u.pMICFailureInfo->multicast == eSIR_TRUE) ?
               NL80211_KEYTYPE_GROUP :
               NL80211_KEYTYPE_PAIRWISE),
<<<<<<< HEAD
<<<<<<< HEAD
              pRoamInfo->u.pMICFailureInfo->keyId, 
              pRoamInfo->u.pMICFailureInfo->TSC, 
              GFP_KERNEL);
#endif
      
   }
   
=======
              pRoamInfo->u.pMICFailureInfo->keyId,
              pRoamInfo->u.pMICFailureInfo->TSC,
=======
              pRoamInfo->u.pMICFailureInfo->keyId, 
              pRoamInfo->u.pMICFailureInfo->TSC, 
>>>>>>> 657b0e9... prima update
              GFP_KERNEL);
#endif
      
   }
<<<<<<< HEAD

>>>>>>> d97af3b... add prima wlan driver
=======
   
>>>>>>> 657b0e9... prima update
   return( eHAL_STATUS_SUCCESS );
}

/**============================================================================
 *
<<<<<<< HEAD
<<<<<<< HEAD
  @brief roamRoamConnectStatusUpdateHandler() - The Ibss connection status is 
  updated regularly here in this function.
  
  ===========================================================================*/
static eHalStatus roamRoamConnectStatusUpdateHandler( hdd_adapter_t *pAdapter, tCsrRoamInfo *pRoamInfo, 
   tANI_U32 roamId, eRoamCmdStatus roamStatus,                                                
=======
  @brief roamRoamConnectStatusUpdateHandler() - The Ibss connection status is
=======
  @brief roamRoamConnectStatusUpdateHandler() - The Ibss connection status is 
>>>>>>> 657b0e9... prima update
  updated regularly here in this function.
  
  ===========================================================================*/
<<<<<<< HEAD
static eHalStatus roamRoamConnectStatusUpdateHandler( hdd_adapter_t *pAdapter, tCsrRoamInfo *pRoamInfo,
   tANI_U32 roamId, eRoamCmdStatus roamStatus,
>>>>>>> d97af3b... add prima wlan driver
=======
static eHalStatus roamRoamConnectStatusUpdateHandler( hdd_adapter_t *pAdapter, tCsrRoamInfo *pRoamInfo, 
   tANI_U32 roamId, eRoamCmdStatus roamStatus,                                                
>>>>>>> 657b0e9... prima update
   eCsrRoamResult roamResult )
{
   VOS_STATUS vosStatus;

   hdd_context_t *pHddCtx = WLAN_HDD_GET_CTX(pAdapter);
   switch( roamResult )
   {
      case eCSR_ROAM_RESULT_IBSS_NEW_PEER:
      {
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
         VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO,
                    "IBSS New Peer indication from SME "
                    "with peerMac %2x-%2x-%2x-%2x-%2x-%2x  and  stationID= %d",
                    pRoamInfo->peerMac[0], pRoamInfo->peerMac[1], pRoamInfo->peerMac[2],
                    pRoamInfo->peerMac[3], pRoamInfo->peerMac[4], pRoamInfo->peerMac[5], 
<<<<<<< HEAD
                    pRoamInfo->staId );
         
=======
         hdd_station_ctx_t *pHddStaCtx = WLAN_HDD_GET_STATION_CTX_PTR(pAdapter);
         struct station_info staInfo;

         pr_info ( "IBSS New Peer indication from SME "
                    "with peerMac " MAC_ADDRESS_STR " BSSID: " MAC_ADDRESS_STR " and stationID= %d",
                    MAC_ADDR_ARRAY(pRoamInfo->peerMac),
                    MAC_ADDR_ARRAY(pHddStaCtx->conn_info.bssId),
                    pRoamInfo->staId );

>>>>>>> d97af3b... add prima wlan driver
=======
                    pRoamInfo->staId );
         
>>>>>>> 657b0e9... prima update
         if ( !roamSaveIbssStation( WLAN_HDD_GET_STATION_CTX_PTR(pAdapter), pRoamInfo->staId, (v_MACADDR_t *)pRoamInfo->peerMac ) )
         {
            VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_WARN,
                       "New IBSS peer but we already have the max we can handle.  Can't register this one" );
            break;
         }

         pHddCtx->sta_to_adapter[pRoamInfo->staId] = pAdapter;

<<<<<<< HEAD
<<<<<<< HEAD
         // Register the Station with TL for the new peer. 
=======
         pHddCtx->sta_to_adapter[IBSS_BROADCAST_STAID] = pAdapter;
         WLANTL_UpdateSTABssIdforIBSS(pHddCtx->pvosContext,
                      IBSS_BROADCAST_STAID,pHddStaCtx->conn_info.bssId);

         // Register the Station with TL for the new peer.
>>>>>>> d97af3b... add prima wlan driver
=======
         // Register the Station with TL for the new peer. 
>>>>>>> 657b0e9... prima update
         vosStatus = hdd_roamRegisterSTA( pAdapter,
                                          pRoamInfo,
                                          pRoamInfo->staId,
                                          (v_MACADDR_t *)pRoamInfo->peerMac,
                                          pRoamInfo->pBssDesc );
         if ( !VOS_IS_STATUS_SUCCESS( vosStatus ) )
         {
            VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
               "Cannot register STA with TL for IBSS.  Failed with vosStatus = %d [%08lX]",
               vosStatus, vosStatus );
         }
<<<<<<< HEAD
<<<<<<< HEAD
         
=======
         pHddStaCtx->ibss_sta_generation++;
         memset(&staInfo, 0, sizeof(staInfo));
         staInfo.filled = 0;
         staInfo.generation = pHddStaCtx->ibss_sta_generation;

         cfg80211_new_sta(pAdapter->dev,
                      (const u8 *)pRoamInfo->peerMac,
                      &staInfo, GFP_KERNEL);

         if ( eCSR_ENCRYPT_TYPE_WEP40_STATICKEY == pHddStaCtx->ibss_enc_key.encType
            ||eCSR_ENCRYPT_TYPE_WEP104_STATICKEY == pHddStaCtx->ibss_enc_key.encType
            ||eCSR_ENCRYPT_TYPE_TKIP == pHddStaCtx->ibss_enc_key.encType
            ||eCSR_ENCRYPT_TYPE_AES == pHddStaCtx->ibss_enc_key.encType )
         {
            pHddStaCtx->ibss_enc_key.keyDirection = eSIR_TX_RX;
            memcpy(&pHddStaCtx->ibss_enc_key.peerMac,
                              pRoamInfo->peerMac, WNI_CFG_BSSID_LEN);

            VOS_TRACE( VOS_MODULE_ID_HDD,
               VOS_TRACE_LEVEL_INFO_HIGH, "New peer joined set PTK encType=%d\n",
               pHddStaCtx->ibss_enc_key.encType);

            vosStatus = sme_RoamSetKey( WLAN_HDD_GET_HAL_CTX(pAdapter),
               pAdapter->sessionId, &pHddStaCtx->ibss_enc_key, &roamId );

            if ( VOS_STATUS_SUCCESS != vosStatus )
            {
               hddLog(VOS_TRACE_LEVEL_ERROR,
                       "%s: sme_RoamSetKey failed, returned %d",
                       __func__, vosStatus);
               return VOS_STATUS_E_FAILURE;
            }
         }
>>>>>>> d97af3b... add prima wlan driver
=======
         
>>>>>>> 657b0e9... prima update
         netif_carrier_on(pAdapter->dev);
         netif_tx_start_all_queues(pAdapter->dev);
         break;
      }
<<<<<<< HEAD
<<<<<<< HEAD
         
      case eCSR_ROAM_RESULT_IBSS_CONNECT:
      {
      
         roamIbssConnectHandler( pAdapter, pRoamInfo );
         
         break;
      }   
      case eCSR_ROAM_RESULT_IBSS_PEER_DEPARTED:
      {

         if ( !roamRemoveIbssStation( WLAN_HDD_GET_STATION_CTX_PTR(pAdapter), pRoamInfo->staId ) )
=======

=======
         
>>>>>>> 657b0e9... prima update
      case eCSR_ROAM_RESULT_IBSS_CONNECT:
      {
      
         roamIbssConnectHandler( pAdapter, pRoamInfo );
         
         break;
      }   
      case eCSR_ROAM_RESULT_IBSS_PEER_DEPARTED:
      {

<<<<<<< HEAD
         if ( !roamRemoveIbssStation( pHddStaCtx, pRoamInfo->staId ) )
>>>>>>> d97af3b... add prima wlan driver
=======
         if ( !roamRemoveIbssStation( WLAN_HDD_GET_STATION_CTX_PTR(pAdapter), pRoamInfo->staId ) )
>>>>>>> 657b0e9... prima update
         {
            VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_WARN,
                    "IBSS peer departed by cannot find peer in our registration table with TL" );
         }

<<<<<<< HEAD
<<<<<<< HEAD
         hdd_roamDeregisterSTA( pAdapter, pRoamInfo->staId );

         pHddCtx->sta_to_adapter[pRoamInfo->staId] = NULL;
=======
         pr_info ( "IBSS Peer Departed from SME "
                    "with peerMac " MAC_ADDRESS_STR " BSSID: " MAC_ADDRESS_STR " and stationID= %d",
                    MAC_ADDR_ARRAY(pRoamInfo->peerMac),
                    MAC_ADDR_ARRAY(pHddStaCtx->conn_info.bssId),
                    pRoamInfo->staId );

         hdd_roamDeregisterSTA( pAdapter, pRoamInfo->staId );

         pHddCtx->sta_to_adapter[pRoamInfo->staId] = NULL;
         pHddStaCtx->ibss_sta_generation++;
         cfg80211_del_sta(pAdapter->dev,
                         (const u8 *)&pRoamInfo->peerMac,
                         GFP_KERNEL);
>>>>>>> d97af3b... add prima wlan driver
=======
         hdd_roamDeregisterSTA( pAdapter, pRoamInfo->staId );

         pHddCtx->sta_to_adapter[pRoamInfo->staId] = NULL;
>>>>>>> 657b0e9... prima update

         break;
      }
      case eCSR_ROAM_RESULT_IBSS_INACTIVE:
      {
<<<<<<< HEAD
<<<<<<< HEAD
=======
          VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_MED,
                    "Received eCSR_ROAM_RESULT_IBSS_INACTIVE from SME");
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
         // Stop only when we are inactive
         netif_tx_disable(pAdapter->dev);
         netif_carrier_off(pAdapter->dev);
         hdd_connSetConnectionState( WLAN_HDD_GET_STATION_CTX_PTR(pAdapter), eConnectionState_NotConnected );
<<<<<<< HEAD
<<<<<<< HEAD
         
=======

>>>>>>> d97af3b... add prima wlan driver
=======
         
>>>>>>> 657b0e9... prima update
         // Send the bssid address to the wext.
         hdd_SendAssociationEvent(pAdapter->dev, pRoamInfo);
         // clean up data path
         hdd_disconnect_tx_rx(pAdapter);
         break;
      }
      default:
         break;
<<<<<<< HEAD
<<<<<<< HEAD
   
   }
   
   return( eHAL_STATUS_SUCCESS );
}

eHalStatus hdd_smeRoamCallback( void *pContext, tCsrRoamInfo *pRoamInfo, tANI_U32 roamId, 
=======

=======
   
>>>>>>> 657b0e9... prima update
   }
   
   return( eHAL_STATUS_SUCCESS );
}

<<<<<<< HEAD
#ifdef FEATURE_WLAN_TDLS
/**============================================================================
 *
  @brief hdd_roamRegisterTDLSSTA() - Construct the staDesc and register with
  TL the new STA. This is called as part of ADD_STA in the TDLS setup
  Return: VOS_STATUS

  ===========================================================================*/
VOS_STATUS hdd_roamRegisterTDLSSTA( hdd_adapter_t *pAdapter,
                                    tANI_U8 *peerMac, tANI_U16 staId, tANI_U8 ucastSig)
{
    hdd_station_ctx_t *pHddStaCtx = WLAN_HDD_GET_STATION_CTX_PTR(pAdapter);
    v_CONTEXT_t pVosContext = (WLAN_HDD_GET_CTX(pAdapter))->pvosContext;
    VOS_STATUS vosStatus = VOS_STATUS_E_FAILURE;
    WLAN_STADescType staDesc = {0};
    eCsrEncryptionType connectedCipherAlgo = eCSR_ENCRYPT_TYPE_UNKNOWN;
    v_BOOL_t fConnected   = FALSE;
    hdd_context_t *pHddCtx = WLAN_HDD_GET_CTX(pAdapter);
    hdd_config_t *cfg_param = pHddCtx->cfg_ini;

    fConnected = hdd_connGetConnectedCipherAlgo( pHddStaCtx, &connectedCipherAlgo );
    if (!fConnected) {
        VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                     "%s not connected. ignored", __func__);
        return VOS_FALSE;
    }

    /*
     * TDLS sta in BSS should be set as STA type TDLS and STA MAC should
     * be peer MAC, here we are wokrking on direct Link
     */
    staDesc.ucSTAId = staId ;

    staDesc.wSTAType = WLAN_STA_TDLS ;

    vos_mem_copy( staDesc.vSTAMACAddress.bytes, peerMac,
                                         sizeof(tSirMacAddr) );

    vos_mem_copy(staDesc.vBSSIDforIBSS.bytes, pHddStaCtx->conn_info.bssId,6 );
    vos_copy_macaddr( &staDesc.vSelfMACAddress, &pAdapter->macAddressCurrent );

    /* set the QoS field appropriately ..*/
    (hdd_wmm_is_active(pAdapter)) ? (staDesc.ucQosEnabled = 1)
                                          : (staDesc.ucQosEnabled = 0) ;

    VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH, "HDD register \
                                TL QoS_enabled=%d\n", staDesc.ucQosEnabled );

    staDesc.ucProtectedFrame = (connectedCipherAlgo != eCSR_ENCRYPT_TYPE_NONE) ;

    VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_MED,
               "HDD register TL Sec_enabled= %d.\n", staDesc.ucProtectedFrame );

    /*
     * UMA is ready we inform TL  to do frame translation.
     */
    staDesc.ucSwFrameTXXlation = 1;
    staDesc.ucSwFrameRXXlation = 1;
    staDesc.ucAddRmvLLC = 1;

    /* Initialize signatures and state */
    staDesc.ucUcastSig  = ucastSig ;

    /* tdls Direct Link do not need bcastSig */
    staDesc.ucBcastSig  = 0 ;

#ifdef VOLANS_ENABLE_SW_REPLAY_CHECK
    if(staDesc.ucProtectedFrame)
        staDesc.ucIsReplayCheckValid = VOS_TRUE;
    else
        staDesc.ucIsReplayCheckValid = VOS_FALSE;
#endif

    staDesc.ucInitState = WLANTL_STA_CONNECTED ;

   /* Register the Station with TL...  */
    vosStatus = WLANTL_RegisterSTAClient( pVosContext,
                                          hdd_rx_packet_cbk,
                                          hdd_tx_complete_cbk,
                                          hdd_tx_fetch_packet_cbk, &staDesc, 0 );

    if ( !VOS_IS_STATUS_SUCCESS( vosStatus ) )
    {
        VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                     "%s: WLANTL_RegisterSTAClient() failed to register.  \
                            Status= %d [0x%08lX]", __func__, vosStatus, vosStatus );
         return vosStatus;
    }

    if ( cfg_param->dynSplitscan &&
       ( VOS_TIMER_STATE_RUNNING !=
                        vos_timer_getCurrentState(&pHddCtx->tx_rx_trafficTmr)) )
    {
        vos_timer_start(&pHddCtx->tx_rx_trafficTmr,
                        cfg_param->trafficMntrTmrForSplitScan);
    }
    return( vosStatus );
}

static VOS_STATUS hdd_roamDeregisterTDLSSTA( hdd_adapter_t *pAdapter, tANI_U8 staId )
{
    VOS_STATUS vosStatus;
    vosStatus = WLANTL_ClearSTAClient( (WLAN_HDD_GET_CTX(pAdapter))->pvosContext, staId );
    if ( !VOS_IS_STATUS_SUCCESS( vosStatus ) )
    {
        VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_WARN,
                   "%s: WLANTL_ClearSTAClient() failed to for staID %d.  "
                   "Status= %d [0x%08lX]",
                   __func__, staId, vosStatus, vosStatus );
    }
    return( vosStatus );
}


/*
 * HDD interface between SME and TL to ensure TDLS client registration with
 * TL in case of new TDLS client is added and deregistration at the time
 * TDLS client is deleted.
 */

eHalStatus hdd_RoamTdlsStatusUpdateHandler(hdd_adapter_t *pAdapter,
                                             tCsrRoamInfo *pRoamInfo,
                                              tANI_U32 roamId,
                                                eRoamCmdStatus roamStatus,
                                                  eCsrRoamResult roamResult)
{
    hdd_context_t *pHddCtx = WLAN_HDD_GET_CTX(pAdapter);
    eHalStatus status = eHAL_STATUS_FAILURE ;
    tANI_U8 staIdx;

#ifdef WLAN_FEATURE_TDLS_DEBUG
    VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
    ("hdd_tdlsStatusUpdate: %s staIdx %d %02x:%02x:%02x:%02x:%02x:%02x \n"),
      roamResult == eCSR_ROAM_RESULT_ADD_TDLS_PEER ? "ADD_TDLS_PEER" :
      roamResult == eCSR_ROAM_RESULT_DELETE_TDLS_PEER ? "DEL_TDLS_PEER" :
      roamResult == eCSR_ROAM_RESULT_TEARDOWN_TDLS_PEER_IND ? "DEL_TDLS_PEER_IND" :
      roamResult == eCSR_ROAM_RESULT_DELETE_ALL_TDLS_PEER_IND? "DEL_ALL_TDLS_PEER_IND" :
      roamResult == eCSR_ROAM_RESULT_UPDATE_TDLS_PEER? "UPDATE_TDLS_PEER" :
      roamResult == eCSR_ROAM_RESULT_LINK_ESTABLISH_REQ_RSP? "LINK_ESTABLISH_REQ_RSP" :
      "UNKNOWN",
       pRoamInfo->staId,
       pRoamInfo->peerMac[0],
       pRoamInfo->peerMac[1],
       pRoamInfo->peerMac[2],
       pRoamInfo->peerMac[3],
       pRoamInfo->peerMac[4],
       pRoamInfo->peerMac[5]) ;
#endif
    switch( roamResult )
    {
        case eCSR_ROAM_RESULT_ADD_TDLS_PEER:
        {
            if(eSIR_SME_SUCCESS != pRoamInfo->statusCode)
            {
                VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                     ("%s: Add Sta is failed. %d"),__func__, pRoamInfo->statusCode);
            }
            else
            {

                /* check if there is available index for this new TDLS STA */
                for ( staIdx = 0; staIdx < HDD_MAX_NUM_TDLS_STA; staIdx++ )
                {
                    if (0 == pHddCtx->tdlsConnInfo[staIdx].staId )
                    {
                        pHddCtx->tdlsConnInfo[staIdx].sessionId = pRoamInfo->sessionId;
                        pHddCtx->tdlsConnInfo[staIdx].staId = pRoamInfo->staId;

                        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_WARN,
                         ("TDLS: STA IDX at %d is %d "
                                  "of mac %02x:%02x:%02x:%02x:%02x:%02x"),
                                  staIdx, pHddCtx->tdlsConnInfo[staIdx].staId,
                                          pRoamInfo->peerMac[0],
                                          pRoamInfo->peerMac[1],
                                          pRoamInfo->peerMac[2],
                                          pRoamInfo->peerMac[3],
                                          pRoamInfo->peerMac[4],
                                          pRoamInfo->peerMac[5]) ;

                        vos_copy_macaddr(&pHddCtx->tdlsConnInfo[staIdx].peerMac,
                                         (v_MACADDR_t *)pRoamInfo->peerMac) ;
                        status = eHAL_STATUS_SUCCESS ;
                        break ;
                    }
                }
                if (staIdx < HDD_MAX_NUM_TDLS_STA)
                {
                    if (-1 == wlan_hdd_tdls_set_sta_id(pAdapter, pRoamInfo->peerMac, pRoamInfo->staId)) {
                        VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                                     "wlan_hdd_tdls_set_sta_id() failed");
                        return VOS_FALSE;
                    }

                    (WLAN_HDD_GET_CTX(pAdapter))->sta_to_adapter[pRoamInfo->staId] = pAdapter;
                    /* store the ucast signature , if required for further reference. */

                    wlan_hdd_tdls_set_signature( pAdapter, pRoamInfo->peerMac, pRoamInfo->ucastSig );
                    /* start TDLS client registration with TL */
                    status = hdd_roamRegisterTDLSSTA( pAdapter,
                                                      pRoamInfo->peerMac,
                                                      pRoamInfo->staId,
                                                      pRoamInfo->ucastSig);
                }
                else
                {
                    status = eHAL_STATUS_FAILURE;
                    VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                    "%s: no available slot in conn_info. staId %d cannot be stored", __func__, pRoamInfo->staId);
                }
                pAdapter->tdlsAddStaStatus = status;
            }
            complete(&pAdapter->tdls_add_station_comp);
            break ;
        }
        case eCSR_ROAM_RESULT_UPDATE_TDLS_PEER:
        {
            if (eSIR_SME_SUCCESS != pRoamInfo->statusCode)
            {
                VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                     "%s: Add Sta is failed. %d", __func__, pRoamInfo->statusCode);
            }
            /* store the ucast signature which will be used later when
             * registering to TL
             */
            pAdapter->tdlsAddStaStatus = pRoamInfo->statusCode;
            complete(&pAdapter->tdls_add_station_comp);
            break;
        }
        case eCSR_ROAM_RESULT_LINK_ESTABLISH_REQ_RSP:
        {
            if (eSIR_SME_SUCCESS != pRoamInfo->statusCode)
            {
                VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                     "%s: Link Establish Request failed. %d", __func__, pRoamInfo->statusCode);
            }
            complete(&pAdapter->tdls_link_establish_req_comp);
            break;
        }
        case eCSR_ROAM_RESULT_DELETE_TDLS_PEER:
        {
            hddTdlsPeer_t *curr_peer;
            for ( staIdx = 0; staIdx < HDD_MAX_NUM_TDLS_STA; staIdx++ )
            {
                if ((pHddCtx->tdlsConnInfo[staIdx].sessionId == pRoamInfo->sessionId) &&
                    pRoamInfo->staId == pHddCtx->tdlsConnInfo[staIdx].staId)
                {
                    VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_WARN,
                                   ("HDD: del STA IDX = %x"), pRoamInfo->staId) ;

                    curr_peer = wlan_hdd_tdls_find_peer(pAdapter, pRoamInfo->peerMac);
                    if (NULL != curr_peer && TDLS_IS_CONNECTED(curr_peer))
                    {
                        hdd_roamDeregisterTDLSSTA ( pAdapter, pRoamInfo->staId );
                        wlan_hdd_tdls_decrement_peer_count(pAdapter);
                    }
                    wlan_hdd_tdls_reset_peer(pAdapter, pRoamInfo->peerMac);
                    (WLAN_HDD_GET_CTX(pAdapter))->sta_to_adapter[pRoamInfo->staId] = NULL;

                    pHddCtx->tdlsConnInfo[staIdx].staId = 0 ;
                    pHddCtx->tdlsConnInfo[staIdx].sessionId = 255;
                    vos_mem_zero(&pHddCtx->tdlsConnInfo[staIdx].peerMac,
                                               sizeof(v_MACADDR_t)) ;
                    wlan_hdd_tdls_check_bmps(pAdapter);
                    status = eHAL_STATUS_SUCCESS ;
                    break ;
                }
            }
            complete(&pAdapter->tdls_del_station_comp);
        }
        break ;
        case eCSR_ROAM_RESULT_TEARDOWN_TDLS_PEER_IND:
        {
            hddTdlsPeer_t *curr_peer;
            VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                       "%s: Sending teardown to supplicant with reason code %u",
                       __func__, pRoamInfo->reasonCode);

#ifdef CONFIG_TDLS_IMPLICIT
            curr_peer = wlan_hdd_tdls_find_peer(pAdapter, pRoamInfo->peerMac);
            wlan_hdd_tdls_indicate_teardown(pAdapter, curr_peer, pRoamInfo->reasonCode);
#endif
            status = eHAL_STATUS_SUCCESS ;
            break ;
        }
        case eCSR_ROAM_RESULT_DELETE_ALL_TDLS_PEER_IND:
        {
            /* 0 staIdx is assigned to AP we dont want to touch that */
            for ( staIdx = 0; staIdx < HDD_MAX_NUM_TDLS_STA; staIdx++ )
            {
                if ((pHddCtx->tdlsConnInfo[staIdx].sessionId == pRoamInfo->sessionId) &&
                    pHddCtx->tdlsConnInfo[staIdx].staId)
                {
                    VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_WARN,
                              ("hdd_tdlsStatusUpdate: staIdx %d %02x:%02x:%02x:%02x:%02x:%02x"),
                                pHddCtx->tdlsConnInfo[staIdx].staId,
                                pHddCtx->tdlsConnInfo[staIdx].peerMac.bytes[0],
                                pHddCtx->tdlsConnInfo[staIdx].peerMac.bytes[1],
                                pHddCtx->tdlsConnInfo[staIdx].peerMac.bytes[2],
                                pHddCtx->tdlsConnInfo[staIdx].peerMac.bytes[3],
                                pHddCtx->tdlsConnInfo[staIdx].peerMac.bytes[4],
                                pHddCtx->tdlsConnInfo[staIdx].peerMac.bytes[5]) ;
                    wlan_hdd_tdls_reset_peer(pAdapter, pHddCtx->tdlsConnInfo[staIdx].peerMac.bytes);
                    hdd_roamDeregisterTDLSSTA ( pAdapter,  pHddCtx->tdlsConnInfo[staIdx].staId );
                    wlan_hdd_tdls_decrement_peer_count(pAdapter);

                    (WLAN_HDD_GET_CTX(pAdapter))->sta_to_adapter[staIdx] = NULL;
                    vos_mem_zero(&pHddCtx->tdlsConnInfo[staIdx].peerMac,
                                               sizeof(v_MACADDR_t)) ;
                    pHddCtx->tdlsConnInfo[staIdx].staId = 0 ;
                    pHddCtx->tdlsConnInfo[staIdx].sessionId = 255;

                    status = eHAL_STATUS_SUCCESS ;
                }
            }
            wlan_hdd_tdls_check_bmps(pAdapter);
            break ;
        }
        default:
        {
            break ;
        }
    }

    return status ;
}
#endif

eHalStatus hdd_smeRoamCallback( void *pContext, tCsrRoamInfo *pRoamInfo, tANI_U32 roamId,
>>>>>>> d97af3b... add prima wlan driver
=======
eHalStatus hdd_smeRoamCallback( void *pContext, tCsrRoamInfo *pRoamInfo, tANI_U32 roamId, 
>>>>>>> 657b0e9... prima update
                                eRoamCmdStatus roamStatus, eCsrRoamResult roamResult )
{
    eHalStatus halStatus = eHAL_STATUS_SUCCESS;
    hdd_adapter_t *pAdapter = (hdd_adapter_t *)pContext;
<<<<<<< HEAD
<<<<<<< HEAD
    hdd_wext_state_t *pWextState= WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter);
    hdd_station_ctx_t *pHddStaCtx = WLAN_HDD_GET_STATION_CTX_PTR(pAdapter);
    VOS_STATUS status = VOS_STATUS_SUCCESS;

    VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH,
            "CSR Callback: status= %d result= %d roamID=%ld", 
                    roamStatus, roamResult, roamId ); 

    /*Sanity check*/
    if (WLAN_HDD_ADAPTER_MAGIC != pAdapter->magic)
    {
       VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL,
          "pAdapter has invalid magic return"); 
=======
    hdd_wext_state_t *pWextState = NULL;
    hdd_station_ctx_t *pHddStaCtx = NULL;
=======
    hdd_wext_state_t *pWextState= WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter);
    hdd_station_ctx_t *pHddStaCtx = WLAN_HDD_GET_STATION_CTX_PTR(pAdapter);
>>>>>>> 657b0e9... prima update
    VOS_STATUS status = VOS_STATUS_SUCCESS;

    VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH,
            "CSR Callback: status= %d result= %d roamID=%ld", 
                    roamStatus, roamResult, roamId ); 

    /*Sanity check*/
    if (WLAN_HDD_ADAPTER_MAGIC != pAdapter->magic)
    {
       VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL,
<<<<<<< HEAD
          "invalid WEXT state or HDD station context");
>>>>>>> d97af3b... add prima wlan driver
=======
          "pAdapter has invalid magic return"); 
>>>>>>> 657b0e9... prima update
       return eHAL_STATUS_FAILURE;
    }

    switch( roamStatus )
    {
        case eCSR_ROAM_SESSION_OPENED:
            if(pAdapter != NULL)
            {
                set_bit(SME_SESSION_OPENED, &pAdapter->event_flags);
                complete(&pAdapter->session_open_comp_var);
            }
            break;
<<<<<<< HEAD
<<<<<<< HEAD
            
#if  defined (WLAN_FEATURE_VOWIFI_11R) || defined (FEATURE_WLAN_CCX) || defined(FEATURE_WLAN_LFR)
            /* We did pre-auth,then we attempted a 11r or ccx reassoc.
             * reassoc failed due to failure, timeout, reject from ap
             * in any case tell the OS, our carrier is off and mark 
=======

#if  defined (WLAN_FEATURE_VOWIFI_11R) || defined (FEATURE_WLAN_CCX) || defined(FEATURE_WLAN_LFR)
            /* We did pre-auth,then we attempted a 11r or ccx reassoc.
             * reassoc failed due to failure, timeout, reject from ap
             * in any case tell the OS, our carrier is off and mark
>>>>>>> d97af3b... add prima wlan driver
=======
            
#if  defined (WLAN_FEATURE_VOWIFI_11R) || defined (FEATURE_WLAN_CCX) || defined(FEATURE_WLAN_LFR)
            /* We did pre-auth,then we attempted a 11r or ccx reassoc.
             * reassoc failed due to failure, timeout, reject from ap
             * in any case tell the OS, our carrier is off and mark 
>>>>>>> 657b0e9... prima update
             * interface down */
        case eCSR_ROAM_FT_REASSOC_FAILED:
            hddLog(LOG1, FL("Reassoc Failed\n"));
            halStatus = hdd_DisConnectHandler( pAdapter, pRoamInfo, roamId, roamStatus, roamResult );
            /* Check if Mcast/Bcast Filters are set, if yes clear the filters here */
            if ((WLAN_HDD_GET_CTX(pAdapter))->hdd_mcastbcast_filter_set == TRUE) {
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
#ifdef FEATURE_WLAN_NON_INTEGRATED_SOC
#ifdef MSM_PLATFORM
                    hdd_conf_mcastbcast_filter((WLAN_HDD_GET_CTX(pAdapter)), FALSE);
#endif
#endif
<<<<<<< HEAD
=======
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
                    (WLAN_HDD_GET_CTX(pAdapter))->hdd_mcastbcast_filter_set = FALSE;
            }
            pHddStaCtx->ft_carrier_on = FALSE;
            break;

        case eCSR_ROAM_FT_START:
<<<<<<< HEAD
<<<<<<< HEAD
            // When we roam for CCX and 11r, we dont want the 
            // OS to be informed that the link is down. So mark
            // the link ready for ft_start. After this the 
=======
            // When we roam for CCX and 11r, we dont want the
            // OS to be informed that the link is down. So mark
            // the link ready for ft_start. After this the
>>>>>>> d97af3b... add prima wlan driver
=======
            // When we roam for CCX and 11r, we dont want the 
            // OS to be informed that the link is down. So mark
            // the link ready for ft_start. After this the 
>>>>>>> 657b0e9... prima update
            // eCSR_ROAM_SHOULD_ROAM will be received.
            // Where in we will not mark the link down
            // Also we want to stop tx at this point when we will be
            // doing disassoc at this time. This saves 30-60 msec
            // after reassoc.
            {
                struct net_device *dev = pAdapter->dev;
                netif_tx_disable(dev);
                /*
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
        		 * Deregister for this STA with TL with the objective to flush
        		 * all the packets for this STA from wmm_tx_queue. If not done here,
        		 * we would run into a race condition (CR390567) wherein TX
        		 * thread would schedule packets from wmm_tx_queue AFTER peer STA has
        		 * been deleted. And, these packets get assigned with a STA idx of
        		 * self-sta (since the peer STA has been deleted) and get transmitted
        		 * on the new channel before the reassoc request. Since there will be
        		 * no ACK on the new channel, each packet gets retransmitted which
        		 * takes several seconds before the transmission of reassoc request.
        		 * This leads to reassoc-timeout and roam failure.
    		     */
<<<<<<< HEAD
=======
                 * Deregister for this STA with TL with the objective to flush
                 * all the packets for this STA from wmm_tx_queue. If not done here,
                 * we would run into a race condition (CR390567) wherein TX
                 * thread would schedule packets from wmm_tx_queue AFTER peer STA has
                 * been deleted. And, these packets get assigned with a STA idx of
                 * self-sta (since the peer STA has been deleted) and get transmitted
                 * on the new channel before the reassoc request. Since there will be
                 * no ACK on the new channel, each packet gets retransmitted which
                 * takes several seconds before the transmission of reassoc request.
                 * This leads to reassoc-timeout and roam failure.
                 */
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
                status = hdd_roamDeregisterSTA( pAdapter, pHddStaCtx->conn_info.staId [0] );
                if ( !VOS_IS_STATUS_SUCCESS(status ) )
                {
                    VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_WARN,
                            FL("hdd_roamDeregisterSTA() failed to for staID %d.  Status= %d [0x%x]"),
                            pHddStaCtx->conn_info.staId[0], status, status );
                    halStatus = eHAL_STATUS_FAILURE;
<<<<<<< HEAD
<<<<<<< HEAD
                }		
            }
            pHddStaCtx->ft_carrier_on = TRUE;
=======
                }
            }
            pHddStaCtx->ft_carrier_on = TRUE;
            pHddStaCtx->hdd_ReassocScenario = VOS_TRUE;
>>>>>>> d97af3b... add prima wlan driver
=======
                }		
            }
            pHddStaCtx->ft_carrier_on = TRUE;
>>>>>>> 657b0e9... prima update
            break;
#endif

        case eCSR_ROAM_SHOULD_ROAM:
           // Dont need to do anything
            {
                struct net_device *dev = pAdapter->dev;
                hdd_station_ctx_t *pHddStaCtx = WLAN_HDD_GET_STATION_CTX_PTR(pAdapter);
                // notify apps that we can't pass traffic anymore
                netif_tx_disable(dev);
#if  defined (WLAN_FEATURE_VOWIFI_11R) || defined (FEATURE_WLAN_CCX) || defined(FEATURE_WLAN_LFR)
                if (pHddStaCtx->ft_carrier_on == FALSE)
                {
#endif
                    netif_carrier_off(dev);
#if  defined (WLAN_FEATURE_VOWIFI_11R) || defined (FEATURE_WLAN_CCX) || defined(FEATURE_WLAN_LFR)
                }
#endif

#if  !(defined (WLAN_FEATURE_VOWIFI_11R) || defined (FEATURE_WLAN_CCX) || defined(FEATURE_WLAN_LFR))
                //We should clear all sta register with TL, for now, only one.
                status = hdd_roamDeregisterSTA( pAdapter, pHddStaCtx->conn_info.staId [0] );
                if ( !VOS_IS_STATUS_SUCCESS(status ) )
                {
                    VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_WARN,
                        FL("hdd_roamDeregisterSTA() failed to for staID %d.  Status= %d [0x%x]"),
                                        pHddStaCtx->conn_info.staId[0], status, status );
                    halStatus = eHAL_STATUS_FAILURE;
                }
#endif
                // Clear saved connection information in HDD
                hdd_connRemoveConnectInfo( WLAN_HDD_GET_STATION_CTX_PTR(pAdapter) );
            }
           break;
        case eCSR_ROAM_LOSTLINK:
        case eCSR_ROAM_DISASSOCIATED:
            {
<<<<<<< HEAD
<<<<<<< HEAD
                hdd_context_t* pHddCtx = (hdd_context_t*)pAdapter->pHddCtx;
=======
>>>>>>> d97af3b... add prima wlan driver
=======
                hdd_context_t* pHddCtx = (hdd_context_t*)pAdapter->pHddCtx;
>>>>>>> 657b0e9... prima update
                VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO,
                        "****eCSR_ROAM_DISASSOCIATED****");
                halStatus = hdd_DisConnectHandler( pAdapter, pRoamInfo, roamId, roamStatus, roamResult );
                /* Check if Mcast/Bcast Filters are set, if yes clear the filters here */
<<<<<<< HEAD
<<<<<<< HEAD
                if ((WLAN_HDD_GET_CTX(pAdapter))->hdd_mcastbcast_filter_set == TRUE) {
                    hdd_conf_mcastbcast_filter((WLAN_HDD_GET_CTX(pAdapter)), FALSE);
                    (WLAN_HDD_GET_CTX(pAdapter))->hdd_mcastbcast_filter_set = FALSE;
                }
#ifdef WLAN_FEATURE_PACKET_FILTERING    
                if (pHddCtx->cfg_ini->isMcAddrListFilter)
                {
                    /*Multicast addr filtering is enabled*/
                    if(pHddCtx->mc_addr_list.isFilterApplied)
                    {
                        /*Filter applied during suspend mode*/
                        /*Clear it here*/
                        wlan_hdd_set_mc_addr_list(pHddCtx, FALSE, pAdapter->sessionId);
                    }
                }
#endif

                if (WLAN_HDD_P2P_CLIENT != pAdapter->device_mode)
                {
                    /* Disconnected from current AP. Reset the country code information
                     * so that it re-initialize the valid channel list*/
                    hdd_ResetCountryCodeAfterDisAssoc(pAdapter);
                }
=======
                pHddCtx = WLAN_HDD_GET_CTX(pAdapter);
                if (pHddCtx->hdd_mcastbcast_filter_set == TRUE)
                {
                    hdd_conf_mcastbcast_filter(pHddCtx, FALSE);
                    pHddCtx->configuredMcastBcastFilter =
                        pHddCtx->sus_res_mcastbcast_filter;
                    pHddCtx->sus_res_mcastbcast_filter_valid = VOS_FALSE;

                    hddLog(VOS_TRACE_LEVEL_INFO,
                           "offload: disassociation happening, restoring configuredMcastBcastFilter");
                    hddLog(VOS_TRACE_LEVEL_INFO,"McastBcastFilter = %d",
                           pHddCtx->configuredMcastBcastFilter);
                    hddLog(VOS_TRACE_LEVEL_INFO,
                           "offload: already called mcastbcast filter");
=======
                if ((WLAN_HDD_GET_CTX(pAdapter))->hdd_mcastbcast_filter_set == TRUE) {
                    hdd_conf_mcastbcast_filter((WLAN_HDD_GET_CTX(pAdapter)), FALSE);
>>>>>>> 657b0e9... prima update
                    (WLAN_HDD_GET_CTX(pAdapter))->hdd_mcastbcast_filter_set = FALSE;
                }
#ifdef WLAN_FEATURE_PACKET_FILTERING    
                if (pHddCtx->cfg_ini->isMcAddrListFilter)
                {
                    /*Multicast addr filtering is enabled*/
                    if(pHddCtx->mc_addr_list.isFilterApplied)
                    {
                        /*Filter applied during suspend mode*/
                        /*Clear it here*/
                        wlan_hdd_set_mc_addr_list(pHddCtx, FALSE, pAdapter->sessionId);
                    }
                }
#endif
<<<<<<< HEAD
>>>>>>> d97af3b... add prima wlan driver
=======

                if (WLAN_HDD_P2P_CLIENT != pAdapter->device_mode)
                {
                    /* Disconnected from current AP. Reset the country code information
                     * so that it re-initialize the valid channel list*/
                    hdd_ResetCountryCodeAfterDisAssoc(pAdapter);
                }
>>>>>>> 657b0e9... prima update
            }
            break;
        case eCSR_ROAM_IBSS_LEAVE:
            VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO,
                    "****eCSR_ROAM_IBSS_LEAVE****");
            halStatus = hdd_DisConnectHandler( pAdapter, pRoamInfo, roamId, roamStatus, roamResult );
            break;
        case eCSR_ROAM_ASSOCIATION_COMPLETION:
            VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO,
                    "****eCSR_ROAM_ASSOCIATION_COMPLETION****");
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
            if (  (roamResult != eCSR_ROAM_RESULT_ASSOCIATED)
               && (   (pWextState->roamProfile.EncryptionType.encryptionType[0] == eCSR_ENCRYPT_TYPE_WEP40_STATICKEY) 
                   || (pWextState->roamProfile.EncryptionType.encryptionType[0] == eCSR_ENCRYPT_TYPE_WEP104_STATICKEY)
                  )
               && (eCSR_AUTH_TYPE_SHARED_KEY != pWextState->roamProfile.AuthType.authType[0])
<<<<<<< HEAD
=======
            if ( (roamResult != eCSR_ROAM_RESULT_ASSOCIATED) &&
                 ( (pWextState->roamProfile.EncryptionType.encryptionType[0] ==
                       eCSR_ENCRYPT_TYPE_WEP40) ||
                   (pWextState->roamProfile.EncryptionType.encryptionType[0] ==
                       eCSR_ENCRYPT_TYPE_WEP104)
                 ) &&
                 (eCSR_AUTH_TYPE_SHARED_KEY != pWextState->roamProfile.AuthType.authType[0])
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
               )
            {
                v_U32_t roamId = 0;
                VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH,
                        "****WEP open authentication failed, trying with shared authentication****");
                (WLAN_HDD_GET_STATION_CTX_PTR(pAdapter))->conn_info.authType = eCSR_AUTH_TYPE_SHARED_KEY;
                pWextState->roamProfile.AuthType.authType[0] = (WLAN_HDD_GET_STATION_CTX_PTR(pAdapter))->conn_info.authType;
                pWextState->roamProfile.csrPersona = pAdapter->device_mode;
                halStatus = sme_RoamConnect( WLAN_HDD_GET_HAL_CTX(pAdapter), pAdapter->sessionId, &(pWextState->roamProfile), &roamId);
            }
            else
            {
                halStatus = hdd_AssociationCompletionHandler( pAdapter, pRoamInfo, roamId, roamStatus, roamResult );
            }

            break;
        case eCSR_ROAM_ASSOCIATION_FAILURE:
<<<<<<< HEAD
<<<<<<< HEAD
            halStatus = hdd_AssociationCompletionHandler( pAdapter, 
                    pRoamInfo, roamId, roamStatus, roamResult );
            break;
        case eCSR_ROAM_IBSS_IND:
            halStatus = roamRoamIbssIndicationHandler( pAdapter, pRoamInfo, roamId, roamStatus, roamResult );
=======
            halStatus = hdd_AssociationCompletionHandler( pAdapter,
                    pRoamInfo, roamId, roamStatus, roamResult );
            break;
        case eCSR_ROAM_IBSS_IND:
            hdd_RoamIbssIndicationHandler( pAdapter, pRoamInfo, roamId,
                                           roamStatus, roamResult );
>>>>>>> d97af3b... add prima wlan driver
=======
            halStatus = hdd_AssociationCompletionHandler( pAdapter, 
                    pRoamInfo, roamId, roamStatus, roamResult );
            break;
        case eCSR_ROAM_IBSS_IND:
            halStatus = roamRoamIbssIndicationHandler( pAdapter, pRoamInfo, roamId, roamStatus, roamResult );
>>>>>>> 657b0e9... prima update
            break;

        case eCSR_ROAM_CONNECT_STATUS_UPDATE:
            halStatus = roamRoamConnectStatusUpdateHandler( pAdapter, pRoamInfo, roamId, roamStatus, roamResult );
<<<<<<< HEAD
<<<<<<< HEAD
            break;            
=======
            break;
>>>>>>> d97af3b... add prima wlan driver
=======
            break;            
>>>>>>> 657b0e9... prima update

        case eCSR_ROAM_MIC_ERROR_IND:
            halStatus = hdd_RoamMicErrorIndicationHandler( pAdapter, pRoamInfo, roamId, roamStatus, roamResult );
            break;

        case eCSR_ROAM_SET_KEY_COMPLETE:
<<<<<<< HEAD
<<<<<<< HEAD
            halStatus = hdd_RoamSetKeyCompleteHandler( pAdapter, pRoamInfo, roamId, roamStatus, roamResult );
=======
            {
                hdd_context_t* pHddCtx = (hdd_context_t*)pAdapter->pHddCtx;

                if((pHddCtx) &&
                   (VOS_TRUE == pHddStaCtx->hdd_ReassocScenario) &&
                   (TRUE == pHddCtx->hdd_wlan_suspended) &&
                   (eCSR_ROAM_RESULT_NONE == roamResult))
                {
                    /* Send DTIM period to the FW; only if the wlan is already
                       in suspend. This is the case with roaming (reassoc),
                       DELETE_BSS_REQ zeroes out Modulated/Dynamic DTIM sent in
                       previous suspend_wlan. Sending SET_POWER_PARAMS_REQ
                       before the ENTER_BMPS_REQ ensures Listen Interval is
                       regained back to LI * Modulated DTIM */
                    hdd_set_pwrparams(pHddCtx);
                    pHddStaCtx->hdd_ReassocScenario = VOS_FALSE;

                    /* At this point, device should not be in BMPS;
                       if due to unexpected scenario, if we are in BMPS,
                       then trigger Exit and Enter BMPS to take DTIM period
                       effective */
                    if (BMPS == pmcGetPmcState(pHddCtx->hHal))
                    {
                        hddLog( LOGE, FL("Not expected: device is already in BMPS mode, Exit & Enter BMPS again!"));

                        /* put the device into full power */
                        wlan_hdd_enter_bmps(pAdapter, DRIVER_POWER_MODE_ACTIVE);

                        /* put the device back into BMPS */
                        wlan_hdd_enter_bmps(pAdapter, DRIVER_POWER_MODE_AUTO);
                    }
                }
                halStatus = hdd_RoamSetKeyCompleteHandler( pAdapter, pRoamInfo, roamId, roamStatus, roamResult );
            }
>>>>>>> d97af3b... add prima wlan driver
=======
            halStatus = hdd_RoamSetKeyCompleteHandler( pAdapter, pRoamInfo, roamId, roamStatus, roamResult );
>>>>>>> 657b0e9... prima update
            break;
#ifdef WLAN_FEATURE_VOWIFI_11R
        case eCSR_ROAM_FT_RESPONSE:
            hdd_SendFTEvent(pAdapter);
            break;
#endif
<<<<<<< HEAD
<<<<<<< HEAD
#ifdef FEATURE_WLAN_LFR
        case eCSR_ROAM_PMK_NOTIFY:
           if (eCSR_AUTH_TYPE_RSN == pHddStaCtx->conn_info.authType) 
=======
#if defined(FEATURE_WLAN_LFR) && (LINUX_VERSION_CODE >= KERNEL_VERSION(3,4,0))
        case eCSR_ROAM_PMK_NOTIFY:
           if (eCSR_AUTH_TYPE_RSN == pHddStaCtx->conn_info.authType)
>>>>>>> d97af3b... add prima wlan driver
=======
#ifdef FEATURE_WLAN_LFR
        case eCSR_ROAM_PMK_NOTIFY:
           if (eCSR_AUTH_TYPE_RSN == pHddStaCtx->conn_info.authType) 
>>>>>>> 657b0e9... prima update
           {
               /* Notify the supplicant of a new candidate */
               halStatus = wlan_hdd_cfg80211_pmksa_candidate_notify(pAdapter, pRoamInfo, 1, false);
           }
           break;
#endif

<<<<<<< HEAD
<<<<<<< HEAD
#ifdef WLAN_FEATURE_P2P
=======
>>>>>>> d97af3b... add prima wlan driver
=======
#ifdef WLAN_FEATURE_P2P
>>>>>>> 657b0e9... prima update
        case eCSR_ROAM_INDICATE_MGMT_FRAME:
            hdd_indicateMgmtFrame( pAdapter,
                                  pRoamInfo->nFrameLength,
                                  pRoamInfo->pbFrames,
                                  pRoamInfo->frameType,
<<<<<<< HEAD
<<<<<<< HEAD
                                  pRoamInfo->rxChan );
=======
                                  pRoamInfo->rxChan,
                                  pRoamInfo->rxRssi );
>>>>>>> d97af3b... add prima wlan driver
=======
                                  pRoamInfo->rxChan );
>>>>>>> 657b0e9... prima update
            break;
        case eCSR_ROAM_REMAIN_CHAN_READY:
            hdd_remainChanReadyHandler( pAdapter );
            break;
        case eCSR_ROAM_SEND_ACTION_CNF:
            hdd_sendActionCnf( pAdapter,
               (roamResult == eCSR_ROAM_RESULT_NONE) ? TRUE : FALSE );
            break;
<<<<<<< HEAD
<<<<<<< HEAD
=======
#ifdef FEATURE_WLAN_TDLS
        case eCSR_ROAM_TDLS_STATUS_UPDATE:
            halStatus = hdd_RoamTdlsStatusUpdateHandler( pAdapter, pRoamInfo,
                                                roamId, roamStatus, roamResult );
            break ;
        case eCSR_ROAM_RESULT_MGMT_TX_COMPLETE_IND:
            wlan_hdd_tdls_mgmt_completion_callback(pAdapter, pRoamInfo->reasonCode);
            break;
#endif
#ifdef WLAN_FEATURE_11W
       case eCSR_ROAM_UNPROT_MGMT_FRAME_IND:
            hdd_indicateUnprotMgmtFrame(pAdapter, pRoamInfo->nFrameLength,
                                         pRoamInfo->pbFrames,
                                         pRoamInfo->frameType);
            break;
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
#endif
        default:
            break;
    }
    return( halStatus );
}
<<<<<<< HEAD
<<<<<<< HEAD
eCsrAuthType hdd_TranslateRSNToCsrAuthType( u_int8_t auth_suite[4]) 
{
    eCsrAuthType auth_type;
    // is the auth type supported?
    if ( memcmp(auth_suite , ccpRSNOui01, 4) == 0) 
    {
        auth_type = eCSR_AUTH_TYPE_RSN;
    } else 
    if (memcmp(auth_suite , ccpRSNOui02, 4) == 0) 
    {
        auth_type = eCSR_AUTH_TYPE_RSN_PSK;
    } else 
#ifdef WLAN_FEATURE_VOWIFI_11R
    if (memcmp(auth_suite , ccpRSNOui04, 4) == 0) 
    {
        // Check for 11r FT Authentication with PSK
        auth_type = eCSR_AUTH_TYPE_FT_RSN_PSK;
    } else 
    if (memcmp(auth_suite , ccpRSNOui03, 4) == 0) 
    {
        // Check for 11R FT Authentication with 802.1X
        auth_type = eCSR_AUTH_TYPE_FT_RSN;
    } else 
#endif
#ifdef FEATURE_WLAN_CCX
    if (memcmp(auth_suite , ccpRSNOui06, 4) == 0) 
=======
eCsrAuthType hdd_TranslateRSNToCsrAuthType( u_int8_t auth_suite[4])
=======
eCsrAuthType hdd_TranslateRSNToCsrAuthType( u_int8_t auth_suite[4]) 
>>>>>>> 657b0e9... prima update
{
    eCsrAuthType auth_type;
    // is the auth type supported?
    if ( memcmp(auth_suite , ccpRSNOui01, 4) == 0) 
    {
        auth_type = eCSR_AUTH_TYPE_RSN;
    } else 
    if (memcmp(auth_suite , ccpRSNOui02, 4) == 0) 
    {
        auth_type = eCSR_AUTH_TYPE_RSN_PSK;
    } else 
#ifdef WLAN_FEATURE_VOWIFI_11R
    if (memcmp(auth_suite , ccpRSNOui04, 4) == 0) 
    {
        // Check for 11r FT Authentication with PSK
        auth_type = eCSR_AUTH_TYPE_FT_RSN_PSK;
    } else 
    if (memcmp(auth_suite , ccpRSNOui03, 4) == 0) 
    {
        // Check for 11R FT Authentication with 802.1X
        auth_type = eCSR_AUTH_TYPE_FT_RSN;
    } else 
#endif
#ifdef FEATURE_WLAN_CCX
<<<<<<< HEAD
    if (memcmp(auth_suite , ccpRSNOui06, 4) == 0)
>>>>>>> d97af3b... add prima wlan driver
=======
    if (memcmp(auth_suite , ccpRSNOui06, 4) == 0) 
>>>>>>> 657b0e9... prima update
    {
        auth_type = eCSR_AUTH_TYPE_CCKM_RSN;
    } else
#endif /* FEATURE_WLAN_CCX */
<<<<<<< HEAD
<<<<<<< HEAD
    { 
        auth_type = eCSR_AUTH_TYPE_UNKNOWN;
    }
    return auth_type;
} 
#ifdef WLAN_SOFTAP_FEATURE
eCsrAuthType 
hdd_TranslateWPAToCsrAuthType(u_int8_t auth_suite[4]) 
#else
static eCsrAuthType hdd_TranslateWPAToCsrAuthType(u_int8_t auth_suite[4]) 
#endif
{
    eCsrAuthType auth_type;
    // is the auth type supported?
    if ( memcmp(auth_suite , ccpWpaOui01, 4) == 0) 
    {
        auth_type = eCSR_AUTH_TYPE_WPA;
    } else 
    if (memcmp(auth_suite , ccpWpaOui02, 4) == 0) 
    {
        auth_type = eCSR_AUTH_TYPE_WPA_PSK;
    } else 
#ifdef FEATURE_WLAN_CCX
    if (memcmp(auth_suite , ccpWpaOui06, 4) == 0) 
    {
        auth_type = eCSR_AUTH_TYPE_CCKM_WPA;
    } else 
#endif /* FEATURE_WLAN_CCX */
    { 
=======
#ifdef WLAN_FEATURE_11W
    if (memcmp(auth_suite , ccpRSNOui07, 4) == 0)
    {
        auth_type = eCSR_AUTH_TYPE_RSN_PSK_SHA256;
    } else
#endif
    {
=======
    { 
>>>>>>> 657b0e9... prima update
        auth_type = eCSR_AUTH_TYPE_UNKNOWN;
    }
    return auth_type;
} 
#ifdef WLAN_SOFTAP_FEATURE
eCsrAuthType 
hdd_TranslateWPAToCsrAuthType(u_int8_t auth_suite[4]) 
#else
static eCsrAuthType hdd_TranslateWPAToCsrAuthType(u_int8_t auth_suite[4]) 
#endif
{
    eCsrAuthType auth_type;
    // is the auth type supported?
    if ( memcmp(auth_suite , ccpWpaOui01, 4) == 0) 
    {
        auth_type = eCSR_AUTH_TYPE_WPA;
    } else 
    if (memcmp(auth_suite , ccpWpaOui02, 4) == 0) 
    {
        auth_type = eCSR_AUTH_TYPE_WPA_PSK;
    } else 
#ifdef FEATURE_WLAN_CCX
    if (memcmp(auth_suite , ccpWpaOui06, 4) == 0) 
    {
        auth_type = eCSR_AUTH_TYPE_CCKM_WPA;
    } else 
#endif /* FEATURE_WLAN_CCX */
<<<<<<< HEAD
    {
>>>>>>> d97af3b... add prima wlan driver
=======
    { 
>>>>>>> 657b0e9... prima update
        auth_type = eCSR_AUTH_TYPE_UNKNOWN;
    }
    hddLog(LOG1, FL("auth_type: %d"), auth_type);
    return auth_type;
}
<<<<<<< HEAD
<<<<<<< HEAD
#ifdef WLAN_SOFTAP_FEATURE
eCsrEncryptionType 
hdd_TranslateRSNToCsrEncryptionType(u_int8_t cipher_suite[4])
#else
static eCsrEncryptionType hdd_TranslateRSNToCsrEncryptionType(u_int8_t cipher_suite[4])                                    
#endif
{
    eCsrEncryptionType cipher_type;
    // is the cipher type supported?
    if ( memcmp(cipher_suite , ccpRSNOui04, 4) == 0) 
    {
        cipher_type = eCSR_ENCRYPT_TYPE_AES;
    } 
    else if (memcmp(cipher_suite , ccpRSNOui02, 4) == 0) 
    {
        cipher_type = eCSR_ENCRYPT_TYPE_TKIP;
    } 
    else if (memcmp(cipher_suite , ccpRSNOui00, 4) == 0) 
    {
        cipher_type = eCSR_ENCRYPT_TYPE_NONE;
    } 
    else if (memcmp(cipher_suite , ccpRSNOui01, 4) == 0) 
    {
        cipher_type = eCSR_ENCRYPT_TYPE_WEP40_STATICKEY;
    } 
    else if (memcmp(cipher_suite , ccpRSNOui05, 4) == 0) 
    {        
        cipher_type = eCSR_ENCRYPT_TYPE_WEP104_STATICKEY; 
    } 
    else 
    { 
=======

eCsrEncryptionType
=======
#ifdef WLAN_SOFTAP_FEATURE
eCsrEncryptionType 
>>>>>>> 657b0e9... prima update
hdd_TranslateRSNToCsrEncryptionType(u_int8_t cipher_suite[4])
#else
static eCsrEncryptionType hdd_TranslateRSNToCsrEncryptionType(u_int8_t cipher_suite[4])                                    
#endif
{
    eCsrEncryptionType cipher_type;
    // is the cipher type supported?
    if ( memcmp(cipher_suite , ccpRSNOui04, 4) == 0) 
    {
        cipher_type = eCSR_ENCRYPT_TYPE_AES;
    } 
    else if (memcmp(cipher_suite , ccpRSNOui02, 4) == 0) 
    {
        cipher_type = eCSR_ENCRYPT_TYPE_TKIP;
    } 
    else if (memcmp(cipher_suite , ccpRSNOui00, 4) == 0) 
    {
        cipher_type = eCSR_ENCRYPT_TYPE_NONE;
    } 
    else if (memcmp(cipher_suite , ccpRSNOui01, 4) == 0) 
    {
        cipher_type = eCSR_ENCRYPT_TYPE_WEP40_STATICKEY;
<<<<<<< HEAD
    }
    else if (memcmp(cipher_suite , ccpRSNOui05, 4) == 0)
    {
        cipher_type = eCSR_ENCRYPT_TYPE_WEP104_STATICKEY;
    }
    else
    {
>>>>>>> d97af3b... add prima wlan driver
=======
    } 
    else if (memcmp(cipher_suite , ccpRSNOui05, 4) == 0) 
    {        
        cipher_type = eCSR_ENCRYPT_TYPE_WEP104_STATICKEY; 
    } 
    else 
    { 
>>>>>>> 657b0e9... prima update
        cipher_type = eCSR_ENCRYPT_TYPE_FAILED;
    }
    hddLog(LOG1, FL("cipher_type: %d"), cipher_type);
    return cipher_type;
<<<<<<< HEAD
<<<<<<< HEAD
} 
=======
}
>>>>>>> d97af3b... add prima wlan driver
=======
} 
>>>>>>> 657b0e9... prima update
/* To find if the MAC address is NULL */
static tANI_U8 hdd_IsMACAddrNULL (tANI_U8 *macAddr, tANI_U8 length)
{
    int i;
    for (i = 0; i < length; i++)
    {
        if (0x00 != (macAddr[i]))
        {
            return FALSE;
        }
    }
    return TRUE;
} /****** end hdd_IsMACAddrNULL() ******/
<<<<<<< HEAD
<<<<<<< HEAD
#ifdef WLAN_SOFTAP_FEATURE
eCsrEncryptionType 
hdd_TranslateWPAToCsrEncryptionType(u_int8_t cipher_suite[4])
#else
static eCsrEncryptionType 
hdd_TranslateWPAToCsrEncryptionType(u_int8_t cipher_suite[4])                                    
#endif
{
    eCsrEncryptionType cipher_type;
    // is the cipher type supported?
    if ( memcmp(cipher_suite , ccpWpaOui04, 4) == 0) 
    {
        cipher_type = eCSR_ENCRYPT_TYPE_AES;
    } else 
    if (memcmp(cipher_suite , ccpWpaOui02, 4) == 0) 
    {
        cipher_type = eCSR_ENCRYPT_TYPE_TKIP;
    } else 
    if (memcmp(cipher_suite , ccpWpaOui00, 4) == 0) 
    {
        cipher_type = eCSR_ENCRYPT_TYPE_NONE;
    } else 
    if (memcmp(cipher_suite , ccpWpaOui01, 4) == 0) 
    {
        cipher_type = eCSR_ENCRYPT_TYPE_WEP40_STATICKEY;
    } else 
    if (memcmp(cipher_suite , ccpWpaOui05, 4) == 0) 
    {
        cipher_type = eCSR_ENCRYPT_TYPE_WEP104_STATICKEY; 
    } else 
    { 
=======

eCsrEncryptionType
=======
#ifdef WLAN_SOFTAP_FEATURE
eCsrEncryptionType 
>>>>>>> 657b0e9... prima update
hdd_TranslateWPAToCsrEncryptionType(u_int8_t cipher_suite[4])
#else
static eCsrEncryptionType 
hdd_TranslateWPAToCsrEncryptionType(u_int8_t cipher_suite[4])                                    
#endif
{
    eCsrEncryptionType cipher_type;
    // is the cipher type supported?
    if ( memcmp(cipher_suite , ccpWpaOui04, 4) == 0) 
    {
        cipher_type = eCSR_ENCRYPT_TYPE_AES;
    } else 
    if (memcmp(cipher_suite , ccpWpaOui02, 4) == 0) 
    {
        cipher_type = eCSR_ENCRYPT_TYPE_TKIP;
    } else 
    if (memcmp(cipher_suite , ccpWpaOui00, 4) == 0) 
    {
        cipher_type = eCSR_ENCRYPT_TYPE_NONE;
    } else 
    if (memcmp(cipher_suite , ccpWpaOui01, 4) == 0) 
    {
        cipher_type = eCSR_ENCRYPT_TYPE_WEP40_STATICKEY;
    } else 
    if (memcmp(cipher_suite , ccpWpaOui05, 4) == 0) 
    {
<<<<<<< HEAD
>>>>>>> d97af3b... add prima wlan driver
=======
        cipher_type = eCSR_ENCRYPT_TYPE_WEP104_STATICKEY; 
    } else 
    { 
>>>>>>> 657b0e9... prima update
        cipher_type = eCSR_ENCRYPT_TYPE_FAILED;
    }
    hddLog(LOG1, FL("cipher_type: %d"), cipher_type);
    return cipher_type;
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
} 

static tANI_S32 hdd_ProcessGENIE(hdd_adapter_t *pAdapter, 
                struct ether_addr *pBssid, 
                eCsrEncryptionType *pEncryptType, 
                eCsrEncryptionType *mcEncryptType, 
                eCsrAuthType *pAuthType, 
                u_int16_t gen_ie_len, 
                u_int8_t *gen_ie) 
<<<<<<< HEAD
{
    tHalHandle halHandle = WLAN_HDD_GET_HAL_CTX(pAdapter);
    eHalStatus result; 
    tDot11fIERSN dot11RSNIE; 
    tDot11fIEWPA dot11WPAIE; 
    tANI_U32 i; 
    tANI_U8 *pRsnIe; 
    tANI_U16 RSNIeLen; 
    tPmkidCacheInfo PMKIDCache[4]; // Local transfer memory
=======
}

static tANI_S32 hdd_ProcessGENIE(hdd_adapter_t *pAdapter,
                struct ether_addr *pBssid,
                eCsrEncryptionType *pEncryptType,
                eCsrEncryptionType *mcEncryptType,
                eCsrAuthType *pAuthType,
#ifdef WLAN_FEATURE_11W
                u_int8_t *pMfpRequired,
                u_int8_t *pMfpCapable,
#endif
                u_int16_t gen_ie_len,
                u_int8_t *gen_ie)
=======
>>>>>>> 657b0e9... prima update
{
    tHalHandle halHandle = WLAN_HDD_GET_HAL_CTX(pAdapter);
    eHalStatus result; 
    tDot11fIERSN dot11RSNIE; 
    tDot11fIEWPA dot11WPAIE; 
    tANI_U32 i; 
    tANI_U8 *pRsnIe; 
    tANI_U16 RSNIeLen; 
    tPmkidCacheInfo PMKIDCache[4]; // Local transfer memory
<<<<<<< HEAD
    v_BOOL_t updatePMKCache = FALSE;
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update

    /* Clear struct of tDot11fIERSN and tDot11fIEWPA specifically setting present
       flag to 0 */
    memset( &dot11WPAIE, 0 , sizeof(tDot11fIEWPA) );
    memset( &dot11RSNIE, 0 , sizeof(tDot11fIERSN) );

    // Validity checks
<<<<<<< HEAD
<<<<<<< HEAD
    if ((gen_ie_len < VOS_MIN(DOT11F_IE_RSN_MIN_LEN, DOT11F_IE_WPA_MIN_LEN)) ||  
            (gen_ie_len > VOS_MAX(DOT11F_IE_RSN_MAX_LEN, DOT11F_IE_WPA_MAX_LEN)) ) 
        return -EINVAL;
    // Type check
    if ( gen_ie[0] ==  DOT11F_EID_RSN) 
    {         
        // Validity checks
        if ((gen_ie_len < DOT11F_IE_RSN_MIN_LEN ) ||  
=======
    if ((gen_ie_len < VOS_MIN(DOT11F_IE_RSN_MIN_LEN, DOT11F_IE_WPA_MIN_LEN)) ||
            (gen_ie_len > VOS_MAX(DOT11F_IE_RSN_MAX_LEN, DOT11F_IE_WPA_MAX_LEN)) )
=======
    if ((gen_ie_len < VOS_MIN(DOT11F_IE_RSN_MIN_LEN, DOT11F_IE_WPA_MIN_LEN)) ||  
            (gen_ie_len > VOS_MAX(DOT11F_IE_RSN_MAX_LEN, DOT11F_IE_WPA_MAX_LEN)) ) 
>>>>>>> 657b0e9... prima update
        return -EINVAL;
    // Type check
    if ( gen_ie[0] ==  DOT11F_EID_RSN) 
    {         
        // Validity checks
<<<<<<< HEAD
        if ((gen_ie_len < DOT11F_IE_RSN_MIN_LEN ) ||
>>>>>>> d97af3b... add prima wlan driver
=======
        if ((gen_ie_len < DOT11F_IE_RSN_MIN_LEN ) ||  
>>>>>>> 657b0e9... prima update
                (gen_ie_len > DOT11F_IE_RSN_MAX_LEN) )
        {
            return -EINVAL;
        }
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
        // Skip past the EID byte and length byte  
        pRsnIe = gen_ie + 2; 
        RSNIeLen = gen_ie_len - 2; 
        // Unpack the RSN IE 
        dot11fUnpackIeRSN((tpAniSirGlobal) halHandle, 
                            pRsnIe, 
                            RSNIeLen, 
<<<<<<< HEAD
                            &dot11RSNIE);
        // Copy out the encryption and authentication types 
        hddLog(LOG1, FL("%s: pairwise cipher suite count: %d"), 
                __FUNCTION__, dot11RSNIE.pwise_cipher_suite_count );
        hddLog(LOG1, FL("%s: authentication suite count: %d"), 
                __FUNCTION__, dot11RSNIE.akm_suite_count);
        /*Here we have followed the apple base code, 
          but probably I suspect we can do something different*/
        //dot11RSNIE.akm_suite_count
        // Just translate the FIRST one 
        *pAuthType =  hdd_TranslateRSNToCsrAuthType(dot11RSNIE.akm_suites[0]); 
        //dot11RSNIE.pwise_cipher_suite_count 
        *pEncryptType = hdd_TranslateRSNToCsrEncryptionType(dot11RSNIE.pwise_cipher_suites[0]);                     
        //dot11RSNIE.gp_cipher_suite_count 
        *mcEncryptType = hdd_TranslateRSNToCsrEncryptionType(dot11RSNIE.gp_cipher_suite);                     
        // Set the PMKSA ID Cache for this interface
        for (i=0; i<dot11RSNIE.pmkid_count; i++) 
        {
            if ( pBssid == NULL) 
            {
                break;
            }
            if ( hdd_IsMACAddrNULL( (u_char *) pBssid , sizeof( (char *) pBssid))) 
            {
                break;
            }
=======
        // Skip past the EID byte and length byte
        pRsnIe = gen_ie + 2;
        RSNIeLen = gen_ie_len - 2;
        // Unpack the RSN IE
        dot11fUnpackIeRSN((tpAniSirGlobal) halHandle,
                            pRsnIe,
                            RSNIeLen,
=======
>>>>>>> 657b0e9... prima update
                            &dot11RSNIE);
        // Copy out the encryption and authentication types 
        hddLog(LOG1, FL("%s: pairwise cipher suite count: %d"), 
                __FUNCTION__, dot11RSNIE.pwise_cipher_suite_count );
        hddLog(LOG1, FL("%s: authentication suite count: %d"), 
                __FUNCTION__, dot11RSNIE.akm_suite_count);
        /*Here we have followed the apple base code, 
          but probably I suspect we can do something different*/
        //dot11RSNIE.akm_suite_count
        // Just translate the FIRST one 
        *pAuthType =  hdd_TranslateRSNToCsrAuthType(dot11RSNIE.akm_suites[0]); 
        //dot11RSNIE.pwise_cipher_suite_count 
        *pEncryptType = hdd_TranslateRSNToCsrEncryptionType(dot11RSNIE.pwise_cipher_suites[0]);                     
        //dot11RSNIE.gp_cipher_suite_count 
        *mcEncryptType = hdd_TranslateRSNToCsrEncryptionType(dot11RSNIE.gp_cipher_suite);                     
        // Set the PMKSA ID Cache for this interface
        for (i=0; i<dot11RSNIE.pmkid_count; i++) 
        {
            if ( pBssid == NULL) 
            {
                break;
            }
            if ( hdd_IsMACAddrNULL( (u_char *) pBssid , sizeof( (char *) pBssid))) 
            {
                break;
            }
<<<<<<< HEAD
            updatePMKCache = TRUE;
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
            // For right now, I assume setASSOCIATE() has passed in the bssid.
            vos_mem_copy(PMKIDCache[i].BSSID,
                            pBssid, ETHER_ADDR_LEN);
            vos_mem_copy(PMKIDCache[i].PMKID,
                            dot11RSNIE.pmkid[i],
                            CSR_RSN_PMKID_SIZE);
        }
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
        // Calling csrRoamSetPMKIDCache to configure the PMKIDs into the cache
        hddLog(LOG1, FL("%s: Calling csrRoamSetPMKIDCache with cache entry %ld."), 
                                                                            __FUNCTION__, i );
        // Finally set the PMKSA ID Cache in CSR
        result = sme_RoamSetPMKIDCache(halHandle,pAdapter->sessionId,
                                        PMKIDCache, 
                                        dot11RSNIE.pmkid_count );
<<<<<<< HEAD
=======

        if (updatePMKCache)
        {
            // Calling csrRoamSetPMKIDCache to configure the PMKIDs into the cache
            hddLog(LOG1, FL("%s: Calling csrRoamSetPMKIDCache with cache entry %ld."),
                                                                            __func__, i );
            // Finally set the PMKSA ID Cache in CSR
            result = sme_RoamSetPMKIDCache(halHandle,pAdapter->sessionId,
                                           PMKIDCache,
                                           dot11RSNIE.pmkid_count );
        }
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
    }
    else if (gen_ie[0] == DOT11F_EID_WPA)
    {
        // Validity checks
        if ((gen_ie_len < DOT11F_IE_WPA_MIN_LEN ) ||
                    (gen_ie_len > DOT11F_IE_WPA_MAX_LEN))
        {
            return -EINVAL;
        }
        // Skip past the EID byte and length byte - and four byte WiFi OUI
<<<<<<< HEAD
<<<<<<< HEAD
        pRsnIe = gen_ie + 2 + 4; 
        RSNIeLen = gen_ie_len - (2 + 4); 
        // Unpack the WPA IE 
=======
        pRsnIe = gen_ie + 2 + 4;
        RSNIeLen = gen_ie_len - (2 + 4);
        // Unpack the WPA IE
>>>>>>> d97af3b... add prima wlan driver
=======
        pRsnIe = gen_ie + 2 + 4; 
        RSNIeLen = gen_ie_len - (2 + 4); 
        // Unpack the WPA IE 
>>>>>>> 657b0e9... prima update
        dot11fUnpackIeWPA((tpAniSirGlobal) halHandle,
                            pRsnIe,
                            RSNIeLen,
                            &dot11WPAIE);
        // Copy out the encryption and authentication types
        hddLog(LOG1, FL("%s: WPA unicast cipher suite count: %d"),
<<<<<<< HEAD
<<<<<<< HEAD
               __FUNCTION__, dot11WPAIE.unicast_cipher_count );
        hddLog(LOG1, FL("%s: WPA authentication suite count: %d"),
               __FUNCTION__, dot11WPAIE.auth_suite_count);
=======
               __func__, dot11WPAIE.unicast_cipher_count );
        hddLog(LOG1, FL("%s: WPA authentication suite count: %d"),
               __func__, dot11WPAIE.auth_suite_count);
>>>>>>> d97af3b... add prima wlan driver
=======
               __FUNCTION__, dot11WPAIE.unicast_cipher_count );
        hddLog(LOG1, FL("%s: WPA authentication suite count: %d"),
               __FUNCTION__, dot11WPAIE.auth_suite_count);
>>>>>>> 657b0e9... prima update
        //dot11WPAIE.auth_suite_count
        // Just translate the FIRST one
        *pAuthType =  hdd_TranslateWPAToCsrAuthType(dot11WPAIE.auth_suites[0]);
        //dot11WPAIE.unicast_cipher_count
        *pEncryptType = hdd_TranslateWPAToCsrEncryptionType(dot11WPAIE.unicast_ciphers[0]);
        //dot11WPAIE.unicast_cipher_count
        *mcEncryptType = hdd_TranslateWPAToCsrEncryptionType(dot11WPAIE.multicast_cipher);
    }
    else
    {
        hddLog(LOGW, FL("gen_ie[0]: %d"), gen_ie[0]);
<<<<<<< HEAD
<<<<<<< HEAD
        return -EINVAL; 
=======
        return -EINVAL;
>>>>>>> d97af3b... add prima wlan driver
=======
        return -EINVAL; 
>>>>>>> 657b0e9... prima update
    }
    return 0;
}
int hdd_SetGENIEToCsr( hdd_adapter_t *pAdapter, eCsrAuthType *RSNAuthType)
{
    hdd_wext_state_t *pWextState = WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter);
    v_U32_t status = 0;
    eCsrEncryptionType RSNEncryptType;
    eCsrEncryptionType mcRSNEncryptType;
<<<<<<< HEAD
<<<<<<< HEAD
=======
#ifdef WLAN_FEATURE_11W
    u_int8_t RSNMfpRequired;
    u_int8_t RSNMfpCapable;
#endif
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
    struct ether_addr   bSsid;   // MAC address of assoc peer
    // MAC address of assoc peer
    // But, this routine is only called when we are NOT associated.
    vos_mem_copy(bSsid.ether_addr_octet,
            pWextState->roamProfile.BSSIDs.bssid,
            sizeof(bSsid.ether_addr_octet));
    if (pWextState->WPARSNIE[0] == DOT11F_EID_RSN || pWextState->WPARSNIE[0] == DOT11F_EID_WPA)
    {
        //continue
<<<<<<< HEAD
<<<<<<< HEAD
    } 
=======
    }
>>>>>>> d97af3b... add prima wlan driver
=======
    } 
>>>>>>> 657b0e9... prima update
    else
    {
        return 0;
    }
    // The actual processing may eventually be more extensive than this.
    // Right now, just consume any PMKIDs that are  sent in by the app.
    status = hdd_ProcessGENIE(pAdapter,
            &bSsid,   // MAC address of assoc peer
            &RSNEncryptType,
            &mcRSNEncryptType,
            RSNAuthType,
<<<<<<< HEAD
<<<<<<< HEAD
=======
#ifdef WLAN_FEATURE_11W
            &RSNMfpRequired,
            &RSNMfpCapable,
#endif
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
            pWextState->WPARSNIE[1]+2,
            pWextState->WPARSNIE);
    if (status == 0)
    {
        // Now copy over all the security attributes you have parsed out
        pWextState->roamProfile.EncryptionType.numEntries = 1;
        pWextState->roamProfile.mcEncryptionType.numEntries = 1;
<<<<<<< HEAD
<<<<<<< HEAD
        
        pWextState->roamProfile.EncryptionType.encryptionType[0] = RSNEncryptType; // Use the cipher type in the RSN IE
        pWextState->roamProfile.mcEncryptionType.encryptionType[0] = mcRSNEncryptType;
        hddLog( LOG1, "%s: CSR AuthType = %d, EncryptionType = %d mcEncryptionType = %d", __FUNCTION__, *RSNAuthType, RSNEncryptType, mcRSNEncryptType);
=======

        pWextState->roamProfile.EncryptionType.encryptionType[0] = RSNEncryptType; // Use the cipher type in the RSN IE
        pWextState->roamProfile.mcEncryptionType.encryptionType[0] = mcRSNEncryptType;

        if ( (WLAN_HDD_IBSS == pAdapter->device_mode) &&
             ((eCSR_ENCRYPT_TYPE_AES == mcRSNEncryptType) ||
             (eCSR_ENCRYPT_TYPE_TKIP == mcRSNEncryptType)))
        {
           /*For wpa none supplicant sends the WPA IE with unicast cipher as
             eCSR_ENCRYPT_TYPE_NONE ,where as the multicast cipher as
             either AES/TKIP based on group cipher configuration
             mentioned in the wpa_supplicant.conf.*/

           /*Set the unicast cipher same as multicast cipher*/
           pWextState->roamProfile.EncryptionType.encryptionType[0]
                                                     = mcRSNEncryptType;
        }

#ifdef WLAN_FEATURE_11W
        pWextState->roamProfile.MFPRequired = RSNMfpRequired;
        pWextState->roamProfile.MFPCapable = RSNMfpCapable;
#endif
        hddLog( LOG1, "%s: CSR AuthType = %d, EncryptionType = %d mcEncryptionType = %d", __func__, *RSNAuthType, RSNEncryptType, mcRSNEncryptType);
>>>>>>> d97af3b... add prima wlan driver
=======
        
        pWextState->roamProfile.EncryptionType.encryptionType[0] = RSNEncryptType; // Use the cipher type in the RSN IE
        pWextState->roamProfile.mcEncryptionType.encryptionType[0] = mcRSNEncryptType;
        hddLog( LOG1, "%s: CSR AuthType = %d, EncryptionType = %d mcEncryptionType = %d", __FUNCTION__, *RSNAuthType, RSNEncryptType, mcRSNEncryptType);
>>>>>>> 657b0e9... prima update
    }
    return 0;
}
int hdd_set_csr_auth_type ( hdd_adapter_t  *pAdapter, eCsrAuthType RSNAuthType)
{
    hdd_wext_state_t *pWextState = WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter);
    tCsrRoamProfile* pRoamProfile = &(pWextState->roamProfile);
    hdd_station_ctx_t *pHddStaCtx = WLAN_HDD_GET_STATION_CTX_PTR(pAdapter);
    ENTER();
<<<<<<< HEAD
<<<<<<< HEAD
    
    pRoamProfile->AuthType.numEntries = 1;
    hddLog( LOG1, "%s: pHddStaCtx->conn_info.authType = %d\n", __FUNCTION__, pHddStaCtx->conn_info.authType);
      
=======

    pRoamProfile->AuthType.numEntries = 1;
    hddLog( LOG1, "%s: pHddStaCtx->conn_info.authType = %d\n", __func__, pHddStaCtx->conn_info.authType);

>>>>>>> d97af3b... add prima wlan driver
=======
    
    pRoamProfile->AuthType.numEntries = 1;
    hddLog( LOG1, "%s: pHddStaCtx->conn_info.authType = %d\n", __FUNCTION__, pHddStaCtx->conn_info.authType);
      
>>>>>>> 657b0e9... prima update
    switch( pHddStaCtx->conn_info.authType)
    {
       case eCSR_AUTH_TYPE_OPEN_SYSTEM:
#ifdef FEATURE_WLAN_CCX
       case eCSR_AUTH_TYPE_CCKM_WPA:
       case eCSR_AUTH_TYPE_CCKM_RSN:
#endif
<<<<<<< HEAD
<<<<<<< HEAD
        if (pWextState->wpaVersion & IW_AUTH_WPA_VERSION_DISABLED) {           
           
           pRoamProfile->AuthType.authType[0] = eCSR_AUTH_TYPE_OPEN_SYSTEM ;
        } else 
        if (pWextState->wpaVersion & IW_AUTH_WPA_VERSION_WPA) {
           
#ifdef FEATURE_WLAN_CCX
            if ((RSNAuthType == eCSR_AUTH_TYPE_CCKM_WPA) && 
                ((pWextState->authKeyMgmt & IW_AUTH_KEY_MGMT_802_1X) 
                 == IW_AUTH_KEY_MGMT_802_1X)) { 
                hddLog( LOG1, "%s: set authType to CCKM WPA. AKM also 802.1X.\n", __FUNCTION__);
                pRoamProfile->AuthType.authType[0] = eCSR_AUTH_TYPE_CCKM_WPA;   
            } else 
            if ((RSNAuthType == eCSR_AUTH_TYPE_CCKM_WPA)) { 
                hddLog( LOG1, "%s: Last chance to set authType to CCKM WPA.\n", __FUNCTION__);
                pRoamProfile->AuthType.authType[0] = eCSR_AUTH_TYPE_CCKM_WPA;   
=======
        if (pWextState->wpaVersion & IW_AUTH_WPA_VERSION_DISABLED) {

=======
        if (pWextState->wpaVersion & IW_AUTH_WPA_VERSION_DISABLED) {           
           
>>>>>>> 657b0e9... prima update
           pRoamProfile->AuthType.authType[0] = eCSR_AUTH_TYPE_OPEN_SYSTEM ;
        } else 
        if (pWextState->wpaVersion & IW_AUTH_WPA_VERSION_WPA) {
           
#ifdef FEATURE_WLAN_CCX
<<<<<<< HEAD
            if ((RSNAuthType == eCSR_AUTH_TYPE_CCKM_WPA) &&
                ((pWextState->authKeyMgmt & IW_AUTH_KEY_MGMT_802_1X)
                 == IW_AUTH_KEY_MGMT_802_1X)) {
                hddLog( LOG1, "%s: set authType to CCKM WPA. AKM also 802.1X.\n", __func__);
                pRoamProfile->AuthType.authType[0] = eCSR_AUTH_TYPE_CCKM_WPA;
            } else
            if ((RSNAuthType == eCSR_AUTH_TYPE_CCKM_WPA)) {
                hddLog( LOG1, "%s: Last chance to set authType to CCKM WPA.\n", __func__);
                pRoamProfile->AuthType.authType[0] = eCSR_AUTH_TYPE_CCKM_WPA;
>>>>>>> d97af3b... add prima wlan driver
=======
            if ((RSNAuthType == eCSR_AUTH_TYPE_CCKM_WPA) && 
                ((pWextState->authKeyMgmt & IW_AUTH_KEY_MGMT_802_1X) 
                 == IW_AUTH_KEY_MGMT_802_1X)) { 
                hddLog( LOG1, "%s: set authType to CCKM WPA. AKM also 802.1X.\n", __FUNCTION__);
                pRoamProfile->AuthType.authType[0] = eCSR_AUTH_TYPE_CCKM_WPA;   
            } else 
            if ((RSNAuthType == eCSR_AUTH_TYPE_CCKM_WPA)) { 
                hddLog( LOG1, "%s: Last chance to set authType to CCKM WPA.\n", __FUNCTION__);
                pRoamProfile->AuthType.authType[0] = eCSR_AUTH_TYPE_CCKM_WPA;   
>>>>>>> 657b0e9... prima update
            } else
#endif
            if((pWextState->authKeyMgmt & IW_AUTH_KEY_MGMT_802_1X)
                    == IW_AUTH_KEY_MGMT_802_1X) {
<<<<<<< HEAD
<<<<<<< HEAD
               pRoamProfile->AuthType.authType[0] = eCSR_AUTH_TYPE_WPA;   
            } else 
            if ((pWextState->authKeyMgmt & IW_AUTH_KEY_MGMT_PSK)
                    == IW_AUTH_KEY_MGMT_PSK) {
               pRoamProfile->AuthType.authType[0] = eCSR_AUTH_TYPE_WPA_PSK;
            } else {     
               pRoamProfile->AuthType.authType[0] = eCSR_AUTH_TYPE_WPA_NONE;
            }    
        }
        if (pWextState->wpaVersion & IW_AUTH_WPA_VERSION_WPA2) {
#ifdef FEATURE_WLAN_CCX
            if ((RSNAuthType == eCSR_AUTH_TYPE_CCKM_RSN) && 
                ((pWextState->authKeyMgmt & IW_AUTH_KEY_MGMT_802_1X) 
                 == IW_AUTH_KEY_MGMT_802_1X)) { 
                hddLog( LOG1, "%s: set authType to CCKM RSN. AKM also 802.1X.\n", __FUNCTION__);
                pRoamProfile->AuthType.authType[0] = eCSR_AUTH_TYPE_CCKM_RSN;   
            } else
            if ((RSNAuthType == eCSR_AUTH_TYPE_CCKM_RSN)) { 
                hddLog( LOG1, "%s: Last chance to set authType to CCKM RSN.\n", __FUNCTION__);
                pRoamProfile->AuthType.authType[0] = eCSR_AUTH_TYPE_CCKM_RSN;   
=======
               pRoamProfile->AuthType.authType[0] = eCSR_AUTH_TYPE_WPA;
            } else
=======
               pRoamProfile->AuthType.authType[0] = eCSR_AUTH_TYPE_WPA;   
            } else 
>>>>>>> 657b0e9... prima update
            if ((pWextState->authKeyMgmt & IW_AUTH_KEY_MGMT_PSK)
                    == IW_AUTH_KEY_MGMT_PSK) {
               pRoamProfile->AuthType.authType[0] = eCSR_AUTH_TYPE_WPA_PSK;
            } else {     
               pRoamProfile->AuthType.authType[0] = eCSR_AUTH_TYPE_WPA_NONE;
            }    
        }
        if (pWextState->wpaVersion & IW_AUTH_WPA_VERSION_WPA2) {
#ifdef FEATURE_WLAN_CCX
            if ((RSNAuthType == eCSR_AUTH_TYPE_CCKM_RSN) && 
                ((pWextState->authKeyMgmt & IW_AUTH_KEY_MGMT_802_1X) 
                 == IW_AUTH_KEY_MGMT_802_1X)) { 
                hddLog( LOG1, "%s: set authType to CCKM RSN. AKM also 802.1X.\n", __FUNCTION__);
                pRoamProfile->AuthType.authType[0] = eCSR_AUTH_TYPE_CCKM_RSN;   
            } else
<<<<<<< HEAD
            if ((RSNAuthType == eCSR_AUTH_TYPE_CCKM_RSN)) {
                hddLog( LOG1, "%s: Last chance to set authType to CCKM RSN.\n", __func__);
                pRoamProfile->AuthType.authType[0] = eCSR_AUTH_TYPE_CCKM_RSN;
>>>>>>> d97af3b... add prima wlan driver
=======
            if ((RSNAuthType == eCSR_AUTH_TYPE_CCKM_RSN)) { 
                hddLog( LOG1, "%s: Last chance to set authType to CCKM RSN.\n", __FUNCTION__);
                pRoamProfile->AuthType.authType[0] = eCSR_AUTH_TYPE_CCKM_RSN;   
>>>>>>> 657b0e9... prima update
            } else
#endif

#ifdef WLAN_FEATURE_VOWIFI_11R
<<<<<<< HEAD
<<<<<<< HEAD
            if ((RSNAuthType == eCSR_AUTH_TYPE_FT_RSN) && 
                ((pWextState->authKeyMgmt & IW_AUTH_KEY_MGMT_802_1X) 
                 == IW_AUTH_KEY_MGMT_802_1X)) {
               pRoamProfile->AuthType.authType[0] = eCSR_AUTH_TYPE_FT_RSN;   
            }else
            if ((RSNAuthType == eCSR_AUTH_TYPE_FT_RSN_PSK) && 
                ((pWextState->authKeyMgmt & IW_AUTH_KEY_MGMT_PSK)
                 == IW_AUTH_KEY_MGMT_PSK)) {
               pRoamProfile->AuthType.authType[0] = eCSR_AUTH_TYPE_FT_RSN_PSK;   
            } else
#endif

            if( (pWextState->authKeyMgmt & IW_AUTH_KEY_MGMT_802_1X) 
                    == IW_AUTH_KEY_MGMT_802_1X) {
               pRoamProfile->AuthType.authType[0] = eCSR_AUTH_TYPE_RSN;   
            } else 
            if ( (pWextState->authKeyMgmt & IW_AUTH_KEY_MGMT_PSK)
                    == IW_AUTH_KEY_MGMT_PSK) {
               pRoamProfile->AuthType.authType[0] = eCSR_AUTH_TYPE_RSN_PSK;
            } else {             
               pRoamProfile->AuthType.authType[0] = eCSR_AUTH_TYPE_UNKNOWN;
            }    
        }
        break;     
         
       case eCSR_AUTH_TYPE_SHARED_KEY:
         
          pRoamProfile->AuthType.authType[0] = eCSR_AUTH_TYPE_SHARED_KEY;  
          break;
        default:
         
#ifdef FEATURE_WLAN_CCX
           hddLog( LOG1, "%s: In default, unknown auth type.\n", __FUNCTION__); 
=======
            if ((RSNAuthType == eCSR_AUTH_TYPE_FT_RSN) &&
                ((pWextState->authKeyMgmt & IW_AUTH_KEY_MGMT_802_1X)
=======
            if ((RSNAuthType == eCSR_AUTH_TYPE_FT_RSN) && 
                ((pWextState->authKeyMgmt & IW_AUTH_KEY_MGMT_802_1X) 
>>>>>>> 657b0e9... prima update
                 == IW_AUTH_KEY_MGMT_802_1X)) {
               pRoamProfile->AuthType.authType[0] = eCSR_AUTH_TYPE_FT_RSN;   
            }else
            if ((RSNAuthType == eCSR_AUTH_TYPE_FT_RSN_PSK) && 
                ((pWextState->authKeyMgmt & IW_AUTH_KEY_MGMT_PSK)
                 == IW_AUTH_KEY_MGMT_PSK)) {
               pRoamProfile->AuthType.authType[0] = eCSR_AUTH_TYPE_FT_RSN_PSK;   
            } else
#endif

            if( (pWextState->authKeyMgmt & IW_AUTH_KEY_MGMT_802_1X) 
                    == IW_AUTH_KEY_MGMT_802_1X) {
               pRoamProfile->AuthType.authType[0] = eCSR_AUTH_TYPE_RSN;   
            } else 
            if ( (pWextState->authKeyMgmt & IW_AUTH_KEY_MGMT_PSK)
                    == IW_AUTH_KEY_MGMT_PSK) {
               pRoamProfile->AuthType.authType[0] = eCSR_AUTH_TYPE_RSN_PSK;
            } else {             
               pRoamProfile->AuthType.authType[0] = eCSR_AUTH_TYPE_UNKNOWN;
            }    
        }
        break;     
         
       case eCSR_AUTH_TYPE_SHARED_KEY:
         
          pRoamProfile->AuthType.authType[0] = eCSR_AUTH_TYPE_SHARED_KEY;  
          break;
        default:
         
#ifdef FEATURE_WLAN_CCX
<<<<<<< HEAD
           hddLog( LOG1, "%s: In default, unknown auth type.\n", __func__);
>>>>>>> d97af3b... add prima wlan driver
=======
           hddLog( LOG1, "%s: In default, unknown auth type.\n", __FUNCTION__); 
>>>>>>> 657b0e9... prima update
#endif /* FEATURE_WLAN_CCX */
           pRoamProfile->AuthType.authType[0] = eCSR_AUTH_TYPE_UNKNOWN;
           break;
    }
<<<<<<< HEAD
<<<<<<< HEAD
   
    hddLog( LOG1, "%s Set roam Authtype to %d",
            __FUNCTION__, pWextState->roamProfile.AuthType.authType[0]);
   
=======

    hddLog( LOG1, "%s Set roam Authtype to %d",
            __func__, pWextState->roamProfile.AuthType.authType[0]);

>>>>>>> d97af3b... add prima wlan driver
=======
   
    hddLog( LOG1, "%s Set roam Authtype to %d",
            __FUNCTION__, pWextState->roamProfile.AuthType.authType[0]);
   
>>>>>>> 657b0e9... prima update
   EXIT();
    return 0;
}

/**---------------------------------------------------------------------------
<<<<<<< HEAD
<<<<<<< HEAD
  
  \brief iw_set_essid() - 
   This function sets the ssid received from wpa_supplicant
   to the CSR roam profile. 
   
  \param  - dev - Pointer to the net device.
              - info - Pointer to the iw_request_info.
              - wrqu - Pointer to the iwreq_data.
              - extra - Pointer to the data.        
  \return - 0 for success, non zero for failure
  
  --------------------------------------------------------------------------*/

int iw_set_essid(struct net_device *dev, 
=======

  \brief iw_set_essid() -
=======
  
  \brief iw_set_essid() - 
>>>>>>> 657b0e9... prima update
   This function sets the ssid received from wpa_supplicant
   to the CSR roam profile. 
   
  \param  - dev - Pointer to the net device.
              - info - Pointer to the iw_request_info.
              - wrqu - Pointer to the iwreq_data.
              - extra - Pointer to the data.        
  \return - 0 for success, non zero for failure
  
  --------------------------------------------------------------------------*/

<<<<<<< HEAD
int iw_set_essid(struct net_device *dev,
>>>>>>> d97af3b... add prima wlan driver
=======
int iw_set_essid(struct net_device *dev, 
>>>>>>> 657b0e9... prima update
                        struct iw_request_info *info,
                        union iwreq_data *wrqu, char *extra)
{
    v_U32_t status = 0;
    hdd_wext_state_t *pWextState;
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
    v_U32_t roamId;
    tCsrRoamProfile          *pRoamProfile;
    eMib_dot11DesiredBssType connectedBssType;
    eCsrAuthType RSNAuthType;
    tHalHandle hHal = WLAN_HDD_GET_HAL_CTX(pAdapter);
    hdd_station_ctx_t *pHddStaCtx = WLAN_HDD_GET_STATION_CTX_PTR(pAdapter);
<<<<<<< HEAD
<<<<<<< HEAD
 
    pWextState = WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter); 
    
=======

    pWextState = WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter);

>>>>>>> d97af3b... add prima wlan driver
=======
 
    pWextState = WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter); 
    
>>>>>>> 657b0e9... prima update
    ENTER();

    if ((WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress)
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL,
                                  "%s:LOGP in Progress. Ignore!!!",__func__);
        return 0;
    }

    if(pWextState->mTKIPCounterMeasures == TKIP_COUNTER_MEASURE_STARTED) {
        hddLog(VOS_TRACE_LEVEL_INFO_HIGH, "%s :Counter measure is in progress", __func__);
        return -EBUSY;
    }
    if( SIR_MAC_MAX_SSID_LENGTH < wrqu->essid.length )
        return -EINVAL;
    pRoamProfile = &pWextState->roamProfile;
<<<<<<< HEAD
<<<<<<< HEAD
    if (pRoamProfile) 
=======
    if (pRoamProfile)
>>>>>>> d97af3b... add prima wlan driver
=======
    if (pRoamProfile) 
>>>>>>> 657b0e9... prima update
    {
        if ( hdd_connGetConnectedBssType( pHddStaCtx, &connectedBssType ) ||
             ( eMib_dot11DesiredBssType_independent == pHddStaCtx->conn_info.connDot11DesiredBssType ))
        {
            VOS_STATUS vosStatus;
<<<<<<< HEAD
<<<<<<< HEAD
            // need to issue a disconnect to CSR. 
=======
            // need to issue a disconnect to CSR.
>>>>>>> d97af3b... add prima wlan driver
=======
            // need to issue a disconnect to CSR. 
>>>>>>> 657b0e9... prima update
            INIT_COMPLETION(pAdapter->disconnect_comp_var);
            vosStatus = sme_RoamDisconnect( hHal, pAdapter->sessionId, eCSR_DISCONNECT_REASON_UNSPECIFIED );

            if(VOS_STATUS_SUCCESS == vosStatus)
               wait_for_completion_interruptible_timeout(&pAdapter->disconnect_comp_var,
                     msecs_to_jiffies(WLAN_WAIT_TIME_DISCONNECT));
        }
    }
    /** wpa_supplicant 0.8.x, wext driver uses */
<<<<<<< HEAD
<<<<<<< HEAD
    else 
=======
    else
>>>>>>> d97af3b... add prima wlan driver
=======
    else 
>>>>>>> 657b0e9... prima update
    {
        return -EINVAL;
    }
    /** wpa_supplicant 0.8.x, wext driver uses */
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
#ifdef CONFIG_CFG80211
    /** when cfg80211 defined, wpa_supplicant wext driver uses 
      zero-length, null-string ssid for force disconnection. 
      after disconnection (if previously connected) and cleaning ssid, 
<<<<<<< HEAD
=======
    /** when cfg80211 defined, wpa_supplicant wext driver uses
      zero-length, null-string ssid for force disconnection.
      after disconnection (if previously connected) and cleaning ssid,
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
      driver MUST return success */
    if ( 0 == wrqu->essid.length ) {
        return 0;
    }
<<<<<<< HEAD
<<<<<<< HEAD
#endif
=======
>>>>>>> d97af3b... add prima wlan driver
=======
#endif
>>>>>>> 657b0e9... prima update

    status = hdd_wmm_get_uapsd_mask(pAdapter,
                                    &pWextState->roamProfile.uapsd_mask);
    if (VOS_STATUS_SUCCESS != status)
    {
       pWextState->roamProfile.uapsd_mask = 0;
    }
    pWextState->roamProfile.SSIDs.numOfSSIDs = 1;
<<<<<<< HEAD
<<<<<<< HEAD
     
    pWextState->roamProfile.SSIDs.SSIDList->SSID.length = wrqu->essid.length;
   
    vos_mem_zero(pWextState->roamProfile.SSIDs.SSIDList->SSID.ssId, sizeof(pWextState->roamProfile.SSIDs.SSIDList->SSID.ssId)); 
    vos_mem_copy((void *)(pWextState->roamProfile.SSIDs.SSIDList->SSID.ssId), extra, wrqu->essid.length);
    if (IW_AUTH_WPA_VERSION_WPA == pWextState->wpaVersion ||
        IW_AUTH_WPA_VERSION_WPA2 == pWextState->wpaVersion ) {
   
=======

=======
     
>>>>>>> 657b0e9... prima update
    pWextState->roamProfile.SSIDs.SSIDList->SSID.length = wrqu->essid.length;
   
    vos_mem_zero(pWextState->roamProfile.SSIDs.SSIDList->SSID.ssId, sizeof(pWextState->roamProfile.SSIDs.SSIDList->SSID.ssId)); 
    vos_mem_copy((void *)(pWextState->roamProfile.SSIDs.SSIDList->SSID.ssId), extra, wrqu->essid.length);
    if (IW_AUTH_WPA_VERSION_WPA == pWextState->wpaVersion ||
        IW_AUTH_WPA_VERSION_WPA2 == pWextState->wpaVersion ) {
<<<<<<< HEAD

>>>>>>> d97af3b... add prima wlan driver
=======
   
>>>>>>> 657b0e9... prima update
        //set gen ie
        hdd_SetGENIEToCsr(pAdapter, &RSNAuthType);

        //set auth
        hdd_set_csr_auth_type(pAdapter, RSNAuthType);
    }
#ifdef FEATURE_WLAN_WAPI
<<<<<<< HEAD
<<<<<<< HEAD
    hddLog(LOG1, "%s: Setting WAPI AUTH Type and Encryption Mode values", __FUNCTION__);
=======
    hddLog(LOG1, "%s: Setting WAPI AUTH Type and Encryption Mode values", __func__);
>>>>>>> d97af3b... add prima wlan driver
=======
    hddLog(LOG1, "%s: Setting WAPI AUTH Type and Encryption Mode values", __FUNCTION__);
>>>>>>> 657b0e9... prima update
    if (pAdapter->wapi_info.nWapiMode)
    {
        switch (pAdapter->wapi_info.wapiAuthMode)
        {
            case WAPI_AUTH_MODE_PSK:
            {
<<<<<<< HEAD
<<<<<<< HEAD
                hddLog(LOG1, "%s: WAPI AUTH TYPE: PSK: %d", __FUNCTION__, pAdapter->wapi_info.wapiAuthMode);
=======
                hddLog(LOG1, "%s: WAPI AUTH TYPE: PSK: %d", __func__, pAdapter->wapi_info.wapiAuthMode);
>>>>>>> d97af3b... add prima wlan driver
=======
                hddLog(LOG1, "%s: WAPI AUTH TYPE: PSK: %d", __FUNCTION__, pAdapter->wapi_info.wapiAuthMode);
>>>>>>> 657b0e9... prima update
                pRoamProfile->AuthType.numEntries = 1;
                pRoamProfile->AuthType.authType[0] = eCSR_AUTH_TYPE_WAPI_WAI_PSK;
                break;
            }
            case WAPI_AUTH_MODE_CERT:
            {
<<<<<<< HEAD
<<<<<<< HEAD
                hddLog(LOG1, "%s: WAPI AUTH TYPE: CERT: %d", __FUNCTION__, pAdapter->wapi_info.wapiAuthMode);
=======
                hddLog(LOG1, "%s: WAPI AUTH TYPE: CERT: %d", __func__, pAdapter->wapi_info.wapiAuthMode);
>>>>>>> d97af3b... add prima wlan driver
=======
                hddLog(LOG1, "%s: WAPI AUTH TYPE: CERT: %d", __FUNCTION__, pAdapter->wapi_info.wapiAuthMode);
>>>>>>> 657b0e9... prima update
                pRoamProfile->AuthType.numEntries = 1;
                pRoamProfile->AuthType.authType[0] = eCSR_AUTH_TYPE_WAPI_WAI_CERTIFICATE;
                break;
            }
        } // End of switch
        if ( pAdapter->wapi_info.wapiAuthMode == WAPI_AUTH_MODE_PSK ||
             pAdapter->wapi_info.wapiAuthMode == WAPI_AUTH_MODE_CERT)
        {
<<<<<<< HEAD
<<<<<<< HEAD
            hddLog(LOG1, "%s: WAPI PAIRWISE/GROUP ENCRYPTION: WPI", __FUNCTION__);
=======
            hddLog(LOG1, "%s: WAPI PAIRWISE/GROUP ENCRYPTION: WPI", __func__);
>>>>>>> d97af3b... add prima wlan driver
=======
            hddLog(LOG1, "%s: WAPI PAIRWISE/GROUP ENCRYPTION: WPI", __FUNCTION__);
>>>>>>> 657b0e9... prima update
            pRoamProfile->EncryptionType.numEntries = 1;
            pRoamProfile->EncryptionType.encryptionType[0] = eCSR_ENCRYPT_TYPE_WPI;
            pRoamProfile->mcEncryptionType.numEntries = 1;
            pRoamProfile->mcEncryptionType.encryptionType[0] = eCSR_ENCRYPT_TYPE_WPI;
        }
    }
#endif /* FEATURE_WLAN_WAPI */
    /* if previous genIE is not NULL, update AssocIE */
    if (0 != pWextState->genIE.length)
    {
        memset( &pWextState->assocAddIE, 0, sizeof(pWextState->assocAddIE) );
        memcpy( pWextState->assocAddIE.addIEdata, pWextState->genIE.addIEdata,
            pWextState->genIE.length);
        pWextState->assocAddIE.length = pWextState->genIE.length;
        pWextState->roamProfile.pAddIEAssoc = pWextState->assocAddIE.addIEdata;
        pWextState->roamProfile.nAddIEAssocLength = pWextState->assocAddIE.length;

        /* clear previous genIE after use it */
        memset( &pWextState->genIE, 0, sizeof(pWextState->genIE) );
    }

    /* assumes it is not WPS Association by default, except when pAddIEAssoc has WPS IE */
    pWextState->roamProfile.bWPSAssociation = FALSE;

    if (NULL != wlan_hdd_get_wps_ie_ptr(pWextState->roamProfile.pAddIEAssoc,
        pWextState->roamProfile.nAddIEAssocLength))
        pWextState->roamProfile.bWPSAssociation = TRUE;


    // Disable auto BMPS entry by PMC until DHCP is done
    sme_SetDHCPTillPowerActiveFlag(WLAN_HDD_GET_HAL_CTX(pAdapter), TRUE);

<<<<<<< HEAD
<<<<<<< HEAD
    pWextState->roamProfile.csrPersona = pAdapter->device_mode; 
    (WLAN_HDD_GET_CTX(pAdapter))->isAmpAllowed = VOS_FALSE;
    status = sme_RoamConnect( hHal,pAdapter->sessionId, &(pWextState->roamProfile),&roamId);
    pRoamProfile->ChannelInfo.ChannelList = NULL; 
=======
    pWextState->roamProfile.csrPersona = pAdapter->device_mode;
    (WLAN_HDD_GET_CTX(pAdapter))->isAmpAllowed = VOS_FALSE;

    if ( eCSR_BSS_TYPE_START_IBSS == pRoamProfile->BSSType )
    {
        hdd_select_cbmode(pAdapter,
            (WLAN_HDD_GET_CTX(pAdapter))->cfg_ini->AdHocChannel5G);
    }
    status = sme_RoamConnect( hHal,pAdapter->sessionId,
                         &(pWextState->roamProfile), &roamId);
    pRoamProfile->ChannelInfo.ChannelList = NULL;
>>>>>>> d97af3b... add prima wlan driver
=======
    pWextState->roamProfile.csrPersona = pAdapter->device_mode; 
    (WLAN_HDD_GET_CTX(pAdapter))->isAmpAllowed = VOS_FALSE;
    status = sme_RoamConnect( hHal,pAdapter->sessionId, &(pWextState->roamProfile),&roamId);
    pRoamProfile->ChannelInfo.ChannelList = NULL; 
>>>>>>> 657b0e9... prima update
    pRoamProfile->ChannelInfo.numOfChannels = 0;

    EXIT();
    return status;
}
<<<<<<< HEAD
<<<<<<< HEAD
/**---------------------------------------------------------------------------
  
  \brief iw_get_essid() - 
   This function returns the essid to the wpa_supplicant.
   
  \param  - dev - Pointer to the net device.
              - info - Pointer to the iw_request_info.
              - wrqu - Pointer to the iwreq_data.
              - extra - Pointer to the data.        
  \return - 0 for success, non zero for failure
  
  --------------------------------------------------------------------------*/
int iw_get_essid(struct net_device *dev, 
=======

=======
>>>>>>> 657b0e9... prima update
/**---------------------------------------------------------------------------
  
  \brief iw_get_essid() - 
   This function returns the essid to the wpa_supplicant.
   
  \param  - dev - Pointer to the net device.
              - info - Pointer to the iw_request_info.
              - wrqu - Pointer to the iwreq_data.
              - extra - Pointer to the data.        
  \return - 0 for success, non zero for failure
  
  --------------------------------------------------------------------------*/
<<<<<<< HEAD
int iw_get_essid(struct net_device *dev,
>>>>>>> d97af3b... add prima wlan driver
=======
int iw_get_essid(struct net_device *dev, 
>>>>>>> 657b0e9... prima update
                       struct iw_request_info *info,
                       struct iw_point *dwrq, char *extra)
{
   hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
<<<<<<< HEAD
<<<<<<< HEAD
   hdd_wext_state_t *wextBuf = WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter); 
=======
   hdd_wext_state_t *wextBuf = WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter);
>>>>>>> d97af3b... add prima wlan driver
=======
   hdd_wext_state_t *wextBuf = WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter); 
>>>>>>> 657b0e9... prima update
   hdd_station_ctx_t *pHddStaCtx = WLAN_HDD_GET_STATION_CTX_PTR(pAdapter);
   ENTER();

   if((pHddStaCtx->conn_info.connState == eConnectionState_Associated &&
     wextBuf->roamProfile.SSIDs.SSIDList->SSID.length > 0) ||
      ((pHddStaCtx->conn_info.connState == eConnectionState_IbssConnected ||
        pHddStaCtx->conn_info.connState == eConnectionState_IbssDisconnected) &&
        wextBuf->roamProfile.SSIDs.SSIDList->SSID.length > 0))
   {
       dwrq->length = pHddStaCtx->conn_info.SSID.SSID.length;
       memcpy(extra, pHddStaCtx->conn_info.SSID.SSID.ssId, dwrq->length);
       dwrq->flags = 1;
   } else {
       memset(extra, 0, dwrq->length);
       dwrq->length = 0;
       dwrq->flags = 0;
   }
   EXIT();
   return 0;
}
/**---------------------------------------------------------------------------
<<<<<<< HEAD
<<<<<<< HEAD
  
  \brief iw_set_auth() - 
   This function sets the auth type received from the wpa_supplicant.
   
  \param  - dev - Pointer to the net device.
              - info - Pointer to the iw_request_info.
              - wrqu - Pointer to the iwreq_data.
              - extra - Pointer to the data.        
  \return - 0 for success, non zero for failure
  
=======

  \brief iw_set_auth() -
=======
  
  \brief iw_set_auth() - 
>>>>>>> 657b0e9... prima update
   This function sets the auth type received from the wpa_supplicant.
   
  \param  - dev - Pointer to the net device.
              - info - Pointer to the iw_request_info.
              - wrqu - Pointer to the iwreq_data.
              - extra - Pointer to the data.        
  \return - 0 for success, non zero for failure
<<<<<<< HEAD

>>>>>>> d97af3b... add prima wlan driver
=======
  
>>>>>>> 657b0e9... prima update
  --------------------------------------------------------------------------*/
int iw_set_auth(struct net_device *dev,struct iw_request_info *info,
                        union iwreq_data *wrqu,char *extra)
{
   hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
<<<<<<< HEAD
<<<<<<< HEAD
   hdd_wext_state_t *pWextState = WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter); 
   hdd_station_ctx_t *pHddStaCtx = WLAN_HDD_GET_STATION_CTX_PTR(pAdapter);
   tCsrRoamProfile *pRoamProfile = &pWextState->roamProfile;
   eCsrEncryptionType mcEncryptionType;   
   eCsrEncryptionType ucEncryptionType;
   
   ENTER();
   switch(wrqu->param.flags & IW_AUTH_INDEX)
   {
      case IW_AUTH_WPA_VERSION:
        
         pWextState->wpaVersion = wrqu->param.value;
       
         break;
   
   case IW_AUTH_CIPHER_PAIRWISE:
   {
      if(wrqu->param.value & IW_AUTH_CIPHER_NONE) {            
         ucEncryptionType = eCSR_ENCRYPT_TYPE_NONE;
      }           
      else if(wrqu->param.value & IW_AUTH_CIPHER_TKIP) {
         ucEncryptionType = eCSR_ENCRYPT_TYPE_TKIP;
      }            
      else if(wrqu->param.value & IW_AUTH_CIPHER_CCMP) {
         ucEncryptionType = eCSR_ENCRYPT_TYPE_AES;
      }    
            
     else if(wrqu->param.value & IW_AUTH_CIPHER_WEP40) {
           
         if( (IW_AUTH_KEY_MGMT_802_1X 
                     == (pWextState->authKeyMgmt & IW_AUTH_KEY_MGMT_802_1X)  ) 
                 && (eCSR_AUTH_TYPE_OPEN_SYSTEM == pHddStaCtx->conn_info.authType) )
                /*Dynamic WEP key*/
             ucEncryptionType = eCSR_ENCRYPT_TYPE_WEP40;     
         else
                /*Static WEP key*/
             ucEncryptionType = eCSR_ENCRYPT_TYPE_WEP40_STATICKEY;              
      }      
      else if(wrqu->param.value & IW_AUTH_CIPHER_WEP104) {
           
         if( ( IW_AUTH_KEY_MGMT_802_1X 
                     == (pWextState->authKeyMgmt & IW_AUTH_KEY_MGMT_802_1X) ) 
=======
   hdd_wext_state_t *pWextState = WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter);
=======
   hdd_wext_state_t *pWextState = WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter); 
>>>>>>> 657b0e9... prima update
   hdd_station_ctx_t *pHddStaCtx = WLAN_HDD_GET_STATION_CTX_PTR(pAdapter);
   tCsrRoamProfile *pRoamProfile = &pWextState->roamProfile;
   eCsrEncryptionType mcEncryptionType;   
   eCsrEncryptionType ucEncryptionType;
   
   ENTER();
   switch(wrqu->param.flags & IW_AUTH_INDEX)
   {
      case IW_AUTH_WPA_VERSION:
        
         pWextState->wpaVersion = wrqu->param.value;
       
         break;
   
   case IW_AUTH_CIPHER_PAIRWISE:
   {
      if(wrqu->param.value & IW_AUTH_CIPHER_NONE) {            
         ucEncryptionType = eCSR_ENCRYPT_TYPE_NONE;
      }           
      else if(wrqu->param.value & IW_AUTH_CIPHER_TKIP) {
         ucEncryptionType = eCSR_ENCRYPT_TYPE_TKIP;
      }            
      else if(wrqu->param.value & IW_AUTH_CIPHER_CCMP) {
         ucEncryptionType = eCSR_ENCRYPT_TYPE_AES;
      }    
            
     else if(wrqu->param.value & IW_AUTH_CIPHER_WEP40) {
           
         if( (IW_AUTH_KEY_MGMT_802_1X 
                     == (pWextState->authKeyMgmt & IW_AUTH_KEY_MGMT_802_1X)  ) 
                 && (eCSR_AUTH_TYPE_OPEN_SYSTEM == pHddStaCtx->conn_info.authType) )
                /*Dynamic WEP key*/
             ucEncryptionType = eCSR_ENCRYPT_TYPE_WEP40;     
         else
                /*Static WEP key*/
             ucEncryptionType = eCSR_ENCRYPT_TYPE_WEP40_STATICKEY;              
      }      
      else if(wrqu->param.value & IW_AUTH_CIPHER_WEP104) {
<<<<<<< HEAD

         if( ( IW_AUTH_KEY_MGMT_802_1X
                     == (pWextState->authKeyMgmt & IW_AUTH_KEY_MGMT_802_1X) )
>>>>>>> d97af3b... add prima wlan driver
=======
           
         if( ( IW_AUTH_KEY_MGMT_802_1X 
                     == (pWextState->authKeyMgmt & IW_AUTH_KEY_MGMT_802_1X) ) 
>>>>>>> 657b0e9... prima update
                 && (eCSR_AUTH_TYPE_OPEN_SYSTEM == pHddStaCtx->conn_info.authType))
                  /*Dynamic WEP key*/
            ucEncryptionType = eCSR_ENCRYPT_TYPE_WEP104;
         else
                /*Static WEP key*/
            ucEncryptionType = eCSR_ENCRYPT_TYPE_WEP104_STATICKEY;
<<<<<<< HEAD
<<<<<<< HEAD
               
         }
         else {
           
               hddLog(LOGW, "%s value %d UNKNOWN IW_AUTH_CIPHER",
                      __FUNCTION__, wrqu->param.value); 
               return -EINVAL;
         }
       
         pRoamProfile->EncryptionType.numEntries = 1;
         pRoamProfile->EncryptionType.encryptionType[0] = ucEncryptionType;
      }     
      break;
      case IW_AUTH_CIPHER_GROUP:
      {            
          if(wrqu->param.value & IW_AUTH_CIPHER_NONE) {
            mcEncryptionType = eCSR_ENCRYPT_TYPE_NONE;
      }
        
      else if(wrqu->param.value & IW_AUTH_CIPHER_TKIP) {
             mcEncryptionType = eCSR_ENCRYPT_TYPE_TKIP;
      }
        
      else if(wrqu->param.value & IW_AUTH_CIPHER_CCMP) {              
              mcEncryptionType = eCSR_ENCRYPT_TYPE_AES;
      }
        
      else if(wrqu->param.value & IW_AUTH_CIPHER_WEP40) {
           
         if( ( IW_AUTH_KEY_MGMT_802_1X 
                     == (pWextState->authKeyMgmt & IW_AUTH_KEY_MGMT_802_1X )) 
                 && (eCSR_AUTH_TYPE_OPEN_SYSTEM == pHddStaCtx->conn_info.authType))  
                                            
            mcEncryptionType = eCSR_ENCRYPT_TYPE_WEP40;
            
         else            
               mcEncryptionType = eCSR_ENCRYPT_TYPE_WEP40_STATICKEY; 
      }
        
      else if(wrqu->param.value & IW_AUTH_CIPHER_WEP104) 
      {     
             /*Dynamic WEP keys won't work with shared keys*/
         if( ( IW_AUTH_KEY_MGMT_802_1X 
                     == (pWextState->authKeyMgmt & IW_AUTH_KEY_MGMT_802_1X)) 
=======

=======
               
>>>>>>> 657b0e9... prima update
         }
         else {
           
               hddLog(LOGW, "%s value %d UNKNOWN IW_AUTH_CIPHER",
                      __FUNCTION__, wrqu->param.value); 
               return -EINVAL;
         }
       
         pRoamProfile->EncryptionType.numEntries = 1;
         pRoamProfile->EncryptionType.encryptionType[0] = ucEncryptionType;
      }     
      break;
      case IW_AUTH_CIPHER_GROUP:
      {            
          if(wrqu->param.value & IW_AUTH_CIPHER_NONE) {
            mcEncryptionType = eCSR_ENCRYPT_TYPE_NONE;
      }
        
      else if(wrqu->param.value & IW_AUTH_CIPHER_TKIP) {
             mcEncryptionType = eCSR_ENCRYPT_TYPE_TKIP;
      }
        
      else if(wrqu->param.value & IW_AUTH_CIPHER_CCMP) {              
              mcEncryptionType = eCSR_ENCRYPT_TYPE_AES;
      }
        
      else if(wrqu->param.value & IW_AUTH_CIPHER_WEP40) {
           
         if( ( IW_AUTH_KEY_MGMT_802_1X 
                     == (pWextState->authKeyMgmt & IW_AUTH_KEY_MGMT_802_1X )) 
                 && (eCSR_AUTH_TYPE_OPEN_SYSTEM == pHddStaCtx->conn_info.authType))  
                                            
            mcEncryptionType = eCSR_ENCRYPT_TYPE_WEP40;
            
         else            
               mcEncryptionType = eCSR_ENCRYPT_TYPE_WEP40_STATICKEY; 
      }
        
      else if(wrqu->param.value & IW_AUTH_CIPHER_WEP104) 
      {     
             /*Dynamic WEP keys won't work with shared keys*/
<<<<<<< HEAD
         if( ( IW_AUTH_KEY_MGMT_802_1X
                     == (pWextState->authKeyMgmt & IW_AUTH_KEY_MGMT_802_1X))
>>>>>>> d97af3b... add prima wlan driver
=======
         if( ( IW_AUTH_KEY_MGMT_802_1X 
                     == (pWextState->authKeyMgmt & IW_AUTH_KEY_MGMT_802_1X)) 
>>>>>>> 657b0e9... prima update
                 && (eCSR_AUTH_TYPE_OPEN_SYSTEM == pHddStaCtx->conn_info.authType))
         {
            mcEncryptionType = eCSR_ENCRYPT_TYPE_WEP104;
         }
         else
         {
            mcEncryptionType = eCSR_ENCRYPT_TYPE_WEP104_STATICKEY;
         }
      }
      else {
<<<<<<< HEAD
<<<<<<< HEAD
           
          hddLog(LOGW, "%s value %d UNKNOWN IW_AUTH_CIPHER",
                 __FUNCTION__, wrqu->param.value); 
          return -EINVAL;
       }
              
=======

=======
           
>>>>>>> 657b0e9... prima update
          hddLog(LOGW, "%s value %d UNKNOWN IW_AUTH_CIPHER",
                 __FUNCTION__, wrqu->param.value); 
          return -EINVAL;
       }
<<<<<<< HEAD

>>>>>>> d97af3b... add prima wlan driver
=======
              
>>>>>>> 657b0e9... prima update
         pRoamProfile->mcEncryptionType.numEntries = 1;
         pRoamProfile->mcEncryptionType.encryptionType[0] = mcEncryptionType;
      }
      break;

      case IW_AUTH_80211_AUTH_ALG:
      {
           /*Save the auth algo here and set auth type to SME Roam profile
                in the iw_set_ap_address*/
<<<<<<< HEAD
<<<<<<< HEAD
          if( wrqu->param.value & IW_AUTH_ALG_OPEN_SYSTEM)    
             pHddStaCtx->conn_info.authType = eCSR_AUTH_TYPE_OPEN_SYSTEM;
          
=======
          if( wrqu->param.value & IW_AUTH_ALG_OPEN_SYSTEM)
             pHddStaCtx->conn_info.authType = eCSR_AUTH_TYPE_OPEN_SYSTEM;

>>>>>>> d97af3b... add prima wlan driver
=======
          if( wrqu->param.value & IW_AUTH_ALG_OPEN_SYSTEM)    
             pHddStaCtx->conn_info.authType = eCSR_AUTH_TYPE_OPEN_SYSTEM;
          
>>>>>>> 657b0e9... prima update
          else if(wrqu->param.value & IW_AUTH_ALG_SHARED_KEY)
             pHddStaCtx->conn_info.authType = eCSR_AUTH_TYPE_SHARED_KEY;

          else if(wrqu->param.value & IW_AUTH_ALG_LEAP)
            /*Not supported*/
             pHddStaCtx->conn_info.authType = eCSR_AUTH_TYPE_OPEN_SYSTEM;
          pWextState->roamProfile.AuthType.authType[0] = pHddStaCtx->conn_info.authType;
      }
      break;

      case IW_AUTH_KEY_MGMT:
      {
#ifdef FEATURE_WLAN_CCX
#define IW_AUTH_KEY_MGMT_CCKM       8  /* Should be in linux/wireless.h */
         /*Check for CCKM AKM type */
         if ( wrqu->param.value & IW_AUTH_KEY_MGMT_CCKM) {
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
            //hddLog(VOS_TRACE_LEVEL_INFO_HIGH,"%s: CCKM AKM Set %d\n", __FUNCTION__, wrqu->param.value);
            hddLog(VOS_TRACE_LEVEL_INFO,"%s: CCKM AKM Set %d\n", __FUNCTION__, wrqu->param.value);
            /* Set the CCKM bit in authKeyMgmt */ 
            /* Right now, this breaks all ref to authKeyMgmt because our 
             * code doesn't realize it is a "bitfield" 
<<<<<<< HEAD
=======
            //hddLog(VOS_TRACE_LEVEL_INFO_HIGH,"%s: CCKM AKM Set %d\n", __func__, wrqu->param.value);
            hddLog(VOS_TRACE_LEVEL_INFO,"%s: CCKM AKM Set %d\n", __func__, wrqu->param.value);
            /* Set the CCKM bit in authKeyMgmt */
            /* Right now, this breaks all ref to authKeyMgmt because our
             * code doesn't realize it is a "bitfield"
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
             */
            pWextState->authKeyMgmt |= IW_AUTH_KEY_MGMT_CCKM;
            /*Set the key management to 802.1X*/
            //pWextState->authKeyMgmt = IW_AUTH_KEY_MGMT_802_1X;
            pWextState->isCCXConnection = eANI_BOOLEAN_TRUE;
            //This is test code. I need to actually KNOW whether this is an RSN Assoc or WPA.
            pWextState->collectedAuthType = eCSR_AUTH_TYPE_CCKM_RSN;
         } else if ( wrqu->param.value & IW_AUTH_KEY_MGMT_PSK) {
            /*Save the key management*/
            pWextState->authKeyMgmt |= IW_AUTH_KEY_MGMT_PSK;
            //pWextState->authKeyMgmt = wrqu->param.value;
            //This is test code. I need to actually KNOW whether this is an RSN Assoc or WPA.
            pWextState->collectedAuthType = eCSR_AUTH_TYPE_RSN;
         } else if (!( wrqu->param.value & IW_AUTH_KEY_MGMT_802_1X)) {
            pWextState->collectedAuthType = eCSR_AUTH_TYPE_NONE; //eCSR_AUTH_TYPE_WPA_NONE
            /*Save the key management anyway*/
            pWextState->authKeyMgmt = wrqu->param.value;
         } else { // It must be IW_AUTH_KEY_MGMT_802_1X
            /*Save the key management*/
            pWextState->authKeyMgmt |= IW_AUTH_KEY_MGMT_802_1X;
            //pWextState->authKeyMgmt = wrqu->param.value;
            //This is test code. I need to actually KNOW whether this is an RSN Assoc or WPA.
            pWextState->collectedAuthType = eCSR_AUTH_TYPE_RSN;
         }
#else
         /*Save the key management*/
         pWextState->authKeyMgmt = wrqu->param.value;
#endif /* FEATURE_WLAN_CCX */
      }
      break;

      case IW_AUTH_TKIP_COUNTERMEASURES:
      {
         if(wrqu->param.value) {
            hddLog(VOS_TRACE_LEVEL_INFO_HIGH,
                   "Counter Measure started %d", wrqu->param.value);
            pWextState->mTKIPCounterMeasures = TKIP_COUNTER_MEASURE_STARTED;
         }
         else {
            hddLog(VOS_TRACE_LEVEL_INFO_HIGH,
                   "Counter Measure stopped=%d", wrqu->param.value);
            pWextState->mTKIPCounterMeasures = TKIP_COUNTER_MEASURE_STOPED;
         }
      }
      break;
      case IW_AUTH_DROP_UNENCRYPTED:
      case IW_AUTH_WPA_ENABLED:
      case IW_AUTH_RX_UNENCRYPTED_EAPOL:
      case IW_AUTH_ROAMING_CONTROL:
      case IW_AUTH_PRIVACY_INVOKED:
<<<<<<< HEAD
<<<<<<< HEAD
         
      default:
         
         hddLog(LOGW, "%s called with unsupported auth type %d", __FUNCTION__,
               wrqu->param.flags & IW_AUTH_INDEX);
      break;
   }
   
=======

=======
         
>>>>>>> 657b0e9... prima update
      default:
         
         hddLog(LOGW, "%s called with unsupported auth type %d", __FUNCTION__,
               wrqu->param.flags & IW_AUTH_INDEX);
      break;
   }
<<<<<<< HEAD

>>>>>>> d97af3b... add prima wlan driver
=======
   
>>>>>>> 657b0e9... prima update
   EXIT();
   return 0;
}
/**---------------------------------------------------------------------------
<<<<<<< HEAD
<<<<<<< HEAD
 
  \brief iw_get_auth() - 
   This function returns the auth type to the wpa_supplicant.
   
  \param  - dev - Pointer to the net device.
              - info - Pointer to the iw_request_info.
              - wrqu - Pointer to the iwreq_data.
              - extra - Pointer to the data.        
  \return - 0 for success, non zero for failure
  
=======

  \brief iw_get_auth() -
=======
 
  \brief iw_get_auth() - 
>>>>>>> 657b0e9... prima update
   This function returns the auth type to the wpa_supplicant.
   
  \param  - dev - Pointer to the net device.
              - info - Pointer to the iw_request_info.
              - wrqu - Pointer to the iwreq_data.
              - extra - Pointer to the data.        
  \return - 0 for success, non zero for failure
<<<<<<< HEAD

>>>>>>> d97af3b... add prima wlan driver
=======
  
>>>>>>> 657b0e9... prima update
  --------------------------------------------------------------------------*/
int iw_get_auth(struct net_device *dev,struct iw_request_info *info,
                         union iwreq_data *wrqu,char *extra)
{
    hdd_adapter_t* pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
<<<<<<< HEAD
<<<<<<< HEAD
    hdd_wext_state_t *pWextState= WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter); 
    tCsrRoamProfile *pRoamProfile = &pWextState->roamProfile;
    ENTER();
=======
    hdd_wext_state_t *pWextState= WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter);
    tCsrRoamProfile *pRoamProfile = &pWextState->roamProfile;
    ENTER();

    if ((WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress)
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL,
              "%s:LOGP in Progress. Ignore!!!", __func__);
        return -EBUSY;
    }

>>>>>>> d97af3b... add prima wlan driver
=======
    hdd_wext_state_t *pWextState= WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter); 
    tCsrRoamProfile *pRoamProfile = &pWextState->roamProfile;
    ENTER();
>>>>>>> 657b0e9... prima update
    switch(pRoamProfile->negotiatedAuthType)
    {
        case eCSR_AUTH_TYPE_WPA_NONE:
            wrqu->param.flags = IW_AUTH_WPA_VERSION;
            wrqu->param.value =  IW_AUTH_WPA_VERSION_DISABLED;
            break;
        case eCSR_AUTH_TYPE_WPA:
            wrqu->param.flags = IW_AUTH_WPA_VERSION;
            wrqu->param.value = IW_AUTH_WPA_VERSION_WPA;
            break;
#ifdef WLAN_FEATURE_VOWIFI_11R
        case eCSR_AUTH_TYPE_FT_RSN:
#endif
        case eCSR_AUTH_TYPE_RSN:
            wrqu->param.flags = IW_AUTH_WPA_VERSION;
            wrqu->param.value =  IW_AUTH_WPA_VERSION_WPA2;
            break;
         case eCSR_AUTH_TYPE_OPEN_SYSTEM:
             wrqu->param.value = IW_AUTH_ALG_OPEN_SYSTEM;
             break;
         case eCSR_AUTH_TYPE_SHARED_KEY:
             wrqu->param.value =  IW_AUTH_ALG_SHARED_KEY;
             break;
         case eCSR_AUTH_TYPE_UNKNOWN:
<<<<<<< HEAD
<<<<<<< HEAD
             hddLog(LOG1,"%s called with unknown auth type", __FUNCTION__);
=======
             hddLog(LOG1,"%s called with unknown auth type", __func__);
>>>>>>> d97af3b... add prima wlan driver
=======
             hddLog(LOG1,"%s called with unknown auth type", __FUNCTION__);
>>>>>>> 657b0e9... prima update
             wrqu->param.value =  IW_AUTH_ALG_OPEN_SYSTEM;
             break;
         case eCSR_AUTH_TYPE_AUTOSWITCH:
             wrqu->param.value =  IW_AUTH_ALG_OPEN_SYSTEM;
             break;
         case eCSR_AUTH_TYPE_WPA_PSK:
<<<<<<< HEAD
<<<<<<< HEAD
             hddLog(LOG1,"%s called with unknown auth type", __FUNCTION__);
=======
             hddLog(LOG1,"%s called with unknown auth type", __func__);
>>>>>>> d97af3b... add prima wlan driver
=======
             hddLog(LOG1,"%s called with unknown auth type", __FUNCTION__);
>>>>>>> 657b0e9... prima update
             wrqu->param.value = IW_AUTH_ALG_OPEN_SYSTEM;
             return -EIO;
#ifdef WLAN_FEATURE_VOWIFI_11R
         case eCSR_AUTH_TYPE_FT_RSN_PSK:
#endif
         case eCSR_AUTH_TYPE_RSN_PSK:
<<<<<<< HEAD
<<<<<<< HEAD
             hddLog(LOG1,"%s called with unknown auth type", __FUNCTION__);
             wrqu->param.value = IW_AUTH_ALG_OPEN_SYSTEM;
             return -EIO;
         default:
             hddLog(LOG1,"%s called with unknown auth type", __FUNCTION__);
=======
#ifdef WLAN_FEATURE_11W
         case eCSR_AUTH_TYPE_RSN_PSK_SHA256:
#endif
             hddLog(LOG1,"%s called with unknown auth type", __func__);
             wrqu->param.value = IW_AUTH_ALG_OPEN_SYSTEM;
             return -EIO;
         default:
             hddLog(LOG1,"%s called with unknown auth type", __func__);
>>>>>>> d97af3b... add prima wlan driver
=======
             hddLog(LOG1,"%s called with unknown auth type", __FUNCTION__);
             wrqu->param.value = IW_AUTH_ALG_OPEN_SYSTEM;
             return -EIO;
         default:
             hddLog(LOG1,"%s called with unknown auth type", __FUNCTION__);
>>>>>>> 657b0e9... prima update
             wrqu->param.value = IW_AUTH_ALG_OPEN_SYSTEM;
             return -EIO;
    }
    if(((wrqu->param.flags & IW_AUTH_INDEX) == IW_AUTH_CIPHER_PAIRWISE))
    {
        switch(pRoamProfile->negotiatedUCEncryptionType)
        {
            case eCSR_ENCRYPT_TYPE_NONE:
                wrqu->param.value = IW_AUTH_CIPHER_NONE;
                break;
            case eCSR_ENCRYPT_TYPE_WEP40:
            case eCSR_ENCRYPT_TYPE_WEP40_STATICKEY:
                wrqu->param.value = IW_AUTH_CIPHER_WEP40;
                break;
            case eCSR_ENCRYPT_TYPE_TKIP:
                wrqu->param.value = IW_AUTH_CIPHER_TKIP;
                break;
            case eCSR_ENCRYPT_TYPE_WEP104:
            case eCSR_ENCRYPT_TYPE_WEP104_STATICKEY:
                wrqu->param.value = IW_AUTH_CIPHER_WEP104;
                break;
            case eCSR_ENCRYPT_TYPE_AES:
                wrqu->param.value = IW_AUTH_CIPHER_CCMP;
                break;
            default:
<<<<<<< HEAD
<<<<<<< HEAD
                hddLog(LOG1, "%s called with unknown auth type", __FUNCTION__);
=======
                hddLog(LOG1, "%s called with unknown auth type", __func__);
>>>>>>> d97af3b... add prima wlan driver
=======
                hddLog(LOG1, "%s called with unknown auth type", __FUNCTION__);
>>>>>>> 657b0e9... prima update
                return -EIO;
        }
   }

<<<<<<< HEAD
<<<<<<< HEAD
    if(((wrqu->param.flags & IW_AUTH_INDEX) == IW_AUTH_CIPHER_GROUP)) 
=======
    if(((wrqu->param.flags & IW_AUTH_INDEX) == IW_AUTH_CIPHER_GROUP))
>>>>>>> d97af3b... add prima wlan driver
=======
    if(((wrqu->param.flags & IW_AUTH_INDEX) == IW_AUTH_CIPHER_GROUP)) 
>>>>>>> 657b0e9... prima update
    {
        switch(pRoamProfile->negotiatedMCEncryptionType)
        {
        case eCSR_ENCRYPT_TYPE_NONE:
            wrqu->param.value = IW_AUTH_CIPHER_NONE;
            break;
        case eCSR_ENCRYPT_TYPE_WEP40:
        case eCSR_ENCRYPT_TYPE_WEP40_STATICKEY:
            wrqu->param.value = IW_AUTH_CIPHER_WEP40;
            break;
        case eCSR_ENCRYPT_TYPE_TKIP:
            wrqu->param.value = IW_AUTH_CIPHER_TKIP;
            break;
         case eCSR_ENCRYPT_TYPE_WEP104:
         case eCSR_ENCRYPT_TYPE_WEP104_STATICKEY:
             wrqu->param.value = IW_AUTH_CIPHER_WEP104;
             break;
         case eCSR_ENCRYPT_TYPE_AES:
             wrqu->param.value = IW_AUTH_CIPHER_CCMP;
             break;
         default:
<<<<<<< HEAD
<<<<<<< HEAD
             hddLog(LOG1, "%s called with unknown auth type", __FUNCTION__);
=======
             hddLog(LOG1, "%s called with unknown auth type", __func__);
>>>>>>> d97af3b... add prima wlan driver
=======
             hddLog(LOG1, "%s called with unknown auth type", __FUNCTION__);
>>>>>>> 657b0e9... prima update
            return -EIO;
       }
   }

    hddLog(LOG1, "%s called with auth type %d",
<<<<<<< HEAD
<<<<<<< HEAD
           __FUNCTION__, pRoamProfile->AuthType.authType[0]);
=======
           __func__, pRoamProfile->AuthType.authType[0]);
>>>>>>> d97af3b... add prima wlan driver
=======
           __FUNCTION__, pRoamProfile->AuthType.authType[0]);
>>>>>>> 657b0e9... prima update
    EXIT();
    return 0;
}
/**---------------------------------------------------------------------------
<<<<<<< HEAD
<<<<<<< HEAD
  
  \brief iw_set_ap_address() - 
   This function calls the sme_RoamConnect function to associate 
   to the AP with the specified BSSID received from the wpa_supplicant.
   
  \param  - dev - Pointer to the net device.
              - info - Pointer to the iw_request_info.
              - wrqu - Pointer to the iwreq_data.
              - extra - Pointer to the data.        
  \return - 0 for success, non zero for failure
  
=======

  \brief iw_set_ap_address() -
   This function calls the sme_RoamConnect function to associate
=======
  
  \brief iw_set_ap_address() - 
   This function calls the sme_RoamConnect function to associate 
>>>>>>> 657b0e9... prima update
   to the AP with the specified BSSID received from the wpa_supplicant.
   
  \param  - dev - Pointer to the net device.
              - info - Pointer to the iw_request_info.
              - wrqu - Pointer to the iwreq_data.
              - extra - Pointer to the data.        
  \return - 0 for success, non zero for failure
<<<<<<< HEAD

>>>>>>> d97af3b... add prima wlan driver
=======
  
>>>>>>> 657b0e9... prima update
  --------------------------------------------------------------------------*/
int iw_set_ap_address(struct net_device *dev,
        struct iw_request_info *info,
        union iwreq_data *wrqu, char *extra)
{
    hdd_station_ctx_t *pHddStaCtx = WLAN_HDD_GET_STATION_CTX_PTR(WLAN_HDD_GET_PRIV_PTR(dev));
    v_U8_t  *pMacAddress=NULL;
    ENTER();
    pMacAddress = (v_U8_t*) wrqu->ap_addr.sa_data;
    VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO, "%02x:%02x:%02x:%02x:%02x:%02x",pMacAddress[0],pMacAddress[1],
          pMacAddress[2],pMacAddress[3],pMacAddress[4],pMacAddress[5]);
    vos_mem_copy( pHddStaCtx->conn_info.bssId, pMacAddress, sizeof( tCsrBssid ));
    EXIT();
<<<<<<< HEAD
<<<<<<< HEAD
   
    return 0;
}
/**---------------------------------------------------------------------------
  
  \brief iw_get_ap_address() - 
=======

    return 0;
}
/**---------------------------------------------------------------------------

  \brief iw_get_ap_address() -
>>>>>>> d97af3b... add prima wlan driver
=======
   
    return 0;
}
/**---------------------------------------------------------------------------
  
  \brief iw_get_ap_address() - 
>>>>>>> 657b0e9... prima update
   This function returns the BSSID to the wpa_supplicant
  \param  - dev - Pointer to the net device.
              - info - Pointer to the iw_request_info.
              - wrqu - Pointer to the iwreq_data.
<<<<<<< HEAD
<<<<<<< HEAD
              - extra - Pointer to the data.        
  \return - 0 for success, non zero for failure
  
=======
              - extra - Pointer to the data.
  \return - 0 for success, non zero for failure

>>>>>>> d97af3b... add prima wlan driver
=======
              - extra - Pointer to the data.        
  \return - 0 for success, non zero for failure
  
>>>>>>> 657b0e9... prima update
  --------------------------------------------------------------------------*/
int iw_get_ap_address(struct net_device *dev,
                             struct iw_request_info *info,
                             union iwreq_data *wrqu, char *extra)
{
    //hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
    hdd_station_ctx_t *pHddStaCtx = WLAN_HDD_GET_STATION_CTX_PTR(WLAN_HDD_GET_PRIV_PTR(dev));

    ENTER();

    if ((pHddStaCtx->conn_info.connState == eConnectionState_Associated) ||
        (eConnectionState_IbssConnected == pHddStaCtx->conn_info.connState))
    {
<<<<<<< HEAD
<<<<<<< HEAD
        memcpy(wrqu->ap_addr.sa_data,pHddStaCtx->conn_info.bssId,sizeof(wrqu->ap_addr.sa_data));
=======
        memcpy(wrqu->ap_addr.sa_data,pHddStaCtx->conn_info.bssId,ETH_ALEN);
>>>>>>> d97af3b... add prima wlan driver
=======
        memcpy(wrqu->ap_addr.sa_data,pHddStaCtx->conn_info.bssId,sizeof(wrqu->ap_addr.sa_data));
>>>>>>> 657b0e9... prima update
    }
    else
    {
        memset(wrqu->ap_addr.sa_data,0,sizeof(wrqu->ap_addr.sa_data));
    }
    EXIT();
    return 0;
}

<<<<<<< HEAD
<<<<<<< HEAD

/**---------------------------------------------------------------------------

  \brief hdd_ResetCountryCodeAfterDisAssoc -
  This function reset the country code to default
  \param  - pAdapter - Pointer to HDD adaptor
  \return - nothing

  --------------------------------------------------------------------------*/
void hdd_ResetCountryCodeAfterDisAssoc(hdd_adapter_t *pAdapter)
{
    hdd_context_t* pHddCtx = (hdd_context_t*)pAdapter->pHddCtx;
    tSmeConfigParams smeConfig;
    eHalStatus status = eHAL_STATUS_SUCCESS;
    tANI_U8 defaultCountryCode[3] = SME_INVALID_COUNTRY_CODE;
    tANI_U8 currentCountryCode[3] = SME_INVALID_COUNTRY_CODE;

    sme_GetConfigParam(pHddCtx->hHal, &smeConfig);

    VOS_TRACE( VOS_MODULE_ID_VOSS, VOS_TRACE_LEVEL_INFO,
            "%s: 11d is %s\n",__func__,
            smeConfig.csrConfig.Is11dSupportEnabled ? "Enabled" : "Disabled");
    /* Reset country code only when 11d is enabled
    */
    if (smeConfig.csrConfig.Is11dSupportEnabled)
    {
        sme_GetDefaultCountryCodeFrmNv(pHddCtx->hHal, &defaultCountryCode[0]);
        sme_GetCurrentCountryCode(pHddCtx->hHal, &currentCountryCode[0]);

        VOS_TRACE( VOS_MODULE_ID_VOSS, VOS_TRACE_LEVEL_INFO,
                "%s: Default country code: %c%c%c, Current Country code: %c%c%c \n",
                __func__,
                defaultCountryCode[0], defaultCountryCode[1], defaultCountryCode[2],
                currentCountryCode[0], currentCountryCode[1], currentCountryCode[2]);
        /* Reset country code only when there is a mismatch
         * between current country code and default country code
         */
        if ((defaultCountryCode[0] != currentCountryCode[0]) ||
                (defaultCountryCode[1] != currentCountryCode[1]) ||
                (defaultCountryCode[2] != currentCountryCode[2]))
        {
            VOS_TRACE( VOS_MODULE_ID_VOSS, VOS_TRACE_LEVEL_INFO,
                    "%s: Disconnected from the AP/Assoc failed and "
                    "resetting the country code to default\n",__func__);
            /*reset the country code of previous connection*/
            status = (int)sme_ChangeCountryCode(pHddCtx->hHal, NULL,
                    &defaultCountryCode[0], pAdapter,
                    pHddCtx->pvosContext
                    );
            if( 0 != status )
            {
                VOS_TRACE( VOS_MODULE_ID_VOSS, VOS_TRACE_LEVEL_ERROR,
                        "%s: failed to Reset the Country Code\n",__func__);
            }
        }
    }
}

=======
#ifdef WLAN_FEATURE_11W
=======

>>>>>>> 657b0e9... prima update
/**---------------------------------------------------------------------------

  \brief hdd_ResetCountryCodeAfterDisAssoc -
  This function reset the country code to default
  \param  - pAdapter - Pointer to HDD adaptor
  \return - nothing

  --------------------------------------------------------------------------*/
void hdd_ResetCountryCodeAfterDisAssoc(hdd_adapter_t *pAdapter)
{
    hdd_context_t* pHddCtx = (hdd_context_t*)pAdapter->pHddCtx;
    tSmeConfigParams smeConfig;
    eHalStatus status = eHAL_STATUS_SUCCESS;
    tANI_U8 defaultCountryCode[3] = SME_INVALID_COUNTRY_CODE;
    tANI_U8 currentCountryCode[3] = SME_INVALID_COUNTRY_CODE;

    sme_GetConfigParam(pHddCtx->hHal, &smeConfig);

    VOS_TRACE( VOS_MODULE_ID_VOSS, VOS_TRACE_LEVEL_INFO,
            "%s: 11d is %s\n",__func__,
            smeConfig.csrConfig.Is11dSupportEnabled ? "Enabled" : "Disabled");
    /* Reset country code only when 11d is enabled
    */
    if (smeConfig.csrConfig.Is11dSupportEnabled)
    {
        sme_GetDefaultCountryCodeFrmNv(pHddCtx->hHal, &defaultCountryCode[0]);
        sme_GetCurrentCountryCode(pHddCtx->hHal, &currentCountryCode[0]);

        VOS_TRACE( VOS_MODULE_ID_VOSS, VOS_TRACE_LEVEL_INFO,
                "%s: Default country code: %c%c%c, Current Country code: %c%c%c \n",
                __func__,
                defaultCountryCode[0], defaultCountryCode[1], defaultCountryCode[2],
                currentCountryCode[0], currentCountryCode[1], currentCountryCode[2]);
        /* Reset country code only when there is a mismatch
         * between current country code and default country code
         */
        if ((defaultCountryCode[0] != currentCountryCode[0]) ||
                (defaultCountryCode[1] != currentCountryCode[1]) ||
                (defaultCountryCode[2] != currentCountryCode[2]))
        {
            VOS_TRACE( VOS_MODULE_ID_VOSS, VOS_TRACE_LEVEL_INFO,
                    "%s: Disconnected from the AP/Assoc failed and "
                    "resetting the country code to default\n",__func__);
            /*reset the country code of previous connection*/
            status = (int)sme_ChangeCountryCode(pHddCtx->hHal, NULL,
                    &defaultCountryCode[0], pAdapter,
                    pHddCtx->pvosContext
                    );
            if( 0 != status )
            {
                VOS_TRACE( VOS_MODULE_ID_VOSS, VOS_TRACE_LEVEL_ERROR,
                        "%s: failed to Reset the Country Code\n",__func__);
            }
        }
    }
}
<<<<<<< HEAD
#endif
>>>>>>> d97af3b... add prima wlan driver
=======

>>>>>>> 657b0e9... prima update
