#include <iostream>
#include <iomanip>

#include "arquivo.hpp"

Aquecedor::Aquecedor() {
    _temperatura = 20.00;
    _temperaturaMinima = 10.00;
    _temperaturaMaxima = 40.00;
    _temperaturaFatorDeIncremento = 5.00;
}

Aquecedor::Aquecedor(double addTemperaturaInicial) {
    _temperatura = addTemperaturaInicial;
    _temperaturaMinima = 10.00;
    _temperaturaMaxima = 40.00;
}

Aquecedor::Aquecedor(double addTemperaturaInicial, double addTemperaturaFatorDeIncremento) {
    _temperatura = addTemperaturaInicial;
    _temperaturaMinima = 10.00;
    _temperaturaMaxima = 40.00;
    _temperaturaFatorDeIncremento = addTemperaturaFatorDeIncremento;
}

double Aquecedor::getTemperatura() {
    return _temperatura;
}

void Aquecedor::aquecer() {
    if (_temperatura + _temperaturaFatorDeIncremento > _temperaturaMaxima) {
        std::cout << "Desculpe, nao podemos aquecer " << _temperaturaFatorDeIncremento <<  " graus, pois ira ultrapassar a temperatura maxima de " << _temperaturaMaxima << " Graus!" << std::endl; 
        std::cout << "-----------------------------------" << std::endl;
    }
    else {
        _temperatura += _temperaturaFatorDeIncremento;
    }
    
}

void Aquecedor::esfriar() {
    if (_temperatura - _temperaturaFatorDeIncremento < _temperaturaMinima) {
        std::cout << "Desculpe, nao podemos esfriar " << _temperaturaFatorDeIncremento <<  " graus, pois ira ficar abaixo da temperatura minima de " << _temperaturaMinima << " Graus!" << std::endl; 
        std::cout << "-----------------------------------" << std::endl;
    }
    else {
        _temperatura -= _temperaturaFatorDeIncremento;
    }

}

void Aquecedor::setFatorDeIncrementoDaTemperatura(double addFatorDeIncrementoDaTemperatura) {
    _temperaturaFatorDeIncremento = addFatorDeIncrementoDaTemperatura;
}