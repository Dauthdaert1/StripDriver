#ifndef DISPLAY_DRIVER_H

#define DISPLAY_DRIVER_H

typedef struct display_driver
{
    /*https://www.waveshare.com/wiki/1.28inch_Touch_LCD*/
    //Uses 4-line Serial Interface 1
    int GPIO_RESX;  //reset, it is pulled low when the module is powered on, usually set to 1
    int GPIO_CSX;   //slave chip selection, and the chip will be enabled only when CS is low
    int GPIO_DCX;   //data/command control pin of the chip, when DC = 0, write command, when DC = 1, write data.
    int GPIO_SDA;   //transmitted data, that is, RGB data
    int GPIO_SCL;   //SPI communication clock

}display_spi_config_t;


/** 
 * Configures GPIO and runs commands to initalize LCD screen
*/
void LCD_Init(void);

/** 
 * Configures GPIO and runs commands to initalize LCD touch screen
*/
void LCD_Touch_Init(void);

#endif