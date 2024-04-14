import java.util.ArrayList;
import java.util.List;

// Definir la interfaz ITrabajador
interface ITrabajador {
    void establecerRelacionReflexiva(Trabajador otroTrabajador);
}

// Clase Trabajador que implementa la interfaz ITrabajador
class Trabajador implements ITrabajador {
    protected String nombre;
    protected String cargo;
    protected List<Trabajador> companeros;

    public Trabajador(String nombre, String cargo) {
        this.nombre = nombre;
        this.cargo = cargo;
        this.companeros = new ArrayList<>();
    }

    @Override
    public void establecerRelacionReflexiva(Trabajador otroTrabajador) {
        if (otroTrabajador != null) {
            this.companeros.add(otroTrabajador);
            otroTrabajador.companeros.add(this);
        } else {
            System.out.println("Error: El objeto proporcionado no es un Trabajador.");
        }
    }

    public String getNombre() {
        return nombre;
    }

    public List<Trabajador> getCompaneros() {
        return companeros;
    }
}

// Clase Gerente que extiende de Trabajador
class Gerente extends Trabajador {
    private String area;
    private List<Trabajador> trabajadoresACargo;

    public Gerente(String nombre, String cargo, String area) {
        super(nombre, cargo);
        this.area = area;
        this.trabajadoresACargo = new ArrayList<>();
    }

    public void agregarTrabajador(Trabajador trabajador) {
        if (this.trabajadoresACargo.size() < MAX_TAMANIO_ARREGLO) {
            this.trabajadoresACargo.add(trabajador);
        } else {
            System.out.println("Error: No se pueden agregar más trabajadores a cargo.");
        }
    }

    public String getArea() {
        return area;
    }

    public List<Trabajador> getTrabajadoresACargo() {
        return trabajadoresACargo;
    }
}

// Clase principal que utiliza las clases Trabajador y Gerente
public class Main {
    public static final int MAX_TAMANIO_ARREGLO = 10;

    public static void main(String[] args) {
        // Crear instancias de Trabajador y Gerente
        Trabajador juan = new Trabajador("Juan", "Analista");
        Trabajador ana = new Trabajador("Ana", "Programadora");
        Trabajador luis = new Trabajador("Luis", "Diseñador");
        Gerente maria = new Gerente("Maria", "Gerente de Proyecto", "Desarrollo");

        // Establecer relaciones reflexivas entre compañeros
        juan.establecerRelacionReflexiva(ana);
        juan.establecerRelacionReflexiva(luis);
        ana.establecerRelacionReflexiva(luis);

        // Obtener información sobre las relaciones establecidas
        System.out.println("Los compañeros de " + juan.getNombre() + " son:");
        for (Trabajador compañero : juan.getCompaneros()) {
            System.out.println("- " + compañero.getNombre());
        }

        System.out.println("Los compañeros de " + ana.getNombre() + " son:");
        for (Trabajador compañero : ana.getCompaneros()) {
            System.out.println("- " + compañero.getNombre());
        }

        System.out.println("Los compañeros de " + luis.getNombre() + " son:");
        for (Trabajador compañero : luis.getCompaneros()) {
            System.out.println("- " + compañero.getNombre());
        }

        // Agregar trabajadores a cargo del gerente
        maria.agregarTrabajador(juan);
        maria.agregarTrabajador(ana);

        System.out.println("Los trabajadores a cargo de " + maria.getNombre() + " en el área de " + maria.getArea() + " son:");
        for (Trabajador trabajador : maria.getTrabajadoresACargo()) {
            System.out.println("- " + trabajador.getNombre());
        }
    }
}
