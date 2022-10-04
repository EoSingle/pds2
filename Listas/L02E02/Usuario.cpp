#include "Usuario.hpp"
#include "Review.hpp"
#include <string>
#include <iostream>

Usuario::Usuario(std::string login, std::string nome) {
    _login = login;
    _nome = nome;
}

Usuario::~Usuario() {
    for (int i = 0; i < _reviews.size(); i++) {
        delete _reviews[i];
    }
}

void Usuario::associar_review(Review *review) {
    _reviews.push_back(review);
}

void Usuario::imprimir_info() {
    std::cout << _nome << "\t" << "Reviews:" << "\t" << _reviews.size() << std::endl;
}

void Usuario::imprimir_reviews() {
    if(_reviews.size() == 0) {
        std::cout << "Usuario " << _nome << " não possui reviews!" << std::endl;
    } else {
        imprimir_info();
        for (int i = 0; i < _reviews.size(); i++) {
            _reviews[i]->imprimir_review();
        }
    }
}

std::string Usuario::get_login() {
    return _login;
}