#ifndef __COMANDOS_HPP__
#define __COMANDOS_HPP__

#include <iostream>
#include <stdexcept>
#include <exception>
#include <cstdlib>

#include "interfaces.hpp"
#include "dominios.hpp"
#include "entidades.hpp"
#include "stubs.hpp"
#include "controle.hpp"

using namespace std;

/*----------------------------------------------------------------------------*/

class ComandoCadastro {
    public:
        virtual void ExecutarComando(CadastroIS *) throw (invalid_argument) = 0; //Interface dos comandos
        virtual ~ComandoCadastro(){}

};

class ComandoCadastroLeitorIA : public ComandoCadastro {
    public:
        void ExecutarComando(CadastroIS *) throw (invalid_argument) override;
};

class ComandoCadastroDesenvolvedorIA : public ComandoCadastro {
    public:
        void ExecutarComando(CadastroIS *) throw (invalid_argument) override;

};

class ComandoCadastroAdministradorIA : public ComandoCadastro {
    public:
        void ExecutarComando(CadastroIS *) throw (invalid_argument) override;
};

/*----------------------------------------------------------------------------*/

class ComandoUsuario{
    public:
        virtual Resultado ExecutarComando(UsuarioIS *, const ResultadoUsuario) throw (invalid_argument) = 0;
        virtual ~ComandoUsuario(){}
};

class ComandoExibir : public ComandoUsuario {
    public:
        Resultado ExecutarComando(UsuarioIS *, const ResultadoUsuario) throw (invalid_argument) override;
};

class ComandoExcluir : public ComandoUsuario {
    public:
        Resultado ExecutarComando(UsuarioIS *, const ResultadoUsuario) throw (invalid_argument) override;
};

class ComandoEditar : public ComandoUsuario {
    public:
        Resultado ExecutarComando(UsuarioIS *, const ResultadoUsuario) throw (invalid_argument) override;
};

/*----------------------------------------------------------------------------*/

class ComandoListarVocabularios{
    public:
        vector<VocControlado> ExecutarComando(VocabulariosIS *);
};

class ComandoConsultarVocabulario{
    public:
        vector<Termo> ExecutarComando(VocabulariosIS *, vector<VocControlado>&, string) throw (invalid_argument);
};

class ComandoConsultarTermo {
    public:
        Termo ExecutarComando(VocabulariosIS *, vector<Termo>&, string) throw (invalid_argument);
};

class ComandoConsultarDefinicao{
    public:
        void ExecutarComando(VocabulariosIS *, Termo&) throw (invalid_argument) ;
};

#endif
