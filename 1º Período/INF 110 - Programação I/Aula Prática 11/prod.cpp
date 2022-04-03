#include <iostream>
#include <iomanip>
using namespace std;

int main() {

    int Qntd,Cont;

    cin >> Qntd;
    double NumFun[Qntd];
    bool FunTrab[Qntd];
    int TotTrab = 0;
    double TotInt = 0;

    for (Cont = 0; Cont < Qntd; Cont++) {
        cin >> NumFun[Cont];
        TotInt += NumFun[Cont];
    }
    
    for (Cont = 0; Cont < Qntd; Cont++) {
        cin >> FunTrab[Cont];
    }    

    for (Cont = 0; Cont < Qntd; Cont++) {
        if (FunTrab[Cont] == true) {
            TotTrab++;
        }
    }

    if (TotTrab == 0) {
        cout << "Fechado" << endl;
    }
    else {
        cout << fixed << setprecision(1) << TotInt/TotTrab << endl;
    }
     
    return 0;
}