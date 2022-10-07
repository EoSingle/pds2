#ifndef ELETRONICO_H
#define ELETRONICO_H

#include "Produto.hpp"
#include <string>

class Eletronico : public Produto{
    private:
        std::string _marca;
        std::string _modelo;
    
    public:
        Eletronico(int id, float valor, std::string marca, std::string modelo);
        std::string getMarca();
        std::string getModelo();
        void setMarca(std::string marca);
        void setModelo(std::string modelo);
        virtual void imprimir_info() override;
};


#endif