#include <iostream>
#include <algorithm>

#include "MedianaLenta.h"

void MedianaLenta::insere(int el) {
	elems.push_back(el);
	std::sort(elems.begin(),elems.end());
}

int MedianaLenta::getMediana() {
	if(elems.size()%2) {
		return elems[elems.size()/2];
	} else {
		return (elems[elems.size()/2]+elems[(elems.size()/2)-1])/2;
	}
}


