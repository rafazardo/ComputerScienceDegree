#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main() {
    
    double nNumOvo, nCon1, nCon2, nBanOvo;

    cin >> nNumOvo;

    for (nCon1 = 1; nCon1 <= nNumOvo; nCon1++) {
        for (nCon2 = nCon1; nCon2 <= nNumOvo; nCon2++) {
            nBanOvo = nCon1 * nCon2;
            if (nBanOvo == nNumOvo) {
                cout << nCon1 << " x " << nCon2 <<endl;
            }
        }
    }
    
    return 0;
}