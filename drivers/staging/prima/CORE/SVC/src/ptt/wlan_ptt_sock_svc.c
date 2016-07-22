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

/******************************************************************************
 * wlan_ptt_sock_svc.c
 *
 ******************************************************************************/
#ifdef PTT_SOCK_SVC_ENABLE
#include <wlan_nlink_srv.h>
#include <halTypes.h>
#include <vos_status.h>
#include <wlan_hdd_includes.h>
#include <vos_trace.h>
#include <wlan_nlink_common.h>
#include <wlan_ptt_sock_svc.h>
#include <vos_types.h>
#include <vos_trace.h>
<<<<<<< HEAD
#ifdef ANI_MANF_DIAG
#include <wlan_hdd_ftm.h>
#endif
=======
#include <wlan_hdd_ftm.h>
>>>>>>> d97af3b... add prima wlan driver

#define PTT_SOCK_DEBUG
#ifdef PTT_SOCK_DEBUG
#define PTT_TRACE(level, args...) VOS_TRACE( VOS_MODULE_ID_HDD, level, ## args)
#else
#define PTT_TRACE(level, args...)
#endif
// Global variables
<<<<<<< HEAD
static struct hdd_context_s *pAdapterHandle = NULL;
=======
static struct hdd_context_s *pAdapterHandle;
>>>>>>> d97af3b... add prima wlan driver
//Utility function to perform endianess swap
static void ptt_sock_swap_32(void *pBuffer, unsigned int len)
{
    v_U32_t *pBuf32, data;
    v_U8_t *pBuf8;
    unsigned int i;
    len &= ~(sizeof(v_U32_t)-1);
    pBuf32 = (v_U32_t *) pBuffer;
    pBuf8 = (v_U8_t *) pBuffer;
    for (i = 0; i < len; i += 4, ++pBuf32, pBuf8 += 4) {
        data = *pBuf32;
        pBuf8[0] = (v_U8_t) ((data >> 24) & 0xff);
        pBuf8[1] = (v_U8_t) ((data >> 16) & 0xff);
        pBuf8[2] = (v_U8_t) ((data >> 8) & 0xff);
        pBuf8[3] = (v_U8_t) ((data >> 0) & 0xff);
    }
}
#ifdef PTT_SOCK_DEBUG_VERBOSE
//Utility function to perform a hex dump
static void ptt_sock_dump_buf(const unsigned char * pbuf, int cnt)
{
    int i;
    for (i = 0; i < cnt ; i++) {
        if ((i%16)==0)
            VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO,"\n%p:", pbuf);
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO," %02X", *pbuf);
        pbuf++;
    }
    VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO,"\n");
}
#endif
//Utility function to send a netlink message to an application in user space
int ptt_sock_send_msg_to_app(tAniHdr *wmsg, int radio, int src_mod, int pid)
{
   int err = -1;
   int payload_len;
   int tot_msg_len;
   tAniNlHdr *wnl;
   struct sk_buff *skb;
   struct nlmsghdr *nlh;
   int wmsg_length = be16_to_cpu(wmsg->length);
<<<<<<< HEAD
   static int nlmsg_seq = 0;
   if (radio < 0 || radio > ANI_MAX_RADIOS) {
      PTT_TRACE(VOS_TRACE_LEVEL_ERROR, "%s: invalid radio id [%d]\n",
         __FUNCTION__, radio);
      return -1;
=======
   static int nlmsg_seq;
   if (radio < 0 || radio > ANI_MAX_RADIOS) {
      PTT_TRACE(VOS_TRACE_LEVEL_ERROR, "%s: invalid radio id [%d]\n",
         __func__, radio);
      return -EINVAL;
>>>>>>> d97af3b... add prima wlan driver
   }
   payload_len = wmsg_length + 4;  // 4 extra bytes for the radio idx
   tot_msg_len = NLMSG_SPACE(payload_len);
   if ((skb = dev_alloc_skb(tot_msg_len)) == NULL) {
      PTT_TRACE(VOS_TRACE_LEVEL_ERROR, "%s: dev_alloc_skb() failed for msg size[%d]\n",
<<<<<<< HEAD
         __FUNCTION__, tot_msg_len);
      return -1;
   }
   nlh = NLMSG_PUT(skb, pid, nlmsg_seq++, src_mod, payload_len);
   nlh->nlmsg_flags = NLM_F_REQUEST;
=======
         __func__, tot_msg_len);
      return -ENOMEM;
   }
   nlh = nlmsg_put(skb, pid, nlmsg_seq++, src_mod, payload_len, NLM_F_REQUEST);
   if (NULL == nlh) {
      PTT_TRACE(VOS_TRACE_LEVEL_ERROR, "%s: nlmsg_put() failed for msg size[%d]\n",
         __func__, tot_msg_len);
      kfree_skb(skb);
      return -ENOMEM;
   }
