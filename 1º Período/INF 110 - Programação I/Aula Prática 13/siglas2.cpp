#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int main() {
    char cPalavra1[201]; //Sigla
    char cPalavra2[201]; //Nome
    int nCont,nCont2;
    int nControle = 0;
    bool bVerifi;

    cin.getline(cPalavra1,201);
    cin.getline(cPalavra2,201);

    for (nCont = 0; cPalavra1[nCont] != '\0'; nCont++) { //nCont = Contador da sigla
        bVerifi = false;
        for (nCont2 = nControle; cPalavra2[nCont2] != '\0'; nCont2++) { //nCont2 = Contador da frase
            if (cPalavra2[nCont2] == cPalavra1[nCont]) {
                bVerifi = true;
                nControle = nCont2 + 1;
                break;
            }
        }
        if (bVerifi == false) {
            cout << "NAO" << endl;
            return 0;
        }
    }

    if (bVerifi == true) {
        cout << "SIM" << endl;
    }
    
    return 0;
}
