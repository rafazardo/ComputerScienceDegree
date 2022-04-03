#include <iostream>
#include <iomanip>
using namespace std;


int main() {

    int nNumPri,nCon,nNumDiv1;
    int nNumDiv2 = 0;

    cin >> nNumPri;
    for (nCon = 1; nCon <= nNumPri; nCon++) {
        nNumDiv1 = nNumPri % nCon;
        if (nNumDiv1 == 0) {
            nNumDiv2++;
        }
    }

    if (nNumDiv2 == 2) {
        cout << "Primo." <<endl;
    }
    else {
         cout << "Nao primo." <<endl;
    }

    return 0;
}