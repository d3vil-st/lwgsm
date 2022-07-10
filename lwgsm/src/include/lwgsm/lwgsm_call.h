/**
 * \file            lwgsm_call.h
 * \brief           Call API
 */

/*
 * Copyright (c) 2022 Tilen MAJERLE
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
 * Author:          Tilen MAJERLE <tilen@majerle.eu>
 * Version:         v0.1.1
 */
#ifndef LWGSM_HDR_CALL_H
#define LWGSM_HDR_CALL_H

#include "lwgsm/lwgsm.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * \ingroup         LWGSM
 * \defgroup        LWGSM_CALL Call API
 * \brief           Call manager
 * \{
 */

lwgsmr_t      lwgsm_call_enable(const lwgsm_api_cmd_evt_fn evt_fn, void* const evt_arg, const uint32_t blocking);
lwgsmr_t      lwgsm_call_disable(const lwgsm_api_cmd_evt_fn evt_fn, void* const evt_arg, const uint32_t blocking);

lwgsmr_t      lwgsm_call_start(const char* number, const lwgsm_api_cmd_evt_fn evt_fn, void* const evt_arg, const uint32_t blocking);
lwgsmr_t      lwgsm_call_answer(const lwgsm_api_cmd_evt_fn evt_fn, void* const evt_arg, const uint32_t blocking);
lwgsmr_t      lwgsm_call_hangup(const lwgsm_api_cmd_evt_fn evt_fn, void* const evt_arg, const uint32_t blocking);

/**
 * \}
 */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* LWGSM_HDR_CALL_H */
