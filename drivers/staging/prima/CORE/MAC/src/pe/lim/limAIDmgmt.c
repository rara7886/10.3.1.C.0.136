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
<<<<<<< HEAD
<<<<<<< HEAD
 *
=======
>>>>>>> d97af3b... add prima wlan driver
=======
 *
>>>>>>> 657b0e9... prima update
 * Airgo Networks, Inc proprietary. All rights reserved.
 * This file limAIDmgmt.cc contains the functions related to
 * AID pool management like initialization, assignment etc.
 * Author:        Chandra Modumudi
 * Date:          03/20/02
 * History:-
 * Date           Modified by    Modification Information
 * --------------------------------------------------------------------
 */
 
#include "palTypes.h"
#include "wniCfgSta.h"
#include "aniGlobal.h"
#include "cfgApi.h"
#include "sirParams.h"
#include "limUtils.h"
#include "limTimerUtils.h"
#include "limSession.h"
<<<<<<< HEAD
<<<<<<< HEAD

#define LIM_START_AID   1


/**
 * limInitAIDpool()
=======
#include "limSessionUtils.h"
=======
>>>>>>> 657b0e9... prima update

#define LIM_START_AID   1


/**
<<<<<<< HEAD
 * limInitPeerIdxpool()
>>>>>>> d97af3b... add prima wlan driver
=======
 * limInitAIDpool()
>>>>>>> 657b0e9... prima update
 *
 *FUNCTION:
 * This function is called while starting a BSS at AP
 * to initialize AID pool. This may also be called while
 * starting/joining an IBSS if 'Association' is allowed
 * in IBSS.
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 * NA
 *
 *NOTE:
 * NA
 *
 * @param  pMac - Pointer to Global MAC structure
 * @return None
 */

void
<<<<<<< HEAD
<<<<<<< HEAD
limInitAIDpool(tpAniSirGlobal pMac,tpPESession sessionEntry)
=======
limInitPeerIdxpool(tpAniSirGlobal pMac,tpPESession pSessionEntry)
>>>>>>> d97af3b... add prima wlan driver
=======
limInitAIDpool(tpAniSirGlobal pMac,tpPESession sessionEntry)
>>>>>>> 657b0e9... prima update
{
    tANI_U8 i;
    tANI_U8 maxAssocSta = pMac->lim.gLimAssocStaLimit;

<<<<<<< HEAD
<<<<<<< HEAD
    pMac->lim.gpLimAIDpool[0]=0;
    pMac->lim.freeAidHead=LIM_START_AID;

    for (i=pMac->lim.freeAidHead;i<maxAssocSta; i++)
    {
        pMac->lim.gpLimAIDpool[i]         = i+1;
    }
    pMac->lim.gpLimAIDpool[i]         =  0;

    pMac->lim.freeAidTail=i;
=======
    pSessionEntry->gpLimPeerIdxpool[0]=0;

#ifdef FEATURE_WLAN_TDLS
    //In station role, DPH_STA_HASH_INDEX_PEER (index 1) is reserved for peer
    //station index corresponding to AP. Avoid choosing that index and get index
    //starting from (DPH_STA_HASH_INDEX_PEER + 1) (index 2) for TDLS stations;
    if (pSessionEntry->limSystemRole == eLIM_STA_ROLE )
    {
        pSessionEntry->freePeerIdxHead = DPH_STA_HASH_INDEX_PEER + 1;
    }
    else
#endif
    {
        pSessionEntry->freePeerIdxHead=LIM_START_PEER_IDX;
    }
=======
    pMac->lim.gpLimAIDpool[0]=0;
    pMac->lim.freeAidHead=LIM_START_AID;
>>>>>>> 657b0e9... prima update

    for (i=pMac->lim.freeAidHead;i<maxAssocSta; i++)
    {
        pMac->lim.gpLimAIDpool[i]         = i+1;
    }
    pMac->lim.gpLimAIDpool[i]         =  0;

<<<<<<< HEAD
    pSessionEntry->freePeerIdxTail=i;
>>>>>>> d97af3b... add prima wlan driver
=======
    pMac->lim.freeAidTail=i;
>>>>>>> 657b0e9... prima update

}


