#include <iostream>
using namespace std;

int main() {
    int nSalBas, nVlrHor, nHorTot, nSalTot;

    //Coleta os dados
    cout << "Digite o seu salário base: ";
    cin >> nSalBas;
    cout << "Digite o valor da sua hora de trabalho: ";
    cin >> nVlrHor;
    cout << "Digite o total de horas extras trabalhadas: ";
    cin >> nHorTot;

    //Executa os calculos 
    nSalTot = nSalBas + (nVlrHor*nHorTot);

    //Apresenta os dados
    cout << "O valor do seu salaário total e: " << nSalTot << endl;
    return 0;
}