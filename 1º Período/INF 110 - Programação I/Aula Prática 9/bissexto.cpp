#include <iomanip>
#include <iostream>
#include <math.h>
using namespace std;

bool bissexto(int);

int main() {
    
    int nAno;
    
    cin >> nAno;
    while (nAno >= 0) {
        if (bissexto(nAno)) {
            cout << "bissexto" << endl;
        }
        else {
            cout << "nao bissexto" << endl;
        }
        cin >> nAno;
    }

   return 0; 
}

bool bissexto(int n) {

    bool bEnc;

    if (n % 4 == 0) {
        if (n % 100 == 0) {
            if (n % 400 == 0) {
                bEnc = true;
            }
            else {
                bEnc = false;
            }
        }
        else {
            bEnc = true;
        }
    }
    else {
        bEnc = false;
    }

    return bEnc;
}