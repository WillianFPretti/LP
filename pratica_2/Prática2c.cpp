/*

* Program: Continuously print which quadrant the mouse pointer is in.

* Author: Willian Ferrari Pretti

* Date: 19/03/2024

* Description: Program divides the screen into four sectors A,B,C and D. As the mouse passes under the screen
It will appear in which quadrant of the screen the mouse is.

* License: GNU GENERAL PUBLIC LICENSE

*/

#include <stdio.h>
#include <windows.h>
#include <conio.h>

// Definição da estrutura Ponto para armazenar as coordenadas do mouse
struct Ponto {
    long x;
    long y;
};

int main() {
    // Declaração das variáveis
    struct Ponto pos;
    int tela_larg = 1920;
    int tela_alt = 1080;

    while (1) {
        char ch;
        // Verifica a posição do cursor do mouse
        if (GetCursorPos((POINT*)&pos)) {
            // Calcula o quadrante em que o mouse está
            char quadrante;
            if (pos.x < tela_larg / 2) {
                if (pos.y < tela_alt / 2) {
                    quadrante = 'A';
                } else {
                    quadrante = 'C';
                }
            } else {
                if (pos.y < tela_alt / 2) {
                    quadrante = 'B';
                } else {
                    quadrante = 'D';
                }
            }

            // Imprime o quadrante em que o mouse está
            switch (quadrante) {
                case 'A':
                    printf("Posição do mouse: Quadrante A\n");
                    break;
                case 'B':
                    printf("Posição do mouse: Quadrante B\n");
                    break;
                case 'C':
                    printf("Posição do mouse: Quadrante C\n");
                    break;
                case 'D':
                    printf("Posição do mouse: Quadrante D\n");
                    break;
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

