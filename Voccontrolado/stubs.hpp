#ifndef __STUBS__HPP__
#define __STUBS__HPP__

#include <iostream>
#include <stdexcept>
#include <exception>

#include "interfaces.hpp"
#include "comandos.hpp"
#include "dominios.hpp"

using namespace std;

/**
 * @file stubs.hpp
 * @author Henrique Mendes de Freitas Mariano
 * @author Gabriel Alves Castro
 * @date 18 de maio de 2018
 *
 * @brief Simulacao da camada de servicos.
 *
 */

/*----------------------------------------------------------------------------*/

/**
 * @brief Classe com a funcao de simular os servicos de autenticacao, contem os triggers para a simulacao do sistema.
 *
 */

class StubAutenticacao : public AutenticacaoIS{
    public:
        static constexpr const char* TRIGGER_FALHA_SENHA = "Eoqxd12";
        static constexpr const char* TRIGGER_ERRO_SISTEMA_SENHA = "xd12E";

        static constexpr const char* TRIGGER_FALHA_EMAIL = "narutouzumaki@gmail.com";
        static constexpr const char* TRIGGER_ERRO_SISTEMA_EMAIL = "deuruim@hotmail.com";

        static constexpr const char* TRIGGER_LEITOR = "rafael@hotmail.com";
        static constexpr const char* NOME_LEITOR = "Rafael";
        static constexpr const char* SOBRENOME_LEITOR = "Jesus";

        static constexpr const char* TRIGGER_DESENVOLVEDOR = "henrique@gmail.com";
        static constexpr const char* NOME_DESENVOLVEDOR = "Henrique";
        static constexpr const char* SOBRENOME_DESENVOLVEDOR = "Mariano";
        static constexpr const char* DATA_DESENVOLVEDOR = "11/03/1999"; //checar o formato correto da data.

        static constexpr const char* TRIGGER_ADMINISTRADOR = "gabriel@unb.com";
        static constexpr const char* NOME_ADMINISTRADOR = "Gabriel";
        static constexpr const char* SOBRENOME_ADMINISTRADOR = "Alves";
        static constexpr const char* DATA_ADMINISTRADOR = "11/03/1999";
        static constexpr const char* TELEFONE_ADMINISTRADOR = "99 99999-9999";
        static constexpr const char* ENDERECO_ADMINISTRADOR = "Aldeiadafolha";

        static constexpr const char* TRIGGER_FALHA_LEITOR = "teste@gmail.com";

        static constexpr const char* TRIGGER_ERRO_SISTEMA_LEITOR = "erro@gmail.com";

        static constexpr const char* TRIGGER_FALHA_DESENVOLVEDOR = "emailtop@hotmail.com";

        static constexpr const char* TRIGGER_ERRO_SISTEMA_DESENVOLVEDOR = "errodev@gmail.com";

        static constexpr const char* TRIGGER_FALHA_ADMINISTRADOR = "fernando@unb.com";

        static constexpr const char* TRIGGER_ERRO_SISTEMA_ADMINISTRADOR = "erroadm@gmail.com";

        Resultado Autenticar(const Correio_Eletronico&, const Senha&) throw (invalid_argument) override;
        ResultadoUsuario TipoDeUsuario(const Correio_Eletronico&, const Senha&) override;

};

/*----------------------------------------------------------------------------*/

/**
 * @brief Classe com a funcao de simular os servicos de cadastro, contem os triggers para a simulacao do sistema.
 *
 */

class StubCadastro : public CadastroIS{
    private:
        Leitor leitor;
        Desenvolvedor desenvolvedor;
        Administrador administrador;

    public:
        static constexpr const char* TRIGGER_CORREIO_ELETRONICO = "junkdog@gmail.com";
        static constexpr const char* TRIGGER_ERRO_SISTEMA_EMAIL = "eaemeuchapa@gmail.com";
        Resultado CadastroLeitor(const Leitor&) throw (invalid_argument) override;
        Resultado CadastroDesenvolvedor(const Desenvolvedor&) throw (invalid_argument) override;
        Resultado CadastroAdministrador(const Administrador&) throw (invalid_argument) override;


};

/*----------------------------------------------------------------------------*/

/**
 * @brief Classe com a funcao de simular os servicos de usuario.
 *
 */

class StubUsuario : public UsuarioIS{
    public:
        void Exibir(const ResultadoUsuario) throw (invalid_argument) override;
        ResultadoUsuario Editar(const ResultadoUsuario) throw (invalid_argument) override;
        Resultado Excluir() throw (invalid_argument) override;
        ResultadoUsuario EditarLeitor() throw (invalid_argument) override;
        ResultadoUsuario EditarDesenvolvedor() throw (invalid_argument) override;
        ResultadoUsuario EditarAdministrador() throw (invalid_argument) override;
};

/*----------------------------------------------------------------------------*/

/**
 * @brief Classe com a funcao de simular os servicos de vocabulario, contem os triggers para a simulacao do sistema.
 *
 */

 class StubVocabularios : public VocabulariosIS{
     private:
         static constexpr const char* TRIGGER_VOCABULARIO_MATEMATICA = "Matematica";
         static constexpr const char* TRIGGER_VOCABULARIO_ANIMES = "Animes";
         static constexpr const char* TRIGGER_VOCABULARIO_ERRO = "Filosofia";
         static constexpr const char* TRIGGER_TERMO_ERRO = "Quadrado";
         static constexpr const char* TRIGGER_DEFINICAO_ERRO = "Boruto";
         static constexpr const char* TRIGGER_DEFINICAO_TRIANGULO = "Triangulo";
         static constexpr const char* TRIGGER_DEFINICAO_NARUTO = "Naruto";

     public:
         vector<VocControlado> ListaVocabulario() override;
         void ConsultarVocabulario(const VocControlado&) throw(invalid_argument) override;
         vector<Termo> ApresentaTermos(const VocControlado&) throw(invalid_argument) override;
         void ConsultarTermo(const Termo&) throw(invalid_argument) override;
         Definicao BuscaDefinicaoTermo(const Termo&) throw(invalid_argument) override;
         void ConsultaDefinicaoTermo(const Definicao&) override;

         Resultado CriaTermo(const Termo&) throw(invalid_argument) override;
         Resultado ExcluirTermo(const Termo&) throw(invalid_argument) override;
         Resultado CriaVocabulario(const VocControlado&) throw(invalid_argument) override;
         Resultado ExcluirVocabulario(const VocControlado&) throw(invalid_argument) override;
         Resultado EditarDefinicaoVocabulario(Definicao &definicao) throw(invalid_argument) override;//
         Resultado EditarDefinicaoTermo(Termo&) throw(invalid_argument) override;
         Resultado AlterarIdiomaVocabulario(VocControlado&) throw(invalid_argument) override;
         Resultado EditarTermo(Termo&) throw(invalid_argument) override;//


 };

#endif
