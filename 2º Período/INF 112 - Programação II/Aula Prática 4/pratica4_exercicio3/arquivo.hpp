class Aquecedor {

private:
    double _temperatura;
    double _temperaturaMinima;
    double _temperaturaMaxima;
    double _temperaturaFatorDeIncremento;

public:
    Aquecedor();
    Aquecedor(double addTemperaturaInicial);
    Aquecedor(double addTemperaturaInicial, double addTemperaturaFatorDeIncremento);
    double getTemperatura();
    void aquecer();
    void esfriar();
    void setFatorDeIncrementoDaTemperatura(double addFatorDeIncrementoDaTemperatura);
};