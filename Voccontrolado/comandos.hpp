#ifndef __COMANDOS_HPP__
#define __COMANDOS_HPP__

#include <iostream>
#include <stdexcept>
#include <exception>
#include <cstdlib>

#include "interfaces.hpp"
#include "dominios.hpp"
#include "entidades.hpp"
#include "stubs.hpp"
#include "controle.hpp"

using namespace std;

/*----------------------------------------------------------------------------*/

class ComandoCadastro {
    public:
        virtual void ExecutarComando(CadastroIS *) throw (invalid_argument) = 0; //Interface dos comandos
        virtual ~ComandoCadastro(){}

};

/*----------------------------------------------------------------------------*/

class ComandoCadastroLeitorIA : public ComandoCadastro {
    public:
        void ExecutarComando(CadastroIS *) throw (invalid_argument) override;
};

class ComandoCadastroDesenvolvedorIA : public ComandoCadastro {
    public:
        void ExecutarComando(CadastroIS *) throw (invalid_argument) override;

};

class ComandoCadastroAdministradorIA : public ComandoCadastro {
    public:
        void ExecutarComando(CadastroIS *) throw (invalid_argument) override;
};

#endif
