#include <iostream>
#include <iomanip>
using namespace std;

//Verifica se o mes é valido
bool validaData(int, int, int);

//Verifica se o ano é bissexto
bool bissexto(int);

int main() {
    
    int d,m,a;
    cin >> d >> m >> a;

    if (validaData(d,m,a)) {
        cout << "data valida" << endl;
    }
    else {
        cout << "data invalida" << endl;
    }

    return 0;
}

bool validaData(int d, int m, int a) {

    bool bVal;

    //Verifica o mes bissexto
    if (bissexto(a)) {
        if ((m == 2) && (d <= 29)) {
            bVal = true;
        }
        else {
            //verifica os meses de 30 dias
            if (((m == 4 || m == 6 || m == 9 || m == 11) && d <= 30)) {
                bVal = true;
            }
            else {
                //verifica os meses de 31 dias
                if (((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) && d <= 31)) {
                    bVal = true;
                }
                else {
                    bVal = false;
                }
            }
        }
    }
    else {
        if ((m == 2) && (d <= 28)) {
            bVal = true;
        }
        else {
            //verifica os meses de 30 dias
            if (((m == 4 || m == 6 || m == 9 || m == 11) && d <= 30)) {
                bVal = true;
            }
            else {
                //verifica os meses de 31 dias
                if (((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) && d <= 31)) {
                    bVal = true;
                }
                else {
                    bVal = false;
                }
            }
        }
    }

    return bVal;
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