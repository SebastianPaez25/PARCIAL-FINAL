from datos import obtener_datos_vehiculo
from parqueadero import Parqueadero

if __name__ == "__main__":
    while True:
        datos = obtener_datos_vehiculo()
        if datos:
            parqueadero = Parqueadero(*datos)
            parqueadero.iniciar()
        else:
            break