>>>>>>> d97af3b... add prima wlan driver
   wnl = (tAniNlHdr *) nlh;
   wnl->radio = radio;
   memcpy(&wnl->wmsg, wmsg, wmsg_length);
   PTT_TRACE(VOS_TRACE_LEVEL_INFO, "%s: Sending Msg Type [0x%X] to pid[%d]\n",
<<<<<<< HEAD
      __FUNCTION__, be16_to_cpu(wmsg->type), pid);
=======
      __func__, be16_to_cpu(wmsg->type), pid);
>>>>>>> d97af3b... add prima wlan driver
#ifdef PTT_SOCK_DEBUG_VERBOSE
   ptt_sock_dump_buf((const unsigned char *)skb->data, skb->len);
#endif
   err = nl_srv_ucast(skb, pid);
<<<<<<< HEAD
nlmsg_failure:
=======
>>>>>>> d97af3b... add prima wlan driver
   return err;
}
/*
 * Process tregisteration request and send registration response messages
 * to the PTT Socket App in user space
 */
static void ptt_sock_proc_reg_req(tAniHdr *wmsg, int radio)
{
   tAniNlAppRegReq *reg_req;
   tAniNlAppRegRsp rspmsg;
   reg_req = (tAniNlAppRegReq *)(wmsg + 1);
   memset((char *)&rspmsg, 0, sizeof(rspmsg));
   //send reg response message to the application
   rspmsg.ret = ANI_NL_MSG_OK;
   rspmsg.regReq.type = reg_req->type;
<<<<<<< HEAD
=======
#ifdef WLAN_KD_READY_NOTIFIER
   /* NL client try to registration
    * to make sure connection, broadcast READY notification */
   nl_srv_nl_ready_indication();
#endif /* WLAN_KD_READY_NOTIFIER */
>>>>>>> d97af3b... add prima wlan driver
   /*Save the pid*/    
   pAdapterHandle->ptt_pid = reg_req->pid;   
   rspmsg.regReq.pid= reg_req->pid;
   rspmsg.wniHdr.type = cpu_to_be16(ANI_MSG_APP_REG_RSP);
   rspmsg.wniHdr.length = cpu_to_be16(sizeof(rspmsg));
   if (ptt_sock_send_msg_to_app((tAniHdr *)&rspmsg.wniHdr, radio,
      ANI_NL_MSG_PUMAC, reg_req->pid) < 0)
   {
      PTT_TRACE(VOS_TRACE_LEVEL_ERROR, "%s: Error sending ANI_MSG_APP_REG_RSP to pid[%d]\n",
<<<<<<< HEAD
         __FUNCTION__, reg_req->pid);
=======
         __func__, reg_req->pid);
>>>>>>> d97af3b... add prima wlan driver
   }
}
/*
 * Process all the messages from the PTT Socket App in user space
 */
