#include "Playlist.hpp"
#include <iostream>

void Playlist::adicionar_musica(std::string nome, std::string artista, std::string album, float duracao, bool favorita){
    Fila* aux = new Fila;
    aux->_musica._nome = nome;
    aux->_musica._artista = artista;
    aux->_musica._album = album;
    aux->_musica._duracao = duracao;
    aux->_musica._favorita = favorita;
    aux->_next = nullptr;

    if(_head == nullptr){
        _head = aux;
        _tail = aux;
        aux->_id = 1;
    }else{
        _tail->_next = aux;
        _tail = aux;
        aux->_id = _tail->_id + 1;
    }
}

void Playlist::remover_musica(int id){
    Fila* current = _head;
    Fila* previous = nullptr;

    while(current != nullptr){
        if(current->_musica._id == id){
            if(previous == nullptr){
                _head = current->_next;
            }else if(current->_next == nullptr){
                previous->_next=nullptr;
                _tail=previous;
            }else{
                previous->_next = current->_next;
            }
            delete current;
            return;    
        }

        previous = current;
        current = current->_next;
    }
        
}


void Playlist::imprimir(){
    Fila* aux = _head;
    while(aux != nullptr){
        aux->_musica.imprimir_dados();
        aux = aux->_next;
    }
}

