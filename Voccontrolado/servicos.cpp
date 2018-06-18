#include "servicos.hpp"

/*-----------------------------------------------------------------------------------------------------*/

Resultado ServicoCadastroControle::CadastroLeitor(const Nome &nome, const Sobrenome &sobrenome,
                                                  const Correio_Eletronico &correio_eletronico,
                                                  const Senha &senha) throw (invalid_argument){
    Resultado resultado;
    Leitor leitor;

    leitor = Leitor(nome, sobrenome, correio_eletronico, senha);

    if(leitor.get_nome().get_nome() != nome.get_nome()){
        resultado.set_resultado(Resultado::FALHA);
        throw invalid_argument("Nome nao setado com sucesso");
    }

    if(leitor.get_sobrenome().get_sobrenome() != sobrenome.get_sobrenome()){
        resultado.set_resultado(Resultado::FALHA);
        throw invalid_argument("Sobrenome nao setado com sucesso");
    }

    if(leitor.get_correio_eletronico().get_correio_eletronico() != correio_eletronico.get_correio_eletronico()){
        resultado.set_resultado(Resultado::FALHA);
        throw invalid_argument("Email nao setado com sucesso");
    }

    if(leitor.get_senha().get_senha() != senha.get_senha()){
        resultado.set_resultado(Resultado::FALHA);
        throw invalid_argument("Senha nao setado com sucesso");
    }

    ComandoSQLCadastrar comandoSQLCadastrar(leitor, "Leitor");
    comandoSQLCadastrar.Executar();

    resultado.set_resultado(Resultado::SUCESSO);

    return resultado;
}

/*-----------------------------------------------------------------------------------------------------*/

Resultado ServicoCadastroControle::CadastroDesenvolvedor(const Nome &nome, const Sobrenome &sobrenome,
                                                         const Data &data_nascimento,
                                                         const Correio_Eletronico &correio_eletronico,
                                                         const Senha &senha) throw (invalid_argument){

    Resultado resultado;
    Desenvolvedor desenvolvedor;

    desenvolvedor = Desenvolvedor(nome, sobrenome, data_nascimento, correio_eletronico, senha);

    if(desenvolvedor.get_nome().get_nome() != nome.get_nome()){
        resultado.set_resultado(Resultado::FALHA);
        throw invalid_argument("Nome nao setado com sucesso");
    }

    if(desenvolvedor.get_sobrenome().get_sobrenome() != sobrenome.get_sobrenome()){
        resultado.set_resultado(Resultado::FALHA);
        throw invalid_argument("Sobrenome nao setado com sucesso");
    }

    if(desenvolvedor.get_data().get_data() != data_nascimento.get_data()){
        resultado.set_resultado(Resultado::FALHA);
        throw invalid_argument("Data de nascimento nao setado com sucesso");
    }

    if(desenvolvedor.get_correio_eletronico().get_correio_eletronico() != correio_eletronico.get_correio_eletronico()){
        resultado.set_resultado(Resultado::FALHA);
        throw invalid_argument("Email nao setado com sucesso");
    }

    if(desenvolvedor.get_senha().get_senha() != senha.get_senha()){
        resultado.set_resultado(Resultado::FALHA);
        throw invalid_argument("Senha nao setado com sucesso");
    }

    ComandoSQLCadastrar comandoSQLCadastrar(desenvolvedor, "Desenvolvedor");
    comandoSQLCadastrar.Executar();

    resultado.set_resultado(Resultado::SUCESSO);

    return resultado;
}

/*-----------------------------------------------------------------------------------------------------*/

Resultado ServicoCadastroControle::CadastroAdministrador(const Nome &nome, const Sobrenome &sobrenome,
                                                         const Telefone &telefone, const Data &data_nascimento,
                                                         const Endereco &endereco, const Correio_Eletronico &correio_eletronico,
                                                         const Senha &senha) throw (invalid_argument){
    Resultado resultado;
    Administrador administrador;

    administrador = Administrador(nome, sobrenome, telefone, data_nascimento, endereco, correio_eletronico, senha);
    //colocar os ifs

    ComandoSQLCadastrar comandoSQLCadastrar(administrador, "Administrador");
    comandoSQLCadastrar.Executar();

    resultado.set_resultado(Resultado::SUCESSO);

    return resultado;
}

/*-----------------------------------------------------------------------------------------------------*/

