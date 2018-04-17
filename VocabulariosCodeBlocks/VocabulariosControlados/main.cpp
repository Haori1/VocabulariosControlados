#include <iostream>
#include <string>

#include "dominios.hpp"
#include "testes.hpp"
#include "entidades.hpp"

int main(void) {
    bool executou;

    TNome nome;
    executou = nome.Run();
    if(executou){
        cout << "SUCESSO" << endl;
    } else {
        cout << "FALHA" << endl;
    }

    TSobrenome sobrenome;
    executou = sobrenome.Run();
    if(executou){
        cout << "SUCESSO" << endl;
    } else {
        cout << "FALHA" << endl;
    }

    TTelefone telefone;
    executou = telefone.Run();
    if(executou){
        cout << "SUCESSO" << endl;
    } else {
        cout << "FALHA" << endl;
    }

    TEndereco endereco;
    executou = endereco.Run();
    if(executou){
        cout << "SUCESSO" << endl;
    } else {
        cout << "FALHA" << endl;
    }

    TData data;
    executou = data.Run();
    if(executou){
        cout << "SUCESSO" << endl;
    } else {
        cout << "FALHA" << endl;
    }

    TCorreio_Eletronico correio_eletronico;
    executou = correio_eletronico.Run();
    if(executou){
        cout << "SUCESSO" << endl;
    } else {
        cout << "FALHA" << endl;
    }

    TSenha senha;
    executou = senha.Run();
    if(executou){
        cout << "SUCESSO" << endl;
    } else {
        cout << "FALHA" << endl;
    }

    TTexto_Definicao texto_definicao;
    executou = texto_definicao.Run();
    if(executou){
        cout << "SUCESSO" << endl;
    } else {
        cout << "FALHA" << endl;
    }

    TIdioma idioma;
    executou = idioma.Run();
    if(executou){
        cout << "SUCESSO" << endl;
    } else {
        cout << "FALHA" << endl;
    }

    TClasse_Termo classe_termo;
    executou = classe_termo.Run();
    if(executou){
        cout << "SUCESSO" << endl;
    } else {
        cout << "FALHA" << endl;
    }

    TLeitor leitor;
    executou = leitor.Run();
    if(executou){
        cout << "SUCESSO" << endl;
    } else {
        cout << "FALHA" << endl;
    }

    TDesenvolvedor desenvolvedor;
    executou = leitor.Run();
    if(executou){
        cout << "SUCESSO" << endl;
    } else {
        cout << "FALHA" << endl;
    }


    TAdministrador administrador;
    executou = administrador.Run();
    if(executou){
        cout << "SUCESSO" << endl;
    } else {
        cout << "FALHA" << endl;
    }

    TVocControlado voccontrolado;
    executou = voccontrolado.Run();
    if(executou){
        cout << "SUCESSO" << endl;
    } else {
        cout << "FALHA" << endl;
    }

    TTermo termo;
    executou = termo.Run();
    if(executou){
        cout << "SUCESSO" << endl;
    } else {
        cout << "FALHA" << endl;
    }

    TDefinicao definicao;
    executou = definicao.Run();
    if(executou){
        cout << "SUCESSO" << endl;
    } else {
        cout << "FALHA" << endl;
    }

    return 0;
}
