#ifndef ROBO_H
#define ROBO_H

#include "Ponto2D.hpp"

struct Robo{
    int _id;
    Ponto2D _posicao;
    double _energia=100;
    bool _com_bola;


    Robo(int id=0, Ponto2D posicao=Ponto2D(), bool com_bola=false);

    void mover(double v, double th, double t);

    double calcular_distancia(Robo *robo);

    Robo* determinar_robo_mais_proximo(Robo** naves, int n);

    void passar_bola(Robo **time, int num_robos);

    void imprimir_status();

};

#endif