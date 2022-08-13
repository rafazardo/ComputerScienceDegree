#include <algorithm>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <cassert>
using namespace std;

void merge(int *v, int p, int q, int r, int *aux) {
    int tam = r-p;
    int i = p; 
    int j = q; 
    int k = 0; 
    while(i < q && j < r) {
        if (v[i] <= v[j])
            aux[k++] = v[i++];
        else
            aux[k++] = v[j++];
    }
    while(i < q)
        aux[k++] = v[i++];
    while(j < r)
        aux[k++] = v[j++];
    for(k = 0; k < tam; k++)
        v[p+k] = aux[k];    
}

void mergeSort(int *v, int p, int r, int *aux) {
    if (p < r-1) {
        int meio = (p+r) / 2;
        mergeSort(v, p, meio, aux);
        mergeSort(v, meio, r, aux);
        merge(v, p, meio, r, aux); 
    }
}


void mergeSort(int *v, int n) {
    int *aux = new int[n];
    mergeSort(v, 0, n, aux);
    delete []aux;
}

int main(int argc, char**argv) {

	int n;
	cin >> n;
	int *v = new int[n];

	for(int i=0;i<n;i++) cin >> v[i];

	int soma = 0;

	//Mede o tempo de 10000 execucoes em microsegundos
	auto t0 = std::chrono::system_clock::now();
	mergeSort(v,n);
	auto tempoSort = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now() - t0);
	cerr << "Tempo para ordenar (us): " << tempoSort.count() << "\n";

	for(int i=0;i<n-1;i++) assert(v[i]<=v[i+1]);
	cout << "ok\n";

	delete []v;
	return 0;
}