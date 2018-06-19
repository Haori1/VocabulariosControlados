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

ResultadoUsuario ApresentacaoAutenticacaoControle::Autenticar() throw (invalid_argument)
{
    ResultadoUsuario resultado_autenticacao;
    ResultadoUsuario resultado;
    Correio_Eletronico correio_eletronico;
    Senha senha;
    string input;
    int contador = 0;

    while(contador != 4)
    {
        try
        {
            if(contador != 0)
            {
                system(CLEAR);
                cout << "Voce possui 3 tentativas. Tentativa: " << contador << " de 3\n";
                cout << "Deseja retornar? S/N: ";
                cin >> input;
                if(input == "S" || input == "s")
                {
                    resultado.set_resultado(ResultadoUsuario::RETORNAR);
                    resultado.set_correio_eletronico(correio_eletronico);
                    return resultado;
                }
            }

            system(CLEAR);
            cout << "Digite seu email: ";
            cin >> input;
            correio_eletronico.set_correio_eletronico(input);
            cout << "\nDigite sua senha: ";
            cin >> input;
            senha.set_senha(input);

        } catch (invalid_argument &exp) {
            cout << exp.what() << endl;
            cout << "Pressione qualquer tecla para continuar: ";
            fflush(stdin);
            getchar();
            continue;
        }//end try catch

        resultado = cntr_link_autenticacao->Autenticar(correio_eletronico, senha);
        //resultado_autenticacao = cntr_link_autenticacao->TipoDeUsuario(correio_eletronico, senha);
        if(resultado.get_resultado() == ResultadoUsuario::SUCESSO) {
            resultado.set_resultado(resultado.get_resultado());
            resultado.set_correio_eletronico(correio_eletronico);
            return resultado;
        }
        contador++;
    }//end while()
    resultado_autenticacao.set_resultado(ResultadoUsuario::RETORNAR);
    return resultado;
}//end Autenticar()

/*----------------------------------------------------------------------------*/

