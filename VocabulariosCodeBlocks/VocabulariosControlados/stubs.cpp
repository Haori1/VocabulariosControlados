#include <iostream>

#include "stubs.hpp"
#include "dominios.hpp"

using namespace std;

Resultado StubAutenticacao::Autenticar(const Correio_Eletronico &correio_eletronico, const Senha &senha) throw (invalid_argument){

    cout << endl << "AutenticacaoIS::Autenticar" << endl;

    cout << "Email = " << correio_eletronico.get_correio_eletronico() << endl;
    cout << "Senha = " << senha.get_senha() << endl;

    ResultadoAutenticacao resultado;

    if(TRIGGER_FALHA_EMAIL == correio_eletronico.get_correio_eletronico()){
        resultado.set_resultado(ResultadoAutenticacao::FALHA);
    } else if (TRIGGER_ERRO_SISTEMA_EMAIL == correio_eletronico.get_correio_eletronico()){
        throw invalid_argument("\nErro de sistema.\n");
    } else {
        resultado.set_resultado(ResultadoAutenticacao::SUCESSO);
    }

    if(TRIGGER_FALHA_SENHA == senha.get_senha()){
        resultado.set_resultado(ResultadoAutenticacao::FALHA);
    }


    return resultado;

}//end Autenticar

ResultadoUsuario StubAutenticacao::TipoDeUsuario(const Correio_Eletronico &correio_eletronico, const Senha &senha) throw(invalid_argument) {

    ResultadoUsuario resultado_usuario;

     Leitor leitor;
     Desenvolvedor desenvolvedor;
     Administrador administrador;
     Nome nome;
     Sobrenome sobrenome;
     Data data;
     Telefone telefone;
     Endereco endereco;

    if(TRIGGER_LEITOR == correio_eletronico.get_correio_eletronico()) {
        resultado_usuario.tipo_de_usuario = resultado_usuario.LEITOR;
        leitor.set_correio_eletronico(correio_eletronico);
        leitor.set_senha(senha);
        nome.set_nome(NOME_LEITOR);
        leitor.set_nome(nome);
        sobrenome.set_sobrenome(SOBRENOME_LEITOR);
        leitor.set_sobrenome(sobrenome);
        resultado_usuario.set_leitor(leitor);
    } else if(TRIGGER_DESENVOLVEDOR == correio_eletronico.get_correio_eletronico()) {
        resultado_usuario.tipo_de_usuario = resultado_usuario.DESENVOLVEDOR;
        desenvolvedor.set_correio_eletronico(correio_eletronico);
        desenvolvedor.set_senha(senha);
        nome.set_nome(NOME_DESENVOLVEDOR);
        desenvolvedor.set_nome(nome);
        sobrenome.set_sobrenome(SOBRENOME_DESENVOLVEDOR);
        desenvolvedor.set_sobrenome(sobrenome);
        data.set_data(DATA_DESENVOLVEDOR);
        desenvolvedor.set_data(data);
        resultado_usuario.set_desenvolvedor(desenvolvedor);
    } else if(TRIGGER_ADMINISTRADOR == correio_eletronico.get_correio_eletronico()) {
        resultado_usuario.tipo_de_usuario = resultado_usuario.ADMINISTRADOR;
        administrador.set_correio_eletronico(correio_eletronico);
        administrador.set_senha(senha);
        nome.set_nome(NOME_ADMINISTRADOR);
        administrador.set_nome(nome);
        sobrenome.set_sobrenome(SOBRENOME_ADMINISTRADOR);
        administrador.set_sobrenome(sobrenome);
        data.set_data(DATA_ADMINISTRADOR);
        administrador.set_data(data);
        telefone.set_telefone(TELEFONE_ADMINISTRADOR);
        administrador.set_telefone(telefone);
        endereco.set_endereco(ENDERECO_ADMINISTRADOR);
        administrador.set_endereco(endereco);
        resultado_usuario.set_administrador(administrador);
    } else { //O leitor eh estabelecido como usuario padrao.
        resultado_usuario.tipo_de_usuario = resultado_usuario.LEITOR;
        leitor.set_correio_eletronico(correio_eletronico);
        leitor.set_senha(senha);
        nome.set_nome(NOME_LEITOR);
        leitor.set_nome(nome);
        sobrenome.set_sobrenome(SOBRENOME_LEITOR);
        leitor.set_sobrenome(sobrenome);
        resultado_usuario.set_leitor(leitor);
    } //o erro de sistema deve ser colocado aqui.


    return(resultado_usuario);

}
