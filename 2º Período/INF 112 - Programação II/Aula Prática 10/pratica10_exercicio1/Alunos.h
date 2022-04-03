#ifndef INF112_ALUNOS_H
#define INF112_ALUNOS_H

#include <iostream>
#include <string>

class Alunos {

private:
    int _matricula;
    std::string _nome;
    double _nota1;
    double _nota2;
    double _media;

public:
    Alunos(int addMatricula, std::string addNome, double addNota1, double addNota2);
    ~Alunos();

    int get_matricula();
    std::string get_nome();
    double get_nota1();
    double get_nota2();
    double get_media();

    void set_matricula(int addMatricula);
    void set_nome(std::string addNome);
    void set_nota1(double addNota1);
    void set_nota2(double addNota2);
    void set_media(double addMedia);      

    void calcular_media();  
};

#endif