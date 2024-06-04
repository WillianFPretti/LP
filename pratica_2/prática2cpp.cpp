/*
* Program: Continuously print which quadrant the mouse pointer is in.

* Author: Willian Ferrari Pretti

* Date: 19/03/2024

* Description: Program divides the screen into four sectors A,B,C and D. As the mouse passes under the screen
It will appear in which quadrant of the screen the mouse is.

* License: GNU GENERAL PUBLIC LICENSE

*/

#include <iostream>
#include <Windows.h>
#include <conio.h>

// Definição da estrutura Ponto para armazenar as coordenadas do mouse
struct Ponto {
    long x;
    long y;
};

int main() {
    // Declaração das variáveis
    Ponto pos;
    int tela_larg = 1920;
    int tela_alt = 1080;

    while (true) {
        char ch;
        // Verifica a posição do cursor do mouse
        if (GetCursorPos(reinterpret_cast<POINT*>(&pos))) {
            // Determina em qual quadrante o mouse está
            if (pos.x < tela_larg / 2) {
                if (pos.y < tela_alt / 2) {
                    std::cout << "Posição do mouse: Quadrante A" << std::endl;
                } else {
                    std::cout << "Posição do mouse: Quadrante C " << std::endl;
                }
            } else if (pos.y < tela_alt / 2) { // pos.x >= tela_larg / 2
                std::cout << "Posição do mouse: Quadrante B" << std::endl;
            } else {
                std::cout << "Posição do mouse: Quadrante D" << std::endl;
            }
        }

        // Aguarda um curto período de tempo
        Sleep(100); // ajuste conforme necessário

        // Verifica se uma tecla foi pressionada
        if (_kbhit()) {
            ch = _getch();
            if (ch == 'c') {
                break;
            }
        }
    }

    return 0;
}

