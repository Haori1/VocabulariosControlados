#ifndef __COMANDO_SQL__HPP__
#define __COMANDO_SQL__HPP__

#include <iostream>
#include <conio.h>
#include <string>
#include <stdio.h>
#include <list>

#include "sqlite3.h"
#include "dominios.hpp"
#include "entidades.hpp"

using namespace std;

/*----------------------------------------------------------------------------*/

class Elemento{
    private:
        string nome_coluna;
        string valor_coluna;

    public:
        void set_nome_coluna(const string &nome_coluna){
            this->nome_coluna = nome_coluna;
        }

        string get_nome_coluna() const {
            return nome_coluna;
        }

        void set_valor_coluna(const string &valor_coluna){
            this->valor_coluna = valor_coluna;
        }

        string get_valor_coluna() const {
            return valor_coluna;
        }
};

/*----------------------------------------------------------------------------*/

class ComandoSQL{
    private:
        const char *nome_banco_dados;
        sqlite3 *bd;
        char* mensagem;
        int rc;

        void Conectar() throw (invalid_argument);
        void Desconectar() throw (invalid_argument);
        static int Callback(void *, int, char **, char **);

    protected:
        string comando_sql;
        static list<Elemento> lista_resultado;

    public:
        ComandoSQL(){
            nome_banco_dados = "voc_controlado_db.db";
        }

        void Executar() throw (invalid_argument);
};

/*----------------------------------------------------------------------------*/

class ComandoSQLCadastrar : public ComandoSQL {
    public:
        ComandoSQLCadastrar(const Leitor&, string tipo);
        ComandoSQLCadastrar(const Desenvolvedor&, string tipo);
        ComandoSQLCadastrar(const Administrador&, string tipo);
};


#endif
