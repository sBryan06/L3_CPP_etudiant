#include <iostream>
#include "FigureGeometrique.hpp"
#include "Ligne.hpp"

int main(){
  Couleur c{1,0,0};
  Point p0{0,0};
  Point p1{100,200};
  Ligne ligne(c, p0 , p1);
  ligne.afficher();
  return 0;
} 
