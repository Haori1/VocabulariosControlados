#include <iostream>
#include <string>
#include <stdexcept>
#include <exception>
#include <cstdlib>

#include "controle.hpp"
#include "comandos.hpp"
#include "interfaces.hpp"

using namespace std;

/*----------------------------------------------------------------------------*/

ResultadoUsuario ApresentacaoAutenticacaoControle::Autenticar() throw (invalid_argument){
    ResultadoUsuario resultado_autenticacao;
    Resultado resultado;
    Correio_Eletronico correio_eletronico;
    Senha senha;
    string input;
    int contador = 0;

    while(contador != 4){
        try{
            if(contador != 0){
                cout << "Voce possui 3 tentativas. Tentativa: " << contador << " de 3\n";
                cout << "Deseja retornar? S/N: ";
                cin >> input;
                if(input == "S" || input == "s"){
                    resultado_autenticacao.set_resultado(ResultadoUsuario::RETORNAR);
                    resultado_autenticacao.set_correio_eletronico(correio_eletronico);
                    return resultado_autenticacao;
                }
            }

            system(CLEAR);
            cout << "Digite seu email: ";
            cin >> input;
            correio_eletronico.set_correio_eletronico(input);
            cout << "\nDigite sua senha: ";
            cin >> input;
            senha.set_senha(input);

        } catch (const invalid_argument &exp) {
            cout << "\nEntrada com formato incorreto.\n";
            cout << "Pressione qualquer tecla para continuar: ";
            fflush(stdin);
            getchar();
            continue;
        }//end try catch

        resultado = cntr_link_autenticacao->Autenticar(correio_eletronico, senha);
        resultado_autenticacao = cntr_link_autenticacao->TipoDeUsuario(correio_eletronico, senha);
        if(resultado.get_resultado() == ResultadoUsuario::FALHA){
            cout << "Email ou Senha Invalido" << endl;
            cout << "Pressione qualquer tecla para continuar: ";
            fflush(stdin);
            getchar();
        } else {
            resultado_autenticacao.set_resultado(resultado.get_resultado());
            resultado_autenticacao.set_correio_eletronico(correio_eletronico);
            return resultado_autenticacao;
        }
        contador++;
    }//end while()
    resultado_autenticacao.set_resultado(ResultadoUsuario::RETORNAR);
    return resultado_autenticacao;
}//end Autenticar()

/*----------------------------------------------------------------------------*/

void ApresentacaoCadastroControle::ExecutarIA() throw (invalid_argument){
    ComandoCadastro *comando;
    int conta;

    do{
        system(CLEAR);
        cout << "Tipo de conta a ser cadastrada: " << endl;
        cout << "1. Leitor" << endl;
        cout << "2. Desenvolvedor" << endl;
        cout << "3. Administrador" << endl;
        cout << "4. Retornar" << endl;
        cin >> conta;
    }while(conta < 1 || conta > 4); //end do while

    switch (conta) {
        case LEITOR:
                comando = new ComandoCadastroLeitorIA();
                comando->ExecutarComando(cntr_link_cadastro);
                delete comando;
                break;
        case DESENVOLVEDOR:
            comando = new ComandoCadastroDesenvolvedorIA();
            comando->ExecutarComando(cntr_link_cadastro);
            delete comando;
            break;
        case ADMINISTRADOR:
            comando = new ComandoCadastroAdministradorIA();
            comando->ExecutarComando(cntr_link_cadastro);
            delete comando;
            break;
        case RETORNAR:
            return;
    }

}

/*----------------------------------------------------------------------------*/

void ApresentacaoUsuarioControle::Executar(ResultadoUsuario resultado_usuario) throw (invalid_argument){
    ComandoUsuario *comando;
    int escolha;
    while(true){
        do{
            system(CLEAR);
            cout << "Escolha o tipo de acao a ser realizada: " << endl;
            cout << "1. Exibir" << endl;
            cout << "2. Editar" << endl;
            cout << "3. Excluir" << endl;
            cout << "4. Retornar" << endl;
            cin >> escolha;
        } while (escolha < 1 || escolha > 4);

        switch (escolha) {
            case EXIBIR:
                comando = new ComandoExibir();
                comando->ExecutarComando(cntr_link_usuario, resultado_usuario);
                delete comando;
                break;
            case EDITAR:
                comando = new ComandoEditar();
                comando->ExecutarComando(cntr_link_usuario, resultado_usuario);
                delete comando;
                break;
            case EXCLUIR:
                comando = new ComandoExcluir();
                comando->ExecutarComando(cntr_link_usuario, resultado_usuario);
                delete comando;
                break;
            case RETORNAR:
                return;
        }
    }
}//end Executar

