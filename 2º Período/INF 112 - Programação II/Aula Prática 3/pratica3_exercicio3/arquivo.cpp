#include "arquivo.hpp"
#include <iostream>
#include <iomanip>

Data::Data(int nDia, int nMes, int nAno) {
    _nDia = nDia;
    _nMes = nMes;
    _nAno = nAno;
}

void Data::exibirDataFormatoNumero() {
    std::cout << std::setfill('0') << std::setw(2) << _nDia << "/";
    std::cout << std::setfill('0') << std::setw(2) << _nMes << "/";
    std::cout << std::setfill('0') << std::setw(2) << _nAno << std::endl;
}

void Data::exibirDataPorExtenso() {
    
    std::cout << _nDia << " de ";
    
    if (_nMes == 1) {
        std::cout << "janeiro";
    }
    else {
        if (_nMes == 2) {
            std::cout << "fevereiro";
        }
        else {
            if (_nMes == 3)  {
               std::cout << "marco";
            }
            else {
                if (_nMes == 4) {
                    std::cout << "abril";
                }
                else {
                    if (_nMes == 5) {
                        std::cout << "maio";
                    }
                    else {
                        if (_nMes == 6) {
                            std::cout << "junho";
                        }
                        else {
                            if (_nMes == 7) {
                                std::cout << "julho";
                            }
                            else {
                                if (_nMes == 8) {
                                    std::cout << "agosto";
                                }
                                else {
                                    if (_nMes == 9) {
                                        std::cout << "setembro";
                                    }
                                    else {
                                        if (_nMes == 10) {
                                            std::cout << "outubro";
                                        }
                                        else {
                                            if (_nMes == 11) {
                                                std::cout << "novembro";
                                            }
                                            else {
                                                if (_nMes == 12) {
                                                    std::cout << "dezembro";
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
    
    std::cout << " de " << _nAno << std::endl;

}

void Data::getDataEmSegundos() {

    int nCont;
    int nDiasMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    long long int nQntDias = 0;

    nQntDias += _nDia - 1;

    if ((_nAno - 1970) > 0) {
        nQntDias += (_nAno - 1970)*365;
    }

    for (nCont = 0; nCont < _nMes - 1; nCont++) {
        nQntDias += nDiasMes[nCont];
    }

    nQntDias *= 86400;

    std::cout << nQntDias << std::endl;
}