#ifndef GUI_WINDOW_HPP_
#define GUI_WINDOW_HPP_

#include <gtkmm.h>

class GuiWindow {
    private:
        Gtk::Main _kit;
        Gtk::Window _window;
        Gtk::Image _image;
    public:
        GuiWindow(int argc, char ** argv);
        void run();

        // TODO
        void todoPlot();
};

#endif

