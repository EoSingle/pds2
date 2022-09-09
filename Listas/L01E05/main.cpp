#include "Musica.hpp"
#include "Playlist.hpp"
#include <iostream>

int main(){
    /*Musica m1(1, "A", "B", "C", 1.5, true);
    m1.imprimir_dados();
    Musica m2(2, "D", "E", "F", 2.5, false);
    m2.imprimir_dados();*/

    Playlist p;
    p.adicionar_musica("Master Of Puppets", "Metallica", "Master Of Pupets", 6.0, true);
    p.adicionar_musica("Slaughterhouse", "Motionless in the White", "Scoring the end of the world", 4.5, false);

    p.imprimir();
    p.remover_musica(1); // problema provavelmente está no id
    p.imprimir();
    p.remover_musica(2);

    return 0;
}