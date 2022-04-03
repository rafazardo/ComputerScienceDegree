#include <iostream>
#include <iomanip>

#include "arquivo.hpp"

Rectangle::Rectangle() {
    _width = 1;
    _length = 1;
};

float Rectangle::getLength() {
    return _length;
}

float Rectangle::getWidth() {
    return _width;
}

void Rectangle::setLenght(float addLenght) {

    if (addLenght > 20.0) {
        std::cout << "Desculpe, nao podemos inserir o valor " << addLenght  <<", pois ele é maior que 20.0" << std::endl;
    }
    else {
        if (addLenght < 0.0) {
            std::cout << "Desculpe, nao podemos inserir o valor " << addLenght << ", pois ele é menor que 0.0" << std::endl;
        }
        else {
            _length = addLenght;
        }
    }

}

void Rectangle::setWidth(float addWidth) {

    if (addWidth > 20.0) {
        std::cout << "Desculpe, nao podemos inserir o valor " << addWidth  << ", pois ele é maior que 20.0" << std::endl;
    }
    else {
        if (addWidth < 0.0) {
            std::cout << "Desculpe, nao podemos inserir o valor " << addWidth << ", pois ele é menor que 0.0" << std::endl;
        }
        else {
            _width = addWidth;
        }
    }

}

float Rectangle::calcPerimeter() {
    return (2*_width) + (2*_length);
}

float Rectangle::calcArea() {
    return _width*_length;
}