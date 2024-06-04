#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó na BST (Árvore de Busca Binária)
typedef struct no {
    int cha;
    struct no *esquerda;
    struct no *direita;
} tNo;

// Função para criar um novo nó
tNo *criar_no(int cha) {
    tNo *nov_no = (tNo *) malloc(sizeof(tNo)); // Usando o typedef
    if (nov_no == NULL) {
        fprintf(stderr, "Erro: Falha ao alocar memoria para novo no.\n");
        exit(EXIT_FAILURE);
    }
    nov_no->cha = cha;
    nov_no->esquerda = nov_no->direita = NULL;
    return nov_no;
}

// Função para inserir um nó na BST
tNo *inserir_no(tNo *raiz, int cha) {
    if (raiz == NULL) {
        return criar_no(cha);
    }

    if (cha < raiz->cha) {
        raiz->esquerda = inserir_no(raiz->esquerda, cha);
    } else if (cha > raiz->cha) {
        raiz->direita = inserir_no(raiz->direita, cha);
    } else {
        fprintf(stderr, "Erro: Chave duplicada nao permitida.\n");
        exit(EXIT_FAILURE);
    }

    return raiz;
}

// Função para buscar um elemento na BST
tNo *bus_elem(tNo *raiz, int cha) {
    if (raiz == NULL || raiz->cha == cha) {
        return raiz;
    }

    if (cha < raiz->cha) {
        return bus_elem(raiz->esquerda, cha);
    } else {
        return bus_elem(raiz->direita, cha);
    }
}


int main() {
    tNo *raiz = NULL;
    raiz = inserir_no(raiz, 50);
    inserir_no(raiz, 30);
    inserir_no(raiz, 20);
    inserir_no(raiz, 40);
    inserir_no(raiz, 70);
    inserir_no(raiz, 60);
    inserir_no(raiz, 80);

     // Chaves predefinidas para busca
    int chaves[] = {30, 40, 90};

    // Buscar cada uma das chaves na árvore
    for (int i = 0; i < 3; i++) {
        tNo *result = bus_elem(raiz, chaves[i]);
        if (result != NULL) {
            printf("Elemento %d encontrado.\n", chaves[i]);
        } else {
            printf("Elemento %d nao encontrado.\n", chaves[i]);
        }
    }

    return 0;
}

