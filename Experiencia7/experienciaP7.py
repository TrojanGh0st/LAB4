class Animal:
    def __init__(self, nombre):
        self.nombre = nombre
    
    def hacer_sonido(self):
        print("Haciendo sonido genérico")

    def __del__(self):
        print("Destructor de Animal")

class Perro(Animal):
    def __init__(self, nombre, raza):
        super().__init__(nombre)
        self.raza = raza
    
    def ladrar(self):
        print("¡Guau!")

    def __del__(self):
        print("Destructor de Perro")
        super().__del__()

# Crear un objeto de la clase derivada
mi_perro = Perro("Fido", "Labrador")

# Acceder a atributos y métodos heredados de la clase base
print(mi_perro.nombre)
mi_perro.hacer_sonido()

# Acceder a atributos y métodos propios de la clase derivada
print(mi_perro.raza)
mi_perro.ladrar()

# Modificar atributos propios de la clase derivada
mi_perro.raza = "Golden Retriever"

# Eliminar métodos propios de la clase derivada
del mi_perro.raza

# El objeto se eliminará al salir del ámbito
