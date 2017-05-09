#ifndef DESSIN_HPP_
#define DESSIN_HPP_

#include <gtkmm.h>

class Dessin : public Gtk::DrawingArea {

    public:

    private:
        bool on_expose_event(GdkEventExpose*) override;

        void dessinerDisque(double rayon, int x, int y, 
                Cairo::RefPtr<Cairo::Context> ptrContext);

};

#endif

