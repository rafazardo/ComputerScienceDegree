#include <iostream>
using namespace std;

int main () {
    int nLarg, nAltu, nComp, nVolu;

    //Coleta os valores da caixa
    cout << "Digite a largura: ";
    cin >> nLarg;
    cout << "Digite a altura: ";
    cin >> nAltu;
    cout << "Digite o comprimento: ";
    cin >> nComp;

    //Efetua os cálculos
    nVolu = nLarg*nAltu*nComp;

    //Aprenseta o resultado
    cout << "O valor do volume e igual a: " << nVolu << endl;
    return 0;
}