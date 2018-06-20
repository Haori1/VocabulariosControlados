#ifndef __CONTROLE__HPP_
#define __CONTROLE__HPP_

#include <stdexcept>
#include <exception>

#include "dominios.hpp"
#include "interfaces.hpp"
#include "comandos.hpp"
#include "servicos.hpp"

#define CLEAR "cls||clear"

using namespace std;

/**
 * @file controle.hpp
 * @author Henrique Mendes de Freitas Mariano
 * @author Gabriel Alves Castro
 * @date 18 de maio de 2018
 *
 * @brief Classes controladoras que gerenciam o sistema.
 *
 */

/*----------------------------------------------------------------------------*/

/**
 * @brief Classe com a funcao de controlar os servicos de autenticacao.
 *
 */

class ApresentacaoAutenticacaoControle : public AutenticacaoIA
{
private:
    /**
     * @brief Referencia para a camada de servicos.
     *
     */
    AutenticacaoIS* cntr_link_autenticacao;

public:
    ResultadoUsuario Autenticar() throw (invalid_argument) override;
    void set_aut_ia(AutenticacaoIS *) override;
};
/**
 * @brief A funcao tem como responsabilidade linkar a camada de apresentacao com a camada de servicos.
 *
 */
void inline ApresentacaoAutenticacaoControle::set_aut_ia(AutenticacaoIS* cntr_link_autenticacao)
{
    this->cntr_link_autenticacao = cntr_link_autenticacao;
}

/*----------------------------------------------------------------------------*/

/**
 * @brief Classe com a funcao de controlar os servicos do cadastro.
 *
 */

class ApresentacaoCadastroControle : public CadastroIA
{
private:
    const static int LEITOR = 1;
    const static int DESENVOLVEDOR = 2;
    const static int ADMINISTRADOR = 3;
    const static int RETORNAR = 4;
    /**
     * @brief Referencia para a camada de servicos.
     *
     */
    CadastroIS* cntr_link_cadastro;

public:
    void ExecutarIA() throw (invalid_argument) override;
    void set_cadastro_ia(CadastroIS *) override;
};
/**
 * @brief A funcao tem como responsabilidade linkar a camada de apresentacao com a camada de servicos.
 *
 */
void inline ApresentacaoCadastroControle::set_cadastro_ia(CadastroIS* cntr_link_cadastro)
{
    this->cntr_link_cadastro = cntr_link_cadastro;
}

/*----------------------------------------------------------------------------*/

/**
 * @brief Classe com a funcao de controlar os servicos do usuario.
 *
 */

class ApresentacaoUsuarioControle : public UsuarioIA {
private:
    const static int EXIBIR = 1;
    const static int EDITAR = 2;
    const static int EXCLUIR = 3;
    const static int RETORNAR = 4;
    /**
     * @brief Referencia para a camada de servicos.
     *
     */
    UsuarioIS* cntr_link_usuario;

public:
    Resultado Executar(ResultadoUsuario resultado_usuario) throw (invalid_argument) override;
    void set_usuario_ia(UsuarioIS *) override;
};
/**
 * @brief A funcao tem como responsabilidade linkar a camada de apresentacao com a camada de servicos.
 *
 */
void inline ApresentacaoUsuarioControle::set_usuario_ia(UsuarioIS* cntr_link_usuario) {
    this->cntr_link_usuario = cntr_link_usuario;
}

/*----------------------------------------------------------------------------*/

/**
 * @brief Classe com a funcao de controlar os servicos do vocabulario.
 *
 */

 class ApresentacaoVocabularioControle : public VocabulariosIA
 {
 private:
     /**
      * @brief Referencia para a camada de servicos.
      *
      */
     VocabulariosIS *cntr_link_vocabulario;

 public:
     Resultado Executar(ResultadoUsuario&) throw (invalid_argument) override;
     void set_vocabulario_ia(VocabulariosIS *) override;
 };
 /**
  * @brief A funcao tem como responsabilidade linkar a camada de apresentacao com a camada de servicos.
  *
  */
 void inline ApresentacaoVocabularioControle::set_vocabulario_ia(VocabulariosIS* cntr_link_vocabulario)
 {
     this->cntr_link_vocabulario = cntr_link_vocabulario;
 }

/*----------------------------------------------------------------------------*/
#endif
