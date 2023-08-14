
# A*
# - Trabalho Prático 2 da Disciplina INF 420 - Inteligência Artificial
# - Objetivos: praticar conceitos do algoritimo A*
# - Criado por Rafael Zardo (ES105468) em 29/04/2023
# Informacoes IMPORTANTES:
# - Comando utilizado para compilação: python3 main.py Posicao.py AEstrekaImp.py QuebraCabecaImp.py
# - Utilizado deque para armazenar os nodes por ser mais eficiente que set, list e map para o problema
# - Site utilizado para entender melhor a logica dos nodes e como utiliza-los: https://deniz.co/8-puzzle-solver/

from Posicao import Posicao
from AEstrela import AEstrela
from QuebraCabeca import QuebraCabeca
from QuebraCabecaImp import QuebraCabecaImp

import collections 
import sys

# Responsavel por criar um node inteligente para cada qc da minha arvore
# O objetivo é facilitar encontrar o pai de cada node na solução final encontrada
# Cade node e responsável por gerar o seu G(node), H(node) e F(node)
# - G(node) = distancia do node inicial ao node atual
# - H(node) =  valor do qc do node segundo uma heuristica (implementada a distancia quarterao)
# - F(node) = G(node) + H(node)
class NodeQuebraCabeca:
    def __init__(self, _qc, _pai, _movimento):
        self.qc = _qc # Armazena o tabuleiro desse node
        self.pai = _pai # Armazena o node pai desse node
        self.movimento = _movimento # Armazena o movimento utlizado para chegar nesse node
        self.G = self.gerarG() # Gera o G baseado no G de seu pai

    def gerarF(self):
        return (self.G + self.gerarH()) # F(node) = G(node) + H(node)

    def gerarH(self):
        return self.qc.getValor()    

    def gerarG(self):
        return self.pai.G + 1 if self.pai else 0

    def getQc(self):
        return self.qc.getTab()

    # Visita os pais do node solução, para traçar a rota percorrida
    # @param self NodeQuebraCabeca da solução almejada
    def fazerCaminhoAteInicio(self): 
        nodeQuebraCabeca = self
        listaMovimentos = []

        print("Solução Final: ") 
        nodeQuebraCabeca.printQc() # Print desse node para conferir se realmente e a solução final

        while nodeQuebraCabeca:
            if (nodeQuebraCabeca.movimento != None): listaMovimentos.append(nodeQuebraCabeca.movimento) # Adiciona o movimento do node na lista de movimentos
            nodeQuebraCabeca = nodeQuebraCabeca.pai

        listaMovimentos.reverse() # A solução criada e do final para o inicial, fazendo necessário inverter a lista de movimentos

        return listaMovimentos

    def encontrarMovimentos(self):
        return self.qc.getMovePossiveis()

    def verificarSeEhSolucao(self):
        return self.qc.isOrdenado()

    def gerarHash(self):
        return self.qc.hashCode()

    def printQc(self):
        return print(self.qc.toString())

    # ====== Metodo disponibilizado pelo professor adptado ======
    def getInvCount(self, arr):
        inv_count = 0
        empty_value = -1
        for i in range(0, 9):
            for j in range(i + 1, 9):
                if arr[j] != empty_value and arr[i] != empty_value and arr[i] > arr[j]:
                    inv_count += 1
        return inv_count
 
    # This function returns true
    # if given 8 puzzle is solvable.
    def isSolvable(self):
        puzzle = self.getQc()

        # Count inversions in given 8 puzzle
        inv_count = self.getInvCount([j for sub in puzzle for j in sub])
    
        # return true if inversion count is even.
        if not (inv_count % 2 == 0):
            print("Problema sem solucão! \n") # Se chegar aqui não existe solução e finaliza o programa
            sys.exit()

        return # Se chegou aqui e por existe solução
    # ===========================================================
    

class AEstrelaImp(AEstrela):

    def getSolucao(self, qc):
        nodeInicial = NodeQuebraCabeca(qc,None,None)
        nodeInicial.isSolvable() # Verifica se o qc possui solução

        nodesQuebraCabeca = collections.deque([nodeInicial]) # Criar uma deque, mais eficiente que uma queue e adicionar o primeiro node (qc inicial)

        nodesFechados = set()
        nodesFechados.add(nodesQuebraCabeca[0].gerarHash()) # Adiciona o primeiro node na lista de ja visitados (identificação utilizando hash)

        while len(nodesQuebraCabeca) != 0:
            nodesQuebraCabecaOrdenado = sorted(list(nodesQuebraCabeca), key=lambda NodeQuebraCabeca: NodeQuebraCabeca.gerarF()) # Transforma a deque em uma lista e ordena ela do maior para o menos baseado em F
            nodesQuebraCabeca = collections.deque(nodesQuebraCabecaOrdenado) # Transforma a lista recem ordenada em uma deque novamente

            melhorNodeQuebraCabeca = nodesQuebraCabeca.popleft() # Pega o primeiro elemento da deque e o remove (pega o node e melhor f, ou seja, menor f)

            if melhorNodeQuebraCabeca.verificarSeEhSolucao(): # Se chegamos numa solucão podemos visitar o pai de cade node para obter o caminho dessa solução
                return melhorNodeQuebraCabeca.fazerCaminhoAteInicio()

            for movimento in melhorNodeQuebraCabeca.encontrarMovimentos(): # Visita os vizinhos do melhor node atual
                tempQuebraCabeca = QuebraCabecaImp()
                tempQuebraCabeca.setTab(melhorNodeQuebraCabeca.getQc()) # Gera uma copia do qc do melhor node atual

                posVazio = tempQuebraCabeca.getPosVazio()
                tempQuebraCabeca.move(posVazio.getLinha(),posVazio.getColuna(),movimento.getLinha(),movimento.getColuna()) # Realiza o movimento possivel no qc temporario

                filhoMelhorNodeQuebraCabeca = NodeQuebraCabeca(tempQuebraCabeca,melhorNodeQuebraCabeca,movimento) # Cria um node para o vizinho

                if filhoMelhorNodeQuebraCabeca.gerarHash() not in nodesFechados: # Se esse node vizinho criado nao foi visitado ainda...
                    nodesQuebraCabeca.appendleft(filhoMelhorNodeQuebraCabeca) # Adiciona na lista de nodes abertos
                    nodesFechados.add(filhoMelhorNodeQuebraCabeca.gerarHash()) # Marca o node como fechado, ja que o mesmo foi inserido na lista de nodes abertos
                
       


