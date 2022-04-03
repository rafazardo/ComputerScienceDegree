#include <iostream>
#include <iomanip>

#include "arquivo.hpp"

int main () {

    Rectangle r1, r2;

    std::cout << r1.getLength() << std::endl;
    std::cout << r2.getWidth() << std::endl;

    r1.setLenght(21);
    r1.setWidth(-2);
    r2.setLenght(15);
    r2.setWidth(7);
    
    std::cout << r1.calcPerimeter() << std::endl;
    std::cout << r2.calcArea() << std::endl;

    return 0; 
}