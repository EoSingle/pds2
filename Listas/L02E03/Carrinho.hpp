#ifndef CARRINHO_H
#define CARRINHO_H

#include <vector>
#include "Pedido.hpp"
#include "Produto.hpp"

class Carrinho {
    private:
        std::vector < Pedido * > _pedidos;

    public:
        void adicionar_pedido(Produto* produto, int quantidade);
        ~ Carrinho();
        void imprimir_resumo();
};

#endif