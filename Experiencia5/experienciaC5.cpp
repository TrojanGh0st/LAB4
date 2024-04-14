#include <iostream>
#include <vector>
#include <algorithm> // Para std::find

using namespace std;

// Declaración anticipada de la clase Item para evitar problemas de referencia circular
class Item;

// Clase que representa la colección principal de objetos
class Collection {
private:
    vector<Item*> items;

public:
    Collection() {
        // Constructor vacío
    }

    ~Collection() {
        // Liberar la memoria de los objetos al destruir la instancia
        for (Item* item : items) {
            delete item;
        }
    }

    void addItem(Item* item) {
        items.push_back(item);
        cout << "Item agregado: " << item->getId() << endl;
    }

    void removeItem(Item* item) {
        auto it = find(items.begin(), items.end(), item);
        if (it != items.end()) {
            items.erase(it);
            delete item; // Liberar la memoria del objeto eliminado
            cout << "Item eliminado: " << item->getId() << endl;
        } else {
            cout << "Error: El item no está en la colección" << endl;
        }
    }

    Item* getItemById(int id) {
        for (Item* item : items) {
            if (item->getId() == id) {
                return item;
            }
        }
        cout << "Error: Item con ID " << id << " no encontrado" << endl;
        return nullptr;
    }
};

// Clase que representa los objetos que se agregan a la colección
class Item {
private:
    int id;
    string attribute;

public:
    Item(int itemId, const string& attr) : id(itemId), attribute(attr) {
        // Constructor
    }

    int getId() const {
        return id;
    }

    const string& getAttribute() const {
        return attribute;
    }

    ~Item() {
        // Destructor
    }
};

// Ejemplo de uso
int main() {
    // Crear instancia de la colección
    Collection myCollection;

    // Crear varios objetos para agregar a la colección
    Item* item1 = new Item(1, "First");
    Item* item2 = new Item(2, "Second");
    Item* item3 = new Item(3, "Third");

    // Agregar objetos a la colección
    myCollection.addItem(item1);
    myCollection.addItem(item2);
    myCollection.addItem(item3);

    // Mostrar todos los objetos agregados (solo sus IDs en este ejemplo)
    cout << "Objetos en la colección:" << endl;
    for (Item* item : myCollection.getItems()) {
        cout << "Item ID: " << item->getId() << endl;
    }

    // Obtener un objeto específico por ID
    Item* foundItem = myCollection.getItemById(2);
    if (foundItem != nullptr) {
        cout << "Item encontrado: " << foundItem->getId() << endl;
    }

    // Eliminar un objeto de la colección
    myCollection.removeItem(item2);

    // Mostrar la colección después de la eliminación
    cout << "Objetos en la colección después de la eliminación:" << endl;
    for (Item* item : myCollection.getItems()) {
        cout << "Item ID: " << item->getId() << endl;
    }

    return 0;
}
