// #include "MySet.h"
// #include "MyList.h"
#include "MyList2NewIterator.h"
// #include "MyVecNewIterator.h"
using namespace std;

// int main() {

//     MyList2<int> l;
//     for(int i=1;i<=6;i++)
//     l.push_back(i);
//     int * it = l.begin(); // Nao ira funcionar, pois esta atriuinbo um Nodo para um variavel do tipo int
//     cout << *it << endl;

//     return 0;
// }

// int main() {

//     MyVec<int> v;
//     for(int i=1;i<=6;i++)
//             v.push_back(i);
//     int * it = &(*v.begin());
//     cout << *(it+2) << endl; // Ira imprimir 3


//     return 0;
// }


// int main() {

// MyVec<int> v;
// for(int i=1;i<=6;i++)
//              v.push_back(i*100);
//     swap(*v.begin(),*v.end());
//     cout << v[0]  << endl; // Ira imprimir 0
// }

// int main() {

//     MyVec<int> v;
//     for(int i=1;i<=3;i++) v.push_back(i*100);

//     MyVec<int>::iterator it = v.end(); // Iterator para o end de um myVec sempre sera 0
//     it--;
//     // cout << *it;
//     v.push_back(*it);
//     v.push_back(10+(*it));
//     v.push_back(20+(*it));
//     cout << v[2] << endl; // 300
//     cout << v[3] << endl; // 4 , nao deveria ser 300?
//     cout << v[4] << endl; // 14
//     cout << v[5] << endl; // 24

// }


// int main() {
// MyList2<int> l;
// for(int i=1;i<=5;i++)
//              l.push_back(i*100);
// int *p = &(*l.begin());
// cout << *p << endl; // Imprimi 100
// }

// int main() {
// MyList2<int> l;
// for(int i=1;i<=5;i++)
//              l.push_back(i*100);
// int *p = &(*l.begin());
// p++; // Erro nao podemos incrementar um endereco
// cout << *p << endl;
// }