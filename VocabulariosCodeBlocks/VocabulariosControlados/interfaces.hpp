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
class VocabulariosIS;

/*----------------------------------------------------------------------------*/

class AutenticacaoIA{
    public:
        virtual ResultadoUsuario Autenticar() throw (invalid_argument) = 0; //Metodo virtual de autenticacao

        virtual void set_aut_ia(AutenticacaoIS *) = 0; //Link IA-IS

        virtual ~AutenticacaoIA(){} //Destrutor Virtual
};

class AutenticacaoIS{
    public:
        virtual Resultado Autenticar(const Correio_Eletronico&, const Senha&) throw (invalid_argument) = 0;
        virtual ResultadoUsuario TipoDeUsuario(const Correio_Eletronico&, const Senha&) = 0;

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
        virtual ResultadoUsuario CadastroLeitor(const Leitor&) throw (invalid_argument) = 0;
        virtual ResultadoUsuario CadastroDesenvolvedor(const Desenvolvedor&) throw (invalid_argument) = 0;
        virtual ResultadoUsuario CadastroAdministrador(const Administrador&) throw (invalid_argument) = 0;
        virtual ~CadastroIS(){}
};

//Criar interface com stubs da camada de servico para a camada de apresentacao

/*----------------------------------------------------------------------------*/

class VocabulariosIA{
    public:
    //Para receber o email que foi autentificado, talvez seja melhor modificar a classe resultadoAutentificacao para retornar o
    //tipo de usuario que entrou no sistema(discutir)
    virtual void Executar(const ResultadoUsuario&) throw (invalid_argument) = 0;
    virtual void set_vocabulario_ia(VocabulariosIS *) = 0;
    virtual ~VocabulariosIA(){}
};

//Responsabilidades do modulo de vocabularios:
//Criar Vocabulario (apenas para administrador)
//Criar termo (apenas para desenvolvedor)
//listar vocabulario
//Apresenta Vocabulario
//Consultar termo
//Consultar Definicao de termo
//Retornar (nao necessita de metodo declarado na interface, ao menos nao por enquanto e ao meu ver)

class VocabulariosIS{
    public:
        //A classe resultado eh suficiente para estes casos?

    virtual Resultado ListaVocabulario() throw(invalid_argument) = 0;
    virtual Resultado ApresentaVocabulario(const VocControlado&) throw(invalid_argument) = 0;
    virtual Resultado ConsultarTermo(const Termo&) throw(invalid_argument) = 0;
    virtual Resultado ConsultarDefinicaoTermo(const Termo&) throw(invalid_argument) = 0;
    //Leitor utiliza ateh esse ponto

    virtual Resultado CriaTermo(const Termo&) throw(invalid_argument) = 0;
    virtual Resultado ExcluirTermo(const Termo&) throw(invalid_argument) = 0;
    virtual Resultado EditarTermo(const Termo&) throw(invalid_argument) = 0;
    virtual Resultado EditarDefinicaoTermo(const Termo&) throw(invalid_argument) = 0;
    //Desenvolvedor utiliza ateh esse ponto

    virtual Resultado CriaVocabulario(const VocControlado&) throw(invalid_argument) = 0;
    //Quando a conta de um administrador eh excluida deve-se excluir todos os vocabularios que o mesmo criou, como realizar tal processo?
    virtual Resultado ExcluirVocabulario(const VocControlado&) throw(invalid_argument) = 0;
    virtual Resultado EditarDefinicaoVocabulario(const VocControlado&) throw(invalid_argument) = 0;
    virtual Resultado AlterarIdiomaVocabulario(const VocControlado&) throw(invalid_argument) = 0;
    //Administrador utiliza ateh esse ponto

    virtual ~VocabulariosIS(){}
};

/*----------------------------------------------------------------------------*/


#endif
