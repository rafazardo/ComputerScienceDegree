#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main() {
    
    int nCont,nVetor,nMaior;
    int nMaiorSoma = 0;

    cin >> nVetor;
    double nList[nVetor];

    for (nCont = 0; nCont < nVetor; nCont++) {
        cin >> nList[nCont];
    }
    cin >> nMaior;

    for (nCont = 0; nCont < nVetor; nCont++) {
        if (nList[nCont] >= nMaior) {
            nMaiorSoma++;
        }
    }

    cout << nMaiorSoma << endl;

    return 0;
}