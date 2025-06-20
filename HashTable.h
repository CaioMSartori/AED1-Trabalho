#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include "Contato.h"
using namespace std;

class HashTable {
public:
    HashTable();
    ~HashTable();
    bool empty_();
    bool full_();
    void clear_();
    void insert_(Contato c);
    bool remove_(string n);
    Contato* search_(string n);
private:
    struct Position;

    typedef Position* HashPointer;

    struct Position {
        Contato contato;
        HashPointer nextContato;
    };

    static const int TABLE_SIZE = 101;
    static const int BASE = 128;
    HashPointer table[TABLE_SIZE];

    int transform_(string n);
};

#endif
