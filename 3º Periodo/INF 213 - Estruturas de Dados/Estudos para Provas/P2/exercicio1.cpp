#include <iostream>
#include "MyList2NewIterator.h"
#include "MyVec.h"

using namespace std;

//01) Considere uma lista que armazene, em cada nodo, um bit (0 ou 1) da representação binária de um número. 
//Por exemplo, a lista 0->0->0->->1->1 representa o número 3. 
//Considere a função-membro somaUm(), que irá fazer a soma de uma unidade ao número binário armazenado na lista. 
//Por exemplo, a lista deixará de armazenar 0->0->0->->1->1 e começará a armazenar 0->0->1->0->0.

//a) Há diferença (de complexidade), nesse caso, do uso de lista simplesmente encadeada para duplamente encadeada? Se sim, qual a melhor? Qual a complexidade?
// Sim ha diferenca, enquanto o pior caso da lista duplamente encadeada é O(N) (ter que somar 1 em todos elementos da lista), e o melhor caso pode ser O(1)

//b) Implemente a função (Caso a resposta anterior seja "sim", considere a melhor lista. Se não, escolha uma).

template<class T>
void MyList2<T>::somaUm() {

    Node<T> * curr = dataLast;
    int vaiUm = true;

    while (curr != NULL) {
        if (curr->data == 1 and vaiUm == true) { // Se o elemento é 1, e tem que somar, deixa ele como 0 e passa pro proximo com 1 ainda
            curr->data = 0;
            vaiUm = true;
            curr = curr->prev;
        }

        if (curr->data == 0 and vaiUm == true) { // Se o elemento é 0, e tem que somar, deixa ele como 0 e passa pro proximo com 0 
            curr->data = 1;
            vaiUm = false;
            curr = curr->prev;
        }

        if (vaiUm == false) { // Se vaiUm é 0 nao precisa fazer mais nada
            curr = curr->prev;
        }

        if (curr == dataFirst and vaiUm == true) {

            curr->data = 0;

            Node<T> * newElement = new Node<T>(0);

            newElement->next = dataFirst;
            newElement->next->prev = newElement;
            newElement->prev = NULL;
            dataFirst = newElement;
            dataSize++;

        }
    }
}

int main(  ) {

    MyList2<int> binario;

    int n,j;

    cin >> n;

    for (int k = 0; k < n; k++) {
        cin >> j;
        binario.push_back(j);
    }

    cout << binario;

    binario.somaUm();

    cout << binario;

}