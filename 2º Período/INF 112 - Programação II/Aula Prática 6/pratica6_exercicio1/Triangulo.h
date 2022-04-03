#ifndef INF112_TRIANGULO_H
#define INF112_TRIANGULO_H

#include <iomanip>
#include <iostream>
#include <string>

#include "Forma2D.h"

class Triangulo : public Forma2D {
private:
    double _lado1;
    double _lado2;
    double _lado3;
    double _altura;
    std::string _nome;
    std::string _cor;
    
public:
    Triangulo(double addLado1, double addLado2, double addLado3, double addAltura, std::string addNome, std::string addCor);
    Triangulo(double addLado1eLado2, double addLado3, double addAltura, std::string addNome, std::string addCor);
    Triangulo(double addLado1eLado2eLado3, double addAltura, std::string addNome, std::string addCor);
    virtual std::string get_cor();
    virtual std::string get_nome();   
    virtual double get_area();
    virtual double get_perimetro();
    
};

#endif