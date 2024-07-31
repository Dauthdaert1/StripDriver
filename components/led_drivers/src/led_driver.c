#include "led_driver.h"
#include "led_strip.h"
#include <string.h>

/*==========*
   Typedefs
 *==========*/
typedef void (*led_function_t)(int);

/*=======================
   File Static Variables  
  =======================*/
static led_strip_handle_t led_strip;
static led_strip_spi_config_t spi_config = {
    .clk_src = SPI_CLK_SRC_DEFAULT, // different clock source can lead to different power consumption
    .flags.with_dma = true, // Using DMA can improve performance and help drive more LEDs
    .spi_bus = STRIP_SPI,   // SPI bus ID
};
static led_display_t display_config;
static led_function_t stored_led_function = NULL;
static uint8_t strip_brightness = 255;


/*==============================
   Static Function Declarations  
  ==============================*/
void solid_color(int time);
void color_shift(int time);
void breathe(int time);
void rainbow(int time);


/*=============================
   Public Function Definitions
  =============================*/
void init_strip(uint16_t num_leds){
    if(led_strip!=NULL){
        led_strip_del(led_strip);
    }

    /* LED strip initialization with the GPIO and pixels number*/
    led_strip_config_t strip_config = {
        .strip_gpio_num = PIN_NUM_STRIP, // The GPIO that connected to the LED strip's data line
        .max_leds = num_leds, // The number of LEDs in the strip,
        .led_pixel_format = LED_PIXEL_FORMAT_GRB, // Pixel format of  your LED strip
        .led_model = LED_MODEL_WS2812, // LED strip model
        .flags.invert_out = false, // whether to invert the output signal (useful when your hardware has a level inverter)
    };

    ESP_ERROR_CHECK(led_strip_new_spi_device(&strip_config, &spi_config, &led_strip));
    led_strip_clear(led_strip);
}

void set_strip(led_display_t* display){
    memcpy(&display_config, display, sizeof(led_display_t));
    switch (display->mode)
    {
    case SOLID_COLOR:
        stored_led_function = solid_color;
        break;
    case COLOR_SHIFT:
        stored_led_function = color_shift;
        break;
    case BREATHE:
        stored_led_function = breathe;
        break;
    case RAINBOW:
        stored_led_function = rainbow;
        break;
    default:
        //Error
        break;
    }
}

void set_strip_brightness(uint8_t brightness){
    strip_brightness = brightness;
}

uint8_t get_strip_brightness(){
    return strip_brightness;
}

/*=============================
   Static Function Definitions  
  =============================*/

void solid_color(int time){

}

void color_shift(int time){

}

void breathe(int time){

}

void rainbow(int time){

}