#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int main() {
    char cPalavra1[101];
    char cPalavra2[101];
    int nTot = 0;
    int nCont;

    cin >> cPalavra1 >> cPalavra2;
    
    if (strlen(cPalavra1) != strlen(cPalavra2)) {
        cout << "NAO" << endl;
        return 0;
    }

    for (nCont = 0; cPalavra1[nCont] != '\0'; nCont++) {
        if (cPalavra1[nCont] != cPalavra2[nCont]) {
            nTot++;
        }
    }
    
    if (nTot == 1) {
        cout << "SIM" << endl;
    }
    else {
        cout << "NAO" << endl;
    }

    return 0;
}
