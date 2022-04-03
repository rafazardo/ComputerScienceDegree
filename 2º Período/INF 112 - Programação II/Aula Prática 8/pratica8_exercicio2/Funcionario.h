#ifndef INF112_FUNCIONARIO_H
#define INF112_FUNCIONARIO_H

#include <string>
#include <vector>
#include <iostream>

class Funcionario {

private:
    std::vector<int> _codigo;
    std::vector<std::string> _nome;
    std::vector<double> _despesa;
    std::vector<double> _gastoPercentual;
    double _gastoTotalMensal;
    double _gastoMedioFuncionario;

public:
    Funcionario();
    ~Funcionario();

    std::vector<int> get_codigo();
    std::vector<std::string> get_nome();
    std::vector<double> get_despesa();
    std::vector<double> get_gastoPercentual();
    double get_gastoTotalMensal();
    double get_gastoMedioFuncionario();

    void set_codigo(int addCodigo, int posicao);
    void set_nome(std::string addNome, int posicao);
    void set_despesa(double addDespesa, int posicao);
    void set_gastoPercentual(double addGastoPercentual, int posicao);
    void set_gastoTotalMensal(double addGastoTotalMensal);
    void set_gastoMedioFuncionario(double addGastoMedioFuncionario);

    void gerarRelatorio();
};

#endif