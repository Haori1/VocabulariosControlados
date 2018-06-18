#include "comandoSQL.hpp"

list<Elemento> ComandoSQL::lista_resultado;

/*----------------------------------------------------------------------------*/

void ComandoSQLCriarTabelas::CriarTabelas() {
  comando_sql += "CREATE TABLE IF NOT EXISTS Usuario (";
  comando_sql += "Nome VARCHAR(21) NOT NULL, ";
  comando_sql += "Sobrenome VARCHAR(21) NOT NULL, ";
  comando_sql += "Senha VARCHAR(9) NOT NULL, ";
  comando_sql += "Email VARCHAR(100) NOT NULL, ";
  comando_sql += "Data VARCHAR(11), ";
  comando_sql += "Telefone VARCHAR(14), ";
  comando_sql += "Endereco VARCHAR(21), ";
  comando_sql += "Tipo INTEGER NOT NULL, ";
  comando_sql += "PRIMARY KEY(Email) );";

  comando_sql += "CREATE TABLE IF NOT EXISTS Definicao (";
  comando_sql += "Texto VARCHAR(31) NOT NULL, ";
  comando_sql += "Data VARCHAR(11) NOT NULL, ";
  comando_sql += "PRIMARY KEY(Texto) );";

  comando_sql += "CREATE TABLE IF NOT EXISTS Vocabulario (";
  comando_sql += "Nome VARCHAR(21) NOT NULL, ";
  comando_sql += "Idioma VARCHAR(4) NOT NULL, ";
  comando_sql += "Data VARCHAR(11) NOT NULL, ";
  comando_sql += "Definicao INT NOT NULL, ";
  comando_sql += "Administrador VARCHAR(100) NOT NULL, ";
  comando_sql += "FOREIGN KEY(Definicao) REFERENCES Definicao(Texto) ON DELETE CASCADE, ";
  comando_sql += "FOREIGN KEY(Administrador) REFERENCES Usuario(Email) ON DELETE CASCADE, ";
  comando_sql += "PRIMARY KEY(Nome) );";

  comando_sql += "CREATE TABLE IF NOT EXISTS Termo (";
  comando_sql += "Nome VARCHAR(21) NOT NULL, ";
  comando_sql += "Classe VARCHAR(3) NOT NULL, ";
  comando_sql += "Data VARCHAR(11) NOT NULL, ";
  comando_sql += "Vocabulario VARCHAR(21) NOT NULL, ";
  comando_sql += "FOREIGN KEY(Vocabulario) REFERENCES Vocabulario(Nome) ON DELETE CASCADE, ";
  comando_sql += "PRIMARY KEY(Nome) );";

  comando_sql += "CREATE TABLE IF NOT EXISTS Desenvolvedor_Vocabulario (";
  comando_sql += "Desenvolvedor VARCHAR(100) NOT NULL, ";
  comando_sql += "Vocabulario VARCHAR(21) NOT NULL, ";
  comando_sql += "FOREIGN KEY(Desenvolvedor) REFERENCES Usuario(Email) ON DELETE CASCADE, ";
  comando_sql += "FOREIGN KEY(Vocabulario) REFERENCES Vocabulario(Nome) ON DELETE CASCADE );";

  comando_sql += "CREATE TABLE IF NOT EXISTS Termo_Definicao (";
  comando_sql += "Termo VARCHAR(21) NOT NULL, ";
  comando_sql += "Definicao VARCHAR(31) NOT NULL, ";
  comando_sql += "FOREIGN KEY(Termo) REFERENCES Termo(Nome) ON DELETE CASCADE, ";
  comando_sql += "FOREIGN KEY(Definicao) REFERENCES Definicao(Texto) ON DELETE CASCADE );";
}

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

ComandoSQLRetornoSenha::ComandoSQLRetornoSenha(const Correio_Eletronico &correio_eletronico){
    comando_sql += "SELECT Senha FROM Usuario WHERE Email = ";
    comando_sql += "'" + correio_eletronico.get_correio_eletronico() + "';";
}

string ComandoSQLRetornoSenha::RetornoSenha() const {
    Elemento resultado;
    string senha;

    if(lista_resultado.empty())
        throw invalid_argument("\nLista vazia\n");

    resultado = lista_resultado.back();

    lista_resultado.pop_back();
    senha = resultado.get_valor_coluna();

    lista_resultado.clear();

    return senha;
}

/*----------------------------------------------------------------------------*/

ComandoSQLRetornoEmail::ComandoSQLRetornoEmail(const Correio_Eletronico &correio_eletronico){
    comando_sql += "SELECT Email FROM Usuario WHERE Email = ";
    comando_sql += "'" + correio_eletronico.get_correio_eletronico() + "';";
}

