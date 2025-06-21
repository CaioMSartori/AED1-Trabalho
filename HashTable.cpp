#include <iostream>
#include <string>
#include "HashTable.h"
#include "Contato.h"
using namespace std;

HashTable::HashTable() {
    for(int i=0;i<TABLE_SIZE;i++) {
        table[i] = NULL;
    }
}

HashTable::~HashTable() {
    clear_();
}

bool HashTable::empty_() {
    for(int i=0;i<TABLE_SIZE;i++) {
        if(table[i] != NULL) {
            return false;
        }
    }
    return true;
}

bool HashTable::full_() {
    return false;
}

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

Contato HashTable::search_(string n) {
    int pos = transform_(n);
    HashPointer p;
    p = table[pos];

    while(p != NULL) {
        if(p->contato.getNome() == n) {
            cout << "Contato encontrado." << endl;
            return p->contato;
        }
        p = p->nextContato;
    }
    cout << "Busca falhou. Contato nao encontrado" << endl;
    return Contato();
}

int HashTable::transform_(string n) {
    int pos = 0;
    for(int i=0;i<(int)n.length();i++) {
        pos = (pos * BASE + n[i]) % TABLE_SIZE;
    }
    return pos;
}
