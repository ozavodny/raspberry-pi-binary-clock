#include <giomm.h>
#include <iostream>
#include "ClockGrid.h"

ClockGrid::ClockGrid() {
    Glib::signal_timeout().connect(sigc::mem_fun(*this, &ClockGrid::on_timeout), 1000);

    for (int i = 5; i >= 0; i--) {
        for (int j = 3; j >= 0; j--) {
            auto pixel = new ClockPixel();
            pixel->active_style = styles + style;
            pixels.push_back(pixel);
            pixel->show();
            attach(*pixel, i, j, 1, 1);
        }
    }
}

bool ClockGrid::on_timeout() {
    auto win = get_window();
    if (win) {
        Gdk::Rectangle r(0, 0, win->get_width(),
                         win->get_height());
        win->invalidate_rect(r, false);
    }

    time_t raw_time;
    time(&raw_time);
    struct tm *time_info = localtime(&raw_time);

    int times[3] = {time_info->tm_hour, time_info->tm_min, time_info->tm_sec};

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 4; j++) {
            pixels[i * 2 * 4 + j]->setActive(static_cast<bool>((times[i] / 10) & 1 << (3 - j)));
            pixels[(i * 2 + 1) * 4 + j]->setActive(static_cast<bool>((times[i] % 10) & 1 << (3 - j)));
        }

    return true;
}

void ClockGrid::cycle_forward() {
    style++;
    if(style == style_count)
        style = 0;
    update_styles();
}

void ClockGrid::cycle_backward() {
    style--;
    if(style < 0)
        style = style_count - 1;
    update_styles();
}

void ClockGrid::update_styles() {

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            pixels[i * 4 + j]->active_style = styles + style;
        }
    }
}
