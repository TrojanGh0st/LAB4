class Entity:
    def __init__(self):
        self.items = []

    def add_item(self, item):
        self.items.append(item)
        print(f"Item added: {item.get_id()}")

    def remove_item(self, item):
        if item in self.items:
            self.items.remove(item)
            print(f"Item removed: {item.get_id()}")
        else:
            print("Error: Item not found in collection")

    def get_item_by_id(self, item_id):
        for item in self.items:
            if item.get_id() == item_id:
                return item
        print(f"Error: Item with ID {item_id} not found")
        return None


class Item:
    def __init__(self, item_id, attribute):
        self.item_id = item_id
        self.attribute = attribute

    def get_id(self):
        return self.item_id

    def get_attribute(self):
        return self.attribute


# Ejemplo de uso
if __name__ == "__main__":
    # Crear instancia de la entidad
    entity = Entity()

    # Crear varios objetos para agregar a la colección
    item1 = Item(1, "First")
    item2 = Item(2, "Second")
    item3 = Item(3, "Third")

    # Agregar objetos a la colección
    entity.add_item(item1)
    entity.add_item(item2)
    entity.add_item(item3)

    # Mostrar todos los objetos agregados (solo sus IDs en este ejemplo)
    print("Objetos en la colección:")
    for item in entity.items:
        print(f"Item ID: {item.get_id()}")

    # Obtener un objeto específico por ID
    found_item = entity.get_item_by_id(2)
    if found_item:
        print(f"Item encontrado: {found_item.get_id()}")

    # Eliminar un objeto de la colección
    entity.remove_item(item2)

    # Mostrar la colección después de la eliminación
    print("Objetos en la colección después de la eliminación:")
    for item in entity.items:
        print(f"Item ID: {item.get_id()}")
