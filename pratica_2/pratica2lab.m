{

Program: Continuously print which quadrant the mouse pointer is in.

Author: Willian Ferrari Pretti

Date: 19/03/2024

Description: Program divides the screen into four sectors A,B,C and D. As the mouse passes under the screen
It will appear in which quadrant of the screen the mouse is.

License: Octave (Não encontrei a licença)

%}

% Define a função para obter a posição atual do mouse
function pos = pratica2lab()
    pos = get(0, 'pointerlocation');
end

% Define a largura e altura da tela
tela_larg = 1920;
tela_alt = 1080;

while true
    % Obtém a posição atual do mouse
    pos = pratica2lab();

    % Calcula em qual quadrante a posição do mouse se encontra
    if pos(1) < tela_larg / 2
        if pos(2) < tela_alt / 2
            quadrante = 'A';  % Quadrante A: superior esquerdo
        else
            quadrante = 'C';  % Quadrante C: inferior esquerdo
        end
    elseif pos(1) >= tela_larg / 2
        if pos(2) < tela_alt / 2
            quadrante = 'B';  % Quadrante B: superior direito
        else
            quadrante = 'D';  % Quadrante D: inferior direito
        end
    end

    % Imprime o quadrante em que o mouse está
    switch quadrante
        case 'A'
            disp('Posição do mouse: Quadrante A');
        case 'B'
            disp('Posição do mouse: Quadrante B');
        case 'C'
            disp('Posição do mouse: Quadrante C');
        case 'D'
            disp('Posição do mouse: Quadrante D');
    end

    % Aguarda um curto período de tempo
    pause(0.1);

    % Verifica se uma tecla foi pressionada no console
    if kbhit()
        if getch() == 'c'  % Se a tecla 'c' for pressionada, interrompe o loop
            break;
        end
    end
end

