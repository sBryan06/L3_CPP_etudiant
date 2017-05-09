#ifndef VIEWERFIGURES_HPP
#define VIEWERFIGURES_HPP

#include <gtkmm.h>

#include "ZoneDessin.hpp"

class ViewerFigures
{
 private:
  Gtk::Main _kit;
  Gtk::Window _window;
  ZoneDessin _zone;
 public:
  ViewerFigures(int argc, char** argv);
  void run();
};

#endif
