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
      void setNome(const Nome &nome){
            this->nome = nome;
        }
        Nome getNome() const {
            return nome;
        }
        void setSobrenome(const Sobrenome &sobrenome){
            this->sobrenome = sobrenome;
        }
        Sobrenome getSobrenome() const {
            return sobrenome;
        }
        void setCorreio_Eletronico(const Correio_Eletronico &correio_eletronico){
            this->correio_eletronico = correio_eletronico;
        }
        Correio_Eletronico getCorreio_Eletronico() const {
            return correio_eletronico;
        }
        void setSenha(const Senha &senha) throw (invalid_argument);

};

class Desenvolvedor : public Leitor{
    private:
    Data data_nascimento;

    public:
        void setData_nascimento(const Data &data_nascimento){
            this->data_nascimento = data_nascimento;
        }

};

class Administrador : public Desenvolvedor{
    private:
        Endereco endereco;

    public:
        void setEndereco(const Endereco &endereco){
            this->endereco = endereco;
        }
};

class VocControlado{
    private:
        Nome nome;
        Idioma idioma;
        Data data;

    public:


};

class Termo{
    private:
        Nome nome;
        Classe_Termo classe_termo;
        Data data;

    private:
};

class Definicao{
    private:
        Texto_Definicao texto_definicao;
        Data data;

    private:
};


#endif
