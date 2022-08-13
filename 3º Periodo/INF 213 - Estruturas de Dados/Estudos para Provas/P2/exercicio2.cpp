#include <iostream>
#include "MyList2.h"
#include "MyVec.h"

//02) Considere uma lista duplamente encadeada que armazena os valor 1->1 e a função fibonacci, 
//que preeenche a lista com valores até o n-ésimo termo da sequencia de fibonacci.  

//a) Implemente a função

// Formula: Fn = Fn-1 + Fn-2

template<class T>
void MyList2<T>::fibonacci(const int n) {

    while (dataLast->data + dataLast->prev->data <= n) {

        Node<T> * Fn = new Node<T>(dataLast->data + dataLast->prev->data);

        // Push Back
        dataLast->next = Fn;
        dataLast->next->prev = dataLast;
        dataLast = Fn;
    }

}

int main() {

    MyList2<int> fibo;
    int n;

    fibo.push_back(1);
    fibo.push_back(1);
    fibo.fibonacci(100);

    std::cout << fibo;

}


//b) A complexidade com uma lista simplesmente encadeada seria a mesma?
// Nao, uma vez que precisamos andar para tras na lista simplesmente cadeada pelos elementos, e isso numa lista simplesmente encadeada é muito caro.