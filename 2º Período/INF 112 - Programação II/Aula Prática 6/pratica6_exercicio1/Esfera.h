#ifndef INF112_ESFERA_H
#define INF112_ESFERA_H

#include <iomanip>
#include <iostream>
#include <string>

#include "Forma3D.h"

class Esfera : public Forma3D {
private:
    double _raio;
    std::string _nome;
    std::string _cor;

public:
    Esfera(double addRaio, std::string addNome, std::string addCor);
    virtual std::string get_cor();
    virtual std::string get_nome();
    virtual double get_volume();

};

#endif