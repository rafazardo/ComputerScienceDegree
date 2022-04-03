#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main() {
    
    long double nPi1 = 0;
    long double nPi2 = 1;
    long double nPi3 = 0;
    long double nPi4 = 1;
    long double nPi5 = 0;
    long double nSup3 = 0;
    long double nSup4 = 1;
    long double nCont,nQntTerm,nQntTerm2;
    int nSup;
    char cSelec;

    //Insere as instruções iniciais para o usuário, ensinando como usar o programa.
    cout << "Quantos termos deseja calcular: ";
    cin >> nQntTerm;
    cout << endl;
    cout << "Lista de series infinitas disponiveis:\n";
    cout << "SERIE  - CODIGO " << endl;
    cout << "Leibniz    L\n";
    cout << "Wallis     W\n";
    cout << "Euler      E\n";
    cout << "Viete      V\n";
    cout << "Brounck.   B\n";
    cout << "Todas      T\n";
    cout << "Digite o codigo da(s) serie(s) que deseja visualizar: ";
    cin >> cSelec;
    cout << endl;
    cout << "Processando informacoes...\n";
    cout << endl;
    cout << "=====================================\n";
    cout << fixed << setprecision(0) << "Series Infinitas para " << nQntTerm << " Termos:" << endl;

    //Calcula a série de Leibniz
    if (cSelec == 'L' || cSelec == 'l' || cSelec == 'T' || cSelec == 't') {
        for (nCont = 0; nCont < nQntTerm; nCont++) {
            nPi1 += 4*(pow(-1,nCont) / ((2 * nCont) + 1)); //Fórmula de Leibniz
        }
        cout << fixed << setprecision(80) << "Leibniz = " << nPi1 << endl;
    }

    //Calcula a série de Wallis
    if (cSelec == 'W' || cSelec == 'w' || cSelec == 'T' || cSelec == 't') {
        //Adptador de termos para a série de Wallis
        nSup = nQntTerm;
        if (nSup%2 == 0) {
            //Calcula a série de Wallis para quantidade de termos pares
            nQntTerm2 = (nQntTerm / 2);
            for (nCont = 1; nCont <= nQntTerm2; nCont++) {
                nPi2 *= (((2*nCont)/(2*nCont-1))*((2*nCont)/(2*nCont+1))); //Inicio da Fórmula de Wallis
            }
            nPi2 *= 2; //Fim da Fórmula de Wallis
        }
        else {
            //Calcula a série de Wallis para quantidade de termos impares
            nQntTerm2 = (nQntTerm / 2) - 0.5;
            for (nCont = 1; nCont <= nQntTerm2; nCont++) {
                nPi2 *= (((2*nCont)/(2*nCont-1))*((2*nCont)/(2*nCont+1))); //Fórmula de Wallis
            } 
            nPi2 *= (2*(nQntTerm2+1))/((2*(nQntTerm2+1))-1); //Incrementa o ultimo termo da fórmula de Wallis (Termo impar)
            nPi2 *= 2; //Fim da Fórmula de Wallis
        } 
        cout << fixed << setprecision(80) << "Wallis  = " << nPi2 << endl; 
    }

    //Calcula a série de Euler
    if (cSelec == 'E' || cSelec == 'e' || cSelec == 'T' || cSelec == 't') {
        for (nCont = 1; nCont <= nQntTerm; nCont++) {
            nPi3 += 1/(pow(nCont,2.0)); //Inicio da Fórmula de Euler
        }
        nPi3 = sqrt(nPi3*6); //Fim da Fórmula de Euler
        cout << fixed << setprecision(80) << "Euler   = " << nPi3 << endl;
    }

    //Calcula a série de Viète
    if (cSelec == 'V' || cSelec == 'v' || cSelec == 'T' || cSelec == 't') {
        for (nCont = 1; nCont <= nQntTerm; nCont++) {
            nSup3 = sqrt(2+nSup3); //Calcula o numerador da sequencia de Vièti.
            nPi4 *= nSup3/2; //Adiciona o denominador na linha anterior.
        }
        nPi4 = 2/nPi4; //Fim da Fórmula de Viète
        cout << fixed << setprecision(80) << "Viete   = " << nPi4 << endl;
    }

    //Calcula série de Brouncker
    if (cSelec == 'B' || cSelec == 'b' || cSelec == 'T' || cSelec == 't') {
        //Deescobre o ultimo valor da divisão de Brouncker
        for (nCont = 1; nCont < (nQntTerm - 2); nCont++) {
            nSup4 = nSup4 + 2;
        }
        //Prepara o ultimo termo da sequencia, caso a sequencia tenha mais de 1 termo
        if (nQntTerm > 1) {
            nPi5 = (pow(nSup4,2.0) / 2);
        }
        for (nCont = nSup4 - 2; nCont >= 1; nCont = nCont - 2) {
            nPi5 = (pow(nCont,2.0)) / (nPi5 + 2); //Inicio da Fórmula de Brouncker
        }
        nPi5 = 4/(nPi5 + 1); //Fim da Fórmula de Brouncker
        cout << fixed << setprecision(80) << "Brounck.= " << nPi5 << endl;
    }

    cout << "=====================================\n";

    return 0;
}