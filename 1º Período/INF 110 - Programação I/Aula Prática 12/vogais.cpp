#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    
    int nCont;
    int nQntdVog = 0;
    double nQntdLetras;
    double nPorcentagem;
    char cPalavra[30];

    cin >> cPalavra;

    for (nCont = 0; cPalavra[nCont] != '\0'; nCont++) {
        if (cPalavra[nCont] == 'A' || cPalavra[nCont] == 'a' || cPalavra[nCont] == 'E' || cPalavra[nCont] == 'e' || cPalavra[nCont] == 'I' || cPalavra[nCont] == 'i' || cPalavra[nCont] == 'O' || cPalavra[nCont] == 'o' || cPalavra[nCont] == 'U' || cPalavra[nCont] == 'u') {
            nQntdVog++;
        }
        nQntdLetras = nCont + 1; 
    }
    
    nPorcentagem = (double)(nQntdVog/nQntdLetras) * 100;

    cout << fixed << setprecision(0) << nPorcentagem << "%" << endl;
    
    return 0;
}