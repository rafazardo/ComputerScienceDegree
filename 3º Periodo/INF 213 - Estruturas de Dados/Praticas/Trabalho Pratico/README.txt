Eu li as regras

=== Informacoes Pessoais ===

Nome: Rafael Zardo Crevelari
Matricula: 105468

=== Refêrencias ===

[1] - https://github.com/rafazardo/ComputerScienceDegree/tree/main/2%C2%BA%20Per%C3%ADodo/INF%20112%20-%20Programa%C3%A7%C3%A3o%20II

Utilizei meu repositorio do GitHub que continha todas as minhas praticas/provas/trabalhos da materia INF112 - Programacao II, para 
revisar conceitos e boas praticas de programacao orientada a objetos.

[2] - Pratica 6 INF 213

Utilizei essa pratica que continha todo o meu codigo implementada no MyList, para revisar conceitos e boas praticas sobre o assunto 
de lista simplesmente encadeada.

[3] - https://www.youtube.com/watch?v=8HsJu50IFAc&t=1s 

Utilizei o video para intender o conceito de complemento de 1 e complemento de 2, para transformar numeros negativos em binários.

[4] - https://cplusplus.com/reference/algorithm/stable_sort/

Utilizei a funcao stable_sort para organizar de forma 100% estavel meu codigo, utilizei o link como referencia

=== Respostas ===

Pergunta 1: 
Dadas duas blockchains válidas (onde cada bloco contém o hash correto do bloco anterior), 
é possível ver se as duas são iguais de forma muito eficiente: basta comparar o hash do 
último bloco das duas. Por que isso “garante” a igualdade?

Resposta:
Pois o hash do ultimo bloco, esta ligado diretamente ao hash do bloco passado (prevHash), e assim por diante ate o primeiro bloco,
como o calculo do hash depende do prevHash, assim temos que dois blockchains sao iguais se o ultimo bloco deles possuem hash iguais,
umas vez que o hash de um bloco esta interligado com o seu antecessor.

Pergunta 2:
Pergunta: quantas Capicoins existirão no mundo? (supondo que aceitamos apenas valores inteiros, o primeiro bloco recompensa 256 
Capicoins e esse valor cai pela metade a cada novo bloco).

Resposta:
Sabendo que o halving do Capcoin ocorre a cada 1 bloco, e so é aceito valores inteiros, temos as seguintes recompensas:
1 Bloco: 256
2 Bloco: 128
3 Bloco: 64
4 Bloco: 32
5 Bloco: 16
6 Bloco: 8
7 Bloco: 4
8 Bloco: 2
9 Bloco: 1
10 Bloco: 0
a partir disso todos os proximos blocos terao recompensa zero.
Logo a quantidade de Capcoins no mundo se resume a soma de todas as recompensa de cada bloco, em que temos:
256 + 128 + 64 + 32 + 16 + 8 + 4 + 2 + 1 = 511
ASsim teremos 511 Capcoins no mundo.
