#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Definición de la clase Cliente
class Cliente {
private:
    string nombre;
    string direccion;
    string telefono;
    vector<string> comprasRealizadas;

public:
    Cliente(string nombre, string direccion, string telefono) : nombre(nombre), direccion(direccion), telefono(telefono) {}

    void agregarCompra(string producto) {
        comprasRealizadas.push_back(producto);
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

    vector<string> obtenerComprasRealizadas() {
        return comprasRealizadas;
    }
};

// Definición de la clase Producto
class Producto {
private:
    string codigo;
    string descripcion;
    float precio;
    string proveedor;

public:
    Producto(string codigo, string descripcion, float precio, string proveedor) : codigo(codigo), descripcion(descripcion), precio(precio), proveedor(proveedor) {}

    string obtenerCodigo() {
        return codigo;
    }

    string obtenerDescripcion() {
        return descripcion;
    }

    float obtenerPrecio() {
        return precio;
    }

    string obtenerProveedor() {
        return proveedor;
    }
};

// Definición de la clase Venta
class Venta {
private:
    int numeroFactura;
    string fecha;
    Cliente* cliente;
    vector<Producto*> productosVendidos;

public:
    Venta(int numeroFactura, string fecha, Cliente* cliente) : numeroFactura(numeroFactura), fecha(fecha), cliente(cliente) {}

    void agregarProducto(Producto* producto) {
        productosVendidos.push_back(producto);
    }

    int obtenerNumeroFactura() {
        return numeroFactura;
    }

    string obtenerFecha() {
        return fecha;
    }

    Cliente* obtenerCliente() {
        return cliente;
    }

    vector<Producto*> obtenerProductosVendidos() {
        return productosVendidos;
    }
};

int main() {
    // Crear un cliente
    Cliente cliente1("Pedro Carrasco", "Calle Principal 123", "555-1234");

    // Crear productos
    Producto producto1("001", "Camisa", 25.99, "Proveedor A");
    Producto producto2("002", "Pantalón", 35.99, "Proveedor B");

    // Realizar una venta
    Venta venta1(1001, "2024-04-12", &cliente1);
    venta1.agregarProducto(&producto1);
    venta1.agregarProducto(&producto2);

    // Mostrar la información de la venta
    cout << "Venta #" << venta1.obtenerNumeroFactura() << " realizada el " << venta1.obtenerFecha() << " a nombre de " << venta1.obtenerCliente()->obtenerNombre() << ":" << endl;
    cout << "Productos vendidos:" << endl;
    for (Producto* producto : venta1.obtenerProductosVendidos()) {
        cout << "- " << producto->obtenerDescripcion() << " (" << producto->obtenerPrecio() << ")" << endl;
    }

    return 0;
}
