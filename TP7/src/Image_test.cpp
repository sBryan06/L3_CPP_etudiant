#include <CppUTest/CommandLineTestRunner.h>

#include "Image.hpp"

TEST_GROUP(GroupImage) { };

TEST(GroupImage, test_largeur_image) 
{
  Image im{20, 25};
  CHECK_EQUAL(im.getLargeur(), 20);
}

TEST(GroupImage, test_hauteur_image) 
{
  Image im{20, 25};
  CHECK_EQUAL(im.getHauteur(), 25);
}

TEST(GroupImage, test_pixel_image) 
{
  Image im{20, 25};
  im.setPixel(10,10)=127;
  CHECK_EQUAL(im.getPixel(10,10), 127);
}


/*TEST(GroupDoubler, Doubler_test2) 
{
    CHECK_EQUAL(doubler(0), 0);
    }*/

