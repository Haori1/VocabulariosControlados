#ifndef __ENTIDADES__HPP__
#define __ENTIDADES__HPP__

#include <iostream>

#include "dominiosClasses.hpp"

using namespace std;

class Leitor{
    protected:
        Nome nome;
        Sobrenome sobrenome;
        Correio_Eletronico correio_eletronico;
        Senha senha;

        int Converte_Maiuscula = 32; // Valor que subtraido de uma letra minuscula, retorna uma maiuscula, segundo a tabela ascii
        void validation (const Senha &senha) throw (invalid_argument);

    public:

      void set_nome(const Nome &nome){
            this->nome = nome;
        }
        Nome get_nome() const {
            return nome;
        }
        void set_sobrenome(const Sobrenome &sobrenome){
            this->sobrenome = sobrenome;
        }
        Sobrenome get_sobrenome() const {
            return sobrenome;
        }
        void set_correio_eletronico(const Correio_Eletronico &correio_eletronico){
            this->correio_eletronico = correio_eletronico;
        }
        Correio_Eletronico get_correio_eletronico() const {
            return correio_eletronico;
        }
        void set_senha(const Senha &senha) throw (invalid_argument);

        Senha get_senha() const {
            return senha;
        }

        Leitor(const Nome &nome, const Sobrenome &sobrenome,
               const Correio_Eletronico &correio_eletronico, const Senha &senha){
            set_nome(nome);
            set_sobrenome(sobrenome);
            set_correio_eletronico(correio_eletronico);
            set_senha(senha);
        }
        Leitor(){}

};

class Desenvolvedor : public Leitor{
    protected:
        Data data_nascimento;

    public:
        void set_data(const Data &data_nascimento){
            this->data_nascimento = data_nascimento;
        }
        Data get_data() const {
            return data_nascimento;
        }


        Desenvolvedor(const Nome &nome, const Sobrenome &sobrenome,
               const Data &data_nascimento, const Correio_Eletronico &correio_eletronico,
               const Senha &senha){
            set_nome(nome);
            set_sobrenome(sobrenome);
            set_data(data_nascimento);
            set_correio_eletronico(correio_eletronico);
            set_senha(senha);
        }
        Desenvolvedor(){}

};

class Administrador : public Desenvolvedor{
    protected:
        Telefone telefone;
        Endereco endereco;

    public:
        void set_telefone(const Telefone &telefone){
            this->telefone = telefone;
        }
        Telefone get_telefone() const {
            return telefone;
        }
        void set_endereco(const Endereco &endereco){
            this->endereco = endereco;
        }
        Endereco get_endereco() const {
            return endereco;
        }

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
        Administrador(){}
};

class VocControlado{
    private:
        Nome nome;
        Idioma idioma;
        Data data;

    public:
        void set_nome(const Nome &nome){
            this->nome = nome;
        }
        Nome get_nome() const {
            return nome;
        }
        void set_idioma(const Idioma &idioma){
            this->idioma = idioma;
        }
        Idioma get_idioma() const {
            return idioma;
        }
        void set_data(const Data &data){
            this->data = data;
        }
        Data get_data() const {
            return data;
        }

    VocControlado(const Nome &nome, const Idioma &idioma, const Data &data){
            set_nome(nome);
            set_idioma(idioma);
            set_data(data);
        }
        VocControlado(){}

};

class Termo{
    private:
        Nome nome;
        Classe_Termo classe_termo;
        Data data;

    public:
        void set_nome(const Nome &nome){
            this->nome = nome;
        }
        Nome get_nome() const {
            return nome;
        }
        void set_classe_termo(const Classe_Termo &classe_termo){
            this->classe_termo = classe_termo;
        }
        Classe_Termo get_classe_termo() const {
            return classe_termo;
        }
        void set_data(const Data &data){
            this->data = data;
        }
        Data get_data() const {
            return data;
        }

        Termo(const Nome &nome, const Classe_Termo &classe_termo,
              const Data &data){
            set_nome(nome);
            set_classe_termo(classe_termo);
            set_data(data);
        }
        Termo(){}
};

class Definicao{
    private:
        Texto_Definicao texto_definicao;
        Data data;

    public:
        void set_texto_definicao(const Texto_Definicao &texto_definicao){
            this->texto_definicao = texto_definicao;
        }
        Texto_Definicao get_texto_definicao(){
            return texto_definicao;
        }
        void set_data(const Data &data){
            this->data = data;
        }
        Data get_data() const {
            return data;
        }

        Definicao(const Texto_Definicao &texto_definicao, const Data &data){
            set_texto_definicao(texto_definicao);
            set_data(data);
        }
        Definicao(){}
};


#endif
