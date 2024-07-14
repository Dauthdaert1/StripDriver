idf_component_register(SRCS "src/display_driver.c" "src/display_spi.c" "src/lvgl_helpers.c"
                    INCLUDE_DIRS "include"
                    REQUIRES lvgl driver)
