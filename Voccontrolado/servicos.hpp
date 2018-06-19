#ifndef __SERVICO_HPP__
#define __SERVICO_HPP__

#include "controle.hpp"
#include "comandos.hpp"
#include "dominios.hpp"
#include "entidades.hpp"
#include "interfaces.hpp"
#include "comandoSQL.hpp"

using namespace std;

/*----------------------------------------------------------------------------------*/

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

class ServicoAutenticacaoControle : public AutenticacaoIS {
    public:
        ResultadoUsuario Autenticar(const Correio_Eletronico&, const Senha&) throw (invalid_argument) override;
        ResultadoUsuario TipoDeUsuario(const Correio_Eletronico&, const Senha&) override;
};

/*----------------------------------------------------------------------------------*/

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


class ServicoVocabulariosControle : public VocabulariosIS{
    public:
        vector<VocControlado> ListaVocabulario() override;
        void ConsultarVocabulario(const VocControlado&) throw(invalid_argument) override;
        vector<Termo> ApresentaTermos(const VocControlado&) throw(invalid_argument) override;
        void ConsultarTermo(const Termo&) throw(invalid_argument) override;
        // Definicao BuscaDefinicaoTermo(const Termo&) throw(invalid_argument) override;
        // void ConsultaDefinicaoTermo(const Definicao&) override;

        Resultado CriaTermo(string nome_voc) throw(invalid_argument) override;
        Resultado ExcluirTermo(const Termo&) throw(invalid_argument) override;
        Resultado CriaVocabulario(const ResultadoUsuario &resultado_usuario) throw(invalid_argument) override;
        Resultado ExcluirVocabulario(const VocControlado&) throw(invalid_argument) override;
        Resultado EditarDefinicaoVocabulario(string voc) throw(invalid_argument) override;
        // Resultado EditarDefinicaoTermo(Termo&) throw(invalid_argument) override;
        // Resultado AlterarIdiomaVocabulario(VocControlado&) throw(invalid_argument) override;
        // Resultado EditarTermo(Termo&) throw(invalid_argument) override;//
};

/*----------------------------------------------------------------------------------*/

#endif
