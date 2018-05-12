#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>

#include "dominios.hpp"
#include "entidades.hpp"
#include "controle.hpp"
#include "interfaces.hpp"

#define ACESSAR_CONTA 1 //Defines temporários
#define CADASTRAR 2
#define SAIR 3

using namespace std;

int main(void){
    int escolha;
    do {
        system(CLEAR);
        cout << "\t\t\tVocabularios Controled\n\n";
        cout << "Escolha uma das opcoes: \n";
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

    return 0;
}
