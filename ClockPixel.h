#ifndef RPICLOCK_CLOCKPIXEL_H
#define RPICLOCK_CLOCKPIXEL_H

#include <gtkmm/drawingarea.h>

class ClockPixel : public Gtk::DrawingArea {
public:
    ClockPixel();
    ~ClockPixel() override;

    ClockPixel &setActive(bool active = false);

    struct Color {
        double r, g, b;
        Color(double r, double g, double b): r(r / 255), g(g / 255), b(b / 255) {};
    };
    struct Style {
        Color b, i, a;
    };
    const Style *active_style;
protected:
    bool on_draw(const Cairo::RefPtr<Cairo::Context> &cr) override;

    bool active = false;
};

#endif //RPICLOCK_CLOCKPIXEL_H
