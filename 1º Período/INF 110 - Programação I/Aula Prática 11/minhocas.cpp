#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int Lin,Col,Cont,Cont2;
    int Maior = 0;
    int Pass = 0;
    cin >> Lin >> Col;
    int Camp[Lin][Col];
    

    for (Cont = 0; Cont < Lin; Cont++) {
        for (Cont2 = 0; Cont2 < Col; Cont2++) {
            cin >> Camp[Cont][Cont2];
        }
    }

    for (Cont = 0; Cont < Lin; Cont++) {
        for (Cont2 = 0; Cont2 < Col; Cont2++) {
            Pass += Camp[Cont][Cont2];
        }
        if (Pass > Maior) {
            Maior = Pass;
        }
        Pass = 0;
    }  

    Pass = 0;
    for (Cont = 0; Cont < Col; Cont++) {
        for (Cont2 = 0; Cont2 < Lin; Cont2++) {
            Pass += Camp[Cont2][Cont];
        }
        if (Pass > Maior) {
            Maior = Pass;
        }
        Pass = 0;
    }      

    cout << Maior << endl;
    return 0;
}