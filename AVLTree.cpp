//.CPP IMPLEMENTANDO OS METODOS DA ARVORE AVL. (USANDO OS CRITERIOS DE BALANCEAMENTO COMO NOS SLIDES)

#include <iostream>
#include <string>
#include "AVLTree.h"
#include "Contato.h"
using namespace std;

// CONSTRUTOR
AVLTree::AVLTree() {
    root = NULL;
}

// DESTRUTOR
AVLTree::~AVLTree() {
    clear_();
}

// VERIFICA SE A ARVORE ESTAH VAZIA
bool AVLTree::empty_() {
    return (root == NULL);
}

// VERIFICA SE A ARVORE ESTAH CHEIA
bool AVLTree::full_() {
    return false;
}

// LIMPA A ARVORE
void AVLTree::clear_() {
    clear_(root);
    root = NULL;
}

// AUXILIA NA LIMPEZA DA ARVORE
void AVLTree::clear_(TreePointer &t) {
    if(t != NULL) {
        clear_(t->leftNode);
        clear_(t->rightNode);
        delete t;
    }
}

// INSERE UM CONTATO NA ARVORE
void AVLTree::searchInsert_(Contato c) {
    bool h = false;
    searchInsert_(c, root, h);
}

// AUXILIA NA INSERCAO DO CONTATO NO METODO ANTERIOR
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

// REMOVE UM CONTATO DA ARVORE CHAMANDO O METODO PRIVADO
bool AVLTree::remove_(string n) {
    bool h = false;
    return remove_(n, root, h);
}

// FAZ A REMOCAO DO NOH E REALIZA O BALANCEAMENTO DA ARVORE APOS A REMOCAO
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

// AUXILIA NA REMOCAO AO REMOVER O MENOR NOH
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

// REALIZA O BALANCEAMENTO DA ARVORE QUANDO ESTAH EM DESEQUILIBRIO A DIREITA
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

// REALIZA O BALANCEAMENTO DA ARVORE QUANDO ESTAH EM DESEQUILIBRIO A ESQUERDA
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

// CHAMA A BUSCA CHAMANDO O METODO PRIVADO
Contato* AVLTree::search_(string n) {
    return search_(n, root);
}

// REALIZA A BUSCA DO CONTATO ANALISANDO CADA NOH
Contato* AVLTree::search_(string n, TreePointer &t) {
    if(t == NULL) {
        return NULL;
    }
    if(n < t->contato.getNome()) {
        return search_(n, t->leftNode);
    } else {
        if(n > t->contato.getNome()) {
            return search_(n, t->rightNode);
        } else {
            return &t->contato;
        }
    }
}

// IMPRIME A ARVORE CHAMANDO O METODO PRIVADO E, SE ESTIVER VAZIA IMPRIME A MENSAGEM
void AVLTree::print_() {
    if(root == NULL) {
        cout << "Lista vazia." << endl;
        return;
    }
    print_(root);
}

// FAZ A IMPRESSAO DE TODOS OS CONTATOS ARMAZENADOS NA ARVORE
void AVLTree::print_(TreePointer &t) {
    if(t != NULL) {
        print_(t->leftNode);

        cout << "------------------------------------------" << endl;
        cout << "Nome: " << t->contato.getNome() << endl;
        cout << "Telefones: " << endl;
        for(string f : t->contato.getTelefone()) {
            cout << f << endl;
        }
        cout << "Endereco: " << t->contato.getRua() << ", " << t->contato.getNumero() <<
        ", " << t->contato.getBairro() << endl;
        cout << "------------------------------------------" << endl;

        print_(t->rightNode);
    }
}
