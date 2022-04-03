#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    
    int nCont,nCont2,nQntLin,nQntCol,nEnc;
    int nSoma;

    cin >> nQntLin >> nQntCol;
    int nMat[nQntLin][nQntCol];

    for (nCont = 0; nCont < nQntLin; nCont++) {
        for (nCont2 = 0; nCont2 < nQntCol; nCont2++) {
            cin >> nMat[nCont][nCont2];
        }
    }

    cin >> nEnc;
 
    for (nCont = 0; nCont < nQntLin; nCont++) {
        nSoma = 0;
        for (nCont2 = 0; nCont2 < nQntCol; nCont2++) {
            if (nMat[nCont][nCont2] == nEnc) {
                nSoma++;
            }
        }
        cout << nSoma << endl;
    }
    return 0;
}