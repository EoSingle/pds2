#ifndef REGISTROAVALIACOES_H
#define REGISTROAVALIACOES_H

#include "Usuario.hpp"
#include "Filme.hpp"
#include <vector>

class  RegistroAvaliacoes {
 private :
    std::vector < Usuario * >  _usuarios;
    std::vector < Filme * >  _filmes;

 public :
    RegistroAvaliacoes();
    ~ RegistroAvaliacoes();
    void  adicionar_usuario(std::string  login, std::string  nome);
    void  adicionar_filme(std::string  nome, std::string  genero, int  duracao);
    void  adicionar_review(int  id_filme, std::string  login_usuario, std::string comentario, float nota);
    void  imprimir_estatisticas_usuarios();
    void  imprimir_registro_geral();
    void  imprimir_reviews_usuario(std::string login);
};




#endif