#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>

#include "entidades.hpp"

void Leitor::Validation(const Senha &senha) throw(invalid_argument)
{

    Senha teste_Senha;

    teste_Senha = senha;

    string nome_leitor = nome.get_nome();
    string senha_string = teste_Senha.get_senha();

    int tamanho_nome = nome_leitor.size();
    int tamanho_senha = senha_string.size();

    int contador = 0;

    for(int i = 0; i < tamanho_senha; i++)  //ponto inicial da senha
    {
        for(int j = 0; j < tamanho_nome; j++)  //percorre o tamanho do nome
        {
            if((senha_string[i + j] == nome_leitor[j])                        ||
                    (senha_string[i + j] == (nome_leitor[j] - CONVERTE_MAIUSCULA)) ||
                    ((senha_string[i + j] - CONVERTE_MAIUSCULA) == nome_leitor[j]))
            {
                contador++; //Conta quantos caracteres sao iguais, pois caso a quantidade seja o tamanho do nome, temos um nome contido na senha.
            }
        }
        if(contador == tamanho_nome)
        {
            throw invalid_argument("Senha invalida. O nome nao pode estar contido na senha.");
        }
        if((tamanho_senha - i) < tamanho_nome)
        {
            break;
        } //Verifica se ha menos caracteres a serem checados do que a quantidade de caracteres que o nome possui. Caso sim, para o laco.
        contador = 0;
    }
}

void Leitor::set_senha(const Senha &senha) throw(invalid_argument)
{
    Validation(senha);

    this->senha = senha;
}
