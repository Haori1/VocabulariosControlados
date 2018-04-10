#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>

#include "entidadesClasses.hpp"

void Leitor::validation(const Senha &senha) throw(invalid_argument){

    Senha teste_Senha;

    teste_Senha = senha;

    string nome_Leitor = nome.getNome();
    string senha_String = teste_Senha.getSenha();

    int tamanho_Nome = nome_Leitor.size();
    int tamanho_Senha = senha_String.size();

    int contador = 0;

    for(int i = 0; i < tamanho_Senha; i++){ //ponto inicial da senha
        for(int j = 0; j < tamanho_Nome; j++){ //percorre o tamanho do nome
            if(senha_String[i + j] == nome_Leitor[j]) {
                contador++; //Conta quantos caracteres são iguais, pois caso a quantidade seja o tamanho do nome, temos um nome contido na senha.
            }
        }
        if(contador == tamanho_Nome) {
            throw invalid_argument("Senha invalida. O nome não pode estar contido na senha.");
        }
        if((tamanho_Senha - i) < tamanho_Nome) {
            break;
        } //Verifica se há menos caracteres a serem checados do que a quantidade de caracteres que o nome possui. Caso sim, para o laço.
        contador = 0;
    }
}

void Leitor::setSenha(const Senha &senha) throw(invalid_argument){
    validation(senha);

    this->senha = senha;
}
