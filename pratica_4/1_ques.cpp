/*

* Program: Pr�tica 4 (1)

* Author: Willian Ferrari Pretti

* Date: 26/03/2024

* Description: Adicionar 5 elementos a lista utilizando as fun��es j� definidas de acesso a lista;

* License: GNU GENERAL PUBLIC LICENSE

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} tNode;

typedef struct {
    tNode* first_elem;
} tList;

// Insere um elemento no in�cio da lista
void inserir_lista(tList *lista, int novo_dado) {
    tNode* novo_no = (tNode*) malloc(sizeof(tNode));
    if (novo_no == NULL) {
        printf("Erro: Sem espa�o na mem�ria.\n");
        return;
    }

    novo_no->data = novo_dado;
    novo_no->next = lista->first_elem; // Define o pr�ximo do novo n�
    lista->first_elem = novo_no; // Atualiza o ponteiro externo da lista para o novo n�
}

// Remove um elemento de valor del_data
void remover_lista(tList *lista, int del_data) {
    // Verifica se a lista est� vazia
    if (lista->first_elem == NULL) {
        printf("N�o � poss�vel deletar de uma lista vazia.\n");
        return;
    }

    tNode* atual = lista->first_elem;
    tNode* anterior = NULL;

    // Percorre a lista para encontrar o n� a ser deletado
    while (atual != NULL && atual->data != del_data) {
        anterior = atual;
        atual = atual->next;
    }

    // Se o n� a ser deletado for encontrado
    if (atual != NULL) {
        // Se o n� a ser deletado for o primeiro n�
        if (anterior == NULL) {
            lista->first_elem = atual->next;  // Atualiza o ponteiro da lista para pular o primeiro n�
        } else {
            anterior->next = atual->next;  // Liga o n� anterior ao pr�ximo do n� atual
        }
    
        free(atual);  // Libera a mem�ria alocada para o n�
    } else {
        printf("N� com dado %d n�o encontrado na lista.\n", del_data);
    }
}

// Libera a mem�ria alocada para a lista
void liberar_lista(tList *lista) {
    tNode* atual = lista->first_elem;
    tNode* temp;

    while (atual != NULL) {
        temp = atual;
        atual = atual->next;
        free(temp);  // Libera a mem�ria alocada para cada n�
    }

    lista->first_elem = NULL;  // Define o ponteiro da lista como NULL ap�s liberar todos os n�s
}

// Imprime todos os elementos da lista
void imprimir_lista(tList *lista) {
    tNode* atual = lista->first_elem;

    printf("Elementos da lista: ");
    while (atual != NULL) {
        printf("%d ", atual->data);
        atual = atual->next;
    }
    printf("\n");
}

//Adiciona 5 elementos a mais na lista
void adic_cinco_elem(tList *lista){
	inserir_lista(lista, 40);
	inserir_lista(lista, 50);
	inserir_lista(lista, 60);
	inserir_lista(lista, 70);
	inserir_lista(lista, 80);
}

// Construtor da lista
tList criar_lista() {
    tList lista;
    lista.first_elem = NULL;  // Inicializa a lista com um ponteiro NULL
    return lista;
}

int main(){
    
    tList lista = criar_lista();
  
    inserir_lista(&lista, 10);
    inserir_lista(&lista, 20);
    inserir_lista(&lista, 30);

    imprimir_lista(&lista);
    
    adic_cinco_elem(&lista);
    
    imprimir_lista(&lista);


    liberar_lista(&lista);

    return 0;
}

