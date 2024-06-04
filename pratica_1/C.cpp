/*

* Program: Calcular area e circunferencia de um circulo

* Author: Willian Ferrari Pretti

* Date: 06/03/2024

* Description: Programa que calcula a area de retangulos e circulos e circunferencia de circulos

* License: GNU GENERAL PUBLIC LICENSE (DEVC++)

*/

#include <stdio.h>
#include <stdlib.h>

//Declaração da constante
const float pi = 3.14;
//Declaração de variável global
int menu = 1;

//Definição da estrutura para armazenar dados do círculo
typedef struct{
	float raio;
	float cir;
	float areac;
} Circle;
//Definição da estrutura para armazenar dados do retângulo
typedef struct{
	float comp;
	float lar;
}Rectangle;

//Função principal
int main (){
	//Exibição do menu
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
		// Cálculos referentes ao círculo
		case 1:
			//Entradas dos dados
			float raio;
	 	
			printf("Insira o raio do circulo: ");
			scanf("%f", &raio);
			//Criando uma instância
			Circle c;
			//Calculos do círculo
			c.cir = 2*pi*raio;
			c.areac = pi * (raio*raio);
			//Exibição dos resultados dos cálculos
			printf("Raio do circulo: %.2f\n", raio);
			printf("\n");
			printf("Circunferencia: %.2f\n", c.cir);
			printf("Area do circulo: %.2f\n", c.areac);	
			
			break;
			
		// Cálculos referentes ao retângulo	
		case 2:			
			//Alocação dinâmica de memória 
			float *lad =(float*) malloc (2 * sizeof(float));
			//Veriicando se a alocação foi realizada
			if (lad == NULL){
				printf("ERRO!!\n");
				return -1;
			} else{
			//Pedindo dados do retângulo
			printf("Insira o lado a: ");
			scanf("%f", &lad[0]);
			printf("\n");
			printf("Insira o lado b: ");
			scanf("%f", &lad[1]);
			//Calculos do retângulo
			float per = 2 * (lad[0] + lad[1]);
			float arear = lad[0] * lad[1];
			//Exibição dos resultados dos cálculos
			printf("Lado a: %.2f\n", lad[0]);
			printf("Lado b: %.2f\n", lad[1]);
			
			printf("Perimetro do retangulo: %.2f\n", per);
			printf("Area do retangulo: %.2f\n", arear);
			//Liberação da memória alocada
			free(lad);
			
			}
			
			break;
		
	}	
	// Retornando 0 para mostrar sucesso na execução do programa
	return 0;
	}
	


