#include <iostream>

#include "stubs.hpp"
#include "dominios.hpp"

using namespace std;

/*----------------------------------------------------------------------------*/

// Resultado StubAutenticacao::Autenticar(const Correio_Eletronico &correio_eletronico, const Senha &senha) throw (invalid_argument){
//
//     cout << endl << "AutenticacaoIS::Autenticar" << endl;
//
//     cout << "Email = " << correio_eletronico.get_correio_eletronico() << endl;
//     cout << "Senha = " << senha.get_senha() << endl;
//
//     ResultadoUsuario resultado;
//
//     if(TRIGGER_FALHA_EMAIL == correio_eletronico.get_correio_eletronico()){
//         resultado.set_resultado(ResultadoUsuario::FALHA);
//     } else if (TRIGGER_ERRO_SISTEMA_EMAIL == correio_eletronico.get_correio_eletronico()){
//         throw invalid_argument("\nErro de sistema.\n");
//     } else {
//         resultado.set_resultado(ResultadoUsuario::SUCESSO);
//     }
//
//     if(TRIGGER_FALHA_SENHA == senha.get_senha()){
//         resultado.set_resultado(ResultadoUsuario::FALHA);
//     }
//
//
//     return resultado;
//
// }//end Autenticar

/*----------------------------------------------------------------------------*/

// ResultadoUsuario StubAutenticacao::TipoDeUsuario(const Correio_Eletronico &correio_eletronico, const Senha &senha){
//
//     ResultadoUsuario resultado_usuario;
//
//     Nome nome;
//     Sobrenome sobrenome;
//     Data data;
//     Telefone telefone;
//     Endereco endereco;
//
//     nome.set_nome(NOME_LEITOR);
//     sobrenome.set_sobrenome(SOBRENOME_LEITOR);
//     Leitor leitor(nome, sobrenome, correio_eletronico, senha);
//
//     nome.set_nome(NOME_DESENVOLVEDOR);
//     sobrenome.set_sobrenome(SOBRENOME_DESENVOLVEDOR);
//     data.set_data(DATA_DESENVOLVEDOR);
//     Desenvolvedor desenvolvedor(nome, sobrenome,data, correio_eletronico, senha);
//
//     nome.set_nome(NOME_ADMINISTRADOR);
//     sobrenome.set_sobrenome(SOBRENOME_ADMINISTRADOR);
//     data.set_data(DATA_ADMINISTRADOR);
//     endereco.set_endereco(ENDERECO_ADMINISTRADOR);
//     telefone.set_telefone(TELEFONE_ADMINISTRADOR);
//     Administrador administrador(nome, sobrenome, telefone, data, endereco, correio_eletronico, senha);
//
//     if(TRIGGER_LEITOR == correio_eletronico.get_correio_eletronico()) {
//         resultado_usuario.tipo_de_usuario = resultado_usuario.LEITOR;
//         resultado_usuario.set_leitor(leitor);
//
//     } else if(TRIGGER_DESENVOLVEDOR == correio_eletronico.get_correio_eletronico()) {
//         resultado_usuario.tipo_de_usuario = resultado_usuario.DESENVOLVEDOR;
//         resultado_usuario.set_desenvolvedor(desenvolvedor);
//
//     } else if(TRIGGER_ADMINISTRADOR == correio_eletronico.get_correio_eletronico()) {
//         resultado_usuario.tipo_de_usuario = resultado_usuario.ADMINISTRADOR;
//         resultado_usuario.set_administrador(administrador);
//
//     } else if(TRIGGER_FALHA_LEITOR == correio_eletronico.get_correio_eletronico()){
//         resultado_usuario.tipo_de_usuario = resultado_usuario.LEITOR;
//         resultado_usuario.set_leitor(leitor);
//
//     } else if(TRIGGER_FALHA_DESENVOLVEDOR == correio_eletronico.get_correio_eletronico()){
//         resultado_usuario.tipo_de_usuario = resultado_usuario.DESENVOLVEDOR;
//         resultado_usuario.set_desenvolvedor(desenvolvedor);
//
//     } else if(TRIGGER_FALHA_ADMINISTRADOR == correio_eletronico.get_correio_eletronico()){
//         resultado_usuario.tipo_de_usuario = resultado_usuario.ADMINISTRADOR;
//         resultado_usuario.set_administrador(administrador);
//
//     } else if(TRIGGER_ERRO_SISTEMA_LEITOR == correio_eletronico.get_correio_eletronico()){
//         resultado_usuario.tipo_de_usuario = resultado_usuario.LEITOR;
//         resultado_usuario.set_leitor(leitor);
//
//     } else if(TRIGGER_ERRO_SISTEMA_DESENVOLVEDOR == correio_eletronico.get_correio_eletronico()){
//         resultado_usuario.tipo_de_usuario = resultado_usuario.DESENVOLVEDOR;
//         resultado_usuario.set_desenvolvedor(desenvolvedor);
//
//     } else if(TRIGGER_ERRO_SISTEMA_ADMINISTRADOR == correio_eletronico.get_correio_eletronico()){
//         resultado_usuario.tipo_de_usuario = resultado_usuario.ADMINISTRADOR;
//         resultado_usuario.set_administrador(administrador);
//
//     } else { //O leitor eh estabelecido como usuario padrao.
//         resultado_usuario.tipo_de_usuario = resultado_usuario.LEITOR;
//         resultado_usuario.set_leitor(leitor);
//     }
//
//
//     return resultado_usuario;
//
// }

