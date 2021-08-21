
void gap_evt_handler(esp_bt_gap_cb_event_t event, esp_bt_gap_cb_param_t *parameters);

void a2d_evt_handler(esp_a2d_cb_event_t event, esp_a2d_cb_param_t *parameters);

void a2d_dat_evt_handler(const uint8_t *buf, uint32_t len);
