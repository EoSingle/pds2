#include "Musica.hpp"
#include "Playlist.hpp"
#include "avaliacao_basica_playlist.hpp"
#include <iostream>
#include <string>

int main() {
    Playlist playlist;
    char data;
    while(cin>>data){
        switch (data){
            case 'a':{
                string nome, artista, album;
                float duracao;
                cin>>nome>>artista>>album>>duracao;
                playlist.adicionar_musica(nome, artista, album, duracao);
                break;
            }
            case 's':{
                string nome, artista;
                cin>>nome>>artista;
                Musica* musica = playlist.buscar_musica(nome, artista);
                if(musica != nullptr){
                    musica->imprimir_dados();
                }else{
                    cout<<"Musica nao encontrada"<<endl;
                }
                break;
            }
            case 'r':{
                string nome, artista;
                cin>>nome>>artista;
                playlist.remover_musica(playlist.buscar_musica(nome, artista)->_id);
                break;
            }
            case 'f':{
                string nome, artista;
                cin>>nome>>artista;
                playlist.favoritar_musica(playlist.buscar_musica(nome, artista)->_id);
                break;
            }
            case 'd':{
                string nome, artista;
                cin>>nome>>artista;
                playlist.desfavoritar_musica(playlist.buscar_musica(nome, artista)->_id);
                break;
            }
            case 'p':{
                playlist.imprimir();
                break;
            }
            case 'b':{
                avaliacao_basica();
                break;
            }
        }
    }

    return 0;
}