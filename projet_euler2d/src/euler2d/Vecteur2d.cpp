#include <euler2d/Vecteur2d.hpp>
#include <cmath>

Vecteur2d operator+(const Vecteur2d & v1, const Vecteur2d & v2) {
    return Vecteur2d{v1._x + v2._x, v1._y + v2._y};
}

