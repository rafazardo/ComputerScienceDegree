#include <iostream>
#include "SHA256.h"
using namespace std;

//sua main devera ter esse include e usar a funcao imprimeTransacoes
//para imprimir...
//o arquivo imprimeTransacoes.h nao precisa ser enviado (o submitty ja tem uma copia dele, para garantir
//que ninguem vai modificar a funcao de impressao)
//O include abaixo pode ser mantido comentado quando voce for enviar a primeira parte do trabalho 
//e tambem enquanto voce nao termina a implementacao dos iteradores (caso contrario seu programa nao compilara)
//#include "imprimeTransacoes.h"

int main() {
	//exemplo de uso do calculo do hash:
	int numDados = 16;
	int v[numDados] = {2,123,5,2,3,10,2,1,3,12,3,0,2,20,1,564};
	SHA256 sh;
	int h = sh.calcula(v,numDados);
	cout << h << endl;  //devera ser -232715264  (tente modificar um numero e veja como o hash modifica...

}

