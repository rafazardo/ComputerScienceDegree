#include <iostream>
#include <vector>
#include <string>

#include "ArquivoIP.h"

int main(void) {
    
    ArquivoIP ips;
    
    ips.leArquivosEntrada();
    ips.validaIP();
    ips.geraArquivoIps();
    
}