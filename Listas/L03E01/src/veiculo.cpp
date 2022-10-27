#include "veiculo.hpp"

int Veiculo::_next_id=1;

// Construtor & Destrutor
Veiculo::Veiculo(std::string subtipo, int velocidade, int passageiros){
    _subtipo = subtipo;
    _velo_max = velocidade;
    _n_passageiros = passageiros;
    _id = _next_id;
    _next_id++;
}

Veiculo::~Veiculo(){
    std::cout<<"Destrutor Veiculo"<<std::endl;
}

// Getters
int Veiculo::get_id(){
    return _id;
}

// Metodos
void Veiculo::print_info(){
    std::cout<<"Info: Veiculo "<<_id<<"\n";
    std::cout<<"Preco estimado: RS "<< estima_preco() << ",00"<<"\n";
    std::cout<<"\t"<<"Subtipo: "<<_subtipo<<"\n";
    std::cout<<"\t"<<"Velocidade maxima: "<<_velo_max<<" km/h"<<"\n";
    std::cout<<"\t"<<"Capacidade de passageiros: "<<_n_passageiros<<"\n";
}