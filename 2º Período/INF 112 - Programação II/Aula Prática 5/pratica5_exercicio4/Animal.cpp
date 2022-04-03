#include "Animal.h"
#include <vector>

unsigned int Animal::_next_id=1;

unsigned int Animal::get_new_id(){
    _next_id++;
    return _next_id-1;
}

void popula(std::vector<Animal*>& fazenda, Animal* A, unsigned int max_populacao){
    int escolhido = rand() % fazenda.size();
    fazenda.push_back(A->reproduz());
    if(fazenda.size() < max_populacao){
        popula(fazenda, fazenda[escolhido], max_populacao);
    }
}