/*----------------------------------------------------------------------------*/

/*ResultadoUsuario StubCadastro::CadastroLeitor(const Leitor &leitor) throw (invalid_argument){
    ResultadoUsuario resultado;
    this->leitor = leitor;

    if(leitor.get_correio_eletronico().get_correio_eletronico() == TRIGGER_CORREIO_ELETRONICO){
        cout << endl << "Falha no cadastro" << endl;
        cout << "Pressione qualquer tecla para continuar: ";
        fflush(stdin);
        getchar();
        resultado.set_resultado(Resultado::FALHA);
    } else if(leitor.get_correio_eletronico().get_correio_eletronico() == TRIGGER_ERRO_SISTEMA_EMAIL){
        throw invalid_argument("\nErro de sistema\n");
    } else {
        resultado.set_resultado(Resultado::SUCESSO);
    }

    return resultado;
}

ResultadoUsuario StubCadastro::CadastroDesenvolvedor(const Desenvolvedor &desenvolvedor) throw (invalid_argument) {
    ResultadoUsuario resultado;
    this->desenvolvedor = desenvolvedor;

    if(desenvolvedor.get_correio_eletronico().get_correio_eletronico() == TRIGGER_CORREIO_ELETRONICO){
        cout << endl << "Falha no cadastro" << endl;
        cout << "Pressione qualquer tecla para continuar: ";
        fflush(stdin);
        getchar();
        resultado.set_resultado(Resultado::FALHA);
    } else if(desenvolvedor.get_correio_eletronico().get_correio_eletronico() == TRIGGER_ERRO_SISTEMA_EMAIL){
        throw invalid_argument("\nErro de sistema\n");
    } else {
        resultado.set_resultado(Resultado::SUCESSO);
    }

    return resultado;
}

ResultadoUsuario StubCadastro::CadastroAdministrador(const Administrador &administrador) throw (invalid_argument){
    ResultadoUsuario resultado;
    this->administrador = administrador;

    if(administrador.get_correio_eletronico().get_correio_eletronico() == TRIGGER_CORREIO_ELETRONICO){
        cout << endl << "Falha no cadastro" << endl;
        cout << "Pressione qualquer tecla para continuar: ";
        fflush(stdin);
        getchar();
        resultado.set_resultado(Resultado::FALHA);
    } else if(administrador.get_correio_eletronico().get_correio_eletronico() == TRIGGER_ERRO_SISTEMA_EMAIL){
        throw invalid_argument("\nErro de sistema\n");
    } else {
        resultado.set_resultado(Resultado::SUCESSO);
    }

    return resultado;
}
*/

/*----------------------------------------------------------------------------*/

