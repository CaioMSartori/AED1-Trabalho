#include <iostream>
#include <string>
#include <limits>
#include "Contato.h"
#include "HashTable.h"
#include "AVLTree.h"

// INSERE A BIBLOTECA DEPENDENDO SE FOR WINDOWS OU LINUX
#ifdef _WIN32
#include <windows.h>    // Sleep (esperarSegundos(int seg), windows)
#else
#include <unistd.h>     // sleep (esperarSegundos(int seg), linux)
#endif

using namespace std;

// ------------------------------------------
// METODOS UTILIZADOS PARA FINS ESTETICOS
// ------------------------------------------

// FAZ ESPERAR 2 (DOIS) SEGUNDOS
void esperarSegundos(int seg){
#ifdef _WIN32
    Sleep(seg*1000);
#else
    sleep(seg);
#endif
}

// APAGA A TELA APOS 2 (DOIS) SEGUNDOS
void limparTela() {
    esperarSegundos(2);
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// AGUARDA O USUARIO PRESSIONAR ENTER PARA ENTAO PROSSEGUIR
void esperarEnter() {
    cout << "\nPressione Enter para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

// APAGA LINHAS
void apagarLinha() {
    cout << "\033[A" << flush;
    cout << "\33[2K\r" << flush;
}

// MENU PRINCIPAL
void menu() {
    cout << "LISTA TELEFONICA" << endl << endl;
    cout << "Digite 1 para inserir um novo contato." << endl;
    cout << "Digite 2 para adicionar telefone de um contato." << endl;
    cout << "Digite 3 para remover um contato." << endl;
    cout << "Digite 4 para buscar um contato." << endl;
    cout << "Digite 5 para exibir todos os contatos." << endl;
    cout << "Digite 6 para encerrar." << endl;
}

// ------------------------------------------
// FUNCAO PRINCIPAL (MAIN)
// ------------------------------------------

int main() {
    int option1 = 0;

    cout << "SELECIONE A FORMA DE IMPLEMENTACAO:" << endl << endl;
    cout << "Digite 1 para Tabelas Hash." << endl;
    cout << "Digite 2 para Arvores AVL." << endl;
    cout << "Opcao: ";
    cin >> option1;

    switch(option1) {

        // ARMAZENAMENTO NA TABELA HASH
        case 1: {
            HashTable ListaTelefonica;
            int option2 = 0;

            while(option2 != 6) {
                limparTela();
                menu();
                cout << "Opcao: ";
                cin >> option2;
                if(cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cout << endl;

                switch(option2) {
                    case 1: {   // INSERIR CONTATO
                        limparTela();
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
                                cout << "Entrada invalida." << endl;
                                esperarSegundos(2);
                                apagarLinha();
                                apagarLinha();
                                apagarLinha();
                            } else {
                                break;
                            }
                        }
                        cout << endl;

                        Contato novo(n, f, b, r, num);
                        ListaTelefonica.insert_(novo);
                        break;
                    }
                    case 2: {   // ADICIONAR MAIS UM TELEFONE A UM CONTATO
                        limparTela();
                        string n;

                        cin.ignore();
                        cout << "Nome do contato: ";
                        getline(cin, n);

                        Contato* alterar = ListaTelefonica.search_(n);

                        if(alterar != NULL) {
                            string f;

                            cout << "Numero: ";
                            getline(cin, f);
                            cout << endl;

                            alterar->addTelefone(f);
                        } else {
                            cout << endl;
                            cout << "Contato nao encontrado." << endl;
                        }

                        cout << endl;
                        break;
                    }
                    case 3: {   // REMOVER CONTATO
                        limparTela();
                        string n;

                        cin.ignore();
                        cout << "Nome do contato: ";
                        getline(cin, n);
                        cout << endl;

                        ListaTelefonica.remove_(n);
                        cout << endl;
                        break;
                    }
                    case 4: {   // BUSCAR CONTATO
                        limparTela();
                        string n;

                        cin.ignore();
                        cout << "Nome do contato: ";
                        getline(cin, n);
                        cout << "\nBuscando...";

                        Contato* buscar = ListaTelefonica.search_(n);

                        if(buscar != NULL) {
                            limparTela();
                            cout << "INFORMACOES DO CONTATO" << endl;
                            cout << "Nome: " << n << endl;
                            cout << "Telefones: " << endl;
                            for(string f : buscar->getTelefone()) {
                                cout << f << endl;
                            }
                            cout << "Endereco: " << buscar->getRua() << ", " << buscar->getNumero() <<
                            ", " << buscar->getBairro() << endl;
                            esperarEnter();
                        } else {
                            limparTela();
                            cout << "Contato nao encontrado." << endl;
                            esperarSegundos(2);
                        }
                        break;
                    }
                    case 5: {   // IMPRIMIR LISTA COM TODOS OS CONTATOS
                        limparTela();
                        cout << "LISTA DE CONTATOS" << endl << endl;
                        ListaTelefonica.print_();

                        esperarEnter();
                        break;
                    }
                    case 6: {   // ENCERRAR PROGRAMA
                        cout << "Encerrando..." << endl;
                        esperarSegundos(2);
                        break;
                    }
                    default: {
                        cout << "Opcao invalida." << endl;
                        break;
                    }
                }
            }
            break;
        }

        // ARMAZENAMENTO NA ARVORE
        case 2: {
            AVLTree ListaTelefonica;
            int option3 = 0;

            while(option3 != 6) {
                limparTela();
                menu();
                cout << "Opcao: ";
                cin >> option3;
                if(cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cout << endl;

                switch(option3) {
                    case 1: {   // INSERIR CONTATO
                        limparTela();
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
                                cout << "Entrada invalida." << endl;
                                esperarSegundos(2);
                                apagarLinha();
                                apagarLinha();
                                apagarLinha();
                            } else {
                                break;
                            }
                        }
                        cout << endl;

                        Contato novo(n, f, b, r, num);
                        ListaTelefonica.searchInsert_(novo);
                        break;
                    }
                    case 2: {   // ADICIONAR MAIS UM TELEFONE A UM CONTATO
                        limparTela();
                        string n;

                        cin.ignore();
                        cout << "Nome do contato: ";
                        getline(cin, n);

                        Contato* alterar = ListaTelefonica.search_(n);

                        if(alterar != NULL) {
                            string f;

                            cout << "Numero: ";
                            getline(cin, f);
                            cout << endl;

                            alterar->addTelefone(f);
                        } else {
                            cout << endl;
                            cout << "Contato nao encontrado." << endl;
                        }

                        cout << endl;
                        break;
                    }
                    case 3: {   // REMOVER CONTATO
                        limparTela();
                        string n;

                        cin.ignore();
                        cout << "Nome do contato: ";
                        getline(cin, n);
                        cout << endl;

                        ListaTelefonica.remove_(n);
                        cout << endl;
                        break;
                    }
                    case 4: {   // BUSCAR CONTATO
                        limparTela();
                        string n;

                        cin.ignore();
                        cout << "Nome do contato: ";
                        getline(cin, n);
                        cout << "\nBuscando...";

                        Contato* buscar = ListaTelefonica.search_(n);

                        if(buscar != NULL) {
                            limparTela();
                            cout << "INFORMACOES DO CONTATO" << endl;
                            cout << "Nome: " << n << endl;
                            cout << "Telefones: " << endl;
                            for(string f : buscar->getTelefone()) {
                                cout << f << endl;
                            }
                            cout << "Endereco: " << buscar->getRua() << ", " << buscar->getNumero() <<
                            ", " << buscar->getBairro() << endl;
                            esperarEnter();
                        } else {
                            limparTela();
                            cout << "Contato nao encontrado." << endl;
                            esperarSegundos(2);
                        }
                        break;
                    }
                    case 5: {   // IMPRIMIR LISTA COM TODOS OS CONTATOS
                        limparTela();
                        cout << "LISTA DE CONTATOS" << endl << endl;
                        ListaTelefonica.print_();

                        esperarEnter();
                        break;
                    }
                    case 6: {   // ENCERRAR PROGRAMA
                        cout << "Encerrando..." << endl;
                        esperarSegundos(2);
                        break;
                    }
                    default: {
                        cout << "Opcao invalida." << endl;
                        break;
                    }
                }
            }
            break;
        }
        default: {  // ENCERRA O PROGRAMA
            cout << "Opcao invalida." << endl;
            cout << "Encerrando programa." << endl;
            esperarSegundos(2);
            break;
        }
    }
    return 0;
}
