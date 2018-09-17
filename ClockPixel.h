#ifndef RPICLOCK_CLOCKPIXEL_H
#define RPICLOCK_CLOCKPIXEL_H

#include <gtkmm/drawingarea.h>

class ClockPixel : public Gtk::DrawingArea {
public:
    ClockPixel();

    ~ClockPixel() override;

    void setActive(bool active = false);

protected:
    bool on_draw(const Cairo::RefPtr<Cairo::Context> &cr) override;

    bool active = false;
};

#endif //RPICLOCK_CLOCKPIXEL_H
