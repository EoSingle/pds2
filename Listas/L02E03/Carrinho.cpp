#include "Carrinho.hpp"
#include "Pedido.hpp"
#include "Produto.hpp"
#include <iostream>
#include <iomanip>

void Carrinho::adicionar_pedido(Produto* produto, int quantidade){
    Pedido* pedido = new Pedido(produto, quantidade);
    _pedidos.push_back(pedido);
}

void Carrinho::imprimir_resumo(){
    float total = 0;
    std::cout << std::fixed;
    for(int i=0 ; i < _pedidos.size() ; i++){
        _pedidos[i]->get_produto()->imprimir_info();
        std::cout << "Qtde: " << _pedidos[i]->get_quantidade() <<
         " Total produto: R$ " << std::setprecision(2) <<
          _pedidos[i]->get_valor_total() << std::endl;
        total += _pedidos[i]->get_valor_total();
    }
    std::cout << "Total carrinho: R$ " << std::setprecision(2) << total << std::endl;
}