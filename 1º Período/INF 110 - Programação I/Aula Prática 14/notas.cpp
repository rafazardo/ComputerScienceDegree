#include <iomanip>
#include <iostream>
using namespace std;

struct aluno {
    int nMatricula,nPontos;
};

void bolha (aluno a[], int n) {

    int nSupo2 = 0;
    int nSupo3 = 0;
    aluno nSupo4;

    for (nSupo2 = 0; nSupo2 < n; nSupo2++) {
        for (nSupo3 = nSupo2 + 1; nSupo3 < n; nSupo3++) {
            if (a[nSupo2].nMatricula > a[nSupo3].nMatricula) {
               nSupo4 = a[nSupo3];
               a[nSupo3] = a[nSupo2];
               a[nSupo2] = nSupo4;
            }
        }
    }
}

int main(){

    aluno aAlunos[100];
    int nCont = 0;
    int nNumAln,nCont2;

    cin >> nNumAln;

    for (nCont = 0; nCont < nNumAln; nCont++) {
       cin >> aAlunos[nCont].nMatricula >> aAlunos[nCont].nPontos;
    }

    bolha(aAlunos,nNumAln);
    
    for (nCont = 0; nCont < nNumAln; nCont++) {
       cout << aAlunos[nCont].nMatricula << " " << aAlunos[nCont].nPontos << endl;
    }
    
    return 0;
}