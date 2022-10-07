// NÃO ALTERE ESSA LINHA
#include "avaliacao_basica_cinereview.hpp"
#include "RegistroAvaliacoes.hpp"
#include <iostream>
#include <string>

int main() {
    RegistroAvaliacoes registro;
    char data;
    while(std::cin>>data){
        switch (data){
            case 'u':{
                std::string login, nome;
                std::cin>>login>>nome;
                registro.adicionar_usuario(login, nome);
                break;
            }
            case 'f':{
                std::string nome, genero;
                int duracao;
                std::cin>>nome>>genero>>duracao;
                registro.adicionar_filme(nome, genero, duracao);
                break;
            }
            case 'r':{
                int id_filme;
                std::string login_usuario, comentario;
                float nota;
                std::cin>>id_filme>>login_usuario>>comentario>>nota;
                registro.adicionar_review(id_filme-1, login_usuario, comentario, nota);
                break;
            }
            case 'p':{
                registro.imprimir_registro_geral();
                break;
            }
            case 's':{
                registro.imprimir_estatisticas_usuarios();
                break;
            }
            case 'l':{
                std::string login;
                std::cin>>login;
                registro.imprimir_reviews_usuario(login);
                break;
            }
            case 'b':{
                avaliacao_basica();
                break;
            }
        }
    }

    return 0;
}