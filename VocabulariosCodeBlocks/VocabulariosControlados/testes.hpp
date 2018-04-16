#ifndef __TESTES__HPP__
#define __TESTES__HPP__

#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>

#include "dominiosClasses.hpp"
#include "entidadesClasses.hpp"


using namespace std;

/**
 * @file testes.hpp
 * @author Henrique Mendes de Freitas Mariano
 * @author Gabriel Alves Castro
 * @date 12 de abril de 2018
 *
 * @brief Descricao acerca das classes de teste, referindo-se a seus atributos e funcionalidades.
 *
 * As classes de teste sao um nivel a parte de abstracao abordado nesse projeto.
 * Referem-se a relacao entre o momento de execucao do programa e a sua resposta, objetivando testar se as outras abstracoes
 * funcionam de acordo com o esperado de acordo com o objetivo de sistema.
 */

/*---------------------------------------------------------------------------*/

/**
 * @brief classe abstrata com o intuito de testar o funcionamento da classe Nome.
 *
 * Possui um objeto da classe Nome para realizacao do teste de unidade.
 *
 * Possui os seguintes atributos de validacao:
 * Um string de Nome valido.
 * Cinco strings de Nome invalidos, de acordo com os testes de validade considerados necessarios.
 *
 * A classe retorna se a classe Nome funcionou como o esperado:
 * Se retornou um erro nos casos invalidos.
 * Se armazenou o valor no caso valido.
 *
 * Caso a classe Nome nao passe em algum dos testes invalidos, eh informado em qual dos testes a mesma nao passou.
 * O objetivo dessa classe se restringe ao auxilio aos desenvolvedores, ou aos utilitarios dessa biblioteca que desejam
 * testar se a biblioteca continua em pleno funcionamento em sua respectiva aplicacao.
 *
 * Nao deixa rastros na memoria referentes a classe Nome.
 */

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
        bool notifica;
        void setUp();
        void tearDown();
        void casoSucesso();
        void casoFalha(string);

    public:
    /**
     * @brief Define o valor "SUCESSO".
     *
     * O valor eh utilizado na logica da classe. Todo teste esta em estado de SUCESSO ate que ocorra uma FALHA.
     *
     */
        const static bool SUCESSO = true;
    /**
     * @brief Define o valor "FALHA".
     *
     * O valor eh utilizado na logica da classe. Indica que a classe Nome falhou em algum dos testes realizados.
     *
     */
        const static bool FALHA = false;
    /**
     * @brief Metodo que chama todo o processo de teste da classe TNome.
     *
     * Nao possui parametro.
     * Os atributos de validacao sao os explicitados nas informacoes referentes a classe Nome.
     * Simula o funcionamento da classe Nome.
     * Retorna um booleano que indica SUCESSO ou FALHA.
     *
     */
        bool run();
};

/*---------------------------------------------------------------------------*/

/**
 * @brief classe abstrata com o intuito de testar o funcionamento da classe Sobrenome.
 *
 * Possui um objeto da classe Sobrenome para realizacao do teste de unidade.
 *
 * Possui os seguintes atributos de validacao:
 * Um string de Sobrenome valido.
 * Cinco strings de Sobrenome invalidos, de acordo com os testes de validade considerados necessarios.
 *
 * A classe retorna se a classe Sobrenome funcionou como o esperado:
 * Se retornou um erro nos casos invalidos.
 * Se armazenou o valor no caso valido.
 *
 * Caso a classe Sobrenome nao passe em algum dos testes invalidos, eh informado em qual dos testes a mesma nao passou.
 * O objetivo dessa classe se restringe ao auxilio aos desenvolvedores, ou aos utilitarios dessa biblioteca que desejam
 * testar se a biblioteca continua em pleno funcionamento em sua respectiva aplicacao.
 *
 * Nao deixa rastros na memoria referentes a classe Sobrenome.
 */

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
        bool notifica;
        void setUp();
        void tearDown();
        void casoSucesso();
        void casoFalha(string);

    public:
     /**
     * @brief Define o valor "SUCESSO".
     *
     * O valor eh utilizado na logica da classe. Todo teste esta em estado de SUCESSO ate que ocorra uma FALHA.
     *
     */
        const static bool SUCESSO = true;
    /**
     * @brief Define o valor "FALHA".
     *
     * O valor eh utilizado na logica da classe. Indica que a classe Nome falhou em algum dos testes realizados.
     *
     */
        const static bool FALHA = false;
    /**
     * @brief Metodo que chama todo o processo de teste da classe TSobrenome.
     *
     * Nao possui parametro.
     * Os atributos de validacao sao os explicitados nas informacoes referentes a classe Sobrenome.
     * Simula o funcionamento da classe Sobrenome.
     * Retorna um booleano que indica SUCESSO ou FALHA.
     *
     */
        bool run();
};

