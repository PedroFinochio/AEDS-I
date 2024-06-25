/*Trabalho 3 AEDS 1: Cena Gráfica
 * Pedro Augusto de Souza Finochio 2024.1.08.020*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <math.h>

const float pi = 3.14;

using namespace std;

int main() {
    /* Declaração de variáveis */
    float lado, raio, lado1, lado2, lado3, alt, base, área, vol, lar, comp, ger;
    float áreatotal = 0;
    float volumetotal = 0;
    string objeto;

    ifstream arquivo("cenagrafica.txt"); /* Função para ler dados de um arquivo */

    if (!arquivo.is_open()) { /* Condicional para abrir o arquivo corretamente */
        cout << "Erro ao abrir o arquivo " << endl;
        return 1;
    }

    while (arquivo >> objeto && objeto != "fim") {
        /* Loop para ler cada detalhe do arquivo, imprimir na tela o objeto e interromper quando encontrar a palavra "fim" */
        cout << "O objeto é o(a) :" << endl << objeto << endl;

        if (objeto == "cubo") { /* Condicional para calcular a área e volume do cubo */
            arquivo >> lado;
            vol = pow(lado, 3);
            área = 6 * pow(lado, 2);
            cout << "A área do cubo é:" << área << endl;
            cout << "O volume do cubo é:" << vol << endl << endl;

        } else if (objeto == "esfera") { /* Condicional para calcular a área e volume da esfera */
            arquivo >> raio;
            vol = 4.0 / 3 * pi * pow(raio, 3);
            área = 4 * pi * pow(raio, 2);
            cout << "A área da esfera é:" << área << endl;
            cout << "O volume da esfera é:" << vol << endl << endl;

        } else if (objeto == "quadrado") { /* Condicional para calcular a área do quadrado */
            arquivo >> lado;
            área = pow(lado, 2);
            cout << "A área do quadrado é:" << área << endl << endl;

        } else if (objeto == "círculo") { /* Condicional para calcular a área do círculo */
            arquivo >> raio;
            área = pi * pow(raio, 2);
            cout << "A área do círculo é:" << área << endl << endl;

        } else if (objeto == "retangulo") { /* Condicional para calcular a área do retangulo */
            arquivo >> base >> alt;
            área = base * alt;
            cout << "A área do retângulo é:" << área << endl << endl;

        } else if (objeto == "paralelepípedo") { /* Condicional para calcular a área e o volume do paralelepípedo */
            arquivo >> alt >> lar >> comp;
            área = 2 * (lar * comp + comp * alt + lar * alt);
            vol = alt * lar * comp;
            cout << "A área do paralelepípedo é:" << área << endl;
            cout << "O volume do paralelepípedo é:" << vol << endl << endl;

        } else if (objeto == "cilindro") { /* Condicional para calcular a área e volume do cilindro */
            arquivo >> raio >> alt;
            área = 2 * pi * raio * (raio + alt);
            vol = pi * pow(raio, 2) * alt;
            cout << "A área do cilindro é:" << área << endl;
            cout << "O volume do cilindro é:" << vol << endl << endl;

        } else if (objeto == "cone") { /* Condicional para calcular a área e volume do cone */
            arquivo >> raio >> alt >> ger;
            área = pi * raio * ger + pi * pow(raio, 2);
            vol = (pi * pow(raio, 2) * alt) / 3;
            cout << "A área do cone é:" << área << endl;
            cout << "O volume do cone é:" << vol << endl << endl;

        } else if (objeto == "triangulo") { /* Condicional para calcular a área do triângulo */
            arquivo >> base >> alt;
            área = (base * alt) / 2;
            cout << "A área do triângulo é:" << área << endl << endl;
        }

        /* Acumula a área e o volume */
        áreatotal += área;
        volumetotal += vol;
    }

    /* Imprime a área total e o volume total */
    cout << "A área total da cena é:" << áreatotal << endl;
    cout << "O volume total da cena é:" << volumetotal << endl;

    arquivo.close(); /* Fecha o arquivo */

    return 0;
}