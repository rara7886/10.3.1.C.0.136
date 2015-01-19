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

/**=========================================================================

  \file  macTrace.h

  \brief definition for trace related APIs

  \author Sunit Bhatia

   Copyright 2008 (c) Qualcomm, Incorporated.  All Rights Reserved.

   Qualcomm Confidential and Proprietary.

  ========================================================================*/



#ifndef __MAC_TRACE_H
#define __MAC_TRACE_H

#include "aniGlobal.h"


<<<<<<< HEAD
<<<<<<< HEAD
#ifdef TRACE_RECORD

=======
>>>>>>> d97af3b... add prima wlan driver
=======
#ifdef TRACE_RECORD

>>>>>>> 657b0e9... prima update
#define CASE_RETURN_STRING( str )           \
    case ( ( str ) ): return( (tANI_U8*)(#str) ); break \

#define MAC_TRACE_GET_MODULE_ID(data) ((data >> 8) & 0xff)
#define MAC_TRACE_GET_MSG_ID(data)       (data & 0xffff)


typedef struct  sTraceRecord
{
<<<<<<< HEAD
<<<<<<< HEAD
    tANI_U16 time;
=======
    tANI_U32 time;
>>>>>>> d97af3b... add prima wlan driver
=======
    tANI_U16 time;
>>>>>>> 657b0e9... prima update
    tANI_U8 module;
    tANI_U8 code;
    tANI_U8 session;
    tANI_U32 data;
}tTraceRecord, *tpTraceRecord;

<<<<<<< HEAD
<<<<<<< HEAD


#define MAX_TRACE_RECORDS 500
#define INVALID_TRACE_ADDR 0xffffffff
#define DEFAULT_TRACE_DUMP_COUNT 200
=======
#define eLOG_NODROP_MISSED_BEACON_SCENARIO 0
#define eLOG_PROC_DEAUTH_FRAME_SCENARIO 1
=======
>>>>>>> 657b0e9... prima update


#define MAX_TRACE_RECORDS 500
#define INVALID_TRACE_ADDR 0xffffffff
<<<<<<< HEAD
#define DEFAULT_TRACE_DUMP_COUNT 0
>>>>>>> d97af3b... add prima wlan driver
=======
#define DEFAULT_TRACE_DUMP_COUNT 200
>>>>>>> 657b0e9... prima update



typedef void (*tpTraceCb)(tpAniSirGlobal, tpTraceRecord, tANI_U16);




typedef struct sTraceData
{
    tANI_U32 head;
    tANI_U32 tail;
    tANI_U32 num;
    tANI_U16 numSinceLastDump;

    //Config for controlling the trace
    tANI_U8 enable;
    tANI_U16 dumpCount; //will dump after number of records reach this number.

}tTraceData;


<<<<<<< HEAD
<<<<<<< HEAD

=======
#ifdef TRACE_RECORD
>>>>>>> d97af3b... add prima wlan driver
=======

>>>>>>> 657b0e9... prima update
void macTraceInit(tpAniSirGlobal pMac);
void macTraceReset(tpAniSirGlobal pMac);
void macTrace(tpAniSirGlobal pMac,  tANI_U8 code, tANI_U8 session, tANI_U32 data);
void macTraceNew(tpAniSirGlobal pMac,  tANI_U8 module, tANI_U8 code, tANI_U8 session, tANI_U32 data);
void macTraceDumpAll(tpAniSirGlobal pMac, tANI_U8 code, tANI_U8 session, tANI_U32 count);
void macTraceCfg(tpAniSirGlobal pMac, tANI_U32 enable, tANI_U32 dumpWhenFull, tANI_U32 code, tANI_U32 session);
void macTraceRegister( tpAniSirGlobal pMac, VOS_MODULE_ID moduleId,    tpTraceCb traceCb);
tANI_U8* macTraceGetCfgMsgString( tANI_U16 cfgMsg );
tANI_U8* macTraceGetLimMsgString( tANI_U16 limMsg );
<<<<<<< HEAD
<<<<<<< HEAD
tANI_U8* macTraceGetHalMsgString( tANI_U16 halMsg );
tANI_U8* macTraceGetSmeMsgString( tANI_U16 smeMsg );
tANI_U8* macTraceGetModuleString( tANI_U8 moduleId);



=======
tANI_U8* macTraceGetWdaMsgString( tANI_U16 wdaMsg );
=======
tANI_U8* macTraceGetHalMsgString( tANI_U16 halMsg );
>>>>>>> 657b0e9... prima update
tANI_U8* macTraceGetSmeMsgString( tANI_U16 smeMsg );
tANI_U8* macTraceGetModuleString( tANI_U8 moduleId);



<<<<<<< HEAD
static inline tANI_U8* macTraceGetNeighbourRoamState(tANI_U16 neighbourRoamState) { return NULL; }
static inline tANI_U8* macTraceGetcsrRoamState(tANI_U16 csrRoamState) { return NULL; }
static inline tANI_U8* macTraceGetcsrRoamSubState(tANI_U16 csrRoamSubState) { return NULL; }
static inline tANI_U8* macTraceGetLimSmeState(tANI_U16 limState) { return NULL; }
static inline tANI_U8* macTraceGetLimMlmState(tANI_U16 mlmState) { return NULL; }
static inline tANI_U8* macTraceGetTLState(tANI_U16 tlState) { return NULL; }
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
#endif

#endif