void StubUsuario::Exibir(const ResultadoUsuario resultado_usuario) throw (invalid_argument){
    if(resultado_usuario.tipo_de_usuario == ResultadoUsuario::LEITOR){
        cout << "\nNome: " << resultado_usuario.get_leitor().get_nome().get_nome() << endl;
        cout << "Sobrenome: " << resultado_usuario.get_leitor().get_sobrenome().get_sobrenome() << endl;
        cout << "Email: " << resultado_usuario.get_leitor().get_correio_eletronico().get_correio_eletronico() << endl;
        cout << "Senha: " << resultado_usuario.get_leitor().get_senha().get_senha() << endl;
        cout << endl << "Pressione qualquer tecla para continuar: ";
        fflush(stdin);
        getchar();

    } else if (resultado_usuario.tipo_de_usuario == ResultadoUsuario::DESENVOLVEDOR){
        cout << "\nNome: " << resultado_usuario.get_desenvolvedor().get_nome().get_nome() << endl;
        cout << "Sobrenome: " << resultado_usuario.get_desenvolvedor().get_sobrenome().get_sobrenome() << endl;
        cout << "Email: " << resultado_usuario.get_desenvolvedor().get_correio_eletronico().get_correio_eletronico() << endl;
        cout << "Data de nascimento: " << resultado_usuario.get_desenvolvedor().get_data().get_data() << endl;
        cout << endl << "Pressione qualquer tecla para continuar: ";
        fflush(stdin);
        getchar();

    } else if(resultado_usuario.tipo_de_usuario == ResultadoUsuario::ADMINISTRADOR){
        cout << "\nNome: " << resultado_usuario.get_administrador().get_nome().get_nome() << endl;
        cout << "Sobrenome: " << resultado_usuario.get_administrador().get_sobrenome().get_sobrenome() << endl;
        cout << "Email: " << resultado_usuario.get_administrador().get_correio_eletronico().get_correio_eletronico() << endl;
        cout << "Senha: " << resultado_usuario.get_administrador().get_senha().get_senha() << endl;
        cout << "Data de nascimento: " << resultado_usuario.get_administrador().get_data().get_data() << endl;
        cout << "Telefone: " << resultado_usuario.get_administrador().get_telefone().get_telefone() << endl;
        cout << "Endereco: " << resultado_usuario.get_administrador().get_endereco().get_endereco() << endl;
        cout << endl << "Pressione qualquer tecla para continuar: ";
        fflush(stdin);
        getchar();
    }
}

ResultadoUsuario StubUsuario::Editar(const ResultadoUsuario resultado_usuario) throw (invalid_argument){
    ResultadoUsuario resultado;
    if(resultado_usuario.tipo_de_usuario == ResultadoUsuario::LEITOR){
        resultado = EditarLeitor();
    } else if(resultado_usuario.tipo_de_usuario == ResultadoUsuario::DESENVOLVEDOR){
        resultado = EditarDesenvolvedor();
    } else {
        resultado = EditarAdministrador();
    }
    return resultado;
}

ResultadoUsuario StubUsuario::EditarLeitor() throw (invalid_argument){
    ResultadoUsuario resultado;
    string input;
    Nome nome;
    Sobrenome sobrenome;
    Senha senha;
    Correio_Eletronico correio_eletronico;

    do{
        try{
            system(CLEAR);
            cout << "Escreva seu nome: ";
            cin >> input;
            nome.set_nome(input);
            cout << endl << "Escreva seu sobrenome: ";
            cin >> input;
            sobrenome.set_sobrenome(input);
            cout << endl << "Escreva sua senha: ";
            cin >> input;
            senha.set_senha(input);
            cout << endl << "Escreva seu email: ";
            cin >> input;
            correio_eletronico.set_correio_eletronico(input);
            break;

        } catch (invalid_argument &exp) {
            cout << "\nFormato Invalido\n";
            cout << "Pressione qualquer tecla para continuar: ";
            fflush(stdin);
            getchar();
        }//end try catch
    } while(true);//end while()
    Leitor leitor(nome, sobrenome, correio_eletronico, senha);
    resultado.set_leitor(leitor);
    return resultado;
}//end EditarLeitor()

