#ifndef ZONEDESSIN_HPP
#define ZONEDESSIN_HPP

#include <gtkmm.h>

class ZoneDessin : public Gtk::DraingArea
{
 private:
  std::vector<FigureGeometrique*> _figures;
 public:
  ZoneDessin();
  ~ZoneDessin();
};

#endif
