#include <iostream>

#include "mdc.h"

mdc::mdc(int addX, int addY):
    _x(addX), _y(addY) {} ;

mdc::~mdc() {}

int mdc::get_x() {
    return this->_x;
}

int mdc::get_y() {
    return this->_y;
}

int mdc::encontraMDC(int addX, int addY) {
    
    if (addX % addY == 0) {
        return addY;
    }
    else {
        return encontraMDC(addY, addX % addY);
    }
    
}