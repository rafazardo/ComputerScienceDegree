#ifndef INF112_TURMA_H
#define INF112_TURMA_H

#include <iomanip>
#include <iostream>
#include <string>

class Turma {
private:
    std::string _codigo;
    int _ano;
    
public:
    Turma(std::string addCodigo, int addAno);
    std::string get_codigo();
    int get_ano();
    void set_codigo (std::string setCodigo);
    void set_ano (int setAno);
};

#endif