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
        estado = FALHA;
        nome->setNome(Valor_Invalido_Nome_2);
        estado = FALHA;
        nome->setNome(Valor_Invalido_Nome_3);
        estado = FALHA;
        nome->setNome(Valor_Invalido_Nome_4);
        estado = FALHA;
        nome->setNome(Valor_Invalido_Nome_5);
        estado = FALHA;
    } catch (invalid_argument) {
        return;
    }
} //Acredito que deve ser separado, pois o teste deve validar todos os casos propostos, e n�o somente um.

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
        estado = FALHA;
        sobrenome->setSobrenome(Valor_Invalido_Sobrenome_2);
        estado = FALHA;
        sobrenome->setSobrenome(Valor_Invalido_Sobrenome_3);
        estado = FALHA;
        sobrenome->setSobrenome(Valor_Invalido_Sobrenome_4);
        estado = FALHA;                                     /*Sera que assim funfa?*/
        sobrenome->setSobrenome(Valor_Invalido_Sobrenome_5);
        estado = FALHA;
    } catch (invalid_argument) {
        return;
    }
} //Acredito que deve ser separado, pois o teste deve validar todos os casos propostos, e nao somente um.

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
        estado = FALHA;
        telefone->setTelefone(Valor_Invalido_Telefone_2);
        estado = FALHA;
        telefone->setTelefone(Valor_Invalido_Telefone_3);
        estado = FALHA;
        telefone->setTelefone(Valor_Invalido_Telefone_4);
        estado = FALHA;
        telefone->setTelefone(Valor_Invalido_Telefone_5);
        estado = FALHA;
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

void TEndereco::setUp(){
    endereco = new Endereco();
    estado = SUCESSO;
}

void TEndereco::tearDown(){
    delete endereco;
}

void TEndereco::casoSucesso(){
    try {
        endereco->setEndereco(Valor_Valido_Endereco);
        if(endereco->getEndereco() != Valor_Valido_Endereco) {
            estado = FALHA;
        }
    } catch (invalid_argument){
        return;
    }
}

void TEndereco::casoFalha(string teste){
    try {

        if(teste == Valor_Invalido_Endereco_1) {
            endereco->setEndereco(Valor_Invalido_Endereco_1);
            estado = FALHA;
        }
        if(teste == Valor_Invalido_Endereco_2) {
            endereco->setEndereco(Valor_Invalido_Endereco_2);
            estado = FALHA;
        }
        if(teste == Valor_Invalido_Endereco_3) {
            endereco->setEndereco(Valor_Invalido_Endereco_3);
            estado = FALHA;
        }
        if(teste == Valor_Invalido_Endereco_4) {
            endereco->setEndereco(Valor_Invalido_Endereco_4);
            estado = FALHA;
        }
        if(teste == Valor_Invalido_Endereco_5) {
            endereco->setEndereco(Valor_Invalido_Endereco_5);
            estado = FALHA;
        }
        if(teste == Valor_Invalido_Endereco_6) {
            endereco->setEndereco(Valor_Invalido_Endereco_6);
            estado = FALHA;
        }
    } catch (invalid_argument) {
        return;
    }
}

bool TEndereco::run(){
    setUp();
    casoSucesso();
    casoFalha(Valor_Invalido_Endereco_1);
    casoFalha(Valor_Invalido_Endereco_2);
    casoFalha(Valor_Invalido_Endereco_3);
    casoFalha(Valor_Invalido_Endereco_4);
    casoFalha(Valor_Invalido_Endereco_5);
    casoFalha(Valor_Invalido_Endereco_6);
    tearDown();
    return estado;
}


/*---------------------------------------------------------------------------*/


void TCorreio_Eletronico::setUp(){
    correio_eletronico = new Correio_Eletronico();
    estado = SUCESSO;
}

void TCorreio_Eletronico::tearDown(){
    delete correio_eletronico;
}

void TCorreio_Eletronico::casoSucesso(){
    try{
        correio_eletronico->setCorreio_Eletronico(Valor_Valido_Correio_Eletronico);
        if(correio_eletronico->getCorreio_Eletronico() != Valor_Valido_Correio_Eletronico)
            estado = FALHA;
    } catch (invalid_argument) {
        return;
    }
}

void TCorreio_Eletronico::casoFalha(){
    try{
        correio_eletronico->setCorreio_Eletronico(Valor_Invalido_Correio_Eletronico_6);
        estado = FALHA;
    } catch (invalid_argument) {
        return;
    }
}

bool TCorreio_Eletronico::run(){
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

