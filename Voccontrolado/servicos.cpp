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

    return resultado;
}

ResultadoUsuario ServicoAutenticacaoControle::TipoDeUsuario(const Correio_Eletronico&, const Senha&){
    ResultadoUsuario resultado;
    return resultado;
}
