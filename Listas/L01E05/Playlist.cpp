#include "Playlist.hpp"
#include <iostream>
#include <iomanip>

Playlist::Playlist(Fila* head, Fila* tail){
    _head = head;
    _tail = tail;
}

void Playlist::adicionar_musica(std::string nome, std::string artista, std::string album, float duracao, bool favorita){
    Fila* aux = new Fila;
    aux->_musica._nome = nome;
    aux->_musica._artista = artista;
    aux->_musica._album = album;
    aux->_musica._duracao = duracao;
    aux->_musica._favorita = favorita;
    aux->_next = nullptr;
    aux->_previous = _tail;

    if(this->_head == nullptr){
        _head = aux;
        _tail = aux;
        aux->_id = 1;
        aux->_musica._id = aux->_id;
    }else{
        _tail->_next = aux;
        aux->_id = (this->_tail->_id + 1);
        aux->_musica._id = aux->_id;
        _tail = aux;

    }
}

Musica* Playlist::buscar_musica(std::string nome, std::string artista){
    Fila* aux = _head;
    while(aux != nullptr){
        if(aux->_musica._nome == nome && aux->_musica._artista == artista){
            return &aux->_musica;
        }
        aux = aux->_next;
    }
    return nullptr;
}

void Playlist::remover_musica(int id){
    Fila* current = _head;
    Fila* previous = nullptr;

    while(current != nullptr){
        if(current->_id == id){
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

void Playlist::favoritar_musica(int id){
    Fila* aux = _head;
    while(aux != nullptr){
        if(aux->_id == id){
            aux->_musica._favorita = true;
            if(aux->_previous!=nullptr){
                if(aux->_next!=nullptr){
                    aux->_next->_previous = aux->_previous;
                    aux->_previous->_next = aux->_next;
                } else {
                    aux->_previous->_next = nullptr;
                    _tail = aux->_previous;
                }
                aux->_next = _head;
                aux->_previous = nullptr;
                _head->_previous = aux;
                _head = aux;
            }
            return;
        }
        aux = aux->_next;
    }
}

void Playlist::desfavoritar_musica(int id){
    Fila* aux = _head;
    while(aux != nullptr){
        if(aux->_id == id){
            aux->_musica._favorita = false;
            if(aux->_next!=nullptr){
                if(aux->_previous!=nullptr){
                    aux->_next->_previous = aux->_previous;
                    aux->_previous->_next = aux->_next;
                    
                } else {
                    aux->_next->_previous = nullptr;
                    _head = aux->_next;
                }
                aux->_next = nullptr;
                aux->_previous = _tail;
                _tail->_next = aux;
                _tail = aux;
            }
            return;
        }
        aux = aux->_next;
    }
}

void Playlist::tempo_total(float duracao){
    int minutos = (int)duracao;
    int segundos = (int)((duracao - minutos) * 60);
    std::cout << std::setfill('0') << std::setw(2);
    if(segundos == 0){
        std::cout << "00:" << minutos << ":00";
    }else{
        std::cout << "00:" << minutos << ":" << segundos;
    }
}


void Playlist::imprimir(){
    Fila* aux = _head;
    float total = 0;
    while(aux != nullptr){
        aux->_musica.imprimir_dados();
        total += aux->_musica._duracao;
        aux = aux->_next;
    }
    std::cout << "Tempo total: ";
    tempo_total(total);
    std::cout << std::endl;
}

