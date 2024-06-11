#include <iostream>
#include "include/list.h"

void inserir_lista(Lista *lista, int novo_dado) {
    Node* novo_no = new Node;
    if (novo_no == nullptr) {
        std::cout << "Erro: Sem espaço disponível na memória." << std::endl;
        return;
    }

    novo_no->data = novo_dado;
    novo_no->next = lista->primeiro_elem;
    lista->primeiro_elem = novo_no;
}

void remover_lista(Lista *lista, int dado_remover) {
    if (lista->primeiro_elem == nullptr) {
        std::cout << "Não é possível excluir de uma lista vazia." << std::endl;
        return;
    }

    Node* atual = lista->primeiro_elem;
    Node* anterior = nullptr;

    while (atual != nullptr && atual->data != dado_remover) {
        anterior = atual;
        atual = atual->next;
    }

    if (atual != nullptr) {
        if (anterior == nullptr) {
            lista->primeiro_elem = atual->next;  
        } else {
            anterior->next = atual->next;  
        }
    
        delete atual;  
    } else {
        std::cout << "Nó com dado " << dado_remover << " não encontrado na lista." << std::endl;
    }
}

void liberar_lista(Lista *lista) {
    Node* atual = lista->primeiro_elem;
    Node* temp;

    while (atual != nullptr) {
        temp = atual;
        atual = atual->next;
        delete temp;  
    }

    lista->primeiro_elem = nullptr;  
}

void imprimir_lista(Lista *lista) {
    Node* atual = lista->primeiro_elem;

    std::cout << "Elementos da lista: ";
    while (atual != nullptr) {
        std::cout << atual->data << " ";
        atual = atual->next;
    }
    std::cout << std::endl;
}

Lista criar_lista() {
    Lista lista;
    lista.primeiro_elem = nullptr;  
    return lista;
}
