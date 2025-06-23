#ifndef AVLTREE_H
#define AVLTREE_H

//.H PARA DECLARACAO DA ESTRUTURA DE DADOS ARVORE AVL, IMPLEMENTADA COM OS METODOS NECESSARIOS PARA
//O TRABALHO E SEGUINDO OS MOLDES DOS SLIDES DO PROFESSOR.

#include <string>
#include "Contato.h"
using namespace std;

class AVLTree {
public:
    AVLTree();                          // CONSTRUTOR
    ~AVLTree();                         // DESTRUTOR
    bool empty_();                      // VERIFICA SE A ARVORE ESTAH VAZIA
    bool full_();                       // VERIFICA SE A ARVORE ESTAH CHEIA
    void clear_();                      // LIMPA A ARVORE
    void searchInsert_(Contato c);      // INSERE UM CONTATO NA ARVORE
    bool remove_(string n);             // REMOVE UM CONTATO DA ARVORE CHAMANDO O METODO PRIVADO
    Contato* search_(string n);         // CHAMA A BUSCA CHAMANDO O METODO PRIVADO
    void print_();                      // IMPRIME A ARVORE CHAMANDO O METODO PRIVADO E, SE ESTIVER VAZIA IMPRIME A MENSAGEM

private:
    // ESTRUTURA DA ARVORE:
    struct TreeNode;
    typedef TreeNode* TreePointer;
    struct TreeNode {
        Contato contato;
        int bal;
        TreePointer leftNode;
        TreePointer rightNode;
    };
    TreePointer root;

    // METODOS PRIVADOS:
    void clear_(TreePointer &t);                                // AUXILIA NA LIMPEZA DA ARVORE
    void searchInsert_(Contato c, TreePointer &pA, bool &h);    // AUXILIA NA INSERCAO DO CONTATO NO METODO ANTERIOR
    bool remove_(string n, TreePointer &p, bool &h);            // FAZ A REMOCAO DO NOH E REALIZA O BALANCEAMENTO DA ARVORE APOS A REMOCAO
    void removeMin(TreePointer &q, TreePointer &r, bool &h);    // AUXILIA NA REMOCAO AO REMOVER O MENOR NOH
    void balanceL(TreePointer &pA, bool &h);                    // REALIZA O BALANCEAMENTO DA ARVORE QUANDO ESTAH EM DESEQUILIBRIO A DIREITA
    void balanceR(TreePointer &pA, bool &h);                    // REALIZA O BALANCEAMENTO DA ARVORE QUANDO ESTAH EM DESEQUILIBRIO A ESQUERDA
    Contato* search_(string n, TreePointer &t);                 // REALIZA A BUSCA DO CONTATO ANALISANDO CADA NOH
    void print_(TreePointer &t);                                // FAZ A IMPRESSAO DE TODOS OS CONTATOS ARMAZENADOS NA ARVORE
};

#endif
