#include <iostream>
#include "Liste.hpp"

int main(){
  Liste l;
  l.ajouterDevant(12);
  std::cout << l.getTaille() << std::endl;
  return 0;
}
