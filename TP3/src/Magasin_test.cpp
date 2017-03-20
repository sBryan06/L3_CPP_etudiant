#include <CppUTest/CommandLineTestRunner.h>

#include "Magasin.hpp"
#include <string>
#include <algorithm>

template <typename>
bool contains(std::vector<T> container, T value)
{
  for (auto& c : container)
    if (c == value) return true;

  return false;
}

TEST_GROUP(GroupMagasin) { };

TEST(GroupMagasin, Magasin_test1) 
{
  Magasin m;
  CHECK_EQUAL(m.nbClients(), 0); 
}

TEST(GroupMagasin, Magasin_test2) 
{
  Magasin m;
  CHECK_EQUAL(m.nbClients(), 0);
  CHECK_EQUAL(m.nbClients(), 0);
  m.ajouterClient("Toto");
  m.ajouterClient("Titi");
  m.ajouterClient("Tutu");
  CHECK_EQUAL(m.nbClients(), 3);
  m.supprimerClient(2);
  CHECK_EQUAL(m.nbClients(), 2);
}

TEST(GroupMagasin, Magasin_test3)
{
  Magasin m;
  m.ajouterProduit("Bananes");
  m.ajouterProduit("Tomates");
  CHECK_EQUAL(m.nbProduits(), 2);
  m.supprimerProduit(1);
  std::string b("Produit inexistant");
  CHECK_THROWS(std::string, m.supprimerProduit(2));
}

TEST(GroupMagasin, Magasin_test4)
{
  Magasin m;

  m.ajouterClient("Mike");
  m.ajouterClient("John");
  m.ajouterClient("Henri");
  m.ajouterClient("Marise");
  m.ajouterClient("Jenny");
  
  // Produits libres
  m.ajouterProduit("Bananes");
  m.ajouterProduit("Glaces");
  m.ajouterProduit("Steak");
  m.ajouterProduit("Poisson");

  // Location Mike Bananes, Mike Glaces
  m.ajouterLocation(0, 0);
  m.ajouterLocation(0, 1);
  m.ajouterLocation(1, 2);

  // Check des quantités
  CHECK_EQUAL(m.nbClients(), 5);
  CHECK_EQUAL(m.nbProduits(), 4);
  CHECK_EQUAL(m.nbLocations(), 3);
  m.supprimerLocation(1, 2);
  CHECK_EQUAL(m.nbLocations(), 2);

  std::vector<int> clientsLibres {1, 2, 3, 4};
  std::vector<int> produitsLibres {2, 3};

  std::vector<int> cLibres = m.calculerClientsLibres();
  std::vector<int> pLibres = m.calculerProduitsLibres();
    
  for (auto& i : clientsLibres)
    CHECK_TRUE(contains(cLibres, i));

  for (auto& i : produitsLibres)
    CHECK_TRUE(contains(produitsLibres, i));

  CHECK_TRUE(m.trouverClientDansLocation(0));
  CHECK_FALSE(m.trouverClientDansLocation(1));

  CHECK_TRUE(m.trouverProduitDansLocation(0));
  CHECK_FALSE(m.trouverProduitDansLocation(3));
}
