#include <iomanip>
#include <iostream>

void preencheAleatorios(int nVetor[],int nQntdJog) { 
    
    int nCont;
    
    for (nCont = 0; nCont < nQntdJog; nCont++) {
        nVetor[nCont] = rand() % 10;
    }
}

void imprime(int nVetor[],int nQntdJog) {
    
    int nCont;
    
    for (nCont = 0; nCont < nQntdJog; nCont++) {
        std::cout << nVetor[nCont] << ",";
    }
    std::cout << std::endl;
}

void contaParImpar(int pVetorA[], int pVetorB[], int nQntdJog, int nQntdPar, int nQntdImp) {
    
    int nCont;
    
    for (nCont = 0; nCont < nQntdJog; nCont++) {
        if ((pVetorA[nCont] + pVetorB[nCont]) % 2 == 0) {
            nQntdPar++;
        }
        else {
            nQntdImp++;
        }
    }

    std::cout << "Par: " << nQntdPar << std::endl;
    std::cout << "Impar: " << nQntdImp << std::endl;
}

int main() {
    
    int *pVetorA,*pVetorB;
    int nQntdJog = 0;
    int nQntdPar = 0;
    int nQntdImp = 0;
    
    while (true) {
        std::cout << "Digite a quantidade de jogadas a simular: ";
        std::cin >> nQntdJog;
        if (nQntdJog < 0) {
            break;
        }
        pVetorA = new int [nQntdJog];
        pVetorB = new int [nQntdJog];
        preencheAleatorios(pVetorA,nQntdJog);
        preencheAleatorios(pVetorB,nQntdJog);
        imprime(pVetorA,nQntdJog);
        imprime(pVetorB,nQntdJog);
        contaParImpar(pVetorA,pVetorB,nQntdJog,nQntdPar,nQntdImp);
        delete [] pVetorA;
        delete [] pVetorB;
    }

    return 0;
}