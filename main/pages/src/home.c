#include "lvgl.h"
#include "display_driver.h"
#include "home.h"
//#include "src/font/lv_font.h"



static void power_handler(lv_event_t * e){

}

lv_obj_t* create_home(void){
    



    lv_obj_t* page = lv_obj_create(NULL);
    lv_obj_set_style_bg_color(page, lv_color_hex(0x000000), LV_PART_MAIN);

    static lv_style_t btn_style;
    lv_style_init(&btn_style);
    lv_style_set_bg_color(&btn_style, lv_color_hex(0xBBBBBB));
    lv_style_set_radius(&btn_style, 200);


    lv_obj_t * btn1 = lv_button_create(page);
    lv_obj_add_style(btn1, &btn_style, 0);
    lv_obj_set_size(btn1, 100, 100);
    lv_obj_add_event_cb(btn1, power_handler, LV_EVENT_ALL, NULL);
    lv_obj_center(btn1);

    static lv_style_t big_style;
    lv_style_init(&big_style);
    lv_style_set_bg_color(&big_style, lv_color_hex(0xFFFFFF));
    lv_style_set_line_color(&big_style, lv_color_hex(0xFFFFFF));
    lv_style_set_line_width(&big_style, 15);
    lv_style_set_line_rounded(&big_style, true);

    lv_obj_t * arc = lv_arc_create(page);
    lv_obj_set_size(arc, 75, 75);
    lv_arc_set_rotation(arc, 270);
    lv_arc_set_bg_angles(arc, 45, 315);
    lv_arc_set_value(arc, 0);
    lv_obj_add_style(arc, &big_style, LV_PART_MAIN);
    lv_obj_remove_style(arc, NULL, LV_PART_KNOB);
    lv_obj_remove_flag(arc, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_center(arc);

    lv_obj_t * line1 = lv_line_create(page);
    static lv_point_precise_t line_points[] = { {0, 5}, {0, 10} };
    lv_line_set_points(line1, line_points, 2);
    lv_obj_add_style(line1, &big_style, 0);
    lv_obj_center(line1);
    


    //static lv_style_t text_style;
    //lv_style_init(&text_style);
    //lv_style_set_text_color(&text_style, lv_color_hex(0xFFFFFF));
    //lv_style_set_text_font(&text_style, &lv_font_montserrat_48);
    

    //lv_obj_t * label1 = lv_label_create(btn1);
    //lv_label_set_text(label1, LV_SYMBOL_POWER);
    //lv_obj_add_style(label1, &text_style, 0);
    //lv_obj_center(label1);


    

    return page;
}