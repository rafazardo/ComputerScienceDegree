#ifndef INF112_TWODAYPACKAGE_H
#define INF112_TWODAYPACKAGE_H

#include <iomanip>
#include <iostream>
#include <string>

#include "Package.h"

class TwoDayPackage: public Package {
private:
    unsigned int _taxa;
    
public:
    TwoDayPackage(std::string addNome, std::string addEndereco, unsigned int addPeso, unsigned int addCustoPorKG, int addTaxa);
    unsigned int get_taxa();
    virtual double calculateCost() override;
};

#endif