#include <iostream>
using namespace std;

int main() {
    int comida, bebida, sobremesa; // Consumo
    int valordaconta, valorpago, troco; //Outros valores

    //Leitura dos dados
    cout << "Escreva o valor consumido em comida, bebida e sobremessa: ";
    cin >> comida;
    cin >> bebida;
    cin >> sobremesa;
    cout << "Escreva o valor pago pelo cliente: ";
    cin >> valorpago;

    //Processamento dos dados
    valordaconta = comida + bebida + sobremesa;
    troco = valorpago - valordaconta;

    //Impressao do resultado
    cout << "\n\nRestaurante Pegue e Page\n";
    cout << "Consumo: " << comida << " + " << bebida << " + " << sobremesa;
    cout << " = " << valordaconta << endl;
    cout << "Valor pago: " << valorpago << endl;
    cout << "Troco: " << troco << endl;
    cout << "Volte sempre!\n";
    return 0;
}