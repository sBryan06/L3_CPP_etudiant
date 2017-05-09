#include "PolygoneRegulier.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

#define PI 3.14159265

PolygoneRegulier::PolygoneRegulier(const Couleur& couleur, const Point& centre,
				   int rayon, int nbCotes)
  :FigureGeometrique(couleur), _nbPoints(nbCotes)
{
  //_points = new Point[nbCotes];
  
  double ang = (2 * PI) / nbCotes;

  for (int i = 0; i < _nbPoints; i++)
    {
      int x = centre._x + (rayon * cos(i * ang));
      int y = centre._y + (rayon * sin(i * ang));

      //std::cout << "x[" << i << "] = " << x << std::endl;
      // std::cout << "y[" << i << "] = " << y << std::endl;
    
      Point p{x, y};
      //_points[i] = p;
      _points.push_back (p);
      
    }
}

int PolygoneRegulier::getNbPoints() const{
  return _nbPoints;
}

const Point& PolygoneRegulier::getPoint(int indice) const{
  //return _points[indice];
  return _points.at(indice);
}

void PolygoneRegulier::afficher() const{
  std::stringstream str;
  str << "PolygoneRegulier " << _couleur._r << "_" << _couleur._g
      << "_" << _couleur._b << " ";

  for(int i = 0; i < _nbPoints; i++){
    str << _points[i]._x << "_" << _points[i]._y << " ";
  }
  std::cout << str.str() << std::endl;
  
}

/*PolygoneRegulier::~PolygoneRegulier()
{
  delete [] _points;
  }*/
