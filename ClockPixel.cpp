#include <giomm.h>
#include "ClockPixel.h"

bool ClockPixel::on_draw(const Cairo::RefPtr<Cairo::Context> &cr) {
    cr->set_line_width(1);
    cr->rectangle(0, 0, 80, 80);
    double color = (double) active;
    cr->set_source_rgb(color, color, color);
    cr->fill();

    return true;
}


ClockPixel::ClockPixel() {
    set_size_request(80, 80);
}

void ClockPixel::setActive(bool active) {
    this->active = active;
}

ClockPixel::~ClockPixel() = default;
