#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "led_strip.h"
#include "sdkconfig.h"
#include "lvgl.h"
#include "lvgl_helpers.h"

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


void app_main(void)
{
    ESP_ERROR_CHECK(led_strip_new_spi_device(&strip_config, &spi_config, &led_strip));
    while (true)
    {
        led_strip_clear(led_strip);
        led_strip_refresh(led_strip);
        vTaskDelay(CONFIG_BLINK_PERIOD / portTICK_PERIOD_MS);
        led_strip_set_pixel(led_strip, 0, 255, 0, 0);
        led_strip_refresh(led_strip);
        vTaskDelay(CONFIG_BLINK_PERIOD / portTICK_PERIOD_MS);
        led_strip_set_pixel(led_strip, 1, 255, 0, 0);
        led_strip_refresh(led_strip);
        vTaskDelay(CONFIG_BLINK_PERIOD / portTICK_PERIOD_MS);
    }
}
