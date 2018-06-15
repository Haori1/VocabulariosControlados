#include "comandoSQL.hpp"

list<Elemento> ComandoSQL::lista_resultado;

/*----------------------------------------------------------------------------*/

void ComandoSQL::Conectar() throw (invalid_argument){
    rc = sqlite3_open(nome_banco_dados, &bd);
    if(rc != SQLITE_OK)
        throw invalid_argument("Erro na conexao ao banco de dados");
}

void ComandoSQL::Desconectar() throw (invalid_argument){
    rc = sqlite3_close(bd);
    if(rc != SQLITE_OK)
        throw invalid_argument("Erro na desconexao ao banco de dados");
}

void ComandoSQL::Executar() throw (invalid_argument){
    Conectar();
    rc = sqlite3_exec(bd, comando_sql.c_str(), Callback, nullptr, &mensagem);
    if(rc != SQLITE_OK){
        if(mensagem)
            sqlite3_free(mensagem);

        throw invalid_argument("Erro na execucao do comando SQL");
    }
    Desconectar();
}

int ComandoSQL::Callback(void *not_used, int argc, char **valor_coluna, char **nome_coluna){
    Elemento elemento;

    for(int i = 0; i < argc; i++){
        elemento.set_nome_coluna(nome_coluna[i]);
        elemento.set_valor_coluna(valor_coluna ? valor_coluna[i]: "NULL");
        lista_resultado.push_front(elemento);
    }
    return 0;
}
/*----------------------------------------------------------------------------*/

ComandoSQLCadastrar::ComandoSQLCadastrar(const Leitor &leitor, string tipo){
    comando_sql += "INSERT or IGNORE INTO Usuario (Nome, Sobrenome, Senha, Email, Tipo) VALUES (";
    comando_sql += "'" + leitor.get_nome().get_nome() + "', ";
    comando_sql += "'" + leitor.get_sobrenome().get_sobrenome() + "', ";
    comando_sql += "'" + leitor.get_senha().get_senha() + "', ";
    comando_sql += "'" + leitor.get_correio_eletronico().get_correio_eletronico() + "', ";
    comando_sql += "'" + tipo + "');";
}

ComandoSQLCadastrar::ComandoSQLCadastrar(const Desenvolvedor &desenvolvedor, string tipo){
    comando_sql += "INSERT or IGNORE INTO Usuario (Nome, Sobrenome, Data, Email, Senha, Tipo) VALUES (";
    comando_sql += "'" + desenvolvedor.get_nome().get_nome() + "', ";
    comando_sql += "'" + desenvolvedor.get_sobrenome().get_sobrenome() + "', ";
    comando_sql += "'" + desenvolvedor.get_data().get_data() + "', ";
    comando_sql += "'" + desenvolvedor.get_correio_eletronico().get_correio_eletronico() + "', ";
    comando_sql += "'" + desenvolvedor.get_senha().get_senha() + "', ";
    comando_sql += "'" + tipo += "');";
}

ComandoSQLCadastrar::ComandoSQLCadastrar(const Administrador &administrador, string tipo){
    comando_sql += "INSERT or IGNORE INTO Usuario (Nome, Sobrenome, Telefone, Data, Endereco, Email, Senha, Tipo) VALUES (";
    comando_sql += "'" + administrador.get_nome().get_nome() + "', ";
    comando_sql += "'" + administrador.get_sobrenome().get_sobrenome() + "', ";
    comando_sql += "'" + administrador.get_telefone().get_telefone() + "', ";
    comando_sql += "'" + administrador.get_data().get_data() +  "', ";
    comando_sql += "'" + administrador.get_endereco().get_endereco() + "', ";
    comando_sql += "'" + administrador.get_correio_eletronico().get_correio_eletronico() + "', ";
    comando_sql += "'" + administrador.get_senha().get_senha() + "', ";
    comando_sql += "'" + tipo + "');";
}

/*----------------------------------------------------------------------------*/
