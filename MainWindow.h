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
};

#endif //RPICLOCK_MAINWINDOW_H
