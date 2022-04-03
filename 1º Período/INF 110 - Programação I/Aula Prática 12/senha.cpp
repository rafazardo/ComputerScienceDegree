#include <iostream>
#include <iomanip>
#include <cctype>
using namespace std;

int main() {
    
    bool bLetr = false;
    bool bNum = false;
    bool bSimb = false;
    int nCont = 0;
    char cPalavra[30];
    int nSeguranca = 0;
    int nSup;

    cin >> cPalavra;

    //Verifica se tem letra minuscula
    for (nCont = 0; cPalavra[nCont] != '\0'; nCont++) {
        if (islower(cPalavra[nCont])) {
            nSeguranca++;
            break;
        }
    }
    // cout << nSeguranca << endl;

    // Verifica se tem letra maiscula
    for (nCont = 0; cPalavra[nCont] != '\0'; nCont++) {
        if (isupper(cPalavra[nCont])) {
            nSeguranca++;
            break;
        }
    }
    // cout << nSeguranca << endl;

    //Verifica se tem numero
    for (nCont = 0; cPalavra[nCont] != '\0'; nCont++) {
        if (isdigit(cPalavra[nCont])) {
            nSeguranca++;
            break;
        }
    }
    // cout << nSeguranca << endl;

    //Verifica se tem simbolo
    for (nCont = 0; cPalavra[nCont] != '\0'; nCont++) {
        if (!isalnum(cPalavra[nCont])) {
            nSeguranca++;
            break;
        }
    }
    // cout << nSeguranca << endl;

    if (nSeguranca == 3) {
        cout << "media" << endl;
    }
    else {
        if (nSeguranca == 2) {
            cout << "media" << endl;
        }
        else {
            if (nSeguranca == 1) {
                cout << "fraca" << endl;
            }
            else {
                if (nSeguranca == 4) {
                    cout << "segura" << endl;
                }
            }
        }
    }
    
    return 0;
}