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
 * Airgo Networks, Inc proprietary. All rights reserved.
 * logApi.cc - Handles log messages for all the modules.
<<<<<<< HEAD
<<<<<<< HEAD
 * Author:        Kevin Nguyen    
=======
 * Author:        Kevin Nguyen
>>>>>>> d97af3b... add prima wlan driver
=======
 * Author:        Kevin Nguyen    
>>>>>>> 657b0e9... prima update
 * Date:          02/27/02
 * History:-
 * 02/11/02       Created.
 * 03/12/02       Rearrange logDebug parameter list and add more params.
 * --------------------------------------------------------------------
<<<<<<< HEAD
<<<<<<< HEAD
 * 
 */
#define WNI_PRINT_DEBUG
=======
 *
 */
>>>>>>> d97af3b... add prima wlan driver
=======
 * 
 */
#define WNI_PRINT_DEBUG
>>>>>>> 657b0e9... prima update

#include <sirCommon.h>
#include <sirDebug.h>
#include <utilsApi.h>
<<<<<<< HEAD
<<<<<<< HEAD
#if defined(FEATURE_WLAN_NON_INTEGRATED_SOC)
#include <halCommonApi.h>
#endif
#include <wlan_qct_wda.h>

#include <stdarg.h>
#include "sirWrapper.h"
=======
#include <wlan_qct_wda.h>

#include <stdarg.h>
>>>>>>> d97af3b... add prima wlan driver
=======
#if defined(FEATURE_WLAN_NON_INTEGRATED_SOC)
#include <halCommonApi.h>
#endif
#include <wlan_qct_wda.h>

#include <stdarg.h>
#include "sirWrapper.h"
>>>>>>> 657b0e9... prima update
#include "utilsGlobal.h"
#include "macInitApi.h"
#include "palApi.h"

#include "vos_trace.h"

#ifdef ANI_OS_TYPE_ANDROID
#include <linux/kernel.h>
#endif


<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
//This is not right here. Need to find a better place. 
//_vsnprintf is a function in Windows
//Temporary workaround.
#ifndef ANI_OS_TYPE_WINDOWS
#ifndef _vsnprintf
#define _vsnprintf vsnprintf
#endif
#endif // not Windows

#define dbgTraceInfo(_Mask, _InParams)                 \
  {                                                      \
    KdPrint (_InParams) ;                                 \
  }

#define utilLogLogDebugMessage(HddAdapter, _LogBuffer)   \
  {                                                      \
    VOS_TRACE(VOS_MODULE_ID_SYS, VOS_TRACE_LEVEL_INFO,   \
              _LogBuffer);                               \
  }
  

<<<<<<< HEAD
// ---------------------------------------------------------------------
/**
 * logInit() 
=======
// ---------------------------------------------------------------------
/**
 * logInit()
>>>>>>> d97af3b... add prima wlan driver
=======
// ---------------------------------------------------------------------
/**
 * logInit() 
>>>>>>> 657b0e9... prima update
 *
 * FUNCTION:
 * This function is called to prepare the logging utility.
 *
 * LOGIC:
 *
 * ASSUMPTIONS:
 * None.
 *
 * NOTE:
 *
 * @param tpAniSirGlobal Sirius software parameter strucutre pointer
 * @return None
 */
