#ifndef __MAAUT_HPP__
#define __MAAUT_HPP__

#include "interfaces.hpp"

class stubAUT : public Autenticacao_IS {
    private:
        static constexpr const char* Valor_Conhecido_Email = "gabriel@unb.br";
        static constexpr const char* Valor_Desconhecido_Email = "anna@unb.br";
        static constexpr const char* Valor_Conhecido_Senha = "EaeM3ule";
        static constexpr const char* Valor_Desconhecido_Senha = "EaeMeu";

    public:

};


#endif
