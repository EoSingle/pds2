#include "Produto.hpp"
#include <string>

Produto::Produto(int id, float valor){
    _id = id;
    _valor_unitario = valor;
}

void Produto::setId(int id){
    _id = id;
}

void Produto::setValorUnitario(float valor){
    _valor_unitario = valor;
}

int Produto::getId(){
    return _id;
}

float Produto::getValorUnitario(){
    return _valor_unitario;
}

void Produto::imprimir_info(){}