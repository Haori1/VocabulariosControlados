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

        //const static string Valor_Valido_Nome;
        //const static string Valor_Invalido_Nome_1;
        //const static string Valor_Invalido_Nome_2;
        //const static string Valor_Invalido_Nome_3;
        //const static string Valor_Invalido_Nome_4;
        //const static int sucesso = true;
        //const static int falha = false;

        bool estado;
        void setUp();
        void tearDown();
        void casoSucesso();
        void casoFalha();

    public:
        bool run();
};

        //const string  TNome::Valor_Valido_Nome = "Joniscleuson";
        //const string  TNome::Valor_Invalido_Nome_1 = "eaemermao";
        //const string TNome::Valor_Invalido_Nome_2 = "23eoq";
        //const string TNome::Valor_Invalido_Nome_3 = "Mas0qu3";
        //const string TNome::Valor_Invalido_Nome_4 = "\0";

#endif
