#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "led_strip.h"
#include "sdkconfig.h"
#include "lvgl.h"
#include "display_driver.h"

/* Use project configuration menu (idf.py menuconfig) to choose the GPIO to blink,
   or you can edit the following line and set a number here.
*/
#define BLINK_GPIO 14

static const char *TAG = "LED_STRIP";
static led_strip_handle_t led_strip;


/* LED strip initialization with the GPIO and pixels number*/
led_strip_config_t strip_config = {
    .strip_gpio_num = BLINK_GPIO, // The GPIO that connected to the LED strip's data line
    .max_leds = 3, // The number of LEDs in the strip,
    .led_pixel_format = LED_PIXEL_FORMAT_GRB, // Pixel format of your LED strip
    .led_model = LED_MODEL_WS2812, // LED strip model
    .flags.invert_out = false, // whether to invert the output signal (useful when your hardware has a level inverter)
};

led_strip_spi_config_t spi_config = {
    .clk_src = SPI_CLK_SRC_DEFAULT, // different clock source can lead to different power consumption
    .flags.with_dma = true, // Using DMA can improve performance and help drive more LEDs
    .spi_bus = SPI2_HOST,   // SPI bus ID
};

static void slider_event_cb(lv_event_t * e)
{
    lv_obj_t * slider = lv_event_get_target(e);
    set_brightness((uint8_t) lv_slider_get_value(slider));
}

void app_main(void)
{
    lv_init();
    init_display();
    
    set_brightness(100);

    /*Change the active screen's background color*/
    lv_color_t color = lv_color_hex(0x0000FF);
    printf("Red: %u\n", color.red);
    printf("Green: %u\n", color.green);
    printf("Blue: %u\n", color.blue);
    


    lv_obj_set_style_bg_color(lv_screen_active(), color, LV_PART_MAIN);
    ESP_LOGI(TAG, "4");

    /*Create a white label, set its text and align it to the center*/
    //lv_obj_t * label = lv_label_create(lv_screen_active());
    //lv_label_set_text(label, "Hello world");
    //lv_obj_set_style_text_color(lv_screen_active(), lv_color_hex(0xffffff), LV_PART_MAIN);
    //lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);

    //lv_obj_t * slider = lv_slider_create(lv_screen_active());
    //lv_slider_set_value(slider, 10, LV_ANIM_ON);
    //lv_slider_set_range(slider, 0, 100);
    //lv_obj_set_size(slider, 100, 10);
    //lv_obj_center(slider);
    //lv_obj_add_event_cb(slider, slider_event_cb, LV_EVENT_VALUE_CHANGED, NULL);

    ESP_ERROR_CHECK(led_strip_new_spi_device(&strip_config, &spi_config, &led_strip));
    while (true)
    {
        led_strip_clear(led_strip);
        led_strip_refresh(led_strip);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        led_strip_set_pixel(led_strip, 0, 255, 0, 0);
        led_strip_refresh(led_strip);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        led_strip_set_pixel(led_strip, 1, 255, 0, 0);
        led_strip_refresh(led_strip);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}