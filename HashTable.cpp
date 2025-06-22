#include <iostream>
#include <string>
#include "HashTable.h"
#include "Contato.h"
using namespace std;

// CONSTRUTOR
HashTable::HashTable() {
    for(int i=0;i<TABLE_SIZE;i++) {
        table[i] = NULL;
    }
}

// DESTRUTOR
HashTable::~HashTable() {
    clear_();
}

// VERIFICA SE A TABELA HASH ESTAH VAZIA
bool HashTable::empty_() {
    for(int i=0;i<TABLE_SIZE;i++) {
        if(table[i] != NULL) {
            return false;
        }
    }
    return true;
}

// VERIFICA SE A TABELA HASH ESTAH CHEIA
bool HashTable::full_() {
    return false;
}

// LIMPA A TABELA HASH
void HashTable::clear_() {
    for(int i=0;i<TABLE_SIZE;i++) {
        HashPointer p;
        p = table[i];
        while(p != NULL) {
            HashPointer q;
            q = p;
            p = p->nextContato;
            delete q;
        }
        table[i] = NULL;
    }
}

// INSERE UM CONTATO NA TABELA HASH
void HashTable::insert_(Contato c) {
    int pos = transform_(c.getNome());

    if(table[pos] == NULL) {
        HashPointer newContato = new Position;
        newContato->contato = c;
        newContato->nextContato = NULL;
        table[pos] = newContato;
        cout << "Insercao realizada com sucesso" << endl;
    } else {
        HashPointer p;
        p = table[pos];
        if(p->contato.getNome() == c.getNome()) {
            cout << "Insercao falhou. Contato ja tinha sido inserido" << endl;
            return;
        }
        while(p->nextContato != NULL) {
            p = p->nextContato;
            if(p->contato.getNome() == c.getNome()) {
                cout << "Insercao falhou. Contato ja tinha sido inserido" << endl;
                return;
            }
        }
        HashPointer newContato = new Position;
        newContato->contato = c;
        newContato->nextContato = NULL;
        p->nextContato = newContato;
        cout << "Insercao realizada com sucesso" << endl;
    }
}

// REMOVE UM CONTATO DA TABELA HASH
void HashTable::remove_(string n) {
    int pos = transform_(n);
    HashPointer p, q;
    p = table[pos];
    q = NULL;

    while(p != NULL) {
        if(p->contato.getNome() == n) {
            if(q == NULL) {
                table[pos] = p->nextContato;
            } else {
                q->nextContato = p->nextContato;
            }
            delete p;
            cout << "Remocao realizada com sucesso" << endl;
            return;
        }
        q = p;
        p = p->nextContato;
    }
    cout << "Remocao falhou. Contato nao existe" << endl;
}

// BUSCA UM CONTATO NA TABELA HASH
Contato* HashTable::search_(string n) {
    int pos = transform_(n);
    HashPointer p;
    p = table[pos];

    while(p != NULL) {
        if(p->contato.getNome() == n) {
            return &p->contato;
        }
        p = p->nextContato;
    }
    return NULL;
}

// IMPRIME TODOS OS CONTATOS PRESENTES NA TABELA HASH
void HashTable::print_() {
    if(empty_()) {
        cout << "Lista vazia." << endl;
        return;
    }

    cout << "------------------------------------------" << endl;

    for(int i=0;i<TABLE_SIZE;i++) {
        HashPointer p = table[i];

        while(p != NULL) {
            cout << "Nome: " << p->contato.getNome() << endl;
            cout << "Telefones: " << endl;
            for(string f : p->contato.getTelefone()) {
                cout << f << endl;
            }
            cout << "Endereco: " << p->contato.getRua() << ", " << p->contato.getNumero() <<
            ", " << p->contato.getBairro() << endl;
            cout << "------------------------------------------" << endl;
            p = p->nextContato;
        }
    }
}

// FUNCAO HASH - CONVERTE A STRING NUM INDICE VALIDO PARA A TABELA HASH
int HashTable::transform_(string n) {
    int pos = 0;
    for(int i=0;i<(int)n.length();i++) {
        pos = (pos * BASE + n[i]) % TABLE_SIZE;
    }
    return pos;
}
