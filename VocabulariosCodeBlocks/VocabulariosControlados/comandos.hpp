#ifndef __COMANDOS_HPP__
#define __COMANDOS_HPP__

#include <iostream>
#include <stdexcept>
#include <exception>

#include "interfaces.hpp"
#include "dominios.hpp"
#include "entidades.hpp"

using namespace std;

/*----------------------------------------------------------------------------*/

class ComandoCadastro{
    public:
        virtual Resultado Executar(CadastroIS *) throw (invalid_argument) = 0; //Interface dos comandos
        virtual ~ComandoCadastro(){}

};

/*----------------------------------------------------------------------------*/

class ComandoCadastroIA : public ComandoCadastro {
    public:
        const static int LEITOR = 1;
        const static int DESENVOLVEDOR = 2;
        const static int ADMINISTRADOR = 3;
        const static int RETORNAR = 4;
        Resultado Executar(CadastroIS *) throw (invalid_argument) override;
};







#endif
