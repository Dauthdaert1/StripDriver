#include "lvgl.h"
#include "display_driver.h"
#include "home.h"
#include "globals.h"

// Custom event handler to differentiate touch events
static void arc_event_handler(lv_event_t * e) {
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * arc = lv_event_get_target(e);

    // Get touch position
    lv_indev_t * indev = lv_indev_get_act();
    if(code == LV_EVENT_PRESSING && indev) {
        lv_point_t touch_point;
        lv_indev_get_point(indev, &touch_point);

        // Get arc's center and radius
        lv_area_t arc_area;
        lv_obj_get_coords(arc, &arc_area);
        lv_coord_t arc_radius = lv_obj_get_width(arc) / 2;
        lv_point_t arc_center = {
            .x = (arc_area.x1 + arc_area.x2) / 2,
            .y = (arc_area.y1 + arc_area.y2) / 2
        };

        // Get the arc's width from its style
        lv_coord_t arc_width = lv_obj_get_style_arc_width(arc, LV_PART_MAIN);

        // Calculate distance from touch point to arc center
        lv_coord_t dx = touch_point.x - arc_center.x;
        lv_coord_t dy = touch_point.y - arc_center.y;
        lv_coord_t distance = lv_sqrt32(dx * dx + dy * dy);

        // Handle touch events
        // Ignore touch events that start within the arc but outside the handle
        if(distance < arc_radius - arc_width / 2 || distance > arc_radius + arc_width / 2) {
            lv_event_stop_processing(e);
        }
    }

    // Call the default event handler
    
}


static void power_handler(lv_event_t * e){
    lv_event_code_t code = lv_event_get_code(e);

    if(code == LV_EVENT_VALUE_CHANGED) {
        //Toggle on off
    }
}

static void value_changed_event_cb(lv_event_t * e)
{
    lv_obj_t * arc = lv_event_get_target(e);
    uint8_t brightness = lv_arc_get_value(arc);
    while(xSemaphoreTake(led_strip_mutex, portMAX_DELAY) !=pdTRUE);
    led_strip_set_pixel(led_strip, 0, brightness, 0, 0);
    led_strip_set_pixel(led_strip, 1, brightness, 0, 0);
    xSemaphoreGive(led_strip_mutex);
}

lv_obj_t* create_home(void){
    lv_obj_t* page = lv_obj_create(NULL);
    lv_obj_set_style_bg_color(page, lv_color_hex(0x707070), LV_PART_MAIN);

    static lv_style_t style_arc;
    lv_style_init(&style_arc);
    lv_style_set_arc_width(&style_arc, 25);  // Set the arc width (10 pixels in this example)

    lv_obj_t * arc = lv_arc_create(page);
    lv_obj_add_style(arc, &style_arc, LV_PART_MAIN);
    lv_obj_add_style(arc, &style_arc, LV_PART_INDICATOR);
    lv_obj_set_size(arc, 200, 200);
    lv_arc_set_rotation(arc, 135);
    lv_arc_set_bg_angles(arc, 0, 270);
    lv_arc_set_range(arc, 0, 255);
    lv_arc_set_value(arc, 10);
    lv_obj_center(arc);
    //lv_obj_add_event_cb(arc, arc_event_handler, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(arc, value_changed_event_cb, LV_EVENT_VALUE_CHANGED, NULL);

    static lv_style_t btn_style;
    lv_style_init(&btn_style);
    lv_style_set_bg_color(&btn_style, lv_color_hex(0xBBBBBB));
    lv_style_set_radius(&btn_style, 200);


    lv_obj_t * btn1 = lv_button_create(page);
    lv_obj_add_style(btn1, &btn_style, 0);
    lv_obj_set_size(btn1, 90, 90);
    lv_obj_add_event_cb(btn1, power_handler, LV_EVENT_ALL, NULL);
    lv_obj_add_flag(btn1, LV_OBJ_FLAG_CHECKABLE);
    lv_obj_center(btn1);

    
    static lv_style_t text_style;
    lv_style_init(&text_style);
    lv_style_set_text_color(&text_style, lv_color_hex(0xFFFFFF));
    lv_style_set_text_font(&text_style, &lv_font_montserrat_48);
    

    lv_obj_t * label1 = lv_label_create(btn1);
    lv_label_set_text(label1, LV_SYMBOL_POWER);
    lv_obj_add_style(label1, &text_style, 0);
    lv_obj_center(label1);

    lv_obj_t * btn2 = lv_button_create(page);
    lv_obj_add_style(btn2, &btn_style, 0);
    lv_obj_set_size(btn2, 50, 50);
    //lv_obj_add_flag(btn2, LV_OBJ_FLAG_HIDDEN);
    //lv_obj_add_event_cb(btn2, power_handler, LV_EVENT_ALL, NULL);
    lv_obj_align(btn2, LV_ALIGN_CENTER, 0, 85);

    lv_obj_t * label2 = lv_label_create(page);
    lv_label_set_text(label2, LV_SYMBOL_SETTINGS);
    //lv_obj_clear_flag(label2, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_style(label2, &text_style, 0);
    lv_obj_align(label2, LV_ALIGN_CENTER, 0, 85);

    /*Manually update the label for the first time*/
    lv_obj_send_event(arc, LV_EVENT_VALUE_CHANGED, NULL);
    

    return page;
}