#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    char cPalavra[100];
    int nTermInic,nQntdTem,nTermFin,nCont;
    
    cin >> cPalavra >> nTermInic >> nQntdTem;
    nTermFin = (nTermInic + nQntdTem) - 1;

    for (nCont = nTermInic; nCont <= nTermFin; nCont++) {
        cout << cPalavra[nCont];
    }
    cout << endl;
    return 0;
}