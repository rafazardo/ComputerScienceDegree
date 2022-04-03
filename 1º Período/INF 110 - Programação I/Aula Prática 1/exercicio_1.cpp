#include <iostream>
using namespace std;

int main() {
    int entrevista, curriculo, prova; // Notas do candidato
    int total;                         // Total de pontos
    int media;                        //Média de pontos

    //Leitura dos dados
    cout << "Escreva a nota da entrevista: ";
    cin >> entrevista;
    cout << "Escreva a nota do curriculo: ";
    cin >> curriculo;
    cout << "Escreva a nota da prova: ";
    cin >> prova;

    //Processamento dos dados
    total = entrevista + curriculo + prova;
    media = total / 3;

    //Impressão do resultado
    cout << "Nota final do candidato: " << total << endl;
    cout << "Media da nota final do candidato: " << media << endl;
    return 0;
}