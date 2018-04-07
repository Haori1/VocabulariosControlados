#include "testes.hpp"
#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>

/*---------------------------------------------------------------------------*/

void TNome::setUp(){
    nome = new Nome();
    estado = SUCESSO;
}

void TNome::tearDown(){
    delete nome;
}

void TNome::casoSucesso(){
    try{
        nome->setNome(Valor_Valido_Nome);
        if(nome->getNome() != Valor_Valido_Nome)
            estado = FALHA;
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
        estado = FALHA;
    } catch (invalid_argument) {
        return;
    }
}

bool TNome::run(){
    setUp();
    casoSucesso();
    casoFalha();
    tearDown();
    return estado;
}

/*---------------------------------------------------------------------------*/

void TData::setUp(){
    data = new Data();
    estado = SUCESSO;
}

void TData::tearDown(){
    delete data;
}

void TData::casoSucesso(){
    try{
        data->setData(Valor_Valido_Data);
        if(data->getData() != Valor_Valido_Data)
            estado = FALHA;
    } catch (invalid_argument) {
        return;
    }
}

void TData::casoFalha(){
    try{
        data->setData(Valor_Invalido_Data);
        estado = FALHA;
    } catch (invalid_argument) {
        return;
    }
}

bool TData::run(){
    setUp();
    casoSucesso();
    casoFalha();
    tearDown();
    return estado;
}
