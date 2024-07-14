/**
 * @file display_driver.h
 *  Modified From: https://github.com/lvgl/lvgl_esp32_drivers/blob/9fed1cc47b5a45fec6bae08b55d2147d3b50260c/lvgl_tft/GC9A01.h
 */

#ifndef DISPLAY_DRIVER_H
#define DISPLAY_DRIVER_H

/*********************
 *      INCLUDES
 *********************/
#include <stdbool.h>
#include "lvgl.h"


/*********************
 *      DEFINES
 *********************/
#define GC9A01_DC   32
#define GC9A01_RST  33
#define GC9A01_BCKL 25

#define GC9A01_INVERT_COLORS false

/**********************
 * GLOBAL PROTOTYPES
 **********************/

void display_init(void);
void display_flush(const lv_area_t * area, lv_color_t * color_map);
void display_enable_backlight(bool backlight);
void display_sleep_in(void);
void display_sleep_out(void);

#endif /*DISPLAY_DRIVER_H*/