#include <iostream>
using namespace std;

// 1. Create a Struct
struct Patient {
  int id;
  string name;
  int age;
};

int main() {
  // 2. Create a Patient Variable
  Patient patient1;

  // 4. Assign Values using the regular variable
  patient1.id = 101;
  patient1.name = "John";
  patient1.age = 40;

  // 3. Create a Pointer that stores the address of the patient using &
  Patient *p = &patient1;

  // 5. Display Data Using Pointer (->)
  cout << "ID:" << p->id << endl;
  cout << "Name:" << p->name << endl;
  cout << "Age:" << p->age << endl;

  return 0;
}