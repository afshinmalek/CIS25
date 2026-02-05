#include <iostream>

using namespace std;

int main() {

  // Fixed: Added commas to properly declare multiple float variables
  float n1, n2, n3;

  cout << "Enter three numbers: ";
  // Fixed: Corrected extraction operators and used n2 instead of repeating n1
  cin >> n1 >> n2 >> n3;

  // Fixed: Implemented nested if logic to find the highest value
  if (n1 >= n2) {
    if (n1 >= n3) {
      // Fixed: This path ensures n1 is greater than or equal to both n2 and n3
      cout << "Largest number: " << n1;
    } else {
      // Fixed: If n3 > n1 and we already know n1 >= n2, then n3 is largest
      cout << "Largest number: " << n3;
    }
  } else {
    // This branch means n2 > n1
    if (n2 >= n3) {
      // Fixed: n2 is greater than n1 and greater than or equal to n3
      cout << "Largest number: " << n2;
    } else {
      // Fixed: If n3 > n2 and n2 > n1, then n3 is largest
      cout << "Largest number: " << n3;
    }
  }

  return 0;
}