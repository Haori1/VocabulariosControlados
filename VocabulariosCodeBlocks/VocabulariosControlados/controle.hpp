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
        ResultadoAutenticacao Autenticar() throw (invalid_argument) override;
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

#endif
