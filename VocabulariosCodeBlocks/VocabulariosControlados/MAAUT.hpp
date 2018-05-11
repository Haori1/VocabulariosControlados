#ifndef __MAAUT_HPP__
#define __MAAUT_HPP__

#include "interfaces.hpp"
#include "stubMSAUT.hpp"

class Valida_Correio_Eletronico {
    private:
        Correio_Eletronico email;

    public:
        string Autentica(string);

};

class Valida_Senha {
    private:
         Senha senha;

    public:
        string Autentica(string);

};

class Controlador_AAUT : public Autenticacao_IA {
    private:
        Valida_Senha Valida_Senha_;
        Valida_Correio_Eletronico Valida_Correio_Eletronico_; //Ver padrao do google
        stubAUT stubAUT_;


    public:
        void Testa_Validade(string, string);

};

#endif
