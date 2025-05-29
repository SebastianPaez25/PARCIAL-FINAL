import tkinter as tk
from tkinter import ttk
import datetime

def obtener_datos_vehiculo():
    datos = {}

    def enviar():
        datos["placa"] = entrada_placa.get()
        datos["tipo"] = tipo_vehiculo.get()
        ventana.destroy()

    ventana = tk.Tk()
    ventana.title("Ingreso de Vehículo")
    ventana.geometry("320x300")

    hora_actual = datetime.datetime.now().strftime("%H:%M:%S")
    tk.Label(ventana, text=f"Hora actual: {hora_actual}").pack(pady=5)

    tarifas = "Tarifas:\nCarro 🚗: $1000\nMoto 🏍️: $500\nCamioneta 🚙: $1500"
    tk.Label(ventana, text=tarifas).pack(pady=5)

    tk.Label(ventana, text="Placa:").pack()
    entrada_placa = tk.Entry(ventana)
    entrada_placa.pack(pady=5)

    tk.Label(ventana, text="Tipo de vehículo:").pack()
    tipo_vehiculo = ttk.Combobox(ventana, values=["Carro", "Moto", "Camioneta"])
    tipo_vehiculo.pack(pady=5)

    tk.Button(ventana, text="Ingresar", command=enviar).pack(pady=10)
    ventana.mainloop()

    if datos:
        return datos["placa"], datos["tipo"]
    return None
