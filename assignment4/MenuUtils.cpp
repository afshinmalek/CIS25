
#include "MenuUtils.h"
#include <iostream>

using namespace std;

void showMenu() {
  cout << "\n--- MAIN MENU ---" << endl;
  cout << "1. Add Numbers" << endl;
  cout << "2. View Message" << endl;
  cout << "3. Exit" << endl;
  cout << "Enter your choice: ";
}

void addNumbers() {
  int a, b;
  cout << "Enter first number: ";
  cin >> a;
  cout << "Enter second number: ";
  cin >> b;
  cout << "Result: " << (a + b) << endl;
}

void viewMessage() {
  cout << "Hello! This is the 'View' function running." << endl;
}