string ComandoSQLRetornoEmail::RetornoEmail() const {
    Elemento resultado;
    string email;

    if(lista_resultado.empty())
        throw invalid_argument("\nLista vazia\n");

    resultado = lista_resultado.back();

    lista_resultado.pop_back();
    email = resultado.get_valor_coluna();

    lista_resultado.clear();

    return email;
}

/*----------------------------------------------------------------------------*/

ComandoSQLRetornoTipo::ComandoSQLRetornoTipo(const Correio_Eletronico &correio_eletronico){
    comando_sql += "SELECT Tipo FROM Usuario WHERE Email = ";
    comando_sql += "'" + correio_eletronico.get_correio_eletronico() + "';";
}

string ComandoSQLRetornoTipo::RetornoTipo() const {
    Elemento resultado;
    string tipo;

    if(lista_resultado.empty())
        throw invalid_argument("\nLista vazia\n");

    resultado = lista_resultado.back();

    lista_resultado.pop_back();
    tipo = resultado.get_valor_coluna();

    lista_resultado.clear();

    return tipo;
}

/*----------------------------------------------------------------------------*/

ComandoSQLPesquisarUsuario::ComandoSQLPesquisarUsuario(const Correio_Eletronico &correio_eletronico){
    comando_sql += "SELECT * FROM Usuario WHERE Email = ";
    comando_sql += "'" + correio_eletronico.get_correio_eletronico() + "';";
}

Leitor ComandoSQLPesquisarUsuario::PesquisarLeitor() const {
    Elemento resultado;
    Leitor leitor;
    Nome nome;
    Sobrenome sobrenome;
    Correio_Eletronico correio_eletronico;
    Senha senha;

    if(lista_resultado.empty())
        throw invalid_argument("\nLista vazia\n");

    resultado = lista_resultado.back();
    lista_resultado.pop_back();

    nome.set_nome(resultado.get_valor_coluna());

    if(lista_resultado.empty())
        throw invalid_argument("\nLista vazia\n");

    resultado = lista_resultado.back();
    lista_resultado.pop_back();

    sobrenome.set_sobrenome(resultado.get_valor_coluna());

    if(lista_resultado.empty())
        throw invalid_argument("\nLista vazia\n");

    resultado = lista_resultado.back();
    lista_resultado.pop_back();

    senha.set_senha(resultado.get_valor_coluna());

    if(lista_resultado.empty())
        throw invalid_argument("\nLista vazia\n");

    resultado = lista_resultado.back();
    lista_resultado.pop_back();

    correio_eletronico.set_correio_eletronico(resultado.get_valor_coluna());

    lista_resultado.clear();

    leitor = Leitor(nome, sobrenome, correio_eletronico, senha);
    return leitor;
}

/*----------------------------------------------------------------------------*/

Desenvolvedor ComandoSQLPesquisarUsuario::PesquisarDesenvolvedor() const {
    Elemento resultado;
    Desenvolvedor desenvolvedor;
    Nome nome;
    Sobrenome sobrenome;
    Correio_Eletronico correio_eletronico;
    Senha senha;
    Data data_nascimento;

    if(lista_resultado.empty())
        throw invalid_argument("\nLista vazia\n");

    resultado = lista_resultado.back();
    lista_resultado.pop_back();

    nome.set_nome(resultado.get_valor_coluna());

    if(lista_resultado.empty())
        throw invalid_argument("\nLista vazia\n");

    resultado = lista_resultado.back();
    lista_resultado.pop_back();

    sobrenome.set_sobrenome(resultado.get_valor_coluna());

    if(lista_resultado.empty())
        throw invalid_argument("\nLista vazia\n");

    resultado = lista_resultado.back();
    lista_resultado.pop_back();

    senha.set_senha(resultado.get_valor_coluna());

    if(lista_resultado.empty())
        throw invalid_argument("\nLista vazia\n");

    resultado = lista_resultado.back();
    lista_resultado.pop_back();

    correio_eletronico.set_correio_eletronico(resultado.get_valor_coluna());

    if(lista_resultado.empty())
        throw invalid_argument("\nLista vazia\n");

    resultado = lista_resultado.back();
    lista_resultado.pop_back();

    data_nascimento.set_data(resultado.get_valor_coluna());

    lista_resultado.clear();

    desenvolvedor = Desenvolvedor(nome, sobrenome, data_nascimento, correio_eletronico, senha);

    return desenvolvedor;

}

/*----------------------------------------------------------------------------*/

