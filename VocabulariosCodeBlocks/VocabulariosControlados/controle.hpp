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
        ResultadoAutenticacao Autenticar() throw (invalid_argument) override;
        void set_aut_ia(AutenticacaoIS *) override;
};

void inline ApresentacaoControle::set_aut_ia(AutenticacaoIS* CntrLinkAut){
    this->CntrLinkAut = CntrLinkAut;
}

/*----------------------------------------------------------------------------*/

#endif
