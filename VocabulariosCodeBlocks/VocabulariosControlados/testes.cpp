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
        nome->setNome(Valor_Invalido_Nome_5);

        estado = FALHA;
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
void TSobrenome::setUp(){
    sobrenome = new Sobrenome();
    estado = SUCESSO;
}

void TSobrenome::tearDown(){
    delete sobrenome;
}

void TSobrenome::casoSucesso(){
    try{
        sobrenome->setSobrenome(Valor_Valido_Sobrenome);
        if(sobrenome->getSobrenome() != Valor_Valido_Sobrenome)
            estado = FALHA;
    } catch (invalid_argument) {
        return;
    }
}

void TSobrenome::casoFalha(){
    try{
        sobrenome->setSobrenome(Valor_Invalido_Sobrenome_1);
        sobrenome->setSobrenome(Valor_Invalido_Sobrenome_2);
        sobrenome->setSobrenome(Valor_Invalido_Sobrenome_3);
        sobrenome->setSobrenome(Valor_Invalido_Sobrenome_4);
        sobrenome->setSobrenome(Valor_Invalido_Sobrenome_5);

        estado = FALHA;
    } catch (invalid_argument) {
        return;
    }
} //Acredito que deve ser separado, pois o teste deve validar todos os casos propostos, e não somente um.

bool TSobrenome::run(){
    setUp();
    casoSucesso();
    casoFalha();
    tearDown();
    return estado;
}

/*---------------------------------------------------------------------------*/

void TTelefone::setUp(){
    telefone = new Telefone();
    estado = SUCESSO;
}

void TTelefone::tearDown(){
    delete telefone;
}

void TTelefone::casoSucesso(){
    try{
        telefone->setTelefone(Valor_Valido_Telefone);
        if(telefone->getTelefone() != Valor_Valido_Telefone)
            estado = FALHA;
    } catch (invalid_argument) {
        return;
    }
}

void TTelefone::casoFalha(){
    try{
        telefone->setTelefone(Valor_Invalido_Telefone_1);
        telefone->setTelefone(Valor_Invalido_Telefone_2);
        telefone->setTelefone(Valor_Invalido_Telefone_3);
        telefone->setTelefone(Valor_Invalido_Telefone_4);
        telefone->setTelefone(Valor_Invalido_Telefone_5);
        telefone->setTelefone(Valor_Invalido_Telefone_6);


        estado = FALHA;
    } catch (invalid_argument) {
        return;
    }
}

bool TTelefone::run(){
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
