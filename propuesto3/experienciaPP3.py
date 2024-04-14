class Estudiante:
    def privadoEstudiante(self, nombre, direccion, numero_matricula):
        self.nombre = nombre
        self.direccion = direccion
        self.numero_matricula = numero_matricula
        self.asignaturas_matriculadas = []
        self.notas = []
        self.faltas = []

    def matricular_asignatura(self, asignatura):
        self.asignaturas_matriculadas.append(asignatura)
        self.notas.append(0)  # Inicialmente todas las notas son 0
        self.faltas.append(0)  # Inicialmente no hay faltas

    def registrar_nota(self, indice, nota):
        self.notas[indice] = nota

    def registrar_falta(self, indice):
        self.faltas[indice] += 1

class Profesor:
    def privadoProfesor(self, nombre, direccion, numero_telefono):
        self.nombre = nombre
        self.direccion = direccion
        self.numero_telefono = numero_telefono
        self.asignaturas_impartidas = []

    def asignar_asignatura(self, asignatura):
        self.asignaturas_impartidas.append(asignatura)

class Asignatura:
    def privado_Asignatura(self, codigo, nombre, descripcion, profesor_asociado):
        self.codigo = codigo
        self.nombre = nombre
        self.descripcion = descripcion
        self.profesor_asociado = profesor_asociado

# Crear un estudiante
estudiante = Estudiante("Pedro Carrasco", "Calle Principal 123", "0001")
estudiante.matricular_asignatura("COmputo")
estudiante.matricular_asignatura("Lenguaje")

# Registrar notas del estudiante
estudiante.registrar_nota(0, 85)  # Matemáticas
estudiante.registrar_nota(1, 75)  # Física

# Registrar faltas de asistencia del estudiante
estudiante.registrar_falta(0)  # Matemáticas
estudiante.registrar_falta(1)  # Física

# Mostrar información del estudiante
print("Estudiante:", estudiante.nombre)
print("Dirección:", estudiante.direccion)
print("Número de matrícula:", estudiante.numero_matricula)
print("Asignaturas matriculadas:")
for asignatura, nota, falta in zip(estudiante.asignaturas_matriculadas, estudiante.notas, estudiante.faltas):
    print(f"- {asignatura}: Nota = {nota}, Faltas = {falta}")

# Crear un profesor
profesor = Profesor("Dr. Smith", "Avenida Central 456", "555-6789")
profesor.asignar_asignatura("COmputo")
profesor.asignar_asignatura("lenguaje")

# Crear una asignatura asociada al profesor
asignatura = Asignatura("COM101", "COmputo", "Curso introductorio de computo", profesor)

# Mostrar información de la asignatura
print("\nAsignatura:", asignatura.nombre)
print("Código:", asignatura.codigo)
print("Descripción:", asignatura.descripcion)
print("Profesor:", asignatura.profesor_asociado.nombre)
print("Dirección del profesor:", asignatura.profesor_asociado.direccion)
print("Teléfono del profesor:", asignatura.profesor_asociado.numero_telefono)
