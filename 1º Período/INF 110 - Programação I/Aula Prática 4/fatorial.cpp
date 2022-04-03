#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    long double eFat_Total,eFat,eCntrl;

    eCntrl = 1;
    eFat_Total = 1;

    cin >> eFat;
    while (eCntrl <= eFat) {
        eFat_Total = eFat_Total*eCntrl;
        eCntrl++;
    }

    if (eFat == 0) {
        eFat_Total = 1;
    }

    cout <<  fixed << setprecision(0) << eFat_Total << endl;
    return 0;
}