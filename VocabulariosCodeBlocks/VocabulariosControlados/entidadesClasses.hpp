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
        void setSenha(string senha) throw (invalid_argument);

};

class Desenvolvedor{
    private:
        Nome nome;
        Sobrenome sobrenome;
        Data data;
        Correio_Eletronico correio_eletronico;
        Senha senha;
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
        void setData(const Data &data){
            this->data = data;
        }
        Data getData() const {
            return data;
        }
        void setCorreio_Eletronico(const Correio_Eletronico &correio_eletronico){
            this->correio_eletronico = correio_eletronico;
        }
        Correio_Eletronico getCorreio_Eletronico() const {
            return correio_eletronico;
        }
        void setSenha(string senha) throw (invalid_argument);

};


#endif
