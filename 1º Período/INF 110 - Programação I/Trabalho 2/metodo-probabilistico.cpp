#include <iomanip>
#include <iostream>
#include <math.h>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    
    long double nPontDent = 0;
    long double nPontSort,nDeltaX,nDeltaY,nPi,nDist,nRaio,nPontX,nPontY;
    long int nCont,nSup;
    
    cout << "Digite o valor do raio: ";
    cin >> nRaio;
    nSup = nRaio;
    cout << "Digite o numero de pontos a sortear: ";
    cin >> nPontSort;
    cout << "Processando dados...\n";
    srand(time(NULL));
    for (nCont = 1; nCont <= nPontSort; nCont++) {
        nPontX = rand()%((2*nSup)+1); //Calcula valores de 0 até o tamanho maximo do lado do quadrado para o eixo X.
        nPontY = rand()%((2*nSup)+1); //Calcula valores de 0 até o tamanho maximo do lado do quadrado para o eixo Y.
        nDeltaX = pow((nPontX-nRaio),2.0); 
        nDeltaY = pow((nPontY-nRaio),2.0);
        nDist = sqrt(nDeltaY+nDeltaX); //Calcula distancia do centro do circulo até o ponto gerado
        if (nDist < nRaio) {
            nPontDent++;
        }
    }
    nPi = 4*(nPontDent/nPontSort);
    cout << "===============\n";
    cout << fixed << setprecision(80) << nPi << endl;
    cout << "===============\n";
    return 0;
}