ResultadoUsuario StubUsuario::EditarDesenvolvedor() throw (invalid_argument){
    ResultadoUsuario resultado;
    string input;
    Nome nome;
    Sobrenome sobrenome;
    Senha senha;
    Correio_Eletronico correio_eletronico;
    Data data_nascimento;

    do{
        try{
            system(CLEAR);
            cout << "Escreva seu nome: ";
            cin >> input;
            nome.set_nome(input);
            cout << endl << "Escreva seu sobrenome: ";
            cin >> input;
            sobrenome.set_sobrenome(input);
            cout << endl << "Escreva sua senha: ";
            cin >> input;
            senha.set_senha(input);
            cout << endl << "Escreva seu email: ";
            cin >> input;
            correio_eletronico.set_correio_eletronico(input);
            cout << endl << "Escreva sua data de nascimento: ";
            cin >> input;
            data_nascimento.set_data(input);
            break;

        } catch (invalid_argument &exp) {
            cout << "\nFormato Invalido\n";
            cout << "Pressione qualquer tecla para continuar: ";
            fflush(stdin);
            getchar();
        }//end try catch
    } while(true);//end while()
    Desenvolvedor desenvolvedor(nome, sobrenome, data_nascimento, correio_eletronico, senha);
    resultado.set_desenvolvedor(desenvolvedor);
    return resultado;
}

ResultadoUsuario StubUsuario::EditarAdministrador() throw (invalid_argument){
    ResultadoUsuario resultado;
    string input;
    Nome nome;
    Sobrenome sobrenome;
    Senha senha;
    Correio_Eletronico correio_eletronico;
    Data data_nascimento;
    Telefone telefone;
    Endereco endereco;

    do{
        try{
            system(CLEAR);
            cout << "Escreva seu nome: ";
            cin >> input;
            nome.set_nome(input);
            cout << endl << "Escreva seu sobrenome: ";
            cin >> input;
            sobrenome.set_sobrenome(input);
            cout << endl << "Escreva sua senha: ";
            cin >> input;
            senha.set_senha(input);
            cout << endl << "Escreva seu email: ";
            cin >> input;
            correio_eletronico.set_correio_eletronico(input);
            cout << endl << "Escreva sua data de nascimento: ";
            cin >> input;
            data_nascimento.set_data(input);
            cout << endl << "Escreva seu telefone: ";
            cin >> input;
            telefone.set_telefone(input);
            cout << endl << "Escreva seu endereco: ";
            cin >> input;
            endereco.set_endereco(input);
            break;

        } catch (invalid_argument &exp) {
            cout << "\nFormato Invalido\n";
            cout << "Pressione qualquer tecla para continuar: ";
            fflush(stdin);
            getchar();
        }//end try catch
    } while(true);//end while()
    Administrador administrador(nome, sobrenome, telefone, data_nascimento, endereco, correio_eletronico, senha);
    resultado.set_administrador(administrador);
    return resultado;
}

Resultado StubUsuario::Excluir() throw (invalid_argument){
    string input;
    Senha senha;
    Resultado resultado;

    system(CLEAR);
    cout << endl << "TRIGGER SENHA INVALIDA: " << StubAutenticacao::TRIGGER_FALHA_SENHA;
    cout << endl << "TRIGGER SENHA ERRO SISTEMA: " << StubAutenticacao::TRIGGER_ERRO_SISTEMA_SENHA;
    cout << endl << "Digite a sua senha para confirmar a exclusao: ";
    cin >> input;
    try{
        senha.set_senha(input);
    } catch (invalid_argument &exp){
        cout << "\nFormato Invalido\n";
        cout << "Pressione qualquer tecla para continuar: ";
        fflush(stdin);
        getchar();
    }

    if(senha.get_senha() == StubAutenticacao::TRIGGER_FALHA_SENHA){
        resultado.set_resultado(Resultado::FALHA);
        cout << endl << "Falha na exclusao" << endl;
        cout << "Pressione qualquer tecla para continuar: ";
        fflush(stdin);
        getchar();
        return resultado;

    } else if(senha.get_senha() == StubAutenticacao::TRIGGER_ERRO_SISTEMA_SENHA){
        throw invalid_argument("\nErro de sistema\n");

    } else {
        resultado.set_resultado(Resultado::SUCESSO);
    }
    return resultado;
}//Excluir
/*----------------------------------------------------------------------------*/

