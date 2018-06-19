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

Resultado ServicoUsuarioControle::Excluir(const Correio_Eletronico &correio_eletronico) throw (invalid_argument){
    Resultado resultado;
    string input;
    Senha senha;
    string senha_db;

    system(CLEAR);
    cout << "Digite sua senha para confirmar a exclusao: ";
    try{
        cin >> input;
        senha.set_senha(input);
        ComandoSQLRetornoSenha comandoSQLRetornoSenha(correio_eletronico);
        comandoSQLRetornoSenha.Executar();
        senha_db = comandoSQLRetornoSenha.RetornoSenha();

        if(senha.get_senha() == senha_db){
            resultado.set_resultado(Resultado::SUCESSO);
        } else {
            resultado.set_resultado(Resultado::FALHA);
        }

    } catch (invalid_argument &exp) {
        cout << endl << exp.what() << endl;
        resultado.set_resultado(Resultado::FALHA);
        fflush(stdin);
        getchar();
    }

    if(resultado.get_resultado() == Resultado::FALHA){
        cout << endl << "Senha incorreta." << endl;
        fflush(stdin);
        getchar();
        return resultado;
    }

    try{
        ComandoSQLExcluir comandoSQLExcluir(correio_eletronico);
        comandoSQLExcluir.Executar();

    } catch (invalid_argument &exp) {
        cout << endl << exp.what() << endl;
        resultado.set_resultado(Resultado::FALHA);
        fflush(stdin);
        getchar();
        return resultado;
    }

    resultado.set_resultado(Resultado::SUCESSO);
    return resultado;
}

/*-----------------------------------------------------------------------------------------------------*/

ResultadoUsuario ServicoUsuarioControle::EditarLeitor(const Correio_Eletronico &correio_eletronico) throw (invalid_argument) {
    ResultadoUsuario resultado;
    Leitor leitor;
    string input;
    Nome nome;
    Sobrenome sobrenome;
    Senha senha;

    try{
        system(CLEAR);
        cout << "Digite seu nome: ";
        cin >> input;
        nome.set_nome(input);

        cout << endl << "Digite seu sobrenome: ";
        cin >> input;
        sobrenome.set_sobrenome(input);

        cout << endl << "Digite sua senha: ";
        cin >> input;
        senha.set_senha(input);

    } catch (invalid_argument &exp) {
        cout << endl << exp.what() << endl;
        resultado.set_resultado(Resultado::FALHA);
        fflush(stdin);
        getchar();
        return resultado;
    }

    try{
        leitor = Leitor(nome, sobrenome, correio_eletronico, senha);

    } catch (invalid_argument &exp) {
        cout << endl << exp.what() << endl;
        resultado.set_resultado(Resultado::FALHA);
        fflush(stdin);
        getchar();
        return resultado;
    }
    resultado.set_resultado(Resultado::SUCESSO);
    resultado.set_leitor(leitor);
    return resultado;
}

/*-----------------------------------------------------------------------------------------------------*/

ResultadoUsuario ServicoUsuarioControle::EditarDesenvolvedor(const Correio_Eletronico &correio_eletronico) throw (invalid_argument) {
    ResultadoUsuario resultado;
    Desenvolvedor desenvolvedor;
    string input;
    Nome nome;
    Sobrenome sobrenome;
    Data data_nascimento;
    Senha senha;

    try{
        system(CLEAR);
        cout << "Digite seu nome: ";
        cin >> input;
        nome.set_nome(input);

        cout << endl << "Digite seu sobrenome: ";
        cin >> input;
        sobrenome.set_sobrenome(input);

        cout << endl << "Digite sua data de nascimento: ";
        cin >> input;
        data_nascimento.set_data(input);

        cout << endl << "Digite sua senha: ";
        cin >> input;
        senha.set_senha(input);

    } catch (invalid_argument &exp) {
        cout << endl << exp.what() << endl;
        resultado.set_resultado(Resultado::FALHA);
        fflush(stdin);
        getchar();
        return resultado;
    }

    try{
        desenvolvedor = Desenvolvedor(nome, sobrenome, data_nascimento, correio_eletronico, senha);

    } catch (invalid_argument &exp) {
        cout << endl << exp.what() << endl;
        resultado.set_resultado(Resultado::FALHA);
        fflush(stdin);
        getchar();
        return resultado;
    }

    resultado.set_desenvolvedor(desenvolvedor);
    resultado.set_resultado(Resultado::SUCESSO);
    return resultado;
}

