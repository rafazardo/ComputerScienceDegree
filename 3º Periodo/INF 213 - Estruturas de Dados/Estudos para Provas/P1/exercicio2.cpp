#include <string>
#include <iostream>
using namespace std;

//Exercicio 1

//Suponha que tenha um array v e um valor k. Como descobrir se existem dois elementos de v cuja soma seja k.
//Exemplo: v=[-5,1,-40,20,6,8,7] e k = 15

int particiona(int array[], int begin, int end, int pivo) {

    int elem = array[pivo];
    int antes = pivo;

    swap(array[pivo], array[end - 1]);

    for (int i = begin; i < end - 1; i++) {
        if (array[i] < elem) {
            swap(array[i],array[antes]);
            antes++;
        }
    }

    swap(array[antes], array[end - 1]);

    return antes;
}

void quickSort(int array[], int begin, int end) {

    if (begin == end) {
        return;
    }

    int meio = particiona(array, begin, end, begin);

    quickSort(array, begin, meio);
    quickSort(array, meio + 1, end);
}

void quickSort(int array[], int size) {
    quickSort(array,0,size);
}

int main() {

    int array[7] = {-5,1,-40,20,6,8,7};
    int chave = 15;

    quickSort(array, 7);

    bool existem = false;
    int esquerda = 0;
    int direita = 7 - 1;

    while (esquerda < direita and array[esquerda] + array[direita] != chave) {

        if (array[esquerda] + array[direita] > chave) { // Se for maior, diminuimos o vetor pra esquerda
            direita = direita - 1;
        }
        else {
            esquerda = esquerda + 1;
        }
    }

    if (esquerda < direita) {
        existem = true;
    }

    if (existem == true) {
        cout << "Existem\n";
    }
    else {
        cout << "Nao Existem\n";
    }
}

// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-