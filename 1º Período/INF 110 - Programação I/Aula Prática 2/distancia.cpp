#include <iostream>
#include <math.h>
#include <iomanip>
#include <cstdio>
using namespace std;

int main() {
    double x1,y1,x2,y2,d,a,b;
    cin >> x1 >> y1 >> x2 >> y2;
    a = x2 - x1;
    b = y2 - y1;
    a = pow(a,2.0);
    b = pow(b,2.0);
    d = sqrt(a + b);
    cout << fixed << setprecision(2) << d << endl;
    return 0;
}