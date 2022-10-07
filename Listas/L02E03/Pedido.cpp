#include "Pedido.hpp"
#include "Produto.hpp"

Pedido::Pedido(Produto* produto, int quantidade){
    _produto = produto;
    _quantidade = quantidade;
}

Pedido::~Pedido(){
    delete _produto;
}

double Pedido::get_valor_total(){
    return _produto->getValorUnitario() * _quantidade;
}

Produto * Pedido::get_produto(){
    return _produto;
}

int Pedido::get_quantidade(){
    return _quantidade;
}