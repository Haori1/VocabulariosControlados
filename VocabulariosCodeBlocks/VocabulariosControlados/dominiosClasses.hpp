#ifndef ___DOMINIOS_HPP__
#define ___DOMINIOS_HPP__

#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>

using namespace std;

/**
 * @file dominiosClasses.hpp
 * @author Henrique Mendes de Freitas Mariano
 * @author Gabriel Alves Castro
 * @date 12 de abril de 2018
 *
 * @brief Descricao acerca das classes de dominio, referindo-se a seus atributos e funcionalidades.
 *
 * As classes de dominio sao o menor nivel de abstracao abordado nesse projeto.
 * Referem-se aos elementos que compoem as entidades.
 */

/**
 * @brief classe abstrata com o intuito de nomear (usuarios ou qualquer outra abstracao que possa receber um "nome").
 *
 * Possui os seguintes atributos de validacao:
 * A classe Nome recebe uma string que pode possuir no maximo 20 caracteres.
 * O primeiro caractere deve ser uma vogal ou consoante maiusculas.
 * A string so pode conter como caracteres consoantes e vogais minusculas.
 *
 * A classe possui um metodo set_nome, para receber uma string.
 * A classe possui um metodo get_nome, que apenas retorna a string contida em um eventual objeto da classe Nome.
 *
 */

class Nome{
    private:
        string nome;
        const static int TAM_MAX_NOME = 20;
        const static int STRING_VAZIA = 0;

    /**
     * @brief Valida o atributo do tipo string da classe Nome
     *
     * é responsavel por validar a string recebida pela classe Nome, de acordo com os seus atributos de validacao.
     *
     * @param string recebe a string da classe Nome, para realizar a sua validacao.
     */

        void validation (string) throw (invalid_argument);

    public:
    /**
     * @brief Recebe uma string para guardar na classe Nome, de acordo com seus atributos privados.
     *
     *  O valor é guardado somente se for validado pelo metodo de validacao.
     *  Os atributos de validacao sao os explicitados nas informacoes referentes a classe Nome.
     *
     * @param nome recebe a string da classe Nome.
     */

        void set_nome (string nome) throw (invalid_argument);
        string get_nome(){
            return nome;
        }

};

/**
 * @brief classe abstrata com o intuito de subnomear entidades que representam informacoes acerca de seres humanos no sistema.
 *
 * Possui os seguintes atributos de validacao:
 * A classe Sobrenome recebe uma string que pode possuir no m�ximo 20 caracteres.
 * O primeiro caractere deve ser uma vogal ou consoante maiusculas.
 * A string so pode conter como caracteres consoantes e vogais minusculas.
 *
 * A classe possui um metodo set_sobreome, para receber uma string.
 * A classe possui um metodo get_sobreome, que apenas retorna a string contida em um eventual objeto da classe Sobrenome.
 *
 */

class Sobrenome{
    private:
        string sobrenome;
        const static int TAM_MAX_SOBRENOME = 20;
        const static int STRING_VAZIA = 0;

    /**
     * @brief Valida o atributo do tipo string da classe Sobrenome
     *
     * eh responsavel por validar a string recebida pela classe Sobrenome, de acordo com os seus atributos de valicacao.
     *
     * @param string recebe a string da classe Sobrenome, para realizar a sua validacao.
     */

        void validation (string) throw (invalid_argument);

    public:
    /**
     * @brief Recebe uma string para guardar na classe Sobrenome, de acordo com seus atributos privados.
     *
     *  O valor eh guardado somente se for validado pelo metodo de validacao.
     *  Os atributos de validacao sao os explicitados nas informacoes referentes a classe Sobrenome.
     *
     * @param sobrenome recebe a string da classe Sobrenome.
     */
        void set_sobrenome (string sobrenome) throw (invalid_argument);
        string get_sobrenome(){
            return sobrenome;
        }

};

/**
 * @brief classe abstrata com o intuito de guardar um endereco de telefone valido.
 *
 * Possui os seguintes atributos de validacao:
 * A classe Telefone recebe uma string que pode possuir no m�ximo 13 caracteres.
 * O terceiro caractere deve ser um espaco.
 * O nono caractere deve ser um traco do tipo "-".
 * A string so pode conter como caracteres numeros de 0 a 9.
 *
 * A classe possui um metodo set_telefone, para receber uma string.
 * A classe possui um metodo get_telefone, que apenas retorna a string contida em um eventual objeto da classe Telefone.
 *
 */


