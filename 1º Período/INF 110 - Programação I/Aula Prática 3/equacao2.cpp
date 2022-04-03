#include <iostream>
#include <iomanip>
#include <math.h>
#include <cstdio>
using namespace std;

int main() {
    double A,B,C,d,r1,r2;
    cin >> A >> B >> C;
    d = pow(B,2.0) - (4*A*C);

    if (d < 0) {
        cout << "Nao ha raiz real" << endl;
    }
    else {
        if (d == 0) {
            r1 = -B / (2*A);
            cout << fixed << setprecision(2) << r1 << endl;
        }
        else {
            r1 = (-B - sqrt(d)) / (2*A);
            r2 = (-B + sqrt(d)) / (2*A);
            cout << fixed << setprecision(2) << r1 << " " << r2 << endl;
        }
    } 

    return 0;
}