<<<<<<< HEAD
<<<<<<< HEAD
tSirRetStatus 
=======
tSirRetStatus
>>>>>>> d97af3b... add prima wlan driver
=======
tSirRetStatus 
>>>>>>> 657b0e9... prima update
logInit(tpAniSirGlobal pMac)
{
    tANI_U32    i;

    // Add code to initialize debug level from CFG module
    // For now, enable all logging
    for (i = 0; i < LOG_ENTRY_NUM; i++)
    {
#ifdef SIR_DEBUG
        pMac->utils.gLogEvtLevel[i] = pMac->utils.gLogDbgLevel[i] = LOG1;
#else
<<<<<<< HEAD
<<<<<<< HEAD
#ifdef LX5280
        pMac->utils.gLogEvtLevel[i] = pMac->utils.gLogDbgLevel[i] = LOGE;
#else
        pMac->utils.gLogEvtLevel[i] = pMac->utils.gLogDbgLevel[i] = LOGW;
#endif
#endif
=======
        pMac->utils.gLogEvtLevel[i] = pMac->utils.gLogDbgLevel[i] = LOGW;
#endif
>>>>>>> d97af3b... add prima wlan driver
=======
#ifdef LX5280
        pMac->utils.gLogEvtLevel[i] = pMac->utils.gLogDbgLevel[i] = LOGE;
#else
        pMac->utils.gLogEvtLevel[i] = pMac->utils.gLogDbgLevel[i] = LOGW;
#endif
#endif
>>>>>>> 657b0e9... prima update
    }
    return eSIR_SUCCESS;

} /*** logInit() ***/

void
logDeinit(tpAniSirGlobal pMac)
{
    return;
}

/**
<<<<<<< HEAD
<<<<<<< HEAD
 * logDbg() 
=======
 * logDbg()
>>>>>>> d97af3b... add prima wlan driver
=======
 * logDbg() 
>>>>>>> 657b0e9... prima update
 *
 *FUNCTION:
 * This function is called to log a debug message.
 *
 *PARAMS:
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 * None.
 *
 *NOTE:
 *
 * @param tpAniSirGlobal Sirius software parameter strucutre pointer
 * @param ModId        8-bit modID
 * @param debugLevel   debugging level for this message
 * @param pStr         string parameter pointer
 * @return None
 */

<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
#if defined(ANI_OS_TYPE_OSX)
#if defined ANI_FIREWIRE_LOG
#include <IOKit/firewire/FireLog.h>
#define printk          FireLog
#else
#define printk          printf
#endif
#define tx_time_get()   (0)
#endif
<<<<<<< HEAD
=======
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update

void logDbg(tpAniSirGlobal pMac, tANI_U8 modId, tANI_U32 debugLevel, const char *pStr,...)
{
#ifdef WLAN_DEBUG
    if ( debugLevel > pMac->utils.gLogDbgLevel[LOG_INDEX_FOR_MODULE( modId )] )
        return;
    else
    {
        va_list marker;

        va_start( marker, pStr );     /* Initialize variable arguments. */

        logDebug(pMac, modId, debugLevel, pStr, marker);
<<<<<<< HEAD
<<<<<<< HEAD
        
        va_end( marker );              /* Reset variable arguments.      */
    }      
#endif
}

#ifdef VOSS_ENABLED
static inline VOS_TRACE_LEVEL getVosDebugLevel(tANI_U32 debugLevel)
{   
=======

=======
        
>>>>>>> 657b0e9... prima update
        va_end( marker );              /* Reset variable arguments.      */
    }      
#endif
}