/*---------------------------------------------------------------------------*/

/**
 * @brief classe abstrata com o intuito de testar o funcionamento da classe Telefone.
 *
 * Possui um objeto da classe Telefone para realizacao do teste de unidade.
 *
 * Possui os seguintes atributos de validacao:
 * Um string de Telefone valido.
 * Seis strings de Telefone invalidos, de acordo com os testes de validade considerados necessarios.
 *
 * A classe retorna se a classe Telefone funcionou como o esperado:
 * Se retornou um erro nos casos invalidos.
 * Se armazenou o valor no caso valido.
 *
 * Caso a classe Telefone nao passe em algum dos testes invalidos, eh informado em qual dos testes a mesma nao passou.
 * O objetivo dessa classe se restringe ao auxilio aos desenvolvedores, ou aos utilitarios dessa biblioteca que desejam
 * testar se a biblioteca continua em pleno funcionamento em sua respectiva aplicacao.
 *
 * Nao deixa rastros na memoria referentes a classe Telefone.
 */

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
        bool notifica;
        void setUp();
        void tearDown();
        void casoSucesso();
        void casoFalha(string);

    public:
    /**
     * @brief Define o valor "SUCESSO".
     *
     * O valor eh utilizado na logica da classe. Todo teste esta em estado de SUCESSO ate que ocorra uma FALHA.
     *
     */
        const static bool SUCESSO = true;
    /**
     * @brief Define o valor "FALHA".
     *
     * O valor eh utilizado na logica da classe. Indica que a classe Nome falhou em algum dos testes realizados.
     *
     */
        const static bool FALHA = false;
    /**
     * @brief Metodo que chama todo o processo de teste da classe TTelefone.
     *
     * Nao possui parametro.
     * Os atributos de validacao sao os explicitados nas informacoes referentes a classe Telefone.
     * Simula o funcionamento da classe Telefone.
     * Retorna um booleano que indica SUCESSO ou FALHA.
     *
     */
        bool run();
};

/*---------------------------------------------------------------------------*/

/**
 * @brief classe abstrata com o intuito de testar o funcionamento da classe Endereco.
 *
 * Possui um objeto da classe Endereco para realizacao do teste de unidade.
 *
 * Possui os seguintes atributos de validacao:
 * Um string de Endereco valido.
 * Seis strings de Endereco invalidos, de acordo com os testes de validade considerados necessarios.
 *
 * A classe retorna se a classe Endereco funcionou como o esperado:
 * Se retornou um erro nos casos invalidos.
 * Se armazenou o valor no caso valido.
 *
 * Caso a classe Endereco nao passe em algum dos testes invalidos, eh informado em qual dos testes a mesma nao passou.
 * O objetivo dessa classe se restringe ao auxilio aos desenvolvedores, ou aos utilitarios dessa biblioteca que desejam
 * testar se a biblioteca continua em pleno funcionamento em sua respectiva aplicacao.
 *
 * Nao deixa rastros na memoria referentes a classe Endereco.
 */

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
        bool notifica;
        void setUp();
        void tearDown();
        void casoSucesso();
        void casoFalha(string);

    public:
    /**
     * @brief Define o valor "SUCESSO".
     *
     * O valor eh utilizado na logica da classe. Todo teste esta em estado de SUCESSO ate que ocorra uma FALHA.
     *
     */
        const static bool SUCESSO = true;
    /**
     * @brief Define o valor "FALHA".
     *
     * O valor eh utilizado na logica da classe. Indica que a classe Nome falhou em algum dos testes realizados.
     *
     */
        const static bool FALHA = false;
    /**
     * @brief Metodo que chama todo o processo de teste da classe TEndereco.
     *
     * Nao possui parametro.
     * Os atributos de validacao sao os explicitados nas informacoes referentes a classe Endereco.
     * Simula o funcionamento da classe Endereco.
     * Retorna um booleano que indica SUCESSO ou FALHA.
     *
     */
        bool run();
};

    // URGENTE:
    // A declaração abaixo não está dando certo, provavelmente declarei algo errado, concertar depois.
    //const char Valor_Valido_Endereco[] = "endereco qualquer";
    //const char Valor_Invalido_Endereco_1[] = " teste";
    //const char Valor_Invalido_Endereco_2[] = " testesestes ";
    //const char Valor_Invalido_Endereco_3[] = "testes  estes";
    //const char Valor_Invalido_Endereco_4[] = "testes estes ";
    //const char Valor_Invalido_Endereco_5[] = "testes es  tes";
    //const char Valor_Invalido_Endereco_6[] = "Excedenteeeeeeeeeeeeeeee";

