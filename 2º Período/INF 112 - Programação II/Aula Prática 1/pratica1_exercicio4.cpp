#include <iomanip>
#include <iostream>
using namespace std;

struct Jogador { 
    int pontos;
    int x,y; 
};

void leDadosJogador(Jogador *nPrt){
    cin >> nPrt->pontos >> nPrt->x >> nPrt->y;
}

int main(){ 

    Jogador j[5];   
    Jogador *nPtr;
    int nCont;
   

    for (nCont = 0; nCont < 5; nCont++) {
        nPtr = &j[nCont];
        leDadosJogador(nPtr);
    }

    for (nCont = 0; nCont < 5; nCont++) {
        cout << "Jogador: " << nCont + 1 << endl;
        cout << "Pontos: " << j[nCont].pontos <<  " "<< "X: " << j[nCont].x << " " << "Y: " << j[nCont].y << endl;
    }    

    return 0; 
}