#ifndef __ENTIDADES__HPP__
#define __ENTIDADES__HPP__

#include <iostream>

#include "dominiosClasses.hpp"

using namespace std;

class Leitor{
    private:
        Nome nome;
        Sobrenome sobrenome;
        Correio_Eletronico correio_eletronico;
        Senha senha;

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

};

class Desenvolvedor : public Leitor{
    private:
    Data data_nascimento;

    public:
        void set_data_nascimento(const Data &data_nascimento){
            this->data_nascimento = data_nascimento;
        }

};

class Administrador : public Desenvolvedor{
    private:
        Endereco endereco;

    public:
        void set_endereco(const Endereco &endereco){
            this->endereco = endereco;
        }
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
        Nome get_nome(){
            return nome;
        }
        void set_idioma(const Idioma &idioma){
            this->idioma = idioma;
        }
        Idioma get_idioma(){
            return idioma;
        }
        void set_data(const Data &data){
            this->data = data;
        }
        Data get_data(){
            return data;
        }


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
        Nome get_nome(){
            return nome;
        }
        void set_classe_termo(const Classe_Termo &classe_termo){
            this->classe_termo = classe_termo;
        }
        Classe_Termo get_classe_termo(){
            return classe_termo;
        }
        void set_data(const Data &data){
            this->data = data;
        }
        Data get_data(){
            return data;
        }
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
        Data get_data(){
            return data;
        }
};


#endif
