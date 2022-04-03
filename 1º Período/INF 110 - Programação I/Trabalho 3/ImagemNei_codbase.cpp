// INF110 - Trabalho Pratico 3
//
// Programa para ler, modificar e gravar uma imagem no formato PNM
//
// Autores: Andre Gustavo dos Santos			(criado em 16/06/14)
//          Andre Gustavo dos Santos			(modificado em 22/05/18)
//			Andre Gustavo dos Santos			(modificado em 13/09/21)
//			Rafael Zardo Crevelari				(modificado em 04/09/21)

#include <iostream>
#include <fstream>
#include <cstring>
#include <math.h>
#include <iomanip>

const int MAXALTURA  = 355;							//Tamanho máximo aceito pelo programa
const int MAXLARGURA = 355;

using namespace std;

int main() {
	unsigned char imagem[MAXALTURA][MAXLARGURA];	//Matriz para armazenar imagens em tons de cinza
	unsigned char imagemR[MAXALTURA][MAXLARGURA];	//Matriz para armazenar a parte Red de imagens coloridas
	unsigned char imagemG[MAXALTURA][MAXLARGURA];	//Matriz para armazenar a parte Green de imagens coloridas
	unsigned char imagemB[MAXALTURA][MAXLARGURA];	//Matriz para armazenar a parte Blue de imagens coloridas
	int largura, altura;							//Dimensoes da imagem
	char tipo[4];									//Tipo da imagem
	ifstream arqentrada;							//Arquivo que contem a imagem original
	ofstream arqsaida;								//Arquivo que contera a imagem gerada
	char comentario[200], c, tipoimg;				//Auxiliares
	int i, j, valor;								//Auxiliares

//*** MENSAGENS INICIAIS AO USUÁRIO ***//
	char nomearquivo[300]; 							//Armazena o nome do arquivo que deseja editar
	cout << "===========================\n";
	cout << "Bem vindo ao ImagemNei!\n";
	cout << "O software de edicao de imagems que une a sua imaginacao com suas fotos!\n";
	cout << "===========================\n";
	cout << "Digite o nome do arquivo, no formato (.pnm), para nosso software fazer a leitura:\n";
	cout << "Exemplos: fotolindadeperfil.pnm ou fotosorrindo.pnm\n";
	cout << "Atencao! nao esqueca o .pnm no final do nome do arquivo.\n";
	cin >> nomearquivo;
	cout << "Carregando imagem...\n";
	cout << "---------------------\n";
	//***************************//

//*** LEITURA DA IMAGEM ***//

	//*** Abertura do arquivo ***//
	arqentrada.open(nomearquivo,ios::in); //Abre arquivo para leitura
	if (!arqentrada) {
		cout << "Nao consegui abrir arquivo.pnm, verifique se digitou o .pnm no final do nome!\n";
		cout << "=====================\n";
		return 0;
	}
	//***************************//

	//*** Leitura do cabecalho ***//
	arqentrada >> tipo;		//Le o tipo de arquivo
	arqentrada.get();		//Le e descarta o \n do final da 1a. linha

	if (strcmp(tipo,"P2")==0) {
		cout << "Imagem em tons de cinza\n";
		tipoimg  = 'T';
	}
	else if (strcmp(tipo,"P3")==0) {
		cout << "Imagem colorida\n";
		tipoimg  = 'C';
	}
	else if (strcmp(tipo,"P1")==0) {
		cout << "Imagem preto e branco\n";
		cout << "Desculpe, nao trabalho com esse tipo de imagem.\n";
		cout << "=====================\n";
		arqentrada.close();
		return 0;
	}
	else if (strcmp(tipo,"P4")==0 || strcmp(tipo,"P5")==0 || strcmp(tipo,"P6")==0) {
		cout << "Imagem no formato RAW\n";
		cout << "Desculpe, nao trabalho com esse tipo de imagem.\n";
		cout << "=====================\n";
		arqentrada.close();
		return 0;
	}

	while((c = arqentrada.get()) == '#')	//Enquanto for comentario
		arqentrada.getline(comentario,200);	//Le e descarta a linha "inteira"

	arqentrada.putback(c);	//Devolve o caractere lido para a entrada, pois como
													//Nao era comentario, era o primeiro digito da largura

	arqentrada >> largura >> altura;	//Le o numero de pixels da horizontal e vertical
	cout << "Tamanho: " << largura << " x " << altura << endl;
	if (largura>MAXLARGURA) {
		cout << "Desculpe, ainda nao trabalho com imagens com mais de " << MAXLARGURA << " pixels de largura.\n";
		cout << "=====================\n";
		arqentrada.close();
		return 0;
	}
	if (altura>MAXALTURA) {
		cout << "Desculpe, ainda nao trabalho com imagens com mais de " << MAXALTURA << " pixels de altura.\n";
		cout << "=====================\n";
		arqentrada.close();
		return 0;
	}

	arqentrada >> valor;	//Valor maximo do pixel
	//****************************//


	//*** Leitura dos pixels da imagem em tons de cinza ***//
	if (tipoimg == 'T') {
		for(i=0;i<altura;i++)
			for(j=0;j<largura;j++) {
				arqentrada >> valor;
				imagem[i][j] = (unsigned char)valor;
			}
	}
	//************************************//

	//*** Leitura dos pixels da imagem colorida ***//
	if (tipoimg == 'C') {
		for(i=0;i<altura;i++)
			for(j=0;j<largura;j++) {
				arqentrada >> valor;
				imagemR[i][j] = (unsigned char)valor;
				arqentrada >> valor;
				imagemG[i][j] = (unsigned char)valor;
				arqentrada >> valor;
 				imagemB[i][j] = (unsigned char)valor;
			}
	}
	//************************************//

	arqentrada.close();  //Fecha arquivo apos a leitura

//*** FIM DA LEITURA DA IMAGEM ***//


//*** MENSAGEM DE SELEÇÃO DE AÇÕES À SEREM EFETUADAS NA IMAGEM ESCOLHIDA ***//
	char cEscolha; //Armazena o código da ação desejada pelo usuário
	cout << "Sua imagem foi carregada com sucesso!\n";
	cout << "---------------------\n";
	cout << "Digite o codigo da acao que deseja realizar na sua imagem inserida:\n";
	cout << "Acao: 					Codigo:\n";
	cout << "Clarear                            	  C\n";
	cout << "Escurecer                          	  U\n";
	cout << "Negativar				  N\n";
	cout << "Espelhar				  E\n";
	cout << "Filtro de Sobel				  S\n";
	cout << "Filtro de Realce			  R\n";
	cout << "Filtro 3D		  		  D\n";
	cout << "Tons de Cinza (Somente Coloridas)	  T\n";
	cout << "Cancelar				  X\n";
	cin >> cEscolha;
	//Caso digite um código incompativel, faz o usuário repitir o código até ser compativel com os disponibilizados
	while (cEscolha != 'C' && cEscolha != 'c' && cEscolha != 'U' && cEscolha != 'u' && cEscolha != 'N' && cEscolha != 'n' && cEscolha != 'E' && cEscolha != 'e' && cEscolha != 'D' && cEscolha != 'd' && cEscolha != 'T' && cEscolha != 't' && cEscolha != 'R' && cEscolha != 'r' && cEscolha != 'S' && cEscolha != 's' && cEscolha != 'X' && cEscolha != 'x') {
		cout << "---------------------\n";
		cout << "Ops! Codigo invalido, tente novamente.\n";
		cin >> cEscolha;
	}
	cout << "---------------------\n";

//*** TRATAMENTO DA IMAGEM ***//

	//*** Cancelar o Programa ***//
	if (cEscolha == 'X' || cEscolha == 'x') {
		cout << "Cancelando edicao da imagem....\n";
		cout << "Fechando o software....\n";
		cout << "=====================\n";
		return 0;
	}

	//*** Clareia a imagem ***//
	if (cEscolha == 'C' || cEscolha == 'c') {
		//Se a imagem for em tons de cinza
		if (tipoimg == 'T') {
			int fator;

			cout << "Voce escolheu a acao CLAREAR!\n";
			cout << "Qual o fator de clareamento (0-255) ? \n";
			cin >> fator;

			for(i = 0; i < altura; i++) {
				for(j = 0; j < largura; j++) {
					valor = (int)imagem[i][j];						//Pega o valor do pixel
					valor += fator;									//Clareia o pixel
					if (valor > 255) {								//Se der maior que 255
						valor = 255;								//Deixa branco
					}									
					imagem[i][j] = (unsigned char)valor;			//Modifica o pixel
				}
			}
		}

		//Se a imagem for colorida
		if (tipoimg == 'C') { 
			int fator;

			cout << "Voce escolheu a acao CLAREAR!\n";
			cout << "Qual o fator de clareamento (0-255) ? \n";
			cin >> fator;

			for(i = 0; i < altura; i++) {
				for(j = 0; j < largura; j++) {
					//Clareia a matriz RED
					valor = (int)imagemR[i][j];						//Pega o valor do pixel
					valor += fator;									//Clareia o pixel
					if (valor > 255) {								//Se der maior que 255
						valor = 255;								//Deixa branco
					}									
					imagemR[i][j] = (unsigned char)valor;			//Modifica o pixel
					
					//Clareia a matriz GREEN
					valor = (int)imagemG[i][j];						//Pega o valor do pixel
					valor += fator;									//Clareia o pixel
					if (valor > 255) {								//Se der maior que 255
						valor = 255;								//Deixa branco
					}									
					imagemG[i][j] = (unsigned char)valor;			//Modifica o pixel	
					
					//Clareia a matriz BLUE
					valor = (int)imagemB[i][j];						//Pega o valor do pixel
					valor += fator;									//Clareia o pixel
					if (valor > 255) {								//Se der maior que 255
						valor = 255;								//Deixa branco
					}									
					imagemB[i][j] = (unsigned char)valor;			//Modifica o pixel									
				}
			}
		}	
	}
    //*************************//

	//*** Escurece a imagem ***//
	if (cEscolha == 'U' || cEscolha == 'u') {
		//Se a imagem for em tons de cinza
		if (tipoimg == 'T') {
			int fator;

			cout << "Voce escolheu a acao ESCURECER!\n";
			cout << "Qual o fator de escurecimento (0-255) ? \n";
			cin >> fator;

			for(i = 0; i < altura; i++) {
				for(j = 0; j < largura; j++) {
					valor = (int)imagem[i][j];						//Pega o valor do pixel
					valor -= fator;									//Escurece o pixel
					if (valor < 0) {								//Se der negativo
						valor = 0;									//Deixa preto
					}									
					imagem[i][j] = (unsigned char)valor;			//Modifica o pixel
				}
			}
		}

		//Se a imagem for colorida
		if (tipoimg == 'C') { 
			int fator;

			cout << "Voce escolheu a acao ESCURECER!\n";
			cout << "Qual o fator de escurecimento (0-255) ? \n";
			cin >> fator;

			for(i = 0; i < altura; i++) {
				for(j = 0; j < largura; j++) {
					//Escurece a matriz RED
					valor = (int)imagemR[i][j];						//Pega o valor do pixel
					valor -= fator;									//Escurece o pixel
					if (valor < 0) {								//Se der negativo
						valor = 0;									//Deixa preto
					}									
					imagemR[i][j] = (unsigned char)valor;			//Modifica o pixel
					
					//Escurece a matriz GREEN
					valor = (int)imagemG[i][j];						//Pega o valor do pixel
					valor -= fator;									//Escurece o pixel
					if (valor < 0) {								//Se der negativo
						valor = 0;									//Deixa preto
					}									
					imagemG[i][j] = (unsigned char)valor;			//Modifica o pixel	
					
					//Escurece a matriz BLUE
					valor = (int)imagemB[i][j];						//Pega o valor do pixel
					valor -= fator;									//Escurece o pixel
					if (valor < 0) {								//Se der negativo
						valor = 0;									//Deixa preto
					}									
					imagemB[i][j] = (unsigned char)valor;			//Modifica o pixel										
				}
			}
		}
	}
    //*************************//

	//*** Negativa a imagem ***//
	if (cEscolha == 'N' || cEscolha == 'n') {
		//Se a imagem for em tons de cinza
		if (tipoimg == 'T') {	
			cout << "Voce escolheu a acao NEGATIVAR\n";

			for(i = 0; i < altura; i++) {
				for(j = 0; j < largura; j++) {
					valor = (int)imagem[i][j];						//Pega o valor do pixel
					valor -= 255;									//Transforma o inverso do pixel
					if (valor < 0) {								//Se der negativo
						valor = valor * -1;							//Transforma em positivo
					}									
					imagem[i][j] = (unsigned char)valor;			//Modifica o pixel
				}
			}
		}

		//Se a imagem for colorida
		if (tipoimg == 'C') { 
			cout << "Voce escolheu a acao NEGATIVAR!\n";

			for(i = 0; i < altura; i++) {
				for(j = 0; j < largura; j++) {
					//Negativa a matriz RED
					valor = (int)imagemR[i][j];						//Pega o valor do pixel
					valor -= 255;									//Transforma o inverso do pixel
					if (valor < 0) {								//Se der negativo
						valor = valor * -1;							//Transforma em positivo
					}									
					imagemR[i][j] = (unsigned char)valor;			//Modifica o pixel
					
					//Negativa a matriz GREEN
					valor = (int)imagemG[i][j];						//Pega o valor do pixel
					valor -= 255;									//Transforma o inverso do pixel
					if (valor < 0) {								//Se der negativo
						valor = valor * -1;							//Transforma em positivo
					}									
					imagemG[i][j] = (unsigned char)valor;			//Modifica o pixel
					
					//Negativa a matriz BLUE
					valor = (int)imagemB[i][j];						//Pega o valor do pixel
					valor -= 255;									//Transforma o inverso do pixel
					if (valor < 0) {								//Se der negativo
						valor = valor * -1;							//Transforma em positivo
					}									
					imagemB[i][j] = (unsigned char)valor;			//Modifica o pixel									
				}
			}
		}
	}
    //*************************//

	//*** Espelha a imagem ***//
	if (cEscolha == 'E' || cEscolha == 'e') {	
		//Se a imagem for em tons de cinza
		if (tipoimg == 'T') {
			int ultimotermo,auxiliar2;

			cout << "Voce escolheu a acao ESPELHAR!\n";

			for(i = 0; i < altura; i++) {
				ultimotermo = largura - 1; 							//Pega a quantidade de termos da linha da matriz
				for(j = 0; j < largura; j++) { 
					auxiliar2 = imagem[i][j]; 						//Armazena um valor da matriz em uma variavel auxiliar
					imagem[i][j] = imagem[i][ultimotermo]; 			//Faz a troca de valores da linha da matriz
					imagem[i][ultimotermo] = auxiliar2; 			//Faz a troca de valores da linha da matriz, com ajuda da matriz auxiliar
					ultimotermo--; 									//Retira um valor do ultimo termo
					if (ultimotermo < (largura/2 + 1)) {  			//Não é necessario fazer operações diferentes para larguaras pares ou impares, pois o contador ultimotermo vai sempre 1 valor a frente da metade da quntidade de termos da linha
						break;										//Para o programa se ultimotermo for menor que a metade da quantidade de termos da largura, para nao reeinventer os números
					}	
				}
			}
		}

		//Se a imagem for colorida
		if (tipoimg == 'C') { 
			int ultimotermo,auxiliar2;

			cout << "Voce escolheu a acao ESPELHAR!\n";

			//Espelha a matriz RED
			for(i = 0; i < altura; i++) {
				ultimotermo = largura - 1; 							//Pega a quantidade de termos da linha da matriz
				for(j = 0; j < largura; j++) { 
					auxiliar2 = imagemR[i][j]; 						//Armazena um valor da matriz em uma variavel auxiliar
					imagemR[i][j] = imagemR[i][ultimotermo]; 		//Faz a troca de valores da linha da matriz
					imagemR[i][ultimotermo] = auxiliar2; 			//Faz a troca de valores da linha da matriz, com ajuda da matriz auxiliar
					ultimotermo--; 									//Retira um valor do ultimo termo
					if (ultimotermo < (largura/2 + 1)) {  			//Não é necessario fazer operações diferentes para larguaras pares ou impares, pois o contador ultimotermo vai sempre 1 valor a frente da metade da quntidade de termos da linha
						break;										//Para o programa se ultimotermo for menor que a metade da quantidade de termos da largura, para nao reeinventer os números
					}	
				}
			}

			//Espelha a matriz GREEN
			for(i = 0; i < altura; i++) {
				ultimotermo = largura - 1; 							//Pega a quantidade de termos da linha da matriz
				for(j = 0; j < largura; j++) { 
					auxiliar2 = imagemG[i][j]; 						//Armazena um valor da matriz em uma variavel auxiliar
					imagemG[i][j] = imagemG[i][ultimotermo]; 		//Faz a troca de valores da linha da matriz
					imagemG[i][ultimotermo] = auxiliar2; 			//Faz a troca de valores da linha da matriz, com ajuda da matriz auxiliar
					ultimotermo--; 									//Retira um valor do ultimo termo
					if (ultimotermo < (largura/2 + 1)) {  			//Não é necessario fazer operações diferentes para larguaras pares ou impares, pois o contador ultimotermo vai sempre 1 valor a frente da metade da quntidade de termos da linha
						break;										//Para o programa se ultimotermo for menor que a metade da quantidade de termos da largura, para nao reeinventer os números
					}	
				}
			}

			//Espelha a matriz BLUE
			for(i = 0; i < altura; i++) {
				ultimotermo = largura - 1; 							//Pega a quantidade de termos da linha da matriz
				for(j = 0; j < largura; j++) { 
					auxiliar2 = imagemB[i][j]; 						//Armazena um valor da matriz em uma variavel auxiliar
					imagemB[i][j] = imagemB[i][ultimotermo]; 		//Faz a troca de valores da linha da matriz
					imagemB[i][ultimotermo] = auxiliar2; 			//Faz a troca de valores da linha da matriz, com ajuda da matriz auxiliar
					ultimotermo--; 									//Retira um valor do ultimo termo
					if (ultimotermo < (largura/2 + 1)) {  			//Não é necessario fazer operações diferentes para larguaras pares ou impares, pois o contador ultimotermo vai sempre 1 valor a frente da metade da quntidade de termos da linha
						break;										//Para o programa se ultimotermo for menor que a metade da quantidade de termos da largura, para nao reeinventer os números
					}	
				}
			}						
		}		
	}
    //*************************//

	//*** Aplica filtro 3D a imagem ***//
	if (cEscolha == 'D' || cEscolha == 'd') {
		//Se a imagem for em tons de cinza
		if (tipoimg == 'T') { 	
			unsigned char imagem_auxiliar[MAXALTURA][MAXLARGURA];	//Matriz auxiliar

			cout << "Voce escolheu a acao APLICAR FILTRO 3D!\n";

			for(i = 0; i < altura; i++) {
				for(j = 0; j < largura; j++) {
					imagem_auxiliar[i][j] = imagem[i][j];			//Transfere os valores da imagem para uma matriz auxiliar
				}
			}

			for(i = 0; i < altura; i++) {
				for(j = 0; j < largura; j++) {
					if (i == 0 || i == altura - 1 || j == 0 || j == largura - 1) { //Não permite aplicar o filtro nos pixeis que contornam a imagem
						continue;
					}						
					valor = (int)((imagem_auxiliar[i-1][j-1] * -2) + (imagem_auxiliar[i+1][j+1] * 2) + (imagem_auxiliar[i][j-1] * -1) + (imagem_auxiliar[i][j+1] * -1) + (imagem_auxiliar[i][j] * 3));
					if (valor < 0) {								//Se der negativo
						valor = 0;									//Deixa preto
					}
					if (valor > 255) {								//Se der maior que 255
						valor = 255;								//Deixa branco
					}				
					imagem[i][j] = (unsigned char)valor;			//Modifica o pixel	
				}
			}
		}

		//Se a imagem for colorida
		if (tipoimg == 'C') { 
			unsigned char imagemR_auxiliar[MAXALTURA][MAXLARGURA];  //Matriz auxiliar RED
			unsigned char imagemG_auxiliar[MAXALTURA][MAXLARGURA];	//Matriz auxiliar GREEN
			unsigned char imagemB_auxiliar[MAXALTURA][MAXLARGURA];	//Matriz auxiliar BLUE

			cout << "Voce escolheu a acao APLICAR FILTRO 3D!\n";

			for(i = 0; i < altura; i++) {
				for(j = 0; j < largura; j++) {
					imagemR_auxiliar[i][j] = imagemR[i][j];         //Transfere os valores da imagem para uma matriz auxiliar
					imagemG_auxiliar[i][j] = imagemG[i][j];			//Transfere os valores da imagem para uma matriz auxiliar
					imagemB_auxiliar[i][j] = imagemB[i][j];			//Transfere os valores da imagem para uma matriz auxiliar	
				}
			}

			//Aplica o filtro 3D na matriz RED
			for(i = 0; i < altura; i++) {
				for(j = 0; j < largura; j++) {
					if (i == 0 || i == altura - 1 || j == 0 || j == largura - 1) { //Não permite aplicar o filtro nos pixeis que contornam a imagem
						continue;
					}						
					valor = (int)((imagemR_auxiliar[i-1][j-1] * -2) + (imagemR_auxiliar[i+1][j+1] * 2) + (imagemR_auxiliar[i][j-1] * -1) + (imagemR_auxiliar[i][j+1] * -1) + (imagemR_auxiliar[i][j] * 3));
					if (valor < 0) {								//Se der negativo
						valor = 0;									//Deixa preto
					}
					if (valor > 255) {								//Se der maior que 255
						valor = 255;								//Deixa branco
					}				
					imagemR[i][j] = (unsigned char)valor;			//Modifica o pixel	
				}
			}

			//Aplica o filtro 3D na matriz GREEN
			for(i = 0; i < altura; i++) {
				for(j = 0; j < largura; j++) {
					if (i == 0 || i == altura - 1 || j == 0 || j == largura - 1) { //Não permite aplicar o filtro nos pixeis que contornam a imagem
						continue;
					}						
					valor = (int)((imagemG_auxiliar[i-1][j-1] * -2) + (imagemG_auxiliar[i+1][j+1] * 2) + (imagemG_auxiliar[i][j-1] * -1) + (imagemG_auxiliar[i][j+1] * -1) + (imagemG_auxiliar[i][j] * 3));
					if (valor < 0) {								//Se der negativo
						valor = 0;									//Deixa preto
					}
					if (valor > 255) {								//Se der maior que 255
						valor = 255;								//Deixa branco
					}				
					imagemG[i][j] = (unsigned char)valor;			//Modifica o pixel	
				}
			}

			//Aplica o filtro 3D na matriz BLUE
			for(i = 0; i < altura; i++) {
				for(j = 0; j < largura; j++) {
					if (i == 0 || i == altura - 1 || j == 0 || j == largura - 1) { //Não permite aplicar o filtro nos pixeis que contornam a imagem
						continue;
					}						
					valor = (int)((imagemB_auxiliar[i-1][j-1] * -2) + (imagemB_auxiliar[i+1][j+1] * 2) + (imagemB_auxiliar[i][j-1] * -1) + (imagemB_auxiliar[i][j+1] * -1) + (imagemB_auxiliar[i][j] * 3));
					if (valor < 0) {								//Se der negativo
						valor = 0;									//Deixa preto
					}
					if (valor > 255) {								//Se der maior que 255
						valor = 255;								//Deixa branco
					}				
					imagemB[i][j] = (unsigned char)valor;			//Modifica o pixel	
				}
			}						
		}		
	}
    //*************************//

	//*** Aplica tons de cinza na imagem colorida ***//
	if (cEscolha == 'T' || cEscolha == 't') {	
		//Se a imagem for em tons de cinza
		if (tipoimg == 'T') { 
			cout << "Ops, nao fazemos isso em imagens em tons de cinza, uma vez que ela ja esta em tons de cinza!\n";
			cout << "===================\n";
			return 0;
		}

		//Se a imagem for colorida
		if (tipoimg == 'C') { 
			cout << "Voce escolheu a acao TRANSFORMAR IMAGEM COLORIDA EM TONS DE CINZA!\n";

			for(i = 0; i < altura; i++) {
				for(j = 0; j < largura; j++) {
					valor = (int) ((imagemR[i][j] + imagemG[i][j] + imagemB[i][j]) / 3); //Faz a media dos 3 valores das matrizes RED, GREEN, BLUE
					if (valor < 0) {								//Se der negativo
						valor = 0;									//Deixa preto
					}
					if (valor > 255) {								//Se der maior que 255
						valor = 255;								//Deixa branco
					}
					imagemR[i][j] = (unsigned char)valor;			//Modifica o pixel	
					imagemG[i][j] = (unsigned char)valor;			//Modifica o pixel	
					imagemB[i][j] = (unsigned char)valor;			//Modifica o pixel	
				}
			}						
		}			
	}
    //*************************//

	//*** Aplica filtro de realce na imagem ***//
	if (cEscolha == 'R' || cEscolha == 'r') {
		//Se a imagem for em tons de cinza
		if (tipoimg == 'T') { 	
			unsigned char imagem_auxiliar[MAXALTURA][MAXLARGURA];	//Matriz auxiliar 

			cout << "Voce escolheu a acao APLICAR FILTRO REALCE!\n";

			for(i = 0; i < altura; i++) {
				for(j = 0; j < largura; j++) {
					imagem_auxiliar[i][j] = imagem[i][j];			//Transfere os valores da imagem para uma matriz auxiliar
				}
			}

			for(i = 0; i < altura; i++) {
				for(j = 0; j < largura; j++) {
					if (i == 0 || i == altura - 1 || j == 0 || j == largura - 1) { //Não permite aplicar o filtro nos pixeis que contornam a imagem
						continue;
					}
					valor = (int)((imagem_auxiliar[i-1][j] * -1) + (imagem_auxiliar[i][j-1] * -1) + (imagem_auxiliar[i+1][j] * -1) + (imagem_auxiliar[i][j+1] * -1) + (imagem_auxiliar[i][j] * 5));
					if (valor < 0) {								//Se der negativo
						valor = 0;									//Deixa preto
					}
					if (valor > 255) {								//Se der maior que 255
						valor = 255;								//Deixa branco
					}				
					imagem[i][j] = (unsigned char)valor;			//Modifica o pixel
				}
			}
		}

		//Se a imagem for em colorida
		if (tipoimg == 'C') { 
			unsigned char imagemR_auxiliar[MAXALTURA][MAXLARGURA]; //Matriz auxiliar RED
			unsigned char imagemG_auxiliar[MAXALTURA][MAXLARGURA]; //Matriz auxiliar GREEN
			unsigned char imagemB_auxiliar[MAXALTURA][MAXLARGURA]; //Matriz auxiliar BLUE	

			cout << "Voce escolheu a acao APLICAR FILTRO REALCE!\n";

			for(i = 0; i < altura; i++) {
				for(j = 0; j < largura; j++) {
					imagemR_auxiliar[i][j] = imagemR[i][j];      	//Transfere os valores da imagem para uma matriz auxiliar RED
					imagemG_auxiliar[i][j] = imagemG[i][j];			//Transfere os valores da imagem para uma matriz auxiliar GREEN
					imagemB_auxiliar[i][j] = imagemB[i][j];			//Transfere os valores da imagem para uma matriz auxiliar BLUE
				}
			}

			//Aplica o filtro realce na matriz RED
			for(i = 0; i < altura; i++) {
				for(j = 0; j < largura; j++) {
					if (i == 0 || i == altura - 1 || j == 0 || j == largura - 1) { //Não permite aplicar o filtro nos pixeis que contornam a imagem
						continue;
					}					
					valor = (int)((imagemR_auxiliar[i-1][j] * -1) + (imagemR_auxiliar[i][j-1] * -1) + (imagemR_auxiliar[i+1][j] * -1) + (imagemR_auxiliar[i][j+1] * -1) + (imagemR_auxiliar[i][j] * 5));
					if (valor < 0) {								//Se der negativo
						valor = 0;									//Deixa preto
					}
					if (valor > 255) {								//Se der maior que 255
						valor = 255;								//Deixa branco
					}				
					imagemR[i][j] = (unsigned char)valor;			//Modifica o pixel
				}
			}

			//Aplica o filtro realce na matriz GREEN
			for(i = 0; i < altura; i++) {
				for(j = 0; j < largura; j++) {
					if (i == 0 || i == altura - 1 || j == 0 || j == largura - 1) { //Não permite aplicar o filtro nos pixeis que contornam a imagem
						continue;
					}					
					valor = (int)((imagemG_auxiliar[i-1][j] * -1) + (imagemG_auxiliar[i][j-1] * -1) + (imagemG_auxiliar[i+1][j] * -1) + (imagemG_auxiliar[i][j+1] * -1) + (imagemG_auxiliar[i][j] * 5));
					if (valor < 0) {								//Se der negativo
						valor = 0;									//Deixa preto
					}
					if (valor > 255) {								//Se der maior que 255
						valor = 255;								//Deixa branco
					}				
					imagemG[i][j] = (unsigned char)valor;			//Modifica o pixel
				}
			}

			//Aplica o filtro realce na matriz BLUE
			for(i = 0; i < altura; i++) {
				for(j = 0; j < largura; j++) {
					if (i == 0 || i == altura - 1 || j == 0 || j == largura - 1) { //Não permite aplicar o filtro nos pixeis que contornam a imagem
						continue;
					}					
					valor = (int)((imagemB_auxiliar[i-1][j] * -1) + (imagemB_auxiliar[i][j-1] * -1) + (imagemB_auxiliar[i+1][j] * -1) + (imagemB_auxiliar[i][j+1] * -1) + (imagemB_auxiliar[i][j] * 5));
					if (valor < 0) {								//Se der negativo
						valor = 0;									//Deixa preto
					}
					if (valor > 255) {								//Se der maior que 255
						valor = 255;								//Deixa branco
					}				
					imagemB[i][j] = (unsigned char)valor;			//Modifica o pixel
				}
			}						
		}		
	}
    //*************************//

	//*** Aplica filtro de sobel na imagem ***//
	if (cEscolha == 'S' || cEscolha == 's') {
		//Se a imagem for em tons de cinza
		if (tipoimg == 'T') { 
			unsigned char imagem_auxiliar1a[MAXALTURA][MAXLARGURA]; //Primeira matriz auxiliar da primeira parte do filtro
			unsigned char imagem_auxiliar1b[MAXALTURA][MAXLARGURA];	//Primeira matriz auxiliar da Segunda parte do filtro
			unsigned char imagem_auxiliar2a[MAXALTURA][MAXLARGURA];	//Segunda matriz auxiliar da primeira parte do filtro
			unsigned char imagem_auxiliar2b[MAXALTURA][MAXLARGURA];	//Segunda matriz auxiliar da Segunda parte do filtro

			cout << "Voce escolheu a acao APLICAR FILTRO SOBEL!\n";
			
			for(i = 0; i < altura; i++) {
				for(j = 0; j < largura; j++) {
					imagem_auxiliar1a[i][j] = imagem[i][j];			//Transfere os valores da imagem para uma matriz auxiliar da primeira parte
					imagem_auxiliar2a[i][j] = imagem[i][j];			//Transfere os valores da imagem para uma matriz auxiliar da primeira parte
				}
			}

			//Aplica a primeira matriz do filtro
			for(i = 0; i < altura; i++) {
				for(j = 0; j < largura; j++) {					
					valor = (int) ((imagem_auxiliar1a[i-1][j-1] * 1) + (imagem_auxiliar1a[i-1][j] * 2) + (imagem_auxiliar1a[i-1][j+1] * 1) + (imagem_auxiliar1a[i+1][j-1] * -1) + (imagem_auxiliar1a[i+1][j] * -2) + (imagem_auxiliar1a[i+1][j+1] * -1));
					if (valor < 0) {								//Se der negativo
						valor = 0;									//Deixa preto
					}
					if (valor > 255) {								//Se der maior que 255
						valor = 255;								//Deixa branco
					}
					imagem_auxiliar1b[i][j] = (unsigned char)valor;	//Modifica o pixel
				}
			}

			//Aplica a segunda matriz do filtro
			for(i = 0; i < altura; i++) {
				for(j = 0; j < largura; j++) {					
					valor = (int) ((imagem_auxiliar2a[i-1][j-1] * 1) + (imagem_auxiliar2a[i-1][j+1] * -1) + (imagem_auxiliar2a[i][j-1] * 2) + (imagem_auxiliar2a[i][j+1] * -2) + (imagem_auxiliar2a[i+1][j-1] * 1) + (imagem_auxiliar2a[i+1][j+1] * -1));
					if (valor < 0) {								//Se der negativo
						valor = 0;									//Deixa preto
					}
					if (valor > 255) {								//Se der maior que 255
						valor = 255;								//Deixa branco
					}
					imagem_auxiliar2b[i][j] = (unsigned char) valor;	//Modifica o pixel
				}
			}				

			//Encontra o maior termo entre a primeira e segunda matriz do filtro
			for(i = 0; i < altura; i++) {
				for(j = 0; j < largura; j++) {						
					if (imagem_auxiliar1b[i][j] > imagem_auxiliar2b[i][j]) {
						valor = imagem_auxiliar1b[i][j];
					}
					else {
						valor = imagem_auxiliar2b[i][j];
					}
					imagem[i][j] = (unsigned char) valor;				//Modifica o pixel
				}
			}
		}

		//Se a imagem for colorida
		if (tipoimg == 'C') { 
			unsigned char imagemR_auxiliar1a[MAXALTURA][MAXLARGURA];	//Primeira matriz RED auxiliar da primeira parte do filtro
			unsigned char imagemR_auxiliar1b[MAXALTURA][MAXLARGURA];	//Primeira matriz RED auxiliar da Segunda parte do filtro
			unsigned char imagemR_auxiliar2a[MAXALTURA][MAXLARGURA];	//Segunda matriz RED auxiliar da primeira parte do filtro
			unsigned char imagemR_auxiliar2b[MAXALTURA][MAXLARGURA];	//Segunda matriz RED auxiliar da Segunda parte do filtro
			unsigned char imagemG_auxiliar1a[MAXALTURA][MAXLARGURA];	//Primeira matriz GREEN auxiliar da primeira parte do filtro
			unsigned char imagemG_auxiliar1b[MAXALTURA][MAXLARGURA];	//Primeira matriz GREEN auxiliar da Segunda parte do filtro
			unsigned char imagemG_auxiliar2a[MAXALTURA][MAXLARGURA];	//Segunda matriz GREEN auxiliar da primeira parte do filtro
			unsigned char imagemG_auxiliar2b[MAXALTURA][MAXLARGURA];	//Segunda matriz GREEN auxiliar da Segunda parte do filtro
			unsigned char imagemB_auxiliar1a[MAXALTURA][MAXLARGURA];	//Primeira matriz BLUE auxiliar da primeira parte do filtro
			unsigned char imagemB_auxiliar1b[MAXALTURA][MAXLARGURA];	//Primeira matriz BLUE auxiliar da Segunda parte do filtro
			unsigned char imagemB_auxiliar2a[MAXALTURA][MAXLARGURA];	//Segunda matriz BLUE auxiliar da primeira parte do filtro
			unsigned char imagemB_auxiliar2b[MAXALTURA][MAXLARGURA];	//Segunda matriz BLUE auxiliar da Segunda parte do filtro					

			cout << "Voce escolheu a acao APLICAR FILTRO SOBEL!\n";
			
			for(i = 0; i < altura; i++) {
				for(j = 0; j < largura; j++) {
					imagemR_auxiliar1a[i][j] = imagemR[i][j];			//Transfere os valores da imagem para uma matriz RED auxiliar da primeira parte
					imagemR_auxiliar2a[i][j] = imagemR[i][j];			//Transfere os valores da imagem para uma matriz RED auxiliar da primeira parte								
				}
			}

			for(i = 0; i < altura; i++) {
				for(j = 0; j < largura; j++) {
					imagemG_auxiliar1a[i][j] = imagemG[i][j];			//Transfere os valores da imagem para uma matriz GREEN auxiliar da primeira parte
					imagemG_auxiliar2a[i][j] = imagemG[i][j];			//Transfere os valores da imagem para uma matriz GREEN auxiliar da primeira parte				
				}
			}

			for(i = 0; i < altura; i++) {
				for(j = 0; j < largura; j++) {
					imagemB_auxiliar1a[i][j] = imagemB[i][j];			//Transfere os valores da imagem para uma matriz BLUE auxiliar da primeira parte
					imagemB_auxiliar2a[i][j] = imagemB[i][j];			//Transfere os valores da imagem para uma matriz BLUE auxiliar da primeira parte								
				}
			}

			//Aplica sobel na matrix RED
			//Aplica a primeira matriz do filtro
			for(i = 0; i < altura; i++) {
				for(j = 0; j < largura; j++) {						
					valor = (int) ((imagemR_auxiliar1a[i-1][j-1] * 1) + (imagemR_auxiliar1a[i-1][j] * 2) + (imagemR_auxiliar1a[i-1][j+1] * 1) + (imagemR_auxiliar1a[i+1][j-1] * -1) + (imagemR_auxiliar1a[i+1][j] * -2) + (imagemR_auxiliar1a[i+1][j+1] * -1));
					if (valor < 0) {									//Se der negativo
						valor = 0;										//Deixa preto
					}
					if (valor > 255) {									//Se der maior que 255
						valor = 255;									//Deixa branco
					}
					imagemR_auxiliar1b[i][j] = (unsigned char)valor;	//Modifica o pixel
				}
			}

			//Aplica a segunda matriz do filtro
			for(i = 0; i < altura; i++) {
				for(j = 0; j < largura; j++) {						
					valor = (int) ((imagemR_auxiliar2a[i-1][j-1] * 1) + (imagemR_auxiliar2a[i-1][j+1] * -1) + (imagemR_auxiliar2a[i][j-1] * 2) + (imagemR_auxiliar2a[i][j+1] * -2) + (imagemR_auxiliar2a[i+1][j-1] * 1) + (imagemR_auxiliar2a[i+1][j+1] * -1));
					if (valor < 0) {									//Se der negativo
						valor = 0;										//Deixa preto
					}
					if (valor > 255) {									//Se der maior que 255
						valor = 255;									//Deixa branco
					}
					imagemR_auxiliar2b[i][j] = (unsigned char) valor;	//Modifica o pixel
				}
			}				

			//Encontra o maior termo entre a primeira e segunda matriz do filtro
			for(i = 0; i < altura; i++) {
				for(j = 0; j < largura; j++) {
					if (imagemR_auxiliar1b[i][j] > imagemR_auxiliar2b[i][j]) {
						valor = imagemR_auxiliar1b[i][j];
					}
					else {
						valor = imagemR_auxiliar2b[i][j];
					}
					imagemR[i][j] = (unsigned char) valor;				//Modifica o pixel
				}
			}

			//Aplica sobel na matrix GREEN
			//Aplica a primeira matriz do filtro
			for(i = 0; i < altura; i++) {
				for(j = 0; j < largura; j++) {						
					valor = (int) ((imagemG_auxiliar1a[i-1][j-1] * 1) + (imagemG_auxiliar1a[i-1][j] * 2) + (imagemG_auxiliar1a[i-1][j+1] * 1) + (imagemG_auxiliar1a[i+1][j-1] * -1) + (imagemG_auxiliar1a[i+1][j] * -2) + (imagemG_auxiliar1a[i+1][j+1] * -1));
					if (valor < 0) {									//Se der negativo
						valor = 0;										//Deixa preto
					}
					if (valor > 255) {									//Se der maior que 255
						valor = 255;									//Deixa branco
					}
					imagemG_auxiliar1b[i][j] = (unsigned char)valor;	//Modifica o pixel
				}
			}

			//Aplica a segunda matriz do filtro
			for(i = 0; i < altura; i++) {
				for(j = 0; j < largura; j++) {						
					valor = (int) ((imagemG_auxiliar2a[i-1][j-1] * 1) + (imagemG_auxiliar2a[i-1][j+1] * -1) + (imagemG_auxiliar2a[i][j-1] * 2) + (imagemG_auxiliar2a[i][j+1] * -2) + (imagemG_auxiliar2a[i+1][j-1] * 1) + (imagemG_auxiliar2a[i+1][j+1] * -1));
					if (valor < 0) {									//Se der negativo
						valor = 0;										//Deixa preto
					}
					if (valor > 255) {									//Se der maior que 255
						valor = 255;									//Deixa branco
					}
					imagemG_auxiliar2b[i][j] = (unsigned char) valor;	//Modifica o pixel
				}
			}				

			//Encontra o maior termo entre a primeira e segunda matriz do filtro
			for(i = 0; i < altura; i++) {
				for(j = 0; j < largura; j++) {
					if (imagemG_auxiliar1b[i][j] > imagemG_auxiliar2b[i][j]) {
						valor = imagemG_auxiliar1b[i][j];
					}
					else {
						valor = imagemG_auxiliar2b[i][j];
					}
					imagemG[i][j] = (unsigned char) valor;				//Modifica o pixel
				}
			}

			//Aplica sobel na matrix BLUE
			//Aplica a primeira matriz do filtro
			for(i = 0; i < altura; i++) {
				for(j = 0; j < largura; j++) {						
					valor = (int) ((imagemB_auxiliar1a[i-1][j-1] * 1) + (imagemB_auxiliar1a[i-1][j] * 2) + (imagemB_auxiliar1a[i-1][j+1] * 1) + (imagemB_auxiliar1a[i+1][j-1] * -1) + (imagemB_auxiliar1a[i+1][j] * -2) + (imagemB_auxiliar1a[i+1][j+1] * -1));
					if (valor < 0) {									//Se der negativo
						valor = 0;										//Deixa preto
					}
					if (valor > 255) {									//Se der maior que 255
						valor = 255;									//Deixa branco
					}
					imagemB_auxiliar1b[i][j] = (unsigned char)valor;	//Modifica o pixel
				}
			}

			//Aplica a segunda matriz do filtro
			for(i = 0; i < altura; i++) {
				for(j = 0; j < largura; j++) {						
					valor = (int) ((imagemB_auxiliar2a[i-1][j-1] * 1) + (imagemB_auxiliar2a[i-1][j+1] * -1) + (imagemB_auxiliar2a[i][j-1] * 2) + (imagemB_auxiliar2a[i][j+1] * -2) + (imagemB_auxiliar2a[i+1][j-1] * 1) + (imagemB_auxiliar2a[i+1][j+1] * -1));
					if (valor < 0) {									//Se der negativo
						valor = 0;										//Deixa preto
					}
					if (valor > 255) {									//Se der maior que 255
						valor = 255;									//Deixa branco
					}
					imagemB_auxiliar2b[i][j] = (unsigned char) valor;	//Modifica o pixel
				}
			}				

			//Encontra o maior termo entre a primeira e segunda matriz do filtro
			for(i = 0; i < altura; i++) {
				for(j = 0; j < largura; j++) {
					if (imagemB_auxiliar1b[i][j] > imagemB_auxiliar2b[i][j]) {
						valor = imagemB_auxiliar1b[i][j];
					}
					else {
						valor = imagemB_auxiliar2b[i][j];
					}
					imagemB[i][j] = (unsigned char) valor;				//Modifica o pixel
				}
			}						
		}	
	}
    //*************************//

//*** FIM DO TRATAMENTO DA IMAGEM ***//



//*** GRAVACAO DA IMAGEM ***//
//inicialmente nao sera necessario entender nem mudar nada nesta parte

	//*** Grava a nova imagem ***//
	char nomearquivofinal[300];											//Armazena o nome do arquivo que deseja salvar
	cout << "---------------------\n";
	cout << "Digite o nome da nova imagem gerada, para ela ser salva: \n";
	cout << "Exemplos: fotolindadeperfileditada.pnm ou fotosorrindoeditada.pnm\n";
	cout << "Atencao! nao esqueca o .pnm no final do nome do arquivo.\n";
	cin >> nomearquivofinal;
	cout << "Salvando imagem...\n";
	arqsaida.open(nomearquivofinal,ios::out);							//Abre arquivo para escrita
	if (!arqsaida) {
		cout << "Nao consegui criar novaimagem.pnm\n";
		cout << "=====================\n";
		return 0;
	}

	//Se a imagem for em tons de cinza, executa esses passos
	if (tipoimg == 'T') { 
		arqsaida << tipo << endl;										//Tipo
		arqsaida << "# INF110\n";										//Comentario
		arqsaida << largura << " " << altura;							//Dimensoes
		arqsaida << " " << 255 << endl;									//Maior valor
		for(i=0;i<altura;i++)
			for(j=0;j<largura;j++)
				arqsaida << (int)imagem[i][j] << endl;					//Pixels
		arqsaida.close();												//Fecha o arquivo
	}

	//Se a imagem for colorida, executa esses passos
	if (tipoimg == 'C') { 
		arqsaida << tipo << endl;										//Tipo
		arqsaida << "# INF110\n";										//Comentario
		arqsaida << largura << " " << altura;							//Dimensoes
		arqsaida << " " << 255 << endl;									//Maior valor
		for(i=0;i<altura;i++)
			for(j=0;j<largura;j++) {
				arqsaida << (int)imagemR[i][j] << endl;					//Pixels RED
				arqsaida << (int)imagemG[i][j] << endl;					//Pixels GREEN
				arqsaida << (int)imagemB[i][j] << endl;					//Pixels BLUE
			}
		arqsaida.close();												//Fecha o arquivo
	}		
	//***************************//

//*** FIM DA GRAVACAO DA IMAGEM ***//
	cout << "---------------------\n";
	cout << "Imagem " << nomearquivofinal << " salva com sucesso!\n";
	cout << "=====================\n";

	return 0;
}
