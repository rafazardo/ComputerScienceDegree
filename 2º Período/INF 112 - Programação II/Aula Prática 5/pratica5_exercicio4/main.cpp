#include "Vaca.h"
#include "Cachorro.h"
#include <iostream>
#include <vector>

int main(void) {

    std::vector <Animal*> fazenda;

    fazenda.push_back(new Vaca("marrom",10));
    fazenda.push_back(new Cachorro("branco"));

    fazenda[0]->faz_barulho();

    popula(fazenda,fazenda[0],10);
    for(unsigned int i=0;i<fazenda.size();i++){
        std::cout << fazenda[i]->get_id() << std::endl;
    }
}