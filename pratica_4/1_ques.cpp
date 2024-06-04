/*

* Program: Prática 4 (1)

* Author: Willian Ferrari Pretti

* Date: 26/03/2024

* Description: Adicionar 5 elementos a lista utilizando as funções já definidas de acesso a lista;

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

// Insere um elemento no início da lista
void inserir_lista(tList *lista, int novo_dado) {
    tNode* novo_no = (tNode*) malloc(sizeof(tNode));
    if (novo_no == NULL) {
        printf("Erro: Sem espaço na memória.\n");
        return;
    }

    novo_no->data = novo_dado;
    novo_no->next = lista->first_elem; // Define o próximo do novo nó
    lista->first_elem = novo_no; // Atualiza o ponteiro externo da lista para o novo nó
}

// Remove um elemento de valor del_data
void remover_lista(tList *lista, int del_data) {
    // Verifica se a lista está vazia
    if (lista->first_elem == NULL) {
        printf("Não é possível deletar de uma lista vazia.\n");
        return;
    }

    tNode* atual = lista->first_elem;
    tNode* anterior = NULL;

    // Percorre a lista para encontrar o nó a ser deletado
    while (atual != NULL && atual->data != del_data) {
        anterior = atual;
        atual = atual->next;
    }

    // Se o nó a ser deletado for encontrado
    if (atual != NULL) {
        // Se o nó a ser deletado for o primeiro nó
        if (anterior == NULL) {
            lista->first_elem = atual->next;  // Atualiza o ponteiro da lista para pular o primeiro nó
        } else {
            anterior->next = atual->next;  // Liga o nó anterior ao próximo do nó atual
        }
    
        free(atual);  // Libera a memória alocada para o nó
    } else {
        printf("Nó com dado %d não encontrado na lista.\n", del_data);
    }
}

// Libera a memória alocada para a lista
void liberar_lista(tList *lista) {
    tNode* atual = lista->first_elem;
    tNode* temp;

    while (atual != NULL) {
        temp = atual;
        atual = atual->next;
        free(temp);  // Libera a memória alocada para cada nó
    }

    lista->first_elem = NULL;  // Define o ponteiro da lista como NULL após liberar todos os nós
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

