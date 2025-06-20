#ifndef CONTATO_H
#define CONTATO_H

#include <string>
using namespace std;

class Contato {
public:
    Contato();
    Contato(string n, string f);
    ~Contato();
    string getNome();
    string getFone();
    void setNome(string n);
    void setFone(string f);
private:
    struct Dados {
        string nome;
        string fone;
    };

    Dados dados;
};

#endif
