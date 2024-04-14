#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Definición de la clase Autor
class Autor {
private:
    string nombre;
    string nacionalidad;
    vector<string> librosEscritos;

public:
    Autor(string nombre, string nacionalidad) : nombre(nombre), nacionalidad(nacionalidad) {}

    void agregarLibroEscrito(string libro) {
        librosEscritos.push_back(libro);
    }

    string obtenerNombre() {
        return nombre;
    }

    string obtenerNacionalidad() {
        return nacionalidad;
    }

    vector<string> obtenerLibrosEscritos() {
        return librosEscritos;
    }
};

// Definición de la clase Libro
class Libro {
private:
    string ISBN;
    string titulo;
    int anoPublicacion;
    int cantidadEjemplares;
    Autor* autor;

public:
    Libro(string ISBN, string titulo, int anoPublicacion, int cantidadEjemplares, Autor* autor)
        : ISBN(ISBN), titulo(titulo), anoPublicacion(anoPublicacion), cantidadEjemplares(cantidadEjemplares), autor(autor) {}

    string obtenerISBN() {
        return ISBN;
    }

    string obtenerTitulo() {
        return titulo;
    }

    int obtenerAnoPublicacion() {
        return anoPublicacion;
    }

    int obtenerCantidadEjemplares() {
        return cantidadEjemplares;
    }

    Autor* obtenerAutor() {
        return autor;
    }
};

// Definición de la clase Usuario
class Usuario {
private:
    string nombre;
    string direccion;
    string telefono;
    vector<Libro*> librosPrestados;

public:
    Usuario(string nombre, string direccion, string telefono) : nombre(nombre), direccion(direccion), telefono(telefono) {}

    void prestarLibro(Libro* libro) {
        librosPrestados.push_back(libro);
    }

    string obtenerNombre() {
        return nombre;
    }

    string obtenerDireccion() {
        return direccion;
    }

    string obtenerTelefono() {
        return telefono;
    }

    vector<Libro*> obtenerLibrosPrestados() {
        return librosPrestados;
    }
};

int main() {
    // Crear un autor
    Autor autor("Stephen King", "Estados Unidos");

    // Crear un libro y asociarlo con el autor
    Libro libro("9788490626780", "It", 1986, 5, &autor);

    // Crear un usuario
    Usuario usuario("Pedro Carrasco", "Calle Principal 123", "555-1234");

    // Prestar un libro al usuario
    usuario.prestarLibro(&libro);

    // Mostrar la información del libro prestado al usuario
    vector<Libro*> librosPrestados = usuario.obtenerLibrosPrestados();
    cout << "Libros prestados a " << usuario.obtenerNombre() << ":" << endl;
    for (Libro* libroPrestado : librosPrestados) {
        cout << "- " << libroPrestado->obtenerTitulo() << " (" << libroPrestado->obtenerAnoPublicacion() << ")" << endl;
    }

    return 0;
}
