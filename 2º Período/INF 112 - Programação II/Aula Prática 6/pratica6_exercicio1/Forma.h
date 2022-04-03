#ifndef INF112_FORMA_H
#define INF112_FORMA_H

#include <iostream>
#include <iomanip>
#include <string>

class Forma {
private:

public:
    virtual std::string get_cor() = 0;
    virtual std::string get_nome() = 0;

};

#endif