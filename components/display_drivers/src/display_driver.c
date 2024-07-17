#include <stdio.h>
#include <string.h>
#include "display_driver.h"
#include "driver/spi_master.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "lvgl.h"

// Frame buffer 1/5th the size of screen to reduce ram
#define BUFFER_SIZE 2*240*240/5

spi_device_handle_t spi;
lv_display_t * display;
static const char *TAG = "DISPLAY_DRIVER";

static uint8_t frame_buffer[BUFFER_SIZE]; 

//static const uint32_t width = 240;
//static const uint32_t height = 240;

typedef struct {
    uint8_t cmd;
    uint8_t data[16];
    uint8_t databytes; //No of data in data; bit 7 = delay after set; 0xFF = end of cmds.
} lcd_init_cmd_t;

static void send_cmd(lcd_init_cmd_t* cmd);
static void spi_send_cmd(uint8_t cmd);
static void spi_send_data(void * data, uint32_t size);
static void disp_spi_send_data(void * data, uint32_t size);

//https://docs.lvgl.io/master/porting/display.html#flush-cb
void display_flush_cb(lv_display_t * display, const lv_area_t * area, void * px_map){
    ESP_LOGI(TAG, "FLUSH running, X1: %ld, X2: %ld, Y1: %ld, Y2: %ld", area->x1, area->x2, area->y1, area->y2);
    uint16_t * buf16 = (uint16_t *)px_map;

    spi_send_cmd(0x2A);
    uint8_t data_x[4] = {0, area->x1, 0, area->x2};
    spi_send_data(data_x, 4);

    spi_send_cmd(0x2B);
    uint8_t data_y[4] = {0, area->y1, 0, area->y2};
    ESP_LOGI(TAG, "pos %u", ((uint8_t*)&data_y)[2]);
    spi_send_data(data_y, 4);

    spi_send_cmd(0x2C);
    ESP_LOGI(TAG, "Size %u", BUFFER_SIZE);
    spi_send_data(px_map, BUFFER_SIZE);

    lv_display_flush_ready(display);
}

