#ifndef ___DOMINIOS_HPP__
#define ___DOMINIOS_HPP__

#include <iostream>
#include <string>
#include <stdexcept>

#define TAM_MAX_NOME 21; // O professor havia falado para tomar cuidado com números mágicos
                          //estes não seriam? 
#define TAM_MAX_SOBRENOME 21;
#define TAM_MAX_TELEFONE 14;
#define TAM_MAX_ENDERECO 21;
#define TAM_MAX_DATA 11;
#define TAM_MAX_SENHA 9;
#define POS_ESPA_TELEFONE 2;
#define POS_TRACO_TELEFONE 8;
#define TAM_MAX_ESPAC_CONSEC 2;



using namespace std;

class Nome{
    private:
        string nome;
        void validation (string) throw (invalid_argument); //Sugiro utilizar "argumento_invalido", devido a nossa nacionalidade
                //Os warnings não são provenientes da declaração da função como um void? Ela está retornando um valor...
    public:
        void setNome (string nome) throw (invalid_argument);
        string getNome(){
            return nome;
        }

};

class Sobrenome{
    private:
        string sobrenome;
        void validation (string) throw (invalid_argument);

    public:
        void setSobrenome (string sobrenome) throw (invalid_argument);
        string getSobrenome(){
            return sobrenome;
        }

};

class Telefone{ 
    private:
        string telefone;
        void validation (string) throw (invalid_argument);

    public:
        void setTelefone (string telefone) throw (invalid_argument);
        string getTelefone(){
            return telefone;
        }
};

class Endereco{
    private:
        string endereco;
        void validation(string) throw (invalid_argument);

    public:
        void setEndereco (string endereco) throw (invalid_argument);
        string getEndereco(){
            return endereco;
        }
};

class Data{
    private:
        string data;
        void validation(string) throw (invalid_argument);

    public:
        void setData (string data) throw (invalid_argument);
        string getData(){
            return data;
        }
};

class Correio_Eletronico{
    private:
        string correio_eletronico;
        void validation(string) throw (invalid_argument);

    public:
        void setCorreio_Eletronico (string correio_eletronico) throw (invalid_argument);
        string getCorreio_Eletronico(){
            return correio_eletronico;
        }
};

class Senha{
    private:
        string senha;
        void validation(string) throw (invalid_argument);

    public:
        void setSenha (string senha) throw (invalid_argument);
        string getSenha(){
            return senha;
        }
};

class Texto_Definicao{
    private:
        string texto_definicao;
        void validation(string) throw (invalid_argument);

    public:
        void setTexto_Definicao (string texto_definicao) throw (invalid_argument);
        string getTexto_Definicao(){
            return texto_definicao;
        }
};

class Idioma{
    private:
        string idioma;
        void validation(string) throw (invalid_argument);

    public:
        void setIdioma (string idioma) throw (invalid_argument);
        string getIdioma(){
            return idioma;
        }
};

class Classe_Termo{
    private:
        string classe_termo;
        void validation(string) throw (invalid_argument);
    
    public:
        void setClasse_Termo (string classe_termo) throw (invalid_argument);
        string getClasse_Termo(){
            return classe_termo;
        }
};
#endif