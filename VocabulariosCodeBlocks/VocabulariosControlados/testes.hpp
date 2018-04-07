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
#define Valor_Invalido_Nome_5 "Aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
#define sucesso true
#define falha false

/*---------------------------------------------------------------------------*/
#define Valor_Valido_Sobrenome "Maiusculo"
#define Valor_Invalido_Sobrenome_1 "Minusculo"
#define Valor_Invalido_Sobrenome_2 "23"
#define Valor_Invalido_Sobrenome_3 "Teste0teste3"
#define Valor_Invalido_Sobrenome_4 "\0"
#define Valor_Invalido_Sobrenome_5 "Aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
/*---------------------------------------------------------------------------*/


using namespace std;

/*---------------------------------------------------------------------------*/

class TNome{
    private:
        Nome* nome;

        //const static string Valor_Valido_Nome;
        //const static string Valor_Invalido_Nome_1;
        //const static string Valor_Invalido_Nome_2;
        //const static string Valor_Invalido_Nome_3;
        //const static string Valor_Invalido_Nome_4;
        //const static string Valor_Invalido_Nome_5;
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
        //const string TNome::Valor_Invalido_Nome_5 = "Aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";

/*---------------------------------------------------------------------------*/

class TSobrenome {
    private:
        Sobrenome* sobrenome;

        //const static string Valor_Valido_Sorenome;
        //const static string Valor_Invalido_Sobrenome_1;
        //const static string Valor_Invalido_Sobrenome_2;
        //const static string Valor_Invalido_Sobrenome_3;
        //const static string Valor_Invalido_Sobrenome_4;
        //const static string Valor_Invalido_Sobrenome_5;
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

        //const string  TNome::Valor_Valido_Sobrenome = "Joniscleuson";
        //const string  TNome::Valor_Invalido_Sobrenome_1 = "eaemermao";
        //const string TNome::Valor_Invalido_Sobrenome_2 = "23eoq";
        //const string TNome::Valor_Invalido_Sobrenome_3 = "Mas0qu3";
        //const string TNome::Valor_Invalido_Sobrenome_4 = "\0";
        //const string TNome::Valor_Invalido_Sobrenome_5 = "Aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";

/*---------------------------------------------------------------------------*/
#endif
