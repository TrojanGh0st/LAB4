class Estudiante:
    def __init__(self, nombre, edad):
        self.nombre = nombre  # Atributo para almacenar el nombre del estudiante
        self.edad = edad  # Atributo para almacenar la edad del estudiante

class Docente:
    def __init__(self, nombre, especialidad):
        self.nombre = nombre  # Atributo para almacenar el nombre del docente
        self.especialidad = especialidad  # Atributo para almacenar la especialidad del docente

class Curso:
    def __init__(self, nombre, codigo):
        self.nombre = nombre  # Atributo para almacenar el nombre del curso
        self.codigo = codigo  # Atributo para almacenar el código del curso

class Asociacion:
    def __init__(self, estudiante, docente, curso):
        self.estudiante = estudiante  # Objeto de tipo Estudiante
        self.docente = docente  # Objeto de tipo Docente
        self.curso = curso  # Objeto de tipo Curso

# Creación de instancias de Estudiante, Docente y Curso
estudiante1 = Estudiante("Gohan", 49)
docente1 = Docente("Goku", "Calculo Integral")
curso1 = Curso("Calculo Integral", 202)

# Creación de instancia de Asociacion (uso de asociación ternaria)
asociacion1 = Asociacion(estudiante1, docente1, curso1)

# Utilización de los objetos para obtener información
print("Estudiante--->", asociacion1.estudiante.nombre)
print("Docente---->", asociacion1.docente.nombre)
print("Curso---->", asociacion1.curso.nombre)
