#include <iostream>

int main() {
    
    /*Pedro Augusto de Souza Finochio
     2024.1.08.020*/
    
    /*Utilizamos esse tipo de dado chamado float para armazenar com precisão decimal
     os lados do triangulo, que podem ser números fracionados
     */
    float lado1, lado2, lado3;
    
   /*Utilizamos o comando cout para imprimir o título do programa e as ações que
   o usuário deve seguir para se determinar o tipo de triangulo; Inserimos
    o comando cin para permitir ao usuário inserir o lado do triangulo, a condicional
    * if para limitar o lado do triangulo a um número positivo e por fim, colocamos o
    * comando return 1 para impedir que o programa continue caso o usuário insira um 
    * valor menor ou igual a 0*/
  
                                        
    
    std::cout << "\nDiferenciação dos triângulos quanto ao seu lado";
    
    std::cout << "\nColoque o valor do lado1:";
    std::cin >> lado1;
    if (lado1<= 0){
        std::cout << "Insira apenas valores positivos";
        return 1;
    }
    
    std::cout << "\nColoque o valor do lado2:";
    std::cin >> lado2;
    if (lado2 <= 0){
       std::cout << "Insira apenas valores positivos";
        return 1;
    }
    
    std::cout << "\nColoque o valor do lado3:";
    std::cin >> lado3;
    if (lado3 <= 0){
        std::cout << "Insira apenas valores positivos";
        return 1;
    }
    
    /*Aqui, colocamos as condicionais if e else if para verificar se os lados que o
     * usuário inserir está compatível com os pré-requisitos para se formar um triangulo,
     *além disso, para especificar cada caso e as características dos triangulos quanto
     * ao seus lados, sejam eles equiláteros,isósceles,escaleno,retangulo ou escaleno
     * e retangulo 
     */

    if (lado1 + lado2 > lado3 && lado1 + lado3 > lado2 && lado2 + lado3 > lado1) {
        std::cout << "\nForma um triângulo ";
        if (lado1 == lado2 && lado2 == lado3) {
            std::cout << "\nO triângulo é equilátero";
        } else if (lado1 == lado2 || lado2 == lado3 || lado1 == lado3) {
            std::cout << "\nO triângulo é isósceles";
        } else {
           std::cout << "\nO triângulo é escaleno";
        }

        if (lado1*lado1 == lado2*lado2 + lado3*lado3 || lado2*lado2 == lado1*lado1 + lado3*lado3 || lado3*lado3 == lado1*lado1 + lado2*lado2) {
            std::cout << "\nO triângulo é retângulo";
        }
    } else {
        std::cout << "\nNão forma triângulo";
    }

    return 0;
}