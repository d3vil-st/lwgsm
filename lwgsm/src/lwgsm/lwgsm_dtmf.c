/**
 * \file            lwgsm_dtmf.c
 * \brief           DTMF API
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
#include "lwgsm/lwgsm_private.h"
#include "lwgsm/lwgsm_dtmf.h"
#include "lwgsm/lwgsm_mem.h"

#if LWGSM_CFG_DTMF || __DOXYGEN__

#if !__DOXYGEN__
#define CHECK_ENABLED()                 if (!(check_enabled() == lwgsmOK)) { return lwgsmERRNOTENABLED; }
#define CHECK_READY()                   if (!(check_ready() == lwgsmOK)) { return lwgsmERR; }
#endif /* !__DOXYGEN__ */

/**
 * \brief           Check if dtmf is enabled
 * \return          \ref lwgsmOK on success, member of \ref lwgsmr_t otherwise
 */
static lwgsmr_t
check_enabled(void) {
    lwgsmr_t res;
    lwgsm_core_lock();
    res = lwgsm.m.dtmf.enabled ? lwgsmOK : lwgsmERR;
    lwgsm_core_unlock();
    return res;
}

/**
 * \brief           Check if DTMF is available
 * \return          \ref lwgsmOK on success, member of \ref lwgsmr_t enumeration otherwise
 */
static lwgsmr_t
check_ready(void) {
    lwgsmr_t res;
    lwgsm_core_lock();
    res = lwgsm.m.dtmf.ready ? lwgsmOK : lwgsmERR;
    lwgsm_core_unlock();
    return res;
}

/**
 * \brief           Enable DTMF functionality
 * \param[in]       evt_fn: Callback function called when command has finished. Set to `NULL` when not used
 * \param[in]       evt_arg: Custom argument for event callback function
 * \param[in]       blocking: Status whether command should be blocking or not
 * \return          \ref lwgsmOK on success, member of \ref lwgsmr_t otherwise
 */
lwgsmr_t
lwgsm_dtmf_enable(const lwgsm_api_cmd_evt_fn evt_fn, void* const evt_arg, const uint32_t blocking) {
    LWGSM_MSG_VAR_DEFINE(msg);

    LWGSM_MSG_VAR_ALLOC(msg, blocking);
    LWGSM_MSG_VAR_SET_EVT(msg, evt_fn, evt_arg);
    LWGSM_MSG_VAR_REF(msg).cmd_def = LWGSM_CMD_DTMF_ENABLE;
    LWGSM_MSG_VAR_REF(msg).cmd = LWGSM_CMD_DDET_SET;

    return lwgsmi_send_msg_to_producer_mbox(&LWGSM_MSG_VAR_REF(msg), lwgsmi_initiate_cmd, 60000);
}

/**
 * \brief           Disable DTMF functionality
 * \param[in]       evt_fn: Callback function called when command has finished. Set to `NULL` when not used
 * \param[in]       evt_arg: Custom argument for event callback function
 * \param[in]       blocking: Status whether command should be blocking or not
 * \return          \ref lwgsmOK on success, member of \ref lwgsmr_t otherwise
 */
lwgsmr_t
lwgsm_dtmf_disable(const lwgsm_api_cmd_evt_fn evt_fn, void* const evt_arg, const uint32_t blocking) {
    lwgsm_core_lock();
    lwgsm.m.dtmf.enabled = 0;
    if (evt_fn != NULL) {
        evt_fn(lwgsmOK, evt_arg);
    }
    lwgsm_core_unlock();
    LWGSM_UNUSED(blocking);
    return lwgsmOK;
}

#endif /* LWGSM_CFG_DTMF || __DOXYGEN__ */
