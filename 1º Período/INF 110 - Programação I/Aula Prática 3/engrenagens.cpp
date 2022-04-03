#include <iostream>
using namespace std;

int main() {
    int p1,p2,v;
    cin >> p1 >> p2;
    v = p2%p1;
    if (v == 0) {
        cout << "1" << endl;
    }
    else {
        cout << "0" << endl;
    }
    return 0;
}