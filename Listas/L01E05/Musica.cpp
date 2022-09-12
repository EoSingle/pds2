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
    int minutos = (int)duracao;
    int segundos = (int)((duracao - minutos) * 60);
    std::cout << std::setfill('0') << std::setw(2);
    if(segundos == 0){
        std::cout << minutos << ":00";
    }else{
        std::cout << minutos << ":" << segundos;
    }
}

void Musica::imprimir_dados(){
    std::cout << _id << "\t" << _album << "\t" << _artista << "\t" << _nome << "\t";
    normalize(_duracao);
    std:: cout << "\t" << _favorita << std::endl;   
}