import java.util.ArrayList;

// Definición de la clase Curso
class Curso {
    private String nombre;
    private String codigo;
    private String descripcion;
    private String fechaInicio;
    private String fechaFinalizacion;
    private ArrayList<Estudiante> estudiantes; // Lista para almacenar los estudiantes asociados al curso

    // Constructor de la clase Curso
    public Curso(String nombre, String codigo, String descripcion, String fechaInicio, String fechaFinalizacion) {
        this.nombre = nombre;
        this.codigo = codigo;
        this.descripcion = descripcion;
        this.fechaInicio = fechaInicio;
        this.fechaFinalizacion = fechaFinalizacion;
        this.estudiantes = new ArrayList<>();
    }

    // Método para agregar un estudiante al curso
    public void agregarEstudiante(Estudiante estudiante) {
        estudiantes.add(estudiante); // Agrega el estudiante a la lista de estudiantes asociados al curso
        estudiante.agregarCurso(this); // Agrega este curso a la lista de cursos del estudiante
    }

    // Método para eliminar un estudiante del curso
    public void eliminarEstudiante(Estudiante estudiante) {
        estudiantes.remove(estudiante); // Remueve al estudiante de la lista
        estudiante.eliminarCurso(this); // Elimina este curso de la lista de cursos del estudiante
    }

    // Método para imprimir los detalles del curso
    public void imprimirCurso() {
        System.out.println("Nombre: " + nombre + ", Codigo: " + codigo + ", Descripcion: " + descripcion +
                ", Fecha de Inicio: " + fechaInicio + ", Fecha de Finalizacion: " + fechaFinalizacion);
        System.out.println("Estudiantes asociados:");
        for (Estudiante estudiante : estudiantes) { // Itera sobre la lista de estudiantes asociados al curso
            estudiante.imprimirEstudiante(); // Imprime los detalles de cada estudiante asociado al curso
        }
    }
}

// Definición de la clase Estudiante
class Estudiante {
    private String nombre;
    private String apellido;
    private String numIdentificacion;
    private String correoElectronico;
    private ArrayList<Curso> cursos; // Lista para almacenar los cursos asociados al estudiante

    // Constructor de la clase Estudiante
    public Estudiante(String nombre, String apellido, String numIdentificacion, String correoElectronico) {
        this.nombre = nombre;
        this.apellido = apellido;
        this.numIdentificacion = numIdentificacion;
        this.correoElectronico = correoElectronico;
        this.cursos = new ArrayList<>();
    }

    // Método para agregar un curso al estudiante
    public void agregarCurso(Curso curso) {
        cursos.add(curso); // Agrega el curso a la lista de cursos asociados al estudiante
    }

    // Método para eliminar un curso del estudiante
    public void eliminarCurso(Curso curso) {
        cursos.remove(curso); // Remueve el curso de la lista de cursos del estudiante
    }

    // Método para imprimir los detalles del estudiante
    public void imprimirEstudiante() {
        System.out.println("Nombre: " + nombre + ", Apellido: " + apellido + ", Numero de Identificacion: " + numIdentificacion +
                ", Correo Electronico: " + correoElectronico);
        System.out.println("Cursos asociados:");
        for (Curso curso : cursos) { // Itera sobre la lista de cursos asociados al estudiante
            curso.imprimirCurso(); // Imprime los detalles de cada curso asociado al estudiante
        }
    }
}

public class Main {
    public static void main(String[] args) {
        // Creación de instancias de Curso y Estudiante
        Curso curso1 = new Curso("Curso 1", "001", "Descripcion del Curso 1", "01/04/2024", "30/06/2024");
        Curso curso2 = new Curso("Curso 2", "002", "Descripcion del Curso 2", "15/04/2024", "15/07/2024");

        Estudiante estudiante1 = new Estudiante("nom1", "apell1", "52312", "user1@gmail.com");
        Estudiante estudiante2 = new Estudiante("nom2", "apell2", "12312", "user2@gmail.com");

        // Impresión de detalles antes de asociar estudiantes y cursos
        System.out.println("Cursos antes de asociar estudiantes:");
        curso1.imprimirCurso();
        curso2.imprimirCurso();
        System.out.println("\nEstudiantes antes de asociar cursos:");
        estudiante1.imprimirEstudiante();
        estudiante2.imprimirEstudiante();

        // Asociación de estudiantes y cursos
        curso1.agregarEstudiante(estudiante1);
        curso2.agregarEstudiante(estudiante1);
        curso2.agregarEstudiante(estudiante2);

        estudiante1.agregarCurso(curso1);
        estudiante1.agregarCurso(curso2);
        estudiante2.agregarCurso(curso2);

        // Desasociación de estudiantes y cursos
        curso1.eliminarEstudiante(estudiante1);
        estudiante1.eliminarCurso(curso2);

        // Impresión de detalles después de asociar y desasociar estudiantes y cursos
        System.out.println("\nCursos despues de asociar y desasociar estudiantes:");
        curso1.imprimirCurso();
        curso2.imprimirCurso();

        System.out.println("\nEstudiantes despues de asociar y desasociar cursos:");
        estudiante1.imprimirEstudiante();
        estudiante2.imprimirEstudiante();
    }
}
