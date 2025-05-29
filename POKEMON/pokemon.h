#pragma once
#include <string>
#include <vector>

struct Ataque {
    std::string nombre;
    int danio;
};

struct Pokemon {
    std::string nombre;
    std::string arte;
    std::vector<Ataque> ataques;
    int vida = 100;
    int vidaMaxima = 100;
};