#include <iostream>
#include <string> 
using namespace std;

int find(string &str, int ini, int fim) {
    if (ini >= fim) return 0;

    if (str[ini] == str[fim]) return find(str, ini+1, fim-1);

    return min(1+find(str, ini+1, fim),1+ find(str, ini, fim-1));
}

int main() {

    string str = "ACRADRAM";

    cout << find(str, 0, str.length()-1) << endl;

    return 0;
}