#include <iostream>
using namespace std;

int main() {
  // 1. Print "Hello Inventory System!"
  cout << "Hello Inventory System!" << endl;

  // 2. Demonstrate escape characters (\n for newline, \t for tab)
  cout << "\nDemonstrating Escape Characters:" << endl;
  cout << "Column 1\tColumn 2\tColumn 3" << endl; // \t adds a tab space
  cout << "1\t\t2\t\t3" << endl;

  // 3. Output sizes of int, float, and char
  cout << "\nData Type Sizes (in bytes):"
       << endl; // \n adds an extra empty line before this
  cout << "Size of char: " << sizeof(char) << " byte" << endl;
  cout << "Size of int: " << sizeof(int) << " bytes" << endl;
  cout << "Size of float: " << sizeof(float) << " bytes" << endl;

  return 0;
}