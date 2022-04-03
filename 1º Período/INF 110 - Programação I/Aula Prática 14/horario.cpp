#include <iomanip>
#include <iostream>
using namespace std;

struct Horario {
    int horas, minutos;
};

void escreve(Horario h) {

    if (h.horas >= 0 && h.horas < 12 ) {
        if (h.horas == 0) {
            cout << setfill('0') << setw(2) << "12:";
            cout << setfill('0') << setw(2) << h.minutos << " AM" << endl;
        }
        else {
            cout << setfill('0') << setw(2) << h.horas << ":";
            cout << setfill('0') << setw(2) << h.minutos << " AM" << endl;
        }
    }

    if (h.horas >= 12 && h.horas < 24 ) {
        if (h.horas == 12) {
            cout << setfill('0') << setw(2) << "12:";
            cout << setfill('0') << setw(2) << h.minutos << " PM" << endl;
        }
        else {
            h.horas = (h.horas - 12);
            cout << setfill('0') << setw(2) << h.horas << ":";
            cout << setfill('0') << setw(2) << h.minutos << " PM" << endl;
        }
    }    
}

int main() {

    Horario hHoras;
    int nCont = 1;
    int nQntHor;

    cin >> nQntHor;
    
    while(nCont <= nQntHor) {

        cin >> hHoras.horas >> hHoras.minutos;
        escreve(hHoras);
        nCont++;
    }

    return 0;
}