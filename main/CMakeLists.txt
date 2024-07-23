idf_component_register(SRCS "main.c" "pages/src/home.c"
                       INCLUDE_DIRS "." "pages"
                       REQUIRES lvgl display_drivers)
