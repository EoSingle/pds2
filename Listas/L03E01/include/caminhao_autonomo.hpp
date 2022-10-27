#pragma once

#include "caminhao.hpp"

class CaminhaoAutonomo : public Caminhao{
    protected:
    std::string _fabricante;

    public:
        // Construtor & Destrutor
        CaminhaoAutonomo(int velo_max, int n_passageiros, int carga_max, std::string fabricante);
        ~CaminhaoAutonomo();

        virtual int estima_preco() override;
        virtual void print_info() override;
};