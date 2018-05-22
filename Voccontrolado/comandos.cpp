#include "comandos.hpp"

/*----------------------------------------------------------------------------*/

void ComandoCadastroLeitorIA::ExecutarComando(CadastroIS *cntr_link_cadastro) throw (invalid_argument) {
    string input;
    Resultado resultado_cadastro;
    Nome nome;
    Sobrenome sobrenome;
    Correio_Eletronico correio_eletronico;
    Senha senha;

    while(true){
        try{
        cout << "\nEscreva seu nome: ";
        cin >> input;
        nome.set_nome(input);
        cout << "\nEscreva seu sobrenome: ";
        cin >> input;
        sobrenome.set_sobrenome(input);
        cout << "\nEscreva seu email: ";
        cin >> input;
        correio_eletronico.set_correio_eletronico(input);
        cout << "\nEscreva sua senha: ";
        cin >> input;
        senha.set_senha(input);

    } catch (invalid_argument &exp) {
        cout << "\nFormato incorreto\n";
        getchar();
        continue;
    }
        Leitor leitor(nome, sobrenome, correio_eletronico, senha);
        resultado_cadastro = cntr_link_cadastro->CadastroLeitor(leitor);
        return;
    }//end while(true)
}//end Executar()

/*----------------------------------------------------------------------------*/

void ComandoCadastroDesenvolvedorIA::ExecutarComando(CadastroIS *cntr_link_cadastro) throw (invalid_argument){
    string input;
    Resultado resultado_cadastro;
    Nome nome;
    Sobrenome sobrenome;
    Correio_Eletronico correio_eletronico;
    Senha senha;
    Data data_nascimento;

    while(true){
        try{
        cout << "\nEscreva seu nome: ";
        cin >> input;
        nome.set_nome(input);
        cout << "\nEscreva seu sobrenome: ";
        cin >> input;
        sobrenome.set_sobrenome(input);
        cout << "\nEscreva seu email: ";
        cin >> input;
        correio_eletronico.set_correio_eletronico(input);
        cout << "\nEscreva sua data de nascimento: ";
        cin >> input;
        data_nascimento.set_data(input);
        cout << "\nEscreva sua senha: ";
        cin >> input;
        senha.set_senha(input);

    } catch (invalid_argument &exp) {
        cout << "\nFormato incorreto\n";
        getchar();
        continue;
    }
        Desenvolvedor desenvolvedor(nome, sobrenome, data_nascimento, correio_eletronico, senha);
        resultado_cadastro = cntr_link_cadastro->CadastroLeitor(desenvolvedor);
        return;
    }//end while(true)
}

/*----------------------------------------------------------------------------*/

void ComandoCadastroAdministradorIA::ExecutarComando(CadastroIS *cntr_link_cadastro) throw (invalid_argument){
    string input;
    Resultado resultado_cadastro;
    Nome nome;
    Sobrenome sobrenome;
    Correio_Eletronico correio_eletronico;
    Senha senha;
    Data data_nascimento;
    Telefone telefone;
    Endereco endereco;

    while(true){
        try{
        cout << "\nEscreva seu nome: ";
        cin >> input;
        nome.set_nome(input);
        cout << "\nEscreva seu sobrenome: ";
        cin >> input;
        sobrenome.set_sobrenome(input);
        cout << "\nEscreva seu email: ";
        cin >> input;
        correio_eletronico.set_correio_eletronico(input);
        cout << "\nEscreva sua data de nascimento: ";
        cin >> input;
        data_nascimento.set_data(input);
        cout << "\nEscreva seu telefone: ";
        cin >> input;
        telefone.set_telefone(input);
        cout << "\nEscreva seu endereco: ";
        cin >> input;
        endereco.set_endereco(input);
        cout << "\nEscreva sua senha: ";
        cin >> input;
        senha.set_senha(input);

    } catch (invalid_argument &exp) {
        cout << "\nFormato incorreto\n";
        getchar();
        continue;
    }
        Administrador administrador(nome, sobrenome, telefone, data_nascimento, endereco, correio_eletronico, senha);
        resultado_cadastro = cntr_link_cadastro->CadastroLeitor(administrador);
        if(resultado_cadastro.get_resultado() == Resultado::FALHA){
            cout << "\nFalha no cadastro\n";
            cout << "Pressione qualquer tecla para continuar: ";
            fflush(stdin);
            getchar();
        }
        return;

    }//end while(true)
}

/*----------------------------------------------------------------------------*/

