#include "RegistroAvaliacoes.hpp"
#include "Usuario.hpp"
#include "Review.hpp"
#include "Filme.hpp"
#include <string>
#include <iostream>
#include <vector>


RegistroAvaliacoes::RegistroAvaliacoes() {
    _usuarios = std::map < std::string , Usuario * > ();
    _filmes = std::vector < Filme * > ();
}

RegistroAvaliacoes::~RegistroAvaliacoes() {
    std::map < std::string , Usuario * > ::iterator it;
    for (it = _usuarios.begin(); it != _usuarios.end(); it++) {
        it->second->~Usuario();
    }
    for (int i = _filmes.size()-1; i >= 0; i--) {
        _filmes[i]->~Filme();
    }
}

void RegistroAvaliacoes::adicionar_usuario(std::string login, std::string nome) {
    Usuario * usuario = new Usuario(login, nome);
    _usuarios.insert(std::pair < std::string , Usuario * > (login, usuario));
}

void RegistroAvaliacoes::adicionar_filme(std::string nome, std::string genero, int duracao) {
    Filme * filme = new Filme(_filmes.size()+1, nome, genero, duracao);
    _filmes.push_back(filme);
}

void RegistroAvaliacoes::adicionar_review(int id_filme, std::string login_usuario,
    std::string comentario, float nota) {

    Usuario * usuario = NULL;
    std::map < std::string , Usuario * > ::iterator it;
    for (it = _usuarios.begin(); it != _usuarios.end(); it++) {
        if (it->first == login_usuario) {
            usuario = it->second;
        }
    }
    if (usuario == NULL) {
        std::cout << "Usuario " << login_usuario << " não encontrado!" << std::endl;
        return ;
    }
    if (id_filme > _filmes.size()) {
        std::cout << "Filme " << id_filme << " não encontrado!" << std::endl;
        return ;
    }
    Review * review = _filmes[id_filme-1]->adicionar_review(comentario, nota);
    usuario->associar_review(review);
}

void RegistroAvaliacoes::imprimir_estatisticas_usuarios(){
    std::map < std::string , Usuario * > ::iterator it;
    for (it = _usuarios.begin(); it != _usuarios.end(); it++) {
        it->second->imprimir_info();
    }
}

void RegistroAvaliacoes::imprimir_registro_geral(){
    for(int i = 0; i < _filmes.size(); i++) {
        _filmes[i]->imprimir_nota_consolidada();
    }
}

void RegistroAvaliacoes::imprimir_reviews_usuario(std::string login){
    std::map < std::string , Usuario * > ::iterator it;
    for (it = _usuarios.begin(); it != _usuarios.end(); it++) {
        if (it->first == login) {
            it->second->imprimir_reviews();
        }
    }
}
