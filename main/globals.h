#ifndef GLOBALS_H
#define GLOBALS_H

#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"
#include "led_strip.h"

// Declare mutex handles as extern
extern SemaphoreHandle_t lvgl_mutex;
extern SemaphoreHandle_t led_strip_mutex;
extern led_strip_handle_t led_strip;

void init_globals(void);

#endif