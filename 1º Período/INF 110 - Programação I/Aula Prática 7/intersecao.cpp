#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main() {
 
    int nCont,nQntd1,nQntd2,nSup;

    cin >> nQntd1 >> nQntd2;
    int nVetA[nQntd1];
    int nVetB[nQntd2];

    for (nCont = 0; nCont < nQntd1; nCont++) {
        cin >> nVetA[nCont];
    }
     
    for (nCont = 0; nCont < nQntd2; nCont++) {
        cin >> nVetB[nCont];
    }

    cout << "{";
    for (nCont = 0; nCont < nQntd1; nCont++) {
        for (nSup = 0; nSup < nQntd2; nSup++) {
            if (nVetA[nCont] == nVetB[nSup]) {
                cout << nVetA[nCont] << " ";
            }
        }       
    }

    cout << "}" << endl;

    return 0;
}