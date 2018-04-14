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

        void validation (const Senha &senha) throw (invalid_argument);

    public:
        Leitor(const Nome &nome, const Sobrenome &sobrenome,
               const Correio_Eletronico &correio_eletronico, const Senha &senha){
            this->nome = nome;
            this->sobrenome = sobrenome;
            this->correio_eletronico = correio_eletronico;
            this->senha = senha;
        }
        Leitor(){}  //Nao entendi mt bem, mas o construtor so funfa assim.
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

};

class Desenvolvedor : public Leitor{
    protected:
        Data data_nascimento;

    public:
        Desenvolvedor(const Nome &nome, const Sobrenome &sobrenome,
                      const Data &data_nascimento, const Correio_Eletronico &correio_eletronico,
                      const Senha &senha){
            this->nome = nome;
            this->sobrenome = sobrenome;
            this->data_nascimento = data_nascimento;
            this->correio_eletronico = correio_eletronico;
            this->senha = senha;
                      }
        Desenvolvedor(){}
        void set_data_nascimento(const Data &data_nascimento_){
            this->data_nascimento = data_nascimento;
        }

};

class Administrador : public Desenvolvedor{
    protected:
        Endereco endereco;

    public:
        Administrador(const Nome &nome, const Sobrenome &sobrenome,
                      const Data &data_nascimento, const Correio_Eletronico &correio_eletronico,
                      const Senha &senha, const Endereco &endereco){
            this->nome = nome;
            this->sobrenome = sobrenome;
            this->data_nascimento = data_nascimento;
            this->correio_eletronico = correio_eletronico;
            this->senha = senha;
            this->endereco = endereco;
        }
        Administrador(){}
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
        VocControlado(Nome &nome, Idioma &idioma, Data &data){
            this->nome = nome;
            this->idioma = idioma;
            this->data = data;
        }
        VocControlado(){}
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


};

class Termo{
    private:
        Nome nome;
        Classe_Termo classe_termo;
        Data data;

    public:
        Termo(const Nome &nome, const Classe_Termo &classe_termo,
              const Data &data){
            this->nome = nome;
            this->classe_termo = classe_termo;
            this->data = data;
        }
        Termo(){}
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
};

class Definicao{
    private:
        Texto_Definicao texto_definicao;
        Data data;

    public:
        Definicao(const Texto_Definicao &texto_definicao, const Data &data){
            this->texto_definicao = texto_definicao;
            this->data = data;
        }
        Definicao(){}
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
};


#endif
