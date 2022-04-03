#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main() {
    
    double nCapEle,nLeiElv,eCont,nEntElv,nSaiElv;
    double nPesElv = 0;
    double nLimAci = 0;

    cin >> nLeiElv >> nCapEle;

    for (eCont = 1; eCont <= nLeiElv; eCont++) {
        cin >> nSaiElv >> nEntElv;
        nPesElv = ((nPesElv - nSaiElv) + nEntElv);
        if (nPesElv > nCapEle) {
            nLimAci++;
        }
    }

    if (nLimAci == 0) {
        cout << "N" << endl;
    }
    else {
        cout << "S" << endl;
    }
    

    return 0;
}