#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    
    int nCont = 1;
    int nQntListas,nCont2,nQntdItens,nCont3;
    bool bAcha;

    cin >> nQntListas;

    while (nCont <= nQntListas) {
        bAcha = false;
        cin >> nQntdItens;
        int nLista[10000];
        int nQntdValIguais[10000];

        for (nCont2 = 0; nCont2 < nQntdItens; nCont2++) {
            cin >> nLista[nCont2];
        }

        for (nCont2 = 0; nCont2 < nQntdItens; nCont2++) {
             nQntdValIguais[nCont2] = 0;
        }        
        
        for (nCont2 = 0; nCont2 < nQntdItens; nCont2++) {
            for (nCont3 = 0; nCont3 < nQntdItens; nCont3++) {
                if (nLista[nCont2] == nLista[nCont3]) {
                   nQntdValIguais[nCont2]++;
                }

                if (nQntdValIguais[nCont2] == 2) {
                    cout << "SIM: " << nLista[nCont2] << endl;
                    bAcha = true;
                    break;                    
                }
            } 
            if (bAcha == true) {
                break;
            }    
        }
        
        if (bAcha == false) {
            cout << "NAO" << endl;
        }

        nCont++;
    }

    return 0;
}