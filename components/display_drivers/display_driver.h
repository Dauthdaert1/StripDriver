#ifndef DISPLAY_DRIVER_H
#define DISPLAY_DRIVER_H

#include "lvgl.h"

//GPIO Pins connected to the LCD display
#define PIN_NUM_MISO 19
#define PIN_NUM_MOSI 23
#define PIN_NUM_CLK  18
#define PIN_NUM_CS   5
#define PIN_NUM_DC   32
#define PIN_NUM_RST  33
#define PIN_NUM_BL   25

//SPI to use for LCD controller
#define DISPLAY_SPI     SPI3_HOST

//Display Width and Height
#define DISPLAY_WIDTH   240
#define DISPLAY_HEIGHT  240

// Frame buffers 1/10th the size of screen to reduce ram
// Multiply by 2 for 16 bit color mapping
#define BUFFER_SIZE 2*DISPLAY_WIDTH*DISPLAY_HEIGHT/10

/** 
 * Must be called to initialize connection with GC9A01 LCD controller before it can be used.
 * Initalizes SPI and GPIO for LCD control, as well as registers with LVGL to handle display output.
 * TODO: Initalize Touch Screen with CST816S touch controller
*/
void init_display();

/**
 * Implementation of function to print the buffer in px_map to the display to be called by LVGL
 * Following implementation in: https://docs.lvgl.io/master/porting/display.html#flush-cb
 */
void display_flush_cb(lv_display_t * display, const lv_area_t * area, void * px_map);

#endif