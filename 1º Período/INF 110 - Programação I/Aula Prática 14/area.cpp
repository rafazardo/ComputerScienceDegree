#include <iomanip>
#include <iostream>
#include <math.h>
using namespace std;

struct Ponto {
    int x,y;
};

double area (double P, double Q, double R) {
    long double s;
    s = (P + Q + R) / 2.0;
    return sqrt(s * (s - P) * (s - Q) * (s - R));
}

double distancia (Ponto A, Ponto B) {
    return sqrt(pow(B.x - A.x,2.0) + pow(B.y - A.y,2.0));
}

int main() {
    
    Ponto pA,pB,pC;
    long double nDistA,nDistB,nDistC;

    cin >> pA.x >> pA.y >> pB.x >> pB.y >> pC.x >> pC.y;
    nDistA = distancia(pA,pB);
    nDistB = distancia(pB,pC);
    nDistC = distancia(pC,pA);
    cout << fixed << setprecision(2) << area(nDistA,nDistB,nDistC) << endl;

    return 0;
}