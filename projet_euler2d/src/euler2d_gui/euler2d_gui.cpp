#include "Dessin.hpp"

int main(int argc, char ** argv) {

    Gtk::Main kit(argc, argv);
    Gtk::Window window;
    Dessin dessin;
    window.add(dessin);
    window.set_size_request(800, 600);
    window.set_resizable(false);
    window.show_all();
    kit.run(window);

    return 0;
}

