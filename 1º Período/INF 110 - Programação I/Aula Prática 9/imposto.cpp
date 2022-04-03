#include <iostream>
#include <iomanip>
using namespace std;

double imposto(double);

int main() {

    double nVlrInic;
    
    cin >> nVlrInic;
    while (nVlrInic != 0) {
        cout << fixed << setprecision(2) << "R$ " << imposto(nVlrInic) << endl;
        cin >> nVlrInic;
    }

    return 0;
}

double imposto(double v) {

    double nImpPag;

    if (v <= 22847.76) {
        nImpPag = 0;
    }
    else {
        if (v <= 33919.80) {
            nImpPag = ((7.5/100)*v) - 1713.58;
        }
        else {
            if (v <= 45012.60) {
                nImpPag = ((15.0/100)*v) - 4257.57;
            }
            else {
                if (v <= 55976.16) {
                    nImpPag = ((22.5/100)*v) - 7633.51;
                }
                else {
                    nImpPag = ((27.5/100)*v) - 10432.32;
                }
            }
        }
    } 

    return nImpPag;
}