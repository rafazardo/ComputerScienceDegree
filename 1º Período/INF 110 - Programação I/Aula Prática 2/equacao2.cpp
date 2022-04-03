#include <iostream>
#include <math.h>
#include <cstdio>
#include <iomanip>
using namespace std;

int main() {
    double a,b,c,d,x1,x2;
    cin >> a >> b >> c;
    d = pow(b,2.0) - 4*a*c;
    x1 = (-b + sqrt(d))/(2*a);
    x2 = (-b - sqrt(d))/(2*a);
    cout << fixed << setprecision(4) << x1 << " " << x2 << endl;
    return 0;
}