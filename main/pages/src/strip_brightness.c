#include "strip_brightness.h"
#include "lvgl.h"
#include "globals.h"

static void value_changed_event_cb(lv_event_t * e)
{
    lv_obj_t * arc = lv_event_get_target(e);
    lv_obj_t * label = lv_event_get_user_data(e);
    uint8_t brightness = lv_arc_get_value(arc);
    while(xSemaphoreTake(led_strip_mutex, portMAX_DELAY) !=pdTRUE);
    led_strip_set_pixel(led_strip, 0, brightness, 0, 0);
    led_strip_set_pixel(led_strip, 1, brightness, 0, 0);
    xSemaphoreGive(led_strip_mutex);

    lv_label_set_text_fmt(label, "%" LV_PRId32 "%%", lv_arc_get_value(arc));

    /*Rotate the label to the current position of the arc*/
    lv_arc_rotate_obj_to_angle(arc, label, 25);

    //lv_obj_invalidate(arc);
    //lv_obj_invalidate(label);
}

lv_obj_t* create_brightness(void){
    lv_obj_t* page = lv_obj_create(NULL);

    
    lv_color_t color = lv_color_hex(0xFFFFFF);
    lv_obj_set_style_bg_color(page, color, LV_PART_MAIN);

    lv_obj_t * label = lv_label_create(page);
    lv_obj_t * arc = lv_arc_create(page);
    lv_obj_set_size(arc, 150, 150);
    lv_arc_set_rotation(arc, 135);
    lv_arc_set_bg_angles(arc, 0, 270);
    lv_arc_set_range(arc, 0, 255);
    lv_arc_set_value(arc, 10);
    lv_obj_center(arc);
    lv_obj_add_event_cb(arc, value_changed_event_cb, LV_EVENT_VALUE_CHANGED, label);

    /*Manually update the label for the first time*/
    lv_obj_send_event(arc, LV_EVENT_VALUE_CHANGED, NULL);

    return page;
}