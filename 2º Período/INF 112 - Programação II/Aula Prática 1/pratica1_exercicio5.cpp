#include <iomanip>
#include <iostream>
using namespace std;

int main() {

    char str[] = "abc teste";
    char *cPtr;

    cPtr = str;

    for (; *cPtr != '\0'; cPtr++) {
    }

    for (cPtr--; *cPtr; cPtr--) {
        cout << *cPtr;
    }
    cout << endl;

    return 0;

}

