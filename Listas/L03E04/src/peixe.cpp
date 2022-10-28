#include "peixe.hpp"

Peixe::Peixe(double peso, char sexo) : Criatura("Peixe"){
    std::cout<<"Peixe:"<< _subtipo <<std::endl;
    _peso = peso;
    _sexo = sexo;
}

Peixe::~Peixe(){
    std::cout<<"~Peixe:"<< _subtipo << std::endl;
}

double Peixe::get_peso(){
    return _peso;
}

char Peixe::get_sexo(){
    return _sexo;
}

void Peixe::print_info(){
    Criatura::print_info();
    std::cout<< "\t" <<"Peso: "<< _peso << " kg"<<std::endl;
    std::cout<< "\t" <<"Sexo: "<< _sexo <<std::endl;
}

list<unique_ptr<Criatura>> Peixe::acasalar(shared_ptr<Criatura> c){
    list<unique_ptr<Criatura>> crias;
    if(c->get_subtipo() == "Peixe"){
        shared_ptr<Peixe> p = dynamic_pointer_cast<Peixe>(c);
        if(p->get_sexo() != _sexo){
            
            crias.push_back(unique_ptr<Peixe>(new Peixe((_peso+p->get_peso())/2, 'F')));
            crias.push_back(unique_ptr<Peixe>(new Peixe((_peso+p->get_peso())/2, 'M')));
        }
    }
    return crias;
}