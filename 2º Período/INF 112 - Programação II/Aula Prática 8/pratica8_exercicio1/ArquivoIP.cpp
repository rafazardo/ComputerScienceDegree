#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <exception>

#include "ArquivoIP.h"

ArquivoIP::ArquivoIP() {}

ArquivoIP::~ArquivoIP() {}

std::vector<std::string> ArquivoIP::get_ips() {
    return this->_ips;
}

std::vector<std::string> ArquivoIP::get_ipsValidos() {
    return this->_ipsValidos;
}

std::vector<std::string> ArquivoIP::get_ipsNaoValidos() {
    return this->_ipsNaoValidos;
}

void ArquivoIP::set_ips(std::string addIP, int addPosicao) {
    this->_ips[addPosicao] = addIP;
}

void ArquivoIP::set_ipsValidos(std::string addIPValidos, int addPosicao) {
    this->_ipsValidos[addPosicao] = addIPValidos;
}

void ArquivoIP::set_ipsNaoValidos(std::string addIPNaoValidos, int addPosicao) {
    this->_ipsNaoValidos[addPosicao] = addIPNaoValidos;
}

void ArquivoIP::leArquivosEntrada() {

    std::string stringSuporte;

    std::ifstream fin("entrada.txt");

    try {
        if (!fin.is_open()) {
            throw std::exception();
        }
    }
    catch (std::exception &erro) {
        std::cerr << "Erro: O arquivo para coletar os ips nao foi localizado! \n";
        exit(1);
    }

    while (true) {
        fin >> stringSuporte;
        this->_ips.push_back(stringSuporte);
        if (fin.eof()) {
            break;
        }
    }

    fin.close();
}


void ArquivoIP::validaIP() {

    char stringSuporte[1];
    int valorSuporte = 0;
    int n = 1;

    for (int i = 0; i < this->_ips.size(); i++) {
        for (int j = (this->_ips[i].length() - 1); j >= 0 ; j--) {
            if (_ips[i][j] == '.') { //Verifica o valor antes do .
                if (valorSuporte < 0 || valorSuporte > 255) {
                    this->_ipsNaoValidos.push_back(_ips[i]);
                    break;
                }
                n = 1;
                valorSuporte = 0;
                continue;                
            }

            stringSuporte[0] = _ips[i][j]; //Pega um termo da string
            valorSuporte += atoi(stringSuporte)*n; //Transforma os termos antes do . em inteiros 
            n *= 10;

            if (j == 0) {
                if (valorSuporte < 0 || valorSuporte > 255) { //Verifica o ultimo valor
                    this->_ipsNaoValidos.push_back(_ips[i]);
                }
                else {
                    this->_ipsValidos.push_back(_ips[i]);
                }
            }
        }
        n = 1;
        valorSuporte = 0;
    }
    
}

void ArquivoIP::geraArquivoIps() {

    std::ofstream fout("ips.txt");

    try {
        if (!fout.is_open()) {
            throw std::exception();
        }
    }
    catch (std::exception &erro) {
        std::cerr << "Erro: O arquivo para salvar os ips nao foi localizado! \n";
        exit(1);
    }    

    fout << "[Enderecos Validos:]" << std::endl;

    for (int i = 0; i < this->_ipsValidos.size(); i++) {
        fout << _ipsValidos[i] << std::endl;
    }

    fout << std::endl;

    fout << "[Enderecos Invalidos:]" << std::endl;

    for (int i = 0; i < this->_ipsNaoValidos.size(); i++) {
        fout << _ipsNaoValidos[i] << std::endl;
    }    

    fout.close();
}