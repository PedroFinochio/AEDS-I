//Vetor de Registros
//Pedro Augusto de Souza Finochio
//2024.1.08.020

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

const int TAM = 1000;

typedef struct { // Definição da estrutura "Pessoa" para representar a agenda
    string nome;
    string celular;
    string cidade;
    string email;
    bool valido = true;
} Pessoa;

int main() { // Declaração de variáveis
    Pessoa agenda[TAM];
    int qtde = 0, opcao = 0;
    string busca;

    ifstream arquivo("agenda.txt"); // Abre o arquivo para leitura

    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo " << endl;
        return 1;
    }
    // Leitura dos registros do arquivo
    while (qtde < TAM && arquivo >> agenda[qtde].nome >> agenda[qtde].celular >> agenda[qtde].cidade >> agenda[qtde].email) {
        qtde++;
    }

    int contatos = qtde;

    arquivo.close(); // Fecha o arquivo

    do { // Início do loop do programa
        cout << "\nAgenda virtual\n"
                << "1. Exibir a agenda\n"
                << "2. Pesquisar um amigo\n"
                << "3. Adicionar um amigo\n"
                << "4. Remover um amigo\n"
                << "0. Sair\n"
                << "Escolha a opção: ";
        cin >> opcao;

        switch (opcao) { // Possibilidades para o usuário manipular a agenda
            case 1:
                cout << "Exibindo a agenda:" << endl;

                for (int i = 0; i < contatos; ++i) {
                    if (agenda[i].valido == true) {
                        cout << "Nome: " << agenda[i].nome << endl;
                        cout << "Celular: " << agenda[i].celular << endl;
                        cout << "Cidade: " << agenda[i].cidade << endl;
                        cout << "Email: " << agenda[i].email << endl << endl;
                    }
                }
                break;

            case 2:
                cout << "Digite o nome do amigo: ";
                cin >> busca;
                // Lógica de pesquisa
                {
                    bool encontrado = false; // Variável bool falsa por não encontrarmos nenhum amigo ainda
                    for (int i = 0; i < qtde; ++i) {
                        if (agenda[i].nome == busca && agenda[i].valido) {
                            cout << "Nome: " << agenda[i].nome << endl;
                            cout << "Celular: " << agenda[i].celular << endl;
                            cout << "Cidade: " << agenda[i].cidade << endl;
                            cout << "Email: " << agenda[i].email << endl << endl;
                            encontrado = true;
                            break;
                        }
                    }
                    if (!encontrado) {
                        cout << "Amigo não encontrado" << endl;
                    }
                }
                break;

            case 3:
                if (qtde < TAM) {
                    cout << "Adicionar amigo" << endl;
                    cout << "Nome: ";
                    cin >> agenda[qtde].nome;
                    cout << "Celular: ";
                    cin >> agenda[qtde].celular;
                    cout << "Cidade: ";
                    cin >> agenda[qtde].cidade;
                    cout << "Email: ";
                    cin >> agenda[qtde].email;
                    agenda[qtde].valido = true;
                    qtde++;
                    contatos++;
                }
                break;

            case 4:
                cout << "Digite o nome do amigo a ser removido: ";
                cin >> busca;
                // Lógica de remoção
                {
                    bool encontrado = false;
                    for (int i = 0; i < qtde; ++i) {
                        if (agenda[i].nome == busca && agenda[i].valido) {
                            // Desloca os amigos à direita do amigo removido uma posição para a esquerda
                            for (int j = i; j < qtde - 1; ++j) {
                                agenda[j] = agenda[j + 1];
                            }
                            contatos--; // Reduz o número de contatos válidos
                            encontrado = true;
                            break; // Sai do loop assim que o amigo é encontrado e removido
                        }
                    }
                    if (!encontrado) {
                        cout << "Amigo não encontrado" << endl;
                    }
                }
                break;

        }
    } while (opcao != 0);

    return 0;
}
