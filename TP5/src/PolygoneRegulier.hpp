#ifndef POLYGONEREGULIER_HPP
#define POLYGONEREGULIER_HPP

#include "FigureGeometrique.hpp"
#include "Point.hpp"
#include "Couleur.hpp"

class PolygoneRegulier : public FigureGeometrique {
 private:
  int _nbPoints;
  Point* _points;
public:
  PolygoneRegulier(const Couleur& couleur, const Point& centre, int rayon
		   , int nbCotes);
  void afficher() const override;
  int getNbPoints() const;
  const Point& getPoint(int indice) const;
  ~PolygoneRegulier();
};

#endif
