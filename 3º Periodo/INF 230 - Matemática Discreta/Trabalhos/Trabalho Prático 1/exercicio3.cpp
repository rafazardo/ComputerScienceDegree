#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int primeiro = 0, segundo = 1;
	int proximo;

	int cont = 0;

	cout << "11 primeiros numeros de Fibonacci divisiveis por 5\n";
	cout << primeiro << " ";

	while(cont < 11) {
		proximo = primeiro + segundo;
		primeiro = segundo;
		segundo = proximo;

		if ((proximo % 5) == 0) {
			cout << proximo << " ";
			cont++;
		}

	}

	return 0;
}