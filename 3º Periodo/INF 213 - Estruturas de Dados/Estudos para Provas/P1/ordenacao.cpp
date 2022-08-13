#include <iostream>
using namespace std;

// Metodo BubbleSort

// Explicacao: Compara elementos vizinhos para ver se estao ordenados, caso contrario faz a troca, mandando o maior pro final
// Complexidade (Pior caso): O(Nˆ2) 
// Complexidade (Melhor caso): O(N) - ja estao ordenados os dados
// OBS: Instavel, IN-Place e nao recomendavel para muitos dados

void bubbleSortIterativo(int array[], int size) {

    for (int n = 0; n < size - 1; n++) { // IMPORTANTE: nao é necessario ir ate o ultimo elemnto, por isso o -1 no final
        for (int k = 0; k < size - 1; k++) { // IMPORTANTE: nao é necessario ir ate o ultimo elemnto, por isso o -1 no final
            if (array[k] > array[k+1]) { // IMPORTANTE: o que faz ele ser instavel é o >, se fosse >= deixaria de ser instavel
                swap(array[k], array[k+1]);
            }
        }
    }

}

void bubbleSortRecursivo(int array[], int size) { // OBS: A ideia é deixar recursivo o primeiro for

    if (size == 1) { // IMPORTANTE: o primeiro for é substituido, criando a recursividade, de decrementar o tamanho do array até um
        return;
    }

    int qntdTrocas = 0;

    // IMPORTANTE: o segundo for continua sendo deixado
    for (int k = 0; k < size - 1; k++) { // IMPORTANTE: nao é necessario ir ate o ultimo elemnto, por isso o -1 no final
        if (array[k] > array[k+1]) { // IMPORTANTE: o que faz ele ser instavel é o >, se fosse >= deixaria de ser instavel
            swap(array[k], array[k+1]);
            qntdTrocas++;
        }
    }

    if (qntdTrocas == 0) { // IMPORTANTE: se nao realizou nenhuma troca, e por que o algoritimo ja esta ordenado, e podemos para-lo
        return;
    }    

    bubbleSortRecursivo(array,size-1); // IMPORTANTE: o ultimo elemnto ja esta fixo, entao nao precisamos mais dele

}

// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

// Metodo Selection Sort

// Explicacao: Faz interacoes para os menores elementos e leva eles para as primeiras posicoes
// Complexidade (Pior caso): O(Nˆ2) 
// Complexidade (Melhor caso): O(N) - ja estao ordenados os dados
// OBS: Nao instavel, IN-Place e nao recomendavel para muitos dados
// OBS: Nao instavel, pois [8,7,4,4], ele vai pegar o ultimo 4 e botar primeiro

void selectionSortIterativo(int array[], int size) {

    for (int i = 0; i < size - 1; i++) { 
 
        int posMenor = i; // IMPORTANTE: a posicao menor sempre vai ser a anterior

        for (int n = i + 1; n < size; n++) { // IMPORTANTE: ele vai verificar os proximos, depois de colocar o menor antes
            if (array[n] < array[posMenor]) {
                posMenor = n; // IMPORTANTE: queremos encontrar a posicao do menor 
            }
        }

        swap(array[i], array[posMenor]);

        // Para deixar estavel, retirando o swap
        // int key = array[posMenor];
        // while (posMenor > i) {
        //     array[posMenor] = array[posMenor - 1];
        //     posMenor--;
        // }
        // array[i] = key;
    }
}

void selectionSortRecursive(int array[], int size) { // OBS: A ideia é deixar recursivo o primeiro for

    if (size == 1) { // IMPORTANTE: forma alternativa de substituir o for externo
        return;
    }

    selectionSortRecursive(array, size - 1); // IMPORTANTE: ele vai ate 1 (onde seria o int k = 1 do for) e depois volta para 2,3,4,5,6
 
    int posMenor = size; // IMPORTANTE: a posicao menor sempre vai ser a anterior

    for (int n = size + 1; n < size; n++) { // IMPORTANTE: ele vai verificar os proximos, depois de colocar o menor antes
        if (array[n] < array[posMenor]) {
            posMenor = n; // IMPORTANTE: queremos encontrar a posicao do menor 
        }
    }

    swap(array[size], array[posMenor]);
    
}

// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

// Metodo Inserction Sort

// Explicacao: Pega uma carta, e ordena todas as outras atras dela, e ela mesma, como se tivesse organizando baralho
// Complexidade (Pior caso): O(nˆ2) - quandos os elemtos do vetor estao em ordem descrente
// Complexidade (Melhor caso): O(n) - quando ja estao ordenados
// OBS: Instavel, IN-Place e nao recomendavel para muitos dados

