#include "aquario.hpp"

Aquario::Aquario(const Aquario &orig){
    for(auto &c: orig._criaturas){
        if(c->get_subtipo() == "Peixe"){
            _criaturas.push_back(shared_ptr<Criatura>(new Peixe(*dynamic_pointer_cast<Peixe>(c))));
        }else if(c->get_subtipo() == "Polvo"){
            _criaturas.push_back(shared_ptr<Criatura>(new Polvo(*dynamic_pointer_cast<Polvo>(c))));
        }
    }
}

void Aquario::add_peixe(double peso, char sexo){
    _criaturas.push_back(make_shared<Peixe>(peso, sexo));
}

void Aquario::add_polvo(double qi){
    _criaturas.push_back(make_shared<Polvo>(qi));
}

void Aquario::acasalamento(int id1, int id2){
    if(id1 < 0 || id1 >= _criaturas.size() || id2 < 0 || id2 >= _criaturas.size()){
        return;
    }
    list<unique_ptr<Criatura>> crias = _criaturas[id1]->acasalar(_criaturas[id2]);
    for(auto &c: crias){
        _criaturas.push_back(move(c));
    }
}

void Aquario::print(){
    std::cout<<"============="<<std::endl << "Aquario Info:" << std::endl;
    for(int i = 0; i < _criaturas.size(); i++){
        _criaturas[i]->print_info();
    }
    std::cout<<"============="<<std::endl;
}