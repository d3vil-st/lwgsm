/**
 * \file            lwgsm_sleep.c
 * \brief           Sleep functionality
 */

/*
 * Copyright (c) 2020 Tilen MAJERLE
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of the Software,
 * and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
 * AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * This file is part of LwGSM - Lightweight GSM-AT library.
 *
 * Authors:          Tilen MAJERLE <tilen@majerle.eu>,
 *                   Ilya Kargapolov <d3vil.st@gmail.com>
 * Version:         v0.1.0
 */


#include <lwgsm/lwgsm_private.h>
#include "lwgsm/lwgsm_mem.h"

#if LWGSM_CFG_SLEEP || __DOXYGEN__

/**
 * \brief           Set Sleep mode
 * \param[in]       value: Value for parameter, `1` for enable, `0` for disable timesync with base station
 * \param[in]       evt_fn: Callback function called when command has finished. Set to `NULL` when not used
 * \param[in]       evt_arg: Custom argument for event callback function
 * \param[in]       blocking: Status whether command should be blocking or not
 * \return          \ref lwgsmOK on success, member of \ref lwgsmr_t otherwise
 */
lwgsmr_t
lwgsm_sleep_mode_set(uint8_t value, lwgsm_api_cmd_evt_fn evt_fn, void* evt_arg, uint32_t blocking) {
  LWGSM_MSG_VAR_DEFINE(msg);

  LWGSM_MSG_VAR_ALLOC(msg, blocking);
  LWGSM_MSG_VAR_SET_EVT(msg, evt_fn, evt_arg);
  LWGSM_MSG_VAR_REF(msg).cmd_def = LWGSM_CMD_CSCLK;
  LWGSM_MSG_VAR_REF(msg).msg.sleep.mode = value;

  return lwgsmi_send_msg_to_producer_mbox(&LWGSM_MSG_VAR_REF(msg), lwgsmi_initiate_cmd, 10000);
}

#endif /* LWGSM_CFG_SLEEP || __DOXYGEN__ */
