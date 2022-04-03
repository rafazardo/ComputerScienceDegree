#ifndef INF112_CIRCULO_H
#define INF112_CIRCULO_H

#include <iomanip>
#include <iostream>
#include <string>

#include "Forma2D.h"

class Circulo : public Forma2D {
private:
    double _raio;
    std::string _nome;
    std::string _cor;

public:
    Circulo(double addRaio, std::string addNome, std::string addCor);
    virtual std::string get_cor();
    virtual std::string get_nome();
    virtual double get_area();
    virtual double get_perimetro();
    
};

#endif