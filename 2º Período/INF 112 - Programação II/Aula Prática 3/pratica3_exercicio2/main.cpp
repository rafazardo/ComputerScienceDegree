#include "arquivo.hpp"
#include <iostream>
#include <iomanip>

int main() {

    float area, volume;
    Cubo *cubo = new Cubo(3.0);

    area = cubo->calculaAreaCubo(); 
    std::cout << area << std::endl;
    volume = cubo->calculaVolumeCubo(); 
    std::cout << volume << std::endl;
    delete cubo;

    return 0; 

}