class Telefone{
    private:
        string telefone;
        const static int TAM_MAX_TELEFONE = 13;
        const static int POS_ESPA_TELEFONE = 2;
        const static int POS_TRACO_TELEFONE = 8;
        const static int STRING_VAZIA = 0;

    /**
     * @brief Valida o atributo do tipo string da classe Telefone
     *
     * eh responsavel por validar a string recebida pela classe Telefone, de acordo com os seus atributos de valicacao.
     *
     * @param string recebe a string da classe Telefone, para realizar a sua validacao.
     */
        void validation (string) throw (invalid_argument);

    public:
    /**
     * @brief Recebe uma string para guardar na classe Telefone, de acordo com seus atributos privados.
     *
     *  O valor eh guardado somente se for validado pelo metodo de validacao.
     *  Os atributos de validacao sao os explicitados nas informacoes referentes a classe Telefone.
     *
     * @param telefone recebe a string da classe Telefone.
     */
        void set_telefone (string telefone) throw (invalid_argument);
        string get_telefone(){
            return telefone;
        }
};

/**
 * @brief classe abstrata com o intuito de guardar um endereco geografico.
 *
 * Possui os seguintes atributos de validacao:
 * A classe Endereco recebe uma string que pode possuir no m�ximo 20 caracteres.
 * O primeiro e o ultimo caracteres nao podem ser um espaco.
 * Nao deve possuir dois ou mais espacos consecutivos.
 * A string so pode conter como caracteres vogais ou consoantes, minusculas ou maiusculas.
 *
 * A classe possui um metodo set_endereco, para receber uma string.
 * A classe possui um metodo get_endereco, que apenas retorna a string contida em um eventual objeto da classe Endereco.
 *
 */

class Endereco{
    private:
        string endereco;
        const static int TAM_MAX_ENDERECO = 20;
        const static int TAM_MAX_ESPAC_CONSEC = 2;
        const static int STRING_VAZIA = 0;

    /**
     * @brief Valida o atributo do tipo string da classe Endereco
     *
     * eh responsavel por validar a string recebida pela classe Endereco, de acordo com os seus atributos de valicacao.
     *
     * @param string recebe a string da classe Endereco, para realizar a sua validacao.
     */
        void validation(string) throw (invalid_argument);

    public:
    /**
     * @brief Recebe uma string para guardar na classe Endereco, de acordo com seus atributos privados.
     *
     *  O valor eh guardado somente se for validado pelo metodo de validacao.
     *  Os atributos de validacao sao os explicitados nas informacoes referentes a classe Endereco.
     *
     * @param endereco recebe a string da classe Endereco.
     */
        void set_endereco (string endereco) throw (invalid_argument);
        string get_endereco(){
            return endereco;
        }
};

/**
 * @brief classe abstrata com o intuito de guardar uma data.
 *
 *
 * Possui os seguintes atributos de validacao:
 * A classe Endereco recebe uma string que pode possuir no m�ximo 20 caracteres.
 * Deve possuir um formato fixo: DD/MM/AAAA.
 * DD eh uma string que representa um numero entre 01 e 31.
 * MM eh uma string que representa um numero entre 01 e 12.
 * AAAAA eh uma string que representa um numero entre 1900 e 2099.
 * As datas consideram os anos bissextos.
 *
 * A classe possui um metodo set_data, para receber uma string.
 * A classe possui um metodo get_data, que apenas retorna a string contida em um eventual objeto da classe Data.
 *
 */

class Data{
    private:
        string data;
        const static int TAM_MAX_DATA = 10;
        const static int STRING_VAZIA = 0;
        const static int DIA_MAX = 31;
        const static int DIA_MIN = 1;
        const static int MES_MAX = 12;
        const static int MES_MIN = 1;
        const static int ANO_MIN = 1900;
        const static int ANO_MAX = 2099;
        const static int FEVEREIRO = 2;
        const static int ABRIL = 4;
        const static int JUNHO = 6;
        const static int SETEMBRO = 9;
        const static int NOVEMBRO = 11;

