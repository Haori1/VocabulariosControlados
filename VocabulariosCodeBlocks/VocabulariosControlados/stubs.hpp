#ifndef __STUBS__HPP__
#define __STUBS__HPP__

#include <iostream>
#include <stdexcept>
#include <exception>

#include "interfaces.hpp"
#include "dominios.hpp"

using namespace std;

class StubAutenticacao : public AutenticacaoIS{
    public:
        static constexpr const char* TRIGGER_FALHA_SENHA = "Eoqxd12";
        static constexpr const char* TRIGGER_SUCESSO_SENHA = "Boalek1";
        static constexpr const char* TRIGGER_ERRO_SISTEMA_SENHA = "xd12E";

        static constexpr const char* TRIGGER_FALHA_EMAIL = "narutouzumaki@gmail.com";
        static constexpr const char* TRIGGER_SUCESSO_EMAIL = "borutouzumaki@gmail.com";
        static constexpr const char* TRIGGER_ERRO_SISTEMA_EMAIL = "deuruim@hotmail.com";

        bool Autenticar(const Correio_Eletronico&, const Senha&) throw (invalid_argument);

};





#endif
