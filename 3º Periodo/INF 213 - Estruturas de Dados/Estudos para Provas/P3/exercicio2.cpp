#include <iostream>

#include "MySet.h"

using namespace std;

// 02) Dada a implementação usual de uma ABP, implemente uma função que retorne quantos valores que estão 
// faltando no intervalo [menor elemento, maior elemento]. Por exemplo,
// Árvore:
//				5
//		2				8 	
//	1		3		6		11 

// retorno: 4 (explicação: 4, 7, 9 e 10).	
// você não pode usar nenhum tipo de estrutura de dados para armazenar estes valores.

// a) Considere que NÃO existem iteradores e esta é uma função-membro.

// A ideia e pegar o menor elemento, e andar com ele junto com um percurso in-order
template<class T>
int MySet<T>::totalMissing() {
    int k = 0;
    int l = 0;

    Node<T> * curr = root;

    while (curr != NULL) { // leva ate o primeiro elemeto (vulgo, menor)
        k = curr->elem;
        curr = curr->left;
    }

    totalMissing(root, &k, &l);

    return l;
}

template<class T>
void MySet<T>::totalMissing(Node<T> *nodo, int *k, int *l) { // Fazemos o percurso in-order

    if (nodo == NULL) {
        return;
    }

    totalMissing(nodo->left,k,l); 

    if (*k != nodo->elem) { // Como o in-order deixa os elementos em ordem, o proximo elemento for diferente do que deveria ser, incrementamos mais 1
        *l += 1;
    }

    *k += 1; // pega o proximo elemento que deveria ser
    totalMissing(nodo->right,k,l);
}

//b) Considere que existem iteradores e esta é uma função não-membro.

int totalMissing(MySet<int> &set) {

    MySet<int>::iterator it = set.begin();
    int k = *it;
    int soma = 0;

    while (it != set.end()) {
        if (*it != k) {
            soma++;
        }
        it++;
        k++;
    }

    return soma;
}

int main() {


    MySet<int> tree;

    tree.insert(5);
    tree.insert(2);
    tree.insert(8);
    tree.insert(1);
    tree.insert(3);
    tree.insert(6);
    tree.insert(11);

    cout << tree.totalMissing();
    cout << totalMissing(tree);

    return 0;
}
