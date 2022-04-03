#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main() {
    
    int nCont,y;
    int nSomaVet = 0;

    cin >> y;
    int nVetA[y];
    int nVetB[y];

    for (nCont = 0; nCont < y; nCont++) {
        cin >> nVetA[nCont];
    }

    for (nCont = 0; nCont < y; nCont++) {
        cin >> nVetB[nCont];
    }

    for (nCont = 0; nCont < y; nCont++) {
        nSomaVet += nVetA[nCont] * nVetB[nCont];
    }

    cout << nSomaVet << endl;

    return 0;
}