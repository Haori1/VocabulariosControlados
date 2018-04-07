#include "testes.hpp"
#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>

/*---------------------------------------------------------------------------*/

void TNome::setUp(){
    nome = new Nome();
    estado = sucesso;
}

void TNome::tearDown(){
    delete nome;
}

void TNome::casoSucesso(){
    try{
        nome->setNome(Valor_Valido_Nome);
        if(nome->getNome() != Valor_Valido_Nome)
            estado = falha;
    } catch (invalid_argument) {
        return;
    }
}

void TNome::casoFalha(){
    try{
        nome->setNome(Valor_Invalido_Nome_1);
        nome->setNome(Valor_Invalido_Nome_2);
        nome->setNome(Valor_Invalido_Nome_3);
        nome->setNome(Valor_Invalido_Nome_4);
        estado = falha;
    } catch (invalid_argument) {
        return;
    }
} //Acredito que deve ser separado, pois o teste deve validar todos os casos propostos, e não somente um.

bool TNome::run(){
    setUp();
    casoSucesso();
    casoFalha();
    tearDown();
    return estado;
}











/*---------------------------------------------------------------------------*/
