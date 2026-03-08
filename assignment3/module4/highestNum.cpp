#include <iostream>

using namespace std;

int main() {
  int choice;

  // PART 1: Build a simple menu
  cout << "=== Main Menu ===" << endl;
  cout << "1. Find the largest of three numbers" << endl;
  cout << "2. Exit" << endl;
  cout << "Enter your choice (1 or 2): ";
  cin >> choice;

  // Using an if statement for the menu as requested
  if (choice == 1) {

    // PART 2: Debugged code from your original submission
    // Fixed: Added commas to properly declare multiple float variables
    float n1, n2, n3;

    cout << "Enter three numbers: ";
    // Fixed: Corrected extraction operators and used n2 instead of repeating n1
    cin >> n1 >> n2 >> n3;

    // Fixed: Implemented nested if logic to find the highest value
    if (n1 >= n2) {
      if (n1 >= n3) {
        // Fixed: This path ensures n1 is greater than or equal to both n2 and
        // n3
        cout << "Largest number: " << n1 << endl;
      } else {
        // Fixed: If n3 > n1 and we already know n1 >= n2, then n3 is largest
        cout << "Largest number: " << n3 << endl;
      }
    } else {
      // This branch means n2 > n1
      if (n2 >= n3) {
        // Fixed: n2 is greater than n1 and greater than or equal to n3
        cout << "Largest number: " << n2 << endl;
      } else {
        // Fixed: If n3 > n2 and n2 > n1, then n3 is largest
        cout << "Largest number: " << n3 << endl;
      }
    }

  } else if (choice == 2) {
    cout << "Exiting the program." << endl;
  } else {
    cout << "Invalid choice. Please run the program again." << endl;
  }

  return 0;
}