/*---------------------------------------------------------------------------*/

/**
 * @brief classe abstrata com o intuito de testar o funcionamento da classe Data.
 *
 * Possui um objeto da classe Data para realizacao do teste de unidade.
 *
 * Possui os seguintes atributos de validacao:
 * Um string de Data valido.
 * Um string de Data invalido, de acordo com os testes de validade considerados necessarios.
 *
 * A classe retorna se a classe Data funcionou como o esperado:
 * Se retornou um erro no caso invalido.
 * Se armazenou o valor no caso valido.
 *
 * O objetivo dessa classe se restringe ao auxilio aos desenvolvedores, ou aos utilitarios dessa biblioteca que desejam
 * testar se a biblioteca continua em pleno funcionamento em sua respectiva aplicacao.
 *
 * Nao deixa rastros na memoria referentes a classe Data.
 */


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
    /**
     * @brief Define o valor "SUCESSO".
     *
     * O valor eh utilizado na logica da classe. Todo teste esta em estado de SUCESSO ate que ocorra uma FALHA.
     *
     */
        const static bool SUCESSO = true;
    /**
     * @brief Define o valor "FALHA".
     *
     * O valor eh utilizado na logica da classe. Indica que a classe Nome falhou em algum dos testes realizados.
     *
     */
        const static bool FALHA = false;
    /**
     * @brief Metodo que chama todo o processo de teste da classe TData.
     *
     * Nao possui parametro.
     * Os atributos de validacao sao os explicitados nas informacoes referentes a classe Data.
     * Simula o funcionamento da classe Data.
     * Retorna um booleano que indica SUCESSO ou FALHA.
     *
     */
        bool run();
};


/*---------------------------------------------------------------------------*/

/**
 * @brief classe abstrata com o intuito de testar o funcionamento da classe Correio_Eletronico.
 *
 * Possui um objeto da classe Correio_Eletronico para realizacao do teste de unidade.
 *
 * Possui os seguintes atributos de validacao:
 * Um string de Correio_Eletronico valido.
 * Seis strings de Correio_Eletronico invalidos, de acordo com os testes de validade considerados necessarios.
 *
 * A classe retorna se a classe Correio_Eletronico funcionou como o esperado:
 * Se retornou um erro nos casos invalidos.
 * Se armazenou o valor no caso valido.
 *
 * Caso a classe Correio_Eletronico nao passe em algum dos testes invalidos, eh informado em qual dos testes a mesma nao passou.
 * O objetivo dessa classe se restringe ao auxilio aos desenvolvedores, ou aos utilitarios dessa biblioteca que desejam
 * testar se a biblioteca continua em pleno funcionamento em sua respectiva aplicacao.
 *
 * Nao deixa rastros na memoria referentes a classe Correio_Eletronico.
 */

class TCorreio_Eletronico{
    private:
        Correio_Eletronico* correio_eletronico;

        static constexpr const char* Valor_Valido_Correio_Eletronico = "eaemen@hotmail.com";
        static constexpr const char* Valor_Invalido_Correio_Eletronico_1 = ".eaemen@hotmail.com";
        static constexpr const char* Valor_Invalido_Correio_Eletronico_2 = "eaemen@@hotmail.com";
        static constexpr const char* Valor_Invalido_Correio_Eletronico_3 = "lel@gmail.com.";
        static constexpr const char* Valor_Invalido_Correio_Eletronico_4 = "eaemeubacana@25655.com";
        static constexpr const char* Valor_Invalido_Correio_Eletronico_5 = "ewewwewe";
        static constexpr const char* Valor_Invalido_Correio_Eletronico_6 = "eaemeuguerreiro@yahoo.com.";

