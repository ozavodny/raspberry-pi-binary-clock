

#include <gtkmm/application.h>
#include "MainWindow.h"

int main(int argc, char *argv[]) {
    auto app = Gtk::Application::create(argc, argv, "net.zavodny.rpiclock");

    MainWindow mainWindow;

    return app->run(mainWindow);
}