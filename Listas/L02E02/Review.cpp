#include "Review.hpp"
#include "Filme.hpp"
#include <string.h>
#include <iostream>
#include <iomanip>

Review::Review(Filme *filme, std::string comentario, float nota) {
    _filme = filme;
    _comentario = comentario;
    _nota = nota;
}

Review::~Review() {}

void Review::imprimir_review() {
    std::cout<<std::fixed;
    std::cout << _filme->get_nome() << "\t" << _comentario << "\t" <<
     std::setprecision(1) << _nota << std::endl;
}

float Review::get_nota() {
    return _nota;
}
