#include <iostream>
#include <iomanip>
using namespace std;

int main() {

    int Cont,Qntd;
    int SomaSec = 0;
    int DivTer = 0;
    int SomaTer = 0;
    cin >> Qntd;
    int EspTer[Qntd];    

    for (Cont = 0; Cont < Qntd; Cont++) {
        cin >> EspTer[Cont];
        SomaTer += EspTer[Cont];
    }        
    
    DivTer = SomaTer / 2;
    SomaTer = 0;

    for (Cont = 0; Cont < Qntd; Cont++) {
        SomaTer += EspTer[Cont];
        SomaSec++; 
        if (DivTer == SomaTer) {
            break;
        }
    }

    cout << SomaSec << endl;    

    return 0;
}