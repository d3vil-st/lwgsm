idf_component_register(
  SRCS
    "lwgsm/src/api/lwgsm_netconn.c"
    "lwgsm/src/api/lwgsm_network_api.c"
    "lwgsm/src/lwgsm/lwgsm.c"
    "lwgsm/src/lwgsm/lwgsm_buff.c"
    "lwgsm/src/lwgsm/lwgsm_call.c"
    "lwgsm/src/lwgsm/lwgsm_conn.c"
    "lwgsm/src/lwgsm/lwgsm_clock.c"
    "lwgsm/src/lwgsm/lwgsm_debug.c"
    "lwgsm/src/lwgsm/lwgsm_device_info.c"
    "lwgsm/src/lwgsm/lwgsm_dtmf.c"
    "lwgsm/src/lwgsm/lwgsm_evt.c"
    "lwgsm/src/lwgsm/lwgsm_fs.c"
    "lwgsm/src/lwgsm/lwgsm_input.c"
    "lwgsm/src/lwgsm/lwgsm_int.c"
    "lwgsm/src/lwgsm/lwgsm_ip_app.c"
    "lwgsm/src/lwgsm/lwgsm_mem.c"
    "lwgsm/src/lwgsm/lwgsm_mqtt.c"
    "lwgsm/src/lwgsm/lwgsm_network.c"
    "lwgsm/src/lwgsm/lwgsm_operator.c"
    "lwgsm/src/lwgsm/lwgsm_parser.c"
    "lwgsm/src/lwgsm/lwgsm_pbuf.c"
    "lwgsm/src/lwgsm/lwgsm_phonebook.c"
    "lwgsm/src/lwgsm/lwgsm_ping.c"
    "lwgsm/src/lwgsm/lwgsm_sim.c"
    "lwgsm/src/lwgsm/lwgsm_sms.c"
    "lwgsm/src/lwgsm/lwgsm_ssl.c"
    "lwgsm/src/lwgsm/lwgsm_threads.c"
    "lwgsm/src/lwgsm/lwgsm_timeout.c"
    "lwgsm/src/lwgsm/lwgsm_unicode.c"
    "lwgsm/src/lwgsm/lwgsm_ussd.c"
    "lwgsm/src/lwgsm/lwgsm_utils.c"
    "lwgsm/src/system/lwgsm_mem_lwmem.c"
    "lwgsm/src/system/lwgsm_sys_freeRTOS.c"
    "lwgsm/src/system/lwgsm_ll_esp32.c"
    "lwgsm/src/apps/mqtt/lwgsm_mqtt_client.c"
    "lwgsm/src/apps/mqtt/lwgsm_mqtt_client_api.c"
    "lwgsm/src/apps/mqtt/lwgsm_mqtt_client_evt.c"
  INCLUDE_DIRS  "${PROJECT_DIR}/main/include/"
                "lwgsm/src/include/"
                "lwgsm/src/include/system/"
                "lwgsm/src/include/system/port/freeRTOS"
                "lwgsm/src/include/lwgsm/apps/"

)
