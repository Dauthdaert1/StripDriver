#ifndef DISPLAY_DRIVER_H
#define DISPLAY_DRIVER_H

#include "lvgl.h"
#include "driver/i2c_master.h"

//GPIO Pins connected to the LCD display
#define PIN_NUM_MISO 19
#define PIN_NUM_MOSI 23
#define PIN_NUM_CLK  18
#define PIN_NUM_CS   5
#define PIN_NUM_DC   32
#define PIN_NUM_RST  33
#define PIN_NUM_BL   25

//GPIO Pins connected to touch controller
#define PIN_TP_SDA   21
#define PIN_TP_SCL   22
#define PIN_TP_INT   26
#define PIN_TP_RST   27

//SPI to use for LCD controller
#define DISPLAY_SPI     SPI3_HOST

//I2C to use for touch controller
#define TOUCH_I2C       I2C_NUM_1

//Display Width and Height
#define DISPLAY_WIDTH   240
#define DISPLAY_HEIGHT  240

// Frame buffers 1/10th the size of screen to reduce ram
// Multiply by 2 for 16 bit color mapping
#define BUFFER_SIZE 2*DISPLAY_WIDTH*DISPLAY_HEIGHT/10

/** 
 * Must be called to initialize connection with GC9A01 LCD controller before it can be used.
 * Initalizes SPI and GPIO for LCD control, as well as registers with LVGL to handle display output.
 * Initalizes Touch Screen with CST816S touch controller
*/
void init_display();

/**
 * Implementation of function to print the buffer in px_map to the display to be called by LVGL
 * Following implementation in: https://docs.lvgl.io/master/porting/display.html#flush-cb
 */
void display_flush_cb(lv_display_t * display, const lv_area_t * area, unsigned char * px_map);

/**
 * Used to control brightness of display with PWM wave
 * Acceptable values are 0 - 100
 */
void set_brightness(uint8_t brightness);

#endif