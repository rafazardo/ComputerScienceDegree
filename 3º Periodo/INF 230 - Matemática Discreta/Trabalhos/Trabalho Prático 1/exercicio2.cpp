/*
INF 230 - Matematica Discreta 
- Software criado para resolucao do exercicio 2 do Trabalho Prático 1
- Criado por: Rafael Zardo
- Data: 09/07/2022
*/

#include <iostream>
#include <math.h>
using namespace std;

int encontraQuartaMaxima(int valor) { // Funcao que encontra a maior quarta possivel de um valor. Ex: 17, maior quarta possivel 2 elavado a 4, ou seja 2

    int contadorAux = 0;

    while(true) {
        if (pow(contadorAux,4) == valor) { // Se o resultado for igual ao valor retorna o resultado
            return contadorAux;
        }
        else if (pow(contadorAux+1,4) > valor) { // Se o resultado for maior que o valor, retorna o resultado anterior, que é uma quarta menor que valor.
            return contadorAux;
        }
        contadorAux++;
    }


}

void verificaQuarta (int valor) { // Funcao que verifica a equacao proposta no exercicio 2

    int valorQuartaMaxima = encontraQuartaMaxima(valor);

    // Sequencia de for para testar todos valores possiveis de a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r para verificar se a seguinte equacao é valida:
    // a4 + b4 + c4 + d4 + e4 + f4 + g4 + h4 + i4 + j4 + k4 + l4 + m4 + n4 + o4 + p4 + q4 + r4 = valor

    for (int a = 0; a <= valorQuartaMaxima; a++)
        for (int b = 0; b <= valorQuartaMaxima; b++)
            for (int c = 0; c <= valorQuartaMaxima; c++)
                for (int d = 0; d <= valorQuartaMaxima; d++)
                    for (int e = 0; e <= valorQuartaMaxima; e++)
                        for (int f = 0; f <= valorQuartaMaxima; f++)
                            for (int g = 0; g <= valorQuartaMaxima; g++)
                                for (int h = 0; h <= valorQuartaMaxima; h++)
                                    for (int i = 0; i <= valorQuartaMaxima; i++)
                                        for (int j = 0; j <= valorQuartaMaxima; j++)
                                            for (int k = 0; k <= valorQuartaMaxima; k++)
                                                for (int l = 0; l <= valorQuartaMaxima; l++)
                                                    for (int m = 0; m <= valorQuartaMaxima; m++)
                                                        for (int n = 0; n <= valorQuartaMaxima; n++)
                                                            for (int o = 0; o <= valorQuartaMaxima; o++)
                                                                for (int p = 0; p <= valorQuartaMaxima; p++)
                                                                    for (int q = 0; q <= valorQuartaMaxima; q++)
                                                                        for (int r = 0; r <= valorQuartaMaxima; r++) {
                                                                            if ((pow(a,4) + pow(b,4) + pow(c,4) + pow(d,4) + pow(e,4) + pow(f,4) + pow(g,4) + pow(h,4) + pow(i,4) + pow(j,4) + pow(k,4) + pow(l,4) + pow(m,4) + pow(n,4) + pow(o,4) + pow(p,4) + pow(q,4) + pow(r,4)) == valor) {
                                                                                cout << " Valido \n"; //Se passar por todos for e encontrar forma que valide a equacao, retorna valido
                                                                                return;
                                                                            }
                                                                        }

    cout << " Nao valido\n"; //Se passar por todos for e nao encontrar forma que valide a equacao, retorna nao valido
    return;
}

int main(void) {

    int inputInicial;

    cout << "Escolha as opcoes \n";
    cout << "[0] - Testar somente um valor se é valido \n";
    cout << "[1] - Testar uma sequencia de 1 a N valores \n";
    cin >> inputInicial;

    if (inputInicial == 0) {
        int valorTeste;

        cout << "Digite o valor que deseja testar: \n";
        cin >> valorTeste;
        cout << "[" << valorTeste << "] ";
        verificaQuarta(valorTeste);
    }
    else if(inputInicial == 1) {
        int valorMaximoTestes;

        cout << "Digite até qual valor maximo deseja verificar: \n";
        cin >> valorMaximoTestes;

        for (int k = 0; k <= valorMaximoTestes; k++) {
            cout << "[" << k << "] ";
            verificaQuarta(k);
        }         
    }
}