#include <iostream>
#include <cmath>
using namespace std;


long long int fat(long long int n) {
	if (n == 1)
		return 1;
	else
		return n * fat(n-1);
}


int main() {

	long long int n = 3, denominador, numerador;
	long long int fatorial;
	int cont = 0;
	int primos[4] = {2, 3, 5, 7};

	while (cont < 8) {

		numerador = (2*n);
		denominador = n;

		denominador = fat(denominador);    // n!
		numerador = fat(numerador);		   // (2n)!

		denominador = denominador * denominador;    // n!*n!

		fatorial = (numerador/denominador);

		for (int i=0; i<7; i++) {
			int primo = (primos[i] * primos[i]);

			if ((fatorial % primo) == 0) {
				cout << "n = " << n << " divisivel por ";
				cout << primo << "\n";
				cont++;
				break;
			}
		}
		n++;
	}

	return 0;

}