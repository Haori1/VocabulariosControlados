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
        void set_nome (string nome) throw (invalid_argument);
        string get_nome(){
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
        void set_sobrenome (string sobrenome) throw (invalid_argument);
        string get_sobrenome(){
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
        void set_telefone (string telefone) throw (invalid_argument);
        string get_telefone(){
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
        void set_endereco (string endereco) throw (invalid_argument);
        string get_endereco(){
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
        void set_data (string data) throw (invalid_argument);
        string get_data(){
            return data;
        }
};

class Correio_Eletronico{
    private:
        string correio_eletronico;
        const static int POS_INVALIDA = -1;
        const static int STRING_VAZIA = 0;

        void validation(string) throw (invalid_argument);

    public:
        void set_correio_eletronico (string correio_eletronico) throw (invalid_argument);
        string get_correio_eletronico(){
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
        void set_senha (string senha) throw (invalid_argument);
        string get_senha(){
            return senha;
        }
};

class Texto_Definicao{
    private:
        string texto_definicao;
        const static int TAM_MAX_TEXTO = 30;

        void validation(string) throw (invalid_argument);

    public:
        void set_texto_definicao (string texto_definicao) throw (invalid_argument);
        string get_texto_definicao(){
            return texto_definicao;
        }
};

class Idioma{
    private:
        string idioma;
        void validation(string) throw (invalid_argument);

    public:
        void set_idioma (string idioma) throw (invalid_argument);
        string get_idioma(){
            return idioma;
        }
};

class Classe_Termo{
    private:
        string classe_termo;
        void validation(string) throw (invalid_argument);

    public:
        void set_classe_termo (string classe_termo) throw (invalid_argument);
        string get_classe_termo(){
            return classe_termo;
        }
};
#endif
