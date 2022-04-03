#ifndef INF112_EXCECAOSOMA_H
#define INF112_EXCECAOSOMA_H

#include <iostream>
#include <iomanip>
#include <stdexcept>

#include "ExcecaoAcimaDeX.h"

class ExcecaoSoma {

private:
    double _x; //Valor maximo da soma
    double _n; //Quantidade de numeros

public:
    ExcecaoSoma();

    double get_x();
    int get_n();

    void set_x(double addX);
    void set_n(int addN);

    void somaValores() throw(ExcecaoAcimaDeX);
};


#endif