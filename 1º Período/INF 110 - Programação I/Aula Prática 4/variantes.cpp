#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main() {
    double ePess,eTaxa,eCntrl;

    eCntrl = 0;
    cin >> ePess >> eTaxa;

    while (ePess < 1000000000) {
        ePess = (ePess + (eTaxa*ePess));
        eCntrl++;
    }

    cout << eCntrl << endl;
    return 0;
}