Administrador ComandoSQLPesquisarUsuario::PesquisarAdministrador() const {
    Elemento resultado;
    Administrador administrador;
    Nome nome;
    Sobrenome sobrenome;
    Correio_Eletronico correio_eletronico;
    Senha senha;
    Data data_nascimento;
    Telefone telefone;
    Endereco endereco;

    if(lista_resultado.empty())
        throw invalid_argument("\nLista vazia\n");

    resultado = lista_resultado.back();
    lista_resultado.pop_back();

    nome.set_nome(resultado.get_valor_coluna());

    if(lista_resultado.empty())
        throw invalid_argument("\nLista vazia\n");

    resultado = lista_resultado.back();
    lista_resultado.pop_back();

    sobrenome.set_sobrenome(resultado.get_valor_coluna());

    if(lista_resultado.empty())
        throw invalid_argument("\nLista vazia\n");

    resultado = lista_resultado.back();
    lista_resultado.pop_back();

    senha.set_senha(resultado.get_valor_coluna());

    if(lista_resultado.empty())
        throw invalid_argument("\nLista vazia\n");

    resultado = lista_resultado.back();
    lista_resultado.pop_back();

    correio_eletronico.set_correio_eletronico(resultado.get_valor_coluna());

    if(lista_resultado.empty())
        throw invalid_argument("\nLista vazia\n");

    resultado = lista_resultado.back();
    lista_resultado.pop_back();

    data_nascimento.set_data(resultado.get_valor_coluna());

    if(lista_resultado.empty())
        throw invalid_argument("\nLista vazia\n");

    resultado = lista_resultado.back();
    lista_resultado.pop_back();

    telefone.set_telefone(resultado.get_valor_coluna());

    if(lista_resultado.empty())
        throw invalid_argument("\nLista vazia\n");

    resultado = lista_resultado.back();
    lista_resultado.pop_back();

    endereco.set_endereco(resultado.get_valor_coluna());

    lista_resultado.clear();

    administrador = Administrador(nome, sobrenome, telefone, data_nascimento, endereco, correio_eletronico, senha);
    return administrador;
}

/*----------------------------------------------------------------------------*/

ComandoSQLRetornoVocabularios::ComandoSQLRetornoVocabularios() {
    comando_sql += "SELECT Nome, Idioma, Data FROM Vocabulario";
}

vector<VocControlado>ComandoSQLRetornoVocabularios::GetVocabularios() {

    vector<VocControlado> voc_controlados;
    VocControlado aux;
    Nome nome;
    Idioma idioma;
    Data data;
    Elemento resultado;

    int QUANTIDADE_VOCABULARIOS = lista_resultado.size()/QUANTIDADE_COLUNAS;

    if(lista_resultado.empty()) {
        throw("Vocabularios nao encontrados");
    } else {
        for(int i = 0; i < QUANTIDADE_VOCABULARIOS; i++) {

            resultado = lista_resultado.back();
            lista_resultado.pop_back();
            aux.set_nome(nome.set_nome(resultado.get_valor_coluna()));

            resultado = lista_resultado.back();
            lista_resultado.pop_back();
            aux.set_idioma(idioma.set_idioma(resultado.get_valor_coluna()));

            resultado = lista_resultado.back();
            lista_resultado.pop_back();
            aux.set_data(data.set_data(resultado.get_nome_coluna()));

            voc_controlados.push_back(aux);
        }
    }

    lista_resultado.clear();
    return voc_controlados;
}

ComandoSQLRetornoTermos::ComandoSQLRetornoTermos(const VocControlado &voc_controlado) {
    comando_sql += "SELECT Nome, Classe, Data FROM Termo WHERE Vocabulario = ";
    comando_sql += "'" + voc_controlado.get_nome().get_nome() + "';";
}

vector<Termo> ComandoSQLRetornoTermos::GetTermos() {
    vector<Termo> termos;
    Termo aux;
    Nome nome;
    Classe_Termo classe_termo;
    Data data;
    Elemento resultado;

    int QUANTIDADE_TERMOS = lista_resultado.size()/QUANTIDADE_COLUNAS;

    if(lista_resultado.empty()){
        throw("Termos nao encontrados para este vocabulario");
    } else {
        for(int i = 0; i < QUANTIDADE_TERMOS; i++) {
            resultado = lista_resultado.back();
            lista_resultado.pop_back();
            aux.set_nome(nome.set_nome(resultado.get_valor_coluna()));

            resultado = lista_resultado.back();
            lista_resultado.pop_back();
            aux.get_classe_termo(classe_termo.set_classe_termo(resultado.get_valor_coluna()));

            resultado = lista_resultado.back();
            lista_resultado.pop_back();
            aux.set_data(data.set_data(resultado.get_nome_coluna()));

            termos.push_back(aux);
        }
    }

    lista_resultado.clear();
    return termos;
}
