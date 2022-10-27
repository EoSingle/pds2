#include "caminhao.hpp"

// Construtor & Destrutor
Caminhao::Caminhao(std::string subtipo, int velo_max, int n_passageiros, int carga_max) : Veiculo(subtipo, velo_max, n_passageiros){
    _carga_max = carga_max;
}

Caminhao::Caminhao(int velo_max, int n_passageiros, int carga_max) : Veiculo("Caminhao", velo_max, n_passageiros){
    _carga_max = carga_max;
}

Caminhao::~Caminhao(){
    std::cout<<"Destrutor Caminhao"<<std::endl;
}

// Metodos
int Caminhao::estima_preco(){
    return 50000+(100*_carga_max)+(10*_velo_max);
}

void Caminhao::print_info(){
    Veiculo::print_info();
    std::cout<<"\t"<<"Carga maxima: "<<_carga_max<<" kg"<<"\n";
}