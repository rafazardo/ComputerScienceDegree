#include <iostream>
#include <iomanip>
#include <math.h>
#include <cstdio>
using namespace std;

int main() {
    char E;
    double T,R;
    cin >> T >> E;
    R = 0;
    if (E == 'C') {
        R = (T*1.8) + 32;
        cout << fixed << setprecision(1) << R << " " << "F" << endl;
    }
    else {
        R = (T - 32) / 1.8;
        cout << fixed << setprecision(1) << R << " " << "C" << endl;
    }
    return 0;
}