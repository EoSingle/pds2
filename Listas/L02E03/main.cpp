// NÃO ALTERE ESSA LINHA
#include "avaliacao_basica_ecommerce.hpp"
#include "Catalogo.hpp"
#include "Carrinho.hpp"
#include <iostream>
#include <string>

int main() {
    Catalogo catalogo;
    Carrinho carrinho;
    char data;
    while(std::cin>>data){
        switch (data){
            case 'q':{
                std::string nome;
                int idade;
                float valor;
                std::cin>>nome>>idade>>valor;
                catalogo.adicionar_produto(nome, idade, valor);
                break;
            }
            case 'l':{
                std::string titulo, autor;
                int ano;
                float valor;
                std::cin>>titulo>>autor>>ano>>valor;
                catalogo.adicionar_produto(titulo, autor, ano, valor);
                break;
            }
            case 'e':{
                std::string marca, modelo;
                float valor;
                std::cin>>marca>>modelo>>valor;
                catalogo.adicionar_produto(marca, modelo, valor);
                break;
            }
            case 'c':{
                catalogo.imprimir();
                break;
            }
            case 'p':{
                int id, quantidade;
                std::cin>>id>>quantidade;
                Produto* produto = catalogo.buscar_produto(id);
                if(produto != nullptr){
                    carrinho.adicionar_pedido(produto, quantidade);
                }
                break;
            }
            case 'r':{
                carrinho.imprimir_resumo();
                break;
            }
            case 'b':{
                avaliacao_basica();
                break;
            }
        }
    }

    return 0;
}