#include <iostream>

#include "MySet.h"

using namespace std;

// 04) Considere a seguinte implementação de Nodo:

// class Node {
// public:
// 	Node(): left(NULL), right(NULL), parent(NULL), neighbor(NULL) {};
// 	Node * left, * right; //filhos da esquerda e direita de cada nodo.
// 	Node * parent; //pai de cada nodo
// 	Node * neighbor; // Vizinho a direita de um nodo. Isto é, o nodo que está ao seu lado no mesmo nível.
// };

//Por exemplo:

//				5
//		2		->		8 	-> NULL
//	1	->	3	->	6	->	11 	-> NULL

// Isto é, o vizinho de 2 é 8; de 1 é 3; de 3, 6; de 6, 11 e de 8 e 11, NULL.

// Considere que, sempre ao inserir um elemento nessa árvore, seja chamada a função setNeighbors(), 
// que define os vizinhos de cada nodo. Implemente essa função.

template <class T>
void MySet<T>::setNeighbors() {
	
}

int main() {





    return 0;
}
