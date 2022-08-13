#ifndef MEDIANA_H_
#define MEDIANA_H_

#include "MyPriorityQueue.h"
#include <limits>

class Mediana {
private:
  MyPriorityQueue<int> queuePequena;
  MyPriorityQueue<int> queueGrande;

public:
  Mediana();
  ~Mediana();

  void insere(int el);
  int getMediana();

};

// Deixei essas funcoes no .h pois nao estavam compilando com elas implementadas somente no .cpp, conforme avisei na aula pratica para o senhor

Mediana::Mediana() {}

Mediana::~Mediana() {}

void Mediana::insere(int el) {
  queuePequena.push(el);
  queueGrande.push(-queuePequena.top());
  queuePequena.pop();

  if (queuePequena.size() < queueGrande.size()) {
    queuePequena.push(-queueGrande.top());
    queueGrande.pop();
  }
}

int Mediana::getMediana() { 

  if (queuePequena.size() > queueGrande.size()) {
    return queuePequena.top();
  }
  else {  
    return ((queuePequena.top() - queueGrande.top()) >> 1);
  }
}

#endif