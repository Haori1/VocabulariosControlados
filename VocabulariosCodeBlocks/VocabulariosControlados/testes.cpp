#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>

#include "testes.hpp"
#include "dominiosClasses.hpp"
#include "entidadesClasses.hpp"

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
        nome->set_nome(Valor_Valido_Nome);
        if(nome->get_nome() != Valor_Valido_Nome)
            estado = FALHA;
    } catch (invalid_argument) {
        return;
    }
}

void TNome::casoFalha(){
    try{
        nome->set_nome(Valor_Invalido_Nome_1);
        estado = FALHA;
        nome->set_nome(Valor_Invalido_Nome_2);
        estado = FALHA;
        nome->set_nome(Valor_Invalido_Nome_3);
        estado = FALHA;
        nome->set_nome(Valor_Invalido_Nome_4);
        estado = FALHA;
        nome->set_nome(Valor_Invalido_Nome_5);
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
        sobrenome->set_sobrenome(Valor_Valido_Sobrenome);
        if(sobrenome->get_sobrenome() != Valor_Valido_Sobrenome)
            estado = FALHA;
    } catch (invalid_argument) {
        return;
    }
}

void TSobrenome::casoFalha(){
    try{
        sobrenome->set_sobrenome(Valor_Invalido_Sobrenome_1);
        estado = FALHA;
        sobrenome->set_sobrenome(Valor_Invalido_Sobrenome_2);
        estado = FALHA;
        sobrenome->set_sobrenome(Valor_Invalido_Sobrenome_3);
        estado = FALHA;
        sobrenome->set_sobrenome(Valor_Invalido_Sobrenome_4);
        estado = FALHA;                                     /*Sera que assim funfa?*/
        sobrenome->set_sobrenome(Valor_Invalido_Sobrenome_5);
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
        telefone->set_telefone(Valor_Valido_Telefone);
        if(telefone->get_telefone() != Valor_Valido_Telefone)
            estado = FALHA;
    } catch (invalid_argument) {
        return;
    }
}

void TTelefone::casoFalha(){
    try{
        telefone->set_telefone(Valor_Invalido_Telefone_1);
        estado = FALHA;
        telefone->set_telefone(Valor_Invalido_Telefone_2);
        estado = FALHA;
        telefone->set_telefone(Valor_Invalido_Telefone_3);
        estado = FALHA;
        telefone->set_telefone(Valor_Invalido_Telefone_4);
        estado = FALHA;
        telefone->set_telefone(Valor_Invalido_Telefone_5);
        estado = FALHA;
        telefone->set_telefone(Valor_Invalido_Telefone_6);
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
        endereco->set_endereco(Valor_Valido_Endereco);
        if(endereco->get_endereco() != Valor_Valido_Endereco) {
            estado = FALHA;
        }
    } catch (invalid_argument){
        return;
    }
}

