#ifndef CATALOGO_H
#define CATALOGO_H

#include "Produto.hpp"
#include "Brinquedo.hpp"
#include "Livro.hpp"
#include "Eletronico.hpp"
#include <vector>
#include <string>

class Catalogo{
    private:
        std::vector < Produto * > _produtos;
        int _id;

    public:
        Catalogo(int id=0);
        void adicionar_produto(std::string nome, int idade_minima, float valor);
        void adicionar_produto(std::string titulo, std::string autor, int ano, float valor);
        void adicionar_produto(std::string marca, std::string modelo, float valor);
        Produto* buscar_produto(int id);
        void imprimir();
};

#endif