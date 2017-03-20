#include "Location.hpp"
#include "Client.hpp"
#include "Produit.hpp"
#include "Magasin.hpp"
#include <iostream>

int main(int argc, char** argv)
{
  Location location(0, 2);
  location.afficherLocation();

  Client client(42, "toto");
  client.afficherClient();

  Produit produit(24, "Tomates");
  produit.afficherProduit();

  Magasin magasin;
  std::cout << "**** MAGASIN ****" << std::endl;
  magasin.ajouterClient("Mike");
  magasin.ajouterClient("Jenny");
  magasin.ajouterClient("Bro");
  magasin.afficherClients();
  std::cout << "Nombre de clients: " << magasin.nbClients() << std::endl;
  magasin.supprimerClient(1);
  std::cout << "Suppression de Jenny" << std::endl;
  magasin.afficherClients();

  magasin.ajouterProduit("Tomates");
  magasin.ajouterProduit("Glaces");
  magasin.afficherProduits();
  std::cout << "Nombre de produits: " << magasin.nbProduits() << std::endl;

  // Erreur intentionnelle
  
  
  return 0;
}
