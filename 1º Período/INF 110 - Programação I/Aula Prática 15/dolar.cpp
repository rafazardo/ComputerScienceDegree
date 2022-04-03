#include <iomanip>
#include <iostream>
using namespace std;

int main() {

    double nMaior = -100000;
    double nMenor = 100000;
    double nSup;
    int nQntdVari,nCont;

    cin >> nQntdVari;

    double nVari[nQntdVari];

    for (nCont = 0; nCont < nQntdVari; nCont++) { //Preenchi as variações
        cin >> nVari[nCont];
    }

    for (nCont = 0; nCont < nQntdVari - 1; nCont++) { //Verifica qual váriação é a maior e qual é a menor
       nSup = nVari[nCont] - nVari[nCont + 1];
        if (nSup > nMaior) {
            nMaior = nSup;
        }
        if (nSup < nMenor) {
             nMenor = nSup;
        }
    }

    cout << fixed << setprecision(4) << nMaior << endl;
    cout << fixed << setprecision(4) << nMenor*(-1) << endl;
    return 0;
}