#ifndef __ENTIDADES__HPP__
#define __ENTIDADES__HPP__

#include <iostream>

#include "dominios.hpp"

using namespace std;

class Leitor{
    private:
        Nome nome;
        Sobrenome sobrenome;
        Correio_Eletronico correio_eletronico;
        Senha senha;

};

class Desenvolvedor{
    private:
        Nome nome;
        Sobrenome sobrenome;
        
};


#endif