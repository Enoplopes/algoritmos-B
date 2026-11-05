#include <cstring>
#include <ctype.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <vector>
#include <fstream>
using namespace std;

typedef struct {
    string numeroCelular;
    string dadosSessao;
} Telefone;


void listar(vector<Telefone> listaSessoes) {
    if (listaSessoes.empty()) {
        cout << "Nenhum numero cadastrado cadastrada.\n";
        return;
    }

    cout << "\nNumeros cadastrados cadastradas:\n";
    for (int i = 0; i < listaSessoes.size(); i++) {
        cout << i + 1 << " - Numeros: " << listaSessoes[i].numeroCelular << "\n";
    }
    cout << "  Quantidade: " << listaSessoes.size() << "\n";
}


void carregarBase(string nomeArquivo, vector<Telefone>& listaSessoes) {
    ifstream arquivo(nomeArquivo);

    if (!arquivo) {
        return;
    }

    string celular, sessao;
    listaSessoes.clear(); 

    
    while (getline(arquivo, celular, ';') && getline(arquivo, sessao)) {
        if (!celular.empty() && !sessao.empty()) {
            Telefone t;
            t.numeroCelular = celular;
            t.dadosSessao = sessao; 
            listaSessoes.push_back(t);
        }
    }

    arquivo.close();
}

void pesquisar(const vector<Telefone>& listaSessoes) {
    string numeroPesquisa;

    cout << "Digite o numero que deseja pesquisar: ";
    cin >> numeroPesquisa;

    bool encontrado = false;
    for (int i = 0; i < listaSessoes.size(); i++) {
        if (numeroPesquisa == listaSessoes[i].numeroCelular) {
            cout << "Numero encontrado! Numero: " << listaSessoes[i].numeroCelular << " | Dados: " << listaSessoes[i].dadosSessao << "\n";
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "Numero nao encontrado.\n";
    }
}
int main() {
    vector<Telefone> listaSessoes;
    int opcao;
    string ListasBase = "telephony_sessions.txt";

    

    do {
        cout << "MENU\n";
        cout << "1 - Listar telefones\n";
        cout << "2 - Pesquisar telefone e dados de sessao\n";
        cout << "3 - Finalizar\n";
        cout << "Opcao: ";
        cin >> opcao;
        cin.ignore();

        carregarBase (ListasBase, listaSessoes);
        switch (opcao) {
            case 1: 
                
            listar(listaSessoes);
                break;
            case 2:
                
                pesquisar(listaSessoes);
                break;
            case 3:
                cout << "Obrigado por usar o sistema\n";
                break;
            default:
                cout << "Opcao invalida!\n";
                break;
        }
    } while (opcao != 3);

    return 1;
}