static void ptt_proc_pumac_msg(struct sk_buff * skb, tAniHdr *wmsg, int radio)
{
   u16 ani_msg_type = be16_to_cpu(wmsg->type);
   switch(ani_msg_type)
   {
      case ANI_MSG_APP_REG_REQ:
         PTT_TRACE(VOS_TRACE_LEVEL_INFO, "%s: Received ANI_MSG_APP_REG_REQ [0x%X]\n",
<<<<<<< HEAD
            __FUNCTION__, ani_msg_type);
=======
            __func__, ani_msg_type);
>>>>>>> d97af3b... add prima wlan driver
         ptt_sock_proc_reg_req(wmsg, radio);
         break;
      default:
         PTT_TRACE(VOS_TRACE_LEVEL_ERROR, "%s: Received Unknown Msg Type[0x%X]\n",
<<<<<<< HEAD
            __FUNCTION__, ani_msg_type);
=======
            __func__, ani_msg_type);
>>>>>>> d97af3b... add prima wlan driver
         break;
   }
}
/*
 * Process all the messages from the Quarky Client
 */
static void ptt_proc_quarky_msg(tAniNlHdr *wnl, tAniHdr *wmsg, int radio)
{
   u16 ani_msg_type = be16_to_cpu(wmsg->type);
   v_U32_t reg_addr;
   v_U32_t reg_val;
   v_U32_t len_payload;
   v_U8_t* buf;
   unsigned int arg1, arg2, arg3, arg4, cmd;
   VOS_STATUS vosStatus = VOS_STATUS_SUCCESS;
   if (radio < 0 || radio > ANI_MAX_RADIOS) {
      PTT_TRACE(VOS_TRACE_LEVEL_ERROR, "%s: ANI Msg [0x%X] invalid radio id [%d]\n",
<<<<<<< HEAD
         __FUNCTION__, ani_msg_type, radio);
=======
         __func__, ani_msg_type, radio);
>>>>>>> d97af3b... add prima wlan driver
      return;
   }
   if(ani_msg_type == ANI_MSG_APP_REG_REQ)
   {
      ptt_sock_proc_reg_req(wmsg, radio);
   }
   else
   {
      switch (ani_msg_type)
      {
         case PTT_MSG_READ_REGISTER:
            reg_addr = *(v_U32_t*) ((char*)wmsg + 8);
            PTT_TRACE(VOS_TRACE_LEVEL_INFO, "%s: PTT_MSG_READ_REGISTER [0x%08lX]\n",
<<<<<<< HEAD
               __FUNCTION__, reg_addr);
=======
               __func__, reg_addr);
>>>>>>> d97af3b... add prima wlan driver
            vosStatus = sme_DbgReadRegister(pAdapterHandle->hHal, reg_addr, &reg_val);
            *(v_U32_t*) ((char*)wmsg + 12) = reg_val;
            if(vosStatus != VOS_STATUS_SUCCESS)
               PTT_TRACE(VOS_TRACE_LEVEL_ERROR, "%s: Read Register [0x%08lX] failed!!\n",
<<<<<<< HEAD
               __FUNCTION__, reg_addr);
=======
               __func__, reg_addr);
>>>>>>> d97af3b... add prima wlan driver
            ptt_sock_send_msg_to_app(wmsg, 0, ANI_NL_MSG_PUMAC, wnl->nlh.nlmsg_pid);
            break;
         case PTT_MSG_WRITE_REGISTER:
            reg_addr = *(v_U32_t*) ((const unsigned char*)wmsg + 8);
            reg_val = *(v_U32_t*)((const unsigned char*)wmsg + 12);
            PTT_TRACE(VOS_TRACE_LEVEL_INFO, "%s: PTT_MSG_WRITE_REGISTER Addr [0x%08lX] value [0x%08lX]\n",
<<<<<<< HEAD
               __FUNCTION__, reg_addr, reg_val);
=======
               __func__, reg_addr, reg_val);
>>>>>>> d97af3b... add prima wlan driver
            vosStatus = sme_DbgWriteRegister(pAdapterHandle->hHal, reg_addr, reg_val);
            if(vosStatus != VOS_STATUS_SUCCESS)
            {
               PTT_TRACE(VOS_TRACE_LEVEL_ERROR, "%s: Write Register [0x%08lX] value [0x%08lX] failed!!\n",
<<<<<<< HEAD
                  __FUNCTION__, reg_addr, reg_val);
=======
                  __func__, reg_addr, reg_val);
