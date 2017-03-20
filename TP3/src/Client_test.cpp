#include <CppUTest/CommandLineTestRunner.h>

#include "Client.hpp"

TEST_GROUP(GroupClient) { };

TEST(GroupClient, Client_test1) 
{
  Client c (42, "toto");
  CHECK_EQUAL(c.getId(), 42);
  CHECK_EQUAL(c.getNom(), "toto");
}
