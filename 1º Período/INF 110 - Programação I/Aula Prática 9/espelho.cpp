#include <iomanip>
#include <iostream>
#include <math.h>
using namespace std;

int espelhar(int);

int main() {
    
    double nA,nB;

    cin >> nA >> nB;
    while (nA != 0 || nB != 0) {
        if (espelhar(nA) == nB) {
            cout << "espelho" << endl;
        }
        else {
            cout << "nao espelho" << endl;
        }
        cin >> nA >> nB;
    }
    return 0;
}

int espelhar(int n) {
    
    int nEsp[4];
    int nCont,nSup;
    int nNum = 0;
    int nDig = 0;

    for (nCont = 0; nCont <= 3; nCont++) {
        nSup = n % 10;
        if (nCont == 3) {
            nSup = n;
        }
        nEsp[nCont] = nSup;
        n = n / 10;
    }

    for (nCont = 1000; nCont >= 1; nCont = nCont / 10) {
        nNum += nEsp[nDig]*nCont;
        nDig = nDig + 1;
    }

    return nNum;
}



