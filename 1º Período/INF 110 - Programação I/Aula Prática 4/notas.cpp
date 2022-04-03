#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double eAlns,eNota,eNota_Tot,eCntrl,eMedia;

    eNota_Tot = 0;
    eCntrl = 1;
    cin >> eAlns;
    while (eCntrl <= eAlns) {
        cin >> eNota;
        eNota_Tot += eNota;
        eCntrl++;
    }
    eMedia = eNota_Tot / eAlns;
    cout << fixed << setprecision(2) << eMedia << endl; 
    return 0;
}