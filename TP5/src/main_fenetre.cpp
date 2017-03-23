#include <iostream>
#include <gtkmm.h>

#include "ViewerFigures.hpp"

int main(int argc, char ** argv) {
  
  ViewerFigures view (argc, argv);
  view.run();
    
    return 0;
}
