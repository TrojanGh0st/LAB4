class Curso:
    def __init__(self, nombre, codigo, descripcion, fecha_inicio, fecha_finalizacion):
        # Inicialización de los atributos del curso
        self.nombre = nombre
        self.codigo = codigo
        self.descripcion = descripcion
        self.fecha_inicio = fecha_inicio
        self.fecha_finalizacion = fecha_finalizacion
        self.estudiantes = []  # Lista para almacenar los estudiantes asociados al curso
    
    def agregar_estudiante(self, estudiante):
        # Método para agregar un estudiante al curso
        self.estudiantes.append(estudiante)  # Agrega el estudiante a la lista de estudiantes asociados al curso
        estudiante.agregar_curso(self)  # Agrega este curso a la lista de cursos del estudiante
    
    def eliminar_estudiante(self, estudiante):
        # Método para eliminar un estudiante del curso
        if estudiante in self.estudiantes:  # Verifica si el estudiante está en la lista de estudiantes asociados
            self.estudiantes.remove(estudiante)  # Remueve al estudiante de la lista
            estudiante.eliminar_curso(self)  # Elimina este curso de la lista de cursos del estudiante
    
    def imprimir_curso(self):
        # Método para imprimir los detalles del curso
        print(f"Nombre: {self.nombre}, Codigo: {self.codigo}, Descripcion: {self.descripcion}, Fecha de Inicio: {self.fecha_inicio}, Fecha de Finalizacion: {self.fecha_finalizacion}")
        print("Estudiantes asociados:")
        for estudiante in self.estudiantes:  # Itera sobre la lista de estudiantes asociados al curso
            estudiante.imprimir_estudiante()  # Imprime los detalles de cada estudiante asociado al curso


class Estudiante:
    def __init__(self, nombre, apellido, num_identificacion, correo_electronico):
        # Inicialización de los atributos del estudiante
        self.nombre = nombre
        self.apellido = apellido
        self.num_identificacion = num_identificacion
        self.correo_electronico = correo_electronico
        self.cursos = []  # Lista para almacenar los cursos asociados al estudiante
    
    def agregar_curso(self, curso):
        # Método para agregar un curso al estudiante
        self.cursos.append(curso)  # Agrega el curso a la lista de cursos asociados al estudiante
    
    def eliminar_curso(self, curso):
        # Método para eliminar un curso del estudiante
        if curso in self.cursos:  # Verifica si el curso está en la lista de cursos asociados
            self.cursos.remove(curso)  # Remueve el curso de la lista de cursos del estudiante
    
    def imprimir_estudiante(self):
        # Método para imprimir los detalles del estudiante
        print(f"Nombre: {self.nombre}, Apellido: {self.apellido}, Numero de Identificacion: {self.num_identificacion}, Correo Electronico: {self.correo_electronico}")
        print("Cursos asociados:")
        for curso in self.cursos:  # Itera sobre la lista de cursos asociados al estudiante
            print(f"Nombre: {curso.nombre}, Codigo: {curso.codigo}, Descripcion: {curso.descripcion}, Fecha de Inicio: {curso.fecha_inicio}, Fecha de Finalizacion: {curso.fecha_finalizacion}")


# Creación de instancias de Curso y Estudiante
curso1 = Curso("Curso 1", "001", "Descripcion del Curso 1", "01/04/2024", "30/06/2024")
curso2 = Curso("Curso 2", "002", "Descripcion del Curso 2", "15/04/2024", "15/07/2024")

estudiante1 = Estudiante("nom1", "apell1", "52312", "user1@gmail.com")
estudiante2 = Estudiante("nom2", "apell2", "12312", "user2@gmail.com")

# Impresión de detalles antes de asociar estudiantes y cursos
print("Cursos antes de asociar estudiantes:")
curso1.imprimir_curso()
curso2.imprimir_curso()
print("\nEstudiantes antes de asociar cursos:")
estudiante1.imprimir_estudiante()
estudiante2.imprimir_estudiante()

# Asociación de estudiantes y cursos
curso1.agregar_estudiante(estudiante1)
curso2.agregar_estudiante(estudiante1)
curso2.agregar_estudiante(estudiante2)

estudiante1.agregar_curso(curso1)
estudiante1.agregar_curso(curso2)
estudiante2.agregar_curso(curso2)

# Desasociación de estudiantes y cursos
curso1.eliminar_estudiante(estudiante1)
estudiante1.eliminar_curso(curso2)

# Impresión de detalles después de asociar y desasociar estudiantes y cursos
print("\nCursos despues de asociar y desasociar estudiantes:")
curso1.imprimir_curso()
curso2.imprimir_curso()

print("\nEstudiantes despues de asociar y desasociar cursos:")
estudiante1.imprimir_estudiante()
estudiante2.imprimir_estudiante()
