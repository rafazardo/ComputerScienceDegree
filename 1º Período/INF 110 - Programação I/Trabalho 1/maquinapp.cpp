#include <iostream>
using namespace std;

int main() {
   double eP,eVlr_Inse;
   char eVlr_Tipo;
   double eP1 = 430;
   double eP2 = 270;
   double eP3 = 143;
   double eVlr_Tot = 0;
   double eTroc = 0;

   //Entrada de valores, e transforma celudas em centavos
   cin >> eP;
   while (eVlr_Inse != 0) {
      cin >> eVlr_Tipo >> eVlr_Inse;
      if (eVlr_Tipo == 'C') {
         eVlr_Tot += (eVlr_Inse*100);
      }
      else {
         eVlr_Tot += eVlr_Inse;
      }
   }

   //Verifica se o produto é valido, se sim, calcula o troco do produto escolhido, e por fim informa o saldo.
   if ((eP != 1) && (eP != 2) && (eP != 3)) {
      cout << "Produto inexistente." << endl;
   }
   else {
      if (eP == 1) {
         eTroc = eVlr_Tot - eP1;
         if (eTroc >= 0) {
            while (eTroc >= 10000) {
               cout << "C" << " " << "100" <<endl;
               eTroc = eTroc - 10000;
            }
            while (eTroc >= 5000) {
               cout << "C" << " " << "50" <<endl;
               eTroc = eTroc - 5000;
            }
            while (eTroc >= 2000) {
               cout << "C" << " " << "20" <<endl;
               eTroc = eTroc - 2000;
            }
            while (eTroc >= 1000) {
               cout << "C" << " " << "10" <<endl;
               eTroc = eTroc - 1000;
            }
            while (eTroc >= 500) {
               cout << "C" << " " << "5" <<endl;
               eTroc = eTroc - 500;
            }
            while (eTroc >= 200) {
               cout << "C" << " " << "2" <<endl;
               eTroc = eTroc - 200;
            }
            while (eTroc >= 100) {
               cout << "M" << " " << "100" <<endl;
               eTroc = eTroc - 100;
            }
            while (eTroc >= 50) {
               cout << "M" << " " << "50" <<endl;
               eTroc = eTroc - 50;
            }
            while (eTroc >= 25) {
               cout << "M" << " " << "25" <<endl;
               eTroc = eTroc - 25;
            }
            while (eTroc >= 10) {
               cout << "M" << " " << "10" <<endl;
               eTroc = eTroc - 10;
            }
            while (eTroc >= 5) {
               cout << "M" << " " << "5" <<endl;
               eTroc = eTroc - 5;
            }
            while (eTroc >= 1) {
               cout << "M" << " " << "1"<<endl;
               eTroc = eTroc - 1;
            }
         }
         else {
            cout << "Saldo insuficiente." <<endl;
         }
      }
      else {
         if (eP == 2) {
            eTroc = eVlr_Tot - eP2;
            if (eTroc >= 0) {
               while (eTroc >= 10000) {
               cout << "C" << " " << "100" <<endl;
               eTroc = eTroc - 10000;
               }
               while (eTroc >= 5000) {
                  cout << "C" << " " << "50" <<endl;
                  eTroc = eTroc - 5000;
               }
               while (eTroc >= 2000) {
                  cout << "C" << " " << "20" <<endl;
                  eTroc = eTroc - 2000;
               }
               while (eTroc >= 1000) {
                  cout << "C" << " " << "10" <<endl;
                  eTroc = eTroc - 1000;
               }
               while (eTroc >= 500) {
                  cout << "C" << " " << "5" <<endl;
                  eTroc = eTroc - 500;
               }
               while (eTroc >= 200) {
                  cout << "C" << " " << "2" <<endl;
                  eTroc = eTroc - 200;
               }
               while (eTroc >= 100) {
                  cout << "M" << " " << "100" <<endl;
                  eTroc = eTroc - 100;
               }
               while (eTroc >= 50) {
                  cout << "M" << " " << "50" <<endl;
                  eTroc = eTroc - 50;
               }
               while (eTroc >= 25) {
                  cout << "M" << " " << "25" <<endl;
                  eTroc = eTroc - 25;
               }
               while (eTroc >= 10) {
                  cout << "M" << " " << "10" <<endl;
                  eTroc = eTroc - 10;
               }
               while (eTroc >= 5) {
                  cout << "M" << " " << "5" <<endl;
                  eTroc = eTroc - 5;
               }
               while (eTroc >= 1) {
                  cout << "M" << " " << "1"<<endl;
                  eTroc = eTroc - 1;
               }
            }
            else {
               cout << "Saldo insuficiente." <<endl;
            }            
         }
         else {
            if (eP == 3) {
               eTroc = eVlr_Tot - eP3;
               if (eTroc >= 0) {
                  while (eTroc >= 10000) {
                  cout << "C" << " " << "100" <<endl;
                  eTroc = eTroc - 10000;
                  }
                  while (eTroc >= 5000) {
                     cout << "C" << " " << "50" <<endl;
                     eTroc = eTroc - 5000;
                  }
                  while (eTroc >= 2000) {
                     cout << "C" << " " << "20" <<endl;
                     eTroc = eTroc - 2000;
                  }
                  while (eTroc >= 1000) {
                     cout << "C" << " " << "10" <<endl;
                     eTroc = eTroc - 1000;
                  }
                  while (eTroc >= 500) {
                     cout << "C" << " " << "5" <<endl;
                     eTroc = eTroc - 500;
                  }
                  while (eTroc >= 200) {
                     cout << "C" << " " << "2" <<endl;
                     eTroc = eTroc - 200;
                  }
                  while (eTroc >= 100) {
                     cout << "M" << " " << "100" <<endl;
                     eTroc = eTroc - 100;
                  }
                  while (eTroc >= 50) {
                     cout << "M" << " " << "50" <<endl;
                     eTroc = eTroc - 50;
                  }
                  while (eTroc >= 25) {
                     cout << "M" << " " << "25" <<endl;
                     eTroc = eTroc - 25;
                  }
                  while (eTroc >= 10) {
                     cout << "M" << " " << "10" <<endl;
                     eTroc = eTroc - 10;
                  }
                  while (eTroc >= 5) {
                     cout << "M" << " " << "5" <<endl;
                     eTroc = eTroc - 5;
                  }
                  while (eTroc >= 1) {
                     cout << "M" << " " << "1"<<endl;
                     eTroc = eTroc - 1;
                  }
               }
               else {
                  cout << "Saldo insuficiente." <<endl;
               }               
            }            
         }
      }
   }
   return 0;
}
