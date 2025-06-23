#ifndef CONTATO_H
#define CONTATO_H

//.H PARA DECLARACAO DA CLASSE CONTATO, QUE REPRESENTARA OS REGISTROS UTILIZADOS NAS ESTRUTURAS
//TABELA HASH E ARVORE AVL NO PROGRAMA. CONTEM UMA STRING PARA O NOME DO CONTATO, QUE SERA A CHAVE
//DE BUSCA, UMA LISTA DE TELEFONES (IMPORTADA POR BIBLIOTECA DO C++, POIS LISTA NAO EH UMA ESTRUTURA
//QUE DEVERIA SER IMPLEMENTADA MANUALMENTE NO PROJETO), E UMA STRUCT ENDERECO COM CAMPOS DE STRING/INT
//NAS DEVIDAS INFORMACOES QUE SERAO ARMAZENADAS.

#include <list>
#include <string>
using namespace std;

// ESTRUTURA DO ENDERECO PARA OS CONTATOS
struct Endereco {
    string bairro;
    string rua;
    int numero;
};

class Contato {
public:
    Contato();                                                  // CONSTRUTOR DE CONTATO VAZIO
    Contato(string n, string f, string b, string r, int num);   // CONSTRUTOR DE CONTATO PREENCHIDO (COM OS DADOS QUE SERAO INSERIDOS)
    ~Contato();                                                 // DESTRUTOR

    // METODOS GETS DAS INFORMACOES SOLICITADAS
    string getNome();
    list<string> &getTelefone();
    string getBairro();
    string getRua();
    int getNumero();

    // VERIFICA SE O TELEFONE JAH FOI ADICIONADO ANTERIORMENTE PARA O CONTATO, SE NAO, ADICIONA NOVO TELEFONE NA LISTA
    void addTelefone(string f);

private:

    // ESTRUTURA PARA OS DADOS DO CONTATO
    struct Dados {
        string nome;
        list<string> telefone;
        Endereco endereco;
    };

    // VARIAVEL DO TIPO DADOS (STRUCT)
    Dados dados;
};

#endif
