#include "Eletronico.hpp"
#include "Produto.hpp"
#include <iostream>
#include <iomanip>

Eletronico::Eletronico(int id, float valor, std::string marca, std::string modelo) : Produto(id, valor){
    _marca = marca;
    _modelo = modelo;
}

void Eletronico::imprimir_info(){
    Produto::imprimir_info();
    std::cout << std::fixed;
    std::cout << getId() << "\t" << "Eletronico" << "\t" << _marca << "\t" <<
     _modelo << "\t" << "R$" << "\t" << std::setprecision(2) << getValorUnitario()
      << std::endl;
}