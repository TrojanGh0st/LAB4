#include <iostream>
#include <string>

using namespace std;

// Declaración de la clase Hijo
class Hijo {
private:
    string nombre;

public:
    // Constructor de la clase Hijo
    // Se proporciona un valor predeterminado para el nombre en caso de que no se proporcione al crear un objeto Hijo
    Hijo(string nombre = "") : nombre(nombre) {}

    // Método getter para obtener el nombre del hijo
    string getNombre() const {
        return nombre;
    }

    // Método setter para establecer el nombre del hijo
    void setNombre(string nombre) {
        this->nombre = nombre;
    }
};

// Declaración de la clase Padre
class Padre {
private:
    string nombre;
    static const int maxHijos = 5;
    Hijo hijos[maxHijos]; // Arreglo de objetos Hijo para almacenar los hijos del padre
    int numHijos; // Variable para contar cuántos hijos tiene el padre

public:
    // Constructor de la clase Padre
    Padre(string nombre) : nombre(nombre), numHijos(0) {
        // Inicializamos cada elemento del arreglo con un objeto Hijo vacío
        for (int i = 0; i < maxHijos; ++i) {
            hijos[i] = Hijo(); // Utilizamos el constructor por defecto de Hijo
        }
    }

    // Método getter para obtener el nombre del padre
    string getNombre() const {
        return nombre;
    }

    // Método setter para establecer el nombre del padre
    void setNombre(string nombre) {
        this->nombre = nombre;
    }

    // Método para agregar un hijo al arreglo de hijos
    void agregarHijo(const Hijo& hijo) {
        // Verificamos si hay espacio disponible para agregar otro hijo
        if (numHijos < maxHijos) {
            hijos[numHijos++] = hijo; // Agregamos el hijo al arreglo
        } else {
            cout << "No se pueden agregar más hijos. Límite alcanzado." << endl;
        }
    }

    // Método para imprimir la información del padre y la cantidad de hijos
    void imprimirInfo() const {
        // Imprimimos el nombre del padre
        cout << "Padre: " << nombre << endl;
        // Imprimimos la cantidad de hijos del padre
        cout << "Número de hijos: " << numHijos << endl;
    }
};

int main() {
    // Creamos un objeto Padre con el nombre "Juan"
    Padre padre("p1");

    // Creamos varios objetos Hijo con nombres
    Hijo hijo1("h1");
    Hijo hijo2("h2");
    Hijo hijo3("h3");

    // Relacionamos los objetos Hijo con el objeto Padre
    padre.agregarHijo(hijo1);
    padre.agregarHijo(hijo2);
    padre.agregarHijo(hijo3);

    // Imprimimos la información del padre y la cantidad de hijos
    padre.imprimirInfo();

    return 0;
}
