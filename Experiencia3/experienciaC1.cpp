#include <iostream>
#include <string>

using namespace std;

// Clase Estudiante
class Estudiante {
private:
    string nombre; // Atributo para almacenar el nombre del estudiante
    int edad; // Atributo para almacenar la edad del estudiante
public:
    // Constructor de la clase Estudiante
    Estudiante(string _nombre, int _edad) : nombre(_nombre), edad(_edad) {}

    // Métodos para obtener información del estudiante
    string getNombre() { return nombre; } // Método para obtener el nombre del estudiante
    int getEdad() { return edad; } // Método para obtener la edad del estudiante
};

// Clase Docente
class Docente {
private:
    string nombre; // Atributo para almacenar el nombre del docente
    string especialidad; // Atributo para almacenar la especialidad del docente
public:
    // Constructor de la clase Docente
    Docente(string _nombre, string _especialidad) : nombre(_nombre), especialidad(_especialidad) {}

    // Métodos para obtener información del docente
    string getNombre() { return nombre; } // Método para obtener el nombre del docente
    string getEspecialidad() { return especialidad; } // Método para obtener la especialidad del docente
};

// Clase Curso
class Curso {
private:
    string nombre; // Atributo para almacenar el nombre del curso
    int codigo; // Atributo para almacenar el código del curso
public:
    // Constructor de la clase Curso
    Curso(string _nombre, int _codigo) : nombre(_nombre), codigo(_codigo) {}

    // Métodos para obtener información del curso
    string getNombre() { return nombre; } // Método para obtener el nombre del curso
    int getCodigo() { return codigo; } // Método para obtener el código del curso
};

// Clase Asociacion
class Asociacion {
private:
    Estudiante* estudiante; // Puntero a un objeto de tipo Estudiante
    Docente* docente; // Puntero a un objeto de tipo Docente
    Curso* curso; // Puntero a un objeto de tipo Curso
public:
    // Constructor de la clase Asociacion
    Asociacion(Estudiante* _estudiante, Docente* _docente, Curso* _curso) : estudiante(_estudiante), docente(_docente), curso(_curso) {}

    // Métodos para obtener los objetos relacionados
    Estudiante* getEstudiante() { return estudiante; } // Método para obtener el objeto Estudiante asociado
    Docente* getDocente() { return docente; } // Método para obtener el objeto Docente asociado
    Curso* getCurso() { return curso; } // Método para obtener el objeto Curso asociado
};

int main() {
    // Creación de instancias de Estudiante, Docente y Curso
    Estudiante* estudiante1 = new Estudiante("Gohan", 49); // Creación de un estudiante con nombre "Gohan" y edad 49
    Docente* docente1 = new Docente("Goku ", "Calculo Integral"); // Creación de un docente con nombre "Goku" y especialidad "Calculo Integral"
    Curso* curso1 = new Curso("Calculo Integral", 202); // Creación de un curso con nombre "Calculo Integral" y código 202

    // Creación de instancia de Asociacion (uso de asociación ternaria)
    Asociacion* asociacion1 = new Asociacion(estudiante1, docente1, curso1); // Creación de una asociación entre un estudiante, un docente y un curso

    // Utilización de los métodos de las clases para obtener información
    cout << "Estudiante---> " << asociacion1->getEstudiante()->getNombre() << endl; // Imprimir el nombre del estudiante asociado
    cout << "Docente----> " << asociacion1->getDocente()->getNombre() << endl; // Imprimir el nombre del docente asociado
    cout << "Curso----> " << asociacion1->getCurso()->getNombre() << endl; // Imprimir el nombre del curso asociado

    // Liberación de memoria
    delete estudiante1; // Liberar la memoria del objeto Estudiante
    delete docente1; // Liberar la memoria del objeto Docente
    delete curso1; // Liberar la memoria del objeto Curso
    delete asociacion1; // Liberar la memoria del objeto Asociacion

    return 0;
}
