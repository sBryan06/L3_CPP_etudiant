#include "Controleur.hpp"

#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>

Controleur::Controleur(int argc, char ** argv) {
    _vues.push_back(std::make_unique<VueGraphique>(argc, argv, *this));
}

void Controleur::run() {
    for (auto & v : _vues)
        v->run();
}