void ApresentacaoCadastroControle::ExecutarIA() throw (invalid_argument)
{
    ComandoCadastro *comando;
    int conta;

    do
    {
        system(CLEAR);
        cout << "Tipo de conta a ser cadastrada: " << endl;
        cout << "1. Leitor" << endl;
        cout << "2. Desenvolvedor" << endl;
        cout << "3. Administrador" << endl;
        cout << "4. Retornar" << endl;
        cin >> conta;
    }
    while(conta < 1 || conta > 4);  //end do while

    switch (conta)
    {
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

Resultado ApresentacaoUsuarioControle::Executar(ResultadoUsuario resultado_usuario) throw (invalid_argument){
    ComandoUsuario *comando;
    Resultado resultado;
    int escolha;
    while(true)
    {
        do
        {
            system(CLEAR);
            cout << "Escolha o tipo de acao a ser realizada: " << endl;
            cout << "1. Exibir" << endl;
            cout << "2. Editar" << endl;
            cout << "3. Excluir" << endl;
            cout << "4. Retornar" << endl;
            cin >> escolha;
        }
        while (escolha < 1 || escolha > 4);

        switch (escolha)
        {
        case EXIBIR:
            comando = new ComandoExibir();
            comando->ExecutarComando(cntr_link_usuario, resultado_usuario.get_correio_eletronico());
            delete comando;
            break;
        case EDITAR:
            comando = new ComandoEditar();
            comando->ExecutarComando(cntr_link_usuario, resultado_usuario.get_correio_eletronico());
            delete comando;
            break;
        case EXCLUIR:
            comando = new ComandoExcluir();
            comando->ExecutarComando(cntr_link_usuario, resultado_usuario.get_correio_eletronico());
            delete comando;
            break;
        case RETORNAR:
            resultado.set_resultado(Resultado::RETORNAR);
            return resultado;
        }
    }
}//end Executar

/*----------------------------------------------------------------------------*/

Resultado ApresentacaoVocabularioControle::Executar(const ResultadoUsuario &resultado_usuario) throw(invalid_argument){

    string input;
    string string_input;
    Nome nome;
    Resultado resultado;
    Resultado retorno;
    int contador = 0;
    int tamanho = 0;

    ComandoListarVocabularios *comando_listar_vocabularios;
    vector<VocControlado> lista_vocabularios;

    ComandoConsultarVocabulario *comando_consultar_vocabulario;
    vector<Termo> lista_termos;

    ComandoConsultarTermo *comando_consultar_termo;
    Termo termo;

    ComandoConsultarDefinicao *comando_consultar_definicao;

    ComandoCriarVocabulario *comando_criar_vocabulario;

    VocControlado voc_aux;
    string voc_atual;
    ComandoExcluirVocabulario *comando_excluir_vocabulario;
    ComandoAlterarIdiomaVoc *comando_alterar_idioma_voc;
    ComandoEditarDefinicaoVoc *comando_editar_definicao_voc;

    Termo termo_aux;
    ComandoCriarTermo *comando_criar_termo;
    ComandoExcluirTermo *comando_excluir_termo;
    ComandoEditarTermo *comando_editar_termo;
    ComandoEditarDefinicaoTermo *comando_editar_definicao_termo;


    do
    {
        cout<< "\nEscolha uma das opcoes abaixo:" << endl;
        cout<< "\n- Digite a letra L para listar vocabularios" << endl;
        if(resultado_usuario.tipo_de_usuario == resultado_usuario.ADMINISTRADOR)
        {
            cout<< "\n- Digite a letra C para criar vocabulario" << endl;
        }
        cout<< "\n- Digite a letra R para retornar" << endl;
        cin >> input;

        if(input == "L")
        {
            system(CLEAR);
            comando_listar_vocabularios = new ComandoListarVocabularios();
            lista_vocabularios = comando_listar_vocabularios->ExecutarComando(cntr_link_vocabulario);
            delete comando_listar_vocabularios;
            do
            {
                cout<< "\nEscolha uma das opcoes:" << endl;
                cout<< "\n- Digite V para consultar vocabulario" << endl;
                if(resultado_usuario.tipo_de_usuario == resultado_usuario.ADMINISTRADOR)
                {
                    cout<< "\n- Digite E para excluir vocabulario" << endl;
                    cout<< "\n- Digite I para editar idioma de vocabulario" << endl;
                }
                cout<< "\n- Digite R para retornar" << endl;
                cin >> input;

                if(input == "V")
                {

                    cout<< "\nDigite o nome do vocabulario que deseja consultar:" << endl;
                    cin >> string_input;

                    try
                    {
                        nome.set_nome(string_input);
                    }
                    catch(invalid_argument &exp)
                    {
                        cout<< exp.what() << endl;
                        fflush(stdin);
                        getchar();
                        continue;
                    }

                    try
                    {
                        system(CLEAR);
                        comando_consultar_vocabulario = new ComandoConsultarVocabulario;
                        lista_termos = comando_consultar_vocabulario->ExecutarComando(cntr_link_vocabulario, lista_vocabularios, string_input);
                        voc_atual = string_input;
                        delete comando_consultar_vocabulario;

                        do
                        {
                            cout<< "\nEscolha uma das opcoes:" << endl;
                            cout<< "\n- Digite T para consultar termo" << endl;
                            if((resultado_usuario.tipo_de_usuario == resultado_usuario.ADMINISTRADOR) ||
                                    (resultado_usuario.tipo_de_usuario == resultado_usuario.DESENVOLVEDOR))
                            {
                                cout<< "\n- Digite C para criar termo" << endl;
                                cout<< "\n- Digite E para excluir termo" << endl;
                                cout<< "\n- Digite TE para editar termo" << endl;
                                cout<< "\n- Digite ED para editar definicao termo" << endl;
                                cout<< "\n- Digite EV para editar definicao vocabulario" << endl;
                            }
                            cout<< "\n- Digite R para retornar" << endl;
                            cin >> input;

                            if(input == "T")
                            {
                                cout<< "\nDigite o nome do termo que deseja consultar:" << endl;
                                cin >> string_input;


                                try
                                {
                                    nome.set_nome(string_input);
                                }
                                catch(invalid_argument &exp)
                                {
                                    cout << "\n" << exp.what() << endl;
                                    fflush(stdin);
                                    getchar();
                                    continue;
                                }

                                try
                                {
                                    system(CLEAR);
                                    comando_consultar_termo = new ComandoConsultarTermo;
                                    termo = comando_consultar_termo->ExecutarComando(cntr_link_vocabulario, lista_termos, string_input);
                                    delete comando_consultar_termo;

                                    do
                                    {
                                        cout <<"\nEscolha uma das opcoes:" << endl;
                                        cout <<"\n- Digite D para consultar definicao" << endl;
                                        cout <<"\n- Digite R para retornar" << endl;
                                        cin >> input;
                                        try
                                        {
                                            if(input == "D")
                                            {
                                                system(CLEAR);
                                                comando_consultar_definicao = new ComandoConsultarDefinicao;
                                                comando_consultar_definicao->ExecutarComando(cntr_link_vocabulario, termo);
                                                delete comando_consultar_definicao;

                                                do
                                                {
                                                    cout<<"\nEscolha uma das opcoes:" << endl;
                                                    cout<<"\n-Digite R para retornar" << endl;
                                                    cout<<"\n-Digite S para sair" << endl;
                                                    cin >> input;

                                                    if(input == "R")
                                                    {
                                                        break;
                                                    }
                                                    else if(input == "S")
                                                    {
                                                        retorno.set_resultado(Resultado::RETORNAR);
                                                        return retorno;
                                                    }
                                                    else
                                                    {
                                                        cout << "Escolha Invalida";
                                                    }

                                                }
                                                while(input != "R" && input != "S");
                                            }
                                            else if(input == "R")
                                            {
                                                break;
                                            }
                                            else
                                            {
                                                cout << "Escolha Invalida" << endl;
                                            }
                                        }
                                        catch(invalid_argument &exp)
                                        {
                                            cout << "\n" << exp.what() << endl;
                                            fflush(stdin);
                                            getchar();
                                            continue;
                                        }
                                    }
                                    while (input != "D" && input != "R");

                                }
                                catch(invalid_argument &exp)
                                {
                                    cout << "\n" << exp.what() << endl;
                                    continue;
                                }
                            } else
                            if((input == "ED") && ( (resultado_usuario.tipo_de_usuario == resultado_usuario.ADMINISTRADOR) ||
                                                    (resultado_usuario.tipo_de_usuario == resultado_usuario.DESENVOLVEDOR)
                                                  ))
                            {

                                do
                                {
                                    cout<< "\nDigite o nome do Termo que deseja editar a definicao:" << endl;
                                    cin >> string_input;
                                    try
                                    {
                                        nome.set_nome(string_input);
                                    }
                                    catch(invalid_argument &exp)
                                    {
                                        cout<< "\nNome invalido"<< endl;
                                        continue;
                                    }
                                    tamanho = lista_vocabularios.size();
                                    int i = 0;
                                    for(i = 0; i < tamanho; i++)
                                    {
                                        if(lista_termos[i].get_nome().get_nome() == string_input)
                                        {
                                            termo_aux = lista_termos[i];
                                            break;
                                        }
                                        if(i == tamanho - 1)
                                        {
                                            cout << "\nTermo nao encontado" << endl;
                                            cout << "\nPressione qualquer tecla para continuar:" << endl;
                                            fflush(stdin);
                                            getchar();
                                            retorno.set_resultado(Resultado::RETORNAR);
                                            return retorno;
                                        }
                                    }
                                    comando_editar_definicao_termo = new ComandoEditarDefinicaoTermo;
                                    resultado = comando_editar_definicao_termo->Executar(cntr_link_vocabulario, termo_aux);
                                    delete comando_editar_definicao_termo;

                                    if(resultado.get_resultado() == Resultado::FALHA)
                                    {
                                        cout << "\nOperacao nao realizada com sucesso" << endl;
                                        cout << "\nPressione S para tentar novamente, ou qualquer outra tecla para sair" << endl;
                                        cin >> string_input;
                                        if(string_input == "S")
                                        {
                                            continue;
                                        }
                                        else
                                        {
                                            break;
                                        }
                                    }
                                    else if(resultado.get_resultado() == Resultado::SUCESSO)
                                    {
                                        cout << "\nOperacao realizada com sucesso" << endl;
                                        cout << "\nPressione qualquer tecla para continuar" << endl;
                                        fflush(stdin);
                                        getchar();
                                        break;
                                    }
                                }
                                while(true);
                            } else if((input == "EV") && ( (resultado_usuario.tipo_de_usuario == resultado_usuario.ADMINISTRADOR) ||
                                                        (resultado_usuario.tipo_de_usuario == resultado_usuario.DESENVOLVEDOR)
                                                      ))
                            {
                                do {
                                    comando_editar_definicao_voc = new ComandoEditarDefinicaoVoc();
                                    resultado = comando_editar_definicao_voc->Executar(cntr_link_vocabulario, voc_atual);
                                    delete comando_editar_definicao_voc;

                                    if(resultado.get_resultado() == Resultado::FALHA)
                                    {
                                        cout << "\nOperacao nao realizada com sucesso" << endl;
                                        cout << "\nPressione S para tentar novamente, ou qualquer outra tecla para sair" << endl;
                                        cin >> string_input;
                                        if(string_input == "S")
                                        {
                                            continue;
                                        }
                                        else
                                        {
                                            break;
                                        }
                                    }
                                    else if(resultado.get_resultado() == Resultado::SUCESSO)
                                    {
                                        cout << "\nOperacao realizada com sucesso" << endl;
                                        cout << "\nPressione qualquer tecla para continuar" << endl;
                                        fflush(stdin);
                                        getchar();
                                        break;
                                    }
                                } while(true);
                            }
                            else if((input == "C") && ( (resultado_usuario.tipo_de_usuario == resultado_usuario.ADMINISTRADOR) ||
                                                        (resultado_usuario.tipo_de_usuario == resultado_usuario.DESENVOLVEDOR)
                                                      ))
                            {
                                contador = 3;
                                comando_criar_termo = new ComandoCriarTermo();
                                do
                                {

                                    resultado = comando_criar_termo->Executar(cntr_link_vocabulario, voc_atual);


                                    if(resultado.get_resultado() == Resultado::SUCESSO)
                                    {
                                        cout << "Pressione qualquer tecla para continuar: ";
                                        fflush(stdin);
                                        getchar();
                                        retorno.set_resultado(Resultado::RETORNAR);
                                        return retorno;
                                    }
                                    else if(resultado.get_resultado() == Resultado::FALHA)
                                    {
                                        cout << "\nClique S para continuar ou qualquer outra tecla para sair, voce tem " << contador << " tentativas" << endl;
                                        cin >> string_input;
                                        if(string_input == "S")
                                        {
                                            contador--;
                                            continue;
                                        }
                                        else
                                        {
                                            break;
                                        }
                                    }

                                }
                                while(contador > 0);
                                delete comando_criar_termo;
                            }
                            else if((input == "E") && ( (resultado_usuario.tipo_de_usuario == resultado_usuario.ADMINISTRADOR) ||
                                                        (resultado_usuario.tipo_de_usuario == resultado_usuario.DESENVOLVEDOR)
                                                      ))
                            {
                                do
                                {
                                    cout<< "\nDigite o nome do Termo que deseja excluir:" << endl;
                                    cin >> string_input;
                                    try
                                    {
                                        nome.set_nome(string_input);
                                    }
                                    catch(invalid_argument &exp)
                                    {
                                        cout<< endl << exp.what() << endl;
                                        fflush(stdin);
                                        getchar();
                                        continue;
                                    }
                                    tamanho = lista_termos.size();
                                    int i = 0;
                                    for(i = 0; i < tamanho; i++)
                                    {
                                        if(lista_termos[i].get_nome().get_nome() == string_input)
                                        {
                                            termo_aux = lista_termos[i];
                                            break;
                                        }
                                        if(i == tamanho - 1)
                                        {
                                            cout << "\nTermo nao encontado" << endl;
                                            cout << "\nPressione qualquer tecla para continuar:" << endl;
                                            fflush(stdin);
                                            getchar();
                                            retorno.set_resultado(Resultado::RETORNAR);
                                            return retorno;
                                        }
                                    }
                                    try
                                    {
                                        comando_excluir_termo = new ComandoExcluirTermo();
                                        resultado = comando_excluir_termo->Executar(cntr_link_vocabulario, termo_aux);
                                        delete comando_excluir_termo;
                                    }
                                    catch(invalid_argument &exp)
                                    {
                                        cout << "\n" << exp.what() << endl;
                                        retorno.set_resultado(Resultado::RETORNAR);
                                        return retorno;
                                    }
                                    if(resultado.get_resultado() == Resultado::FALHA)
                                    {
                                        cout << "\n" << "falha ao excluir, pressione S para tentar novamente, ou qualquer tecla para sair" << endl;
                                        cin >> string_input;
                                        if(string_input == "S")
                                        {
                                            continue;
                                        }
                                        else
                                        {
                                            retorno.set_resultado(Resultado::RETORNAR);
                                            return retorno;
                                        }
                                    }
                                    else if(resultado.get_resultado() == Resultado::SUCESSO)
                                    {
                                        cout << "\n" << "Termo excluido com sucesso, pressione S para excluir mais um termo, ou qualquer tecla para sair" << endl;
                                        cin >> string_input;
                                        if(string_input == "S")
                                        {
                                            continue;
                                        }
                                        else
                                        {
                                            retorno.set_resultado(Resultado::RETORNAR);
                                            return retorno;
                                        }
                                    }
                                    else if(resultado.get_resultado() == Resultado::RETORNAR)
                                    {
                                        retorno.set_resultado(Resultado::RETORNAR);
                                        return retorno;
                                    }
                                }
                                while(true);
                            }
                            else if((input == "TE") && ( (resultado_usuario.tipo_de_usuario == resultado_usuario.ADMINISTRADOR) ||
                                                         (resultado_usuario.tipo_de_usuario == resultado_usuario.DESENVOLVEDOR)
                                                       ))
                            {
                                do
                                {
                                    cout<< "\nDigite o nome do Termo que deseja editar:" << endl;
                                    cin >> string_input;
                                    try
                                    {
                                        nome.set_nome(string_input);
                                    }
                                    catch(invalid_argument &exp)
                                    {
                                        cout << endl << exp.what() << endl;
                                        fflush(stdin);
                                        getchar();
                                        continue;
                                    }
                                    tamanho = lista_vocabularios.size();
                                    int i = 0;
                                    for(i = 0; i < tamanho; i++)
                                    {
                                        if(lista_termos[i].get_nome().get_nome() == string_input)
                                        {
                                            termo_aux = lista_termos[i];
                                            break;
                                        }
                                        if(i == tamanho - 1)
                                        {
                                            cout << "\nTermo nao encontado" << endl;
                                            cout << "\nPressione qualquer tecla para continuar:" << endl;
                                            fflush(stdin);
                                            getchar();
                                            retorno.set_resultado(Resultado::RETORNAR);
                                            return retorno;
                                        }
                                    }
                                    comando_editar_termo = new ComandoEditarTermo;
                                    resultado = comando_editar_termo->Executar(cntr_link_vocabulario, termo_aux);
                                    delete comando_editar_termo;

                                    if(resultado.get_resultado() == Resultado::FALHA)
                                    {
                                        cout << "\nOperacao nao realizada com sucesso" << endl;
                                        cout << "\nPressione S para tentar novamente, ou qualquer outra tecla para sair" << endl;
                                        cin >> string_input;
                                        if(string_input == "S")
                                        {
                                            continue;
                                        }
                                        else
                                        {
                                            break;
                                        }
                                    }
                                    else if(resultado.get_resultado() == Resultado::SUCESSO)
                                    {
                                        cout << "\nOperacao realizada com sucesso" << endl;
                                        cout << "\nPressione qualquer tecla para continuar" << endl;
                                        fflush(stdin);
                                        getchar();
                                        break;
                                    }
                                }
                                while(true);

                            }
                            else if(input == "R")
                            {
                                break;
                            }
                            else
                            {
                                cout << "Escolha invalida" << endl;
                            }
                        }
                        while(input != "T" && input != "R");

                    }
                    catch(invalid_argument &exp)
                    {
                        cout << endl << exp.what() << endl;
                        fflush(stdin);
                        getchar();
                        continue;
                    }
                }
                else if((input == "I") && (resultado_usuario.tipo_de_usuario == resultado_usuario.ADMINISTRADOR))
                {
                    do
                    {
                        cout<< "\nDigite o nome do vocabulario do qual deseja editar o idioma:" << endl;
                        cin >> string_input;
                        try
                        {
                            nome.set_nome(string_input);
                        }
                        catch(invalid_argument &exp)
                        {
                            cout << endl << exp.what() << endl;
                            continue;
                        }
                        tamanho = lista_vocabularios.size();
                        int i = 0;
                        for(i = 0; i < tamanho; i++)
                        {
                            if(lista_vocabularios[i].get_nome().get_nome() == string_input)
                            {
                                voc_aux = lista_vocabularios[i];
                                break;
                            }
                            if(i == tamanho - 1)
                            {
                                cout << "\nVocabulario nao encontado" << endl;
                                cout << "\nPressione qualquer tecla para continuar:" << endl;
                                fflush(stdin);
                                getchar();
                                retorno.set_resultado(Resultado::RETORNAR);
                                return retorno;
                            }
                        }
                        comando_alterar_idioma_voc = new ComandoAlterarIdiomaVoc;
                        resultado = comando_alterar_idioma_voc->Executar(cntr_link_vocabulario, voc_aux);
                        delete comando_alterar_idioma_voc;

                        if(resultado.get_resultado() == Resultado::FALHA)
                        {
                            cout << "\nOperacao nao realizada com sucesso" << endl;
                            cout << "\nPressione S para tentar novamente, ou qualquer outra tecla para sair" << endl;
                            cin >> string_input;
                            if(string_input == "S")
                            {
                                continue;
                            }
                            else
                            {
                                break;
                            }
                        }
                        else if(resultado.get_resultado() == Resultado::SUCESSO)
                        {
                            cout << "\nOperacao realizada com sucesso" << endl;
                            cout << "\nPressione qualquer tecla para continuar" << endl;
                            fflush(stdin);
                            getchar();
                            break;
                        }
                    }
                    while(true);
                }
                else if(input == "R")
                {
                    break;
                }
                else if((input == "E") && (resultado_usuario.tipo_de_usuario == resultado_usuario.ADMINISTRADOR))
                {
                    do
                    {
                        cout<< "\nDigite o nome do vocabulario que deseja excluir:" << endl;
                        cin >> string_input;
                        try
                        {
                            nome.set_nome(string_input);
                        }
                        catch(invalid_argument &exp)
                        {
                            cout << endl << exp.what() << endl;
                            continue;
                        }
                        tamanho = lista_vocabularios.size();
                        int i = 0;
                        for(i = 0; i < tamanho; i++)
                        {
                            if(lista_vocabularios[i].get_nome().get_nome() == string_input)
                            {
                                voc_aux = lista_vocabularios[i];
                                break;
                            }
                            if(i == tamanho - 1)
                            {
                                cout << "\nVocabulario nao encontado" << endl;
                                cout << "\nPressione qualquer tecla para continuar:" << endl;
                                fflush(stdin);
                                getchar();
                                retorno.set_resultado(Resultado::RETORNAR);
                                return retorno;
                            }
                        }
                        try
                        {
                            comando_excluir_vocabulario = new ComandoExcluirVocabulario();
                            resultado = comando_excluir_vocabulario->Executar(cntr_link_vocabulario, voc_aux);
                            delete comando_excluir_vocabulario;
                        }
                        catch(invalid_argument &exp)
                        {
                            cout << endl << exp.what() << endl;
                            retorno.set_resultado(Resultado::RETORNAR);
                            return retorno;
                        }
                        if(resultado.get_resultado() == Resultado::FALHA)
                        {
                            cout << "\n" << "falha ao excluir, pressione S para tentar novamente, ou qualquer tecla para sair" << endl;
                            cin >> string_input;
                            if(string_input == "S")
                            {
                                continue;
                            }
                            else
                            {
                                retorno.set_resultado(Resultado::RETORNAR);
                                return retorno;
                            }
                        }
                        else if(resultado.get_resultado() == Resultado::SUCESSO)
                        {
                            cout << "\n" << "Vocabulario excluido com sucesso, pressione S para excluir mais um vocabulario, ou qualquer tecla para sair" << endl;
                            cin >> string_input;
                            if(string_input == "S")
                            {
                                continue;
                            }
                            else
                            {
                                retorno.set_resultado(Resultado::RETORNAR);
                                return retorno;
                            }
                        }
                        else if(resultado.get_resultado() == Resultado::RETORNAR)
                        {
                            retorno.set_resultado(Resultado::RETORNAR);
                            return retorno;
                        }
                    }
                    while(true);
                }
                else
                {
                    cout << "\nEscolha invalida." << endl;
                }

            }
            while(input != "V" && input != "R" && input != "E");
        }
        else if(input == "R")
        {
            retorno.set_resultado(Resultado::RETORNAR);
            return retorno;
        }
        else if((input == "C") && (resultado_usuario.tipo_de_usuario == resultado_usuario.ADMINISTRADOR))
        {
            contador = 3;
            comando_criar_vocabulario = new ComandoCriarVocabulario();
            do
            {

                resultado = comando_criar_vocabulario->Executar(cntr_link_vocabulario, resultado_usuario);

                if(resultado.get_resultado() == Resultado::SUCESSO)
                {
                    cout << "Pressione qualquer tecla para continuar: ";
                    fflush(stdin);
                    getchar();
                    retorno.set_resultado(Resultado::RETORNAR);
                    return retorno;
                }
                else if(resultado.get_resultado() == Resultado::FALHA)
                {
                    cout << "\nClique S para continuar ou qualquer outra tecla para sair, voce tem " << contador << " tentativas" << endl;
                    cin >> string_input;
                    if(string_input == "S")
                    {
                        contador--;
                        continue;
                    }
                    else
                    {
                        break;
                    }
                }

            }
            while(contador > 0);
            delete comando_criar_vocabulario;
        }
        else
        {
            cout << "\nEscolha invalida\n" << endl;
            continue;
        }
    }
    while(true);

}
