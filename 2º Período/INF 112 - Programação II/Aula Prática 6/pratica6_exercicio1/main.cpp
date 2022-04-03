#include <iostream>
#include <iomanip>
#include <string>

#include "Circulo.h"
#include "Cubo.h"
#include "Esfera.h"
#include "Forma.h"
#include "Forma2D.h"
#include "Forma3D.h"
#include "Quadrado.h"
#include "Triangulo.h"

int main() {

    //lado, nome, cor
    Quadrado q(2.0, "Quadrado", "Vermelho");

    //raio, nome, cor
    Circulo c(3.0, "Circulo", "Azul");

    //lado 1, lado 2, lado 3/base, altura, nome, cor
    Triangulo t1(7.0, 3.0, 4.0, 2.0, "Triangulo Escaleno", "Amarelo");

     //lado 1/lado 2, lado 3/base, altura, nome, cor
    Triangulo t2(3.0, 4.0, 2.0, "Triangulo Isosceles", "Rosa");

    // lado 1/ base , altura , nome , cor
    Triangulo t3(7.0,2.0, "Triangulo Equilatero", "Verde");

    //raio, nome, cor
    Esfera e(6.0,"Esfera", "Branco");
    
    //lado, nome, cor
    Cubo cb(9.0,"Cubo", "Preto");

    std::cout << "Area: " << q.get_area() << " - Perimetro: " << q. get_perimetro() << " - Nome: " << q.get_nome() << " - Cor: " << q. get_cor() << std::endl;
    std::cout << "Area: " << c.get_area() << " - Perimetro: " << c. get_perimetro() << " - Nome: " << c.get_nome() << " - Cor: " << c. get_cor() << std::endl;
    std::cout << "Area: " << t1.get_area() << " - Perimetro: " << t1. get_perimetro() << " - Nome: " << t1.get_nome() << " - Cor: " << t1. get_cor() << std::endl;
    std::cout << "Area: " << t2.get_area() << " - Perimetro: " << t2. get_perimetro() << " - Nome: " << t2.get_nome() << " - Cor: " << t2. get_cor() << std::endl;
    std::cout << "Area: " << t3.get_area() << " - Perimetro: " << t3. get_perimetro() << " - Nome: " << t3.get_nome() << " - Cor: " << t3. get_cor() << std::endl;
    std::cout << "Volume: " << e.get_volume() << " - Nome: " << e.get_nome() << " - Cor: " << e.get_cor() << std::endl;
    std::cout << "Volume: " << cb.get_volume() << " - Nome: " << cb.get_nome() << " - Cor: " << cb.get_cor() << std::endl;

    return 0;
}