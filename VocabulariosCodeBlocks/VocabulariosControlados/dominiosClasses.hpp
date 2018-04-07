#ifndef ___DOMINIOS_HPP__
#define ___DOMINIOS_HPP__

#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>

using namespace std;

class Nome{
    private:
        string nome;
        const static int TAM_MAX_NOME = 20;
        const static int STRING_VAZIA = 0;

        void validation (string) throw (invalid_argument);

    public:
        void setNome (string nome) throw (invalid_argument);
        string getNome(){
            return nome;
        }

};

class Sobrenome{
    private:
        string sobrenome;
        const static int TAM_MAX_SOBRENOME = 20;
        const static int STRING_VAZIA = 0;
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
        const static int TAM_MAX_TELEFONE = 13;
        const static int POS_ESPA_TELEFONE = 2;
        const static int POS_TRACO_TELEFONE = 8;
        const static int STRING_VAZIA = 0;

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
        const static int TAM_MAX_ENDERECO = 20;
        const static int TAM_MAX_ESPAC_CONSEC = 2;
        const static int STRING_VAZIA = 0;

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
        const static int TAM_MAX_DATA = 10;
        const static int STRING_VAZIA = 0;
        const static int DIA_MAX = 31;
        const static int DIA_MIN = 1;
        const static int MES_MAX = 12;
        const static int MES_MIN = 1;
        const static int ANO_MIN = 1900;
        const static int ANO_MAX = 2099;
        const static int FEVEREIRO = 2;
        const static int ABRIL = 4;
        const static int JUNHO = 6;
        const static int SETEMBRO = 9;
        const static int NOVEMBRO = 11;

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
        const static int TAM_MAX_SENHA = 8;
        const static int STRING_VAZIA = 0;

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
