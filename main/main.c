#include "lvgl.h"
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "led_driver.h"
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

    //Start LED Strip with 3 leds
    init_strip(3);

    led_color_t color1 = {
        .red = 0,
        .green = 255,
        .blue = 0,
    };

    led_display_t mode = {
        .mode = SOLID_COLOR,
        .color1 = color1,
    };

    set_strip(&mode);

    while (true)
    {
        uint32_t wait = strip_timer_handler();
        vTaskDelay(wait / portTICK_PERIOD_MS);
    }
}