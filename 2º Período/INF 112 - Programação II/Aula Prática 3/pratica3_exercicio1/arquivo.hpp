#define TAMANHO 100

struct ListaVetorInteiros {
    // Dados
    int *_elementos;
    int _num_elementos_inseridos;

    ListaVetorInteiros();
    ~ListaVetorInteiros();
    void inserir_elemento(int elemento);
    void imprimir();
    void remover_primeiro();
    void remover_ultimo();
    void inverte();
};