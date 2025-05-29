#pragma once
#include <vector>
#include <string>
#include "pokemon.h"

int elegirDificultad();
Pokemon elegirPokemon(const std::vector<Pokemon>& pokemones, const std::string& mensaje);
Pokemon elegirRival(const std::vector<Pokemon>& pokemones, const Pokemon& jugador);
void mostrarPokemon(const Pokemon& p);