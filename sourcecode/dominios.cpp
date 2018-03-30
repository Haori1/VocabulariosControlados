#include "dominios.hpp"
#include <iostream>
#include <string>

using namespace std;

void Nome::validation(string nome) throw (invalid_argument){
    if(nome[0] < 'A' || nome[0] > 'Z'){
        throw invalid_argument("A primeira letra deve ser maiuscula.");
    }
}