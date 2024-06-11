#include "./include/microempreendedor.hpp"

MicroEmpreendedor::MicroEmpreendedor(const std::string& nome, int idade, int cpf, int cnpj) 
    : Pessoa(nome, idade, cpf), Empresa(cnpj) {}

MicroEmpreendedor::~MicroEmpreendedor() {}

void MicroEmpreendedor::exibe_cpf() {
    std::cout << "CPF: " << cpf << std::endl;
}

void MicroEmpreendedor::exibe_cnpj() {
    std::cout << "CNPJ: " << cnpj << std::endl;
}
