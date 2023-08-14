/*
Fantastic Bits 
- Trabalho Prático 1 da Disciplina INF 420 - Inteligência Artificial
- Objetivos: praticar conceitos de multi-agent
- Criado por Rafael Zardo em 07/04/2023
*/

/*
Informacoes IMPORTANTES:
- O nome utilizado na plataforma foi: rafazardo
- Os prints da classificação estão anexados neste zip
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdlib.h>     
#include <time.h> 

using namespace std;

// Calcula distancia euclediana de dois pontos
int getDistance(int x1, int y1, int x2, int y2) {
    return sqrt(pow((x2 - x1),2.0) + pow((y2 - y1),2.0));
}

// Elementos do nosso sistemas multi-agent
struct element {
    int entityId, positionX, positionY, velocityX, velocityY; 
    int state; // Caso o estado for 1, o elemento esta carregando o snaffle, caso 0 o mesmo não esta
    int mapGoalX, mapGoalY = 3750;
    int mapDefenseX, mapDefenseY = 3750;

    // Constroi o elemento baseado nos seus parâmetros
    void setElement(int _entityId, int _positionX, int _positionY, int _velocityX, int _velocityY, int _state, int _myTeamId) {
        entityId = _entityId;
        positionX = _positionX; positionY = _positionY; 
        velocityX = _velocityX; velocityY = _velocityY; 
        state = _state;

        // Ao criar um elemento, o mapa do mesmo é definido
        setMap(_myTeamId);
    }  

    // Define o mapa de acordo com o lado do jogador
    void setMap(int _myTeamId)  {
        if (_myTeamId == 0) {
            mapGoalX = 16000;
            mapDefenseX = 0;
        } else {
            mapGoalX = 0;
            mapDefenseX = 16000;
        }
    }
};

// Mago voltado para a estratégia de ataque
struct attackWizzard : element {
    // Mago atacante ira jogar a bola coma a força maxima para o gol
    void attackToGoal() {
        std::cout << "THROW " << mapGoalX << " " << mapGoalY << " " << 500 << endl;
    }

    // Mago atacante ira para bola mais proxima a ele
    void moveToAttack(vector<element> _snaffles) {
        int shortDistance = 100000000;
        int posToAttackX, posToAttackY;

        // Percorre por todos snaffles buscando o de menor distancia
        for (element item : _snaffles) {
            if (shortDistance > getDistance(item.positionX,item.positionY,positionX,positionY)){
                shortDistance = getDistance(item.positionX,item.positionY,positionX,positionY);

                posToAttackX = item.positionX; posToAttackY = item.positionY;
            } 
        }
            
        std::cout << "MOVE " << posToAttackX << " " << posToAttackY << " " << 150 << endl;
    }    
};

// Mago voltado para a estratégia de defesa
struct defenseWizzard : element {
    // Mago defensor ira jogar a bola coma a força maxima para o atacante, caso o mesmo esteja perto ira jogar a bola para o gol com força maxima
    void attackToAttacker(attackWizzard _botAttack) {
        if (getDistance(positionX, _botAttack.positionX, positionY, _botAttack.velocityY) > 2500) std::cout << "THROW " << _botAttack.positionX << " " << _botAttack.positionY << " " << 500 << endl;
        else std::cout << "THROW " << mapGoalX << " " << mapGoalY << " " << 500 << endl;
    }

    // Mago defensor ira atrás da bola ate um limite do campo, caso ultrapasse o limite o mesmo voltara para posição de defesa
    void moveToDefense(vector<element> _snaffles) {
        int posToDefenseX, posToDefenseY; 
        int shortDistance = 100000000;

        // Percorre por todos snaffles buscando o de menor distancia
        for (element item : _snaffles) {
            if (shortDistance > getDistance(item.positionX, item.positionY, positionX, positionY)){
                shortDistance = getDistance(item.positionX, item.positionY, positionX,positionY);
                
                posToDefenseX = item.positionX; posToDefenseY = item.positionY;
            } 
        }

        // Verifica o lado do jogador e define o limite de campo para o defensor
        if (mapDefenseX == 0) {
            if (posToDefenseX < abs(mapDefenseX - 6500)) {
                std::cout << "MOVE " << posToDefenseX << " " << posToDefenseY << " " << 150 << endl;
            } else {
                posToDefenseX = abs(mapDefenseX - 2000); posToDefenseY = mapDefenseY;
                std::cout << "MOVE " << posToDefenseX << " " << posToDefenseY << " " << 150 << endl;
            } 
        } else {
            if (posToDefenseX > abs(mapDefenseX - 6500)) {
                std::cout << "MOVE " << posToDefenseX << " " << posToDefenseY << " " << 150 << endl;
            } else {
                posToDefenseX = abs(mapDefenseX - 2000); posToDefenseY = mapDefenseY;
                std::cout << "MOVE " << posToDefenseX << " " << posToDefenseY << " " << 150 << endl;
            }
        }
    }    
};

int main() {
    int myTeamId; 
    cin >> myTeamId; cin.ignore();

    // Loop gerador do jogo
    while (1) {
        int my_score;
        int my_magic; 
        
        cin >> my_score >> my_magic; cin.ignore();

        int opponent_score;
        int opponent_magic; 
        cin >> opponent_score >> opponent_magic; cin.ignore();

        int entities; 
        cin >> entities; cin.ignore();

        int numBots = 0;
        attackWizzard botAttack;
        defenseWizzard botDefense;

        vector<element> opponentWizzards;
        vector<element> snaffles;

        for (int i = 0; i < entities; i++) {
            string entityType; 
            int entityId, positionX, positionY, velocityX, velocityY; 
            int state; 

            cin >> entityId >> entityType >> positionX >> positionY; 
            cin >> velocityX >> velocityY >> state; cin.ignore();

            if (entityType == "WIZARD") {
                // Garante que o mesmo bot sempre sera o atacante e defensor
                if (numBots == 0) {
                    botAttack.setElement(entityId, positionX, positionY, velocityX, velocityY, state, myTeamId);
                    numBots++;
                } else { 
                    botDefense.setElement(entityId, positionX, positionY, velocityX, velocityY, state, myTeamId);
                }
            } else if (entityType == "OPPONENT_WIZARD") {
                element opponentWizzard;

                opponentWizzard.setElement(entityId, positionX, positionY, velocityX, velocityY, state, myTeamId);
                opponentWizzards.push_back(opponentWizzard);
            } else {
                element snaffle;

                snaffle.setElement(entityId, positionX, positionY, velocityX, velocityY, state, myTeamId);
                snaffles.push_back(snaffle);
            }
        }

        // Iniciando metodos de atacante baseado no estado
        if (botAttack.state) botAttack.attackToGoal();
        else botAttack.moveToAttack(snaffles);
        
        // Iniciando metodos de defensorbaseado no estado
        if (botDefense.state)botDefense.attackToAttacker(botAttack);
        else botDefense.moveToDefense(snaffles);
    }
}