    /**
     * @brief Valida o atributo do tipo string da classe Data
     *
     * eh responsavel por validar a string recebida pela classe Data, de acordo com os seus atributos de valicacao.
     *
     * @param string recebe a string da classe Data, para realizar a sua validacao.
     */
        void validation(string) throw (invalid_argument);

    public:
    /**
     * @brief Recebe uma string para guardar na classe Data, de acordo com seus atributos privados.
     *
     *  O valor eh guardado somente se for validado pelo metodo de validacao.
     *  Os atributos de validacao sao os explicitados nas informacoes referentes a classe Endereco.
     *
     * @param data recebe a string da classe Data.
     */
        void set_data (string data) throw (invalid_argument);
        string get_data(){
            return data;
        }
};

/**
 * @brief classe abstrata com o intuito de guardar um endereco de correio eletronico.
 *
 * Possui os seguintes atributos de validacao:
 * local:
 * O primeiro e o ultimo caracteres nao podem ser um ponto ".".
 * Pode conter como caracteres vogais ou consoantes, minusculas ou maiusculas. numeros de 0 a 9.
 * Pode conter caracteres da sequencia especifica: " ! # $ % & ' * + - / = ? ^ _ ' { | } ~ ; ".
 * dominio:
 * O primeiro e o ultimo caracteres nao podem ser um hifen "-".
 * Pode conter como caracteres vogais ou consoantes, minusculas ou maiusculas. numeros de 0 a 9. e o hifen.
 *
 * O local e o dominio sao separados por "@".
 *
 * A classe possui um metodo set_correio_eletronico, para receber uma string.
 * A classe possui um metodo get_correio_eletronico, que apenas retorna a string contida em um eventual objeto da classe Endereco.
 *
 */

class Correio_Eletronico{
    private:
        string correio_eletronico;
        const static int POS_INVALIDA = -1;
        const static int STRING_VAZIA = 0;
        const static int APOSTROFO = 39;

    /**
     * @brief Valida o atributo do tipo string da classe Correio_Eletronico
     *
     * é responsavel por validar a string recebida pela classe Correio_Eletronico, de acordo com os seus atributos de valicacao.
     *
     * @param string recebe a string da classe Correio_Eletronico, para realizar a sua validacao.
     */
        void validation(string) throw (invalid_argument);

    public:
    /**
     * @brief Recebe uma string para guardar na classe Correio_Eletronico, de acordo com seus atributos privados.
     *
     *  O valor eh guardado somente se for validado pelo metodo de validacao.
     *  Os atributos de validacao sao os explicitados nas informacoes referentes a classe Correio_Eletronico.
     *
     * @param correio_eletronico recebe a string da classe Correio_Eletronico.
     */
        void set_correio_eletronico (string correio_eletronico) throw (invalid_argument);
        string get_correio_eletronico(){
            return correio_eletronico;
        }
};

/**
 * @brief classe abstrata com o intuito de guardar a senha de um usuario.
 *
 *
 * Possui os seguintes atributos de validacao:
 * A classe Senha recebe uma string que pode possuir no m�ximo 8 caracteres.
 * Deve conter ao menos uma letra minuscula, uma letra maiuscula e um numero.
 * Pode conter como caracteres vogais ou consoantes, minusculas ou maiusculas. numeros de 0 a 9.
 *
 * A classe possui um metodo set_senha, para receber uma string.
 * A classe possui um metodo get_senha, que apenas retorna a string contida em um eventual objeto da classe Senha.
 *
 */

class Senha{
    private:
        string senha;
        const static int TAM_MAX_SENHA = 8;
        const static int STRING_VAZIA = 0;

    /**
     * @brief Valida o atributo do tipo string da classe Senha
     *
     * eh responsavel por validar a string recebida pela classe Senha, de acordo com os seus atributos de valicacao.
     *
     * @param string recebe a string da classe Senha, para realizar a sua validacao.
     */
        void validation(string) throw (invalid_argument);

    public:
    /**
     * @brief Recebe uma string para guardar na classe Senha, de acordo com seus atributos privados.
     *
     *  O valor eh guardado somente se for validado pelo metodo de validacao.
     *  Os atributos de validacao sao os explicitados nas informacoes referentes a classe Senha.
     *
     * @param senha recebe a string da classe Senha.
     */
        void set_senha (string senha) throw (invalid_argument);
        string get_senha(){
            return senha;
        }
};

