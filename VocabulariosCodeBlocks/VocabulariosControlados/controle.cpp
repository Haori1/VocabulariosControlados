#include <iostream>
#include <stdexcept>
#include <exception>

#include "controle.hpp"

using namespace std;

/*----------------------------------------------------------------------------*/

void ApresentacaoControle::Controle(){
    do {
        system(CLEAR);
        cout << "\t\t\tVocabularios Controled\n\n\n";
        cout << "Escolha uma das opções: \n";
        cout << "1. Acessar conta\n";
        cout << "2. Cadastrar\n";
        cout << "3. Sair\n";
        cin >> escolha;
    } while(escolha > 3 || escolha < 1);

    switch (escolha) {
        case ACESSAR_CONTA: //Falta preencher com os métodos que serão chamados
            break;
        case CADASTRAR:
            break;
        case SAIR:
            exit(0);

    }
}//end Controle()
