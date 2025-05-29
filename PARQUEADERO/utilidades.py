def obtener_icono_vehiculo(tipo):
    if tipo.lower() == "carro":
        return "🚗"
    elif tipo.lower() == "moto":
        return "🏍️"
    elif tipo.lower() == "camioneta":
        return "🚙"
    else:
        return "🚘"

def calcular_tarifa(tipo, minutos):
    tarifas = {
        "carro": 1000,
        "moto": 500,
        "camioneta": 1500
    }
    tarifa_base = tarifas.get(tipo.lower(), 1000)
    return tarifa_base * ((minutos // 60) + 1)