        bool estado;
        bool notifica;
        void setUp();
        void tearDown();
        void casoSucesso();
        void casoFalha(string);

    public:
    /**
     * @brief Define o valor "SUCESSO".
     *
     * O valor eh utilizado na logica da classe. Todo teste esta em estado de SUCESSO ate que ocorra uma FALHA.
     *
     */
        const static bool SUCESSO = true;
    /**
     * @brief Define o valor "FALHA".
     *
     * O valor eh utilizado na logica da classe. Indica que a classe Nome falhou em algum dos testes realizados.
     *
     */
        const static bool FALHA = false;
    /**
     * @brief Metodo que chama todo o processo de teste da classe TCorreio_Eletronico.
     *
     * Nao possui parametro.
     * Os atributos de validacao sao os explicitados nas informacoes referentes a classe Correio_Eletronico.
     * Simula o funcionamento da classe Correio_Eletronico.
     * Retorna um booleano que indica SUCESSO ou FALHA.
     *
     */
        bool run();
};
/*---------------------------------------------------------------------------*/

/**
 * @brief classe abstrata com o intuito de testar o funcionamento da classe Senha.
 *
 * Possui um objeto da classe Senha para realizacao do teste de unidade.
 *
 * Possui os seguintes atributos de validacao:
 * Um string de Senha valido.
 * Tres strings de Senha invalidos, de acordo com os testes de validade considerados necessarios.
 *
 * A classe retorna se a classe Senha funcionou como o esperado:
 * Se retornou um erro nos casos invalidos.
 * Se armazenou o valor no caso valido.
 *
 * Caso a classe Senha nao passe em algum dos testes invalidos, eh informado em qual dos testes a mesma nao passou.
 * O objetivo dessa classe se restringe ao auxilio aos desenvolvedores, ou aos utilitarios dessa biblioteca que desejam
 * testar se a biblioteca continua em pleno funcionamento em sua respectiva aplicacao.
 *
 * Nao deixa rastros na memoria referentes a classe Senha.
 */

class TSenha{
    private:
        Senha* senha;

        static constexpr const char* Valor_Valido_Senha = "EaeM3ule";
        static constexpr const char* Valor_Invalido_Senha_1 = "minuscul";
        static constexpr const char* Valor_Invalido_Senha_2 = "E1cedenteeeeeeee";
        static constexpr const char* Valor_Invalido_Senha_3 = "xd3E.d";

        bool estado;
        bool notifica;
        void setUp();
        void tearDown();
        void casoSucesso();
        void casoFalha(string);

    public:
    /**
     * @brief Define o valor "SUCESSO".
     *
     * O valor eh utilizado na logica da classe. Todo teste esta em estado de SUCESSO ate que ocorra uma FALHA.
     *
     */
        const static bool SUCESSO = true;
    /**
     * @brief Define o valor "FALHA".
     *
     * O valor eh utilizado na logica da classe. Indica que a classe Nome falhou em algum dos testes realizados.
     *
     */
        const static bool FALHA = false;
    /**
     * @brief Metodo que chama todo o processo de teste da classe TSenha.
     *
     * Nao possui parametro.
     * Os atributos de validacao sao os explicitados nas informacoes referentes a classe Senha.
     * Simula o funcionamento da classe Correio_Eletronico.
     * Retorna um booleano que indica SUCESSO ou FALHA.
     *
     */
        bool run();

};

/*---------------------------------------------------------------------------*/

/**
 * @brief classe abstrata com o intuito de testar o funcionamento da classe Texto_Definicao.
 *
 * Possui um objeto da classe Texto_Definicao para realizacao do teste de unidade.
 *
 * Possui os seguintes atributos de validacao:
 * Um string de Texto_Definicao valido.
 * Um string de Texto_Definicao invalido, de acordo com os testes de validade considerados necessarios.
 *
 * A classe retorna se a classe Texto_Definicao funcionou como o esperado:
 * Se retornou um erro no caso invalido.
 * Se armazenou o valor no caso valido.
 *
 * O objetivo dessa classe se restringe ao auxilio aos desenvolvedores, ou aos utilitarios dessa biblioteca que desejam
 * testar se a biblioteca continua em pleno funcionamento em sua respectiva aplicacao.
 *
 * Nao deixa rastros na memoria referentes a classe Texto_Definicao.
 */

