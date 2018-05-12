#ifndef __CONTROLE__HPP_
#define __CONTROLE__HPP_

#include <stdexcept>
#include <exception>

#include "dominios.hpp"
#include "interfaces.hpp"

#define CLEAR "cls||clear"

using namespace std;

/*----------------------------------------------------------------------------*/

class ApresentacaoControle : public AutenticacaoIA{
    private:
        AutenticacaoIS* CntrLinkAut;

    public:
        bool Autenticar() throw (invalid_argument) override;

        void set_aut_ia(AutenticacaoIS *);

        static const bool FALHA = false;
        static const bool SUCESSO = true;

};

void inline ApresentacaoControle::set_aut_ia(AutenticacaoIS* CntrLinkAut){
    this->CntrLinkAut = CntrLinkAut;
}

/*----------------------------------------------------------------------------*/

#endif
