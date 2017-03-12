#ifndef FIGUREGEOMETRIQUE_HPP
#define FIGUREGEOMETRIQUE_HPP

#include "Couleur.hpp"

class FigureGeometrique
{
 protected:
  Couleur _couleur;
 public:
  FigureGeometrique(const Couleur& couleur);
  const Couleur& getCouleur() const;
};

#endif
