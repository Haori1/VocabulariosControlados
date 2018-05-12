#include <iostream>

#include "stubs.hpp"
#include "dominios.hpp"

using namespace std;

bool StubAutenticacao::Autenticar(const Correio_Eletronico &correio_eletronico, const Senha &senha) throw (invalid_argument){

    cout << "AutenticacaoIS::Autenticar" << endl;

    cout << "Email = " << correio_eletronico.get_correio_eletronico() << endl;
    cout << "Senha = " << senha.get_senha() << endl;

    bool retorno = false; //Temporário

    if(TRIGGER_FALHA_EMAIL == correio_eletronico.get_correio_eletronico()){
        retorno = false;
    } else if (TRIGGER_ERRO_SISTEMA_EMAIL == correio_eletronico.get_correio_eletronico()){
        throw invalid_argument("Erro de sistema.");
    } else {
        retorno = true;
    }


    return retorno; //Temporário

}//end Autenticar
