#include <iostream>
using namespace std;

int findArray[1000] = {0};

void find(int container[], int inicio, int fim) {
    if (container[inicio] == container[fim]) {
        findArray[container[inicio]] = findArray[container[inicio]] + (fim - inicio + 1);
        return;
    }
    else {
        int meio = ((fim + inicio) / 2);
        find(container, inicio, meio);
        find(container, meio+1, fim);
    }
}

int main() {

    int n, valor;

    cin >> n;

    int container[n];

    for (int i = 0; i < n; i++) {
        cin >> valor;
        container[i] = valor;
    }

    find(container, 0, n-1);

    for (int i = 0; i < 1000; i++) {
        if (findArray[i] != 0) cout << "F[" << i << "]: " << findArray[i] << endl;
    }

    return 0;
}