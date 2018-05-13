#ifndef __INTERFACES_HPP__
#define __INTERFACES_HPP__

#include <exception>
#include <stdexcept>
#include <iostream>
#include <string>


#include "dominios.hpp"
#include "entidades.hpp"

using namespace std;

class AutenticacaoIS;  //Autenticação anterior para o link reconhecer a classe

/*----------------------------------------------------------------------------*/

class AutenticacaoIA{
    public:
        virtual ResultadoAutenticacao Autenticar() throw (invalid_argument) = 0; //Metodo virtual de autenticacao

        virtual void set_aut_ia(AutenticacaoIS *) = 0; //Link

        virtual ~AutenticacaoIA(){} //Destrutor Virtual
};

class AutenticacaoIS{
    public:
        virtual Resultado Autenticar(const Correio_Eletronico&, const Senha&) throw (invalid_argument) = 0;
        virtual ~AutenticacaoIS(){}
};

/*----------------------------------------------------------------------------*/

//Criar interface com stubs da camada de servico para a camada de apresentacao

#endif
