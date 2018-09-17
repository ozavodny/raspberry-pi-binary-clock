#include <iostream>
#include "MainWindow.h"

MainWindow::MainWindow() {
    set_default_size(480, 320);

    add(clock);
    clock.show();

    signal_key_press_event().connect(sigc::mem_fun(*this, &MainWindow::on_key_press));
}

gboolean MainWindow::on_key_press(GdkEventKey *eventKey) {
    if(eventKey->keyval == GDK_KEY_F11) {
        if(is_fullscreen)
            unfullscreen();
        else
            fullscreen();
        is_fullscreen = !is_fullscreen;
    }
    return 0;
}

MainWindow::~MainWindow() = default;
