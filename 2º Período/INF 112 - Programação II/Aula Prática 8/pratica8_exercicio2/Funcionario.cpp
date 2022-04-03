#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <math.h>

#include "Funcionario.h"

Funcionario::Funcionario() {}

Funcionario::~Funcionario() {}

std::vector<int> Funcionario::get_codigo() {
    return this->_codigo;
}

std::vector<std::string> Funcionario::get_nome() {
    return this->_nome;
}

std::vector<double> Funcionario::get_despesa() {
    return this->_despesa;
}

std::vector<double> Funcionario::get_gastoPercentual() {
    return this->_gastoPercentual;
}

double Funcionario::get_gastoTotalMensal() {
    return this->_gastoTotalMensal;
}

double Funcionario::get_gastoMedioFuncionario() {
    return this->_gastoMedioFuncionario;
}

void Funcionario::set_codigo(int addCodigo, int posicao) {
    this->_codigo[posicao] = addCodigo;
}

void Funcionario::set_nome(std::string addNome, int posicao) {
    this->_nome[posicao] = addNome;
}

void Funcionario::set_despesa(double addDespesa, int posicao) {
    this->_despesa[posicao] = addDespesa;
}

void Funcionario::set_gastoPercentual(double addGastoPercentual, int posicao) {
    this->_gastoPercentual[posicao] = addGastoPercentual;
}

void Funcionario::set_gastoTotalMensal(double addGastoTotalMensal) {
    this->_gastoTotalMensal = addGastoTotalMensal;
}

void Funcionario::set_gastoMedioFuncionario(double addGastoMedioFuncionario) {
    this->_gastoMedioFuncionario = addGastoMedioFuncionario;
}

void Funcionario::gerarRelatorio() {

    char nomeFuncionario[1000];
    double valorReais;
    double valorGastoTotal = 0;
    int contador = 0;

    std::ifstream fin("funcionarios.txt");

    try {
        if (!fin.is_open()) {
            throw std::exception();
        }
    }
    catch (std::exception &erro) {
        std::cerr << "Erro: O arquivo para coletar os dados dos funcionarios nao foi localizado! \n";
        exit(1);
    }

    std::ofstream fout("relatorio.txt",std::ios::out);

    try {
        if (!fout.is_open()) {
            throw std::exception();
        }
    }
    catch (std::exception &erro) {
        std::cerr << "Erro: O arquivo para salvar o relatorio nao foi localizado! \n";
        exit(1);
    }     

    while (true) {
        
        if (fin.eof()) {
            break;
        }        

        fin.getline(nomeFuncionario, 1000, ' ');    
        fin.ignore(1000,'$');

        fin >> valorReais;

        this->_codigo.push_back(contador + 1);
        this->_nome.push_back(nomeFuncionario);
        this->_despesa.push_back(valorReais);
        contador++;
        fin.ignore();
    }

    for (int i = 0; i < this->_despesa.size(); i++) {
        valorGastoTotal += _despesa[i];
    }

    set_gastoTotalMensal(valorGastoTotal);
    set_gastoMedioFuncionario(get_gastoTotalMensal()/this->_codigo.size());

    for (int i = 0; i < this->_despesa.size(); i++) {
        _gastoPercentual.push_back((this->_despesa[i]*100) / get_gastoTotalMensal() );
    }

    fout << "Nro. Funcionario Gasto %" << std::endl;

    for (int i = 0; i < this->_codigo.size(); i++) {
        fout << std::fixed << std::setprecision(2) << this->_codigo[i] << " " << this->_nome[i] << " R$" <<  this->_despesa[i] << " ";
        fout << std::fixed << std::setprecision(0) << this->_gastoPercentual[i] << "% \n";
    }
              
    fout << std::fixed << std::setprecision(2) << "Gasto mensal total: R$" << get_gastoTotalMensal() << std::endl;
    fout << std::fixed << std::setprecision(2) << "Gasto medio por funcionario: R$" << get_gastoMedioFuncionario() << std::endl;

    fin.close();
    fout.close();

}