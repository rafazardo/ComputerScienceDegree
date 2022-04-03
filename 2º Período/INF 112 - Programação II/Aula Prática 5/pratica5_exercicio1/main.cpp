#include <iostream>
#include <iomanip>

#include "estudante.h"
#include "pessoa.h"
#include "turma.h"

void f(Pessoa &pessoa) {
  std::cout << "Na função: " << pessoa.defina_meu_tipo() << std::endl;
}

int main() {

  Turma turma("INF110",2021);
  Pessoa pessoa("Julio Reis.");
  Estudante estudante("Jane Doe", 20180101,turma);

  estudante.get_turma();
  estudante.set_turma("INF112",2022);
  estudante.get_turma();

  std::cout << "----------------" << std::endl;

  std::cout << "A pessoa é: " << pessoa.defina_meu_tipo() << std::endl;
  std::cout << "O estudante é: " << estudante.defina_meu_tipo() << std::endl;
  f(pessoa);
  f(estudante);

  return 0;
}