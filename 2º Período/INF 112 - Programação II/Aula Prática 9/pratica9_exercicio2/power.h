#ifndef INF112_POWER_H
#define INF112_POWER_H

class power {

private:
    int _k;
    int _n;

public:
    power(int addK, int addN);
    ~power();

    int get_k();
    int get_n();

    int powerExponencial(int addK, int addN);
};

#endif