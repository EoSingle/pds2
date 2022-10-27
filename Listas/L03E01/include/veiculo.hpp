#pragma once

#include <string>
#include <iostream>

class Veiculo{
    private:
        int _id;
        std::string _subtipo;
        static int _next_id;

    protected:
        int _velo_max;
        int _n_passageiros;

    public:
        // Construtor & Destrutor
        Veiculo(std::string subtipo, int velocidade, int passageiros);
        virtual ~Veiculo();


        // Getters
        int get_id();

        // Metodos
        virtual int estima_preco() = 0;
        virtual void print_info();

};


