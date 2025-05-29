#include <iostream>
#include "pokemon.h"
#include "utilidades.h"
#include "combate.h"
#include <ctime>

using namespace std;

int main() {
    vector<Pokemon> pokemones = {
        {"Pikachu", "  (o^.^o)\n  (   Y   )\n", {{"Impactrueno", 20}, {"Rayo", 30}, {"Electrobola", 35}}},
        {"Charmander", "  (^-^ )\n  (  ^  )\n   \\_/_/\n", {{"Arañazo", 15}, {"Lanzallamas", 25}, {"Ascuas", 20}}},
        {"Bulbasaur", "  (^-^ )\n <(  ^  )>\n   (___)\n", {{"Látigo cepa", 20}, {"Drenadoras", 15}, {"Rayo solar", 35}}},
        {"Squirtle", "  (O_O )\n  (  o  )\n  /|___|\\\n", {{"Burbuja", 20}, {"Pistola agua", 25}, {"Hidrobomba", 35}}},
        {"Eevee", "  ( *w* )\n  ( U U )\n", {{"Placaje", 15}, {"Mordisco", 20}, {"Ataque rápido", 25}}}
    };

    char jugarOtraVez;
    do {
        cout << "\n===== COMBATE POKÉMON =====\n";

        int vidaBase = elegirDificultad();

        Pokemon jugador = elegirPokemon(pokemones, "\nElige tu Pokémon:");
        jugador.vida = jugador.vidaMaxima = vidaBase;

        Pokemon rival = elegirRival(pokemones, jugador);
        rival.vida = rival.vidaMaxima = vidaBase;

        cout << "\n¡Combate entre " << jugador.nombre << " y " << rival.nombre << "!\n";

        bool turnoJugador = true;
        while (true) {
            cout << "\n======= ESTADO =======\n";
            mostrarPokemon(jugador);
            mostrarPokemon(rival);

            if (turnoJugador) {
                realizarAtaque(jugador, rival);
            } else {
                Ataque atq = rival.ataques[(time(0) + rival.vida) % rival.ataques.size()];
                cout << rival.nombre << " usa " << atq.nombre << "! Causa " << atq.danio << " de daño.\n";
                jugador.vida -= atq.danio;
                if (jugador.vida < 0) jugador.vida = 0;
            }

            if (comprobarVictoria(jugador, rival)) break;
            turnoJugador = !turnoJugador;
        }

        cout << "\n¿Deseas jugar otra vez? (s/n): ";
        cin >> jugarOtraVez;
        while (jugarOtraVez != 's' && jugarOtraVez != 'n') {
            cout << "Por favor, escribe 's' para sí o 'n' para no: ";
            cin >> jugarOtraVez;
        }
    } while (jugarOtraVez == 's');

    cout << "\nGracias por jugar. ¡Hasta la próxima!\n";
    return 0;
}