/**
<<<<<<< HEAD
<<<<<<< HEAD
 * limAssignAID()
 *
 *FUNCTION:
 * This function is called during Association/Reassociation
 * frame handling to assign association ID (aid) to a STA.
=======
 * limAssignPeerIdx()
=======
 * limAssignAID()
>>>>>>> 657b0e9... prima update
 *
 *FUNCTION:
 * This function is called during Association/Reassociation
 * frame handling to assign association ID (aid) to a STA.
<<<<<<< HEAD
 * In case of TDLS, this is used to assign a index into the Dph hash entry.
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 * NA
 *
 *NOTE:
 *
 * @param  pMac - Pointer to Global MAC structure
<<<<<<< HEAD
<<<<<<< HEAD
 * @return aid  - assigned Association ID for STA
 */

tANI_U16
limAssignAID(tpAniSirGlobal pMac)
{
    tANI_U16 aid;

    // make sure we haven't exceeded the configurable limit on associations
    if (pMac->lim.gLimNumOfCurrentSTAs >= pMac->lim.gLimAssocStaLimit)
=======
 * @return peerIdx  - assigned peer Station IDx for STA
=======
 * @return aid  - assigned Association ID for STA
>>>>>>> 657b0e9... prima update
 */

tANI_U16
limAssignAID(tpAniSirGlobal pMac)
{
    tANI_U16 aid;

    // make sure we haven't exceeded the configurable limit on associations
<<<<<<< HEAD
    // This count is global to ensure that it doesnt exceed the hardware limits.
    if (peGetCurrentSTAsCount(pMac) >= pMac->lim.gLimAssocStaLimit)
>>>>>>> d97af3b... add prima wlan driver
=======
    if (pMac->lim.gLimNumOfCurrentSTAs >= pMac->lim.gLimAssocStaLimit)
>>>>>>> 657b0e9... prima update
    {
        // too many associations already active
        return 0;
    }

    /* return head of free list */

<<<<<<< HEAD
<<<<<<< HEAD
    if (pMac->lim.freeAidHead)
    {
        aid=pMac->lim.freeAidHead;
        pMac->lim.freeAidHead=pMac->lim.gpLimAIDpool[pMac->lim.freeAidHead];
        if (pMac->lim.freeAidHead==0)
            pMac->lim.freeAidTail=0;
        pMac->lim.gLimNumOfCurrentSTAs++;
        //PELOG2(limLog(pMac, LOG2,FL("Assign aid %d, numSta %d, head %d tail %d \n"),aid,pMac->lim.gLimNumOfCurrentSTAs,pMac->lim.freeAidHead,pMac->lim.freeAidTail);)
        return aid;
    }

    return 0; /* no more free aids */
=======
    if (pSessionEntry->freePeerIdxHead)
=======
    if (pMac->lim.freeAidHead)
>>>>>>> 657b0e9... prima update
    {
        aid=pMac->lim.freeAidHead;
        pMac->lim.freeAidHead=pMac->lim.gpLimAIDpool[pMac->lim.freeAidHead];
        if (pMac->lim.freeAidHead==0)
            pMac->lim.freeAidTail=0;
        pMac->lim.gLimNumOfCurrentSTAs++;
        //PELOG2(limLog(pMac, LOG2,FL("Assign aid %d, numSta %d, head %d tail %d \n"),aid,pMac->lim.gLimNumOfCurrentSTAs,pMac->lim.freeAidHead,pMac->lim.freeAidTail);)
        return aid;
    }

<<<<<<< HEAD
    return 0; /* no more free peer index */
>>>>>>> d97af3b... add prima wlan driver
=======
    return 0; /* no more free aids */
>>>>>>> 657b0e9... prima update
}


/**
<<<<<<< HEAD
<<<<<<< HEAD
 * limReleaseAID()
 *
 *FUNCTION:
 * This function is called when a STA context is removed
 * at AP (or at a STA in IBSS mode) to return association ID (aid)
=======
 * limReleasePeerIdx()
 *
 *FUNCTION:
 * This function is called when a STA context is removed
 * at AP (or at a STA in IBSS mode or TDLS) to return peer Index
>>>>>>> d97af3b... add prima wlan driver
=======
 * limReleaseAID()
 *
 *FUNCTION:
 * This function is called when a STA context is removed
 * at AP (or at a STA in IBSS mode) to return association ID (aid)
>>>>>>> 657b0e9... prima update
 * to free pool.
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 * NA
 *
 *NOTE:
 *
 * @param  pMac - Pointer to Global MAC structure
<<<<<<< HEAD
<<<<<<< HEAD
 * @param  aid - Association ID that need to return to free pool
=======
 * @param  peerIdx - peer station index that need to return to free pool
>>>>>>> d97af3b... add prima wlan driver
=======
 * @param  aid - Association ID that need to return to free pool
>>>>>>> 657b0e9... prima update
 *
 * @return None
 */

void
<<<<<<< HEAD
<<<<<<< HEAD
limReleaseAID(tpAniSirGlobal pMac, tANI_U16 aid)
{
    pMac->lim.gLimNumOfCurrentSTAs--;

    /* insert at tail of free list */
    if (pMac->lim.freeAidTail)
    {
        pMac->lim.gpLimAIDpool[pMac->lim.freeAidTail]=(tANI_U8)aid;
        pMac->lim.freeAidTail=(tANI_U8)aid;
    }
    else
    {
        pMac->lim.freeAidTail=pMac->lim.freeAidHead=(tANI_U8)aid;
    }
    pMac->lim.gpLimAIDpool[(tANI_U8)aid]=0;
    //PELOG2(limLog(pMac, LOG2,FL("Release aid %d, numSta %d, head %d tail %d \n"),aid,pMac->lim.gLimNumOfCurrentSTAs,pMac->lim.freeAidHead,pMac->lim.freeAidTail);)
=======
limReleasePeerIdx(tpAniSirGlobal pMac, tANI_U16 peerIdx, tpPESession pSessionEntry)
=======
limReleaseAID(tpAniSirGlobal pMac, tANI_U16 aid)
>>>>>>> 657b0e9... prima update
{
    pMac->lim.gLimNumOfCurrentSTAs--;

    /* insert at tail of free list */
    if (pMac->lim.freeAidTail)
    {
        pMac->lim.gpLimAIDpool[pMac->lim.freeAidTail]=(tANI_U8)aid;
        pMac->lim.freeAidTail=(tANI_U8)aid;
    }
    else
    {
        pMac->lim.freeAidTail=pMac->lim.freeAidHead=(tANI_U8)aid;
    }
<<<<<<< HEAD
    pSessionEntry->gpLimPeerIdxpool[(tANI_U8)peerIdx]=0;
    //PELOG2(limLog(pMac, LOG2,FL("Release aid %d, numSta %d, head %d tail %d "),aid,pMac->lim.gLimNumOfCurrentSTAs,pMac->lim.freeAidHead,pMac->lim.freeAidTail);)
>>>>>>> d97af3b... add prima wlan driver
=======
    pMac->lim.gpLimAIDpool[(tANI_U8)aid]=0;
    //PELOG2(limLog(pMac, LOG2,FL("Release aid %d, numSta %d, head %d tail %d \n"),aid,pMac->lim.gLimNumOfCurrentSTAs,pMac->lim.freeAidHead,pMac->lim.freeAidTail);)
>>>>>>> 657b0e9... prima update

}
