#include "RegistroAvaliacoes.hpp"
#include "Usuario.hpp"
#include "Review.hpp"
#include "Filme.hpp"
#include <string>
#include <iostream>
#include <vector>

RegistroAvaliacoes::RegistroAvaliacoes() {
    _usuarios = std::vector < Usuario * > ();
    _filmes = std::vector < Filme * > ();
}

RegistroAvaliacoes::~RegistroAvaliacoes() {
    for (int i = 0; i < _usuarios.size(); i++) {
        delete _usuarios[i];
    }
    for (int i = 0; i < _filmes.size(); i++) {
        delete _filmes[i];
    }
}

void RegistroAvaliacoes::adicionar_usuario(std::string login, std::string nome) {
    Usuario * usuario = new Usuario(login, nome);
    _usuarios.push_back(usuario);
}

void RegistroAvaliacoes::adicionar_filme(std::string nome, std::string genero, int duracao) {
    Filme * filme = new Filme(_filmes.size(), nome, genero, duracao);
    _filmes.push_back(filme);
}

void RegistroAvaliacoes::adicionar_review(int id_filme, std::string login_usuario,
    std::string comentario, float nota) {

    Usuario * usuario = NULL;
    for (int i = 0; i < _usuarios.size(); i++) {
        if (_usuarios[i]->get_login() == login_usuario) {
            usuario = _usuarios[i];
        }
    }
    if (usuario == NULL) {
        std::cout << "Usuario " << login_usuario << " não encontrado!" << std::endl;
        return ;
    }
    if (id_filme >= _filmes.size()) {
        std::cout << "Filme " << id_filme << " não encontrado!" << std::endl;
        return ;
    }
    Review * review = _filmes[id_filme]->adicionar_review(comentario, nota);
    usuario->associar_review(review);
}

void RegistroAvaliacoes::imprimir_estatisticas_usuarios(){
    for(int i=0; i<_usuarios.size(); i++){
        _usuarios[i]->imprimir_info();
    }
}

void RegistroAvaliacoes::imprimir_registro_geral(){
    for(int i = 0; i < _filmes.size(); i++) {
        _filmes[i]->imprimir_nota_consolidada();
    }
}

void RegistroAvaliacoes::imprimir_reviews_usuario(std::string login){
    for(int i = 0; i < _usuarios.size(); i++) {
        if(_usuarios[i]->get_login() == login) {
            _usuarios[i]->imprimir_reviews();
        }
    }
}