void TEndereco::casoFalha(string teste){
    try {

        if(teste == Valor_Invalido_Endereco_1) {
            endereco->set_endereco(Valor_Invalido_Endereco_1);
            estado = FALHA;
        }
        if(teste == Valor_Invalido_Endereco_2) {
            endereco->set_endereco(Valor_Invalido_Endereco_2);
            estado = FALHA;
        }
        if(teste == Valor_Invalido_Endereco_3) {
            endereco->set_endereco(Valor_Invalido_Endereco_3);
            estado = FALHA;
        }
        if(teste == Valor_Invalido_Endereco_4) {
            endereco->set_endereco(Valor_Invalido_Endereco_4);
            estado = FALHA;
        }
        if(teste == Valor_Invalido_Endereco_5) {
            endereco->set_endereco(Valor_Invalido_Endereco_5);
            estado = FALHA;
        }
        if(teste == Valor_Invalido_Endereco_6) {
            endereco->set_endereco(Valor_Invalido_Endereco_6);
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

void TData::setUp(){
    data = new Data();
    estado = SUCESSO;
}

void TData::tearDown(){
    delete data;
}

void TData::casoSucesso(){
    try{
        data->set_data(Valor_Valido_Data);
        if(data->get_data() != Valor_Valido_Data)
            estado = FALHA;
    } catch (invalid_argument) {
        return;
    }
}

void TData::casoFalha(){
    try{
        data->set_data(Valor_Invalido_Data);
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
        correio_eletronico->set_correio_eletronico(Valor_Valido_Correio_Eletronico);
        if(correio_eletronico->get_correio_eletronico() != Valor_Valido_Correio_Eletronico)
            estado = FALHA;
    } catch (invalid_argument) {
        return;
    }
}

void TCorreio_Eletronico::casoFalha(){
    try{
        correio_eletronico->set_correio_eletronico(Valor_Invalido_Correio_Eletronico_6);
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

void TSenha::setUp(){
    senha = new Senha();
    estado = SUCESSO;
}

void TSenha::tearDown(){
    delete senha;
}

void TSenha::casoSucesso(){
    try{
        senha->set_senha(Valor_Valido_Senha);
        if(senha->get_senha() != Valor_Valido_Senha)
            estado = FALHA;
    } catch (invalid_argument) {
        return;
    }
}

void TSenha::casoFalha(){
    try{
        senha->set_senha(Valor_Invalido_Senha_3);
        estado = FALHA;
    } catch (invalid_argument) {
        return;
    }
}

bool TSenha::run(){
    setUp();
    casoSucesso();
    casoFalha();
    tearDown();
    return estado;
}

/*---------------------------------------------------------------------------*/

void TTexto_Definicao::setUp(){
    texto_definicao = new Texto_Definicao();
    estado = SUCESSO;
}

void TTexto_Definicao::tearDown(){
    delete texto_definicao;
}

void TTexto_Definicao::casoSucesso(){
    try{
        texto_definicao->set_texto_definicao(Valor_Valido_Texto_Definicao);
        if(texto_definicao->get_texto_definicao() != Valor_Valido_Texto_Definicao)
            estado = FALHA;
    } catch (invalid_argument) {
        return;
    }
}

void TTexto_Definicao::casoFalha(){
    try{
        texto_definicao->set_texto_definicao(Valor_Invalido_Texto_Definicao);
        estado = FALHA;
    } catch (invalid_argument) {
        return;
    }
}

bool TTexto_Definicao::run(){
    setUp();
    casoSucesso();
    casoFalha();
    tearDown();
    return estado;
}

/*---------------------------------------------------------------------------*/

void TIdioma::setUp(){
    idioma = new Idioma();
    estado = SUCESSO;
}

void TIdioma::tearDown(){
    delete idioma;
}

void TIdioma::casoSucesso(){
    try{
        idioma->set_idioma(Valor_Valido_Idioma);
        if(idioma->get_idioma() != Valor_Valido_Idioma)
            estado = FALHA;
    } catch (invalid_argument) {
        return;
    }
}

void TIdioma::casoFalha(){
    try{
        idioma->set_idioma(Valor_Invalido_Idioma);
        estado = FALHA;
    } catch (invalid_argument) {
        return;
    }
}

bool TIdioma::run(){
    setUp();
    casoSucesso();
    casoFalha();
    tearDown();
    return estado;
}

/*---------------------------------------------------------------------------*/

void TClasse_Termo::setUp(){
    classe_termo = new Classe_Termo();
    estado = SUCESSO;
}

void TClasse_Termo::tearDown(){
    delete classe_termo;
}

void TClasse_Termo::casoSucesso(){
    try{
        classe_termo->set_classe_termo(Valor_Valido_Classe_Termo);
        if(classe_termo->get_classe_termo() != Valor_Valido_Classe_Termo)
            estado = FALHA;
    } catch (invalid_argument) {
        return;
    }
}

void TClasse_Termo::casoFalha(){
    try{
        classe_termo->set_classe_termo(Valor_Invalido_Classe_Termo);
        estado = FALHA;
    } catch (invalid_argument) {
        return;
    }
}

bool TClasse_Termo::run(){
    setUp();
    casoSucesso();
    casoFalha();
    tearDown();
    return estado;
}

/*-------------------------------------Entidades--------------------------------------*/

void TLeitor::setUp(){
    nome.set_nome(Valor_Nome);
    sobrenome.set_sobrenome(Valor_Sobrenome);
    correio_eletronico.set_correio_eletronico(Valor_Correio_Eletronico);
    senha.set_senha(Valor_Senha);

    leitor = new Leitor(nome, sobrenome, correio_eletronico, senha);
    estado = SUCESSO;
}

void TLeitor::tearDown(){
    delete leitor;
}

void TLeitor::casoSucesso(){
    try{
        if(leitor->get_nome().get_nome() != nome.get_nome())
            estado = FALHA;
        if(leitor->get_sobrenome().get_sobrenome() != sobrenome.get_sobrenome())
            estado = FALHA;
        if(leitor->get_correio_eletronico().get_correio_eletronico() != correio_eletronico.get_correio_eletronico())
            estado = FALHA;
        if(leitor->get_senha().get_senha() != senha.get_senha())
            estado = FALHA;
    } catch (invalid_argument) {
        return;
    }
}

bool TLeitor::run(){
    setUp();
    casoSucesso();
    tearDown();
    return estado;
}
