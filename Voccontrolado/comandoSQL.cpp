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
  comando_sql += "Tipo VARCHAR(30) NOT NULL, ";
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
  comando_sql += "FOREIGN KEY(Definicao) REFERENCES Definicao(Texto), ";
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
    cout << comando_sql;
    system("pause");
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

    for (int i = 0; i < argc; i++) {
        elemento.set_nome_coluna(nome_coluna[i]);
        if (valor_coluna[i] != nullptr) {
            elemento.set_valor_coluna(valor_coluna[i]);
        } else {
            continue;
        }
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


  if (lista_resultado.empty()) {
    throw invalid_argument("\nLista Vazia\n");
  }
  resultado = lista_resultado.back();
  lista_resultado.pop_back();
  nome.set_nome(resultado.get_valor_coluna());
  leitor.set_nome(nome);

  if (lista_resultado.empty()) {
    throw invalid_argument("\nLista Vazia\n");
  }
  resultado = lista_resultado.back();
  lista_resultado.pop_back();
  sobrenome.set_sobrenome(resultado.get_valor_coluna());
  leitor.set_sobrenome(sobrenome);

  if (lista_resultado.empty()) {
    throw invalid_argument("\nLista Vazia\n");
  }
  resultado = lista_resultado.back();
  lista_resultado.pop_back();
  senha.set_senha(resultado.get_valor_coluna());
  leitor.set_senha(senha);

  if (lista_resultado.empty()) {
    throw invalid_argument("\nLista Vazia\n");
  }
  resultado = lista_resultado.back();
  lista_resultado.pop_back();
  correio_eletronico.set_correio_eletronico(resultado.get_valor_coluna());
  leitor.set_correio_eletronico(correio_eletronico);

  lista_resultado.clear();

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
ComandoSQLExcluir::ComandoSQLExcluir(const Correio_Eletronico &correio_eletronico){
    comando_sql += "DELETE FROM Usuario WHERE Email = ";
    comando_sql += "'" + correio_eletronico.get_correio_eletronico() + "';";
}

/*----------------------------------------------------------------------------*/

ComandoSQLEditar::ComandoSQLEditar(const Leitor &leitor){
    comando_sql = "UPDATE Usuario ";
    comando_sql += "SET Nome = '" + leitor.get_nome().get_nome();
    comando_sql += "', Sobrenome = '" + leitor.get_sobrenome().get_sobrenome();
    comando_sql += "', Senha = '" + leitor.get_senha().get_senha();
    comando_sql += "' WHERE Email = '" + leitor.get_correio_eletronico().get_correio_eletronico() + "';";
}

ComandoSQLEditar::ComandoSQLEditar(const Desenvolvedor &desenvolvedor){
    comando_sql = "UPDATE Usuario ";
    comando_sql += "SET Nome = '" + desenvolvedor.get_nome().get_nome();
    comando_sql += "', Sobrenome = '" + desenvolvedor.get_sobrenome().get_sobrenome();
    comando_sql += "', Senha = '" + desenvolvedor.get_senha().get_senha();
    comando_sql += "', Data = '" + desenvolvedor.get_data().get_data();
    comando_sql += "' WHERE Email = '" + desenvolvedor.get_correio_eletronico().get_correio_eletronico() + "';";
}

ComandoSQLEditar::ComandoSQLEditar(const Administrador &administrador){
    comando_sql = "UPDATE Usuario ";
    comando_sql += "SET Nome = '" + administrador.get_nome().get_nome();
    comando_sql += "', Sobrenome = '" + administrador.get_sobrenome().get_sobrenome();
    comando_sql += "', Senha = '" + administrador.get_senha().get_senha();
    comando_sql += "', Data = '" + administrador.get_data().get_data();
    comando_sql += "', Telefone = '" + administrador.get_telefone().get_telefone();
    comando_sql += "', Endereco = '" + administrador.get_endereco().get_endereco();
    comando_sql += "' WHERE Email = '" + administrador.get_correio_eletronico().get_correio_eletronico() + "';";
}
/*----------------------------------------------------------------------------*/

ComandoSQLRegistraDefinicao::ComandoSQLRegistraDefinicao(const Definicao &definicao){
    comando_sql += "INSERT or IGNORE INTO Definicao (Texto, Data) VALUES (";
    comando_sql += "'" + definicao.get_texto_definicao().get_texto_definicao() + "',";
    comando_sql += "'" + definicao.get_data().get_data() + "');";
}

ComandoSQLRegistraVocabulario::ComandoSQLRegistraVocabulario(const VocControlado &voc_controlado,const Definicao &definicao,
                                                             const Administrador &admistrador) {
    comando_sql += "INSERT or IGNORE INTO Vocabulario (Nome, Idioma, Data, Definicao, Administrador) VALUES (";
    comando_sql += "'" + voc_controlado.get_nome().get_nome() +  "',";
    comando_sql += "'" + voc_controlado.get_idioma().get_idioma() + "',";
    comando_sql += "'" + voc_controlado.get_data().get_data() + "',";
    comando_sql += "'" + definicao.get_texto_definicao().get_texto_definicao() + "',";
    comando_sql += "'" + admistrador.get_correio_eletronico().get_correio_eletronico() + "');";
}

ComandoSQLRegistraTermo::ComandoSQLRegistraTermo(const Termo &termo, string nome_voc) {
    comando_sql += "INSERT or IGNORE INTO Termo (Nome, Classe, Data, Vocabulario) VALUES (";
    comando_sql += "'" + termo.get_nome().get_nome() + "',";
    comando_sql += "'" + termo.get_classe_termo().get_classe_termo() + "',";
    comando_sql += "'" + termo.get_data().get_data() + "',";
    comando_sql += "'" + nome_voc + "');";
}

ComandoSQLRetornoVocabularios::ComandoSQLRetornoVocabularios() {
    comando_sql += "SELECT Nome, Idioma, Data FROM Vocabulario";
}

vector<VocControlado> ComandoSQLRetornoVocabularios::get_vocabularios() {

    vector<VocControlado> voc_controlados;
    Nome nome;
    Idioma idioma;
    Data data;
    Elemento resultado;

    if((lista_resultado.size() % QUANTIDADE_COLUNAS) != 0) {
        cout <<"\nErro de consistencia no retorno do banco de dados\n";
        return voc_controlados;
    }

    int QUANTIDADE_VOCABULARIOS = lista_resultado.size()/QUANTIDADE_COLUNAS;

    if(lista_resultado.empty()) {
        cout << "\nVocabularios nao encontrados\n";
        return voc_controlados;
    } else {
        for(int i = 0; i < QUANTIDADE_VOCABULARIOS; i++) {
            resultado = lista_resultado.back();
            lista_resultado.pop_back();
            nome.set_nome(resultado.get_valor_coluna());

            resultado = lista_resultado.back();
            lista_resultado.pop_back();
            idioma.set_idioma(resultado.get_valor_coluna());

            resultado = lista_resultado.back();
            lista_resultado.pop_back();
            data.set_data(resultado.get_valor_coluna());

            VocControlado aux(nome, idioma, data);

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

vector<Termo> ComandoSQLRetornoTermos::get_termos(){
    vector<Termo> termos;
    Nome nome;
    Classe_Termo classe_termo;
    Data data;
    Elemento resultado;



    if((lista_resultado.size() % QUANTIDADE_COLUNAS) != 0) {
        cout << "\nErro de consistencia no retorno do banco de dados\n";
        return termos;
    }


    int QUANTIDADE_TERMOS = lista_resultado.size()/QUANTIDADE_COLUNAS;

    if(lista_resultado.empty()){
        cout <<"\nNao ha termos\n";
        return termos;
    } else {
        for(int i = 0; i < QUANTIDADE_TERMOS; i++) {
            resultado = lista_resultado.back();
            lista_resultado.pop_back();
            nome.set_nome(resultado.get_valor_coluna());

            resultado = lista_resultado.back();
            lista_resultado.pop_back();
            classe_termo.set_classe_termo(resultado.get_valor_coluna());

            resultado = lista_resultado.back();
            lista_resultado.pop_back();
            data.set_data(resultado.get_valor_coluna());

            Termo aux(nome, classe_termo, data);

            termos.push_back(aux);
        }
    }

    lista_resultado.clear();
    return termos;
}

ComandoSQLRetornoDefinicoesVoc::ComandoSQLRetornoDefinicoesVoc(const VocControlado &voc_controlado) {
    comando_sql += "SELECT Texto, Data FROM Definicao WHERE Texto = (SELECT Definicao FROM Vocabulario WHERE Nome = ";
    comando_sql += "'" + voc_controlado.get_nome().get_nome() + "');";
}

Definicao ComandoSQLRetornoDefinicoesVoc::get_definicao() {
    Texto_Definicao texto;
    Data data;
    Elemento resultado;
    Definicao definicao_vazia;

    if((lista_resultado.size() % QUANTIDADE_COLUNAS) != 0) {
        cout << "\nErro de consistencia no retorno do banco de dados\n";
        return definicao_vazia;
    }

    if(lista_resultado.empty()) {
        cout << "\nDefinicao nao encontrada\n";
        return definicao_vazia;
    } else {
        resultado = lista_resultado.back();
        lista_resultado.pop_back();
        texto.set_texto_definicao(resultado.get_valor_coluna());

        resultado = lista_resultado.back();
        lista_resultado.pop_back();
        data.set_data(resultado.get_valor_coluna());

        Definicao definicao(texto, data);

        lista_resultado.clear();
        return definicao;
    }
}

ComandoSQLExcluirVocabulario::ComandoSQLExcluirVocabulario(const VocControlado &voc_controlado) {
    comando_sql += "DELETE FROM Definicao WHERE Texto = ";
    comando_sql += "(SELECT Definicao FROM Vocabulario WHERE Nome =";
    comando_sql += "'" + voc_controlado.get_nome().get_nome() + "');";
    comando_sql += "DELETE FROM Vocabulario WHERE Nome = ";
    comando_sql += "'" + voc_controlado.get_nome().get_nome() + "';";
}

ComandoSQLExcluirTermo::ComandoSQLExcluirTermo(const Termo &termo){
    comando_sql += "DELETE FROM Termo WHERE Nome = ";
    comando_sql += "'" + termo.get_nome().get_nome() + "';";
}

ComandoSQLEditarDefinicaoVocabulario::ComandoSQLEditarDefinicaoVocabulario(string voc, const Definicao &definicao) {
    comando_sql += "UPDATE Definicao ";
    comando_sql += "SET Texto = '" + definicao.get_texto_definicao().get_texto_definicao() + "',";
    comando_sql += "Data = '" + definicao.get_data().get_data() + "'";
    comando_sql += "WHERE Texto = ";
    comando_sql += "(SELECT Definicao FROM Vocabulario WHERE Nome =";
    comando_sql += "'" + voc + "');";
}

ComandoSQLAlterarIdiomaVoc::ComandoSQLAlterarIdiomaVoc(const VocControlado &voc_controlado) {
    comando_sql += "UPDATE Vocabulario ";
    comando_sql += "SET Idioma = '" + voc_controlado.get_idioma().get_idioma() + "'";
    comando_sql += "WHERE Nome = '" + voc_controlado.get_nome().get_nome() + "';";
}

ComandoSQLCadastraDevenvolvedor::ComandoSQLCadastraDevenvolvedor(string voc, string correio_eletronico) {
    comando_sql += "INSERT or IGNORE INTO Desenvolvedor_Vocabulario(Desenvolvedor, Vocabulario) VALUES (";
    comando_sql += "'" + correio_eletronico + "',";
    comando_sql += "'" + voc + "');";
}

ComandoRetornaDesenvolvedor_Vocabulario::ComandoRetornaDesenvolvedor_Vocabulario(string voc){
    comando_sql += "SELECT Desenvolvedor FROM Desenvolvedor_Vocabulario WHERE Vocabulario = ";
    comando_sql += "'" + voc + "';";
}

ComandoRetornaDesenvolvedor_Vocabulario::get_quantidade_desenvolvedores() {
    int tamanho;
    tamanho = lista_resultado.size();
    lista_resultado.clear();
    return tamanho;
}

vector<string> ComandoRetornaDesenvolvedor_Vocabulario::get_desenvolvedores() {
    vector<string> desenvolvedores;
    Elemento resultado;


    int QUANTIDADE_TERMOS = lista_resultado.size();

    if(lista_resultado.empty()){
        cout <<"\nNao ha desenvolvedores\n";
        return desenvolvedores;
    } else {
        for(int i = 0; i < QUANTIDADE_TERMOS; i++) {
            resultado = lista_resultado.back();
            lista_resultado.pop_back();
            desenvolvedores.push_back(resultado.get_valor_coluna());
        }
    }

    lista_resultado.clear();
    return desenvolvedores;
}

ComandoSQLLinkaDefinicao_Termo::ComandoSQLLinkaDefinicao_Termo(string texto_definicao, string nome_termo) {
    comando_sql += "INSERT or IGNORE INTO Termo_Definicao(Termo, Definicao) VALUES (";
    comando_sql += "'" + nome_termo + "',";
    comando_sql += "'" + texto_definicao + "');";
}

ComandoSQLRetornaDefinicao_Termo::ComandoSQLRetornaDefinicao_Termo(string termo) {
    comando_sql += "SELECT Definicao FROM Termo_Definicao WHERE Termo = ";
    comando_sql += "'" + termo + "';";
}

int ComandoSQLRetornaDefinicao_Termo::get_quantidade_definicoes() {
    int tamanho;
    tamanho = lista_resultado.size();
    lista_resultado.clear();
    return tamanho;
}

vector<string> ComandoSQLRetornaDefinicao_Termo::get_definicoes() {
    vector<string> definicoes;
    Elemento resultado;


    int QUANTIDADE_TERMOS = lista_resultado.size();

    if(lista_resultado.empty()){
        cout <<"\nNao ha definicoes\n";
        return definicoes;
    } else {
        for(int i = 0; i < QUANTIDADE_TERMOS; i++) {
            resultado = lista_resultado.back();
            lista_resultado.pop_back();
            definicoes.push_back(resultado.get_valor_coluna());
        }
    }

    lista_resultado.clear();
    return definicoes;
}

ComandoSQLRetornaDefinicoesTermo::ComandoSQLRetornaDefinicoesTermo(string texto_definicao){
    comando_sql += "SELECT Texto, Data FROM Definicao WHERE Texto = ";
    comando_sql += "'" + texto_definicao + "';";
}

Definicao ComandoSQLRetornaDefinicoesTermo::get_definicao() {
    Texto_Definicao texto;
    Data data;
    Elemento resultado;
    Definicao definicao_vazia;

    if((lista_resultado.size() % QUANTIDADE_COLUNAS) != 0) {
        cout << "\nErro de consistencia no retorno do banco de dados\n";
        return definicao_vazia;
    }

    if(lista_resultado.empty()) {
        cout << "\nDefinicao nao encontrada\n";
        return definicao_vazia;
    } else {
        resultado = lista_resultado.back();
        lista_resultado.pop_back();
        texto.set_texto_definicao(resultado.get_valor_coluna());

        resultado = lista_resultado.back();
        lista_resultado.pop_back();
        data.set_data(resultado.get_valor_coluna());

        Definicao definicao(texto, data);

        lista_resultado.clear();
        return definicao;
    }
}

ComandoSQLEditarTermo::ComandoSQLEditarTermo(const Termo &termo, string nome_termo) {
    comando_sql += "UPDATE Termo ";
    comando_sql += "SET Nome = '" + termo.get_nome().get_nome() + "',";
    comando_sql += "Data = '" + termo.get_data().get_data() + "'";
    comando_sql += "WHERE Nome = '" + nome_termo + "';";
    comando_sql += "UPDATE Termo_Definicao ";
    comando_sql += "SET Termo = '" + termo.get_nome().get_nome() + "'";
    comando_sql += "WHERE Termo = '" + nome_termo + "';";
}

ComandoSQLEditarDeficaoTermo::ComandoSQLEditarDeficaoTermo(const Definicao &definicao, string texto_definicao_anterior) {
     comando_sql += "UPDATE Definicao ";
    comando_sql += "SET Texto = '" + definicao.get_texto_definicao().get_texto_definicao() + "',";
    comando_sql += "Data = '" + definicao.get_data().get_data() + "'";
    comando_sql += "WHERE Texto = '" + texto_definicao_anterior + "';";
    comando_sql += "UPDATE Termo_Definicao ";
    comando_sql += "SET Definicao = '" + definicao.get_texto_definicao().get_texto_definicao() + "'";
    comando_sql += "WHERE Definicao = '" + texto_definicao_anterior + "';";
}

ComandoSQLRetornaAdministradorVoc::ComandoSQLRetornaAdministradorVoc(string voc) {
    comando_sql += "SELECT Administrador FROM Vocabulario WHERE Nome = '";
    comando_sql += voc + "';";
}

string ComandoSQLRetornaAdministradorVoc::get_administrador(){
    string administrador;
    Elemento resultado;

    if(lista_resultado.empty()) {
        cout << "\nAdministrador nao encontrado\n";
        return administrador;
    } else {
        resultado = lista_resultado.back();
        lista_resultado.pop_back();
        administrador = resultado.get_valor_coluna();

        lista_resultado.clear();
        return administrador;
    }
}
