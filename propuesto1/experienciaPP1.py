class Autor:
    def privado(self, nombre, nacionalidad):
        self.nombre = nombre
        self.nacionalidad = nacionalidad
        self.libros_escritos = []

    def agregar_libro_escrito(self, libro):
        self.libros_escritos.append(libro)

class Libro:
    def privado2(self, ISBN, titulo, ano_publicacion, cantidad_ejemplares, autor):
        self.ISBN = ISBN
        self.titulo = titulo
        self.ano_publicacion = ano_publicacion
        self.cantidad_ejemplares = cantidad_ejemplares
        self.autor = autor

class Usuario:
    def privado3(self, nombre, direccion, telefono):
        self.nombre = nombre
        self.direccion = direccion
        self.telefono = telefono
        self.libros_prestados = []

    def prestar_libro(self, libro):
        self.libros_prestados.append(libro)

# Crear un autor
autor = Autor("Stephen King", "Estados Unidos")

# Crear un libro y asociarlo con el autor
libro = Libro("9788490626780", "It", 1986, 5, autor)

# Crear un usuario
usuario = Usuario("Pedro Carrasco", "Calle Principal 123", "555-1234")

# Prestar un libro al usuario
usuario.prestar_libro(libro)

# Mostrar la información del libro prestado al usuario
print(f"Libros prestados a {usuario.nombre}:")
for libro_prestado in usuario.libros_prestados:
    print(f"- {libro_prestado.titulo} ({libro_prestado.ano_publicacion})")

