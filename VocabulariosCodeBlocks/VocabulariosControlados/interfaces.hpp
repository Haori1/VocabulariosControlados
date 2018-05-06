#ifndef __INTERFACES_HPP__
#define __INTERFACES_HPP__

#include <exception>
#include <stdexcept>

#include "dominios.hpp"
#include "entidades.hpp"

using namespace std;

class IUAutenticacao{
    public:
        virtual bool Autenticar(string, string) throw (invalid_argument) = 0; //Método virtual de autenticação
        virtual ~IUAutenticacao(){} //Destrutor Virtual
};


#endif
