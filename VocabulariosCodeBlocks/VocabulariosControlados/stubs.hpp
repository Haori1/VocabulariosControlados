#ifndef __STUBS__HPP__
#define __STUBS__HPP__

#include <iostream>
#include <stdexcept>
#include <exception>

#include "interfaces.hpp"
#include "dominios.hpp"

using namespace std;

/*----------------------------------------------------------------------------*/

class StubAutenticacao : public AutenticacaoIS{
    public:
        static constexpr const char* TRIGGER_FALHA_SENHA = "Eoqxd12";
        static constexpr const char* TRIGGER_ERRO_SISTEMA_SENHA = "xd12E";

        static constexpr const char* TRIGGER_FALHA_EMAIL = "narutouzumaki@gmail.com";
        static constexpr const char* TRIGGER_ERRO_SISTEMA_EMAIL = "deuruim@hotmail.com";

        static constexpr const char* TRIGGER_LEITOR = "yuri@hotmail.com";
        static constexpr const char* NOME_LEITOR = "Yuri";
        static constexpr const char* SOBRENOME_LEITOR = "Azevedo";

        static constexpr const char* TRIGGER_DESENVOLVEDOR = "henrique@gmail.com";
        static constexpr const char* NOME_DESENVOLVEDOR = "Henrique";
        static constexpr const char* SOBRENOME_DESENVOLVEDOR = "Mariano";
        static constexpr const char* DATA_DESENVOLVEDOR = "11/03/1999"; //checar o formato correto da data.

        static constexpr const char* TRIGGER_ADMINISTRADOR = "gabriel@unb.com";
        static constexpr const char* NOME_ADMINISTRADOR = "Gabriel";
        static constexpr const char* SOBRENOME_ADMINISTRADOR = "Alves";
        static constexpr const char* DATA_ADMINISTRADOR = "11/03/1999";
        static constexpr const char* TELEFONE_ADMINISTRADOR = "99 99999-9999";
        static constexpr const char* ENDERECO_ADMINISTRADOR = "Aldeiadafolha";

        Resultado Autenticar(const Correio_Eletronico&, const Senha&) throw (invalid_argument) override;
        ResultadoUsuario TipoDeUsuario(const Correio_Eletronico&, const Senha&) override;

};

/*----------------------------------------------------------------------------*/

class StubCadastro : public CadastroIS{ //Falta terminar a declaracao e codificar a classe
    private:
        Leitor leitor;
        Desenvolvedor desenvolvedor;
        Administrador administrador;

    public:
        static constexpr const char* TRIGGER_CORREIO_ELETRONICO = "junkdog@gmail.com";
        static constexpr const char* TRIGGER_ERRO_SISTEMA_EMAIL = "eaemeuchapa@gmail.com";
        Resultado CadastroLeitor(const Leitor&) throw (invalid_argument) override;
        Resultado CadastroDesenvolvedor(const Desenvolvedor&) throw (invalid_argument) override;
        Resultado CadastroAdministrador(const Administrador&) throw (invalid_argument) override;


};

/*----------------------------------------------------------------------------*/

class StubVocabularios : public VocabulariosIS{


};

#endif
