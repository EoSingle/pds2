#ifndef PLAYLIST_H
#define PLAYLIST_H
#include <string>
#include "Musica.hpp"

struct Fila{
    int _id;
    Musica _musica;
    Fila* _next;
    Fila* _previous;


};

struct Playlist{
    Fila* _head;
    Fila* _tail;

    Playlist(Fila* _head=nullptr, Fila* _tail=nullptr);
    void adicionar_musica(std::string nome, std::string artista, std::string album, float duracao, bool favorita=false);
    Musica* buscar_musica(std::string nome, std::string artista);
    void remover_musica(int id);
    void favoritar_musica(int id);
    void desfavoritar_musica(int id);
    void imprimir();
    void tempo_total(float duracao);
};

#endif