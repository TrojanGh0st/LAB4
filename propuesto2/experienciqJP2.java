import java.util.ArrayList;
import java.util.List;

// Definición de la clase Cliente
class Cliente {
    private String nombre;
    private String direccion;
    private String telefono;
    private List<String> comprasRealizadas;

    public Cliente(String nombre, String direccion, String telefono) {
        this.nombre = nombre;
        this.direccion = direccion;
        this.telefono = telefono;
        this.comprasRealizadas = new ArrayList<>();
    }

    public void agregarCompra(String producto) {
        comprasRealizadas.add(producto);
    }

    public String obtenerNombre() {
        return nombre;
    }

    public String obtenerDireccion() {
        return direccion;
    }

    public String obtenerTelefono() {
        return telefono;
    }

    public List<String> obtenerComprasRealizadas() {
        return comprasRealizadas;
    }
}

// Definición de la clase Producto
class Producto {
    private String codigo;
    private String descripcion;
    private double precio;
    private String proveedor;

    public Producto(String codigo, String descripcion, double precio, String proveedor) {
        this.codigo = codigo;
        this.descripcion = descripcion;
        this.precio = precio;
        this.proveedor = proveedor;
    }

    public String obtenerCodigo() {
        return codigo;
    }

    public String obtenerDescripcion() {
        return descripcion;
    }

    public double obtenerPrecio() {
        return precio;
    }

    public String obtenerProveedor() {
        return proveedor;
    }
}

// Definición de la clase Venta
class Venta {
    private int numeroFactura;
    private String fecha;
    private Cliente cliente;
    private List<Producto> productosVendidos;

    public Venta(int numeroFactura, String fecha, Cliente cliente) {
        this.numeroFactura = numeroFactura;
        this.fecha = fecha;
        this.cliente = cliente;
        this.productosVendidos = new ArrayList<>();
    }

    public void agregarProducto(Producto producto) {
        productosVendidos.add(producto);
    }

    public int obtenerNumeroFactura() {
        return numeroFactura;
    }

    public String obtenerFecha() {
        return fecha;
    }

    public Cliente obtenerCliente() {
        return cliente;
    }

    public List<Producto> obtenerProductosVendidos() {
        return productosVendidos;
    }
}

public class Main {
    public static void main(String[] args) {
        // Crear un cliente
        Cliente cliente1 = new Cliente("Pedro Carrasco", "Calle Principal 123", "555-1234");

        // Crear productos
        Producto producto1 = new Producto("001", "Camisa", 25.99, "Proveedor A");
        Producto producto2 = new Producto("002", "Pantalón", 35.99, "Proveedor B");

        // Realizar una venta
        Venta venta1 = new Venta(1001, "2024-04-12", cliente1);
        venta1.agregarProducto(producto1);
        venta1.agregarProducto(producto2);

        // Mostrar la información de la venta
        System.out.println("Venta #" + venta1.obtenerNumeroFactura() + " realizada el " + venta1.obtenerFecha() + " a nombre de " + venta1.obtenerCliente().obtenerNombre() + ":");
        System.out.println("Productos vendidos:");
        for (Producto producto : venta1.obtenerProductosVendidos()) {
            System.out.println("- " + producto.obtenerDescripcion() + " (" + producto.obtenerPrecio() + ")");
        }
    }
}
