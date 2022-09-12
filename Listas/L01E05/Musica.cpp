#include "Musica.hpp"
#include <iostream>
#include <string>
#include <iomanip>

Musica::Musica(int id, std::string nome, std::string artista, std::string album, float duracao, bool favorita){
    _id = id;
    _nome = nome;
    _artista = artista;
    _album = album;
    _duracao = duracao;
    _favorita = favorita;
}

void Musica::normalize(float duracao){
    int segundos = duracao*60;
    int minutos = segundos/60;
    segundos = segundos%60;

    std::cout << std::setfill('0') << std::setw(2);
    std::cout << minutos << ":";
    std::cout << std::setfill('0') << std::setw(2);
    std::cout << segundos;
}

void Musica::imprimir_dados(){
    std::cout << _id << "\t" << _album << "\t" << _artista << "\t" << _nome << "\t";
    normalize(_duracao);
    std:: cout << "\t" << _favorita << std::endl;   
}