/*
<<<<<<< HEAD
<<<<<<< HEAD
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
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update

/**========================================================================

  \file  wlan_hdd_cfg80211.c

  \brief WLAN Host Device Driver implementation

<<<<<<< HEAD
<<<<<<< HEAD
  Copyright 2008 (c) Qualcomm, Incorporated.  All Rights Reserved.

  Qualcomm Confidential and Proprietary.

  ========================================================================*/

/**========================================================================= 

  EDIT HISTORY FOR FILE 


  This section contains comments describing changes made to the module. 
  Notice that changes are listed in reverse chronological order. 


  $Header:$   $DateTime: $ $Author: $ 


  when        who            what, where, why 
  --------    ---            --------------------------------------------------------
 21/12/09     Ashwani        Created module.  

 07/06/10     Kumar Deepak   Implemented cfg80211 callbacks for ANDROID
              Ganesh K       
  ==========================================================================*/

#ifdef CONFIG_CFG80211
=======
  Copyright 2008 (c) Qualcomm Technologies, Inc.  All Rights Reserved.
=======
  Copyright 2008 (c) Qualcomm, Incorporated.  All Rights Reserved.
>>>>>>> 657b0e9... prima update

  Qualcomm Confidential and Proprietary.

  ========================================================================*/

/**========================================================================= 

  EDIT HISTORY FOR FILE 


  This section contains comments describing changes made to the module. 
  Notice that changes are listed in reverse chronological order. 


  $Header:$   $DateTime: $ $Author: $ 


  when        who            what, where, why 
  --------    ---            --------------------------------------------------------
 21/12/09     Ashwani        Created module.  

 07/06/10     Kumar Deepak   Implemented cfg80211 callbacks for ANDROID
              Ganesh K       
  ==========================================================================*/

<<<<<<< HEAD
>>>>>>> d97af3b... add prima wlan driver
=======
#ifdef CONFIG_CFG80211
>>>>>>> 657b0e9... prima update

#include <linux/version.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/wireless.h>
#include <wlan_hdd_includes.h>
#include <net/arp.h>
#include <net/cfg80211.h>
#include <linux/wireless.h>
#include <wlan_hdd_wowl.h>
#include <aniGlobal.h>
#include "ccmApi.h"
#include "sirParams.h"
#include "dot11f.h"
#include "wlan_hdd_assoc.h"
#include "wlan_hdd_wext.h"
#include "sme_Api.h"
#include "wlan_hdd_p2p.h"
#include "wlan_hdd_cfg80211.h"
#include "wlan_hdd_hostapd.h"
#include "sapInternal.h"
#include "wlan_hdd_softap_tx_rx.h"
#include "wlan_hdd_main.h"
<<<<<<< HEAD
<<<<<<< HEAD
=======
#include "wlan_hdd_assoc.h"
#include "wlan_hdd_power.h"
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
#ifdef WLAN_BTAMP_FEATURE
#include "bap_hdd_misc.h"
#endif
#include <qc_sap_ioctl.h>
<<<<<<< HEAD
<<<<<<< HEAD
=======
#ifdef FEATURE_WLAN_TDLS
#include "wlan_hdd_tdls.h"
#include "wlan_hdd_wmm.h"
#include "wlan_qct_wda.h"
#endif
#include "wlan_nv.h"
#include "wlan_hdd_dev_pwr.h"
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update

#define g_mode_rates_size (12)
#define a_mode_rates_size (8)
#define FREQ_BASE_80211G          (2407)
#define FREQ_BAND_DIFF_80211G     (5)
#define MAX_SCAN_SSID 9
#define GET_IE_LEN_IN_BSS_DESC(lenInBss) ( lenInBss + sizeof(lenInBss) - \
        ((int) OFFSET_OF( tSirBssDescription, ieFields)))

#define HDD2GHZCHAN(freq, chan, flag)   {     \
    .band =  IEEE80211_BAND_2GHZ, \
    .center_freq = (freq), \
    .hw_value = (chan),\
    .flags = (flag), \
    .max_antenna_gain = 0 ,\
    .max_power = 30, \
}

#define HDD5GHZCHAN(freq, chan, flag)   {     \
    .band =  IEEE80211_BAND_5GHZ, \
    .center_freq = (freq), \
    .hw_value = (chan),\
    .flags = (flag), \
    .max_antenna_gain = 0 ,\
    .max_power = 30, \
}

#define HDD_G_MODE_RATETAB(rate, rate_id, flag)\
{\
    .bitrate = rate, \
    .hw_value = rate_id, \
    .flags = flag, \
}

<<<<<<< HEAD
<<<<<<< HEAD
static const u32 hdd_cipher_suites[] = 
=======
#ifndef WLAN_FEATURE_TDLS_DEBUG
#define TDLS_LOG_LEVEL VOS_TRACE_LEVEL_INFO
#else
#define TDLS_LOG_LEVEL VOS_TRACE_LEVEL_ERROR
#endif

#ifdef WLAN_FEATURE_VOWIFI_11R
#define WLAN_AKM_SUITE_FT_8021X         0x000FAC03
#define WLAN_AKM_SUITE_FT_PSK           0x000FAC04
#endif

static const u32 hdd_cipher_suites[] =
>>>>>>> d97af3b... add prima wlan driver
=======
static const u32 hdd_cipher_suites[] = 
>>>>>>> 657b0e9... prima update
{
    WLAN_CIPHER_SUITE_WEP40,
    WLAN_CIPHER_SUITE_WEP104,
    WLAN_CIPHER_SUITE_TKIP,
#ifdef FEATURE_WLAN_CCX
#define WLAN_CIPHER_SUITE_KRK 0x004096ff /* use for KRK */
    WLAN_CIPHER_SUITE_KRK,
    WLAN_CIPHER_SUITE_CCMP,
#else
    WLAN_CIPHER_SUITE_CCMP,
#endif
#ifdef FEATURE_WLAN_WAPI
    WLAN_CIPHER_SUITE_SMS4,
#endif
<<<<<<< HEAD
<<<<<<< HEAD
=======
#ifdef WLAN_FEATURE_11W
    WLAN_CIPHER_SUITE_AES_CMAC,
#endif
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
};

static inline int is_broadcast_ether_addr(const u8 *addr)
{
    return ((addr[0] == 0xff) && (addr[1] == 0xff) && (addr[2] == 0xff) &&
            (addr[3] == 0xff) && (addr[4] == 0xff) && (addr[5] == 0xff));
}

static struct ieee80211_channel hdd_channels_2_4_GHZ[] =
<<<<<<< HEAD
<<<<<<< HEAD
{  
=======
{
>>>>>>> d97af3b... add prima wlan driver
=======
{  
>>>>>>> 657b0e9... prima update
    HDD2GHZCHAN(2412, 1, 0) ,
    HDD2GHZCHAN(2417, 2, 0) ,
    HDD2GHZCHAN(2422, 3, 0) ,
    HDD2GHZCHAN(2427, 4, 0) ,
    HDD2GHZCHAN(2432, 5, 0) ,
    HDD2GHZCHAN(2437, 6, 0) ,
    HDD2GHZCHAN(2442, 7, 0) ,
    HDD2GHZCHAN(2447, 8, 0) ,
    HDD2GHZCHAN(2452, 9, 0) ,
    HDD2GHZCHAN(2457, 10, 0) ,
    HDD2GHZCHAN(2462, 11, 0) ,
    HDD2GHZCHAN(2467, 12, 0) ,
    HDD2GHZCHAN(2472, 13, 0) ,
    HDD2GHZCHAN(2484, 14, 0) ,
};

<<<<<<< HEAD
<<<<<<< HEAD
#ifdef WLAN_FEATURE_P2P
=======
>>>>>>> d97af3b... add prima wlan driver
=======
#ifdef WLAN_FEATURE_P2P
>>>>>>> 657b0e9... prima update
static struct ieee80211_channel hdd_social_channels_2_4_GHZ[] =
{
    HDD2GHZCHAN(2412, 1, 0) ,
    HDD2GHZCHAN(2437, 6, 0) ,
    HDD2GHZCHAN(2462, 11, 0) ,
};
<<<<<<< HEAD
<<<<<<< HEAD
#endif

static struct ieee80211_channel hdd_channels_5_GHZ[] =
{
=======

static struct ieee80211_channel hdd_channels_5_GHZ[] =
{
    HDD5GHZCHAN(4920, 240, 0) ,
    HDD5GHZCHAN(4940, 244, 0) ,
    HDD5GHZCHAN(4960, 248, 0) ,
    HDD5GHZCHAN(4980, 252, 0) ,
    HDD5GHZCHAN(5040, 208, 0) ,
    HDD5GHZCHAN(5060, 212, 0) ,
    HDD5GHZCHAN(5080, 216, 0) ,
>>>>>>> d97af3b... add prima wlan driver
=======
#endif

static struct ieee80211_channel hdd_channels_5_GHZ[] =
{
>>>>>>> 657b0e9... prima update
    HDD5GHZCHAN(5180, 36, 0) ,
    HDD5GHZCHAN(5200, 40, 0) ,
    HDD5GHZCHAN(5220, 44, 0) ,
    HDD5GHZCHAN(5240, 48, 0) ,
    HDD5GHZCHAN(5260, 52, 0) ,
    HDD5GHZCHAN(5280, 56, 0) ,
    HDD5GHZCHAN(5300, 60, 0) ,
    HDD5GHZCHAN(5320, 64, 0) ,
    HDD5GHZCHAN(5500,100, 0) ,
    HDD5GHZCHAN(5520,104, 0) ,
    HDD5GHZCHAN(5540,108, 0) ,
    HDD5GHZCHAN(5560,112, 0) ,
    HDD5GHZCHAN(5580,116, 0) ,
    HDD5GHZCHAN(5600,120, 0) ,
    HDD5GHZCHAN(5620,124, 0) ,
    HDD5GHZCHAN(5640,128, 0) ,
    HDD5GHZCHAN(5660,132, 0) ,
    HDD5GHZCHAN(5680,136, 0) ,
    HDD5GHZCHAN(5700,140, 0) ,
    HDD5GHZCHAN(5745,149, 0) ,
    HDD5GHZCHAN(5765,153, 0) ,
    HDD5GHZCHAN(5785,157, 0) ,
    HDD5GHZCHAN(5805,161, 0) ,
    HDD5GHZCHAN(5825,165, 0) ,
};

static struct ieee80211_rate g_mode_rates[] =
{
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
    HDD_G_MODE_RATETAB(10, 0x1, 0),    
    HDD_G_MODE_RATETAB(20, 0x2, 0),    
    HDD_G_MODE_RATETAB(55, 0x4, 0),    
    HDD_G_MODE_RATETAB(110, 0x8, 0),    
    HDD_G_MODE_RATETAB(60, 0x10, 0),    
    HDD_G_MODE_RATETAB(90, 0x20, 0),    
    HDD_G_MODE_RATETAB(120, 0x40, 0),    
    HDD_G_MODE_RATETAB(180, 0x80, 0),    
    HDD_G_MODE_RATETAB(240, 0x100, 0),    
    HDD_G_MODE_RATETAB(360, 0x200, 0),    
    HDD_G_MODE_RATETAB(480, 0x400, 0),    
<<<<<<< HEAD
    HDD_G_MODE_RATETAB(540, 0x800, 0),
};   

static struct ieee80211_rate a_mode_rates[] =
{
    HDD_G_MODE_RATETAB(60, 0x10, 0),    
    HDD_G_MODE_RATETAB(90, 0x20, 0),    
    HDD_G_MODE_RATETAB(120, 0x40, 0),    
    HDD_G_MODE_RATETAB(180, 0x80, 0),    
    HDD_G_MODE_RATETAB(240, 0x100, 0),    
    HDD_G_MODE_RATETAB(360, 0x200, 0),    
    HDD_G_MODE_RATETAB(480, 0x400, 0),    
=======
    HDD_G_MODE_RATETAB(10, 0x1, 0),
    HDD_G_MODE_RATETAB(20, 0x2, 0),
    HDD_G_MODE_RATETAB(55, 0x4, 0),
    HDD_G_MODE_RATETAB(110, 0x8, 0),
    HDD_G_MODE_RATETAB(60, 0x10, 0),
    HDD_G_MODE_RATETAB(90, 0x20, 0),
    HDD_G_MODE_RATETAB(120, 0x40, 0),
    HDD_G_MODE_RATETAB(180, 0x80, 0),
    HDD_G_MODE_RATETAB(240, 0x100, 0),
    HDD_G_MODE_RATETAB(360, 0x200, 0),
    HDD_G_MODE_RATETAB(480, 0x400, 0),
=======
>>>>>>> 657b0e9... prima update
    HDD_G_MODE_RATETAB(540, 0x800, 0),
};   

static struct ieee80211_rate a_mode_rates[] =
{
<<<<<<< HEAD
    HDD_G_MODE_RATETAB(60, 0x10, 0),
    HDD_G_MODE_RATETAB(90, 0x20, 0),
    HDD_G_MODE_RATETAB(120, 0x40, 0),
    HDD_G_MODE_RATETAB(180, 0x80, 0),
    HDD_G_MODE_RATETAB(240, 0x100, 0),
    HDD_G_MODE_RATETAB(360, 0x200, 0),
    HDD_G_MODE_RATETAB(480, 0x400, 0),
>>>>>>> d97af3b... add prima wlan driver
=======
    HDD_G_MODE_RATETAB(60, 0x10, 0),    
    HDD_G_MODE_RATETAB(90, 0x20, 0),    
    HDD_G_MODE_RATETAB(120, 0x40, 0),    
    HDD_G_MODE_RATETAB(180, 0x80, 0),    
    HDD_G_MODE_RATETAB(240, 0x100, 0),    
    HDD_G_MODE_RATETAB(360, 0x200, 0),    
    HDD_G_MODE_RATETAB(480, 0x400, 0),    
>>>>>>> 657b0e9... prima update
    HDD_G_MODE_RATETAB(540, 0x800, 0),
};

static struct ieee80211_supported_band wlan_hdd_band_2_4_GHZ =
{
    .channels = hdd_channels_2_4_GHZ,
    .n_channels = ARRAY_SIZE(hdd_channels_2_4_GHZ),
    .band       = IEEE80211_BAND_2GHZ,
    .bitrates = g_mode_rates,
    .n_bitrates = g_mode_rates_size,
    .ht_cap.ht_supported   = 1,
    .ht_cap.cap            =  IEEE80211_HT_CAP_SGI_20
                            | IEEE80211_HT_CAP_GRN_FLD
                            | IEEE80211_HT_CAP_DSSSCCK40
                            | IEEE80211_HT_CAP_LSIG_TXOP_PROT,
    .ht_cap.ampdu_factor   = IEEE80211_HT_MAX_AMPDU_64K,
    .ht_cap.ampdu_density  = IEEE80211_HT_MPDU_DENSITY_16,
    .ht_cap.mcs.rx_mask    = { 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
    .ht_cap.mcs.rx_highest = cpu_to_le16( 72 ),
    .ht_cap.mcs.tx_params  = IEEE80211_HT_MCS_TX_DEFINED,
};

<<<<<<< HEAD
<<<<<<< HEAD
#ifdef WLAN_FEATURE_P2P
=======
>>>>>>> d97af3b... add prima wlan driver
=======
#ifdef WLAN_FEATURE_P2P
>>>>>>> 657b0e9... prima update
static struct ieee80211_supported_band wlan_hdd_band_p2p_2_4_GHZ =
{
    .channels = hdd_social_channels_2_4_GHZ,
    .n_channels = ARRAY_SIZE(hdd_social_channels_2_4_GHZ),
    .band       = IEEE80211_BAND_2GHZ,
    .bitrates = g_mode_rates,
    .n_bitrates = g_mode_rates_size,
    .ht_cap.ht_supported   = 1,
    .ht_cap.cap            =  IEEE80211_HT_CAP_SGI_20
                            | IEEE80211_HT_CAP_GRN_FLD
                            | IEEE80211_HT_CAP_DSSSCCK40
                            | IEEE80211_HT_CAP_LSIG_TXOP_PROT,
    .ht_cap.ampdu_factor   = IEEE80211_HT_MAX_AMPDU_64K,
    .ht_cap.ampdu_density  = IEEE80211_HT_MPDU_DENSITY_16,
    .ht_cap.mcs.rx_mask    = { 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
    .ht_cap.mcs.rx_highest = cpu_to_le16( 72 ),
    .ht_cap.mcs.tx_params  = IEEE80211_HT_MCS_TX_DEFINED,
};
<<<<<<< HEAD
<<<<<<< HEAD
#endif
=======
>>>>>>> d97af3b... add prima wlan driver
=======
#endif
>>>>>>> 657b0e9... prima update

static struct ieee80211_supported_band wlan_hdd_band_5_GHZ =
{
    .channels = hdd_channels_5_GHZ,
    .n_channels = ARRAY_SIZE(hdd_channels_5_GHZ),
    .band     = IEEE80211_BAND_5GHZ,
    .bitrates = a_mode_rates,
    .n_bitrates = a_mode_rates_size,
    .ht_cap.ht_supported   = 1,
    .ht_cap.cap            =  IEEE80211_HT_CAP_SGI_20
                            | IEEE80211_HT_CAP_GRN_FLD
                            | IEEE80211_HT_CAP_DSSSCCK40
                            | IEEE80211_HT_CAP_LSIG_TXOP_PROT
                            | IEEE80211_HT_CAP_SGI_40
                            | IEEE80211_HT_CAP_SUP_WIDTH_20_40,
    .ht_cap.ampdu_factor   = IEEE80211_HT_MAX_AMPDU_64K,
    .ht_cap.ampdu_density  = IEEE80211_HT_MPDU_DENSITY_16,
    .ht_cap.mcs.rx_mask    = { 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
    .ht_cap.mcs.rx_highest = cpu_to_le16( 72 ),
    .ht_cap.mcs.tx_params  = IEEE80211_HT_MCS_TX_DEFINED,
};

<<<<<<< HEAD
<<<<<<< HEAD
/* This structure contain information what kind of frame are expected in 
=======
/* This structure contain information what kind of frame are expected in
>>>>>>> d97af3b... add prima wlan driver
=======
/* This structure contain information what kind of frame are expected in 
>>>>>>> 657b0e9... prima update
     TX/RX direction for each kind of interface */
static const struct ieee80211_txrx_stypes
wlan_hdd_txrx_stypes[NUM_NL80211_IFTYPES] = {
    [NL80211_IFTYPE_STATION] = {
        .tx = 0xffff,
        .rx = BIT(SIR_MAC_MGMT_ACTION) |
            BIT(SIR_MAC_MGMT_PROBE_REQ),
    },
    [NL80211_IFTYPE_AP] = {
        .tx = 0xffff,
        .rx = BIT(SIR_MAC_MGMT_ASSOC_REQ) |
            BIT(SIR_MAC_MGMT_REASSOC_REQ) |
            BIT(SIR_MAC_MGMT_PROBE_REQ) |
            BIT(SIR_MAC_MGMT_DISASSOC) |
            BIT(SIR_MAC_MGMT_AUTH) |
            BIT(SIR_MAC_MGMT_DEAUTH) |
            BIT(SIR_MAC_MGMT_ACTION),
    },
<<<<<<< HEAD
<<<<<<< HEAD
#ifdef WLAN_FEATURE_P2P    
=======
    [NL80211_IFTYPE_ADHOC] = {
        .tx = 0xffff,
        .rx = BIT(SIR_MAC_MGMT_ASSOC_REQ) |
            BIT(SIR_MAC_MGMT_REASSOC_REQ) |
            BIT(SIR_MAC_MGMT_PROBE_REQ) |
            BIT(SIR_MAC_MGMT_DISASSOC) |
            BIT(SIR_MAC_MGMT_AUTH) |
            BIT(SIR_MAC_MGMT_DEAUTH) |
            BIT(SIR_MAC_MGMT_ACTION),
    },
>>>>>>> d97af3b... add prima wlan driver
=======
#ifdef WLAN_FEATURE_P2P    
>>>>>>> 657b0e9... prima update
    [NL80211_IFTYPE_P2P_CLIENT] = {
        .tx = 0xffff,
        .rx = BIT(SIR_MAC_MGMT_ACTION) |
            BIT(SIR_MAC_MGMT_PROBE_REQ),
    },
    [NL80211_IFTYPE_P2P_GO] = {
        /* This is also same as for SoftAP */
        .tx = 0xffff,
        .rx = BIT(SIR_MAC_MGMT_ASSOC_REQ) |
            BIT(SIR_MAC_MGMT_REASSOC_REQ) |
            BIT(SIR_MAC_MGMT_PROBE_REQ) |
            BIT(SIR_MAC_MGMT_DISASSOC) |
            BIT(SIR_MAC_MGMT_AUTH) |
            BIT(SIR_MAC_MGMT_DEAUTH) |
            BIT(SIR_MAC_MGMT_ACTION),
    },
<<<<<<< HEAD
<<<<<<< HEAD
#endif    
};

=======
};

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(3,4,0))
static const struct ieee80211_iface_limit
wlan_hdd_iface_limit[] = {
    {
        /* max = 3 ; Our driver create two interfaces during driver init
         * wlan0 and p2p0 interfaces. p2p0 is considered as station
         * interface until a group is formed. In JB architecture, once the
         * group is formed, interface type of p2p0 is changed to P2P GO or
         * Client.
         * When supplicant remove the group, it first issue a set interface
         * cmd to change the mode back to Station. In JB this works fine as
         * we advertize two station type interface during driver init.
         * Some vendors create separate interface for P2P GO/Client,
         * after group formation(Third one). But while group remove
         * supplicant first tries to change the mode(3rd interface) to STATION
         * But as we advertized only two sta type interfaces nl80211 was
         * returning error for the third one which was leading to failure in
         * delete interface. Ideally while removing the group, supplicant
         * should not try to change the 3rd interface mode to Station type.
         * Till we get a fix in wpa_supplicant, we advertize max STA
         * interface type to 3
         */
        .max = 3,
        .types = BIT(NL80211_IFTYPE_STATION),
    },
    {
        .max = 1,
        .types = BIT(NL80211_IFTYPE_ADHOC) | BIT(NL80211_IFTYPE_AP),
    },
    {
        .max = 1,
        .types = BIT(NL80211_IFTYPE_P2P_GO) |
                 BIT(NL80211_IFTYPE_P2P_CLIENT),
    },
};

/* By default, only single channel concurrency is allowed */
static struct ieee80211_iface_combination
wlan_hdd_iface_combination = {
        .limits = wlan_hdd_iface_limit,
        .num_different_channels = 1,
        /*
         * max = WLAN_MAX_INTERFACES ; JellyBean architecture creates wlan0
         * and p2p0 interfaces during driver init
         * Some vendors create separate interface for P2P operations.
         * wlan0: STA interface
         * p2p0: P2P Device interface, action frames goes
         * through this interface.
         * p2p-xx: P2P interface, After GO negotiation this interface is
         * created for p2p operations(GO/CLIENT interface).
         */
        .max_interfaces = WLAN_MAX_INTERFACES,
        .n_limits = ARRAY_SIZE(wlan_hdd_iface_limit),
        .beacon_int_infra_match = false,
};
#endif

>>>>>>> d97af3b... add prima wlan driver
=======
#endif    
};

>>>>>>> 657b0e9... prima update
static struct cfg80211_ops wlan_hdd_cfg80211_ops;

/* Data rate 100KBPS based on IE Index */
struct index_data_rate_type
{
   v_U8_t   beacon_rate_index;
   v_U16_t  supported_rate[4];
};

/* 11B, 11G Rate table include Basic rate and Extended rate
   The IDX field is the rate index
   The HI field is the rate when RSSI is strong or being ignored
    (in this case we report actual rate)
   The MID field is the rate when RSSI is moderate
    (in this case we cap 11b rates at 5.5 and 11g rates at 24)
   The LO field is the rate when RSSI is low
    (in this case we don't report rates, actual current rate used)
 */
static const struct
{
   v_U8_t   beacon_rate_index;
<<<<<<< HEAD
<<<<<<< HEAD
   v_U16_t  supported_rate[3];
} supported_data_rate[] =
{
/* IDX     HI  MID LO (RSSI-based index */
   {2,   { 10,  10, 0}},
   {4,   { 20,  20, 0}},
   {11,  { 55,  55, 0}},
   {12,  { 60,  60, 0}},
   {18,  { 90,  90, 0}},
   {22,  {110,  55, 0}},
   {24,  {120, 120, 0}},
   {36,  {180, 180, 0}},
   {44,  {220, 220, 0}},
   {48,  {240, 240, 0}},
   {66,  {330, 240, 0}},
   {72,  {360, 240, 0}},
   {96,  {480, 240, 0}},
   {108, {540, 240, 0}}
=======
   v_U16_t  supported_rate[4];
} supported_data_rate[] =
{
/* IDX     HI  HM  LM LO (RSSI-based index */
   {2,   { 10,  10, 10, 0}},
   {4,   { 20,  20, 10, 0}},
   {11,  { 55,  20, 10, 0}},
   {12,  { 60,  55, 20, 0}},
   {18,  { 90,  55, 20, 0}},
   {22,  {110,  55, 20, 0}},
   {24,  {120,  90, 60, 0}},
   {36,  {180, 120, 60, 0}},
   {44,  {220, 180, 60, 0}},
   {48,  {240, 180, 90, 0}},
   {66,  {330, 180, 90, 0}},
   {72,  {360, 240, 90, 0}},
   {96,  {480, 240, 120, 0}},
   {108, {540, 240, 120, 0}}
>>>>>>> d97af3b... add prima wlan driver
=======
   v_U16_t  supported_rate[3];
} supported_data_rate[] =
{
/* IDX     HI  MID LO (RSSI-based index */
   {2,   { 10,  10, 0}},
   {4,   { 20,  20, 0}},
   {11,  { 55,  55, 0}},
   {12,  { 60,  60, 0}},
   {18,  { 90,  90, 0}},
   {22,  {110,  55, 0}},
   {24,  {120, 120, 0}},
   {36,  {180, 180, 0}},
   {44,  {220, 220, 0}},
   {48,  {240, 240, 0}},
   {66,  {330, 240, 0}},
   {72,  {360, 240, 0}},
   {96,  {480, 240, 0}},
   {108, {540, 240, 0}}
>>>>>>> 657b0e9... prima update
};

/* MCS Based rate table */
static struct index_data_rate_type supported_mcs_rate[] =
{
/* MCS  L20   L40   S20  S40 */
   {0,  {65,  135,  72,  150}},
   {1,  {130, 270,  144, 300}},
   {2,  {195, 405,  217, 450}},
   {3,  {260, 540,  289, 600}},
   {4,  {390, 810,  433, 900}},
   {5,  {520, 1080, 578, 1200}},
   {6,  {585, 1215, 650, 1350}},
   {7,  {650, 1350, 722, 1500}}
};

<<<<<<< HEAD
<<<<<<< HEAD
extern struct net_device_ops net_ops_struct;

/*
 * FUNCTION: wlan_hdd_cfg80211_init
 * This function is called by hdd_wlan_startup() 
 * during initialization. 
 * This function is used to initialize and register wiphy structure.
 */
struct wiphy *wlan_hdd_cfg80211_init(int priv_size)
=======
#ifdef WLAN_FEATURE_11AC

#define DATA_RATE_11AC_MCS_MASK    0x03

struct index_vht_data_rate_type
{
   v_U8_t   beacon_rate_index;
   v_U16_t  supported_VHT80_rate[2];
   v_U16_t  supported_VHT40_rate[2];
   v_U16_t  supported_VHT20_rate[2];
};

typedef enum
{
   DATA_RATE_11AC_MAX_MCS_7,
   DATA_RATE_11AC_MAX_MCS_8,
   DATA_RATE_11AC_MAX_MCS_9,
   DATA_RATE_11AC_MAX_MCS_NA
} eDataRate11ACMaxMcs;

/* MCS Based VHT rate table */
static struct index_vht_data_rate_type supported_vht_mcs_rate[] =
{
/* MCS  L80    S80     L40   S40    L20   S40*/
   {0,  {293,  325},  {135,  150},  {65,   72}},
   {1,  {585,  650},  {270,  300},  {130,  144}},
   {2,  {878,  975},  {405,  450},  {195,  217}},
   {3,  {1170, 1300}, {540,  600},  {260,  289}},
   {4,  {1755, 1950}, {810,  900},  {390,  433}},
   {5,  {2340, 2600}, {1080, 1200}, {520,  578}},
   {6,  {2633, 2925}, {1215, 1350}, {585,  650}},
   {7,  {2925, 3250}, {1350, 1500}, {650,  722}},
   {8,  {3510, 3900}, {1620, 1800}, {780,  867}},
   {9,  {3900, 4333}, {1800, 2000}, {780,  867}}
};
#endif /* WLAN_FEATURE_11AC */

=======
>>>>>>> 657b0e9... prima update
extern struct net_device_ops net_ops_struct;

/*
 * FUNCTION: wlan_hdd_cfg80211_init
 * This function is called by hdd_wlan_startup() 
 * during initialization. 
 * This function is used to initialize and register wiphy structure.
 */
<<<<<<< HEAD
struct wiphy *wlan_hdd_cfg80211_wiphy_alloc(int priv_size)
>>>>>>> d97af3b... add prima wlan driver
=======
struct wiphy *wlan_hdd_cfg80211_init(int priv_size)
>>>>>>> 657b0e9... prima update
{
    struct wiphy *wiphy;
    ENTER();

<<<<<<< HEAD
<<<<<<< HEAD
    /* 
     *   Create wiphy device 
=======
    /*
     *   Create wiphy device
>>>>>>> d97af3b... add prima wlan driver
=======
    /* 
     *   Create wiphy device 
>>>>>>> 657b0e9... prima update
     */
    wiphy = wiphy_new(&wlan_hdd_cfg80211_ops, priv_size);

    if (!wiphy)
    {
        /* Print error and jump into err label and free the memory */
        hddLog(VOS_TRACE_LEVEL_ERROR, "%s: wiphy init failed", __func__);
        return NULL;
    }

    return wiphy;
}

/*
 * FUNCTION: wlan_hdd_cfg80211_update_band
<<<<<<< HEAD
<<<<<<< HEAD
 * This function is called from the supplicant through a 
=======
 * This function is called from the supplicant through a
>>>>>>> d97af3b... add prima wlan driver
=======
 * This function is called from the supplicant through a 
>>>>>>> 657b0e9... prima update
 * private ioctl to change the band value
 */
int wlan_hdd_cfg80211_update_band(struct wiphy *wiphy, eCsrBand eBand)
{
<<<<<<< HEAD
<<<<<<< HEAD
    ENTER();
    switch(eBand)
    {
        case eCSR_BAND_24:
            wiphy->bands[IEEE80211_BAND_2GHZ] = &wlan_hdd_band_2_4_GHZ;
            wiphy->bands[IEEE80211_BAND_5GHZ] = NULL;
            break;
        case eCSR_BAND_5G:
#ifdef WLAN_FEATURE_P2P
            wiphy->bands[IEEE80211_BAND_2GHZ] = &wlan_hdd_band_p2p_2_4_GHZ;
#else
            wiphy->bands[IEEE80211_BAND_2GHZ] = NULL;
#endif
            wiphy->bands[IEEE80211_BAND_5GHZ] = &wlan_hdd_band_5_GHZ;
            break;
        case eCSR_BAND_ALL:
        default:
            wiphy->bands[IEEE80211_BAND_2GHZ] = &wlan_hdd_band_2_4_GHZ;
            wiphy->bands[IEEE80211_BAND_5GHZ] = &wlan_hdd_band_5_GHZ;
=======
    int i, j;
    eNVChannelEnabledType channelEnabledState;

=======
>>>>>>> 657b0e9... prima update
    ENTER();
    switch(eBand)
    {
<<<<<<< HEAD

        if (NULL == wiphy->bands[i])
        {
           hddLog(VOS_TRACE_LEVEL_ERROR,"%s: wiphy->bands[i] is NULL, i = %d",
                  __func__, i);
           continue;
        }

        for (j = 0; j < wiphy->bands[i]->n_channels; j++)
        {
            struct ieee80211_supported_band *band = wiphy->bands[i];

            channelEnabledState = vos_nv_getChannelEnabledState(
                                  band->channels[j].hw_value);

            if (IEEE80211_BAND_2GHZ == i && eCSR_BAND_5G == eBand) // 5G only
            {
                // Enable Social channels for P2P
                if (WLAN_HDD_IS_SOCIAL_CHANNEL(band->channels[j].center_freq) &&
                    NV_CHANNEL_ENABLE == channelEnabledState)
                    band->channels[j].flags &= ~IEEE80211_CHAN_DISABLED;
                else
                    band->channels[j].flags |= IEEE80211_CHAN_DISABLED;
                continue;
            }
            else if (IEEE80211_BAND_5GHZ == i && eCSR_BAND_24 == eBand) // 2G only
            {
                band->channels[j].flags |= IEEE80211_CHAN_DISABLED;
                continue;
            }

            if (NV_CHANNEL_DISABLE == channelEnabledState ||
                NV_CHANNEL_INVALID == channelEnabledState)
            {
                band->channels[j].flags |= IEEE80211_CHAN_DISABLED;
            }
            else if (NV_CHANNEL_DFS == channelEnabledState)
            {
                band->channels[j].flags &= ~IEEE80211_CHAN_DISABLED;
                band->channels[j].flags |= IEEE80211_CHAN_RADAR;
            }
            else
            {
                band->channels[j].flags &= ~(IEEE80211_CHAN_DISABLED
                                             |IEEE80211_CHAN_RADAR);
            }
        }
>>>>>>> d97af3b... add prima wlan driver
=======
        case eCSR_BAND_24:
            wiphy->bands[IEEE80211_BAND_2GHZ] = &wlan_hdd_band_2_4_GHZ;
            wiphy->bands[IEEE80211_BAND_5GHZ] = NULL;
            break;
        case eCSR_BAND_5G:
#ifdef WLAN_FEATURE_P2P
            wiphy->bands[IEEE80211_BAND_2GHZ] = &wlan_hdd_band_p2p_2_4_GHZ;
#else
            wiphy->bands[IEEE80211_BAND_2GHZ] = NULL;
#endif
            wiphy->bands[IEEE80211_BAND_5GHZ] = &wlan_hdd_band_5_GHZ;
            break;
        case eCSR_BAND_ALL:
        default:
            wiphy->bands[IEEE80211_BAND_2GHZ] = &wlan_hdd_band_2_4_GHZ;
            wiphy->bands[IEEE80211_BAND_5GHZ] = &wlan_hdd_band_5_GHZ;
>>>>>>> 657b0e9... prima update
    }
    return 0;
}
/*
 * FUNCTION: wlan_hdd_cfg80211_init
<<<<<<< HEAD
<<<<<<< HEAD
 * This function is called by hdd_wlan_startup() 
 * during initialization. 
 * This function is used to initialize and register wiphy structure.
 */
int wlan_hdd_cfg80211_register(struct device *dev, 
=======
 * This function is called by hdd_wlan_startup()
 * during initialization.
 * This function is used to initialize and register wiphy structure.
 */
int wlan_hdd_cfg80211_init(struct device *dev,
>>>>>>> d97af3b... add prima wlan driver
=======
 * This function is called by hdd_wlan_startup() 
 * during initialization. 
 * This function is used to initialize and register wiphy structure.
 */
int wlan_hdd_cfg80211_register(struct device *dev, 
>>>>>>> 657b0e9... prima update
                               struct wiphy *wiphy,
                               hdd_config_t *pCfg
                               )
{
<<<<<<< HEAD
<<<<<<< HEAD
=======
    int i, j;
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
    ENTER();

    /* Now bind the underlying wlan device with wiphy */
    set_wiphy_dev(wiphy, dev);

    wiphy->mgmt_stypes = wlan_hdd_txrx_stypes;

<<<<<<< HEAD
<<<<<<< HEAD
    wiphy->flags |=   WIPHY_FLAG_HAVE_AP_SME 
                    | WIPHY_FLAG_AP_PROBE_RESP_OFFLOAD
                    | WIPHY_FLAG_CUSTOM_REGULATORY;

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(3,4,0))
    wiphy->flags |=   WIPHY_FLAG_HAS_REMAIN_ON_CHANNEL 
                    | WIPHY_FLAG_OFFCHAN_TX;
#endif

    wiphy->max_scan_ssids = MAX_SCAN_SSID; 
    
    wiphy->max_scan_ie_len = 200 ; //TODO: define a macro

    /* Supports STATION & AD-HOC modes right now */
    wiphy->interface_modes =   BIT(NL80211_IFTYPE_STATION) 
                             | BIT(NL80211_IFTYPE_ADHOC)
#ifdef WLAN_FEATURE_P2P
                             | BIT(NL80211_IFTYPE_P2P_CLIENT)
                             | BIT(NL80211_IFTYPE_P2P_GO)
#endif                       
                             | BIT(NL80211_IFTYPE_AP);

=======
    /* This will disable updating of NL channels from passive to
     * active if a beacon is received on passive channel. */
    wiphy->flags |=   WIPHY_FLAG_DISABLE_BEACON_HINTS;

=======
    wiphy->flags |=   WIPHY_FLAG_HAVE_AP_SME 
                    | WIPHY_FLAG_AP_PROBE_RESP_OFFLOAD
                    | WIPHY_FLAG_CUSTOM_REGULATORY;
>>>>>>> 657b0e9... prima update

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(3,4,0))
    wiphy->flags |=   WIPHY_FLAG_HAS_REMAIN_ON_CHANNEL 
                    | WIPHY_FLAG_OFFCHAN_TX;
#endif

    wiphy->max_scan_ssids = MAX_SCAN_SSID; 
    
    wiphy->max_scan_ie_len = 200 ; //TODO: define a macro

    /* Supports STATION & AD-HOC modes right now */
    wiphy->interface_modes =   BIT(NL80211_IFTYPE_STATION) 
                             | BIT(NL80211_IFTYPE_ADHOC)
#ifdef WLAN_FEATURE_P2P
                             | BIT(NL80211_IFTYPE_P2P_CLIENT)
                             | BIT(NL80211_IFTYPE_P2P_GO)
#endif                       
                             | BIT(NL80211_IFTYPE_AP);

<<<<<<< HEAD
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(3,4,0))
    if( pCfg->enableMCC )
    {
        /* Currently, supports up to two channels */
        wlan_hdd_iface_combination.num_different_channels = 2;

        if( !pCfg->allowMCCGODiffBI )
            wlan_hdd_iface_combination.beacon_int_infra_match = true;

    }
    wiphy->iface_combinations = &wlan_hdd_iface_combination;
    wiphy->n_iface_combinations = 1;
#endif

>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
    /* Before registering we need to update the ht capabilitied based
     * on ini values*/
    if( !pCfg->ShortGI20MhzEnable )
    {
        wlan_hdd_band_2_4_GHZ.ht_cap.cap     &= ~IEEE80211_HT_CAP_SGI_20;
        wlan_hdd_band_5_GHZ.ht_cap.cap       &= ~IEEE80211_HT_CAP_SGI_20;
        wlan_hdd_band_p2p_2_4_GHZ.ht_cap.cap &= ~IEEE80211_HT_CAP_SGI_20;
    }

    if( !pCfg->ShortGI40MhzEnable )
    {
        wlan_hdd_band_5_GHZ.ht_cap.cap       &= ~IEEE80211_HT_CAP_SGI_40;
    }

    if( !pCfg->nChannelBondingMode5GHz )
    {
        wlan_hdd_band_5_GHZ.ht_cap.cap &= ~IEEE80211_HT_CAP_SUP_WIDTH_20_40;
    }

<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
    /*Initialize band capability*/
    switch(pCfg->nBandCapability)
    {
        case eCSR_BAND_24:
            wiphy->bands[IEEE80211_BAND_2GHZ] = &wlan_hdd_band_2_4_GHZ;
            break;
        case eCSR_BAND_5G:
#ifdef WLAN_FEATURE_P2P
            wiphy->bands[IEEE80211_BAND_2GHZ] = &wlan_hdd_band_p2p_2_4_GHZ;
#endif
            wiphy->bands[IEEE80211_BAND_5GHZ] = &wlan_hdd_band_5_GHZ;
            break;
        case eCSR_BAND_ALL:
        default:
            wiphy->bands[IEEE80211_BAND_2GHZ] = &wlan_hdd_band_2_4_GHZ;
            wiphy->bands[IEEE80211_BAND_5GHZ] = &wlan_hdd_band_5_GHZ;
<<<<<<< HEAD
=======
   wiphy->bands[IEEE80211_BAND_2GHZ] = &wlan_hdd_band_2_4_GHZ;
   wiphy->bands[IEEE80211_BAND_5GHZ] = &wlan_hdd_band_5_GHZ;

   for (i = 0; i < IEEE80211_NUM_BANDS; i++)
   {

       if (NULL == wiphy->bands[i])
       {
          hddLog(VOS_TRACE_LEVEL_ERROR,"%s: wiphy->bands[i] is NULL, i = %d",
                 __func__, i);
          continue;
       }

       for (j = 0; j < wiphy->bands[i]->n_channels; j++)
       {
           struct ieee80211_supported_band *band = wiphy->bands[i];

           if (IEEE80211_BAND_2GHZ == i && eCSR_BAND_5G == pCfg->nBandCapability) // 5G only
           {
               // Enable social channels for P2P
               if (WLAN_HDD_IS_SOCIAL_CHANNEL(band->channels[j].center_freq))
                   band->channels[j].flags &= ~IEEE80211_CHAN_DISABLED;
               else
                   band->channels[j].flags |= IEEE80211_CHAN_DISABLED;
               continue;
           }
           else if (IEEE80211_BAND_5GHZ == i && eCSR_BAND_24 == pCfg->nBandCapability) // 2G only
           {
               band->channels[j].flags |= IEEE80211_CHAN_DISABLED;
               continue;
           }
       }
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
    }
    /*Initialise the supported cipher suite details*/
    wiphy->cipher_suites = hdd_cipher_suites;
    wiphy->n_cipher_suites = ARRAY_SIZE(hdd_cipher_suites);

    /*signal strength in mBm (100*dBm) */
    wiphy->signal_type = CFG80211_SIGNAL_TYPE_MBM;

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,38))
<<<<<<< HEAD
<<<<<<< HEAD
#ifdef WLAN_FEATURE_P2P
    wiphy->max_remain_on_channel_duration = 1000;
#endif
#endif

    /* Register our wiphy dev with cfg80211 */
    if (0 > wiphy_register(wiphy))
    {
        /* print eror */
=======
=======
#ifdef WLAN_FEATURE_P2P
>>>>>>> 657b0e9... prima update
    wiphy->max_remain_on_channel_duration = 1000;
#endif
#endif

    /* Register our wiphy dev with cfg80211 */
    if (0 > wiphy_register(wiphy))
    {
<<<<<<< HEAD
        /* print error */
>>>>>>> d97af3b... add prima wlan driver
=======
        /* print eror */
>>>>>>> 657b0e9... prima update
        hddLog(VOS_TRACE_LEVEL_ERROR,"%s: wiphy register failed", __func__);
        return -EIO;
    }

    EXIT();
    return 0;
<<<<<<< HEAD
<<<<<<< HEAD
}     

/* In this function we will do all post VOS start initialization.
   In this function we will register for all frame in which supplicant
   is interested. 
*/
void wlan_hdd_cfg80211_post_voss_start(hdd_adapter_t* pAdapter)
{
#ifdef WLAN_FEATURE_P2P
=======
}

/* In this function we are updating channel list when,
   regulatory domain is FCC and country code is US.
   Here In FCC standard 5GHz UNII-1 Bands are indoor only.
   As per FCC smart phone is not a indoor device.
   GO should not opeate on indoor channels */
void wlan_hdd_cfg80211_update_reg_info(struct wiphy *wiphy)
{
    int j;
    hdd_context_t *pHddCtx = wiphy_priv(wiphy);
    tANI_U8 defaultCountryCode[3] = SME_INVALID_COUNTRY_CODE;
    //Default counrtycode from NV at the time of wiphy initialization.
    if (eHAL_STATUS_SUCCESS != sme_GetDefaultCountryCodeFrmNv(pHddCtx->hHal,
                                  &defaultCountryCode[0]))
    {
       hddLog(LOGE, FL("%s Failed to get default country code from NV"));
    }
    if ((defaultCountryCode[0]== 'U') && (defaultCountryCode[1]=='S'))
    {
       if (NULL == wiphy->bands[IEEE80211_BAND_5GHZ])
       {
          hddLog(VOS_TRACE_LEVEL_ERROR,"%s: wiphy->bands[IEEE80211_BAND_5GHZ] is NULL",__func__ );
          return;
       }
       for (j = 0; j < wiphy->bands[IEEE80211_BAND_5GHZ]->n_channels; j++)
       {
          struct ieee80211_supported_band *band = wiphy->bands[IEEE80211_BAND_5GHZ];
          // Mark UNII -1 band channel as passive
          if (WLAN_HDD_CHANNEL_IN_UNII_1_BAND(band->channels[j].center_freq))
             band->channels[j].flags |= IEEE80211_CHAN_PASSIVE_SCAN;
       }
    }
}
=======
}     
>>>>>>> 657b0e9... prima update

/* In this function we will do all post VOS start initialization.
   In this function we will register for all frame in which supplicant
   is interested. 
*/
void wlan_hdd_cfg80211_post_voss_start(hdd_adapter_t* pAdapter)
{
<<<<<<< HEAD
>>>>>>> d97af3b... add prima wlan driver
=======
#ifdef WLAN_FEATURE_P2P
>>>>>>> 657b0e9... prima update
    tHalHandle hHal = WLAN_HDD_GET_HAL_CTX(pAdapter);
    /* Register for all P2P action, public action etc frames */
    v_U16_t type = (SIR_MAC_MGMT_FRAME << 2) | ( SIR_MAC_MGMT_ACTION << 4);

    ENTER();

   /* Right now we are registering these frame when driver is getting
      initialized. Once we will move to 2.6.37 kernel, in which we have
      frame register ops, we will move this code as a part of that */
    /* GAS Initial Request */
<<<<<<< HEAD
<<<<<<< HEAD
    sme_RegisterMgmtFrame(hHal, pAdapter->sessionId, type, 
=======
    sme_RegisterMgmtFrame(hHal, pAdapter->sessionId, type,
>>>>>>> d97af3b... add prima wlan driver
=======
    sme_RegisterMgmtFrame(hHal, pAdapter->sessionId, type, 
>>>>>>> 657b0e9... prima update
                         (v_U8_t*)GAS_INITIAL_REQ, GAS_INITIAL_REQ_SIZE );

    /* GAS Initial Response */
    sme_RegisterMgmtFrame(hHal, pAdapter->sessionId, type,
                         (v_U8_t*)GAS_INITIAL_RSP, GAS_INITIAL_RSP_SIZE );
<<<<<<< HEAD
<<<<<<< HEAD
    
=======

>>>>>>> d97af3b... add prima wlan driver
=======
    
>>>>>>> 657b0e9... prima update
    /* GAS Comeback Request */
    sme_RegisterMgmtFrame(hHal, pAdapter->sessionId, type,
                         (v_U8_t*)GAS_COMEBACK_REQ, GAS_COMEBACK_REQ_SIZE );

    /* GAS Comeback Response */
    sme_RegisterMgmtFrame(hHal, pAdapter->sessionId, type,
                         (v_U8_t*)GAS_COMEBACK_RSP, GAS_COMEBACK_RSP_SIZE );

    /* P2P Public Action */
    sme_RegisterMgmtFrame(hHal, pAdapter->sessionId, type,
<<<<<<< HEAD
<<<<<<< HEAD
                         (v_U8_t*)P2P_PUBLIC_ACTION_FRAME, 
=======
                         (v_U8_t*)P2P_PUBLIC_ACTION_FRAME,
>>>>>>> d97af3b... add prima wlan driver
=======
                         (v_U8_t*)P2P_PUBLIC_ACTION_FRAME, 
>>>>>>> 657b0e9... prima update
                                  P2P_PUBLIC_ACTION_FRAME_SIZE );

    /* P2P Action */
    sme_RegisterMgmtFrame(hHal, pAdapter->sessionId, type,
                         (v_U8_t*)P2P_ACTION_FRAME,
                                  P2P_ACTION_FRAME_SIZE );
<<<<<<< HEAD
<<<<<<< HEAD
#endif /* WLAN_FEATURE_P2P */
=======

    /* WNM BSS Transition Request frame */
    sme_RegisterMgmtFrame(hHal, pAdapter->sessionId, type,
                         (v_U8_t*)WNM_BSS_ACTION_FRAME,
                                  WNM_BSS_ACTION_FRAME_SIZE );

#ifdef WLAN_FEATURE_11W
    /* SA Query Response Action Frame */
    sme_RegisterMgmtFrame(hHal, pAdapter->sessionId, type,
                         (v_U8_t*)SA_QUERY_FRAME_RSP,
                                  SA_QUERY_FRAME_RSP_SIZE );
#endif /* WLAN_FEATURE_11W */
>>>>>>> d97af3b... add prima wlan driver
=======
#endif /* WLAN_FEATURE_P2P */
>>>>>>> 657b0e9... prima update
}

void wlan_hdd_cfg80211_pre_voss_stop(hdd_adapter_t* pAdapter)
{
<<<<<<< HEAD
<<<<<<< HEAD
#ifdef WLAN_FEATURE_P2P
=======
>>>>>>> d97af3b... add prima wlan driver
=======
#ifdef WLAN_FEATURE_P2P
>>>>>>> 657b0e9... prima update
    tHalHandle hHal = WLAN_HDD_GET_HAL_CTX(pAdapter);
    /* Register for all P2P action, public action etc frames */
    v_U16_t type = (SIR_MAC_MGMT_FRAME << 2) | ( SIR_MAC_MGMT_ACTION << 4);

    ENTER();

   /* Right now we are registering these frame when driver is getting
      initialized. Once we will move to 2.6.37 kernel, in which we have
      frame register ops, we will move this code as a part of that */
    /* GAS Initial Request */

    sme_DeregisterMgmtFrame(hHal, pAdapter->sessionId, type,
                          (v_U8_t*)GAS_INITIAL_REQ, GAS_INITIAL_REQ_SIZE );

    /* GAS Initial Response */
    sme_DeregisterMgmtFrame(hHal, pAdapter->sessionId, type,
                         (v_U8_t*)GAS_INITIAL_RSP, GAS_INITIAL_RSP_SIZE );
<<<<<<< HEAD
<<<<<<< HEAD
    
=======

>>>>>>> d97af3b... add prima wlan driver
=======
    
>>>>>>> 657b0e9... prima update
    /* GAS Comeback Request */
    sme_DeregisterMgmtFrame(hHal, pAdapter->sessionId, type,
                         (v_U8_t*)GAS_COMEBACK_REQ, GAS_COMEBACK_REQ_SIZE );

    /* GAS Comeback Response */
    sme_DeregisterMgmtFrame(hHal, pAdapter->sessionId, type,
                         (v_U8_t*)GAS_COMEBACK_RSP, GAS_COMEBACK_RSP_SIZE );

    /* P2P Public Action */
    sme_DeregisterMgmtFrame(hHal, pAdapter->sessionId, type,
<<<<<<< HEAD
<<<<<<< HEAD
                         (v_U8_t*)P2P_PUBLIC_ACTION_FRAME, 
=======
                         (v_U8_t*)P2P_PUBLIC_ACTION_FRAME,
>>>>>>> d97af3b... add prima wlan driver
=======
                         (v_U8_t*)P2P_PUBLIC_ACTION_FRAME, 
>>>>>>> 657b0e9... prima update
                                  P2P_PUBLIC_ACTION_FRAME_SIZE );

    /* P2P Action */
    sme_DeregisterMgmtFrame(hHal, pAdapter->sessionId, type,
                         (v_U8_t*)P2P_ACTION_FRAME,
                                  P2P_ACTION_FRAME_SIZE );
<<<<<<< HEAD
<<<<<<< HEAD
#endif /* WLAN_FEATURE_P2P */
=======

#ifdef WLAN_FEATURE_11W
    /* SA Query Response Action Frame */
    sme_DeregisterMgmtFrame(hHal, pAdapter->sessionId, type,
                         (v_U8_t*)SA_QUERY_FRAME_RSP,
                                  SA_QUERY_FRAME_RSP_SIZE );
#endif /* WLAN_FEATURE_11W */
>>>>>>> d97af3b... add prima wlan driver
=======
#endif /* WLAN_FEATURE_P2P */
>>>>>>> 657b0e9... prima update
}

#ifdef FEATURE_WLAN_WAPI
void wlan_hdd_cfg80211_set_key_wapi(hdd_adapter_t* pAdapter, u8 key_index,
                                     const u8 *mac_addr, u8 *key , int key_Len)
{
    hdd_station_ctx_t *pHddStaCtx = WLAN_HDD_GET_STATION_CTX_PTR(pAdapter);
    tCsrRoamSetKey  setKey;
    v_BOOL_t isConnected = TRUE;
    int status = 0;
    v_U32_t roamId= 0xFF;
    tANI_U8 *pKeyPtr = NULL;
    int n = 0;

    hddLog(VOS_TRACE_LEVEL_INFO, "%s: device_mode = %d\n",
                                        __func__,pAdapter->device_mode);

<<<<<<< HEAD
<<<<<<< HEAD
=======
    vos_mem_zero(&setKey, sizeof(tCsrRoamSetKey));
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
    setKey.keyId = key_index; // Store Key ID
    setKey.encType  = eCSR_ENCRYPT_TYPE_WPI; // SET WAPI Encryption
    setKey.keyDirection = eSIR_TX_RX;  // Key Directionn both TX and RX
    setKey.paeRole = 0 ; // the PAE role
    if (!mac_addr || is_broadcast_ether_addr(mac_addr))
    {
        vos_set_macaddr_broadcast( (v_MACADDR_t *)setKey.peerMac );
    }
    else
    {
        isConnected = hdd_connIsConnected(pHddStaCtx);
        vos_mem_copy(setKey.peerMac,&pHddStaCtx->conn_info.bssId,WNI_CFG_BSSID_LEN);
    }
    setKey.keyLength = key_Len;
    pKeyPtr = setKey.Key;
    memcpy( pKeyPtr, key, key_Len);

    hddLog(VOS_TRACE_LEVEL_INFO,"\n%s: WAPI KEY LENGTH:0x%04x",
                                            __func__, key_Len);
    for (n = 0 ; n < key_Len; n++)
        hddLog(VOS_TRACE_LEVEL_INFO, "%s WAPI KEY Data[%d]:%02x ",
                                           __func__,n,setKey.Key[n]);

    pHddStaCtx->roam_info.roamingState = HDD_ROAM_STATE_SETTING_KEY;
    if ( isConnected )
    {
        status= sme_RoamSetKey( WLAN_HDD_GET_HAL_CTX(pAdapter),
                             pAdapter->sessionId, &setKey, &roamId );
    }
    if ( status != 0 )
    {
        VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                  "[%4d] sme_RoamSetKey returned ERROR status= %d",
                                                __LINE__, status );
        pHddStaCtx->roam_info.roamingState = HDD_ROAM_STATE_NONE;
    }
}
#endif /* FEATURE_WLAN_WAPI*/

#if (LINUX_VERSION_CODE < KERNEL_VERSION(3,4,0))
<<<<<<< HEAD
<<<<<<< HEAD
int wlan_hdd_cfg80211_alloc_new_beacon(hdd_adapter_t *pAdapter, 
                                       beacon_data_t **ppBeacon,
                                       struct beacon_parameters *params)
#else
int wlan_hdd_cfg80211_alloc_new_beacon(hdd_adapter_t *pAdapter, 
=======
int wlan_hdd_cfg80211_alloc_new_beacon(hdd_adapter_t *pAdapter,
                                       beacon_data_t **ppBeacon,
                                       struct beacon_parameters *params)
#else
int wlan_hdd_cfg80211_alloc_new_beacon(hdd_adapter_t *pAdapter,
>>>>>>> d97af3b... add prima wlan driver
=======
int wlan_hdd_cfg80211_alloc_new_beacon(hdd_adapter_t *pAdapter, 
                                       beacon_data_t **ppBeacon,
                                       struct beacon_parameters *params)
#else
int wlan_hdd_cfg80211_alloc_new_beacon(hdd_adapter_t *pAdapter, 
>>>>>>> 657b0e9... prima update
                                       beacon_data_t **ppBeacon,
                                       struct cfg80211_beacon_data *params,
                                       int dtim_period)
#endif
<<<<<<< HEAD
<<<<<<< HEAD
{    
=======
{
>>>>>>> d97af3b... add prima wlan driver
=======
{    
>>>>>>> 657b0e9... prima update
    int size;
    beacon_data_t *beacon = NULL;
    beacon_data_t *old = NULL;
    int head_len,tail_len;

    ENTER();
    if (params->head && !params->head_len)
        return -EINVAL;

    old = pAdapter->sessionCtx.ap.beacon;

    if (!params->head && !old)
        return -EINVAL;

    if (params->tail && !params->tail_len)
        return -EINVAL;

#if (LINUX_VERSION_CODE <= KERNEL_VERSION(2,6,38))
    /* Kernel 3.0 is not updating dtim_period for set beacon */
    if (!params->dtim_period)
        return -EINVAL;
#endif

    if(params->head)
        head_len = params->head_len;
    else
        head_len = old->head_len;

    if(params->tail || !old)
        tail_len = params->tail_len;
    else
        tail_len = old->tail_len;

    size = sizeof(beacon_data_t) + head_len + tail_len;

    beacon = kzalloc(size, GFP_KERNEL);

    if( beacon == NULL )
        return -ENOMEM;

#if (LINUX_VERSION_CODE < KERNEL_VERSION(3,4,0))
    if(params->dtim_period || !old )
        beacon->dtim_period = params->dtim_period;
    else
        beacon->dtim_period = old->dtim_period;
#else
    if(dtim_period || !old )
        beacon->dtim_period = dtim_period;
    else
        beacon->dtim_period = old->dtim_period;
#endif
<<<<<<< HEAD
<<<<<<< HEAD
 
=======

>>>>>>> d97af3b... add prima wlan driver
=======
 
>>>>>>> 657b0e9... prima update
    beacon->head = ((u8 *) beacon) + sizeof(beacon_data_t);
    beacon->tail = beacon->head + head_len;
    beacon->head_len = head_len;
    beacon->tail_len = tail_len;

    if(params->head) {
        memcpy (beacon->head,params->head,beacon->head_len);
    }
<<<<<<< HEAD
<<<<<<< HEAD
    else { 
        if(old)
            memcpy (beacon->head,old->head,beacon->head_len);
    }
    
=======
    else {
        if(old)
            memcpy (beacon->head,old->head,beacon->head_len);
    }

>>>>>>> d97af3b... add prima wlan driver
=======
    else { 
        if(old)
            memcpy (beacon->head,old->head,beacon->head_len);
    }
    
>>>>>>> 657b0e9... prima update
    if(params->tail) {
        memcpy (beacon->tail,params->tail,beacon->tail_len);
    }
    else {
<<<<<<< HEAD
<<<<<<< HEAD
       if(old)   
=======
       if(old)
>>>>>>> d97af3b... add prima wlan driver
=======
       if(old)   
>>>>>>> 657b0e9... prima update
           memcpy (beacon->tail,old->tail,beacon->tail_len);
    }

    *ppBeacon = beacon;

    kfree(old);

    return 0;

}

v_U8_t* wlan_hdd_cfg80211_get_ie_ptr(v_U8_t *pIes, int length, v_U8_t eid)
{
    int left = length;
    v_U8_t *ptr = pIes;
    v_U8_t elem_id,elem_len;
<<<<<<< HEAD
<<<<<<< HEAD
   
    while(left >= 2)
    {   
=======

    while(left >= 2)
    {
>>>>>>> d97af3b... add prima wlan driver
=======
   
    while(left >= 2)
    {   
>>>>>>> 657b0e9... prima update
        elem_id  =  ptr[0];
        elem_len =  ptr[1];
        left -= 2;
        if(elem_len > left)
        {
            hddLog(VOS_TRACE_LEVEL_FATAL,
                    FL("****Invalid IEs eid = %d elem_len=%d left=%d*****"),
                                                    eid,elem_len,left);
            return NULL;
        }
<<<<<<< HEAD
<<<<<<< HEAD
        if (elem_id == eid) 
        {
            return ptr;
        }
   
=======
        if (elem_id == eid)
        {
            return ptr;
        }

>>>>>>> d97af3b... add prima wlan driver
=======
        if (elem_id == eid) 
        {
            return ptr;
        }
   
>>>>>>> 657b0e9... prima update
        left -= elem_len;
        ptr += (elem_len + 2);
    }
    return NULL;
}

/* Check if rate is 11g rate or not */
static int wlan_hdd_rate_is_11g(u8 rate)
{
<<<<<<< HEAD
<<<<<<< HEAD
    u8 gRateArray[8] = {12, 18, 24, 36, 48, 72, 96, 104}; /* actual rate * 2 */
=======
    static const u8 gRateArray[8] = {12, 18, 24, 36, 48, 72, 96, 108}; /* actual rate * 2 */
>>>>>>> d97af3b... add prima wlan driver
=======
    u8 gRateArray[8] = {12, 18, 24, 36, 48, 72, 96, 104}; /* actual rate * 2 */
>>>>>>> 657b0e9... prima update
    u8 i;
    for (i = 0; i < 8; i++)
    {
        if(rate == gRateArray[i])
            return TRUE;
    }
    return FALSE;
}

/* Check for 11g rate and set proper 11g only mode */
static void wlan_hdd_check_11gmode(u8 *pIe, u8* require_ht,
                     u8* pCheckRatesfor11g, eSapPhyMode* pSapHw_mode)
{
    u8 i, num_rates = pIe[0];

    pIe += 1;
    for ( i = 0; i < num_rates; i++)
    {
        if( *pCheckRatesfor11g && (TRUE == wlan_hdd_rate_is_11g(pIe[i] & RATE_MASK)))
        {
            /* If rate set have 11g rate than change the mode to 11G */
            *pSapHw_mode = eSAP_DOT11_MODE_11g;
            if (pIe[i] & BASIC_RATE_MASK)
            {
                /* If we have 11g rate as  basic rate, it means mode
                   is 11g only mode.
                 */
               *pSapHw_mode = eSAP_DOT11_MODE_11g_ONLY;
               *pCheckRatesfor11g = FALSE;
            }
        }
        else if((BASIC_RATE_MASK | WLAN_BSS_MEMBERSHIP_SELECTOR_HT_PHY) == pIe[i])
        {
            *require_ht = TRUE;
        }
    }
    return;
}

static void wlan_hdd_set_sapHwmode(hdd_adapter_t *pHostapdAdapter)
{
    tsap_Config_t *pConfig = &pHostapdAdapter->sessionCtx.ap.sapConfig;
    beacon_data_t *pBeacon = pHostapdAdapter->sessionCtx.ap.beacon;
    struct ieee80211_mgmt *pMgmt_frame = (struct ieee80211_mgmt*)pBeacon->head;
    u8 checkRatesfor11g = TRUE;
    u8 require_ht = FALSE;
    u8 *pIe=NULL;

    pConfig->SapHw_mode= eSAP_DOT11_MODE_11b;

    pIe = wlan_hdd_cfg80211_get_ie_ptr(&pMgmt_frame->u.beacon.variable[0],
                                       pBeacon->head_len, WLAN_EID_SUPP_RATES);
    if (pIe != NULL)
    {
        pIe += 1;
        wlan_hdd_check_11gmode(pIe, &require_ht, &checkRatesfor11g,
                               &pConfig->SapHw_mode);
    }

    pIe = wlan_hdd_cfg80211_get_ie_ptr(pBeacon->tail, pBeacon->tail_len,
                                WLAN_EID_EXT_SUPP_RATES);
    if (pIe != NULL)
    {

        pIe += 1;
        wlan_hdd_check_11gmode(pIe, &require_ht, &checkRatesfor11g,
                               &pConfig->SapHw_mode);
    }

    if( pConfig->channel > 14 )
    {
        pConfig->SapHw_mode= eSAP_DOT11_MODE_11a;
    }

    pIe = wlan_hdd_cfg80211_get_ie_ptr(pBeacon->tail, pBeacon->tail_len,
                                       WLAN_EID_HT_CAPABILITY);

<<<<<<< HEAD
<<<<<<< HEAD
    if(pIe) 
=======
    if(pIe)
>>>>>>> d97af3b... add prima wlan driver
=======
    if(pIe) 
>>>>>>> 657b0e9... prima update
    {
        pConfig->SapHw_mode= eSAP_DOT11_MODE_11n;
        if(require_ht)
            pConfig->SapHw_mode= eSAP_DOT11_MODE_11n_ONLY;
    }
}

<<<<<<< HEAD
<<<<<<< HEAD
=======
static int wlan_hdd_add_ie(hdd_adapter_t* pHostapdAdapter, v_U8_t *genie,
                              v_U8_t *total_ielen, v_U8_t *oui, v_U8_t oui_size)
{
    v_U16_t ielen = 0;
    v_U8_t *pIe = NULL;
    beacon_data_t *pBeacon = pHostapdAdapter->sessionCtx.ap.beacon;

    pIe = wlan_hdd_get_vendor_oui_ie_ptr(oui, oui_size,
                                          pBeacon->tail, pBeacon->tail_len);

    if (pIe)
    {
        ielen = pIe[1] + 2;
        if ((*total_ielen + ielen) <= MAX_GENIE_LEN)
        {
            vos_mem_copy(&genie[*total_ielen], pIe, ielen);
        }
        else
        {
            hddLog( VOS_TRACE_LEVEL_ERROR, "**Ie Length is too big***");
            return -EINVAL;
        }
        *total_ielen += ielen;
    }
    return 0;
}

static void wlan_hdd_add_hostapd_conf_vsie(hdd_adapter_t* pHostapdAdapter,
                                           v_U8_t *genie, v_U8_t *total_ielen)
{
    beacon_data_t *pBeacon = pHostapdAdapter->sessionCtx.ap.beacon;
    int left = pBeacon->tail_len;
    v_U8_t *ptr = pBeacon->tail;
    v_U8_t elem_id, elem_len;
    v_U16_t ielen = 0;

    if ( NULL == ptr || 0 == left )
        return;

    while (left >= 2)
    {
        elem_id  = ptr[0];
        elem_len = ptr[1];
        left -= 2;
        if (elem_len > left)
        {
            hddLog( VOS_TRACE_LEVEL_ERROR,
                    "****Invalid IEs eid = %d elem_len=%d left=%d*****",
                    elem_id, elem_len, left);
            return;
        }
        if (IE_EID_VENDOR == elem_id)
        {
            /* skipping the VSIE's which we don't want to include or
             * it will be included by existing code
             */
            if ((memcmp( &ptr[2], WPS_OUI_TYPE, WPS_OUI_TYPE_SIZE) != 0 ) &&
#ifdef WLAN_FEATURE_WFD
               (memcmp( &ptr[2], WFD_OUI_TYPE, WFD_OUI_TYPE_SIZE) != 0) &&
#endif
               (memcmp( &ptr[2], WHITELIST_OUI_TYPE, WPA_OUI_TYPE_SIZE) != 0) &&
               (memcmp( &ptr[2], BLACKLIST_OUI_TYPE, WPA_OUI_TYPE_SIZE) != 0) &&
               (memcmp( &ptr[2], "\x00\x50\xf2\x02", WPA_OUI_TYPE_SIZE) != 0) &&
               (memcmp( &ptr[2], WPA_OUI_TYPE, WPA_OUI_TYPE_SIZE) != 0) &&
               (memcmp( &ptr[2], P2P_OUI_TYPE, P2P_OUI_TYPE_SIZE) != 0))
            {
               ielen = ptr[1] + 2;
               if ((*total_ielen + ielen) <= MAX_GENIE_LEN)
               {
                   vos_mem_copy(&genie[*total_ielen], ptr, ielen);
                   *total_ielen += ielen;
               }
               else
               {
                   hddLog( VOS_TRACE_LEVEL_ERROR,
                           "IE Length is too big "
                           "IEs eid=%d elem_len=%d total_ie_lent=%d",
                           elem_id, elem_len, *total_ielen);
               }
            }
        }

        left -= elem_len;
        ptr += (elem_len + 2);
    }
    return;
}

>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
#if (LINUX_VERSION_CODE < KERNEL_VERSION(3,4,0))
static int wlan_hdd_cfg80211_update_apies(hdd_adapter_t* pHostapdAdapter,
                            struct beacon_parameters *params)
#else
static int wlan_hdd_cfg80211_update_apies(hdd_adapter_t* pHostapdAdapter,
                                     struct cfg80211_beacon_data *params)
#endif
{
    v_U8_t *genie;
<<<<<<< HEAD
<<<<<<< HEAD
    v_U8_t total_ielen = 0, ielen = 0;
    v_U8_t *pIe = NULL;
    v_U8_t addIE[1] = {0};
    beacon_data_t *pBeacon = pHostapdAdapter->sessionCtx.ap.beacon;
=======
    v_U8_t total_ielen = 0;
    v_U8_t addIE[1] = {0};
>>>>>>> d97af3b... add prima wlan driver
=======
    v_U8_t total_ielen = 0, ielen = 0;
    v_U8_t *pIe = NULL;
    v_U8_t addIE[1] = {0};
    beacon_data_t *pBeacon = pHostapdAdapter->sessionCtx.ap.beacon;
>>>>>>> 657b0e9... prima update
    int ret = 0;

    genie = vos_mem_malloc(MAX_GENIE_LEN);

    if(genie == NULL) {

        return -ENOMEM;
    }

<<<<<<< HEAD
<<<<<<< HEAD
    pIe = wlan_hdd_get_wps_ie_ptr(pBeacon->tail, pBeacon->tail_len);

    if(pIe)
    {
        /*Copy the wps IE*/
        ielen = pIe[1] + 2;
        if( ielen <=MAX_GENIE_LEN)
        {
            vos_mem_copy(genie, pIe, ielen);
        }
        else 
        {
            hddLog( VOS_TRACE_LEVEL_ERROR, "**Wps Ie Length is too big***\n");
            ret = -EINVAL;
            goto done;
        }
        total_ielen = ielen;
    }

#ifdef WLAN_FEATURE_WFD
    pIe = wlan_hdd_get_wfd_ie_ptr(pBeacon->tail,pBeacon->tail_len);

    if(pIe) 
    { 
        ielen = pIe[1] + 2;
        if(total_ielen + ielen <= MAX_GENIE_LEN) {
            vos_mem_copy(&genie[total_ielen],pIe,(pIe[1] + 2));
        }
        else {
           hddLog( VOS_TRACE_LEVEL_ERROR, "**Wps Ie + P2p Ie + Wfd Ie Length is too big***\n");
           ret = -EINVAL;
           goto done;
        }
        total_ielen += ielen; 
    }
#endif

#ifdef WLAN_FEATURE_P2P
    pIe = wlan_hdd_get_p2p_ie_ptr(pBeacon->tail,pBeacon->tail_len);

    if(pIe)
    {
        ielen = pIe[1] + 2;
        if(total_ielen + ielen <= MAX_GENIE_LEN)
        {
            vos_mem_copy(&genie[total_ielen], pIe, (pIe[1] + 2));
        }
        else
        {
            hddLog( VOS_TRACE_LEVEL_ERROR, 
                    "**Wps Ie+ P2pIE Length is too big***\n");
            ret = -EINVAL;
            goto done;
        }
        total_ielen += ielen;
    }
#endif
=======
    if (0 != wlan_hdd_add_ie(pHostapdAdapter, genie,
                              &total_ielen, WPS_OUI_TYPE, WPS_OUI_TYPE_SIZE))
=======
    pIe = wlan_hdd_get_wps_ie_ptr(pBeacon->tail, pBeacon->tail_len);

    if(pIe)
>>>>>>> 657b0e9... prima update
    {
        /*Copy the wps IE*/
        ielen = pIe[1] + 2;
        if( ielen <=MAX_GENIE_LEN)
        {
            vos_mem_copy(genie, pIe, ielen);
        }
        else 
        {
            hddLog( VOS_TRACE_LEVEL_ERROR, "**Wps Ie Length is too big***\n");
            ret = -EINVAL;
            goto done;
        }
        total_ielen = ielen;
    }

#ifdef WLAN_FEATURE_WFD
    pIe = wlan_hdd_get_wfd_ie_ptr(pBeacon->tail,pBeacon->tail_len);

    if(pIe) 
    { 
        ielen = pIe[1] + 2;
        if(total_ielen + ielen <= MAX_GENIE_LEN) {
            vos_mem_copy(&genie[total_ielen],pIe,(pIe[1] + 2));
        }
        else {
           hddLog( VOS_TRACE_LEVEL_ERROR, "**Wps Ie + P2p Ie + Wfd Ie Length is too big***\n");
           ret = -EINVAL;
           goto done;
        }
        total_ielen += ielen; 
    }
#endif

#ifdef WLAN_FEATURE_P2P
    pIe = wlan_hdd_get_p2p_ie_ptr(pBeacon->tail,pBeacon->tail_len);

    if(pIe)
    {
        ielen = pIe[1] + 2;
        if(total_ielen + ielen <= MAX_GENIE_LEN)
        {
            vos_mem_copy(&genie[total_ielen], pIe, (pIe[1] + 2));
        }
        else
        {
            hddLog( VOS_TRACE_LEVEL_ERROR, 
                    "**Wps Ie+ P2pIE Length is too big***\n");
            ret = -EINVAL;
            goto done;
        }
        total_ielen += ielen;
    }
<<<<<<< HEAD
>>>>>>> d97af3b... add prima wlan driver
=======
#endif
>>>>>>> 657b0e9... prima update

    if (ccmCfgSetStr((WLAN_HDD_GET_CTX(pHostapdAdapter))->hHal,
       WNI_CFG_PROBE_RSP_BCN_ADDNIE_DATA, genie, total_ielen, NULL,
               eANI_BOOLEAN_FALSE)==eHAL_STATUS_FAILURE)
    {
        hddLog(LOGE,
               "Could not pass on WNI_CFG_PROBE_RSP_BCN_ADDNIE_DATA to CCM");
        ret = -EINVAL;
        goto done;
    }

    if (ccmCfgSetInt((WLAN_HDD_GET_CTX(pHostapdAdapter))->hHal,
          WNI_CFG_PROBE_RSP_BCN_ADDNIE_FLAG, 1,NULL,
          test_bit(SOFTAP_BSS_STARTED, &pHostapdAdapter->event_flags) ?
                   eANI_BOOLEAN_TRUE : eANI_BOOLEAN_FALSE)
          ==eHAL_STATUS_FAILURE)
    {
        hddLog(LOGE,
            "Could not pass on WNI_CFG_PROBE_RSP_BCN_ADDNIE_FLAG to CCM");
        ret = -EINVAL;
        goto done;
    }

    // Added for ProResp IE
    if ( (params->proberesp_ies != NULL) && (params->proberesp_ies_len != 0) )
    {
        u16 rem_probe_resp_ie_len = params->proberesp_ies_len;
        u8 probe_rsp_ie_len[3] = {0};
        u8 counter = 0;
        /* Check Probe Resp Length if it is greater then 255 then Store
           Probe Resp IEs into WNI_CFG_PROBE_RSP_ADDNIE_DATA1 &
           WNI_CFG_PROBE_RSP_ADDNIE_DATA2 CFG Variable As We are not able
           Store More then 255 bytes into One Variable.
        */
        while ((rem_probe_resp_ie_len > 0) && (counter < 3))
        {
            if (rem_probe_resp_ie_len > MAX_CFG_STRING_LEN)
            {
                probe_rsp_ie_len[counter++] = MAX_CFG_STRING_LEN;
                rem_probe_resp_ie_len -= MAX_CFG_STRING_LEN;
            }
            else
            {
                probe_rsp_ie_len[counter++] = rem_probe_resp_ie_len;
                rem_probe_resp_ie_len = 0;
            }
        }

        rem_probe_resp_ie_len = 0;

        if (probe_rsp_ie_len[0] > 0)
        {
            if (ccmCfgSetStr((WLAN_HDD_GET_CTX(pHostapdAdapter))->hHal,
                            WNI_CFG_PROBE_RSP_ADDNIE_DATA1,
                            (tANI_U8*)&params->proberesp_ies[rem_probe_resp_ie_len],
                            probe_rsp_ie_len[0], NULL,
                            eANI_BOOLEAN_FALSE) == eHAL_STATUS_FAILURE)
            {
                 hddLog(LOGE,
                       "Could not pass on WNI_CFG_PROBE_RSP_ADDNIE_DATA1 to CCM");
                 ret = -EINVAL;
                 goto done;
            }
            rem_probe_resp_ie_len += probe_rsp_ie_len[0];
        }

        if (probe_rsp_ie_len[1] > 0)
        {
            if (ccmCfgSetStr((WLAN_HDD_GET_CTX(pHostapdAdapter))->hHal,
                            WNI_CFG_PROBE_RSP_ADDNIE_DATA2,
                            (tANI_U8*)&params->proberesp_ies[rem_probe_resp_ie_len],
                            probe_rsp_ie_len[1], NULL,
                            eANI_BOOLEAN_FALSE) == eHAL_STATUS_FAILURE)
            {
                 hddLog(LOGE,
                       "Could not pass on WNI_CFG_PROBE_RSP_ADDNIE_DATA2 to CCM");
                 ret = -EINVAL;
                 goto done;
            }
            rem_probe_resp_ie_len += probe_rsp_ie_len[1];
        }

        if (probe_rsp_ie_len[2] > 0)
        {
            if (ccmCfgSetStr((WLAN_HDD_GET_CTX(pHostapdAdapter))->hHal,
                            WNI_CFG_PROBE_RSP_ADDNIE_DATA3,
                            (tANI_U8*)&params->proberesp_ies[rem_probe_resp_ie_len],
                            probe_rsp_ie_len[2], NULL,
                            eANI_BOOLEAN_FALSE) == eHAL_STATUS_FAILURE)
            {
                 hddLog(LOGE,
                       "Could not pass on WNI_CFG_PROBE_RSP_ADDNIE_DATA3 to CCM");
                 ret = -EINVAL;
                 goto done;
            }
            rem_probe_resp_ie_len += probe_rsp_ie_len[2];
        }

        if (probe_rsp_ie_len[1] == 0 )
        {
            if ( eHAL_STATUS_FAILURE == ccmCfgSetStr((WLAN_HDD_GET_CTX(pHostapdAdapter))->hHal,
                            WNI_CFG_PROBE_RSP_ADDNIE_DATA2, (tANI_U8*)addIE, 0, NULL,
                            eANI_BOOLEAN_FALSE) )
            {
                hddLog(LOGE,
                   "Could not pass on WNI_CFG_PROBE_RSP_ADDNIE_DATA2 to CCM\n");
            }
        }

        if (probe_rsp_ie_len[2] == 0 )
        {
            if ( eHAL_STATUS_FAILURE == ccmCfgSetStr((WLAN_HDD_GET_CTX(pHostapdAdapter))->hHal,
                            WNI_CFG_PROBE_RSP_ADDNIE_DATA3, (tANI_U8*)addIE, 0, NULL,
                            eANI_BOOLEAN_FALSE) )
            {
                hddLog(LOGE,
                   "Could not pass on WNI_CFG_PROBE_RSP_ADDNIE_DATA3 to CCM\n");
            }
        }

        if (ccmCfgSetInt((WLAN_HDD_GET_CTX(pHostapdAdapter))->hHal,
             WNI_CFG_PROBE_RSP_ADDNIE_FLAG, 1,NULL,
             test_bit(SOFTAP_BSS_STARTED, &pHostapdAdapter->event_flags) ?
                      eANI_BOOLEAN_TRUE : eANI_BOOLEAN_FALSE)
             == eHAL_STATUS_FAILURE)
        {
           hddLog(LOGE,
             "Could not pass on WNI_CFG_PROBE_RSP_ADDNIE_FLAG to CCM");
           ret = -EINVAL;
           goto done;
        }
    }
    else
    {
        // Reset WNI_CFG_PROBE_RSP Flags
        wlan_hdd_reset_prob_rspies(pHostapdAdapter);

        hddLog(VOS_TRACE_LEVEL_INFO,
               "%s: No Probe Response IE received in set beacon",
               __func__);
    }

    // Added for AssocResp IE
    if ( (params->assocresp_ies != NULL) && (params->assocresp_ies_len != 0) )
    {
       if (ccmCfgSetStr((WLAN_HDD_GET_CTX(pHostapdAdapter))->hHal,
               WNI_CFG_ASSOC_RSP_ADDNIE_DATA, (tANI_U8*)params->assocresp_ies,
               params->assocresp_ies_len, NULL,
               eANI_BOOLEAN_FALSE) == eHAL_STATUS_FAILURE)
       {
            hddLog(LOGE,
                  "Could not pass on WNI_CFG_ASSOC_RSP_ADDNIE_DATA to CCM");
            ret = -EINVAL;
            goto done;
       }

       if (ccmCfgSetInt((WLAN_HDD_GET_CTX(pHostapdAdapter))->hHal,
          WNI_CFG_ASSOC_RSP_ADDNIE_FLAG, 1, NULL,
          test_bit(SOFTAP_BSS_STARTED, &pHostapdAdapter->event_flags) ?
                   eANI_BOOLEAN_TRUE : eANI_BOOLEAN_FALSE)
          == eHAL_STATUS_FAILURE)
       {
          hddLog(LOGE,
            "Could not pass on WNI_CFG_ASSOC_RSP_ADDNIE_FLAG to CCM");
          ret = -EINVAL;
          goto done;
       }
    }
    else
    {
        hddLog(VOS_TRACE_LEVEL_INFO,
               "%s: No Assoc Response IE received in set beacon",
               __func__);

        if ( eHAL_STATUS_FAILURE == ccmCfgSetInt((WLAN_HDD_GET_CTX(pHostapdAdapter))->hHal,
                            WNI_CFG_ASSOC_RSP_ADDNIE_FLAG, 0, NULL,
                            eANI_BOOLEAN_FALSE) )
        {
            hddLog(LOGE,
               "Could not pass on WNI_CFG_ASSOC_RSP_ADDNIE_FLAG to CCM\n");
        }
    }

done:
    vos_mem_free(genie);
<<<<<<< HEAD
<<<<<<< HEAD
    return 0;
}

/* 
=======
    return ret;
}

/*
>>>>>>> d97af3b... add prima wlan driver
=======
    return 0;
}

/* 
>>>>>>> 657b0e9... prima update
 * FUNCTION: wlan_hdd_validate_operation_channel
 * called by wlan_hdd_cfg80211_start_bss() and
 * wlan_hdd_cfg80211_set_channel()
 * This function validates whether given channel is part of valid
<<<<<<< HEAD
<<<<<<< HEAD
 * channel list. 
 */ 
static VOS_STATUS wlan_hdd_validate_operation_channel(hdd_adapter_t *pAdapter,int channel)
{
        
=======
 * channel list.
 */
VOS_STATUS wlan_hdd_validate_operation_channel(hdd_adapter_t *pAdapter,int channel)
{

>>>>>>> d97af3b... add prima wlan driver
=======
 * channel list. 
 */ 
static VOS_STATUS wlan_hdd_validate_operation_channel(hdd_adapter_t *pAdapter,int channel)
{
        
>>>>>>> 657b0e9... prima update
    v_U32_t num_ch = 0;
    u8 valid_ch[WNI_CFG_VALID_CHANNEL_LIST_LEN];
    u32 indx = 0;
    tHalHandle hHal = WLAN_HDD_GET_HAL_CTX(pAdapter);
<<<<<<< HEAD
<<<<<<< HEAD
     
    num_ch = WNI_CFG_VALID_CHANNEL_LIST_LEN;

    if (0 != ccmCfgGetStr(hHal, WNI_CFG_VALID_CHANNEL_LIST,
            valid_ch, &num_ch))
    {
        hddLog(VOS_TRACE_LEVEL_ERROR,
                "%s: failed to get valid channel list\n", __func__);
        return VOS_STATUS_E_FAILURE;
    }

    for (indx = 0; indx < num_ch; indx++)
    {
        if (channel == valid_ch[indx])
        {
            break;
        }
    }

    if (indx >= num_ch)
    {
        hddLog(VOS_TRACE_LEVEL_ERROR,
                "%s: Invalid Channel [%d] \n", __func__, channel);
        return VOS_STATUS_E_FAILURE;
    }
    return VOS_STATUS_SUCCESS;
         
}

=======
    v_U8_t fValidChannel = FALSE, count = 0;
    hdd_config_t *hdd_pConfig_ini= (WLAN_HDD_GET_CTX(pAdapter))->cfg_ini;

=======
     
>>>>>>> 657b0e9... prima update
    num_ch = WNI_CFG_VALID_CHANNEL_LIST_LEN;

    if (0 != ccmCfgGetStr(hHal, WNI_CFG_VALID_CHANNEL_LIST,
            valid_ch, &num_ch))
    {
        hddLog(VOS_TRACE_LEVEL_ERROR,
                "%s: failed to get valid channel list\n", __func__);
        return VOS_STATUS_E_FAILURE;
    }

    for (indx = 0; indx < num_ch; indx++)
    {
        if (channel == valid_ch[indx])
        {
            break;
        }
    }

    if (indx >= num_ch)
    {
        hddLog(VOS_TRACE_LEVEL_ERROR,
                "%s: Invalid Channel [%d] \n", __func__, channel);
        return VOS_STATUS_E_FAILURE;
    }
    return VOS_STATUS_SUCCESS;
         
}

<<<<<<< HEAD
/**
 * FUNCTION: wlan_hdd_cfg80211_set_channel
 * This function is used to set the channel number
 */
static int wlan_hdd_cfg80211_set_channel( struct wiphy *wiphy, struct net_device *dev,
                                   struct ieee80211_channel *chan,
                                   enum nl80211_channel_type channel_type
                                 )
{
    v_U32_t num_ch = 0;
    int channel = 0;
    hdd_adapter_t *pAdapter = NULL;
    int freq = chan->center_freq; /* freq is in MHZ */
    hdd_context_t *pHddCtx;
    int status;

    ENTER();

    if( NULL == dev )
    {
        hddLog(VOS_TRACE_LEVEL_ERROR,
                "%s: Called with dev = NULL.\n", __func__);
        return -ENODEV;
    }
    pAdapter = WLAN_HDD_GET_PRIV_PTR( dev );

    hddLog(VOS_TRACE_LEVEL_INFO,
                "%s: device_mode = %d  freq = %d \n",__func__,
                            pAdapter->device_mode, chan->center_freq);

    pHddCtx = WLAN_HDD_GET_CTX(pAdapter);
    status = wlan_hdd_validate_context(pHddCtx);

    if (0 != status)
    {
        VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                   "%s: HDD context is not valid", __func__);
        return status;
    }

    /*
     * Do freq to chan conversion
     * TODO: for 11a
     */

    channel = ieee80211_frequency_to_channel(freq);

    /* Check freq range */
    if ((WNI_CFG_CURRENT_CHANNEL_STAMIN > channel) ||
            (WNI_CFG_CURRENT_CHANNEL_STAMAX < channel))
    {
        hddLog(VOS_TRACE_LEVEL_ERROR,
                "%s: Channel [%d] is outside valid range from %d to %d\n",
                __func__, channel, WNI_CFG_CURRENT_CHANNEL_STAMIN,
                WNI_CFG_CURRENT_CHANNEL_STAMAX);
        return -EINVAL;
    }

    num_ch = WNI_CFG_VALID_CHANNEL_LIST_LEN;

    if ((WLAN_HDD_SOFTAP != pAdapter->device_mode) &&
       (WLAN_HDD_P2P_GO != pAdapter->device_mode))
    {
        if(VOS_STATUS_SUCCESS != wlan_hdd_validate_operation_channel(pAdapter,channel))
        {
            hddLog(VOS_TRACE_LEVEL_ERROR,
                    "%s: Invalid Channel [%d] \n", __func__, channel);
            return -EINVAL;
        }
        hddLog(VOS_TRACE_LEVEL_INFO_HIGH,
                "%s: set channel to [%d] for device mode =%d",
                          __func__, channel,pAdapter->device_mode);
    }
    if( (pAdapter->device_mode == WLAN_HDD_INFRA_STATION)
     || (pAdapter->device_mode == WLAN_HDD_P2P_CLIENT)
      )
    {
        hdd_wext_state_t *pWextState = WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter);
        tCsrRoamProfile * pRoamProfile = &pWextState->roamProfile;
        hdd_station_ctx_t *pHddStaCtx = WLAN_HDD_GET_STATION_CTX_PTR(pAdapter);

        if (eConnectionState_IbssConnected == pHddStaCtx->conn_info.connState)
        {
           /* Link is up then return cant set channel*/
            hddLog( VOS_TRACE_LEVEL_ERROR,
                   "%s: IBSS Associated, can't set the channel\n", __func__);
            return -EINVAL;
        }

        num_ch = pRoamProfile->ChannelInfo.numOfChannels = 1;
        pHddStaCtx->conn_info.operationChannel = channel;
        pRoamProfile->ChannelInfo.ChannelList =
            &pHddStaCtx->conn_info.operationChannel;
    }
    else if ((pAdapter->device_mode == WLAN_HDD_SOFTAP)
        ||   (pAdapter->device_mode == WLAN_HDD_P2P_GO)
            )
    {
        if (WLAN_HDD_P2P_GO == pAdapter->device_mode)
        {
            if(VOS_STATUS_SUCCESS !=
                       wlan_hdd_validate_operation_channel(pAdapter,channel))
            {
               hddLog(VOS_TRACE_LEVEL_ERROR,
                      "%s: Invalid Channel [%d] \n", __func__, channel);
               return -EINVAL;
            }
            (WLAN_HDD_GET_AP_CTX_PTR(pAdapter))->sapConfig.channel = channel;
        }
        else if ( WLAN_HDD_SOFTAP == pAdapter->device_mode )
        {
            hdd_config_t *cfg_param = (WLAN_HDD_GET_CTX(pAdapter))->cfg_ini;

            /* If auto channel selection is configured as enable/ 1 then ignore
            channel set by supplicant
            */
            if ( cfg_param->apAutoChannelSelection )
            {
                (WLAN_HDD_GET_AP_CTX_PTR(pAdapter))->sapConfig.channel =
                                                          AUTO_CHANNEL_SELECT;
                hddLog(VOS_TRACE_LEVEL_INFO_HIGH,
                       "%s: set channel to auto channel (0) for device mode =%d",
                       __func__, pAdapter->device_mode);
            }
            else
            {
                if(VOS_STATUS_SUCCESS !=
                         wlan_hdd_validate_operation_channel(pAdapter,channel))
                {
                   hddLog(VOS_TRACE_LEVEL_ERROR,
                          "%s: Invalid Channel [%d] \n", __func__, channel);
                   return -EINVAL;
                }
                (WLAN_HDD_GET_AP_CTX_PTR(pAdapter))->sapConfig.channel = channel;
            }
        }
    }
    else
    {
        hddLog(VOS_TRACE_LEVEL_FATAL,
               "%s: Invalid device mode failed to set valid channel", __func__);
        return -EINVAL;
    }
    EXIT();
    return status;
}
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update

#if (LINUX_VERSION_CODE < KERNEL_VERSION(3,4,0))
static int wlan_hdd_cfg80211_start_bss(hdd_adapter_t *pHostapdAdapter,
                            struct beacon_parameters *params)
#else
static int wlan_hdd_cfg80211_start_bss(hdd_adapter_t *pHostapdAdapter,
                                       struct cfg80211_beacon_data *params,
                                       const u8 *ssid, size_t ssid_len,
                                       enum nl80211_hidden_ssid hidden_ssid)
#endif
{
    tsap_Config_t *pConfig;
    beacon_data_t *pBeacon = NULL;
    struct ieee80211_mgmt *pMgmt_frame;
    v_U8_t *pIe=NULL;
    v_U16_t capab_info;
    eCsrAuthType RSNAuthType;
    eCsrEncryptionType RSNEncryptType;
    eCsrEncryptionType mcRSNEncryptType;
    int status = VOS_STATUS_SUCCESS;
    tpWLAN_SAPEventCB pSapEventCallback;
    hdd_hostapd_state_t *pHostapdState;
    v_U8_t wpaRsnIEdata[(SIR_MAC_MAX_IE_LENGTH * 2)+4];  //Max ie length 255 * 2(WPA+RSN) + 2 bytes (vendor specific ID) * 2
    v_CONTEXT_t pVosContext = (WLAN_HDD_GET_CTX(pHostapdAdapter))->pvosContext;
<<<<<<< HEAD
<<<<<<< HEAD
    struct qc_mac_acl_entry *acl_entry = NULL;
    v_SINT_t i;
=======
    tHalHandle hHal = WLAN_HDD_GET_HAL_CTX(pHostapdAdapter);
    struct qc_mac_acl_entry *acl_entry = NULL;
    v_SINT_t i;
    hdd_context_t *pHddCtx = WLAN_HDD_GET_CTX(pHostapdAdapter);
>>>>>>> d97af3b... add prima wlan driver
=======
    struct qc_mac_acl_entry *acl_entry = NULL;
    v_SINT_t i;
>>>>>>> 657b0e9... prima update

    ENTER();

    pHostapdState = WLAN_HDD_GET_HOSTAP_STATE_PTR(pHostapdAdapter);

    pConfig = &pHostapdAdapter->sessionCtx.ap.sapConfig;

    pBeacon = pHostapdAdapter->sessionCtx.ap.beacon;

    pMgmt_frame = (struct ieee80211_mgmt*)pBeacon->head;

    pConfig->beacon_int =  pMgmt_frame->u.beacon.beacon_int;

    //channel is already set in the set_channel Call back
    //pConfig->channel = pCommitConfig->channel;

    /*Protection parameter to enable or disable*/
<<<<<<< HEAD
<<<<<<< HEAD
    pConfig->protEnabled = 
=======
    pConfig->protEnabled =
>>>>>>> d97af3b... add prima wlan driver
=======
    pConfig->protEnabled = 
>>>>>>> 657b0e9... prima update
           (WLAN_HDD_GET_CTX(pHostapdAdapter))->cfg_ini->apProtEnabled;

    pConfig->dtim_period = pBeacon->dtim_period;

    hddLog(VOS_TRACE_LEVEL_INFO_HIGH,"****pConfig->dtim_period=%d***\n",
                                      pConfig->dtim_period);


    if (pHostapdAdapter->device_mode == WLAN_HDD_SOFTAP)
    {
        pIe = wlan_hdd_cfg80211_get_ie_ptr(pBeacon->tail, pBeacon->tail_len,
                                       WLAN_EID_COUNTRY);
        if(pIe)
        {
            tANI_BOOLEAN restartNeeded;
<<<<<<< HEAD
<<<<<<< HEAD
            tHalHandle hHal = WLAN_HDD_GET_HAL_CTX(pHostapdAdapter);
=======
>>>>>>> d97af3b... add prima wlan driver
=======
            tHalHandle hHal = WLAN_HDD_GET_HAL_CTX(pHostapdAdapter);
>>>>>>> 657b0e9... prima update
            pConfig->ieee80211d = 1;
            vos_mem_copy(pConfig->countryCode, &pIe[2], 3);
            sme_setRegInfo(hHal, pConfig->countryCode);
            sme_ResetCountryCodeInformation(hHal, &restartNeeded);
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
            /*
             * If auto channel is configured i.e. channel is 0,
             * so skip channel validation.
             */
            if( AUTO_CHANNEL_SELECT != pConfig->channel )
<<<<<<< HEAD
            {
                if(VOS_STATUS_SUCCESS != wlan_hdd_validate_operation_channel(pHostapdAdapter,pConfig->channel))
                {
                    hddLog(VOS_TRACE_LEVEL_ERROR,
                            "%s: Invalid Channel [%d] \n", __func__, pConfig->channel);
                    return -EINVAL;
                }
=======
        }
        else
        {
            pConfig->ieee80211d = 0;
        }
        /*
        * If auto channel is configured i.e. channel is 0,
        * so skip channel validation.
        */
        if( AUTO_CHANNEL_SELECT != pConfig->channel )
        {
            if(VOS_STATUS_SUCCESS != wlan_hdd_validate_operation_channel(pHostapdAdapter,pConfig->channel))
            {
                 hddLog(VOS_TRACE_LEVEL_ERROR,
                         "%s: Invalid Channel [%d] \n", __func__, pConfig->channel);
                 return -EINVAL;
>>>>>>> d97af3b... add prima wlan driver
=======
            {
                if(VOS_STATUS_SUCCESS != wlan_hdd_validate_operation_channel(pHostapdAdapter,pConfig->channel))
                {
                    hddLog(VOS_TRACE_LEVEL_ERROR,
                            "%s: Invalid Channel [%d] \n", __func__, pConfig->channel);
                    return -EINVAL;
                }
>>>>>>> 657b0e9... prima update
            }
        }
        else
        {
<<<<<<< HEAD
<<<<<<< HEAD
            pConfig->ieee80211d = 0;
=======
             if(1 != pHddCtx->is_dynamic_channel_range_set)
             {
                  hdd_config_t *hdd_pConfig= (WLAN_HDD_GET_CTX(pHostapdAdapter))->cfg_ini;
                  WLANSAP_SetChannelRange(hHal, hdd_pConfig->apStartChannelNum,
                       hdd_pConfig->apEndChannelNum,hdd_pConfig->apOperatingBand);
             }
                   pHddCtx->is_dynamic_channel_range_set = 0;
>>>>>>> d97af3b... add prima wlan driver
=======
            pConfig->ieee80211d = 0;
>>>>>>> 657b0e9... prima update
        }
    }
    else
    {
        pConfig->ieee80211d = 0;
    }
    pConfig->authType = eSAP_AUTO_SWITCH;

    capab_info = pMgmt_frame->u.beacon.capab_info;
<<<<<<< HEAD
<<<<<<< HEAD
    
    pConfig->privacy = (pMgmt_frame->u.beacon.capab_info & 
=======

    pConfig->privacy = (pMgmt_frame->u.beacon.capab_info &
>>>>>>> d97af3b... add prima wlan driver
=======
    
    pConfig->privacy = (pMgmt_frame->u.beacon.capab_info & 
>>>>>>> 657b0e9... prima update
                        WLAN_CAPABILITY_PRIVACY) ? VOS_TRUE : VOS_FALSE;

    (WLAN_HDD_GET_AP_CTX_PTR(pHostapdAdapter))->uPrivacy = pConfig->privacy;

    /*Set wps station to configured*/
    pIe = wlan_hdd_get_wps_ie_ptr(pBeacon->tail, pBeacon->tail_len);

    if(pIe)
    {
        if(pIe[1] < (2 + WPS_OUI_TYPE_SIZE))
        {
            hddLog( VOS_TRACE_LEVEL_ERROR, "**Wps Ie Length is too small***\n");
            return -EINVAL;
        }
        else if(memcmp(&pIe[2], WPS_OUI_TYPE, WPS_OUI_TYPE_SIZE) == 0)
        {
             hddLog( VOS_TRACE_LEVEL_INFO, "** WPS IE(len %d) ***", (pIe[1]+2));
             /* Check 15 bit of WPS IE as it contain information for wps state
              * WPS state
              */
              if(SAP_WPS_ENABLED_UNCONFIGURED == pIe[15])
              {
                  pConfig->wps_state = SAP_WPS_ENABLED_UNCONFIGURED;
              } else if(SAP_WPS_ENABLED_CONFIGURED == pIe[15])
              {
                  pConfig->wps_state = SAP_WPS_ENABLED_CONFIGURED;
              }
        }
    }
    else
    {
        pConfig->wps_state = SAP_WPS_DISABLED;
    }
<<<<<<< HEAD
<<<<<<< HEAD
    pConfig->fwdWPSPBCProbeReq  = 1; // Forward WPS PBC probe request frame up 

    pConfig->RSNWPAReqIELength = 0;
    pConfig->pRSNWPAReqIE = NULL;
    pIe = wlan_hdd_cfg80211_get_ie_ptr(pBeacon->tail, pBeacon->tail_len, 
                                       WLAN_EID_RSN);
    if(pIe && pIe[1])
    { 
        pConfig->RSNWPAReqIELength = pIe[1] + 2;
        memcpy(&wpaRsnIEdata[0], pIe, pConfig->RSNWPAReqIELength);
        pConfig->pRSNWPAReqIE = &wpaRsnIEdata[0];
        /* The actual processing may eventually be more extensive than 
         * this. Right now, just consume any PMKIDs that are  sent in 
         * by the app.
         * */
        status = hdd_softap_unpackIE( 
=======
    pConfig->fwdWPSPBCProbeReq  = 1; // Forward WPS PBC probe request frame up
=======
    pConfig->fwdWPSPBCProbeReq  = 1; // Forward WPS PBC probe request frame up 
>>>>>>> 657b0e9... prima update

    pConfig->RSNWPAReqIELength = 0;
    pConfig->pRSNWPAReqIE = NULL;
    pIe = wlan_hdd_cfg80211_get_ie_ptr(pBeacon->tail, pBeacon->tail_len, 
                                       WLAN_EID_RSN);
    if(pIe && pIe[1])
    { 
        pConfig->RSNWPAReqIELength = pIe[1] + 2;
        memcpy(&wpaRsnIEdata[0], pIe, pConfig->RSNWPAReqIELength);
        pConfig->pRSNWPAReqIE = &wpaRsnIEdata[0];
        /* The actual processing may eventually be more extensive than 
         * this. Right now, just consume any PMKIDs that are  sent in 
         * by the app.
         * */
<<<<<<< HEAD
        status = hdd_softap_unpackIE(
>>>>>>> d97af3b... add prima wlan driver
=======
        status = hdd_softap_unpackIE( 
>>>>>>> 657b0e9... prima update
                        vos_get_context( VOS_MODULE_ID_SME, pVosContext),
                        &RSNEncryptType,
                        &mcRSNEncryptType,
                        &RSNAuthType,
                        pConfig->pRSNWPAReqIE[1]+2,
                        pConfig->pRSNWPAReqIE );

        if( VOS_STATUS_SUCCESS == status )
        {
<<<<<<< HEAD
<<<<<<< HEAD
            /* Now copy over all the security attributes you have 
             * parsed out 
=======
            /* Now copy over all the security attributes you have
             * parsed out
>>>>>>> d97af3b... add prima wlan driver
=======
            /* Now copy over all the security attributes you have 
             * parsed out 
>>>>>>> 657b0e9... prima update
             * */
            pConfig->RSNEncryptType = RSNEncryptType; // Use the cipher type in the RSN IE
            pConfig->mcRSNEncryptType = mcRSNEncryptType;
            (WLAN_HDD_GET_AP_CTX_PTR(pHostapdAdapter))->ucEncryptType
                                                              = RSNEncryptType;
<<<<<<< HEAD
<<<<<<< HEAD
            hddLog( LOG1, FL("%s: CSR AuthType = %d, "
=======
            hddLog( LOG1, FL("CSR AuthType = %d, "
>>>>>>> d97af3b... add prima wlan driver
=======
            hddLog( LOG1, FL("%s: CSR AuthType = %d, "
>>>>>>> 657b0e9... prima update
                        "EncryptionType = %d mcEncryptionType = %d\n"),
                        RSNAuthType, RSNEncryptType, mcRSNEncryptType);
        }
    }
<<<<<<< HEAD
<<<<<<< HEAD
    
=======

>>>>>>> d97af3b... add prima wlan driver
=======
    
>>>>>>> 657b0e9... prima update
    pIe = wlan_hdd_get_vendor_oui_ie_ptr(WPA_OUI_TYPE, WPA_OUI_TYPE_SIZE,
                                         pBeacon->tail, pBeacon->tail_len);

    if(pIe && pIe[1] && (pIe[0] == DOT11F_EID_WPA))
    {
        if (pConfig->pRSNWPAReqIE)
        {
            /*Mixed mode WPA/WPA2*/
            memcpy((&wpaRsnIEdata[0] + pConfig->RSNWPAReqIELength), pIe, pIe[1] + 2);
            pConfig->RSNWPAReqIELength += pIe[1] + 2;
        }
        else
        {
            pConfig->RSNWPAReqIELength = pIe[1] + 2;
            memcpy(&wpaRsnIEdata[0], pIe, pConfig->RSNWPAReqIELength);
            pConfig->pRSNWPAReqIE = &wpaRsnIEdata[0];
<<<<<<< HEAD
<<<<<<< HEAD
            status = hdd_softap_unpackIE( 
=======
            status = hdd_softap_unpackIE(
>>>>>>> d97af3b... add prima wlan driver
=======
            status = hdd_softap_unpackIE( 
>>>>>>> 657b0e9... prima update
                          vos_get_context( VOS_MODULE_ID_SME, pVosContext),
                          &RSNEncryptType,
                          &mcRSNEncryptType,
                          &RSNAuthType,
                          pConfig->pRSNWPAReqIE[1]+2,
                          pConfig->pRSNWPAReqIE );

            if( VOS_STATUS_SUCCESS == status )
            {
<<<<<<< HEAD
<<<<<<< HEAD
                /* Now copy over all the security attributes you have 
                 * parsed out 
=======
                /* Now copy over all the security attributes you have
                 * parsed out
>>>>>>> d97af3b... add prima wlan driver
=======
                /* Now copy over all the security attributes you have 
                 * parsed out 
>>>>>>> 657b0e9... prima update
                 * */
                pConfig->RSNEncryptType = RSNEncryptType; // Use the cipher type in the RSN IE
                pConfig->mcRSNEncryptType = mcRSNEncryptType;
                (WLAN_HDD_GET_AP_CTX_PTR(pHostapdAdapter))->ucEncryptType
                                                              = RSNEncryptType;
<<<<<<< HEAD
<<<<<<< HEAD
                hddLog( LOG1, FL("%s: CSR AuthType = %d, "
=======
                hddLog( LOG1, FL("CSR AuthType = %d, "
>>>>>>> d97af3b... add prima wlan driver
=======
                hddLog( LOG1, FL("%s: CSR AuthType = %d, "
>>>>>>> 657b0e9... prima update
                                "EncryptionType = %d mcEncryptionType = %d\n"),
                                RSNAuthType, RSNEncryptType, mcRSNEncryptType);
            }
        }
    }

<<<<<<< HEAD
<<<<<<< HEAD
=======
    if (pConfig->RSNWPAReqIELength > sizeof wpaRsnIEdata) {
        hddLog( VOS_TRACE_LEVEL_ERROR, "**RSNWPAReqIELength is too large***");
        return -EINVAL;
    }

>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
    pConfig->SSIDinfo.ssidHidden = VOS_FALSE;

#if (LINUX_VERSION_CODE < KERNEL_VERSION(3,4,0))
    if (params->ssid != NULL)
    {
        memcpy(pConfig->SSIDinfo.ssid.ssId, params->ssid, params->ssid_len);
        pConfig->SSIDinfo.ssid.length = params->ssid_len;
        if (params->hidden_ssid != NL80211_HIDDEN_SSID_NOT_IN_USE)
            pConfig->SSIDinfo.ssidHidden = VOS_TRUE;
    }
#else
    if (ssid != NULL)
    {
        memcpy(pConfig->SSIDinfo.ssid.ssId, ssid, ssid_len);
        pConfig->SSIDinfo.ssid.length = ssid_len;
        if (hidden_ssid != NL80211_HIDDEN_SSID_NOT_IN_USE)
            pConfig->SSIDinfo.ssidHidden = VOS_TRUE;
    }
#endif

<<<<<<< HEAD
<<<<<<< HEAD
    vos_mem_copy(pConfig->self_macaddr.bytes, 
               pHostapdAdapter->macAddressCurrent.bytes, sizeof(v_MACADDR_t));
    
=======
    vos_mem_copy(pConfig->self_macaddr.bytes,
               pHostapdAdapter->macAddressCurrent.bytes, sizeof(v_MACADDR_t));

>>>>>>> d97af3b... add prima wlan driver
=======
    vos_mem_copy(pConfig->self_macaddr.bytes, 
               pHostapdAdapter->macAddressCurrent.bytes, sizeof(v_MACADDR_t));
    
>>>>>>> 657b0e9... prima update
    /* default value */
    pConfig->SapMacaddr_acl = eSAP_ACCEPT_UNLESS_DENIED;
    pConfig->num_accept_mac = 0;
    pConfig->num_deny_mac = 0;

    pIe = wlan_hdd_get_vendor_oui_ie_ptr(BLACKLIST_OUI_TYPE, WPA_OUI_TYPE_SIZE,
                                         pBeacon->tail, pBeacon->tail_len);

    /* pIe for black list is following form:
            type    : 1 byte
            length  : 1 byte
            OUI     : 4 bytes
            acl type : 1 byte
            no of mac addr in black list: 1 byte
            list of mac_acl_entries: variable, 6 bytes per mac address + sizeof(int) for vlan id
<<<<<<< HEAD
<<<<<<< HEAD
    */    
    if ((pIe != NULL) && (pIe[1] != 0))    
=======
    */
    if ((pIe != NULL) && (pIe[1] != 0))
>>>>>>> d97af3b... add prima wlan driver
=======
    */    
    if ((pIe != NULL) && (pIe[1] != 0))    
>>>>>>> 657b0e9... prima update
    {
        pConfig->SapMacaddr_acl = pIe[6];
        pConfig->num_deny_mac   = pIe[7];
        hddLog(VOS_TRACE_LEVEL_INFO,"acl type = %d no deny mac = %d\n",
                                     pIe[6], pIe[7]);
<<<<<<< HEAD
<<<<<<< HEAD
        if (pConfig->num_deny_mac > MAX_MAC_ADDRESS_DENIED)
            pConfig->num_deny_mac = MAX_MAC_ADDRESS_DENIED;
=======
        if (pConfig->num_deny_mac > MAX_ACL_MAC_ADDRESS)
            pConfig->num_deny_mac = MAX_ACL_MAC_ADDRESS;
>>>>>>> d97af3b... add prima wlan driver
=======
        if (pConfig->num_deny_mac > MAX_MAC_ADDRESS_DENIED)
            pConfig->num_deny_mac = MAX_MAC_ADDRESS_DENIED;
>>>>>>> 657b0e9... prima update
        acl_entry = (struct qc_mac_acl_entry *)(pIe + 8);
        for (i = 0; i < pConfig->num_deny_mac; i++)
        {
            vos_mem_copy(&pConfig->deny_mac[i], acl_entry->addr, sizeof(qcmacaddr));
            acl_entry++;
<<<<<<< HEAD
<<<<<<< HEAD
        }        
=======
        }
>>>>>>> d97af3b... add prima wlan driver
=======
        }        
>>>>>>> 657b0e9... prima update
    }
    pIe = wlan_hdd_get_vendor_oui_ie_ptr(WHITELIST_OUI_TYPE, WPA_OUI_TYPE_SIZE,
                                         pBeacon->tail, pBeacon->tail_len);

    /* pIe for white list is following form:
            type    : 1 byte
            length  : 1 byte
            OUI     : 4 bytes
            acl type : 1 byte
            no of mac addr in white list: 1 byte
            list of mac_acl_entries: variable, 6 bytes per mac address + sizeof(int) for vlan id
<<<<<<< HEAD
<<<<<<< HEAD
    */    
    if ((pIe != NULL) && (pIe[1] != 0))    
=======
    */
    if ((pIe != NULL) && (pIe[1] != 0))
>>>>>>> d97af3b... add prima wlan driver
=======
    */    
    if ((pIe != NULL) && (pIe[1] != 0))    
>>>>>>> 657b0e9... prima update
    {
        pConfig->SapMacaddr_acl = pIe[6];
        pConfig->num_accept_mac   = pIe[7];
        hddLog(VOS_TRACE_LEVEL_INFO,"acl type = %d no accept mac = %d\n",
                                      pIe[6], pIe[7]);
<<<<<<< HEAD
<<<<<<< HEAD
        if (pConfig->num_accept_mac > MAX_MAC_ADDRESS_ACCEPTED)
            pConfig->num_accept_mac = MAX_MAC_ADDRESS_ACCEPTED;
=======
        if (pConfig->num_accept_mac > MAX_ACL_MAC_ADDRESS)
            pConfig->num_accept_mac = MAX_ACL_MAC_ADDRESS;
>>>>>>> d97af3b... add prima wlan driver
=======
        if (pConfig->num_accept_mac > MAX_MAC_ADDRESS_ACCEPTED)
            pConfig->num_accept_mac = MAX_MAC_ADDRESS_ACCEPTED;
>>>>>>> 657b0e9... prima update
        acl_entry = (struct qc_mac_acl_entry *)(pIe + 8);
        for (i = 0; i < pConfig->num_accept_mac; i++)
        {
            vos_mem_copy(&pConfig->accept_mac[i], acl_entry->addr, sizeof(qcmacaddr));
            acl_entry++;
        }
    }
<<<<<<< HEAD
<<<<<<< HEAD
    wlan_hdd_set_sapHwmode(pHostapdAdapter);

#ifdef WLAN_FEATURE_11AC
    if(((WLAN_HDD_GET_CTX(pHostapdAdapter))->cfg_ini->dot11Mode == eHDD_DOT11_MODE_AUTO) || 
       ((WLAN_HDD_GET_CTX(pHostapdAdapter))->cfg_ini->dot11Mode == eHDD_DOT11_MODE_11ac) ||
       ((WLAN_HDD_GET_CTX(pHostapdAdapter))->cfg_ini->dot11Mode == eHDD_DOT11_MODE_11ac_ONLY) )
    {
        pConfig->SapHw_mode = eSAP_DOT11_MODE_11ac;
    }
#endif

=======

=======
>>>>>>> 657b0e9... prima update
    wlan_hdd_set_sapHwmode(pHostapdAdapter);

#ifdef WLAN_FEATURE_11AC
    if(((WLAN_HDD_GET_CTX(pHostapdAdapter))->cfg_ini->dot11Mode == eHDD_DOT11_MODE_AUTO) || 
       ((WLAN_HDD_GET_CTX(pHostapdAdapter))->cfg_ini->dot11Mode == eHDD_DOT11_MODE_11ac) ||
       ((WLAN_HDD_GET_CTX(pHostapdAdapter))->cfg_ini->dot11Mode == eHDD_DOT11_MODE_11ac_ONLY) )
    {
        pConfig->SapHw_mode = eSAP_DOT11_MODE_11ac;
    }
#endif

<<<<<<< HEAD
    if ( AUTO_CHANNEL_SELECT != pConfig->channel )
    {
        sme_SelectCBMode(hHal,
            sapConvertSapPhyModeToCsrPhyMode(pConfig->SapHw_mode),
            pConfig->channel);
    }
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
    // ht_capab is not what the name conveys,this is used for protection bitmap
    pConfig->ht_capab =
                 (WLAN_HDD_GET_CTX(pHostapdAdapter))->cfg_ini->apProtection;

    if ( 0 != wlan_hdd_cfg80211_update_apies(pHostapdAdapter, params) )
    {
        hddLog(LOGE, FL("SAP Not able to set AP IEs"));
        return -EINVAL;
    }

    //Uapsd Enabled Bit
<<<<<<< HEAD
<<<<<<< HEAD
    pConfig->UapsdEnable =  
          (WLAN_HDD_GET_CTX(pHostapdAdapter))->cfg_ini->apUapsdEnabled;
    //Enable OBSS protection
    pConfig->obssProtEnabled = 
           (WLAN_HDD_GET_CTX(pHostapdAdapter))->cfg_ini->apOBSSProtEnabled; 

    hddLog(LOGW, FL("SOftAP macaddress : "MAC_ADDRESS_STR"\n"), 
                 MAC_ADDR_ARRAY(pHostapdAdapter->macAddressCurrent.bytes));
    hddLog(LOGW,FL("ssid =%s\n"), pConfig->SSIDinfo.ssid.ssId);  
    hddLog(LOGW,FL("beaconint=%d, channel=%d\n"), (int)pConfig->beacon_int,
                                                     (int)pConfig->channel);
    hddLog(LOGW,FL("hw_mode=%x\n"),  pConfig->SapHw_mode);
    hddLog(LOGW,FL("privacy=%d, authType=%d\n"), pConfig->privacy, 
                                                 pConfig->authType); 
    hddLog(LOGW,FL("RSN/WPALen=%d, \n"),(int)pConfig->RSNWPAReqIELength);
    hddLog(LOGW,FL("Uapsd = %d\n"),pConfig->UapsdEnable); 
    hddLog(LOGW,FL("ProtEnabled = %d, OBSSProtEnabled = %d\n"),
                          pConfig->protEnabled, pConfig->obssProtEnabled);

    if(test_bit(SOFTAP_BSS_STARTED, &pHostapdAdapter->event_flags)) 
=======
    pConfig->UapsdEnable =
=======
    pConfig->UapsdEnable =  
>>>>>>> 657b0e9... prima update
          (WLAN_HDD_GET_CTX(pHostapdAdapter))->cfg_ini->apUapsdEnabled;
    //Enable OBSS protection
    pConfig->obssProtEnabled = 
           (WLAN_HDD_GET_CTX(pHostapdAdapter))->cfg_ini->apOBSSProtEnabled; 

    hddLog(LOGW, FL("SOftAP macaddress : "MAC_ADDRESS_STR"\n"), 
                 MAC_ADDR_ARRAY(pHostapdAdapter->macAddressCurrent.bytes));
    hddLog(LOGW,FL("ssid =%s\n"), pConfig->SSIDinfo.ssid.ssId);  
    hddLog(LOGW,FL("beaconint=%d, channel=%d\n"), (int)pConfig->beacon_int,
                                                     (int)pConfig->channel);
    hddLog(LOGW,FL("hw_mode=%x\n"),  pConfig->SapHw_mode);
    hddLog(LOGW,FL("privacy=%d, authType=%d\n"), pConfig->privacy, 
                                                 pConfig->authType); 
    hddLog(LOGW,FL("RSN/WPALen=%d, \n"),(int)pConfig->RSNWPAReqIELength);
    hddLog(LOGW,FL("Uapsd = %d\n"),pConfig->UapsdEnable); 
    hddLog(LOGW,FL("ProtEnabled = %d, OBSSProtEnabled = %d\n"),
                          pConfig->protEnabled, pConfig->obssProtEnabled);

<<<<<<< HEAD
    if(test_bit(SOFTAP_BSS_STARTED, &pHostapdAdapter->event_flags))
>>>>>>> d97af3b... add prima wlan driver
=======
    if(test_bit(SOFTAP_BSS_STARTED, &pHostapdAdapter->event_flags)) 
>>>>>>> 657b0e9... prima update
    {
        //Bss already started. just return.
        //TODO Probably it should update some beacon params.
        hddLog( LOGE, "Bss Already started...Ignore the request");
        EXIT();
        return 0;
    }
<<<<<<< HEAD
<<<<<<< HEAD
    
=======

>>>>>>> d97af3b... add prima wlan driver
=======
    
>>>>>>> 657b0e9... prima update
    pConfig->persona = pHostapdAdapter->device_mode;

    pSapEventCallback = hdd_hostapd_SAPEventCB;
    if(WLANSAP_StartBss(pVosContext, pSapEventCallback, pConfig,
                 (v_PVOID_t)pHostapdAdapter->dev) != VOS_STATUS_SUCCESS)
    {
        hddLog(LOGE,FL("SAP Start Bss fail\n"));
        return -EINVAL;
    }

<<<<<<< HEAD
<<<<<<< HEAD
    hddLog(LOG1, 
           FL("Waiting for Scan to complete(auto mode) and BSS to start"));

    status = vos_wait_single_event(&pHostapdState->vosEvent, 10000);
   
    if (!VOS_IS_STATUS_SUCCESS(status))
    {  
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR, 
                 ("ERROR: HDD vos wait for single_event failed!!\n"));
        VOS_ASSERT(0);
    }
 
    //Succesfully started Bss update the state bit.
    set_bit(SOFTAP_BSS_STARTED, &pHostapdAdapter->event_flags);

=======
    hddLog(LOG1,
=======
    hddLog(LOG1, 
>>>>>>> 657b0e9... prima update
           FL("Waiting for Scan to complete(auto mode) and BSS to start"));

    status = vos_wait_single_event(&pHostapdState->vosEvent, 10000);
   
    if (!VOS_IS_STATUS_SUCCESS(status))
    {  
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR, 
                 ("ERROR: HDD vos wait for single_event failed!!\n"));
        VOS_ASSERT(0);
    }
 
    //Succesfully started Bss update the state bit.
    set_bit(SOFTAP_BSS_STARTED, &pHostapdAdapter->event_flags);

<<<<<<< HEAD
#ifdef WLAN_FEATURE_P2P_DEBUG
    if (pHostapdAdapter->device_mode == WLAN_HDD_P2P_GO)
    {
         if(globalP2PConnectionStatus == P2P_GO_NEG_COMPLETED)
         {
             globalP2PConnectionStatus = P2P_GO_COMPLETED_STATE;
             hddLog(LOGE,"[P2P State] From Go nego completed to "
                         "Non-autonomous Group started");
         }
         else if(globalP2PConnectionStatus == P2P_NOT_ACTIVE)
         {
             globalP2PConnectionStatus = P2P_GO_COMPLETED_STATE;
             hddLog(LOGE,"[P2P State] From Inactive to "
                         "Autonomous Group started");
         }
    }
#endif

>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
    pHostapdState->bCommit = TRUE;
    EXIT();

   return 0;
}

#if (LINUX_VERSION_CODE < KERNEL_VERSION(3,4,0))
<<<<<<< HEAD
<<<<<<< HEAD
static int wlan_hdd_cfg80211_add_beacon(struct wiphy *wiphy, 
                                        struct net_device *dev, 
                                        struct beacon_parameters *params)
{
    hdd_adapter_t *pAdapter =  WLAN_HDD_GET_PRIV_PTR(dev);
    int status=VOS_STATUS_SUCCESS; 
=======
static int wlan_hdd_cfg80211_add_beacon(struct wiphy *wiphy,
                                        struct net_device *dev,
                                        struct beacon_parameters *params)
{
    hdd_adapter_t *pAdapter =  WLAN_HDD_GET_PRIV_PTR(dev);
    hdd_context_t  *pHddCtx;
    int status;
>>>>>>> d97af3b... add prima wlan driver
=======
static int wlan_hdd_cfg80211_add_beacon(struct wiphy *wiphy, 
                                        struct net_device *dev, 
                                        struct beacon_parameters *params)
{
    hdd_adapter_t *pAdapter =  WLAN_HDD_GET_PRIV_PTR(dev);
    int status=VOS_STATUS_SUCCESS; 
>>>>>>> 657b0e9... prima update

    ENTER();

    hddLog(VOS_TRACE_LEVEL_INFO_HIGH, "device mode=%d\n",pAdapter->device_mode);

<<<<<<< HEAD
<<<<<<< HEAD
    if ( (WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress )
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                "%s:LOGP in Progress. Ignore!!!", __func__);
        return -EAGAIN;
    }

    if ( (pAdapter->device_mode == WLAN_HDD_SOFTAP) 
#ifdef WLAN_FEATURE_P2P
      || (pAdapter->device_mode == WLAN_HDD_P2P_GO)
#endif
=======
    pHddCtx = WLAN_HDD_GET_CTX(pAdapter);
    status = wlan_hdd_validate_context(pHddCtx);

    if (0 != status)
=======
    if ( (WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress )
>>>>>>> 657b0e9... prima update
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                "%s:LOGP in Progress. Ignore!!!", __func__);
        return -EAGAIN;
    }

    if ( (pAdapter->device_mode == WLAN_HDD_SOFTAP) 
#ifdef WLAN_FEATURE_P2P
      || (pAdapter->device_mode == WLAN_HDD_P2P_GO)
<<<<<<< HEAD
>>>>>>> d97af3b... add prima wlan driver
=======
#endif
>>>>>>> 657b0e9... prima update
       )
    {
        beacon_data_t *old,*new;

        old = pAdapter->sessionCtx.ap.beacon;
<<<<<<< HEAD
<<<<<<< HEAD
   
=======

>>>>>>> d97af3b... add prima wlan driver
=======
   
>>>>>>> 657b0e9... prima update
        if (old)
            return -EALREADY;

        status = wlan_hdd_cfg80211_alloc_new_beacon(pAdapter,&new,params);

<<<<<<< HEAD
<<<<<<< HEAD
        if(status != VOS_STATUS_SUCCESS) 
=======
        if(status != VOS_STATUS_SUCCESS)
>>>>>>> d97af3b... add prima wlan driver
=======
        if(status != VOS_STATUS_SUCCESS) 
>>>>>>> 657b0e9... prima update
        {
             hddLog(VOS_TRACE_LEVEL_FATAL,
                   "%s:Error!!! Allocating the new beacon\n",__func__);
             return -EINVAL;
        }

        pAdapter->sessionCtx.ap.beacon = new;

        status = wlan_hdd_cfg80211_start_bss(pAdapter, params);
    }

    EXIT();
    return status;
}
<<<<<<< HEAD
<<<<<<< HEAD
 
static int wlan_hdd_cfg80211_set_beacon(struct wiphy *wiphy, 
                                        struct net_device *dev,
                                        struct beacon_parameters *params)
{
    hdd_adapter_t *pAdapter =  WLAN_HDD_GET_PRIV_PTR(dev); 
    int status=VOS_STATUS_SUCCESS;
=======

static int wlan_hdd_cfg80211_set_beacon(struct wiphy *wiphy,
                                        struct net_device *dev,
                                        struct beacon_parameters *params)
{
    hdd_adapter_t *pAdapter =  WLAN_HDD_GET_PRIV_PTR(dev);
    hdd_context_t  *pHddCtx;
    int status;
>>>>>>> d97af3b... add prima wlan driver
=======
 
static int wlan_hdd_cfg80211_set_beacon(struct wiphy *wiphy, 
                                        struct net_device *dev,
                                        struct beacon_parameters *params)
{
    hdd_adapter_t *pAdapter =  WLAN_HDD_GET_PRIV_PTR(dev); 
    int status=VOS_STATUS_SUCCESS;
>>>>>>> 657b0e9... prima update

    ENTER();

    hddLog(VOS_TRACE_LEVEL_INFO, "%s: device_mode = %d\n",
                                __func__,pAdapter->device_mode);

<<<<<<< HEAD
<<<<<<< HEAD
    if ( (WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress )
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                "%s:LOGP in Progress. Ignore!!!", __func__);
        return -EAGAIN;
    }

    if ((pAdapter->device_mode == WLAN_HDD_SOFTAP) 
#ifdef WLAN_FEATURE_P2P
     || (pAdapter->device_mode == WLAN_HDD_P2P_GO)
#endif
       ) 
    {
        beacon_data_t *old,*new;
                
        old = pAdapter->sessionCtx.ap.beacon;
        
=======
    pHddCtx = WLAN_HDD_GET_CTX(pAdapter);
    status = wlan_hdd_validate_context(pHddCtx);

    if (0 != status)
=======
    if ( (WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress )
>>>>>>> 657b0e9... prima update
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                "%s:LOGP in Progress. Ignore!!!", __func__);
        return -EAGAIN;
    }

    if ((pAdapter->device_mode == WLAN_HDD_SOFTAP) 
#ifdef WLAN_FEATURE_P2P
     || (pAdapter->device_mode == WLAN_HDD_P2P_GO)
#endif
       ) 
    {
        beacon_data_t *old,*new;
                
        old = pAdapter->sessionCtx.ap.beacon;
<<<<<<< HEAD

>>>>>>> d97af3b... add prima wlan driver
=======
        
>>>>>>> 657b0e9... prima update
        if (!old)
            return -ENOENT;

        status = wlan_hdd_cfg80211_alloc_new_beacon(pAdapter,&new,params);

        if(status != VOS_STATUS_SUCCESS) {
<<<<<<< HEAD
<<<<<<< HEAD
            hddLog(VOS_TRACE_LEVEL_FATAL, 
=======
            hddLog(VOS_TRACE_LEVEL_FATAL,
>>>>>>> d97af3b... add prima wlan driver
=======
            hddLog(VOS_TRACE_LEVEL_FATAL, 
>>>>>>> 657b0e9... prima update
                   "%s: Error!!! Allocating the new beacon\n",__func__);
            return -EINVAL;
       }

       pAdapter->sessionCtx.ap.beacon = new;

       status = wlan_hdd_cfg80211_start_bss(pAdapter, params);
    }

    EXIT();
    return status;
}

#endif //(LINUX_VERSION_CODE < KERNEL_VERSION(3,4,0))

#if (LINUX_VERSION_CODE < KERNEL_VERSION(3,4,0))
static int wlan_hdd_cfg80211_del_beacon(struct wiphy *wiphy,
                                        struct net_device *dev)
#else
static int wlan_hdd_cfg80211_stop_ap (struct wiphy *wiphy,
                                      struct net_device *dev)
#endif
{
    hdd_adapter_t *pAdapter =  WLAN_HDD_GET_PRIV_PTR(dev);
    hdd_context_t  *pHddCtx    = NULL;
    hdd_scaninfo_t *pScanInfo  = NULL;
    hdd_adapter_t  *staAdapter = NULL;
<<<<<<< HEAD
<<<<<<< HEAD
    VOS_STATUS status = 0;

    staAdapter = hdd_get_adapter(pAdapter->pHddCtx, WLAN_HDD_INFRA_STATION);

    if (!staAdapter)
    {
        staAdapter = hdd_get_adapter(pAdapter->pHddCtx, WLAN_HDD_P2P_CLIENT);
    }
    if ((WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress)
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                "%s:LOGP in Progress. Ignore!!!", __func__);
        return -EAGAIN;
    }

    if (staAdapter != NULL)
    {
        pScanInfo =  &staAdapter->scan_info;
    }
=======
    VOS_STATUS status;
>>>>>>> d97af3b... add prima wlan driver
=======
    VOS_STATUS status = 0;
>>>>>>> 657b0e9... prima update

    staAdapter = hdd_get_adapter(pAdapter->pHddCtx, WLAN_HDD_INFRA_STATION);

    if (!staAdapter)
    {
<<<<<<< HEAD
        VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL,
<<<<<<< HEAD
                   "%s: HDD adapter context is Null", __FUNCTION__);
        return -ENODEV;
    }
    if ((WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress)
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL, "%s:LOGP in Progress. Ignore!!!",__func__);
        return -EAGAIN;
    }

    pHddCtx  =  (hdd_context_t*)pAdapter->pHddCtx;
=======
                   "%s: HDD adapter context is Null", __func__);
        return -ENODEV;
=======
        staAdapter = hdd_get_adapter(pAdapter->pHddCtx, WLAN_HDD_P2P_CLIENT);
    }
    if ((WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress)
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                "%s:LOGP in Progress. Ignore!!!", __func__);
        return -EAGAIN;
>>>>>>> 657b0e9... prima update
    }

    if (staAdapter != NULL)
    {
        pScanInfo =  &staAdapter->scan_info;
    }

    ENTER();

    if (NULL == pAdapter)
    {
        VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL,
                   "%s: HDD adapter context is Null", __FUNCTION__);
        return -ENODEV;
    }
    if ((WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress)
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL, "%s:LOGP in Progress. Ignore!!!",__func__);
        return -EAGAIN;
    }

<<<<<<< HEAD
    pScanInfo =  &pHddCtx->scan_info;
>>>>>>> d97af3b... add prima wlan driver
=======
    pHddCtx  =  (hdd_context_t*)pAdapter->pHddCtx;
>>>>>>> 657b0e9... prima update

    hddLog(VOS_TRACE_LEVEL_INFO, "%s: device_mode = %d\n",
                              __func__,pAdapter->device_mode);

    if ((pScanInfo != NULL) && pScanInfo->mScanPending)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        INIT_COMPLETION(staAdapter->abortscan_event_var);
        hdd_abort_mac_scan(staAdapter->pHddCtx);
        status = wait_for_completion_interruptible_timeout(
                           &staAdapter->abortscan_event_var,
=======
        INIT_COMPLETION(pScanInfo->abortscan_event_var);
        hdd_abort_mac_scan(staAdapter->pHddCtx, pAdapter->sessionId);
        status = wait_for_completion_interruptible_timeout(
                           &pScanInfo->abortscan_event_var,
>>>>>>> d97af3b... add prima wlan driver
=======
        INIT_COMPLETION(staAdapter->abortscan_event_var);
        hdd_abort_mac_scan(staAdapter->pHddCtx);
        status = wait_for_completion_interruptible_timeout(
                           &staAdapter->abortscan_event_var,
>>>>>>> 657b0e9... prima update
                           msecs_to_jiffies(WLAN_WAIT_TIME_ABORTSCAN));
        if (!status)
        {
            VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL,
<<<<<<< HEAD
<<<<<<< HEAD
                         "%s: Timeout occured while waiting for abortscan" ,
                         __FUNCTION__);
=======
                         "%s: Timeout occurred while waiting for abortscan" ,
                         __func__);
>>>>>>> d97af3b... add prima wlan driver
=======
                         "%s: Timeout occured while waiting for abortscan" ,
                         __FUNCTION__);
>>>>>>> 657b0e9... prima update
            VOS_ASSERT(pScanInfo->mScanPending);
            return 0;
        }
    }

    if ((pAdapter->device_mode == WLAN_HDD_SOFTAP)
<<<<<<< HEAD
<<<<<<< HEAD
#ifdef WLAN_FEATURE_P2P
     || (pAdapter->device_mode == WLAN_HDD_P2P_GO)
#endif
=======
     || (pAdapter->device_mode == WLAN_HDD_P2P_GO)
>>>>>>> d97af3b... add prima wlan driver
=======
#ifdef WLAN_FEATURE_P2P
     || (pAdapter->device_mode == WLAN_HDD_P2P_GO)
#endif
>>>>>>> 657b0e9... prima update
       )
    {
        beacon_data_t *old;

        old = pAdapter->sessionCtx.ap.beacon;

        if (!old)
            return -ENOENT;

<<<<<<< HEAD
<<<<<<< HEAD
#ifdef CONFIG_CFG80211
        hdd_cleanup_actionframe(pHddCtx, pAdapter);
#endif
=======
        hdd_cleanup_actionframe(pHddCtx, pAdapter);
>>>>>>> d97af3b... add prima wlan driver
=======
#ifdef CONFIG_CFG80211
        hdd_cleanup_actionframe(pHddCtx, pAdapter);
#endif
>>>>>>> 657b0e9... prima update

        mutex_lock(&pHddCtx->sap_lock);
        if(test_bit(SOFTAP_BSS_STARTED, &pAdapter->event_flags))
        {
<<<<<<< HEAD
<<<<<<< HEAD
            if ( VOS_STATUS_SUCCESS == (status = WLANSAP_StopBss((WLAN_HDD_GET_CTX(pAdapter))->pvosContext) ) )
=======
            if ( VOS_STATUS_SUCCESS == (status = WLANSAP_StopBss(pHddCtx->pvosContext) ) )
>>>>>>> d97af3b... add prima wlan driver
=======
            if ( VOS_STATUS_SUCCESS == (status = WLANSAP_StopBss((WLAN_HDD_GET_CTX(pAdapter))->pvosContext) ) )
>>>>>>> 657b0e9... prima update
            {
                hdd_hostapd_state_t *pHostapdState = WLAN_HDD_GET_HOSTAP_STATE_PTR(pAdapter);

                status = vos_wait_single_event(&pHostapdState->vosEvent, 10000);

                if (!VOS_IS_STATUS_SUCCESS(status))
                {
                    VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                             ("ERROR: HDD vos wait for single_event failed!!\n"));
                    VOS_ASSERT(0);
                }
            }
            clear_bit(SOFTAP_BSS_STARTED, &pAdapter->event_flags);
        }
        mutex_unlock(&pHddCtx->sap_lock);

        if(status != VOS_STATUS_SUCCESS)
        {
            hddLog(VOS_TRACE_LEVEL_FATAL,
                    "%s:Error!!! Stopping the BSS\n",__func__);
            return -EINVAL;
        }

<<<<<<< HEAD
<<<<<<< HEAD
        if (ccmCfgSetInt((WLAN_HDD_GET_CTX(pAdapter))->hHal,
=======
        if (ccmCfgSetInt(pHddCtx->hHal,
>>>>>>> d97af3b... add prima wlan driver
=======
        if (ccmCfgSetInt((WLAN_HDD_GET_CTX(pAdapter))->hHal,
>>>>>>> 657b0e9... prima update
            WNI_CFG_PROBE_RSP_BCN_ADDNIE_FLAG, 0,NULL, eANI_BOOLEAN_FALSE)
                                                    ==eHAL_STATUS_FAILURE)
        {
            hddLog(LOGE,
               "Could not pass on WNI_CFG_PROBE_RSP_BCN_ADDNIE_FLAG to CCM\n");
        }

<<<<<<< HEAD
<<<<<<< HEAD
        if ( eHAL_STATUS_FAILURE == ccmCfgSetInt((WLAN_HDD_GET_CTX(pAdapter))->hHal,
=======
        if ( eHAL_STATUS_FAILURE == ccmCfgSetInt(pHddCtx->hHal,
>>>>>>> d97af3b... add prima wlan driver
=======
        if ( eHAL_STATUS_FAILURE == ccmCfgSetInt((WLAN_HDD_GET_CTX(pAdapter))->hHal,
>>>>>>> 657b0e9... prima update
                            WNI_CFG_ASSOC_RSP_ADDNIE_FLAG, 0, NULL,
                            eANI_BOOLEAN_FALSE) )
        {
            hddLog(LOGE,
               "Could not pass on WNI_CFG_ASSOC_RSP_ADDNIE_FLAG to CCM\n");
        }

        // Reset WNI_CFG_PROBE_RSP Flags
        wlan_hdd_reset_prob_rspies(pAdapter);

        pAdapter->sessionCtx.ap.beacon = NULL;
        kfree(old);
<<<<<<< HEAD
<<<<<<< HEAD
=======
#ifdef WLAN_FEATURE_P2P_DEBUG
        if((pAdapter->device_mode == WLAN_HDD_P2P_GO) &&
           (globalP2PConnectionStatus == P2P_GO_COMPLETED_STATE))
        {
            hddLog(LOGE,"[P2P State] From GO completed to Inactive state "
                        "GO got removed");
            globalP2PConnectionStatus = P2P_NOT_ACTIVE;
        }
#endif
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
    }
    EXIT();
    return status;
}

#if (LINUX_VERSION_CODE > KERNEL_VERSION(3,3,0))

<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
static int wlan_hdd_cfg80211_start_ap(struct wiphy *wiphy, 
                                      struct net_device *dev, 
                                      struct cfg80211_ap_settings *params)
{
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
    int            status = VOS_STATUS_SUCCESS; 
<<<<<<< HEAD

    ENTER();

    hddLog(VOS_TRACE_LEVEL_INFO_HIGH, "device mode=%d\n", pAdapter->device_mode);

    if ((WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress)
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL, "%s:LOGP in Progress. Ignore!!!",__func__);
        return -EAGAIN;
    }
    if ((pAdapter->device_mode == WLAN_HDD_SOFTAP) 
#ifdef WLAN_FEATURE_P2P
      || (pAdapter->device_mode == WLAN_HDD_P2P_GO)
#endif
       )
    {
        beacon_data_t  *old,*new;

        old = pAdapter->sessionCtx.ap.beacon;
   
=======
static int wlan_hdd_cfg80211_start_ap(struct wiphy *wiphy,
                                      struct net_device *dev,
                                      struct cfg80211_ap_settings *params)
{
    hdd_adapter_t *pAdapter;
    hdd_context_t *pHddCtx;
    int            status;
=======
>>>>>>> 657b0e9... prima update

    ENTER();

    hddLog(VOS_TRACE_LEVEL_INFO_HIGH, "device mode=%d\n", pAdapter->device_mode);

    if ((WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress)
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL, "%s:LOGP in Progress. Ignore!!!",__func__);
        return -EAGAIN;
    }
    if ((pAdapter->device_mode == WLAN_HDD_SOFTAP) 
#ifdef WLAN_FEATURE_P2P
      || (pAdapter->device_mode == WLAN_HDD_P2P_GO)
#endif
       )
    {
        beacon_data_t  *old,*new;

        old = pAdapter->sessionCtx.ap.beacon;
<<<<<<< HEAD

>>>>>>> d97af3b... add prima wlan driver
=======
   
>>>>>>> 657b0e9... prima update
        if (old)
            return -EALREADY;

        status = wlan_hdd_cfg80211_alloc_new_beacon(pAdapter, &new, &params->beacon, params->dtim_period);

<<<<<<< HEAD
<<<<<<< HEAD
        if(status != VOS_STATUS_SUCCESS) 
        {
             hddLog(VOS_TRACE_LEVEL_FATAL,
                   "%s:Error!!! Allocating the new beacon\n",__func__);
             return -EINVAL;
        }
        pAdapter->sessionCtx.ap.beacon = new;
=======
        if (status != 0)
=======
        if(status != VOS_STATUS_SUCCESS) 
>>>>>>> 657b0e9... prima update
        {
             hddLog(VOS_TRACE_LEVEL_FATAL,
                   "%s:Error!!! Allocating the new beacon\n",__func__);
             return -EINVAL;
        }
        pAdapter->sessionCtx.ap.beacon = new;
<<<<<<< HEAD
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(3,6,0))
        wlan_hdd_cfg80211_set_channel(wiphy, dev,
#if (LINUX_VERSION_CODE < KERNEL_VERSION(3,8,0))
        params->channel, params->channel_type);
#else
        params->chandef.chan, cfg80211_get_chandef_type(&(params->chandef)));
#endif
#endif
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
        status = wlan_hdd_cfg80211_start_bss(pAdapter, &params->beacon, params->ssid,
                                             params->ssid_len, params->hidden_ssid);
    }

    EXIT();
    return status;
}


<<<<<<< HEAD
<<<<<<< HEAD
static int wlan_hdd_cfg80211_change_beacon(struct wiphy *wiphy, 
                                        struct net_device *dev,
                                        struct cfg80211_beacon_data *params)
{
    hdd_adapter_t *pAdapter =  WLAN_HDD_GET_PRIV_PTR(dev); 
    int status=VOS_STATUS_SUCCESS;
=======
static int wlan_hdd_cfg80211_change_beacon(struct wiphy *wiphy,
                                        struct net_device *dev,
                                        struct cfg80211_beacon_data *params)
{
    hdd_adapter_t *pAdapter =  WLAN_HDD_GET_PRIV_PTR(dev);
    hdd_context_t *pHddCtx;
    int status;
>>>>>>> d97af3b... add prima wlan driver
=======
static int wlan_hdd_cfg80211_change_beacon(struct wiphy *wiphy, 
                                        struct net_device *dev,
                                        struct cfg80211_beacon_data *params)
{
    hdd_adapter_t *pAdapter =  WLAN_HDD_GET_PRIV_PTR(dev); 
    int status=VOS_STATUS_SUCCESS;
>>>>>>> 657b0e9... prima update

    ENTER();

    hddLog(VOS_TRACE_LEVEL_INFO, "%s: device_mode = %d\n",
                                __func__, pAdapter->device_mode);
<<<<<<< HEAD
<<<<<<< HEAD
    if ((WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress)
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL, "%s:LOGP in Progress. Ignore!!!",__func__);
        return -EAGAIN;
    }

    if ((pAdapter->device_mode == WLAN_HDD_SOFTAP) 
#ifdef WLAN_FEATURE_P2P
     || (pAdapter->device_mode == WLAN_HDD_P2P_GO)
#endif
       ) 
    {
        beacon_data_t *old,*new;
                
        old = pAdapter->sessionCtx.ap.beacon;
        
=======

    pHddCtx = WLAN_HDD_GET_CTX(pAdapter);
    status = wlan_hdd_validate_context(pHddCtx);

    if (0 != status)
=======
    if ((WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress)
>>>>>>> 657b0e9... prima update
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL, "%s:LOGP in Progress. Ignore!!!",__func__);
        return -EAGAIN;
    }

    if ((pAdapter->device_mode == WLAN_HDD_SOFTAP) 
#ifdef WLAN_FEATURE_P2P
     || (pAdapter->device_mode == WLAN_HDD_P2P_GO)
#endif
       ) 
    {
        beacon_data_t *old,*new;
                
        old = pAdapter->sessionCtx.ap.beacon;
<<<<<<< HEAD

>>>>>>> d97af3b... add prima wlan driver
=======
        
>>>>>>> 657b0e9... prima update
        if (!old)
            return -ENOENT;

        status = wlan_hdd_cfg80211_alloc_new_beacon(pAdapter, &new, params, 0);

        if(status != VOS_STATUS_SUCCESS) {
<<<<<<< HEAD
<<<<<<< HEAD
            hddLog(VOS_TRACE_LEVEL_FATAL, 
=======
            hddLog(VOS_TRACE_LEVEL_FATAL,
>>>>>>> d97af3b... add prima wlan driver
=======
            hddLog(VOS_TRACE_LEVEL_FATAL, 
>>>>>>> 657b0e9... prima update
                   "%s: Error!!! Allocating the new beacon\n",__func__);
            return -EINVAL;
       }

       pAdapter->sessionCtx.ap.beacon = new;

       status = wlan_hdd_cfg80211_start_bss(pAdapter, params, NULL, 0, 0);
    }

    EXIT();
    return status;
}

#endif //(LINUX_VERSION_CODE > KERNEL_VERSION(3,3,0))


static int wlan_hdd_cfg80211_change_bss (struct wiphy *wiphy,
                                      struct net_device *dev,
                                      struct bss_parameters *params)
{
    hdd_adapter_t *pAdapter =  WLAN_HDD_GET_PRIV_PTR(dev);

    ENTER();
<<<<<<< HEAD
<<<<<<< HEAD
    
=======

>>>>>>> d97af3b... add prima wlan driver
=======
    
>>>>>>> 657b0e9... prima update
    hddLog(VOS_TRACE_LEVEL_INFO, "%s: device_mode = %d\n",
                               __func__,pAdapter->device_mode);

    if((pAdapter->device_mode == WLAN_HDD_SOFTAP)
<<<<<<< HEAD
<<<<<<< HEAD
#ifdef WLAN_FEATURE_P2P
     ||  (pAdapter->device_mode == WLAN_HDD_P2P_GO)
#endif
      ) 
    {
        /* ap_isolate == -1 means that in change bss, upper layer doesn't
         * want to update this parameter */
        if (-1 != params->ap_isolate) 
        {
            pAdapter->sessionCtx.ap.apDisableIntraBssFwd = !!params->ap_isolate;
        } 
=======
=======
#ifdef WLAN_FEATURE_P2P
>>>>>>> 657b0e9... prima update
     ||  (pAdapter->device_mode == WLAN_HDD_P2P_GO)
#endif
      ) 
    {
        /* ap_isolate == -1 means that in change bss, upper layer doesn't
         * want to update this parameter */
        if (-1 != params->ap_isolate) 
        {
            pAdapter->sessionCtx.ap.apDisableIntraBssFwd = !!params->ap_isolate;
<<<<<<< HEAD
        }
>>>>>>> d97af3b... add prima wlan driver
=======
        } 
>>>>>>> 657b0e9... prima update
    }

    EXIT();
    return 0;
}

/*
 * FUNCTION: wlan_hdd_cfg80211_change_iface
 * This function is used to set the interface type (INFRASTRUCTURE/ADHOC)
 */
int wlan_hdd_cfg80211_change_iface( struct wiphy *wiphy,
                                    struct net_device *ndev,
                                    enum nl80211_iftype type,
                                    u32 *flags,
                                    struct vif_params *params
                                  )
{
    struct wireless_dev *wdev;
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR( ndev );
    hdd_context_t *pHddCtx = WLAN_HDD_GET_CTX( pAdapter );
<<<<<<< HEAD
<<<<<<< HEAD
    tCsrRoamProfile *pRoamProfile = NULL;
    eCsrRoamBssType LastBSSType;
    hdd_config_t *pConfig = pHddCtx->cfg_ini;
=======
    hdd_adapter_t  *pP2pAdapter = NULL;
    tCsrRoamProfile *pRoamProfile = NULL;
    eCsrRoamBssType LastBSSType;
    hdd_config_t *pConfig = NULL;
>>>>>>> d97af3b... add prima wlan driver
=======
    tCsrRoamProfile *pRoamProfile = NULL;
    eCsrRoamBssType LastBSSType;
    hdd_config_t *pConfig = pHddCtx->cfg_ini;
>>>>>>> 657b0e9... prima update
    eMib_dot11DesiredBssType connectedBssType;
    VOS_STATUS status;

    ENTER();

<<<<<<< HEAD
<<<<<<< HEAD
    if ((WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress)
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL, "%s:LOGP in Progress. Ignore!!!",__func__);
        return -EAGAIN;
=======
    status = wlan_hdd_validate_context(pHddCtx);

    if (0 != status)
    {
        VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                   "%s: HDD context is not valid", __func__);
        return status;
>>>>>>> d97af3b... add prima wlan driver
=======
    if ((WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress)
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL, "%s:LOGP in Progress. Ignore!!!",__func__);
        return -EAGAIN;
>>>>>>> 657b0e9... prima update
    }

    hddLog(VOS_TRACE_LEVEL_INFO, "%s: device_mode = %d",
                             __func__, pAdapter->device_mode);

<<<<<<< HEAD
<<<<<<< HEAD
=======
    pConfig = pHddCtx->cfg_ini;
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
    wdev = ndev->ieee80211_ptr;

#ifdef WLAN_BTAMP_FEATURE
    if((NL80211_IFTYPE_P2P_CLIENT == type)||
       (NL80211_IFTYPE_ADHOC == type)||
       (NL80211_IFTYPE_AP == type)||
       (NL80211_IFTYPE_P2P_GO == type))
    {
        pHddCtx->isAmpAllowed = VOS_FALSE;
        // stop AMP traffic
        status = WLANBAP_StopAmp();
        if(VOS_STATUS_SUCCESS != status )
        {
            pHddCtx->isAmpAllowed = VOS_TRUE;
            hddLog(VOS_TRACE_LEVEL_FATAL,
                   "%s: Failed to stop AMP", __func__);
            return -EINVAL;
        }
    }
#endif //WLAN_BTAMP_FEATURE
    /* Reset the current device mode bit mask*/
    wlan_hdd_clear_concurrency_mode(pHddCtx, pAdapter->device_mode);

    if( (pAdapter->device_mode == WLAN_HDD_INFRA_STATION)
<<<<<<< HEAD
<<<<<<< HEAD
#ifdef WLAN_FEATURE_P2P
      || (pAdapter->device_mode == WLAN_HDD_P2P_CLIENT)
      || (pAdapter->device_mode == WLAN_HDD_P2P_DEVICE)
#endif
=======
      || (pAdapter->device_mode == WLAN_HDD_P2P_CLIENT)
      || (pAdapter->device_mode == WLAN_HDD_P2P_DEVICE)
>>>>>>> d97af3b... add prima wlan driver
=======
#ifdef WLAN_FEATURE_P2P
      || (pAdapter->device_mode == WLAN_HDD_P2P_CLIENT)
      || (pAdapter->device_mode == WLAN_HDD_P2P_DEVICE)
#endif
>>>>>>> 657b0e9... prima update
      )
    {
        hdd_wext_state_t *pWextState = WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter);
        pRoamProfile = &pWextState->roamProfile;
        LastBSSType = pRoamProfile->BSSType;

        switch (type)
        {
            case NL80211_IFTYPE_STATION:
<<<<<<< HEAD
<<<<<<< HEAD
#ifdef WLAN_FEATURE_P2P
            case NL80211_IFTYPE_P2P_CLIENT:
#endif
=======
            case NL80211_IFTYPE_P2P_CLIENT:
>>>>>>> d97af3b... add prima wlan driver
=======
#ifdef WLAN_FEATURE_P2P
            case NL80211_IFTYPE_P2P_CLIENT:
#endif
>>>>>>> 657b0e9... prima update
                hddLog(VOS_TRACE_LEVEL_INFO,
                   "%s: setting interface Type to INFRASTRUCTURE", __func__);
                pRoamProfile->BSSType = eCSR_BSS_TYPE_INFRASTRUCTURE;
#ifdef WLAN_FEATURE_11AC
                if(pConfig->dot11Mode == eHDD_DOT11_MODE_AUTO)
                {
                    pConfig->dot11Mode = eHDD_DOT11_MODE_11ac;
                }
#endif
<<<<<<< HEAD
<<<<<<< HEAD
                pRoamProfile->phyMode = 
                hdd_cfg_xlate_to_csr_phy_mode(pConfig->dot11Mode);
                wdev->iftype = type;
#ifdef WLAN_FEATURE_P2P
                pAdapter->device_mode = (type == NL80211_IFTYPE_STATION) ?
                                WLAN_HDD_INFRA_STATION: WLAN_HDD_P2P_CLIENT;
#endif
=======
                pRoamProfile->phyMode =
=======
                pRoamProfile->phyMode = 
>>>>>>> 657b0e9... prima update
                hdd_cfg_xlate_to_csr_phy_mode(pConfig->dot11Mode);
                wdev->iftype = type;
#ifdef WLAN_FEATURE_P2P
                pAdapter->device_mode = (type == NL80211_IFTYPE_STATION) ?
                                WLAN_HDD_INFRA_STATION: WLAN_HDD_P2P_CLIENT;
#endif
<<<<<<< HEAD

>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
                break;
            case NL80211_IFTYPE_ADHOC:
                hddLog(VOS_TRACE_LEVEL_INFO,
                  "%s: setting interface Type to ADHOC", __func__);
                pRoamProfile->BSSType = eCSR_BSS_TYPE_START_IBSS;
                pRoamProfile->phyMode =
                    hdd_cfg_xlate_to_csr_phy_mode(pConfig->dot11Mode);
<<<<<<< HEAD
<<<<<<< HEAD
=======
                pAdapter->device_mode = WLAN_HDD_IBSS;
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
                wdev->iftype = type;
                break;

            case NL80211_IFTYPE_AP:
<<<<<<< HEAD
<<<<<<< HEAD
#ifdef WLAN_FEATURE_P2P
            case NL80211_IFTYPE_P2P_GO:
#endif
=======
            case NL80211_IFTYPE_P2P_GO:
>>>>>>> d97af3b... add prima wlan driver
=======
#ifdef WLAN_FEATURE_P2P
            case NL80211_IFTYPE_P2P_GO:
#endif
>>>>>>> 657b0e9... prima update
            {
                hddLog(VOS_TRACE_LEVEL_INFO_HIGH,
                      "%s: setting interface Type to %s", __func__,
                      (type == NL80211_IFTYPE_AP) ? "SoftAP" : "P2pGo");

<<<<<<< HEAD
<<<<<<< HEAD
=======
                //Cancel any remain on channel for GO mode
                if (NL80211_IFTYPE_P2P_GO == type)
                {
                    wlan_hdd_cancel_existing_remain_on_channel(pAdapter);
                }
                if (NL80211_IFTYPE_AP == type)
                {
                     /* As Loading WLAN Driver one interface being created for p2p device
                      * address. This will take one HW STA and the max number of clients
                      * that can connect to softAP will be reduced by one. so while changing
                      * the interface type to NL80211_IFTYPE_AP (SoftAP) remove p2p0
                      * interface as it is not required in SoftAP mode.
                      */

                    // Get P2P Adapter
                    pP2pAdapter = hdd_get_adapter(pHddCtx, WLAN_HDD_P2P_DEVICE);

                    if (pP2pAdapter)
                    {
                        hdd_stop_adapter(pHddCtx, pP2pAdapter);
                        hdd_deinit_adapter(pHddCtx, pP2pAdapter);
                        hdd_close_adapter(pHddCtx, pP2pAdapter, VOS_TRUE);
                    }
                }

>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
                //De-init the adapter.
                hdd_stop_adapter( pHddCtx, pAdapter );
                hdd_deinit_adapter( pHddCtx, pAdapter );
                memset(&pAdapter->sessionCtx, 0, sizeof(pAdapter->sessionCtx));
<<<<<<< HEAD
<<<<<<< HEAD
#ifdef WLAN_SOFTAP_FEATURE
#ifdef WLAN_FEATURE_P2P
                pAdapter->device_mode = (type == NL80211_IFTYPE_AP) ?
                                   WLAN_HDD_SOFTAP : WLAN_HDD_P2P_GO;
#else
                pAdapter->device_mode = WLAN_HDD_SOFTAP;
#endif
=======
                pAdapter->device_mode = (type == NL80211_IFTYPE_AP) ?
                                   WLAN_HDD_SOFTAP : WLAN_HDD_P2P_GO;
>>>>>>> d97af3b... add prima wlan driver
=======
#ifdef WLAN_SOFTAP_FEATURE
#ifdef WLAN_FEATURE_P2P
                pAdapter->device_mode = (type == NL80211_IFTYPE_AP) ?
                                   WLAN_HDD_SOFTAP : WLAN_HDD_P2P_GO;
#else
                pAdapter->device_mode = WLAN_HDD_SOFTAP;
#endif
>>>>>>> 657b0e9... prima update

                //Disable BMPS and IMPS if enabled
                //before starting Go
                if(WLAN_HDD_P2P_GO == pAdapter->device_mode)
                {
<<<<<<< HEAD
<<<<<<< HEAD
                    if(VOS_STATUS_E_FAILURE == 
=======
                    if(VOS_STATUS_E_FAILURE ==
>>>>>>> d97af3b... add prima wlan driver
=======
                    if(VOS_STATUS_E_FAILURE == 
>>>>>>> 657b0e9... prima update
                       hdd_disable_bmps_imps(pHddCtx, WLAN_HDD_P2P_GO))
                    {
                       //Fail to Exit BMPS
                       VOS_ASSERT(0);
                    }
                }

                if ((WLAN_HDD_SOFTAP == pAdapter->device_mode) &&
                    (pConfig->apRandomBssidEnabled))
                {
                    /* To meet Android requirements create a randomized
                       MAC address of the form 02:1A:11:Fx:xx:xx */
                    get_random_bytes(&ndev->dev_addr[3], 3);
                    ndev->dev_addr[0] = 0x02;
                    ndev->dev_addr[1] = 0x1A;
                    ndev->dev_addr[2] = 0x11;
                    ndev->dev_addr[3] |= 0xF0;
                    memcpy(pAdapter->macAddressCurrent.bytes, ndev->dev_addr,
                           VOS_MAC_ADDR_SIZE);
                    pr_info("wlan: Generated HotSpot BSSID "
                            "%02x:%02x:%02x:%02x:%02x:%02x\n",
                            ndev->dev_addr[0],
                            ndev->dev_addr[1],
                            ndev->dev_addr[2],
                            ndev->dev_addr[3],
                            ndev->dev_addr[4],
                            ndev->dev_addr[5]);
                }

                hdd_set_ap_ops( pAdapter->dev );

                status = hdd_init_ap_mode(pAdapter);
                if(status != VOS_STATUS_SUCCESS)
                {
                    hddLog(VOS_TRACE_LEVEL_FATAL,
                           "%s: Error initializing the ap mode", __func__);
                    return -EINVAL;
                }
                hdd_set_conparam(1);

<<<<<<< HEAD
<<<<<<< HEAD
#endif
=======
>>>>>>> d97af3b... add prima wlan driver
=======
#endif
>>>>>>> 657b0e9... prima update
                /*interface type changed update in wiphy structure*/
                if(wdev)
                {
                    wdev->iftype = type;
                    pHddCtx->change_iface = type;
                }
                else
                {
                    hddLog(VOS_TRACE_LEVEL_ERROR,
                            "%s: ERROR !!!! Wireless dev is NULL", __func__);
                    return -EINVAL;
                }
                goto done;
            }

            default:
                hddLog(VOS_TRACE_LEVEL_ERROR, "%s: Unsupported interface Type",
                        __func__);
                return -EOPNOTSUPP;
        }
    }
    else if ( (pAdapter->device_mode == WLAN_HDD_SOFTAP)
<<<<<<< HEAD
<<<<<<< HEAD
#ifdef WLAN_FEATURE_P2P
           || (pAdapter->device_mode == WLAN_HDD_P2P_GO)
#endif
=======
           || (pAdapter->device_mode == WLAN_HDD_P2P_GO)
>>>>>>> d97af3b... add prima wlan driver
=======
#ifdef WLAN_FEATURE_P2P
           || (pAdapter->device_mode == WLAN_HDD_P2P_GO)
#endif
>>>>>>> 657b0e9... prima update
            )
    {
       switch(type)
       {
           case NL80211_IFTYPE_STATION:
<<<<<<< HEAD
<<<<<<< HEAD
#ifdef WLAN_FEATURE_P2P
           case NL80211_IFTYPE_P2P_CLIENT:
#endif
=======
           case NL80211_IFTYPE_P2P_CLIENT:
>>>>>>> d97af3b... add prima wlan driver
=======
#ifdef WLAN_FEATURE_P2P
           case NL80211_IFTYPE_P2P_CLIENT:
#endif
>>>>>>> 657b0e9... prima update
           case NL80211_IFTYPE_ADHOC:
                hdd_stop_adapter( pHddCtx, pAdapter );
                hdd_deinit_adapter( pHddCtx, pAdapter );
                wdev->iftype = type;
<<<<<<< HEAD
<<<<<<< HEAD
#ifdef WLAN_FEATURE_P2P
                pAdapter->device_mode = (type == NL80211_IFTYPE_STATION) ?
                                  WLAN_HDD_INFRA_STATION: WLAN_HDD_P2P_CLIENT;
#endif
=======
                //Check for sub-string p2p to confirm its a p2p interface
                if (NULL != strstr(ndev->name,"p2p"))
                {
                    pAdapter->device_mode = (type == NL80211_IFTYPE_STATION) ?
                                  WLAN_HDD_P2P_DEVICE : WLAN_HDD_P2P_CLIENT;
                }
                else
                {
                    pAdapter->device_mode = (type == NL80211_IFTYPE_STATION) ?
                                  WLAN_HDD_INFRA_STATION: WLAN_HDD_P2P_CLIENT;
                }
>>>>>>> d97af3b... add prima wlan driver
=======
#ifdef WLAN_FEATURE_P2P
                pAdapter->device_mode = (type == NL80211_IFTYPE_STATION) ?
                                  WLAN_HDD_INFRA_STATION: WLAN_HDD_P2P_CLIENT;
#endif
>>>>>>> 657b0e9... prima update
                hdd_set_conparam(0);
                pHddCtx->change_iface = type;
                memset(&pAdapter->sessionCtx, 0, sizeof(pAdapter->sessionCtx));
                hdd_set_station_ops( pAdapter->dev );
                status = hdd_init_station_mode( pAdapter );
                if( VOS_STATUS_SUCCESS != status )
                    return -EOPNOTSUPP;
                /* In case of JB, for P2P-GO, only change interface will be called,
                 * This is the right place to enable back bmps_imps()
                 */
<<<<<<< HEAD
<<<<<<< HEAD
                hdd_enable_bmps_imps(pHddCtx);
                goto done;
            case NL80211_IFTYPE_AP:
#ifdef WLAN_FEATURE_P2P
            case NL80211_IFTYPE_P2P_GO:
#endif
                wdev->iftype = type;
#ifdef WLAN_FEATURE_P2P
                pAdapter->device_mode = (type == NL80211_IFTYPE_AP) ?
                                        WLAN_HDD_SOFTAP : WLAN_HDD_P2P_GO;
#endif
=======
                if (pHddCtx->hdd_wlan_suspended)
                {
                    hdd_set_pwrparams(pHddCtx);
                }
=======
>>>>>>> 657b0e9... prima update
                hdd_enable_bmps_imps(pHddCtx);
                goto done;
            case NL80211_IFTYPE_AP:
#ifdef WLAN_FEATURE_P2P
            case NL80211_IFTYPE_P2P_GO:
#endif
                wdev->iftype = type;
#ifdef WLAN_FEATURE_P2P
                pAdapter->device_mode = (type == NL80211_IFTYPE_AP) ?
                                        WLAN_HDD_SOFTAP : WLAN_HDD_P2P_GO;
<<<<<<< HEAD
>>>>>>> d97af3b... add prima wlan driver
=======
#endif
>>>>>>> 657b0e9... prima update
               goto done;
           default:
                hddLog(VOS_TRACE_LEVEL_ERROR, "%s: Unsupported interface Type",
                        __func__);
                return -EOPNOTSUPP;

       }

    }
    else
    {
      return -EOPNOTSUPP;
    }


    if(pRoamProfile)
    {
        if ( LastBSSType != pRoamProfile->BSSType )
        {
            /*interface type changed update in wiphy structure*/
            wdev->iftype = type;

            /*the BSS mode changed, We need to issue disconnect
              if connected or in IBSS disconnect state*/
            if ( hdd_connGetConnectedBssType(
                 WLAN_HDD_GET_STATION_CTX_PTR(pAdapter), &connectedBssType ) ||
                ( eCSR_BSS_TYPE_START_IBSS == LastBSSType ) )
            {
                /*need to issue a disconnect to CSR.*/
                INIT_COMPLETION(pAdapter->disconnect_comp_var);
                if( eHAL_STATUS_SUCCESS ==
                        sme_RoamDisconnect( WLAN_HDD_GET_HAL_CTX(pAdapter),
                                pAdapter->sessionId,
                                eCSR_DISCONNECT_REASON_UNSPECIFIED ) )
                {
                    wait_for_completion_interruptible_timeout(
                              &pAdapter->disconnect_comp_var,
                              msecs_to_jiffies(WLAN_WAIT_TIME_DISCONNECT));
                }
            }
        }
    }

done:
    /*set bitmask based on updated value*/
    wlan_hdd_set_concurrency_mode(pHddCtx, pAdapter->device_mode);
<<<<<<< HEAD
<<<<<<< HEAD
#ifdef WLAN_BTAMP_FEATURE
    if((NL80211_IFTYPE_STATION == type) && (pHddCtx->concurrency_mode <= 1) && 
=======

   /* Only STA mode support TM now
    * all other mode, TM feature should be disabled */
    if ( (pHddCtx->cfg_ini->thermalMitigationEnable) &&
         (~VOS_STA & pHddCtx->concurrency_mode) )
    {
        hddDevTmLevelChangedHandler(pHddCtx->parent_dev, 0);
    }

#ifdef WLAN_BTAMP_FEATURE
    if((NL80211_IFTYPE_STATION == type) && (pHddCtx->concurrency_mode <= 1) &&
>>>>>>> d97af3b... add prima wlan driver
=======
#ifdef WLAN_BTAMP_FEATURE
    if((NL80211_IFTYPE_STATION == type) && (pHddCtx->concurrency_mode <= 1) && 
>>>>>>> 657b0e9... prima update
       (pHddCtx->no_of_sessions[WLAN_HDD_INFRA_STATION] <=1))
    {
        //we are ok to do AMP
        pHddCtx->isAmpAllowed = VOS_TRUE;
    }
#endif //WLAN_BTAMP_FEATURE
    EXIT();
    return 0;
}

<<<<<<< HEAD
<<<<<<< HEAD
=======
#ifdef FEATURE_WLAN_TDLS
static int wlan_hdd_tdls_add_station(struct wiphy *wiphy,
          struct net_device *dev, u8 *mac, bool update, tCsrStaParams *StaParams)
{
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
    hdd_context_t *pHddCtx = wiphy_priv(wiphy);
    VOS_STATUS status;
    hddTdlsPeer_t *pTdlsPeer;

    ENTER();

    if (NULL == pHddCtx || NULL == pHddCtx->cfg_ini)
    {
        VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                "Invalid arguments");
        return -EINVAL;
    }

    if ((eTDLS_SUPPORT_NOT_ENABLED == pHddCtx->tdls_mode) ||
        (eTDLS_SUPPORT_DISABLED == pHddCtx->tdls_mode))
    {
         VOS_TRACE( VOS_MODULE_ID_HDD, TDLS_LOG_LEVEL,
                    "%s: TDLS mode is disabled OR not enabled in FW."
                    MAC_ADDRESS_STR " Request declined.",
                    __func__, MAC_ADDR_ARRAY(mac));
        return -ENOTSUPP;
    }

    if (pHddCtx->isLogpInProgress)
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                "%s:LOGP in Progress. Ignore!!!", __func__);
        wlan_hdd_tdls_set_link_status(pAdapter, mac, eTDLS_LINK_IDLE);
        return -EBUSY;
    }

    pTdlsPeer = wlan_hdd_tdls_find_peer(pAdapter, mac);

    if ( NULL == pTdlsPeer ) {
        VOS_TRACE( VOS_MODULE_ID_HDD, TDLS_LOG_LEVEL,
               "%s: " MAC_ADDRESS_STR " (update %d) not exist. return invalid",
               __func__, MAC_ADDR_ARRAY(mac), update);
        return -EINVAL;
    }

    /* in add station, we accept existing valid staId if there is */
    if ((0 == update) &&
        ((pTdlsPeer->link_status >= eTDLS_LINK_CONNECTING) ||
         (TDLS_STA_INDEX_VALID(pTdlsPeer->staId))))
    {
        VOS_TRACE( VOS_MODULE_ID_HDD, TDLS_LOG_LEVEL,
                   "%s: " MAC_ADDRESS_STR
                   " link_status %d. staId %d. add station ignored.",
                   __func__, MAC_ADDR_ARRAY(mac), pTdlsPeer->link_status, pTdlsPeer->staId);
        return 0;
    }
    /* in change station, we accept only when staId is valid */
    if ((1 == update) &&
        ((pTdlsPeer->link_status > eTDLS_LINK_CONNECTING) ||
         (!TDLS_STA_INDEX_VALID(pTdlsPeer->staId))))
    {
        VOS_TRACE( VOS_MODULE_ID_HDD, TDLS_LOG_LEVEL,
                   "%s: " MAC_ADDRESS_STR
                   " link status %d. staId %d. change station %s.",
                   __func__, MAC_ADDR_ARRAY(mac), pTdlsPeer->link_status, pTdlsPeer->staId,
                   (TDLS_STA_INDEX_VALID(pTdlsPeer->staId)) ? "ignored" : "declined");
        return (TDLS_STA_INDEX_VALID(pTdlsPeer->staId)) ? 0 : -EPERM;
    }

    /* when others are on-going, we want to change link_status to idle */
    if (NULL != wlan_hdd_tdls_is_progress(pHddCtx, mac, TRUE, TRUE))
    {
        VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                   "%s: " MAC_ADDRESS_STR
                   " TDLS setup is ongoing. Request declined.",
                   __func__, MAC_ADDR_ARRAY(mac));
        goto error;
    }

    /* first to check if we reached to maximum supported TDLS peer.
       TODO: for now, return -EPERM looks working fine,
       but need to check if any other errno fit into this category.*/
    if (HDD_MAX_NUM_TDLS_STA <= wlan_hdd_tdlsConnectedPeers(pAdapter))
    {
        VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                   "%s: " MAC_ADDRESS_STR
                   " TDLS Max peer already connected. Request declined.",
                    __func__, MAC_ADDR_ARRAY(mac));
        goto error;
    }
    else
    {
        hddTdlsPeer_t *pTdlsPeer;
        pTdlsPeer = wlan_hdd_tdls_find_peer(pAdapter, mac);
        if (pTdlsPeer && TDLS_IS_CONNECTED(pTdlsPeer))
        {
            VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                       "%s: " MAC_ADDRESS_STR " already connected. Request declined.",
                       __func__, MAC_ADDR_ARRAY(mac));
            return -EPERM;
        }
    }
    if (0 == update)
        wlan_hdd_tdls_set_link_status(pAdapter, mac, eTDLS_LINK_CONNECTING);

    /* debug code */
    if (NULL != StaParams)
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, TDLS_LOG_LEVEL,
                  "%s: TDLS Peer Parameters.", __func__);
        if(StaParams->htcap_present)
        {
            VOS_TRACE(VOS_MODULE_ID_HDD, TDLS_LOG_LEVEL,
                      "ht_capa->cap_info: %0x", StaParams->HTCap.capInfo);
            VOS_TRACE(VOS_MODULE_ID_HDD, TDLS_LOG_LEVEL,
                      "ht_capa->extended_capabilities: %0x",
                      StaParams->HTCap.extendedHtCapInfo);
        }
        VOS_TRACE(VOS_MODULE_ID_HDD, TDLS_LOG_LEVEL,
                  "params->capability: %0x",StaParams->capability);
        VOS_TRACE(VOS_MODULE_ID_HDD, TDLS_LOG_LEVEL,
                  "params->ext_capab_len: %0x",StaParams->extn_capability);
        if(StaParams->vhtcap_present)
        {
            VOS_TRACE(VOS_MODULE_ID_HDD, TDLS_LOG_LEVEL,
                      "rxMcsMap %x rxHighest %x txMcsMap %x txHighest %x",
                      StaParams->VHTCap.suppMcs.rxMcsMap, StaParams->VHTCap.suppMcs.rxHighest,
                      StaParams->VHTCap.suppMcs.txMcsMap, StaParams->VHTCap.suppMcs.txHighest);
        }
        {
            int i = 0;
            VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO, "Supported rates:");
            for (i = 0; i < sizeof(StaParams->supported_rates); i++)
               VOS_TRACE(VOS_MODULE_ID_HDD, TDLS_LOG_LEVEL,
                          "[%d]: %x ", i, StaParams->supported_rates[i]);
        }
    }  /* end debug code */
    else if ((1 == update) && (NULL == StaParams))
    {
        VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                   "%s : update is true, but staParams is NULL. Error!", __func__);
        return -EPERM;
    }

    INIT_COMPLETION(pAdapter->tdls_add_station_comp);

    if (!update)
    {
        status = sme_AddTdlsPeerSta(WLAN_HDD_GET_HAL_CTX(pAdapter),
                pAdapter->sessionId, mac);
    }
    else
    {
        status = sme_ChangeTdlsPeerSta(WLAN_HDD_GET_HAL_CTX(pAdapter),
                                       pAdapter->sessionId, mac, StaParams);
    }

    status = wait_for_completion_interruptible_timeout(&pAdapter->tdls_add_station_comp,
           msecs_to_jiffies(WAIT_TIME_TDLS_ADD_STA));

    if (!status)
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                "%s: timeout waiting for tdls add station indication",
                __func__);
        return -EPERM;
    }
    if ( eHAL_STATUS_SUCCESS != pAdapter->tdlsAddStaStatus)
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                "%s: Add Station is unsucessful", __func__);
        return -EPERM;
    }

    return 0;

error:
    wlan_hdd_tdls_set_link_status(pAdapter, mac, eTDLS_LINK_IDLE);
    return -EPERM;

}
#endif

>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
static int wlan_hdd_change_station(struct wiphy *wiphy,
                                         struct net_device *dev,
                                         u8 *mac,
                                         struct station_parameters *params)
{
    VOS_STATUS status = VOS_STATUS_SUCCESS;
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR( dev );
<<<<<<< HEAD
<<<<<<< HEAD
    v_MACADDR_t STAMacAddress;

    ENTER();

    if ( (WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress )
=======
    hdd_context_t *pHddCtx;
    hdd_station_ctx_t *pHddStaCtx;
=======
>>>>>>> 657b0e9... prima update
    v_MACADDR_t STAMacAddress;

    ENTER();

<<<<<<< HEAD
    if (pHddCtx->isLogpInProgress)
>>>>>>> d97af3b... add prima wlan driver
=======
    if ( (WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress )
>>>>>>> 657b0e9... prima update
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                "%s:LOGP in Progress. Ignore!!!", __func__);
        return -EAGAIN;
    }

    vos_mem_copy(STAMacAddress.bytes, mac, sizeof(v_MACADDR_t));

<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
    if ( ( pAdapter->device_mode == WLAN_HDD_SOFTAP )
#ifdef WLAN_FEATURE_P2P
      || ( pAdapter->device_mode == WLAN_HDD_P2P_GO )
#endif
       )
<<<<<<< HEAD
    {
        if(params->sta_flags_set & BIT(NL80211_STA_FLAG_AUTHORIZED)) 
        {
            status = hdd_softap_change_STA_state( pAdapter, &STAMacAddress, 
                                                  WLANTL_STA_AUTHENTICATED);

            VOS_TRACE( VOS_MODULE_ID_HDD_SOFTAP, VOS_TRACE_LEVEL_ERROR,
                "%s: Station MAC address does not matching", __FUNCTION__);
            return -EINVAL;
        }
    }
    
    EXIT();
    return status;
}

/*
 * FUNCTION: wlan_hdd_cfg80211_get_ibss_peer_staidx
 * This function is used to get peer station index in IBSS mode
 */
static u8 wlan_hdd_cfg80211_get_ibss_peer_staidx(hdd_adapter_t* pAdapter)
{
    u8 idx = 0;
    u8 temp[VOS_MAC_ADDR_SIZE] = {0}; 
    ENTER();
    memset(temp, 0, VOS_MAC_ADDR_SIZE);
    for ( idx = 0; idx < HDD_MAX_NUM_IBSS_STA; idx++ )
    {
        if ( (0 != 
            (WLAN_HDD_GET_STATION_CTX_PTR(pAdapter))->conn_info.staId[idx]) 
          && memcmp((u8*)&(WLAN_HDD_GET_STATION_CTX_PTR(pAdapter))->conn_info.peerMacAddress[idx],
                                                     temp, VOS_MAC_ADDR_SIZE) 
           )
        {
            return idx;
        }
    }
    return idx;
}


=======
    if ((pAdapter->device_mode == WLAN_HDD_SOFTAP)
      || (pAdapter->device_mode == WLAN_HDD_P2P_GO))
=======
>>>>>>> 657b0e9... prima update
    {
        if(params->sta_flags_set & BIT(NL80211_STA_FLAG_AUTHORIZED)) 
        {
            status = hdd_softap_change_STA_state( pAdapter, &STAMacAddress, 
                                                  WLANTL_STA_AUTHENTICATED);

            VOS_TRACE( VOS_MODULE_ID_HDD_SOFTAP, VOS_TRACE_LEVEL_ERROR,
                "%s: Station MAC address does not matching", __FUNCTION__);
            return -EINVAL;
        }
    }
    
    EXIT();
    return status;
}

/*
 * FUNCTION: wlan_hdd_cfg80211_get_ibss_peer_staidx
 * This function is used to get peer station index in IBSS mode
 */
static u8 wlan_hdd_cfg80211_get_ibss_peer_staidx(hdd_adapter_t* pAdapter)
{
    u8 idx = 0;
    u8 temp[VOS_MAC_ADDR_SIZE] = {0}; 
    ENTER();
    memset(temp, 0, VOS_MAC_ADDR_SIZE);
    for ( idx = 0; idx < HDD_MAX_NUM_IBSS_STA; idx++ )
    {
        if ( (0 != 
            (WLAN_HDD_GET_STATION_CTX_PTR(pAdapter))->conn_info.staId[idx]) 
          && memcmp((u8*)&(WLAN_HDD_GET_STATION_CTX_PTR(pAdapter))->conn_info.peerMacAddress[idx],
                                                     temp, VOS_MAC_ADDR_SIZE) 
           )
        {
            return idx;
        }
    }
    return idx;
}

<<<<<<< HEAD
>>>>>>> d97af3b... add prima wlan driver
=======

>>>>>>> 657b0e9... prima update
/*
 * FUNCTION: wlan_hdd_cfg80211_add_key
 * This function is used to initialize the key information
 */
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,38))
<<<<<<< HEAD
<<<<<<< HEAD
static int wlan_hdd_cfg80211_add_key( struct wiphy *wiphy, 
=======
static int wlan_hdd_cfg80211_add_key( struct wiphy *wiphy,
>>>>>>> d97af3b... add prima wlan driver
=======
static int wlan_hdd_cfg80211_add_key( struct wiphy *wiphy, 
>>>>>>> 657b0e9... prima update
                                      struct net_device *ndev,
                                      u8 key_index, bool pairwise,
                                      const u8 *mac_addr,
                                      struct key_params *params
                                      )
#else
<<<<<<< HEAD
<<<<<<< HEAD
static int wlan_hdd_cfg80211_add_key( struct wiphy *wiphy, 
=======
static int wlan_hdd_cfg80211_add_key( struct wiphy *wiphy,
>>>>>>> d97af3b... add prima wlan driver
=======
static int wlan_hdd_cfg80211_add_key( struct wiphy *wiphy, 
>>>>>>> 657b0e9... prima update
                                      struct net_device *ndev,
                                      u8 key_index, const u8 *mac_addr,
                                      struct key_params *params
                                      )
#endif
{
<<<<<<< HEAD
<<<<<<< HEAD
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR( ndev ); 
    tCsrRoamSetKey  setKey;
    u8 groupmacaddr[WNI_CFG_BSSID_LEN] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
    int status = 0;
    v_U32_t roamId= 0xFF; 
    v_CONTEXT_t pVosContext = (WLAN_HDD_GET_CTX(pAdapter))->pvosContext;  
    hdd_hostapd_state_t *pHostapdState;
    VOS_STATUS vos_status;

    ENTER();

    if ( (WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress )
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                "%s:LOGP in Progress. Ignore!!!", __func__);
        return -EAGAIN;
    }

    hddLog(VOS_TRACE_LEVEL_INFO, "%s: device_mode = %d\n",
            __func__,pAdapter->device_mode);

    if (CSR_MAX_NUM_KEY <= key_index)
    {
        hddLog(VOS_TRACE_LEVEL_ERROR, "%s: Invalid key index %d", __func__, 
=======
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR( ndev );
=======
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR( ndev ); 
>>>>>>> 657b0e9... prima update
    tCsrRoamSetKey  setKey;
    u8 groupmacaddr[WNI_CFG_BSSID_LEN] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
    int status = 0;
    v_U32_t roamId= 0xFF; 
    v_CONTEXT_t pVosContext = (WLAN_HDD_GET_CTX(pAdapter))->pvosContext;  
    hdd_hostapd_state_t *pHostapdState;
    VOS_STATUS vos_status;

    ENTER();

    if ( (WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress )
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                "%s:LOGP in Progress. Ignore!!!", __func__);
        return -EAGAIN;
    }

    hddLog(VOS_TRACE_LEVEL_INFO, "%s: device_mode = %d\n",
            __func__,pAdapter->device_mode);

    if (CSR_MAX_NUM_KEY <= key_index)
    {
<<<<<<< HEAD
        hddLog(VOS_TRACE_LEVEL_ERROR, "%s: Invalid key index %d", __func__,
>>>>>>> d97af3b... add prima wlan driver
=======
        hddLog(VOS_TRACE_LEVEL_ERROR, "%s: Invalid key index %d", __func__, 
>>>>>>> 657b0e9... prima update
                key_index);

        return -EINVAL;
    }

<<<<<<< HEAD
<<<<<<< HEAD
    hddLog(VOS_TRACE_LEVEL_INFO, 
            "%s: called with key index = %d & key length %d",
            __func__, key_index, params->key_len);
=======
    if (CSR_MAX_KEY_LEN < params->key_len)
    {
        hddLog(VOS_TRACE_LEVEL_ERROR, "%s: Invalid key length %d", __func__,
                params->key_len);

        return -EINVAL;
    }

    hddLog(VOS_TRACE_LEVEL_INFO,
           "%s: called with key index = %d & key length %d",
           __func__, key_index, params->key_len);
>>>>>>> d97af3b... add prima wlan driver
=======
    hddLog(VOS_TRACE_LEVEL_INFO, 
            "%s: called with key index = %d & key length %d",
            __func__, key_index, params->key_len);
>>>>>>> 657b0e9... prima update

    /*extract key idx, key len and key*/
    vos_mem_zero(&setKey,sizeof(tCsrRoamSetKey));
    setKey.keyId = key_index;
    setKey.keyLength = params->key_len;
    vos_mem_copy(&setKey.Key[0],params->key, params->key_len);

<<<<<<< HEAD
<<<<<<< HEAD
    switch (params->cipher) 
=======
    switch (params->cipher)
>>>>>>> d97af3b... add prima wlan driver
=======
    switch (params->cipher) 
>>>>>>> 657b0e9... prima update
    {
        case WLAN_CIPHER_SUITE_WEP40:
            setKey.encType = eCSR_ENCRYPT_TYPE_WEP40_STATICKEY;
            break;

        case WLAN_CIPHER_SUITE_WEP104:
            setKey.encType = eCSR_ENCRYPT_TYPE_WEP104_STATICKEY;
            break;

        case WLAN_CIPHER_SUITE_TKIP:
            {
                u8 *pKey = &setKey.Key[0];
                setKey.encType = eCSR_ENCRYPT_TYPE_TKIP;

                vos_mem_zero(pKey, CSR_MAX_KEY_LEN);

<<<<<<< HEAD
<<<<<<< HEAD
                /*Supplicant sends the 32bytes key in this order 

                  |--------------|----------|----------|
                  |   Tk1        |TX-MIC    |  RX Mic  | 
=======
                /*Supplicant sends the 32bytes key in this order

                  |--------------|----------|----------|
                  |   Tk1        |TX-MIC    |  RX Mic  |
>>>>>>> d97af3b... add prima wlan driver
=======
                /*Supplicant sends the 32bytes key in this order 

                  |--------------|----------|----------|
                  |   Tk1        |TX-MIC    |  RX Mic  | 
>>>>>>> 657b0e9... prima update
                  |--------------|----------|----------|
                  <---16bytes---><--8bytes--><--8bytes-->

                */
                /*Sme expects the 32 bytes key to be in the below order

                  |--------------|----------|----------|
<<<<<<< HEAD
<<<<<<< HEAD
                  |   Tk1        |RX-MIC    |  TX Mic  | 
=======
                  |   Tk1        |RX-MIC    |  TX Mic  |
>>>>>>> d97af3b... add prima wlan driver
=======
                  |   Tk1        |RX-MIC    |  TX Mic  | 
>>>>>>> 657b0e9... prima update
                  |--------------|----------|----------|
                  <---16bytes---><--8bytes--><--8bytes-->
                  */
                /* Copy the Temporal Key 1 (TK1) */
<<<<<<< HEAD
<<<<<<< HEAD
                vos_mem_copy(pKey, params->key,16);

                /*Copy the rx mic first*/
                vos_mem_copy(&pKey[16],&params->key[24],8); 

                /*Copy the tx mic */
                vos_mem_copy(&pKey[24],&params->key[16],8); 
=======
                vos_mem_copy(pKey, params->key, 16);
=======
                vos_mem_copy(pKey, params->key,16);
>>>>>>> 657b0e9... prima update

                /*Copy the rx mic first*/
                vos_mem_copy(&pKey[16],&params->key[24],8); 

                /*Copy the tx mic */
<<<<<<< HEAD
                vos_mem_copy(&pKey[24], &params->key[16], 8);
>>>>>>> d97af3b... add prima wlan driver
=======
                vos_mem_copy(&pKey[24],&params->key[16],8); 
>>>>>>> 657b0e9... prima update


                break;
            }

        case WLAN_CIPHER_SUITE_CCMP:
            setKey.encType = eCSR_ENCRYPT_TYPE_AES;
            break;

#ifdef FEATURE_WLAN_WAPI
        case WLAN_CIPHER_SUITE_SMS4:
            {
                vos_mem_zero(&setKey,sizeof(tCsrRoamSetKey));
                wlan_hdd_cfg80211_set_key_wapi(pAdapter, key_index, mac_addr,
                        params->key, params->key_len);
                return 0;
            }
#endif
<<<<<<< HEAD
<<<<<<< HEAD
=======

>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
#ifdef FEATURE_WLAN_CCX
        case WLAN_CIPHER_SUITE_KRK:
            setKey.encType = eCSR_ENCRYPT_TYPE_KRK;
            break;
#endif
<<<<<<< HEAD
<<<<<<< HEAD
=======

#ifdef WLAN_FEATURE_11W
        case WLAN_CIPHER_SUITE_AES_CMAC:
            setKey.encType = eCSR_ENCRYPT_TYPE_AES_CMAC;
            break;
#endif

>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
        default:
            hddLog(VOS_TRACE_LEVEL_ERROR, "%s: unsupported cipher type %lu",
                    __func__, params->cipher);
            return -EOPNOTSUPP;
    }

    hddLog(VOS_TRACE_LEVEL_INFO_MED, "%s: encryption type %d",
            __func__, setKey.encType);

<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update


    if ((pAdapter->device_mode == WLAN_HDD_SOFTAP)
#ifdef WLAN_FEATURE_P2P
            || (pAdapter->device_mode == WLAN_HDD_P2P_GO)
<<<<<<< HEAD
#endif
       )
    {


        if ( 
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,38))
                (!pairwise)
#else
                (!mac_addr || is_broadcast_ether_addr(mac_addr)) 
#endif
           )
        {
            /* set group key*/
            VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO,
                    "%s- %d: setting Broacast key",
                    __func__, __LINE__);
            setKey.keyDirection = eSIR_RX_ONLY;
            vos_mem_copy(setKey.peerMac,groupmacaddr,WNI_CFG_BSSID_LEN);
        }
        else
        {
            /* set pairwise key*/
            VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO,
                    "%s- %d: setting pairwise key",
                    __func__, __LINE__);
            setKey.keyDirection = eSIR_TX_RX;
            vos_mem_copy(setKey.peerMac, mac_addr,WNI_CFG_BSSID_LEN);
        }

        pHostapdState = WLAN_HDD_GET_HOSTAP_STATE_PTR(pAdapter);
        if( pHostapdState->bssState == BSS_START ) 
        { 
=======
    if (
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,38))
                (!pairwise)
#else
                (!mac_addr || is_broadcast_ether_addr(mac_addr))
=======
>>>>>>> 657b0e9... prima update
#endif
       )
    {


        if ( 
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,38))
                (!pairwise)
#else
                (!mac_addr || is_broadcast_ether_addr(mac_addr)) 
#endif
           )
        {
            /* set group key*/
            VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO,
                    "%s- %d: setting Broacast key",
                    __func__, __LINE__);
            setKey.keyDirection = eSIR_RX_ONLY;
            vos_mem_copy(setKey.peerMac,groupmacaddr,WNI_CFG_BSSID_LEN);
        }
        else
        {
<<<<<<< HEAD
>>>>>>> d97af3b... add prima wlan driver
=======
            /* set pairwise key*/
            VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO,
                    "%s- %d: setting pairwise key",
                    __func__, __LINE__);
            setKey.keyDirection = eSIR_TX_RX;
            vos_mem_copy(setKey.peerMac, mac_addr,WNI_CFG_BSSID_LEN);
        }

        pHostapdState = WLAN_HDD_GET_HOSTAP_STATE_PTR(pAdapter);
        if( pHostapdState->bssState == BSS_START ) 
        { 
>>>>>>> 657b0e9... prima update
            status = WLANSAP_SetKeySta( pVosContext, &setKey);

            if ( status != eHAL_STATUS_SUCCESS )
            {
                VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                        "[%4d] WLANSAP_SetKeySta returned ERROR status= %d",
                        __LINE__, status );
            }
        }

        /* Saving WEP keys */
        else if( eCSR_ENCRYPT_TYPE_WEP40_STATICKEY  == setKey.encType ||
                eCSR_ENCRYPT_TYPE_WEP104_STATICKEY  == setKey.encType  )
        {
            //Save the wep key in ap context. Issue setkey after the BSS is started.
            hdd_ap_ctx_t *pAPCtx = WLAN_HDD_GET_AP_CTX_PTR(pAdapter);
            vos_mem_copy(&pAPCtx->wepKey[key_index], &setKey, sizeof(tCsrRoamSetKey));
        }
        else
        {
            //Save the key in ap context. Issue setkey after the BSS is started.
<<<<<<< HEAD
<<<<<<< HEAD
            hdd_ap_ctx_t *pAPCtx = WLAN_HDD_GET_AP_CTX_PTR(pAdapter); 
            vos_mem_copy(&pAPCtx->groupKey, &setKey, sizeof(tCsrRoamSetKey));
        }
    }
    else if ( (pAdapter->device_mode == WLAN_HDD_INFRA_STATION) 
#ifdef WLAN_FEATURE_P2P
            || (pAdapter->device_mode == WLAN_HDD_P2P_CLIENT)
#endif
            )
=======
            hdd_ap_ctx_t *pAPCtx = WLAN_HDD_GET_AP_CTX_PTR(pAdapter);
            vos_mem_copy(&pAPCtx->groupKey, &setKey, sizeof(tCsrRoamSetKey));
        }
    }
    else if ( (pAdapter->device_mode == WLAN_HDD_INFRA_STATION) ||
              (pAdapter->device_mode == WLAN_HDD_P2P_CLIENT) )
>>>>>>> d97af3b... add prima wlan driver
=======
            hdd_ap_ctx_t *pAPCtx = WLAN_HDD_GET_AP_CTX_PTR(pAdapter); 
            vos_mem_copy(&pAPCtx->groupKey, &setKey, sizeof(tCsrRoamSetKey));
        }
    }
    else if ( (pAdapter->device_mode == WLAN_HDD_INFRA_STATION) 
#ifdef WLAN_FEATURE_P2P
            || (pAdapter->device_mode == WLAN_HDD_P2P_CLIENT)
#endif
            )
>>>>>>> 657b0e9... prima update
    {
        hdd_wext_state_t *pWextState = WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter);
        hdd_station_ctx_t *pHddStaCtx = WLAN_HDD_GET_STATION_CTX_PTR(pAdapter);

<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
        pWextState->roamProfile.Keys.KeyLength[key_index] = (u8)params->key_len;

        vos_mem_copy(&pWextState->roamProfile.Keys.KeyMaterial[key_index][0], 
                params->key, params->key_len);

        pHddStaCtx->roam_info.roamingState = HDD_ROAM_STATE_SETTING_KEY;

    if (!(  ( IW_AUTH_KEY_MGMT_802_1X 
                    == (pWextState->authKeyMgmt & IW_AUTH_KEY_MGMT_802_1X)) 
                    && (eCSR_AUTH_TYPE_OPEN_SYSTEM == pHddStaCtx->conn_info.authType)
             )
                &&
                (  (WLAN_CIPHER_SUITE_WEP40 == params->cipher)
                   || (WLAN_CIPHER_SUITE_WEP104 == params->cipher)
                )
           )
<<<<<<< HEAD
        {
            /* in case of static WEP, macaddr/bssid is not coming from nl80211
             * interface, copy bssid for pairwise key and group macaddr for 
             * group key initialization*/

            tCsrRoamProfile          *pRoamProfile = &pWextState->roamProfile;

            pWextState->roamProfile.negotiatedUCEncryptionType = 
                pHddStaCtx->conn_info.ucEncryptionType = 
                ((WLAN_CIPHER_SUITE_WEP40 == params->cipher) ?
                 eCSR_ENCRYPT_TYPE_WEP40_STATICKEY :
                 eCSR_ENCRYPT_TYPE_WEP104_STATICKEY);


            hddLog(VOS_TRACE_LEVEL_INFO_MED, 
                    "%s: Negotiated encryption type %d", __func__, 
                    pWextState->roamProfile.negotiatedUCEncryptionType);

            sme_SetCfgPrivacy((tpAniSirGlobal)WLAN_HDD_GET_HAL_CTX(pAdapter),
                    &pWextState->roamProfile, true);
            setKey.keyLength = 0;
            setKey.keyDirection =  eSIR_TX_RX;

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,38))
            if (pairwise) 
            {
#endif
                if (mac_addr)
                {
                    vos_mem_copy(setKey.peerMac, mac_addr,WNI_CFG_BSSID_LEN);
                }
                else
                {
                    /* macaddr is NULL, set the peerMac to bssId in case of BSS, 
                     * and peerMacAddress in case of IBSS*/
                    if (eCSR_BSS_TYPE_START_IBSS == pRoamProfile->BSSType)
                    {
                        u8 staidx = wlan_hdd_cfg80211_get_ibss_peer_staidx(pAdapter);
                        if (HDD_MAX_NUM_IBSS_STA != staidx)
                        {
                            vos_mem_copy(setKey.peerMac,
                                    &pHddStaCtx->conn_info.peerMacAddress[staidx],
                                    WNI_CFG_BSSID_LEN);

                        } 
                        else
                        {
                            hddLog(VOS_TRACE_LEVEL_ERROR, "%s: No peerMac found", 
                                    __func__);
                            return -EOPNOTSUPP;
                        } 
                    }
                    else
                    {
                        vos_mem_copy(setKey.peerMac,
                                &pHddStaCtx->conn_info.bssId[0],
                                WNI_CFG_BSSID_LEN);
                    }
                }
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,38))
            }
            else
            {
                /* set group key*/
                VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO,
                        "%s- %d: setting Group key",
                        __func__, __LINE__);
                setKey.keyDirection = eSIR_RX_ONLY;
                vos_mem_copy(setKey.peerMac, groupmacaddr, WNI_CFG_BSSID_LEN);
            }
#endif
        }
        else if (
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,38))
                (!pairwise)
#else
                (!mac_addr || is_broadcast_ether_addr(mac_addr)) 
#endif
                )
        {
            /* set group key*/
            VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO,
                    "%s- %d: setting Group key",
                    __func__, __LINE__);
            setKey.keyDirection = eSIR_RX_ONLY;
            vos_mem_copy(setKey.peerMac,groupmacaddr,WNI_CFG_BSSID_LEN);
        }
        else
        {
            /* set pairwise key*/
            VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO,
                    "%s- %d: setting pairwise key",
                    __func__, __LINE__);
            setKey.keyDirection = eSIR_TX_RX;
            vos_mem_copy(setKey.peerMac, mac_addr,WNI_CFG_BSSID_LEN);
        }

        hddLog(VOS_TRACE_LEVEL_INFO_MED, 
                "%s: set key for peerMac %2x:%2x:%2x:%2x:%2x:%2x, direction %d",
                __func__, setKey.peerMac[0], setKey.peerMac[1], 
                setKey.peerMac[2], setKey.peerMac[3], 
                setKey.peerMac[4], setKey.peerMac[5], 
=======
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,38))
        if (!pairwise)
#else
        if (!mac_addr || is_broadcast_ether_addr(mac_addr))
#endif
=======
>>>>>>> 657b0e9... prima update
        {
            /* in case of static WEP, macaddr/bssid is not coming from nl80211
             * interface, copy bssid for pairwise key and group macaddr for 
             * group key initialization*/

            tCsrRoamProfile          *pRoamProfile = &pWextState->roamProfile;

            pWextState->roamProfile.negotiatedUCEncryptionType = 
                pHddStaCtx->conn_info.ucEncryptionType = 
                ((WLAN_CIPHER_SUITE_WEP40 == params->cipher) ?
                 eCSR_ENCRYPT_TYPE_WEP40_STATICKEY :
                 eCSR_ENCRYPT_TYPE_WEP104_STATICKEY);


            hddLog(VOS_TRACE_LEVEL_INFO_MED, 
                    "%s: Negotiated encryption type %d", __func__, 
                    pWextState->roamProfile.negotiatedUCEncryptionType);

            sme_SetCfgPrivacy((tpAniSirGlobal)WLAN_HDD_GET_HAL_CTX(pAdapter),
                    &pWextState->roamProfile, true);
            setKey.keyLength = 0;
            setKey.keyDirection =  eSIR_TX_RX;

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,38))
            if (pairwise) 
            {
#endif
                if (mac_addr)
                {
                    vos_mem_copy(setKey.peerMac, mac_addr,WNI_CFG_BSSID_LEN);
                }
                else
                {
                    /* macaddr is NULL, set the peerMac to bssId in case of BSS, 
                     * and peerMacAddress in case of IBSS*/
                    if (eCSR_BSS_TYPE_START_IBSS == pRoamProfile->BSSType)
                    {
                        u8 staidx = wlan_hdd_cfg80211_get_ibss_peer_staidx(pAdapter);
                        if (HDD_MAX_NUM_IBSS_STA != staidx)
                        {
                            vos_mem_copy(setKey.peerMac,
                                    &pHddStaCtx->conn_info.peerMacAddress[staidx],
                                    WNI_CFG_BSSID_LEN);

                        } 
                        else
                        {
                            hddLog(VOS_TRACE_LEVEL_ERROR, "%s: No peerMac found", 
                                    __func__);
                            return -EOPNOTSUPP;
                        } 
                    }
                    else
                    {
                        vos_mem_copy(setKey.peerMac,
                                &pHddStaCtx->conn_info.bssId[0],
                                WNI_CFG_BSSID_LEN);
                    }
                }
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,38))
            }
            else
            {
                /* set group key*/
                VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO,
                        "%s- %d: setting Group key",
                        __func__, __LINE__);
                setKey.keyDirection = eSIR_RX_ONLY;
                vos_mem_copy(setKey.peerMac, groupmacaddr, WNI_CFG_BSSID_LEN);
            }
#endif
        }
        else if (
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,38))
                (!pairwise)
#else
                (!mac_addr || is_broadcast_ether_addr(mac_addr)) 
#endif
                )
        {
            /* set group key*/
            VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO,
                    "%s- %d: setting Group key",
                    __func__, __LINE__);
            setKey.keyDirection = eSIR_RX_ONLY;
            vos_mem_copy(setKey.peerMac,groupmacaddr,WNI_CFG_BSSID_LEN);
        }
        else
        {
            /* set pairwise key*/
            VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO,
                    "%s- %d: setting pairwise key",
                    __func__, __LINE__);
            setKey.keyDirection = eSIR_TX_RX;
            vos_mem_copy(setKey.peerMac, mac_addr,WNI_CFG_BSSID_LEN);
        }

        hddLog(VOS_TRACE_LEVEL_INFO_MED, 
                "%s: set key for peerMac %2x:%2x:%2x:%2x:%2x:%2x, direction %d",
<<<<<<< HEAD
                __func__, setKey.peerMac[0], setKey.peerMac[1],
                setKey.peerMac[2], setKey.peerMac[3],
                setKey.peerMac[4], setKey.peerMac[5],
>>>>>>> d97af3b... add prima wlan driver
=======
                __func__, setKey.peerMac[0], setKey.peerMac[1], 
                setKey.peerMac[2], setKey.peerMac[3], 
                setKey.peerMac[4], setKey.peerMac[5], 
>>>>>>> 657b0e9... prima update
                setKey.keyDirection);

        vos_status = wlan_hdd_check_ula_done(pAdapter);

        if ( vos_status != VOS_STATUS_SUCCESS )
        {
            VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                    "[%4d] wlan_hdd_check_ula_done returned ERROR status= %d",
                    __LINE__, vos_status );

            pHddStaCtx->roam_info.roamingState = HDD_ROAM_STATE_NONE;

            return -EINVAL;

        }

<<<<<<< HEAD
<<<<<<< HEAD
=======
#ifdef WLAN_FEATURE_VOWIFI_11R
        /* The supplicant may attempt to set the PTK once pre-authentication
           is done. Save the key in the UMAC and include it in the ADD BSS
           request */
        halStatus = sme_FTUpdateKey( WLAN_HDD_GET_HAL_CTX(pAdapter), &setKey);
        if ( halStatus == eHAL_STATUS_FT_PREAUTH_KEY_SUCCESS )
        {
           hddLog(VOS_TRACE_LEVEL_INFO_MED,
                  "%s: Update PreAuth Key success", __func__);
           return 0;
        }
        else if ( halStatus == eHAL_STATUS_FT_PREAUTH_KEY_FAILED )
        {
           hddLog(VOS_TRACE_LEVEL_ERROR,
                  "%s: Update PreAuth Key failed", __func__);
           return -EINVAL;
        }
#endif /* WLAN_FEATURE_VOWIFI_11R */
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update

        /* issue set key request to SME*/
        status = sme_RoamSetKey( WLAN_HDD_GET_HAL_CTX(pAdapter),
                pAdapter->sessionId, &setKey, &roamId );

        if ( 0 != status )
        {
<<<<<<< HEAD
<<<<<<< HEAD
            hddLog(VOS_TRACE_LEVEL_ERROR, 
=======
            hddLog(VOS_TRACE_LEVEL_ERROR,
>>>>>>> d97af3b... add prima wlan driver
=======
            hddLog(VOS_TRACE_LEVEL_ERROR, 
>>>>>>> 657b0e9... prima update
                    "%s: sme_RoamSetKey failed, returned %d", __func__, status);
            pHddStaCtx->roam_info.roamingState = HDD_ROAM_STATE_NONE;
            return -EINVAL;
        }


<<<<<<< HEAD
<<<<<<< HEAD
        /* in case of IBSS as there was no information available about WEP keys during 
         * IBSS join, group key intialized with NULL key, so re-initialize group key 
         * with correct value*/
        if ( (eCSR_BSS_TYPE_START_IBSS == pWextState->roamProfile.BSSType) && 
            !(  ( IW_AUTH_KEY_MGMT_802_1X 
                    == (pWextState->authKeyMgmt & IW_AUTH_KEY_MGMT_802_1X)) 
=======
        /* in case of IBSS as there was no information available about WEP keys during
         * IBSS join, group key intialized with NULL key, so re-initialize group key
         * with correct value*/
        if ( (eCSR_BSS_TYPE_START_IBSS == pWextState->roamProfile.BSSType) &&
            !(  ( IW_AUTH_KEY_MGMT_802_1X
                    == (pWextState->authKeyMgmt & IW_AUTH_KEY_MGMT_802_1X))
>>>>>>> d97af3b... add prima wlan driver
=======
        /* in case of IBSS as there was no information available about WEP keys during 
         * IBSS join, group key intialized with NULL key, so re-initialize group key 
         * with correct value*/
        if ( (eCSR_BSS_TYPE_START_IBSS == pWextState->roamProfile.BSSType) && 
            !(  ( IW_AUTH_KEY_MGMT_802_1X 
                    == (pWextState->authKeyMgmt & IW_AUTH_KEY_MGMT_802_1X)) 
>>>>>>> 657b0e9... prima update
                    && (eCSR_AUTH_TYPE_OPEN_SYSTEM == pHddStaCtx->conn_info.authType)
                 )
                &&
                (  (WLAN_CIPHER_SUITE_WEP40 == params->cipher)
                   || (WLAN_CIPHER_SUITE_WEP104 == params->cipher)
                )
           )
        {
            setKey.keyDirection = eSIR_RX_ONLY;
            vos_mem_copy(setKey.peerMac,groupmacaddr,WNI_CFG_BSSID_LEN);

<<<<<<< HEAD
<<<<<<< HEAD
            hddLog(VOS_TRACE_LEVEL_INFO_MED, 
                    "%s: set key peerMac %2x:%2x:%2x:%2x:%2x:%2x, direction %d",
                    __func__, setKey.peerMac[0], setKey.peerMac[1], 
                    setKey.peerMac[2], setKey.peerMac[3], 
                    setKey.peerMac[4], setKey.peerMac[5], 
                    setKey.keyDirection);

            status = sme_RoamSetKey( WLAN_HDD_GET_HAL_CTX(pAdapter), 
=======
            hddLog(VOS_TRACE_LEVEL_INFO_MED,
=======
            hddLog(VOS_TRACE_LEVEL_INFO_MED, 
>>>>>>> 657b0e9... prima update
                    "%s: set key peerMac %2x:%2x:%2x:%2x:%2x:%2x, direction %d",
                    __func__, setKey.peerMac[0], setKey.peerMac[1], 
                    setKey.peerMac[2], setKey.peerMac[3], 
                    setKey.peerMac[4], setKey.peerMac[5], 
                    setKey.keyDirection);

<<<<<<< HEAD
            status = sme_RoamSetKey( WLAN_HDD_GET_HAL_CTX(pAdapter),
>>>>>>> d97af3b... add prima wlan driver
=======
            status = sme_RoamSetKey( WLAN_HDD_GET_HAL_CTX(pAdapter), 
>>>>>>> 657b0e9... prima update
                    pAdapter->sessionId, &setKey, &roamId );

            if ( 0 != status )
            {
<<<<<<< HEAD
<<<<<<< HEAD
                hddLog(VOS_TRACE_LEVEL_ERROR, 
                        "%s: sme_RoamSetKey failed for group key (IBSS), returned %d", 
=======
                hddLog(VOS_TRACE_LEVEL_ERROR,
                        "%s: sme_RoamSetKey failed for group key (IBSS), returned %d",
>>>>>>> d97af3b... add prima wlan driver
=======
                hddLog(VOS_TRACE_LEVEL_ERROR, 
                        "%s: sme_RoamSetKey failed for group key (IBSS), returned %d", 
>>>>>>> 657b0e9... prima update
                        __func__, status);
                pHddStaCtx->roam_info.roamingState = HDD_ROAM_STATE_NONE;
                return -EINVAL;
            }
        }
    }

    return 0;
}

/*
 * FUNCTION: wlan_hdd_cfg80211_get_key
 * This function is used to get the key information
 */
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,38))
<<<<<<< HEAD
<<<<<<< HEAD
static int wlan_hdd_cfg80211_get_key( 
                        struct wiphy *wiphy, 
                        struct net_device *ndev,
                        u8 key_index, bool pairwise, 
=======
static int wlan_hdd_cfg80211_get_key(
                        struct wiphy *wiphy,
                        struct net_device *ndev,
                        u8 key_index, bool pairwise,
>>>>>>> d97af3b... add prima wlan driver
=======
static int wlan_hdd_cfg80211_get_key( 
                        struct wiphy *wiphy, 
                        struct net_device *ndev,
                        u8 key_index, bool pairwise, 
>>>>>>> 657b0e9... prima update
                        const u8 *mac_addr, void *cookie,
                        void (*callback)(void *cookie, struct key_params*)
                        )
#else
<<<<<<< HEAD
<<<<<<< HEAD
static int wlan_hdd_cfg80211_get_key( 
                        struct wiphy *wiphy, 
=======
static int wlan_hdd_cfg80211_get_key(
                        struct wiphy *wiphy,
>>>>>>> d97af3b... add prima wlan driver
=======
static int wlan_hdd_cfg80211_get_key( 
                        struct wiphy *wiphy, 
>>>>>>> 657b0e9... prima update
                        struct net_device *ndev,
                        u8 key_index, const u8 *mac_addr, void *cookie,
                        void (*callback)(void *cookie, struct key_params*)
                        )
#endif
{
<<<<<<< HEAD
<<<<<<< HEAD
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR( ndev ); 
=======
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR( ndev );
>>>>>>> d97af3b... add prima wlan driver
=======
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR( ndev ); 
>>>>>>> 657b0e9... prima update
    hdd_wext_state_t *pWextState= WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter);
    tCsrRoamProfile *pRoamProfile = &(pWextState->roamProfile);
    struct key_params params;

    ENTER();
<<<<<<< HEAD
<<<<<<< HEAD
    
    hddLog(VOS_TRACE_LEVEL_INFO, "%s: device_mode = %d\n",
                                 __func__,pAdapter->device_mode);
    
=======

    hddLog(VOS_TRACE_LEVEL_INFO, "%s: device_mode = %d\n",
                                 __func__,pAdapter->device_mode);

>>>>>>> d97af3b... add prima wlan driver
=======
    
    hddLog(VOS_TRACE_LEVEL_INFO, "%s: device_mode = %d\n",
                                 __func__,pAdapter->device_mode);
    
>>>>>>> 657b0e9... prima update
    memset(&params, 0, sizeof(params));

    if (CSR_MAX_NUM_KEY <= key_index)
    {
        return -EINVAL;
<<<<<<< HEAD
<<<<<<< HEAD
    }   
=======
    }
>>>>>>> d97af3b... add prima wlan driver
=======
    }   
>>>>>>> 657b0e9... prima update

    switch(pRoamProfile->EncryptionType.encryptionType[0])
    {
        case eCSR_ENCRYPT_TYPE_NONE:
            params.cipher = IW_AUTH_CIPHER_NONE;
            break;

        case eCSR_ENCRYPT_TYPE_WEP40_STATICKEY:
        case eCSR_ENCRYPT_TYPE_WEP40:
            params.cipher = WLAN_CIPHER_SUITE_WEP40;
            break;

        case eCSR_ENCRYPT_TYPE_WEP104_STATICKEY:
        case eCSR_ENCRYPT_TYPE_WEP104:
            params.cipher = WLAN_CIPHER_SUITE_WEP104;
            break;

        case eCSR_ENCRYPT_TYPE_TKIP:
            params.cipher = WLAN_CIPHER_SUITE_TKIP;
            break;

        case eCSR_ENCRYPT_TYPE_AES:
            params.cipher = WLAN_CIPHER_SUITE_AES_CMAC;
            break;

        default:
            params.cipher = IW_AUTH_CIPHER_NONE;
            break;
    }

    params.key_len = pRoamProfile->Keys.KeyLength[key_index];
    params.seq_len = 0;
    params.seq = NULL;
    params.key = &pRoamProfile->Keys.KeyMaterial[key_index][0];
    callback(cookie, &params);
    return 0;
}

/*
 * FUNCTION: wlan_hdd_cfg80211_del_key
 * This function is used to delete the key information
 */
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,38))
<<<<<<< HEAD
<<<<<<< HEAD
static int wlan_hdd_cfg80211_del_key( struct wiphy *wiphy, 
                                      struct net_device *ndev,
                                      u8 key_index, 
                                      bool pairwise, 
                                      const u8 *mac_addr
                                    )
#else
static int wlan_hdd_cfg80211_del_key( struct wiphy *wiphy, 
=======
static int wlan_hdd_cfg80211_del_key( struct wiphy *wiphy,
=======
static int wlan_hdd_cfg80211_del_key( struct wiphy *wiphy, 
>>>>>>> 657b0e9... prima update
                                      struct net_device *ndev,
                                      u8 key_index, 
                                      bool pairwise, 
                                      const u8 *mac_addr
                                    )
#else
<<<<<<< HEAD
static int wlan_hdd_cfg80211_del_key( struct wiphy *wiphy,
>>>>>>> d97af3b... add prima wlan driver
=======
static int wlan_hdd_cfg80211_del_key( struct wiphy *wiphy, 
>>>>>>> 657b0e9... prima update
                                      struct net_device *ndev,
                                      u8 key_index,
                                      const u8 *mac_addr
                                    )
#endif
{
    int status = 0;

    //This code needs to be revisited. There is sme_removeKey API, we should
<<<<<<< HEAD
<<<<<<< HEAD
    //plan to use that. After the change to use correct index in setkey, 
=======
    //plan to use that. After the change to use correct index in setkey,
>>>>>>> d97af3b... add prima wlan driver
=======
    //plan to use that. After the change to use correct index in setkey, 
>>>>>>> 657b0e9... prima update
    //it is observed that this is invalidating peer
    //key index whenever re-key is done. This is affecting data link.
    //It should be ok to ignore del_key.
#if 0
<<<<<<< HEAD
<<<<<<< HEAD
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR( ndev ); 
    v_CONTEXT_t pVosContext = (WLAN_HDD_GET_CTX(pAdapter))->pvosContext;  
    u8 groupmacaddr[WNI_CFG_BSSID_LEN] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
    tCsrRoamSetKey  setKey;
    v_U32_t roamId= 0xFF;
    
=======
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR( ndev );
    v_CONTEXT_t pVosContext = (WLAN_HDD_GET_CTX(pAdapter))->pvosContext;
    u8 groupmacaddr[WNI_CFG_BSSID_LEN] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
    tCsrRoamSetKey  setKey;
    v_U32_t roamId= 0xFF;

>>>>>>> d97af3b... add prima wlan driver
=======
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR( ndev ); 
    v_CONTEXT_t pVosContext = (WLAN_HDD_GET_CTX(pAdapter))->pvosContext;  
    u8 groupmacaddr[WNI_CFG_BSSID_LEN] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
    tCsrRoamSetKey  setKey;
    v_U32_t roamId= 0xFF;
    
>>>>>>> 657b0e9... prima update
    ENTER();

    hddLog(VOS_TRACE_LEVEL_INFO_HIGH, "%s: device_mode = %d\n",
                                     __func__,pAdapter->device_mode);

    if (CSR_MAX_NUM_KEY <= key_index)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        hddLog(VOS_TRACE_LEVEL_ERROR, "%s: Invalid key index %d", __func__, 
=======
        hddLog(VOS_TRACE_LEVEL_ERROR, "%s: Invalid key index %d", __func__,
>>>>>>> d97af3b... add prima wlan driver
=======
        hddLog(VOS_TRACE_LEVEL_ERROR, "%s: Invalid key index %d", __func__, 
>>>>>>> 657b0e9... prima update
                key_index);

        return -EINVAL;
    }

    vos_mem_zero(&setKey,sizeof(tCsrRoamSetKey));
    setKey.keyId = key_index;

    if (mac_addr)
        vos_mem_copy(setKey.peerMac, mac_addr,WNI_CFG_BSSID_LEN);
    else
        vos_mem_copy(setKey.peerMac, groupmacaddr, WNI_CFG_BSSID_LEN);

    setKey.encType = eCSR_ENCRYPT_TYPE_NONE;

    if ((pAdapter->device_mode == WLAN_HDD_SOFTAP)
<<<<<<< HEAD
<<<<<<< HEAD
#ifdef WLAN_FEATURE_P2P
      || (pAdapter->device_mode == WLAN_HDD_P2P_GO)
#endif
       ) 
    { 
       
        hdd_hostapd_state_t *pHostapdState =  
=======
      || (pAdapter->device_mode == WLAN_HDD_P2P_GO)
       )
    {

        hdd_hostapd_state_t *pHostapdState =
>>>>>>> d97af3b... add prima wlan driver
=======
#ifdef WLAN_FEATURE_P2P
      || (pAdapter->device_mode == WLAN_HDD_P2P_GO)
#endif
       ) 
    { 
       
        hdd_hostapd_state_t *pHostapdState =  
>>>>>>> 657b0e9... prima update
                                  WLAN_HDD_GET_HOSTAP_STATE_PTR(pAdapter);
        if( pHostapdState->bssState == BSS_START)
        {
            status = WLANSAP_SetKeySta( pVosContext, &setKey);
<<<<<<< HEAD
<<<<<<< HEAD
    
=======

>>>>>>> d97af3b... add prima wlan driver
=======
    
>>>>>>> 657b0e9... prima update
            if ( status != eHAL_STATUS_SUCCESS )
            {
                VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                     "[%4d] WLANSAP_SetKeySta returned ERROR status= %d",
                     __LINE__, status );
            }
        }
    }
    else if ( (pAdapter->device_mode == WLAN_HDD_INFRA_STATION)
<<<<<<< HEAD
<<<<<<< HEAD
#ifdef WLAN_FEATURE_P2P
           || (pAdapter->device_mode == WLAN_HDD_P2P_CLIENT) 
#endif
=======
           || (pAdapter->device_mode == WLAN_HDD_P2P_CLIENT)
>>>>>>> d97af3b... add prima wlan driver
=======
#ifdef WLAN_FEATURE_P2P
           || (pAdapter->device_mode == WLAN_HDD_P2P_CLIENT) 
#endif
>>>>>>> 657b0e9... prima update
            )
    {
        hdd_station_ctx_t *pHddStaCtx = WLAN_HDD_GET_STATION_CTX_PTR(pAdapter);

<<<<<<< HEAD
<<<<<<< HEAD
        pHddStaCtx->roam_info.roamingState = HDD_ROAM_STATE_SETTING_KEY;   
    
        hddLog(VOS_TRACE_LEVEL_INFO_MED, 
                "%s: delete key for peerMac %2x:%2x:%2x:%2x:%2x:%2x",
                __func__, setKey.peerMac[0], setKey.peerMac[1], 
                setKey.peerMac[2], setKey.peerMac[3], 
                setKey.peerMac[4], setKey.peerMac[5]);
        if(pAdapter->sessionCtx.station.conn_info.connState == 
                                       eConnectionState_Associated) 
        {
            status = sme_RoamSetKey( WLAN_HDD_GET_HAL_CTX(pAdapter), 
                                   pAdapter->sessionId, &setKey, &roamId );
        
            if ( 0 != status )
            {
                hddLog(VOS_TRACE_LEVEL_ERROR, 
=======
        pHddStaCtx->roam_info.roamingState = HDD_ROAM_STATE_SETTING_KEY;

        hddLog(VOS_TRACE_LEVEL_INFO_MED,
=======
        pHddStaCtx->roam_info.roamingState = HDD_ROAM_STATE_SETTING_KEY;   
    
        hddLog(VOS_TRACE_LEVEL_INFO_MED, 
>>>>>>> 657b0e9... prima update
                "%s: delete key for peerMac %2x:%2x:%2x:%2x:%2x:%2x",
                __func__, setKey.peerMac[0], setKey.peerMac[1], 
                setKey.peerMac[2], setKey.peerMac[3], 
                setKey.peerMac[4], setKey.peerMac[5]);
        if(pAdapter->sessionCtx.station.conn_info.connState == 
                                       eConnectionState_Associated) 
        {
            status = sme_RoamSetKey( WLAN_HDD_GET_HAL_CTX(pAdapter), 
                                   pAdapter->sessionId, &setKey, &roamId );
        
            if ( 0 != status )
            {
<<<<<<< HEAD
                hddLog(VOS_TRACE_LEVEL_ERROR,
>>>>>>> d97af3b... add prima wlan driver
=======
                hddLog(VOS_TRACE_LEVEL_ERROR, 
>>>>>>> 657b0e9... prima update
                        "%s: sme_RoamSetKey failure, returned %d",
                                                     __func__, status);
                pHddStaCtx->roam_info.roamingState = HDD_ROAM_STATE_NONE;
                return -EINVAL;
            }
        }
    }
#endif
    EXIT();
    return status;
}

/*
 * FUNCTION: wlan_hdd_cfg80211_set_default_key
 * This function is used to set the default tx key index
 */
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,38))
static int wlan_hdd_cfg80211_set_default_key( struct wiphy *wiphy,
                                              struct net_device *ndev,
                                              u8 key_index,
                                              bool unicast, bool multicast)
#else
static int wlan_hdd_cfg80211_set_default_key( struct wiphy *wiphy,
                                              struct net_device *ndev,
                                              u8 key_index)
#endif
{
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR( ndev ); 
    hdd_wext_state_t *pWextState = WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter);
    int status = 0;
    hdd_station_ctx_t *pHddStaCtx = WLAN_HDD_GET_STATION_CTX_PTR(pAdapter);

    ENTER();

<<<<<<< HEAD
    hddLog(VOS_TRACE_LEVEL_INFO, "%s: device_mode = %d key_index = %d \n",
                                         __func__,pAdapter->device_mode, key_index);
   
    if (CSR_MAX_NUM_KEY <= key_index)
    {
        hddLog(VOS_TRACE_LEVEL_ERROR, "%s: Invalid key index %d", __func__, 
=======
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR( ndev );
    int status;
    hdd_wext_state_t *pWextState;
    hdd_station_ctx_t *pHddStaCtx;
    hdd_context_t *pHddCtx;

    ENTER();

    if ((NULL == pAdapter))
    {
       VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL,
          "invalid adapter");
       return -EINVAL;
    }

    pWextState = WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter);
    pHddStaCtx = WLAN_HDD_GET_STATION_CTX_PTR(pAdapter);

    if ((NULL == pWextState) || (NULL == pHddStaCtx))
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL,
                  "invalid Wext state or HDD context");
        return -EINVAL;
    }

=======
>>>>>>> 657b0e9... prima update
    hddLog(VOS_TRACE_LEVEL_INFO, "%s: device_mode = %d key_index = %d \n",
                                         __func__,pAdapter->device_mode, key_index);
   
    if (CSR_MAX_NUM_KEY <= key_index)
    {
<<<<<<< HEAD
        hddLog(VOS_TRACE_LEVEL_ERROR, "%s: Invalid key index %d", __func__,
>>>>>>> d97af3b... add prima wlan driver
=======
        hddLog(VOS_TRACE_LEVEL_ERROR, "%s: Invalid key index %d", __func__, 
>>>>>>> 657b0e9... prima update
                key_index);

        return -EINVAL;
    }

<<<<<<< HEAD
<<<<<<< HEAD
    if ( (WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress )
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                "%s:LOGP in Progress. Ignore!!!", __func__);
        return -EAGAIN;
    }
    
    if ((pAdapter->device_mode == WLAN_HDD_INFRA_STATION)
#ifdef WLAN_FEATURE_P2P
     || (pAdapter->device_mode == WLAN_HDD_P2P_CLIENT)
#endif
       ) 
    {
        if ( (key_index != pWextState->roamProfile.Keys.defaultIndex) && 
             (eCSR_ENCRYPT_TYPE_TKIP != 
                pWextState->roamProfile.EncryptionType.encryptionType[0]) &&
             (eCSR_ENCRYPT_TYPE_AES != 
                pWextState->roamProfile.EncryptionType.encryptionType[0])
           )
        {  
            /* if default key index is not same as previous one, 
             * then update the default key index */
    
            tCsrRoamSetKey  setKey;
            v_U32_t roamId= 0xFF;
            tCsrKeys *Keys = &pWextState->roamProfile.Keys;
            
            hddLog(VOS_TRACE_LEVEL_INFO_HIGH, "%s: default tx key index %d", 
                    __func__, key_index);
            
=======
    pHddCtx = WLAN_HDD_GET_CTX(pAdapter);
    status = wlan_hdd_validate_context(pHddCtx);

    if (0 != status)
=======
    if ( (WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress )
>>>>>>> 657b0e9... prima update
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                "%s:LOGP in Progress. Ignore!!!", __func__);
        return -EAGAIN;
    }
    
    if ((pAdapter->device_mode == WLAN_HDD_INFRA_STATION)
#ifdef WLAN_FEATURE_P2P
     || (pAdapter->device_mode == WLAN_HDD_P2P_CLIENT)
#endif
       ) 
    {
        if ( (key_index != pWextState->roamProfile.Keys.defaultIndex) && 
             (eCSR_ENCRYPT_TYPE_TKIP != 
                pWextState->roamProfile.EncryptionType.encryptionType[0]) &&
             (eCSR_ENCRYPT_TYPE_AES != 
                pWextState->roamProfile.EncryptionType.encryptionType[0])
           )
        {  
            /* if default key index is not same as previous one, 
             * then update the default key index */
    
            tCsrRoamSetKey  setKey;
            v_U32_t roamId= 0xFF;
            tCsrKeys *Keys = &pWextState->roamProfile.Keys;
            
            hddLog(VOS_TRACE_LEVEL_INFO_HIGH, "%s: default tx key index %d", 
                    __func__, key_index);
<<<<<<< HEAD

>>>>>>> d97af3b... add prima wlan driver
=======
            
>>>>>>> 657b0e9... prima update
            Keys->defaultIndex = (u8)key_index;
            vos_mem_zero(&setKey,sizeof(tCsrRoamSetKey));
            setKey.keyId = key_index;
            setKey.keyLength = Keys->KeyLength[key_index];
<<<<<<< HEAD
<<<<<<< HEAD
            
            vos_mem_copy(&setKey.Key[0], 
                    &Keys->KeyMaterial[key_index][0], 
                    Keys->KeyLength[key_index]);
    
            setKey.keyDirection = eSIR_TX_ONLY;
    
            vos_mem_copy(setKey.peerMac, 
                    &pHddStaCtx->conn_info.bssId[0],
                    WNI_CFG_BSSID_LEN);
    
            setKey.encType = 
                pWextState->roamProfile.EncryptionType.encryptionType[0];
             
            /* issue set key request */
            status = sme_RoamSetKey( WLAN_HDD_GET_HAL_CTX(pAdapter), 
                                   pAdapter->sessionId, &setKey, &roamId );
    
            if ( 0 != status )
            {
                hddLog(VOS_TRACE_LEVEL_ERROR, 
                        "%s: sme_RoamSetKey failed, returned %d", __func__, 
=======

            vos_mem_copy(&setKey.Key[0],
                    &Keys->KeyMaterial[key_index][0],
=======
            
            vos_mem_copy(&setKey.Key[0], 
                    &Keys->KeyMaterial[key_index][0], 
>>>>>>> 657b0e9... prima update
                    Keys->KeyLength[key_index]);
    
            setKey.keyDirection = eSIR_TX_ONLY;
    
            vos_mem_copy(setKey.peerMac, 
                    &pHddStaCtx->conn_info.bssId[0],
                    WNI_CFG_BSSID_LEN);
    
            setKey.encType = 
                pWextState->roamProfile.EncryptionType.encryptionType[0];
             
            /* issue set key request */
            status = sme_RoamSetKey( WLAN_HDD_GET_HAL_CTX(pAdapter), 
                                   pAdapter->sessionId, &setKey, &roamId );
    
            if ( 0 != status )
            {
<<<<<<< HEAD
                hddLog(VOS_TRACE_LEVEL_ERROR,
                        "%s: sme_RoamSetKey failed, returned %d", __func__,
>>>>>>> d97af3b... add prima wlan driver
=======
                hddLog(VOS_TRACE_LEVEL_ERROR, 
                        "%s: sme_RoamSetKey failed, returned %d", __func__, 
>>>>>>> 657b0e9... prima update
                        status);
                return -EINVAL;
            }
        }
    }

    /* In SoftAp mode setting key direction for default mode */
    else if ( WLAN_HDD_SOFTAP == pAdapter->device_mode )
    {
        if ( (eCSR_ENCRYPT_TYPE_TKIP !=
                pWextState->roamProfile.EncryptionType.encryptionType[0]) &&
             (eCSR_ENCRYPT_TYPE_AES !=
                pWextState->roamProfile.EncryptionType.encryptionType[0])
           )
        {
            /*  Saving key direction for default key index to TX default */
            hdd_ap_ctx_t *pAPCtx = WLAN_HDD_GET_AP_CTX_PTR(pAdapter);
            pAPCtx->wepKey[key_index].keyDirection = eSIR_TX_DEFAULT;
        }
    }
<<<<<<< HEAD
<<<<<<< HEAD
 
    return status;
}

/**
 * FUNCTION: wlan_hdd_cfg80211_set_channel
 * This function is used to set the channel number 
 */
int wlan_hdd_cfg80211_set_channel( struct wiphy *wiphy, struct net_device *dev,
                                   struct ieee80211_channel *chan,
                                   enum nl80211_channel_type channel_type
                                 )
{
    v_U32_t num_ch = 0;
    u32 channel = 0;
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR( dev ); 
    int freq = chan->center_freq; /* freq is in MHZ */ 
 
    ENTER();
    
    hddLog(VOS_TRACE_LEVEL_INFO, 
                "%s: device_mode = %d  freq = %d \n",__func__, 
                            pAdapter->device_mode, chan->center_freq);
    if ((WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress)
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL, "%s:LOGP in Progress. Ignore!!!",__func__);
        return -EAGAIN;
    }

    /* 
     * Do freq to chan conversion
     * TODO: for 11a
     */

    channel = ieee80211_frequency_to_channel(freq);
    
    /* Check freq range */
    if ((WNI_CFG_CURRENT_CHANNEL_STAMIN > channel) || 
            (WNI_CFG_CURRENT_CHANNEL_STAMAX < channel)) 
    {
        hddLog(VOS_TRACE_LEVEL_ERROR, 
                "%s: Channel [%d] is outside valid range from %d to %d\n",
                __func__, channel, WNI_CFG_CURRENT_CHANNEL_STAMIN,
                WNI_CFG_CURRENT_CHANNEL_STAMAX);
        return -EINVAL;
    }

    num_ch = WNI_CFG_VALID_CHANNEL_LIST_LEN;

    if ((WLAN_HDD_SOFTAP != pAdapter->device_mode)
#ifdef WLAN_FEATURE_P2P
     && (WLAN_HDD_P2P_GO != pAdapter->device_mode)
#endif
      )
    {
        if(VOS_STATUS_SUCCESS != wlan_hdd_validate_operation_channel(pAdapter,channel))
        {
            hddLog(VOS_TRACE_LEVEL_ERROR,
                    "%s: Invalid Channel [%d] \n", __func__, channel);
            return -EINVAL;
        }
        hddLog(VOS_TRACE_LEVEL_INFO_HIGH, 
                "%s: set channel to [%d] for device mode =%d", 
                          __func__, channel,pAdapter->device_mode);
    }
    if( (pAdapter->device_mode == WLAN_HDD_INFRA_STATION)
#ifdef WLAN_FEATURE_P2P
     || (pAdapter->device_mode == WLAN_HDD_P2P_CLIENT)
#endif
      )
    {
        hdd_wext_state_t *pWextState = WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter); 
        tCsrRoamProfile * pRoamProfile = &pWextState->roamProfile;
        hdd_station_ctx_t *pHddStaCtx = WLAN_HDD_GET_STATION_CTX_PTR(pAdapter);

        if (eConnectionState_IbssConnected == pHddStaCtx->conn_info.connState)
        {
           /* Link is up then return cant set channel*/
            hddLog( VOS_TRACE_LEVEL_ERROR, 
                   "%s: IBSS Associated, can't set the channel\n", __func__);
            return -EINVAL;
        }

        num_ch = pRoamProfile->ChannelInfo.numOfChannels = 1;
        pHddStaCtx->conn_info.operationChannel = channel; 
        pRoamProfile->ChannelInfo.ChannelList = 
            &pHddStaCtx->conn_info.operationChannel; 
    }
    else if ((pAdapter->device_mode == WLAN_HDD_SOFTAP) 
#ifdef WLAN_FEATURE_P2P
        ||   (pAdapter->device_mode == WLAN_HDD_P2P_GO)
#endif
            ) 
    {
        (WLAN_HDD_GET_AP_CTX_PTR(pAdapter))->sapConfig.channel = channel;

        if ( WLAN_HDD_SOFTAP == pAdapter->device_mode )
        {
            hdd_config_t *cfg_param = (WLAN_HDD_GET_CTX(pAdapter))->cfg_ini;

            /* If auto channel selection is configured as enable/ 1 then ignore
            channel set by supplicant
            */
            if ( cfg_param->apAutoChannelSelection )
            {
                (WLAN_HDD_GET_AP_CTX_PTR(pAdapter))->sapConfig.channel = AUTO_CHANNEL_SELECT;

                hddLog(VOS_TRACE_LEVEL_INFO_HIGH,
                       "%s: set channel to auto channel (0) for device mode =%d",
                       __func__, pAdapter->device_mode);
            }
        }
    }
    else 
    {
        hddLog(VOS_TRACE_LEVEL_FATAL, 
               "%s: Invalid device mode failed to set valid channel", __func__);
        return -EINVAL;
    }
    EXIT();
    return 0;
}



=======

    return status;
}

>>>>>>> d97af3b... add prima wlan driver
=======
 
    return status;
}

/**
 * FUNCTION: wlan_hdd_cfg80211_set_channel
 * This function is used to set the channel number 
 */
int wlan_hdd_cfg80211_set_channel( struct wiphy *wiphy, struct net_device *dev,
                                   struct ieee80211_channel *chan,
                                   enum nl80211_channel_type channel_type
                                 )
{
    v_U32_t num_ch = 0;
    u32 channel = 0;
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR( dev ); 
    int freq = chan->center_freq; /* freq is in MHZ */ 
 
    ENTER();
    
    hddLog(VOS_TRACE_LEVEL_INFO, 
                "%s: device_mode = %d  freq = %d \n",__func__, 
                            pAdapter->device_mode, chan->center_freq);
    if ((WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress)
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL, "%s:LOGP in Progress. Ignore!!!",__func__);
        return -EAGAIN;
    }

    /* 
     * Do freq to chan conversion
     * TODO: for 11a
     */

    channel = ieee80211_frequency_to_channel(freq);
    
    /* Check freq range */
    if ((WNI_CFG_CURRENT_CHANNEL_STAMIN > channel) || 
            (WNI_CFG_CURRENT_CHANNEL_STAMAX < channel)) 
    {
        hddLog(VOS_TRACE_LEVEL_ERROR, 
                "%s: Channel [%d] is outside valid range from %d to %d\n",
                __func__, channel, WNI_CFG_CURRENT_CHANNEL_STAMIN,
                WNI_CFG_CURRENT_CHANNEL_STAMAX);
        return -EINVAL;
    }

    num_ch = WNI_CFG_VALID_CHANNEL_LIST_LEN;

    if ((WLAN_HDD_SOFTAP != pAdapter->device_mode)
#ifdef WLAN_FEATURE_P2P
     && (WLAN_HDD_P2P_GO != pAdapter->device_mode)
#endif
      )
    {
        if(VOS_STATUS_SUCCESS != wlan_hdd_validate_operation_channel(pAdapter,channel))
        {
            hddLog(VOS_TRACE_LEVEL_ERROR,
                    "%s: Invalid Channel [%d] \n", __func__, channel);
            return -EINVAL;
        }
        hddLog(VOS_TRACE_LEVEL_INFO_HIGH, 
                "%s: set channel to [%d] for device mode =%d", 
                          __func__, channel,pAdapter->device_mode);
    }
    if( (pAdapter->device_mode == WLAN_HDD_INFRA_STATION)
#ifdef WLAN_FEATURE_P2P
     || (pAdapter->device_mode == WLAN_HDD_P2P_CLIENT)
#endif
      )
    {
        hdd_wext_state_t *pWextState = WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter); 
        tCsrRoamProfile * pRoamProfile = &pWextState->roamProfile;
        hdd_station_ctx_t *pHddStaCtx = WLAN_HDD_GET_STATION_CTX_PTR(pAdapter);

        if (eConnectionState_IbssConnected == pHddStaCtx->conn_info.connState)
        {
           /* Link is up then return cant set channel*/
            hddLog( VOS_TRACE_LEVEL_ERROR, 
                   "%s: IBSS Associated, can't set the channel\n", __func__);
            return -EINVAL;
        }

        num_ch = pRoamProfile->ChannelInfo.numOfChannels = 1;
        pHddStaCtx->conn_info.operationChannel = channel; 
        pRoamProfile->ChannelInfo.ChannelList = 
            &pHddStaCtx->conn_info.operationChannel; 
    }
    else if ((pAdapter->device_mode == WLAN_HDD_SOFTAP) 
#ifdef WLAN_FEATURE_P2P
        ||   (pAdapter->device_mode == WLAN_HDD_P2P_GO)
#endif
            ) 
    {
        (WLAN_HDD_GET_AP_CTX_PTR(pAdapter))->sapConfig.channel = channel;

        if ( WLAN_HDD_SOFTAP == pAdapter->device_mode )
        {
            hdd_config_t *cfg_param = (WLAN_HDD_GET_CTX(pAdapter))->cfg_ini;

            /* If auto channel selection is configured as enable/ 1 then ignore
            channel set by supplicant
            */
            if ( cfg_param->apAutoChannelSelection )
            {
                (WLAN_HDD_GET_AP_CTX_PTR(pAdapter))->sapConfig.channel = AUTO_CHANNEL_SELECT;

                hddLog(VOS_TRACE_LEVEL_INFO_HIGH,
                       "%s: set channel to auto channel (0) for device mode =%d",
                       __func__, pAdapter->device_mode);
            }
        }
    }
    else 
    {
        hddLog(VOS_TRACE_LEVEL_FATAL, 
               "%s: Invalid device mode failed to set valid channel", __func__);
        return -EINVAL;
    }
    EXIT();
    return 0;
}



>>>>>>> 657b0e9... prima update
/*
 * FUNCTION: wlan_hdd_cfg80211_inform_bss
 * This function is used to inform the BSS details to nl80211 interface.
 */
static struct cfg80211_bss* wlan_hdd_cfg80211_inform_bss(
                    hdd_adapter_t *pAdapter, tCsrRoamConnectedProfile *roamProfile)
{
    struct net_device *dev = pAdapter->dev;
    struct wireless_dev *wdev = dev->ieee80211_ptr;
    struct wiphy *wiphy = wdev->wiphy;
    tSirBssDescription *pBssDesc = roamProfile->pBssDesc;
    int chan_no;
    int ie_length;
    const char *ie;
    unsigned int freq;
    struct ieee80211_channel *chan;
    int rssi = 0;
    struct cfg80211_bss *bss = NULL;

    ENTER();

    if( NULL == pBssDesc )
    {
        hddLog(VOS_TRACE_LEVEL_FATAL, "%s: pBssDesc is NULL\n", __func__);
        return bss;
    }

    chan_no = pBssDesc->channelId;
    ie_length = GET_IE_LEN_IN_BSS_DESC( pBssDesc->length );
    ie =  ((ie_length != 0) ? (const char *)&pBssDesc->ieFields: NULL);

    if( NULL == ie )
    {
       hddLog(VOS_TRACE_LEVEL_FATAL, "%s: IE of BSS descriptor is NULL\n", __func__);
       return bss;
    }

#if (LINUX_VERSION_CODE > KERNEL_VERSION(2,6,38))
    if (chan_no <= ARRAY_SIZE(hdd_channels_2_4_GHZ))
    {
        freq = ieee80211_channel_to_frequency(chan_no, IEEE80211_BAND_2GHZ);
    }
    else
    {
        freq = ieee80211_channel_to_frequency(chan_no, IEEE80211_BAND_5GHZ);
    }
#else
    freq = ieee80211_channel_to_frequency(chan_no);
#endif

    chan = __ieee80211_get_channel(wiphy, freq);

    bss = cfg80211_get_bss(wiphy, chan, pBssDesc->bssId,
                           &roamProfile->SSID.ssId[0], roamProfile->SSID.length,
                           WLAN_CAPABILITY_ESS, WLAN_CAPABILITY_ESS);
    if (bss == NULL)
    {
        rssi = (VOS_MIN ((pBssDesc->rssi + pBssDesc->sinr), 0))*100;

<<<<<<< HEAD
<<<<<<< HEAD
        return (cfg80211_inform_bss(wiphy, chan, pBssDesc->bssId, 
                le64_to_cpu(*(__le64 *)pBssDesc->timeStamp), 
=======
        return (cfg80211_inform_bss(wiphy, chan, pBssDesc->bssId,
                le64_to_cpu(*(__le64 *)pBssDesc->timeStamp),
>>>>>>> d97af3b... add prima wlan driver
=======
        return (cfg80211_inform_bss(wiphy, chan, pBssDesc->bssId, 
                le64_to_cpu(*(__le64 *)pBssDesc->timeStamp), 
>>>>>>> 657b0e9... prima update
                pBssDesc->capabilityInfo,
                pBssDesc->beaconInterval, ie, ie_length,
                rssi, GFP_KERNEL ));
}
    else
    {
        return bss;
    }
}



/*
 * FUNCTION: wlan_hdd_cfg80211_inform_bss_frame
 * This function is used to inform the BSS details to nl80211 interface.
 */
struct cfg80211_bss*
wlan_hdd_cfg80211_inform_bss_frame( hdd_adapter_t *pAdapter,
                                    tSirBssDescription *bss_desc
                                    )
{
    /*
      cfg80211_inform_bss() is not updating ie field of bss entry, if entry
      already exists in bss data base of cfg80211 for that particular BSS ID.
      Using cfg80211_inform_bss_frame to update the bss entry instead of
      cfg80211_inform_bss, But this call expects mgmt packet as input. As of
      now there is no possibility to get the mgmt(probe response) frame from PE,
      converting bss_desc to ieee80211_mgmt(probe response) and passing to
      cfg80211_inform_bss_frame.
     */
    struct net_device *dev = pAdapter->dev;
    struct wireless_dev *wdev = dev->ieee80211_ptr;
    struct wiphy *wiphy = wdev->wiphy;
    int chan_no = bss_desc->channelId;
<<<<<<< HEAD
<<<<<<< HEAD
    int ie_length = GET_IE_LEN_IN_BSS_DESC( bss_desc->length );
=======
#ifdef WLAN_ENABLE_AGEIE_ON_SCAN_RESULTS
    qcom_ie_age *qie_age = NULL;
    int ie_length = GET_IE_LEN_IN_BSS_DESC( bss_desc->length ) + sizeof(qcom_ie_age);
#else
    int ie_length = GET_IE_LEN_IN_BSS_DESC( bss_desc->length );
#endif
>>>>>>> d97af3b... add prima wlan driver
=======
    int ie_length = GET_IE_LEN_IN_BSS_DESC( bss_desc->length );
>>>>>>> 657b0e9... prima update
    const char *ie =
        ((ie_length != 0) ? (const char *)&bss_desc->ieFields: NULL);
    unsigned int freq;
    struct ieee80211_channel *chan;
    struct ieee80211_mgmt *mgmt =
        kzalloc((sizeof (struct ieee80211_mgmt) + ie_length), GFP_KERNEL);
    struct cfg80211_bss *bss_status = NULL;
    size_t frame_len = sizeof (struct ieee80211_mgmt) + ie_length;
    int rssi = 0;
#ifdef WLAN_OPEN_SOURCE
    struct timespec ts;
#endif

    ENTER();

    if (!mgmt)
        return NULL;

    memcpy(mgmt->bssid, bss_desc->bssId, ETH_ALEN);

#ifdef WLAN_OPEN_SOURCE
    /* Android does not want the timestamp from the frame.
       Instead it wants a monotonic increasing value */
    get_monotonic_boottime(&ts);
    mgmt->u.probe_resp.timestamp =
         ((u64)ts.tv_sec * 1000000) + (ts.tv_nsec / 1000);
#else
    /* keep old behavior for non-open source (for now) */
    memcpy(&mgmt->u.probe_resp.timestamp, bss_desc->timeStamp,
            sizeof (bss_desc->timeStamp));

#endif

    mgmt->u.probe_resp.beacon_int = bss_desc->beaconInterval;
    mgmt->u.probe_resp.capab_info = bss_desc->capabilityInfo;
<<<<<<< HEAD
<<<<<<< HEAD
    memcpy(mgmt->u.probe_resp.variable, ie, ie_length);

    mgmt->frame_control |=
        (u16)(IEEE80211_FTYPE_MGMT | IEEE80211_STYPE_PROBE_RESP);

#if (LINUX_VERSION_CODE > KERNEL_VERSION(2,6,38))
    if (chan_no <= ARRAY_SIZE(hdd_channels_2_4_GHZ) && 
=======

#ifdef WLAN_ENABLE_AGEIE_ON_SCAN_RESULTS
    /* GPS Requirement: need age ie per entry. Using vendor specific. */
    /* Assuming this is the last IE, copy at the end */
    ie_length           -=sizeof(qcom_ie_age);
    qie_age =  (qcom_ie_age *)(mgmt->u.probe_resp.variable + ie_length);
    qie_age->element_id = QCOM_VENDOR_IE_ID;
    qie_age->len        = QCOM_VENDOR_IE_AGE_LEN;
    qie_age->oui_1      = QCOM_OUI1;
    qie_age->oui_2      = QCOM_OUI2;
    qie_age->oui_3      = QCOM_OUI3;
    qie_age->type       = QCOM_VENDOR_IE_AGE_TYPE;
    qie_age->age        = vos_timer_get_system_ticks() - bss_desc->nReceivedTime;
#endif

=======
>>>>>>> 657b0e9... prima update
    memcpy(mgmt->u.probe_resp.variable, ie, ie_length);

    mgmt->frame_control |=
        (u16)(IEEE80211_FTYPE_MGMT | IEEE80211_STYPE_PROBE_RESP);

#if (LINUX_VERSION_CODE > KERNEL_VERSION(2,6,38))
<<<<<<< HEAD
    if (chan_no <= ARRAY_SIZE(hdd_channels_2_4_GHZ) &&
>>>>>>> d97af3b... add prima wlan driver
=======
    if (chan_no <= ARRAY_SIZE(hdd_channels_2_4_GHZ) && 
>>>>>>> 657b0e9... prima update
        (wiphy->bands[IEEE80211_BAND_2GHZ] != NULL))
    {
        freq = ieee80211_channel_to_frequency(chan_no, IEEE80211_BAND_2GHZ);
    }
<<<<<<< HEAD
<<<<<<< HEAD
    else if ((chan_no > ARRAY_SIZE(hdd_channels_2_4_GHZ)) && 
=======
    else if ((chan_no > ARRAY_SIZE(hdd_channels_2_4_GHZ)) &&
>>>>>>> d97af3b... add prima wlan driver
=======
    else if ((chan_no > ARRAY_SIZE(hdd_channels_2_4_GHZ)) && 
>>>>>>> 657b0e9... prima update
        (wiphy->bands[IEEE80211_BAND_5GHZ] != NULL))

    {
        freq = ieee80211_channel_to_frequency(chan_no, IEEE80211_BAND_5GHZ);
    }
    else
    {
        kfree(mgmt);
        return NULL;
    }
#else
    freq = ieee80211_channel_to_frequency(chan_no);
#endif
    chan = __ieee80211_get_channel(wiphy, freq);
<<<<<<< HEAD
<<<<<<< HEAD

    /*To keep the rssi icon of the connected AP in the scan window
    *and the rssi icon of the wireless networks in sync 
=======
    /*when the band is changed on the fly using the GUI, three things are done
     * 1. scan abort 2.flush scan results from cache 3.update the band with the new band user specified(refer to the hdd_setBand_helper function)
     * as part of the scan abort, message willbe queued to PE and we proceed with flushing and changinh the band.
     * pe will stop the scanning further and report back the results what ever it had till now by calling the call back function.
     * if the time between update band and scandone call back is sufficent enough the band change reflects in SME, SME validates the channels
     * and discards the channels correponding to previous band and calls back with zero bss results.
     * but if the time between band update and scan done callback is very small then band change will not reflect in SME and SME reports to HDD
     * all the channels correponding to previous band.this is due to race condition.but those channels are invalid to the new band and so
     * this function __ieee80211_get_channel will return NULL.Each time we report scan result with this pointer null warning kernel trace is printed.
     * if the scan results contain large number of APs continuosly kernel warning trace is printed and it will lead to apps watch dog bark.
     * So drop the bss and continue to next bss.
     */
    if(chan == NULL)
    {
       hddLog(VOS_TRACE_LEVEL_INFO, "%s chan pointer is NULL", __func__);
       kfree(mgmt);
       return NULL;
    }
    /*To keep the rssi icon of the connected AP in the scan window
    *and the rssi icon of the wireless networks in sync
>>>>>>> d97af3b... add prima wlan driver
=======

    /*To keep the rssi icon of the connected AP in the scan window
    *and the rssi icon of the wireless networks in sync 
>>>>>>> 657b0e9... prima update
    * */
    if (( eConnectionState_Associated ==
             pAdapter->sessionCtx.station.conn_info.connState ) &&
             ( VOS_TRUE == vos_mem_compare(bss_desc->bssId,
                             pAdapter->sessionCtx.station.conn_info.bssId,
                             WNI_CFG_BSSID_LEN)))
    {
       /* supplicant takes the signal strength in terms of mBm(100*dBm) */
       rssi = (pAdapter->rssi * 100);
    }
    else
    {
       rssi = (VOS_MIN ((bss_desc->rssi + bss_desc->sinr), 0))*100;
    }

    bss_status = cfg80211_inform_bss_frame(wiphy, chan, mgmt,
            frame_len, rssi, GFP_KERNEL);
    kfree(mgmt);
    return bss_status;
}

/*
 * FUNCTION: wlan_hdd_cfg80211_update_bss_db
 * This function is used to update the BSS data base of CFG8011
 */
<<<<<<< HEAD
<<<<<<< HEAD
struct cfg80211_bss* wlan_hdd_cfg80211_update_bss_db( hdd_adapter_t *pAdapter, 
=======
struct cfg80211_bss* wlan_hdd_cfg80211_update_bss_db( hdd_adapter_t *pAdapter,
>>>>>>> d97af3b... add prima wlan driver
=======
struct cfg80211_bss* wlan_hdd_cfg80211_update_bss_db( hdd_adapter_t *pAdapter, 
>>>>>>> 657b0e9... prima update
                                      tCsrRoamInfo *pRoamInfo
                                      )
{
    tCsrRoamConnectedProfile roamProfile;
    tHalHandle hHal = WLAN_HDD_GET_HAL_CTX(pAdapter);
    struct cfg80211_bss *bss = NULL;

    ENTER();

    memset(&roamProfile, 0, sizeof(tCsrRoamConnectedProfile));
    sme_RoamGetConnectProfile(hHal, pAdapter->sessionId, &roamProfile);

    if (NULL != roamProfile.pBssDesc)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        bss = wlan_hdd_cfg80211_inform_bss(pAdapter, 
=======
        bss = wlan_hdd_cfg80211_inform_bss(pAdapter,
>>>>>>> d97af3b... add prima wlan driver
=======
        bss = wlan_hdd_cfg80211_inform_bss(pAdapter, 
>>>>>>> 657b0e9... prima update
                &roamProfile);

        if (NULL == bss)
        {
            hddLog(VOS_TRACE_LEVEL_INFO, "%s: cfg80211_inform_bss return NULL",
                    __func__);
        }

        sme_RoamFreeConnectProfile(hHal, &roamProfile);
    }
    else
    {
        hddLog(VOS_TRACE_LEVEL_ERROR, "%s:  roamProfile.pBssDesc is NULL",
                __func__);
    }
    return bss;
}

/*
 * FUNCTION: wlan_hdd_cfg80211_update_bss
 */
<<<<<<< HEAD
<<<<<<< HEAD
static int wlan_hdd_cfg80211_update_bss( struct wiphy *wiphy, 
                                         hdd_adapter_t *pAdapter 
                                        )
{   
=======
static int wlan_hdd_cfg80211_update_bss( struct wiphy *wiphy,
                                         hdd_adapter_t *pAdapter
                                        )
{
>>>>>>> d97af3b... add prima wlan driver
=======
static int wlan_hdd_cfg80211_update_bss( struct wiphy *wiphy, 
                                         hdd_adapter_t *pAdapter 
                                        )
{   
>>>>>>> 657b0e9... prima update
    tHalHandle hHal = WLAN_HDD_GET_HAL_CTX(pAdapter);
    tCsrScanResultInfo *pScanResult;
    eHalStatus status = 0;
    tScanResultHandle pResult;
    struct cfg80211_bss *bss_status = NULL;

    ENTER();

    if ((WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress)
    {
      VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL, "%s:LOGP in Progress. Ignore!!!",__func__);
      return -EAGAIN;
    }

    /*
     * start getting scan results and populate cgf80211 BSS database
     */
    status = sme_ScanGetResult(hHal, pAdapter->sessionId, NULL, &pResult);

    /* no scan results */
    if (NULL == pResult)
    {
        hddLog(VOS_TRACE_LEVEL_INFO, "%s: No scan result\n", __func__);
        return status;
    }

    pScanResult = sme_ScanResultGetFirst(hHal, pResult);

    while (pScanResult)
    {
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
        /* 
         * cfg80211_inform_bss() is not updating ie field of bss entry, if 
         * entry already exists in bss data base of cfg80211 for that 
         * particular BSS ID.  Using cfg80211_inform_bss_frame to update the 
         * bss entry instead of cfg80211_inform_bss, But this call expects 
         * mgmt packet as input. As of now there is no possibility to get 
         * the mgmt(probe response) frame from PE, converting bss_desc to 
<<<<<<< HEAD
=======
        /*
         * cfg80211_inform_bss() is not updating ie field of bss entry, if
         * entry already exists in bss data base of cfg80211 for that
         * particular BSS ID.  Using cfg80211_inform_bss_frame to update the
         * bss entry instead of cfg80211_inform_bss, But this call expects
         * mgmt packet as input. As of now there is no possibility to get
         * the mgmt(probe response) frame from PE, converting bss_desc to
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
         * ieee80211_mgmt(probe response) and passing to c
         * fg80211_inform_bss_frame.
         * */

        bss_status = wlan_hdd_cfg80211_inform_bss_frame(pAdapter,
                &pScanResult->BssDescriptor);
<<<<<<< HEAD
<<<<<<< HEAD
    
=======

>>>>>>> d97af3b... add prima wlan driver
=======
    
>>>>>>> 657b0e9... prima update

        if (NULL == bss_status)
        {
            hddLog(VOS_TRACE_LEVEL_INFO,
                    "%s: NULL returned by cfg80211_inform_bss\n", __func__);
        }
        else
        {
<<<<<<< HEAD
<<<<<<< HEAD
            cfg80211_put_bss(bss_status);
=======
            cfg80211_put_bss(
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(3,9,0))
                             wiphy,
#endif
                             bss_status);
>>>>>>> d97af3b... add prima wlan driver
=======
            cfg80211_put_bss(bss_status);
>>>>>>> 657b0e9... prima update
        }

        pScanResult = sme_ScanResultGetNext(hHal, pResult);
    }

<<<<<<< HEAD
<<<<<<< HEAD
    sme_ScanResultPurge(hHal, pResult); 

    return 0; 
=======
    sme_ScanResultPurge(hHal, pResult);

    return 0;
>>>>>>> d97af3b... add prima wlan driver
=======
    sme_ScanResultPurge(hHal, pResult); 

    return 0; 
>>>>>>> 657b0e9... prima update
}

void
hddPrintMacAddr(tCsrBssid macAddr, tANI_U8 logLevel)
{
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
    VOS_TRACE(VOS_MODULE_ID_HDD, logLevel, 
           "%X:%X:%X:%X:%X:%X\n",
           macAddr[0], macAddr[1], macAddr[2], macAddr[3], macAddr[4],
           macAddr[5]);
<<<<<<< HEAD
} /****** end hddPrintMacAddr() ******/

void
hddPrintPmkId(tCsrBssid pmkId, tANI_U8 logLevel)
{
    VOS_TRACE(VOS_MODULE_ID_HDD, logLevel, 
           "%X:%X:%X:%X:%X:%X:%X:%X:%X:%X:%X:%X:%X:%X:%X:%X\n",
           pmkId[0], pmkId[1], pmkId[2], pmkId[3], pmkId[4],
           pmkId[5], pmkId[6], pmkId[7], pmkId[8], pmkId[9],
           pmkId[10], pmkId[11], pmkId[12], pmkId[13], pmkId[14],
           pmkId[15]);
=======
    VOS_TRACE(VOS_MODULE_ID_HDD, logLevel,
              "%02X:%02X:%02X:%02X:%02X:%02X\n",
              macAddr[0], macAddr[1], macAddr[2], macAddr[3], macAddr[4],
              macAddr[5]);
=======
>>>>>>> 657b0e9... prima update
} /****** end hddPrintMacAddr() ******/

void
hddPrintPmkId(tCsrBssid pmkId, tANI_U8 logLevel)
{
<<<<<<< HEAD
    VOS_TRACE(VOS_MODULE_ID_HDD, logLevel,
              "%02X:%02X:%02X:%02X:%02X:%02X:%02X:%02X:%02X:%02X:%02X:%02X:%02X:%02X:%02X:%02X\n",
              pmkId[0], pmkId[1], pmkId[2], pmkId[3], pmkId[4],
              pmkId[5], pmkId[6], pmkId[7], pmkId[8], pmkId[9], pmkId[10],
              pmkId[11], pmkId[12], pmkId[13], pmkId[14], pmkId[15]);
>>>>>>> d97af3b... add prima wlan driver
=======
    VOS_TRACE(VOS_MODULE_ID_HDD, logLevel, 
           "%X:%X:%X:%X:%X:%X:%X:%X:%X:%X:%X:%X:%X:%X:%X:%X\n",
           pmkId[0], pmkId[1], pmkId[2], pmkId[3], pmkId[4],
           pmkId[5], pmkId[6], pmkId[7], pmkId[8], pmkId[9],
           pmkId[10], pmkId[11], pmkId[12], pmkId[13], pmkId[14],
           pmkId[15]);
>>>>>>> 657b0e9... prima update
} /****** end hddPrintPmkId() ******/

//hddPrintMacAddr(tCsrBssid macAddr, tANI_U8 logLevel);
//hddPrintMacAddr(macAddr, VOS_TRACE_LEVEL_FATAL);

//void sirDumpBuf(tpAniSirGlobal pMac, tANI_U8 modId, tANI_U32 level, tANI_U8 *buf, tANI_U32 size);
//sirDumpBuf(pMac, VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL, pmkid, 16);

#define dump_bssid(bssid) \
    { \
        hddLog(VOS_TRACE_LEVEL_INFO, "BSSID (MAC) address:\t"); \
        hddPrintMacAddr(bssid, VOS_TRACE_LEVEL_INFO);\
        hddLog(VOS_TRACE_LEVEL_INFO, "\n"); \
    }

#define dump_pmkid(pMac, pmkid) \
    { \
        hddLog(VOS_TRACE_LEVEL_INFO, "PMKSA-ID:\t"); \
        hddPrintPmkId(pmkid, VOS_TRACE_LEVEL_INFO);\
        hddLog(VOS_TRACE_LEVEL_INFO, "\n"); \
    }

<<<<<<< HEAD
<<<<<<< HEAD
#ifdef FEATURE_WLAN_LFR
=======
#if defined(FEATURE_WLAN_LFR) && (LINUX_VERSION_CODE >= KERNEL_VERSION(3,4,0))
>>>>>>> d97af3b... add prima wlan driver
=======
#ifdef FEATURE_WLAN_LFR
>>>>>>> 657b0e9... prima update
/*
 * FUNCTION: wlan_hdd_cfg80211_pmksa_candidate_notify
 * This function is used to notify the supplicant of a new PMKSA candidate.
 */
int wlan_hdd_cfg80211_pmksa_candidate_notify(
<<<<<<< HEAD
<<<<<<< HEAD
                    hdd_adapter_t *pAdapter, tCsrRoamInfo *pRoamInfo, 
=======
                    hdd_adapter_t *pAdapter, tCsrRoamInfo *pRoamInfo,
>>>>>>> d97af3b... add prima wlan driver
=======
                    hdd_adapter_t *pAdapter, tCsrRoamInfo *pRoamInfo, 
>>>>>>> 657b0e9... prima update
                    int index, bool preauth )
{
#ifdef FEATURE_WLAN_OKC
    struct net_device *dev = pAdapter->dev;
<<<<<<< HEAD
<<<<<<< HEAD
=======
    hdd_context_t *pHddCtx = (hdd_context_t*)pAdapter->pHddCtx;
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update

    ENTER();
    hddLog(VOS_TRACE_LEVEL_INFO, "%s is going to notify supplicant of:", __func__);

    if( NULL == pRoamInfo )
    {
        hddLog(VOS_TRACE_LEVEL_FATAL, "%s: pRoamInfo is NULL\n", __func__);
        return -EINVAL;
    }

<<<<<<< HEAD
<<<<<<< HEAD
    dump_bssid(pRoamInfo->bssid);
    cfg80211_pmksa_candidate_notify(dev, index,
                                    pRoamInfo->bssid, preauth, GFP_KERNEL);
#endif  /* FEATURE_WLAN_OKC */
    return 0; 
=======
    if (eANI_BOOLEAN_TRUE == hdd_is_okc_mode_enabled(pHddCtx))
    {
        dump_bssid(pRoamInfo->bssid);
        cfg80211_pmksa_candidate_notify(dev, index,
=======
    dump_bssid(pRoamInfo->bssid);
    cfg80211_pmksa_candidate_notify(dev, index,
>>>>>>> 657b0e9... prima update
                                    pRoamInfo->bssid, preauth, GFP_KERNEL);
#endif  /* FEATURE_WLAN_OKC */
<<<<<<< HEAD
    return 0;
>>>>>>> d97af3b... add prima wlan driver
=======
    return 0; 
>>>>>>> 657b0e9... prima update
}
#endif //FEATURE_WLAN_LFR

/*
 * FUNCTION: hdd_cfg80211_scan_done_callback
 * scanning callback function, called after finishing scan
 *
 */
<<<<<<< HEAD
<<<<<<< HEAD
static eHalStatus hdd_cfg80211_scan_done_callback(tHalHandle halHandle, 
        void *pContext, tANI_U32 scanId, eCsrScanStatus status)
{
    struct net_device *dev = (struct net_device *) pContext;
    //struct wireless_dev *wdev = dev->ieee80211_ptr;    
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR( dev );
    hdd_scaninfo_t *pScanInfo = &pAdapter->scan_info;
=======
static eHalStatus hdd_cfg80211_scan_done_callback(tHalHandle halHandle,
=======
static eHalStatus hdd_cfg80211_scan_done_callback(tHalHandle halHandle, 
>>>>>>> 657b0e9... prima update
        void *pContext, tANI_U32 scanId, eCsrScanStatus status)
{
    struct net_device *dev = (struct net_device *) pContext;
    //struct wireless_dev *wdev = dev->ieee80211_ptr;    
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR( dev );
<<<<<<< HEAD
    hdd_context_t *pHddCtx = WLAN_HDD_GET_CTX(pAdapter);
    hdd_scaninfo_t *pScanInfo = &pHddCtx->scan_info;
>>>>>>> d97af3b... add prima wlan driver
=======
    hdd_scaninfo_t *pScanInfo = &pAdapter->scan_info;
>>>>>>> 657b0e9... prima update
    struct cfg80211_scan_request *req = NULL;
    int ret = 0;

    ENTER();

    hddLog(VOS_TRACE_LEVEL_INFO,
            "%s called with halHandle = %p, pContext = %p,"
<<<<<<< HEAD
<<<<<<< HEAD
            "scanID = %d, returned status = %d\n", 
=======
            "scanID = %d, returned status = %d\n",
>>>>>>> d97af3b... add prima wlan driver
=======
            "scanID = %d, returned status = %d\n", 
>>>>>>> 657b0e9... prima update
            __func__, halHandle, pContext, (int) scanId, (int) status);

    //Block on scan req completion variable. Can't wait forever though.
    ret = wait_for_completion_interruptible_timeout(
                         &pScanInfo->scan_req_completion_event,
                         msecs_to_jiffies(WLAN_WAIT_TIME_SCAN_REQ));
    if (!ret)
    {
       VOS_ASSERT(pScanInfo->mScanPending);
       goto allow_suspend;
    }

    if(pScanInfo->mScanPending != VOS_TRUE)
    {
        VOS_ASSERT(pScanInfo->mScanPending);
        goto allow_suspend;
    }

    /* Check the scanId */
<<<<<<< HEAD
<<<<<<< HEAD
    if (pScanInfo->scanId != scanId) 
    {
        hddLog(VOS_TRACE_LEVEL_INFO,
                "%s called with mismatched scanId pScanInfo->scanId = %d "
                "scanId = %d \n", __func__, (int) pScanInfo->scanId, 
                (int) scanId);
    }

    ret = wlan_hdd_cfg80211_update_bss((WLAN_HDD_GET_CTX(pAdapter))->wiphy, 
                                        pAdapter);

    if (0 > ret)
        hddLog(VOS_TRACE_LEVEL_INFO, "%s: NO SCAN result", __func__);    
=======
    if (pScanInfo->scanId != scanId)
=======
    if (pScanInfo->scanId != scanId) 
>>>>>>> 657b0e9... prima update
    {
        hddLog(VOS_TRACE_LEVEL_INFO,
                "%s called with mismatched scanId pScanInfo->scanId = %d "
                "scanId = %d \n", __func__, (int) pScanInfo->scanId, 
                (int) scanId);
    }

    ret = wlan_hdd_cfg80211_update_bss((WLAN_HDD_GET_CTX(pAdapter))->wiphy, 
                                        pAdapter);

    if (0 > ret)
<<<<<<< HEAD
        hddLog(VOS_TRACE_LEVEL_INFO, "%s: NO SCAN result", __func__);
>>>>>>> d97af3b... add prima wlan driver
=======
        hddLog(VOS_TRACE_LEVEL_INFO, "%s: NO SCAN result", __func__);    
>>>>>>> 657b0e9... prima update


    /* If any client wait scan result through WEXT
     * send scan done event to client */
<<<<<<< HEAD
<<<<<<< HEAD
    if (pAdapter->scan_info.waitScanResult)
    {
        /* The other scan request waiting for current scan finish
         * Send event to notify current scan finished */
        if(WEXT_SCAN_PENDING_DELAY == pAdapter->scan_info.scan_pending_option)
        {
            vos_event_set(&pAdapter->scan_info.scan_finished_event);
        }
        /* Send notify to WEXT client */
        else if(WEXT_SCAN_PENDING_PIGGYBACK == pAdapter->scan_info.scan_pending_option)
=======
    if (pHddCtx->scan_info.waitScanResult)
=======
    if (pAdapter->scan_info.waitScanResult)
>>>>>>> 657b0e9... prima update
    {
        /* The other scan request waiting for current scan finish
         * Send event to notify current scan finished */
        if(WEXT_SCAN_PENDING_DELAY == pAdapter->scan_info.scan_pending_option)
        {
            vos_event_set(&pAdapter->scan_info.scan_finished_event);
        }
        /* Send notify to WEXT client */
<<<<<<< HEAD
        else if(WEXT_SCAN_PENDING_PIGGYBACK == pHddCtx->scan_info.scan_pending_option)
>>>>>>> d97af3b... add prima wlan driver
=======
        else if(WEXT_SCAN_PENDING_PIGGYBACK == pAdapter->scan_info.scan_pending_option)
>>>>>>> 657b0e9... prima update
        {
            struct net_device *dev = pAdapter->dev;
            union iwreq_data wrqu;
            int we_event;
            char *msg;

            memset(&wrqu, '\0', sizeof(wrqu));
            we_event = SIOCGIWSCAN;
            msg = NULL;
            wireless_send_event(dev, we_event, &wrqu, msg);
        }
    }
<<<<<<< HEAD
<<<<<<< HEAD
    pAdapter->scan_info.waitScanResult = FALSE;
=======
    pHddCtx->scan_info.waitScanResult = FALSE;
>>>>>>> d97af3b... add prima wlan driver
=======
    pAdapter->scan_info.waitScanResult = FALSE;
>>>>>>> 657b0e9... prima update

    /* Get the Scan Req */
    req = pAdapter->request;

    if (!req)
    {
        hddLog(VOS_TRACE_LEVEL_ERROR, "request is became NULL\n");
        pScanInfo->mScanPending = VOS_FALSE;
        goto allow_suspend;
    }

    /*
     * setting up 0, just in case.
<<<<<<< HEAD
<<<<<<< HEAD
     */  
=======
     */
>>>>>>> d97af3b... add prima wlan driver
=======
     */  
>>>>>>> 657b0e9... prima update
    req->n_ssids = 0;
    req->n_channels = 0;
    req->ie = 0;

<<<<<<< HEAD
<<<<<<< HEAD
    complete(&pAdapter->abortscan_event_var);
=======
>>>>>>> d97af3b... add prima wlan driver
=======
    complete(&pAdapter->abortscan_event_var);
>>>>>>> 657b0e9... prima update
    pAdapter->request = NULL;
    /* Scan is no longer pending */
    pScanInfo->mScanPending = VOS_FALSE;

    /*
     * cfg80211_scan_done informing NL80211 about completion
     * of scanning
     */
    cfg80211_scan_done(req, false);
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
#ifdef WLAN_FEATURE_P2P
    /* Flush out scan result after p2p_serach is done */
    if(pScanInfo->flushP2pScanResults)
    {
        tANI_U8 sessionId = pAdapter->sessionId;
        sme_ScanFlushP2PResult(WLAN_HDD_GET_HAL_CTX(pAdapter), sessionId);
        pScanInfo->flushP2pScanResults = 0;
    }
#endif
<<<<<<< HEAD
=======
    complete(&pScanInfo->abortscan_event_var);
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update

allow_suspend:
    /* release the wake lock at the end of the scan*/
    hdd_allow_suspend();

<<<<<<< HEAD
<<<<<<< HEAD
=======
    /* Acquire wakelock to handle the case where APP's tries to suspend
     * immediatly after the driver gets connect request(i.e after scan)
     * from supplicant, this result in app's is suspending and not able
     * to process the connect request to AP */
    hdd_allow_suspend_timeout(1000);

#ifdef FEATURE_WLAN_TDLS
    wlan_hdd_tdls_scan_done_callback(pAdapter);
#endif

>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
    EXIT();
    return 0;
}

/*
<<<<<<< HEAD
<<<<<<< HEAD
 * FUNCTION: wlan_hdd_cfg80211_scan
 * this scan respond to scan trigger and update cfg80211 scan database
 * later, scan dump command can be used to recieve scan results
 */
int wlan_hdd_cfg80211_scan( struct wiphy *wiphy, struct net_device *dev,
        struct cfg80211_scan_request *request)
{  
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR( dev ); 
    hdd_context_t *pHddCtx = WLAN_HDD_GET_CTX( pAdapter );
    hdd_wext_state_t *pwextBuf = WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter);
    hdd_config_t *cfg_param = (WLAN_HDD_GET_CTX(pAdapter))->cfg_ini;
    tCsrScanRequest scanRequest;
    tANI_U8 *channelList = NULL, i;
    v_U32_t scanId = 0;
    int status = 0;
    hdd_scaninfo_t *pScanInfo = &pAdapter->scan_info;
#ifdef WLAN_FEATURE_P2P
    v_U8_t* pP2pIe = NULL;
#endif

=======
 * FUNCTION: hdd_isScanAllowed
 * Go through each adapter and check if scan allowed
 *
=======
 * FUNCTION: wlan_hdd_cfg80211_scan
 * this scan respond to scan trigger and update cfg80211 scan database
 * later, scan dump command can be used to recieve scan results
>>>>>>> 657b0e9... prima update
 */
int wlan_hdd_cfg80211_scan( struct wiphy *wiphy, struct net_device *dev,
        struct cfg80211_scan_request *request)
{  
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR( dev ); 
    hdd_context_t *pHddCtx = WLAN_HDD_GET_CTX( pAdapter );
    hdd_wext_state_t *pwextBuf = WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter);
    hdd_config_t *cfg_param = (WLAN_HDD_GET_CTX(pAdapter))->cfg_ini;
    tCsrScanRequest scanRequest;
    tANI_U8 *channelList = NULL, i;
    v_U32_t scanId = 0;
    int status = 0;
    hdd_scaninfo_t *pScanInfo = &pAdapter->scan_info;
#ifdef WLAN_FEATURE_P2P
    v_U8_t* pP2pIe = NULL;
#endif

>>>>>>> d97af3b... add prima wlan driver
    ENTER();

    hddLog(VOS_TRACE_LEVEL_INFO, "%s: device_mode = %d\n",
                                   __func__,pAdapter->device_mode);
<<<<<<< HEAD
<<<<<<< HEAD
#ifdef WLAN_BTAMP_FEATURE
    //Scan not supported when AMP traffic is on.
    if( VOS_TRUE == WLANBAP_AmpSessionOn() ) 
    {
        hddLog(VOS_TRACE_LEVEL_ERROR, 
=======

    status = wlan_hdd_validate_context(pHddCtx);

    if (0 != status)
    {
        VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                   "%s: HDD context is not valid", __func__);
        return status;
    }

    cfg_param = pHddCtx->cfg_ini;
    pScanInfo = &pHddCtx->scan_info;

    if ((WLAN_HDD_INFRA_STATION == pAdapter->device_mode) &&
        (eConnectionState_Connecting ==
           (WLAN_HDD_GET_STATION_CTX_PTR(pAdapter))->conn_info.connState))
    {
        hddLog(VOS_TRACE_LEVEL_ERROR,
                "%s: %p(%d) Connection in progress: Scan request denied (EBUSY)", __func__, \
                WLAN_HDD_GET_STATION_CTX_PTR(pAdapter), pAdapter->sessionId);
        return -EBUSY;
    }

=======
>>>>>>> 657b0e9... prima update
#ifdef WLAN_BTAMP_FEATURE
    //Scan not supported when AMP traffic is on.
    if( VOS_TRUE == WLANBAP_AmpSessionOn() ) 
    {
<<<<<<< HEAD
        hddLog(VOS_TRACE_LEVEL_ERROR,
>>>>>>> d97af3b... add prima wlan driver
=======
        hddLog(VOS_TRACE_LEVEL_ERROR, 
>>>>>>> 657b0e9... prima update
                "%s: No scanning when AMP is on", __func__);
        return -EOPNOTSUPP;
    }
#endif
    //Scan on any other interface is not supported.
<<<<<<< HEAD
<<<<<<< HEAD
    if( pAdapter->device_mode == WLAN_HDD_SOFTAP ) 
    {
        hddLog(VOS_TRACE_LEVEL_ERROR, 
=======
    if (pAdapter->device_mode == WLAN_HDD_SOFTAP)
    {
        hddLog(VOS_TRACE_LEVEL_ERROR,
>>>>>>> d97af3b... add prima wlan driver
=======
    if( pAdapter->device_mode == WLAN_HDD_SOFTAP ) 
    {
        hddLog(VOS_TRACE_LEVEL_ERROR, 
>>>>>>> 657b0e9... prima update
                "%s: Not scanning on device_mode = %d",
                                    __func__, pAdapter->device_mode);
        return -EOPNOTSUPP;
    }

    if (TRUE == pScanInfo->mScanPending)
    {
        hddLog(VOS_TRACE_LEVEL_INFO, "%s: mScanPending is TRUE", __func__);
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
        return -EBUSY;                  
    }

    if ((WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress)
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL,
                  "%s:LOGP in Progress. Ignore!!!", __func__);
        return -EAGAIN;
<<<<<<< HEAD
    }

    if ((WLAN_HDD_GET_CTX(pAdapter))->isLoadUnloadInProgress)
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL,
                  "%s:Unloading/Loading in Progress. Ignore!!!", __func__);
        return -EAGAIN;
    }
    //Don't Allow Scan and return busy if Remain On 
    //Channel and action frame is pending
    //Otherwise Cancel Remain On Channel and allow Scan
    //If no action frame pending
    if(0 != wlan_hdd_check_remain_on_channel(pAdapter))
=======
        return -EBUSY;
=======
>>>>>>> 657b0e9... prima update
    }

    if ((WLAN_HDD_GET_CTX(pAdapter))->isLoadUnloadInProgress)
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL,
                  "%s:Unloading/Loading in Progress. Ignore!!!", __func__);
        return -EAGAIN;
    }
    //Don't Allow Scan and return busy if Remain On 
    //Channel and action frame is pending
    //Otherwise Cancel Remain On Channel and allow Scan
    //If no action frame pending
<<<<<<< HEAD
    if (0 != wlan_hdd_check_remain_on_channel(pAdapter))
>>>>>>> d97af3b... add prima wlan driver
=======
    if(0 != wlan_hdd_check_remain_on_channel(pAdapter))
>>>>>>> 657b0e9... prima update
    {
        hddLog(VOS_TRACE_LEVEL_INFO, "%s: Remain On Channel Pending", __func__);
        return -EBUSY;
    }
<<<<<<< HEAD
<<<<<<< HEAD
=======
#ifdef FEATURE_WLAN_TDLS
    /* if tdls disagree scan right now, return immediately.
       tdls will schedule the scan when scan is allowed. (return SUCCESS)
       or will reject the scan if any TDLS is in progress. (return -EBUSY)
    */
    status = wlan_hdd_tdls_scan_callback (pAdapter,
                                          wiphy,
#if (LINUX_VERSION_CODE < KERNEL_VERSION(3,6,0))
                                          dev,
#endif
                                          request);
    if(status <= 0)
    {
        hddLog(VOS_TRACE_LEVEL_INFO, "%s: TDLS Pending %d", __func__, status);
        return status;
    }
#endif
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update

    if (mutex_lock_interruptible(&pHddCtx->tmInfo.tmOperationLock))
    {
        VOS_TRACE(VOS_MODULE_ID_HDD,VOS_TRACE_LEVEL_ERROR,
<<<<<<< HEAD
<<<<<<< HEAD
                  "%s: Aquire lock fail", __func__);
        return -EAGAIN;
    }    
=======
                  "%s: Acquire lock fail", __func__);
        return -EAGAIN;
    }
>>>>>>> d97af3b... add prima wlan driver
=======
                  "%s: Aquire lock fail", __func__);
        return -EAGAIN;
    }    
>>>>>>> 657b0e9... prima update
    if (TRUE == pHddCtx->tmInfo.tmAction.enterImps)
    {
        hddLog(VOS_TRACE_LEVEL_WARN,
               "%s: MAX TM Level Scan not allowed", __func__);
        mutex_unlock(&pHddCtx->tmInfo.tmOperationLock);
<<<<<<< HEAD
<<<<<<< HEAD
        return -EBUSY;                  
    }
    mutex_unlock(&pHddCtx->tmInfo.tmOperationLock);

=======
        return -EBUSY;
    }
    mutex_unlock(&pHddCtx->tmInfo.tmOperationLock);

    /* Check if scan is allowed at this point of time.
     */
    if (!hdd_isScanAllowed(pHddCtx))
    {
        hddLog(VOS_TRACE_LEVEL_ERROR, "%s: Scan not allowed", __func__);
        return -EBUSY;
    }

>>>>>>> d97af3b... add prima wlan driver
=======
        return -EBUSY;                  
    }
    mutex_unlock(&pHddCtx->tmInfo.tmOperationLock);

>>>>>>> 657b0e9... prima update
    vos_mem_zero( &scanRequest, sizeof(scanRequest));

    if (NULL != request)
    {
        hddLog(VOS_TRACE_LEVEL_INFO, "scan request for ssid = %d",
<<<<<<< HEAD
<<<<<<< HEAD
               (int)request->n_ssids);  
=======
               (int)request->n_ssids);
>>>>>>> d97af3b... add prima wlan driver
=======
               (int)request->n_ssids);  
>>>>>>> 657b0e9... prima update

        /* Even though supplicant doesn't provide any SSIDs, n_ssids is set to 1.
         * Becasue of this, driver is assuming that this is not wildcard scan and so
         * is not aging out the scan results.
         */
        if (request->ssids && '\0' == request->ssids->ssid[0])
        {
            request->n_ssids = 0;
        }

<<<<<<< HEAD
<<<<<<< HEAD
        if (0 < request->n_ssids)
=======
        if ((request->ssids) && (0 < request->n_ssids))
>>>>>>> d97af3b... add prima wlan driver
=======
        if (0 < request->n_ssids)
>>>>>>> 657b0e9... prima update
        {
            tCsrSSIDInfo *SsidInfo;
            int j;
            scanRequest.SSIDs.numOfSSIDs = request->n_ssids;
            /* Allocate num_ssid tCsrSSIDInfo structure */
            SsidInfo = scanRequest.SSIDs.SSIDList =
                      ( tCsrSSIDInfo *)vos_mem_malloc(
                              request->n_ssids*sizeof(tCsrSSIDInfo));

            if(NULL == scanRequest.SSIDs.SSIDList)
            {
                hddLog(VOS_TRACE_LEVEL_ERROR,
                               "memory alloc failed SSIDInfo buffer");
                return -ENOMEM;
            }

            /* copy all the ssid's and their length */
            for(j = 0; j < request->n_ssids; j++, SsidInfo++)
            {
                /* get the ssid length */
                SsidInfo->SSID.length = request->ssids[j].ssid_len;
                vos_mem_copy(SsidInfo->SSID.ssId, &request->ssids[j].ssid[0],
                             SsidInfo->SSID.length);
                SsidInfo->SSID.ssId[SsidInfo->SSID.length] = '\0';
                hddLog(VOS_TRACE_LEVEL_INFO_HIGH, "SSID number %d:  %s",
                                                   j, SsidInfo->SSID.ssId);
            }
            /* set the scan type to active */
            scanRequest.scanType = eSIR_ACTIVE_SCAN;
        }
        else if(WLAN_HDD_P2P_GO == pAdapter->device_mode)
        {
            /* set the scan type to active */
            scanRequest.scanType = eSIR_ACTIVE_SCAN;
        }
        else
        {
            /*Set the scan type to default type, in this case it is ACTIVE*/
            scanRequest.scanType = pScanInfo->scan_mode;
        }
<<<<<<< HEAD
<<<<<<< HEAD
        scanRequest.minChnTime = cfg_param->nActiveMinChnTime; 
=======
        scanRequest.minChnTime = cfg_param->nActiveMinChnTime;
>>>>>>> d97af3b... add prima wlan driver
=======
        scanRequest.minChnTime = cfg_param->nActiveMinChnTime; 
>>>>>>> 657b0e9... prima update
        scanRequest.maxChnTime = cfg_param->nActiveMaxChnTime;
    }
    else
    {
        /* set the scan type to active */
        scanRequest.scanType = eSIR_ACTIVE_SCAN;
        vos_mem_set( scanRequest.bssid, sizeof( tCsrBssid ), 0xff );

        /* set min and max channel time to zero */
        scanRequest.minChnTime = 0;
        scanRequest.maxChnTime = 0;
    }

    /* set BSSType to default type */
    scanRequest.BSSType = eCSR_BSS_TYPE_ANY;

    /*TODO: scan the requested channels only*/

    /*Right now scanning all the channels */
    if( request )
    {
        if( request->n_channels )
        {
            channelList = vos_mem_malloc( request->n_channels );
            if( NULL == channelList )
            {
                status = -ENOMEM;
                goto free_mem;
            }

            for( i = 0 ; i < request->n_channels ; i++ )
                channelList[i] = request->channels[i]->hw_value;
        }

        scanRequest.ChannelInfo.numOfChannels = request->n_channels;
        scanRequest.ChannelInfo.ChannelList = channelList;

        /* set requestType to full scan */
        scanRequest.requestType = eCSR_SCAN_REQUEST_FULL_SCAN;

<<<<<<< HEAD
<<<<<<< HEAD
=======
        /* Flush the scan results(only p2p beacons) for STA scan and P2P
         * search (Flush on both full  scan and social scan but not on single
         * channel scan).P2P  search happens on 3 social channels (1, 6, 11)
         */

        /* Supplicant does single channel scan after 8-way handshake
         * and in that case driver shoudnt flush scan results. If
         * driver flushes the scan results here and unfortunately if
         * the AP doesnt respond to our probe req then association
         * fails which is not desired
         */

        if( request->n_channels != WLAN_HDD_P2P_SINGLE_CHANNEL_SCAN )
        {
            sme_ScanFlushP2PResult( WLAN_HDD_GET_HAL_CTX(pAdapter),
                                                pAdapter->sessionId );
        }

>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
        if( request->ie_len )
        {
            /* save this for future association (join requires this) */
            memset( &pScanInfo->scanAddIE, 0, sizeof(pScanInfo->scanAddIE) );
            memcpy( pScanInfo->scanAddIE.addIEdata, request->ie, request->ie_len);
            pScanInfo->scanAddIE.length = request->ie_len;

            if((WLAN_HDD_INFRA_STATION == pAdapter->device_mode) ||
                (WLAN_HDD_P2P_CLIENT == pAdapter->device_mode) ||
                (WLAN_HDD_P2P_DEVICE == pAdapter->device_mode)
              )
            {
               pwextBuf->roamProfile.pAddIEScan = pScanInfo->scanAddIE.addIEdata;
               pwextBuf->roamProfile.nAddIEScanLength = pScanInfo->scanAddIE.length;
            }

            scanRequest.uIEFieldLen = pScanInfo->scanAddIE.length;
            scanRequest.pIEField = pScanInfo->scanAddIE.addIEdata;

<<<<<<< HEAD
<<<<<<< HEAD
#ifdef WLAN_FEATURE_P2P
=======
>>>>>>> d97af3b... add prima wlan driver
=======
#ifdef WLAN_FEATURE_P2P
>>>>>>> 657b0e9... prima update
            pP2pIe = wlan_hdd_get_p2p_ie_ptr((v_U8_t*)request->ie,
                                                       request->ie_len);
            if (pP2pIe != NULL)
            {
<<<<<<< HEAD
<<<<<<< HEAD
                /* no_cck will be set during p2p find to disable 11b rates */
                if(TRUE == request->no_cck)
                {
                    tANI_U8 sessionId = pAdapter->sessionId;
=======
#ifdef WLAN_FEATURE_P2P_DEBUG
                if (((globalP2PConnectionStatus == P2P_GO_NEG_COMPLETED) ||
                    (globalP2PConnectionStatus == P2P_GO_NEG_PROCESS)) &&
                    (WLAN_HDD_P2P_CLIENT == pAdapter->device_mode))
                {
                    globalP2PConnectionStatus = P2P_CLIENT_CONNECTING_STATE_1;
                    hddLog(VOS_TRACE_LEVEL_ERROR,"[P2P State] Changing state from "
                                    "Go nego completed to Connection is started");
                    hddLog(VOS_TRACE_LEVEL_ERROR,"[P2P]P2P Scanning is started "
                                   "for 8way Handshake");
                }
                else if((globalP2PConnectionStatus == P2P_CLIENT_DISCONNECTED_STATE) &&
                        (WLAN_HDD_P2P_CLIENT == pAdapter->device_mode))
                {
                    globalP2PConnectionStatus = P2P_CLIENT_CONNECTING_STATE_2;
                    hddLog(VOS_TRACE_LEVEL_ERROR,"[P2P State] Changing state from "
                                    "Disconnected state to Connection is started");
                    hddLog(VOS_TRACE_LEVEL_ERROR,"[P2P]P2P Scanning is started "
                                                        "for 4way Handshake");
                }
#endif

                /* no_cck will be set during p2p find to disable 11b rates */
                if(TRUE == request->no_cck)
                {
>>>>>>> d97af3b... add prima wlan driver
=======
                /* no_cck will be set during p2p find to disable 11b rates */
                if(TRUE == request->no_cck)
                {
                    tANI_U8 sessionId = pAdapter->sessionId;
>>>>>>> 657b0e9... prima update
                    hddLog(VOS_TRACE_LEVEL_INFO,
                           "%s: This is a P2P Search", __func__);
                    scanRequest.p2pSearch = 1;

<<<<<<< HEAD
<<<<<<< HEAD
                    /* Flush the scan results only for P2P search.
                       P2P search happens on 3 social channels (1, 6, 11) */
                    if( request->n_channels == WLAN_HDD_P2P_SOCIAL_CHANNELS )
                    {
                         pScanInfo->flushP2pScanResults = 1;
                         sme_ScanFlushP2PResult( WLAN_HDD_GET_HAL_CTX(pAdapter),
                                          sessionId );
=======
                    if( request->n_channels == WLAN_HDD_P2P_SOCIAL_CHANNELS )
                    {
>>>>>>> d97af3b... add prima wlan driver
=======
                    /* Flush the scan results only for P2P search.
                       P2P search happens on 3 social channels (1, 6, 11) */
                    if( request->n_channels == WLAN_HDD_P2P_SOCIAL_CHANNELS )
                    {
                         pScanInfo->flushP2pScanResults = 1;
                         sme_ScanFlushP2PResult( WLAN_HDD_GET_HAL_CTX(pAdapter),
                                          sessionId );
>>>>>>> 657b0e9... prima update
                         /* set requestType to P2P Discovery */
                         scanRequest.requestType = eCSR_SCAN_P2P_DISCOVERY;
                    }

                    /*
                       Skip Dfs Channel in case of P2P Search
                       if it is set in ini file
                    */
                    if(cfg_param->skipDfsChnlInP2pSearch)
                    {
                       scanRequest.skipDfsChnlInP2pSearch = 1;
                    }
                    else
                    {
                       scanRequest.skipDfsChnlInP2pSearch = 0;
                    }

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
        }
    }

    INIT_COMPLETION(pScanInfo->scan_req_completion_event);

<<<<<<< HEAD
<<<<<<< HEAD
    /* acquire the wakelock to avoid the apps suspend during the scan. To 
     * address the following issues.
     * 1) Disconnected scenario: we are not allowing the suspend as WLAN is not in 
     * BMPS/IMPS this result in android trying to suspend aggressively and backing off 
     * for long time, this result in apps running at full power for long time.
     * 2) Connected scenario: If we allow the suspend during the scan, RIVA will 
=======
    /* acquire the wakelock to avoid the apps suspend during the scan. To
=======
    /* acquire the wakelock to avoid the apps suspend during the scan. To 
>>>>>>> 657b0e9... prima update
     * address the following issues.
     * 1) Disconnected scenario: we are not allowing the suspend as WLAN is not in 
     * BMPS/IMPS this result in android trying to suspend aggressively and backing off 
     * for long time, this result in apps running at full power for long time.
<<<<<<< HEAD
     * 2) Connected scenario: If we allow the suspend during the scan, RIVA will
>>>>>>> d97af3b... add prima wlan driver
=======
     * 2) Connected scenario: If we allow the suspend during the scan, RIVA will 
>>>>>>> 657b0e9... prima update
     * be stuck in full power because of resume BMPS
     */
    hdd_prevent_suspend();

    status = sme_ScanRequest( WLAN_HDD_GET_HAL_CTX(pAdapter),
                              pAdapter->sessionId, &scanRequest, &scanId,
                              &hdd_cfg80211_scan_done_callback, dev );

    if (eHAL_STATUS_SUCCESS != status)
    {
        hddLog(VOS_TRACE_LEVEL_ERROR,
                "%s: sme_ScanRequest returned error %d", __func__, status);
        complete(&pScanInfo->scan_req_completion_event);
        if(eHAL_STATUS_RESOURCES == status)
        {
                hddLog(VOS_TRACE_LEVEL_INFO, "%s: HO is in progress.So defer the scan by informing busy",__func__);
                status = -EBUSY;
        } else {
                status = -EIO;
        }
        hdd_allow_suspend();
        goto free_mem;
    }

    pScanInfo->mScanPending = TRUE;
    pAdapter->request = request;
    pScanInfo->scanId = scanId;

    complete(&pScanInfo->scan_req_completion_event);

free_mem:
    if( scanRequest.SSIDs.SSIDList )
    {
        vos_mem_free(scanRequest.SSIDs.SSIDList);
    }

    if( channelList )
      vos_mem_free( channelList );

    EXIT();

    return status;
}

<<<<<<< HEAD
<<<<<<< HEAD
/*
 * FUNCTION: wlan_hdd_cfg80211_connect_start
 * This function is used to start the association process 
 */
int wlan_hdd_cfg80211_connect_start( hdd_adapter_t  *pAdapter, 
=======

void hdd_select_cbmode( hdd_adapter_t *pAdapter,v_U8_t operationChannel)
{
    v_U8_t iniDot11Mode =
               (WLAN_HDD_GET_CTX(pAdapter))->cfg_ini->dot11Mode;
    eHddDot11Mode   hddDot11Mode = iniDot11Mode;

    switch ( iniDot11Mode )
    {
       case eHDD_DOT11_MODE_AUTO:
       case eHDD_DOT11_MODE_11ac:
       case eHDD_DOT11_MODE_11ac_ONLY:
#ifdef WLAN_FEATURE_11AC
          hddDot11Mode = eHDD_DOT11_MODE_11ac;
#else
          hddDot11Mode = eHDD_DOT11_MODE_11n;
#endif
          break;
       case eHDD_DOT11_MODE_11n:
       case eHDD_DOT11_MODE_11n_ONLY:
          hddDot11Mode = eHDD_DOT11_MODE_11n;
          break;
       default:
          hddDot11Mode = iniDot11Mode;
          break;
    }
     /* This call decides required channel bonding mode */
    sme_SelectCBMode((WLAN_HDD_GET_CTX(pAdapter)->hHal),
                     hdd_cfg_xlate_to_csr_phy_mode(hddDot11Mode),
                     operationChannel);
}

=======
>>>>>>> 657b0e9... prima update
/*
 * FUNCTION: wlan_hdd_cfg80211_connect_start
 * This function is used to start the association process 
 */
<<<<<<< HEAD
int wlan_hdd_cfg80211_connect_start( hdd_adapter_t  *pAdapter,
>>>>>>> d97af3b... add prima wlan driver
=======
int wlan_hdd_cfg80211_connect_start( hdd_adapter_t  *pAdapter, 
>>>>>>> 657b0e9... prima update
        const u8 *ssid, size_t ssid_len, const u8 *bssid, u8 operatingChannel)
{
    int status = 0;
    hdd_wext_state_t *pWextState;
    v_U32_t roamId;
    tCsrRoamProfile *pRoamProfile;
    eMib_dot11DesiredBssType connectedBssType;
    eCsrAuthType RSNAuthType;

    ENTER();

    pWextState = WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter);
<<<<<<< HEAD
<<<<<<< HEAD
    
=======

>>>>>>> d97af3b... add prima wlan driver
=======
    
>>>>>>> 657b0e9... prima update
    if (SIR_MAC_MAX_SSID_LENGTH < ssid_len)
    {
        hddLog(VOS_TRACE_LEVEL_ERROR, "%s: wrong SSID len", __func__);
        return -EINVAL;
    }

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
        int ret = 0;
        hdd_station_ctx_t *pHddStaCtx;
        pHddStaCtx = WLAN_HDD_GET_STATION_CTX_PTR(pAdapter);
        hdd_connGetConnectedBssType(pHddStaCtx,&connectedBssType );

        if((eMib_dot11DesiredBssType_independent == connectedBssType) ||
           (eConnectionState_Associated == pHddStaCtx->conn_info.connState) ||
           (eConnectionState_IbssConnected == pHddStaCtx->conn_info.connState))
        {
            /* Issue disconnect to CSR */
            INIT_COMPLETION(pAdapter->disconnect_comp_var);
<<<<<<< HEAD
<<<<<<< HEAD
            if( eHAL_STATUS_SUCCESS == 
=======
            if( eHAL_STATUS_SUCCESS ==
>>>>>>> d97af3b... add prima wlan driver
=======
            if( eHAL_STATUS_SUCCESS == 
>>>>>>> 657b0e9... prima update
                  sme_RoamDisconnect( WLAN_HDD_GET_HAL_CTX(pAdapter),
                            pAdapter->sessionId,
                            eCSR_DISCONNECT_REASON_UNSPECIFIED ) )
            {
                ret = wait_for_completion_interruptible_timeout(
                             &pAdapter->disconnect_comp_var,
                             msecs_to_jiffies(WLAN_WAIT_TIME_DISCONNECT));
                if (0 == ret)
                {
                    VOS_ASSERT(0);
                }
            }
        }
        else if(eConnectionState_Disconnecting == pHddStaCtx->conn_info.connState)
        {
            ret = wait_for_completion_interruptible_timeout(
                         &pAdapter->disconnect_comp_var,
                         msecs_to_jiffies(WLAN_WAIT_TIME_DISCONNECT));
            if (0 == ret)
            {
                VOS_ASSERT(0);
            }
        }

<<<<<<< HEAD
<<<<<<< HEAD
        if (HDD_WMM_USER_MODE_NO_QOS == 
=======
        if (HDD_WMM_USER_MODE_NO_QOS ==
>>>>>>> d97af3b... add prima wlan driver
=======
        if (HDD_WMM_USER_MODE_NO_QOS == 
>>>>>>> 657b0e9... prima update
                        (WLAN_HDD_GET_CTX(pAdapter))->cfg_ini->WmmMode)
        {
            /*QoS not enabled in cfg file*/
            pRoamProfile->uapsd_mask = 0;
        }
        else
        {
            /*QoS enabled, update uapsd mask from cfg file*/
<<<<<<< HEAD
<<<<<<< HEAD
            pRoamProfile->uapsd_mask = 
=======
            pRoamProfile->uapsd_mask =
>>>>>>> d97af3b... add prima wlan driver
=======
            pRoamProfile->uapsd_mask = 
>>>>>>> 657b0e9... prima update
                     (WLAN_HDD_GET_CTX(pAdapter))->cfg_ini->UapsdMask;
        }

        pRoamProfile->SSIDs.numOfSSIDs = 1;
        pRoamProfile->SSIDs.SSIDList->SSID.length = ssid_len;
        vos_mem_zero(pRoamProfile->SSIDs.SSIDList->SSID.ssId,
<<<<<<< HEAD
<<<<<<< HEAD
                sizeof(pRoamProfile->SSIDs.SSIDList->SSID.ssId)); 
=======
                sizeof(pRoamProfile->SSIDs.SSIDList->SSID.ssId));
>>>>>>> d97af3b... add prima wlan driver
=======
                sizeof(pRoamProfile->SSIDs.SSIDList->SSID.ssId)); 
>>>>>>> 657b0e9... prima update
        vos_mem_copy((void *)(pRoamProfile->SSIDs.SSIDList->SSID.ssId),
                ssid, ssid_len);

        if (bssid)
        {
            pRoamProfile->BSSIDs.numOfBSSIDs = 1;
            vos_mem_copy((void *)(pRoamProfile->BSSIDs.bssid), bssid,
                    WNI_CFG_BSSID_LEN);
<<<<<<< HEAD
<<<<<<< HEAD
            /* Save BSSID in seperate variable as well, as RoamProfile 
               BSSID is getting zeroed out in the association process. And in 
=======
            /* Save BSSID in seperate variable as well, as RoamProfile
               BSSID is getting zeroed out in the association process. And in
>>>>>>> d97af3b... add prima wlan driver
=======
            /* Save BSSID in seperate variable as well, as RoamProfile 
               BSSID is getting zeroed out in the association process. And in 
>>>>>>> 657b0e9... prima update
               case of join failure we should send valid BSSID to supplicant
             */
            vos_mem_copy((void *)(pWextState->req_bssId), bssid,
                    WNI_CFG_BSSID_LEN);
        }
<<<<<<< HEAD
<<<<<<< HEAD

        if ((IW_AUTH_WPA_VERSION_WPA == pWextState->wpaVersion) ||
                (IW_AUTH_WPA_VERSION_WPA2 == pWextState->wpaVersion))
        { 
=======
        else
        {
            vos_mem_zero((void *)(pRoamProfile->BSSIDs.bssid),WNI_CFG_BSSID_LEN);
        }

        if ((IW_AUTH_WPA_VERSION_WPA == pWextState->wpaVersion) ||
                (IW_AUTH_WPA_VERSION_WPA2 == pWextState->wpaVersion))
        {
>>>>>>> d97af3b... add prima wlan driver
=======

        if ((IW_AUTH_WPA_VERSION_WPA == pWextState->wpaVersion) ||
                (IW_AUTH_WPA_VERSION_WPA2 == pWextState->wpaVersion))
        { 
>>>>>>> 657b0e9... prima update
            /*set gen ie*/
            hdd_SetGENIEToCsr(pAdapter, &RSNAuthType);
            /*set auth*/
            hdd_set_csr_auth_type(pAdapter, RSNAuthType);
        }
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
        else if ( (pWextState->roamProfile.AuthType.authType[0] == 
                    eCSR_AUTH_TYPE_OPEN_SYSTEM)
                && ((pWextState->roamProfile.EncryptionType.encryptionType[0] == 
                        eCSR_ENCRYPT_TYPE_WEP40_STATICKEY) 
                    || (pWextState->roamProfile.EncryptionType.encryptionType[0] == 
                        eCSR_ENCRYPT_TYPE_WEP104_STATICKEY))
                )
        {
            /*Android UI not having any option to configure the Authentication type to OPEN/SHARED;
             * The authentication type will be always eCSR_AUTH_TYPE_OPEN_SYSTEM when WEP is used
             * Use eCSR_AUTH_TYPE_AUTOSWITCH when WEP encryption used*/
            (WLAN_HDD_GET_STATION_CTX_PTR(pAdapter))->conn_info.authType = 
                                                     eCSR_AUTH_TYPE_AUTOSWITCH;
            pWextState->roamProfile.AuthType.authType[0] = 
                  (WLAN_HDD_GET_STATION_CTX_PTR(pAdapter))->conn_info.authType;
        }
<<<<<<< HEAD
#ifdef FEATURE_WLAN_WAPI
        if (pAdapter->wapi_info.nWapiMode)
        {
            hddLog(LOG1, "%s: Setting WAPI AUTH Type and Encryption Mode values", __FUNCTION__);
=======
#ifdef FEATURE_WLAN_WAPI
        if (pAdapter->wapi_info.nWapiMode)
        {
            hddLog(LOG1, "%s: Setting WAPI AUTH Type and Encryption Mode values", __func__);
>>>>>>> d97af3b... add prima wlan driver
=======
#ifdef FEATURE_WLAN_WAPI
        if (pAdapter->wapi_info.nWapiMode)
        {
            hddLog(LOG1, "%s: Setting WAPI AUTH Type and Encryption Mode values", __FUNCTION__);
>>>>>>> 657b0e9... prima update
            switch (pAdapter->wapi_info.wapiAuthMode)
            {
                case WAPI_AUTH_MODE_PSK:
                {
<<<<<<< HEAD
<<<<<<< HEAD
                    hddLog(LOG1, "%s: WAPI AUTH TYPE: PSK: %d", __FUNCTION__,
=======
                    hddLog(LOG1, "%s: WAPI AUTH TYPE: PSK: %d", __func__,
>>>>>>> d97af3b... add prima wlan driver
=======
                    hddLog(LOG1, "%s: WAPI AUTH TYPE: PSK: %d", __FUNCTION__,
>>>>>>> 657b0e9... prima update
                                                   pAdapter->wapi_info.wapiAuthMode);
                    pRoamProfile->AuthType.authType[0] = eCSR_AUTH_TYPE_WAPI_WAI_PSK;
                    break;
                }
                case WAPI_AUTH_MODE_CERT:
                {
<<<<<<< HEAD
<<<<<<< HEAD
                    hddLog(LOG1, "%s: WAPI AUTH TYPE: CERT: %d", __FUNCTION__,
=======
                    hddLog(LOG1, "%s: WAPI AUTH TYPE: CERT: %d", __func__,
>>>>>>> d97af3b... add prima wlan driver
=======
                    hddLog(LOG1, "%s: WAPI AUTH TYPE: CERT: %d", __FUNCTION__,
>>>>>>> 657b0e9... prima update
                                                    pAdapter->wapi_info.wapiAuthMode);
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
                pRoamProfile->AuthType.numEntries = 1;
                pRoamProfile->EncryptionType.numEntries = 1;
                pRoamProfile->EncryptionType.encryptionType[0] = eCSR_ENCRYPT_TYPE_WPI;
                pRoamProfile->mcEncryptionType.numEntries = 1;
                pRoamProfile->mcEncryptionType.encryptionType[0] = eCSR_ENCRYPT_TYPE_WPI;
            }
        }
#endif /* FEATURE_WLAN_WAPI */
<<<<<<< HEAD
<<<<<<< HEAD
=======
#ifdef WLAN_FEATURE_GTK_OFFLOAD
        /* Initializing gtkOffloadReqParams */
        if ((WLAN_HDD_INFRA_STATION == pAdapter->device_mode) ||
            (WLAN_HDD_P2P_CLIENT == pAdapter->device_mode))
        {
            memset(&pHddStaCtx->gtkOffloadReqParams, 0,
                  sizeof (tSirGtkOffloadParams));
            pHddStaCtx->gtkOffloadReqParams.ulFlags = GTK_OFFLOAD_DISABLE;
        }
#endif
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
        pRoamProfile->csrPersona = pAdapter->device_mode;

        if( operatingChannel )
        {
           pRoamProfile->ChannelInfo.ChannelList = &operatingChannel;
           pRoamProfile->ChannelInfo.numOfChannels = 1;
        }
<<<<<<< HEAD
<<<<<<< HEAD

        status = sme_RoamConnect( WLAN_HDD_GET_HAL_CTX(pAdapter), 
                            pAdapter->sessionId, pRoamProfile, &roamId);

        pRoamProfile->ChannelInfo.ChannelList = NULL;
        pRoamProfile->ChannelInfo.numOfChannels = 0;
=======
        else
        {
            pRoamProfile->ChannelInfo.ChannelList = NULL;
            pRoamProfile->ChannelInfo.numOfChannels = 0;
        }
        if ( (WLAN_HDD_IBSS == pAdapter->device_mode) && operatingChannel)
        {
            hdd_select_cbmode(pAdapter,operatingChannel);
        }
        /* change conn_state to connecting before sme_RoamConnect(), because sme_RoamConnect()
         * has a direct path to call hdd_smeRoamCallback(), which will change the conn_state
         * If direct path, conn_state will be accordingly changed to NotConnected or Associated
         * by either hdd_AssociationCompletionHandler() or hdd_DisConnectHandler() in sme_RoamCallback()
         * if sme_RomConnect is to be queued, Connecting state will remain until it is completed.
         */
        if (WLAN_HDD_INFRA_STATION == pAdapter->device_mode ||
            WLAN_HDD_P2P_CLIENT == pAdapter->device_mode)
            hdd_connSetConnectionState(WLAN_HDD_GET_STATION_CTX_PTR(pAdapter),
                                                 eConnectionState_Connecting);
=======
>>>>>>> 657b0e9... prima update

        status = sme_RoamConnect( WLAN_HDD_GET_HAL_CTX(pAdapter), 
                            pAdapter->sessionId, pRoamProfile, &roamId);

        pRoamProfile->ChannelInfo.ChannelList = NULL;
        pRoamProfile->ChannelInfo.numOfChannels = 0;
<<<<<<< HEAD

>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
    }
    else
    {
        hddLog(VOS_TRACE_LEVEL_ERROR, "%s: No valid Roam profile", __func__);
        return -EINVAL;
    }
<<<<<<< HEAD
<<<<<<< HEAD
    EXIT(); 
=======
    EXIT();
>>>>>>> d97af3b... add prima wlan driver
=======
    EXIT(); 
>>>>>>> 657b0e9... prima update
    return status;
}

/*
 * FUNCTION: wlan_hdd_set_cfg80211_auth_type
 * This function is used to set the authentication type (OPEN/SHARED).
 *
 */
static int wlan_hdd_cfg80211_set_auth_type(hdd_adapter_t *pAdapter,
        enum nl80211_auth_type auth_type)
{
<<<<<<< HEAD
<<<<<<< HEAD
    hdd_wext_state_t *pWextState = WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter);   
=======
    hdd_wext_state_t *pWextState = WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter);
>>>>>>> d97af3b... add prima wlan driver
=======
    hdd_wext_state_t *pWextState = WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter);   
>>>>>>> 657b0e9... prima update
    hdd_station_ctx_t *pHddStaCtx = WLAN_HDD_GET_STATION_CTX_PTR(pAdapter);

    ENTER();

    /*set authentication type*/
<<<<<<< HEAD
<<<<<<< HEAD
    switch (auth_type) 
    {
        case NL80211_AUTHTYPE_OPEN_SYSTEM:
        case NL80211_AUTHTYPE_AUTOMATIC:
            hddLog(VOS_TRACE_LEVEL_INFO, 
=======
    switch (auth_type)
=======
    switch (auth_type) 
>>>>>>> 657b0e9... prima update
    {
        case NL80211_AUTHTYPE_OPEN_SYSTEM:
<<<<<<< HEAD
#ifdef WLAN_FEATURE_VOWIFI_11R
        case NL80211_AUTHTYPE_FT:
#endif /* WLAN_FEATURE_VOWIFI_11R */
            hddLog(VOS_TRACE_LEVEL_INFO,
>>>>>>> d97af3b... add prima wlan driver
=======
        case NL80211_AUTHTYPE_AUTOMATIC:
            hddLog(VOS_TRACE_LEVEL_INFO, 
>>>>>>> 657b0e9... prima update
                    "%s: set authentication type to OPEN", __func__);
            pHddStaCtx->conn_info.authType = eCSR_AUTH_TYPE_OPEN_SYSTEM;
            break;

        case NL80211_AUTHTYPE_SHARED_KEY:
<<<<<<< HEAD
<<<<<<< HEAD
            hddLog(VOS_TRACE_LEVEL_INFO, 
=======
            hddLog(VOS_TRACE_LEVEL_INFO,
>>>>>>> d97af3b... add prima wlan driver
=======
            hddLog(VOS_TRACE_LEVEL_INFO, 
>>>>>>> 657b0e9... prima update
                    "%s: set authentication type to SHARED", __func__);
            pHddStaCtx->conn_info.authType = eCSR_AUTH_TYPE_SHARED_KEY;
            break;
#ifdef FEATURE_WLAN_CCX
        case NL80211_AUTHTYPE_NETWORK_EAP:
<<<<<<< HEAD
<<<<<<< HEAD
            hddLog(VOS_TRACE_LEVEL_INFO, 
=======
            hddLog(VOS_TRACE_LEVEL_INFO,
>>>>>>> d97af3b... add prima wlan driver
=======
            hddLog(VOS_TRACE_LEVEL_INFO, 
>>>>>>> 657b0e9... prima update
                            "%s: set authentication type to CCKM WPA", __func__);
            pHddStaCtx->conn_info.authType = eCSR_AUTH_TYPE_CCKM_WPA;//eCSR_AUTH_TYPE_CCKM_RSN needs to be handled as well if required.
            break;
#endif


        default:
<<<<<<< HEAD
<<<<<<< HEAD
            hddLog(VOS_TRACE_LEVEL_ERROR, 
                    "%s: Unsupported authentication type %d", __func__, 
=======
            hddLog(VOS_TRACE_LEVEL_ERROR,
                    "%s: Unsupported authentication type %d", __func__,
>>>>>>> d97af3b... add prima wlan driver
=======
            hddLog(VOS_TRACE_LEVEL_ERROR, 
                    "%s: Unsupported authentication type %d", __func__, 
>>>>>>> 657b0e9... prima update
                    auth_type);
            pHddStaCtx->conn_info.authType = eCSR_AUTH_TYPE_UNKNOWN;
            return -EINVAL;
    }

<<<<<<< HEAD
<<<<<<< HEAD
    pWextState->roamProfile.AuthType.authType[0] = 
=======
    pWextState->roamProfile.AuthType.authType[0] =
>>>>>>> d97af3b... add prima wlan driver
=======
    pWextState->roamProfile.AuthType.authType[0] = 
>>>>>>> 657b0e9... prima update
                                        pHddStaCtx->conn_info.authType;
    return 0;
}

/*
 * FUNCTION: wlan_hdd_set_akm_suite
 * This function is used to set the key mgmt type(PSK/8021x).
 *
 */
<<<<<<< HEAD
<<<<<<< HEAD
static int wlan_hdd_set_akm_suite( hdd_adapter_t *pAdapter, 
=======
static int wlan_hdd_set_akm_suite( hdd_adapter_t *pAdapter,
>>>>>>> d97af3b... add prima wlan driver
=======
static int wlan_hdd_set_akm_suite( hdd_adapter_t *pAdapter, 
>>>>>>> 657b0e9... prima update
                                   u32 key_mgmt
                                   )
{
    hdd_wext_state_t *pWextState = WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter);
    ENTER();
<<<<<<< HEAD
<<<<<<< HEAD
    
=======

>>>>>>> d97af3b... add prima wlan driver
=======
    
>>>>>>> 657b0e9... prima update
    /*set key mgmt type*/
    switch(key_mgmt)
    {
        case WLAN_AKM_SUITE_PSK:
<<<<<<< HEAD
<<<<<<< HEAD
            hddLog(VOS_TRACE_LEVEL_INFO, "%s: setting key mgmt type to PSK", 
=======
#ifdef WLAN_FEATURE_VOWIFI_11R
        case WLAN_AKM_SUITE_FT_PSK:
#endif
            hddLog(VOS_TRACE_LEVEL_INFO, "%s: setting key mgmt type to PSK",
>>>>>>> d97af3b... add prima wlan driver
=======
            hddLog(VOS_TRACE_LEVEL_INFO, "%s: setting key mgmt type to PSK", 
>>>>>>> 657b0e9... prima update
                    __func__);
            pWextState->authKeyMgmt |= IW_AUTH_KEY_MGMT_PSK;
            break;

        case WLAN_AKM_SUITE_8021X:
<<<<<<< HEAD
<<<<<<< HEAD
            hddLog(VOS_TRACE_LEVEL_INFO, "%s: setting key mgmt type to 8021x", 
=======
#ifdef WLAN_FEATURE_VOWIFI_11R
        case WLAN_AKM_SUITE_FT_8021X:
#endif
            hddLog(VOS_TRACE_LEVEL_INFO, "%s: setting key mgmt type to 8021x",
>>>>>>> d97af3b... add prima wlan driver
=======
            hddLog(VOS_TRACE_LEVEL_INFO, "%s: setting key mgmt type to 8021x", 
>>>>>>> 657b0e9... prima update
                    __func__);
            pWextState->authKeyMgmt |= IW_AUTH_KEY_MGMT_802_1X;
            break;
#ifdef FEATURE_WLAN_CCX
#define WLAN_AKM_SUITE_CCKM         0x00409600 /* Should be in ieee802_11_defs.h */
#define IW_AUTH_KEY_MGMT_CCKM       8  /* Should be in linux/wireless.h */
        case WLAN_AKM_SUITE_CCKM:
            hddLog(VOS_TRACE_LEVEL_INFO, "%s: setting key mgmt type to CCKM",
                            __func__);
            pWextState->authKeyMgmt |= IW_AUTH_KEY_MGMT_CCKM;
            break;
#endif

        default:
<<<<<<< HEAD
<<<<<<< HEAD
            hddLog(VOS_TRACE_LEVEL_ERROR, "%s: Unsupported key mgmt type %d", 
=======
            hddLog(VOS_TRACE_LEVEL_ERROR, "%s: Unsupported key mgmt type %d",
>>>>>>> d97af3b... add prima wlan driver
=======
            hddLog(VOS_TRACE_LEVEL_ERROR, "%s: Unsupported key mgmt type %d", 
>>>>>>> 657b0e9... prima update
                    __func__, key_mgmt);
            return -EINVAL;

    }
    return 0;
}

/*
 * FUNCTION: wlan_hdd_cfg80211_set_cipher
<<<<<<< HEAD
<<<<<<< HEAD
 * This function is used to set the encryption type 
 * (NONE/WEP40/WEP104/TKIP/CCMP).
 */
static int wlan_hdd_cfg80211_set_cipher( hdd_adapter_t *pAdapter, 
                                u32 cipher, 
=======
 * This function is used to set the encryption type
 * (NONE/WEP40/WEP104/TKIP/CCMP).
 */
static int wlan_hdd_cfg80211_set_cipher( hdd_adapter_t *pAdapter,
                                u32 cipher,
>>>>>>> d97af3b... add prima wlan driver
=======
 * This function is used to set the encryption type 
 * (NONE/WEP40/WEP104/TKIP/CCMP).
 */
static int wlan_hdd_cfg80211_set_cipher( hdd_adapter_t *pAdapter, 
                                u32 cipher, 
>>>>>>> 657b0e9... prima update
                                bool ucast
                                )
{
    eCsrEncryptionType encryptionType = eCSR_ENCRYPT_TYPE_NONE;
<<<<<<< HEAD
<<<<<<< HEAD
    hdd_wext_state_t *pWextState = WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter);   
=======
    hdd_wext_state_t *pWextState = WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter);
>>>>>>> d97af3b... add prima wlan driver
=======
    hdd_wext_state_t *pWextState = WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter);   
>>>>>>> 657b0e9... prima update
    hdd_station_ctx_t *pHddStaCtx = WLAN_HDD_GET_STATION_CTX_PTR(pAdapter);

    ENTER();

<<<<<<< HEAD
<<<<<<< HEAD
    if (!cipher) 
    {
        hddLog(VOS_TRACE_LEVEL_ERROR, "%s: received cipher %d - considering none", 
=======
    if (!cipher)
    {
        hddLog(VOS_TRACE_LEVEL_ERROR, "%s: received cipher %d - considering none",
>>>>>>> d97af3b... add prima wlan driver
=======
    if (!cipher) 
    {
        hddLog(VOS_TRACE_LEVEL_ERROR, "%s: received cipher %d - considering none", 
>>>>>>> 657b0e9... prima update
                __func__, cipher);
        encryptionType = eCSR_ENCRYPT_TYPE_NONE;
    }
    else
    {
<<<<<<< HEAD
<<<<<<< HEAD
    
        /*set encryption method*/
        switch (cipher) 
=======

        /*set encryption method*/
        switch (cipher)
>>>>>>> d97af3b... add prima wlan driver
=======
    
        /*set encryption method*/
        switch (cipher) 
>>>>>>> 657b0e9... prima update
        {
            case IW_AUTH_CIPHER_NONE:
                encryptionType = eCSR_ENCRYPT_TYPE_NONE;
                break;
<<<<<<< HEAD
<<<<<<< HEAD
    
            case WLAN_CIPHER_SUITE_WEP40:
                if ((IW_AUTH_KEY_MGMT_802_1X == pWextState->authKeyMgmt) && 
                    (eCSR_AUTH_TYPE_OPEN_SYSTEM == pHddStaCtx->conn_info.authType))
                    encryptionType = eCSR_ENCRYPT_TYPE_WEP40;
                else
                    encryptionType = eCSR_ENCRYPT_TYPE_WEP40_STATICKEY;
                break;
    
            case WLAN_CIPHER_SUITE_WEP104:
                if ((IW_AUTH_KEY_MGMT_802_1X == pWextState->authKeyMgmt) && 
                    (eCSR_AUTH_TYPE_OPEN_SYSTEM == pHddStaCtx->conn_info.authType))
                    encryptionType = eCSR_ENCRYPT_TYPE_WEP104;
                else
                    encryptionType = eCSR_ENCRYPT_TYPE_WEP104_STATICKEY;
                break;
    
            case WLAN_CIPHER_SUITE_TKIP:
                encryptionType = eCSR_ENCRYPT_TYPE_TKIP;
                break;
    
=======

=======
    
>>>>>>> 657b0e9... prima update
            case WLAN_CIPHER_SUITE_WEP40:
                if ((IW_AUTH_KEY_MGMT_802_1X == pWextState->authKeyMgmt) && 
                    (eCSR_AUTH_TYPE_OPEN_SYSTEM == pHddStaCtx->conn_info.authType))
                    encryptionType = eCSR_ENCRYPT_TYPE_WEP40;
                else
                    encryptionType = eCSR_ENCRYPT_TYPE_WEP40_STATICKEY;
                break;
    
            case WLAN_CIPHER_SUITE_WEP104:
                if ((IW_AUTH_KEY_MGMT_802_1X == pWextState->authKeyMgmt) && 
                    (eCSR_AUTH_TYPE_OPEN_SYSTEM == pHddStaCtx->conn_info.authType))
                    encryptionType = eCSR_ENCRYPT_TYPE_WEP104;
                else
                    encryptionType = eCSR_ENCRYPT_TYPE_WEP104_STATICKEY;
                break;
    
            case WLAN_CIPHER_SUITE_TKIP:
                encryptionType = eCSR_ENCRYPT_TYPE_TKIP;
                break;
<<<<<<< HEAD

>>>>>>> d97af3b... add prima wlan driver
=======
    
>>>>>>> 657b0e9... prima update
            case WLAN_CIPHER_SUITE_CCMP:
                encryptionType = eCSR_ENCRYPT_TYPE_AES;
                break;
#ifdef FEATURE_WLAN_WAPI
        case WLAN_CIPHER_SUITE_SMS4:
            encryptionType = eCSR_ENCRYPT_TYPE_WPI;
            break;
#endif

#ifdef FEATURE_WLAN_CCX
        case WLAN_CIPHER_SUITE_KRK:
            encryptionType = eCSR_ENCRYPT_TYPE_KRK;
            break;
#endif
            default:
<<<<<<< HEAD
<<<<<<< HEAD
                hddLog(VOS_TRACE_LEVEL_ERROR, "%s: Unsupported cipher type %d", 
=======
                hddLog(VOS_TRACE_LEVEL_ERROR, "%s: Unsupported cipher type %d",
>>>>>>> d97af3b... add prima wlan driver
=======
                hddLog(VOS_TRACE_LEVEL_ERROR, "%s: Unsupported cipher type %d", 
>>>>>>> 657b0e9... prima update
                        __func__, cipher);
                return -EOPNOTSUPP;
        }
    }

    if (ucast)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        hddLog(VOS_TRACE_LEVEL_INFO, "%s: setting unicast cipher type to %d", 
                __func__, encryptionType);
        pHddStaCtx->conn_info.ucEncryptionType            = encryptionType;
        pWextState->roamProfile.EncryptionType.numEntries = 1;
        pWextState->roamProfile.EncryptionType.encryptionType[0] = 
=======
        hddLog(VOS_TRACE_LEVEL_INFO, "%s: setting unicast cipher type to %d",
                __func__, encryptionType);
        pHddStaCtx->conn_info.ucEncryptionType            = encryptionType;
        pWextState->roamProfile.EncryptionType.numEntries = 1;
        pWextState->roamProfile.EncryptionType.encryptionType[0] =
>>>>>>> d97af3b... add prima wlan driver
=======
        hddLog(VOS_TRACE_LEVEL_INFO, "%s: setting unicast cipher type to %d", 
                __func__, encryptionType);
        pHddStaCtx->conn_info.ucEncryptionType            = encryptionType;
        pWextState->roamProfile.EncryptionType.numEntries = 1;
        pWextState->roamProfile.EncryptionType.encryptionType[0] = 
>>>>>>> 657b0e9... prima update
                                          encryptionType;
    }
    else
    {
<<<<<<< HEAD
<<<<<<< HEAD
        hddLog(VOS_TRACE_LEVEL_INFO, "%s: setting mcast cipher type to %d", 
=======
        hddLog(VOS_TRACE_LEVEL_INFO, "%s: setting mcast cipher type to %d",
>>>>>>> d97af3b... add prima wlan driver
=======
        hddLog(VOS_TRACE_LEVEL_INFO, "%s: setting mcast cipher type to %d", 
>>>>>>> 657b0e9... prima update
                __func__, encryptionType);
        pHddStaCtx->conn_info.mcEncryptionType                       = encryptionType;
        pWextState->roamProfile.mcEncryptionType.numEntries        = 1;
        pWextState->roamProfile.mcEncryptionType.encryptionType[0] = encryptionType;
    }

    return 0;
}


/*
 * FUNCTION: wlan_hdd_cfg80211_set_ie
 * This function is used to parse WPA/RSN IE's.
 */
<<<<<<< HEAD
<<<<<<< HEAD
int wlan_hdd_cfg80211_set_ie( hdd_adapter_t *pAdapter, 
                              u8 *ie, 
=======
int wlan_hdd_cfg80211_set_ie( hdd_adapter_t *pAdapter,
                              u8 *ie,
>>>>>>> d97af3b... add prima wlan driver
=======
int wlan_hdd_cfg80211_set_ie( hdd_adapter_t *pAdapter, 
                              u8 *ie, 
>>>>>>> 657b0e9... prima update
                              size_t ie_len
                              )
{
    hdd_wext_state_t *pWextState = WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter);
    u8 *genie = ie;
    v_U16_t remLen = ie_len;
#ifdef FEATURE_WLAN_WAPI
    v_U32_t akmsuite[MAX_NUM_AKM_SUITES];
    u16 *tmp;
    v_U16_t akmsuiteCount;
    int *akmlist;
#endif
    ENTER();

    /* clear previous assocAddIE */
    pWextState->assocAddIE.length = 0;
    pWextState->roamProfile.bWPSAssociation = VOS_FALSE;

    while (remLen >= 2)
    {
        v_U16_t eLen = 0;
        v_U8_t elementId;
        elementId = *genie++;
        eLen  = *genie++;
        remLen -= 2;
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 657b0e9... prima update
    
        hddLog(VOS_TRACE_LEVEL_INFO, "%s: IE[0x%X], LEN[%d]\n", 
            __func__, elementId, eLen);
         
        switch ( elementId ) 
        {
            case DOT11F_EID_WPA: 
                if ((2+4) > eLen) /* should have at least OUI */
                {
                    hddLog(VOS_TRACE_LEVEL_ERROR, 
                              "%s: Invalid WPA IE", __func__);
                    return -EINVAL;
                }
                else if (0 == memcmp(&genie[0], "\x00\x50\xf2\x04", 4)) 
                {
                    v_U16_t curAddIELen = pWextState->assocAddIE.length;
                    hddLog (VOS_TRACE_LEVEL_INFO, "%s Set WPS IE(len %d)", 
                            __func__, eLen + 2);
                    
<<<<<<< HEAD
                    if( SIR_MAC_MAX_IE_LENGTH < (pWextState->assocAddIE.length + eLen) )
                    {
                       hddLog(VOS_TRACE_LEVEL_FATAL, "Cannot accomadate assocAddIE. "
                                                      "Need bigger buffer space\n");
=======

        hddLog(VOS_TRACE_LEVEL_INFO, "%s: IE[0x%X], LEN[%d]\n",
            __func__, elementId, eLen);

        switch ( elementId )
        {
            case DOT11F_EID_WPA:
                if (4 > eLen) /* should have at least OUI which is 4 bytes so extra 2 bytes not needed */
                {
                    hddLog(VOS_TRACE_LEVEL_ERROR,
                              "%s: Invalid WPA IE", __func__);
                    return -EINVAL;
                }
                else if (0 == memcmp(&genie[0], "\x00\x50\xf2\x04", 4))
                {
                    v_U16_t curAddIELen = pWextState->assocAddIE.length;
                    hddLog (VOS_TRACE_LEVEL_INFO, "%s Set WPS IE(len %d)",
                            __func__, eLen + 2);

                    if( SIR_MAC_MAX_IE_LENGTH < (pWextState->assocAddIE.length + eLen) )
                    {
                       hddLog(VOS_TRACE_LEVEL_FATAL, "Cannot accommodate assocAddIE. "
                                                      "Need bigger buffer space");
>>>>>>> d97af3b... add prima wlan driver
=======
                    if( SIR_MAC_MAX_IE_LENGTH < (pWextState->assocAddIE.length + eLen) )
                    {
                       hddLog(VOS_TRACE_LEVEL_FATAL, "Cannot accomadate assocAddIE. "
                                                      "Need bigger buffer space\n");
>>>>>>> 657b0e9... prima update
                       VOS_ASSERT(0);
                       return -ENOMEM;
                    }
                    // WSC IE is saved to Additional IE ; it should be accumulated to handle WPS IE + P2P IE
                    memcpy( pWextState->assocAddIE.addIEdata + curAddIELen, genie - 2, eLen + 2);
                    pWextState->assocAddIE.length += eLen + 2;
<<<<<<< HEAD
<<<<<<< HEAD
                    
=======

>>>>>>> d97af3b... add prima wlan driver
=======
                    
>>>>>>> 657b0e9... prima update
                    pWextState->roamProfile.bWPSAssociation = VOS_TRUE;
                    pWextState->roamProfile.pAddIEAssoc = pWextState->assocAddIE.addIEdata;
                    pWextState->roamProfile.nAddIEAssocLength = pWextState->assocAddIE.length;
                }
<<<<<<< HEAD
<<<<<<< HEAD
                else if (0 == memcmp(&genie[0], "\x00\x50\xf2", 3)) 
                {  
=======
                else if (0 == memcmp(&genie[0], "\x00\x50\xf2", 3))
                {
>>>>>>> d97af3b... add prima wlan driver
=======
                else if (0 == memcmp(&genie[0], "\x00\x50\xf2", 3)) 
                {  
>>>>>>> 657b0e9... prima update
                    hddLog (VOS_TRACE_LEVEL_INFO, "%s Set WPA IE (len %d)",__func__, eLen + 2);
                    memset( pWextState->WPARSNIE, 0, MAX_WPA_RSN_IE_LEN );
                    memcpy( pWextState->WPARSNIE, genie - 2, (eLen + 2) /*ie_len*/);
                    pWextState->roamProfile.pWPAReqIE = pWextState->WPARSNIE;
                    pWextState->roamProfile.nWPAReqIELength = eLen + 2;//ie_len;
                }
<<<<<<< HEAD
<<<<<<< HEAD
#ifdef WLAN_FEATURE_P2P
                else if ( (0 == memcmp(&genie[0], P2P_OUI_TYPE, 
                                                         P2P_OUI_TYPE_SIZE)) 
=======
                else if ( (0 == memcmp(&genie[0], P2P_OUI_TYPE,
                                                         P2P_OUI_TYPE_SIZE))
>>>>>>> d97af3b... add prima wlan driver
=======
#ifdef WLAN_FEATURE_P2P
                else if ( (0 == memcmp(&genie[0], P2P_OUI_TYPE, 
                                                         P2P_OUI_TYPE_SIZE)) 
>>>>>>> 657b0e9... prima update
                        /*Consider P2P IE, only for P2P Client */
                         && (WLAN_HDD_P2P_CLIENT == pAdapter->device_mode) )
                {
                    v_U16_t curAddIELen = pWextState->assocAddIE.length;
<<<<<<< HEAD
<<<<<<< HEAD
                    hddLog (VOS_TRACE_LEVEL_INFO, "%s Set P2P IE(len %d)", 
                            __func__, eLen + 2);
                    
                    if( SIR_MAC_MAX_IE_LENGTH < (pWextState->assocAddIE.length + eLen) )
                    {
                       hddLog(VOS_TRACE_LEVEL_FATAL, "Cannot accomadate assocAddIE "
                                                      "Need bigger buffer space\n");
=======
                    hddLog (VOS_TRACE_LEVEL_INFO, "%s Set P2P IE(len %d)",
=======
                    hddLog (VOS_TRACE_LEVEL_INFO, "%s Set P2P IE(len %d)", 
>>>>>>> 657b0e9... prima update
                            __func__, eLen + 2);
                    
                    if( SIR_MAC_MAX_IE_LENGTH < (pWextState->assocAddIE.length + eLen) )
                    {
<<<<<<< HEAD
                       hddLog(VOS_TRACE_LEVEL_FATAL, "Cannot accommodate assocAddIE "
                                                      "Need bigger buffer space");
>>>>>>> d97af3b... add prima wlan driver
=======
                       hddLog(VOS_TRACE_LEVEL_FATAL, "Cannot accomadate assocAddIE "
                                                      "Need bigger buffer space\n");
>>>>>>> 657b0e9... prima update
                       VOS_ASSERT(0);
                       return -ENOMEM;
                    }
                    // P2P IE is saved to Additional IE ; it should be accumulated to handle WPS IE + P2P IE
                    memcpy( pWextState->assocAddIE.addIEdata + curAddIELen, genie - 2, eLen + 2);
                    pWextState->assocAddIE.length += eLen + 2;
<<<<<<< HEAD
<<<<<<< HEAD
                    
                    pWextState->roamProfile.pAddIEAssoc = pWextState->assocAddIE.addIEdata;
                    pWextState->roamProfile.nAddIEAssocLength = pWextState->assocAddIE.length;
                }
#endif
#ifdef WLAN_FEATURE_WFD
                else if ( (0 == memcmp(&genie[0], WFD_OUI_TYPE, 
                                                         WFD_OUI_TYPE_SIZE)) 
=======

=======
                    
>>>>>>> 657b0e9... prima update
                    pWextState->roamProfile.pAddIEAssoc = pWextState->assocAddIE.addIEdata;
                    pWextState->roamProfile.nAddIEAssocLength = pWextState->assocAddIE.length;
                }
#endif
#ifdef WLAN_FEATURE_WFD
<<<<<<< HEAD
                else if ( (0 == memcmp(&genie[0], WFD_OUI_TYPE,
                                                         WFD_OUI_TYPE_SIZE))
>>>>>>> d97af3b... add prima wlan driver
=======
                else if ( (0 == memcmp(&genie[0], WFD_OUI_TYPE, 
                                                         WFD_OUI_TYPE_SIZE)) 
>>>>>>> 657b0e9... prima update
                        /*Consider WFD IE, only for P2P Client */
                         && (WLAN_HDD_P2P_CLIENT == pAdapter->device_mode) )
                {
                    v_U16_t curAddIELen = pWextState->assocAddIE.length;
<<<<<<< HEAD
<<<<<<< HEAD
                    hddLog (VOS_TRACE_LEVEL_INFO, "%s Set WFD IE(len %d)", 
                            __func__, eLen + 2);
                    
                    if( SIR_MAC_MAX_IE_LENGTH < (pWextState->assocAddIE.length + eLen) )
                    {
                       hddLog(VOS_TRACE_LEVEL_FATAL, "Cannot accomadate assocAddIE "
                                                      "Need bigger buffer space\n");
=======
                    hddLog (VOS_TRACE_LEVEL_INFO, "%s Set WFD IE(len %d)",
=======
                    hddLog (VOS_TRACE_LEVEL_INFO, "%s Set WFD IE(len %d)", 
>>>>>>> 657b0e9... prima update
                            __func__, eLen + 2);
                    
                    if( SIR_MAC_MAX_IE_LENGTH < (pWextState->assocAddIE.length + eLen) )
                    {
<<<<<<< HEAD
                       hddLog(VOS_TRACE_LEVEL_FATAL, "Cannot accommodate assocAddIE "
                                                      "Need bigger buffer space");
>>>>>>> d97af3b... add prima wlan driver
=======
                       hddLog(VOS_TRACE_LEVEL_FATAL, "Cannot accomadate assocAddIE "
                                                      "Need bigger buffer space\n");
>>>>>>> 657b0e9... prima update
                       VOS_ASSERT(0);
                       return -ENOMEM;
                    }
                    // WFD IE is saved to Additional IE ; it should be accumulated to handle
                    // WPS IE + P2P IE + WFD IE
                    memcpy( pWextState->assocAddIE.addIEdata + curAddIELen, genie - 2, eLen + 2);
                    pWextState->assocAddIE.length += eLen + 2;
<<<<<<< HEAD
<<<<<<< HEAD
                    
=======

>>>>>>> d97af3b... add prima wlan driver
=======
                    
>>>>>>> 657b0e9... prima update
                    pWextState->roamProfile.pAddIEAssoc = pWextState->assocAddIE.addIEdata;
                    pWextState->roamProfile.nAddIEAssocLength = pWextState->assocAddIE.length;
                }
#endif
<<<<<<< HEAD
<<<<<<< HEAD
=======
                /* Appending HS 2.0 Indication Element in Assiciation Request */
                else if ( (0 == memcmp(&genie[0], HS20_OUI_TYPE,
                                       HS20_OUI_TYPE_SIZE)) )
                {
                    v_U16_t curAddIELen = pWextState->assocAddIE.length;
                    hddLog (VOS_TRACE_LEVEL_INFO, "%s Set HS20 IE(len %d)",
                            __func__, eLen + 2);

                    if( SIR_MAC_MAX_IE_LENGTH < (pWextState->assocAddIE.length + eLen) )
                    {
                        hddLog(VOS_TRACE_LEVEL_FATAL, "Cannot accommodate assocAddIE "
                               "Need bigger buffer space");
                        VOS_ASSERT(0);
                        return -ENOMEM;
                    }
                    memcpy( pWextState->assocAddIE.addIEdata + curAddIELen, genie - 2, eLen + 2);
                    pWextState->assocAddIE.length += eLen + 2;

                    pWextState->roamProfile.pAddIEAssoc = pWextState->assocAddIE.addIEdata;
                    pWextState->roamProfile.nAddIEAssocLength = pWextState->assocAddIE.length;
                }

                if (WLAN_HDD_IBSS == pAdapter->device_mode) {

                   /* populating as ADDIE in beacon frames */
                   if (ccmCfgSetStr(WLAN_HDD_GET_HAL_CTX(pAdapter),
                       WNI_CFG_PROBE_RSP_BCN_ADDNIE_DATA, genie - 2, eLen + 2,
                       NULL, eANI_BOOLEAN_FALSE)== eHAL_STATUS_SUCCESS)
                   {
                       if (ccmCfgSetInt(WLAN_HDD_GET_HAL_CTX(pAdapter),
                           WNI_CFG_PROBE_RSP_BCN_ADDNIE_FLAG, 1,NULL,
                           eANI_BOOLEAN_FALSE) == eHAL_STATUS_FAILURE)
                       {
                           hddLog(LOGE,
                                  "Coldn't pass "
                                  "WNI_CFG_PROBE_RSP_BCN_ADDNIE_FLAG to CCM");
                       }
                   }/* ccmCfgSetStr(,WNI_CFG_PROBE_RSP_BCN_ADDNIE_DATA, , )*/
                   else
                       hddLog(LOGE,
                              "Could not pass on "
                              "WNI_CFG_PROBE_RSP_BCN_ADDNIE_DATA to CCM");

                   /* IBSS mode doesn't contain params->proberesp_ies still
                    beaconIE's need to be populated in probe response frames */
                   if ( (NULL != (genie - 2)) && (0 != eLen + 2) )
                   {
                      u16 rem_probe_resp_ie_len = eLen + 2;
                      u8 probe_rsp_ie_len[3] = {0};
                      u8 counter = 0;

                      /* Check Probe Resp Length if it is greater then 255 then
                         Store Probe Rsp IEs into WNI_CFG_PROBE_RSP_ADDNIE_DATA1
                         & WNI_CFG_PROBE_RSP_ADDNIE_DATA2 CFG Variable As We are
                         not able Store More then 255 bytes into One Variable */

                      while ((rem_probe_resp_ie_len > 0) && (counter < 3))
                      {
                         if (rem_probe_resp_ie_len > MAX_CFG_STRING_LEN)
                         {
                            probe_rsp_ie_len[counter++] = MAX_CFG_STRING_LEN;
                            rem_probe_resp_ie_len -= MAX_CFG_STRING_LEN;
                         }
                         else
                         {
                            probe_rsp_ie_len[counter++] = rem_probe_resp_ie_len;
                            rem_probe_resp_ie_len = 0;
                         }
                      }

                      rem_probe_resp_ie_len = 0;

                      if (probe_rsp_ie_len[0] > 0)
                      {
                         if (ccmCfgSetStr(WLAN_HDD_GET_HAL_CTX(pAdapter),
                                          WNI_CFG_PROBE_RSP_ADDNIE_DATA1,
                                          (tANI_U8*)(genie - 2),
                                          probe_rsp_ie_len[0], NULL,
                                          eANI_BOOLEAN_FALSE)
                                          == eHAL_STATUS_FAILURE)
                         {
                            hddLog(LOGE,
                                   "Could not pass"
                                   "on WNI_CFG_PROBE_RSP_ADDNIE_DATA1 to CCM");
                         }
                         rem_probe_resp_ie_len += probe_rsp_ie_len[0];
                      }

                      if (probe_rsp_ie_len[1] > 0)
                      {
                         if (ccmCfgSetStr(WLAN_HDD_GET_HAL_CTX(pAdapter),
                                          WNI_CFG_PROBE_RSP_ADDNIE_DATA2,
                                          (tANI_U8*)(genie - (2 + rem_probe_resp_ie_len)),
                                          probe_rsp_ie_len[1], NULL,
                                          eANI_BOOLEAN_FALSE)
                                          == eHAL_STATUS_FAILURE)
                         {
                             hddLog(LOGE,
                                    "Could not pass"
                                    "on WNI_CFG_PROBE_RSP_ADDNIE_DATA2 to CCM");
                         }
                         rem_probe_resp_ie_len += probe_rsp_ie_len[1];
                      }

                      if (probe_rsp_ie_len[2] > 0)
                      {
                         if (ccmCfgSetStr(WLAN_HDD_GET_HAL_CTX(pAdapter),
                                          WNI_CFG_PROBE_RSP_ADDNIE_DATA3,
                                          (tANI_U8*)(genie - (2 + rem_probe_resp_ie_len)),
                                          probe_rsp_ie_len[2], NULL,
                                          eANI_BOOLEAN_FALSE)
                                          == eHAL_STATUS_FAILURE)
                          {
                            hddLog(LOGE,
                                   "Could not pass"
                                   "on WNI_CFG_PROBE_RSP_ADDNIE_DATA3 to CCM");
                          }
                          rem_probe_resp_ie_len += probe_rsp_ie_len[2];
                       }

                       if (ccmCfgSetInt(WLAN_HDD_GET_HAL_CTX(pAdapter),
                           WNI_CFG_PROBE_RSP_ADDNIE_FLAG, 1,NULL,
                           eANI_BOOLEAN_FALSE) == eHAL_STATUS_FAILURE)
                       {
                          hddLog(LOGE,
                                "Could not pass"
                                "on WNI_CFG_PROBE_RSP_ADDNIE_FLAG to CCM");
                       }
                   }
                   else
                   {
                      // Reset WNI_CFG_PROBE_RSP Flags
                      wlan_hdd_reset_prob_rspies(pAdapter);

                      hddLog(VOS_TRACE_LEVEL_INFO,
                            "%s: No Probe Response IE received in set beacon",
                            __func__);
                   }
                } /* end of if (WLAN_HDD_IBSS == pAdapter->device_mode) */
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
                break;
            case DOT11F_EID_RSN:
                hddLog (VOS_TRACE_LEVEL_INFO, "%s Set RSN IE(len %d)",__func__, eLen + 2);
                memset( pWextState->WPARSNIE, 0, MAX_WPA_RSN_IE_LEN );
                memcpy( pWextState->WPARSNIE, genie - 2, (eLen + 2)/*ie_len*/);
                pWextState->roamProfile.pRSNReqIE = pWextState->WPARSNIE;
                pWextState->roamProfile.nRSNReqIELength = eLen + 2; //ie_len;
                break;
<<<<<<< HEAD
<<<<<<< HEAD
=======
                /* Appending Extended Capabilities with Interworking bit set in Assoc Req */
            case DOT11F_EID_EXTCAP:
                {
                    v_U16_t curAddIELen = pWextState->assocAddIE.length;
                    hddLog (VOS_TRACE_LEVEL_INFO, "%s Set Extended CAPS IE(len %d)",
                            __func__, eLen + 2);

                    if( SIR_MAC_MAX_IE_LENGTH < (pWextState->assocAddIE.length + eLen) )
                    {
                       hddLog(VOS_TRACE_LEVEL_FATAL, "Cannot accommodate assocAddIE "
                                                      "Need bigger buffer space");
                       VOS_ASSERT(0);
                       return -ENOMEM;
                    }
                    memcpy( pWextState->assocAddIE.addIEdata + curAddIELen, genie - 2, eLen + 2);
                    pWextState->assocAddIE.length += eLen + 2;

                    pWextState->roamProfile.pAddIEAssoc = pWextState->assocAddIE.addIEdata;
                    pWextState->roamProfile.nAddIEAssocLength = pWextState->assocAddIE.length;
                    break;
                }
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
#ifdef FEATURE_WLAN_WAPI
            case WLAN_EID_WAPI:
                pAdapter->wapi_info.nWapiMode = 1;   //Setting WAPI Mode to ON=1
                hddLog(VOS_TRACE_LEVEL_INFO,"WAPI MODE IS  %lu \n",
                                          pAdapter->wapi_info.nWapiMode);
                tmp = (u16 *)ie;
<<<<<<< HEAD
<<<<<<< HEAD
                tmp = tmp + 2; // Skip element Id and Len, Version        
=======
                tmp = tmp + 2; // Skip element Id and Len, Version
>>>>>>> d97af3b... add prima wlan driver
=======
                tmp = tmp + 2; // Skip element Id and Len, Version        
>>>>>>> 657b0e9... prima update
                akmsuiteCount = WPA_GET_LE16(tmp);
                tmp = tmp + 1;
                akmlist = (int *)(tmp);
                if(akmsuiteCount <= MAX_NUM_AKM_SUITES)
                {
                    memcpy(akmsuite, akmlist, (4*akmsuiteCount));
                }
                else
                {
                    hddLog(VOS_TRACE_LEVEL_FATAL, "Invalid akmSuite count\n");
                    VOS_ASSERT(0);
                    return -EINVAL;
                }

                if (WAPI_PSK_AKM_SUITE == akmsuite[0])
                {
                    hddLog(VOS_TRACE_LEVEL_INFO, "%s: WAPI AUTH MODE SET TO PSK",
<<<<<<< HEAD
<<<<<<< HEAD
                                                            __FUNCTION__);
                    pAdapter->wapi_info.wapiAuthMode = WAPI_AUTH_MODE_PSK;
                }    
                if (WAPI_CERT_AKM_SUITE == akmsuite[0])
                {     
                    hddLog(VOS_TRACE_LEVEL_INFO, "%s: WAPI AUTH MODE SET TO CERTIFICATE",
                                                             __FUNCTION__);
=======
                                                            __func__);
=======
                                                            __FUNCTION__);
>>>>>>> 657b0e9... prima update
                    pAdapter->wapi_info.wapiAuthMode = WAPI_AUTH_MODE_PSK;
                }    
                if (WAPI_CERT_AKM_SUITE == akmsuite[0])
                {     
                    hddLog(VOS_TRACE_LEVEL_INFO, "%s: WAPI AUTH MODE SET TO CERTIFICATE",
<<<<<<< HEAD
                                                             __func__);
>>>>>>> d97af3b... add prima wlan driver
=======
                                                             __FUNCTION__);
>>>>>>> 657b0e9... prima update
                    pAdapter->wapi_info.wapiAuthMode = WAPI_AUTH_MODE_CERT;
                }
                break;
#endif
            default:
<<<<<<< HEAD
<<<<<<< HEAD
                hddLog (VOS_TRACE_LEVEL_ERROR, 
                        "%s Set UNKNOWN IE %X", __func__, elementId);
                return 0;
=======
                hddLog (VOS_TRACE_LEVEL_ERROR,
                        "%s Set UNKNOWN IE %X", __func__, elementId);
                /* when Unknown IE is received we should break and continue
                 * to the next IE in the buffer instead we were returning
                 * so changing this to break */
                break;
>>>>>>> d97af3b... add prima wlan driver
=======
                hddLog (VOS_TRACE_LEVEL_ERROR, 
                        "%s Set UNKNOWN IE %X", __func__, elementId);
                return 0;
>>>>>>> 657b0e9... prima update
        }
        genie += eLen;
        remLen -= eLen;
    }
    EXIT();
    return 0;
}

/*
<<<<<<< HEAD
<<<<<<< HEAD
 * FUNCTION: wlan_hdd_cfg80211_set_privacy
 * This function is used to initialize the security 
 * parameters during connect operation.
 */
int wlan_hdd_cfg80211_set_privacy( hdd_adapter_t *pAdapter, 
=======
 * FUNCTION: hdd_isWPAIEPresent
 * Parse the received IE to find the WPA IE
 *
 */
static bool hdd_isWPAIEPresent(u8 *ie, u8 ie_len)
{
    v_U8_t eLen = 0;
    v_U16_t remLen = ie_len;
    v_U8_t elementId = 0;

    while (remLen >= 2)
    {
        elementId = *ie++;
        eLen  = *ie++;
        remLen -= 2;
        if (eLen > remLen)
        {
            hddLog(VOS_TRACE_LEVEL_ERROR,
                "%s: IE length is wrong %d", __func__, eLen);
            return FALSE;
        }
        if ((elementId == DOT11F_EID_WPA) && (remLen > 5))
        {
          /* OUI - 0x00 0X50 0XF2
             WPA Information Element - 0x01
             WPA version - 0x01*/
            if (0 == memcmp(&ie[0], "\x00\x50\xf2\x01\x01", 5))
               return TRUE;
        }
        ie += eLen;
        remLen -= eLen;
    }
    return FALSE;
}

/*
=======
>>>>>>> 657b0e9... prima update
 * FUNCTION: wlan_hdd_cfg80211_set_privacy
 * This function is used to initialize the security 
 * parameters during connect operation.
 */
<<<<<<< HEAD
int wlan_hdd_cfg80211_set_privacy( hdd_adapter_t *pAdapter,
>>>>>>> d97af3b... add prima wlan driver
=======
int wlan_hdd_cfg80211_set_privacy( hdd_adapter_t *pAdapter, 
>>>>>>> 657b0e9... prima update
                                   struct cfg80211_connect_params *req
                                   )
{
    int status = 0;
<<<<<<< HEAD
<<<<<<< HEAD
    hdd_wext_state_t *pWextState = WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter);   
=======
    hdd_wext_state_t *pWextState = WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter);
>>>>>>> d97af3b... add prima wlan driver
=======
    hdd_wext_state_t *pWextState = WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter);   
>>>>>>> 657b0e9... prima update
    ENTER();

    /*set wpa version*/
    pWextState->wpaVersion = IW_AUTH_WPA_VERSION_DISABLED;

<<<<<<< HEAD
<<<<<<< HEAD
    if (req->crypto.wpa_versions) 
    {
        if ( (NL80211_WPA_VERSION_1 == req->crypto.wpa_versions)
            && ( (req->ie_len) 
           && (0 == memcmp( &req->ie[2], "\x00\x50\xf2",3) ) ) ) 
           // Make sure that it is including a WPA IE.
           /* Currently NL is putting WPA version 1 even for open, 
            * since p2p ie is also put in same buffer.
            * */
=======
    if (req->crypto.wpa_versions)
    {
        if (NL80211_WPA_VERSION_1 == req->crypto.wpa_versions)
>>>>>>> d97af3b... add prima wlan driver
=======
    if (req->crypto.wpa_versions) 
    {
        if ( (NL80211_WPA_VERSION_1 == req->crypto.wpa_versions)
            && ( (req->ie_len) 
           && (0 == memcmp( &req->ie[2], "\x00\x50\xf2",3) ) ) ) 
           // Make sure that it is including a WPA IE.
           /* Currently NL is putting WPA version 1 even for open, 
            * since p2p ie is also put in same buffer.
            * */
>>>>>>> 657b0e9... prima update
        {
            pWextState->wpaVersion = IW_AUTH_WPA_VERSION_WPA;
        }
        else if (NL80211_WPA_VERSION_2 == req->crypto.wpa_versions)
        {
            pWextState->wpaVersion = IW_AUTH_WPA_VERSION_WPA2;
        }
    }
<<<<<<< HEAD
<<<<<<< HEAD
    
    hddLog(VOS_TRACE_LEVEL_INFO, "%s: set wpa version to %d", __func__, 
=======

    hddLog(VOS_TRACE_LEVEL_INFO, "%s: set wpa version to %d", __func__,
>>>>>>> d97af3b... add prima wlan driver
=======
    
    hddLog(VOS_TRACE_LEVEL_INFO, "%s: set wpa version to %d", __func__, 
>>>>>>> 657b0e9... prima update
            pWextState->wpaVersion);

    /*set authentication type*/
    status = wlan_hdd_cfg80211_set_auth_type(pAdapter, req->auth_type);

    if (0 > status)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        hddLog(VOS_TRACE_LEVEL_ERROR, 
=======
        hddLog(VOS_TRACE_LEVEL_ERROR,
>>>>>>> d97af3b... add prima wlan driver
=======
        hddLog(VOS_TRACE_LEVEL_ERROR, 
>>>>>>> 657b0e9... prima update
                "%s: failed to set authentication type ", __func__);
        return status;
    }

    /*set key mgmt type*/
    if (req->crypto.n_akm_suites)
    {
        status = wlan_hdd_set_akm_suite(pAdapter, req->crypto.akm_suites[0]);
        if (0 > status)
        {
<<<<<<< HEAD
<<<<<<< HEAD
            hddLog(VOS_TRACE_LEVEL_ERROR, "%s: failed to set akm suite", 
=======
            hddLog(VOS_TRACE_LEVEL_ERROR, "%s: failed to set akm suite",
>>>>>>> d97af3b... add prima wlan driver
=======
            hddLog(VOS_TRACE_LEVEL_ERROR, "%s: failed to set akm suite", 
>>>>>>> 657b0e9... prima update
                    __func__);
            return status;
        }
    }

    /*set pairwise cipher type*/
    if (req->crypto.n_ciphers_pairwise)
    {
        status = wlan_hdd_cfg80211_set_cipher(pAdapter,
                                      req->crypto.ciphers_pairwise[0], true);
        if (0 > status)
        {
<<<<<<< HEAD
<<<<<<< HEAD
            hddLog(VOS_TRACE_LEVEL_ERROR, 
=======
            hddLog(VOS_TRACE_LEVEL_ERROR,
>>>>>>> d97af3b... add prima wlan driver
=======
            hddLog(VOS_TRACE_LEVEL_ERROR, 
>>>>>>> 657b0e9... prima update
                    "%s: failed to set unicast cipher type", __func__);
            return status;
        }
    }
    else
    {
        /*Reset previous cipher suite to none*/
        status = wlan_hdd_cfg80211_set_cipher(pAdapter, 0, true);
        if (0 > status)
        {
<<<<<<< HEAD
<<<<<<< HEAD
            hddLog(VOS_TRACE_LEVEL_ERROR, 
=======
            hddLog(VOS_TRACE_LEVEL_ERROR,
>>>>>>> d97af3b... add prima wlan driver
=======
            hddLog(VOS_TRACE_LEVEL_ERROR, 
>>>>>>> 657b0e9... prima update
                    "%s: failed to set unicast cipher type", __func__);
            return status;
        }
    }

    /*set group cipher type*/
    status = wlan_hdd_cfg80211_set_cipher(pAdapter, req->crypto.cipher_group,
                                                                       false);

    if (0 > status)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        hddLog(VOS_TRACE_LEVEL_ERROR, "%s: failed to set mcast cipher type", 
=======
        hddLog(VOS_TRACE_LEVEL_ERROR, "%s: failed to set mcast cipher type",
>>>>>>> d97af3b... add prima wlan driver
=======
        hddLog(VOS_TRACE_LEVEL_ERROR, "%s: failed to set mcast cipher type", 
>>>>>>> 657b0e9... prima update
                __func__);
        return status;
    }

<<<<<<< HEAD
<<<<<<< HEAD
=======
#ifdef WLAN_FEATURE_11W
    pWextState->roamProfile.MFPEnabled = (req->mfp == NL80211_MFP_REQUIRED);
#endif

>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
    /*parse WPA/RSN IE, and set the correspoing fileds in Roam profile*/
    if (req->ie_len)
    {
        status = wlan_hdd_cfg80211_set_ie(pAdapter, req->ie, req->ie_len);
        if ( 0 > status)
        {
<<<<<<< HEAD
<<<<<<< HEAD
            hddLog(VOS_TRACE_LEVEL_ERROR, "%s: failed to parse the WPA/RSN IE", 
=======
            hddLog(VOS_TRACE_LEVEL_ERROR, "%s: failed to parse the WPA/RSN IE",
>>>>>>> d97af3b... add prima wlan driver
=======
            hddLog(VOS_TRACE_LEVEL_ERROR, "%s: failed to parse the WPA/RSN IE", 
>>>>>>> 657b0e9... prima update
                    __func__);
            return status;
        }
    }

    /*incase of WEP set default key information*/
<<<<<<< HEAD
<<<<<<< HEAD
    if (req->key && req->key_len) 
=======
    if (req->key && req->key_len)
>>>>>>> d97af3b... add prima wlan driver
=======
    if (req->key && req->key_len) 
>>>>>>> 657b0e9... prima update
    {
        if ( (WLAN_CIPHER_SUITE_WEP40 == req->crypto.ciphers_pairwise[0])
                || (WLAN_CIPHER_SUITE_WEP104 == req->crypto.ciphers_pairwise[0])
          )
        {
<<<<<<< HEAD
<<<<<<< HEAD
            if ( IW_AUTH_KEY_MGMT_802_1X 
                    == (pWextState->authKeyMgmt & IW_AUTH_KEY_MGMT_802_1X  ))
            {
                hddLog(VOS_TRACE_LEVEL_ERROR, "%s: Dynamic WEP not supported", 
=======
            if ( IW_AUTH_KEY_MGMT_802_1X
                    == (pWextState->authKeyMgmt & IW_AUTH_KEY_MGMT_802_1X  ))
            {
                hddLog(VOS_TRACE_LEVEL_ERROR, "%s: Dynamic WEP not supported",
>>>>>>> d97af3b... add prima wlan driver
=======
            if ( IW_AUTH_KEY_MGMT_802_1X 
                    == (pWextState->authKeyMgmt & IW_AUTH_KEY_MGMT_802_1X  ))
            {
                hddLog(VOS_TRACE_LEVEL_ERROR, "%s: Dynamic WEP not supported", 
>>>>>>> 657b0e9... prima update
                        __func__);
                return -EOPNOTSUPP;
            }
            else
            {
                u8 key_len = req->key_len;
                u8 key_idx = req->key_idx;

<<<<<<< HEAD
<<<<<<< HEAD
                if ((eCSR_SECURITY_WEP_KEYSIZE_MAX_BYTES >= key_len) 
                        && (CSR_MAX_NUM_KEY > key_idx)
                  )
                {
                    hddLog(VOS_TRACE_LEVEL_INFO, 
                     "%s: setting default wep key, key_idx = %hu key_len %hu", 
                            __func__, key_idx, key_len);
                    vos_mem_copy(
                       &pWextState->roamProfile.Keys.KeyMaterial[key_idx][0], 
                                  req->key, key_len);
                    pWextState->roamProfile.Keys.KeyLength[key_idx] = 
=======
                if ((eCSR_SECURITY_WEP_KEYSIZE_MAX_BYTES >= key_len)
=======
                if ((eCSR_SECURITY_WEP_KEYSIZE_MAX_BYTES >= key_len) 
>>>>>>> 657b0e9... prima update
                        && (CSR_MAX_NUM_KEY > key_idx)
                  )
                {
                    hddLog(VOS_TRACE_LEVEL_INFO, 
                     "%s: setting default wep key, key_idx = %hu key_len %hu", 
                            __func__, key_idx, key_len);
                    vos_mem_copy(
                       &pWextState->roamProfile.Keys.KeyMaterial[key_idx][0], 
                                  req->key, key_len);
<<<<<<< HEAD
                    pWextState->roamProfile.Keys.KeyLength[key_idx] =
>>>>>>> d97af3b... add prima wlan driver
=======
                    pWextState->roamProfile.Keys.KeyLength[key_idx] = 
>>>>>>> 657b0e9... prima update
                                                               (u8)key_len;
                    pWextState->roamProfile.Keys.defaultIndex = (u8)key_idx;
                }
            }
        }
    }

    return status;
}

/*
 * FUNCTION: wlan_hdd_cfg80211_set_privacy
<<<<<<< HEAD
<<<<<<< HEAD
 * This function is used to initialize the security 
 * parameters during connect operation.
 */
static int wlan_hdd_cfg80211_connect( struct wiphy *wiphy, 
=======
 * This function is used to initialize the security
 * parameters during connect operation.
 */
static int wlan_hdd_cfg80211_connect( struct wiphy *wiphy,
>>>>>>> d97af3b... add prima wlan driver
=======
 * This function is used to initialize the security 
 * parameters during connect operation.
 */
static int wlan_hdd_cfg80211_connect( struct wiphy *wiphy, 
>>>>>>> 657b0e9... prima update
                                      struct net_device *ndev,
                                      struct cfg80211_connect_params *req
                                      )
{
<<<<<<< HEAD
<<<<<<< HEAD
    int status = 0;
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR( ndev ); 
=======
    int status;
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR( ndev );
>>>>>>> d97af3b... add prima wlan driver
=======
    int status = 0;
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR( ndev ); 
>>>>>>> 657b0e9... prima update
    VOS_STATUS exitbmpsStatus = VOS_STATUS_E_INVAL;
    hdd_context_t *pHddCtx = NULL;

    ENTER();

<<<<<<< HEAD
<<<<<<< HEAD
    hddLog(VOS_TRACE_LEVEL_INFO, 
             "%s: device_mode = %d\n",__func__,pAdapter->device_mode);

    if ( (WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress )
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                "%s:LOGP in Progress. Ignore!!!", __func__);
        return -EAGAIN;
=======
    hddLog(VOS_TRACE_LEVEL_INFO,
=======
    hddLog(VOS_TRACE_LEVEL_INFO, 
>>>>>>> 657b0e9... prima update
             "%s: device_mode = %d\n",__func__,pAdapter->device_mode);

    if ( (WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress )
    {
<<<<<<< HEAD
        VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                   "%s: HDD context is not valid", __func__);
        return status;
>>>>>>> d97af3b... add prima wlan driver
=======
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                "%s:LOGP in Progress. Ignore!!!", __func__);
        return -EAGAIN;
>>>>>>> 657b0e9... prima update
    }

#ifdef WLAN_BTAMP_FEATURE
    //Infra connect not supported when AMP traffic is on.
<<<<<<< HEAD
<<<<<<< HEAD
    if( VOS_TRUE == WLANBAP_AmpSessionOn() ) 
    {
        hddLog(VOS_TRACE_LEVEL_ERROR, 
                "%s: No connection when AMP is on", __func__);
        return -1;
    }
#endif
    /*initialise security parameters*/
    status = wlan_hdd_cfg80211_set_privacy(pAdapter, req); 

    if ( 0 > status)
    {
        hddLog(VOS_TRACE_LEVEL_ERROR, "%s: failed to set security params", 
=======
    if( VOS_TRUE == WLANBAP_AmpSessionOn() )
=======
    if( VOS_TRUE == WLANBAP_AmpSessionOn() ) 
>>>>>>> 657b0e9... prima update
    {
        hddLog(VOS_TRACE_LEVEL_ERROR, 
                "%s: No connection when AMP is on", __func__);
        return -1;
    }
#endif
    /*initialise security parameters*/
    status = wlan_hdd_cfg80211_set_privacy(pAdapter, req); 

    if ( 0 > status)
    {
<<<<<<< HEAD
        hddLog(VOS_TRACE_LEVEL_ERROR, "%s: failed to set security params",
>>>>>>> d97af3b... add prima wlan driver
=======
        hddLog(VOS_TRACE_LEVEL_ERROR, "%s: failed to set security params", 
>>>>>>> 657b0e9... prima update
                __func__);
        return status;
    }

    //If Device Mode is Station Concurrent Sessions Exit BMps
<<<<<<< HEAD
<<<<<<< HEAD
    //P2P Mode will be taken care in Open/close adaptor
    if((WLAN_HDD_INFRA_STATION == pAdapter->device_mode) &&
        (vos_concurrent_sessions_running()))
    {
        v_CONTEXT_t pVosContext = vos_get_global_context( VOS_MODULE_ID_HDD, NULL );

        if (NULL != pVosContext)
        {
            pHddCtx = vos_get_context( VOS_MODULE_ID_HDD, pVosContext);
            if(NULL != pHddCtx)
            {
               exitbmpsStatus = hdd_disable_bmps_imps(pHddCtx, WLAN_HDD_INFRA_STATION);
            }
        }
=======
    //P2P Mode will be taken care in Open/close adapter
    if((WLAN_HDD_INFRA_STATION == pAdapter->device_mode) &&
        (vos_concurrent_sessions_running()))
    {
        exitbmpsStatus = hdd_disable_bmps_imps(pHddCtx, WLAN_HDD_INFRA_STATION);
>>>>>>> d97af3b... add prima wlan driver
=======
    //P2P Mode will be taken care in Open/close adaptor
    if((WLAN_HDD_INFRA_STATION == pAdapter->device_mode) &&
        (vos_concurrent_sessions_running()))
    {
        v_CONTEXT_t pVosContext = vos_get_global_context( VOS_MODULE_ID_HDD, NULL );

        if (NULL != pVosContext)
        {
            pHddCtx = vos_get_context( VOS_MODULE_ID_HDD, pVosContext);
            if(NULL != pHddCtx)
            {
               exitbmpsStatus = hdd_disable_bmps_imps(pHddCtx, WLAN_HDD_INFRA_STATION);
            }
        }
>>>>>>> 657b0e9... prima update
    }

    if ( req->channel )
    {
        status = wlan_hdd_cfg80211_connect_start(pAdapter, req->ssid,
                                                  req->ssid_len, req->bssid,
                                                  req->channel->hw_value);
    }
    else
    {
        status = wlan_hdd_cfg80211_connect_start(pAdapter, req->ssid,
<<<<<<< HEAD
<<<<<<< HEAD
                                                  req->ssid_len, req->bssid,
                                                  0);
=======
                                                  req->ssid_len, req->bssid, 0);
>>>>>>> d97af3b... add prima wlan driver
=======
                                                  req->ssid_len, req->bssid,
                                                  0);
>>>>>>> 657b0e9... prima update
    }

    if (0 > status)
    {
        //ReEnable BMPS if disabled
        if((VOS_STATUS_SUCCESS == exitbmpsStatus) &&
            (NULL != pHddCtx))
        {
<<<<<<< HEAD
<<<<<<< HEAD
=======
            if (pHddCtx->hdd_wlan_suspended)
            {
                hdd_set_pwrparams(pHddCtx);
            }
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
           //ReEnable Bmps and Imps back
           hdd_enable_bmps_imps(pHddCtx);
        }

        hddLog(VOS_TRACE_LEVEL_ERROR, "%s: connect failed", __func__);
        return status;
    }
<<<<<<< HEAD
<<<<<<< HEAD
    (WLAN_HDD_GET_CTX(pAdapter))->isAmpAllowed = VOS_FALSE;
=======
    pHddCtx->isAmpAllowed = VOS_FALSE;
>>>>>>> d97af3b... add prima wlan driver
=======
    (WLAN_HDD_GET_CTX(pAdapter))->isAmpAllowed = VOS_FALSE;
>>>>>>> 657b0e9... prima update
    EXIT();
    return status;
}


/*
<<<<<<< HEAD
<<<<<<< HEAD
 * FUNCTION: wlan_hdd_cfg80211_disconnect
 * This function is used to issue a disconnect request to SME
 */
static int wlan_hdd_cfg80211_disconnect( struct wiphy *wiphy, 
                                         struct net_device *dev,
                                         u16 reason
                                         )
{
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR( dev ); 
    tCsrRoamProfile  *pRoamProfile = 
                    &(WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter))->roamProfile;
    int status = 0;
    hdd_station_ctx_t *pHddStaCtx = WLAN_HDD_GET_STATION_CTX_PTR(pAdapter);
    
    ENTER();
    
    hddLog(VOS_TRACE_LEVEL_INFO, "%s: device_mode = %d\n", 
                                    __func__,pAdapter->device_mode);

    hddLog(VOS_TRACE_LEVEL_INFO, "%s: Disconnect called with reason code %d", 
            __func__, reason);    

    if ((WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress)
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                "%s:LOGP in Progress. Ignore!!!",__func__);
        return -EAGAIN;
    }
    if (NULL != pRoamProfile)
    {
        /*issue disconnect request to SME, if station is in connected state*/
        if (pHddStaCtx->conn_info.connState == eConnectionState_Associated)
        {
            eCsrRoamDisconnectReason reasonCode = 
                                       eCSR_DISCONNECT_REASON_UNSPECIFIED;
=======
 * FUNCTION: wlan_hdd_disconnect
 * This function is used to issue a disconnect request to SME
 */
int wlan_hdd_disconnect( hdd_adapter_t *pAdapter, u16 reason )
{
    int status;
    hdd_station_ctx_t *pHddStaCtx = WLAN_HDD_GET_STATION_CTX_PTR(pAdapter);
    hdd_context_t *pHddCtx = WLAN_HDD_GET_CTX(pAdapter);

    status = wlan_hdd_validate_context(pHddCtx);

    if (0 != status)
    {
        VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                   "%s: HDD context is not valid", __func__);
        return status;
    }

    pHddCtx->isAmpAllowed = VOS_TRUE;
    pHddStaCtx->conn_info.connState = eConnectionState_NotConnected;
    INIT_COMPLETION(pAdapter->disconnect_comp_var);

    /*issue disconnect*/
    status = sme_RoamDisconnect( WLAN_HDD_GET_HAL_CTX(pAdapter),
                                 pAdapter->sessionId, reason);

    if ( 0 != status )
    {
        hddLog(VOS_TRACE_LEVEL_ERROR,
               "%s csrRoamDisconnect failure, returned %d \n",
               __func__, (int)status );
        return -EINVAL;
    }
    wait_for_completion_interruptible_timeout(
                &pAdapter->disconnect_comp_var,
                msecs_to_jiffies(WLAN_WAIT_TIME_DISCONNECT));
    /*stop tx queues*/
    netif_tx_disable(pAdapter->dev);
    netif_carrier_off(pAdapter->dev);
    return status;
}


/*
=======
>>>>>>> 657b0e9... prima update
 * FUNCTION: wlan_hdd_cfg80211_disconnect
 * This function is used to issue a disconnect request to SME
 */
static int wlan_hdd_cfg80211_disconnect( struct wiphy *wiphy, 
                                         struct net_device *dev,
                                         u16 reason
                                         )
{
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR( dev ); 
    tCsrRoamProfile  *pRoamProfile = 
                    &(WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter))->roamProfile;
    int status = 0;
    hdd_station_ctx_t *pHddStaCtx = WLAN_HDD_GET_STATION_CTX_PTR(pAdapter);
    
    ENTER();
    
    hddLog(VOS_TRACE_LEVEL_INFO, "%s: device_mode = %d\n", 
                                    __func__,pAdapter->device_mode);

    hddLog(VOS_TRACE_LEVEL_INFO, "%s: Disconnect called with reason code %d", 
            __func__, reason);    

    if ((WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress)
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                "%s:LOGP in Progress. Ignore!!!",__func__);
        return -EAGAIN;
    }
    if (NULL != pRoamProfile)
    {
        /*issue disconnect request to SME, if station is in connected state*/
        if (pHddStaCtx->conn_info.connState == eConnectionState_Associated)
        {
            eCsrRoamDisconnectReason reasonCode = 
                                       eCSR_DISCONNECT_REASON_UNSPECIFIED;
<<<<<<< HEAD
            hdd_scaninfo_t *pScanInfo;
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
            switch(reason)
            {
                case WLAN_REASON_MIC_FAILURE:
                    reasonCode = eCSR_DISCONNECT_REASON_MIC_ERROR;
                    break;

                case WLAN_REASON_DISASSOC_DUE_TO_INACTIVITY:
                case WLAN_REASON_DISASSOC_AP_BUSY:
                case WLAN_REASON_CLASS3_FRAME_FROM_NONASSOC_STA:
                    reasonCode = eCSR_DISCONNECT_REASON_DISASSOC;
                    break;

                case WLAN_REASON_PREV_AUTH_NOT_VALID:
                case WLAN_REASON_CLASS2_FRAME_FROM_NONAUTH_STA:
                    reasonCode = eCSR_DISCONNECT_REASON_DEAUTH;
                    break;

                case WLAN_REASON_DEAUTH_LEAVING:
                default:
                    reasonCode = eCSR_DISCONNECT_REASON_UNSPECIFIED;
                    break;
            }
            pHddStaCtx->conn_info.connState = eConnectionState_NotConnected;
<<<<<<< HEAD
<<<<<<< HEAD
            (WLAN_HDD_GET_CTX(pAdapter))->isAmpAllowed = VOS_TRUE;
            INIT_COMPLETION(pAdapter->disconnect_comp_var);

            /*issue disconnect*/
            status = sme_RoamDisconnect( WLAN_HDD_GET_HAL_CTX(pAdapter), 
                                         pAdapter->sessionId, reasonCode);

            if ( 0 != status)
            {
                hddLog(VOS_TRACE_LEVEL_ERROR,
                        "%s csrRoamDisconnect failure, returned %d \n", 
                        __func__, (int)status );
                return -EINVAL;
            }

            wait_for_completion_interruptible_timeout(
                   &pAdapter->disconnect_comp_var,
                   msecs_to_jiffies(WLAN_WAIT_TIME_DISCONNECT));


            /*stop tx queues*/
            netif_tx_disable(dev);
            netif_carrier_off(dev);
=======
            pScanInfo =  &pHddCtx->scan_info;
            if (pScanInfo->mScanPending)
            {
               hddLog(VOS_TRACE_LEVEL_INFO, "Disconnect is in progress, "
                              "Aborting Scan");
                hdd_abort_mac_scan(pHddCtx, pAdapter->sessionId);
            }
=======
            (WLAN_HDD_GET_CTX(pAdapter))->isAmpAllowed = VOS_TRUE;
            INIT_COMPLETION(pAdapter->disconnect_comp_var);
>>>>>>> 657b0e9... prima update

            /*issue disconnect*/
            status = sme_RoamDisconnect( WLAN_HDD_GET_HAL_CTX(pAdapter), 
                                         pAdapter->sessionId, reasonCode);

            if ( 0 != status)
            {
                hddLog(VOS_TRACE_LEVEL_ERROR,
                        "%s csrRoamDisconnect failure, returned %d \n", 
                        __func__, (int)status );
                return -EINVAL;
            }
<<<<<<< HEAD
>>>>>>> d97af3b... add prima wlan driver
=======

            wait_for_completion_interruptible_timeout(
                   &pAdapter->disconnect_comp_var,
                   msecs_to_jiffies(WLAN_WAIT_TIME_DISCONNECT));


            /*stop tx queues*/
            netif_tx_disable(dev);
            netif_carrier_off(dev);
>>>>>>> 657b0e9... prima update
        }
    }
    else
    {
        hddLog(VOS_TRACE_LEVEL_ERROR, "%s: No valid roam profile", __func__);
    }

    return status;
}

<<<<<<< HEAD
<<<<<<< HEAD
/*
 * FUNCTION: wlan_hdd_cfg80211_set_privacy_ibss
 * This function is used to initialize the security 
 * settings in IBSS mode.
 */
static int wlan_hdd_cfg80211_set_privacy_ibss(
                                         hdd_adapter_t *pAdapter, 
=======

=======
>>>>>>> 657b0e9... prima update
/*
 * FUNCTION: wlan_hdd_cfg80211_set_privacy_ibss
 * This function is used to initialize the security 
 * settings in IBSS mode.
 */
static int wlan_hdd_cfg80211_set_privacy_ibss(
<<<<<<< HEAD
                                         hdd_adapter_t *pAdapter,
>>>>>>> d97af3b... add prima wlan driver
=======
                                         hdd_adapter_t *pAdapter, 
>>>>>>> 657b0e9... prima update
                                         struct cfg80211_ibss_params *params
                                         )
{
    int status = 0;
<<<<<<< HEAD
<<<<<<< HEAD
    hdd_wext_state_t *pWextState = WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter);   
    eCsrEncryptionType encryptionType = eCSR_ENCRYPT_TYPE_NONE;
    hdd_station_ctx_t *pHddStaCtx = WLAN_HDD_GET_STATION_CTX_PTR(pAdapter);
    
=======
    hdd_wext_state_t *pWextState = WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter);
    eCsrEncryptionType encryptionType = eCSR_ENCRYPT_TYPE_NONE;
    hdd_station_ctx_t *pHddStaCtx = WLAN_HDD_GET_STATION_CTX_PTR(pAdapter);

>>>>>>> d97af3b... add prima wlan driver
=======
    hdd_wext_state_t *pWextState = WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter);   
    eCsrEncryptionType encryptionType = eCSR_ENCRYPT_TYPE_NONE;
    hdd_station_ctx_t *pHddStaCtx = WLAN_HDD_GET_STATION_CTX_PTR(pAdapter);
    
>>>>>>> 657b0e9... prima update
    ENTER();

    pWextState->wpaVersion = IW_AUTH_WPA_VERSION_DISABLED;

    if (params->ie_len && ( NULL != params->ie) )
    {
<<<<<<< HEAD
<<<<<<< HEAD
        if (WLAN_EID_RSN == params->ie[0]) 
=======
        if (wlan_hdd_cfg80211_get_ie_ptr (params->ie,
                            params->ie_len, WLAN_EID_RSN ))
>>>>>>> d97af3b... add prima wlan driver
=======
        if (WLAN_EID_RSN == params->ie[0]) 
>>>>>>> 657b0e9... prima update
        {
            pWextState->wpaVersion = IW_AUTH_WPA_VERSION_WPA2;
            encryptionType = eCSR_ENCRYPT_TYPE_AES;
        }
<<<<<<< HEAD
<<<<<<< HEAD
        else
        {
            pWextState->wpaVersion = IW_AUTH_WPA_VERSION_WPA;
            encryptionType = eCSR_ENCRYPT_TYPE_TKIP;
        }
=======
        else if ( hdd_isWPAIEPresent (params->ie, params->ie_len ))
=======
        else
>>>>>>> 657b0e9... prima update
        {
            pWextState->wpaVersion = IW_AUTH_WPA_VERSION_WPA;
            encryptionType = eCSR_ENCRYPT_TYPE_TKIP;
        }
<<<<<<< HEAD

>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
        status = wlan_hdd_cfg80211_set_ie(pAdapter, params->ie, params->ie_len);

        if (0 > status)
        {
<<<<<<< HEAD
<<<<<<< HEAD
            hddLog(VOS_TRACE_LEVEL_ERROR, "%s: failed to parse WPA/RSN IE", 
=======
            hddLog(VOS_TRACE_LEVEL_ERROR, "%s: failed to parse WPA/RSN IE",
>>>>>>> d97af3b... add prima wlan driver
=======
            hddLog(VOS_TRACE_LEVEL_ERROR, "%s: failed to parse WPA/RSN IE", 
>>>>>>> 657b0e9... prima update
                    __func__);
            return status;
        }
    }

<<<<<<< HEAD
<<<<<<< HEAD
    pWextState->roamProfile.AuthType.authType[0] = 
                                pHddStaCtx->conn_info.authType = 
=======
    pWextState->roamProfile.AuthType.authType[0] =
                                pHddStaCtx->conn_info.authType =
>>>>>>> d97af3b... add prima wlan driver
=======
    pWextState->roamProfile.AuthType.authType[0] = 
                                pHddStaCtx->conn_info.authType = 
>>>>>>> 657b0e9... prima update
                                eCSR_AUTH_TYPE_OPEN_SYSTEM;

    if (params->privacy)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        /* Security enabled IBSS, At this time there is no information available 
         * about the security paramters, so initialise the encryption type to 
         * eCSR_ENCRYPT_TYPE_WEP40_STATICKEY.
         * The correct security parameters will be updated later in 
         * wlan_hdd_cfg80211_add_key */
        /* Hal expects encryption type to be set inorder 
=======
        /* Security enabled IBSS, At this time there is no information available
         * about the security paramters, so initialise the encryption type to
=======
        /* Security enabled IBSS, At this time there is no information available 
         * about the security paramters, so initialise the encryption type to 
>>>>>>> 657b0e9... prima update
         * eCSR_ENCRYPT_TYPE_WEP40_STATICKEY.
         * The correct security parameters will be updated later in 
         * wlan_hdd_cfg80211_add_key */
<<<<<<< HEAD
        /* Hal expects encryption type to be set inorder
>>>>>>> d97af3b... add prima wlan driver
=======
        /* Hal expects encryption type to be set inorder 
>>>>>>> 657b0e9... prima update
         *enable privacy bit in beacons */

        encryptionType = eCSR_ENCRYPT_TYPE_WEP40_STATICKEY;
    }
<<<<<<< HEAD
<<<<<<< HEAD

    pHddStaCtx->conn_info.ucEncryptionType                   = encryptionType;
    pWextState->roamProfile.EncryptionType.numEntries        = 1;
    pWextState->roamProfile.EncryptionType.encryptionType[0] = encryptionType;

=======
    VOS_TRACE (VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_HIGH,
                          "encryptionType=%d", encryptionType);
    pHddStaCtx->conn_info.ucEncryptionType                   = encryptionType;
    pWextState->roamProfile.EncryptionType.numEntries        = 1;
    pWextState->roamProfile.EncryptionType.encryptionType[0] = encryptionType;
>>>>>>> d97af3b... add prima wlan driver
=======

    pHddStaCtx->conn_info.ucEncryptionType                   = encryptionType;
    pWextState->roamProfile.EncryptionType.numEntries        = 1;
    pWextState->roamProfile.EncryptionType.encryptionType[0] = encryptionType;

>>>>>>> 657b0e9... prima update
    return status;
}

/*
 * FUNCTION: wlan_hdd_cfg80211_join_ibss
<<<<<<< HEAD
<<<<<<< HEAD
 * This function is used to create/join an IBSS 
 */
static int wlan_hdd_cfg80211_join_ibss( struct wiphy *wiphy, 
=======
 * This function is used to create/join an IBSS
 */
static int wlan_hdd_cfg80211_join_ibss( struct wiphy *wiphy,
>>>>>>> d97af3b... add prima wlan driver
=======
 * This function is used to create/join an IBSS 
 */
static int wlan_hdd_cfg80211_join_ibss( struct wiphy *wiphy, 
>>>>>>> 657b0e9... prima update
                                        struct net_device *dev,
                                        struct cfg80211_ibss_params *params
                                       )
{
<<<<<<< HEAD
<<<<<<< HEAD
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR( dev ); 
=======
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR( dev );
>>>>>>> d97af3b... add prima wlan driver
=======
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR( dev ); 
>>>>>>> 657b0e9... prima update
    hdd_wext_state_t *pWextState = WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter);
    tCsrRoamProfile          *pRoamProfile;
    int status;
    hdd_station_ctx_t *pHddStaCtx = WLAN_HDD_GET_STATION_CTX_PTR(pAdapter);
<<<<<<< HEAD
<<<<<<< HEAD

    ENTER();
    
    hddLog(VOS_TRACE_LEVEL_INFO, 
                  "%s: device_mode = %d\n",__func__,pAdapter->device_mode);

    if ( (WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress )
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                "%s:LOGP in Progress. Ignore!!!", __func__);
        return -EAGAIN;
=======
    hdd_context_t *pHddCtx = WLAN_HDD_GET_CTX(pAdapter);
=======
>>>>>>> 657b0e9... prima update

    ENTER();
    
    hddLog(VOS_TRACE_LEVEL_INFO, 
                  "%s: device_mode = %d\n",__func__,pAdapter->device_mode);

    if ( (WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress )
    {
<<<<<<< HEAD
        VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                   "%s: HDD context is not valid", __func__);
        return status;
>>>>>>> d97af3b... add prima wlan driver
=======
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                "%s:LOGP in Progress. Ignore!!!", __func__);
        return -EAGAIN;
>>>>>>> 657b0e9... prima update
    }

    if (NULL == pWextState)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        hddLog (VOS_TRACE_LEVEL_ERROR, "%s ERROR: Data Storage Corruption\n", 
=======
        hddLog (VOS_TRACE_LEVEL_ERROR, "%s ERROR: Data Storage Corruption\n",
>>>>>>> d97af3b... add prima wlan driver
=======
        hddLog (VOS_TRACE_LEVEL_ERROR, "%s ERROR: Data Storage Corruption\n", 
>>>>>>> 657b0e9... prima update
                __func__);
        return -EIO;
    }

    pRoamProfile = &pWextState->roamProfile;

    if ( eCSR_BSS_TYPE_START_IBSS != pRoamProfile->BSSType )
    {
<<<<<<< HEAD
<<<<<<< HEAD
        hddLog (VOS_TRACE_LEVEL_ERROR, 
=======
        hddLog (VOS_TRACE_LEVEL_ERROR,
>>>>>>> d97af3b... add prima wlan driver
=======
        hddLog (VOS_TRACE_LEVEL_ERROR, 
>>>>>>> 657b0e9... prima update
                "%s Interface type is not set to IBSS \n", __func__);
        return -EINVAL;
    }

    /* Set Channel */
<<<<<<< HEAD
<<<<<<< HEAD
    if (NULL != params->channel)
    {
        u8 channelNum;
        if (IEEE80211_BAND_5GHZ == params->channel->band)
        {
            hddLog(VOS_TRACE_LEVEL_ERROR, 
                    "%s: IBSS join is called with unsupported band %d", 
                    __func__, params->channel->band);
            return -EOPNOTSUPP;
        }

        /* Get channel number */
        channelNum = 
               ieee80211_frequency_to_channel(params->channel->center_freq);

        /*TODO: use macro*/
        if (14 >= channelNum)
        {
            v_U32_t numChans = WNI_CFG_VALID_CHANNEL_LIST_LEN;
            v_U8_t validChan[WNI_CFG_VALID_CHANNEL_LIST_LEN];
            tHalHandle hHal = WLAN_HDD_GET_HAL_CTX(pAdapter);
            int indx;

            if (0 != ccmCfgGetStr(hHal, WNI_CFG_VALID_CHANNEL_LIST,
                        validChan, &numChans))
            {
                hddLog(VOS_TRACE_LEVEL_ERROR, "%s: No valid channel list", 
                        __func__);
                return -EOPNOTSUPP;
            }

            for (indx = 0; indx < numChans; indx++)
            {
                if (channelNum == validChan[indx])
                {
                    break;
                }
            }
            if (indx >= numChans)
            {
                hddLog(VOS_TRACE_LEVEL_ERROR, "%s: Not valid Channel %d", 
                        __func__, channelNum);
                return -EINVAL;
            }
            /* Set the Operational Channel */
            hddLog(VOS_TRACE_LEVEL_INFO_HIGH, "%s: set channel %d", __func__, 
                    channelNum);
            pRoamProfile->ChannelInfo.numOfChannels = 1;
            pHddStaCtx->conn_info.operationChannel = channelNum;
            pRoamProfile->ChannelInfo.ChannelList = 
                &pHddStaCtx->conn_info.operationChannel;
        }
        else
        {
            hddLog(VOS_TRACE_LEVEL_ERROR, "%s: Not valid Channel %hu", 
                    __func__, channelNum);
            return -EINVAL;
        }
    }

    /* Initialize security parameters */
    status = wlan_hdd_cfg80211_set_privacy_ibss(pAdapter, params); 
    if (status < 0)
    {
        hddLog(VOS_TRACE_LEVEL_ERROR, "%s: failed to set security parameters", 
=======
    if (NULL !=
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(3,8,0))
                params->chandef.chan)
#else
                params->channel)
#endif
=======
    if (NULL != params->channel)
>>>>>>> 657b0e9... prima update
    {
        u8 channelNum;
        if (IEEE80211_BAND_5GHZ == params->channel->band)
        {
            hddLog(VOS_TRACE_LEVEL_ERROR, 
                    "%s: IBSS join is called with unsupported band %d", 
                    __func__, params->channel->band);
            return -EOPNOTSUPP;
        }

        /* Get channel number */
        channelNum = 
               ieee80211_frequency_to_channel(params->channel->center_freq);

        /*TODO: use macro*/
        if (14 >= channelNum)
        {
            v_U32_t numChans = WNI_CFG_VALID_CHANNEL_LIST_LEN;
            v_U8_t validChan[WNI_CFG_VALID_CHANNEL_LIST_LEN];
            tHalHandle hHal = WLAN_HDD_GET_HAL_CTX(pAdapter);
            int indx;

            if (0 != ccmCfgGetStr(hHal, WNI_CFG_VALID_CHANNEL_LIST,
                        validChan, &numChans))
            {
                hddLog(VOS_TRACE_LEVEL_ERROR, "%s: No valid channel list", 
                        __func__);
                return -EOPNOTSUPP;
            }

            for (indx = 0; indx < numChans; indx++)
            {
                if (channelNum == validChan[indx])
                {
                    break;
                }
            }
            if (indx >= numChans)
            {
                hddLog(VOS_TRACE_LEVEL_ERROR, "%s: Not valid Channel %d", 
                        __func__, channelNum);
                return -EINVAL;
            }
            /* Set the Operational Channel */
            hddLog(VOS_TRACE_LEVEL_INFO_HIGH, "%s: set channel %d", __func__, 
                    channelNum);
            pRoamProfile->ChannelInfo.numOfChannels = 1;
            pHddStaCtx->conn_info.operationChannel = channelNum;
            pRoamProfile->ChannelInfo.ChannelList = 
                &pHddStaCtx->conn_info.operationChannel;
        }
        else
        {
            hddLog(VOS_TRACE_LEVEL_ERROR, "%s: Not valid Channel %hu", 
                    __func__, channelNum);
            return -EINVAL;
        }
    }

    /* Initialize security parameters */
    status = wlan_hdd_cfg80211_set_privacy_ibss(pAdapter, params); 
    if (status < 0)
    {
<<<<<<< HEAD
        hddLog(VOS_TRACE_LEVEL_ERROR, "%s: failed to set security parameters",
>>>>>>> d97af3b... add prima wlan driver
=======
        hddLog(VOS_TRACE_LEVEL_ERROR, "%s: failed to set security parameters", 
>>>>>>> 657b0e9... prima update
                __func__);
        return status;
    }

    /* Issue connect start */
<<<<<<< HEAD
<<<<<<< HEAD
    status = wlan_hdd_cfg80211_connect_start(pAdapter, params->ssid, 
            params->ssid_len, params->bssid, 0);
=======
    status = wlan_hdd_cfg80211_connect_start(pAdapter, params->ssid,
            params->ssid_len, params->bssid,
            pHddStaCtx->conn_info.operationChannel);
>>>>>>> d97af3b... add prima wlan driver
=======
    status = wlan_hdd_cfg80211_connect_start(pAdapter, params->ssid, 
            params->ssid_len, params->bssid, 0);
>>>>>>> 657b0e9... prima update

    if (0 > status)
    {
        hddLog(VOS_TRACE_LEVEL_ERROR, "%s: connect failed", __func__);
        return status;
    }

    return 0;
}

/*
 * FUNCTION: wlan_hdd_cfg80211_leave_ibss
<<<<<<< HEAD
<<<<<<< HEAD
 * This function is used to leave an IBSS 
 */
static int wlan_hdd_cfg80211_leave_ibss( struct wiphy *wiphy, 
                                         struct net_device *dev
                                         )
{
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR( dev ); 
    hdd_wext_state_t *pWextState = WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter);
    tCsrRoamProfile *pRoamProfile;

    ENTER();

    if ( (WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress )
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                "%s:LOGP in Progress. Ignore!!!", __func__);
        return -EAGAIN;
=======
 * This function is used to leave an IBSS
=======
 * This function is used to leave an IBSS 
>>>>>>> 657b0e9... prima update
 */
static int wlan_hdd_cfg80211_leave_ibss( struct wiphy *wiphy, 
                                         struct net_device *dev
                                         )
{
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR( dev ); 
    hdd_wext_state_t *pWextState = WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter);
    tCsrRoamProfile *pRoamProfile;

    ENTER();

    if ( (WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress )
    {
<<<<<<< HEAD
        VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                   "%s: HDD context is not valid", __func__);
        return status;
>>>>>>> d97af3b... add prima wlan driver
=======
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                "%s:LOGP in Progress. Ignore!!!", __func__);
        return -EAGAIN;
>>>>>>> 657b0e9... prima update
    }

    hddLog(VOS_TRACE_LEVEL_INFO, "%s: device_mode = %d\n",__func__,pAdapter->device_mode);
    if (NULL == pWextState)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        hddLog (VOS_TRACE_LEVEL_ERROR, "%s ERROR: Data Storage Corruption\n", 
=======
        hddLog (VOS_TRACE_LEVEL_ERROR, "%s ERROR: Data Storage Corruption\n",
>>>>>>> d97af3b... add prima wlan driver
=======
        hddLog (VOS_TRACE_LEVEL_ERROR, "%s ERROR: Data Storage Corruption\n", 
>>>>>>> 657b0e9... prima update
                __func__);
        return -EIO;
    }

    pRoamProfile = &pWextState->roamProfile;

    /* Issue disconnect only if interface type is set to IBSS */
    if (eCSR_BSS_TYPE_START_IBSS != pRoamProfile->BSSType)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        hddLog (VOS_TRACE_LEVEL_ERROR, "%s: BSS Type is not set to IBSS", 
=======
        hddLog (VOS_TRACE_LEVEL_ERROR, "%s: BSS Type is not set to IBSS",
>>>>>>> d97af3b... add prima wlan driver
=======
        hddLog (VOS_TRACE_LEVEL_ERROR, "%s: BSS Type is not set to IBSS", 
>>>>>>> 657b0e9... prima update
                __func__);
        return -EINVAL;
    }

    /* Issue Disconnect request */
    INIT_COMPLETION(pAdapter->disconnect_comp_var);
    sme_RoamDisconnect( WLAN_HDD_GET_HAL_CTX(pAdapter), pAdapter->sessionId,
                                  eCSR_DISCONNECT_REASON_IBSS_LEAVE);

    return 0;
}

/*
 * FUNCTION: wlan_hdd_cfg80211_set_wiphy_params
 * This function is used to set the phy parameters
 * (RTS Threshold/FRAG Threshold/Retry Count etc ...)
 */
<<<<<<< HEAD
<<<<<<< HEAD
static int wlan_hdd_cfg80211_set_wiphy_params(struct wiphy *wiphy, 
=======
static int wlan_hdd_cfg80211_set_wiphy_params(struct wiphy *wiphy,
>>>>>>> d97af3b... add prima wlan driver
=======
static int wlan_hdd_cfg80211_set_wiphy_params(struct wiphy *wiphy, 
>>>>>>> 657b0e9... prima update
        u32 changed)
{
    hdd_context_t *pHddCtx = wiphy_priv(wiphy);
    tHalHandle hHal = pHddCtx->hHal;
<<<<<<< HEAD
<<<<<<< HEAD

    ENTER();

    if ( pHddCtx->isLogpInProgress )
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                "%s:LOGP in Progress. Ignore!!!", __func__);
        return -EAGAIN;
=======
    int status;
=======
>>>>>>> 657b0e9... prima update

    ENTER();

    if ( pHddCtx->isLogpInProgress )
    {
<<<<<<< HEAD
        VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                   "%s: HDD context is not valid", __func__);
        return status;
>>>>>>> d97af3b... add prima wlan driver
=======
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                "%s:LOGP in Progress. Ignore!!!", __func__);
        return -EAGAIN;
>>>>>>> 657b0e9... prima update
    }

    if (changed & WIPHY_PARAM_RTS_THRESHOLD)
    {
        u16 rts_threshold = (wiphy->rts_threshold == -1) ?
                               WNI_CFG_RTS_THRESHOLD_STAMAX :
                               wiphy->rts_threshold;

        if ((WNI_CFG_RTS_THRESHOLD_STAMIN > rts_threshold) ||
<<<<<<< HEAD
<<<<<<< HEAD
                (WNI_CFG_RTS_THRESHOLD_STAMAX < rts_threshold)) 
        {
            hddLog(VOS_TRACE_LEVEL_ERROR, 
                    "%s: Invalid RTS Threshold value %hu", 
=======
                (WNI_CFG_RTS_THRESHOLD_STAMAX < rts_threshold))
        {
            hddLog(VOS_TRACE_LEVEL_ERROR,
                    "%s: Invalid RTS Threshold value %hu",
>>>>>>> d97af3b... add prima wlan driver
=======
                (WNI_CFG_RTS_THRESHOLD_STAMAX < rts_threshold)) 
        {
            hddLog(VOS_TRACE_LEVEL_ERROR, 
                    "%s: Invalid RTS Threshold value %hu", 
>>>>>>> 657b0e9... prima update
                    __func__, rts_threshold);
            return -EINVAL;
        }

        if (0 != ccmCfgSetInt(hHal, WNI_CFG_RTS_THRESHOLD,
                    rts_threshold, ccmCfgSetCallback,
<<<<<<< HEAD
<<<<<<< HEAD
                    eANI_BOOLEAN_TRUE)) 
        {
            hddLog(VOS_TRACE_LEVEL_ERROR, 
                    "%s: ccmCfgSetInt failed for rts_threshold value %hu", 
=======
                    eANI_BOOLEAN_TRUE))
        {
            hddLog(VOS_TRACE_LEVEL_ERROR,
                    "%s: ccmCfgSetInt failed for rts_threshold value %hu",
>>>>>>> d97af3b... add prima wlan driver
=======
                    eANI_BOOLEAN_TRUE)) 
        {
            hddLog(VOS_TRACE_LEVEL_ERROR, 
                    "%s: ccmCfgSetInt failed for rts_threshold value %hu", 
>>>>>>> 657b0e9... prima update
                    __func__, rts_threshold);
            return -EIO;
        }

<<<<<<< HEAD
<<<<<<< HEAD
        hddLog(VOS_TRACE_LEVEL_INFO_MED, "%s: set rts threshold %hu", __func__, 
=======
        hddLog(VOS_TRACE_LEVEL_INFO_MED, "%s: set rts threshold %hu", __func__,
>>>>>>> d97af3b... add prima wlan driver
=======
        hddLog(VOS_TRACE_LEVEL_INFO_MED, "%s: set rts threshold %hu", __func__, 
>>>>>>> 657b0e9... prima update
                rts_threshold);
    }

    if (changed & WIPHY_PARAM_FRAG_THRESHOLD)
    {
        u16 frag_threshold = (wiphy->frag_threshold == -1) ?
                                WNI_CFG_FRAGMENTATION_THRESHOLD_STAMAX :
                                wiphy->frag_threshold;

        if ((WNI_CFG_FRAGMENTATION_THRESHOLD_STAMIN > frag_threshold)||
<<<<<<< HEAD
<<<<<<< HEAD
                (WNI_CFG_FRAGMENTATION_THRESHOLD_STAMAX < frag_threshold) ) 
        {
            hddLog(VOS_TRACE_LEVEL_ERROR, 
                    "%s: Invalid frag_threshold value %hu", __func__, 
=======
                (WNI_CFG_FRAGMENTATION_THRESHOLD_STAMAX < frag_threshold) )
        {
            hddLog(VOS_TRACE_LEVEL_ERROR,
                    "%s: Invalid frag_threshold value %hu", __func__,
>>>>>>> d97af3b... add prima wlan driver
=======
                (WNI_CFG_FRAGMENTATION_THRESHOLD_STAMAX < frag_threshold) ) 
        {
            hddLog(VOS_TRACE_LEVEL_ERROR, 
                    "%s: Invalid frag_threshold value %hu", __func__, 
>>>>>>> 657b0e9... prima update
                    frag_threshold);
            return -EINVAL;
        }

        if (0 != ccmCfgSetInt(hHal, WNI_CFG_FRAGMENTATION_THRESHOLD,
                    frag_threshold, ccmCfgSetCallback,
<<<<<<< HEAD
<<<<<<< HEAD
                    eANI_BOOLEAN_TRUE)) 
        {
            hddLog(VOS_TRACE_LEVEL_ERROR, 
                    "%s: ccmCfgSetInt failed for frag_threshold value %hu", 
=======
                    eANI_BOOLEAN_TRUE))
        {
            hddLog(VOS_TRACE_LEVEL_ERROR,
                    "%s: ccmCfgSetInt failed for frag_threshold value %hu",
>>>>>>> d97af3b... add prima wlan driver
=======
                    eANI_BOOLEAN_TRUE)) 
        {
            hddLog(VOS_TRACE_LEVEL_ERROR, 
                    "%s: ccmCfgSetInt failed for frag_threshold value %hu", 
>>>>>>> 657b0e9... prima update
                    __func__, frag_threshold);
            return -EIO;
        }

        hddLog(VOS_TRACE_LEVEL_INFO_MED, "%s: set frag threshold %hu", __func__,
                frag_threshold);
    }

    if ((changed & WIPHY_PARAM_RETRY_SHORT)
            || (changed & WIPHY_PARAM_RETRY_LONG))
    {
        u8 retry_value = (changed & WIPHY_PARAM_RETRY_SHORT) ?
                         wiphy->retry_short :
                         wiphy->retry_long;

        if ((WNI_CFG_LONG_RETRY_LIMIT_STAMIN > retry_value) ||
                (WNI_CFG_LONG_RETRY_LIMIT_STAMAX < retry_value))
        {
<<<<<<< HEAD
<<<<<<< HEAD
            hddLog(VOS_TRACE_LEVEL_ERROR, "%s: Invalid Retry count %hu", 
=======
            hddLog(VOS_TRACE_LEVEL_ERROR, "%s: Invalid Retry count %hu",
>>>>>>> d97af3b... add prima wlan driver
=======
            hddLog(VOS_TRACE_LEVEL_ERROR, "%s: Invalid Retry count %hu", 
>>>>>>> 657b0e9... prima update
                    __func__, retry_value);
            return -EINVAL;
        }

        if (changed & WIPHY_PARAM_RETRY_SHORT)
        {
            if (0 != ccmCfgSetInt(hHal, WNI_CFG_LONG_RETRY_LIMIT,
                        retry_value, ccmCfgSetCallback,
<<<<<<< HEAD
<<<<<<< HEAD
                        eANI_BOOLEAN_TRUE)) 
            {
                hddLog(VOS_TRACE_LEVEL_ERROR, 
                        "%s: ccmCfgSetInt failed for long retry count %hu", 
                        __func__, retry_value);
                return -EIO;
            }
            hddLog(VOS_TRACE_LEVEL_INFO_MED, "%s: set long retry count %hu", 
=======
                        eANI_BOOLEAN_TRUE))
=======
                        eANI_BOOLEAN_TRUE)) 
>>>>>>> 657b0e9... prima update
            {
                hddLog(VOS_TRACE_LEVEL_ERROR, 
                        "%s: ccmCfgSetInt failed for long retry count %hu", 
                        __func__, retry_value);
                return -EIO;
            }
<<<<<<< HEAD
            hddLog(VOS_TRACE_LEVEL_INFO_MED, "%s: set long retry count %hu",
>>>>>>> d97af3b... add prima wlan driver
=======
            hddLog(VOS_TRACE_LEVEL_INFO_MED, "%s: set long retry count %hu", 
>>>>>>> 657b0e9... prima update
                    __func__, retry_value);
        }
        else if (changed & WIPHY_PARAM_RETRY_SHORT)
        {
            if (0 != ccmCfgSetInt(hHal, WNI_CFG_SHORT_RETRY_LIMIT,
                        retry_value, ccmCfgSetCallback,
<<<<<<< HEAD
<<<<<<< HEAD
                        eANI_BOOLEAN_TRUE)) 
            {
                hddLog(VOS_TRACE_LEVEL_ERROR, 
                        "%s: ccmCfgSetInt failed for short retry count %hu", 
                        __func__, retry_value);
                return -EIO;
            }
            hddLog(VOS_TRACE_LEVEL_INFO_MED, "%s: set short retry count %hu", 
=======
                        eANI_BOOLEAN_TRUE))
=======
                        eANI_BOOLEAN_TRUE)) 
>>>>>>> 657b0e9... prima update
            {
                hddLog(VOS_TRACE_LEVEL_ERROR, 
                        "%s: ccmCfgSetInt failed for short retry count %hu", 
                        __func__, retry_value);
                return -EIO;
            }
<<<<<<< HEAD
            hddLog(VOS_TRACE_LEVEL_INFO_MED, "%s: set short retry count %hu",
>>>>>>> d97af3b... add prima wlan driver
=======
            hddLog(VOS_TRACE_LEVEL_INFO_MED, "%s: set short retry count %hu", 
>>>>>>> 657b0e9... prima update
                    __func__, retry_value);
        }
    }

    return 0;
}

/*
 * FUNCTION: wlan_hdd_cfg80211_set_txpower
 * This function is used to set the txpower
 */
static int wlan_hdd_cfg80211_set_txpower(struct wiphy *wiphy,
<<<<<<< HEAD
<<<<<<< HEAD
#if LINUX_VERSION_CODE <= KERNEL_VERSION(2,6,35)
        enum tx_power_setting type, 
#else
        enum nl80211_tx_power_setting type, 
=======
#if LINUX_VERSION_CODE >= KERNEL_VERSION(3,8,0)
        struct wireless_dev *wdev,
#endif
=======
>>>>>>> 657b0e9... prima update
#if LINUX_VERSION_CODE <= KERNEL_VERSION(2,6,35)
        enum tx_power_setting type, 
#else
<<<<<<< HEAD
        enum nl80211_tx_power_setting type,
>>>>>>> d97af3b... add prima wlan driver
=======
        enum nl80211_tx_power_setting type, 
>>>>>>> 657b0e9... prima update
#endif
        int dbm)
{
    hdd_context_t *pHddCtx = (hdd_context_t*) wiphy_priv(wiphy);
<<<<<<< HEAD
<<<<<<< HEAD
    tHalHandle hHal = pHddCtx->hHal;
    tSirMacAddr bssid = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
    tSirMacAddr selfMac = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};

    ENTER();

    if (0 != ccmCfgSetInt(hHal, WNI_CFG_CURRENT_TX_POWER_LEVEL, 
                dbm, ccmCfgSetCallback, 
                eANI_BOOLEAN_TRUE)) 
    {
        hddLog(VOS_TRACE_LEVEL_ERROR, 
                "%s: ccmCfgSetInt failed for tx power %hu", __func__, dbm);
        return -EIO;
    }

    if ( pHddCtx->isLogpInProgress )
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                "%s:LOGP in Progress. Ignore!!!", __func__);
        return -EAGAIN;
=======
    tHalHandle hHal = NULL;
=======
    tHalHandle hHal = pHddCtx->hHal;
>>>>>>> 657b0e9... prima update
    tSirMacAddr bssid = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
    tSirMacAddr selfMac = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};

    ENTER();

    if (0 != ccmCfgSetInt(hHal, WNI_CFG_CURRENT_TX_POWER_LEVEL, 
                dbm, ccmCfgSetCallback, 
                eANI_BOOLEAN_TRUE)) 
    {
        hddLog(VOS_TRACE_LEVEL_ERROR, 
                "%s: ccmCfgSetInt failed for tx power %hu", __func__, dbm);
        return -EIO;
    }

    if ( pHddCtx->isLogpInProgress )
    {
<<<<<<< HEAD
        hddLog(VOS_TRACE_LEVEL_ERROR,
                "%s: ccmCfgSetInt failed for tx power %hu", __func__, dbm);
        return -EIO;
>>>>>>> d97af3b... add prima wlan driver
=======
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                "%s:LOGP in Progress. Ignore!!!", __func__);
        return -EAGAIN;
>>>>>>> 657b0e9... prima update
    }

    hddLog(VOS_TRACE_LEVEL_INFO_MED, "%s: set tx power level %d dbm", __func__,
            dbm);

    switch(type)
    {
    case NL80211_TX_POWER_AUTOMATIC: /*automatically determine transmit power*/
       /* Fall through */
    case NL80211_TX_POWER_LIMITED: /*limit TX power by the mBm parameter*/
       if( sme_SetMaxTxPower(hHal, bssid, selfMac, dbm) != eHAL_STATUS_SUCCESS )
       {
<<<<<<< HEAD
<<<<<<< HEAD
          hddLog(VOS_TRACE_LEVEL_ERROR, "%s: Setting maximum tx power failed", 
                 __func__); 
          return -EIO;          
       }
       break;
    case NL80211_TX_POWER_FIXED: /*fix TX power to the mBm parameter*/
       hddLog(VOS_TRACE_LEVEL_ERROR, "%s: NL80211_TX_POWER_FIXED not supported", 
=======
          hddLog(VOS_TRACE_LEVEL_ERROR, "%s: Setting maximum tx power failed",
                 __func__);
          return -EIO;
       }
       break;
    case NL80211_TX_POWER_FIXED: /*fix TX power to the mBm parameter*/
       hddLog(VOS_TRACE_LEVEL_ERROR, "%s: NL80211_TX_POWER_FIXED not supported",
>>>>>>> d97af3b... add prima wlan driver
=======
          hddLog(VOS_TRACE_LEVEL_ERROR, "%s: Setting maximum tx power failed", 
                 __func__); 
          return -EIO;          
       }
       break;
    case NL80211_TX_POWER_FIXED: /*fix TX power to the mBm parameter*/
       hddLog(VOS_TRACE_LEVEL_ERROR, "%s: NL80211_TX_POWER_FIXED not supported", 
>>>>>>> 657b0e9... prima update
              __func__);
       return -EOPNOTSUPP;
       break;
    default:
<<<<<<< HEAD
<<<<<<< HEAD
       hddLog(VOS_TRACE_LEVEL_ERROR, "%s: Invalid power setting type %d", 
              __func__, type); 
=======
       hddLog(VOS_TRACE_LEVEL_ERROR, "%s: Invalid power setting type %d",
              __func__, type);
>>>>>>> d97af3b... add prima wlan driver
=======
       hddLog(VOS_TRACE_LEVEL_ERROR, "%s: Invalid power setting type %d", 
              __func__, type); 
>>>>>>> 657b0e9... prima update
       return -EIO;
    }

    return 0;
}

/*
 * FUNCTION: wlan_hdd_cfg80211_get_txpower
 * This function is used to read the txpower
 */
<<<<<<< HEAD
<<<<<<< HEAD
static int wlan_hdd_cfg80211_get_txpower(struct wiphy *wiphy, int *dbm)
=======
static int wlan_hdd_cfg80211_get_txpower(struct wiphy *wiphy,
#if LINUX_VERSION_CODE >= KERNEL_VERSION(3,8,0)
                                         struct wireless_dev *wdev,
#endif
                                         int *dbm)
>>>>>>> d97af3b... add prima wlan driver
=======
static int wlan_hdd_cfg80211_get_txpower(struct wiphy *wiphy, int *dbm)
>>>>>>> 657b0e9... prima update
{

    hdd_adapter_t *pAdapter;
    hdd_context_t *pHddCtx = (hdd_context_t*) wiphy_priv(wiphy);
<<<<<<< HEAD
<<<<<<< HEAD

    ENTER();

    if (NULL == pHddCtx)
    {
        hddLog(VOS_TRACE_LEVEL_FATAL,"%s: HDD context is Null",__func__);
        *dbm = 0;
        return -ENOENT;
    }

    if ( pHddCtx->isLogpInProgress )
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                "%s:LOGP in Progress. Ignore!!!", __func__);
        return -EAGAIN;
=======
    int status;
=======
>>>>>>> 657b0e9... prima update

    ENTER();

    if (NULL == pHddCtx)
    {
        hddLog(VOS_TRACE_LEVEL_FATAL,"%s: HDD context is Null",__func__);
        *dbm = 0;
<<<<<<< HEAD
        return status;
>>>>>>> d97af3b... add prima wlan driver
=======
        return -ENOENT;
    }

    if ( pHddCtx->isLogpInProgress )
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                "%s:LOGP in Progress. Ignore!!!", __func__);
        return -EAGAIN;
>>>>>>> 657b0e9... prima update
    }

    pAdapter = hdd_get_adapter(pHddCtx, WLAN_HDD_INFRA_STATION);
    if (NULL == pAdapter)
    {
        hddLog(VOS_TRACE_LEVEL_FATAL, "%s: Not in station context " ,__func__);
        return -ENOENT;
    }

    wlan_hdd_get_classAstats(pAdapter);
    *dbm = pAdapter->hdd_stats.ClassA_stat.max_pwr;

    EXIT();
    return 0;
}

static int wlan_hdd_cfg80211_get_station(struct wiphy *wiphy, struct net_device *dev,
                                   u8* mac, struct station_info *sinfo)
{
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR( dev );
    hdd_station_ctx_t *pHddStaCtx = WLAN_HDD_GET_STATION_CTX_PTR(pAdapter);
    int ssidlen = pHddStaCtx->conn_info.SSID.SSID.length;
    tANI_U8 rate_flags;

    hdd_context_t *pHddCtx = (hdd_context_t*) wiphy_priv(wiphy);
    hdd_config_t  *pCfg    = pHddCtx->cfg_ini;
<<<<<<< HEAD
<<<<<<< HEAD
    tHalHandle hHal        = WLAN_HDD_GET_HAL_CTX(pAdapter);
=======
>>>>>>> d97af3b... add prima wlan driver
=======
    tHalHandle hHal        = WLAN_HDD_GET_HAL_CTX(pAdapter);
>>>>>>> 657b0e9... prima update

    tANI_U8  OperationalRates[CSR_DOT11_SUPPORTED_RATES_MAX];
    tANI_U32 ORLeng = CSR_DOT11_SUPPORTED_RATES_MAX;
    tANI_U8  ExtendedRates[CSR_DOT11_EXTENDED_SUPPORTED_RATES_MAX];
    tANI_U32 ERLeng = CSR_DOT11_EXTENDED_SUPPORTED_RATES_MAX;
    tANI_U8  MCSRates[SIZE_OF_BASIC_MCS_SET];
    tANI_U32 MCSLeng = SIZE_OF_BASIC_MCS_SET;
    tANI_U16 maxRate = 0;
    tANI_U16 myRate;
    tANI_U16 currentRate = 0;
    tANI_U8  maxSpeedMCS = 0;
    tANI_U8  maxMCSIdx = 0;
    tANI_U8  rateFlag = 1;
    tANI_U8  i, j, rssidx;
<<<<<<< HEAD
<<<<<<< HEAD
=======
    tANI_U16 temp;
    int status;

#ifdef WLAN_FEATURE_11AC
    tANI_U32 vht_mcs_map;
    eDataRate11ACMaxMcs vhtMaxMcs;
#endif /* WLAN_FEATURE_11AC */
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update

    ENTER();

    if ((eConnectionState_Associated != pHddStaCtx->conn_info.connState) ||
            (0 == ssidlen))
    {
        hddLog(VOS_TRACE_LEVEL_INFO, "%s: Not associated or"
                    " Invalid ssidlen, %d", __func__, ssidlen);
        /*To keep GUI happy*/
        return 0;
    }

<<<<<<< HEAD
<<<<<<< HEAD
    if ( (WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress )
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                "%s:LOGP in Progress. Ignore!!!", __func__);
        return -EAGAIN;
=======
    status = wlan_hdd_validate_context(pHddCtx);

    if (0 != status)
    {
        VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                   "%s: HDD context is not valid", __func__);
        return status;
>>>>>>> d97af3b... add prima wlan driver
=======
    if ( (WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress )
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                "%s:LOGP in Progress. Ignore!!!", __func__);
        return -EAGAIN;
>>>>>>> 657b0e9... prima update
    }

    wlan_hdd_get_rssi(pAdapter, &sinfo->signal);
    sinfo->filled |= STATION_INFO_SIGNAL;

    wlan_hdd_get_station_stats(pAdapter);
    rate_flags = pAdapter->hdd_stats.ClassA_stat.tx_rate_flags;

    //convert to the UI units of 100kbps
    myRate = pAdapter->hdd_stats.ClassA_stat.tx_rate * 5;

#ifdef LINKSPEED_DEBUG_ENABLED
<<<<<<< HEAD
<<<<<<< HEAD
    pr_info("RSSI %d, RLMS %u, rate %d, rssi high %d, rssi low %d\n",
=======
    pr_info("RSSI %d, RLMS %u, rate %d, rssi high %d, rssi mid %d, rssi low %d, rate_flags 0x%x, MCS %d\n",
>>>>>>> d97af3b... add prima wlan driver
=======
    pr_info("RSSI %d, RLMS %u, rate %d, rssi high %d, rssi low %d\n",
>>>>>>> 657b0e9... prima update
            sinfo->signal,
            pCfg->reportMaxLinkSpeed,
            myRate,
            (int) pCfg->linkSpeedRssiHigh,
<<<<<<< HEAD
<<<<<<< HEAD
            (int) pCfg->linkSpeedRssiLow);
=======
            (int) pCfg->linkSpeedRssiMid,
            (int) pCfg->linkSpeedRssiLow,
            (int) rate_flags,
            (int) pAdapter->hdd_stats.ClassA_stat.mcs_index);
>>>>>>> d97af3b... add prima wlan driver
=======
            (int) pCfg->linkSpeedRssiLow);
>>>>>>> 657b0e9... prima update
#endif //LINKSPEED_DEBUG_ENABLED

    if (eHDD_LINK_SPEED_REPORT_ACTUAL != pCfg->reportMaxLinkSpeed)
    {
        // we do not want to necessarily report the current speed
        if (eHDD_LINK_SPEED_REPORT_MAX == pCfg->reportMaxLinkSpeed)
        {
            // report the max possible speed
            rssidx = 0;
        }
        else if (eHDD_LINK_SPEED_REPORT_MAX_SCALED == pCfg->reportMaxLinkSpeed)
        {
            // report the max possible speed with RSSI scaling
            if (sinfo->signal >= pCfg->linkSpeedRssiHigh)
            {
                // report the max possible speed
                rssidx = 0;
            }
<<<<<<< HEAD
<<<<<<< HEAD
            else if (sinfo->signal >= pCfg->linkSpeedRssiLow)
=======
            else if (sinfo->signal >= pCfg->linkSpeedRssiMid)
>>>>>>> d97af3b... add prima wlan driver
            {
                // report middle speed
                rssidx = 1;
            }
<<<<<<< HEAD
            else
            {
                // report actual speed
                rssidx = 2;
=======
=======
>>>>>>> 657b0e9... prima update
            else if (sinfo->signal >= pCfg->linkSpeedRssiLow)
            {
                // report middle speed
                rssidx = 1;
            }
            else
            {
                // report actual speed
<<<<<<< HEAD
                rssidx = 3;
>>>>>>> d97af3b... add prima wlan driver
=======
                rssidx = 2;
>>>>>>> 657b0e9... prima update
            }
        }
        else
        {
            // unknown, treat as eHDD_LINK_SPEED_REPORT_MAX
            hddLog(VOS_TRACE_LEVEL_ERROR,
                   "%s: Invalid value for reportMaxLinkSpeed: %u",
                    __func__, pCfg->reportMaxLinkSpeed);
            rssidx = 0;
        }

        maxRate = 0;

        /* Get Basic Rate Set */
<<<<<<< HEAD
<<<<<<< HEAD
        ccmCfgGetStr(hHal, WNI_CFG_OPERATIONAL_RATE_SET, OperationalRates, &ORLeng);
=======
        if (0 != ccmCfgGetStr(WLAN_HDD_GET_HAL_CTX(pAdapter), WNI_CFG_OPERATIONAL_RATE_SET,
                             OperationalRates, &ORLeng))
        {
            hddLog(VOS_TRACE_LEVEL_ERROR, "%s: ccm api returned failure", __func__);
            /*To keep GUI happy*/
            return 0;
        }

>>>>>>> d97af3b... add prima wlan driver
=======
        ccmCfgGetStr(hHal, WNI_CFG_OPERATIONAL_RATE_SET, OperationalRates, &ORLeng);
>>>>>>> 657b0e9... prima update
        for (i = 0; i < ORLeng; i++)
        {
            for (j = 0; j < (sizeof(supported_data_rate) / sizeof(supported_data_rate[0])); j ++)
            {
                /* Validate Rate Set */
                if (supported_data_rate[j].beacon_rate_index == (OperationalRates[i] & 0x7F))
                {
                    currentRate = supported_data_rate[j].supported_rate[rssidx];
                    break;
                }
            }
            /* Update MAX rate */
            maxRate = (currentRate > maxRate)?currentRate:maxRate;
        }

        /* Get Extended Rate Set */
<<<<<<< HEAD
<<<<<<< HEAD
        ccmCfgGetStr(hHal, WNI_CFG_EXTENDED_OPERATIONAL_RATE_SET, ExtendedRates, &ERLeng);
=======
        if (0 != ccmCfgGetStr(WLAN_HDD_GET_HAL_CTX(pAdapter), WNI_CFG_EXTENDED_OPERATIONAL_RATE_SET,
                             ExtendedRates, &ERLeng))
        {
            hddLog(VOS_TRACE_LEVEL_ERROR, "%s: ccm api returned failure", __func__);
            /*To keep GUI happy*/
            return 0;
        }

>>>>>>> d97af3b... add prima wlan driver
=======
        ccmCfgGetStr(hHal, WNI_CFG_EXTENDED_OPERATIONAL_RATE_SET, ExtendedRates, &ERLeng);
>>>>>>> 657b0e9... prima update
        for (i = 0; i < ERLeng; i++)
        {
            for (j = 0; j < (sizeof(supported_data_rate) / sizeof(supported_data_rate[0])); j ++)
            {
                if (supported_data_rate[j].beacon_rate_index == (ExtendedRates[i] & 0x7F))
                {
                    currentRate = supported_data_rate[j].supported_rate[rssidx];
                    break;
                }
            }
            /* Update MAX rate */
            maxRate = (currentRate > maxRate)?currentRate:maxRate;
        }
<<<<<<< HEAD
<<<<<<< HEAD

        /* Get MCS Rate Set -- but only if we are connected at MCS
           rates or if we are always reporting max speed or if we have
           good rssi */
        if ((0 == rssidx) || !(rate_flags & eHAL_TX_RATE_LEGACY))
        {
            ccmCfgGetStr(hHal, WNI_CFG_CURRENT_MCS_SET, MCSRates, &MCSLeng);
            rateFlag = 0;
            if (rate_flags & eHAL_TX_RATE_HT40)
            {
                rateFlag |= 1;
            }
            if (rate_flags & eHAL_TX_RATE_SGI)
            {
                rateFlag |= 2;
            }

            for (i = 0; i < MCSLeng; i++)
            {
                for (j = 0; j < (sizeof(supported_mcs_rate) / sizeof(supported_mcs_rate[0])); j++)
                {
                    if (supported_mcs_rate[j].beacon_rate_index == MCSRates[i])
                    {
                        currentRate = supported_mcs_rate[j].supported_rate[rateFlag];
                        break;
                    }
                }
                if (currentRate > maxRate)
                {
                    maxRate     = currentRate;
                    maxSpeedMCS = 1;
                    maxMCSIdx   = supported_mcs_rate[j].beacon_rate_index;
=======
=======

>>>>>>> 657b0e9... prima update
        /* Get MCS Rate Set -- but only if we are connected at MCS
           rates or if we are always reporting max speed or if we have
           good rssi */
        if ((0 == rssidx) || !(rate_flags & eHAL_TX_RATE_LEGACY))
        {
            ccmCfgGetStr(hHal, WNI_CFG_CURRENT_MCS_SET, MCSRates, &MCSLeng);
            rateFlag = 0;
            if (rate_flags & eHAL_TX_RATE_HT40)
            {
                rateFlag |= 1;
            }
            if (rate_flags & eHAL_TX_RATE_SGI)
            {
                rateFlag |= 2;
            }

            for (i = 0; i < MCSLeng; i++)
            {
                for (j = 0; j < (sizeof(supported_mcs_rate) / sizeof(supported_mcs_rate[0])); j++)
                {
                    if (supported_mcs_rate[j].beacon_rate_index == MCSRates[i])
                    {
                        currentRate = supported_mcs_rate[j].supported_rate[rateFlag];
                        break;
                    }
>>>>>>> d97af3b... add prima wlan driver
                }
                if (currentRate > maxRate)
                {
                    maxRate     = currentRate;
                    maxSpeedMCS = 1;
                    maxMCSIdx   = supported_mcs_rate[j].beacon_rate_index;
                }
            }
        }

<<<<<<< HEAD
<<<<<<< HEAD
        // make sure we report a value at least as big as our current rate
        if (maxRate < myRate)
=======
        else if (!(rate_flags & eHAL_TX_RATE_LEGACY))
        {
            maxRate = myRate;
            maxSpeedMCS = 1;
            maxMCSIdx = pAdapter->hdd_stats.ClassA_stat.mcs_index;
        }

        // make sure we report a value at least as big as our current rate
        if (((maxRate < myRate) && (0 == rssidx)) ||
             (0 == maxRate))
>>>>>>> d97af3b... add prima wlan driver
=======
        // make sure we report a value at least as big as our current rate
        if (maxRate < myRate)
>>>>>>> 657b0e9... prima update
        {
           maxRate = myRate;
           if (rate_flags & eHAL_TX_RATE_LEGACY)
           {
              maxSpeedMCS = 0;
           }
           else
           {
              maxSpeedMCS = 1;
              maxMCSIdx = pAdapter->hdd_stats.ClassA_stat.mcs_index;
           }
        }

<<<<<<< HEAD
<<<<<<< HEAD
        if (!maxSpeedMCS)
=======
        if (rate_flags & eHAL_TX_RATE_LEGACY)
>>>>>>> d97af3b... add prima wlan driver
=======
        if (!maxSpeedMCS)
>>>>>>> 657b0e9... prima update
        {
            sinfo->txrate.legacy  = maxRate;
#ifdef LINKSPEED_DEBUG_ENABLED
            pr_info("Reporting legacy rate %d\n", sinfo->txrate.legacy);
#endif //LINKSPEED_DEBUG_ENABLED
        }
        else
        {
            sinfo->txrate.mcs    = maxMCSIdx;
<<<<<<< HEAD
<<<<<<< HEAD
            sinfo->txrate.flags |= RATE_INFO_FLAGS_MCS;
            if (rate_flags & eHAL_TX_RATE_SGI)
            {
                sinfo->txrate.flags |= RATE_INFO_FLAGS_SHORT_GI;
            }
            if (rate_flags & eHAL_TX_RATE_HT40)
            {
                sinfo->txrate.flags |= RATE_INFO_FLAGS_40_MHZ_WIDTH;
            }
=======
#ifdef WLAN_FEATURE_11AC
            sinfo->txrate.nss = 1;
            if (rate_flags & eHAL_TX_RATE_VHT80)
=======
            sinfo->txrate.flags |= RATE_INFO_FLAGS_MCS;
            if (rate_flags & eHAL_TX_RATE_SGI)
>>>>>>> 657b0e9... prima update
            {
                sinfo->txrate.flags |= RATE_INFO_FLAGS_SHORT_GI;
            }
            if (rate_flags & eHAL_TX_RATE_HT40)
            {
                sinfo->txrate.flags |= RATE_INFO_FLAGS_40_MHZ_WIDTH;
            }
<<<<<<< HEAD
            else if (rate_flags & eHAL_TX_RATE_VHT20)
            {
                sinfo->txrate.flags |= RATE_INFO_FLAGS_VHT_MCS;
            }
#endif /* WLAN_FEATURE_11AC */
            if (rate_flags & (eHAL_TX_RATE_HT20 | eHAL_TX_RATE_HT40))
            {
                sinfo->txrate.flags |= RATE_INFO_FLAGS_MCS;
                if (rate_flags & eHAL_TX_RATE_HT40)
                {
                    sinfo->txrate.flags |= RATE_INFO_FLAGS_40_MHZ_WIDTH;
                }
            }
            if (rate_flags & eHAL_TX_RATE_SGI)
            {
                sinfo->txrate.flags |= RATE_INFO_FLAGS_SHORT_GI;
            }

>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
#ifdef LINKSPEED_DEBUG_ENABLED
            pr_info("Reporting MCS rate %d flags %x\n",
                    sinfo->txrate.mcs,
                    sinfo->txrate.flags );
#endif //LINKSPEED_DEBUG_ENABLED
        }
    }
    else
    {
        // report current rate instead of max rate

        if (rate_flags & eHAL_TX_RATE_LEGACY)
        {
            //provide to the UI in units of 100kbps
            sinfo->txrate.legacy = myRate;
#ifdef LINKSPEED_DEBUG_ENABLED
            pr_info("Reporting actual legacy rate %d\n", sinfo->txrate.legacy);
#endif //LINKSPEED_DEBUG_ENABLED
        }
        else
        {
            //must be MCS
            sinfo->txrate.mcs = pAdapter->hdd_stats.ClassA_stat.mcs_index;
<<<<<<< HEAD
<<<<<<< HEAD
            sinfo->txrate.flags |= RATE_INFO_FLAGS_MCS;
=======
#ifdef WLAN_FEATURE_11AC
            sinfo->txrate.nss = 1;
            if (rate_flags & eHAL_TX_RATE_VHT80)
            {
                sinfo->txrate.flags |= RATE_INFO_FLAGS_VHT_MCS;
            }
            else
#endif /* WLAN_FEATURE_11AC */
            {
                sinfo->txrate.flags |= RATE_INFO_FLAGS_MCS;
            }
>>>>>>> d97af3b... add prima wlan driver
=======
            sinfo->txrate.flags |= RATE_INFO_FLAGS_MCS;
>>>>>>> 657b0e9... prima update
            if (rate_flags & eHAL_TX_RATE_SGI)
            {
                sinfo->txrate.flags |= RATE_INFO_FLAGS_SHORT_GI;
            }
            if (rate_flags & eHAL_TX_RATE_HT40)
            {
                sinfo->txrate.flags |= RATE_INFO_FLAGS_40_MHZ_WIDTH;
            }
<<<<<<< HEAD
<<<<<<< HEAD
=======
#ifdef WLAN_FEATURE_11AC
            else if (rate_flags & eHAL_TX_RATE_VHT80)
            {
                sinfo->txrate.flags |= RATE_INFO_FLAGS_80_MHZ_WIDTH;
            }
#endif /* WLAN_FEATURE_11AC */
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
#ifdef LINKSPEED_DEBUG_ENABLED
            pr_info("Reporting actual MCS rate %d flags %x\n",
                    sinfo->txrate.mcs,
                    sinfo->txrate.flags );
#endif //LINKSPEED_DEBUG_ENABLED
        }
    }
    sinfo->filled |= STATION_INFO_TX_BITRATE;

    sinfo->tx_packets =
       pAdapter->hdd_stats.summary_stat.tx_frm_cnt[0] +
       pAdapter->hdd_stats.summary_stat.tx_frm_cnt[1] +
       pAdapter->hdd_stats.summary_stat.tx_frm_cnt[2] +
       pAdapter->hdd_stats.summary_stat.tx_frm_cnt[3];

    sinfo->tx_retries =
       pAdapter->hdd_stats.summary_stat.retry_cnt[0] +
       pAdapter->hdd_stats.summary_stat.retry_cnt[1] +
       pAdapter->hdd_stats.summary_stat.retry_cnt[2] +
       pAdapter->hdd_stats.summary_stat.retry_cnt[3];

    sinfo->tx_failed =
       pAdapter->hdd_stats.summary_stat.fail_cnt[0] +
       pAdapter->hdd_stats.summary_stat.fail_cnt[1] +
       pAdapter->hdd_stats.summary_stat.fail_cnt[2] +
       pAdapter->hdd_stats.summary_stat.fail_cnt[3];

    sinfo->filled |=
       STATION_INFO_TX_PACKETS |
       STATION_INFO_TX_RETRIES |
       STATION_INFO_TX_FAILED;

       EXIT();
       return 0;
}

static int wlan_hdd_cfg80211_set_power_mgmt(struct wiphy *wiphy,
<<<<<<< HEAD
<<<<<<< HEAD
                     struct net_device *dev, bool mode, v_SINT_t timeout)
{
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
    VOS_STATUS vos_status;
=======
                     struct net_device *dev, bool mode, int timeout)
=======
                     struct net_device *dev, bool mode, v_SINT_t timeout)
>>>>>>> 657b0e9... prima update
{
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
    VOS_STATUS vos_status;
<<<<<<< HEAD
    int status;
>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update

    ENTER();

    if (NULL == pAdapter)
    {
        hddLog(VOS_TRACE_LEVEL_ERROR, "%s: Adapter is NULL\n", __func__);
        return -ENODEV;
    }
<<<<<<< HEAD
<<<<<<< HEAD
    if ( (WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress )
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                "%s:LOGP in Progress. Ignore!!!", __func__);
        return -EAGAIN;
    }

    /**The get power cmd from the supplicant gets updated by the nl only
     *on successful execution of the function call
     *we are oppositely mapped w.r.t mode in the driver
     **/
    vos_status =  wlan_hdd_enter_bmps(pAdapter, !mode);

    EXIT();
=======

    pHddCtx = WLAN_HDD_GET_CTX(pAdapter);
    status = wlan_hdd_validate_context(pHddCtx);

    if (0 != status)
    {
        VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                   "%s: HDD context is not valid", __func__);
        return status;
    }

    if ((DRIVER_POWER_MODE_AUTO == !mode) &&
        (TRUE == pHddCtx->hdd_wlan_suspended) &&
        (pHddCtx->cfg_ini->fhostArpOffload) &&
        (eConnectionState_Associated ==
             (WLAN_HDD_GET_STATION_CTX_PTR(pAdapter))->conn_info.connState))
=======
    if ( (WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress )
>>>>>>> 657b0e9... prima update
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                "%s:LOGP in Progress. Ignore!!!", __func__);
        return -EAGAIN;
    }

    /**The get power cmd from the supplicant gets updated by the nl only
     *on successful execution of the function call
     *we are oppositely mapped w.r.t mode in the driver
     **/
    vos_status =  wlan_hdd_enter_bmps(pAdapter, !mode);

    EXIT();
>>>>>>> d97af3b... add prima wlan driver
    if (VOS_STATUS_E_FAILURE == vos_status)
    {
        return -EINVAL;
    }
    return 0;
}


#if (LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,38))
static int wlan_hdd_set_default_mgmt_key(struct wiphy *wiphy,
                         struct net_device *netdev,
                         u8 key_index)
{
    ENTER();
    return 0;
}
<<<<<<< HEAD
<<<<<<< HEAD
#endif //LINUX_VERSION_CODE 
=======
#endif //LINUX_VERSION_CODE
>>>>>>> d97af3b... add prima wlan driver
=======
#endif //LINUX_VERSION_CODE 
>>>>>>> 657b0e9... prima update

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(3,4,0))
static int wlan_hdd_set_txq_params(struct wiphy *wiphy,
                   struct net_device *dev,
                   struct ieee80211_txq_params *params)
{
    ENTER();
    return 0;
}
#elif (LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,38))
static int wlan_hdd_set_txq_params(struct wiphy *wiphy,
                   struct ieee80211_txq_params *params)
{
    ENTER();
    return 0;
}
#endif //LINUX_VERSION_CODE

static int wlan_hdd_cfg80211_del_station(struct wiphy *wiphy,
                                         struct net_device *dev, u8 *mac)
{
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
<<<<<<< HEAD
<<<<<<< HEAD

    ENTER();
    if ( NULL == pAdapter || NULL == pAdapter->pHddCtx)
    {
        hddLog(VOS_TRACE_LEVEL_FATAL, "%s: Invalid Adapter or HDD Context " ,__func__);
        return -EINVAL;
    }

    if (((hdd_context_t*)pAdapter->pHddCtx)->isLoadUnloadInProgress)
    {
         hddLog( LOGE,
                 "%s: Wlan Load/Unload is in progress", __func__);
         return -EBUSY;
    }

    if ( (WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress )
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                "%s:LOGP in Progress. Ignore!!!", __func__);
        return -EAGAIN;
    }

    if ( (WLAN_HDD_SOFTAP == pAdapter->device_mode)
#ifdef WLAN_FEATURE_P2P
       || (WLAN_HDD_P2P_GO == pAdapter->device_mode)
#endif
=======
    hdd_context_t *pHddCtx;
    VOS_STATUS vos_status;
    int status;
    v_U8_t staId;
=======
>>>>>>> 657b0e9... prima update

    ENTER();
    if ( NULL == pAdapter || NULL == pAdapter->pHddCtx)
    {
        hddLog(VOS_TRACE_LEVEL_FATAL, "%s: Invalid Adapter or HDD Context " ,__func__);
        return -EINVAL;
    }

    if (((hdd_context_t*)pAdapter->pHddCtx)->isLoadUnloadInProgress)
    {
         hddLog( LOGE,
                 "%s: Wlan Load/Unload is in progress", __func__);
         return -EBUSY;
    }

    if ( (WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress )
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                "%s:LOGP in Progress. Ignore!!!", __func__);
        return -EAGAIN;
    }

    if ( (WLAN_HDD_SOFTAP == pAdapter->device_mode)
#ifdef WLAN_FEATURE_P2P
       || (WLAN_HDD_P2P_GO == pAdapter->device_mode)
<<<<<<< HEAD
>>>>>>> d97af3b... add prima wlan driver
=======
#endif
>>>>>>> 657b0e9... prima update
       )
    {
        if( NULL == mac )
        {
            v_U16_t i;
            for(i = 0; i < WLAN_MAX_STA_COUNT; i++)
            {
<<<<<<< HEAD
<<<<<<< HEAD
                if(pAdapter->aStaInfo[i].isUsed)
=======
                if ((pAdapter->aStaInfo[i].isUsed) &&
                    (!pAdapter->aStaInfo[i].isDeauthInProgress))
>>>>>>> d97af3b... add prima wlan driver
=======
                if(pAdapter->aStaInfo[i].isUsed)
>>>>>>> 657b0e9... prima update
                {
                    u8 *macAddr = pAdapter->aStaInfo[i].macAddrSTA.bytes;
                    hddLog(VOS_TRACE_LEVEL_INFO,
                                        "%s: Delete STA with MAC::"
                                        "%02x:%02x:%02x:%02x:%02x:%02x",
                                        __func__,
                                        macAddr[0], macAddr[1], macAddr[2],
                                        macAddr[3], macAddr[4], macAddr[5]);
<<<<<<< HEAD
<<<<<<< HEAD
                    hdd_softap_sta_deauth(pAdapter, macAddr);
=======
                    vos_status = hdd_softap_sta_deauth(pAdapter, macAddr);
                    if (VOS_IS_STATUS_SUCCESS(vos_status))
                        pAdapter->aStaInfo[i].isDeauthInProgress = TRUE;
>>>>>>> d97af3b... add prima wlan driver
=======
                    hdd_softap_sta_deauth(pAdapter, macAddr);
>>>>>>> 657b0e9... prima update
                }
            }
        }
        else
        {
<<<<<<< HEAD
<<<<<<< HEAD
=======

            vos_status = hdd_softap_GetStaId(pAdapter,(v_MACADDR_t *)mac, &staId);
            if (!VOS_IS_STATUS_SUCCESS(vos_status))
            {
                hddLog(VOS_TRACE_LEVEL_INFO,
                                "%s: Skip this DEL STA as this is not used::"
                                "%02x:%02x:%02x:%02x:%02x:%02x",
                                __func__,
                                mac[0], mac[1], mac[2],
                                mac[3], mac[4], mac[5]);
                return -ENOENT;
            }

            if( pAdapter->aStaInfo[staId].isDeauthInProgress == TRUE)
            {
                hddLog(VOS_TRACE_LEVEL_INFO,
                                "%s: Skip this DEL STA as deauth is in progress::"
                                "%02x:%02x:%02x:%02x:%02x:%02x",
                                __func__,
                                mac[0], mac[1], mac[2],
                                mac[3], mac[4], mac[5]);
                return -ENOENT;
            }

            pAdapter->aStaInfo[staId].isDeauthInProgress = TRUE;

>>>>>>> d97af3b... add prima wlan driver
=======
>>>>>>> 657b0e9... prima update
            hddLog(VOS_TRACE_LEVEL_INFO,
                                "%s: Delete STA with MAC::"
                                "%02x:%02x:%02x:%02x:%02x:%02x",
                                __func__,
                                mac[0], mac[1], mac[2],
                                mac[3], mac[4], mac[5]);
<<<<<<< HEAD
<<<<<<< HEAD
            hdd_softap_sta_deauth(pAdapter, mac);
=======

            vos_status = hdd_softap_sta_deauth(pAdapter, mac);
            if (!VOS_IS_STATUS_SUCCESS(vos_status))
            {
                pAdapter->aStaInfo[staId].isDeauthInProgress = FALSE;
                hddLog(VOS_TRACE_LEVEL_INFO,
                                "%s: STA removal failed for ::"
                                "%02x:%02x:%02x:%02x:%02x:%02x",
                                __func__,
                                mac[0], mac[1], mac[2],
                                mac[3], mac[4], mac[5]);
                return -ENOENT;
            }

>>>>>>> d97af3b... add prima wlan driver
        }
    }

    EXIT();

    return 0;
}

static int wlan_hdd_cfg80211_add_station(struct wiphy *wiphy,
          struct net_device *dev, u8 *mac, struct station_parameters *params)
{
<<<<<<< HEAD
    // TODO: Implement this later.
    ENTER();
    return 0;
=======
    int status = -EPERM;
#ifdef FEATURE_WLAN_TDLS
    u32 mask, set;
    ENTER();
    mask = params->sta_flags_mask;

    set = params->sta_flags_set;

#ifdef WLAN_FEATURE_TDLS_DEBUG
    VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
               "%s: mask 0x%x set 0x%x " MAC_ADDRESS_STR,
               __func__, mask, set, MAC_ADDR_ARRAY(mac));
#endif

    if (mask & BIT(NL80211_STA_FLAG_TDLS_PEER)) {
        if (set & BIT(NL80211_STA_FLAG_TDLS_PEER)) {
            status = wlan_hdd_tdls_add_station(wiphy, dev, mac, 0, NULL);
        }
    }
#endif
    return status;
>>>>>>> d97af3b... add prima wlan driver
}


#ifdef FEATURE_WLAN_LFR
<<<<<<< HEAD
static int wlan_hdd_cfg80211_set_pmksa(struct wiphy *wiphy, struct net_device *dev,
            struct cfg80211_pmksa *pmksa)
{
#define MAX_PMKSAIDS_IN_CACHE 8
    static tPmkidCacheInfo PMKIDCache[MAX_PMKSAIDS_IN_CACHE]; // HDD Local cache
    static tANI_U32 i = 0; // HDD Local Cache index 
    tANI_U32 j=0;  
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
    tHalHandle halHandle;
    eHalStatus result; 
    tANI_U8  BSSIDMatched = 0;
   
    ENTER();

    // Validate pAdapter  
    if ( NULL == pAdapter || NULL == pAdapter->pHddCtx)
    {
        hddLog(VOS_TRACE_LEVEL_FATAL, "%s: Invalid Adapter or HDD Context " ,__func__);
        return -EINVAL;
    }

    if (((hdd_context_t*)pAdapter->pHddCtx)->isLoadUnloadInProgress)
    {
         hddLog( LOGE,
                 "%s: Wlan Load/Unload is in progress", __func__);
         return -EBUSY;
    }

    if ( (WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress )
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                "%s:LOGP in Progress. Ignore!!!", __func__);
        return -EAGAIN;
    }

    // Retrieve halHandle  
    halHandle = WLAN_HDD_GET_HAL_CTX(pAdapter);

    for (j = 0; j < i; j++)
    {
        if(vos_mem_compare(PMKIDCache[j].BSSID, 
=======
#define MAX_PMKSAIDS_IN_CACHE 8

static tPmkidCacheInfo PMKIDCache[MAX_PMKSAIDS_IN_CACHE]; // HDD local cache
static tANI_U32 PMKIDCacheIndex; // HDD local Cache index


static int wlan_hdd_cfg80211_set_pmksa(struct wiphy *wiphy, struct net_device *dev,
            struct cfg80211_pmksa *pmksa)
{
    tANI_U32 j=0;
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
    tHalHandle halHandle;
    eHalStatus result;
    int status;
    tANI_U8  BSSIDMatched = 0;
    hdd_context_t *pHddCtx;

    ENTER();

    // Validate pAdapter
    if ( NULL == pAdapter )
    {
        hddLog(VOS_TRACE_LEVEL_ERROR, "%s: Invalid Adapter" ,__func__);
        return -EINVAL;
    }

    pHddCtx = WLAN_HDD_GET_CTX(pAdapter);
    status = wlan_hdd_validate_context(pHddCtx);

    if (0 != status)
    {
        VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                   "%s: HDD context is not valid", __func__);
        return status;
    }

    // Retrieve halHandle
    halHandle = WLAN_HDD_GET_HAL_CTX(pAdapter);

    for (j = 0; j < PMKIDCacheIndex; j++)
    {
        if(vos_mem_compare(PMKIDCache[j].BSSID,
>>>>>>> d97af3b... add prima wlan driver
                    pmksa->bssid, WNI_CFG_BSSID_LEN))
        {
            /* BSSID matched previous entry.  Overwrite it. */
            BSSIDMatched = 1;
<<<<<<< HEAD
            vos_mem_copy(PMKIDCache[j].BSSID, 
                    pmksa->bssid, WNI_CFG_BSSID_LEN);
            vos_mem_copy(PMKIDCache[j].PMKID, 
                    pmksa->pmkid,   
                    CSR_RSN_PMKID_SIZE);
            hddLog(VOS_TRACE_LEVEL_FATAL, "%s: Reusing cache entry %d.", 
                    __FUNCTION__, j );
=======
            vos_mem_copy(PMKIDCache[j].BSSID,
                    pmksa->bssid, WNI_CFG_BSSID_LEN);
            vos_mem_copy(PMKIDCache[j].PMKID,
                    pmksa->pmkid,
                    CSR_RSN_PMKID_SIZE);
            hddLog(VOS_TRACE_LEVEL_FATAL, "%s: Reusing cache entry %d.",
                    __func__, j );
>>>>>>> d97af3b... add prima wlan driver
            dump_bssid(pmksa->bssid);
            dump_pmkid(halHandle, pmksa->pmkid);
            break;
        }
    }

    /* Check we compared all entries,if then take the first slot now */
<<<<<<< HEAD
    if(j == MAX_PMKSAIDS_IN_CACHE) i=0;

    if (!BSSIDMatched)
    { 
        // Now, we DON'T have a BSSID match, so take a new entry in the cache.  
        vos_mem_copy(PMKIDCache[i].BSSID, 
                pmksa->bssid, ETHER_ADDR_LEN); 
        vos_mem_copy(PMKIDCache[i].PMKID, 
                pmksa->pmkid,   
                CSR_RSN_PMKID_SIZE);
        hddLog(VOS_TRACE_LEVEL_FATAL, "%s: Adding a new cache entry %d.", 
                __FUNCTION__, i );
        dump_bssid(pmksa->bssid);
        dump_pmkid(halHandle, pmksa->pmkid);
        // Increment the HDD Local Cache index 
        // The "i=0" doesn't work for the call to sme_RoamSetPMKIDCache() - LFR FIXME
        if (i<=(MAX_PMKSAIDS_IN_CACHE-1)) i++; else i=0; 
=======
    if(j == MAX_PMKSAIDS_IN_CACHE) PMKIDCacheIndex=0;

    if (!BSSIDMatched)
    {
        // Now, we DON'T have a BSSID match, so take a new entry in the cache.
        vos_mem_copy(PMKIDCache[PMKIDCacheIndex].BSSID,
                pmksa->bssid, ETHER_ADDR_LEN);
        vos_mem_copy(PMKIDCache[PMKIDCacheIndex].PMKID,
                pmksa->pmkid,
                CSR_RSN_PMKID_SIZE);
        hddLog(VOS_TRACE_LEVEL_FATAL, "%s: Adding a new cache entry %d.",
                __func__, PMKIDCacheIndex );
        dump_bssid(pmksa->bssid);
        dump_pmkid(halHandle, pmksa->pmkid);
        // Increment the HDD Local Cache index
        // The "i=0" doesn't work for the call to sme_RoamSetPMKIDCache() - LFR FIXME
        if (PMKIDCacheIndex <= (MAX_PMKSAIDS_IN_CACHE-1)) PMKIDCacheIndex++; else PMKIDCacheIndex = 0;
>>>>>>> d97af3b... add prima wlan driver
    }


    // Calling csrRoamSetPMKIDCache to configure the PMKIDs into the cache
<<<<<<< HEAD
    //hddLog(LOG1, FL("%s: Calling csrRoamSetPMKIDCache with %d cache entries."), 
    //        __FUNCTION__, i );
    hddLog(VOS_TRACE_LEVEL_FATAL, "%s: Calling csrRoamSetPMKIDCache with %d cache entries.", 
            __FUNCTION__, i );
    // Finally set the PMKSA ID Cache in CSR
    result = sme_RoamSetPMKIDCache(halHandle,pAdapter->sessionId, 
                                    PMKIDCache, 
                                    i );
=======
    //hddLog(LOG1, FL("%s: Calling csrRoamSetPMKIDCache with %d cache entries."),
    //        __func__, i );
    hddLog(VOS_TRACE_LEVEL_FATAL, "%s: Calling csrRoamSetPMKIDCache with %d cache entries.",
            __func__, PMKIDCacheIndex );
    // Finally set the PMKSA ID Cache in CSR
    result = sme_RoamSetPMKIDCache(halHandle,pAdapter->sessionId,
                                    PMKIDCache,
                                    PMKIDCacheIndex);
>>>>>>> d97af3b... add prima wlan driver
    return 0;
}


<<<<<<< HEAD
static int wlan_hdd_cfg80211_del_pmksa(struct wiphy *wiphy, struct net_device *dev,
            struct cfg80211_pmksa *pmksa)
{
    ENTER();
    // TODO: Implement this later.
    return 0;
}

static int wlan_hdd_cfg80211_flush_pmksa(struct wiphy *wiphy, struct net_device *dev)
{
    ENTER();
    // TODO: Implement this later.
    return 0;
}
#endif


/* cfg80211_ops */
static struct cfg80211_ops wlan_hdd_cfg80211_ops = 
{
    .add_virtual_intf = wlan_hdd_add_virtual_intf,
    .del_virtual_intf = wlan_hdd_del_virtual_intf,
    .change_virtual_intf = wlan_hdd_cfg80211_change_iface,
    .change_station = wlan_hdd_change_station,
#if (LINUX_VERSION_CODE < KERNEL_VERSION(3,4,0))
    .add_beacon = wlan_hdd_cfg80211_add_beacon,
    .del_beacon = wlan_hdd_cfg80211_del_beacon,
    .set_beacon = wlan_hdd_cfg80211_set_beacon,
#else
    .start_ap = wlan_hdd_cfg80211_start_ap,
    .change_beacon = wlan_hdd_cfg80211_change_beacon,
    .stop_ap = wlan_hdd_cfg80211_stop_ap,
#endif
    .change_bss = wlan_hdd_cfg80211_change_bss,
    .add_key = wlan_hdd_cfg80211_add_key,
    .get_key = wlan_hdd_cfg80211_get_key,
    .del_key = wlan_hdd_cfg80211_del_key,
    .set_default_key = wlan_hdd_cfg80211_set_default_key,
    .set_channel = wlan_hdd_cfg80211_set_channel,
    .scan = wlan_hdd_cfg80211_scan,
    .connect = wlan_hdd_cfg80211_connect,
    .disconnect = wlan_hdd_cfg80211_disconnect,
    .join_ibss  = wlan_hdd_cfg80211_join_ibss,
    .leave_ibss = wlan_hdd_cfg80211_leave_ibss,
    .set_wiphy_params = wlan_hdd_cfg80211_set_wiphy_params,
    .set_tx_power = wlan_hdd_cfg80211_set_txpower,
    .get_tx_power = wlan_hdd_cfg80211_get_txpower,
#ifdef WLAN_FEATURE_P2P
    .remain_on_channel = wlan_hdd_cfg80211_remain_on_channel,
    .cancel_remain_on_channel =  wlan_hdd_cfg80211_cancel_remain_on_channel,
    .mgmt_tx =  wlan_hdd_action,
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,38))
     .mgmt_tx_cancel_wait = wlan_hdd_cfg80211_mgmt_tx_cancel_wait,
     .set_default_mgmt_key = wlan_hdd_set_default_mgmt_key,
     .set_txq_params = wlan_hdd_set_txq_params,
#endif
#endif
     .get_station = wlan_hdd_cfg80211_get_station,
     .set_power_mgmt = wlan_hdd_cfg80211_set_power_mgmt,
     .del_station  = wlan_hdd_cfg80211_del_station,
     .add_station  = wlan_hdd_cfg80211_add_station,
#ifdef FEATURE_WLAN_LFR
     .set_pmksa = wlan_hdd_cfg80211_set_pmksa,
     .del_pmksa = wlan_hdd_cfg80211_del_pmksa,
     .flush_pmksa = wlan_hdd_cfg80211_flush_pmksa,
#endif
};

#endif // CONFIG_CFG80211
=======

static int wlan_hdd_cfg80211_del_pmksa(struct wiphy *wiphy, struct net_device *dev,
             struct cfg80211_pmksa *pmksa)
{
    tANI_U32 j=0;
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
    tHalHandle halHandle;
    int status;
    tANI_U8  BSSIDMatched = 0;
    tANI_U8 *pBSSId;
    hdd_context_t *pHddCtx;
    int result = 0;

    hddLog(VOS_TRACE_LEVEL_DEBUG, "%s: deleting PMKSA with PMKSA_ID %d .",
            __func__,pmksa->pmkid);

    /* Validate pAdapter */
    if (NULL == pAdapter)
    {
       hddLog(VOS_TRACE_LEVEL_ERROR, "%s: Invalid Adapter" ,__func__);
       return -EINVAL;
    }

    pHddCtx = WLAN_HDD_GET_CTX(pAdapter);
    status = wlan_hdd_validate_context(pHddCtx);

    if (0 != status)
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                   "%s: HDD context is not valid", __func__);
        return status;
    }

    /*Retrieve halHandle*/
    halHandle = WLAN_HDD_GET_HAL_CTX(pAdapter);

    /*in case index is 0,no entry to delete*/
    if (0 == PMKIDCacheIndex)
    {
        hddLog(VOS_TRACE_LEVEL_ERROR, "%s: Invalid entry to delete" ,
              __func__);
        return -EINVAL;
    }

    /*find the matching PMKSA entry from j=0 to (index-1),
     * and delete the matched one
     */
    for (j = 0; j<PMKIDCacheIndex; j++)
    {
          if (vos_mem_compare(PMKIDCache[j].BSSID,
                             pmksa->bssid,
                             WNI_CFG_BSSID_LEN))
          {
             /* BSSID matched entry */
             BSSIDMatched = 1;

             if (j<PMKIDCacheIndex-1)
             {
                 /*replace the matching entry with the last entry in HDD local cache*/
                 vos_mem_copy(PMKIDCache[j].BSSID,
                              PMKIDCache[PMKIDCacheIndex-1].BSSID,
                              WNI_CFG_BSSID_LEN);
                 vos_mem_copy(PMKIDCache[j].PMKID,
                              PMKIDCache[PMKIDCacheIndex-1].PMKID,
                              CSR_RSN_PMKID_SIZE);
              }

             /*clear the last entry in HDD cache ---[index-1]*/
             pBSSId =(tANI_U8 *)(PMKIDCache[PMKIDCacheIndex-1].BSSID);
             vos_mem_zero(PMKIDCache[PMKIDCacheIndex-1].BSSID, WNI_CFG_BSSID_LEN);
             vos_mem_zero(PMKIDCache[PMKIDCacheIndex-1].PMKID, CSR_RSN_PMKID_SIZE);

             /*reduce the PMKID array index*/
             PMKIDCacheIndex--;

             /*delete the last PMKID cache in CSR*/
             result = sme_RoamDelPMKIDfromCache(halHandle, pAdapter->sessionId, pBSSId);
             if (0 != result)
             {
                hddLog(VOS_TRACE_LEVEL_ERROR,"%s: cannot delete PMKSA %d CONTENT.",
                          __func__,PMKIDCacheIndex);
             }

             dump_bssid(pmksa->bssid);
             dump_pmkid(halHandle,pmksa->pmkid);

             break;
          }
    }

    /* we compare all entries,but cannot find matching entry */
    if (j == MAX_PMKSAIDS_IN_CACHE && !BSSIDMatched)
    {
       hddLog(VOS_TRACE_LEVEL_FATAL, "%s: No such PMKSA entry existed %d.",
             __func__,pmksa->bssid);
       dump_bssid(pmksa->bssid);
       dump_pmkid(halHandle, pmksa->pmkid);
       return -EINVAL;
    }
   return result;
}



static int wlan_hdd_cfg80211_flush_pmksa(struct wiphy *wiphy, struct net_device *dev)
{
    tANI_U32 j=0;
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
    tHalHandle halHandle;
    hdd_context_t *pHddCtx;
    tANI_U8 *pBSSId;
    int status;
    int result;

    hddLog(VOS_TRACE_LEVEL_DEBUG, "%s: flushing PMKSA ",__func__);

    /* Validate pAdapter */
    if (NULL == pAdapter)
    {
        hddLog(VOS_TRACE_LEVEL_ERROR,
               "%s: Invalid Adapter" ,__func__);
       return -EINVAL;
    }

    pHddCtx = WLAN_HDD_GET_CTX(pAdapter);
    status = wlan_hdd_validate_context(pHddCtx);

    if (0 != status)
    {
       hddLog(VOS_TRACE_LEVEL_ERROR,
              "%s: HDD context is not valid", __func__);
       return status;
    }

    /*Retrieve halHandle*/
    halHandle = WLAN_HDD_GET_HAL_CTX(pAdapter);

    /*in case index is 0,no entry to delete*/
    if (0 == PMKIDCacheIndex)
    {
       hddLog(VOS_TRACE_LEVEL_ERROR, "%s: Invalid entry to delete" ,
              __func__);
       return -EINVAL;
    }

    /*delete all the PMKSA one by one */
    for (j = 0; j<PMKIDCacheIndex; j++)
    {
          /*clear the entry in HDD cache 0--index-1 */
          pBSSId =(tANI_U8 *)(PMKIDCache[j].BSSID);
          vos_mem_zero(PMKIDCache[j].BSSID, WNI_CFG_BSSID_LEN);
          vos_mem_zero(PMKIDCache[j].PMKID, CSR_RSN_PMKID_SIZE);

          /*delete the PMKID in CSR*/
          result = sme_RoamDelPMKIDfromCache(halHandle, pAdapter->sessionId, pBSSId);

          if (0!= result)
          {
             hddLog(VOS_TRACE_LEVEL_ERROR ,"%s cannot flush PMKIDCache %d.",
                    __func__,j);
          }
      }

    PMKIDCacheIndex = 0;
    return result;
}
#endif

#if defined(WLAN_FEATURE_VOWIFI_11R) && defined(KERNEL_SUPPORT_11R_CFG80211)
static int wlan_hdd_cfg80211_update_ft_ies(struct wiphy *wiphy,
          struct net_device *dev, struct cfg80211_update_ft_ies_params *ftie)
{
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
    hdd_station_ctx_t *pHddStaCtx;

    if (NULL == pAdapter)
    {
        hddLog(VOS_TRACE_LEVEL_ERROR, "%s: Adapter is NULL\n", __func__);
        return -ENODEV;
    }

    pHddStaCtx = WLAN_HDD_GET_STATION_CTX_PTR(pAdapter);

    // Added for debug on reception of Re-assoc Req.
    if (eConnectionState_Associated != pHddStaCtx->conn_info.connState)
    {
        hddLog(LOGE, FL("Called with Ie of length = %d when not associated\n"),
               ftie->ie_len);
        hddLog(LOGE, FL("Should be Re-assoc Req IEs\n"));
    }

#ifdef WLAN_FEATURE_VOWIFI_11R_DEBUG
    hddLog(LOGE, FL("%s called with Ie of length = %d\n"), __func__,
           ftie->ie_len);
#endif

    // Pass the received FT IEs to SME
    sme_SetFTIEs( WLAN_HDD_GET_HAL_CTX(pAdapter), pAdapter->sessionId,
                  (const u8 *)ftie->ie,
                  ftie->ie_len);
    return 0;
}
#endif

#ifdef FEATURE_WLAN_SCAN_PNO

void hdd_cfg80211_sched_scan_done_callback(void *callbackContext,
                              tSirPrefNetworkFoundInd *pPrefNetworkFoundInd)
{
    int ret;
    hdd_adapter_t* pAdapter = (hdd_adapter_t*)callbackContext;
    hdd_context_t *pHddCtx;

    if (NULL == pAdapter)
    {
        VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL,
                   "%s: HDD adapter is Null", __func__);
        return ;
    }

    pHddCtx = WLAN_HDD_GET_CTX(pAdapter);
    if (NULL == pHddCtx)
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                "%s: HDD context is Null!!!", __func__);
        return ;
    }

    spin_lock(&pHddCtx->schedScan_lock);
    if (TRUE == pHddCtx->isWiphySuspended)
    {
        pHddCtx->isSchedScanUpdatePending = TRUE;
        spin_unlock(&pHddCtx->schedScan_lock);
        hddLog(VOS_TRACE_LEVEL_INFO,
               "%s: Update cfg80211 scan database after it resume", __func__);
        return ;
    }
    spin_unlock(&pHddCtx->schedScan_lock);

    ret = wlan_hdd_cfg80211_update_bss(pHddCtx->wiphy, pAdapter);

    if (0 > ret)
        hddLog(VOS_TRACE_LEVEL_INFO, "%s: NO SCAN result", __func__);

    cfg80211_sched_scan_results(pHddCtx->wiphy);
    VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO,
            "%s: cfg80211 scan result database updated", __func__);
}

/*
 * FUNCTION: wlan_hdd_cfg80211_sched_scan_start
 * NL interface to enable PNO
 */
static int wlan_hdd_cfg80211_sched_scan_start(struct wiphy *wiphy,
          struct net_device *dev, struct cfg80211_sched_scan_request *request)
{
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
    tpSirPNOScanReq pPnoRequest = NULL;
    hdd_context_t *pHddCtx;
    tHalHandle hHal;
    v_U32_t i, indx, num_ch, tempInterval;
    u8 valid_ch[WNI_CFG_VALID_CHANNEL_LIST_LEN];
    u8 channels_allowed[WNI_CFG_VALID_CHANNEL_LIST_LEN];
    v_U32_t num_channels_allowed = WNI_CFG_VALID_CHANNEL_LIST_LEN;
    eHalStatus status = eHAL_STATUS_FAILURE;
    int ret = 0;

    if (NULL == pAdapter)
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL,
                  "%s: HDD adapter is Null", __func__);
        return -ENODEV;
    }

    pHddCtx = WLAN_HDD_GET_CTX(pAdapter);
    ret = wlan_hdd_validate_context(pHddCtx);

    if (0 != ret)
    {
        VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                   "%s: HDD context is not valid", __func__);
        return -EINVAL;
    }

    hHal = WLAN_HDD_GET_HAL_CTX(pAdapter);
    if (NULL == hHal)
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                  "%s: HAL context  is Null!!!", __func__);
        return -EINVAL;
    }

    pPnoRequest = (tpSirPNOScanReq) vos_mem_malloc(sizeof (tSirPNOScanReq));
    if (NULL == pPnoRequest)
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL,
                  "%s: vos_mem_malloc failed", __func__);
        return -ENOMEM;
    }

    memset(pPnoRequest, 0, sizeof (tSirPNOScanReq));
    pPnoRequest->enable = 1; /*Enable PNO */
    pPnoRequest->ucNetworksCount = request->n_match_sets;

    if (( !pPnoRequest->ucNetworksCount ) ||
        ( pPnoRequest->ucNetworksCount > SIR_PNO_MAX_SUPP_NETWORKS ))
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                  "Network input is not correct");
        ret = -EINVAL;
        goto error;
    }

    if ( SIR_PNO_MAX_NETW_CHANNELS_EX < request->n_channels )
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                  "Incorrect number of channels");
        ret = -EINVAL;
        goto error;
    }

    /* Framework provides one set of channels(all)
     * common for all saved profile */
    if (0 != ccmCfgGetStr(hHal, WNI_CFG_VALID_CHANNEL_LIST,
            channels_allowed, &num_channels_allowed))
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                "%s: failed to get valid channel list", __func__);
        ret = -EINVAL;
        goto error;
    }
    /* Checking each channel against allowed channel list */
    num_ch = 0;
    for (i = 0; i < request->n_channels; i++)
    {
        for (indx = 0; indx < num_channels_allowed; indx++)
        {
            if (request->channels[i]->hw_value == channels_allowed[indx])
            {
                valid_ch[num_ch++] = request->channels[i]->hw_value;
                break ;
            }
        }
    }

    /* Filling per profile  params */
    for (i = 0; i < pPnoRequest->ucNetworksCount; i++)
    {
        pPnoRequest->aNetworks[i].ssId.length =
               request->match_sets[i].ssid.ssid_len;

        if (( 0 == pPnoRequest->aNetworks[i].ssId.length ) ||
            ( pPnoRequest->aNetworks[i].ssId.length > 32 ) )
        {
            VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                      "SSID Len %d is not correct for network %d",
                      pPnoRequest->aNetworks[i].ssId.length, i);
            ret = -EINVAL;
            goto error;
        }

        memcpy(pPnoRequest->aNetworks[i].ssId.ssId,
               request->match_sets[i].ssid.ssid,
               request->match_sets[i].ssid.ssid_len);
        pPnoRequest->aNetworks[i].authentication = 0; /*eAUTH_TYPE_ANY*/
        pPnoRequest->aNetworks[i].encryption     = 0; /*eED_ANY*/
        pPnoRequest->aNetworks[i].bcastNetwType  = 0; /*eBCAST_UNKNOWN*/

        /*Copying list of valid channel into request */
        memcpy(pPnoRequest->aNetworks[i].aChannels, valid_ch, num_ch);
        pPnoRequest->aNetworks[i].ucChannelCount = num_ch;

        pPnoRequest->aNetworks[i].rssiThreshold = 0; //Default value
    }

    VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO,
              "request->ie_len = %d", request->ie_len);
    if ((0 < request->ie_len) && (NULL != request->ie))
    {
        pPnoRequest->us24GProbeTemplateLen = request->ie_len;
        memcpy(&pPnoRequest->p24GProbeTemplate, request->ie,
                pPnoRequest->us24GProbeTemplateLen);

        pPnoRequest->us5GProbeTemplateLen = request->ie_len;
        memcpy(&pPnoRequest->p5GProbeTemplate, request->ie,
                pPnoRequest->us5GProbeTemplateLen);
    }

    /* Driver gets only one time interval which is hardcoded in
     * supplicant for 10000ms. Taking power consumption into account 6 timers
     * will be used, Timervalue is increased exponentially i.e 10,20,40,
     * 80,160,320 secs. And number of scan cycle for each timer
     * is configurable through INI param gPNOScanTimerRepeatValue.
     * If it is set to 0 only one timer will be used and PNO scan cycle
     * will be repeated after each interval specified by supplicant
     * till PNO is disabled.
     */
    if (0 == pHddCtx->cfg_ini->configPNOScanTimerRepeatValue)
        pPnoRequest->scanTimers.ucScanTimersCount = HDD_PNO_SCAN_TIMERS_SET_ONE;
    else
        pPnoRequest->scanTimers.ucScanTimersCount =
                                               HDD_PNO_SCAN_TIMERS_SET_MULTIPLE;

    tempInterval = (request->interval)/1000;
    VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO,
              "Base scan interval = %d PNOScanTimerRepeatValue = %d",
              tempInterval, pHddCtx->cfg_ini->configPNOScanTimerRepeatValue);
    for ( i = 0; i < pPnoRequest->scanTimers.ucScanTimersCount; i++)
    {
        pPnoRequest->scanTimers.aTimerValues[i].uTimerRepeat =
                                 pHddCtx->cfg_ini->configPNOScanTimerRepeatValue;
        pPnoRequest->scanTimers.aTimerValues[i].uTimerValue = tempInterval;
        tempInterval *= 2;
    }
    //Repeat last timer until pno disabled.
    pPnoRequest->scanTimers.aTimerValues[i-1].uTimerRepeat = 0;

    pPnoRequest->modePNO = SIR_PNO_MODE_IMMEDIATE;

    status = sme_SetPreferredNetworkList(WLAN_HDD_GET_HAL_CTX(pAdapter),
                              pPnoRequest, pAdapter->sessionId,
                              hdd_cfg80211_sched_scan_done_callback, pAdapter);
    if (eHAL_STATUS_SUCCESS != status)
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                  "Failed to enable PNO");
        ret = -EINVAL;
        goto error;
    }

    VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO,
                  "PNO scanRequest offloaded");

error:
    vos_mem_free(pPnoRequest);
    return ret;
}

/*
 * FUNCTION: wlan_hdd_cfg80211_sched_scan_stop
 * NL interface to disable PNO
 */
static int wlan_hdd_cfg80211_sched_scan_stop(struct wiphy *wiphy,
          struct net_device *dev)
{
    eHalStatus status = eHAL_STATUS_FAILURE;
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
    hdd_context_t *pHddCtx;
    tHalHandle hHal;
    tpSirPNOScanReq pPnoRequest = NULL;
    int ret = 0;

    ENTER();

    if (NULL == pAdapter)
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL,
                  "%s: HDD adapter is Null", __func__);
        return -ENODEV;
    }

    pHddCtx = WLAN_HDD_GET_CTX(pAdapter);

    if (NULL == pHddCtx)
    {
        VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                "%s: HDD context is Null", __func__);
        return -ENODEV;
    }

    /* The return 0 is intentional when isLogpInProgress and
     * isLoadUnloadInProgress. We did observe a crash due to a return of
     * failure in sched_scan_stop , especially for a case where the unload
     * of the happens at the same time. The function __cfg80211_stop_sched_scan
     * was clearing rdev->sched_scan_req only when the sched_scan_stop returns
     * success. If it returns a failure , then its next invocation due to the
     * clean up of the second interface will have the dev pointer corresponding
     * to the first one leading to a crash.
     */
    if (pHddCtx->isLogpInProgress)
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                  "%s: LOGP in Progress. Ignore!!!", __func__);
        return ret;
    }

    if (pHddCtx->isLoadUnloadInProgress)
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                  "%s: Unloading/Loading in Progress. Ignore!!!", __func__);
        return ret;
    }

    hHal = WLAN_HDD_GET_HAL_CTX(pAdapter);
    if (NULL == hHal)
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                "%s: HAL context  is Null!!!", __func__);
        return -EINVAL;
    }

    pPnoRequest = (tpSirPNOScanReq) vos_mem_malloc(sizeof (tSirPNOScanReq));
    if (NULL == pPnoRequest)
    {
        VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL,
                   "%s: vos_mem_malloc failed", __func__);
        return -ENOMEM;
    }

    memset(pPnoRequest, 0, sizeof (tSirPNOScanReq));
    pPnoRequest->enable = 0; /* Disable PNO */
    pPnoRequest->ucNetworksCount = 0;

    status = sme_SetPreferredNetworkList(hHal, pPnoRequest,
                                pAdapter->sessionId,
                                NULL, pAdapter);
    if (eHAL_STATUS_SUCCESS != status)
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                  "Failed to disabled PNO");
        ret = -EINVAL;
    }

    VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO,
                   "%s: PNO scan disabled", __func__);

    vos_mem_free(pPnoRequest);

    EXIT();
    return ret;
}

#endif /*FEATURE_WLAN_SCAN_PNO*/


#ifdef FEATURE_WLAN_TDLS
static int wlan_hdd_cfg80211_tdls_mgmt(struct wiphy *wiphy, struct net_device *dev,
                     u8 *peer, u8 action_code,  u8 dialog_token,
                                                 u16 status_code, const u8 *buf, size_t len)
{

    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
    hdd_context_t *pHddCtx = wiphy_priv(wiphy);
    u8 peerMac[6];
    VOS_STATUS status;
    int max_sta_failed = 0;
    int responder;
    long rc;

    if (NULL == pHddCtx || NULL == pHddCtx->cfg_ini)
    {
        VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                "Invalid arguments");
        return -EINVAL;
    }

    if (pHddCtx->isLogpInProgress)
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                "%s:LOGP in Progress. Ignore!!!", __func__);
        wlan_hdd_tdls_set_link_status(pAdapter, peer, eTDLS_LINK_IDLE);
        return -EBUSY;
    }

    if (eTDLS_SUPPORT_NOT_ENABLED == pHddCtx->tdls_mode)
    {
         VOS_TRACE( VOS_MODULE_ID_HDD, TDLS_LOG_LEVEL,
                    "%s: TDLS mode is disabled OR not enabled in FW."
                    MAC_ADDRESS_STR " action %d declined.",
                    __func__, MAC_ADDR_ARRAY(peer), action_code);
        return -ENOTSUPP;
    }

    /* other than teardown frame, other mgmt frames are not sent if disabled */
    if (SIR_MAC_TDLS_TEARDOWN != action_code)
    {
       /* if tdls_mode is disabled to respond to peer's request */
        if (eTDLS_SUPPORT_DISABLED == pHddCtx->tdls_mode)
        {
             VOS_TRACE( VOS_MODULE_ID_HDD, TDLS_LOG_LEVEL,
                        "%s: " MAC_ADDRESS_STR
                        " TDLS mode is disabled. action %d declined.",
                        __func__, MAC_ADDR_ARRAY(peer), action_code);

        return -ENOTSUPP;
        }
    }

    if (WLAN_IS_TDLS_SETUP_ACTION(action_code))
    {
        if (NULL != wlan_hdd_tdls_is_progress(pHddCtx, peer, TRUE, TRUE))
        {
            VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                       "%s: " MAC_ADDRESS_STR
                       " TDLS setup is ongoing. action %d declined.",
                       __func__, MAC_ADDR_ARRAY(peer), action_code);
            return -EPERM;
        }
    }

    if (SIR_MAC_TDLS_SETUP_REQ == action_code ||
        SIR_MAC_TDLS_SETUP_RSP == action_code )
    {
        if (HDD_MAX_NUM_TDLS_STA <= wlan_hdd_tdlsConnectedPeers(pAdapter))
        {
            /* supplicant still sends tdls_mgmt(SETUP_REQ) even after
               we return error code at 'add_station()'. Hence we have this
               check again in addtion to add_station().
               Anyway, there is no hard to double-check. */
            if (SIR_MAC_TDLS_SETUP_REQ == action_code)
            {
                VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                           "%s: " MAC_ADDRESS_STR
                           " TDLS Max peer already connected. action %d declined.",
                           __func__, MAC_ADDR_ARRAY(peer), action_code);
                goto error;
            }
            else
            {
                /* maximum reached. tweak to send error code to peer and return
                   error code to supplicant */
                status_code = eSIR_MAC_UNSPEC_FAILURE_STATUS;
                VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                           "%s: " MAC_ADDRESS_STR
                           " TDLS Max peer already connected send response status %d",
                           __func__, MAC_ADDR_ARRAY(peer), status_code);
                max_sta_failed = -EPERM;
                /* fall through to send setup resp with failure status
                code */
            }
        }
        else
        {
            hddTdlsPeer_t *pTdlsPeer;
            pTdlsPeer = wlan_hdd_tdls_find_peer(pAdapter, peer);
            if (pTdlsPeer && TDLS_IS_CONNECTED(pTdlsPeer))
            {
                VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                        "%s:" MAC_ADDRESS_STR " already connected. action %d declined.",
                        __func__, MAC_ADDR_ARRAY(peer), action_code);
                return -EPERM;
            }
        }
    }
    vos_mem_copy(peerMac, peer, 6);

#ifdef WLAN_FEATURE_TDLS_DEBUG
    VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
               "%s: " MAC_ADDRESS_STR " action %d, dialog_token %d status %d, len = %d",
               "tdls_mgmt", MAC_ADDR_ARRAY(peer),
               action_code, dialog_token, status_code, len);
#endif

    /*Except teardown responder will not be used so just make 0*/
    responder = 0;
    if (SIR_MAC_TDLS_TEARDOWN == action_code)
    {

       hddTdlsPeer_t *pTdlsPeer;
       pTdlsPeer = wlan_hdd_tdls_find_peer(pAdapter, peerMac);

       if(pTdlsPeer && TDLS_IS_CONNECTED(pTdlsPeer))
            responder = pTdlsPeer->is_responder;
       else
       {
           VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                    "%s: " MAC_ADDRESS_STR " peer doesn't exist or not connected %d dialog_token %d status %d, len = %d",
                    __func__, MAC_ADDR_ARRAY(peer), (NULL == pTdlsPeer) ? -1 : pTdlsPeer->link_status,
                     dialog_token, status_code, len);
           return -EPERM;
       }
    }

    /* For explicit trigger of DIS_REQ come out of BMPS for
       successfully receiving DIS_RSP from peer. */
    if ((SIR_MAC_TDLS_SETUP_RSP == action_code) ||
        (SIR_MAC_TDLS_DIS_RSP == action_code) ||
        (SIR_MAC_TDLS_DIS_REQ == action_code))
    {
        if (TRUE == sme_IsPmcBmps(WLAN_HDD_GET_HAL_CTX(pAdapter)))
        {
            VOS_TRACE( VOS_MODULE_ID_HDD, TDLS_LOG_LEVEL,
                       "%s: Sending frame action_code %u.Disable BMPS", __func__, action_code);
            hdd_disable_bmps_imps(pHddCtx, WLAN_HDD_INFRA_STATION);
        }
        if (SIR_MAC_TDLS_DIS_REQ != action_code)
            wlan_hdd_tdls_set_cap(pAdapter, peerMac, eTDLS_CAP_SUPPORTED);
    }

    /* make sure doesn't call send_mgmt() while it is pending */
    if (TDLS_CTX_MAGIC == pAdapter->mgmtTxCompletionStatus)
    {
        VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
            "%s: " MAC_ADDRESS_STR " action %d couldn't sent, as one is pending. return EBUSY\n",
            __func__, MAC_ADDR_ARRAY(peer), action_code);
        return -EBUSY;
    }

    pAdapter->mgmtTxCompletionStatus = TDLS_CTX_MAGIC;
    INIT_COMPLETION(pAdapter->tdls_mgmt_comp);

    status = sme_SendTdlsMgmtFrame(WLAN_HDD_GET_HAL_CTX(pAdapter), pAdapter->sessionId,
            peerMac, action_code, dialog_token, status_code, (tANI_U8 *)buf, len, responder);

    if (VOS_STATUS_SUCCESS != status)
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                "%s: sme_SendTdlsMgmtFrame failed!", __func__);
        pAdapter->mgmtTxCompletionStatus = FALSE;
        wlan_hdd_tdls_check_bmps(pAdapter);
        goto error;
    }

    rc = wait_for_completion_interruptible_timeout(&pAdapter->tdls_mgmt_comp,
                                                        msecs_to_jiffies(WAIT_TIME_TDLS_MGMT));

    if ((rc <= 0) || (TRUE != pAdapter->mgmtTxCompletionStatus))
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                  "%s: Mgmt Tx Completion failed status %ld TxCompletion %lu",
                  __func__, rc, pAdapter->mgmtTxCompletionStatus);
        pAdapter->mgmtTxCompletionStatus = FALSE;
        wlan_hdd_tdls_check_bmps(pAdapter);
        goto error;
    }

    if (max_sta_failed)
    {
      wlan_hdd_tdls_check_bmps(pAdapter);
      return max_sta_failed;
    }

    if (SIR_MAC_TDLS_SETUP_RSP == action_code)
    {
        wlan_hdd_tdls_set_responder(pAdapter, peerMac, TRUE);
    }
    else if (SIR_MAC_TDLS_SETUP_CNF == action_code)
    {
        wlan_hdd_tdls_set_responder(pAdapter, peerMac, FALSE);
    }

    return 0;
error:
    /* max_sta_failed ; we didn't set to CONNECTING for this case,
       because we already know that this transaction will be failed,
       but we weren't sure if supplicant call DISABLE_LINK or not. So,
       to be safe, do not change the state mahine.
    */
    if(max_sta_failed == 0 &&
           (WLAN_IS_TDLS_SETUP_ACTION(action_code)))
            wlan_hdd_tdls_set_link_status(pAdapter, peerMac, eTDLS_LINK_IDLE);
    return -EPERM;
}

static int wlan_hdd_cfg80211_tdls_oper(struct wiphy *wiphy, struct net_device *dev,
                 u8 *peer, enum nl80211_tdls_operation oper)
{
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
    hdd_context_t *pHddCtx = wiphy_priv(wiphy);
    int status;
#ifdef WLAN_FEATURE_TDLS_DEBUG
    const char *tdls_oper_str[]= {
        "NL80211_TDLS_DISCOVERY_REQ",
        "NL80211_TDLS_SETUP",
        "NL80211_TDLS_TEARDOWN",
        "NL80211_TDLS_ENABLE_LINK",
        "NL80211_TDLS_DISABLE_LINK",
        "NL80211_TDLS_UNKNOWN_OPER"};
#endif
    hddTdlsPeer_t *pTdlsPeer;

    if ( NULL == peer )
    {
        VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                   "%s: Invalid arguments", __func__);
        return -EINVAL;
    }

    status = wlan_hdd_validate_context(pHddCtx);

    if (0 != status)
    {
        VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                   "%s: HDD context is not valid", __func__);
        return status;
    }

    pTdlsPeer = wlan_hdd_tdls_find_peer(pAdapter, peer);

    if ( NULL == pTdlsPeer ) {
        hddLog(VOS_TRACE_LEVEL_ERROR, "%s: " MAC_ADDRESS_STR " (oper %d) not exsting. ignored",
               __func__, MAC_ADDR_ARRAY(peer), (int)oper);
        return -EINVAL;
    }

#ifdef WLAN_FEATURE_TDLS_DEBUG
    if((int)oper > 4)
        oper = 5;

    VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
               "%s: " MAC_ADDRESS_STR " link_status %d (%s) ", "tdls_oper",
               MAC_ADDR_ARRAY(peer), pTdlsPeer->link_status,
               tdls_oper_str[(int)oper]);
#endif

    if( FALSE == pHddCtx->cfg_ini->fEnableTDLSSupport ||
        FALSE == sme_IsFeatureSupportedByFW(TDLS))
    {
        VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                "TDLS Disabled in INI OR not enabled in FW. "
                "Cannot process TDLS commands");
        return -ENOTSUPP;
    }

    switch (oper) {
        case NL80211_TDLS_ENABLE_LINK:
            {
                VOS_STATUS status;
                tCsrTdlsLinkEstablishParams tdlsLinkEstablishParams;

                if (!TDLS_STA_INDEX_VALID(pTdlsPeer->staId))
                {
                    hddLog(VOS_TRACE_LEVEL_ERROR, "%s: Invalid Staion Index %u "
                           MAC_ADDRESS_STR " failed",
                           __func__, pTdlsPeer->staId, MAC_ADDR_ARRAY(peer));
                    return -EINVAL;
                }

                if (eTDLS_LINK_CONNECTED != pTdlsPeer->link_status)
                {
                    long ret;
                    if (IS_ADVANCE_TDLS_ENABLE) {

                        if (0 != wlan_hdd_tdls_get_link_establish_params(
                                   pAdapter, peer,&tdlsLinkEstablishParams)) {
                            return -EINVAL;
                        }
                        INIT_COMPLETION(pAdapter->tdls_link_establish_req_comp);

                        sme_SendTdlsLinkEstablishParams(WLAN_HDD_GET_HAL_CTX(pAdapter),
                            pAdapter->sessionId, peer, &tdlsLinkEstablishParams);
                        /* Send TDLS peer UAPSD capabilities to the firmware and
                         * register with the TL on after the response for this operation
                         * is received .
                         */
                        ret = wait_for_completion_interruptible_timeout(
                                &pAdapter->tdls_link_establish_req_comp,
                                msecs_to_jiffies(WAIT_TIME_TDLS_LINK_ESTABLISH_REQ));
                        if (ret <= 0)
                        {
                            VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                                      "%s: Link Establish Request Faled Status %ld",
                                      __func__, ret);
                            return -EINVAL;
                        }
                    }
                    wlan_hdd_tdls_set_peer_link_status(pTdlsPeer, eTDLS_LINK_CONNECTED);
                    /* Mark TDLS client Authenticated .*/
                    status = WLANTL_ChangeSTAState( pHddCtx->pvosContext,
                                                    pTdlsPeer->staId,
                                                    WLANTL_STA_AUTHENTICATED);
                    if (VOS_STATUS_SUCCESS == status)
                    {
                        if (pTdlsPeer->is_responder == 0)
                        {
                            v_U8_t staId = (v_U8_t)pTdlsPeer->staId;

                            wlan_hdd_tdls_timer_restart(pAdapter,
                                                        &pTdlsPeer->initiatorWaitTimeoutTimer,
                                                       WAIT_TIME_TDLS_INITIATOR);
                            /* suspend initiator TX until it receives direct packet from the
                            reponder or WAIT_TIME_TDLS_INITIATOR timer expires */
                            WLANTL_SuspendDataTx( (WLAN_HDD_GET_CTX(pAdapter))->pvosContext,
                                                   &staId, NULL);
                        }
                        wlan_hdd_tdls_increment_peer_count(pAdapter);
                    }
                    wlan_hdd_tdls_check_bmps(pAdapter);

                    /* Update TL about the UAPSD masks , to route the packets to firmware */
                    if ((TRUE == pHddCtx->cfg_ini->fEnableTDLSBufferSta)
                        || pHddCtx->cfg_ini->fTDLSUapsdMask )
                    {
                        int ac;
                        uint8 ucAc[4] = { WLANTL_AC_VO,
                                          WLANTL_AC_VI,
                                          WLANTL_AC_BK,
                                          WLANTL_AC_BE };
                        uint8 tlTid[4] = { 7, 5, 2, 3 } ;
                        for(ac=0; ac < 4; ac++)
                        {
                            status = WLANTL_EnableUAPSDForAC( (WLAN_HDD_GET_CTX(pAdapter))->pvosContext,
                                                               pTdlsPeer->staId, ucAc[ac],
                                                               tlTid[ac], tlTid[ac], 0, 0,
                                                               WLANTL_BI_DIR );
                        }
                    }
                }

            }
            break;
        case NL80211_TDLS_DISABLE_LINK:
            {
                if(TDLS_STA_INDEX_VALID(pTdlsPeer->staId))
                {
                    long status;

                    INIT_COMPLETION(pAdapter->tdls_del_station_comp);

                    sme_DeleteTdlsPeerSta( WLAN_HDD_GET_HAL_CTX(pAdapter),
                            pAdapter->sessionId, peer );

                    status = wait_for_completion_interruptible_timeout(&pAdapter->tdls_del_station_comp,
                              msecs_to_jiffies(WAIT_TIME_TDLS_DEL_STA));
                    if (status <= 0)
                    {
                        wlan_hdd_tdls_set_peer_link_status(pTdlsPeer, eTDLS_LINK_IDLE);
                        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                                  "%s: Del station failed status %ld",
                                  __func__, status);
                        return -EPERM;
                    }
                    wlan_hdd_tdls_set_peer_link_status(pTdlsPeer, eTDLS_LINK_IDLE);
                }
                else
                {
                    VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                              "%s: TDLS Peer Station doesn't exist.", __func__);
                }
            }
            break;
        case NL80211_TDLS_TEARDOWN:
        case NL80211_TDLS_SETUP:
        case NL80211_TDLS_DISCOVERY_REQ:
            /* We don't support in-driver setup/teardown/discovery */
            return -ENOTSUPP;
        default:
            return -ENOTSUPP;
    }
    return 0;
}

int wlan_hdd_cfg80211_send_tdls_discover_req(struct wiphy *wiphy,
                            struct net_device *dev, u8 *peer)
{
    hddLog(VOS_TRACE_LEVEL_INFO, "tdls send discover req: %x %x %x %x %x %x",
            peer[0], peer[1], peer[2], peer[3], peer[4], peer[5]);

    return wlan_hdd_cfg80211_tdls_mgmt(wiphy, dev, peer,
                            WLAN_TDLS_DISCOVERY_REQUEST, 1, 0, NULL, 0);
}
#endif

#ifdef WLAN_FEATURE_GTK_OFFLOAD
/*
 * FUNCTION: wlan_hdd_cfg80211_update_replayCounterCallback
 * Callback rountine called upon receiving response for
 * get offload info
 */
void wlan_hdd_cfg80211_update_replayCounterCallback(void *callbackContext,
                            tpSirGtkOffloadGetInfoRspParams pGtkOffloadGetInfoRsp)
{

    hdd_adapter_t *pAdapter = (hdd_adapter_t *)callbackContext;
    tANI_U8 tempReplayCounter[8];
    hdd_station_ctx_t *pHddStaCtx;

    ENTER();

    if (NULL == pAdapter)
    {
        VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL,
                   "%s: HDD adapter is Null", __func__);
        return ;
    }

    if (NULL == pGtkOffloadGetInfoRsp)
    {
        VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                   "%s: pGtkOffloadGetInfoRsp is Null", __func__);
        return ;
    }

    if (VOS_STATUS_SUCCESS != pGtkOffloadGetInfoRsp->ulStatus)
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                "%s: wlan Failed to get replay counter value",
                __func__);
        return ;
    }

    pHddStaCtx = WLAN_HDD_GET_STATION_CTX_PTR(pAdapter);
    /* Update replay counter */
    pHddStaCtx->gtkOffloadReqParams.ullKeyReplayCounter =
                                   pGtkOffloadGetInfoRsp->ullKeyReplayCounter;

    {
        /* changing from little to big endian since supplicant
         * works on big endian format
         */
        int i;
        tANI_U8 *p = (tANI_U8 *)&pGtkOffloadGetInfoRsp->ullKeyReplayCounter;

        for (i = 0; i < 8; i++)
        {
            tempReplayCounter[7-i] = (tANI_U8)p[i];
        }
    }

    /* Update replay counter to NL */
    cfg80211_gtk_rekey_notify(pAdapter->dev, pGtkOffloadGetInfoRsp->bssId,
          tempReplayCounter, GFP_KERNEL);
}

/*
 * FUNCTION: wlan_hdd_cfg80211_set_rekey_data
 * This function is used to offload GTK rekeying job to the firmware.
 */
int wlan_hdd_cfg80211_set_rekey_data(struct wiphy *wiphy, struct net_device *dev,
                                     struct cfg80211_gtk_rekey_data *data)
{
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
    hdd_context_t *pHddCtx = wiphy_priv(wiphy);
    hdd_station_ctx_t *pHddStaCtx;
    tHalHandle hHal;
    int result;
    tSirGtkOffloadParams hddGtkOffloadReqParams;
    eHalStatus status = eHAL_STATUS_FAILURE;

    ENTER();

    if (NULL == pAdapter)
    {
        VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL,
                   "%s: HDD adapter is Null", __func__);
        return -ENODEV;
    }

    result = wlan_hdd_validate_context(pHddCtx);

    if (0 != result)
    {
        VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                   "%s: HDD context is not valid", __func__);
        return result;
    }

    pHddStaCtx = WLAN_HDD_GET_STATION_CTX_PTR(pAdapter);
    hHal = WLAN_HDD_GET_HAL_CTX(pAdapter);
    if (NULL == hHal)
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                "%s: HAL context  is Null!!!", __func__);
        return -EAGAIN;
    }

    pHddStaCtx->gtkOffloadReqParams.ulFlags = GTK_OFFLOAD_ENABLE;
    memcpy(pHddStaCtx->gtkOffloadReqParams.aKCK, data->kck, NL80211_KCK_LEN);
    memcpy(pHddStaCtx->gtkOffloadReqParams.aKEK, data->kek, NL80211_KEK_LEN);
    memcpy(pHddStaCtx->gtkOffloadReqParams.bssId, &pHddStaCtx->conn_info.bssId,
          WNI_CFG_BSSID_LEN);
    {
        /* changing from big to little endian since driver
         * works on little endian format
         */
        tANI_U8 *p =
              (tANI_U8 *)&pHddStaCtx->gtkOffloadReqParams.ullKeyReplayCounter;
        int i;

        for (i = 0; i < 8; i++)
        {
            p[7-i] = data->replay_ctr[i];
        }
    }

    if (TRUE == pHddCtx->hdd_wlan_suspended)
    {
        /* if wlan is suspended, enable GTK offload directly from here */
        memcpy(&hddGtkOffloadReqParams, &pHddStaCtx->gtkOffloadReqParams,
              sizeof (tSirGtkOffloadParams));
        status = sme_SetGTKOffload(hHal, &hddGtkOffloadReqParams,
                       pAdapter->sessionId);

        if (eHAL_STATUS_SUCCESS != status)
        {
            VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                    "%s: sme_SetGTKOffload failed, returned %d",
                    __func__, status);
            return status;
        }
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO,
                "%s: sme_SetGTKOffload successfull", __func__);
    }
    else
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO,
                "%s: wlan not suspended GTKOffload request is stored",
                __func__);
    }
=======
            hdd_softap_sta_deauth(pAdapter, mac);
        }
    }

    EXIT();
>>>>>>> 657b0e9... prima update

    return 0;
}

static int wlan_hdd_cfg80211_add_station(struct wiphy *wiphy,
          struct net_device *dev, u8 *mac, struct station_parameters *params)
{
    // TODO: Implement this later.
    ENTER();
    return 0;
}


#ifdef FEATURE_WLAN_LFR
static int wlan_hdd_cfg80211_set_pmksa(struct wiphy *wiphy, struct net_device *dev,
            struct cfg80211_pmksa *pmksa)
{
#define MAX_PMKSAIDS_IN_CACHE 8
    static tPmkidCacheInfo PMKIDCache[MAX_PMKSAIDS_IN_CACHE]; // HDD Local cache
    static tANI_U32 i = 0; // HDD Local Cache index 
    tANI_U32 j=0;  
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
    tHalHandle halHandle;
    eHalStatus result; 
    tANI_U8  BSSIDMatched = 0;
   
    ENTER();

    // Validate pAdapter  
    if ( NULL == pAdapter || NULL == pAdapter->pHddCtx)
    {
        hddLog(VOS_TRACE_LEVEL_FATAL, "%s: Invalid Adapter or HDD Context " ,__func__);
        return -EINVAL;
    }

    if (((hdd_context_t*)pAdapter->pHddCtx)->isLoadUnloadInProgress)
    {
         hddLog( LOGE,
                 "%s: Wlan Load/Unload is in progress", __func__);
         return -EBUSY;
    }

    if ( (WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress )
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                "%s:LOGP in Progress. Ignore!!!", __func__);
        return -EAGAIN;
    }

    // Retrieve halHandle  
    halHandle = WLAN_HDD_GET_HAL_CTX(pAdapter);

    for (j = 0; j < i; j++)
    {
        if(vos_mem_compare(PMKIDCache[j].BSSID, 
                    pmksa->bssid, WNI_CFG_BSSID_LEN))
        {
            /* BSSID matched previous entry.  Overwrite it. */
            BSSIDMatched = 1;
            vos_mem_copy(PMKIDCache[j].BSSID, 
                    pmksa->bssid, WNI_CFG_BSSID_LEN);
            vos_mem_copy(PMKIDCache[j].PMKID, 
                    pmksa->pmkid,   
                    CSR_RSN_PMKID_SIZE);
            hddLog(VOS_TRACE_LEVEL_FATAL, "%s: Reusing cache entry %d.", 
                    __FUNCTION__, j );
            dump_bssid(pmksa->bssid);
            dump_pmkid(halHandle, pmksa->pmkid);
            break;
        }
    }

    /* Check we compared all entries,if then take the first slot now */
    if(j == MAX_PMKSAIDS_IN_CACHE) i=0;

    if (!BSSIDMatched)
    { 
        // Now, we DON'T have a BSSID match, so take a new entry in the cache.  
        vos_mem_copy(PMKIDCache[i].BSSID, 
                pmksa->bssid, ETHER_ADDR_LEN); 
        vos_mem_copy(PMKIDCache[i].PMKID, 
                pmksa->pmkid,   
                CSR_RSN_PMKID_SIZE);
        hddLog(VOS_TRACE_LEVEL_FATAL, "%s: Adding a new cache entry %d.", 
                __FUNCTION__, i );
        dump_bssid(pmksa->bssid);
        dump_pmkid(halHandle, pmksa->pmkid);
        // Increment the HDD Local Cache index 
        // The "i=0" doesn't work for the call to sme_RoamSetPMKIDCache() - LFR FIXME
        if (i<=(MAX_PMKSAIDS_IN_CACHE-1)) i++; else i=0; 
    }


    // Calling csrRoamSetPMKIDCache to configure the PMKIDs into the cache
    //hddLog(LOG1, FL("%s: Calling csrRoamSetPMKIDCache with %d cache entries."), 
    //        __FUNCTION__, i );
    hddLog(VOS_TRACE_LEVEL_FATAL, "%s: Calling csrRoamSetPMKIDCache with %d cache entries.", 
            __FUNCTION__, i );
    // Finally set the PMKSA ID Cache in CSR
    result = sme_RoamSetPMKIDCache(halHandle,pAdapter->sessionId, 
                                    PMKIDCache, 
                                    i );
    return 0;
}


static int wlan_hdd_cfg80211_del_pmksa(struct wiphy *wiphy, struct net_device *dev,
            struct cfg80211_pmksa *pmksa)
{
    ENTER();
    // TODO: Implement this later.
    return 0;
}

static int wlan_hdd_cfg80211_flush_pmksa(struct wiphy *wiphy, struct net_device *dev)
{
    ENTER();
    // TODO: Implement this later.
    return 0;
}
#endif


/* cfg80211_ops */
static struct cfg80211_ops wlan_hdd_cfg80211_ops = 
{
    .add_virtual_intf = wlan_hdd_add_virtual_intf,
    .del_virtual_intf = wlan_hdd_del_virtual_intf,
    .change_virtual_intf = wlan_hdd_cfg80211_change_iface,
    .change_station = wlan_hdd_change_station,
#if (LINUX_VERSION_CODE < KERNEL_VERSION(3,4,0))
    .add_beacon = wlan_hdd_cfg80211_add_beacon,
    .del_beacon = wlan_hdd_cfg80211_del_beacon,
    .set_beacon = wlan_hdd_cfg80211_set_beacon,
#else
    .start_ap = wlan_hdd_cfg80211_start_ap,
    .change_beacon = wlan_hdd_cfg80211_change_beacon,
    .stop_ap = wlan_hdd_cfg80211_stop_ap,
#endif
    .change_bss = wlan_hdd_cfg80211_change_bss,
    .add_key = wlan_hdd_cfg80211_add_key,
    .get_key = wlan_hdd_cfg80211_get_key,
    .del_key = wlan_hdd_cfg80211_del_key,
    .set_default_key = wlan_hdd_cfg80211_set_default_key,
    .set_channel = wlan_hdd_cfg80211_set_channel,
    .scan = wlan_hdd_cfg80211_scan,
    .connect = wlan_hdd_cfg80211_connect,
    .disconnect = wlan_hdd_cfg80211_disconnect,
    .join_ibss  = wlan_hdd_cfg80211_join_ibss,
    .leave_ibss = wlan_hdd_cfg80211_leave_ibss,
    .set_wiphy_params = wlan_hdd_cfg80211_set_wiphy_params,
    .set_tx_power = wlan_hdd_cfg80211_set_txpower,
    .get_tx_power = wlan_hdd_cfg80211_get_txpower,
#ifdef WLAN_FEATURE_P2P
    .remain_on_channel = wlan_hdd_cfg80211_remain_on_channel,
    .cancel_remain_on_channel =  wlan_hdd_cfg80211_cancel_remain_on_channel,
    .mgmt_tx =  wlan_hdd_action,
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,38))
     .mgmt_tx_cancel_wait = wlan_hdd_cfg80211_mgmt_tx_cancel_wait,
     .set_default_mgmt_key = wlan_hdd_set_default_mgmt_key,
     .set_txq_params = wlan_hdd_set_txq_params,
#endif
#endif
     .get_station = wlan_hdd_cfg80211_get_station,
     .set_power_mgmt = wlan_hdd_cfg80211_set_power_mgmt,
     .del_station  = wlan_hdd_cfg80211_del_station,
     .add_station  = wlan_hdd_cfg80211_add_station,
#ifdef FEATURE_WLAN_LFR
     .set_pmksa = wlan_hdd_cfg80211_set_pmksa,
     .del_pmksa = wlan_hdd_cfg80211_del_pmksa,
     .flush_pmksa = wlan_hdd_cfg80211_flush_pmksa,
#endif
};

<<<<<<< HEAD
>>>>>>> d97af3b... add prima wlan driver
=======
#endif // CONFIG_CFG80211
>>>>>>> 657b0e9... prima update
