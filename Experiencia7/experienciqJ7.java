// Clase base: Animal
class Animal {
    private String nombre;

    // Constructor
    public Animal(String nombre) {
        this.nombre = nombre;
    }

    // Método hacerSonido
    public void hacerSonido() {
        System.out.println("Haciendo sonido genérico");
    }

    // Destructor (método finalize)
    @Override
    protected void finalize() throws Throwable {
        System.out.println("Destructor de Animal");
    }
}

// Clase derivada: Perro (hereda de Animal)
class Perro extends Animal {
    private String raza;

    // Constructor
    public Perro(String nombre, String raza) {
        super(nombre); // Llama al constructor de la clase base (Animal)
        this.raza = raza;
    }

    // Método propio: ladrar
    public void ladrar() {
        System.out.println("¡Guau!");
    }

    // Destructor (método finalize)
    @Override
    protected void finalize() throws Throwable {
        System.out.println("Destructor de Perro");
        super.finalize(); // Llama al destructor de la clase base (Animal)
    }
}

public class Main {
    public static void main(String[] args) {
        // Crear un objeto de la clase derivada (Perro)
        Perro miPerro = new Perro("Fido", "Labrador");

        // Acceder a atributos y métodos heredados de la clase base (Animal)
        System.out.println(miPerro.getNombre());
        miPerro.hacerSonido();

        // Acceder a atributos y métodos propios de la clase derivada (Perro)
        System.out.println(miPerro.getRaza());
        miPerro.ladrar();

        // Modificar atributos propios de la clase derivada (Perro)
        miPerro.setRaza("Golden Retriever");

        // Eliminar atributos propios de la clase derivada (Perro)
        miPerro.setRaza(null);

        // El objeto se eliminará al salir del ámbito
    }
}
