#include "Livro.hpp"
#include "Produto.hpp"
#include <iostream>
#include <iomanip>

Livro::Livro(int id, float valor, std::string titulo, std::string autor, int ano) : Produto(id, valor){
    _titulo = titulo;
    _autor = autor;
    _ano = ano;
}

void Livro::imprimir_info(){
    Produto::imprimir_info();
    std::cout << std::fixed;
    std::cout << getId() << "\t" << "Livro" << "\t" <<_titulo << "\t" <<
     _autor << "\t" << _ano << "\t" << "R$" << "\t" << std::setprecision(2)
     << getValorUnitario() << std::endl;
}