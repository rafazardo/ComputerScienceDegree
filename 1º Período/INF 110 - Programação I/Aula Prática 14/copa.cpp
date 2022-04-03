#include <iomanip>
#include <iostream>
using namespace std;

struct TipoPartida {
    char time1[31], time2[31];
    int placar1, placar2;
};

struct Pontos {
    char time[31];
    int pontos = 0;
};

struct PontosB {
    char time[31];
    int pontos = 0;
};

int main() {

    TipoPartida Jogos[50];
    Pontos pPontos[50];
    PontosB pPontos2[50];
    int nCont,nQntdJogos;
    char cLixo;
    

    cin >> nQntdJogos;

    for (nCont = 0; nCont < nQntdJogos; nCont++) {
        cin >> Jogos[nCont].time1 >> Jogos[nCont].placar1 >> cLixo >> Jogos[nCont].time2 >> Jogos[nCont].placar2;
        if (Jogos[nCont].placar1 > Jogos[nCont].placar2) {
            pPontos[nCont].time = Jogos[nCont].time1;
            pPontos[nCont].pontos++;
        }
        else {
            if (Jogos[nCont].placar1 < Jogos[nCont].placar2) {
                pPontos[nCont].time = Jogos[nCont].time2;
                pPontos[nCont].pontos++;   
            }
            else {
                if (Jogos[nCont].placar1 == Jogos[nCont].placar2) {
                    pPontos[nCont].time = Jogos[nCont].time2;
                    pPontos[nCont].pontos++;
                    pPontos[nCont+10].time = Jogos[nCont].time2;
                    pPontos[nCont+10].pontos++;    
                }
            }
        }
    }


    for (nCont = 0; nCont < 50; nCont++) {
        if (pPontos[nCont].time == )
    
    
    }





    return 0;
}