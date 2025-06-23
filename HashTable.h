#ifndef HASHTABLE_H
#define HASHTABLE_H

//.H PARA DECLARACAO DA ESTRUTURA DE DADOS TABELA HASH, IMPLEMENTADA COM OS METODOS NECESSARIOS PARA
//O TRABALHO E SEGUINDO OS MOLDES DOS SLIDES DO PROFESSOR.

#include <string>
#include "Contato.h"
using namespace std;

class HashTable {
public:
    HashTable();                    // CONSTRUTOR
    ~HashTable();                   // DESTRUTOR
    bool empty_();                  // VERIFICA SE A HASH ESTAH VAZIA
    bool full_();                   // VERIFICA SE A HASH ESTAH CHEIA
    void clear_();                  // LIMPA A TABELA HASH
    void insert_(Contato c);        // INSERE UM CONTATO NA TABELA HASH
    void remove_(string n);         // REMOVE UM CONTATO DA TABELA HASH
    Contato* search_(string n);     // BUSCA UM CONTATO NA TABELA HASH
    void print_();                  // IMPRIME TODOS OS CONTATOS PRESENTES NA TABELA HASH
private:
    // ESTRUTURA DA POSICAO DO CONTATO, PARA A LISTA ENCADEADA DAS POSICOES
    struct Position;
    typedef Position* HashPointer;
    struct Position {
        Contato contato;
        HashPointer nextContato;
    };

    // CONSTANTES PARA UTILIZACAO NO VETOR E NA FUNCAO HASHING
    static const int TABLE_SIZE = 101;
    static const int BASE = 128;

    // VETOR  DE PONTEIROS (ENCADEAMENTO NA TABELA HASH)
    HashPointer table[TABLE_SIZE];

    int transform_(string n);       // FUNCAO HASH - CONVERTE A STRING NUM INDICE VALIDO PARA A TABELA HASH
};

#endif