>>>>>>> d97af3b... add prima wlan driver
            }
            //send message to the app
            ptt_sock_send_msg_to_app(wmsg, 0, ANI_NL_MSG_PUMAC, wnl->nlh.nlmsg_pid);
            break;
         case PTT_MSG_READ_MEMORY:
            reg_addr = *(v_U32_t*) ((char*)wmsg + 8);
            len_payload = *(v_U32_t*) ((char*)wmsg + 12);
            PTT_TRACE(VOS_TRACE_LEVEL_INFO, "%s: PTT_MSG_READ_MEMORY addr [0x%08lX] bytes [0x%08lX]\n",
<<<<<<< HEAD
               __FUNCTION__, reg_addr, len_payload);
=======
               __func__, reg_addr, len_payload);
>>>>>>> d97af3b... add prima wlan driver
            buf = (v_U8_t*)wmsg + 16;
            vosStatus = sme_DbgReadMemory(pAdapterHandle->hHal, reg_addr, buf, len_payload);
            if(vosStatus != VOS_STATUS_SUCCESS) {
               PTT_TRACE(VOS_TRACE_LEVEL_ERROR, "%s: Memory read failed for [0x%08lX]!!\n",
<<<<<<< HEAD
                  __FUNCTION__, reg_addr);
=======
                  __func__, reg_addr);
>>>>>>> d97af3b... add prima wlan driver
            }
            ptt_sock_swap_32(buf, len_payload);
            //send message to the app
            ptt_sock_send_msg_to_app(wmsg, 0, ANI_NL_MSG_PUMAC, wnl->nlh.nlmsg_pid);
            break;
         case PTT_MSG_WRITE_MEMORY:
            reg_addr = *(v_U32_t*) ((char*)wmsg + 8);
            len_payload = *(v_U32_t*) ((char*)wmsg + 12);
            PTT_TRACE(VOS_TRACE_LEVEL_INFO, "%s: PTT_MSG_DBG_WRITE_MEMORY addr [0x%08lX] bytes [0x%08lX]\n",
<<<<<<< HEAD
               __FUNCTION__, reg_addr, len_payload);
=======
               __func__, reg_addr, len_payload);
>>>>>>> d97af3b... add prima wlan driver
            buf = (v_U8_t*)wmsg + 16;
            ptt_sock_swap_32(buf, len_payload);
            vosStatus = sme_DbgWriteMemory(pAdapterHandle->hHal, reg_addr, buf, len_payload);
            if(vosStatus != VOS_STATUS_SUCCESS)
            {
               PTT_TRACE(VOS_TRACE_LEVEL_ERROR, "%s: Memory write failed for addr [0x%08lX]!!\n",
<<<<<<< HEAD
                  __FUNCTION__, reg_addr);
=======
                  __func__, reg_addr);
>>>>>>> d97af3b... add prima wlan driver
            }
            //send message to the app
            ptt_sock_send_msg_to_app(wmsg, 0, ANI_NL_MSG_PUMAC, wnl->nlh.nlmsg_pid);
            break;
         case PTT_MSG_LOG_DUMP_DBG:
            cmd = *(unsigned int *) ((char *)wmsg + 8);
            arg1 = *(unsigned int *) ((char *)wmsg + 12);
            arg2 = *(unsigned int *) ((char *)wmsg + 16);
            arg3 = *(unsigned int *) ((char *)wmsg + 20);
            arg4 = *(unsigned int *) ((char *)wmsg + 24);
            PTT_TRACE(VOS_TRACE_LEVEL_INFO, "%s: PTT_MSG_LOG_DUMP_DBG %d arg1 %d arg2 %d arg3 %d arg4 %d\n",
<<<<<<< HEAD
               __FUNCTION__, cmd, arg1, arg2, arg3, arg4);
