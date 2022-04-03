#ifndef INF112_ESTUDANTE_H
#define INF112_ESTUDANTE_H

#include "pessoa.h"
#include "turma.h"

class Estudante : public Pessoa {
private:
  int _matricula;
  Turma _turma;

public:
  Estudante(std::string nome, int matricula, Turma addTurma);
  int get_matricula() const;
  void get_turma();
  void set_turma(std::string setCodigo, int setAno);
  virtual std::string defina_meu_tipo() const override;
};

#endif