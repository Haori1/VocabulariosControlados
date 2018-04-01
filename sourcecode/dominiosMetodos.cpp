#ifndef ___DOMINIOS_CPP__
#define ___DOMINIOS_CPP__

#include "dominios.hpp"
#include <iostream>
#include <string>

using namespace std;


// Vamos deixar os métodos das classes, todos juntos, separando por comentário.
void Nome::validation(string nome) throw (invalid_argument){
    int tamanhoVetor = 0;

    for(int i = 0; i <= TAM_MAX_NOME; i++) { //o problema dos números mágicos é capaz de persisitir aqui.
        if(nome[i] == '\n') {
            tamanhoVetor = i;
            break;
        }
    } // Conta a quantidade de caracteres inseridos

    if(tamanhoVetor > TAM_MAX_NOME) {
        throw invalid_argument("Quantidade maxima de caracteres excedida");
    }

    if(tamanhoVetor == 0) {
        throw invalid_argument("Nao foi inserido nenhum caractere");
    }

    if(nome[0] < 'A' || nome[0] > 'Z'){ 
        throw invalid_argument("A primeira letra deve ser maiuscula.");
    } else {

        for(int i = 1; i < tamanhoVetor; i++) {
            if(nome[i] < 'a' || nome[i] > 'z') { // Existem caracteces com pontuação também, como proceder?
                throw invalid_argument("Caractere invalido inserido");
            }
        } // Testa um a um os caracteres, caso não sejam caracteres minusculos, retorna um erro
        //obs: Nas especificações do trabalho não é informado se devemos considerar somente caracteres minusculos
        //nos restantes caracteres de nome.

    }
}

void Sobrenome::validation(string sobrenome) throw (invalid_argument) {
    int tamanhoVetor = 0;

    for(int i = 0; i <= TAM_MAX_NOME; i++) { //o problema dos números mágicos é capaz de persisitir aqui.
        if(sobrenome[i] == '\n') {
            tamanhoVetor = i;
            break;
        }
    } // Conta a quantidade de caracteres inseridos

    if(tamanhoVetor > TAM_MAX_NOME) {
        throw invalid_argument("Quantidade maxima de caracteres excedida");
    }

    if(tamanhoVetor == 0) {
        throw invalid_argument("Nao foi inserido nenhum caractere");
    }

    if(sobrenome[0] < 'A' || sobrenome[0] > 'Z'){ 
        throw invalid_argument("A primeira letra deve ser maiuscula.");
    } else {

        for(int i = 1; i < tamanhoVetor; i++) {
            if(sobrenome[i] < 'a' || sobrenome[i] > 'z') { // Existem caracteces com pontuação também, como proceder?
                throw invalid_argument("Caractere invalido inserido");
            }
        }

    }
}

void Telefone::validation(string telefone) throw(invalid_argument) {
    int tamanhoVetor = 0;

    //Seria possível transformar esse código repetido de contar o tamanho do vetor e esses erros gerais, em uma função.
    for(int i = 0; i <= TAM_MAX_TELEFONE; i++) { //o problema dos números mágicos é capaz de persisitir aqui.
        if(telefone[i] == '\n') {
            tamanhoVetor = i;
            break;
        }
    } // Conta a quantidade de caracteres inseridos

    if(tamanhoVetor > TAM_MAX_NOME) {
        throw invalid_argument("Quantidade maxima de caracteres excedida");
    }

    if(tamanhoVetor == 0) { //existem aqui muitos números mágicos, como podemos resolver o problema?
        throw invalid_argument("Nao foi inserido nenhum caractere");
    }

    for(int i = 0; i < tamanhoVetor; i++){

        if(i == 2 || i == 8) {
            continue;
        }

        if(telefone[i] < '0' || telefone[i] > '9') {
            throw invalid_argument("Nao foi inserido nenhum caractere");
            break;
        }
    }

    if(telefone[2] != ' ') {
        throw invalid_argument("Fortamo Invalido. Insira o formato correto: AA BBBBB-BBBB");
    }

    if(telefone[8] != '-') {
        throw invalid_argument("Fortamo Invalido. Insira o formato correto: AA BBBBB-BBBB");
    }


} // no formato AA numero, há uma espaço entre o AA e o número, ou não?

#endif