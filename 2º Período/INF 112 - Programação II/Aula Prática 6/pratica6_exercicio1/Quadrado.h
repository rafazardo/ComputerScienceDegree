#ifndef INF112_QUADRADO_H
#define INF112_QUADRADO_H

#include <iomanip>
#include <iostream>
#include <string>

#include "Forma2D.h"

class Quadrado : public Forma2D {
private:
    double _lado;
    std::string _nome;
    std::string _cor;

public:
    Quadrado(double addLado, std::string addNome, std::string addCor);
    virtual std::string get_cor();
    virtual std::string get_nome();
    virtual double get_area();
    virtual double get_perimetro();

};

#endif