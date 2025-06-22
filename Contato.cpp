#include <iostream>
#include <list>
#include <string>
#include "Contato.h"
using namespace std;

// CONSTRUTOR DE CONTATO VAZIO
Contato::Contato() {
    dados.nome = " ";
    dados.telefone.push_back(" ");
    dados.endereco.bairro = " ";
    dados.endereco.rua = " ";
    dados.endereco.numero = -1;
}

// CONSTRUTOR DE CONTATO PREENCHIDO (COM OS DADOS QUE SERAO INSERIDOS)
Contato::Contato(string n, string f, string b, string r, int num) {
    dados.nome = n;
    dados.telefone.push_back(f);
    dados.endereco.bairro = b;
    dados.endereco.rua = r;
    dados.endereco.numero = num;
}

// DESTRUTOR
Contato::~Contato() {}

// METODOS GETS DAS INFORMACOES SOLICITADAS
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

// VERIFICA SE O TELEFONE NAO JAH FOI ADICIONADO ANTERIORMENTE PARA O CONTATO
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
