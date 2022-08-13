#ifndef MEDIANALENTA_H
#define MEDIANALENTA_H

#include <iostream>

#include "MyVecNewIterator.h"

class MedianaLenta {
public:
	void insere(int el);
	int getMediana();

private:
	MyVec<int> elems;
};

#endif