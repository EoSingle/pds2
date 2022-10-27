#pragma once

#include "veiculo.hpp"
#include <string>

class Caminhao : public Veiculo{
    protected:
        int _carga_max;

    public:
        // Construtor & Destrutor
        Caminhao(std::string subtipo, int velo_max, int n_passageiros, int carga_max);
        Caminhao(int velo_max, int n_passageiros, int carga_max);
        ~Caminhao();

        // Metodos
        virtual int estima_preco() override;
        virtual void print_info() override;
};