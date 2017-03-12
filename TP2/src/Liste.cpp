#include "Liste.hpp"
#include <cassert>

Liste::Liste():_tete(nullptr){}

void Liste::ajouterDevant(int x){
  /*Noeud* ptr new Noeud;
  ptr->_valeur = x;
  ptr->_suivant = _tete;
  _tete = n;*/
  
  _tete = new Noeud {x, _tete};
}


int Liste::getTaille() const{
  int compteur = 0;
  Noeud* ptr = _tete;
  if(ptr  != nullptr){
    while(ptr){
      compteur++;
      ptr = ptr->_suivant;
    }
  }
  return compteur;
}

int Liste::getElement(int i) const{
  Noeud* p = _tete;
  for(int j=0; j<i; j++){
    assert(p);
    p = p->_suivant;
  }
  assert(p);
  return p->_valeur;
}