vector<VocControlado> StubVocabularios::ListaVocabulario() {

    Nome nome_mat;
    Idioma idioma_mat;
    Data data_mat;

    nome_mat.set_nome(TRIGGER_VOCABULARIO_MATEMATICA);
    idioma_mat.set_idioma("POR");
    data_mat.set_data("14/05/2018");

    Nome nome_anime;
    Idioma idioma_anime;
    Data data_anime;

    nome_anime.set_nome(TRIGGER_VOCABULARIO_ANIMES);
    idioma_anime.set_idioma("POR");
    data_anime.set_data("13/05/2018");

    Nome nome_erro;
    Idioma idioma_erro;
    Data data_erro;

    nome_erro.set_nome(TRIGGER_VOCABULARIO_ERRO);
    idioma_erro.set_idioma("ENG");
    data_erro.set_data("16/05/2018");

    VocControlado voc_matematica(nome_mat, idioma_mat, data_mat);
    VocControlado voc_animes(nome_anime, idioma_anime, data_anime);
    VocControlado voc_erro(nome_erro, idioma_erro, data_erro);


    vector<VocControlado> vetor_vocabularios;

    vetor_vocabularios.push_back(voc_matematica);
    vetor_vocabularios.push_back(voc_animes);
    vetor_vocabularios.push_back(voc_erro);

    return vetor_vocabularios;

}

void StubVocabularios::ConsultarVocabulario(const VocControlado &voc_controlado) throw(invalid_argument){
    if(voc_controlado.get_nome().get_nome() == TRIGGER_VOCABULARIO_ERRO) {
        throw invalid_argument("\nInformacoes do vocabulario nao encontradas");
    } else {
            cout<< "\nidioma:" << voc_controlado.get_idioma().get_idioma();
            cout<< "\ndata:" << voc_controlado.get_data().get_data();
    }
}

vector<Termo> StubVocabularios::ApresentaTermos(const VocControlado &voc_controlado) throw(invalid_argument){

    Nome nome_mat_quadrado;
    Classe_Termo classe_termo_mat_quadrado;
    Data data_mat_quadrado;

    nome_mat_quadrado.set_nome("Quadrado");
    classe_termo_mat_quadrado.set_classe_termo("PT");
    data_mat_quadrado.set_data("12/05/2018");

    Nome nome_mat_triangulo;
    Classe_Termo classe_termo_mat_triangulo;
    Data data_mat_triangulo;

    nome_mat_triangulo.set_nome("Triangulo");
    classe_termo_mat_triangulo.set_classe_termo("PT");
    data_mat_triangulo.set_data("12/05/2018");

    Termo termo_mat_quadrado(nome_mat_quadrado, classe_termo_mat_quadrado, data_mat_quadrado);
    Termo termo_mat_triangulo(nome_mat_triangulo, classe_termo_mat_triangulo, data_mat_triangulo);

    Nome nome_anime_naruto;
    Classe_Termo classe_anime_naruto;
    Data data_anime_naruto;

    nome_anime_naruto.set_nome("Naruto");
    classe_anime_naruto.set_classe_termo("PT");
    data_anime_naruto.set_data("03/10/2002");

    Nome nome_anime_boruto;
    Classe_Termo classe_anime_boruto;
    Data data_anime_boruto;

    nome_anime_boruto.set_nome("Boruto");
    classe_anime_boruto.set_classe_termo("NP");
    data_anime_boruto.set_data("01/11/2017");

    Termo termo_anime_naruto(nome_anime_naruto, classe_anime_naruto, data_anime_naruto);
    Termo termo_anime_boruto(nome_anime_boruto, classe_anime_boruto, data_anime_boruto);

    vector<Termo> vetor_termos;

    if(voc_controlado.get_nome().get_nome() == TRIGGER_VOCABULARIO_MATEMATICA) {
        vetor_termos.push_back(termo_mat_quadrado);
        vetor_termos.push_back(termo_mat_triangulo);

        cout << "\n" << vetor_termos[0].get_nome().get_nome() << endl;
        cout << "\n" << vetor_termos[1].get_nome().get_nome() << endl;

        return vetor_termos;
    } else if(voc_controlado.get_nome().get_nome() == TRIGGER_VOCABULARIO_ANIMES) {
        vetor_termos.push_back(termo_anime_naruto);
        vetor_termos.push_back(termo_anime_boruto);

        cout << "\n" << vetor_termos[0].get_nome().get_nome() << endl;
        cout << "\n" << vetor_termos[1].get_nome().get_nome() << endl;

        return vetor_termos;
    } else if(voc_controlado.get_nome().get_nome() == TRIGGER_VOCABULARIO_ERRO) {
        throw invalid_argument("\nTermos do vocabulario nao encontrados\n");
    }

    return vetor_termos;
}

