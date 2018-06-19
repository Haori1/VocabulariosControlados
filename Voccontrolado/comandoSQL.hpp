#ifndef __COMANDO_SQL__HPP__
#define __COMANDO_SQL__HPP__

#include <iostream>
#include <conio.h>
#include <string>
#include <stdio.h>
#include <list>
#include <vector>

#include "sqlite3.h"
#include "dominios.hpp"
#include "entidades.hpp"
#include "servicos.hpp"

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

/*----------------------------------------------------------------------------*/

class ComandoSQLRetornoSenha : public ComandoSQL {
    public:
        ComandoSQLRetornoSenha(const Correio_Eletronico&);
        string RetornoSenha() const;
};

/*----------------------------------------------------------------------------*/

class ComandoSQLRetornoEmail : public ComandoSQL {
    public:
        ComandoSQLRetornoEmail(const Correio_Eletronico&);
        string RetornoEmail() const;
};

/*----------------------------------------------------------------------------*/

class ComandoSQLRetornoTipo : public ComandoSQL {
    public:
        ComandoSQLRetornoTipo(const Correio_Eletronico&);
        string RetornoTipo() const;
};

/*----------------------------------------------------------------------------*/

class ComandoSQLPesquisarUsuario : public ComandoSQL {
    public:
        ComandoSQLPesquisarUsuario(const Correio_Eletronico&);
        Leitor PesquisarLeitor() const;
        Desenvolvedor PesquisarDesenvolvedor() const;
        Administrador PesquisarAdministrador() const;
};

/*----------------------------------------------------------------------------*/

class ComandoSQLExcluir : public ComandoSQL {
    public:
        ComandoSQLExcluir(const Correio_Eletronico&);

};

/*----------------------------------------------------------------------------*/

class ComandoSQLEditar : public ComandoSQL {
    public:
        ComandoSQLEditar(const Leitor&);
        ComandoSQLEditar(const Desenvolvedor&);
        ComandoSQLEditar(const Administrador&);
};

/*----------------------------------------------------------------------------*/

class ComandoSQLCriarTabelas : public ComandoSQL {
    public:
        void CriarTabelas();
};

/*----------------------------------------------------------------------------*/

class ComandoSQLRegistraDefinicao : public ComandoSQL {
    public:
        ComandoSQLRegistraDefinicao(const Definicao &definicao);
};

class ComandoSQLRegistraVocabulario : public ComandoSQL {
    public:
        ComandoSQLRegistraVocabulario(const VocControlado &voc_controlado, const Definicao &definicao, const Administrador &admistrador);
};

class ComandoSQLRegistraTermo : public ComandoSQL {
    public:
        ComandoSQLRegistraTermo(const Termo &termo, string nome_voc);
};

class ComandoSQLExcluirVocabulario : public ComandoSQL {
    public:
        ComandoSQLExcluirVocabulario(const VocControlado &voc_controlado);
};

class ComandoSQLExcluirTermo : public ComandoSQL {
    public:
        ComandoSQLExcluirTermo(const Termo &termo);
};

class ComandoSQLEditarDefinicaoVocabulario : public ComandoSQL {
    public:
        ComandoSQLEditarDefinicaoVocabulario(string voc, const Definicao &definicao);
};

class ComandoSQLRetornoVocabularios : public ComandoSQL {
    private:
        int QUANTIDADE_COLUNAS = 3;
    public:
        ComandoSQLRetornoVocabularios();
        vector<VocControlado> get_vocabularios();
};

class ComandoSQLRetornoTermos : public ComandoSQL {
    private:
        int QUANTIDADE_COLUNAS = 3;
    public:
        ComandoSQLRetornoTermos(const VocControlado &voc_controlado);
        vector<Termo> get_termos();
};

class ComandoSQLRetornoDefinicoesVoc : public ComandoSQL {
    private:
        int QUANTIDADE_COLUNAS = 2;
    public:
 //havera a definicao de vocabulario, que devera ser linkada ao vocabulario sempre, ou nao, dependendo do que escolher na apresentacao
        ComandoSQLRetornoDefinicoesVoc(const VocControlado &voc_controlado);
        Definicao get_definicao();
};

 //haverao as definicoes dos termos, que devera seguir determinadas regras de negocio.

class ComandoSQLAlterarIdiomaVoc : public ComandoSQL {
    public:
        ComandoSQLAlterarIdiomaVoc(const VocControlado &voc_controlado);
 };

class ComandoSQLCadastraDevenvolvedor : public ComandoSQL {
    public:
        ComandoSQLCadastraDevenvolvedor(string voc, string correio_eletronico);
};

class ComandoRetornaDesenvolvedor_Vocabulario : public ComandoSQL {
    public:
        ComandoRetornaDesenvolvedor_Vocabulario(string voc);
        int get_quantidade_desenvolvedores();
        vector<string> get_desenvolvedores();
};

class ComandoSQLLinkaDefinicao_Termo : public ComandoSQL {
    public:
        ComandoSQLLinkaDefinicao_Termo(string texto_definicao, string nome_termo);
};

class ComandoSQLRetornaDefinicao_Termo : public ComandoSQL {
    public:
        ComandoSQLRetornaDefinicao_Termo(string termo);
        int get_quantidade_definicoes();
        vector<string> get_definicoes();
};

class ComandoSQLRetornaDefinicoesTermo : public ComandoSQL {
    private:
        int QUANTIDADE_COLUNAS = 2;
    public:
        ComandoSQLRetornaDefinicoesTermo(string texto_definicao);
        Definicao get_definicao();
};


#endif
