#include <iostream>
#include <string>

#include "Gerente.h"

Gerente::Gerente(int codigo, std::string nome, double salario, std::string cpf, std::string endereco, std::string email, std::string data_nascimento, std::string senha, bool curso_superior):
    Funcionario(codigo, nome, salario, cpf, endereco, email, data_nascimento, senha), _curso_superior(curso_superior) {} 

Gerente::~Gerente() {

}

bool Gerente::get_curso_superior() {
    return this->_curso_superior;
}

void Gerente::set_curso_superior(bool curso_superior) {
    this->_curso_superior = curso_superior;
}

// Metodo especializado para a classe Gerente (polimorfismo)
void Gerente::exibir_dados() {
    std::cout << "------------------------------------------------\n";
    std::cout << "Dados do Gerente:\n";
    std::cout << "Nome: " << Funcionario::get_nome() << std::endl;
    std::cout << "Codigo: " << Funcionario::get_codigo() << std::endl; 
    std::cout << "Salario: " << Funcionario::get_salario() << std::endl;
    std::cout << "CPF: " << Funcionario::get_cpf() << std::endl;
    std::cout << "Endereco: " << Funcionario::get_endereco() << std::endl;
    std::cout << "E-mail: " << Funcionario::get_email() << std::endl;
    std::cout << "Data de Nascimento: " << Funcionario::get_data_nascimento() << std::endl;
    std::cout << "Senha: " << Funcionario::get_senha() << std::endl;
    std::cout << "Certificado de curso superior: " << this->get_curso_superior() << std::endl;
    std::cout << "------------------------------------------------\n";
}
