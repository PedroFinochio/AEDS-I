#include <iostream>
#include "funcoes.h"

using namespace std;

void somaMatrizes(int mat1[][100], int mat2[][100], int matSum[][100], int l1, int c1, int l2, int c2) {
    if (l1 != l2 || c1 != c2) {
        cout << "A soma só pode ser realizada por matrizes de iguais dimensões" << endl;
        return;
    }
    for (int i = 0; i < l1; i++) {
        for (int j = 0; j < c1; j++) {
            matSum[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    cout << "A soma das matrizes é: " << endl;
    for (int i = 0; i < l1; i++) {
        cout << "[ ";
        for (int j = 0; j < c1; j++) {
            cout << matSum[i][j] << " ";
        }
        cout << "]" << endl;
    }
}

void multiplicaMatrizes(int mat1[][100], int mat2[][100], int matProd[][100], int l1, int c1, int l2, int c2) {
    if (c1 != l2) {
        cout << "A multiplicação não pode ser realizada por matrizes dessas dimensões" << endl;
        return;
    }
    for (int i = 0; i < l1; i++) {
        for (int j = 0; j < c2; j++) {
            matProd[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                matProd[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    cout << "A multiplicação das matrizes é: " << endl;
    for (int i = 0; i < l1; i++) {
        cout << "[ ";
        for (int j = 0; j < c2; j++) {
            cout << matProd[i][j] << " ";
        }
        cout << "]" << endl;
    }
}

void transpoeMatriz(int mat[][100], int matTransp[][100], int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            matTransp[j][i] = mat[i][j];
        }
    }
    for (int i = 0; i < colunas; i++) {
        cout << "[ ";
        for (int j = 0; j < linhas; j++) {
            cout << matTransp[i][j] << " ";
        }
        cout << "]" << endl;
    }
}

double valorMedioMatriz(int mat[][100], int linhas, int colunas) {
    double soma = 0;
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            soma += mat[i][j];
        }
    }
    return soma / (linhas * colunas);
}
