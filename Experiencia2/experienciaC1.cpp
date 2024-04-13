#include <iostream>
#include <string>

using namespace std;

// Declaración anticipada de la clase Estudiante
class Estudiante;

// Definición de la clase Curso
class Curso {
private:
    string nombre;
    string codigo;
    string descripcion;
    string fechaInicio;
    string fechaFinalizacion;
    Estudiante* estudiantes[100]; // Arreglo de punteros a objetos Estudiante
    int numEstudiantes; // Contador de estudiantes asociados

public:
    // Constructor de la clase Curso
    Curso(string nombre, string codigo, string descripcion, string fechaInicio, string fechaFinalizacion)
        : nombre(nombre), codigo(codigo), descripcion(descripcion), fechaInicio(fechaInicio), fechaFinalizacion(fechaFinalizacion), numEstudiantes(0) {}

    // Función para agregar un estudiante al curso
    void agregarEstudiante(Estudiante* estudiante);

    // Función para eliminar un estudiante del curso
    void eliminarEstudiante(Estudiante* estudiante);

    // Función para imprimir los detalles del curso
    void imprimirCurso();

    // Funciones de acceso a los atributos
    string getNombre() const { return nombre; }
    string getCodigo() const { return codigo; }
    string getDescripcion() const { return descripcion; }
    string getFechaInicio() const { return fechaInicio; }
    string getFechaFinalizacion() const { return fechaFinalizacion; }
};

// Definición de la clase Estudiante
class Estudiante {
private:
    string nombre;
    string apellido;
    string numIdentificacion;
    string correoElectronico;
    Curso* cursos[100]; // Arreglo de punteros a objetos Curso
    int numCursos; // Contador de cursos asociados

public:
    // Constructor de la clase Estudiante
    Estudiante(string nombre, string apellido, string numIdentificacion, string correoElectronico)
        : nombre(nombre), apellido(apellido), numIdentificacion(numIdentificacion), correoElectronico(correoElectronico), numCursos(0) {}

    // Función para agregar un curso al estudiante
    void agregarCurso(Curso* curso);

    // Función para eliminar un curso del estudiante
    void eliminarCurso(Curso* curso);

    // Función para imprimir los detalles del estudiante
    void imprimirEstudiante();

    // Funciones de acceso a los atributos
    string getNombre() const { return nombre; }
    string getApellido() const { return apellido; }
    string getNumIdentificacion() const { return numIdentificacion; }
    string getCorreoElectronico() const { return correoElectronico; }
};

// Función para imprimir los detalles de un curso
void imprimirDetalles(const Curso& curso) {
    cout << "Nombre: " << curso.getNombre() << ", Codigo: " << curso.getCodigo() << ", Descripcion: " << curso.getDescripcion() << ", Fecha de Inicio: " << curso.getFechaInicio() << ", Fecha de Finalizacion: " << curso.getFechaFinalizacion() << endl;
}

// Función para imprimir los detalles de un estudiante
void imprimirDetalles(const Estudiante& estudiante) {
    cout << "Nombre: " << estudiante.getNombre() << ", Apellido: " << estudiante.getApellido() << ", Numero de Identificacion: " << estudiante.getNumIdentificacion() << ", Correo Electronico: " << estudiante.getCorreoElectronico() << endl;
}

// Implementación de la función agregarEstudiante
void Curso::agregarEstudiante(Estudiante* estudiante) {
    if (numEstudiantes < 100) {
        estudiantes[numEstudiantes] = estudiante; // Agrega el estudiante al arreglo
        numEstudiantes++; // Incrementa el contador de estudiantes
        estudiante->agregarCurso(this); // Agrega este curso a la lista de cursos del estudiante
    } else {
        cout << "No se pueden agregar mas estudiantes al curso." << endl;
    }
}