/*-----------------------------------------------------------------------------------------------------*/

ResultadoUsuario ServicoUsuarioControle::EditarAdministrador(const Correio_Eletronico &correio_eletronico) throw (invalid_argument) {
    ResultadoUsuario resultado;
    Administrador administrador;
    string input;
    Nome nome;
    Sobrenome sobrenome;
    Telefone telefone;
    Data data_nascimento;
    Endereco endereco;
    Senha senha;

    try{
        system(CLEAR);
        cout << "Digite seu nome: ";
        cin >> input;
        nome.set_nome(input);

        cout << endl << "Digite seu sobrenome: ";
        cin >> input;
        sobrenome.set_sobrenome(input);

        cout << endl << "Digite seu telefone: ";
        cin.clear();
        cin.ignore();
        getline(cin, input);
        telefone.set_telefone(input);

        cout << endl << "Digite sua data de nascimento: ";
        cin >> input;
        data_nascimento.set_data(input);

        cout << endl << "Digite seu endereco: ";
        cin.clear();
        cin.ignore();
        getline(cin, input);
        endereco.set_endereco(input);

        cout << endl << "Digite sua senha: ";
        cin >> input;
        senha.set_senha(input);

    } catch (invalid_argument &exp) {
        cout << endl << exp.what() << endl;
        resultado.set_resultado(Resultado::FALHA);
        fflush(stdin);
        getchar();
        return resultado;
    }

    try{
        administrador = Administrador(nome, sobrenome, telefone, data_nascimento, endereco, correio_eletronico, senha);

    } catch (invalid_argument &exp) {
        cout << endl << exp.what() << endl;
        resultado.set_resultado(Resultado::FALHA);
        fflush(stdin);
        getchar();
        return resultado;
    }

    resultado.set_administrador(administrador);
    resultado.set_resultado(Resultado::SUCESSO);
    return resultado;
}

ResultadoUsuario ServicoUsuarioControle::Editar(const Leitor &leitor) throw (invalid_argument) {
    ResultadoUsuario resultado;
    resultado = EditarLeitor(leitor.get_correio_eletronico());
    return resultado;
}

ResultadoUsuario ServicoUsuarioControle::Editar(const Desenvolvedor &desenvolvedor) throw (invalid_argument) {
    ResultadoUsuario resultado;
    resultado = EditarDesenvolvedor(desenvolvedor.get_correio_eletronico());
    return resultado;
}

