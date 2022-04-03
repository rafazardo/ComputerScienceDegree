#ifndef INF112_PACKAGE_H
#define INF112_PACKAGE_H

#include <iomanip>
#include <iostream>
#include <string>

class Package {
protected:
    std::string _nome;
    std::string _endereco;
    unsigned int _peso;
    unsigned int _custoPorKG;

public:
    Package(std::string addNome, std::string addEndereco, unsigned int addPeso, unsigned int addCustoPorKG);
    std::string get_nome();
    std::string get_endereco();
    unsigned int get_peso();
    unsigned int get_custoPorKG();
    virtual double calculateCost();
};

#endif