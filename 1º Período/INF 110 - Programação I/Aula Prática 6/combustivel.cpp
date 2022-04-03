#include <iomanip>
#include <iostream>
#include <math.h>
using namespace std;

int main() {
    
    double eCon,eInf,eMed;
    double eKlmTot = 0;
    double eGasTot = 0;
    char eTip;
    
    while (true) {
        cin >> eTip;
        if (eTip == 'X') {
            break;
        }
        cin >> eInf;
        if (eTip == 'R') {
            eKlmTot += eInf;
        }
        else {
            eGasTot += eInf;
        }
    }

    eMed = eKlmTot/eGasTot;

    cout << fixed << setprecision(2) << eMed << endl;

    return 0;
}