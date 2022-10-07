#include "Catalogo.hpp"
#include "Produto.hpp"
#include "Pedido.hpp"
#include "Brinquedo.hpp"
#include "Livro.hpp"
#include "Eletronico.hpp"
#include <iostream>

Catalogo::Catalogo(int id){
    _id = id;
}

void Catalogo::adicionar_produto(std::string nome, int idade_minima, float valor){
    int id = _id + 1;
    _id = id;
    Brinquedo* brinquedo = new Brinquedo(id, valor, nome, idade_minima);
    _produtos.push_back(brinquedo);
}

void Catalogo::adicionar_produto(std::string titulo, std::string autor, int ano, float valor){
    int id = _id + 1;
    _id = id;
    Livro* livro = new Livro(id, valor, titulo, autor, ano);
    _produtos.push_back(livro);
}

void Catalogo::adicionar_produto(std::string marca, std::string modelo, float valor){
    int id = _id + 1;
    _id = id;
    Eletronico* eletronico = new Eletronico(id, valor, marca, modelo);
    _produtos.push_back(eletronico);
}

Produto* Catalogo::buscar_produto(int id){
    for(int i = 0; i < _produtos.size(); i++){
        if(_produtos[i]->getId() == id){
            return _produtos[i];
        }
    }
    std::cout << "Produto não encontrado" << std::endl;
    return nullptr;
}

void Catalogo::imprimir(){
    for(int i = 0; i < _produtos.size(); i++){
        _produtos[i]->imprimir_info();
    }
}