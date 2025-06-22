#ifndef AVLTREE_H
#define AVLTREE_H

#include <string>
#include "Contato.h"
using namespace std;

class AVLTree {
public:
    AVLTree();
    ~AVLTree();
    bool empty_();
    bool full_();
    void clear_();
    void searchInsert_(Contato c);
    bool remove_(string n);
    Contato* search_(string n);
    void print_();
private:
    struct TreeNode;

    typedef TreeNode* TreePointer;

    struct TreeNode {
        Contato contato;
        int bal;
        TreePointer leftNode;
        TreePointer rightNode;
    };

    TreePointer root;

    void clear_(TreePointer &t);
    void searchInsert_(Contato c, TreePointer &pA, bool &h);
    bool remove_(string n, TreePointer &p, bool &h);
    void removeMin(TreePointer &q, TreePointer &r, bool &h);
    void balanceL(TreePointer &pA, bool &h);
    void balanceR(TreePointer &pA, bool &h);
    Contato* search_(string n, TreePointer &t);
    void print_(TreePointer &t);
};

#endif
