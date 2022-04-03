#ifndef INF112_CUBO_H
#define INF112_CUBO_H

#include <iomanip>
#include <iostream>
#include <string>

#include "Forma3D.h"

class Cubo : public Forma3D {
private:
    double _lado;
    std::string _nome;
    std::string _cor;

public:
    Cubo(double addLado, std::string addNome, std::string addCor);
    virtual std::string get_cor();
    virtual std::string get_nome();
    virtual double get_volume();

};

#endif