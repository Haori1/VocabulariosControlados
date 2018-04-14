#include <iostream>
#include <string>
#include "dominiosClasses.hpp"
#include "testes.hpp"
#include "entidadesClasses.hpp"

int main(void) {
    bool executou;

    TNome nome;
    executou = nome.run();
    if(executou){
        cout << "SUCESSO" << endl;
    } else {
        cout << "FALHA" << endl;
    }

    TSobrenome sobrenome;
    executou = sobrenome.run();
    if(executou){
        cout << "SUCESSO" << endl;
    } else {
        cout << "FALHA" << endl;
    }

    TTelefone telefone;
    executou = telefone.run();
    if(executou){
        cout << "SUCESSO" << endl;
    } else {
        cout << "FALHA" << endl;
    }

    TEndereco endereco;
    executou = endereco.run();
    if(executou){
        cout << "SUCESSO" << endl;
    } else {
        cout << "FALHA" << endl;
    }

    TData data;
    executou = data.run();
    if(executou){
        cout << "SUCESSO" << endl;
    } else {
        cout << "FALHA" << endl;
    }

    TCorreio_Eletronico correio_eletronico;
    executou = correio_eletronico.run();
    if(executou){
        cout << "SUCESSO" << endl;
    } else {
        cout << "FALHA" << endl;
    }

    TSenha senha;
    executou = senha.run();
    if(executou){
        cout << "SUCESSO" << endl;
    } else {
        cout << "FALHA" << endl;
    }

    TTexto_Definicao texto_definicao;
    executou = texto_definicao.run();
    if(executou){
        cout << "SUCESSO" << endl;
    } else {
        cout << "FALHA" << endl;
    }

    TIdioma idioma;
    executou = idioma.run();
    if(executou){
        cout << "SUCESSO" << endl;
    } else {
        cout << "FALHA" << endl;
    }

    TClasse_Termo classe_termo;
    executou = classe_termo.run();
    if(executou){
        cout << "SUCESSO" << endl;
    } else {
        cout << "FALHA" << endl;
    }

    Nome nomeTeste;
    Senha senhaTeste;

    nomeTeste.set_nome("eaemen");
    senhaTeste.set_senha("1eaemen");

    Leitor leitor;

    leitor.set_nome(nomeTeste);

    try {
        leitor.set_senha(senhaTeste);
    }catch(invalid_argument) {
        printf("Deu certo, capturei a senha contida no nome.");
    }

    return 0;
}
