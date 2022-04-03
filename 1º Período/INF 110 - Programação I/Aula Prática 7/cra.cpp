#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main() {
 
    int nCont,nQntd;
    double nSomaCre = 0;
    double nSomaCreNot = 0;

    cin >> nQntd;
    double nNotas[nQntd];
    double nCred[nQntd];

    for (nCont = 0; nCont < nQntd; nCont++) {
        cin >> nNotas[nCont];
    }

    for (nCont = 0; nCont < nQntd; nCont++) {
        cin >> nCred[nCont];
    }

    for (nCont = 0; nCont < nQntd; nCont++) {
        nSomaCreNot += nCred[nCont]*nNotas[nCont];
        nSomaCre += nCred[nCont];
    }

    cout << fixed << setprecision(1) << (nSomaCreNot / nSomaCre) << endl;

    return 0;
}