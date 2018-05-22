#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>

#include "dominios.hpp"
#include "entidades.hpp"
#include "controle.hpp"
#include "interfaces.hpp"
#include "stubs.hpp"
#include "comandos.hpp"

#define ACESSAR_CONTA 1
#define CADASTRAR 2
#define SAIR 3
#define USUARIO 1
#define VOCABULARIO 2

using namespace std;

int main(void){
    do{
        int escolha;
        int servico;
        //Controladoras
        AutenticacaoIA *cntr_ia_autenticacao;
        CadastroIA *cntr_ia_cadastro;
        UsuarioIA *cntr_ia_usuario;
        VocabulariosIA *cntr_ia_vocabulario;

        cntr_ia_autenticacao = new ApresentacaoAutenticacaoControle();
        cntr_ia_cadastro = new ApresentacaoCadastroControle();
        cntr_ia_usuario = new ApresentacaoUsuarioControle();
        cntr_ia_vocabulario = new ApresentacaoVocabularioControle();

        //Stubs
        AutenticacaoIS *stub_autenticacao;
        stub_autenticacao = new StubAutenticacao();

        CadastroIS *stub_cadastro;
        stub_cadastro = new StubCadastro();

        UsuarioIS *stub_usuario;
        stub_usuario = new StubUsuario();

        VocabulariosIS *stub_vocabulario;
        stub_vocabulario = new StubVocabularios();

        //Link controladora-stub
        cntr_ia_autenticacao->set_aut_ia(stub_autenticacao);
        cntr_ia_cadastro->set_cadastro_ia(stub_cadastro);
        cntr_ia_usuario->set_usuario_ia(stub_usuario);
        cntr_ia_vocabulario->set_vocabulario_ia(stub_vocabulario);

        system(CLEAR);
        cout << "\tValores dos Triggers: \n";
        cout << "Email Invalido: " << StubAutenticacao::TRIGGER_FALHA_EMAIL << endl;
        cout << "Senha Invalida: " << StubAutenticacao::TRIGGER_FALHA_SENHA << endl;
        cout << "Erro Sistema Email: " << StubAutenticacao::TRIGGER_ERRO_SISTEMA_EMAIL << endl;
        cout << "Erro Sistema Senha: " << StubAutenticacao::TRIGGER_ERRO_SISTEMA_SENHA << endl;

        ResultadoUsuario resultado;

        do {
            cout << "\t\t\tVocabularios Controled\n\n";
            cout << "Escolha uma das opcoes: \n";
            cout << "1. Acessar conta\n";
            cout << "2. Cadastrar\n";
            cout << "3. Sair\n";
            cin >> escolha;
        } while(escolha > 3 || escolha < 1);

        switch (escolha) {
            case ACESSAR_CONTA: //Falta preencher com os métodos que serão chamados
                try{
                    resultado = cntr_ia_autenticacao->Autenticar();
                    switch (resultado.get_resultado()) {
                        case ResultadoUsuario::SUCESSO:
                            do{
                                system(CLEAR);
                                cout << endl << "Voce ira utilizar qual servico: " << endl;
                                cout << "1. Servicos de usuario" << endl;
                                cout << "2. Servicos de vocabulario" << endl;
                                cin >> servico;
                            }while(servico < 1 || servico > 2);
                            switch (servico) {
                                case USUARIO:
                                    cntr_ia_usuario->Executar(resultado);
                                    break;
                                case VOCABULARIO:
                                    cntr_ia_vocabulario->Executar(resultado);
                                    break;
                            }//end switch()
                            break;
                        case ResultadoUsuario::RETORNAR:
                            continue;
                    } //end switch()
                } catch (const invalid_argument &exp) {
                    cout << "Erro de sistema" << endl;
                    cout << "Pressione qualquer tecla para continuar: ";
                    fflush(stdin);
                    getchar();

                }//end try catch
                break;
            case CADASTRAR:
                try{
                    cntr_ia_cadastro->ExecutarIA();
                } catch (invalid_argument &exp) {
                    cout << "Erro de sistema" << endl;
                    cout << "Pressione qualquer tecla para continuar: ";
                    fflush(stdin);
                    getchar();

                }
                break;
            case SAIR:
                exit(0);
        }//end switch()

        delete cntr_ia_autenticacao;
        delete cntr_ia_cadastro;
        delete cntr_ia_usuario;
        delete cntr_ia_vocabulario;
        delete stub_autenticacao;
        delete stub_cadastro;
        delete stub_usuario;
        delete stub_vocabulario;
    }while(true);//do while principal

    return 0;
}
