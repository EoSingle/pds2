#include "polvo.hpp"

Polvo::Polvo(double qi): Criatura("Polvo"){
    std::cout<<"Polvo:"<< _subtipo <<std::endl;
    _qi = qi;
}

Polvo::~Polvo(){
    std::cout<<"~Polvo:"<< _subtipo << std::endl;
}

double Polvo::get_qi(){
    return _qi;
}

void Polvo::print_info(){
    Criatura::print_info();
    std::cout<< "\t" <<"QI: "<< _qi <<std::endl;
}

list<unique_ptr<Criatura>> Polvo::acasalar(shared_ptr<Criatura> c){
    list<unique_ptr<Criatura>> crias;
    if(c->get_subtipo() == "Polvo"){
        shared_ptr<Polvo> p = dynamic_pointer_cast<Polvo>(c);
        crias.push_back(unique_ptr<Polvo>(new Polvo((_qi+p->get_qi())/2)));
    }
    return crias;
}