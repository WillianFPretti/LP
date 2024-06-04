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

// Defini��o da estrutura para armazenar dados do c�rculo
struct Circle {
    float raio;
    float cir;
    float areac;
};

// Fun��o para exibir o menu
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
        
		// C�lculos referentes ao c�rculo
        if (opcao == 1) {
        	//Entradas dos dados
            float raio;
            cout << "Insira o raio do circulo: ";
            cin >> raio;
			//Criando uma inst�ncia
            Circle c;
            //Calculos do c�rculo
            c.cir = 2 * pi * raio;
            c.areac = pi * raio * raio;
			//Exibi��o dos resultados dos c�lculos
            cout << "Circunferencia do circulo: " << c.cir << endl;
            cout << "Area do circulo: " << c.areac << endl << endl;
        } 
		// C�lculos referentes ao ret�ngulo
		else if (opcao == 2) {
			//Entradas dos dados
            float a, b;
            cout << "Insira o comprimento e a largura do retangulo: ";
            cin >> a >> b;
			//Calculos do ret�ngulo
            float perimetro = 2 * (a + b);
            float area = a * b;
			//Exibi��o dos resultados dos c�lculos
            cout << "Perimetro do retangulo: " << perimetro << endl;
            cout << "Area do retangulo: " << area << endl << endl;
        } 
		//Op��o para fechar o programa
		else if (opcao == 3) {
            break;
        } else {
            cout << "Opcao invalida! Por favor, tente novamente.\n\n";
        }
    }

    return 0;
}

