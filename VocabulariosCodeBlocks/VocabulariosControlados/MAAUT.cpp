#ifndef __MAAUT_CPP__
#define __MAAUT_CPP__

#include "MAAUT.hpp"

Valida_Correio_Eletronico::Autentica(string email) {

this->email.set_correio_eletronico(email);

return (
        this->Email.get_correio_eletronico();
        );

}

Valida_Senha::Autentica(string senha) {

this->senha.set_senha(senha);

return (
        this->senha.get_senha();
        );

}

Controlador_AAUT::Testa_Validade(string email, string senha) {

    while(true) {

        try{
            Valida_Email_.Autentica(email);
            Valida_Senha_.Autentica(Senha);

            break;
        }catch{

        }

    }

}

Controlador_AAUT::autenticar() {




}
#endif
