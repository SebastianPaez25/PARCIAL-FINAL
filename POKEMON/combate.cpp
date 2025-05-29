#include "combate.h"
#include <iostream>
using namespace std;

void realizarAtaque(Pokemon& atacante, Pokemon& defensor) {
    cout << "\nAtaques de " << atacante.nombre << ":\n";
    for (size_t i = 0; i < atacante.ataques.size(); ++i)
        cout << i + 1 << ". " << atacante.ataques[i].nombre
             << " (Dano: " << atacante.ataques[i].danio << ")\n";
    cout << "Elige ataque: ";
    int opcion;
    cin >> opcion;
    while (opcion < 1 || opcion > (int)atacante.ataques.size()) {
        cout << "Opcion invalida. Intenta de nuevo: ";
        cin >> opcion;
    }
    Ataque atq = atacante.ataques[opcion - 1];
    cout << atacante.nombre << " usa " << atq.nombre << "! Causa " << atq.danio << " de dano.\n";
    defensor.vida -= atq.danio;
    if (defensor.vida < 0) defensor.vida = 0;
}

bool comprobarVictoria(const Pokemon& a, const Pokemon& b) {
    if (a.vida <= 0) {
        cout << "\n" << b.nombre << " gana el combate!\n";
        return true;
    }
    if (b.vida <= 0) {
        cout << "\n" << a.nombre << " gana el combate!\n";
        return true;
    }
    return false;
}