class TTexto_Definicao{
    private:
        Texto_Definicao* texto_definicao;

        static constexpr const char* Valor_Valido_Texto_Definicao = "teste valido texto";
        static constexpr const char* Valor_Invalido_Texto_Definicao = "excedenteeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee";

        bool estado;
        void setUp();
        void tearDown();
        void casoSucesso();
        void casoFalha();

    public:
    /**
     * @brief Define o valor "SUCESSO".
     *
     * O valor eh utilizado na logica da classe. Todo teste esta em estado de SUCESSO ate que ocorra uma FALHA.
     *
     */
        const static bool SUCESSO = true;
    /**
     * @brief Define o valor "FALHA".
     *
     * O valor eh utilizado na logica da classe. Indica que a classe Nome falhou em algum dos testes realizados.
     *
     */
        const static bool FALHA = false;
    /**
     * @brief Metodo que chama todo o processo de teste da classe TTexto_Definicao.
     *
     * Nao possui parametro.
     * Os atributos de validacao sao os explicitados nas informacoes referentes a classe Texto_Definicao.
     * Simula o funcionamento da classe Texto_Definicao.
     * Retorna um booleano que indica SUCESSO ou FALHA.
     *
     */
        bool run();
};

/*---------------------------------------------------------------------------*/

/**
 * @brief classe abstrata com o intuito de testar o funcionamento da classe Idioma.
 *
 * Possui um objeto da classe Idioma para realizacao do teste de unidade.
 *
 * Possui os seguintes atributos de validacao:
 * Um string de Idioma valido.
 * Um string de Idioma invalido, de acordo com os testes de validade considerados necessarios.
 *
 * A classe retorna se a classe Idioma funcionou como o esperado:
 * Se retornou um erro no caso invalido.
 * Se armazenou o valor no caso valido.
 *
 * O objetivo dessa classe se restringe ao auxilio aos desenvolvedores, ou aos utilitarios dessa biblioteca que desejam
 * testar se a biblioteca continua em pleno funcionamento em sua respectiva aplicacao.
 *
 * Nao deixa rastros na memoria referentes a classe Idioma.
 */

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
    /**
     * @brief Define o valor "SUCESSO".
     *
     * O valor eh utilizado na logica da classe. Todo teste esta em estado de SUCESSO ate que ocorra uma FALHA.
     *
     */
        const static bool SUCESSO = true;
    /**
     * @brief Define o valor "FALHA".
     *
     * O valor eh utilizado na logica da classe. Indica que a classe Nome falhou em algum dos testes realizados.
     *
     */
        const static bool FALHA = false;
    /**
     * @brief Metodo que chama todo o processo de teste da classe TIdioma.
     *
     * Nao possui parametro.
     * Os atributos de validacao sao os explicitados nas informacoes referentes a classe Idioma.
     * Simula o funcionamento da classe Idioma.
     * Retorna um booleano que indica SUCESSO ou FALHA.
     *
     */
        bool run();
};

/*---------------------------------------------------------------------------*/

/**
 * @brief classe abstrata com o intuito de testar o funcionamento da classe Classe_Termo.
 *
 * Possui um objeto da classe Classe_Termo para realizacao do teste de unidade.
 *
 * Possui os seguintes atributos de validacao:
 * Um string de Classe_Termo valido.
 * Um string de Classe_Termo invalido, de acordo com os testes de validade considerados necessarios.
 *
 * A classe retorna se a classe Classe_Termo funcionou como o esperado:
 * Se retornou um erro no caso invalido.
 * Se armazenou o valor no caso valido.
 *
 * O objetivo dessa classe se restringe ao auxilio aos desenvolvedores, ou aos utilitarios dessa biblioteca que desejam
 * testar se a biblioteca continua em pleno funcionamento em sua respectiva aplicacao.
 *
 * Nao deixa rastros na memoria referentes a classe Classe_Termo.
 */

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
    /**
     * @brief Define o valor "SUCESSO".
     *
     * O valor eh utilizado na logica da classe. Todo teste esta em estado de SUCESSO ate que ocorra uma FALHA.
     *
     */
        const static bool SUCESSO = true;
    /**
     * @brief Define o valor "FALHA".
     *
     * O valor eh utilizado na logica da classe. Indica que a classe Nome falhou em algum dos testes realizados.
     *
     */
        const static bool FALHA = false;
    /**
     * @brief Metodo que chama todo o processo de teste da classe TClasse_Termo.
     *
     * Nao possui parametro.
     * Os atributos de validacao sao os explicitados nas informacoes referentes a classe Classe_Termo.
     * Simula o funcionamento da classe Classe_Termo.
     * Retorna um booleano que indica SUCESSO ou FALHA.
     *
     */
        bool run();
};

