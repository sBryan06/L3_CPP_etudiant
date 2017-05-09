#include <iostream>

#include "ZoneDessin.hpp"

#include "PolygoneRegulier.hpp"
#include "Ligne.hpp"

ZoneDessin::ZoneDessin()
{

  PolygoneRegulier poly = new PolygoneRegulier({0, 0.75, 0}, {375, 120},100, 5);
//PolygoneRegulier poly2 = new PolygoneRegulier(Couleur{0, 0.75, 0},
//						Point{320, 300}, 60, 6);
  //Ligne lign1({1,0,1},{0,0},{100,200});
  
  _figures.push_back(&poly);
  //_figures.push_back(poly2);
  //_figures.push_back(&lign1);

  std::cout << "coucou je fais un test dans CONSTRUCTEUR" << std::endl;
  
}

ZoneDessin::~ZoneDessin()
{
  //return test
}

bool ZoneDessin::on_expose_event(GdkEventExpose*){
  std::cout << "coucou je fais un test" << std::endl;
  for(FigureGeometrique * fig : _figures){
    fig->afficher();
  }
  return true;
}
