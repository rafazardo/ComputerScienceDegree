#ifndef INF112_POSICOESVETOR_H
#define INF112_POSICOESVETOR_H

#include <iostream>

class PosicoesVetor {

private:
    int _tamanhoVetor;
    int *_vetor;

public:
    PosicoesVetor(int addtamanhoVetor);
    ~PosicoesVetor();

    int get_tamanhoVetor();
    void get_vetor();

    void set_tamanhoVetor(int addtamanhoVetor);
    void set_vetor(int addValorVetor, int addPosicao);

    void preencherValores();
};

#endif