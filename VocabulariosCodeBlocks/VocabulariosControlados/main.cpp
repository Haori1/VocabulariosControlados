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

    TLeitor leitor;
    executou = leitor.run();
    if(executou){
        cout << "SUCESSO" << endl;
    } else {
        cout << "FALHA" << endl;
    }

    TDesenvolvedor desenvolvedor;
    executou = leitor.run();
    if(executou){
        cout << "SUCESSO" << endl;
    } else {
        cout << "FALHA" << endl;
    }


    TAdministrador administrador;
    executou = administrador.run();
    if(executou){
        cout << "SUCESSO" << endl;
    } else {
        cout << "FALHA" << endl;
    }

    TVocControlado voccontrolado;
    executou = voccontrolado.run();
    if(executou){
        cout << "SUCESSO" << endl;
    } else {
        cout << "FALHA" << endl;
    }

    TTermo termo;
    executou = termo.run();
    if(executou){
        cout << "SUCESSO" << endl;
    } else {
        cout << "FALHA" << endl;
    }

    TDefinicao definicao;
    executou = definicao.run();
    if(executou){
        cout << "SUCESSO" << endl;
    } else {
        cout << "FALHA" << endl;
    }
    
    return 0;
}
