#define max9850e_debug true

// Mclk config
#define max9850e_clk_channel 0
#define max9850e_clk_f 7680000 //7.680mhz mclk for 44.1khz sample rate
#define max9850e_clk_pin 21

// i2c config
#define max9850e_i2c_SCL_pin 19
#define max9850e_i2c_SDA_pin 18
#define max9850e_i2c_clk_f 50000
#define max9850e_i2c_port 0
#define max9850e_addr 0x10 // address pin grounded

// i2s config
#define max9850e_i2s_port 0
#define max9850e_i2s_BCLK 26
#define max9850e_i2s_LRCLK 27
#define max9850e_i2s_SDIN 23

void max9850e_init();

void max9850e_write_reg(uint8_t reg, uint8_t data);

uint8_t max9850e_read_reg(uint8_t reg);

void max9850e_reg_dump();
