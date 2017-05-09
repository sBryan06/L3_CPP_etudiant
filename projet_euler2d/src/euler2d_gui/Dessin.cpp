#include "Dessin.hpp"
#include <iostream>

bool Dessin::on_expose_event(GdkEventExpose*) {

    Glib::RefPtr<Gdk::Window> window = get_window();
    if (window) {
        Cairo::RefPtr<Cairo::Context> cr = window->create_cairo_context();
        cr->set_source_rgb(1.0, 0.0, 0.0);
        dessinerDisque(20, 200, 300, cr);
    }

    return true;
}

void Dessin::dessinerDisque(double rayon, int x, int y, 
        Cairo::RefPtr<Cairo::Context> ptrContext) {

    ptrContext->save();
    ptrContext->translate(x, y);
    ptrContext->scale(rayon, rayon);
    ptrContext->arc(0, 0, 1, 0, 2*M_PI);
    ptrContext->fill();
    ptrContext->restore();
    ptrContext->stroke();
}


