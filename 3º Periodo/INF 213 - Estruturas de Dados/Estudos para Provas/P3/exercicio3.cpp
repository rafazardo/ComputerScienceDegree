#include <iostream>

#include "MySet.h"

using namespace std;

// 03) Implemente uma função getMediana() que retorna a mediana dos valores de uma ABP. 

// a) Considere que NÃO existem iteradores e esta é uma função-membro.

template<class T>
int MySet<T>::getMediana() {

    Node<T> * ptr = root;
    int media = 0;
    int mediaSup = (size()-1)/2;
    int cont = 0;

    while(ptr->left) ptr = ptr->left; // pega o menor elemento da lista

    while (ptr != NULL) {

        if (size()%2 == 0) { // se for par, precisa pegar o posterior
            if (cont == mediaSup or cont == mediaSup + 1) { // pega o do meio e o posterior
                media += ptr->elem;
                if (cont == mediaSup + 1) {
                    return media/2; // se pegou o posterior pode retornar
                }
            }
        }
        else { // se e impar so retornar
            if (cont == mediaSup) {
                media += ptr->elem;
                return media;
            }            
        }

        cont++;

        // operador de incremento
        if (ptr->right != NULL) {

            ptr = ptr->right;

            while (ptr->left != NULL) {
                ptr = ptr->left;
            }
        }
        else {
            while (ptr->parent != NULL && ptr->parent->right == ptr) {
                ptr = ptr->parent;
            }
            ptr = ptr->parent;
        }
    }
}
// b) Considere que existem iteradores e esta é uma função não-membro.

int getMediana( MySet<int> &set) { 

    int media = (set.size()-1)/2;
    int cont = 0;
    int mediaSup;

    MySet<int>::iterator it = set.begin();

    while (it != set.end()) {

        if (set.size()%2 == 0) {
            if (cont == media)  {
                mediaSup = *it;
                it++;
                mediaSup += *it;
                return mediaSup/2;
            }
        }
        else {
            if (cont == media)  {
                mediaSup = *it;
                return mediaSup;
            }
        }
        cont++;
        it++;
    }

}

int main() {

    MySet<int> tree;

    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(10);
    tree.insert(5);

    cout << tree.getMediana();
    cout << getMediana(tree);


    return 0;
}
