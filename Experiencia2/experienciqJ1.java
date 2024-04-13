public class Curso {
    private String nombre;
    private String codigo;
    private String descripcion;
    private String fechaInicio;
    private String fechaFinalizacion;
    private Estudiante[] estudiantes;
    private int numEstudiantes;

    public Curso(String nombre, String codigo, String descripcion, String fechaInicio, String fechaFinalizacion) {
        // Inicialización de los atributos de la clase Curso
        this.nombre = nombre;
        this.codigo = codigo;
        this.descripcion = descripcion;
        this.fechaInicio = fechaInicio;
        this.fechaFinalizacion = fechaFinalizacion;
        this.estudiantes = new Estudiante[100]; // Arreglo de punteros a objetos Estudiante
        this.numEstudiantes = 0; // Contador de estudiantes asociados
    }

    public void agregarEstudiante(Estudiante estudiante) {
        // Método para agregar un estudiante al curso
        if (numEstudiantes < 100) {
            this.estudiantes[numEstudiantes] = estudiante;
            numEstudiantes++;
            estudiante.agregarCurso(this); // Agrega este curso a la lista de cursos del estudiante
        } else {
            System.out.println("No se pueden agregar más estudiantes al curso.");
        }
    }

    public void eliminarEstudiante(Estudiante estudiante) {
        // Método para eliminar un estudiante del curso
        for (int i = 0; i < numEstudiantes; i++) {
            if (estudiantes[i] == estudiante) {
                for (int j = i; j < numEstudiantes - 1; j++) {
                    estudiantes[j] = estudiantes[j + 1];
                }
                numEstudiantes--;
                estudiante.eliminarCurso(this); // Elimina este curso de la lista de cursos del estudiante
                break;
            }
        }
    }

    public void imprimirCurso() {
        // Método para imprimir los detalles del curso
        System.out.println("Nombre: " + nombre);
        System.out.println("Codigo: " + codigo);
        System.out.println("Descripcion: " + descripcion);
        System.out.println("Fecha de Inicio: " + fechaInicio);
        System.out.println("Fecha de Finalizacion: " + fechaFinalizacion);
        System.out.println("Estudiantes asociados:");
        for (int i = 0; i < numEstudiantes; i++) {
            estudiantes[i].imprimirEstudiante();
        }
    }

    // Métodos de acceso para los atributos
    public String getNombre() {
        return nombre;
    }

    public String getCodigo() {
        return codigo;
    }

    public String getDescripcion() {
        return descripcion;
    }

    public String getFechaInicio() {
        return fechaInicio;
    }

    public String getFechaFinalizacion() {
        return fechaFinalizacion;
    }
}

public class Estudiante {
    private String nombre;
    private String apellido;
    private String numIdentificacion;
    private String correoElectronico;
    private Curso[] cursos;
    private int numCursos;

    public Estudiante(String nombre, String apellido, String numIdentificacion, String correoElectronico) {
        // Inicialización de los atributos de la clase Estudiante
        this.nombre = nombre;
        this.apellido = apellido;
        this.numIdentificacion = numIdentificacion;
        this.correoElectronico = correoElectronico;
        this.cursos = new Curso[100]; // Arreglo de punteros a objetos Curso
        this.numCursos = 0; // Contador de cursos asociados
    }

    public void agregarCurso(Curso curso) {
        // Método para agregar un curso al estudiante
        if (numCursos < 100) {
            this.cursos[numCursos] = curso;
            numCursos++;
        } else {
            System.out.println("No se pueden agregar más cursos al estudiante.");
        }
    }

    public void eliminarCurso(Curso curso) {
        // Método para eliminar un curso del estudiante
        for (int i = 0; i < numCursos; i++) {
            if (cursos[i] == curso) {
                for (int j = i; j < numCursos - 1; j++) {
                    cursos[j] = cursos[j + 1];
                }
                numCursos--;
                break;
            }
        }
    }

    public void imprimirEstudiante() {
        // Método para imprimir los detalles del estudiante
        System.out.println("Nombre: " + nombre);
        System.out.println("Apellido: " + apellido);
        System.out.println("Numero de Identificacion: " + numIdentificacion);
        System.out.println("Correo Electronico: " + correoElectronico);
        System.out.println("Cursos asociados:");
        for (int i = 0; i < numCursos; i++) {
            cursos[i].imprimirCurso();
        }
    }
}

public class Main {
    public static void main(String[] args) {
        // Creación de instancias de Curso y Estudiante
        Curso curso1 = new Curso("Curso 1", "001", "Descripcion1", "01/04/2024", "30/06/2024");
        Curso curso2 = new Curso("Curso 2", "002", "Descripcion2", "15/04/2024", "15/07/2024");

        Estudiante estudiante1 = new Estudiante("nom1", "apell1", "12345", "user1@gmail.com");
        Estudiante estudiante2 = new Estudiante("nom2", "apell2", "67890", "user2@gmail.com");

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
        System.out.println("\nCursos después de asociar y desasociar estudiantes:");
        curso1.imprimirCurso();
        curso2.imprimirCurso();

        System.out.println("\nEstudiantes después de asociar y desasociar cursos:");
        estudiante1.imprimirEstudiante();
        estudiante2.imprimirEstudiante();
    }
}
