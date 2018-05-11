#ifndef __INTERFACES_HPP__
#define __INTERFACES_HPP__

#include <exception>
#include <stdexcept>
#include <iostream>
#include <string>


#include "dominios.hpp"
#include "entidades.hpp"

using namespace std;

class Autenticacao_IA{
    public:
        static const int Email_Valido = 1;
        static const int Email_Invalido = 2;
        static const int Senha_Valida = 3;
        static const int Senha_Invalida = 4;
        static const int Erro_Sistema = 5;

        virtual int autenticar() throw (invalid_argument) = 0; //Metodo virtual de autenticacao
        // checar nome minusculo do mehtodo
        virtual ~Autenticacao_IA(){} //Destrutor Virtual
};

class Autenticacao_IS{
    public:
        virtual int Autenticar(string, string);
        virtual ~Autenticacao_IS();
};

#Criar interface com stubs da camada de servico para a camada de apresentacao

#endif
