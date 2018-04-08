#include <iostream>
#include <string>
#include "dominiosClasses.hpp"
#include "testes.hpp"

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
    return 0;
}
