#include <iostream>
#include <string>

using namespace std;

// 1. Base Class
class User {
protected: // Access Control: Allows derived classes to access the username
  string username;

public:
  // Constructor to initialize the username
  User(string name) { username = name; }

  // Virtual function to be overridden by derived classes
  virtual void accessLevel() {
    cout << "Role: General User\n";
    cout << "Permissions: No specific access.\n";
  }
};

// 2. Derived Classes

// Employee Class inheriting from User
class Employee : public User {
public:
  Employee(string name) : User(name) {}

  // Method Overriding
  void accessLevel() override {
    cout << "Role: Employee (" << username << ")\n";
    cout << "Permissions: View inventory\n\n";
  }
};

// Manager Class inheriting from User
class Manager : public User {
public:
  Manager(string name) : User(name) {}

  // Method Overriding
  void accessLevel() override {
    cout << "Role: Manager (" << username << ")\n";
    cout << "Permissions: View and update inventory\n\n";
  }
};

// Admin Class inheriting from User
class Admin : public User {
public:
  Admin(string name) : User(name) {}

  // Method Overriding
  void accessLevel() override {
    cout << "Role: Admin (" << username << ")\n";
    cout << "Permissions: Full access: add, update, delete inventory\n\n";
  }
};

int main() {
  // Instantiate objects for each role
  Employee emp("Afshin");
  Manager mgr("Alice");
  Admin admin("Bob");

  // Call the overridden methods to demonstrate polymorphism
  emp.accessLevel();
  mgr.accessLevel();
  admin.accessLevel();

  return 0;
}