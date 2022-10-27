#include "caminhao_autonomo.hpp"

// Construtor & Destrutor
CaminhaoAutonomo::CaminhaoAutonomo(int velo_max, int n_passageiros, int carga_max, std::string fabricante) : Caminhao("CaminhaoAutonomo",velo_max, n_passageiros, carga_max){
    _fabricante = fabricante;
}

CaminhaoAutonomo::~CaminhaoAutonomo(){
    std::cout<<"Destrutor CaminhaoAutonomo"<<std::endl;
}

// Metodos
int CaminhaoAutonomo::estima_preco(){
    if(_fabricante == "Tesla"){
        return 500000+(100*_carga_max)+(10*_velo_max);
    }
    else{
        return 400000+(100*_carga_max)+(10*_velo_max);
    }
}

void CaminhaoAutonomo::print_info(){
    Caminhao::print_info();
    std::cout<<"\t"<<"Fabricante: "<<_fabricante<<"\n";
}