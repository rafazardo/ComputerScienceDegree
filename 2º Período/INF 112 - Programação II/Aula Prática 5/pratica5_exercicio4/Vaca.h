#ifndef VACA_H
#define VACA_H

#include <iostream>
#include "Animal.h"

class Vaca : public Animal {
    private:
        float _producao_leite;
    public:
        Vaca(std::string cor,float producao_leite);
        virtual Animal* reproduz();
        virtual void faz_barulho();
        virtual unsigned int get_id();
        float get_producao_leite();
};

#endif