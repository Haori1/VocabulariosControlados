#include "comandos.hpp"

void ComandoCadastroLeitorIA::Executar(CadastroIS* cntr_link_cadastro) throw (invalid_argument){
    int conta;
    Leitor leitor;
    Desenvolvedor desenvolvedor;
    Administrador administrador;
    string input;
    ResultadoUsuario resultado_cadastro;
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
            }while(conta < 1 || conta > 4);

            switch(conta){
                case LEITOR:
                    resultado_cadastro = cntr_link_cadastro->CadastroLeitor(leitor);
                    break;
                case DESENVOLVEDOR:
                    resultado_cadastro = cntr_link_cadastro->CadastroDesenvolvedor(desenvolvedor);
                    break;
                case ADMINISTRADOR:
                    resultado_cadastro = cntr_link_cadastro->CadastroAdministrador(administrador);
                    break;

            }//end switch()

        } catch (invalid_argument &exp) {
            cout << endl <<"Formato incorreto" << endl;

        }//end try catch
    }//end while(true)
}//end Executar()
