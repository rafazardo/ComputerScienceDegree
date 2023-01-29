#include <iostream>
#include <stdio.h>
#include <pthread.h>

const int n = 7;
const int qntdThread = 3;
int *array = new int[n]; 

void *pthreadFnc(void *id) {

    int contador = n / qntdThread;

    long res = 0;

    for (int i = contador * (long)id; i < (contador * (long)id) + contador; i++) {
        if (i == n - 2 and n % 2 != 0) {
            res += array[n-1];
        }
        res += array[i];
    }

    pthread_exit((void *)res);
}

int main() {

    for (int i = 0; i < n; i++) {
        std::cin >> array[i];
    }

    pthread_t t[qntdThread];
    void *resultadoThread[qntdThread];
    int total = 0;

    for (int i = 0; i < qntdThread; i++) {
        pthread_create(&t[i], NULL, pthreadFnc, (void *)i);
    }

    for (int i = 0; i < qntdThread; i++) {
        pthread_join(t[i], &resultadoThread[i]);
    }

    for (int i = 0; i < qntdThread; i++) {
        total += (long)resultadoThread[i];
    }

    std::cout << "Valor total da soma: " << total << std::endl;
    // std::cout << "Nucleos: " << get_nprocs() << std::endl;

    pthread_exit(NULL);

    return 0;
}