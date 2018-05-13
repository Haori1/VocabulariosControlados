#include <iostream>

#include "stubs.hpp"
#include "dominios.hpp"

using namespace std;

Resultado StubAutenticacao::Autenticar(const Correio_Eletronico &correio_eletronico, const Senha &senha) throw (invalid_argument){

    cout << "AutenticacaoIS::Autenticar" << endl;

    cout << "Email = " << correio_eletronico.get_correio_eletronico() << endl;
    cout << "Senha = " << senha.get_senha() << endl;

    ResultadoAutenticacao resultado;

    if(TRIGGER_FALHA_EMAIL == correio_eletronico.get_correio_eletronico()){
        resultado.set_resultado(ResultadoAutenticacao::FALHA);
    } else if (TRIGGER_ERRO_SISTEMA_EMAIL == correio_eletronico.get_correio_eletronico()){
        throw invalid_argument("Erro de sistema.");
    } else {
        resultado.set_resultado(ResultadoAutenticacao::SUCESSO);
    }

    if(TRIGGER_FALHA_SENHA == senha.get_senha()){
        resultado.set_resultado(ResultadoAutenticacao::FALHA);
    }


    return resultado;

}//end Autenticar
