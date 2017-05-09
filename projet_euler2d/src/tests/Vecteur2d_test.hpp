#include <functional>
#include <euler2d/Vecteur2d.hpp>

TEST_GROUP(GroupVecteur2d) { };

TEST(GroupVecteur2d, Vecteur2d_plus_1) { 
    Vecteur2d v1 {1, 2};
    Vecteur2d v2 {3, 4};
    Vecteur2d v3 = v1 + v2;
    DOUBLES_EQUAL(4, v3._x, 1e-6);
    DOUBLES_EQUAL(6, v3._y, 1e-6);
}

