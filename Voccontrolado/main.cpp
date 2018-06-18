#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>


#include "dominios.hpp"
#include "entidades.hpp"
#include "controle.hpp"
#include "interfaces.hpp"
#include "stubs.hpp"
#include "servicos.hpp"
#include "comandos.hpp"
#include "comandoSQL.hpp"

#define ACESSAR_CONTA 1
#define CADASTRAR 2
#define SAIR 3
#define USUARIO 1
#define VOCABULARIO 2

using namespace std;

int main(int argc, char *argv[]){

    ComandoSQLCriarTabelas comando_sql_criar_tabelas;
    comando_sql_criar_tabelas.CriarTabelas();
    comando_sql_criar_tabelas.Executar();

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
        AutenticacaoIS *controle_autenticacao;
        controle_autenticacao = new ServicoAutenticacaoControle();

        CadastroIS *controle_cadastro;
        controle_cadastro = new ServicoCadastroControle();

        UsuarioIS *controle_usuario;
        controle_usuario = new ServicoUsuarioControle();

        VocabulariosIS *stub_vocabulario;
        stub_vocabulario = new StubVocabularios();

        //Link controladora-stub
        cntr_ia_autenticacao->set_aut_ia(controle_autenticacao);
        cntr_ia_cadastro->set_cadastro_ia(controle_cadastro);
        cntr_ia_usuario->set_usuario_ia(controle_usuario);
        cntr_ia_vocabulario->set_vocabulario_ia(stub_vocabulario);

        ResultadoUsuario resultado;
        Resultado resultado_usuario;
        Resultado resultado_vocabulario;

        do {
            system(CLEAR);
            cout << "\n\t\t\tVocabularios Controlados\n\n";
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
                                do{
                                    system(CLEAR);
                                    cout << endl << "Seja Bem-vindo!" << endl;
                                    cout << "Escolha o servico a ser utilizado:" << endl;
                                    cout << "1. Servicos de Usuario" << endl;
                                    cout << "2. Servicos de Vocabulario" << endl;
                                    cout << "3. Retornar" << endl;
                                    cin >> servico;
                                }while(servico < 1 || servico > 3);
                                    if(servico == USUARIO){
                                        resultado_usuario = cntr_ia_usuario->Executar(resultado);
                                        if(resultado_usuario.get_resultado() == Resultado::RETORNAR)
                                            continue;
                                    }

                                    if(servico == VOCABULARIO){
                                        resultado_vocabulario = cntr_ia_vocabulario->Executar(resultado);
                                        if(resultado_vocabulario.get_resultado() == Resultado::RETORNAR)
                                            continue;
                                    }

                                    if(servico == SAIR)
                                        break;
                            }while(true);
                            break;
                        case ResultadoUsuario::RETORNAR:
                            continue;
                    } //end switch()
                } catch (const invalid_argument &exp) {
                    cout << exp.what() << endl;
                    cout << "Pressione qualquer tecla para continuar: ";
                    fflush(stdin);
                    getchar();

                }//end try catch
                break;
            case CADASTRAR:
                try{
                    cntr_ia_cadastro->ExecutarIA();

                } catch (invalid_argument &exp) {
                    cout << exp.what() << endl;
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
        delete controle_autenticacao;
        delete controle_cadastro;
        delete controle_usuario;
        delete stub_vocabulario;
    }while(true);//do while principal



    return 0;
}
