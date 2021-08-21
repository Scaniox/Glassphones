//// event handlers for bluetooth events (GAP, A2DP)


#include "globals.h"

const static char* GAP_TAG = "gap tag";


// event handlers :
// gap events:
void gap_evt_handler(esp_bt_gap_cb_event_t event, esp_bt_gap_cb_param_t *parameters){
    switch(event){
        case ESP_BT_GAP_DISC_RES_EVT:{ // discovery result event (found currently pairable devices)
            ESP_LOGI(GAP_TAG, "generic discovery event\n");
            uint8_t device_address = *(parameters->disc_res.bda);

            ESP_LOGI(GAP_TAG, "device found, address: %i\n", (int)device_address);

            break;
        }

        case ESP_BT_GAP_DISC_STATE_CHANGED_EVT:{
            ESP_LOGI(GAP_TAG, "discovery state changed\n");
            break;
        }

        case ESP_BT_GAP_READ_REMOTE_NAME_EVT:{ // find a device's name
        char* name = (char*)parameters->read_rmt_name.rmt_name;
        ESP_LOGI(GAP_TAG, "device name event: name: %s\n", name);
        ESP_LOGI(GAP_TAG, "device status: %i\n", parameters->read_rmt_name.stat);
        break;
        }

        case ESP_BT_GAP_AUTH_CMPL_EVT:{
            sender_bt_address = *(parameters->auth_cmpl.bda);
            esp_bt_status_t stat = parameters->auth_cmpl.stat;
            char* name = (char*)parameters->auth_cmpl.device_name;
            ESP_LOGI(GAP_TAG, "auth complete: address: %i, stat: %i, name %s\n", (int)sender_bt_address, (int)stat, name);
            break;
        }

        case ESP_BT_GAP_KEY_NOTIF_EVT:{
            uint8_t addr = *(parameters->key_notif.bda);
            ESP_LOGI(GAP_TAG, "key notif from %i\n, key: %i", addr, (int)parameters->key_notif.passkey);
            break;
        }


        default:{
            ESP_LOGI(GAP_TAG, "gap event %i not handled\n", event);
            break;
        }
    }
}


// info events for a2d:
void a2d_evt_handler(esp_a2d_cb_event_t event, esp_a2d_cb_param_t *parameters){
    switch(event){
        default:{
            ESP_LOGI("A2D", "a2d event %i not handled\n", event);
            break;
        }
    }
}


// data event for a2d
void a2d_dat_evt_handler(const uint8_t *buf, uint32_t len){
    // write data to the i2s bus
    //printf("a2d data: %i bytes arrived\n", len);
    size_t written;
    i2s_write(i2s_port, buf, len, &written, portMAX_DELAY);

}
