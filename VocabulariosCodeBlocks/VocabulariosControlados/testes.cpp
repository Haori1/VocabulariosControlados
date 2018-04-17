#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>

#include "testes.hpp"
#include "dominios.hpp"
#include "entidades.hpp"

/*---------------------------------------------------------------------------*/

void TNome::setUp(){
    nome = new Nome();
    estado = SUCESSO;
    notifica = SUCESSO;
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

void TNome::casoFalha(string teste){
    try{
        if(teste == Valor_Invalido_Nome_1){
            nome->set_nome(Valor_Invalido_Nome_1);
            estado = FALHA;
            notifica = FALHA;
        }
        if(teste == Valor_Invalido_Nome_2){
            nome->set_nome(Valor_Invalido_Nome_2);
            estado = FALHA;
            notifica = FALHA;
        }
        if(teste == Valor_Invalido_Nome_3){
            nome->set_nome(Valor_Invalido_Nome_3);
            estado = FALHA;
            notifica = FALHA;
        }
        if(teste == Valor_Invalido_Nome_4){
            nome->set_nome(Valor_Invalido_Nome_4);
            estado = FALHA;
            notifica = FALHA;
        }
        if(teste == Valor_Invalido_Nome_5){
            nome->set_nome(Valor_Invalido_Nome_5);
            estado = FALHA;
            notifica = FALHA;
        }
    } catch (invalid_argument) {
        return;
    }
}

bool TNome::run(){
    setUp();
    casoSucesso();
    casoFalha(Valor_Invalido_Nome_1);
    if(notifica == FALHA) {
        cout << "Falha no teste para o valor invalido padrao 1 de nome";
        notifica = SUCESSO;
    }
    casoFalha(Valor_Invalido_Nome_2);
    if(notifica == FALHA) {
        cout << "Falha no teste para o valor invalido padrao 2 de nome";
        notifica = SUCESSO;
    }
    casoFalha(Valor_Invalido_Nome_3);
    if(notifica == FALHA) {
        cout << "Falha no teste para o valor invalido padrao 3 de nome";
        notifica = SUCESSO;
    }
    casoFalha(Valor_Invalido_Nome_4);
    if(notifica == FALHA) {
        cout << "Falha no teste para o valor invalido padrao 4 de nome";
        notifica = SUCESSO;
    }
    casoFalha(Valor_Invalido_Nome_5);
    if(notifica == FALHA) {
        cout << "Falha no teste para o valor invalido padrao 5 de nome";
        notifica = SUCESSO;
    }
    tearDown();
    return estado;
}

/*---------------------------------------------------------------------------*/
void TSobrenome::setUp(){
    sobrenome = new Sobrenome();
    estado = SUCESSO;
    notifica = SUCESSO;
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

void TSobrenome::casoFalha(string teste){
    try{
        if(teste == Valor_Invalido_Sobrenome_1) {
            sobrenome->set_sobrenome(Valor_Invalido_Sobrenome_1);
            estado = FALHA;
            notifica = FALHA;
        }
        if(teste == Valor_Invalido_Sobrenome_2) {
            sobrenome->set_sobrenome(Valor_Invalido_Sobrenome_2);
            estado = FALHA;
            notifica = FALHA;
        }
        if(teste == Valor_Invalido_Sobrenome_2) {
            sobrenome->set_sobrenome(Valor_Invalido_Sobrenome_2);
            estado = FALHA;
            notifica = FALHA;
        }
        if(teste == Valor_Invalido_Sobrenome_2) {
            sobrenome->set_sobrenome(Valor_Invalido_Sobrenome_2);
            estado = FALHA;
            notifica = FALHA;
        }
        if(teste == Valor_Invalido_Sobrenome_2) {
            sobrenome->set_sobrenome(Valor_Invalido_Sobrenome_2);
            estado = FALHA;
            notifica = FALHA;
        }
    } catch (invalid_argument) {
        return;
    }
}

bool TSobrenome::run(){
    setUp();
    casoSucesso();
    casoFalha(Valor_Invalido_Sobrenome_1);
    if(notifica == FALHA) {
        cout << "Falha no teste para o valor invalido padrao 1 de sobrenome";
        notifica = SUCESSO;
    }
    casoFalha(Valor_Invalido_Sobrenome_2);
    if(notifica == FALHA) {
        cout << "Falha no teste para o valor invalido padrao 2 de sobrenome";
        notifica = SUCESSO;
    }
    casoFalha(Valor_Invalido_Sobrenome_3);
    if(notifica == FALHA) {
        cout << "Falha no teste para o valor invalido padrao 3 de sobrenome";
        notifica = SUCESSO;
    }
    casoFalha(Valor_Invalido_Sobrenome_4);
    if(notifica == FALHA) {
        cout << "Falha no teste para o valor invalido padrao 4 de sobrenome";
        notifica = SUCESSO;
    }
    casoFalha(Valor_Invalido_Sobrenome_5);
    if(notifica == FALHA) {
        cout << "Falha no teste para o valor invalido padrao 5 de sobrenome";
        notifica = SUCESSO;
    }
    tearDown();
    return estado;
}

/*---------------------------------------------------------------------------*/

void TTelefone::setUp(){
    telefone = new Telefone();
    estado = SUCESSO;
    notifica = SUCESSO;
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

void TTelefone::casoFalha(string teste){
    try{
        if(teste == Valor_Invalido_Telefone_1){
            telefone->set_telefone(Valor_Invalido_Telefone_1);
            estado = FALHA;
            notifica = SUCESSO;
        }
        if(teste == Valor_Invalido_Telefone_2){
            telefone->set_telefone(Valor_Invalido_Telefone_2);
            estado = FALHA;
            notifica = SUCESSO;
        }
        if(teste == Valor_Invalido_Telefone_3){
            telefone->set_telefone(Valor_Invalido_Telefone_3);
            estado = FALHA;
            notifica = SUCESSO;
        }
        if(teste == Valor_Invalido_Telefone_4){
            telefone->set_telefone(Valor_Invalido_Telefone_4);
            estado = FALHA;
            notifica = SUCESSO;
        }
        if(teste == Valor_Invalido_Telefone_5){
            telefone->set_telefone(Valor_Invalido_Telefone_5);
            estado = FALHA;
            notifica = SUCESSO;
        }
        if(teste == Valor_Invalido_Telefone_6){
            telefone->set_telefone(Valor_Invalido_Telefone_6);
            estado = FALHA;
            notifica = SUCESSO;
        }
    } catch (invalid_argument) {
        return;
    }
}

bool TTelefone::run(){
    setUp();
    casoSucesso();
    casoFalha(Valor_Invalido_Telefone_1);
    if(notifica == FALHA) {
        cout << "Falha no teste para o valor invalido padrao 1 de telefone";
        notifica = SUCESSO;
    }
    casoFalha(Valor_Invalido_Telefone_2);
    if(notifica == FALHA) {
        cout << "Falha no teste para o valor invalido padrao 2 de telefone";
        notifica = SUCESSO;
    }
    casoFalha(Valor_Invalido_Telefone_3);
    if(notifica == FALHA) {
        cout << "Falha no teste para o valor invalido padrao 3 de telefone";
        notifica = SUCESSO;
    }
    casoFalha(Valor_Invalido_Telefone_4);
    if(notifica == FALHA) {
        cout << "Falha no teste para o valor invalido padrao 4 de telefone";
        notifica = SUCESSO;
    }
    casoFalha(Valor_Invalido_Telefone_5);
    if(notifica == FALHA) {
        cout << "Falha no teste para o valor invalido padrao 5 de telefone";
        notifica = SUCESSO;
    }
    casoFalha(Valor_Invalido_Telefone_6);
    if(notifica == FALHA) {
        cout << "Falha no teste para o valor invalido padrao 6 de telefone";
        notifica = SUCESSO;
    }
    tearDown();
    return estado;
}

/*---------------------------------------------------------------------------*/

void TEndereco::setUp(){
    endereco = new Endereco();
    estado = SUCESSO;
    notifica = SUCESSO;
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
            notifica = FALHA;
        }
        if(teste == Valor_Invalido_Endereco_2) {
            endereco->set_endereco(Valor_Invalido_Endereco_2);
            estado = FALHA;
            notifica = FALHA;
        }
        if(teste == Valor_Invalido_Endereco_3) {
            endereco->set_endereco(Valor_Invalido_Endereco_3);
            estado = FALHA;
            notifica = FALHA;
        }
        if(teste == Valor_Invalido_Endereco_4) {
            endereco->set_endereco(Valor_Invalido_Endereco_4);
            estado = FALHA;
            notifica = FALHA;
        }
        if(teste == Valor_Invalido_Endereco_5) {
            endereco->set_endereco(Valor_Invalido_Endereco_5);
            estado = FALHA;
            notifica = FALHA;
        }
        if(teste == Valor_Invalido_Endereco_6) {
            endereco->set_endereco(Valor_Invalido_Endereco_6);
            estado = FALHA;
            notifica = FALHA;
        }
    } catch (invalid_argument) {
        return;
    }
}

bool TEndereco::run(){
    setUp();
    casoSucesso();
    casoFalha(Valor_Invalido_Endereco_1);
    if(notifica == FALHA) {
        cout << "Falha no teste para o valor invalido padrao 1 de endereco";
        notifica = SUCESSO;
    }
    casoFalha(Valor_Invalido_Endereco_2);
    if(notifica == FALHA) {
        cout << "Falha no teste para o valor invalido padrao 2 de endereco";
        notifica = SUCESSO;
    }
    casoFalha(Valor_Invalido_Endereco_3);
    if(notifica == FALHA) {
        cout << "Falha no teste para o valor invalido padrao 3 de endereco";
        notifica = SUCESSO;
    }
    casoFalha(Valor_Invalido_Endereco_4);
    if(notifica == FALHA) {
        cout << "Falha no teste para o valor invalido padrao 4 de endereco";
        notifica = SUCESSO;
    }
    casoFalha(Valor_Invalido_Endereco_5);
    if(notifica == FALHA) {
        cout << "Falha no teste para o valor invalido padrao 5 de endereco";
        notifica = SUCESSO;
    }
    casoFalha(Valor_Invalido_Endereco_6);
    if(notifica == FALHA) {
        cout << "Falha no teste para o valor invalido padrao 6 de endereco";
        notifica = SUCESSO;
    }
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
    notifica = SUCESSO;
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

void TCorreio_Eletronico::casoFalha(string teste){
    try{
        if(teste == Valor_Invalido_Correio_Eletronico_1){
            correio_eletronico->set_correio_eletronico(Valor_Invalido_Correio_Eletronico_1);
            estado = FALHA;
            notifica = FALHA;
        }
        if(teste == Valor_Invalido_Correio_Eletronico_2){
            correio_eletronico->set_correio_eletronico(Valor_Invalido_Correio_Eletronico_2);
            estado = FALHA;
            notifica = FALHA;
        }
        if(teste == Valor_Invalido_Correio_Eletronico_3){
            correio_eletronico->set_correio_eletronico(Valor_Invalido_Correio_Eletronico_3);
            estado = FALHA;
            notifica = FALHA;
        }
        if(teste == Valor_Invalido_Correio_Eletronico_4){
            correio_eletronico->set_correio_eletronico(Valor_Invalido_Correio_Eletronico_4);
            estado = FALHA;
            notifica = FALHA;
        }
        if(teste == Valor_Invalido_Correio_Eletronico_5){
            correio_eletronico->set_correio_eletronico(Valor_Invalido_Correio_Eletronico_5);
            estado = FALHA;
            notifica = FALHA;
        }
        if(teste == Valor_Invalido_Correio_Eletronico_6){
            correio_eletronico->set_correio_eletronico(Valor_Invalido_Correio_Eletronico_6);
            estado = FALHA;
            notifica = FALHA;
        }
    } catch (invalid_argument) {
        return;
    }
}

bool TCorreio_Eletronico::run(){
    setUp();
    casoSucesso();
    casoFalha(Valor_Invalido_Correio_Eletronico_1);
    if(notifica == FALHA) {
        cout << "Falha no teste para o valor invalido padrao 1 de correio eletronico";
        notifica = SUCESSO;
    }
    casoFalha(Valor_Invalido_Correio_Eletronico_2);
    if(notifica == FALHA) {
        cout << "Falha no teste para o valor invalido padrao 2 de correio eletronico";
        notifica = SUCESSO;
    }
    casoFalha(Valor_Invalido_Correio_Eletronico_3);
    if(notifica == FALHA) {
        cout << "Falha no teste para o valor invalido padrao 3 de correio eletronico";
        notifica = SUCESSO;
    }
    casoFalha(Valor_Invalido_Correio_Eletronico_4);
    if(notifica == FALHA) {
        cout << "Falha no teste para o valor invalido padrao 4 de correio eletronico";
        notifica = SUCESSO;
    }
    casoFalha(Valor_Invalido_Correio_Eletronico_5);
    if(notifica == FALHA) {
        cout << "Falha no teste para o valor invalido padrao 5 de correio eletronico";
        notifica = SUCESSO;
    }
    casoFalha(Valor_Invalido_Correio_Eletronico_6);
    if(notifica == FALHA) {
        cout << "Falha no teste para o valor invalido padrao 6 de correio eletronico";
        notifica = SUCESSO;
    }
    tearDown();
    return estado;
}

/*---------------------------------------------------------------------------*/

void TSenha::setUp(){
    senha = new Senha();
    estado = SUCESSO;
    notifica = SUCESSO;
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

void TSenha::casoFalha(string teste){
    try{
        if(teste == Valor_Invalido_Senha_1){
            senha->set_senha(Valor_Invalido_Senha_1);
            estado = FALHA;
            notifica = FALHA;
        }
        if(teste == Valor_Invalido_Senha_2){
            senha->set_senha(Valor_Invalido_Senha_2);
            estado = FALHA;
            notifica = FALHA;
        }
        if(teste == Valor_Invalido_Senha_3){
            senha->set_senha(Valor_Invalido_Senha_3);
            estado = FALHA;
            notifica = FALHA;
        }

    } catch (invalid_argument) {
        return;
    }
}

bool TSenha::run(){
    setUp();
    casoSucesso();
    casoFalha(Valor_Invalido_Senha_1);
    if(notifica == FALHA) {
        cout << "Falha no teste para o valor invalido padrao 1 de senha";
        notifica = SUCESSO;
    }
    casoFalha(Valor_Invalido_Senha_2);
    if(notifica == FALHA) {
        cout << "Falha no teste para o valor invalido padrao 2 de senha";
        notifica = SUCESSO;
    }
    casoFalha(Valor_Invalido_Senha_3);
    if(notifica == FALHA) {
        cout << "Falha no teste para o valor invalido padrao 3 de senha";
        notifica = SUCESSO;
    }
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

/*---------------------------------------------------------------------------*/

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

/*---------------------------------------------------------------------------*/

void TDesenvolvedor::setUp(){
    nome.set_nome(Valor_Nome);
    sobrenome.set_sobrenome(Valor_Sobrenome);
    data_nascimento.set_data(Valor_Data_Nascimento);
    correio_eletronico.set_correio_eletronico(Valor_Correio_Eletronico);
    senha.set_senha(Valor_Senha);

    desenvolvedor = new Desenvolvedor(nome, sobrenome, data_nascimento, correio_eletronico, senha);
    estado = SUCESSO;
}

void TDesenvolvedor::tearDown(){
    delete desenvolvedor;
}

void TDesenvolvedor::casoSucesso(){
    try{
        if(desenvolvedor->get_nome().get_nome() != nome.get_nome())
            estado = FALHA;
        if(desenvolvedor->get_sobrenome().get_sobrenome() != sobrenome.get_sobrenome())
            estado = FALHA;
        if(desenvolvedor->get_data().get_data() != data_nascimento.get_data())
            estado = FALHA;
        if(desenvolvedor->get_correio_eletronico().get_correio_eletronico() != correio_eletronico.get_correio_eletronico())
            estado = FALHA;
        if(desenvolvedor->get_senha().get_senha() != senha.get_senha())
            estado = FALHA;
    } catch (invalid_argument) {
        return;
    }
}

bool TDesenvolvedor::run(){
    setUp();
    casoSucesso();
    tearDown();
    return estado;
}

/*---------------------------------------------------------------------------*/

void TAdministrador::setUp(){
    nome.set_nome(Valor_Nome);
    sobrenome.set_sobrenome(Valor_Sobrenome);
    telefone.set_telefone(Valor_Telefone);
    data_nascimento.set_data(Valor_Data_Nascimento);
    endereco.set_endereco(Valor_Endereco);
    correio_eletronico.set_correio_eletronico(Valor_Correio_Eletronico);
    senha.set_senha(Valor_Senha);

    administrador = new Administrador(nome, sobrenome, telefone, data_nascimento, endereco, correio_eletronico, senha);
    estado = SUCESSO;
}

void TAdministrador::tearDown(){
    delete administrador;
}

void TAdministrador::casoSucesso(){
    try{
        if(administrador->get_nome().get_nome() != nome.get_nome())
            estado = FALHA;
        if(administrador->get_sobrenome().get_sobrenome() != sobrenome.get_sobrenome())
            estado = FALHA;
        if(administrador->get_telefone().get_telefone() != telefone.get_telefone())
            estado = FALHA;
        if(administrador->get_data().get_data() != data_nascimento.get_data())
            estado = FALHA;
        if(administrador->get_endereco().get_endereco() != endereco.get_endereco())
            estado = FALHA;
        if(administrador->get_correio_eletronico().get_correio_eletronico() != correio_eletronico.get_correio_eletronico())
            estado = FALHA;
        if(administrador->get_senha().get_senha() != senha.get_senha())
            estado = FALHA;
    } catch (invalid_argument) {
        return;
    }
}

bool TAdministrador::run(){
    setUp();
    casoSucesso();
    tearDown();
    return estado;
}

/*---------------------------------------------------------------------------*/

void TVoc_Controlado::setUp(){
    nome.set_nome(Valor_Nome);
    idioma.set_idioma(Valor_Idioma);
    data.set_data(Valor_Data);

    voc_controlado = new Voc_Controlado(nome, idioma, data);
    estado = SUCESSO;
}

void TVoc_Controlado::tearDown(){
    delete voc_controlado;
}

void TVoc_Controlado::casoSucesso(){
    try{
        if(voc_controlado->get_nome().get_nome() != nome.get_nome())
            estado = FALHA;
        if(voc_controlado ->get_idioma().get_idioma() != idioma.get_idioma())
            estado = FALHA;
        if(voc_controlado->get_data().get_data() != data.get_data())
            estado = FALHA;
    } catch (invalid_argument) {
        return;
    }
}

bool TVoc_Controlado::run(){
    setUp();
    casoSucesso();
    tearDown();
    return estado;
}

/*---------------------------------------------------------------------------*/

void TTermo::setUp(){
    nome.set_nome(Valor_Nome);
    classe_termo.set_classe_termo(Valor_Classe_Termo);
    data.set_data(Valor_Data);

    termo = new Termo(nome, classe_termo, data);
    estado = SUCESSO;
}

void TTermo::tearDown(){
    delete termo;
}

void TTermo::casoSucesso(){
    try{
        if(termo->get_nome().get_nome() != nome.get_nome())
            estado = FALHA;
        if(termo->get_classe_termo().get_classe_termo() != classe_termo.get_classe_termo())
            estado = FALHA;
        if(termo->get_data().get_data() != data.get_data())
            estado = FALHA;
    } catch (invalid_argument) {
        return;
    }
}

bool TTermo::run(){
    setUp();
    casoSucesso();
    tearDown();
    return estado;
}

/*---------------------------------------------------------------------------*/

void TDefinicao::setUp(){
    texto_definicao.set_texto_definicao(Valor_Texto_Definicao);
    data.set_data(Valor_Data);

    definicao = new Definicao(texto_definicao, data);
    estado = SUCESSO;
}

void TDefinicao::tearDown(){
    delete definicao;
}

void TDefinicao::casoSucesso(){
    try{
        if(definicao->get_texto_definicao().get_texto_definicao() != texto_definicao.get_texto_definicao())
            estado = FALHA;
        if(definicao->get_data().get_data() != data.get_data())
            estado = FALHA;
    } catch (invalid_argument) {
        return;
    }
}

bool TDefinicao::run(){
    setUp();
    casoSucesso();
    tearDown();
    return estado;
}

/*---------------------------------------------------------------------------*/
