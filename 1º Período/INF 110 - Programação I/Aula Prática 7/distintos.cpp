#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main() {
 
    int nCont,nQtnd,nSup,nCont2;
    int nSoma = 0;

    cin >> nQtnd;
    int nList[nQtnd];
    nList[nQtnd] = 1000000000;

    for (nCont = 0; nCont < nQtnd; nCont++) {
        cin >> nList[nCont];
    }

    for (nCont = 0; nCont < nQtnd; nCont++) {
        for (nCont2 = nCont + 1; nCont2 < nQtnd;nCont2++) {
            if (nList[nCont] >= nList[nCont2]) {
                nSup = nList[nCont2];
                nList[nCont2] = nList[nCont];
                nList[nCont] = nSup;
            }
        }
    }

    for (nCont = 0; nCont < nQtnd; nCont++) {
        if (nList[nCont] == nList[nCont+1]) {
            nSoma++;
        }
    }

    cout << nQtnd - nSoma << endl;
    return 0;
}