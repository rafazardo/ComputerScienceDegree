#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

// int bolha (int a[], int);
// double media(int a[],int);
// double mediana(int ,int);

double media(int a[],int n) {

    int nCont = 0;
    double Soma = 0;
    double Media;

    for (nCont = 0; nCont < n; nCont++) {
        Soma += a[nCont];
    }

    Media = Soma / n;
    return Media;
}

double mediana(int a[],int n) {
    double Mediana;

    if (n%2 == 0) {
       Mediana = (a[((n/2) - 1)] + a[((n/2))]) / 2;
    }
    else {
        Mediana = a[((n/2))];
    }
    return Mediana;
}


void bolha (int a[], int n) {

    int nSupo2 = 0;
    int nSupo3 = 0;
    int nSupo4 = 0;

    for (nSupo2 = 0; nSupo2 < n; nSupo2++) {
        for (nSupo3 = nSupo2 + 1; nSupo3 < n; nSupo3++) {
            if (a[nSupo2] > a[nSupo3]) {
               nSupo4 = a[nSupo3];
               a[nSupo3] = a[nSupo2];
               a[nSupo2] = nSupo4;
            }
        }
    }
}

int main() {

    int n,nCont;
    cin >> n;
    int a[10000];
    
    for (nCont = 0; nCont < n; nCont++) {
        cin >> a[nCont];
    }
    bolha(a,n);
    cout << fixed << setprecision(1) << "Media: " << media(a,n) << endl;
    cout << fixed << setprecision(1) << "Mediana: " << mediana(a,n) << endl;
    return 0;
}

// double media(int a[],int n) {

//     int nCont = 0;
//     double Soma = 0;
//     double Media;

//     for (nCont = 0; nCont < n; nCont++) {
//         Soma += a[nCont];
//     }

//     Media = Soma / n;
//     return Media;
// }

// double mediana(int a[],int n) {
//     double Mediana;

//     if (n%2 == 0) {
//        Mediana = (a[((n/2) - 1)] + a[((n/2))]) / 2;
//     }
//     else {
//         Mediana = a[((n/2))];
//     }
//     return Mediana;
// }


// void bolha (int a[], int n) {

//     int nSupo2 = 0;
//     int nSupo3 = 0;
//     int nSupo4 = 0;

//     for (nSupo2 = 0; nSupo2 < n; nSupo2++) {
//         for (nSupo3 = nSupo2 + 1; nSupo3 < n; nSupo3++) {
//             if (a[nSupo2] > a[nSupo3]) {
//                nSupo4 = a[nSupo3];
//                a[nSupo3] = a[nSupo2];
//                a[nSupo2] = nSupo4;
//             }
//         }
//     }
// }