void init_display(){
    esp_err_t ret;

    // Configuration for the SPI bus
    spi_bus_config_t buscfg = {
        .miso_io_num = -1,
        .mosi_io_num = PIN_NUM_MOSI,
        .sclk_io_num = PIN_NUM_CLK,
        .quadwp_io_num = -1,
        .quadhd_io_num = -1,
        .max_transfer_sz = sizeof(frame_buffer),
    };

    // Initialize the SPI bus
    ret = spi_bus_initialize(SPI3_HOST, &buscfg, 1);
    ESP_ERROR_CHECK(ret);

    // Configuration for the SPI device on the bus
    spi_device_interface_config_t devcfg = {
        .clock_speed_hz = 40 * 1000 * 1000, // Clock out at 80 MHz
        .mode = 0,                          // SPI mode 0
        .spics_io_num = PIN_NUM_CS,         // CS pin
        .queue_size = 7,                    // Transaction queue size
        .pre_cb = NULL,                     // Specify pre-transfer callback to handle D/C line
    };

    // Attach the SPI device to the SPI bus
    ret = spi_bus_add_device(SPI3_HOST, &devcfg, &spi);
    ESP_ERROR_CHECK(ret);

    //Configure GPIO
    gpio_config_t io_conf;
    io_conf.intr_type = GPIO_INTR_DISABLE;       // Disable interrupt
    io_conf.mode = GPIO_MODE_OUTPUT;             // Set as output mode
    io_conf.pin_bit_mask = (1ULL << PIN_NUM_DC | 1ULL << PIN_NUM_RST | 1ULL << PIN_NUM_BL);  // Bit mask of the pins to set
    io_conf.pull_down_en = 0;                    // Disable pull-down
    io_conf.pull_up_en = 0;                      // Disable pull-up
    gpio_config(&io_conf);

    gpio_set_level(PIN_NUM_RST, 0);
    vTaskDelay(100 / portTICK_PERIOD_MS);
    gpio_set_level(PIN_NUM_RST, 1);
    vTaskDelay(100 / portTICK_PERIOD_MS);
    gpio_set_level(PIN_NUM_BL, 0);



    //LCD Initalization Commands from: 
    //https://github.com/lvgl/lvgl_esp32_drivers/blob/9fed1cc47b5a45fec6bae08b55d2147d3b50260c/lvgl_tft/GC9A01.c
    lcd_init_cmd_t GC_init_cmds[]={
////////////////////////////////////////////
		{0xEF, {0}, 0},
		{0xEB, {0x14}, 1},

		{0xFE, {0}, 0},
		{0xEF, {0}, 0},

		{0xEB, {0x14}, 1},
		{0x84, {0x40}, 1},
		{0x85, {0xFF}, 1},
		{0x86, {0xFF}, 1},
		{0x87, {0xFF}, 1},
		{0x88, {0x0A}, 1},
		{0x89, {0x21}, 1},
		{0x8A, {0x00}, 1},
		{0x8B, {0x80}, 1},
		{0x8C, {0x01}, 1},
		{0x8D, {0x01}, 1},
		{0x8E, {0xFF}, 1},
		{0x8F, {0xFF}, 1},
		{0xB6, {0x00, 0x20}, 2},
		//call orientation
		{0x3A, {0x05}, 1},
		{0x90, {0x08, 0x08, 0X08, 0X08}, 4},
		{0xBD, {0x06}, 1},
		{0xBC, {0x00}, 1},
		{0xFF, {0x60, 0x01, 0x04}, 3},
		{0xC3, {0x13}, 1},
		{0xC4, {0x13}, 1},
		{0xC9, {0x22}, 1},
		{0xBE, {0x11}, 1},
		{0xE1, {0x10, 0x0E}, 2},
		{0xDF, {0x21, 0x0C, 0x02}, 3},
		{0xF0, {0x45, 0x09, 0x08, 0x08, 0x26, 0x2A}, 6},
		{0xF1, {0x43, 0x70, 0x72, 0x36, 0x37, 0x6F}, 6},
		{0xF2, {0x45, 0x09, 0x08, 0x08, 0x26, 0x2A}, 6},
		{0xF3, {0x43, 0x70, 0x72, 0x36, 0x37, 0x6F}, 6},
		{0xED, {0x1B, 0x0B}, 2},
		{0xAE, {0x77}, 1},
		{0xCD, {0x63}, 1},
		{0x70, {0x07, 0x07, 0x04, 0x0E, 0x0F, 0x09, 0x07, 0X08, 0x03}, 9},
		{0xE8, {0x34}, 1},
		{0x62, {0x18, 0x0D, 0x71, 0xED, 0x70, 0x70, 0x18, 0X0F, 0x71, 0xEF, 0x70, 0x70}, 12},
		{0x63, {0x18, 0x11, 0x71, 0xF1, 0x70, 0x70, 0x18, 0X13, 0x71, 0xF3, 0x70, 0x70}, 12},
		{0x64, {0x28, 0x29, 0xF1, 0x01, 0xF1, 0x00, 0x07}, 7},
		{0x66, {0x3C, 0x00, 0xCD, 0x67, 0x45, 0x45, 0x10, 0X00, 0x00, 0x00}, 10},
		{0x67, {0x00, 0x3C, 0x00, 0x00, 0x00, 0x01, 0x54, 0X10, 0x32, 0x98}, 10},
		{0x74, {0x10, 0x85, 0x80, 0x00, 0x00, 0x4E, 0x00}, 7},
		{0x98, {0x3E, 0x07}, 2},
		{0x35, {0}, 0},
		{0x21, {0}, 0},
		{0x11, {0}, 0x80},	//0x80 delay flag
		{0x29, {0}, 0x80},	//0x80 delay flag
        {0x36, {0x68}, 4}, // Set orientation (0x08, 0xC8, 0x68, 0xA8 for "PORTRAIT", "PORTRAIT_INVERTED", "LANDSCAPE", "LANDSCAPE_INVERTED")
		{0, {0}, 0xff},		//init end flag
////////////////////////////////////////////
	};

    //Send commands
    int curr_cmd = 0;
    while(GC_init_cmds[curr_cmd].databytes!=0xff){
        send_cmd(&GC_init_cmds[curr_cmd]);
        if (GC_init_cmds[curr_cmd].databytes & 0x80) {
			vTaskDelay(100 / portTICK_PERIOD_MS);
		}
        curr_cmd++;
    }

    gpio_set_level(PIN_NUM_BL, 1);


    //Connect to LVGL
    display = lv_display_create(240, 240);
    lv_display_set_flush_cb(display, display_flush_cb);
    lv_display_set_buffers(display, frame_buffer, NULL, sizeof(frame_buffer), LV_DISPLAY_RENDER_MODE_PARTIAL); //TODO: Second buffer for drawing while DMA SPI works, add later
}

void test1(){
    ESP_LOGI(TAG, "Running test program");
    spi_send_cmd(0x2A);
    uint8_t data[4] = {0, 100, 0, 125};
    spi_send_data(&data, 4);

    spi_send_cmd(0x2B);
    spi_send_data(&data, 4);
    
    spi_send_cmd(0x2C);
    uint8_t colors[625*2] = {};
    for(uint32_t i = 0; i < (625*2); i+=2){
        colors[i] = 0b00000000;
        colors[i+1] = 0b00011111;
    }

    spi_send_data(&colors, 625*2);

}

static void send_cmd(lcd_init_cmd_t* cmd) {
    spi_send_cmd(cmd->cmd);

    if (cmd->databytes > 0) {
        spi_send_data(&cmd->data, cmd->databytes);
    }
}

static void spi_send_cmd(uint8_t cmd){
    gpio_set_level(PIN_NUM_DC, 0);
    disp_spi_send_data(&cmd, 1);
}

static void spi_send_data(void * data, uint32_t size){
    gpio_set_level(PIN_NUM_DC, 1);
    disp_spi_send_data(data, size);
}

static void disp_spi_send_data(void * data, uint32_t size){
    spi_transaction_t t;
    memset(&t, 0, sizeof(t));       // Zero out the transaction
    t.length = size * 8;          // Data length in bits
    t.tx_buffer = data;             // The data to be sent
    t.user = (void*)1;              // D/C needs to be set to 1

    // Send the data using DMA
    ESP_ERROR_CHECK(spi_device_transmit(spi, &t));
}