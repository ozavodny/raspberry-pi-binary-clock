
#include <iostream>
#include "MainWindow.h"

MainWindow::MainWindow() {
    set_default_size(480, 320);

    add(clock);
    clock.show();

    signal_key_press_event().connect(sigc::mem_fun(*this, &MainWindow::on_key_press));

    gesture_swipe = Gtk::GestureSwipe::create(*this);
    gesture_swipe->signal_swipe().connect(sigc::mem_fun(*this, &MainWindow::on_gesture_swipe_swipe));
    gesture_swipe->set_touch_only(false);
    fullscreen();
}

void MainWindow::on_realize() {
    Widget::on_realize();

    get_window()->set_cursor(Gdk::Cursor::create(Gdk::BLANK_CURSOR));
}

gboolean MainWindow::on_key_press(GdkEventKey *eventKey) {
    switch (eventKey->keyval) {
        case GDK_KEY_F11:
        if (is_fullscreen)
            unfullscreen();
        else
            fullscreen();
        is_fullscreen = !is_fullscreen;
        break;
        case GDK_KEY_Escape:
            destroy_();
            break;
    }
    return 0;
}

void MainWindow::on_gesture_swipe_swipe(double velocity_x, double velocity_y) {
    if(std::abs(velocity_x) > std::abs(velocity_y)) {
        if(velocity_x > 0) {
            clock.cycle_backward();
        } else {
            clock.cycle_forward();
        }
    }
}

MainWindow::~MainWindow() = default;
