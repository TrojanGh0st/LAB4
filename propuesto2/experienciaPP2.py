class Cliente:
    def privadoCLiente(self, nombre, direccion, telefono):
        self.nombre = nombre
        self.direccion = direccion
        self.telefono = telefono
        self.compras_realizadas = []

    def agregar_compra(self, producto):
        self.compras_realizadas.append(producto)

class Producto:
    def privadoProducto(self, codigo, descripcion, precio, proveedor):
        self.codigo = codigo
        self.descripcion = descripcion
        self.precio = precio
        self.proveedor = proveedor

class Venta:
    def privadoVenta(self, numero_factura, fecha, cliente):
        self.numero_factura = numero_factura
        self.fecha = fecha
        self.cliente = cliente
        self.productos_vendidos = []

    def agregar_producto(self, producto):
        self.productos_vendidos.append(producto)

# Crear un cliente
cliente1 = Cliente("Pedro Carrasco", "Calle Principal 123", "555-1234")

# Crear productos
producto1 = Producto("001", "Camisa", 25.99, "Proveedor A")
producto2 = Producto("002", "Pantalon", 35.99, "Proveedor B")

# Realizar una venta
venta1 = Venta(1001, "2024-04-12", cliente1)
venta1.agregar_producto(producto1)
venta1.agregar_producto(producto2)

# Mostrar la información de la venta
print(f"Venta #{venta1.numero_factura} realizada el {venta1.fecha} a nombre de {venta1.cliente.nombre}:")
print("Productos vendidos:")
for producto in venta1.productos_vendidos:
    print(f"- {producto.descripcion} (${producto.precio})")

