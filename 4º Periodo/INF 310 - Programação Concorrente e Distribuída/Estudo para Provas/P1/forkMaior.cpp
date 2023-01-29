#include <iostream>
#include <unistd.h>
using namespace std;

int main() {

    if (fork() == 0) {
        cout<<"1";
        if (fork() == 0) {
            cout<<"2";
        }
        else {
            cout<<"3";
        }
    }
    else {
        cout<<"4";
    }

    if (fork() == 0) {
        cout<<"5";
    }
    else {
        cout<<"6";
    }

 return 0;
}