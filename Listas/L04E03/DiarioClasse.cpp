#include "DiarioClasse.hpp"

bool DiarioClasse::determinarAprovacao(double notaSemestre, double notaEspecial, double frequencia) {

    if (notaSemestre < 0 || notaSemestre > 100) {
        throw ExcecaoNotaSemestreInvalida();

    } else if (frequencia < 0 || frequencia > 1) {
        throw ExcecaoFrequenciaInvalida();

    } else if (notaEspecial < 0 || notaEspecial > 100) {
        throw ExcecaoNotaEspecialInvalida();
    
    } else if (notaSemestre >= 60 && frequencia >= 0.75) {
        return true;

    } else if (notaSemestre >= 40 && notaEspecial >= 60 && frequencia >= 0.75) {
        return true;

    } else if ((notaSemestre < 40 && notaEspecial > 0) || (notaEspecial > 0 && frequencia < 0.75)){
        throw ExcecaoNotaEspecialInvalida();
    
    } else {
        return false;
    }

}