
#define CONTROLS 5

#define GUI_ELEMENTS 0

#define TAB_ELEMENTS 0


#define PLUGIN_UI_URI "urn:bill:monospace_ui"


#include "lv2_plugin.h"

void set_costum_theme(Widget_t *w) {
    w->color_scheme->normal = (Colors) {
         /* cairo    / r  / g  / b  / a  /  */
        .fg =       { 0.850, 0.850, 0.850, 1.000},
        .bg =       { 0.100, 0.100, 0.100, 1.000},
        .base =     { 0.000, 0.000, 0.000, 1.000},
        .text =     { 0.900, 0.900, 0.900, 1.000},
        .shadow =   { 0.000, 0.000, 0.000, 0.200},
        .frame =    { 0.000, 0.000, 0.000, 1.000},
        .light =    { 0.100, 0.100, 0.100, 1.000}
    };

    w->color_scheme->prelight = (Colors) {
         /* cairo    / r  / g  / b  / a  /  */
        .fg =       { 1.000, 0.000, 1.000, 1.000},
        .bg =       { 0.250, 0.250, 0.250, 1.000},
        .base =     { 0.300, 0.300, 0.300, 1.000},
        .text =     { 1.000, 1.000, 1.000, 1.000},
        .shadow =   { 0.100, 0.100, 0.100, 0.400},
        .frame =    { 0.300, 0.300, 0.300, 1.000},
        .light =    { 0.300, 0.300, 0.300, 1.000}
    };

    w->color_scheme->selected = (Colors) {
         /* cairo    / r  / g  / b  / a  /  */
        .fg =       { 0.900, 0.900, 0.900, 1.000},
        .bg =       { 0.200, 0.200, 0.200, 1.000},
        .base =     { 0.500, 0.180, 0.180, 1.000},
        .text =     { 1.000, 1.000, 1.000, 1.000},
        .shadow =   { 0.800, 0.180, 0.180, 0.200},
        .frame =    { 0.500, 0.180, 0.180, 1.000},
        .light =    { 0.500, 0.180, 0.180, 1.000}
    };

    w->color_scheme->active = (Colors) {
         /* cairo    / r  / g  / b  / a  /  */
        .fg =       { 0.000, 1.000, 1.000, 1.000},
        .bg =       { 0.000, 0.000, 0.000, 1.000},
        .base =     { 0.180, 0.380, 0.380, 1.000},
        .text =     { 0.750, 0.750, 0.750, 1.000},
        .shadow =   { 0.180, 0.380, 0.380, 0.500},
        .frame =    { 0.180, 0.380, 0.380, 1.000},
        .light =    { 0.180, 0.380, 0.380, 1.000}
    };

    w->color_scheme->insensitive = (Colors) {
         /* cairo    / r  / g  / b  / a  /  */
        .fg =       { 0.850, 0.850, 0.850, 0.500},
        .bg =       { 0.100, 0.100, 0.100, 0.500},
        .base =     { 0.000, 0.000, 0.000, 0.500},
        .text =     { 0.900, 0.900, 0.900, 0.500},
        .shadow =   { 0.000, 0.000, 0.000, 0.100},
        .frame =    { 0.000, 0.000, 0.000, 0.500},
        .light =    { 0.100, 0.100, 0.100, 0.500}
    };
}

#include "lv2_plugin.cc"



void plugin_value_changed(X11_UI *ui, Widget_t *w, PortIndex index) {
    // do special stuff when needed
}

void plugin_set_window_size(int *w,int *h,const char * plugin_uri) {
    (*w) = 480; //set initial width of main window
    (*h) = 333; //set initial height of main window
}

const char* plugin_set_name() {
    return "monospace"; //set plugin name to display on UI
}

void plugin_create_controller_widgets(X11_UI *ui, const char * plugin_uri) {
    set_costum_theme(ui->win);
    ui->widget[0] = add_lv2_knob (ui->widget[0], ui->win, 3, "DELAYMILLISECONDS", ui, 44,  61, 167, 195);
    set_adjustment(ui->widget[0]->adj, 20.0, 20.0, 1.0, 40.0, 1.0, CL_CONTINUOS);

    ui->widget[1] = add_lv2_knob (ui->widget[1], ui->win, 4, "IMAGEVOLUME", ui, 222,  99, 129, 80);
    set_adjustment(ui->widget[1]->adj, 0.0, 0.0, -96.0, 0.0, 0.1, CL_CONTINUOS);

    ui->widget[2] = add_lv2_knob (ui->widget[2], ui->win, 5, "LOWPASSFILTERFREQ", ui, 343,  139, 125, 80);
    set_adjustment(ui->widget[2]->adj, 8000.0, 8000.0, 20.0, 20000.0, 100.0, CL_CONTINUOS);

    ui->widget[3] = add_lv2_hslider (ui->widget[3], ui->win, 6, "IMAGEPAN", ui, 351,  81, 120, 30);
    set_adjustment(ui->widget[3]->adj, 20.0, 20.0, -90.0, 90.0, 1.0, CL_CONTINUOS);

    ui->widget[4] = add_lv2_hslider (ui->widget[4], ui->win, 7, "ORIGINALPAN", ui, 266,  22, 217, 50);
    set_adjustment(ui->widget[4]->adj, -20.0, -20.0, -90.0, 90.0, 1.0, CL_CONTINUOS);

}

void plugin_cleanup(X11_UI *ui) {
    // clean up used sources when needed
}


void plugin_port_event(LV2UI_Handle handle, uint32_t port_index,
                        uint32_t buffer_size, uint32_t format,
                        const void * buffer) {
    // port value change message from host
    // do special stuff when needed
}

