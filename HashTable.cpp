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
    HashPointer newContato = new Position;
    newContato->contato = c;
    newContato->nextContato = NULL;

    if(table[pos] == NULL) {
        table[pos] = newContato;
    } else {
        HashPointer p;
        p = table[pos];
        while(p->nextContato != NULL) {
            p = p->nextContato;
        }
        p->nextContato = newContato;
    }
}

int HashTable::transform_(string n) {
    int pos = 0;
    for(int i=0;i<(int)n.length();i++) {
        pos = (pos * BASE + n[i]) % TABLE_SIZE;
    }
    return pos;
}
