#include "utilidades.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int elegirDificultad() {
    cout << "Elige dificultad:\n1. Fácil (150 vida)\n2. Normal (100 vida)\n3. Difícil (70 vida)\nOpción: ";
    int op;
    cin >> op;
    switch(op) {
        case 1: return 150;
        case 3: return 70;
        default: return 100;
    }
}

Pokemon elegirPokemon(const vector<Pokemon>& pokemones, const string& mensaje) {
    cout << mensaje << endl;
    for (size_t i = 0; i < pokemones.size(); ++i)
        cout << i+1 << ". " << pokemones[i].nombre << endl;
    int op;
    cin >> op;
    while (op < 1 || op > (int)pokemones.size()) {
        cout << "Opción inválida. Intenta de nuevo: ";
        cin >> op;
    }
    return pokemones[op-1];
}

Pokemon elegirRival(const vector<Pokemon>& pokemones, const Pokemon& jugador) {
    // Elige un rival aleatorio distinto al jugador
    int idx;
    do {
        idx = rand() % pokemones.size();
    } while (pokemones[idx].nombre == jugador.nombre);
    return pokemones[idx];
}

void mostrarPokemon(const Pokemon& p) {
    cout << p.nombre << " (" << p.vida << "/" << p.vidaMaxima << " vida)\n";
    cout << p.arte << endl;
}