void StubVocabularios::ConsultarTermo(const Termo &termo) throw(invalid_argument) {
    if(termo.get_nome().get_nome() == TRIGGER_TERMO_ERRO) {
        throw invalid_argument("\nInformacoes do termo nao encontradas\n");
    } else {
        cout<< "\ntermo:" << termo.get_classe_termo().get_classe_termo() << endl;
        cout<< "\ndata:" << termo.get_data().get_data() << endl;
    }

}

Definicao StubVocabularios::BuscaDefinicaoTermo(const Termo &termo) throw(invalid_argument) {

    Texto_Definicao texto_triangulo;
    Texto_Definicao texto_naruto;

    texto_triangulo.set_texto_definicao("Poligono de tres lados");
    texto_naruto.set_texto_definicao("Anime japones sobre ninjas");

    Data data_triangulo;
    Data data_naruto;

    data_triangulo.set_data("18/05/2018");
    data_naruto.set_data("18/05/2018");

    Definicao definicao_triangulo(texto_triangulo, data_triangulo);
    Definicao definicao_naruto(texto_naruto, data_naruto);

    if(termo.get_nome().get_nome() == TRIGGER_DEFINICAO_TRIANGULO) {
        return definicao_triangulo;
    } else if(termo.get_nome().get_nome() == TRIGGER_DEFINICAO_NARUTO){
        return definicao_naruto;
    } else if(termo.get_nome().get_nome() == TRIGGER_DEFINICAO_ERRO) {
        throw invalid_argument("\nDefinicao nao encontrada\n");
    }

    return definicao_naruto;
}

void StubVocabularios::ConsultaDefinicaoTermo(const Definicao &definicao) {
    cout<< "\ndata de definicao:" << definicao.get_data().get_data() << endl;
    cout<< "\ndefinicao:" << definicao.get_texto_definicao().get_texto_definicao() << endl;
}


/*----------------------------------------------------------------------------*/

Resultado StubVocabularios::CriaTermo() throw(invalid_argument){
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
        resultado.set_resultado(Resultado::SUCESSO);
        return resultado;
    } catch (invalid_argument &exp) {
        cout << "\nFormato Invalido\n";
        cout << "Pressione qualquer tecla para continuar: ";
        fflush(stdin);
        getchar();
        resultado.set_resultado(Resultado::FALHA);
        return resultado;
    }//end try catch
    resultado.set_resultado(Resultado::SUCESSO);
    return resultado;
}//end Criatermo

Resultado StubVocabularios::ExcluirTermo(const Termo&) throw(invalid_argument){
    Resultado resultado;
    cout << "\nExclusão concluida com sucesso\n";
    resultado.set_resultado(Resultado::SUCESSO);
    return resultado;
}

