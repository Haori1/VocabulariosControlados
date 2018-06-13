#include "comandoSQL.hpp"

list<Elemento> ComandoSQL::lista_resultado;

/*----------------------------------------------------------------------------*/

void ComandoSQL::Conectar() throw (ErroPersistencia){
    rc = sqlite3_open(nome_banco_dados, &bd);
    if(rc != SQLITE_OK)
        throw ErroPersistencia("Erro na conexao ao banco de dados");
}

void ComandoSQL::Desconectar() throw (ErroPersistencia){
    rc = sqlite3_close(bd);
    if(rc != SQLITE_OK)
        throw ErroPersistencia("Erro na desconexao ao banco de dados");
}

void ComandoSQL::Executar() throw (ErroPersistencia){
    Conectar();
    rc = sqlite3_exec(bd, comando_sql.c_str(), Callback, 0, &mensagem);
    if(rc != SQLITE_OK){
        if(mensagem)
            free(mensagem);

        throw ErroPersistencia("Erro na execucao do comando SQL");
    }
    Desconectar();
}

int ComandoSQL::Callback(void *not_used, int argc, char **valor_coluna, char **nome_coluna){
    not_used = 0;
    Elemento elemento;

    for(int i = 0; i < argc; i++){
        elemento.set_nome_coluna(nome_coluna[i]);
        elemento.set_valor_coluna(valor_coluna ? valor_coluna[i]: "NULL");
        lista_resultado.push_front(elemento);
    }
    return 0;
}
/*----------------------------------------------------------------------------*/

ComandoSQLCadastrar::ComandoSQLCadastrar(const Leitor &leitor){
    comando_sql = "INSERT or IGNORE INTO Usuarios (Nome, Sobrenome, Senha, Email) VALUES (";
    comando_sql = "'" + leitor.get_nome().get_nome() + "', ";
    comando_sql = "'" + leitor.get_sobrenome().get_sobrenome() + "', ";
    comando_sql = "'" + leitor.get_senha().get_senha() + "', ";
    comando_sql = "'" + leitor.get_correio_eletronico().get_correio_eletronico() + "');";
}

ComandoSQLCadastrar::ComandoSQLCadastrar(const Desenvolvedor &desenvolvedor){
    comando_sql = "INSERT or IGNORE INTO Usuarios (Nome, Sobrenome, Data, Email, Senha) VALUES (";
    comando_sql = "'" + desenvolvedor.get_nome().get_nome() + "', ";
    comando_sql = "'" + desenvolvedor.get_sobrenome().get_sobrenome() + "', ";
    comando_sql = "'" + desenvolvedor.get_data().get_data() + "', ";
    comando_sql = "'" + desenvolvedor.get_correio_eletronico().get_correio_eletronico() + "', ";
    comando_sql = "'" + desenvolvedor.get_senha().get_senha() + "');";
}

ComandoSQLCadastrar::ComandoSQLCadastrar(const Administrador &administrador){
    comando_sql = "INSERT or IGNORE INTO Usuarios (Nome, Sobrenome, Telefone, Data, Endereco, Email, Senha) VALUES (";
    comando_sql = "'" + administrador.get_nome().get_nome() + "', ";
    comando_sql = "'" + administrador.get_sobrenome().get_sobrenome() + "', ";
    comando_sql = "'" + administrador.get_telefone().get_telefone() + "', ";
    comando_sql = "'" + administrador.get_data().get_data() +  "', ";
    comando_sql = "'" + administrador.get_endereco().get_endereco() + "', ";
    comando_sql = "'" + administrador.get_correio_eletronico().get_correio_eletronico() + "', ";
    comando_sql = "'" + administrador.get_senha().get_senha() + "');";
}

/*----------------------------------------------------------------------------*/
