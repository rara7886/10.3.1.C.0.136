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

#if defined WLAN_FEATURE_VOWIFI_11R
/**=========================================================================
  
   Macros and Function prototypes FT and 802.11R purposes 

<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
   Copyright 2010 (c) Qualcomm, Incorporated.  All Rights Reserved.
   
   Qualcomm Confidential and Proprietary.
  
<<<<<<< HEAD
=======
   Copyright 2010 (c) Qualcomm Technologies, Inc.  All Rights Reserved.
   Qualcomm Technologies Confidential and Proprietary.

>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
  ========================================================================*/

#ifndef __LIMFTDEFS_H__
#define __LIMFTDEFS_H__


#include <palTypes.h>
<<<<<<< HEAD
<<<<<<< HEAD
=======
#include "halMsgApi.h"
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update

/*-------------------------------------------------------------------------- 
  Preprocessor definitions and constants
  ------------------------------------------------------------------------*/
#define SIR_MDIE_SIZE               3 // MD ID(2 bytes), Capability(1 byte)
#define MAX_TIDS                    8
#define MAX_FTIE_SIZE             256 // Max size limited to 256, on acct. of IW custom events


/*-------------------------------------------------------------------------- 
  Type declarations
  ------------------------------------------------------------------------*/
<<<<<<< HEAD
<<<<<<< HEAD
/*-------------------------------------------------------------------------- 
  FT Pre Auth Req SME<->PE 
=======
/*--------------------------------------------------------------------------
  FT Pre Auth Req SME<->PE
>>>>>>> d97af3b... add prima wlan driver
=======
/*-------------------------------------------------------------------------- 
  FT Pre Auth Req SME<->PE 
>>>>>>> 657b0e9... prima update
  ------------------------------------------------------------------------*/
typedef struct sSirFTPreAuthReq
{
   tANI_U16    messageType;      // eWNI_SME_FT_PRE_AUTH_REQ
   tANI_U16    length;
   tANI_BOOLEAN bPreAuthRspProcessed; /* Track if response is processed for this request
                                         We expect only one response per request. */
   tANI_U8     preAuthchannelNum;
   tSirMacAddr currbssId;        // BSSID currently associated to suspend the link
   tSirMacAddr preAuthbssId;     // BSSID to preauth to
   tANI_U16    ft_ies_length;
   tANI_U8     ft_ies[MAX_FTIE_SIZE];
   tpSirBssDescription  pbssDescription;
} tSirFTPreAuthReq, *tpSirFTPreAuthReq;

/*-------------------------------------------------------------------------
<<<<<<< HEAD
<<<<<<< HEAD
  FT Pre Auth Rsp PE<->SME 
  ------------------------------------------------------------------------*/
typedef struct sSirFTPreAuthRsp
{
   tANI_U16    messageType;      // eWNI_SME_FT_PRE_AUTH_RSP
   tANI_U16    length;
   tANI_U8     smeSessionId;
   tSirMacAddr preAuthbssId;     // BSSID to preauth to
   tANI_U8     status;
   tANI_U16    ft_ies_length;
   tANI_U8     ft_ies[MAX_FTIE_SIZE];
   tANI_U16    ric_ies_length;
   tANI_U8     ric_ies[MAX_FTIE_SIZE];
} tSirFTPreAuthRsp, *tpSirFTPreAuthRsp;

/*-------------------------------------------------------------------------- 
  FT Pre Auth Req SME<->PE 
  ------------------------------------------------------------------------*/
typedef struct sSirFTUpdateKeyInfo
{
   tANI_U16          messageType;
   tANI_U16          length;
   tSirKeyMaterial   keyMaterial;
} tSirFTUpdateKeyInfo, *tpSirFTUpdateKeyInfo;

/*-------------------------------------------------------------------------
  Global FT Information 
=======
  FT Pre Auth Rsp PE<->SME
=======
  FT Pre Auth Rsp PE<->SME 
>>>>>>> 657b0e9... prima update
  ------------------------------------------------------------------------*/
typedef struct sSirFTPreAuthRsp
{
   tANI_U16    messageType;      // eWNI_SME_FT_PRE_AUTH_RSP
   tANI_U16    length;
   tANI_U8     smeSessionId;
   tSirMacAddr preAuthbssId;     // BSSID to preauth to
   tANI_U8     status;
   tANI_U16    ft_ies_length;
   tANI_U8     ft_ies[MAX_FTIE_SIZE];
   tANI_U16    ric_ies_length;
   tANI_U8     ric_ies[MAX_FTIE_SIZE];
} tSirFTPreAuthRsp, *tpSirFTPreAuthRsp;

/*-------------------------------------------------------------------------- 
  FT Pre Auth Req SME<->PE 
  ------------------------------------------------------------------------*/
typedef struct sSirFTUpdateKeyInfo
{
   tANI_U16          messageType;
   tANI_U16          length;
   tSirKeyMaterial   keyMaterial;
} tSirFTUpdateKeyInfo, *tpSirFTUpdateKeyInfo;

/*-------------------------------------------------------------------------
<<<<<<< HEAD
  Global FT Information
>>>>>>> d97af3b... add prima wlan driver
=======
  Global FT Information 
>>>>>>> 657b0e9... prima update
  ------------------------------------------------------------------------*/
typedef struct sFTPEContext
{
    tpSirFTPreAuthReq pFTPreAuthReq;                      // Saved FT Pre Auth Req
<<<<<<< HEAD
<<<<<<< HEAD
    void              *psavedsessionEntry;                
    tANI_U8           ftPreAuthStatus;
    tANI_U16          saved_auth_rsp_length;
    tANI_U8           saved_auth_rsp[MAX_FTIE_SIZE];

    // Items created for the new FT, session
    void              *pftSessionEntry;                   // Saved session created for pre-auth 
=======
    void              *psavedsessionEntry;
    tSirRetStatus     ftPreAuthStatus;
=======
    void              *psavedsessionEntry;                
    tANI_U8           ftPreAuthStatus;
>>>>>>> 657b0e9... prima update
    tANI_U16          saved_auth_rsp_length;
    tANI_U8           saved_auth_rsp[MAX_FTIE_SIZE];

    // Items created for the new FT, session
<<<<<<< HEAD
    void              *pftSessionEntry;                   // Saved session created for pre-auth
>>>>>>> d97af3b... add prima wlan driver
=======
    void              *pftSessionEntry;                   // Saved session created for pre-auth 
>>>>>>> 657b0e9... prima update
    void              *pAddBssReq;                        // Save add bss req.
    void              *pAddStaReq;                        // Save add sta req.

} tftPEContext, *tpftPEContext; 


#endif /* __LIMFTDEFS_H__ */ 

#endif /* WLAN_FEATURE_VOWIFI_11R */
