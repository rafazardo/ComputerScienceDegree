#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    
    int nTotJog,nIdaReg,nLimJog,nCon,nIdaJog;
    int nIdaLim = 0;

    cin >> nTotJog >> nIdaReg >> nLimJog;
    for (nCon = 1; nCon <= nTotJog; nCon++) {
        cin >> nIdaJog;
        if (nIdaJog >= nIdaReg) {
            nIdaLim += 1;
        }
    } 

    if (nIdaLim > nLimJog) {
        cout << "Nao aceito." << endl;
    }
    else {
         cout << "Aceito." << endl;
    }

    return 0;
}