#ifndef __TESTES__HPP__
#define __TESTES__HPP__

#include "dominiosClasses.hpp"
#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>

#define Valor_Valido_Nome "Joniscleuson"
#define Valor_Invalido_Nome_1 "eaemermao"
#define Valor_Invalido_Nome_2 "23eoq"
#define Valor_Invalido_Nome_3 "Mas0qu3"
#define Valor_Invalido_Nome_4 "\0"
#define sucesso true
#define falha false

using namespace std;

class TNome{
    private:
        Nome* nome;
        bool estado;
        void setUp();
        void tearDown();
        void casoSucesso();
        void casoFalha();

    public:
        bool run();
};

#endif
