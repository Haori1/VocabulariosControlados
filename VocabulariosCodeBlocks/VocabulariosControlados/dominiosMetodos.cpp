#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include "dominiosClasses.hpp"

using namespace std;

/*---------------------------------------------------------------------------------------------------------*/

void Nome::validation(string nome) throw (invalid_argument){

    int tamanhoVetor = nome.size();

    if(tamanhoVetor > TAM_MAX_NOME) {
        throw invalid_argument("Quantidade maxima de caracteres excedida");
    }

    if(tamanhoVetor == STRING_VAZIA) {
        throw invalid_argument("Nao foi inserido nenhum caractere"); //o prompt permite que não sejam inseridos caracteres?
    }

    if(nome[0] < 'A' || nome[0] > 'Z'){
        throw invalid_argument("A primeira letra deve ser maiuscula.");

    } else {

        for(int i = 1; i < tamanhoVetor; i++) {
            if(nome[i] < 'a' || nome[i] > 'z') { // Existem caracteces com pontuação também, como proceder?
                throw invalid_argument("Caractere invalido inserido");
            }
        } // Testa um a um os caracteres, caso não sejam caracteres minusculos, retorna um erro
        //obs: Nas especificações do trabalho não é informado se devemos considerar somente caracteres minusculos
        //nos restantes caracteres de nome.

    }
}

void Nome::setNome(string nome) throw (invalid_argument){
    validation(nome);
    this->nome = nome;
}

/*---------------------------------------------------------------------------------------------------------*/

void Sobrenome::validation(string sobrenome) throw (invalid_argument) {

    int tamanhoVetor = sobrenome.size();

    if(tamanhoVetor > TAM_MAX_SOBRENOME) {
        throw invalid_argument("Quantidade maxima de caracteres excedida");
    }

    if(tamanhoVetor == STRING_VAZIA) {
        throw invalid_argument("Nao foi inserido nenhum caractere");
    }

    if(sobrenome[0] < 'A' || sobrenome[0] > 'Z'){
        throw invalid_argument("A primeira letra deve ser maiuscula.");
    } else {

        for(int i = 1; i < tamanhoVetor; i++) {
            if(sobrenome[i] < 'a' || sobrenome[i] > 'z') { // Existem caracteces com pontuação também, como proceder?
                throw invalid_argument("Caractere invalido inserido");
            }
        }
    }
}

void Sobrenome::setSobrenome(string sobrenome) throw (invalid_argument) {
    validation(sobrenome);
    this->sobrenome = sobrenome;
}
/*---------------------------------------------------------------------------------------------------------*/

void Telefone::validation(string telefone) throw (invalid_argument) {

    int tamanhoVetor = telefone.size();

    if(tamanhoVetor > TAM_MAX_TELEFONE) {
        throw invalid_argument("Quantidade maxima de caracteres excedida");
    }

    if(tamanhoVetor == STRING_VAZIA) {
        throw invalid_argument("Nao foi inserido nenhum caractere");
    }

    for(int i = 0; i < tamanhoVetor; i++){

        if(i == POS_ESPA_TELEFONE || i == POS_TRACO_TELEFONE) {
            continue;
        }

        //Utiliza tabela ascii:
        if(telefone[i] < '0' || telefone[i] > '9') { //A tabela ascii é considerada número mágico?
            throw invalid_argument("Nao foi inserido nenhum caractere");
            break;
        }
    }

    if(telefone[POS_ESPA_TELEFONE] != ' ') {
        throw invalid_argument("Formato Invalido. Insira o formato correto: AA BBBBB-BBBB");
    }

    if(telefone[POS_TRACO_TELEFONE] != '-') {
        throw invalid_argument("Formato Invalido. Insira o formato correto: AA BBBBB-BBBB");
    }
} // no formato AA numero, há uma espaço entre o AA e o número, ou não?

void Telefone::setTelefone(string telefone) throw (invalid_argument) {
    validation(telefone);
    this->telefone = telefone;
}

/*---------------------------------------------------------------------------------------------------------*/

