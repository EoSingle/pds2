#ifndef MUSICA_H
#define MUSICA_H
#include <string>

struct Musica{
    int _id;
    std::string _nome;
    std::string _artista;
    std::string _album;
    float _duracao;
    bool _favorita;

    Musica(int id=0, std::string nome="", std::string artista="", std::string album="", float duracao=0.0, bool favorita=false);
    void normalize(float duracao);
    void imprimir_dados();
};


#endif