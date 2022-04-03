#include <iostream>
#include <string>
#include <vector>

#include "Alunos.h"

bool comparaMedia(Alunos &aluno1, Alunos &aluno2);
void aplicarCripitografia(int matricula);

int main() {
    
    int matricula;
    std::string nome;
    double nota1, nota2;

    std::vector<Alunos> listaAlunos;

    while (true) {

        std::cin >> matricula;

        if (matricula == -1) {
            break;
        }

        std::cin >> nome;

        std::cin >> nota1;      

        std::cin >> nota2;        

        Alunos alunoCadastrado(matricula, nome, nota1, nota2);

        listaAlunos.push_back(alunoCadastrado);
    }
    
    std::sort(listaAlunos.begin(), listaAlunos.end(), comparaMedia);
    
    for (int i = 0; i < listaAlunos.size(); i++) {

        int variavelSuporteMatricula = listaAlunos[i].get_matricula();
        aplicarCripitografia(variavelSuporteMatricula);
        
        std::cout << " - " << listaAlunos[i].get_nome() << " - " << listaAlunos[i].get_media() << std::endl;
    }

    listaAlunos.clear(); //Libera memoria alocada do vector

    return 0;
}

bool comparaMedia(Alunos &aluno1, Alunos &aluno2) {
    return aluno1.get_media() > aluno2.get_media(); 
}

void aplicarCripitografia(int matricula) {

    matricula = ~matricula;

    int quantidadeBitsMatricula = sizeof(matricula);

    for(int i = quantidadeBitsMatricula - 1; i >= 0; i--) {
        if ( (matricula & (1<<i)) != 0) {
            std::cout << 1;
        }
        else {
            std::cout << 0; 
        }
    }
    
}
