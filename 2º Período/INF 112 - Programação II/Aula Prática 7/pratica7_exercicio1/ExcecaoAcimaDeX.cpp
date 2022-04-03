#include <iostream>
#include <stdexcept>

#include "ExcecaoAcimaDeX.h"

const char* ExcecaoAcimaDeX::what() const noexcept {
    return "Erro: A soma ultrapassou o valor de X!";
}

