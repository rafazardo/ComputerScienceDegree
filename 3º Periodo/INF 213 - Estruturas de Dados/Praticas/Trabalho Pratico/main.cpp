/*
Capicoin Software
- Trabalho Prático 1 da Disciplina INF 213 - Estrutura de Dados
- Objetivos: praticar listas encadeadas, gerência de memória, criação de classes, hashing, etc.
- Criado por Rafael Zardo em 25/06/2022
*/

#include <iostream>
#include <string>

#include "Block.h"
#include "Blockchain.h"
#include "SHA256.h"
#include "Transaction.h"
#include "imprimeTransacoes.h"

int main() {

    std::string inputInicial;
    
    std::cin >> inputInicial;

    if (inputInicial == "operacoes") { // Parte 2 do trabalho

        std::string inputSecundario;
        Blockchain blockchainAux;

        while (std::cin >> inputSecundario) {
            
            if (inputSecundario == "criarBloco") {

                int qntdTransactions, qntdMaxTransactions, codCriador;

                std::cin >> qntdTransactions >> qntdMaxTransactions >> codCriador;

                TransactionsTemporarias arrayTransactions[qntdTransactions]; 

                for (int n = 0; n < qntdTransactions; n++) {
                    std::cin >> arrayTransactions[n].codUsuarioRemetente;
                    std::cin >> arrayTransactions[n].codUsuarioRecebedor;
                    std::cin >> arrayTransactions[n].valor;
                    std::cin >> arrayTransactions[n].taxa;
                }

                blockchainAux.createBlock(arrayTransactions, qntdTransactions, qntdMaxTransactions, codCriador);
            } 
            else if (inputSecundario == "imprimeBlockchain") {
                blockchainAux.imprimeBlockchain();
            }
            else if (inputSecundario == "imprimeSaldo") {

                int blocoMax;

                std::cin >> blocoMax;

                blockchainAux.imprimeSaldo(blocoMax);
            }
            else if (inputSecundario == "imprimeTransacoes") {
                imprimeTransacoes(blockchainAux);
            }
            else if (inputSecundario == "alteraTransacao") {

                int posBlock, posTransation, codUsuarioRemetente, codUsuarioRecebedor, valor, taxa;

                std::cin >> posBlock >> posTransation >> codUsuarioRemetente >> codUsuarioRecebedor >> valor >> taxa;

                blockchainAux.alteraTransacao(posBlock, posTransation, codUsuarioRemetente, codUsuarioRecebedor, valor, taxa);
            }
            std::cin.ignore();
        }
    }
    else { // Parte 1 do trabalho

        std::string inputSecundario;
        int pos, prevHash, codCriador, proofWork, qntdTransacoes, codUsuarioRemetente, codUsuarioRecebedor, valor, taxa;

        std::cin >> inputSecundario;

        if (inputSecundario == "validarBloco") {

            std::cin >> pos >> prevHash >> codCriador >> proofWork >> qntdTransacoes;

            Block validarBlock(pos, prevHash, codCriador, proofWork);

            for (int i = 0; i < qntdTransacoes; i++) { // Preenche o objeto Block com as transacoes inseridas pelo usuario
                std::cin >> codUsuarioRemetente >> codUsuarioRecebedor >> valor >> taxa;
                validarBlock.addTransaction(codUsuarioRemetente, codUsuarioRecebedor, valor, taxa);
            }

            validarBlock.exibirValidarBloco(); // Memsagem de output personalizada do objeto
        }
        else if(inputSecundario == "minerarBloco") {

            std::string inputTerciario;

            std::cin >> inputTerciario >> pos >> prevHash >> codCriador >> qntdTransacoes;

            Block minerarBlock(pos, prevHash, codCriador);

            for (int i = 0; i < qntdTransacoes; i++) { // Preenche o objeto Block com as transacoes inseridas pelo usuario
                std::cin >> codUsuarioRemetente >> codUsuarioRecebedor >> valor >> taxa;
                minerarBlock.addTransaction(codUsuarioRemetente, codUsuarioRecebedor, valor, taxa);
            }        

            if (inputTerciario == "quiet") {
                minerarBlock.exibirMinerarBlocoQuiet(); // Memsagem de output personalizada do objeto
            }
            else if (inputTerciario == "verbose") {
                minerarBlock.exibirMinerarBlocoVerbose(); // Memsagem de output personalizada do objeto
            }
        }
    }
}