Resultado ComandoExibir::ExecutarComando(UsuarioIS *cntr_link_usuario, const ResultadoUsuario resultado_usuario) throw (invalid_argument) {
    Resultado resultado;
    if(resultado_usuario.tipo_de_usuario == ResultadoUsuario::DESENVOLVEDOR){
        if(resultado_usuario.get_desenvolvedor().get_correio_eletronico().get_correio_eletronico() == StubAutenticacao::TRIGGER_FALHA_DESENVOLVEDOR){
            resultado.set_resultado(Resultado::FALHA);
            cout << "\nFalha ao Exibir\n";
            cout << "Pressione qualquer tecla para continuar: ";
            fflush(stdin);
            getchar();
            return resultado;

        } else if(resultado_usuario.get_desenvolvedor().get_correio_eletronico().get_correio_eletronico() == StubAutenticacao::TRIGGER_ERRO_SISTEMA_DESENVOLVEDOR){
            throw invalid_argument("\nErro de sistema\n");

        } else {
            resultado.set_resultado(Resultado::SUCESSO);

        }
    } else if(resultado_usuario.tipo_de_usuario == ResultadoUsuario::LEITOR){
        if(resultado_usuario.get_leitor().get_correio_eletronico().get_correio_eletronico() == StubAutenticacao::TRIGGER_FALHA_LEITOR){
            resultado.set_resultado(Resultado::FALHA);
            cout << "\nFalha ao Exibir\n";
            cout << "Pressione qualquer tecla para continuar: ";
            fflush(stdin);
            getchar();
            return resultado;

        } else if(resultado_usuario.get_leitor().get_correio_eletronico().get_correio_eletronico() == StubAutenticacao::TRIGGER_ERRO_SISTEMA_LEITOR){
            throw invalid_argument("\nErro de sistema\n");

        } else {
            resultado.set_resultado(Resultado::SUCESSO);

        }
    } else if(resultado_usuario.tipo_de_usuario == ResultadoUsuario::ADMINISTRADOR){
        if(resultado_usuario.get_administrador().get_correio_eletronico().get_correio_eletronico() == StubAutenticacao::TRIGGER_FALHA_ADMINISTRADOR){
            resultado.set_resultado(Resultado::FALHA);
            cout << "\nFalha ao Exibir\n";
            cout << "Pressione qualquer tecla para continuar: ";
            fflush(stdin);
            getchar();
            return resultado;

        } else if(resultado_usuario.get_administrador().get_correio_eletronico().get_correio_eletronico() == StubAutenticacao::TRIGGER_ERRO_SISTEMA_ADMINISTRADOR){
            throw invalid_argument("\nErro de sistema\n");

        } else {
            resultado.set_resultado(Resultado::SUCESSO);
        }
    }
    cntr_link_usuario->Exibir(resultado_usuario);
    return resultado;
}

Resultado ComandoExcluir::ExecutarComando(UsuarioIS *cntr_link_usuario, const ResultadoUsuario resultado_usuario) throw (invalid_argument) {
    Resultado resultado;
    resultado = cntr_link_usuario->Excluir();
    return resultado;
}

Resultado ComandoEditar::ExecutarComando(UsuarioIS *cntr_link_usuario, const ResultadoUsuario resultado_usuario) throw (invalid_argument) {
    ResultadoUsuario resultado;
    resultado = cntr_link_usuario->Editar(resultado_usuario);
    return resultado;
}

/*----------------------------------------------------------------------------*/

vector<VocControlado> ComandoListarVocabularios::ExecutarComando(VocabulariosIS *cntr_link_vocabulario) {

    int tamanho;
    vector<VocControlado> lista_vocabularios_controlados;

    lista_vocabularios_controlados = cntr_link_vocabulario->ListaVocabulario();

    tamanho = lista_vocabularios_controlados.size();

    for(int i = 0; i < tamanho; i++){
        cout<< i + 1 << "- " << lista_vocabularios_controlados[i].get_nome().get_nome() << endl;
    }

    return lista_vocabularios_controlados;
}

vector<Termo> ComandoConsultarVocabulario::ExecutarComando(VocabulariosIS *cntr_link_vocabulario, vector<VocControlado> &lista_vocabularios,
                                                            const string nome_vocabulario) throw (invalid_argument) {

    bool TRIGGER_ERRO = false;
    int tamanho = lista_vocabularios.size();
    vector<Termo> lista_termos;

    bool aux;



   // try {
        for(int i = 0; i < tamanho; i++) {
            aux = nome_vocabulario == lista_vocabularios[i].get_nome().get_nome();
            if(aux){
                cntr_link_vocabulario->ConsultarVocabulario(lista_vocabularios[i]);
                cout<< "\nTermos do vocabulario:" << endl;
                lista_termos = cntr_link_vocabulario->ApresentaTermos(lista_vocabularios[i]);
                TRIGGER_ERRO = true;
                return lista_termos;
            }
        }
    //}catch(invalid_argument) {
    //    cout << "Esse vocabulario Nao existe";
    //}


    if(TRIGGER_ERRO == false) {
        throw("\nNome nao se encontra na lista de vocabularios\n");
    }

    return lista_termos;
}

Termo ComandoConsultarTermo::ExecutarComando(VocabulariosIS *cntr_link_vocabulario, vector<Termo> &lista_termos,
                                               string nome_termo) throw(invalid_argument){
    bool TRIGGER_ERRO = false;
    int tamanho = lista_termos.size();

    try{
        for(int i = 0; i < tamanho; i++){
            if(nome_termo == lista_termos[i].get_nome().get_nome()) {
                cntr_link_vocabulario->ConsultarTermo(lista_termos[i]);
                TRIGGER_ERRO = true;
                return lista_termos[i];
            }
        }
    } catch(invalid_argument) {

    }

    if(TRIGGER_ERRO == false) {
        throw("\nNome nao se encontra na lista de termos\n");
    }

    return lista_termos[0];
}

void ComandoConsultarDefinicao::ExecutarComando(VocabulariosIS *cntr_link_vocabulario, Termo &termo) throw(invalid_argument){
    Definicao definicao;

    definicao = cntr_link_vocabulario->BuscaDefinicaoTermo(termo);
    cntr_link_vocabulario->ConsultaDefinicaoTermo(definicao);
}
