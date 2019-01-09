#ifndef RPICLOCK_MAINWINDOW_H
#define RPICLOCK_MAINWINDOW_H

#include <gtkmm/window.h>
#include <gtkmm/button.h>
#include "ClockGrid.h"

class MainWindow : public Gtk::Window {
public:
    MainWindow();

    ~MainWindow() override;

protected:
    ClockGrid clock;

    gboolean on_key_press(GdkEventKey *eventKey);

    bool is_fullscreen = false;

    Glib::RefPtr<Gtk::GestureSwipe> gesture_swipe;
    void on_gesture_swipe_swipe(double velocity_x, double velocity_y);

    void on_realize() override;
};

#endif //RPICLOCK_MAINWINDOW_H
