#ifndef __ENTIDADES__HPP__
#define __ENTIDADES__HPP__

#include <iostream>

#include "dominiosClasses.hpp"

using namespace std;

/**
 * @file entidadesClasses.hpp
 * @author Henrique Mendes de Freitas Mariano
 * @author Gabriel Alves Castro
 * @date 12 de abril de 2018
 *
 * @brief Descricao acerca das classes de entidades, referindo-se a seus atributos e funcionalidades.
 *
 * As classes de entidades sao um nivel maior de abstracao abordado nesse projeto.
 * Referem-se aos elementos que compoem as entidades.
 */


/**
 * @brief Classe abstrata com o intuito de armazenar os dados de um leitor.
 * As formas de se utilizar essa classe é pelo seu construtor Leitor() e pelos seus metodos set e get.
 */

class Leitor{
    protected:
        Nome nome;
        Sobrenome sobrenome;
        Correio_Eletronico correio_eletronico;
        Senha senha;

        const static int Converte_Maiuscula = 32; // Valor que subtraido de uma letra minuscula, retorna uma maiuscula, segundo a tabela ascii
        void validation (const Senha &senha) throw (invalid_argument);

    public:
        /**
         * @brief Recebe um objeto do tipo Nome para armazenar na classe Leitor, de acordo com seus atributos privados.
         *
         * @param nome é o objeto que é passado para a classe Leitor, de acordo com seus atributos privados.
         */
      void set_nome(const Nome &nome){
            this->nome = nome;
        }
        /**
         * @brief Fornece o objeto do tipo Nome da classe Leitor.
         */
        Nome get_nome() const {
            return nome;
        }
        /**
         * @brief Recebe um objeto do tipo Sobrenome para armazenar na classe Leitor, de acordo com seus atributos privados.
         *
         * @param sobrenome é o objeto que é passado para a classe Leitor, de acordo com seus atributos privados.
         */
        void set_sobrenome(const Sobrenome &sobrenome){
            this->sobrenome = sobrenome;
        }
        /**
         * @brief Fornece o objeto do tipo Sobrenome da classe Leitor.
         */
        Sobrenome get_sobrenome() const {
            return sobrenome;
        }
        /**
         * @brief Recebe um objeto do tipo Correio_Eletronico para armazenar na classe Leitor, de acordo com seus atributos privados.
         *
         * @param correio_eletronico é o objeto que é passado para a classe Leitor, de acordo com seus atributos privados.
         */
        void set_correio_eletronico(const Correio_Eletronico &correio_eletronico){
            this->correio_eletronico = correio_eletronico;
        }
        /**
         * @brief Fornece o objeto do tipo Correio_Eletronico da classe Leitor.
         */
        Correio_Eletronico get_correio_eletronico() const {
            return correio_eletronico;
        }
        /**
         * @brief Recebe um objeto do tipo Senha para armazenar na classe Leitor, de acordo com seus atributos privados, porém primeiro é realizada uma verificação para averiguar se o nome passado não está contido na senha.
         *
         * @param senha é o objeto que é passado para a classe Leitor, de acordo com seus atributos privados.
         */
        void set_senha(const Senha &senha) throw (invalid_argument);
        /**
         * @brief Fornece o objeto do tipo Senha da classe Leitor.
         */
        Senha get_senha() const {
            return senha;
        }
        /**
         * @brief Leitor() é a função que é passada para criar-se um novo objeto.
         * @param nome é o objeto que é passado para a classe Leitor, de acordo com seus atributos privados.
         * @param sobrenome é o objeto que é passado para a classe Leitor, de acordo com seus atributos privados.
         * @param correio_eletronico é o objeto que é passado para a classe Leitor, de acordo com seus atributos privados.
         * @param senha é o objeto que é passado para a classe Leitor, de acordo com seus atributos privados.
         */
        Leitor(const Nome &nome, const Sobrenome &sobrenome,
               const Correio_Eletronico &correio_eletronico, const Senha &senha){
            set_nome(nome);
            set_sobrenome(sobrenome);
            set_correio_eletronico(correio_eletronico);
            set_senha(senha);
        }
        /**
         * @brief Construtor default da classe Leitor.
         */
        Leitor(){}

};
/**
 * @brief Classe abstrata com o intuito de armazenar os dados de um Desenvolvedor.
 * As formas de se utilizar essa classe é pelo seu construtor Desenvolvedor() e pelos seus metodos set e get.
 */
class Desenvolvedor : public Leitor{
    protected:
        Data data_nascimento;

