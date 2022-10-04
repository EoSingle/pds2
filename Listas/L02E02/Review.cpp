#include "Review.hpp"
#include "Filme.hpp"
#include <string.h>
#include <iostream>

Review::Review(Filme *filme, std::string comentario, float nota) {
    _filme = filme;
    _comentario = comentario;
    _nota = nota;
}

Review::~Review() {
    delete _filme;
}

void Review::imprimir_review() {
    std::cout << _filme->get_nome() << "\t" << _comentario << "\t" << _nota << std::endl;
}

float Review::get_nota() {
    return _nota;
}