/*-------------------------------------Entidades--------------------------------------*/

/*---------------------------------------------------------------------------*/

/**
 * @brief classe abstrata com o intuito de testar o funcionamento da classe Leitor.
 *
 * Possui um objeto da classe Leitor para realizacao do teste de unidade.
 *
 * Possui os seguintes atributos de validacao:
 * Um objeto da classe Nome.
 * Um objeto da classe Sobrenome.
 * Um objeto da classe Correio_Eletronico.
 * Um obheto da classe Senha.
 *
 * Um string valido da classe Nome.
 * Um string valido da classe Sobrenome.
 * Um string valido da classe Correio_Eletronico.
 * Um string valido da classe Senha.
 *
 * A classe retorna se a classe Leitor funcionou como o esperado:
 * Se armazenou os valores esperados.
 *
 * O objetivo dessa classe se restringe ao auxilio aos desenvolvedores, ou aos utilitarios dessa biblioteca que desejam
 * testar se a biblioteca continua em pleno funcionamento em sua respectiva aplicacao.
 *
 * Nao deixa rastros na memoria referentes as classe Leitor, Nome, Sobrenome, Correio_Eletronico e Senha.
 */

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
    /**
     * @brief Define o valor "SUCESSO".
     *
     * O valor eh utilizado na logica da classe. Todo teste esta em estado de SUCESSO ate que ocorra uma FALHA.
     *
     */
        const static bool SUCESSO = true;
    /**
     * @brief Define o valor "FALHA".
     *
     * O valor eh utilizado na logica da classe. Indica que a classe Nome falhou em algum dos testes realizados.
     *
     */
        const static bool FALHA = false;
    /**
     * @brief Metodo que chama todo o processo de teste da classe TLeitor.
     *
     * Nao possui parametro.
     * Simula o funcionamento da classe Leitor.
     * Retorna um booleano que indica SUCESSO ou FALHA.
     *
     */
        bool run();

};

/*---------------------------------------------------------------------------*/

/**
 * @brief classe abstrata com o intuito de testar o funcionamento da classe Desenvolvedor.
 *
 * Possui um objeto da classe Desenvolvedor para realizacao do teste de unidade.
 *
 * Possui os seguintes atributos de validacao:
 * Um objeto da classe Nome.
 * Um objeto da classe Sobrenome.
 * Um objeto da classe Data.
 * Um objeto da classe Correio_Eletronico.
 * Um obheto da classe Senha.
 *
 * Um string valido da classe Nome.
 * Um string valido da classe Sobrenome.
 * Um string valido da classe Data.
 * Um string valido da classe Correio_Eletronico.
 * Um string valido da classe Senha.
 *
 * A classe retorna se a classe Desenvolvedor funcionou como o esperado:
 * Se armazenou os valores esperados.
 *
 * O objetivo dessa classe se restringe ao auxilio aos desenvolvedores, ou aos utilitarios dessa biblioteca que desejam
 * testar se a biblioteca continua em pleno funcionamento em sua respectiva aplicacao.
 *
 * Nao deixa rastros na memoria referentes as classe Leitor, Nome, Sobrenome, Data, Correio_Eletronico e Senha.
 */


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
    /**
     * @brief Define o valor "SUCESSO".
     *
     * O valor eh utilizado na logica da classe. Todo teste esta em estado de SUCESSO ate que ocorra uma FALHA.
     *
     */
        const static bool SUCESSO = true;
    /**
     * @brief Define o valor "FALHA".
     *
     * O valor eh utilizado na logica da classe. Indica que a classe Nome falhou em algum dos testes realizados.
     *
     */
        const static bool FALHA = false;
    /**
     * @brief Metodo que chama todo o processo de teste da classe TDesenvolvedor.
     *
     * Nao possui parametro.
     * Simula o funcionamento da classe Desenvolvedor.
     * Retorna um booleano que indica SUCESSO ou FALHA.
     *
     */
        bool run();
};

