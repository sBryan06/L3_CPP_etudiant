
#ifndef LISTE_HPP_
#define LISTE_HPP_

#include <cassert>
#include <ostream>

// liste d'entiers avec itérateur
template<typename T>
class Liste {
private:
  struct Noeud {
    T _valeur;
    Noeud* _ptrNoeudSuivant;
  };
  Noeud* _ptrTete;
  
public:
  class iterator {

  private:
    Noeud* _ptrNoeudCourant;
    
  public:
    iterator(Noeud* ptrNoeudCourant)
      :_ptrNoeudCourant(ptrNoeudCourant){}
    
    const iterator & operator++() {
       _ptrNoeudCourant = _ptrNoeudCourant->_ptrNoeudSuivant;
      return *this;
    }
    
    T& operator*() const {
      //static int nimpe;
      //return nimpe;
      return _ptrNoeudCourant->_valeur;
    }
    
    bool operator!=(const iterator & it) const {
      return _ptrNoeudCourant != it._ptrNoeudCourant;
    }
    
    friend Liste; 
  };
  
public:
  Liste():_ptrTete(nullptr){}

  ~Liste(){
    clear();
  }
  
  void push_front(T x) {
    //Noeud* n = new Noeud{x, _ptrTete};
    //_ptrTete = n;
    _ptrTete = new Noeud{x, _ptrTete};
  }
  
  T& front() const {
    //atic int nimpe;
    assert(_ptrTete);
    return _ptrTete->_valeur;
  }
  
  void clear() {
    while(_ptrTete){
      Noeud* n = _ptrTete;
      _ptrTete = _ptrTete->_ptrNoeudSuivant;
      delete n;
    }
  }
  
  bool empty() const {
    /*if(_ptrTete == nullptr)
      return true;
    else
      return false;
    */
    //return (_ptrTete==nullptr) ? true : false;
    return _ptrTete == nullptr;
}

  iterator begin() const {
    return iterator(_ptrTete);
  }

  iterator end() const {
    return iterator(nullptr);
  }

};

template<typename T>
std::ostream& operator<<(std::ostream& os, const Liste<T>&) {
  return os;
}

#endif

