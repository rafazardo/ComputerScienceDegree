#include <iostream>

#include "MySet.h"

using namespace std;

//01) Suponha a implementação de MySet que vimos.

//a) considere que NÃO existem iteradores. Crie uma função-membro sumLowerThan que soma todos os valores menores que determinado
// número (elemento da ABP ou não) em uma ABP. Você podedrá criar uma, e somente uma, função auxiliar apenas se for usar recursividade.

template <class T>
int MySet<T>::sumLowerThan(int n) {
    int k = 0;
    sumLowerThan(root, n, &k); // K deve ser passado por referencia, para ser modificado na funcao

    return k;
}

template <class T>
void MySet<T>::sumLowerThan(Node<T> * node, int n, int *k) { // A ideia e usar o in-order, so que em vez de imprimir, faz as operacoes

    if (node == NULL) {
        return;
    }

    if (node->elem >= n) {
        return;
    }

    sumLowerThan(node->left, n, k);
    *k += node->elem;
    sumLowerThan(node->right, n, k);
}

// b) Considere, agora, que existem iteradores. Crie uma função não-membro sumLowerThan que soma todos os valores menores 
// que determinado número (elemento da ABP ou não) em uma ABP. Você não poderá criar funções auxiliares.

int sumLowerThan(MySet<int> tree, int chave) {

    MySet<int>::iterator it = tree.begin();
    
    int soma = 0;

    while (it != tree.end()) { //Sempre pensar se tem um it com NULL fazendo alguma operacao
        if (*it <= chave) {
            soma += *it;
        }
        else {
            break;
        }
        it++;
    }

    return soma;

}

int main() {

    MySet<int> tree;

    tree.insert(1);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(9);

    cout << tree.sumLowerThan(10);
    cout << sumLowerThan(tree, 10);

    return 0;
}
