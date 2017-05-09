#include <iostream>

#include "Liste.hpp"

int main() {

  Liste<int> l1;
  l1.push_front(37);
  l1.push_front(13);
  
  for(int x: l1){
    std::cout << x << std::endl;
  }
  
  std::cout << "for iterator: " << std::endl;
  for(Liste<int>::iterator it = l1.begin(); it!= l1.end(); ++it){
    std::cout << *it << std::endl;
  }
  
  std::cout << l1 << std::endl;
  
    return 0;
}

