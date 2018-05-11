#ifndef __MAAUT_CPP__
#define __MAAUT_CPP__

#include "stubMSAUT.hpp"

stubAUT::Autenticar(string email, senha) {

int retorno = 0;

    if(email == Valor_Conhecido_Email) {
        retorno = 1;
        return(retorno);
    }

    if(email == Valor_Desconhecido_Email) {
        retorno = 2;
        return(retorno);
    }

    if(email == Valor_Conhecido_Senha) {
        retorno = 3;
        return(retorno);
    }

    if(email == Valor_Desconhecido_Senha) {
        retorno = 4;
        return(retorno);
    }

} //Resta por a opcao de erro de sistema.

#endif
