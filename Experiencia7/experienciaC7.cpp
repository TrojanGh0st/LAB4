#include <iostream>
#include <string>

using namespace std;

// Clase base: Animal
class Animal {
protected:
    string nombre;

public:
    // Constructor
    Animal(const string& nombre) : nombre(nombre) {}

    // Método hacerSonido
    void hacerSonido() {
        cout << "Haciendo sonido genérico" << endl;
    }

    // Destructor
    ~Animal() {
        cout << "Destructor de Animal" << endl;
    }
};

// Clase derivada: Perro (hereda de Animal)
class Perro : public Animal {
private:
    string raza;

public:
    // Constructor
    Perro(const string& nombre, const string& raza) : Animal(nombre), raza(raza) {}

    // Método propio: ladrar
    void ladrar() {
        cout << "¡Guau!" << endl;
    }

    // Destructor
    ~Perro() {
        cout << "Destructor de Perro" << endl;
    }

    // Métodos para acceder y modificar atributo raza
    const string& getRaza() const { return raza; }
    void setRaza(const string& nuevaRaza) { raza = nuevaRaza; }
};

int main() {
    // Crear un objeto de la clase derivada (Perro)
    Perro miPerro("Fido", "Labrador");

    // Acceder a atributos y métodos heredados de la clase base (Animal)
    cout << miPerro.nombre << endl;
    miPerro.hacerSonido();

    // Acceder a atributos y métodos propios de la clase derivada (Perro)
    cout << miPerro.getRaza() << endl;
    miPerro.ladrar();

    // Modificar atributos propios de la clase derivada (Perro)
    miPerro.setRaza("Golden Retriever");

    // Eliminar atributos propios de la clase derivada (Perro)
    miPerro.setRaza("");

    // El objeto se destruirá automáticamente al salir del ámbito (fin de main)
    return 0;
}
