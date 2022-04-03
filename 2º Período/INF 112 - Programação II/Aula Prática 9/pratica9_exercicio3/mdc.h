#ifndef INF112_MDC_H
#define INF112_MDC_H

class mdc {
private:
    int _x;
    int _y;

public:
    mdc(int addX, int addY);
    ~mdc();

    int get_x();
    int get_y();

    int encontraMDC(int addX, int addY);
};

#endif