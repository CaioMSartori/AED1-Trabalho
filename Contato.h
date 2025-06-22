#ifndef CONTATO_H
#define CONTATO_H

#include <list>
#include <string>
using namespace std;

struct Endereco {
    string bairro;
    string rua;
    int numero;
};

class Contato {
public:
    Contato();
    Contato(string n, string f, string b, string r, int num);
    ~Contato();
    string getNome();
    list<string> &getTelefone();
    string getBairro();
    string getRua();
    int getNumero();
    void addTelefone(string f);
private:
    struct Dados {
        string nome;
        list<string> telefone;
        Endereco endereco;
    };

    Dados dados;
};

#endif
