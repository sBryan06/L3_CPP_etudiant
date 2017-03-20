#ifndef LOCATION_HPP
#define LOCATION_HPP

struct Location {
  int _idClient;
  int _idProduit;

  Location(int idClient, int idProduit);
  void afficherLocation() const; 
};
#endif 
