#ifndef BRINQUEDO_H
#define BRINQUEDO_H

#include "Produto.hpp"
#include <string>

class Brinquedo : public Produto{
    private:
        std::string _nome;
        int _idade_minima;
    
    public:
        Brinquedo(int id, float valor, std::string nome, int idade_minima);
        std::string getNome();
        int getIdadeMinima();
        void setNome(std::string nome);
        void setIdadeMinima(int idade_minima);
        virtual void imprimir_info() override;
};

#endif