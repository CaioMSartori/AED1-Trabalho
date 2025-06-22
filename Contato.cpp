#include <iostream>
#include <list>
#include <string>
#include "Contato.h"
using namespace std;

Contato::Contato() {
    dados.nome = " ";
    dados.telefone.push_back(" ");
    dados.endereco.bairro = " ";
    dados.endereco.rua = " ";
    dados.endereco.numero = -1;
}

Contato::Contato(string n, string f, string b, string r, int num) {
    dados.nome = n;
    dados.telefone.push_back(f);
    dados.endereco.bairro = b;
    dados.endereco.rua = r;
    dados.endereco.numero = num;
}

Contato::~Contato() {}

string Contato::getNome() {
    return dados.nome;
}

list<string> &Contato::getTelefone() {
    return dados.telefone;
}

string Contato::getBairro() {
    return dados.endereco.bairro;
}

string Contato::getRua() {
    return dados.endereco.rua;
}

int Contato::getNumero() {
    return dados.endereco.numero;
}

void Contato::addTelefone(string f) {
    for(string fone : dados.telefone) {
        if(fone == f) {
            cout << "Telefone ja existente para o contato." << endl;
            return;
        }
    }
    dados.telefone.push_back(f);
    cout << "Telefone adicionado com sucesso." << endl;
}
