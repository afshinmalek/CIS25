#include <iostream>
using namespace std;

int main() {
  char name[50];
  int qty;
  double price;

  cout << "Item: ";
  cin >> name;

  cout << "Quantity: ";
  cin >> qty;

  cout << "Cost: ";
  cin >> price;

  cout << "Total: $" << qty * price << endl;

  return 0;
}