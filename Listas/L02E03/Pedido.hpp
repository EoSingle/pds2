#ifndef PEDIDO_H
#define PEDIDO_H

#include "Produto.hpp"

class Pedido {
    private:
        Produto* _produto;
        int _quantidade;

    public:
        Pedido(Produto* produto, int quantidade);
        double get_valor_total();
        Produto * get_produto();
        int get_quantidade();
        ~ Pedido();
};

#endif