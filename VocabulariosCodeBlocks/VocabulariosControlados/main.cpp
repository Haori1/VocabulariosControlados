#include <iostream>
#include <string>
#include "dominiosClasses.hpp"
#include "testes.hpp"

int main(void) {
    TNome nome;
    bool x = nome.run();
    if(x){
        cout << "Sucesso" << endl;
    } else {
        cout << "Falha" << endl;
    }
    return 0;
}