// Implementación de la función eliminarEstudiante
void Curso::eliminarEstudiante(Estudiante* estudiante) {
    for (int i = 0; i < numEstudiantes; i++) { // Itera sobre los estudiantes asociados al curso
        if (estudiantes[i] == estudiante) { // Si encuentra al estudiante a eliminar
            for (int j = i; j < numEstudiantes - 1; j++) {
                estudiantes[j] = estudiantes[j + 1]; // Mueve los estudiantes restantes hacia atrás
            }
            numEstudiantes--; // Decrementa el contador de estudiantes
            estudiante->eliminarCurso(this); // Elimina este curso de la lista de cursos del estudiante
            break;
        }
    }
}

// Implementación de la función imprimirCurso
void Curso::imprimirCurso() {
    imprimirDetalles(*this); // Imprime los detalles del curso
    cout << "Estudiantes asociados:" << endl;
    for (int i = 0; i < numEstudiantes; i++) { // Itera sobre los estudiantes asociados al curso
        imprimirDetalles(*estudiantes[i]); // Imprime los detalles de cada estudiante
    }
}

// Implementación de la función agregarCurso
void Estudiante::agregarCurso(Curso* curso) {
    if (numCursos < 100) {
        cursos[numCursos] = curso; // Agrega el curso al arreglo
        numCursos++; // Incrementa el contador de cursos
    } else {
        cout << "No se pueden agregar mas cursos al estudiante." << endl;
    }
}

// Implementación de la función eliminarCurso
void Estudiante::eliminarCurso(Curso* curso) {
    for (int i = 0; i < numCursos; i++) { // Itera sobre los cursos asociados al estudiante
        if (cursos[i] == curso) { // Si encuentra el curso a eliminar
            for (int j = i; j < numCursos - 1; j++) {
                cursos[j] = cursos[j + 1]; // Mueve los cursos restantes hacia atrás
            }
            numCursos--; // Decrementa el contador de cursos
            break;
        }
    }
}

// Implementación de la función imprimirEstudiante
void Estudiante::imprimirEstudiante() {
    imprimirDetalles(*this); // Imprime los detalles del estudiante
    cout << "Cursos asociados:" << endl;
    for (int i = 0; i < numCursos; i++) { // Itera sobre los cursos asociados al estudiante
        imprimirDetalles(*cursos[i]); // Imprime los detalles de cada curso
    }
}

int main() {
    // Creación de instancias de Curso y Estudiante
    Curso curso1("Curso 1", "001", "Descripcion1", "01/04/2024", "30/06/2024");
    Curso curso2("Curso 2", "002", "Descripcion2", "15/04/2024", "15/07/2024");

    Estudiante estudiante1("nom1", "apell1", "12345", "user1@gmail.com");
    Estudiante estudiante2("nom2", "apell2", "67890", "user2@gmail.com");

    // Impresión de detalles antes de asociar estudiantes y cursos
    cout << "Cursos antes de asociar estudiantes:" << endl;
    curso1.imprimirCurso();
    curso2.imprimirCurso();

    cout << "\nEstudiantes antes de asociar cursos:" << endl;
    estudiante1.imprimirEstudiante();
    estudiante2.imprimirEstudiante();

    // Asociación de estudiantes y cursos
    curso1.agregarEstudiante(&estudiante1);
    curso2.agregarEstudiante(&estudiante1);
    curso2.agregarEstudiante(&estudiante2);

    estudiante1.agregarCurso(&curso1);
    estudiante1.agregarCurso(&curso2);
    estudiante2.agregarCurso(&curso2);

    // Desasociación de estudiantes y cursos
    curso1.eliminarEstudiante(&estudiante1);
    estudiante1.eliminarCurso(&curso2);

    // Impresión de detalles después de asociar y desasociar estudiantes y cursos
    cout << "\nCursos despues de asociar y desasociar estudiantes:" << endl;
    curso1.imprimirCurso();
    curso2.imprimirCurso();

    cout << "\nEstudiantes despues de asociar y desasociar cursos:" << endl;
    estudiante1.imprimirEstudiante();
    estudiante2.imprimirEstudiante();

    return 0;
}