ResultadoUsuario ServicoUsuarioControle::Editar(const Administrador &administrador) throw (invalid_argument) {
    ResultadoUsuario resultado;
    resultado = EditarAdministrador(administrador.get_correio_eletronico());
    return resultado;
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

vector<VocControlado> ServicoVocabulariosControle::ListaVocabulario() {

    vector<VocControlado> voc_controlados;
    ComandoSQLRetornoVocabularios retorno_vocabulario;
    retorno_vocabulario = ComandoSQLRetornoVocabularios();
    retorno_vocabulario.Executar();

    voc_controlados = retorno_vocabulario.get_vocabularios();

    return voc_controlados;

}

void ServicoVocabulariosControle::ConsultarVocabulario(const VocControlado &voc_controlado) throw(invalid_argument){

    Definicao definicao;

    cout<< "\nidioma:" << voc_controlado.get_idioma().get_idioma();
    cout<< "\ndata:" << voc_controlado.get_data().get_data();

    ComandoSQLRetornoDefinicoesVoc retorno_definicoes_voc(voc_controlado);
    retorno_definicoes_voc.Executar();
    definicao = retorno_definicoes_voc.get_definicao();

    cout << "\nTexto da definicao: " << definicao.get_texto_definicao().get_texto_definicao();
    cout << "\nData da definicao: " << definicao.get_data().get_data();

}

vector<Termo> ServicoVocabulariosControle::ApresentaTermos(const VocControlado &voc_controlado) throw(invalid_argument) {

    vector<Termo> vetor_termos;
    Termo termo;
    int tamanho;

    try {
        ComandoSQLRetornoTermos retorno_termos(voc_controlado);
        retorno_termos.Executar();

        vetor_termos = retorno_termos.get_termos();
        tamanho = vetor_termos.size();

        for(int i = 0; i < tamanho; i++) {
            termo = vetor_termos[i];
            cout << "\n" << termo.get_nome().get_nome() << endl;
        }
    } catch(invalid_argument &exp) {
        cout << exp.what() << endl;
    }

    return vetor_termos;
}

Resultado ServicoVocabulariosControle::CriaTermo(string nome_voc) throw(invalid_argument) {
    Resultado resultado;
    string input;
    Nome nome;
    Classe_Termo classe_termo;
    Data data;
    Termo termo;
    try{
        cout << endl << "Digite o nome do termo: ";
        cin >> input;
        nome.set_nome(input);
        termo.set_nome(nome);
        cout << endl << "Digite a classe do termo: ";
        cin >> input;
        classe_termo.set_classe_termo(input);
        termo.set_classe_termo(classe_termo);
        cout << endl << "Digite a data: ";
        cin >> input;
        data.set_data(input);
        termo.set_data(data);

        ComandoSQLRegistraTermo registra_termo(termo, nome_voc);
        registra_termo.Executar();

        resultado.set_resultado(Resultado::SUCESSO);
        return resultado;
    } catch (invalid_argument &exp) {
        cout << "\n" << exp.what() << endl;
        fflush(stdin);
        getchar();
        resultado.set_resultado(Resultado::FALHA);
        return resultado;
    }//end try catch
    resultado.set_resultado(Resultado::SUCESSO);
    return resultado;
 }//end Criatermo

 Resultado ServicoVocabulariosControle::ExcluirVocabulario(const VocControlado &voc_controlado) throw(invalid_argument){
     Resultado resultado;
     try {
     ComandoSQLExcluirVocabulario excluir_vocabulario(voc_controlado);
     excluir_vocabulario.Executar();
     cout << "\nExclusao concluida com sucesso\n";
     } catch(invalid_argument &exp) {
        resultado.set_resultado(Resultado::FALHA);
        cout << exp.what() << endl;
        return resultado;
     }
     resultado.set_resultado(Resultado::SUCESSO);
     return resultado;
 }

 Resultado ServicoVocabulariosControle::ExcluirTermo(const Termo &termo) throw(invalid_argument){
    Resultado resultado;
     try {
     ComandoSQLExcluirTermo excluir_termo(termo);
     excluir_termo.Executar();
     cout << "\nExclusao concluida com sucesso\n";
     } catch(invalid_argument &exp) {
        resultado.set_resultado(Resultado::FALHA);
        cout << exp.what() << endl;
        return resultado;
     }
     resultado.set_resultado(Resultado::SUCESSO);
     return resultado;
 }

 void ServicoVocabulariosControle::ConsultarTermo(const Termo &termo) throw(invalid_argument){
    cout<< "\ntermo:" << termo.get_classe_termo().get_classe_termo() << endl;
    cout<< "\ndata:" << termo.get_data().get_data() << endl;
 }

 Resultado ServicoVocabulariosControle::EditarDefinicaoVocabulario(string voc) throw(invalid_argument){
    Resultado resultado;
    string input;
    Texto_Definicao texto_definicao;
    Data data_definicao;

    try {
        cout << endl << "Digite o texto da definicao: ";
        cin.clear();    //Limpar o cin pra poder pegar o input de maneira correta
        cin.ignore();
        getline(cin, input);
        texto_definicao.set_texto_definicao(input);

        cout << endl << "Digite a data da definicao: ";
        cin >> input;
        data_definicao.set_data(input);

        Definicao definicao(texto_definicao, data_definicao);

        ComandoSQLEditarDefinicaoVocabulario editar_definicao_vocabulario(voc, definicao);
        editar_definicao_vocabulario.Executar();

        resultado.set_resultado(Resultado::SUCESSO);
        return resultado;
    } catch (invalid_argument &exp) {
        cout << "\n" << exp.what() << endl;
        fflush(stdin);
        getchar();
        resultado.set_resultado(Resultado::FALHA);
        return resultado;
    }

    resultado.set_resultado(Resultado::SUCESSO);
    return resultado;
 }

