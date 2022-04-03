#include <cstring>

struct notas {

    double *_notas;
    int _qtde_disciplinas;
    int _matricula;
    double media_notas;
    int _num_elementos_inseridos;

    
    notas(int nQntdDiscp,int nMatricula);

    ~notas();

    void adicionarNota(double nNotas);

    void calcularMediaAluno();

    void imprimeInformacoesAluno();

};