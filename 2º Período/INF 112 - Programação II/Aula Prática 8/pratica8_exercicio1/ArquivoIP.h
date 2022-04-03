#ifndef INF112_ARQUIVOIP_H
#define INF112_ARQUIVOIP_H

#include <iostream>
#include <vector>
#include <string>

class ArquivoIP {

private:
    std::vector<std::string> _ips;
    std::vector<std::string> _ipsValidos;
    std::vector<std::string> _ipsNaoValidos;

public:
    ArquivoIP();
    ~ArquivoIP();

    std::vector<std::string> get_ips();
    std::vector<std::string> get_ipsValidos();
    std::vector<std::string> get_ipsNaoValidos();

    void set_ips(std::string addIP, int addPosicao);
    void set_ipsValidos(std::string addIPValidos, int addPosicao);
    void set_ipsNaoValidos(std::string addIPNaoValidos, int addPosicao);

    void leArquivosEntrada();
    void validaIP();
    void geraArquivoIps();

};


#endif