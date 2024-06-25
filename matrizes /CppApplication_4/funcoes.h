#ifndef FUNCOES_H
#define FUNCOES_H

void somaMatrizes(int mat1[][100], int mat2[][100], int matSum[][100], int l1, int c1, int l2, int c2);
void multiplicaMatrizes(int mat1[][100], int mat2[][100], int matProd[][100], int l1, int c1, int l2, int c2);
void transpoeMatriz(int mat[][100], int matTransp[][100], int linhas, int colunas);
double valorMedioMatriz(int mat[][100], int linhas, int colunas);

#endif