void inserctionSortIterativo(int array[], int size) {

    for (int i = 1; i < size; i++) { // IMPORTANTE: comecar do 1 por que o primeiro item ja e considera ordenado
        int k = i; // IMPORTANTE: salvamos a posicao da carta, para poder compara-la com as anteriores
        while (k > 0) { // IMPORTANTE: deve passar da carta que segura, ate a primeira cara
            if (array[k] < array[k-1]) { // IMPORTANTE: se a carta de tras for menor, trocar com ela
                swap(array[k],array[k-1]);
            }
            k--;
        }
    }

}

void inserctionSortRecursivo(int array[], int size) {

    // IMPORTANTE: forma alternativa de substituir o for externo
    if (size == 1) {
        return;
    }

    inserctionSortRecursivo(array, size - 1); // IMPORTANTE: ele vai ate 1 (onde seria o int k = 1 do for) e depois volta para 2,3,4,5,6

    int k = size; // IMPORTANTE: salvamos a posicao da carta, para poder compara-la com as anteriores
    while (k > 0) { // IMPORTANTE: deve passar da carta que segura, ate a primeira cara
        if (array[k] < array[k-1]) { // IMPORTANTE: se a carta de tras for menor, trocar com ela
            swap(array[k],array[k-1]);
        }
        k--;
    }

}

// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

// Metodo MergeSort

// Explicacao: Divide o array no meio e depois junta ele de forma ordenada
// Complexidade (Pior caso): O(n*log(n)) 
// Complexidade (Melhor caso): O(n*log(n))
// OBS: Instavel, nao é IN-Place (gasta O(n) de memoria) e recomendavel para muitos dados

void merge(int array[], int begin, int meio, int end) { // Funcao auxiliar

    int tamanhoArray = end - begin;

    int beginAux = begin; //cursor 1
    int meioAux = meio; //cursor 2
    int k = 0; //cursor para aux

    int *arrayAux = new int[tamanhoArray];
    
    while (beginAux < meio && meioAux < end) { // Ordena um lado do array

        if (array[beginAux] <= array[meioAux]) {
            arrayAux[k++] = array[beginAux++];
        }
        else {
            arrayAux[k++] = array[meioAux++];
        }
    }

    while (beginAux < meio) { // Se o lado que sobrou foi o esquerdo, adiciona o resto no array suporte
        arrayAux[k++] = array[beginAux++];
    }

    while(meioAux < end) { // Se o array que sobrou foi o direito, adiciona o resto no array suporte
        arrayAux[k++] = array[meioAux++];
    }


    for(k = 0; k < tamanhoArray; k++) {
        array[begin + k] = arrayAux[k];   
    } 

    delete []arrayAux;

}

void mergeSortIterativo(int array[], int size) {

    int meio;
    int right_end;
    
    for (int curr_size = 1; curr_size <= size ; curr_size = 2 * curr_size) {
       for (int left_start = 0; left_start < size ; left_start += 2 * curr_size) {

           if ( (left_start + curr_size ) < size  ) {
               meio = (left_start + curr_size );
           }
           else {
               meio = size;
           }

           if ( (left_start + 2 * curr_size ) < size) {
               right_end = (left_start + 2 * curr_size);
           }
           else {
               right_end = size;
           } 

           merge(array, left_start, meio, right_end);
       }
   }
}

void mergeSortRecursivo(int array[], int begin, int end) {
    
    int meio = (begin + end) / 2;

    if (begin < end - 1) {
        mergeSortRecursivo(array, begin, meio); // IMPORTANTE: devide pela esquerda
        mergeSortRecursivo(array, meio, end); // IMPORTANTE: devide pela direta
        merge(array, begin, meio, end); // IMPORTANTE: junta os itens divididos
    } 

}

void mergeSortRecursivo(int array[], int size) { // Funcao para passar begin e end
    mergeSortRecursivo(array, 0, size); // IMPORTANTE: passa o begin e end
}

// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

// Metodo QuickSort

// Explicacao: Pegar um valor K, colocar todos menores que k na esquerda, e todos maiores que k na direita, k ficara no meio e sera ordenado
// Complexidade (Pior caso): O(Nˆ2) - ocorre quando o elemento pivô divide a lista de forma desbalanceada
// Complexidade (Melhor caso): O(n*log(n))
// OBS: Nao instavel, IN-Place e recomendavel para muitos dados

int particiona(int array[], int begin, int end, int pivo) {

    int valorPivo = array[pivo];
    int antes = begin; // IMPORTANTE: ao acharmos um elemento menor do que o pivo, vamos coloca-lo na posicao "pos"

    swap(array[pivo], array[end-1]); //IMPORTANTE: colocamos o pivo temporariamente na ultima posição
    
    for(int i = begin; i < end-1; i++) {  // IMPORTANTE: a ideia é andar com duas variaveis diferentes, uma pra itens antes e outro pro array
        if (array[i] < valorPivo) {
            swap(array[antes], array[i]); 
            antes++;  
        }
    }
    
    swap(array[antes],array[end-1]); //coloque o pivo depois do ultimo elemento menor que ele

    return antes;
}

