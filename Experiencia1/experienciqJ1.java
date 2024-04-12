class Hijo {
    private String nombre;  // Atributo para almacenar el nombre del hijo

    // Constructor de la clase Hijo
    Hijo(String nombre) {
        this.nombre = nombre;  // Inicializa el nombre del hijo
    }

    // Método getter para obtener el nombre del hijo
    String getNombre() {
        return nombre;  // Devuelve el nombre del hijo
    }

    // Método setter para establecer el nombre del hijo
    void setNombre(String nombre) {
        this.nombre = nombre;  // Establece el nombre del hijo
    }
}

class Padre {
    private String nombre;  // Atributo para almacenar el nombre del padre
    private static final int maxHijos = 5;  // Número máximo de hijos
    private Hijo[] hijos = new Hijo[maxHijos];  // Arreglo para almacenar los hijos del padre
    private int numHijos;  // Variable para contar cuántos hijos tiene el padre

    // Constructor de la clase Padre
    Padre(String nombre) {
        this.nombre = nombre;  // Inicializa el nombre del padre
        this.numHijos = 0;  // Inicializa el contador de hijos
        // Inicializa cada elemento del arreglo de hijos con un objeto Hijo vacío
        for (int i = 0; i < maxHijos; i++) {
            hijos[i] = new Hijo("");
        }
    }

    // Método getter para obtener el nombre del padre
    String getNombre() {
        return nombre;  // Devuelve el nombre del padre
    }

    // Método setter para establecer el nombre del padre
    void setNombre(String nombre) {
        this.nombre = nombre;  // Establece el nombre del padre
    }

    // Método para agregar un hijo al arreglo de hijos
    void agregarHijo(Hijo hijo) {
        // Verifica si hay espacio disponible para agregar otro hijo
        if (numHijos < maxHijos) {
            hijos[numHijos++] = hijo;  // Agrega el hijo al arreglo de hijos
        } else {
            System.out.println("No se pueden agregar más hijos. Límite alcanzado.");  // Muestra un mensaje de error
        }
    }

    // Método para imprimir la información del padre y la cantidad de hijos
    void imprimirInfo() {
        // Imprime el nombre del padre
        System.out.println("Padre: " + nombre);
        // Imprime la cantidad de hijos del padre
        System.out.println("Número de hijos: " + numHijos);
    }
}

public class Main {
    public static void main(String[] args) {
        // Creamos un objeto Padre con el nombre "Juan"
        Padre padre = new Padre("p1");

        // Creamos varios objetos Hijo con nombres
        Hijo hijo1 = new Hijo("h1");
        Hijo hijo2 = new Hijo("h2");
        Hijo hijo3 = new Hijo("h3");

        // Relacionamos los objetos Hijo con el objeto Padre
        padre.agregarHijo(hijo1);
        padre.agregarHijo(hijo2);
        padre.agregarHijo(hijo3);

        // Imprimimos la información del padre y la cantidad de hijos
        padre.imprimirInfo();
    }
}
