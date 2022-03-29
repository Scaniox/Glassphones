//// reads incoming uart data and processes it


#include "globals.h"

const static char* SER_TAG = "serial";
char msg[msg_buf_len] = "";

// serial message handler
void serial_handle_msg(char *msg)
{
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

    else if(strcmp(msg, "bt start") == 0){
        ESP_LOGI(SER_TAG, "start discovery");
        ESP_ERROR_CHECK(esp_bt_gap_start_discovery(ESP_BT_INQ_MODE_GENERAL_INQUIRY, 10, 0));
    }

    else if(strcmp(msg, "bt bonds") == 0){
        esp_bd_addr_t * dev_list = 0; 
        int * len = 50;
        esp_bt_gap_get_bond_device_list(len, dev_list);
        ESP_LOGI("GAP", "listing bonds:");
        for(int i=0; i<len; i++){
            ESP_LOGI("GAP", "%i", (int)dev_list[i]);
        }
    }
    else if(strncmp(msg, "bt set pwr", 10) == 0){
        char *end_of_last_no = 0;
        uint8_t set_tx_min = strtol(msg+10, &end_of_last_no, 10);
        uint8_t set_tx_max = strtol(end_of_last_no, &end_of_last_no, 10);
        ESP_ERROR_CHECK(esp_bredr_tx_power_set(set_tx_min, set_tx_max));
        ESP_LOGI("BT", "tx power set to min LVL%i, max LVL%i", set_tx_min, set_tx_max);
    }

    else if(strcmp(msg, "SD init") == 0){
        ESP_LOGI(SER_TAG, "attempting to init sd card");
        SD_card_init();
    }

    else{
        ESP_LOGI(SER_TAG, "unknown message: %s\n", msg);
    }
}

// reads characters, grouping them into messages ( '.' terminated)
void serial_read_uart(){
    // check if there is data to read
    char c = getchar();
    while(c != 255){
        // msg is full, so clear it
        if(!(strlen(msg) < msg_buf_len)){
            ESP_LOGI(SER_TAG, "error: not enough space for message\n");
            msg[0] = '\0';
        }

        if(c == '.'){
            serial_handle_msg(msg);
            msg[0] = '\0';
        }

        else{
            // add new character
            strncat(msg, &c, 1);
        }

        c = getchar();
    }
}