//// header file for variables shared across all files


// needed headers
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "nvs_flash.h"

#include "driver/gpio.h"
#include "driver/uart.h"

#include "esp_log.h"
#include "esp_err.h"

#include "esp_bt.h"
#include "esp_bt_main.h"
#include "esp_bt_device.h"
#include "esp_gap_bt_api.h"
#include "esp_a2dp_api.h"
#include "esp_avrc_api.h"
#include "BT_event_handlers.h"

#include "driver/i2c.h"
#include "driver/i2s.h"
#include "driver/ledc.h"
#include "maxim9850e.h"

#include "driver/sdmmc_host.h"
#include "sdmmc_cmd.h"
#include "esp_vfs_fat.h"
#include "diskio_sdmmc.h"
#include "SD_card.h"


// serial communication
#define msg_buf_len 100


// bt
uint8_t sender_bt_address;


// i2s
#define i2s_port 0
#define i2s_BCLK 18
#define i2s_LRCLK 19
#define i2s_SDIN 5


// SD card
#define SD_CD 15
#define SD_WP 16
#define SD_BASE_PATH "/SD"
