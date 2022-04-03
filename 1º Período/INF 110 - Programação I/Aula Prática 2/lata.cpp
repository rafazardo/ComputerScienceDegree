#include <iostream>
#include <cstdio>
#include <iomanip>
#include <math.h>
using namespace std;

int main() {
    double r,h,v;
    cin >> r >> h;
    v = 3.1415*h*pow(r,2.0);
    cout << fixed << setprecision(2) << v << endl;
    return 0;
}