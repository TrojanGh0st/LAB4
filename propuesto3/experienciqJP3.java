import java.util.ArrayList;
import java.util.List;

// Definición de la clase Estudiante
class Estudiante {
    private String nombre;
    private String direccion;
    private String numeroMatricula;
    private List<String> asignaturasMatriculadas;
    private List<Integer> notas;
    private List<Integer> faltas;

    public Estudiante(String nombre, String direccion, String numeroMatricula) {
        this.nombre = nombre;
        this.direccion = direccion;
        this.numeroMatricula = numeroMatricula;
        this.asignaturasMatriculadas = new ArrayList<>();
        this.notas = new ArrayList<>();
        this.faltas = new ArrayList<>();
    }

    public void matricularAsignatura(String asignatura) {
        asignaturasMatriculadas.add(asignatura);
        notas.add(0); // Inicialmente todas las notas son 0
        faltas.add(0); // Inicialmente no hay faltas
    }

    public void registrarNota(int indice, int nota) {
        notas.set(indice, nota);
    }

    public void registrarFalta(int indice) {
        faltas.set(indice, faltas.get(indice) + 1);
    }

    public String obtenerNombre() {
        return nombre;
    }

    public String obtenerDireccion() {
        return direccion;
    }

    public String obtenerNumeroMatricula() {
        return numeroMatricula;
    }

    public List<String> obtenerAsignaturasMatriculadas() {
        return asignaturasMatriculadas;
    }

    public List<Integer> obtenerNotas() {
        return notas;
    }

    public List<Integer> obtenerFaltas() {
        return faltas;
    }
}

// Definición de la clase Profesor
class Profesor {
    private String nombre;
    private String direccion;
    private String numeroTelefono;
    private List<String> asignaturasImpartidas;

    public Profesor(String nombre, String direccion, String numeroTelefono) {
        this.nombre = nombre;
        this.direccion = direccion;
        this.numeroTelefono = numeroTelefono;
        this.asignaturasImpartidas = new ArrayList<>();
    }

    public void asignarAsignatura(String asignatura) {
        asignaturasImpartidas.add(asignatura);
    }

    public String obtenerNombre() {
        return nombre;
    }

    public String obtenerDireccion() {
        return direccion;
    }

    public String obtenerNumeroTelefono() {
        return numeroTelefono;
    }

    public List<String> obtenerAsignaturasImpartidas() {
        return asignaturasImpartidas;
    }
}

// Definición de la clase Asignatura
class Asignatura {
    private String codigo;
    private String nombre;
    private String descripcion;
    private Profesor profesorAsociado;

    public Asignatura(String codigo, String nombre, String descripcion, Profesor profesorAsociado) {
        this.codigo = codigo;
        this.nombre = nombre;
        this.descripcion = descripcion;
        this.profesorAsociado = profesorAsociado;
    }

    public String obtenerCodigo() {
        return codigo;
    }

    public String obtenerNombre() {
        return nombre;
    }

    public String obtenerDescripcion() {
        return descripcion;
    }

    public Profesor obtenerProfesorAsociado() {
        return profesorAsociado;
    }
}

public class Main {
    public static void main(String[] args) {
        // Crear un estudiante
        Estudiante estudiante = new Estudiante("Pedro Carrasco", "Calle Principal 123", "0001");
        estudiante.matricularAsignatura("COmputo");
        estudiante.matricularAsignatura("Lenguaje");

        // Registrar notas del estudiante
        estudiante.registrarNota(0, 85); // Matemáticas
        estudiante.registrarNota(1, 75); // Física

        // Registrar faltas de asistencia del estudiante
        estudiante.registrarFalta(0); // Matemáticas
        estudiante.registrarFalta(1); // Física

        // Mostrar información del estudiante
        System.out.println("Estudiante: " + estudiante.obtenerNombre());
        System.out.println("Dirección: " + estudiante.obtenerDireccion());
        System.out.println("Número de matrícula: " + estudiante.obtenerNumeroMatricula());
        System.out.println("Asignaturas matriculadas:");
        List<String> asignaturasMatriculadas = estudiante.obtenerAsignaturasMatriculadas();
        List<Integer> notas = estudiante.obtenerNotas();
        List<Integer> faltas = estudiante.obtenerFaltas();
        for (int i = 0; i < asignaturasMatriculadas.size(); ++i) {
            System.out.println("- " + asignaturasMatriculadas.get(i) + ": Nota = " + notas.get(i) + ", Faltas = " + faltas.get(i));
        }

        // Crear un profesor
        Profesor profesor = new Profesor("Dr. Smith", "Avenida Central 456", "555-6789");
        profesor.asignarAsignatura("Computo");
        profesor.asignarAsignatura("Lenguaje");

        // Crear una asignatura asociada al profesor
        Asignatura asignatura = new Asignatura("COM101", "Matemáticas", "Curso introductorio de computo", profesor);

        // Mostrar información de la asignatura
        System.out.println("\nAsignatura: " + asignatura.obtenerNombre());
        System.out.println("Código: " + asignatura.obtenerCodigo());
        System.out.println("Descripción: " + asignatura.obtenerDescripcion());
        System.out.println("Profesor: " + asignatura.obtenerProfesorAsociado().obtenerNombre());
        System.out.println("Dirección del profesor: " + asignatura.obtenerProfesorAsociado().obtenerDireccion());
        System.out.println("Teléfono del profesor: " + asignatura.obtenerProfesorAsociado().obtenerNumeroTelefono());
    }
}
