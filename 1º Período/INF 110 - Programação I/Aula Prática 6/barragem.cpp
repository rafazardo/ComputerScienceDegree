#include <iomanip>
#include <iostream>
#include <math.h>
using namespace std;

int main() {
    
    double ePessMin,ePesSal,eTotSal,eTotPes;
    double eTotMin = 0;
    double eConMin = 0;
    double eTot = 0;

    cin >> eTotPes >> eTotMin;

    while (true) {
        cin >> ePesSal;
        if (ePesSal == -1) {
            break;
        }
        eConMin++;
        if (eConMin <= eTotMin) {
            eTot += ePesSal;
        }
    }

    eTotSal = eTotPes - eTot;

    if (eTotSal == 0) {
        cout << "Todos a salvo" <<endl;
    } 
    else {
        cout << "Apenas " << eTot << " pessoas a salvo" <<endl;
    }

    return 0;
}