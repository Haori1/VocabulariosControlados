#ifndef __SERVICO_HPP__
#define __SERVICO_HPP__

#include "controle.hpp"
#include "comandos.hpp"
#include "dominios.hpp"
#include "entidades.hpp"
#include "interfaces.hpp"
#include "comandoSQL.hpp"

using namespace std;

/**
 * @file servicos.hpp
 * @author Henrique Mendes de Freitas Mariano
 * @author Gabriel Alves Castro
 * @date 17 de junho de 2018
 *
 * @brief Controladoras da camada de serviços que regulamentam as regras de negócio.
 *
 */

/*----------------------------------------------------------------------------------*/

/**
 * @brief Classe que regulamenta o cadastro de usuarios no sistema e regulamenta as regras de negócio.
 */


class ServicoCadastroControle : public CadastroIS {
    private:
        Leitor leitor;
        Desenvolvedor desenvolvedor;
        Administrador administrador;

    public:
        Resultado CadastroLeitor(const Nome &nome, const Sobrenome &sobrenome,
                                 const Correio_Eletronico &correio_eletronico, const Senha &senha) throw (invalid_argument) override;

        Resultado CadastroDesenvolvedor(const Nome &nome, const Sobrenome &sobrenome,
                                        const Data &data_nascimento, const Correio_Eletronico &correio_eletronico,
                                        const Senha &senha) throw (invalid_argument) override;

        Resultado CadastroAdministrador(const Nome &nome, const Sobrenome &sobrenome,
                                        const Telefone &telefone, const Data &data_nascimento,
                                        const Endereco &endereco, const Correio_Eletronico &correio_eletronico,
                                        const Senha &senha) throw (invalid_argument) override;
};

/*----------------------------------------------------------------------------------*/

/**
 * @brief Classe que regulamenta a autenticação do sistema.
 */


class ServicoAutenticacaoControle : public AutenticacaoIS {
    public:
        ResultadoUsuario Autenticar(const Correio_Eletronico&, const Senha&) throw (invalid_argument) override;
};

/*----------------------------------------------------------------------------------*/

/**
 * @brief Classe que fornece os serviços de usuario, como exibir, excluir, editar, e regulamenta as regras de negócio do sistema.
 */

class ServicoUsuarioControle : public UsuarioIS {
    public:
        void Exibir(const Leitor&) throw (invalid_argument) override;
        void Exibir(const Desenvolvedor&) throw (invalid_argument) override;
        void Exibir(const Administrador&) throw (invalid_argument) override;
        Resultado Excluir(const Correio_Eletronico&) throw (invalid_argument) override;
        ResultadoUsuario Editar(const Leitor&) throw (invalid_argument) override;
        ResultadoUsuario Editar(const Desenvolvedor&) throw (invalid_argument) override;
        ResultadoUsuario Editar(const Administrador&) throw (invalid_argument) override;
        ResultadoUsuario EditarLeitor(const Correio_Eletronico&) throw (invalid_argument) override;
        ResultadoUsuario EditarDesenvolvedor(const Correio_Eletronico&) throw (invalid_argument) override;
        ResultadoUsuario EditarAdministrador(const Correio_Eletronico&) throw (invalid_argument) override;
};

/*----------------------------------------------------------------------------------*/

/**
 * @brief Classe que fornece os serviços de Vocabulário, e regulamenta as regras de negócio do sistema
 */

class ServicoVocabulariosControle : public VocabulariosIS{
    private:
        int VALOR_MAXIMO_DESENVOLVEDORES = 10;
        int VALOR_MAXIMO_DEFINICOES = 5;
    public:
        vector<VocControlado> ListaVocabulario() override;
        void ConsultarVocabulario(const VocControlado&) throw(invalid_argument) override;
        vector<Termo> ApresentaTermos(const VocControlado&) throw(invalid_argument) override;
        void ConsultarTermo(const Termo&) throw(invalid_argument) override;
        vector<Definicao> BuscaDefinicaoTermo(const Termo&) throw(invalid_argument) override;
        void ConsultaDefinicaoTermo(const vector<Definicao>&) throw(invalid_argument) override;

        Resultado CriaTermo(string nome_voc) throw(invalid_argument) override;
        Resultado ExcluirTermo(const Termo&) throw(invalid_argument) override;
        Resultado CriaVocabulario(const ResultadoUsuario &resultado_usuario) throw(invalid_argument) override;
        Resultado ExcluirVocabulario(const VocControlado&) throw(invalid_argument) override;
        Resultado EditarDefinicaoVocabulario(string voc) throw(invalid_argument) override;
        Resultado EditarDefinicaoTermo(string Texto_Definicao_anterior) throw(invalid_argument) override;
        Resultado AlterarIdiomaVocabulario(VocControlado&) throw(invalid_argument) override;
        Resultado EditarTermo(Termo &termo) throw(invalid_argument) override;

        Resultado CadastraDesenvolvedor(string voc, string correio_eletronico) throw(invalid_argument) override;
        Resultado CriaDefinicaoTermo(const Termo&) throw(invalid_argument) override;

        ResultadoUsuario RetornaAcessoUsuarioVocabulario(const ResultadoUsuario&, string voc) throw(invalid_argument) override;
};

/*----------------------------------------------------------------------------------*/

#endif
