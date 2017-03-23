#include <iostream>
#include "FigureGeometrique.hpp"
#include "Ligne.hpp"
#include "PolygoneRegulier.hpp"
#include <vector>

int main(){
  Couleur c{1,0,0};
  Point p0{0,0};
  Point p1{100,200};
  Ligne ligne(c, p0 , p1);
  ligne.afficher();
  
  Couleur cBleu{0,0,1};
  Point pCentre{100,200};
  int rayon{50};
  int nb{5};
  PolygoneRegulier pentagone(cBleu, pCentre, rayon, nb);
  pentagone.afficher();

  std::vector<FigureGeometrique*> figures {&ligne, &pentagone};
  
  // PolygoneRegulier(cBleu, pCentre, rayon, nb) };

  for(FigureGeometrique * fig : figures)
    fig->afficher();
  
  return 0;
} 
