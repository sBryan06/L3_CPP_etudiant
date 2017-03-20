#include "Magasin.hpp"
#include <iostream>
#include <string>
#include <utility>
#include <stdexcept>

Magasin::Magasin() :
_idCourantClient(0),
_idCourantProduit(0)
{ }

int Magasin::nbClients() const { return _clients.size();  }
int Magasin::nbProduits() const { return _produits.size(); }

void Magasin::ajouterClient(const std::string& nom)
{
  Client c(_idCourantClient++, nom);
  _clients.push_back(c);
}

void Magasin::ajouterProduit(const std::string& nom)
{
  Produit p(_idCourantProduit++, nom);
  _produits.push_back(p);
}

void Magasin::afficherClients() const
{
  for (auto &c : _clients)
    c.afficherClient();
}

void Magasin::afficherProduits() const
{
  for (auto &p : _produits)
    p.afficherProduit();
}

void Magasin::supprimerClient(int client)
{
  if (client < 0 or unsigned(client) > _clients.size() - 1)
    throw std::string("Client inexistant");
  
  std::swap(_clients[client], _clients[_clients.size() - 1]);
  _clients.pop_back();
}

void Magasin::supprimerProduit(int produit)
{
  if (produit < 0 or unsigned(produit) > _produits.size() - 1)
    throw std::string("Produit inexistant");
  
  std::swap(_produits[produit], _produits[_produits.size() - 1]);
  _produits.pop_back();
}

int Magasin::nbLocations() const
{
  return _locations.size();
}

void Magasin::ajouterLocation(int idClient, int idProduit)
{
  for (auto& loc : _locations)
  {
    if (loc._idClient == idClient && loc._idProduit == idProduit)
      throw std::runtime_error("Location déjà existante !");
  }
  
  Location location(idClient, idProduit);
  _locations.push_back(location);
}

void Magasin::afficherLocations() const
{
  for (auto& location : _locations)
    location.afficherLocation();
}

void Magasin::supprimerLocation(int idClient, int idProduit)
{
  for (unsigned int i = 0; i < _locations.size(); i++)
  {
    Location location = _locations[i];

    if (location._idClient == idClient and
	location._idProduit == idProduit)
    {
      if (i == _locations.size() - 1)
	_locations.pop_back();
      else
      {
	std::swap(_locations[i], _locations[_locations.size() - 1]);
	_locations.pop_back();
      }
      
      break;
    }
  }
}

bool Magasin::trouverClientDansLocation(int idClient) const
{
  for (auto& loc : _locations)
    if (loc._idClient == idClient)
      return true;

  return false;
}

std::vector<int> Magasin::calculerClientsLibres() const
{
  std::vector<int> libres;

  for (auto& c : _clients) {
    if (!trouverClientDansLocation(c.getId())) {
      libres.push_back(c.getId());
    }
  }

  return libres;
}

bool Magasin::trouverProduitDansLocation(int idProduit) const
{
  for (auto& loc : _locations) {
    if (loc._idProduit == idProduit) {
      return true;
    } 
  }

  return false;
}

std::vector<int> Magasin::calculerProduitsLibres() const
{
  std::vector<int> libres;

  for (auto& p : _produits) {
    if (!trouverProduitDansLocation(p.getId())) {
	libres.push_back(p.getId());
    }
  }
    
  return libres;
}
