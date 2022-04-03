#ifndef INF112_FORMA3D_H
#define INF112_FORMA3D_H

#include <iostream>
#include <iomanip>
#include <string>

#include "Forma.h"

class Forma3D : public Forma {
private:

public:
    virtual double get_volume() = 0;
    
};

#endif