void Endereco::validation(string endereco) throw (invalid_argument) {

    int contaEspacos = 0;
    int tamanhoVetor = endereco.size();

      if(tamanhoVetor > TAM_MAX_ENDERECO) {
        throw invalid_argument("Quantidade maxima de caracteres excedida");
     }

    if(endereco[0] == ' ') {
        throw invalid_argument("O primeiro caractere nao pode ser um espaco");
    }

    if(endereco[TAM_MAX_ENDERECO - 1] == ' ') {
        throw invalid_argument("O ultimo caractere nao pode ser um espaco");
    }

    for(int i = 1; i < TAM_MAX_ENDERECO; i++) { //começa do 1, pois o primeiro não pode ser espaço
        if(endereco[i] == ' ') {
            contaEspacos++;
        }

        if(contaEspacos == TAM_MAX_ESPAC_CONSEC) {
            throw invalid_argument("Nao podem haver dois espacos consecutivos no endereco");
        } //Chamar o throw dentro de um laço for interrompe o for e o método de exceção?
    }
}

void Endereco::setEndereco(string endereco) throw (invalid_argument) {
    validation(endereco);
    this->endereco = endereco;
}

/*---------------------------------------------------------------------------------------------------------*/

void Correio_Eletronico::validation(string correio_eletronico) throw (invalid_argument) {
    int tamanhoVetor = correio_eletronico.size();
    int pos = POS_INVALIDA;
    string local = "";
    string dominio = "";

    if (tamanhoVetor == STRING_VAZIA) {
        throw invalid_argument("Nao foi inserido nenhum caractere");
    }

    for (int i = 0; i < tamanhoVetor; i++){
        if(correio_eletronico[i] != '@')        /*Pega a parte local do email*/
            local += correio_eletronico[i];

        if(correio_eletronico[i] == '@'){       /*Salva a posição do domínio*/
            pos = i + 1;
            break;
        }
    }

    if(pos == POS_INVALIDA) /*Se durante o percorrimento da string não for encontrado o caractere '@' a pos fica com POS_INVALIDA*/
        throw invalid_argument("Formato Invalido. O email deve conter o caractere '@'");

    for (int i = pos; i < tamanhoVetor; i++){
        if(correio_eletronico[i] == '@'){
            throw invalid_argument("Formato Invalido. O email não pode haver mais de um caracter '@'");
        } else {
            dominio += correio_eletronico[i];   /*Pega a parte do dominio do email*/
        }
    }

    if(correio_eletronico[0] == '.' || correio_eletronico[tamanhoVetor - 1] == '.')
        throw invalid_argument("Nao pode haver o caracter '.' na primeira ou ultima posicao do email");
    if(correio_eletronico[0] == '-' || correio_eletronico[tamanhoVetor - 1] == '-')
        throw invalid_argument("Nao pode haver o caracter '-' na primeira ou ultima do email");

    /*Verificacao local*/
    int tamanhoLocal = local.size();
    for (int i = 0; i < tamanhoLocal; i++){
        if((local[i] >= 'A' && local[i] <= 'Z')      ||
           (local[i] >= 'a' && local[i] <= 'z')      ||
           (local[i] >= '0' && local[i] <= '9')      ||
            local[i] == '!' || local[i] == '#'       ||
            local[i] == '$' || local[i] == '%'       ||
            local[i] == '&' || local[i] == (char) 39 ||         /*O char 39 na tabela ascii é o caracter apostrofo*/
            local[i] == '*' || local[i] == '+'       ||
            local[i] == '-' || local[i] == '/'       ||
            local[i] == '=' || local[i] == '?'       ||
            local[i] == '^' || local[i] == '_'       ||
            local[i] == '`' || local[i] == '{'       ||
            local[i] == '|' || local[i] == '}'       ||
            local[i] == '~' || local[i] == ';'       ||
            local[i] == '.'){
                continue;
            } else {
                throw invalid_argument("Caractere invalido inserido na parte local do email");
            }
    }

    /*Verificacao dominio*/
    int tamanhoDominio = dominio.size();
    bool letra = false;
    for (int i = 0; i < tamanhoDominio; i++){
        if((dominio[i] >= 'A' && dominio[i] <= 'Z') ||  /*O dominio do email so pode conter letras, numeros, o caracter '.' e o caracter '-'*/
           (dominio[i] >= 'a' && dominio[i] <= 'z') ||
           (dominio[i] >= '0' && dominio[i] <= '9') ||
            dominio[i] == '.' || dominio[i] == '-'){
                continue;
            } else {
                throw invalid_argument("Caractere invalido inserido no dominio do email");
            }
    }
    for (int i = 0; i < tamanhoDominio; i++){
        if((dominio[i] >= 'A' && dominio[i] <= 'Z') ||
           (dominio[i] >= 'a' && dominio[i] <= 'z'))
            letra = true;
        if(dominio[i] == '.')
            break;
    }

    if(letra == false)
        throw invalid_argument("O dominio do email nao pode ser somente numerico");
}

