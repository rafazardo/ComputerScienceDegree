#ifndef INF112_FORMA2D_H
#define INF112_FORMA2D_H

#include <iostream>
#include <iomanip>
#include <string>

#include "Forma.h"

class Forma2D : public Forma {
private:

public:
    virtual double get_area() = 0;
    virtual double get_perimetro() = 0;

};

#endif