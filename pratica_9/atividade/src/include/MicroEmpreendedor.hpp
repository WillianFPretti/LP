#ifndef MICROEMPREENDENDOR_HPP
#define MICROEMPREENDENDOR_HPP

#include "pessoa.hpp"
#include "empresa.hpp"

class MicroEmpreendedor : public Pessoa, public Empresa {
public:
    MicroEmpreendedor(const std::string& nome, int idade, int cpf, int cnpj);
    virtual ~MicroEmpreendedor();

    void exibe_cpf();
    void exibe_cnpj();
};

#endif /* MICROEMPREENDENDOR_HPP */
