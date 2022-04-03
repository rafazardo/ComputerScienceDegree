#include <iostream>
using namespace std;

int main() {
    int eDia,eMes_Nume,eTot_Dias,eMes1,eMes2,eMes3,eMes4,eMes5,eMes6,eMes7,eMes8,eMes9,eMes10,eMes11,eMes12;              
    string eMes_Nome,eEstacao;              
    
    cin >> eDia >> eMes_Nume;

    //Defini quantos dias tem cada mês
    eMes1 = 31;
    eMes2 = 28;
    eMes3 = 31;
    eMes4 = 30;
    eMes5 = 31;
    eMes6 = 30;
    eMes7 = 31;
    eMes8 = 31;
    eMes9 = 30;
    eMes10 = 31;
    eMes11 = 30;
    eMes12 = 31;

    //Verifica qual é o nome do mês e soma o total de dias na data especificada.
    if (eMes_Nume == 1) {
        eMes_Nome = "janeiro";
        eTot_Dias = eDia;
    }
    else {
        if (eMes_Nume == 2) {
            eMes_Nome = "fevereiro";
            eTot_Dias = eDia + eMes1;
        }
        else {
            if (eMes_Nume == 3)  {
                eMes_Nome = "marco";
                eTot_Dias = eDia + eMes1 + eMes2;
            }
            else {
                if (eMes_Nume == 4) {
                    eMes_Nome = "abril";
                    eTot_Dias = eDia + eMes1 + eMes2 + eMes3;
                }
                else {
                    if (eMes_Nume == 5) {
                        eMes_Nome = "maio";
                        eTot_Dias = eDia + eMes1 + eMes2 + eMes3 + eMes4;
                    }
                    else {
                        if (eMes_Nume == 6) {
                            eMes_Nome = "junho";
                            eTot_Dias = eDia + eMes1 + eMes2 + eMes3 + eMes4 + eMes5;
                        }
                        else {
                            if (eMes_Nume == 7) {
                                eMes_Nome = "julho";
                                eTot_Dias = eDia + eMes1 + eMes2 + eMes3 + eMes4 + eMes5 + eMes6;
                            }
                            else {
                                if (eMes_Nume == 8) {
                                    eMes_Nome = "agosto";
                                    eTot_Dias = eDia + eMes1 + eMes2 + eMes3 + eMes4 + eMes5 + eMes6 + eMes7;
                                }
                                else {
                                    if (eMes_Nume == 9) {
                                        eMes_Nome = "setembro";
                                        eTot_Dias = eDia + eMes1 + eMes2 + eMes3 + eMes4 + eMes5 + eMes6 + eMes7 + eMes8;
                                    }
                                    else {
                                        if (eMes_Nume == 10) {
                                            eMes_Nome = "outubro";
                                            eTot_Dias = eDia + eMes1 + eMes2 + eMes3 + eMes4 + eMes5 + eMes6 + eMes7 + eMes8 + eMes9;
                                        }
                                        else {
                                            if (eMes_Nume == 11) {
                                                eMes_Nome = "novembro";
                                                eTot_Dias = eDia + eMes1 + eMes2 + eMes3 + eMes4 + eMes5 + eMes6 + eMes7 + eMes8 + eMes9 + eMes10;
                                            }
                                            else {
                                                if (eMes_Nume == 12) {
                                                    eMes_Nome = "dezembro";
                                                    eTot_Dias = eDia + eMes1 + eMes2 + eMes3 + eMes4 + eMes5 + eMes6 + eMes7 + eMes8 + eMes9 + eMes10 + eMes11;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    //Analisa o total de dias para definir a estação
    if (eTot_Dias < (eMes1 + eMes2 + 20)) {
        eEstacao = "Verao";
    }
    else {
        if (eTot_Dias < (eMes1 + eMes2 + eMes3 + eMes4 + eMes5 + 21)) {
            eEstacao = "Outono";
        }
        else {
            if (eTot_Dias < (eMes1 + eMes2 + eMes3 + eMes4 + eMes5 + eMes6 + eMes7 + eMes8 + 22)) {
                eEstacao = "Inverno";
            }
            else {
                if (eTot_Dias < (eMes1 + eMes2 + eMes3 + eMes4 + eMes5 + eMes6 + eMes7 + eMes8 + eMes9 + eMes10 + eMes11 + 21)) {
                    eEstacao = "Primavera";
                }
                else {
                    eEstacao = "Verao";
                }
            }               
        }
    }

    //Saida dos dados 
    cout << eDia << " " << "de" << " " << eMes_Nome << endl;
    cout << eEstacao << endl;            
    return 0;
}