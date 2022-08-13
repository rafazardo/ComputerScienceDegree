#include <iostream>
// #include "MyList2.h"
#include "MyVec.h"
#include "MyList.h"

using namespace std;

// 05) Considere n listas encadeadas que guardam, cada uma, uma certa quantidade de números (representadas por um MyVec de MyList). 
// Implemente uma função não-membro intersecao que retorna uma MyList definida pela interseção de todas as listas passadas como argumento.

// A ideia e voce pegar a primeira lista, e verificar se cada elemento dela esta em todas as outras 
MyList<int> intersecao(MyVec< MyList<int> > p) {

    MyList<int> lista;

    MyList<int>::iterator it = p[0].begin(); /// Aponta para o primeiro elemento da primeira lista

    while (it != p[0].end()) { // Anda por todos elementos da primeira lista

        bool achou = false;

        for (int i = 1; i < p.size(); i++) { // Anda por todas as listas

            MyList<int>::iterator it2 = p[i].begin(); // Aponta para o primeiro elemento da lista
            
            achou = false;

            while (it2 != p[i].end()) { // Anda por todos elementos da lista em questao
                if (it->data == it2->data) { // Se achou, pode parar e passar pra proxima lista
                    achou =  true;
                    break;
                }

                it2 = it2->next;
            }

            if (achou == false) { // Se passou por todo uma lista, e nao achou o elemento, pode parar de procurar esse elemento
                break;
            }
        }

        if (achou == true) { // Se passou por todas listas, e continua  true, pode inserir o elemento
            lista.push_back(it->data);
        }

        it = it->next;
    }

    return lista;

}

// =========================================
// =========================================
// =========================================

int main() {

    MyVec<MyList<int> > listona;

    MyList<int> t;

    t.push_back(4);
    t.push_back(7);
    t.push_back(8);
    t.push_back(1);

    MyList<int> k;

    k.push_back(2);
    k.push_back(7);
    k.push_back(6);
    k.push_back(8);    


    listona.push_back(t);
    listona.push_back(k);

    cout << intersecao(listona);

    return 0;
}