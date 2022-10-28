#include "criatura.hpp"

Criatura::Criatura(string subtipo){
    std::cout<<"Criatura:"<< subtipo <<std::endl;
    _subtipo = subtipo;
}

Criatura::~Criatura(){
    std::cout<<"~Criatura:"<< _subtipo << std::endl;
}

string Criatura::get_subtipo(){
    return _subtipo;
}

void Criatura::print_info(){
    std::cout<<"Info: "<< _subtipo <<std::endl;
}