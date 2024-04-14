import java.util.ArrayList;
import java.util.List;

// Definición de la clase Autor
class Autor {
    private String nombre;
    private String nacionalidad;
    private List<String> librosEscritos;

    public Autor(String nombre, String nacionalidad) {
        this.nombre = nombre;
        this.nacionalidad = nacionalidad;
        this.librosEscritos = new ArrayList<>();
    }

    public void agregarLibroEscrito(String libro) {
        librosEscritos.add(libro);
    }

    public String obtenerNombre() {
        return nombre;
    }

    public String obtenerNacionalidad() {
        return nacionalidad;
    }

    public List<String> obtenerLibrosEscritos() {
        return librosEscritos;
    }
}

// Definición de la clase Libro
class Libro {
    private String ISBN;
    private String titulo;
    private int anoPublicacion;
    private int cantidadEjemplares;
    private Autor autor;

    public Libro(String ISBN, String titulo, int anoPublicacion, int cantidadEjemplares, Autor autor) {
        this.ISBN = ISBN;
        this.titulo = titulo;
        this.anoPublicacion = anoPublicacion;
        this.cantidadEjemplares = cantidadEjemplares;
        this.autor = autor;
    }

    public String obtenerISBN() {
        return ISBN;
    }

    public String obtenerTitulo() {
        return titulo;
    }

    public int obtenerAnoPublicacion() {
        return anoPublicacion;
    }

    public int obtenerCantidadEjemplares() {
        return cantidadEjemplares;
    }

    public Autor obtenerAutor() {
        return autor;
    }
}

// Definición de la clase Usuario
class Usuario {
    private String nombre;
    private String direccion;
    private String telefono;
    private List<Libro> librosPrestados;

    public Usuario(String nombre, String direccion, String telefono) {
        this.nombre = nombre;
        this.direccion = direccion;
        this.telefono = telefono;
        this.librosPrestados = new ArrayList<>();
    }

    public void prestarLibro(Libro libro) {
        librosPrestados.add(libro);
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

    public List<Libro> obtenerLibrosPrestados() {
        return librosPrestados;
    }
}

public class Main {
    public static void main(String[] args) {
        // Crear un autor
        Autor autor = new Autor("Stephen King", "Estados Unidos");

        // Crear un libro y asociarlo con el autor
        Libro libro = new Libro("9788490626780", "It", 1986, 5, autor);

        // Crear un usuario
        Usuario usuario = new Usuario("Pedro Carrasco", "Calle Principal 123", "555-1234");

        // Prestar un libro al usuario
        usuario.prestarLibro(libro);

        // Mostrar la información del libro prestado al usuario
        System.out.println("Libros prestados a " + usuario.obtenerNombre() + ":");
        for (Libro libroPrestado : usuario.obtenerLibrosPrestados()) {
            System.out.println("- " + libroPrestado.obtenerTitulo() + " (" + libroPrestado.obtenerAnoPublicacion() + ")");
        }
    }
}
