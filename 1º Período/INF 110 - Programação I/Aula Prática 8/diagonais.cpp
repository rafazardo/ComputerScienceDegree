#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    
    int nQntd,nCont,nCont2;

    cin >> nQntd;
    int nMat[nQntd][nQntd];

    for (nCont = 0; nCont < nQntd; nCont++) {
        for (nCont2 = 0; nCont2 < nQntd; nCont2++) {
            cin >> nMat[nCont][nCont2];
        }   
    }

    //Diagonal principal
    for (nCont = 0; nCont < nQntd; nCont++) {
        for (nCont2 = 0; nCont2 < nQntd; nCont2++) {
            if (nCont == nCont2) {
                cout << nMat[nCont][nCont2] << endl;
            }
        }   
    }

    cout << endl;

    nCont2 = nQntd - 1;
    for (nCont = 0; nCont < nQntd; nCont++) {
        cout << nMat[nCont][nCont2] << endl;
        nCont2--;
    }
    return 0;
}