#include "MyList.h"
#include "MyStack.h"
#include "MyPriorityQueue.h"

// 5) Considere uma lista simplesmente encadeada que representa um número não negativo grande (em base decimal).
// Nessa lista, cada nodo contém um dos dígitos do número (valendo entre 0 e 9). 
// Por exemplo, o número 12345 seria representado pela lista 1->2->3->4->5, onde 1 é o primeiro elemento e 5 o último.

// onsidere que a lista é armazenada de forma “simples” e fora de uma classe (ou seja, você tem apenas uma classe Nodo
// e a lista é representada como um ponteiro para o primeiro nodo -- não há qualquer função para lhe ajudar a manipular 
// a estrutura de dados). O ponteiro next do último elemento aponta para NULL.

// Suponha que a lista esteja implementada usando a seguinte classe para representar os nodos (por simplicidade, tudo é público):

class Nodo {
	public: //para simplificar, tudo e’ publico…
	int digito;
	Nodo *next;
};

// Implemente a função imprimeReverso que, dado um número inteiro positivo N (representado por um ponteiro L) descrito 
// no formato acima, imprime N de forma reversa na tela. Por exemplo, se L aponta para o primeiro nodo da lista 1->2->3->4, 
// imprimeReverso(L) deveria imprimir 4321 na tela. 

// Sua função NÃO deverá ser recursiva. O aluno poderá, se necessário, utilizar as estruturas de dados MyQueue, 
// MyStack ou MyPriorityQueue para auxiliar na implementação (nenhuma outra estrutura poderá ser utilizada, 
// nem mesmo arrays simples). A complexidade de tempo máxima da sua função deverá ser O(D), onde D é o número de dígitos do número. 

void imprimeReverso(Nodo *L) {
    Nodo *curr = L;
    MyStack<int> pilha;

    while (curr != NULL) { // Passa o elemento de cada nodo para pilha 
        pilha.push(curr->digito);
        curr = curr->next;
    }

    while (pilha.size() != 0) { // Limpa a pilha, imprimindo inverso
        cout << pilha.top();
        pilha.pop();
    }
}

// =========================================
// =========================================
// =========================================

int main() {

    Nodo a,b,c,d,e;
    a.digito = 1;
    b.digito = 2;
    c.digito = 3;
    d.digito = 4;
    e.digito = 5;

    a.next = &b;
    a.next->next = &c;
    a.next->next->next = NULL;

    imprimeReverso(&a);

}