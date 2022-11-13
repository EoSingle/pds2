#include "doctest.h"
#include "DiarioClasse.hpp"

TEST_CASE("Teste 01 - Aprovacao simples") {
    DiarioClasse diario;
    bool aprovado = diario.determinarAprovacao(60, 0, 1);
    CHECK(aprovado);
}

TEST_CASE("Teste 02 - Reprovacao com nota especial") {
    DiarioClasse diario;
    bool aprovado = diario.determinarAprovacao(40, 59, 0.75);
    CHECK_FALSE(aprovado);
}

TEST_CASE("Teste 03 - Caso de borda 1"){
    DiarioClasse diario;
    bool aprovado = diario.determinarAprovacao(100, 0, 1);
    CHECK(aprovado);
}

TEST_CASE("Teste 04 - Caso de borda 2"){
    DiarioClasse diario;
    bool aprovado = diario.determinarAprovacao(0, 0, 1);
    CHECK_FALSE(aprovado);
}

TEST_CASE("Teste 05 - Nota Semestre Invalida 1"){
    DiarioClasse diario;
    CHECK_THROWS_AS(diario.determinarAprovacao(101, 0, 1), ExcecaoNotaSemestreInvalida);    
}

TEST_CASE("Teste 06 - Nota Semestre Invalida 2"){
    DiarioClasse diario;
    CHECK_THROWS_AS(diario.determinarAprovacao(-1, 0, 1), ExcecaoNotaSemestreInvalida);
}

TEST_CASE("Teste 07 - Frequencia Invalida 1"){
    DiarioClasse diario;
    CHECK_THROWS_AS(diario.determinarAprovacao(80, 0, 1.1), ExcecaoFrequenciaInvalida);
}

TEST_CASE("Teste 08 - Frequencia Invalida 2"){
    DiarioClasse diario;
    CHECK_THROWS_AS(diario.determinarAprovacao(80, 0, -0.1), ExcecaoFrequenciaInvalida);
}

TEST_CASE("Teste 09 - Nota Especial Invalida 1"){
    DiarioClasse diario;
    CHECK_THROWS_AS(diario.determinarAprovacao(45, 75, 0.5), ExcecaoNotaEspecialInvalida);
}

TEST_CASE("Teste 10 - Nota Especial Invalida 2"){
    DiarioClasse diario;
    CHECK_THROWS_AS(diario.determinarAprovacao(39, 70, 0.75), ExcecaoNotaEspecialInvalida);
}