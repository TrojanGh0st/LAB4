import java.util.ArrayList;
import java.util.List;

// Clase que representa la entidad principal con una colección de objetos agregados
class Entity {
    private List<Item> items;

    public Entity() {
        this.items = new ArrayList<>();
    }

    public void addItem(Item item) {
        items.add(item);
        System.out.println("Item added: " + item.getId());
    }

    public void removeItem(Item item) {
        if (items.contains(item)) {
            items.remove(item);
            System.out.println("Item removed: " + item.getId());
        } else {
            System.out.println("Error: Item not found in collection");
        }
    }

    public Item getItemById(int itemId) {
        for (Item item : items) {
            if (item.getId() == itemId) {
                return item;
            }
        }
        System.out.println("Error: Item with ID " + itemId + " not found");
        return null;
    }
}

// Clase que representa los objetos que se agregan a la colección
class Item {
    private int id;
    private String attribute;

    public Item(int id, String attribute) {
        this.id = id;
        this.attribute = attribute;
    }

    public int getId() {
        return id;
    }

    public String getAttribute() {
        return attribute;
    }
}

// Ejemplo de uso
public class AggregationExample {
    public static void main(String[] args) {
        // Crear instancia de la entidad
        Entity entity = new Entity();

        // Crear varios objetos para agregar a la colección
        Item item1 = new Item(1, "First");
        Item item2 = new Item(2, "Second");
        Item item3 = new Item(3, "Third");

        // Agregar objetos a la colección
        entity.addItem(item1);
        entity.addItem(item2);
        entity.addItem(item3);

        // Mostrar todos los objetos agregados (solo sus IDs en este ejemplo)
        System.out.println("Objetos en la colección:");
        for (Item item : entity.getItems()) {
            System.out.println("Item ID: " + item.getId());
        }

        // Obtener un objeto específico por ID
        Item foundItem = entity.getItemById(2);
        if (foundItem != null) {
            System.out.println("Item encontrado: " + foundItem.getId());
        }

        // Eliminar un objeto de la colección
        entity.removeItem(item2);

        // Mostrar la colección después de la eliminación
        System.out.println("Objetos en la colección después de la eliminación:");
        for (Item item : entity.getItems()) {
            System.out.println("Item ID: " + item.getId());
        }
    }
}
