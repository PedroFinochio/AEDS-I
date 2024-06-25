/* 
 Pedro Augusto de Souza Finochio 
 * 2024.1.08.020
 * Este projeto é um programa em C++ que realiza operações básicas em matrizes. 
 * Ele solicita ao usuário que insira as dimensões e os valores de duas matrizes, 
 * e então permite a realização de várias operações através de um menu interativo.
 */


#include <iostream>
#include "funcoes.h"

using namespace std;

int main() {
    int l1, c1;
    int l2, c2;

    cout << "-----Matrizes-----" << endl << endl;

    // Captura as dimensões das matrizes
    cout << "Digite o número de linhas da primeira matriz" << endl;
    cin >> l1;
    cout << "Digite o número de colunas da primeira matriz" << endl;
    cin >> c1;
    cout << "Digite o número de linhas da segunda matriz" << endl;
    cin >> l2;
    cout << "Digite o número de colunas da segunda matriz" << endl;
    cin >> c2;

    // Declaração das matrizes com base nas dimensões fornecidas
    int mat1[l1][100]; // Usando 100 como tamanho máximo para as colunas
    int mat2[l2][100]; // Usando 100 como tamanho máximo para as colunas
    int matSum[l1][100]; // Matriz para armazenar a soma
    int matProd[l1][100]; // Matriz para armazenar o produto
    int matTransp1[100][100]; // Matriz para armazenar a transposta da primeira matriz
    int matTransp2[100][100]; // Matriz para armazenar a transposta da segunda matriz

    // Entrada dos valores para a primeira matriz
    cout << "Digite os valores para a primeira matriz:" << endl;
    for (int i = 0; i < l1; i++) {
        for (int j = 0; j < c1; j++) {
            cout << "Digite o valor para mat1[" << i << "][" << j << "]: ";
            cin >> mat1[i][j];
        }
    }

    // Entrada dos valores para a segunda matriz
    cout << "Digite os valores para a segunda matriz:" << endl;
    for (int i = 0; i < l2; i++) {
        for (int j = 0; j < c2; j++) {
            cout << "Digite o valor para mat2[" << i << "][" << j << "]: ";
            cin >> mat2[i][j];
        }
    }

    int opcao;

    do {
        cout << "\nMenu de Operações" << endl;
        cout << "1. Soma das matrizes" << endl;
        cout << "2. Multiplicação das matrizes" << endl;
        cout << "3. Transposição das matrizes" << endl;
        cout << "4. Valor médio da primeira matriz" << endl;
        cout << "5. Sair" << endl;
        cout << "Escolha a opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                somaMatrizes(mat1, mat2, matSum, l1, c1, l2, c2);
                break;

            case 2:
                multiplicaMatrizes(mat1, mat2, matProd, l1, c1, l2, c2);
                break;

            case 3:
                cout << "Transposição da primeira matriz:" << endl;
                transpoeMatriz(mat1, matTransp1, l1, c1);
                cout << "Transposição da segunda matriz:" << endl;
                transpoeMatriz(mat2, matTransp2, l2, c2);
                break;

            case 4:
                cout << "O valor médio da primeira matriz é: " << valorMedioMatriz(mat1, l1, c1) << endl;
                break;

            case 5:
                cout << "Programa finalizado." << endl;
                break;

            default:
                cout << "Opção inválida. Tente novamente." << endl;
                break;
        }
    } while (opcao != 5);

    return 0;
}