void quickSortIterativo(int array[], int begin, int end) {

    int stack[end - begin];
 
    // initialize top of stack
    int top = -1;
 
    // push initial values of l and h to stack
    stack[++top] = begin;
    stack[++top] = end - 1;
 
    // Keep popping from stack while is not empty
    while (top >= 0) {

        end = stack[top--];
        begin = stack[top--];
 
        int meio = particiona(array, begin, end, begin);
 
        if (meio > begin) {
            stack[++top] = begin;
            stack[++top] = meio - 1;
        }
 
        if (meio < end - 1) {
            stack[++top] = meio + 1;
            stack[++top] = end;
        }

    }

}

void quickSortIterativo(int array[], int size) {
    quickSortIterativo(array, 0, size);
}

void quickSortRecursivo(int array[], int begin, int end) {

    if(begin == end) {
        return;
    }

    int meio = particiona(array, begin, end, begin);  // Pega a posicao do meio, pois é muito importante

    quickSortRecursivo(array, begin, meio);
    quickSortRecursivo(array, meio + 1, end);
}

void quickSortRecursivo(int array[], int size) {
    quickSortRecursivo(array, 0, size);
}

// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

// Metodo Busca Binaria

// Explicacao: Parte da ideia de voce dividir o vetor no meio, tendo um inicio e o fim para limitar qual parte do vetor de trata
// Complexidade (Pior caso): O(log(n))
// Complexidade (Melhor caso): O(1) - esta no meio do vetor


int buscaBinIterativa(int array[], int chave, int size) {

    int meio;
    int begin = 0;
    int end = size-1;

    while (begin <= end) {

        meio = ((begin + end) / 2) ; // IMPORTANTE: ira ser soma

        if (array[meio] == chave) {
            return array[meio];
        }
        else if (array[meio] < chave) {
            begin = meio + 1; // IMPORTANTE: nao testar o valor de novo
        }
        else if (array[meio] > chave) {
            end = meio - 1; // IMPORTANTE: nao testar o valor de novo
        }
    }

    return -1;
}

int buscaBinRecusiva(int array[], int chave, int begin, int end) {
    
    if (begin > end) { // IMPORTANTE: grande diferenca, aqui nao temos o while, entao precisamos fazer o inverso do metodo iterativo
        return -1;
    }

    int meio = (begin + end)/2;

    if (array[meio] == chave) {
        return array[meio];
    }

    if (array[meio] < chave) {
        return buscaBinRecusiva(array, chave, meio + 1, end); // IMPORTANTE: return importante para retornar o valor encontrado
    }
    else {
        return buscaBinRecusiva(array, chave, begin, meio - 1); // IMPORTANTE: return importante para retornar o valor encontrado
    }
}

// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

// ======================================================
// ======================================================
// ======================================================


void veArray(int array[]) {
    cout << "Array Ordenada: \n";

    for (int i = 0; i < 10; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}
       
int main() {

    int escolha;

    cout << "[1] - Bolha \n";
    cout << "[2] - Selecao \n";
    cout << "[3] - Insercao \n";
    cout << "[4] - MergeSort \n";
    cout << "[5] - QuickSort \n";
    cout << "[6] - BuscaBin \n";
    cout << endl;

    cin >> escolha;

    int array[10];
    int number;

    for (int k = 0; k < 10; k++) {

        cin >> number;

        array[k] = number;

    }

    switch (escolha) {
    case 1:
        bubbleSortIterativo(array,10);
        veArray(array);
        bubbleSortRecursivo(array,10);
        veArray(array);
        break;
    case 2:
        selectionSortIterativo(array,10);
        veArray(array);
        selectionSortRecursive(array,10);
        veArray(array);
        break; 
    case 3:
        inserctionSortIterativo(array, 10);
        veArray(array);  
        inserctionSortRecursivo(array, 10);
        veArray(array);      
        break;    
    case 4:
        mergeSortIterativo(array,10);
        veArray(array);
        mergeSortRecursivo(array,10);
        veArray(array);        
        break;     
    case 5:
        quickSortIterativo(array,10);
        veArray(array);
        quickSortRecursivo(array,10);
        veArray(array);
        break; 
    case 6:

        int find;

        cin >> find; 

        cout << buscaBinIterativa(array, find, 10) << endl;
        cout << buscaBinRecusiva(array, find, 0, 9) << endl;

        break;                                               
    
    default:
        break;
    }

    return 0;
}