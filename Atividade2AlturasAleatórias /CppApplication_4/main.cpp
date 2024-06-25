/*Atividade 2: Números aleatórios
 Pedro Augusto de Souza Finochio 2024.1.08.020*/

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() { //Variáveis necessárias para o funcionamento do programa
    float alturas[1000];
    float somaAlturas = 0;
    float maiorAltura = 1.5f;
    float menorAltura = 2.3f;
    int contadorMaiorQue2 = 0;
    int contador = 0;

    srand(time(NULL)); //Essa função dá início a geração de números aleatórios

    //Essa condicional de repetição gera as 1000 alturas entre 1.5 e 2.3 metros 
    while (contador < 1000) {
        alturas[contador] = 1.5f + static_cast<float>(rand()) / RAND_MAX * (2.3f - 1.5f);
        somaAlturas += alturas[contador];

        //Essa condicional verifica a maior e a menor altura gerada 
        if (alturas[contador] > maiorAltura) {
            maiorAltura = alturas[contador];
        }
        if (alturas[contador] < menorAltura) {
            menorAltura = alturas[contador];
        }

        //Essa condicional conta quantas alturas são maiores que 2.0 metros
        if (alturas[contador] > 2.0f) {
            contadorMaiorQue2++;
        }

        contador++;
    }

    //Imprime as alturas geradas
    printf("Alturas geradas:\n");
    for (int i = 0; i < 1000; ++i) {
        printf("%.2f\n", alturas[i]);
    }
    
    //Essa funçaõ calcula a média das alturas 
    float media = somaAlturas / 1000;

    // Essa função calcula a porcentagem de pessoas com altura maior que 2.0 metros
    float porcentagemMaiorQue2 = static_cast<float>(contadorMaiorQue2) / 10;

    //Imprime a média, a maior altura, a menor altura e a porcentagem de pessoas maiores que 2 metros
    printf("\nAltura media: %.2f metros\n", media);
    printf("Maior altura: %.2f metros\n", maiorAltura);
    printf("Menor altura: %.2f metros\n", menorAltura);
    printf("Porcentagem de pessoas com altura maior que 2.0 metros: %.2f%%\n", porcentagemMaiorQue2);

    return 0;
}