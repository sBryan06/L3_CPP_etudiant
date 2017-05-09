#include "Controleur.hpp"

#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>


Controleur::Controleur(int argc, char ** argv) {
  _inventaire._bouteilles.push_back(Bouteille{"cyanure", "2013-08-18", 0.25});
  _vues.push_back(std::make_unique<VueGraphique>(argc, argv, *this));
}

void Controleur::run() {
    for (auto & v : _vues)
        v->run();
}

std::string Controleur::getText(){
  std::ostringstream oss;
  std::string str;
  oss << _inventaire;
  str = oss.str();
  std::cout << "test: " << str << std::endl;
  return str;
}


