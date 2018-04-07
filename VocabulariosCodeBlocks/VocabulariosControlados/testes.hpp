#ifndef __TESTES__HPP__
#define __TESTES__HPP__

#include "dominiosClasses.hpp"
#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>


using namespace std;

/*---------------------------------------------------------------------------*/

class TNome{
    private:
        Nome* nome;

        static constexpr const char* Valor_Valido_Nome = "Maiusculo";
        static constexpr const char* Valor_Invalido_Nome_1 = "minusculo";
        static constexpr const char* Valor_Invalido_Nome_2 = "23numero";
        static constexpr const char* Valor_Invalido_Nome_3 = "Maius2culo3";
        static constexpr const char* Valor_Invalido_Nome_4 = "\0";
        static constexpr const char* Valor_Invalido_Nome_5 = "Excedenteeeeeeeeeeeeeeee"; // acredito que realizar esse teste seja válido.


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

/*---------------------------------------------------------------------------*/

class TSobrenome {
    private:
        Sobrenome* sobrenome;

        static constexpr const char* Valor_Valido_Sobrenome = "Maiusculo";
        static constexpr const char* Valor_Invalido_Sobrenome_1 = "minusculo";
        static constexpr const char* Valor_Invalido_Sobrenome_2 = "23numero";
        static constexpr const char* Valor_Invalido_Sobrenome_3 = "Maius2culo3";
        static constexpr const char* Valor_Invalido_Sobrenome_4 = "\0";
        static constexpr const char* Valor_Invalido_Sobrenome_5 = "Excedenteeeeeeeeeeeeeeee";

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

/*---------------------------------------------------------------------------*/

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
        const static bool SUCESSO = true; //Por que colocou como publica?
        const static bool FALHA = false;
        bool run();
};

/*---------------------------------------------------------------------------*/

class TTelefone{
    private:
        Telefone* telefone;

        static constexpr const char* Valor_Valido_Telefone = "99 9999-9999";
        static constexpr const char* Valor_Invalido_Telefone_1 = "A9 9999-9999";
        static constexpr const char* Valor_Invalido_Telefone_2 = "999999-9999";
        static constexpr const char* Valor_Invalido_Telefone_3 = "999 9999-9999";
        static constexpr const char* Valor_Invalido_Telefone_4 = "99 9999 9999";
        static constexpr const char* Valor_Invalido_Telefone_5 = "99 9999-9a9a";
        static constexpr const char* Valor_Invalido_Telefone_6 = "99 9999-99999";


        bool estado;
        void setUp();
        void tearDown();
        void casoSucesso();
        void casoFalha();

    public:
        const static bool SUCESSO = true; //Por que colocou como publica?
        const static bool FALHA = false;
        bool run();
};

/*---------------------------------------------------------------------------*/


#endif
