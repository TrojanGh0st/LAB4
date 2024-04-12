class Hijo:
    def __init__(self, nombre=""):
        self.nombre = nombre  # Inicializa el nombre del hijo

    def getNombre(self):
        return self.nombre  # Devuelve el nombre del hijo

    def setNombre(self, nombre):
        self.nombre = nombre  # Establece el nombre del hijo

class Padre:
    maxHijos = 5  # Define el número máximo de hijos

    def __init__(self, nombre):
        self.nombre = nombre  # Inicializa el nombre del padre
        self.hijos = [Hijo() for _ in range(self.maxHijos)]  # Crea una lista vacía de hijos
        self.numHijos = 0  # Inicializa el número de hijos

    def getNombre(self):
        return self.nombre  # Devuelve el nombre del padre

    def setNombre(self, nombre):
        self.nombre = nombre  # Establece el nombre del padre

    def agregarHijo(self, hijo):
        if self.numHijos < self.maxHijos:
            self.hijos[self.numHijos] = hijo  # Agrega el hijo a la lista de hijos
            self.numHijos += 1  # Incrementa el número de hijos
        else:
            print("No se pueden agregar más hijos. Límite alcanzado.")  # Muestra un mensaje si se alcanza el límite

    def imprimirInfo(self):
        print("Padre:", self.nombre)  # Imprime el nombre del padre
        print("Número de hijos:", self.numHijos)  # Imprime el número de hijos

# Creamos un objeto Padre con el nombre "Juan"
padre = Padre("p1")

# Creamos varios objetos Hijo con nombres
hijo1 = Hijo("h1")
hijo2 = Hijo("h2")
hijo3 = Hijo("h3")

# Relacionamos los objetos Hijo con el objeto Padre
padre.agregarHijo(hijo1)
padre.agregarHijo(hijo2)
padre.agregarHijo(hijo3)

# Imprimimos la información del padre y la cantidad de hijos
padre.imprimirInfo()
