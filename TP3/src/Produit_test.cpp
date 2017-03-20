#include <CppUTest/CommandLineTestRunner.h>

#include "Produit.hpp"

TEST_GROUP(GroupProduit) { };

TEST(GroupProduit, Produit_test1) 
{
  Produit p(24, "tomates");
  CHECK_EQUAL(p.getId(), 24);
  CHECK_EQUAL(p.getDescription(), "tomates"); 
}