/*---------------------------------------------------------------------------*/

/**
 * @brief classe abstrata com o intuito de testar o funcionamento da classe Administrador.
 *
 * Possui um objeto da classe Administrador para realizacao do teste de unidade.
 *
 * Possui os seguintes atributos de validacao:
 * Um objeto da classe Nome.
 * Um objeto da classe Sobrenome.
 * Um objeto da classe Data.
 * Um objeto da classe Endereco.
 * Um objeto da classe Correio_Eletronico.
 * Um obheto da classe Senha.
 *
 * Um string valido da classe Nome.
 * Um string valido da classe Sobrenome.
 * Um string valido da classe Data.
 * Um string valido da classe Endereco.
 * Um string valido da classe Correio_Eletronico.
 * Um string valido da classe Senha.
 *
 * A classe retorna se a classe Administrador funcionou como o esperado:
 * Se armazenou os valores esperados.
 *
 * O objetivo dessa classe se restringe ao auxilio aos desenvolvedores, ou aos utilitarios dessa biblioteca que desejam
 * testar se a biblioteca continua em pleno funcionamento em sua respectiva aplicacao.
 *
 * Nao deixa rastros na memoria referentes as classe Leitor, Nome, Sobrenome, Data, Endereco, Correio_Eletronico e Senha.
 */

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
        static constexpr const char* Valor_Endereco = "Aldeiadafolha";
        static constexpr const char* Valor_Correio_Eletronico = "boruto@gmail.com";
        static constexpr const char* Valor_Senha = "Tocerto1";

        bool estado;
        void setUp();
        void tearDown();
        void casoSucesso();

    public:
    /**
     * @brief Define o valor "SUCESSO".
     *
     * O valor eh utilizado na logica da classe. Todo teste esta em estado de SUCESSO ate que ocorra uma FALHA.
     *
     */
        const static bool SUCESSO = true;
    /**
     * @brief Define o valor "FALHA".
     *
     * O valor eh utilizado na logica da classe. Indica que a classe Nome falhou em algum dos testes realizados.
     *
     */
        const static bool FALHA = false;
    /**
     * @brief Metodo que chama todo o processo de teste da classe TAdministrador.
     *
     * Nao possui parametro.
     * Simula o funcionamento da classe Administrador.
     * Retorna um booleano que indica SUCESSO ou FALHA.
     *
     */
        bool run();
    };

/*---------------------------------------------------------------------------*/

/**
 * @brief classe abstrata com o intuito de testar o funcionamento da classe VocControlado.
 *
 * Possui um objeto da classe VocControlado para realizacao do teste de unidade.
 *
 * Possui os seguintes atributos de validacao:
 * Um objeto da classe Nome.
 * Um objeto da classe Idioma.
 * Um objeto da classe Data.
 *
 * Um string valido da classe Nome.
 * Um string valido da classe Sobrenome.
 * Um string valido da classe Data.
 *
 * A classe retorna se a classe VocControlado funcionou como o esperado:
 * Se armazenou os valores esperados.
 *
 * O objetivo dessa classe se restringe ao auxilio aos desenvolvedores, ou aos utilitarios dessa biblioteca que desejam
 * testar se a biblioteca continua em pleno funcionamento em sua respectiva aplicacao.
 *
 * Nao deixa rastros na memoria referentes as classe Nome, Idioma e Data.
 */

class TVocControlado{
    private:
        VocControlado* voccontrolado;
        Nome nome;
        Idioma idioma;
        Data data;

        static constexpr const char* Valor_Nome = "Boruto";
        static constexpr const char* Valor_Idioma = "ENG";
        static constexpr const char* Valor_Data = "15/04/2018";

        bool estado;
        void setUp();
        void tearDown();
        void casoSucesso();

    public:
    /**
     * @brief Define o valor "SUCESSO".
     *
     * O valor eh utilizado na logica da classe. Todo teste esta em estado de SUCESSO ate que ocorra uma FALHA.
     *
     */
        const static bool SUCESSO = true;
    /**
     * @brief Define o valor "FALHA".
     *
     * O valor eh utilizado na logica da classe. Indica que a classe Nome falhou em algum dos testes realizados.
     *
     */
        const static bool FALHA = false;
    /**
     * @brief Metodo que chama todo o processo de teste da classe TVocControlocado.
     *
     * Nao possui parametro.
     * Simula o funcionamento da classe VocControlado.
     * Retorna um booleano que indica SUCESSO ou FALHA.
     *
     */
        bool run();

};

