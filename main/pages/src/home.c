#include "lvgl.h"
#include "display_driver.h"
#include "home.h"

static void slider_event_cb(lv_event_t * e)
{
    lv_obj_t * slider = lv_event_get_target(e);
    set_brightness((uint8_t) lv_slider_get_value(slider));
}

lv_obj_t* create_home(void){
    lv_obj_t* page = lv_obj_create(NULL);


    lv_color_t color = lv_color_hex(0xFFFFFF);
    lv_obj_set_style_bg_color(page, color, LV_PART_MAIN);

    lv_obj_t * slider = lv_slider_create(page);
    lv_slider_set_value(slider, 10, LV_ANIM_ON);
    lv_slider_set_range(slider, 0, 100);
    lv_obj_set_size(slider, 100, 10);
    lv_obj_center(slider);
    lv_obj_add_event_cb(slider, slider_event_cb, LV_EVENT_VALUE_CHANGED, NULL);

    return page;
}