#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>

#include "dominios.hpp"
#include "entidades.hpp"
#include "controle.hpp"
#include "interfaces.hpp"

using namespace std;

int main(void) {
    ApresentacaoControle menu;
    menu.Menu();
    return 0;
}
