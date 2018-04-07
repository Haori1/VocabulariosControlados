#ifndef __TESTES__HPP__
#define __TESTES__HPP__

#include "dominiosClasses.hpp"
#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>

using namespace std;

class TNome{
    private:
        Nome* nome;

        static constexpr const char* Valor_Valido_Nome = "Joniscleuson";
        static constexpr const char* Valor_Invalido_Nome_1 = "eaemermao";
        static constexpr const char* Valor_Invalido_Nome_2 = "23eoq";
        static constexpr const char* Valor_Invalido_Nome_3 = "Mas0qu3";
        static constexpr const char* Valor_Invalido_Nome_4 = "\0";

        bool estado;
        void setUp();
        void tearDown();
        void casoSucesso();
        void casoFalha();

    public:
        const static bool SUCESSO = true;
        const static bool FALHA = false;
        bool run();
};

class TData{
    private:
        Data* data;

        static constexpr const char* Valor_Valido_Data = "11/03/1999";
        static constexpr const char* Valor_Invalido_Data = "29/02/2018";

        bool estado;
        void setUp();
        void tearDown();
        void casoSucesso();
        void casoFalha();

    public:
        const static bool SUCESSO = true;
        const static bool FALHA = false;
        bool run();
};
#endif
