#include <iostream>
#include <string>

using namespace std;

// Declaración de la clase Motor
class Motor {
private:
    string modelo;
    int caballosDeFuerza;

public:
    Motor(const string& modelo, int caballosDeFuerza) : modelo(modelo), caballosDeFuerza(caballosDeFuerza) {}

    void encender() {
        cout << "El motor " << modelo << " se enciende." << endl;
    }

    void apagar() {
        cout << "El motor " << modelo << " se apaga." << endl;
    }

    ~Motor() {
        cout << "El motor " << modelo << " ha sido destruido." << endl;
    }
};

// Declaración de la clase Vehiculo
class Vehiculo {
private:
    string tipo;
    string marca;
    string modelo;
    int año;
    Motor* motor;  // Composición: Vehiculo tiene un Motor

public:
    Vehiculo(const string& tipo, const string& marca, const string& modelo, int año, Motor* motor)
        : tipo(tipo), marca(marca), modelo(modelo), año(año), motor(motor) {}

    void encender() {
        cout << "Iniciando el " << año << " " << marca << " " << modelo << " " << tipo << "..." << endl;
        motor->encender();
    }

    void apagar() {
        cout << "Deteniendo el " << año << " " << marca << " " << modelo << " " << tipo << "..." << endl;
        motor->apagar();
    }

    ~Vehiculo() {
        delete motor; // Liberar la memoria del objeto Motor asociado
        cout << "El " << tipo << " " << marca << " " << modelo << " del " << año << " ha sido destruido." << endl;
    }
};

int main() {
    // Crear un objeto Motor para un vehículo
    Motor* motor = new Motor("V8", 450);

    // Crear un objeto Vehiculo y asignarle el motor
    Vehiculo* miVehiculo = new Vehiculo("auto", "Tesla", "Model S", 2023, motor);

    // Iniciar el vehículo (se inicia también el motor)
    miVehiculo->encender();  // Salida: Iniciando el 2023 Tesla Model S auto... \n El motor V8 se enciende.

    // Detener el vehículo (se detiene también el motor)
    miVehiculo->apagar();  // Salida: Deteniendo el 2023 Tesla Model S auto... \n El motor V8 se apaga.

    // Liberar la memoria al finalizar el programa
    delete miVehiculo;

    return 0;
}
