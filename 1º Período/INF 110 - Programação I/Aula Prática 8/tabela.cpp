#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    
    int nCont,nCont2,nQntdLin,nQntdCol;

    cin >> nQntdLin >> nQntdCol;
    int nQntProd[nQntdLin][nQntdCol];

    for (nCont = 0; nCont < nQntdLin; nCont++) {
        for (nCont2 = 0; nCont2 < nQntdCol; nCont2++) {
            cin >> nQntProd[nCont][nCont2];
        }
    }

    for (nCont = 0; nCont < nQntdCol; nCont++) {
        for (nCont2 = 0; nCont2 < nQntdLin; nCont2++) {
            if (nCont2 == nQntdLin - 1) {
                cout << nQntProd[nCont2][nCont];
            }
            else {
                cout << nQntProd[nCont2][nCont] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}