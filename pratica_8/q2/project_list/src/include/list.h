#ifndef LIST_H
#define LIST_H

// Estrutura para representar um nó na lista
struct Node {
    int data;         // Dado armazenado no nó
    Node* next;       // Ponteiro para o próximo nó
};

// Estrutura para representar uma lista
struct Lista {
    Node* primeiro_elem;  // Ponteiro para o primeiro nó da lista
};

// Protótipos das funções para manipulação da lista

// Insere um novo elemento na lista
void inserir_lista(Lista *lista, int novo_dado);

// Remove um elemento da lista
void remover_lista(Lista *lista, int dado_remover);

// Libera a memória alocada para a lista
void liberar_lista(Lista *lista);

// Imprime os elementos da lista
void imprimir_lista(Lista *lista);

// Cria e retorna uma lista vazia
Lista criar_lista();

#endif /* LIST_H */
