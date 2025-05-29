#include "utilidades.h"
#include <iostream>
#include <ctime>

using namespace std;

void mostrarBarraDeVida(int vida, int vidaMax) {
    int total = 20;
    int llenos = (vida * total) / vidaMax;
    cout << "[";
    for (int i = 0; i < total; ++i)
        cout << (i < llenos ? "#" : "-");
    cout << "] " << vida << "/" << vidaMax << "\n";
}

void mostrarPokemon(const Pokemon& p) {
    cout << "\n" << p.nombre << "\n" << p.arte;
    mostrarBarraDeVida(p.vida, p.vidaMaxima);
}

void mostrarListaPokemon(const vector<Pokemon>& lista) {
    for (size_t i = 0; i < lista.size(); ++i) {
        cout << "\n" << i + 1 << ". " << lista[i].nombre << ":\n" << lista[i].arte << "\n";
    }
}

int pedirOpcion(int min, int max) {
    int opcion;
    cin >> opcion;
    while (opcion < min || opcion > max) {
        cout << "Opcion invalida. Intenta de nuevo: ";
        cin >> opcion;
    }
    return opcion;
}

Pokemon elegirPokemon(const vector<Pokemon>& lista, const string& mensaje) {
    cout << mensaje << "\n";
    mostrarListaPokemon(lista);
    cout << "Elige (1-" << lista.size() << "): ";
    return lista[pedirOpcion(1, lista.size()) - 1];
}

Pokemon elegirRival(const vector<Pokemon>& lista, const Pokemon& jugador) {
    cout << "\n1. Elegir rival\n2. Aleatorio\nOpcion: ";
    int opcion = pedirOpcion(1, 2);
    if (opcion == 1) {
        while (true) {
            cout << "Elige un rival distinto a tu Pokemon:\n";
            mostrarListaPokemon(lista);
            int idx = pedirOpcion(1, lista.size()) - 1;
            if (lista[idx].nombre != jugador.nombre)
                return lista[idx];
            cout << "Debe ser un Pokemon distinto. Intenta de nuevo.\n";
        }
    } else {
        vector<Pokemon> candidatos;
        for (const auto& p : lista)
            if (p.nombre != jugador.nombre)
                candidatos.push_back(p);
        size_t i = time(0) % candidatos.size();
        return candidatos[i];
    }
}

int elegirDificultad() {
    cout << "\nDificultad:\n1. Facil (150 HP)\n2. Normal (100 HP)\n3. Dificil (75 HP)\nOpcion: ";
    int opcion = pedirOpcion(1, 3);
    if (opcion == 1) return 150;
    if (opcion == 2) return 100;
    return 75;
}