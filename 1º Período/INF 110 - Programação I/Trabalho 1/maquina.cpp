#include <iostream>
using namespace std;

int main() {
    double ePrec_Prod,eVlr_Moed,eVlr_Tot,eVlr_Troc;
    bool ePara;

    ePara = false;
    eVlr_Tot = 0;

    //Insere o valor do produto
    cin >> ePrec_Prod;

    //Insere as moedas na máquina, e só para quando digitar o valor 0
    while (ePara != true) {
        cin >> eVlr_Moed;
        if (eVlr_Moed != 0) {
            eVlr_Tot += eVlr_Moed;
        }
        else {
            ePara = true;
        }
    }

    //Calcula o troco e notifica se o saldo é suficiente ou nao
    eVlr_Troc = eVlr_Tot - ePrec_Prod;
    if (eVlr_Troc >= 0) {
        cout << "Troco de " << eVlr_Troc << " centavos." <<endl;
    }
    else {
        cout << "Saldo insuficiente." <<endl;
    }

    return 0;
}
