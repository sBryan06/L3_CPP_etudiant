#ifndef VECTEUR2D_HPP_
#define VECTEUR2D_HPP_

struct Vecteur2d {
    double _x;
    double _y;
};

Vecteur2d operator+(const Vecteur2d & v1, const Vecteur2d & v2);

#endif