/**
 * @brief classe abstrata com o intuito de guardar um paragrafo tido como uma definicao.
 *
 * Possui os seguintes atributos de validacao:
 * A classe Senha recebe uma string que pode possuir no m�ximo 30 caracteres.
 *
 * A classe possui um metodo set_texto_definicao, para receber uma string.
 * A classe possui um metodo get_texto_definicao, que apenas retorna a string contida em um eventual objeto da classe Senha.
 *
 */

class Texto_Definicao{
    private:
        string texto_definicao;
        const static int TAM_MAX_TEXTO = 30;

    /**
     * @brief Valida o atributo do tipo string da classe Texto_Definicao
     *
     * eh responsavel por validar a string recebida pela classe Texto_Definicao, de acordo com os seus atributos de valicacao.
     *
     * @param string recebe a string da classe Texto_Definicao, para realizar a sua validacao.
     */
        void validation(string) throw (invalid_argument);

    public:
    /**
     * @brief Recebe uma string para guardar na classe Texto_Definicao, de acordo com seus atributos privados.
     *
     *  O valor eh guardado somente se for validado pelo metodo de validacao.
     *  Os atributos de validacao sao os explicitados nas informacoes referentes a classe Texto_Definicao.
     *
     * @param texto_definicao recebe a string da classe Texto_Definicao.
     */
        void set_texto_definicao (string texto_definicao) throw (invalid_argument);
        string get_texto_definicao(){
            return texto_definicao;
        }
};

/**
 * @brief classe abstrata com o intuito de guardar um paragrafo tido como uma definicao.
 *
 * Possui os seguintes atributos de validacao:
 * A classe Idioma recebe uma string que pode possuir somente as seguintes strings: "ENG, FRA, GER, ITA, POR, SPA".
 *
 * A classe possui um metodo set_idioma, para receber uma string.
 * A classe possui um metodo get_idioma, que apenas retorna a string contida em um eventual objeto da classe Idioma.
 *
 */


class Idioma{
    private:
        string idioma;
    /**
     * @brief Valida o atributo do tipo string da classe Idioma
     *
     * eh responsavel por validar a string recebida pela classe Idioma, de acordo com os seus atributos de valicacao.
     *
     * @param string recebe a string da classe Idioma, para realizar a sua validacao.
     */
        void validation(string) throw (invalid_argument);

    public:
    /**
     * @brief Recebe uma string para guardar na classe Idioma, de acordo com seus atributos privados.
     *
     *  O valor eh guardado somente se for validado pelo metodo de validacao.
     *  Os atributos de validacao sao os explicitados nas informacoes referentes a classe Idioma.
     *
     * @param idioma recebe a string da classe idioma.
     */
        void set_idioma (string idioma) throw (invalid_argument);
        string get_idioma(){
            return idioma;
        }
};

/**
 * @brief classe abstrata com o intuito de guardar o tipo de um termo.
 *
 * Possui os seguintes atributos de validacao:
 * A classe Classe_Termo recebe uma string que pode possuir somente as seguintes strings: "PT, NP".
 *
 * A classe possui um metodo set_classe_termo, para receber uma string.
 * A classe possui um metodo get_classe_termo, que apenas retorna a string contida em um eventual objeto da classe Classe_Termo.
 *
 */

class Classe_Termo{
    private:
        string classe_termo;
    /**
     * @brief Valida o atributo do tipo string da classe Classe_Termo
     *
     * eh responsavel por validar a string recebida pela classe Classe_Termo, de acordo com os seus atributos de valicacao.
     *
     * @param string recebe a string da classe Classe_Termo, para realizar a sua validacao.
     */
        void validation(string) throw (invalid_argument);

    public:
    /**
     * @brief Recebe uma string para guardar na classe Classe_Termo, de acordo com seus atributos privados.
     *
     *  O valor eh guardado somente se for validado pelo metodo de validacao.
     *  Os atributos de validacao sao os explicitados nas informacoes referentes a classe Classe_Termo.
     *
     * @param classe_termo recebe a string da classe Classe_Termo.
     */
        void set_classe_termo (string classe_termo) throw (invalid_argument);
        string get_classe_termo(){
            return classe_termo;
        }
};
#endif
