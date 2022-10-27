#include "veiculo.hpp"
#include "caminhao.hpp"
#include "caminhao_autonomo.hpp"

#include <list>
#include <iostream>
#include <string>

std::list<Veiculo*> veiculos;

// Imprime a lista de veiculos
void print_list(std::list<Veiculo*> l){
    for (auto it = l.begin(); it != l.end(); it++){
        (*it)->print_info();
    }
}

// Remove um veiculo da lista
void rm_id(std::list<Veiculo*> &l, int id){
    for (auto it = l.begin(); it != l.end(); it++){
        if ((*it)->get_id() == id){
            l.remove(*it);
            delete(*it);
            return;
        }
    }
}

int main(){
    std::string data;
    while(std::cin>>data){
        if(data=="add_c"){
            int velocidade, passageiros, carga;
            std::cin>>velocidade>>passageiros>>carga;
            veiculos.push_back(new Caminhao(velocidade, passageiros, carga));
        }
        else if(data=="add_ca"){
            int velocidade, passageiros, carga;
            std::string fabricante;
            std::cin>>velocidade>>passageiros>>carga>>fabricante;
            veiculos.push_back(new CaminhaoAutonomo(velocidade, passageiros, carga, fabricante));
        }
        else if(data=="rm"){
            int id;
            std::cin>>id;
            rm_id(veiculos, id);

        }
        else if(data=="print"){
            print_list(veiculos);
        }
    }

    return 0;
}