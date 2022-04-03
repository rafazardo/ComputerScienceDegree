#ifndef INF112_OVERNIGHTPACKAGE_H
#define INF112_OVERNIGHTPACKAGE_H

#include <iomanip>
#include <iostream>
#include <string>

#include "Package.h"

class OvernightPackage : public Package {
private:
    unsigned int _taxaCustoPorKG;
public:
    OvernightPackage(std::string addNome, std::string addEndereco, unsigned int addPeso, unsigned int addCustoPorKG, int addTaxaCustoPorKG);
    unsigned int get__taxaCustoPorKG();
    virtual double calculateCost() override;
};

#endif