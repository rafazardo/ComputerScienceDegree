#include <algorithm>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

//Vamos usar variaveis globais nesse caso...
//Isso nao é uma boa pratica, mas vai facilitar no seu entendimento/implementacao da busca binaria
int taxaVideo,taxaDownload,tamanho;

//Essa funcao devera retornar true sse for possível 
//assistir a um vídeo de "tamanho" segundos, que gasta taxaVideo bytes por segundo para ser assistido
//supondo que sua internet consegue baixar taxaDownload bytes por segundo.
//tempoCarregamento indica quanto tempo voce irá aguardar para começar assistir ao vídeo
//Implemente esta funcao
bool consigoAssistirSemPausas(int tempoCarregamento) {
	int i = 0, bytes = tempoCarregamento*taxaDownload;

	while(i < tamanho){
		bytes += taxaDownload;

		if(bytes >= taxaVideo){
			bytes -= taxaVideo;	
			i++;
		}
		else
			break;
	}

	if(i ==  tamanho) return true;
	else return false;
}

int buscaBin(int begin, int end) {
	if (begin > end) return -1;

	int meio = (end-begin)/2 + begin;

	if (consigoAssistirSemPausas(meio)){
		return buscaBin(array,begin, meio-1, chave); 
	}
	else{
		if(consigoAssistirSemPausas(meio+1))
			return meio;
		else 
			return buscaBin(array,meio+1, end, chave); 	
	}
}


int main() {
	cin >> taxaVideo >> taxaDownload >> tamanho;
	cout << taxaVideo << taxaDownload << tamanho;
}