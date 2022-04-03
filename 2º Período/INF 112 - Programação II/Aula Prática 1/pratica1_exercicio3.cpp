#include <iomanip>
#include <iostream>
#include <cstring>
using namespace std;


int calculaTamanhoString1 (char a[]) { 

    int nCont;
    int nTamString = 0;

    for (nCont = 0; a[nCont] != '\0'; nCont++) {
        nTamString++;
    }

    return nTamString;
}

int calculaTamanhoString2 (char a[]) { 
    
    int nCont;
    int nTamString = 0;

    for (nCont = 0; *(a+nCont) != '\0'; nCont++) {
        nTamString++;
    }

    return nTamString;
}

int calculaTamanhoString3(char a[]) { 

	char *nInic = a;

	for (;*a!='\0';a++) {
    }

	return (a-nInic);
}

int main() {

    char str [51];
    cout << "Digite alguma string... (com ate 50 caracteres):"; 
    cin.getline(str, 50);
    cout << "Tamanhos calculados:" << endl;
    cout << calculaTamanhoString1(str) << " " << calculaTamanhoString2(str) << " " << calculaTamanhoString3(str); cout << endl;

    return 0; 
}
