#ifndef INF112_SOMA_H
#define INF112_SOMA_H

class Soma {
    
private:
    int _m;
    int _n;

public:
    Soma(int addM, int addN);
    ~Soma();

    int get_m();
    int get_n();

    int aplicaSoma(int addM, int addN);
};

#endif