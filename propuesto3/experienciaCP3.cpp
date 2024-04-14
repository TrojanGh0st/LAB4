#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Definición de la clase Estudiante
class Estudiante {
private:
    string nombre;
    string direccion;
    string numeroMatricula;
    vector<string> asignaturasMatriculadas;
    vector<int> notas;
    vector<int> faltas;

public:
    Estudiante(string nombre, string direccion, string numeroMatricula) : nombre(nombre), direccion(direccion), numeroMatricula(numeroMatricula) {}

    void matricularAsignatura(string asignatura) {
        asignaturasMatriculadas.push_back(asignatura);
        notas.push_back(0); // Inicialmente todas las notas son 0
        faltas.push_back(0); // Inicialmente no hay faltas
    }

    void registrarNota(int indice, int nota) {
        notas[indice] = nota;
    }

    void registrarFalta(int indice) {
        faltas[indice]++;
    }

    string obtenerNombre() {
        return nombre;
    }

    string obtenerDireccion() {
        return direccion;
    }

    string obtenerNumeroMatricula() {
        return numeroMatricula;
    }

    vector<string> obtenerAsignaturasMatriculadas() {
        return asignaturasMatriculadas;
    }

    vector<int> obtenerNotas() {
        return notas;
    }

    vector<int> obtenerFaltas() {
        return faltas;
    }
};

// Definición de la clase Profesor
class Profesor {
private:
    string nombre;
    string direccion;
    string numeroTelefono;
    vector<string> asignaturasImpartidas;

public:
    Profesor(string nombre, string direccion, string numeroTelefono) : nombre(nombre), direccion(direccion), numeroTelefono(numeroTelefono) {}

    void asignarAsignatura(string asignatura) {
        asignaturasImpartidas.push_back(asignatura);
    }

    string obtenerNombre() {
        return nombre;
    }

    string obtenerDireccion() {
        return direccion;
    }

    string obtenerNumeroTelefono() {
        return numeroTelefono;
    }

    vector<string> obtenerAsignaturasImpartidas() {
        return asignaturasImpartidas;
    }
};

// Definición de la clase Asignatura
class Asignatura {
private:
    string codigo;
    string nombre;
    string descripcion;
    Profesor* profesorAsociado;

public:
    Asignatura(string codigo, string nombre, string descripcion, Profesor* profesorAsociado)
        : codigo(codigo), nombre(nombre), descripcion(descripcion), profesorAsociado(profesorAsociado) {}

    string obtenerCodigo() {
        return codigo;
    }

    string obtenerNombre() {
        return nombre;
    }

    string obtenerDescripcion() {
        return descripcion;
    }

    Profesor* obtenerProfesorAsociado() {
        return profesorAsociado;
    }
};

int main() {
    // Crear un estudiante
    Estudiante estudiante("Pedro Carrasco", "Calle Principal 123", "0001");
    estudiante.matricularAsignatura("COmputo");
    estudiante.matricularAsignatura("Lenguaje");

    // Registrar notas del estudiante
    estudiante.registrarNota(0, 85); // Matemáticas
    estudiante.registrarNota(1, 75); // Física

    // Registrar faltas de asistencia del estudiante
    estudiante.registrarFalta(0); // Matemáticas
    estudiante.registrarFalta(1); // Física

    // Mostrar información del estudiante
    cout << "Estudiante: " << estudiante.obtenerNombre() << endl;
    cout << "Dirección: " << estudiante.obtenerDireccion() << endl;
    cout << "Número de matrícula: " << estudiante.obtenerNumeroMatricula() << endl;
    cout << "Asignaturas matriculadas:" << endl;
    vector<string> asignaturasMatriculadas = estudiante.obtenerAsignaturasMatriculadas();
    vector<int> notas = estudiante.obtenerNotas();
    vector<int> faltas = estudiante.obtenerFaltas();
    for (int i = 0; i < asignaturasMatriculadas.size(); ++i) {
        cout << "- " << asignaturasMatriculadas[i] << ": Nota = " << notas[i] << ", Faltas = " << faltas[i] << endl;
    }

    // Crear un profesor
    Profesor profesor("Dr. Smith", "Avenida Central 456", "555-6789");
    profesor.asignarAsignatura("COmputo");
    profesor.asignarAsignatura("Lenguaje");

    // Crear una asignatura asociada al profesor
    Asignatura asignatura("COM101", "Computo", "Curso introductorio de matemáticas", &profesor);

    // Mostrar información de la asignatura
    cout << "\nAsignatura: " << asignatura.obtenerNombre() << endl;
    cout << "Código: " << asignatura.obtenerCodigo() << endl;
    cout << "Descripción: " << asignatura.obtenerDescripcion() << endl;
    cout << "Profesor: " << asignatura.obtenerProfesorAsociado()->obtenerNombre() << endl;
    cout << "Dirección del profesor: " << asignatura.obtenerProfesorAsociado()->obtenerDireccion() << endl;
    cout << "Teléfono del profesor: " << asignatura.obtenerProfesorAsociado()->obtenerNumeroTelefono() << endl;

    return 0;
}
