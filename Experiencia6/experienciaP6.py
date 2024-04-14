class Motor:
    def __init__(self, modelo, caballos_de_fuerza):
        self.modelo = modelo
        self.caballos_de_fuerza = caballos_de_fuerza

    def encender(self):
        print(f"El motor {self.modelo} se enciende.")

    def apagar(self):
        print(f"El motor {self.modelo} se apaga.")


class Vehiculo:
    def __init__(self, tipo, marca, modelo, año, motor):
        self.tipo = tipo  # Tipo de vehículo (por ejemplo, "auto", "camión", "moto", etc.)
        self.marca = marca
        self.modelo = modelo
        self.año = año
        self.motor = motor  # Composición: Vehiculo tiene un Motor

    def encender(self):
        print(f"Iniciando el {self.año} {self.marca} {self.modelo} {self.tipo}...")
        self.motor.encender()

    def apagar(self):
        print(f"Deteniendo el {self.año} {self.marca} {self.modelo} {self.tipo}...")
        self.motor.apagar()


# Crear una instancia de Motor para un vehículo
motor = Motor("V8", 450)

# Crear una instancia de Vehiculo y asignarle el motor
mi_vehiculo = Vehiculo("auto", "Tesla", "Model S", 2023, motor)

# Iniciar el vehículo (se inicia también el motor)
mi_vehiculo.encender()  # Salida: Iniciando el 2023 Tesla Model S auto... \n El motor V8 se enciende.

# Detener el vehículo (se detiene también el motor)
mi_vehiculo.apagar()  # Salida: Deteniendo el 2023 Tesla Model S auto... \n El motor V8 se apaga.

