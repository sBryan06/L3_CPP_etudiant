#include <iostream>
#include "Location.hpp"

Location::Location(int idClient, int idProduit) :
  _idClient(idClient),
  _idProduit(idProduit)
{}

void Location::afficherLocation() const
{
  std::cout <<  "Location(" << _idClient << ", " << _idProduit << ")" << std::endl; 
}