/*---------------------------------------------------------------------------*/

/**
 * @brief classe abstrata com o intuito de testar o funcionamento da classe Termo.
 *
 * Possui um objeto da classe Termo para realizacao do teste de unidade.
 *
 * Possui os seguintes atributos de validacao:
 * Um objeto da classe Nome.
 * Um objeto da classe Classe_Termo.
 * Um objeto da classe Data.
 *
 * Um string valido da classe Nome.
 * Um string valido da classe Classe_Termo.
 * Um string valido da classe Data.
 *
 * A classe retorna se a classe Termo funcionou como o esperado:
 * Se armazenou os valores esperados.
 *
 * O objetivo dessa classe se restringe ao auxilio aos desenvolvedores, ou aos utilitarios dessa biblioteca que desejam
 * testar se a biblioteca continua em pleno funcionamento em sua respectiva aplicacao.
 *
 * Nao deixa rastros na memoria referentes as classe Nome, Classe_Termo e Data.
 */

class TTermo{
    private:
        Termo* termo;
        Nome nome;
        Classe_Termo classe_termo;
        Data data;

        static constexpr const char* Valor_Nome = "Boruto";
        static constexpr const char* Valor_Classe_Termo = "PT";
        static constexpr const char* Valor_Data = "15/04/2018";

        bool estado;
        void setUp();
        void tearDown();
        void casoSucesso();

    public:
    /**
     * @brief Define o valor "SUCESSO".
     *
     * O valor eh utilizado na logica da classe. Todo teste esta em estado de SUCESSO ate que ocorra uma FALHA.
     *
     */
        const static bool SUCESSO = true;
    /**
     * @brief Define o valor "FALHA".
     *
     * O valor eh utilizado na logica da classe. Indica que a classe Nome falhou em algum dos testes realizados.
     *
     */
        const static bool FALHA = false;
    /**
     * @brief Metodo que chama todo o processo de teste da classe TTermo.
     *
     * Nao possui parametro.
     * Simula o funcionamento da classe Termo.
     * Retorna um booleano que indica SUCESSO ou FALHA.
     *
     */
        bool run();

};

/*---------------------------------------------------------------------------*/

/**
 * @brief classe abstrata com o intuito de testar o funcionamento da classe Definicao.
 *
 * Possui um objeto da classe Definicao para realizacao do teste de unidade.
 *
 * Possui os seguintes atributos de validacao:
 * Um objeto da classe Texto_Definicao.
 * Um objeto da classe Data.
 *
 * Um string valido da classe Texto_Definicao.
 * Um string valido da classe Data.
 *
 * A classe retorna se a classe Definicao funcionou como o esperado:
 * Se armazenou os valores esperados.
 *
 * O objetivo dessa classe se restringe ao auxilio aos desenvolvedores, ou aos utilitarios dessa biblioteca que desejam
 * testar se a biblioteca continua em pleno funcionamento em sua respectiva aplicacao.
 *
 * Nao deixa rastros na memoria referentes as classe Texto_Definicao e Data.
 */

class TDefinicao{
    private:
        Definicao* definicao;
        Texto_Definicao texto_definicao;
        Data data;

        static constexpr const char* Valor_Texto_Definicao = "Eaemeuchapa";
        static constexpr const char* Valor_Data = "15/04/2018";

        bool estado;
        void setUp();
        void tearDown();
        void casoSucesso();

    public:
    /**
     * @brief Define o valor "SUCESSO".
     *
     * O valor eh utilizado na logica da classe. Todo teste esta em estado de SUCESSO ate que ocorra uma FALHA.
     *
     */
        const static bool SUCESSO = true;
    /**
     * @brief Define o valor "FALHA".
     *
     * O valor eh utilizado na logica da classe. Indica que a classe Nome falhou em algum dos testes realizados.
     *
     */
        const static bool FALHA = false;
    /**
     * @brief Metodo que chama todo o processo de teste da classe TDefinicao.
     *
     * Nao possui parametro.
     * Simula o funcionamento da classe Definicao.
     * Retorna um booleano que indica SUCESSO ou FALHA.
     *
     */
        bool run();
};
#endif
