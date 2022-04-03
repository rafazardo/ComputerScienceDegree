#include <iomanip>
#include <iostream>
#include <string>

#include "TwoDayPackage.h"
#include "Package.h"

TwoDayPackage::TwoDayPackage(std::string addNome, std::string addEndereco, unsigned int addPeso, unsigned int addCustoPorKG, int addTaxa):
    Package(addNome, addEndereco, addPeso, addCustoPorKG), _taxa(addTaxa) {};

unsigned int TwoDayPackage::get_taxa() {
    return this->_taxa;
}

double TwoDayPackage::calculateCost() {
    return (_peso*_custoPorKG) + _taxa;
}