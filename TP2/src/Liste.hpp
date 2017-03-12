#ifndef LISTE_HPP_
#define LISTE_HPP_

struct Noeud {
  int _valeur;
  Noeud* _suivant;
};

struct Liste{
  Noeud* _tete;

  Liste();
  int getTaille() const;
  void ajouterDevant(int x);
  int getElement(int i) const;
};



#endif
