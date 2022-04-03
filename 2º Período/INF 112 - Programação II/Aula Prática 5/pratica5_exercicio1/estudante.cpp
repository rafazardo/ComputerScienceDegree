#include "estudante.h"
#include "turma.h"

Estudante::Estudante(std::string nome, int matricula, Turma addTurma):
  Pessoa(nome), _matricula(matricula), _turma(addTurma) {};

int Estudante::get_matricula() const {
  return this->_matricula;
}

void Estudante::get_turma() {
  std::cout << "Codigo estudante: " << this->_turma.get_codigo() << std::endl;
  std::cout << "Ano estudante: " << this->_turma.get_ano() << std::endl;
}

void Estudante::set_turma(std::string setCodigo, int setAno) {
  _turma.set_codigo(setCodigo);
  _turma.set_ano(setAno);
}

std::string Estudante::defina_meu_tipo() const {
  return "Sou um estudante";
}

