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

class ApresentacaoControle;
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
        virtual ResultadoUsuario Autenticar(const Correio_Eletronico&, const Senha&) throw (invalid_argument) = 0;
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
        virtual Resultado Executar(const ResultadoUsuario) throw (invalid_argument) = 0;
        /**
         * @brief set_usuario_ia() é a função que é responsavel por linkar a camada de apresentacao com as stubs.
         * @param UsuarioIS *
         * @return void
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
     * @return void
     */
        virtual void Exibir(const Leitor&) throw (invalid_argument) = 0;
        virtual void Exibir(const Desenvolvedor&) throw (invalid_argument) = 0;
        virtual void Exibir(const Administrador&) throw (invalid_argument) = 0;
        /**
         * @brief Editar() é uma funcao que a partir de ResultadoUsuario ele pega o objeto que é passado a ele e edita seu conteudo.
         * @param const ResultadoUsuario
         * @return ResultadoUsuario, retorna se foi sucesso ou falha e um objeto Leitor, Desenvolvedor ou Administrador.
         */
        //virtual ResultadoUsuario Editar(const ResultadoUsuario) throw (invalid_argument) = 0;
        /**
         * @brief Excluir() é uma funcao que exclui o usuario quando passado a sua senha.
         * @return Resultado, retorna se foi sucesso ou falha.
         */
        //virtual Resultado Excluir() throw (invalid_argument) = 0;
        //virtual ResultadoUsuario EditarLeitor() throw (invalid_argument) = 0;
        //virtual ResultadoUsuario EditarDesenvolvedor() throw (invalid_argument) = 0;
        //virtual ResultadoUsuario EditarAdministrador() throw (invalid_argument) = 0;
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
         * @return A funcao retorna Resultado indicando se foi sucesso ou falha.
         */
        virtual Resultado CadastroLeitor(const Nome &nome, const Sobrenome &sobrenome,
                                         const Correio_Eletronico &correio_eletronico, const Senha &senha) throw (invalid_argument) = 0;
        /**
         * @brief CadastroDesenvolvedor() é uma funcao que a partir de Leitor ele pega os dados do usuario e passa para o objeto Desenvolvedor.
         * @param const Leitor&
         * @return A funcao retorna Resultado indicando se foi sucesso ou falha.
         */
        virtual Resultado CadastroDesenvolvedor(const Nome &nome, const Sobrenome &sobrenome,
                                                const Data &data_nascimento, const Correio_Eletronico &correio_eletronico,
                                                const Senha &senha) throw (invalid_argument) = 0;
        /**
         * @brief CadastroAdministrador() é uma funcao que a partir de Leitor ele pega os dados do usuario e passa para o objeto Administrador.
         * @param const Leitor&
         * @return A funcao retorna Resultado indicando se foi sucesso ou falha.
         */
        virtual Resultado CadastroAdministrador(const Nome &nome, const Sobrenome &sobrenome,
                                                const Telefone &telefone, const Data &data_nascimento,
                                                const Endereco &endereco, const Correio_Eletronico &correio_eletronico,
                                                const Senha &senha) throw (invalid_argument) = 0;
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
    virtual Resultado Executar(const ResultadoUsuario) throw (invalid_argument) = 0;
    /**
     * @brief set_vocabulario_ia() é a função que é responsavel por linkar a camada de apresentacao com as stubs.
     * @param VocabulariosIS *
     * @return void
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
        /**
         * @brief ListaVocabulario() é uma funcao que lista os vocabularios de acordo com a stub.
         * @return Retorna uma lista de vocabularios vector<VocControlado>
         */
        virtual vector<VocControlado> ListaVocabulario() = 0;
        /**
         * @brief ConsultarVocabulario() é uma funcao que imprime o conteudo de vocabulario, ou seja, Data e Idioma.
         * @return void
         */
        virtual void ConsultarVocabulario(const VocControlado&) throw(invalid_argument) = 0;
        /**
         * @brief ApresentaTermos() é uma funcao que imprime os termos de um vocabulario controlado.
         * @param const VocControlado&
         * @return Retorna uma lista de termos vector<Termo>
         */
        virtual vector<Termo> ApresentaTermos(const VocControlado&) throw(invalid_argument) = 0;
        /**
         * @brief ConsultarTermo() é uma funcao que imprime o conteudo de termo, ou seja, Termo e Data.
         * @param const Termo&
         * @return void
         */
        virtual void ConsultarTermo(const Termo&) throw(invalid_argument) = 0;
        /**
         * @brief BuscaDefinicaoTermo() é uma funcao que busca a definicao do termo passado.
         * @param const Termo&
         * @return Definicao
         */
        virtual Definicao BuscaDefinicaoTermo(const Termo&) throw(invalid_argument) = 0;
        /**
         * @brief ConsultaDefinicaoTermo() é uma funcao que imprime a definicao de um termo.
         * @param const Definicao&
         * @return void
         */
        virtual void ConsultaDefinicaoTermo(const Definicao&) = 0;
    //Leitor utiliza ateh esse ponto

    /**
     * @brief CriaTermo() é uma funcao que cria um Termo.
     * @param const Termo&
     * @return Resultado, retorna se foi sucesso ou falha.
     */
    virtual Resultado CriaTermo() throw(invalid_argument) = 0;
    /**
     * @brief ExcluirTermo() é uma funcao que exclui o tipo Termo passado.
     * @param const Termo&
     * @return Resultado, retorna se foi sucesso ou falha.
     */
    virtual Resultado ExcluirTermo(const Termo&) throw(invalid_argument) = 0;
    /**
     * @brief EditarTermo() é uma funcao que edita o tipo Termo passado.
     * @param const Termo&
     * @return Resultado, retorna se foi sucesso ou falha.
     */
    virtual Resultado EditarTermo(Termo&) throw(invalid_argument) = 0;
    /**
     * @brief EditarDefinicaoTermo() é uma funcao que edita a definicao do Termo passado.
     * @param const Termo&
     * @return Resultado, retorna se foi sucesso ou falha.
     */
    virtual Resultado EditarDefinicaoTermo(Termo&) throw(invalid_argument) = 0;
    //Desenvolvedor utiliza ateh esse ponto
    /**
     * @brief CriaVocabulario() é uma funcao que cria um vocabulario.
     * @param const VocControlado&
     * @return Resultado, retorna se foi sucesso ou falha.
     */
    virtual Resultado CriaVocabulario(ResultadoUsuario&) throw(invalid_argument) = 0;
    /**
     * @brief ExcluirVocabulario() é uma funcao que exclui o vocabulario passado.
     * @param const VocControlado&
     * @return Resultado, retorna se foi sucesso ou falha.
     */
    virtual Resultado ExcluirVocabulario(const VocControlado&) throw(invalid_argument) = 0;
    /**
     * @brief EditarAdministrador() é uma funcao que exclui o vocabulario passado.
     * @param Definicao&
     * @return Resultado, retorna se foi sucesso ou falha.
     */
    virtual Resultado EditarDefinicaoVocabulario(Definicao&) throw(invalid_argument) = 0;
    /**
     * @brief AlterarIdiomaVocabulario() é uma funcao que altera o idioma do vocabulario passado.
     * @param VocControlado&
     * @return Resultado, retorna se foi sucesso ou falha.
     */
    virtual Resultado AlterarIdiomaVocabulario(VocControlado&) throw(invalid_argument) = 0;

    /**
     * @brief Destrutor virtual default da classe VocabulariosIS.
     */

    virtual ~VocabulariosIS(){}
};


#endif
