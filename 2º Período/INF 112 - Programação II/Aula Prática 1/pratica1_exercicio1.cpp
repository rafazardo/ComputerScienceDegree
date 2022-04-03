#include <iomanip>
#include <iostream>
using namespace std;

int main() {

    long int value1 = 200000;
    long int value2 = 0;
    long *longPtr;

    longPtr = &value1;
    cout << *longPtr << endl;
    value2 = *longPtr;
    cout << value2 << endl;
    cout << &value1 << endl;
    cout << longPtr << endl;
    //Sim, o valor impresso de longPtr é igual ao endereço da variavel value1, isso ocorre pois longPtr é um ponteiro que aponta para o endereco de value1.
    
    return 0;
}