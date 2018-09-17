#ifndef RPICLOCK_CLOCKFRAME_H
#define RPICLOCK_CLOCKFRAME_H

#include <gtkmm/container.h>
#include <gtkmm/table.h>
#include <gtkmm/grid.h>
#include <gtkmm/gestureswipe.h>
#include "ClockPixel.h"

class ClockGrid : public Gtk::Grid {
public:
    ClockGrid();
    void cycle_styles();
    void cycle_forward();
    void cycle_backward();
    void update_styles();

    static const int style_count = 3;
protected:
    std::vector<ClockPixel *> pixels;
    bool on_timeout();
    int style = 0;

    const ClockPixel::Style styles[style_count] = {
            {
                    {68, 50, 102},
                    {140, 72, 159},
                    {195, 195, 229},
                },
            {
                    {204, 102, 0},
                    {255, 153, 0},
                    {255, 251, 208}
            },
            {
                    {51, 51, 51},
                    {68, 68, 68},
                    {100, 100, 100}
            }
    };
};

#endif //RPICLOCK_CLOCKFRAME_H
