#include <iostream>
#include <string>
#include <stdexcept>
#include <exception>

#include "controle.hpp"

using namespace std;

/*----------------------------------------------------------------------------*/

bool ApresentacaoControle::Autenticar() throw (invalid_argument){
    Correio_Eletronico correio_eletronico;
    Senha senha;
    string input;
    int contador = 0;
    bool retorno = false;   //Temporário.

    while(contador != 3){
        try{
            if(contador != 0){
                cout << "Você possui 3 tentativas. Tentativa: " << contador << " de 3\n";
                cout << "Deseja retornar? S/N";
                cin >> input;
                if(input == "S" || input == "s"){
                    return false;   //Temporário.
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
        }//end try catch

        retorno = CntrLinkAut->Autenticar(correio_eletronico, senha);
        if(retorno == FALHA){
            cout << "Email ou Senha Inválido" << endl;
        }

        return retorno;

    }//end while()
    return retorno;
}//end Autenticar()

/*----------------------------------------------------------------------------*/