#ifdef FEATURE_WLAN_NON_INTEGRATED_SOC
            // FIXME_PRIMA -- need logDump() replacement
            logPrintf(pAdapterHandle->hHal, cmd, arg1, arg2, arg3, arg4);
#endif //FEATURE_WLAN_NON_INTEGRATED_SOC
            //send message to the app
            ptt_sock_send_msg_to_app(wmsg, 0, ANI_NL_MSG_PUMAC, wnl->nlh.nlmsg_pid);
            break;
#ifdef ANI_MANF_DIAG
         case PTT_MSG_FTM_CMDS_TYPE:
            wlan_hdd_process_ftm_cmd(pAdapterHandle,wnl);
            break;
#endif
         default:
            PTT_TRACE(VOS_TRACE_LEVEL_ERROR, "%s: Unknown ANI Msg [0x%X], length [0x%X]\n",
               __FUNCTION__, ani_msg_type, be16_to_cpu(wmsg->length ));
=======
               __func__, cmd, arg1, arg2, arg3, arg4);
            //send message to the app
            ptt_sock_send_msg_to_app(wmsg, 0, ANI_NL_MSG_PUMAC, wnl->nlh.nlmsg_pid);
            break;
         case PTT_MSG_FTM_CMDS_TYPE:
            wlan_hdd_process_ftm_cmd(pAdapterHandle,wnl);
            break;
         default:
            PTT_TRACE(VOS_TRACE_LEVEL_ERROR, "%s: Unknown ANI Msg [0x%X], length [0x%X]\n",
               __func__, ani_msg_type, be16_to_cpu(wmsg->length ));
>>>>>>> d97af3b... add prima wlan driver
            break;
      }
   }
}
/*
 * Process all the Netlink messages from PTT Socket app in user space
 */
static int ptt_sock_rx_nlink_msg (struct sk_buff * skb)
{
   tAniNlHdr *wnl;
   int radio;
   int type;
   wnl = (tAniNlHdr *) skb->data;
   radio = wnl->radio;
   type = wnl->nlh.nlmsg_type;
   switch (type) {
      case ANI_NL_MSG_PUMAC:  //Message from the PTT socket APP
         PTT_TRACE(VOS_TRACE_LEVEL_INFO, "%s: Received ANI_NL_MSG_PUMAC Msg [0x%X]\n",
<<<<<<< HEAD
            __func__, type, radio);
=======
            __func__, type);
>>>>>>> d97af3b... add prima wlan driver
         ptt_proc_pumac_msg(skb, &wnl->wmsg, radio);
         break;
      case ANI_NL_MSG_PTT: //Message from Quarky GUI
         PTT_TRACE(VOS_TRACE_LEVEL_INFO, "%s: Received ANI_NL_MSG_PTT Msg [0x%X]\n",
<<<<<<< HEAD
            __func__, type, radio);
=======
            __func__, type);
>>>>>>> d97af3b... add prima wlan driver
         ptt_proc_quarky_msg(wnl, &wnl->wmsg, radio);
         break;
      default:
         PTT_TRACE(VOS_TRACE_LEVEL_ERROR, "%s: Unknown NL Msg [0x%X]\n",__func__, type);
         break;
   }
   return 0;
}
int ptt_sock_activate_svc(void *pAdapter)
{
   pAdapterHandle = (struct hdd_context_s*)pAdapter;
   nl_srv_register(ANI_NL_MSG_PUMAC, ptt_sock_rx_nlink_msg);
   nl_srv_register(ANI_NL_MSG_PTT, ptt_sock_rx_nlink_msg);
<<<<<<< HEAD
=======
#ifdef WLAN_KD_READY_NOTIFIER
   nl_srv_nl_ready_indication();
#endif /* WLAN_KD_READY_NOTIFIER */
>>>>>>> d97af3b... add prima wlan driver
   return 0;
}
#endif //PTT_SOCK_SVC_ENABLE
