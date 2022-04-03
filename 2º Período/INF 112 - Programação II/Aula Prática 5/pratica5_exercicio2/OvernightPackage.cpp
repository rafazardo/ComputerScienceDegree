#include <iomanip>
#include <iostream>
#include <string>

#include "Package.h"
#include "OvernightPackage.h"

OvernightPackage::OvernightPackage(std::string addNome, std::string addEndereco, unsigned int addPeso, unsigned int addCustoPorKG, int addTaxaCustoPorKG):
    Package(addNome, addEndereco, addPeso, addCustoPorKG), _taxaCustoPorKG(addTaxaCustoPorKG) {};

unsigned int OvernightPackage::get__taxaCustoPorKG() {
    return this->_taxaCustoPorKG;
}

double OvernightPackage::calculateCost() {
    return (_custoPorKG + _taxaCustoPorKG)*_peso;
} 