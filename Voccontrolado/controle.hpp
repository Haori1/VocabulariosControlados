#ifndef __CONTROLE__HPP_
#define __CONTROLE__HPP_

#include <stdexcept>
#include <exception>

#include "dominios.hpp"
#include "interfaces.hpp"
#include "comandos.hpp"

#define CLEAR "cls||clear"

using namespace std;

/*----------------------------------------------------------------------------*/

class ApresentacaoAutenticacaoControle : public AutenticacaoIA{
    private:
        AutenticacaoIS* cntr_link_autenticacao;

    public:
        ResultadoUsuario Autenticar() throw (invalid_argument) override;
        void set_aut_ia(AutenticacaoIS *) override;
};

void inline ApresentacaoAutenticacaoControle::set_aut_ia(AutenticacaoIS* cntr_link_autenticacao){
    this->cntr_link_autenticacao = cntr_link_autenticacao;
}

/*----------------------------------------------------------------------------*/

class ApresentacaoCadastroControle : public CadastroIA{
    private:
        const static int LEITOR = 1;
        const static int DESENVOLVEDOR = 2;
        const static int ADMINISTRADOR = 3;
        const static int RETORNAR = 4;
        CadastroIS* cntr_link_cadastro;

    public:
        void ExecutarIA() throw (invalid_argument) override;
        void set_cadastro_ia(CadastroIS *) override;
};

void inline ApresentacaoCadastroControle::set_cadastro_ia(CadastroIS* cntr_link_cadastro){
    this->cntr_link_cadastro = cntr_link_cadastro;
}

/*----------------------------------------------------------------------------*/

class ApresentacaoUsuarioControle : public UsuarioIA{
    private:
        const static int EXIBIR = 1;
        const static int EDITAR = 2;
        const static int EXCLUIR = 3;
        const static int RETORNAR = 4;
        UsuarioIS* cntr_link_usuario;

    public:
        void Executar(ResultadoUsuario resultado_usuario) throw (invalid_argument) override;
        void set_usuario_ia(UsuarioIS *) override;
};

void inline ApresentacaoUsuarioControle::set_usuario_ia(UsuarioIS* cntr_link_usuario){
    this->cntr_link_usuario = cntr_link_usuario;
}

/*----------------------------------------------------------------------------*/

class ApresentacaoVocabularioControle : public VocabulariosIA{
    private:
    const static int LISTAR_VOCABULARIO = 1;
    const static int APRESENTAR_VOCABULARIO = 2;
    const static int CONSULTAR_TERMO = 3;
    const static int CONSULTAR_DEFINICAO_TERMO = 4;
    const static int CRIAR_TERMO = 5;
    const static int EXCLUIR_TERMO = 6;
    const static int EDITAR_TERMO = 7;
    const static int EDITAR_DEFINICAO_TERMO = 8;
    const static int CRIAR_VOCABULARIO = 9;
    const static int EXCLUIR_VOCABULARIO = 10;
    const static int EDITAR_DEFINICAO_VOCABULARIO = 11;
    const static int ALTERAR_IDIOMA_VOCABULARIO = 12;

    VocabulariosIS *cntr_link_vocabulario;

    public:
        void Executar(const ResultadoUsuario) throw (invalid_argument) override;
        void set_vocabulario_ia(VocabulariosIS *) override;
};

void inline ApresentacaoVocabularioControle::set_vocabulario_ia(VocabulariosIS* cntr_link_vocabulario){
    this->cntr_link_vocabulario = cntr_link_vocabulario;
}

#endif
