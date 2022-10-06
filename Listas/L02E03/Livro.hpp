#ifndef LIVRO_H
#define LIVRO_H

#include "Produto.hpp"
#include <string>

class Livro : public Produto{
    private:
        std::string _titulo;
        std::string _autor;
        int _ano;

    public:
        Livro(int id, float valor, std::string titulo, std::string autor, int ano);
        std::string getTitulo();
        std::string getAutor();
        int getAno();
        void setTitulo(std::string titulo);
        void setAutor(std::string autor);
        void setAno(int ano);
        void imprimir_info();
};

#endif