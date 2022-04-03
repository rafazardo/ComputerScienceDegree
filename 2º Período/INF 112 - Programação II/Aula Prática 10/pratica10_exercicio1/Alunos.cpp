#include <iostream>
#include <string>

#include "Alunos.h"

Alunos::Alunos(int addMatricula, std::string addNome, double addNota1, double addNota2):
    _matricula(addMatricula), _nome(addNome), _nota1(addNota1), _nota2(addNota2) {};

Alunos::~Alunos() {}

int Alunos::get_matricula() {
    return this->_matricula;
}

std::string Alunos::get_nome() {
    return this->_nome;
}

double Alunos::get_nota1() {
    return this->_nota1;
}

double Alunos::get_nota2() {
    return this->_nota2;
}

double Alunos::get_media() {
    calcular_media();
    return this->_media;
}

void Alunos::set_matricula(int addMatricula) {
    this->_matricula = addMatricula;
}

void Alunos::set_nome(std::string addNome) {
    this->_nome = addNome;
}

void Alunos::set_nota1(double addNota1) {
    this->_nota1 = addNota1;
}

void Alunos::set_nota2(double addNota2) {
    this->_nota2 = addNota2;
}

void Alunos::set_media(double addMedia) {
    this->_media = addMedia;
}      

void Alunos::calcular_media() {
    this->_media = (this->_nota1 + this->_nota2)/2.00;
}