#ifndef __SERVICO_HPP__
#define __SERVICO_HPP__

#include "controle.hpp"
#include "dominios.hpp"
#include "entidades.hpp"
#include "interfaces.hpp"
#include "comandoSQL.hpp"

using namespace std;

class ControleCadastro : public CadastroIS {
    private:
        Leitor leitor;
        Desenvolvedor desenvolvedor;
        Administrador administrador;

    public:
        Resultado CadastroLeitor(const Nome &nome, const Sobrenome &sobrenome,
                                 const Correio_Eletronico &correio_eletronico, const Senha &senha) throw (invalid_argument) override;

        Resultado CadastroDesenvolvedor(const Nome &nome, const Sobrenome &sobrenome,
                                        const Data &data_nascimento, const Correio_Eletronico &correio_eletronico,
                                        const Senha &senha) throw (invalid_argument) override;

        Resultado CadastroAdministrador(const Nome &nome, const Sobrenome &sobrenome,
                                        const Telefone &telefone, const Data &data_nascimento,
                                        const Endereco &endereco, const Correio_Eletronico &correio_eletronico,
                                        const Senha &senha) throw (invalid_argument) override;
};




#endif