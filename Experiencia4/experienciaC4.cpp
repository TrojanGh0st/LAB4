#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Declaración de la clase Trabajador
class Trabajador {
public:
    Trabajador(const string& nombre, const string& cargo) 
        : nombre(nombre), cargo(cargo) {}

    // Método para establecer asociación reflexiva con otros trabajadores
    void agregarCompanero(Trabajador* otro_trabajador) {
        if (otro_trabajador != nullptr) {
            companeros.push_back(otro_trabajador);
            otro_trabajador->companeros.push_back(this);
        } else {
            cout << "Error: El objeto proporcionado no es un Trabajador." << endl;
        }
    }

    // Getters
    const string& getNombre() const { return nombre; }
    const vector<Trabajador*>& getCompaneros() const { return companeros; }

private:
    string nombre;
    string cargo;
    vector<Trabajador*> companeros;
};

// Declaración de la clase Gerente que hereda de Trabajador
class Gerente : public Trabajador {
public:
    Gerente(const string& nombre, const string& cargo, const string& area)
        : Trabajador(nombre, cargo), area(area) {}

    // Método para agregar trabajadores a cargo del gerente
    void agregarTrabajador(Trabajador* trabajador) {
        if (trabajadores_a_cargo.size() < MAX_TAMANIO_ARREGLO) {
            trabajadores_a_cargo.push_back(trabajador);
        } else {
            cout << "Error: No se pueden agregar más trabajadores a cargo." << endl;
        }
    }

    // Getters
    const string& getArea() const { return area; }
    const vector<Trabajador*>& getTrabajadoresACargo() const { return trabajadores_a_cargo; }

private:
    string area;
    vector<Trabajador*> trabajadores_a_cargo;
};

// Definición de la constante para el tamaño máximo del arreglo de trabajadores
const int MAX_TAMANIO_ARREGLO = 5;

int main() {
    // Creación de instancias de la clase Trabajador y Gerente (con punteros)
    Trabajador* juan = new Trabajador("Juan", "Analista");
    Trabajador* ana = new Trabajador("Ana", "Programadora");
    Trabajador* luis = new Trabajador("Luis", "Diseñador");
    Gerente* maria = new Gerente("Maria", "Gerente de Proyecto", "Desarrollo");

    // Establecimiento de relaciones entre los trabajadores del mismo gerente
    juan->agregarCompanero(ana);
    juan->agregarCompanero(luis);
    ana->agregarCompanero(luis);

    // Obtención de información sobre las relaciones establecidas
    cout << "Los compañeros de " << juan->getNombre() << " son:" << endl;
    for (Trabajador* compañero : juan->getCompaneros()) {
        cout << "- " << compañero->getNombre() << endl;
    }

    cout << "Los compañeros de " << ana->getNombre() << " son:" << endl;
    for (Trabajador* compañero : ana->getCompaneros()) {
        cout << "- " << compañero->getNombre() << endl;
    }

    cout << "Los compañeros de " << luis->getNombre() << " son:" << endl;
    for (Trabajador* compañero : luis->getCompaneros()) {
        cout << "- " << compañero->getNombre() << endl;
    }

    cout << "Los trabajadores a cargo de " << maria->getNombre() << " en el área de " << maria->getArea() << " son:" << endl;
    for (Trabajador* trabajador : maria->getTrabajadoresACargo()) {
        cout << "- " << trabajador->getNombre() << endl;
    }

    // Liberar memoria (eliminar trabajadores y gerente)
    delete juan;
    delete ana;
    delete luis;
    delete maria;

    return 0;
}
