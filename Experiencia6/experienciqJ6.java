// Definición de la clase Motor
class Motor {
    private String modelo;
    private int caballosDeFuerza;

    public Motor(String modelo, int caballosDeFuerza) {
        this.modelo = modelo;
        this.caballosDeFuerza = caballosDeFuerza;
    }

    public void encender() {
        System.out.println("El motor " + modelo + " se enciende.");
    }

    public void apagar() {
        System.out.println("El motor " + modelo + " se apaga.");
    }
}

// Definición de la clase Vehiculo
class Vehiculo {
    private String tipo;
    private String marca;
    private String modelo;
    private int año;
    private Motor motor;  // Composición: Vehiculo tiene un Motor

    public Vehiculo(String tipo, String marca, String modelo, int año, Motor motor) {
        this.tipo = tipo;
        this.marca = marca;
        this.modelo = modelo;
        this.año = año;
        this.motor = motor;
    }

    public void encender() {
        System.out.println("Iniciando el " + año + " " + marca + " " + modelo + " " + tipo + "...");
        motor.encender();
    }

    public void apagar() {
        System.out.println("Deteniendo el " + año + " " + marca + " " + modelo + " " + tipo + "...");
        motor.apagar();
    }
}

// Clase principal que contiene el método main para ejecutar el programa
public class Main {
    public static void main(String[] args) {
        // Crear un objeto Motor para un vehículo
        Motor motor = new Motor("V8", 450);

        // Crear un objeto Vehiculo y asignarle el motor
        Vehiculo miVehiculo = new Vehiculo("auto", "Tesla", "Model S", 2023, motor);

        // Iniciar el vehículo (se inicia también el motor)
        miVehiculo.encender();  // Salida: Iniciando el 2023 Tesla Model S auto... \n El motor V8 se enciende.

        // Detener el vehículo (se detiene también el motor)
        miVehiculo.apagar();  // Salida: Deteniendo el 2023 Tesla Model S auto... \n El motor V8 se apaga.
    }
}
