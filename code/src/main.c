//// main file

#include "globals.h"

char msg[msg_buf_len] = "";

const static char* SER_TAG = "serial";
const static char* TAG = "app main";


// serial message handler
void handle_msg(char* msg){
    if(strcmp(msg, "test string") == 0){
        ESP_LOGI(SER_TAG, "specific message recognised\n");
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }

    else if(strcmp(msg, "stats") == 0){
        // return runtime stats
        char stats[1000];
        vTaskGetRunTimeStats(stats);
        printf(stats);
        printf("\n");
    }

    else if(strncmp(msg, "read reg", 8) == 0){
        uint8_t reg = (uint8_t)strtol(msg+8, NULL, 16);
        ESP_LOGI(SER_TAG, "register 0x%02x : 0x%02x", reg, max9850e_read_reg(reg));
    }
    else if(strncmp(msg, "set reg", 7) == 0){
        char* end_of_last_no = 0;
        uint8_t reg = (uint8_t)strtol(msg+7, &end_of_last_no, 16);
        uint8_t val = (uint8_t)strtol(end_of_last_no, &end_of_last_no, 16);
        ESP_LOGI(SER_TAG, "writing (0x%02x) to register 0x%02x", val, reg);
        max9850e_write_reg(reg, val);
    }
    else if(strcmp(msg, "reg dump") == 0){
        max9850e_reg_dump();
    }
    else if(strcmp(msg, "init") == 0){
        max9850e_init();
    }

    else if(strcmp(msg, "timer dump") == 0){
        printf("High speed timers:\n");
        printf("Name:         period:        next alarm:    starts:  triggers:  cb run time:\n");
        esp_timer_dump(stdout);
    }

    else{
        ESP_LOGI(SER_TAG, "unknown message: %s\n", msg);
    }
}

// serial message reciever
void read_uart(){
    // check if there is data to read
    char c = getchar();
    while(c != 255){
        // msg is full, so clear it
        if(!(strlen(msg) < msg_buf_len)){
            ESP_LOGI(SER_TAG, "error: not enough space for message\n");
            msg[0] = '\0';
        }

        if(c == '.'){
            handle_msg(msg);
            msg[0] = '\0';
        }

        else{
            // add new character
            strncat(msg, &c, 1);
        }

        c = getchar();
    }
}


void app_main() {

    ESP_LOGI(TAG, "start\n");

    // config
    gpio_set_direction(5, GPIO_MODE_OUTPUT);
    gpio_set_direction(18, GPIO_MODE_OUTPUT);
    gpio_set_direction(19, GPIO_MODE_OUTPUT);

    ESP_ERROR_CHECK(nvs_flash_init());
    ESP_LOGI(TAG, "nvs init\n");

    // i2s init
    static const i2s_config_t i2s_cfg = {
        .mode = I2S_MODE_MASTER | I2S_MODE_TX,
        .sample_rate = 44100,
        .bits_per_sample = 16,
        .channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT,
        .communication_format = I2S_COMM_FORMAT_STAND_PCM_SHORT,
        .intr_alloc_flags = 0,
        .dma_buf_count = 16,
        .dma_buf_len = 256,
        .tx_desc_auto_clear = true,
    };
    i2s_driver_install(i2s_port, &i2s_cfg, 10, NULL);

    // test: i2s output
    static const i2s_pin_config_t i2s_pin_cfg = {
        .bck_io_num = i2s_BCLK,
        .ws_io_num = i2s_LRCLK,
        .data_out_num = i2s_SDIN,
        .data_in_num = I2S_PIN_NO_CHANGE,
    };
    i2s_set_pin(i2s_port, &i2s_pin_cfg);



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

    // a2dp setup
    ESP_ERROR_CHECK(esp_a2d_register_callback(&a2d_evt_handler));
    ESP_ERROR_CHECK(esp_a2d_sink_register_data_callback(&a2d_dat_evt_handler));
    ESP_ERROR_CHECK(esp_a2d_sink_init());

    ESP_ERROR_CHECK(esp_a2d_sink_connect(&sender_bt_address));

    // start pairing
    //ESP_ERROR_CHECK(esp_bt_gap_start_discovery(ESP_BT_INQ_MODE_GENERAL_INQUIRY, 10, 10));

    max9850e_init();
    max9850e_write_reg(0x02, 0x00);
    #if max9850e_debug
        ESP_LOGI(TAG, "max9850e initted");
    #endif


    // main loop
    while(1){

        // called to keep freertos happy
        vTaskDelay(10);

        read_uart();

    }
}
