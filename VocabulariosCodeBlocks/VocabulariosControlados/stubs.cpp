#include <iostream>

#include "stubs.hpp"
#include "dominios.hpp"

using namespace std;

Resultado StubAutenticacao::Autenticar(const Correio_Eletronico &correio_eletronico, const Senha &senha) throw (invalid_argument){

    cout << endl << "AutenticacaoIS::Autenticar" << endl;

    cout << "Email = " << correio_eletronico.get_correio_eletronico() << endl;
    cout << "Senha = " << senha.get_senha() << endl;

    ResultadoUsuario resultado;

    if(TRIGGER_FALHA_EMAIL == correio_eletronico.get_correio_eletronico()){
        resultado.set_resultado(ResultadoUsuario::FALHA);
    } else if (TRIGGER_ERRO_SISTEMA_EMAIL == correio_eletronico.get_correio_eletronico()){
        throw invalid_argument("\nErro de sistema.\n");
    } else {
        resultado.set_resultado(ResultadoUsuario::SUCESSO);
    }

    if(TRIGGER_FALHA_SENHA == senha.get_senha()){
        resultado.set_resultado(ResultadoUsuario::FALHA);
    }


    return resultado;

}//end Autenticar

ResultadoUsuario StubAutenticacao::TipoDeUsuario(const Correio_Eletronico &correio_eletronico, const Senha &senha) throw(invalid_argument){

    ResultadoUsuario resultado_usuario;

    Nome nome;
    Sobrenome sobrenome;
    Data data;
    Telefone telefone;
    Endereco endereco;

    nome.set_nome(NOME_LEITOR);
    sobrenome.set_sobrenome(SOBRENOME_LEITOR);
    Leitor *leitor;
    leitor = new Leitor(nome, sobrenome, correio_eletronico, senha);

    nome.set_nome(NOME_DESENVOLVEDOR);
    sobrenome.set_sobrenome(SOBRENOME_DESENVOLVEDOR);
    data.set_data(DATA_DESENVOLVEDOR);
    Desenvolvedor *desenvolvedor;
    desenvolvedor = new Desenvolvedor(nome, sobrenome,data, correio_eletronico, senha);

    nome.set_nome(NOME_ADMINISTRADOR);
    sobrenome.set_sobrenome(SOBRENOME_ADMINISTRADOR);
    data.set_data(DATA_ADMINISTRADOR);
    endereco.set_endereco(ENDERECO_ADMINISTRADOR);
    telefone.set_telefone(TELEFONE_ADMINISTRADOR);
    Administrador *administrador;
    administrador = new Administrador(nome, sobrenome, telefone, data, endereco, correio_eletronico, senha);

    if(TRIGGER_LEITOR == correio_eletronico.get_correio_eletronico()) {
        resultado_usuario.tipo_de_usuario = resultado_usuario.LEITOR;
        resultado_usuario.set_leitor(*leitor);
    } else if(TRIGGER_DESENVOLVEDOR == correio_eletronico.get_correio_eletronico()) {
        resultado_usuario.tipo_de_usuario = resultado_usuario.DESENVOLVEDOR;
        resultado_usuario.set_desenvolvedor(*desenvolvedor);
    } else if(TRIGGER_ADMINISTRADOR == correio_eletronico.get_correio_eletronico()) {
        resultado_usuario.tipo_de_usuario = resultado_usuario.ADMINISTRADOR;
        resultado_usuario.set_administrador(*administrador);
    } else { //O leitor eh estabelecido como usuario padrao.
        resultado_usuario.tipo_de_usuario = resultado_usuario.LEITOR;
        resultado_usuario.set_leitor(*leitor);
    }

    delete leitor;
    delete desenvolvedor;
    delete administrador;

    return resultado_usuario;

}
