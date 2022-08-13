#include "MyList.h"
#include "MyStack.h"
#include "MyPriorityQueue.h"

#include <iostream>
using namespace std;

//03) Considere uma lista simplesmente encadeada que guarda um quantidade n de números. 
//Por exemplo 3->5->2->8->9->10->1. Implemente uma função para ordenar esta lista em complexidade máxima de O(n). 
//Para isso, você apenas poderá usar (além de variáveis) uma fila de prioridade e uma pilha. Você poderá criar funções auxiliares.

// A ideia, e que consigo tirar os elementos de ordem descrente da Fila de Prioridade
// Em seguida, e so passar inserindo eles para pilha
// Quando a pilha for passar para lista, ele estara ordenado, uma vez que a pilha inverte o que foi inserido
template<class T>
void MyList<T>::ordenaLista() {

    Node<T> * curr = dataFirst;
    MyPriorityQueue<T> fila;
    MyStack<T> pilha;

    while (curr != NULL) {
        fila.push(curr->data);
        curr = curr->next;
    } 

    while (fila.size() != 0 ) {
        pilha.push(fila.top());
        fila.pop();
    }
    

    clear();

    while (pilha.size() != 0) {
        push_back(pilha.top());
        pilha.pop();
    }
}

// =========================================
// =========================================
// =========================================


int main() {

    MyList<int> fila;

    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        fila.push_back(k);
    }

    fila.ordenaLista();

    cout << fila;

}