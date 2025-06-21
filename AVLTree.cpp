#include <iostream>
#include <string>
#include "AVLTree.h"
#include "Contato.h"
using namespace std;

AVLTree::AVLTree() {
    root = NULL;
}

AVLTree::~AVLTree() {
    clear_();
}

bool AVLTree::empty_() {
    return (root == NULL);
}

bool AVLTree::full_() {
    return false;
}

void AVLTree::clear_() {
    clear_(root);
    root = NULL;
}

void AVLTree::clear_(TreePointer &t) {
    if(t != NULL) {
        clear_(t->leftNode);
        clear_(t->rightNode);
        delete t;
    }
}

void AVLTree::searchInsert_(Contato c) {
    bool h = false;
    searchInsert_(c, root, h);
}

void AVLTree::searchInsert_(Contato c, TreePointer &pA, bool &h) {
    TreePointer pB, pC;

    if(pA == NULL) {
        pA = new TreeNode;
        h = true;
        pA->contato = c;
        pA->leftNode = pA->rightNode = NULL;
        pA->bal = 0;
        cout << "Insercao realizada com sucesso" << endl;
    } else {
        if(c.getNome() < pA->contato.getNome()) {
            searchInsert_(c, pA->leftNode, h);
            if(h) {
                switch(pA->bal) {
                case -1:
                    pA->bal = 0;
                    h = false;
                    break;
                case 0:
                    pA->bal = 1;
                    h = false;
                    break;
                case 1:
                    pB = pA->leftNode;
                    if(pB->bal == 1) {
                        pA->leftNode = pB->rightNode;
                        pB->rightNode = pA;
                        pA->bal = 0;
                        pA = pB;
                    } else {
                        pC = pB->rightNode;
                        pB->rightNode = pC->leftNode;
                        pC->leftNode = pB;
                        pA->leftNode = pC->rightNode;
                        pC->rightNode = pA;
                        if(pC->bal == 1) {
                            pA->bal = -1;
                        } else {
                            pA->bal = 0;
                        }
                        if(pC->bal == -1) {
                            pB->bal = 1;
                        } else {
                            pB->bal = 0;
                        }
                        pA = pC;
                    }
                    pA->bal = 0;
                    h = false;
                    break;
                }
            }
        } else {
            if(c.getNome() > pA->contato.getNome()) {
                searchInsert_(c, pA->rightNode, h);
                if(h) {
                    switch(pA->bal) {
                    case 1:
                        pA->bal = 0;
                        h = false;
                        break;
                    case 0:
                        pA->bal = -1;
                        h = false;
                        break;
                    case -1:
                        pB = pA->rightNode;
                        if(pB->bal == -1) {
                            pA->rightNode = pB->leftNode;
                            pB->leftNode = pA;
                            pA->bal = 0;
                            pA = pB;
                        } else {
                            pC = pB->leftNode;
                            pB->leftNode = pC->rightNode;
                            pC->rightNode = pB;
                            pA->rightNode = pC->leftNode;
                            pC->leftNode = pA;
                            if(pC->bal == -1) {
                                pA->bal = 1;
                            } else {
                                pA->bal = 0;
                            }
                            if(pC->bal == 1) {
                                pB->bal = -1;
                            } else {
                                pB->bal = 0;
                            }
                            pA = pC;
                        }
                        pA->bal = 0;
                        h = false;
                        break;
                    }
                }
            } else {
                cout << "Insercao falhou. Contato ja tinha sido inserido" << endl;
            }
        }
    }
}

bool AVLTree::remove_(string n) {
    bool h = false;
    return remove_(n, root, h);
}

