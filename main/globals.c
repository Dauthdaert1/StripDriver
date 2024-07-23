#include "globals.h"
#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"
#include "led_strip.h"

SemaphoreHandle_t lvgl_mutex = NULL;
SemaphoreHandle_t led_strip_mutex = NULL;
led_strip_handle_t led_strip = NULL;

void init_globals(void){
    lvgl_mutex = xSemaphoreCreateMutex();
    led_strip_mutex = xSemaphoreCreateMutex();

}