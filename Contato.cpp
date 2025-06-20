#include <string>
#include "Contato.h"
using namespace std;

Contato::Contato() {
    dados.nome = " ";
    dados.fone = " ";
}

Contato::Contato(string n, string f) {
    dados.nome = n;
    dados.fone = f;
}

Contato::~Contato() {}

string Contato::getNome() {
    return dados.nome;
}

string Contato::getFone() {
    return dados.fone;
}

void Contato::setNome(string n) {
    dados.nome = n;
}

void Contato::setFone(string f) {
    dados.fone = f;
}
