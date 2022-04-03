#include <iostream>
#include <iomanip>
using namespace std;

void bolha (int a[], int n) {

    int nSupo2 = 0;
    int nSupo3 = 0;
    int nSupo4 = 0;

    for (nSupo2 = 0; nSupo2 < n; nSupo2++) {
        for (nSupo3 = nSupo2 + 1; nSupo3 < n; nSupo3++) {
            if (a[nSupo2] > a[nSupo3]) {
               nSupo4 = a[nSupo3];
               a[nSupo3] = a[nSupo2];
               a[nSupo2] = nSupo4;
            }
        }
    }
}

int main() {

    int QntdCand,Cont,MaiorTerm;
    cin >> QntdCand;
    int Notas[QntdCand];
    int Empat = 0;

    for (Cont = 0; Cont < QntdCand; Cont++) {
        cin >> Notas[Cont];
    }    

    bolha(Notas,QntdCand);
    MaiorTerm = Notas[QntdCand - 1];

    for (Cont = 0; Cont < QntdCand; Cont++) {
        if (Notas[Cont] == MaiorTerm) {
            Empat++;
        }
    } 

    cout << MaiorTerm << " " << Empat << endl;

    return 0;
}