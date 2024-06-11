/*

Program: Experimento 9

Author: Willian Pretti

Date: 10/06/2024

Description: Considerando o código dado na seção Aspectos Teóricos, crie uma classe MicroEmpreendedor que que seja herdeira tanto de Pessoa quanto de Empresa. Implemente os métodos exibe_cpf(), exibe_cnpj(), bem como o construtor e o destrutor. Na função main, chame as funções de exibir_cpf e exibir_cnpj

License: [Type of License]

*/

#include <iostream>
#include "./include/microempreendedor.hpp" 
#include "./include/exibe_cpf.hpp" 
#include "./include/exibe_cnpj.hpp" 
#include "./include/pessoa.hpp" 
#include "./include/empregado.hpp" 
#include "./include/empresa.hpp" 

int main() {
    // Criando instâncias de Pessoa e Empregado
    Pessoa* p = new Pessoa("Lucas", 30, 1182345678);
    Empregado* e = new Empregado("Luis", 23, 1500.00);
    Pessoa* p2 = e; // Convertendo o ponteiro de Empregado para Pessoa

    // Criando instância de Empresa
    Empresa empresa(2905700001);

    // Operações da Empresa
    empresa.paga(*e); // Pagando o empregado
    empresa.contrata(*(static_cast<Empregado*>(p2))); // Contratando o empregado convertido

    // Liberando memória
    delete p;
    delete e;

    return 0;
}
