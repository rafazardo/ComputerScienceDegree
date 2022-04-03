#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main() {
    double vBola,vCaixa,dBola,hCaixa,lCaixa,pCaixa;
    cin >> dBola;
    cin >> hCaixa >> lCaixa >> pCaixa;
    
    if (dBola <= hCaixa) {
        if (dBola <= lCaixa) {
            if (dBola <= pCaixa) {
                cout << "S" << endl;
            }
            else {
                cout << "N" << endl;     
            }
        }
        else {
            cout << "N" << endl;    
        }
    }
    else {
        cout << "N" << endl;
    }
    return 0;
}