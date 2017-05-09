#include "Image.hpp"
#include <cmath>
#include <fstream>
#include <iostream>

void remplir(Image & img){
  for(int x=0; x<img.getLargeur(); x++){
    for(int y=0; y<img.getHauteur(); y++){
      img.setPixel(x, y) = (cos(3*(2*M_PI*y)/img.getLargeur() )+1 )*127;
    }
  }
}

void ecrirePnm(const Image & img, const std::string & nomFichier){
  std::ofstream fichier (nomFichier);

  if(fichier){
    fichier << "P2" << std::endl; // écrit dans le flux
    fichier << 800 << " " << 600 << std::endl;
    fichier << 255 << std::endl;
    
    for(int x=0; x<img.getLargeur(); x++){
      for(int y=0; y<img.getHauteur(); y++){
	fichier << img.getPixel(x, y) << " ";
      }
      fichier << std::endl;
    }
  }
}


int main() {
  Image i{20, 20};
  i.setPixel(10,10)=127;
  std::cout << i.getLargeur() << std::endl;
  std::cout << i.getHauteur() << std::endl;
  std::cout << i.getPixel(10, 10) << std::endl;

  Image img(40,20);
  remplir(img);
  ecrirePnm(img, "image.pnm");
  return 0;
}

