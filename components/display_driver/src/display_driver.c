#include "display_driver.h"
#include "lvgl.h"
#include "driver/gpio.h"
#include "driver/spi_master.h"
#include "esp_log.h"

#define TAG "GC9A01"

spi_device_handle_t spi;

// GC9A01 Initialization Sequence
static const uint8_t GC9A01_init_cmds[] = {
    0xEF, 3, 0x03, 0x80, 0x02,
    // ... Add more initialization commands as needed
};

// Function to send data over SPI
static void lcd_spi_send_data(const uint8_t *data, int len) {
    spi_transaction_t t;
    memset(&t, 0, sizeof(t));
    t.length = len * 8;        // Length is in bits
    t.tx_buffer = data;        // Data
    spi_device_transmit(spi, &t);  // Transmit data
}

/** 
 * Configures GPIO and runs commands to initalize LCD screen
*/
void LCD_Init(void){

}

/** 
 * Configures GPIO and runs commands to initalize LCD touch screen
*/
void LCD_Touch_Init(void){

}
