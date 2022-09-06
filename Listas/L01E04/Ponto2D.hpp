#ifndef PONTO2D_H
#define PONTO2D_H

struct Ponto2D{
    double _x, _y;
    Ponto2D(double x=0, double y=0);
    double calcular_distancia(Ponto2D ponto);
};  

#endif