<<<<<<< HEAD
VOS_TRACE_LEVEL getVosDebugLevel(tANI_U32 debugLevel)
{
>>>>>>> d97af3b... add prima wlan driver
=======
#ifdef VOSS_ENABLED
static inline VOS_TRACE_LEVEL getVosDebugLevel(tANI_U32 debugLevel)
{   
>>>>>>> 657b0e9... prima update
    switch(debugLevel)
    {
        case LOGP:
            return VOS_TRACE_LEVEL_FATAL;
        case LOGE:
            return VOS_TRACE_LEVEL_ERROR;
        case LOGW:
            return VOS_TRACE_LEVEL_WARN;
        case LOG1:
            return VOS_TRACE_LEVEL_INFO;
        case LOG2:
            return VOS_TRACE_LEVEL_INFO_HIGH;
        case LOG3:
            return VOS_TRACE_LEVEL_INFO_MED;
        case LOG4:
            return VOS_TRACE_LEVEL_INFO_LOW;
        default:
            return VOS_TRACE_LEVEL_INFO_LOW;
    }
}

static inline VOS_MODULE_ID getVosModuleId(tANI_U8 modId)
{
    switch(modId)
    {
        case SIR_HAL_MODULE_ID:
        case SIR_PHY_MODULE_ID:
            return VOS_MODULE_ID_WDA;
<<<<<<< HEAD
<<<<<<< HEAD

        case SIR_LIM_MODULE_ID:
        case SIR_SCH_MODULE_ID:
        case SIR_PMM_MODULE_ID:
=======
        case SIR_PMM_MODULE_ID:
            return VOS_MODULE_ID_PMC;

        case SIR_LIM_MODULE_ID:
        case SIR_SCH_MODULE_ID:
>>>>>>> d97af3b... add prima wlan driver
=======

        case SIR_LIM_MODULE_ID:
        case SIR_SCH_MODULE_ID:
        case SIR_PMM_MODULE_ID:
>>>>>>> 657b0e9... prima update
        case SIR_CFG_MODULE_ID:
        case SIR_MNT_MODULE_ID:
        case SIR_DPH_MODULE_ID:
        case SIR_DBG_MODULE_ID:
            return VOS_MODULE_ID_PE;

        case SIR_SYS_MODULE_ID:
            return VOS_MODULE_ID_SYS;
<<<<<<< HEAD
<<<<<<< HEAD
    
=======

>>>>>>> d97af3b... add prima wlan driver
=======
    
>>>>>>> 657b0e9... prima update
        case SIR_SMS_MODULE_ID:
            return VOS_MODULE_ID_SME;

        default:
            return VOS_MODULE_ID_SYS;
    }
}
<<<<<<< HEAD
<<<<<<< HEAD
#endif // VOSS_ENABLED
=======
>>>>>>> d97af3b... add prima wlan driver
=======
#endif // VOSS_ENABLED
>>>>>>> 657b0e9... prima update

#define LOG_SIZE 256
void logDebug(tpAniSirGlobal pMac, tANI_U8 modId, tANI_U32 debugLevel, const char *pStr, va_list marker)
{
    VOS_TRACE_LEVEL  vosDebugLevel;
    VOS_MODULE_ID    vosModuleId;
    char             logBuffer[LOG_SIZE];

    vosDebugLevel = getVosDebugLevel(debugLevel);
    vosModuleId = getVosModuleId(modId);

<<<<<<< HEAD
<<<<<<< HEAD
#ifdef ANI_OS_TYPE_ANDROID
    vsnprintf(logBuffer, LOG_SIZE - 1, pStr, marker);
#else

#ifdef WINDOWS_DT
    RtlStringCbVPrintfA( &logBuffer[ 0 ], LOG_SIZE - 1, pStr, marker );
#else
    _vsnprintf(logBuffer, LOG_SIZE - 1, (char *)pStr, marker);
#endif

#endif
=======
    vsnprintf(logBuffer, LOG_SIZE - 1, pStr, marker);
>>>>>>> d97af3b... add prima wlan driver
=======
#ifdef ANI_OS_TYPE_ANDROID
    vsnprintf(logBuffer, LOG_SIZE - 1, pStr, marker);
#else

#ifdef WINDOWS_DT
    RtlStringCbVPrintfA( &logBuffer[ 0 ], LOG_SIZE - 1, pStr, marker );
#else
    _vsnprintf(logBuffer, LOG_SIZE - 1, (char *)pStr, marker);
#endif

#endif
>>>>>>> 657b0e9... prima update
    VOS_TRACE(vosModuleId, vosDebugLevel, "%s", logBuffer);

    // The caller must check loglevel
    VOS_ASSERT( ( debugLevel <= pMac->utils.gLogDbgLevel[LOG_INDEX_FOR_MODULE( modId )] ) && ( LOGP != debugLevel ) );
} /*** end logDebug() ***/
