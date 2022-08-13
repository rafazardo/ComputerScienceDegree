/*
INF 230 - Matematica Discreta 
- Software criado para resolucao do exercicio 6 do Trabalho Prático 1
- Criado por: Rafael Zardo
- Data: 09/07/2022
*/

#include <iostream>
#include <math.h>
using namespace std;

bool verificarPrimo(long long int valor) { // Verifica se um numero é primo ou nao
    int qntdDivisores = 0;

    if (valor == 0 || valor == 1) { // 0 e 1 nao sao numeros primos
        return false;
    }

    for (int contadoAux = 2; contadoAux <= sqrt(valor); contadoAux++) { // Verifica se o numero e primo verificando ate a raiz do numero
        if(valor % contadoAux == 0) {
            qntdDivisores++; // Quantas vezes o numero e divisivel
        }
    }

    if(qntdDivisores == 0) { // Se nao for divisivel nenhuma vez, ele é primo
        return true;
    }
    else {
        return false;
    }
}

long long int encontraMaiorPrimoQuadrado(long long int valor) { // Encontra o maior primo ao quadrado possivel menor que o valor
    int contadorAux = 0;
    int ultimoPrimo;

    while (true) {
        if (verificarPrimo(contadorAux)) {
            if (pow(contadorAux,2) == valor) { // Se o primo ao quadrado for igual o valor, retorna o valor do primo
                return contadorAux;
            }
            else if (pow(contadorAux,2) > valor) { 
                return ultimoPrimo; // Caso o primo atual for maior que o valor, retorna o ultimo primo
            }            
            ultimoPrimo = contadorAux; // Guarda o ultimo primo salvo
        }
        contadorAux++;
    }
    
}

long long int calculaCombinacao(long long int n, long long int r) { // Calcula a combinacao utilizando o triangulo de pascal
    long long int trianguloPascal[1001][1001] = {0}; // Monta o triangulo de pascal para valores maiores que n

    trianguloPascal[0][0] = 1;
    for (int i = 1; i < 1001; i++) {
        trianguloPascal[i][0] = 1;  
        for (int j = 1; j < i + 1; j++) {
            trianguloPascal[i][j] = (trianguloPascal[i - 1][j - 1] + trianguloPascal[i - 1][j]); // Valor do elemento no triangulo
        }
    }

    return trianguloPascal[n][r]; // Retorna o valor do triangulo de pascal localizado nas posicoes da combinacao
}
 
bool verificaImpar(long long int valor) { // Verifica se o numero é impar
    if (valor%2 != 0) { // Todo numero nao divisivel por dois é impar
        return true;
    }
    else {
        return false;
    }
}

void verificaN(int n) { // Verifica o N
    long long int valorCombiancao = calculaCombinacao(n,n/2);
    long long int maiorPrimoQuadrado = encontraMaiorPrimoQuadrado(valorCombiancao);

    for (int j = 1; j <= maiorPrimoQuadrado; j++) {
        if (verificarPrimo(j)) {
            if (valorCombiancao % (j*j) == 0) {
                cout << "[N = " << n << "]" << " Invalido \n"; // Se a combinacao for divisivel por um primo qualquer ao quadrada ela é invalida
                return;
            }
        }
    }
    cout << "[N = " << n << "]" << " Valido \n"; // Se a combinacao nao for divisivel por um primo qualquer ao quadrada ela é valida.
    return;
}

int main(void) {
    for (int n = 0; n <= 200; n++) {
        if (verificaImpar(n) == true) {
            verificaN(n);
        }
    }
    
}