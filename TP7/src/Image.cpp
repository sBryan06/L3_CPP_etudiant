#include "Image.hpp"

Image::Image(int largeur, int hauteur):
  _largeur(largeur), _hauteur(hauteur)
{
  _pixels = new int[largeur * hauteur];
}

/*int Image::getLargeur() const{
  return _largeur;
}

int Image::getHauteur() const{
  return _hauteur;
}

int Image::getPixel(int i, int j) const{
  return _pixels[_largeur*i + j];
}
*/

const int & Image::getLargeur() const{
  return _largeur;
}

const int & Image::getHauteur() const{
  return _hauteur;
}

const int & Image::getPixel(int i, int j) const{
  return _pixels[_largeur*i + j];
}

//void setPixel(int i, int j, int couleur);
int & Image::setPixel(int i, int j){
  return _pixels[_largeur*i + j];
}

/*void Image::setPixel(int i, int j, int couleur){
  _pixels[_largeur*i +j] = couleur;
  }*/

Image::~Image() {
    delete [] _pixels;
}


				       

