#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int eA,eB,eTest1,eTest2;
    int eCntrl = 0;

    cin >> eA >> eB;
    while (true) {
        eCntrl++;
        eTest1 = eCntrl % eA;
        eTest2 = eCntrl % eB;
        if ((eTest1 == 0) && (eTest2 == 0)) {
            break;
        }
    }

    cout << eCntrl <<endl;
    return 0;
}