#ifndef __DOMINIOS__HPP__
#define __DOMINIOS__HPP__

class Nome {

    private:
    string nome;

    public:
    // fazer método construtor
    void recebeNome (string nome);
    void retornaNome ();

}

class Sobrenome {

    private:
    string sobrenome;

    public:
    // fazer método construtor
    void recebeSobrenome (string sobrenome);
    void retornaSobrenome ();

}

class Telefone {

    private:
    string telefone;

    public:
    // fazer método construtor
    void recebeTelefone (string telefone);
    void retornaTelefone ();
}

class Telefone {

    private:
    string telefone;

    public:
    // fazer método construtor
    void recebeTelefone (string telefone);
    void retornaTelefone ();
}

class Data {

    private:
    int dia;
    int mes;
    int ano;
    string data;

    public:
    // fazer método construtor
    void recebeData (int dia, int mes, int ano);
    void retornaData ();
}

class Endereco {

    private:
    string endereco; //dividir segundo as partes especificadas(nao entendi bem o que são)

    public:
    // fazer método construtor
    void recebeEndereco (string endereco);
    void retornaEndereco ();
}   

class Senha {

    private:
    string senha;

    public:
    // fazer método construtor
    void recebeSenha (string senha);
    void retornaSenha ();
}

class Definicao {

    private:
    string definicao;

    public:
    // fazer método construtor
    void recebeDefinicao (string definicao);
    void retornaDefinicao ();
}

class Idioma {

    private:
    string idioma;

    public:
    // fazer método construtor
    void recebeIdioma (string idioma);
    void retornaIdioma ();
}

class Classe {

    private:
    int codClasse; //acredito que poderia ser utilizado um inteiro ao inves de um string

    public:
    // fazer método construtor
    void recebeClasse (string codClasse); //esta recebendo um string que sera transformado em um inteiro
    void retornaClasse ();
}

//Como sugestão para acrescentar ao sistema: Classes para identificar tipos de palavras, segundo um determinado valor. 

// Indicar material a ser estudado para a manipulacao de strings

#endif