/*
INF 230 - Matematica Discreta 
- Software criado para resolucao do exercicio 4 do Trabalho Prático 1
- Criado por: Rafael Zardo
- Data: 09/07/2022
*/

#include <iostream>
#include <math.h>
using namespace std;

void geraFibonacci() {
    long long int numAnterior = 1, numSucessor = 1, auxNumAnterior;
    int qntdNumFibonacci = 1;  

    cout << "Numeros de Fibonacci: \n"; 

    cout << "[" << qntdNumFibonacci++ << "]" << numAnterior << endl;
    cout << "[" << qntdNumFibonacci++ << "]" << numSucessor << endl;

    while (true) {
        auxNumAnterior = numSucessor; // Armazena o sucessor, pois futuramente ele sera o antecessor
        numSucessor = numAnterior + numSucessor; // Gera o proximo termo da sequencia com a soma dos dois anteriores
        numAnterior = auxNumAnterior; // Garente que o anterior sera o antigo sucessor

        if (numSucessor < 0) { // Quando temos valores negativos, o computador utilizando uma variavel long long int nao consegue mais computar o numero da sequencia de Fibonacci 
            break;
        }

        cout << "[" << qntdNumFibonacci++ << "]" << numSucessor << endl;
    }

    cout << "Quantidade de numeros de Fibonacci gerados: " << qntdNumFibonacci-1 << endl;
    cout << endl;
}

void geraFibonacciDivisor(int numDivisor) {
    long long int numAnterior = 1, numSucessor = 1, auxNumAnterior;
    int qntdNumFibonacci = 1;

    cout << "Numeros de Fibonacci divisiveis por " << numDivisor << ": " << endl;

    if (numAnterior % numDivisor == 0) { // Verifica se o primeiro termo da sequencia é divisivel pelo divisor proposto
        cout << "[" << qntdNumFibonacci++ << "]" << numAnterior <<  endl;
    }

    if (numSucessor % numDivisor == 0) { // Verifica se o segundo termo da sequencia é divisivel pelo divisor proposto
        cout << "[" << qntdNumFibonacci++ << "]" << numSucessor << endl;
    }    

    while (true) {
        auxNumAnterior = numSucessor; // Armazena o sucessor, pois futuramente ele sera o antecessor
        numSucessor = numAnterior + numSucessor; // Gera o proximo termo da sequencia com a soma dos dois anteriores
        numAnterior = auxNumAnterior; // Garente que o anterior sera o antigo sucessor

        if (numSucessor < 0) { // Quando temos valores negativos, o computador utilizando uma variavel long long int nao consegue mais computar o numero da sequencia de Fibonacci 
            break;
        }

        if (numSucessor % numDivisor == 0) { // Se o numero for divisel pelo divisor proposto, sera impresso esse valor no terminal
            cout << "[" << qntdNumFibonacci++ << "]" << numSucessor << endl;
        }
    }
    cout << "Quantidade de numeros de Fibonacci divisiveis por " << numDivisor << " gerados: " << qntdNumFibonacci-1 << endl;
}

int main(void) {
    geraFibonacci(); // Gera a sequencia de fibonacci até o tamanho de uma variavel long long int
    geraFibonacciDivisor(3); // Gera a sequencia de fibonacci até o tamanho de uma variavel long long int, porém só é exibido valores divisiveis por um inteiro de entrada
}