bool AVLTree::remove_(string n, TreePointer &p, bool &h) {
    TreePointer q;
    bool removed;

    if(p == NULL) {
        cout << "Remocao falhou. Contato nao existe" << endl;
        return false;
    }
    if(n < p->contato.getNome()) {
        removed = remove_(n, p->leftNode, h);
        if(h) {
            balanceL(p, h);
        }
        return removed;
    } else {
        if(n > p->contato.getNome()) {
            removed = remove_(n, p->rightNode, h);
            if(h) {
                balanceR(p, h);
            }
            return removed;
        } else {
            q = p;
            if(q->rightNode == NULL) {
                p = q->leftNode;
                h = true;
            } else {
                if(q->leftNode == NULL) {
                    p = q->rightNode;
                    h = true;
                } else {
                    removeMin(q, q->rightNode, h);
                    if(h) {
                        balanceR(p, h);
                    }
                }
            }
            delete q;
            cout << "Remocao realizada com sucesso" << endl;
            return true;
        }
    }
}

void AVLTree::removeMin(TreePointer &q, TreePointer &r, bool &h) {
    if(r->leftNode != NULL) {
        removeMin(q, r->leftNode, h);
        if(h) {
            balanceL(r, h);
        }
    } else {
        q->contato = r->contato;
        q = r;
        r = r->rightNode;
        h = true;
    }
}

void AVLTree::balanceL(TreePointer &pA, bool &h) {
    TreePointer pB, pC;
    int balB, balC;

    switch(pA->bal) {
    case 1:
        pA->bal = 0;
        h = false;
        break;
    case 0:
        pA->bal = -1;
        h = false;
        break;
    case -1:
        pB = pA->rightNode;
        balB = pB->bal;
        if(balB <= 0) {
            pA->rightNode = pB->leftNode;
            pB->leftNode = pA;
            if(balB == 0) {
                pA->bal = -1;
                pB->bal = 1;
                h = false;
            } else {
                pA->bal = 0;
                pB->bal = 0;
            }
            pA = pB;
        } else {
            pC = pB->leftNode;
            balC = pC->bal;
            pB->leftNode = pC->rightNode;
            pC->rightNode = pB;
            pA->rightNode = pC->leftNode;
            pC->leftNode = pA;
            if(balC == -1) {
                pA->bal = 1;
            } else {
                pA->bal = 0;
            }
            if(balC == 1) {
                pB->bal = -1;
            } else {
                pB->bal = 0;
            }
            pA = pC;
            pC->bal = 0;
        }
        break;
    }
}

void AVLTree::balanceR(TreePointer &pA, bool &h) {
    TreePointer pB, pC;
    int balB, balC;

    switch(pA->bal) {
    case -1:
        pA->bal = 0;
        h = false;
        break;
    case 0:
        pA->bal = 1;
        h = false;
        break;
    case 1:
        pB = pA->leftNode;
        balB = pB->bal;
        if(balB >= 0) {
            pA->leftNode = pB->rightNode;
            pB->rightNode = pA;
            if(balB == 0) {
                pA->bal = 1;
                pB->bal = -1;
                h = false;
            } else {
                pA->bal = 0;
                pB->bal = 0;
            }
            pA = pB;
        } else {
            pC = pB->rightNode;
            balC = pC->bal;
            pB->rightNode = pC->leftNode;
            pC->leftNode = pB;
            pA->leftNode = pC->rightNode;
            pC->rightNode = pA;
            if(balC == 1) {
                pA->bal = -1;
            } else {
                pA->bal = 0;
            }
            if(balC == -1) {
                pB->bal = 1;
            } else {
                pB->bal = 0;
            }
            pA = pC;
            pC->bal = 0;
        }
        break;
    }
}

Contato AVLTree::search_(string n) {
    return search_(n, root);
}

Contato AVLTree::search_(string n, TreePointer &t) {
    if(t == NULL) {
        cout << "Busca falhou. Contato nao encontrado" << endl;
        return Contato();
    }
    if(n < t->contato.getNome()) {
        return search_(n, t->leftNode);
    } else {
        if(n > t->contato.getNome()) {
            return search_(n, t->rightNode);
        } else {
            cout << "Contato encontrado." << endl;
            return t->contato;
        }
    }
}
