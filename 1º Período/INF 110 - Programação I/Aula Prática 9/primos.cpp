#include <iomanip>
#include <iostream>
#include <math.h>
using namespace std;

bool eh_primo(int);

int main() {
    int a, b;
    
    cin >> a >> b;
    cout << "Primos entre " << a << " e " << b << ":";
    for(int i = a; i <= b; i++)
        if (eh_primo(i)) { //Se for primo
            cout << " " << i; //imprime o valor
        }
    cout << endl;

    return 0;
}

bool eh_primo(int n) {
    int nCon,nNumDiv1;
    int nNumDiv2 = 0;

    for (nCon = 1; nCon <= n; nCon++) {
        nNumDiv1 = n % nCon;
        if (nNumDiv1 == 0) {
            nNumDiv2++;
        }
    }

    if (nNumDiv2 == 2) {
        return true;
    }
    else {
         return false;
    }
}