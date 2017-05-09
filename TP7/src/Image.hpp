#ifndef IMAGE_HPP_
#define IMAGE_HPP_

#include <string>

class Image{
private:
  int _largeur;
  int _hauteur;
  int * _pixels;

public:
  Image(int largeur, int hauteur);
  ~Image();
  //int getLargeur() const;
  //int getHauteur() const;
  //int getPixel(int i, int j) const;
  const int & getLargeur() const;
  const int & getHauteur() const;
  const int & getPixel(int i, int j) const;
  //void setPixel(int i, int j, int couleur);
  int & setPixel(int i, int j);
};

#endif
