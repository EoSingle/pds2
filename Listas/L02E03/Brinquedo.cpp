#include "Brinquedo.hpp"
#include "Produto.hpp"
#include <string>
#include <iostream>
#include <iomanip>

Brinquedo::Brinquedo(int id, float valor, std::string nome, int idade_minima) : Produto(id, valor){
    _nome = nome;
    _idade_minima = idade_minima;
}

std::string Brinquedo::getNome(){
    return _nome;
}

int Brinquedo::getIdadeMinima(){
    return _idade_minima;
}

void Brinquedo::setNome(std::string nome){
    _nome = nome;
}

void Brinquedo::setIdadeMinima(int idade_minima){
    _idade_minima = idade_minima;
}

void Brinquedo::imprimir_info(){
    Produto::imprimir_info();
    std::cout << std::fixed;
    std::cout << getId() << "\t" << "Brinquedo" << "\t" <<getNome() << "\t" <<
      getIdadeMinima() << "\t" << "R$" << "\t" << std::setprecision(2) << 
      getValorUnitario() << std::endl;
}