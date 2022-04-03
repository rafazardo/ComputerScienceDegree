#ifndef INF112_REMEDIO_H
#define INF112_REMEDIO_H

#include <iostream>
#include <iomanip>
#include <string>

#include "Produto.h"

class Remedio : public Produto {
private:
    double _percentualDeLucro;
    double _valorDoDesconto;

public:
    Remedio(int addCodigo, std::string addDescricao, double addPrecoCompra, double addPercentualDeLucro, double addValorDoDesconto);
    double get_percentualDeLucro();
    double get_valorDoDesconto();
    virtual double gerarPrecoDeVenda();
};

#endif