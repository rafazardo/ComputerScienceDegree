#ifndef INF112_PRODUTO_H
#define INF112_PRODUTO_H

#include <iostream>
#include <iomanip>
#include <string>


class Produto {
protected:
    int _codigo;
    std::string _descricao;
    double _precoDeCompra;

public:
    Produto(int addCodigo, std::string addDescricao, double addPrecoDeCompra);
    int get_codigo();
    std::string get_descricao();
    double get_precoDeCompra();
    virtual double gerarPrecoDeVenda() = 0;
    
};


#endif