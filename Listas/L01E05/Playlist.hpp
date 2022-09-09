#ifndef PLAYLIST_H
#define PLAYLIST_H
#include <string>
#include "Musica.hpp"

struct Fila{
    int _id;
    Musica _musica;
    Fila* _next;
};

struct Playlist{
    Fila* _head = nullptr;
    Fila* _tail = nullptr;

    void adicionar_musica(std::string nome, std::string artista, std::string album, float duracao, bool favorita);
    void remover_musica(int id);
    void imprimir();
};

#endif