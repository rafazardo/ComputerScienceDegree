#include <iomanip>
#include <iostream>
#include <math.h>
using namespace std;

long long int fatorial (int);

int main() {
    
    double nNumAln,nNumAlnComs;
    
    cin >> nNumAln >> nNumAlnComs;
    cout << fatorial(nNumAln) / (fatorial(nNumAlnComs)*fatorial(nNumAln - nNumAlnComs)) << endl;
    return 0;
}

//Calcula fatorial de X
long long int fatorial (int x) {
    long long int fat = 1;
    for(int i=2; i<=x; i++)
        fat *= i;
    return fat;
}
