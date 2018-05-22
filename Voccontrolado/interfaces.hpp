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

/**
 * @file interfaces.hpp
 * @author Henrique Mendes de Freitas Mariano
 * @author Gabriel Alves Castro
 * @date 18 de maio de 2018
 *
 * @brief Interfaces do sistema. Permitem a modularizacao do sistema.
 *
 */

class AutenticacaoIS;  //Autenticação anterior para o link reconhecer a classe
class UsuarioIS;
class CadastroIS;
class VocabulariosIS;

/*----------------------------------------------------------------------------*/

/**
 * @brief Classe abstrata com o intuito de definir a interface entre o controle a camada de apresentacao.
 */

class AutenticacaoIA{
    public:
        /**
         * @brief Autenticar() é a função que é responsavel por fazer a interface com a camada de servicos.
         */
        virtual ResultadoUsuario Autenticar() throw (invalid_argument) = 0; //Metodo virtual de autenticacao

        /**
         * @brief set_aut_ia() é a função que é responsavel por linkar a camada de apresentacao com as stubs.
         * @param AutenticacaoIS *
         */

        virtual void set_aut_ia(AutenticacaoIS *) = 0; //Link IA-IS

        /**
         * @brief Destrutor virtual default da classe AutenticacaoIA.
         */

        virtual ~AutenticacaoIA(){} //Destrutor Virtual
};

/**
 * @brief Classe abstrata com o intuito de definir a interface entre a camada de servicos a camada de apresentacao.
 */

class AutenticacaoIS{
    public:
        /**
         * @brief Autenticar() é a função que é responsavel por fazer a simulacao do servico de autenticar.
         * @param const Correio_Eletronico&
         * @param const Senha&
         */
        virtual Resultado Autenticar(const Correio_Eletronico&, const Senha&) throw (invalid_argument) = 0;
        /**
         * @brief TipoDeUsuario() é uma funcao que a partir do email, ele determina que tipo de usuario ira ser escrito e retornado pelo ResultadoUsuario.
         * @param const Correio_Eletronico&
         * @param const Senha&
         */
        virtual ResultadoUsuario TipoDeUsuario(const Correio_Eletronico&, const Senha&) = 0;

        /**
         * @brief Destrutor virtual default da classe AutenticacaoIS.
         */

        virtual ~AutenticacaoIS(){}
};

/*----------------------------------------------------------------------------*/

/**
 * @brief Classe abstrata com o intuito de definir a interface entre o controle a camada de apresentacao.
 */

class UsuarioIA{
    public:
        virtual void Executar(const ResultadoUsuario) throw (invalid_argument) = 0;
        /**
         * @brief set_usuario_ia() é a função que é responsavel por linkar a camada de apresentacao com as stubs.
         * @param UsuarioIS *
         */
        virtual void set_usuario_ia(UsuarioIS *) = 0; //Link IA-IS
        /**
         * @brief Destrutor virtual default da classe UsuarioIA.
         */
        virtual ~UsuarioIA(){}

};

/**
 * @brief Classe abstrata com o intuito de definir a interface entre a camada de servicos a camada de apresentacao.
 */

class UsuarioIS{
    public:
    /**
     * @brief Exibir() é uma funcao que a partir de ResultadoUsuario ele pega o objeto que é passado a ele e imprime.
     * @param const ResultadoUsuario
     */
        virtual void Exibir(const ResultadoUsuario) throw (invalid_argument) = 0;
        /**
         * @brief Editar() é uma funcao que a partir de ResultadoUsuario ele pega o objeto que é passado a ele e edita seu conteudo.
         * @param const ResultadoUsuario
         */
        virtual ResultadoUsuario Editar(const ResultadoUsuario) throw (invalid_argument) = 0;
        virtual Resultado Excluir() throw (invalid_argument) = 0;
        virtual ResultadoUsuario EditarLeitor() throw (invalid_argument) = 0;
        virtual ResultadoUsuario EditarDesenvolvedor() throw (invalid_argument) = 0;
        virtual ResultadoUsuario EditarAdministrador() throw (invalid_argument) = 0;
        /**
         * @brief Destrutor virtual default da classe UsuarioIS.
         */
        virtual ~UsuarioIS(){}
};

