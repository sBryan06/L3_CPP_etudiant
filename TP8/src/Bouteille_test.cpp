#include <CppUTest/CommandLineTestRunner.h>

#include "Bouteille.hpp"

#include <sstream>

TEST_GROUP(GroupBouteille) { };

TEST(GroupBouteille, TestBouteille_1) 
{
    Bouteille b{"cyanure", "2013-08-18", 0.25};
	CHECK(b._nom == "cyanure");
	CHECK(b._date == "2013-08-18");
	CHECK(b._volume == 0.25);
}

TEST(GroupBouteille, TestBouteille_2) 
{
	std::locale vieuxLoc = std::locale::global(std::locale("fr_FR.UTF-8"));
	Bouteille b{"cyanure", "2013-08-18", 0.25};
	std::ostringstream stream;
	stream << b;
	CHECK(stream.str() == "cyanure;2013-08-18;0,25\n");
	std::locale::global(vieuxLoc);
}

TEST(GroupBouteille, TestBouteille_3) 
{
	std::locale vieuxLoc = std::locale::global(std::locale("fr_FR.UTF-8"));
	Bouteille b{"a", "b", 2};
	std::istringstream stream("cyanure;2013-08-18;0,25\n");
	stream >> b;
	CHECK(b._nom == "cyanure");
	CHECK(b._date == "2013-08-18");
	CHECK(b._volume == 0.25);
	std::locale::global(vieuxLoc);
}
