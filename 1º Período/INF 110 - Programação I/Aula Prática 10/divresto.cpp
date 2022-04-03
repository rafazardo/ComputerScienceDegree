#include <iostream>
#include <iomanip>
using namespace std;

bool divresto(int, int, int &, int &);

int main() {

    int divdend,divi,qntd;
    int cont = 1;
    int quoc = 0;
    int rest = 0;

    cin >> qntd;
    while (cont <= qntd) {
        cin >> divdend >> divi;
        if (divresto(divdend,divi,quoc,rest) == true) {
            cout << quoc << " " << rest << endl;
        }
        else {
            cout << "indefinido" << endl;
        }
        cont++;
    }
    return 0;
}

bool divresto(int divdend, int divi, int &quoc, int &rest) {
    
    bool cond;

    if (divi == 0) {
        return false;
    }
    else {
        quoc = divdend / divi;
        rest = divdend % divi;
        return true;
    }
}