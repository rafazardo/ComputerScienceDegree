#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int numero = 1730;
	int cont = 0;
	int max, cubo1, cubo2, dif;
	int v[2][2];
	
	while(cont < 10) {

		dif = 0;
		max = cbrt(numero);

		for (int i=0; i<=max; i++) {
			for (int j=i; j<=max; j++) {
				cubo1 = pow(i, 3);
				cubo2 = pow(j, 3);
				if ((cubo1 + cubo2) == numero) {
					v[dif][0] = cbrt(cubo1);
					v[dif][1] = cbrt(cubo2);
					dif++;
				}
				if (dif == 2)
					break;
			}
		}
		if (dif == 2) {
			cont++;
			cout << numero << " atende as propriedades: ";
			cout << v[0][0] << "^3+" << v[0][1] << "^3  " << v[1][0] << "^3+" << v[1][1] << "^3\n";
		}
		numero++;
	}

	return 0;

}