#include <iomanip>
#include <iostream>
#include <math.h>
using namespace std;

int main() {
    
    double eCont;
    double eA,eB,eRes;

    cin >> eA >> eB;

    for (eCont = eA; eCont <= eB; eCont++) {
        eRes = (180*(eCont-2))/eCont;
        cout << fixed << setprecision(1) << eRes << endl;
    }
    return 0;
}