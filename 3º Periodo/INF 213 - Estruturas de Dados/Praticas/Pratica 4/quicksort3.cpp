#include <algorithm>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <cassert>
using namespace std;

const int K = 10;

void insertionSort(int *v, int n) {
    for (int i = 1; i < n; i++) {

        int elemInserir = v[i];
        int j = i-1;

        while(j >= 0 && v[j] > elemInserir) {
            v[j+1] = v[j];
            j--;
        }
        
        v[j+1] = elemInserir;
    }
}


int particiona(int *v, int beg, int end, int pivo) {

    int valorPivo = v[pivo];

    swap(v[pivo], v[end-1]);

    int pos = beg;

    for(int i = beg; i < end-1; i++) {
        if (v[i] < valorPivo) {
            swap(v[pos], v[i]); 
            pos++;  
        }
    }

    swap(v[pos],v[end-1]);

    return pos;
}

void quickSort2(int *v, int beg, int end) {

    if(beg == end) {
        return;
    }

    if (end - beg < K) {
        insertionSort(v + beg, end - beg);
        return;
    }
    else {
        int pos = particiona(v, beg, end, rand()%(end - beg) + beg);

        quickSort2(v, beg, pos);
        quickSort2(v, pos + 1, end);
    }

}

void quickSort(int *v, int n) {
    quickSort2(v, 0, n);
}


int main(int argc, char**argv) {
	int n;
	cin >> n;
	int *v = new int[n];

	for(int i=0;i<n;i++) cin >> v[i];

	int soma = 0;

	auto t0 = std::chrono::system_clock::now();
	quickSort(v,n);
	auto tempoSort = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now() - t0);
	cerr << "Tempo para ordenar (us): " << tempoSort.count() << "\n";

	for(int i=0;i<n-1;i++) assert(v[i]<=v[i+1]);
	cout << "ok\n";

	delete []v;
	return 0;
}