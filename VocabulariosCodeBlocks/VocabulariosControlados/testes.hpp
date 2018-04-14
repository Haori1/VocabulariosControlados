#ifndef __TESTES__HPP__
#define __TESTES__HPP__

#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>

#include "dominiosClasses.hpp"
#include "entidadesClasses.hpp"


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
        static constexpr const char* Valor_Invalido_Nome_5 = "Excedenteeeeeeeeeeeeeeee"; // acredito que realizar esse teste seja v�lido.


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

class TTelefone{
    private:
        Telefone* telefone;

        static constexpr const char* Valor_Valido_Telefone = "99 99999-9999";
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
        const static bool SUCESSO = true;
        const static bool FALHA = false;
        bool run();
};

/*---------------------------------------------------------------------------*/

class TEndereco{

    private:
        Endereco* endereco;

        static constexpr const char* Valor_Valido_Endereco = "endereco qualquer";
        static constexpr const char* Valor_Invalido_Endereco_1 = " teste";
        static constexpr const char* Valor_Invalido_Endereco_2 = " testesestes ";
        static constexpr const char* Valor_Invalido_Endereco_3 = "testes  estes";
        static constexpr const char* Valor_Invalido_Endereco_4 = "testes estes ";
        static constexpr const char* Valor_Invalido_Endereco_5 = "testes es  tes";
        static constexpr const char* Valor_Invalido_Endereco_6 = "Excedenteeeeeeeeeeeeeeee";

        bool estado;
        void setUp();
        void tearDown();
        void casoSucesso();
        void casoFalha(string);

    public:
        const static bool SUCESSO = true;
        const static bool FALHA = false;
        bool run();
};

    // A declaração abaixo não está dando certo, provavelmente declarei algo errado, concertar depois.
    //const char Valor_Valido_Endereco[] = "endereco qualquer";
    //const char Valor_Invalido_Endereco_1[] = " teste";
    //const char Valor_Invalido_Endereco_2[] = " testesestes ";
    //const char Valor_Invalido_Endereco_3[] = "testes  estes";
    //const char Valor_Invalido_Endereco_4[] = "testes estes ";
    //const char Valor_Invalido_Endereco_5[] = "testes es  tes";
    //const char Valor_Invalido_Endereco_6[] = "Excedenteeeeeeeeeeeeeeee";

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
        const static bool SUCESSO = true; //Por que colocou como publica? sla ta assim no codigo do chacon
        const static bool FALHA = false;
        bool run();
};


/*---------------------------------------------------------------------------*/

class TCorreio_Eletronico{
    private:
        Correio_Eletronico* correio_eletronico;

        static constexpr const char* Valor_Valido_Correio_Eletronico = "eaemen@hotmail.com";
        static constexpr const char* Valor_Invalido_Correio_Eletronico_1 = ".eaemen@hotmail.com";
        static constexpr const char* Valor_Invalido_Correio_Eletronico_2 = "eaemen@@hotmail.com";
        static constexpr const char* Valor_Invalido_Correio_Eletronico_3 = "lel@gmail.com.";
        static constexpr const char* Valor_Invalido_Correio_Eletronico_4 = "eaemeubacana@25655.com";
        static constexpr const char* Valor_Invalido_Correio_Eletronico_5 = "ewewwewe";
        static constexpr const char* Valor_Invalido_Correio_Eletronico_6 = "eaemeuguerreiro@yahoo.com."; /*A validação desse caso de teste não é feita, porém de acordo com as especificações é valido, como proceder?*/

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

class TSenha{
    private:
        Senha* senha;

        static constexpr const char* Valor_Valido_Senha = "EaeM3ule";
        static constexpr const char* Valor_Invalido_Senha_1 = "kkeaemen";
        static constexpr const char* Valor_Invalido_Senha_2 = "kkkkkkkkkkkkkkkkk";
        static constexpr const char* Valor_Invalido_Senha_3 = "xd3E.d";

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

class TTexto_Definicao{
    private:
        Texto_Definicao* texto_definicao;

        static constexpr const char* Valor_Valido_Texto_Definicao = "eaemeuguerreirotudonapaz?";
        static constexpr const char* Valor_Invalido_Texto_Definicao = "tranquilidadeaimeuparcerinsuavao?";

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

class TIdioma{
    private:
        Idioma* idioma;

        static constexpr const char* Valor_Valido_Idioma = "POR";
        static constexpr const char* Valor_Invalido_Idioma = "JAP";

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

class TClasse_Termo{
    private:
        Classe_Termo* classe_termo;

        static constexpr const char* Valor_Valido_Classe_Termo = "PT";
        static constexpr const char* Valor_Invalido_Classe_Termo = "XD";

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

/*-------------------------------------Entidades--------------------------------------*/

/*---------------------------------------------------------------------------*/

class TLeitor{
    private:
        Leitor* leitor;
        Nome nome;
        Sobrenome sobrenome;
        Correio_Eletronico correio_eletronico;
        Senha senha;

        static constexpr const char* Valor_Nome = "Boruto";
        static constexpr const char* Valor_Sobrenome = "Uzumaki";
        static constexpr const char* Valor_Correio_Eletronico = "boruto@gmail.com";
        static constexpr const char* Valor_Senha = "Tocerto1";

        bool estado;
        void setUp();
        void tearDown();
        void casoSucesso();

    public:
        const static bool SUCESSO = true;
        const static bool FALHA = false;
        bool run();

};

/*---------------------------------------------------------------------------*/

class TDesenvolvedor{
    private:
        Desenvolvedor* desenvolvedor;
        Nome nome;
        Sobrenome sobrenome;
        Data data_nascimento;
        Correio_Eletronico correio_eletronico;
        Senha senha;

        static constexpr const char* Valor_Nome = "Boruto";
        static constexpr const char* Valor_Sobrenome = "Uzumaki";
        static constexpr const char* Valor_Data_Nascimento = "11/03/1999";
        static constexpr const char* Valor_Correio_Eletronico = "boruto@gmail.com";
        static constexpr const char* Valor_Senha = "Tocerto1";

        bool estado;
        void setUp();
        void tearDown();
        void casoSucesso();

    public:
        const static bool SUCESSO = true;
        const static bool FALHA = false;
        bool run();
};

/*---------------------------------------------------------------------------*/

class TAdministrador{
    private:
        Administrador* administrador;
        Nome nome;
        Sobrenome sobrenome;
        Telefone telefone;
        Data data_nascimento;
        Endereco endereco;
        Correio_Eletronico correio_eletronico;
        Senha senha;

        static constexpr const char* Valor_Nome = "Boruto";
        static constexpr const char* Valor_Sobrenome = "Uzumaki";
        static constexpr const char* Valor_Telefone = "61 99999-9999";
        static constexpr const char* Valor_Data_Nascimento = "11/03/1999";
        static constexpr const char* Valor_Endereco = "Aldeia da folha";
        static constexpr const char* Valor_Correio_Eletronico = "boruto@gmail.com";
        static constexpr const char* Valor_Senha = "Tocerto1";

        bool estado;
        void setUp();
        void tearDown();
        void casoSucesso();

    public:
        const static bool SUCESSO = true;
        const static bool FALHA = false;
        bool run();
    };

/*---------------------------------------------------------------------------*/
#endif