Resultado StubVocabularios::CriaVocabulario() throw(invalid_argument){
    Resultado resultado;
    VocControlado voc_controlado;
    Nome nome;
    Idioma idioma;
    Data data;
    string input;
    try{
        cout << "\nDigite o nome do vocabulario: ";
        cin >> input;
        nome.set_nome(input);
        voc_controlado.set_nome(nome);
        cout << "\nDigite o idioma: ";
        cin >> input;
        idioma.set_idioma(input);
        voc_controlado.set_idioma(idioma);
        cout << "\nDigite a data: ";
        cin >> input;
        data.set_data(input);
        voc_controlado.set_data(data);
    } catch (invalid_argument &exp) {
        cout << "\nFormato Invalido\n";
        cout << "Pressione qualquer tecla para continuar: ";
        fflush(stdin);
        getchar();
        resultado.set_resultado(Resultado::FALHA);
        return resultado;
    }
    if (nome.get_nome() ==  TRIGGER_FALHA_CRIA_VOC){
        resultado.set_resultado(Resultado::FALHA);
        return resultado;
    } else {
        resultado.set_resultado(Resultado::SUCESSO);
        return resultado;
    }
}

Resultado StubVocabularios::ExcluirVocabulario(const VocControlado &voc_controlado) throw(invalid_argument){
    if(voc_controlado.get_nome().get_nome() == TRIGGER_VOCABULARIO_ERRO) {
        throw invalid_argument("Erro de sistema");
    }
    Resultado resultado;
    cout << "\nExclusao concluida com sucesso\n";
    resultado.set_resultado(Resultado::SUCESSO);
    return resultado;
}

//Resultado StubVocabularios::EditarDefinicaoVocabulario(const VocControlado&) throw(invalid_argument){
//    Resultado resultado
//}

Resultado StubVocabularios::EditarDefinicaoTermo(Termo& termo) throw(invalid_argument){
    string input;
    Resultado resultado;
    Nome nome;
    Classe_Termo classe_termo;
    Data data;

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
    } catch (invalid_argument &exp) {
        cout << "\nFormato Invalido\n";
        cout << "Pressione qualquer tecla para continuar: ";
        fflush(stdin);
        getchar();
    }//end try catch
    resultado.set_resultado(Resultado::SUCESSO);
    return resultado;
}


Resultado StubVocabularios::AlterarIdiomaVocabulario(VocControlado& voc_controlado) throw(invalid_argument){
    Resultado resultado;
    string input;
    Idioma idioma;
    try{
        cout << endl << "Digite o idioma: ";
        cin >> input;
        idioma.set_idioma(input);
        voc_controlado.set_idioma(idioma);
        resultado.set_resultado(Resultado::SUCESSO);
        return resultado;
    } catch (invalid_argument &exp) {
        cout << "\nFormato Invalido\n";
        cout << "Pressione qualquer tecla para continuar: ";
        fflush(stdin);
        getchar();
        resultado.set_resultado(Resultado::FALHA);
        return resultado;
    }
    resultado.set_resultado(Resultado::SUCESSO);
    return resultado;
}

Resultado StubVocabularios::EditarDefinicaoVocabulario(Definicao &definicao) throw(invalid_argument){
    Resultado resultado;
    string input;

    cout << "\nDigite a nova definicao:" << endl;

    try {

        cout << "\nDigite o novo texto de definicao:" << endl;
        cin >> input;
        definicao.get_texto_definicao().set_texto_definicao(input);

        cout << "\nDigite a data>" << endl;
        cin >> input;
        definicao.get_data().set_data(input);

        resultado.set_resultado(Resultado::SUCESSO);
        return resultado;

    } catch (invalid_argument &exp) {
        cout << "\nFormato Invalido" << endl;
        resultado.set_resultado(Resultado::FALHA);
        return resultado;
    }
}

Resultado StubVocabularios::EditarTermo(Termo &termo) throw(invalid_argument) {

    string input;
    Resultado resultado;

    cout << "\n Digite os novos valores para o termo:" << endl;
    try {
        cout << "\n Digite o novo nome:" << endl;
        cin >> input;
        termo.get_nome().set_nome(input);

        cout << "\nDigite a nova classe:" << endl;
        cin >> input;
        termo.get_classe_termo().set_classe_termo(input);

        cout << "\nDigite a nova data:" << endl;
        cin >> input;
        termo.get_data().set_data(input);

        resultado.set_resultado(Resultado::SUCESSO);
        return resultado;

    } catch(invalid_argument &exp) {
        cout << "\nFormato invalido." << endl;
        resultado.set_resultado(Resultado::FALHA);
        return resultado;
    }
}
