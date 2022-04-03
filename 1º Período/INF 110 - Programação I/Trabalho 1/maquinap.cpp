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
            cout << "Troco de " << eTroc << " centavos." <<endl;
         }
         else {
            cout << "Saldo insuficiente." <<endl;
         }
      }
      else {
         if (eP == 2) {
            eTroc = eVlr_Tot - eP2;
            if (eTroc >= 0) {
               cout << "Troco de " << eTroc << " centavos." <<endl;
            }
            else {
               cout << "Saldo insuficiente." <<endl;
            }            
         }
         else {
            if (eP == 3) {
               eTroc = eVlr_Tot - eP3;
               if (eTroc >= 0) {
                  cout << "Troco de " << eTroc << " centavos." <<endl;
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
