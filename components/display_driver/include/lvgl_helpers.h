/**
 * @file lvgl_helpers.h
 * Modified From: https://github.com/lvgl/lvgl_esp32_drivers/blob/9fed1cc47b5a45fec6bae08b55d2147d3b50260c/lvgl_helpers.h
 */

#ifndef LVGL_HELPERS_H
#define LVGL_HELPERS_H

/*********************
 *      INCLUDES
 *********************/
#include <stdbool.h>

#include "lvgl_spi_conf.h"
#include "lvgl_tft/disp_driver.h"
#include "lvgl_touch/touch_driver.h"

/*********************
 *      DEFINES
 *********************/

/* DISP_BUF_SIZE value doesn't have an special meaning, but it's the size
 * of the buffer(s) passed to LVGL as display buffers. The default values used
 * were the values working for the contributor of the display controller.
 *
 * As LVGL supports partial display updates the DISP_BUF_SIZE doesn't
 * necessarily need to be equal to the display size.
 *
 * When using RGB displays the display buffer size will also depends on the
 * color format being used, for RGB565 each pixel needs 2 bytes.
 * When using the mono theme, the display pixels can be represented in one bit,
 * so the buffer size can be divided by 8, e.g. see SSD1306 display size. */
#define DISP_BUF_SIZE  (LV_HOR_RES_MAX * 40)

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/* Initialize detected SPI and I2C bus and devices */
void lvgl_driver_init(void);

/* Initialize SPI master  */
bool lvgl_spi_driver_init(int host, int miso_pin, int mosi_pin, int sclk_pin,
    int max_transfer_sz, int dma_channel, int quadwp_pin, int quadhd_pin);
/* Initialize I2C master  */
bool lvgl_i2c_driver_init(int port, int sda_pin, int scl_pin, int speed);

#endif /* LVGL_HELPERS_H */