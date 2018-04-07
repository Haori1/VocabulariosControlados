#include <iostream>
#include <string>
#include "dominiosClasses.hpp"
#include "testes.hpp"

int main(void) {
    TData data;
    bool x = data.run();
    if(x){
        cout << "SUCESSO" << endl;
    } else {
        cout << "FALHA" << endl;
    }
}
