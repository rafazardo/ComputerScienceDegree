#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    
    int nQntdLin,nQntdCol,Cont,Cont2,nLinhaAnd,nColAnd,nLinInc,nColInic;

    cin >> nQntdLin >> nQntdCol;
    
    char tabela[nQntdLin][nQntdCol];

    for (Cont = 0; Cont < nQntdLin; Cont++) {
        for (Cont2 = 0; Cont2 < nQntdCol; Cont2++) {
            cin >> tabela[Cont][Cont2];
        }
    }
  
    cin >> nLinhaAnd >> nColAnd;
    cin >> nLinInc >> nColInic;

    for (Cont = nLinInc - 1; Cont < (nLinhaAnd+nLinInc) - 1; Cont++) { //Desenha asc
        for (Cont2 = nColInic - 1; Cont2 < (nColAnd+nColInic) - 1; Cont2++) {
            cout << tabela[Cont][Cont2];
        }
        cout << endl;
    }

    return 0;
}