#include <giomm.h>
#include "ClockPixel.h"

bool ClockPixel::on_draw(const Cairo::RefPtr<Cairo::Context> &cr) {
    cr->set_source_rgb(active_style->b.r, active_style->b.g, active_style->b.b);
    cr->rectangle(0, 0, 80, 80);
    cr->fill();
    cr->rectangle(5, 5, 70, 70);
    if(!active)
        cr->set_source_rgb(active_style->i.r, active_style->i.g, active_style->i.b);
    else
        cr->set_source_rgb(active_style->a.r, active_style->a.g, active_style->a.b);
    cr->fill();

    return true;
}


ClockPixel::ClockPixel() {
    set_size_request(80, 80);
}

ClockPixel &ClockPixel::setActive(bool active) {
    this->active = active;
    return *this;
}

ClockPixel::~ClockPixel() = default;
