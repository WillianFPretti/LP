'''

Program: Calcular area e circunferencia de um circulo

Author: Willian Ferrari Pretti

Date: 06/03/2024

Description: Programa que calcula a area de retangulos e circulos e circunferencia de circulos

License: Não encontrei no Pycharm

'''

#DEFININDO PI
pi = 3.14

#DEFINIÇÃO DA FUNÇÃO PARA EXIBIR AS OPÇÕES DO MENU
def menu():
    print('SELECIONE: ')
    print()
    print('[1] CÍRCULO');
    print('[2] RETÂNGULO')
    print('[3] SAIR')
    print()

#Loop infinito que será executado até a instrução "BREAK"
while True:

    #Exibição do menu
    menu()
    n = int(input('Insira uma opção: '))
    print()

    #Cálculos referentes ao círuclo	
    if (n==1):
	
	#Entrada do raio do círculo
        raio = float(input('Insira um valor de raio: '))
        print()

	#Calculos do círculo
        cir = 2 * pi * raio
        areac = pi * raio**2

	#Exibição dos resultados dos cálculos
        print('O círculo tem: ')
        print('{:.2f} metros' .format(cir))
        print('{:.2f} metros quadrado' .format(areac))
        print()

    #Cálculos referentes ao retângulo
    elif (n==2):

	#Entrada dos lados do retângulo
        a = float(input('Insira o primeiro lado: '))
        b = float(input('Insira o segundo lado: '))
        print()

	#Cálculos do retângulo
        per = (2*a) + (2*b)
        arear = a * b
	
	#Exibição dos resultados dos cálculos
        print('O retângulo possui: ')
        print('{:.2f} metros de perímetro' .format(per))
        print('{:.2f} metros quadrados de área' .format(arear))
        print()

    #Se for 3 o usuário sairá do programa
    elif (n==3):
        break
    
    #Se a opção for diferente de 3, então aparecerá uma mensagem de erro
    else:
        print('INVÁLIDO')