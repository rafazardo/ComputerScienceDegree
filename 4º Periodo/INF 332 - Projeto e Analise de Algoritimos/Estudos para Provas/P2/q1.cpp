/* Questao 1 - Divisao e Consquista
- A ideia, eh pegar o meio do vetor, e verificar seu adjacentes, caso nao for os adjancentes, deve-se verificar qual lado o esta o valor que esta
faltando e em seguida fazer o find para o lado, e repetir o algoritimo. Caso chegue igual a 1, siginifca que o valor que falta e igual o valor
da posicao que falta do container menor o valor que constante
*/

#include <iostream>
using namespace std;

int find(int container[], int inicio, int fim, int sub) {

    if (fim - inicio == 1) return container[fim] - sub; // Se tiver somente 1 elemento na DC

    int meio = ((inicio + fim) / 2) - 1;

    if (container[meio] - container[meio-1] != sub) return container[meio]-sub;  // Verifica elemento da esquerda
    if (container[meio] - container[meio+1] != sub) return container[meio]+sub; // Verifica elemento da direita

    if (container[meio] - container[inicio] != (meio - inicio) * sub) find(container, inicio, meio - 1, sub); // Verifica o elemento que falta esta na esq
    else find(container, meio + 1, fim, sub);
}

int main() {

    int n, valor;

    cin >> n;

    int container[n];

    for (int i = 0; i < n; i++) {
        cin >> valor;
        container[i] = valor;
    }

    int sub = (container[n-1] - container[0])/n;

    std::cout << "O elemento que falta eh: " << find(container, 0, n - 1, sub) << std::endl;


    return 0;
}