    public:
        /**
         * @brief Recebe um objeto do tipo Data para armazenar na classe Desenvolvedor, de acordo com seus atributos privados.
         *
         * @param data_nascimento é o objeto que é passado para a classe Desenvolvedor, de acordo com seus atributos privados.
         */
        void set_data(const Data &data_nascimento){
            this->data_nascimento = data_nascimento;
        }
        /**
         * @brief Fornece o objeto do tipo Data da classe Desenvolvedor.
         */
        Data get_data() const {
            return data_nascimento;
        }
        /**
         * @brief Desenvolvedor() é a função que é passada para criar-se um novo objeto.
         * @param nome é o objeto que é passado para a classe Desenvolvedor, de acordo com seus atributos privados.
         * @param data_nascimento é o objeto que é passado para a classe Desenvolvedor, de acordo com seus atributos privados.
         * @param sobrenome é o objeto que é passado para a classe Desenvolvedor, de acordo com seus atributos privados.
         * @param correio_eletronico é o objeto que é passado para a classe Desenvolvedor, de acordo com seus atributos privados.
         * @param senha é o objeto que é passado para a classe Desenvolvedor, de acordo com seus atributos privados.
         */
        Desenvolvedor(const Nome &nome, const Sobrenome &sobrenome,
               const Data &data_nascimento, const Correio_Eletronico &correio_eletronico,
               const Senha &senha){
            set_nome(nome);
            set_sobrenome(sobrenome);
            set_data(data_nascimento);
            set_correio_eletronico(correio_eletronico);
            set_senha(senha);
        }
        /**
         * @brief Construtor default da classe Desenvolvedor.
         */
        Desenvolvedor(){}

};
/**
 * @brief Classe abstrata com o intuito de armazenar os dados de um Administrador.
 * As formas de se utilizar essa classe é pelo seu construtor Administrador() e pelos seus metodos set e get.
 */
class Administrador : public Desenvolvedor{
    protected:
        Telefone telefone;
        Endereco endereco;

    public:
        /**
         * @brief Recebe um objeto do tipo Telefone para armazenar na classe Administrador, de acordo com seus atributos privados.
         *
         * @param telefone é o objeto que é passado para a classe Administrador, de acordo com seus atributos privados.
         */
        void set_telefone(const Telefone &telefone){
            this->telefone = telefone;
        }
        /**
         * @brief Fornece o objeto do tipo Telefone da classe Administrador.
         */
        Telefone get_telefone() const {
            return telefone;
        }
        /**
         * @brief Recebe um objeto do tipo Endereco para armazenar na classe Administrador, de acordo com seus atributos privados.
         *
         * @param endereco é o objeto que é passado para a classe Administrador, de acordo com seus atributos privados.
         */
        void set_endereco(const Endereco &endereco){
            this->endereco = endereco;
        }
        /**
         * @brief Fornece o objeto do tipo Endereco da classe Administrador.
         */
        Endereco get_endereco() const {
            return endereco;
        }
        /**
         * @brief Administrador() é a função que é passada para criar-se um novo objeto.
         * @param nome é o objeto que é passado para a classe Administrador, de acordo com seus atributos privados.
         * @param sobrenome é o objeto que é passado para a classe Administrador, de acordo com seus atributos privados.
         * @param telefone é o objeto que é passado para a classe Administrador, de acordo com seus atributos privados.
         * @param data_nascimento é o objeto que é passado para a classe Administrador, de acordo com seus atributos privados.
         * @param endereco é o objeto que é passado para a classe Administrador, de acordo com seus atributos privados.
         * @param correio_eletronico é o objeto que é passado para a classe Administrador, de acordo com seus atributos privados.
         * @param senha é o objeto que é passado para a classe Administrador, de acordo com seus atributos privados.
         */
        Administrador(const Nome &nome, const Sobrenome &sobrenome,
               const Telefone &telefone, const Data &data_nascimento,
               const Endereco &endereco, const Correio_Eletronico &correio_eletronico,
               const Senha &senha){
            set_nome(nome);
            set_sobrenome(sobrenome);
            set_telefone(telefone);
            set_data(data_nascimento);
            set_endereco(endereco);
            set_correio_eletronico(correio_eletronico);
            set_senha(senha);
        }
        /**
         * @brief Construtor default da classe Administrador.
         */
        Administrador(){}
};
/**
 * @brief Classe abstrata com o intuito de armazenar os dados de um VocControlado.
 * As formas de se utilizar essa classe é pelo seu construtor VocControlado() e pelos seus metodos set e get.
 */
class VocControlado{
    private:
        Nome nome;
        Idioma idioma;
        Data data;

    public:
        /**
         * @brief Recebe um objeto do tipo Nome para armazenar na classe VocControlado, de acordo com seus atributos privados.
         *
         * @param nome é o objeto que é passado para a classe VocControlado, de acordo com seus atributos privados.
         */
        void set_nome(const Nome &nome){
            this->nome = nome;
        }
        /**
         * @brief Fornece o objeto do tipo Nome da classe VocControlado.
         */
        Nome get_nome() const {
            return nome;
        }
        /**
         * @brief Recebe um objeto do tipo Idioma para armazenar na classe VocControlado, de acordo com seus atributos privados.
         *
         * @param idioma é o objeto que é passado para a classe VocControlado, de acordo com seus atributos privados.
         */
        void set_idioma(const Idioma &idioma){
            this->idioma = idioma;
        }
        /**
         * @brief Fornece o objeto do tipo Idioma da classe VocControlado.
         */
        Idioma get_idioma() const {
            return idioma;
        }
        /**
         * @brief Recebe um objeto do tipo Data para armazenar na classe VocControlado, de acordo com seus atributos privados.
         *
         * @param data é o objeto que é passado para a classe VocControlado, de acordo com seus atributos privados.
         */
        void set_data(const Data &data){
            this->data = data;
        }
        /**
         * @brief Fornece o objeto do tipo Data da classe VocControlado.
         */
        Data get_data() const {
            return data;
        }
        /**
         * @brief VocControlado() é a função que é passada para criar-se um novo objeto.
         * @param nome é o objeto que é passado para a classe VocControlado, de acordo com seus atributos privados.
         * @param idioma é o objeto que é passado para a classe VocControlado, de acordo com seus atributos privados.
         * @param data é o objeto que é passado para a classe VocControlado, de acordo com seus atributos privados.
         */
         VocControlado(const Nome &nome, const Idioma &idioma, const Data &data){
            set_nome(nome);
            set_idioma(idioma);
            set_data(data);
        }
        /**
         * @brief Construtor default da classe VocControlado.
         */
        VocControlado(){}

};
/**
 * @brief Classe abstrata com o intuito de armazenar os dados de um Termo.
 * As formas de se utilizar essa classe é pelo seu construtor Termo() e pelos seus metodos set e get.
 */
