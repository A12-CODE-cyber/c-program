#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Item {
    string name;
    int quantity;
    double price;
};

int main() {
    vector<Item> inventory;
    int choice;

    do {
        cout << "\n ****INVENTORY MANAGEMENT SYSTEM BY AHMED RAZA QURESHI*** \n ***ASSIGNED BY SIR AZHER KHASKHELI*** \n";
        cout << "1. Add Item\n";
        cout << "2. Update Quantity\n";
        cout << "3. View Inventory\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Item newItem;
                cout << "Enter item name: ";
                cin.ignore(); // Clear newline character
                getline(cin, newItem.name);
                cout << "Enter quantity: ";
                cin >> newItem.quantity;
                cout << "Enter price: ";
                cin >> newItem.price;
                inventory.push_back(newItem);
                cout << "Item added successfully!\n";
                break;
            }
            case 2: {
                string itemName;
                int newQuantity;
                cout << "Enter item name to update: ";
                cin.ignore();
                getline(cin, itemName);
                for (int i = 0; i < inventory.size(); ++i) {
                    if (inventory[i].name == itemName) {
                        cout << "Enter new quantity: ";
                        cin >> newQuantity;
                        inventory[i].quantity = newQuantity;
                        cout << "Quantity updated successfully!\n";
                        break;
                    }
                }
                break;
            }
            case 3: {
                cout << "\nInventory:\n";
                for (int i = 0; i < inventory.size(); ++i) { // Use traditional for loop
                    const Item& item = inventory[i];
                    cout << "Name: " << item.name << ", Quantity: " << item.quantity << ", Price: $" << item.price << endl;
                }
                break;
            }
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
