#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int eq2grau(double, double, double, double &, double &);

int main() {

    double a,b,c;
    double x1 = 0;
    double x2 = 0;
    
    cin >> a >> b >> c;

    if (eq2grau(a,b,c,x1,x2) == 0) {
        cout << "Nao ha raiz real" << endl;
    }
    else {
        if (eq2grau(a,b,c,x1,x2) == 1) {
            cout << fixed << setprecision(2) << x1 << endl;
        }
        else {
            cout << fixed << setprecision(2) << x1 << " " << x2 << endl;
        }
    }
    
    return 0;
}

int eq2grau(double a, double b, double c, double &x1, double &x2) {
    
    int QntdTerm;
    double d;

    d = pow(b,2.0) - 4*a*c;
    if (d < 0) {
        QntdTerm = 0;
    }
    else {
        if (d > 0) {
            QntdTerm = 2;
            x1 = (-b - sqrt(d))/(2*a);
            x2 = (-b + sqrt(d))/(2*a);            
        }
        else {
            QntdTerm = 1;
            x1 = (-b - sqrt(d))/(2*a);
        }
    }
    return QntdTerm;
}