#include <iomanip>
#include <iostream>
#include <math.h>
using namespace std;

struct Capivara {
    char cNome[15];
    int nMatricula,nPeso,nAlt;
    double nIMC;
};

void bolha (Capivara a[], int n) { //Função que ordena os de acordo com o imc

    int nSupo2 = 0;
    int nSupo3 = 0;
    Capivara nSupo4;

    for (nSupo2 = 0; nSupo2 < n; nSupo2++) {
        for (nSupo3 = nSupo2 + 1; nSupo3 < n; nSupo3++) {
            if (a[nSupo2].nIMC > a[nSupo3].nIMC) {
               nSupo4 = a[nSupo3];
               a[nSupo3] = a[nSupo2];
               a[nSupo2] = nSupo4;
            }
        }
    }
}


int main() {
    
    int nQntdCapi,nCont;

    cin >> nQntdCapi;
    Capivara InfoAnm[nQntdCapi];
    
    for (nCont = 0; nCont < nQntdCapi; nCont++) { //Preenche os dados das capivaras
        cin >> InfoAnm[nCont].cNome >> InfoAnm[nCont].nMatricula >> InfoAnm[nCont].nPeso >> InfoAnm[nCont].nAlt;
        InfoAnm[nCont].nIMC = (InfoAnm[nCont].nPeso)/(pow((InfoAnm[nCont].nAlt/100.00),2.0)); //Faz calculo do imc
    }

    bolha(InfoAnm,nQntdCapi); //Ordena de acordo com o imc

    for (nCont = 0; nCont < nQntdCapi; nCont++) {
        cout << InfoAnm[nCont].cNome << ";" << InfoAnm[nCont].nMatricula << ";" << InfoAnm[nCont].nPeso << ";" << InfoAnm[nCont].nAlt << endl;
    }    

    return 0;
}