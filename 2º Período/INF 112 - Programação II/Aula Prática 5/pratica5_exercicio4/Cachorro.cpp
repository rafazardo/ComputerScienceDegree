#include <iostream>
#include "Cachorro.h"
#include "Animal.h"

Cachorro::Cachorro(std::string cor){
    _cor=cor;
    _id=Animal::get_new_id();
}
Animal* Cachorro::reproduz(){
    Animal* filhote= new Cachorro(_cor);
    return filhote;
}
void Cachorro::faz_barulho(){
    std::cout<<"Au Au"<<std::endl;
}

unsigned int Cachorro::get_id(){
    return _id;
}
