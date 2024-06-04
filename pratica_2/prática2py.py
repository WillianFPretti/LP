'''

Program: Continuously print which quadrant the mouse pointer is in.

Author: Willian Ferrari Pretti

Date: 19/03/2024

Description: Program divides the screen into four sectors A,B,C and D. As the mouse passes under the screen
It will appear in which quadrant of the screen the mouse is.

License: Pycharm (Não encontrei o tipo de licença)

'''

from ctypes import windll, Structure, c_long, byref
import time
import msvcrt

# Define a classe Ponto para representar as coordenadas do mouse
class Ponto(Structure):
    _fields_ = [("x", c_long), ("y", c_long)]

# Função para obter a posição atual do mouse
def obter_mouse_pos():
    pt = Ponto()
    windll.user32.GetCursorPos(byref(pt))
    return {"x": pt.x, "y": pt.y}

# Define a largura e altura da tela
tela_larg = 1920
tela_alt = 1080

# Loop infinito para monitorar continuamente a posição do mouse
while True:
    # Obtém a posição atual do mouse
    pos = obter_mouse_pos()

    # Verifica em qual quadrante a posição do mouse se encontra e imprime a mensagem correspondente
    if (pos["x"] < tela_larg / 2):
        if (pos["y"] < tela_alt / 2):
            print('Posição do mouse: Quadrante A')
        else:
            print('Posição do mouse: Quadrante C ')
    elif (pos["x"] >= tela_larg / 2):
        if (pos["y"] < tela_alt / 2):
            print('Posição do mouse: Quadrante B')
        else:
            print('Posição do mouse: Quadrante D')

    # Aguarda um curto período de tempo antes de verificar novamente a posição do mouse
    time.sleep(0.1)

    # Verifica se uma tecla foi pressionada no console
    if msvcrt.kbhit():
        if msvcrt.getch() == 'c':
            break