/*----------------------------------------------------------------------------*/

void ApresentacaoVocabularioControle::Executar(const ResultadoUsuario resultado_usuario) throw(invalid_argument){

    string input;
    string string_input;
    Nome nome;

    ComandoListarVocabularios *comando_listar_vocabularios;
    vector<VocControlado> lista_vocabularios;
    ComandoConsultarVocabulario *comando_consultar_vocabulario;
    vector<Termo> lista_termos;
    ComandoConsultarTermo *comando_consultar_termo;
    Termo termo;
    ComandoConsultarDefinicao *comando_consultar_definicao;


    do {
        cout<< "\nEscolha uma das opcoes abaixo:" << endl;
        cout<< "\n- Digite a letra L para listar vocabularios" << endl;
        if(resultado_usuario.tipo_de_usuario == resultado_usuario.ADMINISTRADOR) {
            cout<< "\n- Digite a letra C para criar vocabulario" << endl; //
        }
        cout<< "\n- Digite a letra R para retornar" << endl;
        cin >> input;

        //if(resultado_usuario.tipo_de_usuario == resultado_usuario.LEITOR) {
            if(input == "L") {
                system(CLEAR);
                comando_listar_vocabularios = new ComandoListarVocabularios();
                lista_vocabularios = comando_listar_vocabularios->ExecutarComando(cntr_link_vocabulario);
                delete comando_listar_vocabularios;
                do {
                    cout<< "\nEscolha uma das opcoes:" << endl;
                    cout<< "\n- Digite V para consultar vocabulario" << endl;
                    cout<< "\n- Digite R para retornar" << endl;
                    cin >> input;

                    if(input == "V") {

                        cout<< "\nDigite o nome do vocabulario que deseja consultar:" << endl;
                        cin >> string_input;

                        try{
                            nome.set_nome(string_input);
                        } catch(invalid_argument &exp) {
                            cout<< "\nNome invalido"<< endl;
                            continue;
                        }

                        try{
                            system(CLEAR);
                            comando_consultar_vocabulario = new ComandoConsultarVocabulario;
                            lista_termos = comando_consultar_vocabulario->ExecutarComando(cntr_link_vocabulario, lista_vocabularios, string_input);
                            delete comando_consultar_vocabulario;

                             do {
                                cout<< "\nEscolha uma das opcoes:" << endl;
                                cout<< "\n- Digite T para consultar termo" << endl;
                                cout<< "\n- Digite R para retornar" << endl;
                                cin >> input;

                                if(input == "T") {
                                    cout<< "\nDigite o nome do termo que deseja consultar:" << endl;
                                    cin >> string_input;


                                    try{
                                        nome.set_nome(string_input);
                                    } catch(invalid_argument &exp) {
                                        cout << "\n" << exp.what() << endl;
                                        continue;
                                    }

                                    try {
                                        system(CLEAR);
                                        comando_consultar_termo = new ComandoConsultarTermo;
                                        termo = comando_consultar_termo->ExecutarComando(cntr_link_vocabulario, lista_termos, string_input);
                                        delete comando_consultar_termo;

                                        do {
                                            cout <<"\nEscolha uma das opcoes:" << endl;
                                            cout <<"\n- Digite D para consultar definicao" << endl;
                                            cout <<"\n- Digite R para retornar" << endl;
                                            cin >> input;
                                            try {
                                                if(input == "D") {
                                                    system(CLEAR);
                                                    comando_consultar_definicao = new ComandoConsultarDefinicao;
                                                    comando_consultar_definicao->ExecutarComando(cntr_link_vocabulario, termo);
                                                    delete comando_consultar_definicao;

                                                    do {
                                                        cout<<"\nEscolha uma das opcoes:" << endl;
                                                        cout<<"\n-Digite R para retornar" << endl;
                                                        cout<<"\n-Digite S para sair" << endl;
                                                        cin >> input;

                                                        if(input == "R") {
                                                            break;
                                                        } else if(input == "S") {
                                                            return;
                                                        } else {
                                                            cout << "Escolha Invalida";
                                                        }

                                                    } while(input != "R" && input != "S");
                                                }else if(input == "R") {
                                                    break;
                                                } else {
                                                    cout << "Escolha Invalida" << endl;
                                                }
                                            } catch(invalid_argument &exp) {
                                                cout << "\n" << exp.what() << endl;
                                                continue;
                                            }
                                        } while (input != "D" && input != "R");

                                    } catch(invalid_argument &exp) {
                                        cout << "\n" << exp.what() << endl;
                                        continue;
                                    }
                                }else if(input == "R") {
                                    break;
                                } else {
                                    cout << "Escolha invalida" << endl;
                                }
                            } while(input != "T" && input != "R");

                        } catch(invalid_argument &exp) {
                            cout << endl << exp.what() << endl;
                            fflush(stdin);
                            getchar();
                            continue;
                        }
                    } else if(input == "R") {
                        break;
                    } else {
                        cout << "\nEscolha invalida." << endl;
                    }

                } while(input != "V" && input != "R");
            } else if(input == "R") {
                return;
            } else if((input == "C") && ((resultado_usuario.tipo_de_usuario == resultado_usuario.DESENVOLVEDOR) ||
                                        resultado_usuario.tipo_de_usuario == resultado_usuario.ADMINISTRADOR)){
                continue;
            } else {
                cout << "\nEscolha invalida\n" << endl;
                continue;
            }
        //}

       /* if(resultado_usuario.tipo_de_usuario == resultado_usuario.DESENVOLVEDOR) {
            if(input == "1") {
                system(CLEAR);
                comando_listar_vocabularios = new ComandoListarVocabularios();
                lista_vocabularios = comando_listar_vocabularios->ExecutarComando(cntr_link_vocabulario);
                delete comando_listar_vocabularios;
                do {
                    cout<< "\nEscolha uma das opcoes:" << endl;
                    cout<< "\n1- Consultar vocabulario" << endl;
                    cout<< "\n2- Retornar" << endl;
                    cin >> input;

                    if(input == "1") {

                        cout<< "\nDigite o nome do vocabulario que deseja consultar:" << endl;
                        cin >> string_input;

                        try{
                            nome.set_nome(string_input);
                        } catch(invalid_argument &exp) {
                            cout<< "\nNome invalido"<< endl;
                            continue;
                        }

                        try{
                            system(CLEAR);
                            comando_consultar_vocabulario = new ComandoConsultarVocabulario;
                            lista_termos = comando_consultar_vocabulario->ExecutarComando(cntr_link_vocabulario, lista_vocabularios, string_input);
                            delete comando_consultar_vocabulario;

                             do {
                                cout<< "\nEscolha uma das opcoes:" << endl;
                                cout<< "\n1- Consultar termo" << endl;
                                cout<< "\n2- Retornar" << endl;
                                cin >> input;

                                if(input == "1") {
                                    cout<< "\nDigite o nome do termo que deseja consultar:" << endl;
                                    cin >> string_input;


                                    try{
                                        nome.set_nome(string_input);
                                    } catch(invalid_argument &exp) {
                                        cout << "\n" << exp.what() << endl;
                                        continue;
                                    }

                                    try {
                                        system(CLEAR);
                                        comando_consultar_termo = new ComandoConsultarTermo;
                                        termo = comando_consultar_termo->ExecutarComando(cntr_link_vocabulario, lista_termos, string_input);
                                        delete comando_consultar_termo;

                                        do {
                                            cout <<"\nEscolha uma das opcoes:" << endl;
                                            cout <<"\n1- Consultar definicao" << endl;
                                            cout <<"\n2- Retornar" << endl;
                                            cin >> input;
                                            try {
                                                if(input == "1") {
                                                    system(CLEAR);
                                                    comando_consultar_definicao = new ComandoConsultarDefinicao;
                                                    comando_consultar_definicao->ExecutarComando(cntr_link_vocabulario, termo);
                                                    delete comando_consultar_definicao;

                                                    do {
                                                        cout<<"\nEscolha uma das opcoes:" << endl;
                                                        cout<<"\n1- Retornar" << endl;
                                                        cout<<"\n2- Sair" << endl;
                                                        cin >> input;

                                                        if(input == "1") {
                                                            break;
                                                        }

                                                        if(input == "2") {
                                                            return;
                                                        }

                                                    } while(input != "1" && input != "2");
                                                }

                                                if(input == "2") {
                                                    break;
                                                }
                                            } catch(invalid_argument &exp) {
                                                cout << "\n" << exp.what() << endl;
                                                continue;
                                            }
                                        } while (input != "1" && input != "2");

                                    } catch(invalid_argument &exp) {
                                        cout << "\n" << exp.what() << endl;
                                        continue;
                                    }
                                }

                                if(input == "2") {
                                    break;
                                }
                            } while(input != "1" && input != "2");

                        } catch(invalid_argument &exp) {
                            exp.what();
                            fflush(stdin);
                            getchar();
                            continue;
                        }
                    } else if(input == "2") {
                        break;
                    }

                } while(input != "1" && input != "2");
            } else if(input == "2") {
                return;
            } else {
                cout << "\nEscolha invalida\n" << endl;
                continue;
            }
        } */

      /*  if(resultado_usuario.tipo_de_usuario == resultado_usuario.ADMINISTRADOR) {
            if(input == "1") {
                system(CLEAR);
                comando_listar_vocabularios = new ComandoListarVocabularios();
                lista_vocabularios = comando_listar_vocabularios->ExecutarComando(cntr_link_vocabulario);
                delete comando_listar_vocabularios;
                do {
                    cout<< "\nEscolha uma das opcoes:" << endl;
                    cout<< "\n1- Consultar vocabulario" << endl;
                    cout<< "\n2- Retornar" << endl;
                    cin >> input;

                    if(input == "1") {

                        cout<< "\nDigite o nome do vocabulario que deseja consultar:" << endl;
                        cin >> string_input;

                        try{
                            nome.set_nome(string_input);
                        } catch(invalid_argument &exp) {
                            cout<< "\nNome invalido"<< endl;
                            continue;
                        }

                        try{
                            system(CLEAR);
                            comando_consultar_vocabulario = new ComandoConsultarVocabulario;
                            lista_termos = comando_consultar_vocabulario->ExecutarComando(cntr_link_vocabulario, lista_vocabularios, string_input);
                            delete comando_consultar_vocabulario;

                             do {
                                cout<< "\nEscolha uma das opcoes:" << endl;
                                cout<< "\n1- Consultar termo" << endl;
                                cout<< "\n2- Retornar" << endl;
                                cin >> input;

                                if(input == "1") {
                                    cout<< "\nDigite o nome do termo que deseja consultar:" << endl;
                                    cin >> string_input;


                                    try{
                                        nome.set_nome(string_input);
                                    } catch(invalid_argument &exp) {
                                        cout << "\n" << exp.what() << endl;
                                        continue;
                                    }

                                    try {
                                        system(CLEAR);
                                        comando_consultar_termo = new ComandoConsultarTermo;
                                        termo = comando_consultar_termo->ExecutarComando(cntr_link_vocabulario, lista_termos, string_input);
                                        delete comando_consultar_termo;

                                        do {
                                            cout <<"\nEscolha uma das opcoes:" << endl;
                                            cout <<"\n1- Consultar definicao" << endl;
                                            cout <<"\n2- Retornar" << endl;
                                            cin >> input;
                                            try {
                                                if(input == "1") {
                                                    system(CLEAR);
                                                    comando_consultar_definicao = new ComandoConsultarDefinicao;
                                                    comando_consultar_definicao->ExecutarComando(cntr_link_vocabulario, termo);
                                                    delete comando_consultar_definicao;

                                                    do {
                                                        cout<<"\nEscolha uma das opcoes:" << endl;
                                                        cout<<"\n1- Retornar" << endl;
                                                        cout<<"\n2- Sair" << endl;
                                                        cin >> input;

                                                        if(input == "1") {
                                                            break;
                                                        }

                                                        if(input == "2") {
                                                            return;
                                                        }

                                                    } while(input != "1" && input != "2");
                                                }

                                                if(input == "2") {
                                                    break;
                                                }
                                            } catch(invalid_argument &exp) {
                                                cout << "\n" << exp.what() << endl;
                                                continue;
                                            }
                                        } while (input != "1" && input != "2");

                                    } catch(invalid_argument &exp) {
                                        cout << "\n" << exp.what() << endl;
                                        continue;
                                    }
                                }

                                if(input == "2") {
                                    break;
                                }
                            } while(input != "1" && input != "2");

                        } catch(invalid_argument &exp) {
                            exp.what();
                            fflush(stdin);
                            getchar();
                            continue;
                        }
                    } else if(input == "2") {
                        break;
                    }

                } while(input != "1" && input != "2");
            } else if(input == "2") {
                return;
            } else {
                cout << "\nEscolha invalida\n" << endl;
                continue;
            }
        }
*/
    } while(true);

}
