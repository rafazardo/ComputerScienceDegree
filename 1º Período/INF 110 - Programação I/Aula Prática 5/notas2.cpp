#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main() {

    double nNot,nCon;
    double nNotTot = 0;
    double nTotAln = 0;
    double nAlnApr = 0;
    double nAlnRec = 0;
    double nAlnRep = 0;
    double nAlnPc1 = 0;
    double nAlnPc2 = 0;
    double nAlnPc3 = 0;

    cin >> nTotAln;
    for (nCon = 1; nCon <= nTotAln; nCon++) {
        cin >> nNot;
        nNotTot += nNot;
        if (nNot >= 60) {
            nAlnApr += 1;
        }
        else {
            if (nNot >= 40) {
                nAlnRec += 1;
            }
            else {
                nAlnRep += 1;
            }
        }
    }

    nAlnPc1 = ((nAlnApr / nTotAln) * 100);
    nAlnPc2 = ((nAlnRec / nTotAln) * 100);
    nAlnPc3 = ((nAlnRep / nTotAln) * 100);

    cout << fixed  << setprecision(1) << "Aprovados: " << nAlnPc1 << "%" << endl;
    cout << fixed  << setprecision(1) << "Reprovados: " << nAlnPc3 << "%" << endl;
    cout << fixed  << setprecision(1) << "De exame final: " << nAlnPc2 << "%" << endl;
    return 0;
}