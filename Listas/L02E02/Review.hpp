#ifndef REVIEW_H
#define REVIEW_H

#include <string>

class Filme;

class  Review {
 private :
        Filme * _filme;
        std::string  _comentario;
        float  _nota;

 public :
        Review(Filme * filme, std::string  comentario, float nota=0.0);
        ~ Review();
        void imprimir_review();
        float get_nota();
};

#endif