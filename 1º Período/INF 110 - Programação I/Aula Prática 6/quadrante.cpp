#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int x,y;

    cin >> x >> y;

    if ((x == 0) && (y == 0)) {
        cout << "ORIGEM" << endl;
    }
    else {
        if (x == 0) {
            cout << "EIXO Y" << endl;
        }
        else {
            if (y == 0) {
                cout << "EIXO X" << endl;
            }
            else {
                if ((x >= 1) && (y >= 1)) {
                    cout << "QUADRANTE 1" << endl;
                }
                else {
                    if ((x <= -1) && (y >= 1)) {
                        cout << "QUADRANTE 2" << endl;
                    }
                    else {
                        if ((x <= -1) && (y <= -1)) {
                            cout << "QUADRANTE 3" << endl;
                        }
                        else {
                            if ((x >= 1) && (y <= -1)) {
                                cout << "QUADRANTE 4" << endl;
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}