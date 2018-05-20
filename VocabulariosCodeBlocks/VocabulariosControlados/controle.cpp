#include <iostream>
#include <string>
#include <stdexcept>
#include <exception>

#include "controle.hpp"

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
