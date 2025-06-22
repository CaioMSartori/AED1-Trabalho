#ifndef CONTATO_H
#define CONTATO_H

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

    // VERIFICA SE O TELEFONE NAO JAH FOI ADICIONADO ANTERIORMENTE PARA O CONTATO
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
