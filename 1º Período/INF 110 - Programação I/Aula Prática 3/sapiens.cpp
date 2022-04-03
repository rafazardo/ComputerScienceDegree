#include <iostream>
#include <iomanip>
#include <math.h>
#include <cstdio>
using namespace std;

int main() {
    int NF,FT,FP;
    cin >> NF >> FT >> FP;

    if (FT <= 15) {
        if (FP <= 7) {
            if (NF >= 40) {
                if (NF < 60) {
                    cout << "Final" << endl;
                }
                else {
                    cout << "Aprovado" << endl;
                }
            }
            else {
                cout << "Reprovado" << endl;
            }
        }
        else {
            cout << "Reprovado" << endl;    
        }
    }
    else {
        cout << "Reprovado" << endl;
    }
    return 0;
}