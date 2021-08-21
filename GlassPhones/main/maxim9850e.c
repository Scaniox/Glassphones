//// interface + drivers for DAC/AMP chip
#include "globals.h"

#define max9850e_debug true

// Mclk config
#define max9850e_clk_channel 0
#define max9850e_clk_f 7680000 //7.680mhz mclk for 44.1khz sample rate
#define max9850e_clk_pin 23

// i2c config
#define max9850e_i2c_SCL_pin 22
#define max9850e_i2c_SDA_pin 21
#define max9850e_i2c_clk_f 50000
#define max9850e_i2c_port 0
#define max9850e_addr 0x10 // address pin grounded


void max9850e_init(){

    // set up Mclk source using ledc
    const static ledc_timer_config_t timer_cfg = {
        .speed_mode = LEDC_HIGH_SPEED_MODE,
        .duty_resolution = LEDC_TIMER_1_BIT,
        .timer_num = LEDC_TIMER_0,
        .freq_hz = (max9850e_clk_f),
    };

    ledc_timer_config(&timer_cfg);

    const static ledc_channel_config_t channel_cfg = {
        .gpio_num = (max9850e_clk_pin),
        .speed_mode = LEDC_HIGH_SPEED_MODE,
        .channel = (max9850e_clk_channel),
        .timer_sel = LEDC_TIMER_0,
        .duty = 1, // 50% duty 1 bit square wave
    };

    ledc_channel_config(&channel_cfg);

    #if max9850e_debug
        ESP_LOGI("max9850e", "MCLK started");
    #endif

    // i2c setup
    const static i2c_config_t max9850e_i2c_cfg = {
        .mode = I2C_MODE_MASTER,
        .sda_io_num = (max9850e_i2c_SDA_pin),
        .scl_io_num = (max9850e_i2c_SCL_pin),
        .sda_pullup_en = GPIO_PULLUP_ENABLE,
        .scl_pullup_en = GPIO_PULLUP_ENABLE,
        .master.clk_speed = (max9850e_i2c_clk_f),
    };

    i2c_param_config(max9850e_i2c_port, &max9850e_i2c_cfg);
    i2c_driver_install(max9850e_i2c_port, I2C_MODE_MASTER, 0, 0, 0);

    #if max9850e_debug
        ESP_LOGI("max9850e", "i2c started");
    #endif

    // startup config
    // enable all but line in by setting enable reg (0x05) to 0xFD
    max9850e_write_reg(0x05, 0xFD);
    // enable integer mode by setting reg (0x08) to 0x80
    max9850e_write_reg(0x08, 0x80);
    // set dac integer mode divider ratio by setting LSB reg (0x9) to 0x0B
    max9850e_write_reg(0x09, 0x0B);
    // accept i2s complying data by setting digital audio reg (0x0A) to 0x08
    max9850e_write_reg(0x0A, 0x08);

}

// writes a byte to a register
void max9850e_write_reg(uint8_t reg, uint8_t data){
    i2c_cmd_handle_t cmd = i2c_cmd_link_create();

    i2c_master_start(cmd);
    i2c_master_write_byte(cmd, (max9850e_addr << 1), I2C_MASTER_ACK);
    i2c_master_write_byte(cmd, reg, I2C_MASTER_ACK);
    i2c_master_write_byte(cmd, data, I2C_MASTER_ACK);
    i2c_master_stop(cmd);

    i2c_master_cmd_begin(max9850e_i2c_port, cmd, 10);
    i2c_cmd_link_delete(cmd);
}


// reads a byte from a register
uint8_t max9850e_read_reg(uint8_t reg){
    i2c_cmd_handle_t cmd = i2c_cmd_link_create();
    uint8_t data = 0;

    i2c_master_start(cmd);
    i2c_master_write_byte(cmd, (max9850e_addr << 1), I2C_MASTER_ACK);
    i2c_master_write_byte(cmd, reg, I2C_MASTER_ACK);
    i2c_master_start(cmd);
    i2c_master_write_byte(cmd, (max9850e_addr << 1 | 1), I2C_MASTER_ACK);
    i2c_master_read_byte(cmd, &data, I2C_MASTER_NACK);
    i2c_master_stop(cmd);

    i2c_master_cmd_begin(max9850e_i2c_port, cmd, 10);
    i2c_cmd_link_delete(cmd);

    return data;
}


// dumps all registers' values
void max9850e_reg_dump(){
    ESP_LOGI("max9850e", "register values:");
    for(int reg=0; reg<=0x0A; reg++){
        ESP_LOGI("max9850e", "0x%02x : 0x%02x", reg, max9850e_read_reg(reg));
    }
}
