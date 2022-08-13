#include <iostream>

#include "MyMap.h"

using namespace std;

int main() {

    MyMap<string,int> myMapAux;
    string text;
    int codigo = 0;

    while (cin >> text) {

        if (myMapAux.find(text) == 0) {
            myMapAux.insert(make_pair(text,codigo));
            cout << text << " " << codigo << endl;
            codigo++;
            continue;
        }

        MyMapIterator<string,int> it = (myMapAux.find(text));

        cout << get<0>(*(it)) << " " <<  get<1>(*(it)) << endl;
        
        cin.ignore();
    }
}