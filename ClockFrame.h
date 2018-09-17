#ifndef RPICLOCK_CLOCKFRAME_H
#define RPICLOCK_CLOCKFRAME_H

#include <gtkmm/container.h>
#include <gtkmm/table.h>
#include <gtkmm/grid.h>
#include "ClockPixel.h"

class ClockFrame : public Gtk::Grid {
public:
    ClockFrame();

protected:
    std::vector<ClockPixel *> pixels;

    bool on_timeout();
};

#endif //RPICLOCK_CLOCKFRAME_H
