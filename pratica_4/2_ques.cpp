/*

* Program: Pr�tica 4 (2)

* Author: Willian Ferrari Pretti

* Date: 27/03/2024

* Description: Implementar as fun��es push(l,x) e pop(l) de forma que a lista "l" seja tratada como uma pilha

* License: GNU GENERAL PUBLIC LICENSE

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} tNode;

// Defini��o da estrutura para representar a pilha
typedef struct {
    tNode* top; // Ponteiro para o topo da pilha
} tPilha;

// Fun��o para inicializar a pilha
void inicializar_pilha(tPilha *pilha) {
    pilha->top = NULL; // Inicializa o topo da pilha como NULL
}

// Fun��o para liberar a mem�ria alocada para a pilha
void liberar_pilha(tPilha *pilha) {
    tNode* atual = pilha->top;
    tNode* temp;

    while (atual != NULL) {
        temp = atual;
        atual = atual->next;
        free(temp); // Libera a mem�ria alocada para cada n�
    }

    pilha->top = NULL; // Define o topo da pilha como NULL ap�s liberar todos os n�s
}

// Fun��o para imprimir os elementos da pilha
void imprimir_pilha(tPilha *pilha) {
    tNode* atual = pilha->top;

    printf("Elementos da pilha: ");
    while (atual != NULL) {
        printf("%d ", atual->data);
        atual = atual->next;
    }
    printf("\n");
}

// Fun��o para inserir um elemento no topo da pilha
void push(tPilha *pilha, int novo_dado) {
    tNode* novo_no = (tNode*) malloc(sizeof(tNode));
    if (novo_no == NULL) {
        printf("Erro: Sem espa�o na mem�ria.\n");
        return;
    }

    novo_no->data = novo_dado;
    novo_no->next = pilha->top; // O pr�ximo do novo n� aponta para o antigo topo
    pilha->top = novo_no; // Atualiza o topo para o novo n�
}

// Fun��o para remover o elemento do topo da pilha
int pop(tPilha *pilha) {
    if (pilha->top == NULL) {
        printf("Erro: Pilha vazia.\n");
        return -1; // Indicativo de erro, poderia ser tratado de outra forma dependendo do contexto
    }

    tNode* temp = pilha->top; // Salva o topo atual
    int dado_topo = temp->data; // Salva o dado do topo
    pilha->top = temp->next; // Atualiza o topo para o pr�ximo n�
    free(temp); // Libera a mem�ria alocada para o antigo topo
    return dado_topo; // Retorna o dado do topo removido
}

//Adiciona 5 elementos a mais na pilha (equivalente a adicionar 5 elementos � lista)
void adicionar_cinco_elementos(tPilha *pilha) {
    push(pilha, 40);
    push(pilha, 50);
    push(pilha, 60);
    push(pilha, 70);
    push(pilha, 80);
}

int main() {
    tPilha pilha;
    inicializar_pilha(&pilha); // Inicializa a pilha

    push(&pilha, 10);
    push(&pilha, 20);
    push(&pilha, 30);

    imprimir_pilha(&pilha);

    adicionar_cinco_elementos(&pilha);

    imprimir_pilha(&pilha);

    liberar_pilha(&pilha);

    return 0;
}

