/*

* Program: Calcular area e circunferencia de um circulo

* Author: Willian Ferrari Pretti

* Date: 06/03/2024

* Description: Programa que calcula a area de retangulos e circulos e circunferencia de circulos

* License: GNU GENERAL PUBLIC LICENSE (DEVC++)

*/

#include <stdio.h>
#include <stdlib.h>

//Declara��o da constante
const float pi = 3.14;
//Declara��o de vari�vel global
int menu = 1;

//Defini��o da estrutura para armazenar dados do c�rculo
typedef struct{
	float raio;
	float cir;
	float areac;
} Circle;
//Defini��o da estrutura para armazenar dados do ret�ngulo
typedef struct{
	float comp;
	float lar;
}Rectangle;

//Fun��o principal
int main (){
	//Exibi��o do menu
	printf("SELECIONE:");
	printf("\n");
	printf("[1] CIRCULO");
	printf("\n");
	printf("[2] RETANGULO");
	printf("\n");
	printf("\n");
	printf("Insira uma opcao: ");
	scanf("%d", &menu);
	printf("\n");
	
	switch(menu){
		// C�lculos referentes ao c�rculo
		case 1:
			//Entradas dos dados
			float raio;
	 	
			printf("Insira o raio do circulo: ");
			scanf("%f", &raio);
			//Criando uma inst�ncia
			Circle c;
			//Calculos do c�rculo
			c.cir = 2*pi*raio;
			c.areac = pi * (raio*raio);
			//Exibi��o dos resultados dos c�lculos
			printf("Raio do circulo: %.2f\n", raio);
			printf("\n");
			printf("Circunferencia: %.2f\n", c.cir);
			printf("Area do circulo: %.2f\n", c.areac);	
			
			break;
			
		// C�lculos referentes ao ret�ngulo	
		case 2:			
			//Aloca��o din�mica de mem�ria 
			float *lad =(float*) malloc (2 * sizeof(float));
			//Veriicando se a aloca��o foi realizada
			if (lad == NULL){
				printf("ERRO!!\n");
				return -1;
			} else{
			//Pedindo dados do ret�ngulo
			printf("Insira o lado a: ");
			scanf("%f", &lad[0]);
			printf("\n");
			printf("Insira o lado b: ");
			scanf("%f", &lad[1]);
			//Calculos do ret�ngulo
			float per = 2 * (lad[0] + lad[1]);
			float arear = lad[0] * lad[1];
			//Exibi��o dos resultados dos c�lculos
			printf("Lado a: %.2f\n", lad[0]);
			printf("Lado b: %.2f\n", lad[1]);
			
			printf("Perimetro do retangulo: %.2f\n", per);
			printf("Area do retangulo: %.2f\n", arear);
			//Libera��o da mem�ria alocada
			free(lad);
			
			}
			
			break;
		
	}	
	// Retornando 0 para mostrar sucesso na execu��o do programa
	return 0;
	}
	