void Correio_Eletronico::setCorreio_Eletronico(string correio_eletronico) throw (invalid_argument) {
    validation(correio_eletronico);
    this->correio_eletronico = correio_eletronico;
}

/*---------------------------------------------------------------------------------------------------------*/

void Data::validation(string data) throw (invalid_argument) {
    int tamanhoVetor = data.size();
    string dia = "";
    string mes = "";
    string ano = "";
    int dia_int;
    int mes_int;
    int ano_int;
    if (tamanhoVetor == STRING_VAZIA) {
        throw invalid_argument("Nao foi inserido nenhum caractere");
    }

    if(tamanhoVetor > TAM_MAX_DATA){
        throw invalid_argument("Quantidade maxima de caracteres excedida");
    }

    if(data[2] != '/' || data[5] != '/')    /* Posicao 2 e 5 == '/' */
        throw invalid_argument("Formato Invalido. Insira o formato correto: DD/MM/AAAA");

    for (int i = 0; i < tamanhoVetor; i++)
        if((i != 2 && i != 5) && (data[i] < '0' || data[i] > '9'))
            throw invalid_argument("Caractere invalido inserido");

    for (int i = 0; i < tamanhoVetor; i++) {
        if(i == 0 || i == 1)              /*Data == posicao 0 + 1*/
            dia += data[i];
        if(i == 3 || i == 4)              /*Mes == posicao 3 + 4*/
            mes += data[i];
        if(i == 6 || i == 7 || i == 8 || i == 9)    /*Ano == posicao 6 + 7 + 8 + 9*/
            ano += data[i];
    }

    dia_int = stoi(dia);    /*stoi() passa de string para inteiro*/
    mes_int = stoi(mes);
    ano_int = stoi(ano);

    if(dia_int > DIA_MAX || dia_int < DIA_MIN)
        throw invalid_argument("DD consiste em um numero de 01 a 31");
    if(mes_int > MES_MAX || mes_int < MES_MIN)
        throw invalid_argument("MM consiste em um numero de 01 a 12");
    if(ano_int > ANO_MAX || ano_int < ANO_MIN)
        throw invalid_argument("AAAA consiste em um numero de 1900 a 2099");

    bool bissexto = false;
    if((ano_int % 4 == 0 && ano_int % 100 != 0) || (ano_int % 400 == 0))    /*Condição para que o ano seja bissexto*/
        bissexto = true;

    if( (bissexto == false && mes_int == FEVEREIRO && dia_int > 28) ||
        (bissexto == true && mes_int == FEVEREIRO && dia_int > 29) )    /*Mes 2 é fevereiro e fevereiro só pode ter 29 dias em anos bissextos*/
        throw invalid_argument("O Mes de fevereiro possui somente ate 29 dias em anos bissextos");

    if( (mes_int == ABRIL     ||
         mes_int == JUNHO     ||
         mes_int == SETEMBRO  ||
         mes_int == NOVEMBRO) &&
         dia_int > 30)
        throw invalid_argument("Os meses de Abril, Junho, Setembro e Novembro possuem ate 30 dias");
}

void Data::setData(string data) throw (invalid_argument) {
    validation(data);
    this->data = data;
}

/*---------------------------------------------------------------------------------------------------------*/