ResultadoUsuario ServicoAutenticacaoControle::Autenticar(const Correio_Eletronico &correio_eletronico, const Senha &senha) throw (invalid_argument){
    ResultadoUsuario resultado;
    string senha_db;

    try{
        ComandoSQLRetornoEmail comandoSQLRetornoEmail(correio_eletronico);
        comandoSQLRetornoEmail.Executar();
        string email = comandoSQLRetornoEmail.RetornoEmail();

    } catch (invalid_argument &exp) {
        cout << "\nEmail ou senha invalidos.\n";
        cout << "Pressione qualquer tecla para continuar: ";
        resultado.set_resultado(Resultado::FALHA);
        fflush(stdin);
        getchar();
        return resultado;
    }

    try{
        ComandoSQLRetornoSenha comandoSQLRetornoSenha(correio_eletronico);
        comandoSQLRetornoSenha.Executar();
        senha_db = comandoSQLRetornoSenha.RetornoSenha();

    } catch (invalid_argument &exp) {
        cout << "\nEmail ou senha invalidos.\n";
        cout << "Pressione qualquer tecla para continuar: ";
        resultado.set_resultado(Resultado::FALHA);
        fflush(stdin);
        getchar();
        return resultado;
    }

    if(senha_db == senha.get_senha()){
        resultado.set_correio_eletronico(correio_eletronico);
        resultado.set_resultado(Resultado::SUCESSO);
    } else {
        cout << "\nEmail ou senha invalidos.\n";
        cout << "Pressione qualquer tecla para continuar: ";
        resultado.set_resultado(Resultado::FALHA);
        fflush(stdin);
        getchar();
    }

    ComandoSQLRetornoTipo comandoSQLRetornoTipo(correio_eletronico);
    comandoSQLRetornoTipo.Executar();
    string tipo = comandoSQLRetornoTipo.RetornoTipo();

    ComandoSQLPesquisarUsuario comandoSQLPesquisarUsuario(correio_eletronico);
    comandoSQLPesquisarUsuario.Executar();

    if(tipo == "Leitor"){

        resultado.tipo_de_usuario = ResultadoUsuario::LEITOR;
        Leitor leitor = comandoSQLPesquisarUsuario.PesquisarLeitor();
        resultado.set_leitor(leitor);
    } else if(tipo == "Desenvolvedor"){

        resultado.tipo_de_usuario = ResultadoUsuario::DESENVOLVEDOR;
        Desenvolvedor desenvolvedor = comandoSQLPesquisarUsuario.PesquisarDesenvolvedor();
        resultado.set_desenvolvedor(desenvolvedor);
    } else if(tipo == "Administrador"){

        resultado.tipo_de_usuario = ResultadoUsuario::ADMINISTRADOR;
        Administrador administrador = comandoSQLPesquisarUsuario.PesquisarAdministrador();
        resultado.set_administrador(administrador);
    }
    return resultado;
}

/*-----------------------------------------------------------------------------------------------------*/

ResultadoUsuario ServicoAutenticacaoControle::TipoDeUsuario(const Correio_Eletronico&, const Senha&){ //Retirar essa funcao
    ResultadoUsuario resultado;
    return resultado;
}

/*-----------------------------------------------------------------------------------------------------*/

void ServicoUsuarioControle::Exibir(const Leitor &leitor) throw (invalid_argument){
    cout << endl << "Nome: " << leitor.get_nome().get_nome() << endl;
    cout << "Sobrenome: " << leitor.get_sobrenome().get_sobrenome() << endl;
    cout << "Email: " << leitor.get_correio_eletronico().get_correio_eletronico() << endl;
    cout << "Senha: " << leitor.get_senha().get_senha() << endl;
    cout << endl << "Pressione qualquer tecla para continuar: ";
    fflush(stdin);
    getchar();
}

void ServicoUsuarioControle::Exibir(const Desenvolvedor &desenvolvedor) throw (invalid_argument){
    cout << endl << "Nome: " << desenvolvedor.get_nome().get_nome() << endl;
    cout << "Sobrenome: " << desenvolvedor.get_sobrenome().get_sobrenome() << endl;
    cout << "Email: " << desenvolvedor.get_correio_eletronico().get_correio_eletronico() << endl;
    cout << "Data de nascimento: " << desenvolvedor.get_data().get_data() << endl;
    cout << endl << "Pressione qualquer tecla para continuar: ";
    fflush(stdin);
    getchar();
}

void ServicoUsuarioControle::Exibir(const Administrador &administrador) throw (invalid_argument){
    cout << endl << "Nome: " << administrador.get_nome().get_nome() << endl;
    cout << "Sobrenome: " << administrador.get_sobrenome().get_sobrenome() << endl;
    cout << "Email: " << administrador.get_correio_eletronico().get_correio_eletronico() << endl;
    cout << "Senha: " << administrador.get_senha().get_senha() << endl;
    cout << "Data de nascimento: " << administrador.get_data().get_data() << endl;
    cout << "Telefone: " << administrador.get_telefone().get_telefone() << endl;
    cout << "Endereco: " << administrador.get_endereco().get_endereco() << endl;
    cout << endl << "Pressione qualquer tecla para continuar: ";
    fflush(stdin);
    getchar();
}

/*-----------------------------------------------------------------------------------------------------*/

Resultado ServicoVocabulariosControle::CriaVocabulario(const ResultadoUsuario &resultado_usuario) throw(invalid_argument) {
    Resultado resultado;
    Definicao definicao;
    Nome nome;
    Idioma idioma;
    Data data;
    Texto_Definicao texto_definicao;
    string input;

    try{
        cout << "\nDigite o nome do vocabulario: ";
        cin >> input;
        nome.set_nome(input);

        cout << "\nDigite o idioma: ";
        cin >> input;
        idioma.set_idioma(input);

        cout << "\nDigite a data: ";
        cin >> input;
        data.set_data(input);

        VocControlado voc_controlado(nome, idioma, data);

        cout << "\nDigite a data da definicao do Vocabulario: ";
        cin >> input;
        data.set_data(input);

        cout << "\nDigite o texto da definicao: ";
        cin.clear();    //Limpar o cin pra poder pegar o input de maneira correta
        cin.ignore();
        getline(cin, input);
        texto_definicao.set_texto_definicao(input);

        definicao = Definicao(texto_definicao, data);

        ComandoSQLRegistraDefinicao ComandoSQLRegistraDefinicao(definicao);
        ComandoSQLRegistraDefinicao.Executar();

        ComandoSQLRegistraVocabulario ComandoSQLRegistraVocabulario(voc_controlado, definicao, resultado_usuario.get_administrador());
        ComandoSQLRegistraVocabulario.Executar();


    } catch (invalid_argument &exp) {
        cout << "\n" << exp.what() << endl;
        cout << "Pressione qualquer tecla para continuar: ";
        fflush(stdin);
        getchar();
        resultado.set_resultado(Resultado::FALHA);
        return resultado;
    }

    resultado.set_resultado(Resultado::SUCESSO);
    return resultado;
}
