#include "Filme.hpp"
#include "Usuario.hpp"
#include "Review.hpp"
#include <string>
#include <iostream>

Filme::Filme(int id, std::string nome, std::string genero, int duracao) {
    _id = id;
    _nome = nome;
    _genero = genero;
    _duracao = duracao;
}

Filme::~Filme() {
    for (int i = 0; i < _reviews.size(); i++) {
        delete _reviews[i];
    }
}

Review * Filme::adicionar_review(std::string comentario, double nota) {
    Review * review = new Review(this, comentario, nota);
    _reviews.push_back(review);
    return review;
}

void Filme::imprimir_nota_consolidada() {
    double soma = 0;
    for (int i = 0; i < _reviews.size(); i++) {
        soma += _reviews[i]->get_nota();
    }
    std::cout << _nome << "\t" << "Reviews:" << "\t" << _reviews.size() << "\t" << 
                "Nota media:" << "\t" << soma/_reviews.size() << std::endl;
}

std::string Filme::get_nome() {
    return _nome;
}
