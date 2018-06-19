#ifndef __COMANDOS_HPP__
#define __COMANDOS_HPP__

#include <iostream>
#include <stdexcept>
#include <exception>
#include <cstdlib>

#include "interfaces.hpp"
#include "dominios.hpp"
#include "entidades.hpp"
#include "servicos.hpp"
#include "controle.hpp"
#include "ComandoSQL.hpp"

using namespace std;

/**
 * @file comandos.hpp
 * @author Henrique Mendes de Freitas Mariano
 * @author Gabriel Alves Castro
 * @date 18 de maio de 2018
 *
 * @brief Comandos para a execucao dos servicos.
 *
 */

/*----------------------------------------------------------------------------*/

/**
 * @brief Classe abstrata que define os comandos de cadastro.
 *
 */

class ComandoCadastro
{
public:
    virtual void ExecutarComando(CadastroIS *) throw (invalid_argument) = 0; //Interface dos comandos
    virtual ~ComandoCadastro() {}

};

/**
 * @brief Classe que define a execucao dos comandos para o cadastro de Leitor.
 *
 */

class ComandoCadastroLeitorIA : public ComandoCadastro
{
public:
    void ExecutarComando(CadastroIS *) throw (invalid_argument) override;
};


/**
 * @brief Classe que define a execucao dos comandos para o cadastro de Desenvolvedor.
 *
 */

class ComandoCadastroDesenvolvedorIA : public ComandoCadastro
{
public:
    void ExecutarComando(CadastroIS *) throw (invalid_argument) override;

};

/**
 * @brief Classe que define a execucao dos comandos para o cadastro de Administrador.
 *
 */

class ComandoCadastroAdministradorIA : public ComandoCadastro
{
public:
    void ExecutarComando(CadastroIS *) throw (invalid_argument) override;
};

/*----------------------------------------------------------------------------*/

/**
 * @brief Classe abstrata que define os comandos de usuario.
 *
 */

class ComandoUsuario
{
public:
    virtual Resultado ExecutarComando(UsuarioIS *, const Correio_Eletronico&) throw (invalid_argument) = 0;
    virtual ~ComandoUsuario() {}
};

/**
 * @brief Classe que define a execucao do comando para o servico do modulo de usuario exibir.
 *
 */

class ComandoExibir : public ComandoUsuario{
    public:
        Resultado ExecutarComando(UsuarioIS *, const Correio_Eletronico&) throw (invalid_argument) override;
};

/**
 * @brief Classe que define a execucao do comando para o servico do modulo de usuario excluir.
 *
 */

class ComandoExcluir : public ComandoUsuario
{
public:
    Resultado ExecutarComando(UsuarioIS *, const Correio_Eletronico&) throw (invalid_argument) override;
};

/**
 * @brief Classe que define a execucao do comando para o servico do modulo de usuario editar.
 *
 */

class ComandoEditar : public ComandoUsuario
{
public:
    Resultado ExecutarComando(UsuarioIS *, const Correio_Eletronico&) throw (invalid_argument) override;
};

/*----------------------------------------------------------------------------*/

/**
 * @brief Classe que define a execucao do comando para o servico do modulo de vocabulario listar.
 *
 */

 class ComandoListarVocabularios
 {
 public:
     vector<VocControlado> ExecutarComando(VocabulariosIS *);
 };

 /**
  * @brief Classe que define a execucao do comando para o servico do modulo de vocabulario consultar vocabulario.
  *
  */

 class ComandoConsultarVocabulario
 {
 public:
     vector<Termo> ExecutarComando(VocabulariosIS *, vector<VocControlado>&, const string) throw (invalid_argument);
 };

 /**
  * @brief Classe que define a execucao do comando para o servico do modulo de vocabulario consultar termo.
  *
  */

 class ComandoConsultarTermo
 {
 public:
     Termo ExecutarComando(VocabulariosIS *, vector<Termo>&, string) throw (invalid_argument);
 };

 /**
  * @brief Classe que define a execucao do comando para o servico do modulo de vocabulario consultar definicao.
  *
  */

 class ComandoConsultarDefinicao
 {
 public:
     void ExecutarComando(VocabulariosIS *, Termo&) throw (invalid_argument) ;
 };

 /*----------------------------------------------------------------------------*/

 /**
  * @brief Classe que define a execucao do comando para o servico do modulo de vocabulario editar definicao do vocabulario.
  *
  */

 class ComandoEditarDefinicaoVoc
 {
 public:
     Resultado Executar(VocabulariosIS *, string nome_voc) throw (invalid_argument);
 };

 /**
  * @brief Classe que define a execucao do comando para o servico do modulo de vocabulario alterar idioma do vocabulario.
  *
  */

 class ComandoAlterarIdiomaVoc
 {
 public:
     Resultado Executar(VocabulariosIS *, VocControlado&) throw (invalid_argument);
 };

 /**
  * @brief Classe que define a execucao do comando para o servico do modulo de vocabulario de criar termo.
  *
  */

 class ComandoCriarTermo
 {
 public:
     Resultado Executar(VocabulariosIS *, string nome_voc);
 };

 /**
  * @brief Classe que define a execucao do comando para o servico do modulo de vocabulario de excluir termo.
  *
  */

 class ComandoExcluirTermo
 {
 public:
     Resultado Executar(VocabulariosIS *, Termo&);
 };

 /**
  * @brief Classe que define a execucao do comando para o servico do modulo de vocabulario de editar termo.
  *
  */
 class ComandoEditarTermo
 {
 public:
     Resultado Executar(VocabulariosIS *, Termo&);
 };

 /**
  * @brief Classe que define a execucao do comando para o servico do modulo de vocabulario de editar a definicao de um termo.
  *
  */

 class ComandoEditarDefinicaoTermo
 {
 public:
     Resultado Executar(VocabulariosIS *, Termo&);
 };


 class ComandoCriarVocabulario
 {
 public:
     Resultado Executar(VocabulariosIS *, const ResultadoUsuario&);
 };

 class ComandoExcluirVocabulario
 {
 public:
     Resultado Executar(VocabulariosIS *, VocControlado&);
 };

 class ComandoRegistrarDesenvolvedor
 {
  public:
     Resultado Executar(VocabulariosIS *,string voc, const ResultadoUsuario&);
 };

class ComandoCriarDefinicao
{
public:
    Resultado Executar(VocabulariosIS *, const Termo &temo);
};

#endif
