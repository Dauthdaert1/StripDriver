#ifndef LED_DRIVER_H
#define LED_DRIVER_H

#include "led_strip.h"

/*===============*
   GPIO MAPPINGS
 *===============*/
#define PIN_NUM_STRIP 14


/*========================*
   Configuration Settings
 *========================*/
#define STRIP_SPI       SPI2_HOST
#define UPDATE_RATE_MS  50

/*==========*
   Typedefs
 *==========*/

/*Lighting Modes*/
typedef enum{
    SOLID_COLOR,
    COLOR_SHIFT,
    BREATHE,
    RAINBOW,
}led_light_mode_t;

/*Struct to Store RGB*/
typedef struct{
    uint32_t red;
    uint32_t green;
    uint32_t blue;
}led_color_t;

/*Struct defining how to display lights*/
typedef struct{
    led_light_mode_t mode;
    led_color_t color1;
    led_color_t color2;
    led_color_t color3;
    uint32_t var1;
    uint32_t var2;
    uint32_t var3;
}led_display_t;


/*===========*
   Functions
 *===========*/

/** 
 * @brief Initalizes LED strip
 * @param num_leds The number of LEDs to use
 * @note Is for WS2812 LED strips, must be modified for others
*/
void init_strip(uint16_t num_leds);

/**
 * @brief Sets output for LED strip
 * @param display The led_display_t configuration to display
 */
void set_strip(led_display_t* display);

/**
 * @brief Sets brightness value 0-255
 * @param brightness
 */
void set_strip_brightness(uint8_t brightness);

/**
 * @brief Gets current brightness
 * @returns Brightness value 0-255
 */
uint8_t get_strip_brightness();

/**
 * @brief Call periodically to update LEDs
 * @returns Time to wait for next call (in ms)
 */
uint32_t strip_timer_handler();

#endif