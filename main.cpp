#include <iostream>
#include <string>
#include <limits>
#include "Contato.h"
#include "HashTable.h"
#include "AVLTree.h"
using namespace std;

void menu() {
    cout << "LISTA TELEFONICA" << endl << endl;
    cout << "Digite 1 para inserir um novo contato." << endl;
    cout << "Digite 2 para adicionar telefone de um contato." << endl;
    cout << "Digite 3 para remover um contato." << endl;
    cout << "Digite 4 para buscar um contato." << endl;
    cout << "Digite 5 para exibir todos os contatos." << endl;
    cout << "Digite 6 para encerrar." << endl;
}

int main() {
    int option1 = 0;

    cout << "SELECIONE A FORMA DE IMPLEMENTACAO:" << endl << endl;
    cout << "Digite 1 para Tabelas Hash." << endl;
    cout << "Digite 2 para Arvores AVL." << endl;
    cout << "Opcao: ";
    cin >> option1;
    cout << endl;

    switch(option1) {
        case 1: {
            HashTable ListaTelefonica;
            int option2 = 0;

            while(option2 != 6) {
                menu();
                cout << "Opcao: ";
                cin >> option2;
                if(cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cout << endl;

                switch(option2) {
                    case 1: {
                        string n, f, b, r;
                        int num;

                        cout << "NOVO CONTATO" << endl << endl;
                        cin.ignore();
                        cout << "Nome: ";
                        getline(cin, n);
                        cout << "Telefone: ";
                        getline(cin, f);
                        cout << "Bairro: ";
                        getline(cin, b);
                        cout << "Rua: ";
                        getline(cin, r);

                        while(true) {
                            cout << "Numero: ";
                            cin >> num;

                            if(cin.fail()) {
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cout << endl;
                                cout << "Entrada invalida." << endl << endl;
                            } else {
                                break;
                            }
                        }
                        cout << endl;

                        Contato novo(n, f, b, r, num);
                        ListaTelefonica.insert_(novo);
                        cout << endl;
                        break;
                    }
                    case 2: {
                        string n;

                        cin.ignore();
                        cout << "Nome do contato: ";
                        getline(cin, n);
                        cout << endl;

                        Contato* alterar = ListaTelefonica.search_(n);

                        if(alterar != NULL) {
                            string f;

                            cout << "Numero: ";
                            getline(cin, f);
                            cout << endl;

                            alterar->addTelefone(f);
                        } else {
                            cout << "Contato nao encontrado." << endl;
                        }

                        cout << endl;
                        break;
                    }
                    case 3: {
                        string n;

                        cin.ignore();
                        cout << "Nome do contato: ";
                        getline(cin, n);
                        cout << endl;

                        ListaTelefonica.remove_(n);
                        cout << endl;
                        break;
                    }
                    case 4: {
                        string n;

                        cin.ignore();
                        cout << "Nome do contato: ";
                        getline(cin, n);
                        cout << endl;

                        Contato* buscar = ListaTelefonica.search_(n);

                        if(buscar != NULL) {
                            cout << "INFORMACOES DO CONTATO" << endl << endl;
                            cout << "Telefones: " << endl;
                            for(string f : buscar->getTelefone()) {
                                cout << f << endl;
                            }
                            cout << "Endereco: " << buscar->getRua() << ", " << buscar->getNumero() <<
                            ", " << buscar->getBairro() << endl;
                        } else {
                            cout << "Contato nao encontrado." << endl;
                        }

                        cout << endl;
                        break;
                    }
                    case 5: {
                        cout << "LISTA DE CONTATOS" << endl << endl;
                        ListaTelefonica.print_();

                        cout << endl;
                        break;
                    }
                    case 6: {
                        cout << "Encerrando..." << endl;
                        break;
                    }
                    default: {
                        cout << "Opcao invalida." << endl << endl;
                        break;
                    }
                }
            }
            break;
        }
        case 2: {
            AVLTree ListaTelefonica;
            int option3 = 0;

            while(option3 != 6) {
                menu();
                cout << "Opcao: ";
                cin >> option3;
                if(cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cout << endl;

                switch(option3) {
                    case 1: {
                        string n, f, b, r;
                        int num;

                        cout << "NOVO CONTATO" << endl << endl;
                        cin.ignore();
                        cout << "Nome: ";
                        getline(cin, n);
                        cout << "Telefone: ";
                        getline(cin, f);
                        cout << "Bairro: ";
                        getline(cin, b);
                        cout << "Rua: ";
                        getline(cin, r);

                        while(true) {
                            cout << "Numero: ";
                            cin >> num;

                            if(cin.fail()) {
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cout << endl;
                                cout << "Entrada invalida." << endl << endl;
                            } else {
                                break;
                            }
                        }
                        cout << endl;

                        Contato novo(n, f, b, r, num);
                        ListaTelefonica.searchInsert_(novo);
                        cout << endl;
                        break;
                    }
                    case 2: {
                        string n;

                        cin.ignore();
                        cout << "Nome do contato: ";
                        getline(cin, n);
                        cout << endl;

                        Contato* alterar = ListaTelefonica.search_(n);

                        if(alterar != NULL) {
                            string f;

                            cout << "Numero: ";
                            getline(cin, f);
                            cout << endl;

                            alterar->addTelefone(f);
                        } else {
                            cout << "Contato nao encontrado." << endl;
                        }

                        cout << endl;
                        break;
                    }
                    case 3: {
                        string n;

                        cin.ignore();
                        cout << "Nome do contato: ";
                        getline(cin, n);
                        cout << endl;

                        ListaTelefonica.remove_(n);
                        cout << endl;
                        break;
                    }
                    case 4: {
                        string n;

                        cin.ignore();
                        cout << "Nome do contato: ";
                        getline(cin, n);
                        cout << endl;

                        Contato* buscar = ListaTelefonica.search_(n);

                        if(buscar != NULL) {
                            cout << "INFORMACOES DO CONTATO" << endl << endl;
                            cout << "Telefones: " << endl;
                            for(string f : buscar->getTelefone()) {
                                cout << f << endl;
                            }
                            cout << "Endereco: " << buscar->getRua() << ", " << buscar->getNumero() <<
                            ", " << buscar->getBairro() << endl;
                        } else {
                            cout << "Contato nao encontrado." << endl;
                        }

                        cout << endl;
                        break;
                    }
                    case 5: {
                        cout << "LISTA DE CONTATOS" << endl << endl;
                        ListaTelefonica.print_();

                        cout << endl;
                        break;
                    }
                    case 6: {
                        cout << "Encerrando..." << endl;
                        break;
                    }
                    default: {
                        cout << "Opcao invalida." << endl << endl;
                        break;
                    }
                }
            }
            break;
        }
        default: {
            cout << "Opcao invalida." << endl;
            break;
        }
    }
    return 0;
}
