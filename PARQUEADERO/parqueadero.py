import os
import time
import msvcrt
from datetime import datetime
from utilidades import obtener_icono_vehiculo, calcular_tarifa

class Parqueadero:
    def __init__(self, placa, tipo_vehiculo):
        self.placa = placa
        self.tipo_vehiculo = tipo_vehiculo
        self.entrada = datetime.now()
        self.filas = 9
        self.columnas = 9
        self.mapa = []
        self.icono = obtener_icono_vehiculo(tipo_vehiculo)
        self.pos = [8, 4]  # Entrada
        self.vehiculos_parqueados = set()
        self.generar_mapa()

    def generar_mapa(self):
        self.mapa = [["⬜" for _ in range(self.columnas)] for _ in range(self.filas)]

        # Camino central
        for i in range(self.filas):
            self.mapa[i][4] = "⬛"

        # Espacios de parqueo laterales
        for i in range(1, self.filas - 1):
            if i % 2 == 1:
                self.mapa[i][2] = "🅿️"
                self.mapa[i][6] = "🅿️"

        # Entrada y salida
        self.mapa[8][4] = "⬅️"
        self.mapa[0][4] = "➡️"

        self.mapa[self.pos[0]][self.pos[1]] = self.icono

    def mostrar_mapa(self):
        os.system("cls" if os.name == "nt" else "clear")
        for fila in self.mapa:
            print(" ".join(fila))
        print("\nUse W A S D para moverse. ENTER para interactuar. Q para salir.")

    def mover_vehiculo(self, dx, dy):
        nueva_x = self.pos[0] + dx
        nueva_y = self.pos[1] + dy

        if 0 <= nueva_x < self.filas and 0 <= nueva_y < self.columnas:
            if self.mapa[nueva_x][nueva_y] in ["⬛", "⬜", "🅿️", "⬅️", "➡️"]:
                self.mapa[self.pos[0]][self.pos[1]] = "⬛" if self.pos[1] == 4 else "⬜"
                self.pos = [nueva_x, nueva_y]
                self.mapa[nueva_x][nueva_y] = self.icono

    def leer_tecla(self):
        tecla = msvcrt.getch()
        if tecla in [b'w', b'W']:
            self.mover_vehiculo(-1, 0)
        elif tecla in [b's', b'S']:
            self.mover_vehiculo(1, 0)
        elif tecla in [b'a', b'A']:
            self.mover_vehiculo(0, -1)
        elif tecla in [b'd', b'D']:
            self.mover_vehiculo(0, 1)
        elif tecla == b'\r':
            return self.ejecutar_accion()
        elif tecla in [b'q', b'Q']:
            return False
        return True

    def ejecutar_accion(self):
        x, y = self.pos
        if self.mapa[x][y] == "⬅️":
            print("\nVehículo ingresando...")
            time.sleep(1)
        elif self.mapa[x][y] == "➡️":
            print("\nVehículo saliendo...")
            time.sleep(1)
            self.finalizar()
            input("Presione Enter para continuar...")
            return False
        elif self.mapa[x][y] == self.icono:
            print("\nSeleccione lugar de parqueo (I: izquierda / D: derecha):")
            opcion = msvcrt.getch().lower()
            if opcion == b'i' and y > 0 and self.mapa[x][y-2] == "🅿️":
                self.mapa[x][y] = "⬛"
                self.pos[1] -= 2
                self.mapa[x][y-2] = self.icono
                self.vehiculos_parqueados.add((x, y-2))
            elif opcion == b'd' and y < self.columnas-2 and self.mapa[x][y+2] == "🅿️":
                self.mapa[x][y] = "⬛"
                self.pos[1] += 2
                self.mapa[x][y+2] = self.icono
                self.vehiculos_parqueados.add((x, y+2))
        return True

    def iniciar(self):
        continuar = True
        while continuar:
            self.mostrar_mapa()
            continuar = self.leer_tecla()

    def finalizar(self):
        salida = datetime.now()
        duracion = (salida - self.entrada).seconds // 60 + 1
        tarifa = calcular_tarifa(self.tipo_vehiculo, duracion)
        print(f"\nPlaca: {self.placa}")
        print(f"Tipo: {self.tipo_vehiculo}")
        print(f"Hora de entrada: {self.entrada.strftime('%H:%M:%S')}")
        print(f"Hora de salida: {salida.strftime('%H:%M:%S')}")
        print(f"Duración: {duracion} minutos")
        print(f"Valor a pagar: ${tarifa}")

