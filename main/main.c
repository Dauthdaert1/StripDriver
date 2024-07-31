#include "lvgl.h"
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "led_strip.h"
#include "sdkconfig.h"
#include "display_driver.h"
#include "home.h"
#include "strip_brightness.h"
#include "globals.h"

static const char *TAG = "LED_STRIP";

void app_main(void)
{
    init_globals();
    if (lvgl_mutex == NULL) {
        printf("Mutex creation failed\n");
        return;
    }

    lv_init();
    init_display(&lvgl_mutex);

    //Set Start Screen
    while(xSemaphoreTake(lvgl_mutex, portMAX_DELAY) !=pdTRUE);
    lv_screen_load(create_home());
    xSemaphoreGive(lvgl_mutex);

    set_brightness(100);

    while (true)
    {
        while(xSemaphoreTake(led_strip_mutex, portMAX_DELAY) !=pdTRUE);
        led_strip_refresh(led_strip);
        xSemaphoreGive(led_strip_mutex);
        vTaskDelay(50 / portTICK_PERIOD_MS);
    }
}