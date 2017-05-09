#include "Inventaire.hpp"

std::ostream& operator <<(std::ostream& os, const Inventaire& i) {
  for(auto & b : i._bouteilles){
    os << b;
  }
  return os;
}

