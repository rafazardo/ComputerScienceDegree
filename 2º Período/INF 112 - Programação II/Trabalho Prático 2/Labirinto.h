#ifndef INF112_LABIRINTO_H
#define INF112_LABIRINTO_H

class Labirinto {

private:
    int **_maze;
    int _ordem;

public:
    Labirinto(int n); //n = Ordem da Matriz
    ~Labirinto();

    int get_ordem();

    void set_ordem(int addOrdem);

    void leMatriz(Labirinto &Matriz);
    void imprimeLabirinto(Labirinto &labirintoMatriz);
    bool verificaSaidaLabirinto(int posicaoI, int posicaoJ);
    bool validaPosicao(int posicaoI, int posicaoJ);

};

#endif