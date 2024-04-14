class Trabajador:
    def __init__(self, nombre, cargo):
        self.nombre = nombre
        self.cargo = cargo
        self.companeros = []

    def agregarCompanero(self, otro_trabajador):
        if isinstance(otro_trabajador, Trabajador):
            self.companeros.append(otro_trabajador)
            otro_trabajador.companeros.append(self)
        else:
            print("Error: El objeto proporcionado no es un Trabajador.")

class Gerente(Trabajador):
    def __init__(self, nombre, cargo, area):
        super().__init__(nombre, cargo)
        self.area = area
        self.trabajadores_a_cargo = []

    def agregarTrabajador(self, trabajador):
        if len(self.trabajadores_a_cargo) < MAX_TAMANIO_ARREGLO:
            self.trabajadores_a_cargo.append(trabajador)
        else:
            print("Error: No se pueden agregar más trabajadores a cargo.")

# Definir el tamaño máximo del arreglo de trabajadores
MAX_TAMANIO_ARREGLO = 10

# Crear arreglo de objetos Trabajador con el tamaño definido
trabajadores = [None] * MAX_TAMANIO_ARREGLO

# Crear instancias de Trabajador y Gerente
juan = Trabajador("Juan", "Analista")
ana = Trabajador("Ana", "Programadora")
luis = Trabajador("Luis", "Diseñador")
maria = Gerente("Maria", "Gerente de Proyecto", "Desarrollo")

# Asociar trabajadores bajo el mismo gerente utilizando agregarCompanero
juan.agregarCompanero(ana)
juan.agregarCompanero(luis)
ana.agregarCompanero(luis)

# Obtener información sobre las relaciones establecidas
print(f"Los compañeros de {juan.nombre} son:")
for compañero in juan.companeros:
    print(f"- {compañero.nombre}")

print(f"Los compañeros de {ana.nombre} son:")
for compañero in ana.companeros:
    print(f"- {compañero.nombre}")

print(f"Los compañeros de {luis.nombre} son:")
for compañero in luis.companeros:
    print(f"- {compañero.nombre}")

print(f"Los trabajadores a cargo de {maria.nombre} en el área de {maria.area} son:")
for trabajador in maria.trabajadores_a_cargo:
    print(f"- {trabajador.nombre}")

