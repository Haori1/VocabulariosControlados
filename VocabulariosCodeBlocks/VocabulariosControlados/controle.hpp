#ifndef __CONTROLE__HPP_
#define __CONTROLE__HPP_

#include <stdexcept>
#include <exception>

#include "dominios.hpp"
#include "interfaces.hpp"

#define CLEAR "cls||clear"

using namespace std;

class ApresentacaoControle : public IUAutenticacao {
    private:
        int escolha;

        void Controle();
        bool Autenticar() throw (invalid_argument);

    public:
        const static int ACESSAR_CONTA = 1;
        const static int CADASTRAR = 2;
        const static int SAIR = 3;

        void Menu(){
            Controle();
        }

};

#endif
