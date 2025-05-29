def obtener_tiempo_y_costo(segundos):
    horas = segundos / 3600
    tarifa_por_hora = 3000  # Puedes modificarla
    costo = tarifa_por_hora * horas
    return horas, costo
