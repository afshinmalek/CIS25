
#include "MenuUtils.h"
#include <iostream>

using namespace std;

int main() {
  int option;

  do {
    // 1. Call the function to show the menu
    showMenu();
    cin >> option;

    // 2. Handle the user's choice
    switch (option) {
    case 1:
      addNumbers(); // Calls the function from MenuUtils.cpp
      break;
    case 2:
      viewMessage(); // Calls the function from MenuUtils.cpp
      break;
    case 3:
      cout << "Exiting program..." << endl;
      break;
    default:
      cout << "Invalid option. Please try again." << endl;
    }

  } while (option != 3); // Loops until the user picks 3

  return 0;
}