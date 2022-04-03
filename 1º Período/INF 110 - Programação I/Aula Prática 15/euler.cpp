#include <iomanip>
#include <iostream>
using namespace std;

long double fatorial(long double eFat) { //Calcula o fatorial de um número
    long double eFat_Total,eCntrl;

    eCntrl = 1;
    eFat_Total = 1;

    while (eCntrl <= eFat) {
        eFat_Total = eFat_Total*eCntrl;
        eCntrl++;
    }

    if (eFat == 0) {
        eFat_Total = 1;
    }

    return eFat_Total;
}


int main() {
    
    long double nEuler = 0;
    long double nQntdTerm,nCont;
    
    cin >> nQntdTerm;

    for (nCont = 0; nCont < nQntdTerm; nCont++) {
        nEuler += 1/(fatorial(nCont));   //Incrementa na váriavel euler o valor das parcelas de euler
    }
    
    cout << fixed << setprecision(4) << nEuler << endl; 
    return 0;
}