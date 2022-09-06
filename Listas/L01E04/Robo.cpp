#include "Robo.hpp"
#include "Ponto2D.hpp"
#include <cmath>

Robo::Robo(int id, Ponto2D posicao, bool com_bola) {
    _id = id;
    _posicao = posicao;
    _com_bola = com_bola;
}

Robo::mover(double v, double th, double t) {
    _posicao._x += v*cos(th)*t;
    _posicao._y += v*sin(th)*t;
    _energia -= v*t;
}

Robo::calcular_distancia(Robo *robo) {
    return _posicao.calcular_distancia(robo->_posicao);
}

Robo::determinar_robo_mais_proximo(Robo **time, int num_robos) {
    int id_near = 0;
    double menor_distancia = calcular_distancia(time[0]);
    for (int i = 1; i < num_robos; i++) {
        double distancia = calcular_distancia(time[i]);
        if (distancia < menor_distancia) {
            menor_distancia = distancia;
            id_near=i;
        }
    }
    return id_near;
}

Robo::passar_bola(Robo **time, int num_robos) {
    if (_com_bola) {        
        Robo *robo = determinar_robo_mais_proximo(time, num_robos);
        robo->_com_bola = true;
        _com_bola = false;
    }else{
        cout << "Estou sem a bola!" << endl;
    }
}

Robo::imprimir_status() {
    std::cout << "Robo " << _id << "\t" << _posicao._x << "\t" << _posicao._y << "\t" << _com_bola << "\t" << _energia << std::endl;
}