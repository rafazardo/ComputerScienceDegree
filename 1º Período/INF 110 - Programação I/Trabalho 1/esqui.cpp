#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main() {
    double eDist,eJuiz1,eJuiz2,eJuiz3,eJuiz4,eJuiz5,ePont1,ePont_Total,eJuiz_Maior,eJuiz_Menor;

    cin >> eDist;
    cin >> eJuiz1 >> eJuiz2 >> eJuiz3 >> eJuiz4 >> eJuiz5;

    //Defini a nota da distancia do salto
    if (eDist < 120) {
        ePont1 = (60 - ((120 - eDist)*1.8));
    }
    else {
        if (eDist > 120) {
            ePont1 = (60 + ((eDist - 120)*1.8));
        }
        else {
            if (eDist == 120) {
                ePont1 = 60;
            }
        }
    } 

    //Verifica qual é a maior nota dos juizes
    if ((eJuiz1 >= eJuiz2) && (eJuiz1 >= eJuiz3) && (eJuiz1 >= eJuiz4) && (eJuiz1 >= eJuiz5)) {
        eJuiz_Maior = eJuiz1;
    }
    else {
        if ((eJuiz2 >= eJuiz1) && (eJuiz2 >= eJuiz3) && (eJuiz2 >= eJuiz4) && (eJuiz2 >= eJuiz5)) {
            eJuiz_Maior = eJuiz2;
        }
        else {
            if ((eJuiz3 >= eJuiz1) && (eJuiz3 >= eJuiz2) && (eJuiz3 >= eJuiz4) && (eJuiz3 >= eJuiz5)) {
                eJuiz_Maior = eJuiz3;
            }
            else {
                if ((eJuiz4 >= eJuiz1) && (eJuiz4 >= eJuiz2) && (eJuiz4 >= eJuiz3) && (eJuiz4 >= eJuiz5)) {
                    eJuiz_Maior = eJuiz4;
                }
                else {
                    if ((eJuiz5 >= eJuiz1) && (eJuiz5 >= eJuiz2) && (eJuiz5 >= eJuiz3) && (eJuiz5 >= eJuiz4)) {
                        eJuiz_Maior = eJuiz5;
                    }
                }
            }
        }
    }

    //Verifica qual é a menor nota dos juizes
    if ((eJuiz1 <= eJuiz2) && (eJuiz1 <= eJuiz3) && (eJuiz1 <= eJuiz4) && (eJuiz1 <= eJuiz5)) {
        eJuiz_Menor = eJuiz1;
    }
    else {
        if ((eJuiz2 <= eJuiz1) && (eJuiz2 <= eJuiz3) && (eJuiz2 <= eJuiz4) && (eJuiz2 <= eJuiz5)) {
            eJuiz_Menor = eJuiz2;
        }
        else {
            if ((eJuiz3 <= eJuiz1) && (eJuiz3 <= eJuiz2) && (eJuiz3 <= eJuiz4) && (eJuiz3 <= eJuiz5)) {
                eJuiz_Menor = eJuiz3;
            }
            else {
                if ((eJuiz4 <= eJuiz1) && (eJuiz4 <= eJuiz2) && (eJuiz4 <= eJuiz3) && (eJuiz4 <= eJuiz5)) {
                    eJuiz_Menor = eJuiz4;
                }
                else {
                    if ((eJuiz5 <= eJuiz1) && (eJuiz5 <= eJuiz2) && (eJuiz5 <= eJuiz3) && (eJuiz5 <= eJuiz4)) {
                        eJuiz_Menor = eJuiz5;
                    }
                }
            }
        }
    }

    //Defini a nota final
    ePont_Total = (ePont1 + ((eJuiz1 + eJuiz2 + eJuiz3 + eJuiz4 + eJuiz5) - (eJuiz_Maior + eJuiz_Menor)));
    cout << fixed << setprecision(1) << ePont_Total << endl;
    return 0;
}