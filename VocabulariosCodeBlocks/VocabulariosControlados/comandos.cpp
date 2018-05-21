#include "comandos.hpp"

Resultado ComandoCadastroIA::Executar(CadastroIS* cntr_link_cadastro) throw (invalid_argument){
    int conta;
    Leitor leitor;
    Desenvolvedor desenvolvedor;
    Administrador administrador;
    string input;
    Resultado resultado_cadastro;
    Nome nome;
    Sobrenome sobrenome;
    Correio_Eletronico correio_eletronico;
    Senha senha;

    while(true){
        try{
            do{
                cout << "Tipo de conta a ser cadastrada: " << endl;
                cout << "1. Leitor" << endl;
                cout << "2. Desenvolvedor" << endl;
                cout << "3. Administrador" << endl;
                cout << "4. Retornar" << endl;
                cin >> conta;
            }while(conta < 1 || conta > 4); //end do while

            if(conta == RETORNAR){
                resultado_cadastro.set_resultado(Resultado::RETORNAR);
                return resultado_cadastro;
            }

        } catch (invalid_argument &exp) {
            cout << endl <<"Formato incorreto" << endl;
            cout << "Pressione qualquer tecla para continuar: ";
            fflush(stdin);
            getchar();
        }//end try catch

            switch(conta){
                case LEITOR:
                    try{
                        resultado_cadastro = cntr_link_cadastro->CadastroLeitor(leitor);
                    } catch (invalid_argument &exp) {
                        cout << endl << "Erro de sistema" << endl;
                        cout << "Pressione qualquer tecla para continuar: ";
                        fflush(stdin);
                        getchar();
                    }
                    return resultado_cadastro;
                    break;
                case DESENVOLVEDOR:
                    try{
                        resultado_cadastro = cntr_link_cadastro->CadastroDesenvolvedor(desenvolvedor);
                    } catch (invalid_argument &exp) {
                        cout << endl << "Erro de sistema" << endl;
                        cout << "Pressione qualquer tecla para continuar: ";
                        fflush(stdin);
                        getchar();
                    }
                    return resultado_cadastro;
                    break;
                case ADMINISTRADOR:
                    try{
                        resultado_cadastro = cntr_link_cadastro->CadastroAdministrador(administrador);
                    } catch (invalid_argument &exp) {
                        cout << endl << "Erro de sistema" << endl;
                        cout << "Pressione qualquer tecla para continuar: ";
                        fflush(stdin);
                        getchar();
                    }
                    return resultado_cadastro;
                    break;
            }//end switch()
    }//end while(true)
    return resultado_cadastro;
}//end Executar()
