//Trabalho 4 AEDS1: Operações em Vetores 
//Pedro Augusto de Souza Finochio 
// 2024.1.08.020

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int TAM = 1000;

// Função para preencher o vetor com valores aleatórios
void preencherVetor(int vetor[]) {
    srand(time(NULL));
    for (int i = 0; i < TAM; i++) {
        vetor[i] = rand() % 100; // Valores aleatórios entre 0 e 99
    }
}

// Função para exibir o vetor e as posições de cada valor
void exibirVetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; ++i) {
        cout << "Número: " << vetor[i] << ", Posição: " << i + 1 << endl;
    }
}

// Função para buscar a primeira ocorrência de um valor no vetor
int buscarPrimeiraOcorrencia(int vetor[], int tamanho, int valor) {
    for (int i = 0; i < tamanho; ++i) {
        if (vetor[i] == valor) {
            return i; // Retorna a posição da primeira ocorrência encontrada
        }
    }
    return -1; // Retorna -1 se o valor não for encontrado no vetor
}

// Função para contar a quantidade de ocorrências de um valor no vetor
int contarOcorrencias(int vetor[], int tamanho, int valor) {
    int contador = 0;
    for (int i = 0; i < tamanho; ++i) {
        if (vetor[i] == valor) {
            contador++; // Incrementa o contador quando o valor é encontrado
        }
    }
    return contador; // Retorna a quantidade de ocorrências do valor no vetor
}

// Função para contar a quantidade de ocorrências de valores em um intervalo
int contarOcorrenciasIntervalo(int vetor[], int tamanho, int limiteInferior, int limiteSuperior) {
    int contador = 0;
    for (int i = 0; i < tamanho; ++i) {
        if (vetor[i] >= limiteInferior && vetor[i] <= limiteSuperior) {
            contador++; // Incrementa o contador quando o valor está dentro do intervalo
        }
    }
    return contador; // Retorna a quantidade de ocorrências de valores no intervalo no vetor
}

// Função para inverter os valores do vetor
void inverterVetor(int vetor[], int tamanho) {
    for (int i = 0, j = tamanho - 1; i < j; ++i, --j) {
        int temp = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = temp;
    }
}

// Função para remover um valor do vetor
void removerValor(int vetor[], int& tamanho, int valor) {
    int j = 0;
    for (int i = 0; i < tamanho; ++i) {
        if (vetor[i] != valor) {
            vetor[j++] = vetor[i];
        }
    }
    tamanho = j;
}

// Função para remover valores repetidos do vetor
void removerValoresRepetidos(int vetor[], int& tamanho) {
    for (int i = 0; i < tamanho; ++i) {
        for (int j = i + 1; j < tamanho;) {
            if (vetor[j] == vetor[i]) {
                for (; j < tamanho - 1; ++j) {
                    vetor[j] = vetor[j + 1];
                }
                tamanho--;
            } else {
                j++;
            }
        }
    }
}

int main() { //Declaração de variáveis
    int vetor[TAM];
    int tamanho = TAM;
    int valor, posicao, ocorrencias, intervalo;
    int limiteInferior, limiteSuperior;
    int opcao;

    // Função para preencher o vetor com valores aleatórios ("chama" a função para
    // preencher o vetor com valores aleatórios)
    preencherVetor(vetor);

    do { //Menu de operações para o usuário na tela
        cout << "\nMenu de Operacoes:\n"
                "1. Buscar pela primeira ocorrencia de um valor\n"
                "2. Contar a quantidade de ocorrencias de um valor\n"
                "3. Contar a quantidade de ocorrencias de valores em um intervalo\n"
                "4. Inverter os valores do vetor\n"
                "5. Remover um valor do vetor\n"
                "6. Remover valores repetidos do vetor\n"
                "7. Exibir o vetor\n"
                "0. Sair\n"
                "Escolha a opcao: ";
        cin >> opcao;

        switch (opcao) { //Conjunto de opções para permitir que o usuário manipule
            //o vetor
            case 1:
                cout << "Digite o valor que deseja buscar: ";
                cin >> valor;
                posicao = buscarPrimeiraOcorrencia(vetor, tamanho, valor);
                if (posicao != -1) {
                    cout << "A primeira ocorrencia de " << valor << " foi encontrada na posicao " << posicao + 1 << endl;
                } else {
                    cout << "O valor " << valor << " nao foi encontrado." << endl;
                }
                break;
            case 2:
                cout << "Digite o valor que deseja contar: ";
                cin >> valor;
                ocorrencias = contarOcorrencias(vetor, tamanho, valor);
                cout << "O valor " << valor << " aparece " << ocorrencias << " vezes no vetor." << endl;
                break;
            case 3:
                cout << "Digite o limite inferior do intervalo: ";
                cin >> limiteInferior;
                cout << "Digite o limite superior do intervalo: ";
                cin >> limiteSuperior;
                ocorrencias = contarOcorrenciasIntervalo(vetor, tamanho, limiteInferior, limiteSuperior);
                cout << "A quantidade de ocorrencias de valores no intervalo [" << limiteInferior << ", " << limiteSuperior << "] e: " << ocorrencias << endl;
                break;
            case 4:
                inverterVetor(vetor, tamanho);
                cout << "Vetor invertido com sucesso." << endl;
                break;
            case 5:
                cout << "Digite o valor que deseja remover: ";
                cin >> valor;
                removerValor(vetor, tamanho, valor); // Corrigido para passar o tamanho atual do vetor
                cout << "Valor removido com sucesso." << endl;
                break;
            case 6:
                removerValoresRepetidos(vetor, tamanho); // Corrigido para passar o tamanho atual do vetor
                cout << "Valores repetidos removidos com sucesso." << endl;
                break;
            case 7:
                cout << "Vetor atual:" << endl;
                exibirVetor(vetor, tamanho);
                break;
            case 0:
                cout << "Encerrando o programa." << endl;
                break;
            default:
                cout << "Opcao invalida. Por favor, escolha uma opcao valida." << endl;
        }
    } while (opcao != 0);

    return 0;
}

//As opções do menu estão sendo realizadas acima do menu