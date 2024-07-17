#ifndef DISPLAY_DRIVER_H
#define DISPLAY_DRIVER_H

#include "lvgl.h"

#define PIN_NUM_MISO 19
#define PIN_NUM_MOSI 23
#define PIN_NUM_CLK  18
#define PIN_NUM_CS   5
#define PIN_NUM_DC   32
#define PIN_NUM_RST  33
#define PIN_NUM_BL   25

void init_display();
void display_flush_cb(lv_display_t * display, const lv_area_t * area, void * px_map);
void test1();


#endif