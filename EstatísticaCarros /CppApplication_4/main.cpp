//Estatística em base de dados e veículos
//Pedro Augusto de Souza Finochio
//2024.1.08.020

#include <fstream>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

const int TAM = 99;

struct Carro {
    string modelo;
    string marca;
    string tipo;
    float ano;
    float km;
    float potenciadomotor;
    string combustivel;
    string cambio;
    string direcao;
    string cor;
    int portas;
    string placa;
    float valordoveiculo;
    bool valido;
};

int main() { //Declaração de variáveis 
    Carro bancodedados[TAM];
    int qtde = 0, opcao = 0;

    ifstream arquivo("BD_veiculos.txt"); //Abre o arquivo
    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo." << endl;
        return 1;
    }

    while (qtde < TAM && //Condicional para ler o arquivo e parar quando o modelo for = "FIM"
            arquivo >> bancodedados[qtde].modelo >> bancodedados[qtde].marca >>
            bancodedados[qtde].tipo >> bancodedados[qtde].ano >>
            bancodedados[qtde].km >> bancodedados[qtde].potenciadomotor >>
            bancodedados[qtde].combustivel >> bancodedados[qtde].cambio >>
            bancodedados[qtde].direcao >> bancodedados[qtde].cor >>
            bancodedados[qtde].portas >> bancodedados[qtde].placa >>
            bancodedados[qtde].valordoveiculo) {
        if (bancodedados[qtde].modelo == "FIM") {
            break;
        }
        bancodedados[qtde].valido = true;
        qtde++;
    }

    arquivo.close();

    do {//Menu de opções
        cout << "\nEstatística em Base de Dados de Veículos\n"
                << "1. Incluir um novo veículo na base de dados\n"
                << "2. Buscar um veículo pela placa\n"
                << "3. Buscar um veículo pelo tipo\n"
                << "4. Buscar um veículo pelo câmbio\n"
                << "5. Buscar um veículo por faixa de valores\n"
                << "6. Relatório do banco de dados\n"
                << "7. Sair\n"
                << "Escolha a opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
            {//Adicionar um veículo ao banco de dados
                if (qtde < TAM) {
                    cout << "Digite o modelo do veículo: ";
                    cin >> bancodedados[qtde].modelo;
                    cout << "Digite a marca do veículo: ";
                    cin >> bancodedados[qtde].marca;
                    cout << "Digite o tipo do veículo: ";
                    cin >> bancodedados[qtde].tipo;
                    cout << "Digite o ano do veículo: ";
                    cin >> bancodedados[qtde].ano;
                    cout << "Digite a quilometragem do veículo: ";
                    cin >> bancodedados[qtde].km;
                    cout << "Digite a potência do motor do veículo: ";
                    cin >> bancodedados[qtde].potenciadomotor;
                    cout << "Digite o tipo de combustível utilizado no veículo: ";
                    cin >> bancodedados[qtde].combustivel;
                    cout << "Digite o câmbio do veículo: ";
                    cin >> bancodedados[qtde].cambio;
                    cout << "Digite a direção do veículo: ";
                    cin >> bancodedados[qtde].direcao;
                    cout << "Digite a cor do veículo: ";
                    cin >> bancodedados[qtde].cor;
                    cout << "Digite a quantidade de portas do veículo: ";
                    cin >> bancodedados[qtde].portas;
                    cout << "Digite a placa do veículo: ";
                    cin >> bancodedados[qtde].placa;
                    cout << "Digite o valor do veículo: ";
                    cin >> bancodedados[qtde].valordoveiculo;
                    bancodedados[qtde].valido = true;
                    qtde++;
                } else {
                    cout << "Não é possível adicionar mais carros" << endl;
                }
                break;
            }
            case 2:
            {//Pesquisar um veículo pela placa correspondente 
                string busca;
                cout << "Digite a placa do veículo: ";
                cin >> busca;
                bool encontrado = false;
                for (int i = 0; i < qtde; i++) {
                    if (bancodedados[i].placa == busca && bancodedados[i].valido) {
                        cout << "Modelo: " << bancodedados[i].modelo << endl;
                        cout << "Marca: " << bancodedados[i].marca << endl;
                        cout << "Tipo: " << bancodedados[i].tipo << endl;
                        cout << "Ano: " << bancodedados[i].ano << endl;
                        cout << "Km: " << bancodedados[i].km << endl;
                        cout << "Potência do motor: " << bancodedados[i].potenciadomotor
                                << endl;
                        cout << "Tipo de combustível: " << bancodedados[i].combustivel
                                << endl;
                        cout << "Câmbio do veículo: " << bancodedados[i].cambio << endl;
                        cout << "Direção do veículo: " << bancodedados[i].direcao << endl;
                        cout << "Cor do veículo: " << bancodedados[i].cor << endl;
                        cout << "Quantidade de portas: " << bancodedados[i].portas << endl;
                        cout << "Placa do veículo: " << bancodedados[i].placa << endl;
                        cout << "Valor do veículo: " << bancodedados[i].valordoveiculo
                                << endl;
                        encontrado = true;
                        break;
                    }
                }
                if (!encontrado) {
                    cout << "Carro não encontrado no banco de dados" << endl;
                }
                break;
            }
            case 3:
            {//Pesquisar um veículo pela sua categoria 
                string busca;
                cout << "Digite o tipo do veículo: ";
                cin >> busca;
                bool encontrado = false;
                for (int i = 0; i < qtde; i++) {
                    if (bancodedados[i].tipo == busca && bancodedados[i].valido) {
                        cout << "Modelo: " << bancodedados[i].modelo << endl;
                        cout << "Marca: " << bancodedados[i].marca << endl;
                        cout << "Tipo: " << bancodedados[i].tipo << endl;
                        cout << "Ano: " << bancodedados[i].ano << endl;
                        cout << "Km: " << bancodedados[i].km << endl;
                        cout << "Potência do motor: " << bancodedados[i].potenciadomotor
                                << endl;
                        cout << "Tipo de combustível: " << bancodedados[i].combustivel
                                << endl;
                        cout << "Câmbio do veículo: " << bancodedados[i].cambio << endl;
                        cout << "Direção do veículo: " << bancodedados[i].direcao << endl;
                        cout << "Cor do veículo: " << bancodedados[i].cor << endl;
                        cout << "Quantidade de portas: " << bancodedados[i].portas << endl;
                        cout << "Placa do veículo: " << bancodedados[i].placa << endl;
                        cout << "Valor do veículo: " << bancodedados[i].valordoveiculo
                                << endl;
                        encontrado = true;
                    }
                }
                if (!encontrado) {
                    cout << "Carro não encontrado no banco de dados" << endl;
                }
                break;
            }
            case 4:
            {//Pesquisar um veículo pelo cambio 
                string busca;
                cout << "Digite o câmbio do veículo: ";
                cin >> busca;
                bool encontrado = false;
                for (int i = 0; i < qtde; i++) {
                    if (bancodedados[i].cambio == busca && bancodedados[i].valido) {
                        cout << "Modelo: " << bancodedados[i].modelo << endl;
                        cout << "Marca: " << bancodedados[i].marca << endl;
                        cout << "Tipo: " << bancodedados[i].tipo << endl;
                        cout << "Ano: " << bancodedados[i].ano << endl;
                        cout << "Km: " << bancodedados[i].km << endl;
                        cout << "Potência do motor: " << bancodedados[i].potenciadomotor
                                << endl;
                        cout << "Tipo de combustível: " << bancodedados[i].combustivel
                                << endl;
                        cout << "Câmbio do veículo: " << bancodedados[i].cambio << endl;
                        cout << "Direção do veículo: " << bancodedados[i].direcao << endl;
                        cout << "Cor do veículo: " << bancodedados[i].cor << endl;
                        cout << "Quantidade de portas: " << bancodedados[i].portas << endl;
                        cout << "Placa do veículo: " << bancodedados[i].placa << endl;
                        cout << "Valor do veículo: " << bancodedados[i].valordoveiculo
                                << endl;
                        encontrado = true;
                    }
                }
                if (!encontrado) {
                    cout << "Carro não encontrado no banco de dados" << endl;
                }
                break;
            }
            case 5:
            {//Pesquisar um veículo por uma faixa de valores 
                string min, max;
                cout << "Digite o valor mínimo: ";
                cin >> min;
                cout << "Digite o valor máximo: ";
                cin >> max;
                bool encontrado = false;
                for (int i = 0; i < qtde; i++) {
                    float valor = bancodedados[i].valordoveiculo;
                    if (valor >= stof(min) && valor <= stof(max) &&
                            bancodedados[i].valido) {
                        cout << "Modelo: " << bancodedados[i].modelo << endl;
                        cout << "Marca: " << bancodedados[i].marca << endl;
                        cout << "Tipo: " << bancodedados[i].tipo << endl;
                        cout << "Ano: " << bancodedados[i].ano << endl;
                        cout << "Km: " << bancodedados[i].km << endl;
                        cout << "Potência do motor: " << bancodedados[i].potenciadomotor
                                << endl;
                        cout << "Tipo de combustível: " << bancodedados[i].combustivel
                                << endl;
                        cout << "Câmbio do veículo: " << bancodedados[i].cambio << endl;
                        cout << "Direção do veículo: " << bancodedados[i].direcao << endl;
                        cout << "Cor do veículo: " << bancodedados[i].cor << endl;
                        cout << "Quantidade de portas: " << bancodedados[i].portas << endl;
                        cout << "Placa do veículo: " << bancodedados[i].placa << endl;
                        cout << "Valor do veículo: " << bancodedados[i].valordoveiculo
                                << endl;
                        encontrado = true;
                    }
                }
                if (!encontrado) {
                    cout << "Nenhum veículo encontrado na faixa de valores informada."
                            << endl;
                }
                break;
            }

            case 6:
            {
                // Exibição do relatório do banco de dados 
                float qtd_hatch = 0, qtd_suv = 0, qtd_pickup = 0, qtd_sedan = 0,
                        qtd_van = 0, qtd_gasolina = 0, qtd_diesel = 0, qtd_flex = 0;
                for (int i = 0; i < qtde; i++) {
                    // Loop para contar a categoria do veículo
                    if (bancodedados[i].valido) {
                        if (bancodedados[i].tipo == "Hatch" ||
                                bancodedados[i].tipo == "HATCH" ||
                                bancodedados[i].tipo == "hatch") {
                            qtd_hatch++;
                        } else if (bancodedados[i].tipo == "Suv" ||
                                bancodedados[i].tipo == "SUV" ||
                                bancodedados[i].tipo == "suv") {
                            qtd_suv++;
                        } else if (bancodedados[i].tipo == "Pick-up" ||
                                bancodedados[i].tipo == "PICK-UP" ||
                                bancodedados[i].tipo == "pick-up") {
                            qtd_pickup++;
                        } else if (bancodedados[i].tipo == "Sedan" ||
                                bancodedados[i].tipo == "SEDAN" ||
                                bancodedados[i].tipo == "sedan") {
                            qtd_sedan++;
                        } else if (bancodedados[i].tipo == "Van" ||
                                bancodedados[i].tipo == "VAN" ||
                                bancodedados[i].tipo == "van") {
                            qtd_van++;
                        }

                        // Contagem do tipo de combustível
                        if (bancodedados[i].combustivel == "Gasolina" ||
                                bancodedados[i].combustivel == "gasolina") {
                            qtd_gasolina++;
                        } else if (bancodedados[i].combustivel == "Diesel" ||
                                bancodedados[i].combustivel == "diesel") {
                            qtd_diesel++;
                        } else if (bancodedados[i].combustivel == "Flex" ||
                                bancodedados[i].combustivel == "flex") {
                            qtd_flex++;
                        }
                    }
                }

                // Cálculo das porcentagens de cada tipo de veículo
                float total_veiculos = qtde; 
                qtd_hatch = (qtd_hatch / total_veiculos) * 100.0;
                qtd_suv = (qtd_suv / total_veiculos) * 100.0;
                qtd_pickup = (qtd_pickup / total_veiculos) * 100.0;
                qtd_sedan = (qtd_sedan / total_veiculos) * 100.0;
                qtd_van = (qtd_van / total_veiculos) * 100.0;

                // Exibição das porcentagens de cada tipo de veículo
                cout << "Porcentagem de carros por tipo:" << endl;
                cout << "Hatch: " << qtd_hatch << "%" << endl;
                cout << "SUV: " << qtd_suv << "%" << endl;
                cout << "Pick-up: " << qtd_pickup << "%" << endl;
                cout << "Sedan: " << qtd_sedan << "%" << endl;
                cout << "Van: " << qtd_van << "%" << endl;

                // Cálculo das porcentagens de cada tipo de combustível
                qtd_gasolina = (qtd_gasolina / total_veiculos) * 100.0;
                qtd_diesel = (qtd_diesel / total_veiculos) * 100.0;
                qtd_flex = (qtd_flex / total_veiculos) * 100.0;

                // Exibição das porcentagens de cada tipo de combustível
                cout << "\nPorcentagem de carros por tipo de combustível:" << endl;
                cout << "Gasolina: " << qtd_gasolina << "%" << endl;
                cout << "Diesel: " << qtd_diesel << "%" << endl;
                cout << "Flex: " << qtd_flex << "%" << endl;

                float menorValorMotor1 = 1000000.0;
                string placaMenorValorMotor1;
                bool encontrouMenorMotor1 = false;

                for (int i = 0; i < qtde; i++) {
                    // Loop para percorrer o arquivo e encontrar o carro mais barato com motor 1.0 
                    if (bancodedados[i].valido && bancodedados[i].potenciadomotor == 1.0) {
                        encontrouMenorMotor1 = true;
                        if (bancodedados[i].valordoveiculo < menorValorMotor1) {
                            menorValorMotor1 = bancodedados[i].valordoveiculo;
                            placaMenorValorMotor1 = bancodedados[i].placa;
                        }
                    }
                }

                if (encontrouMenorMotor1) {
                    // Verificar se encontrou o carro mais barato com motor 1.0 
                    cout << "\nInformações sobre o veículo mais barato com potência do motor 1.0:" << endl;
                    cout << "Placa: " << placaMenorValorMotor1 << endl;
                    cout << "Valor: " << menorValorMotor1 << endl;

                    // Cálculo do valor da prestação do financiamento em 60 meses
                    float taxaJuros = 0.05;
                    float valorFinanciado = menorValorMotor1;

                    int meses = 60;

                    float taxaJurosMensal = taxaJuros / 12;
                    float parcela = (valorFinanciado * taxaJurosMensal) /
                            (1 - pow(1 + taxaJurosMensal, -meses));

                    cout << "Valor da prestação em 60 meses: " << parcela << endl;
                } else {
                    cout << "\nNenhum veículo com potência do motor 1.0 encontrado." << endl;
                }

                float maiorValorDirecaoAuto = 0;
                string placaMaiorValorDirecaoAuto;
                bool encontrouMaiorDirecaoAuto = false;

                for (int i = 0; i < qtde; i++) {
                    if (bancodedados[i].valido && bancodedados[i].direcao == "Hidráulica" &&
                            bancodedados[i].cambio == "Automático") {
                        encontrouMaiorDirecaoAuto = true;
                        if (bancodedados[i].valordoveiculo > maiorValorDirecaoAuto) {
                            maiorValorDirecaoAuto = bancodedados[i].valordoveiculo;
                            placaMaiorValorDirecaoAuto = bancodedados[i].placa;
                        }
                    }
                }

                if (encontrouMaiorDirecaoAuto) {
                    cout << "\nInformações sobre o veículo mais caro com direção hidráulica e câmbio automático:" << endl;
                    cout << "Placa: " << placaMaiorValorDirecaoAuto << endl;
                    cout << "Valor: " << maiorValorDirecaoAuto << endl;

                    float percentualSeguro = 0.05;
                    float valorSeguroEstimado = maiorValorDirecaoAuto * percentualSeguro;

                    cout << "Valor do seguro estimado: " << valorSeguroEstimado << endl;
                } else {
                    cout << "\nNenhum veículo com direção hidráulica e câmbio automático encontrado." << endl;
                }

                // Quantidade e Média de Quilometragem (veículos com 5 anos ou mais)
                int veiculos5anosoumais = 0;
                int kmTotal5anosoumais = 0;
                for (int i = 0; i < qtde; i++) {
                    if (bancodedados[i].valido && bancodedados[i].ano <= 2019) { // Verifica se o veículo tem 5 anos ou mais
                        veiculos5anosoumais++;
                        kmTotal5anosoumais += bancodedados[i].km;
                    }
                }

                float mediaKm5anosoumais = 0;
                if (veiculos5anosoumais > 0) {
                    mediaKm5anosoumais = (float) kmTotal5anosoumais / veiculos5anosoumais;
                }

                cout << endl << "O número de carros com 5 anos ou mais é: " << veiculos5anosoumais;
                cout << endl << "Com uma média de: " << mediaKm5anosoumais << " KM percorridos" << endl;

                break;
            }

            case 7:
            {//Encerrar o programa 
                cout << "Voce saiu do programa" << endl;
                break;
            }
            default:
            {
                cout << "Opção inválida. Tente novamente." << endl;
                break;
            }
        }
    } while (opcao != 7);

    return 0;
}
