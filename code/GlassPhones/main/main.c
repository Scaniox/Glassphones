//// main file

#include "globals.h"

const static char* TAG = "app main";


void app_main() {

    ESP_LOGI(TAG, "start\n");

    ESP_ERROR_CHECK(nvs_flash_init());
    ESP_LOGI(TAG, "nvs init\n");


    // bt init
    ESP_ERROR_CHECK(esp_bt_mem_release(ESP_BT_MODE_BLE));

    static esp_bt_controller_config_t bt_c_cfg = BT_CONTROLLER_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_bt_controller_init(&bt_c_cfg));

    ESP_ERROR_CHECK(esp_bt_controller_enable(ESP_BT_MODE_CLASSIC_BT));

    ESP_ERROR_CHECK(esp_bluedroid_init());
    ESP_ERROR_CHECK(esp_bluedroid_enable());

    switch (esp_bluedroid_get_status()) {
        case ESP_BLUEDROID_STATUS_ENABLED:{
            ESP_LOGI(TAG, "bluedroid enable confirmed\n");
            break;
        }

        case ESP_BLUEDROID_STATUS_INITIALIZED:{
            ESP_LOGI(TAG, "bluedroid initted but not enabled\n");
            break;
        }

        case ESP_BLUEDROID_STATUS_UNINITIALIZED:{
            ESP_LOGI(TAG, "bluedroid not initted\n");
            break;
        }
    }

    // use gap to find sender's bt_adddress

    esp_bt_cod_t cod;
    esp_bt_gap_get_cod(&cod);
    cod.minor |= 6; // headphones
    cod.major |= ESP_BT_COD_MAJOR_DEV_AV ;
    cod.service |= ESP_BT_COD_SRVC_RENDERING | ESP_BT_COD_SRVC_AUDIO;
    esp_bt_gap_set_cod(cod, ESP_BT_INIT_COD);

    esp_bt_gap_register_callback(gap_evt_handler);
    esp_bt_gap_set_scan_mode(ESP_BT_CONNECTABLE, ESP_BT_GENERAL_DISCOVERABLE);

    // start pairing
    ESP_ERROR_CHECK(esp_bt_gap_cancel_discovery());
    ESP_ERROR_CHECK(esp_bt_gap_start_discovery(ESP_BT_INQ_MODE_GENERAL_INQUIRY, 10, 0));
    
    // a2dp setup
    ESP_ERROR_CHECK(esp_a2d_register_callback(&a2d_evt_handler));
    ESP_ERROR_CHECK(esp_a2d_sink_register_data_callback(&a2d_dat_evt_handler));
    ESP_ERROR_CHECK(esp_a2d_sink_init());

    ESP_ERROR_CHECK(esp_a2d_sink_connect(&sender_bt_address));


    max9850e_init();
    max9850e_write_reg(0x02, 0x00);
    #if max9850e_debug
        ESP_LOGI(TAG, "max9850e initted");
    #endif



    // main loop
    while(1){

        // called to keep freertos happy
        vTaskDelay(10);

        serial_read_uart();

    }
}