class Termo{
    private:
        Nome nome;
        Classe_Termo classe_termo;
        Data data;

    public:
        /**
         * @brief Recebe um objeto do tipo Nome para armazenar na classe Termo, de acordo com seus atributos privados.
         *
         * @param nome é o objeto que é passado para a classe Termo, de acordo com seus atributos privados.
         */
        void set_nome(const Nome &nome){
            this->nome = nome;
        }
        /**
         * @brief Fornece o objeto do tipo Nome da classe Termo.
         */
        Nome get_nome() const {
            return nome;
        }
        /**
         * @brief Recebe um objeto do tipo Classe_Termo para armazenar na classe Termo, de acordo com seus atributos privados.
         *
         * @param classe_termo é o objeto que é passado para a classe Termo, de acordo com seus atributos privados.
         */
        void set_classe_termo(const Classe_Termo &classe_termo){
            this->classe_termo = classe_termo;
        }
        /**
         * @brief Fornece o objeto do tipo Classe_Termo da classe Termo.
         */
        Classe_Termo get_classe_termo() const {
            return classe_termo;
        }
        /**
         * @brief Recebe um objeto do tipo Data para armazenar na classe Termo, de acordo com seus atributos privados.
         *
         * @param data é o objeto que é passado para a classe Termo, de acordo com seus atributos privados.
         */
        void set_data(const Data &data){
            this->data = data;
        }
        /**
         * @brief Fornece o objeto do tipo Data da classe Termo.
         */
        Data get_data() const {
            return data;
        }
        /**
         * @brief Termo() é a função que é passada para criar-se um novo objeto.
         * @param nome é o objeto que é passado para a classe Termo, de acordo com seus atributos privados.
         * @param classe_termo é o objeto que é passado para a classe Termo, de acordo com seus atributos privados.
         * @param data é o objeto que é passado para a classe Termo, de acordo com seus atributos privados.
         */
        Termo(const Nome &nome, const Classe_Termo &classe_termo,
              const Data &data){
            set_nome(nome);
            set_classe_termo(classe_termo);
            set_data(data);
        }
        /**
         * @brief Construtor default da classe Termo.
         */
        Termo(){}
};
/**
 * @brief Classe abstrata com o intuito de armazenar os dados de uma Definicao.
 * As formas de se utilizar essa classe é pelo seu construtor Definicao() e pelos seus metodos set e get.
 */
class Definicao{
    private:
        Texto_Definicao texto_definicao;
        Data data;

    public:
        /**
         * @brief Recebe um objeto do tipo Texto_Definicao para armazenar na classe Definicao, de acordo com seus atributos privados.
         *
         * @param texto_definicao é o objeto que é passado para a classe Definicao, de acordo com seus atributos privados.
         */
        void set_texto_definicao(const Texto_Definicao &texto_definicao){
            this->texto_definicao = texto_definicao;
        }
        /**
         * @brief Fornece o objeto do tipo Texto_Definicao da classe Definicao.
         */
        Texto_Definicao get_texto_definicao(){
            return texto_definicao;
        }
        /**
         * @brief Recebe um objeto do tipo Data para armazenar na classe Definicao, de acordo com seus atributos privados.
         *
         * @param data é o objeto que é passado para a classe Definicao, de acordo com seus atributos privados.
         */
        void set_data(const Data &data){
            this->data = data;
        }
        /**
         * @brief Fornece o objeto do tipo Data da classe Definicao.
         */
        Data get_data() const {
            return data;
        }
        /**
         * @brief Definicao() é a função que é passada para criar-se um novo objeto.
         * @param texto_definicao é o objeto que é passado para a classe Definicao, de acordo com seus atributos privados.
         * @param data é o objeto que é passado para a classe Definicao, de acordo com seus atributos privados.
         */
        Definicao(const Texto_Definicao &texto_definicao, const Data &data){
            set_texto_definicao(texto_definicao);
            set_data(data);
        }
        /**
         * @brief Construtor default da classe Definicao.
         */
        Definicao(){}
};
#endif
