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
class UsuarioIS;
class CadastroIS;

/*----------------------------------------------------------------------------*/

class AutenticacaoIA{
    public:
        virtual ResultadoAutenticacao Autenticar() throw (invalid_argument) = 0; //Metodo virtual de autenticacao

        virtual void set_aut_ia(AutenticacaoIS *) = 0; //Link IA-IS

        virtual ~AutenticacaoIA(){} //Destrutor Virtual
};

class AutenticacaoIS{
    public:
        virtual Resultado Autenticar(const Correio_Eletronico&, const Senha&) throw (invalid_argument) = 0;
        virtual ~AutenticacaoIS(){}
};

/*----------------------------------------------------------------------------*/

class UsuarioIA{
    public:
        virtual void Executar(const Correio_Eletronico&) throw (invalid_argument) = 0;
        virtual void set_usuario_ia(UsuarioIS *) = 0; //Link IA-IS
        virtual ~UsuarioIA(){}

};

class UsuarioIS{
    public:
        //Criar as interfaces dos servicos que sao oferecidos pelo UsuarioIs

};

/*----------------------------------------------------------------------------*/

class CadastroIA{
    public:
        virtual void Executar() throw (invalid_argument) = 0;
        virtual void set_cadastro_ia(CadastroIS *) = 0; //Link IA-IS
        virtual ~CadastroIA(){}
};

class CadastroIS{
    public:
        virtual ResultadoCadastro CadastroLeitor(const Leitor&) throw (invalid_argument) = 0;
        virtual ResultadoCadastro CadastroDesenvolvedor(const Desenvolvedor&) throw (invalid_argument) = 0;
        virtual ResultadoCadastro CadastroAdministrador(const Administrador&) throw (invalid_argument) = 0;
        virtual ~CadastroIS(){}
};

//Criar interface com stubs da camada de servico para a camada de apresentacao

#endif
