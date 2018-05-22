#ifndef __INTERFACES_HPP__
#define __INTERFACES_HPP__

#include <exception>
#include <stdexcept>
#include <iostream>
#include <string>
#include <vector>

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
        virtual void Executar(const ResultadoUsuario) throw (invalid_argument) = 0;
        virtual void set_usuario_ia(UsuarioIS *) = 0; //Link IA-IS
        virtual ~UsuarioIA(){}

};

class UsuarioIS{
    public:
        virtual void Exibir(const ResultadoUsuario) throw (invalid_argument) = 0;
        virtual ResultadoUsuario Editar(const ResultadoUsuario) throw (invalid_argument) = 0;
        virtual Resultado Excluir() throw (invalid_argument) = 0;
        virtual ResultadoUsuario EditarLeitor() throw (invalid_argument) = 0;
        virtual ResultadoUsuario EditarDesenvolvedor() throw (invalid_argument) = 0;
        virtual ResultadoUsuario EditarAdministrador() throw (invalid_argument) = 0;
        virtual ~UsuarioIS(){}
};

/*----------------------------------------------------------------------------*/

class CadastroIA{
    public:
        virtual void ExecutarIA() throw (invalid_argument) = 0;
        virtual void set_cadastro_ia(CadastroIS *) = 0; //Link IA-IS
        virtual ~CadastroIA(){}
};

class CadastroIS{
    public:
        virtual Resultado CadastroLeitor(const Leitor&) throw (invalid_argument) = 0;
        virtual Resultado CadastroDesenvolvedor(const Desenvolvedor&) throw (invalid_argument) = 0;
        virtual Resultado CadastroAdministrador(const Administrador&) throw (invalid_argument) = 0;
        virtual ~CadastroIS(){}
};

//Criar interface com stubs da camada de servico para a camada de apresentacao

/*----------------------------------------------------------------------------*/

class VocabulariosIA{
    public:
    virtual void Executar(const ResultadoUsuario) throw (invalid_argument) = 0;
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

    virtual vector<VocControlado> ListaVocabulario() = 0;
    virtual void ConsultarVocabulario(const VocControlado&) throw(invalid_argument) = 0;
    virtual vector<Termo> ApresentaTermos(const VocControlado&) throw(invalid_argument) = 0;
    virtual void ConsultarTermo(const Termo&) throw(invalid_argument) = 0;
    virtual Definicao BuscaDefinicaoTermo(const Termo&) throw(invalid_argument) = 0;
    virtual void ConsultaDefinicaoTermo(const Definicao&) = 0;
    //Leitor utiliza ateh esse ponto

    /*virtual Resultado CriaTermo(const Termo&) throw(invalid_argument) = 0;
    //virtual Resultado ExcluirTermo(const Termo&) throw(invalid_argument) = 0;
    //virtual Resultado EditarTermo(const Termo&) throw(invalid_argument) = 0;
    virtual Resultado EditarDefinicaoTermo(const Termo&) throw(invalid_argument) = 0;
    //Desenvolvedor utiliza ateh esse ponto

    virtual Resultado CriaVocabulario(const VocControlado&) throw(invalid_argument) = 0;
    //Quando a conta de um administrador eh excluida deve-se excluir todos os vocabularios que o mesmo criou, como realizar tal processo?
    virtual Resultado ExcluirVocabulario(const VocControlado&) throw(invalid_argument) = 0;
    virtual Resultado EditarDefinicaoVocabulario(const VocControlado&) throw(invalid_argument) = 0;
    virtual Resultado AlterarIdiomaVocabulario(const VocControlado&) throw(invalid_argument) = 0;
    */
    //Administrador utiliza ateh esse ponto

    virtual ~VocabulariosIS(){}
};

#endif