/*----------------------------------------------------------------------------*/

/**
 * @brief Classe abstrata com o intuito de definir a interface entre o controle a camada de apresentacao.
 */

class CadastroIA{
    public:
        virtual void ExecutarIA() throw (invalid_argument) = 0;
        /**
         * @brief set_cadastro_ia() é a função que é responsavel por linkar a camada de apresentacao com as stubs.
         * @param CadastroIS *
         */
        virtual void set_cadastro_ia(CadastroIS *) = 0; //Link IA-IS
        /**
         * @brief Destrutor virtual default da classe CadastroIA.
         */
        virtual ~CadastroIA(){}
};

/**
 * @brief Classe abstrata com o intuito de definir a interface entre a camada de servicos a camada de apresentacao.
 */

class CadastroIS{
    public:
        /**
         * @brief CadastroLeitor() é uma funcao que a partir de Leitor ele pega os dados do usuario e passa para o objeto Leitor.
         * @param const Leitor&
         */
        virtual Resultado CadastroLeitor(const Leitor&) throw (invalid_argument) = 0;
        /**
         * @brief CadastroDesenvolvedor() é uma funcao que a partir de Leitor ele pega os dados do usuario e passa para o objeto Desenvolvedor.
         * @param const Leitor&
         */
        virtual Resultado CadastroDesenvolvedor(const Desenvolvedor&) throw (invalid_argument) = 0;
        /**
         * @brief CadastroAdministrador() é uma funcao que a partir de Leitor ele pega os dados do usuario e passa para o objeto Administrador.
         * @param const Leitor&
         */
        virtual Resultado CadastroAdministrador(const Administrador&) throw (invalid_argument) = 0;
        /**
         * @brief Destrutor virtual default da classe CadastroIS.
         */
        virtual ~CadastroIS(){}
};

/*----------------------------------------------------------------------------*/

/**
 * @brief Classe abstrata com o intuito de definir a interface entre o controle a camada de apresentacao.
 */

class VocabulariosIA{
    public:
    virtual void Executar(const ResultadoUsuario) throw (invalid_argument) = 0;
    /**
     * @brief set_vocabulario_ia() é a função que é responsavel por linkar a camada de apresentacao com as stubs.
     * @param VocabulariosIS *
     */
    virtual void set_vocabulario_ia(VocabulariosIS *) = 0;
    /**
     * @brief Destrutor virtual default da classe VocabulariosIA.
     */
    virtual ~VocabulariosIA(){}
};

//Responsabilidades do modulo de vocabularios:
//Criar Vocabulario (apenas para administrador)
//Criar termo (apenas para desenvolvedor)
//listar vocabulario
//Apresenta Vocabulario
//Consultar termo
//Consultar Definicao de termo
//Retornar

/**
 * @brief Classe abstrata com o intuito de definir a interface entre a camada de servicos a camada de apresentacao.
 */

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


    virtual Resultado CriaTermo(const Termo&) throw(invalid_argument) = 0;
    virtual Resultado ExcluirTermo(const Termo&) throw(invalid_argument) = 0;
    virtual Resultado EditarTermo(Termo&) throw(invalid_argument) = 0;
    virtual Resultado EditarDefinicaoTermo(Termo&) throw(invalid_argument) = 0;
    //Desenvolvedor utiliza ateh esse ponto

    virtual Resultado CriaVocabulario(const VocControlado&) throw(invalid_argument) = 0;
    //Quando a conta de um administrador eh excluida deve-se excluir todos os vocabularios que o mesmo criou, como realizar tal processo?
    virtual Resultado ExcluirVocabulario(const VocControlado&) throw(invalid_argument) = 0;
    virtual Resultado EditarDefinicaoVocabulario(Definicao&) throw(invalid_argument) = 0;
    virtual Resultado AlterarIdiomaVocabulario(VocControlado&) throw(invalid_argument) = 0;

    /**
     * @brief Destrutor virtual default da classe VocabulariosIS.
     */

    virtual ~VocabulariosIS(){}
};

#endif
