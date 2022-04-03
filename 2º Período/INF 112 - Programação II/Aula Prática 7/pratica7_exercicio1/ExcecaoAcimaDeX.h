#ifndef INF112_EXCECAOACIMADEX_H
#define INF112_EXCECAOACIMADEX_H

#include <iostream>
#include <stdexcept>

class ExcecaoAcimaDeX : public std::exception {

public:
    virtual const char* what() const noexcept override;
    
};

#endif

