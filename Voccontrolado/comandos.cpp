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
        return;

    }//end while(true)
}
