#include "Robo.hpp"
#include "Ponto2D.hpp"
#include <cmath>
#include <iostream>

Robo::Robo(int id, Ponto2D posicao, bool com_bola){
    _id = id;
    _posicao = posicao;
    _com_bola = com_bola;
}

void Robo::mover(double v, double th, double t) {
    _posicao._x += ((v*cos(th))*t);
    _posicao._y += ((v*sin(th))*t);
    _energia -= v*t;
}

double Robo::calcular_distancia(Robo *robo) {
    return _posicao.calcular_distancia(robo->_posicao);
}

Robo* Robo::determinar_robo_mais_proximo(Robo **time, int num_robos) {
    int id_near = 0;
    if(_id == 0) id_near = 1;
    double menor_distancia = calcular_distancia(time[0]);
    for (int i = 0; i < num_robos; i++) {
        double distancia = calcular_distancia(time[i]);
        if (i!=_id && distancia < menor_distancia) {
            menor_distancia = distancia;
            id_near = i;
        }
    }
    return time[id_near];
}

void Robo::passar_bola(Robo **time, int num_robos) {
    if (_com_bola) {        
        Robo *robo = determinar_robo_mais_proximo(time, num_robos);
        robo->_com_bola = true;
        _com_bola = false;
    }else{
        std::cout << "Estou sem a bola!" << std::endl;
    }
}

void Robo::imprimir_status() {
    std::cout << _id << "\t" << _posicao._x << "\t" << _posicao._y << "\t" << _com_bola << "\t" << _energia << std::endl;
}