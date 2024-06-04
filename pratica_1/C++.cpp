/*

* Program: Calcular area e circunferencia de um circulo

* Author: Willian Ferrari Pretti

* Date: 06/03/2024

* Description: Programa que calcula a area de retangulos e circulos e circunferencia de circulos

* License: GNU GENERAL PUBLIC LICENSE (DEVC++)

*/

#include <iostream>
using namespace std;

const float pi = 3.14;

// Definição da estrutura para armazenar dados do círculo
struct Circle {
    float raio;
    float cir;
    float areac;
};

// Função para exibir o menu
void menu() {
    cout << "SELECIONE: \n\n";
    cout << "[1] CIRCULO\n";
    cout << "[2] RETANGULO\n";
    cout << "[3] SAIR\n\n";
}

int main() {
    int opcao;
    while (true) {
        menu();
        cout << "Insira uma opcao: ";
        cin >> opcao;
        cout << endl;
        
		// Cálculos referentes ao círculo
        if (opcao == 1) {
        	//Entradas dos dados
            float raio;
            cout << "Insira o raio do circulo: ";
            cin >> raio;
			//Criando uma instância
            Circle c;
            //Calculos do círculo
            c.cir = 2 * pi * raio;
            c.areac = pi * raio * raio;
			//Exibição dos resultados dos cálculos
            cout << "Circunferencia do circulo: " << c.cir << endl;
            cout << "Area do circulo: " << c.areac << endl << endl;
        } 
		// Cálculos referentes ao retângulo
		else if (opcao == 2) {
			//Entradas dos dados
            float a, b;
            cout << "Insira o comprimento e a largura do retangulo: ";
            cin >> a >> b;
			//Calculos do retângulo
            float perimetro = 2 * (a + b);
            float area = a * b;
			//Exibição dos resultados dos cálculos
            cout << "Perimetro do retangulo: " << perimetro << endl;
            cout << "Area do retangulo: " << area << endl << endl;
        } 
		//Opção para fechar o programa
		else if (opcao == 3) {
            break;
        } else {
            cout << "Opcao invalida! Por favor, tente novamente.\n\n";
        }
    }

    return 0;
}

