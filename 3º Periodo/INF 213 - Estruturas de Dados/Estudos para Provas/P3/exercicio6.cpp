//05) Exercicio Prova Antiga
#include <iostream>

#include "MySet.h"

using namespace std;

template <class T>
int MySet<T>::altura(Node<T> * raiz) {

    if (raiz == NULL) {
        return -1; // Precisa do menos 1 para tratar arvores com 1 elemento
    }

    int direita = altura(raiz->right); 
    int esquerda = altura(raiz->left);

    if (direita > esquerda) { // Aquele caminho que tiver maior sera o preferivel
        return direita + 1;
    }
    else {
        return esquerda + 1;
    }

}


template <class T>
void MySet<T>::preencheFB(Node<T> * raiz) {

    int esquerda;
    int direita;

    if (raiz == NULL) {
        return ;
    }

    preencheFB(raiz->left);

    if (raiz->left == NULL) { // se o filho da direita for null, ele vale -1
        esquerda = -1;
    }
    else {
        esquerda = altura(raiz->left); // se nao vale sua altura
    }

    if (raiz->right == NULL) {
        direita = -1;
    }
    else {
        direita = altura(raiz->right);
    }

    raiz->fb = direita - esquerda;

    preencheFB(raiz->right);

}

template <class T>
void MySet<T>::preencheFBA() {
    preencheFB(root);
}


int main() {


    MySet<int> tree;

    tree.insert(10);
    tree.insert(5);
    tree.insert(3);
    tree.insert(11);
    tree.insert(12);

    tree.preencheFBA();
    tree.imprimeDFS_in();



    return 0;
}
