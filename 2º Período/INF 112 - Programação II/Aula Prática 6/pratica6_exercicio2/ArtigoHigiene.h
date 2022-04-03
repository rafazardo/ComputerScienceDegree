#ifndef INF112_ARTIGOHIGIENE_H
#define INF112_ARTIGOHIGIENE_H

#include <iostream>
#include <iomanip>
#include <string>

#include "Produto.h"

class ArtigoHigiene : public Produto {
private:
    double _percentualDeLucro = 30.0;
public:
    ArtigoHigiene(int addCodigo, std::string addDescricao, double addPrecoCompra);
    double get_percentualDeLucro();
    virtual double gerarPrecoDeVenda();
};

#endif