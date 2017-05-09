#include "ViewerFigures.hpp"

ViewerFigures::ViewerFigures(int argc, char** argv)
  : _kit(argc, argv){
  _window.set_title("First fenetre");
  _window.set_default_size(640, 480);

  _window.add(_zone);
}

void ViewerFigures::run(){
  _window.show_all();
  _kit.run(_window);
}
