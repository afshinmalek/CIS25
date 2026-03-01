#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

class Item {
public:
  string name;
  double price;
  int quantity;

  double getTotalPrice() { return price * quantity; }

  // The object knows how to save its own data
  void saveToFile(ofstream &out) {
    out << name << " " << price << " " << quantity << "\n";
  }
};

int main() {
  int choice = 0;

  // The cart array exists only for the current shopping session
  Item cart[100];
  int itemCount = 0;

  while (choice != 3) {
    cout << "\n===== SHOPPING CART MENU =====\n";
    cout << "1. Add item to cart\n";
    cout << "2. View checkout\n";
    cout << "3. Exit\n";
    cout << "Choose an option: ";
    cin >> choice;

    if (choice == 1) {
      Item newItem;
      cout << "Enter item name: ";
      cin >> newItem.name;
      cout << "Enter item price: ";
      cin >> newItem.price;
      cout << "Enter item quantity: ";
      cin >> newItem.quantity;

      // Add item to the current session's array
      cart[itemCount] = newItem;
      itemCount++;

      // Overwrite the text file with the current session's cart
      ofstream outFile("cart.txt");
      if (outFile.is_open()) {
        for (int i = 0; i < itemCount; i++) {
          cart[i].saveToFile(outFile);
        }
        outFile.close();
        cout << "Item added to cart.\n";
      } else {
        cout << "Error: Unable to open file for writing.\n";
      }

    } else if (choice == 2) {
      cout << "\n\n===== CHECKOUT =====\n";

      ifstream inFile("cart.txt");
      if (inFile.is_open()) {
        Item tempItem;
        double grandTotal = 0.0;

        // Format output as money ($X.XX)
        cout << fixed << setprecision(2);

        while (inFile >> tempItem.name >> tempItem.price >> tempItem.quantity) {
          double total = tempItem.getTotalPrice();
          grandTotal += total;
          cout << tempItem.name << " - $" << tempItem.price << " x "
               << tempItem.quantity << " = $" << total << "\n";
        }

        cout << "--------------------\n";
        cout << "Total: $" << grandTotal << "\n";

        inFile.close();
      } else {
        cout << "Error: Unable to open file for reading.\n";
      }

    } else if (choice == 3) {
      cout << "\nThank you for shopping!\n";
      // Note: In a real-world application, I would use remove("cart.txt");
      // here to clear the session data for the next user.
    } else {
      cout << "Invalid option. Please try again.\n";
    }
  }

  return 0;
}