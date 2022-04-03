#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    
    int nIdadeA,nIdadeB,nIdadeC;
    int nMaior = 0;
    int nMenor = 0;
    int nSomaIdades = 0;

    cin >> nIdadeA >> nIdadeB >> nIdadeC;
    nSomaIdades = nIdadeA + nIdadeB + nIdadeC;

    if (nIdadeA >= nIdadeB && nIdadeA >= nIdadeC) { //Encontra a maior idade
        nMaior = nIdadeA;
    }
    else {
        if (nIdadeB >= nIdadeC) {
            nMaior = nIdadeB;
        }
        else {
            nMaior = nIdadeC;
        }
    }

    if (nIdadeA <= nIdadeB && nIdadeA <= nIdadeC) { //Encontra a menor idade
        nMenor = nIdadeA;
    }
    else {
        if (nIdadeB <= nIdadeC) {
            nMenor = nIdadeB;
        }
        else {
            nMenor = nIdadeC;
        }
    }
    
    cout << nSomaIdades - (nMaior + nMenor) << endl; //Deixa somente a idade do do meio
    
    return 0;
}