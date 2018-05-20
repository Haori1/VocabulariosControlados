#ifndef __CONTROLE__HPP_
#define __CONTROLE__HPP_

#include <stdexcept>
#include <exception>

#include "dominios.hpp"
#include "interfaces.hpp"

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
        CadastroIS* cntr_link_cadastro;

    public:
        void Executar() throw (invalid_argument) override;
        void set_cadastro_ia(CadastroIS *) override;
};

void inline ApresentacaoCadastroControle::set_cadastro_ia(CadastroIS* cntr_link_cadastro){
    this->cntr_link_cadastro = cntr_link_cadastro;
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

    public:
        void Executar(const ResultadoUsuario&) throw (invalid_argument) override;
        void set_vocabulario_ia(VocabulariosIS *) override;
};

/*----------------------------------------------------------------------------*/


#endif
