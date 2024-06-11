/*

Program: Experimento 8.2

Author: Willian Pretti

Date: 10/06/2024

Description: Replique agora para um projeto em C++, considerando os arquivos list.c e list.h

License: [Type of License]

*/


#include <iostream> 
#include "include/list.h" 

int main() {
    // Cria uma lista vazia
    Lista minhaLista;

    // Insere alguns elementos na lista
    minhaLista.inserir(10);
    minhaLista.inserir(20);
    minhaLista.inserir(30);

    // Imprime os elementos da lista
    std::cout << "Elementos da lista: ";
    minhaLista.imprimir();
    std::cout << std::endl;

    // Remove um elemento da lista
    minhaLista.remover(20);

    // Imprime os elementos da lista após a remoção
    std::cout << "Elementos da lista após a remoção: ";
    minhaLista.imprimir();
    std::cout << std::endl;

    // Limpa a lista
    minhaLista.limpar();

    return 0;
}
