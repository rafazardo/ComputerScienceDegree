#ifndef INF112_PESSOA_H
#define INF112_PESSOA_H

#include <string>

class Pessoa {
private:
  const std::string _nome;
public:
  Pessoa(std::string nome);
  std::string get_nome() const;
  virtual std::string defina_meu_tipo() const;
};

#endif